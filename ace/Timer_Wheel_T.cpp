// $Id$

#ifndef ACE_TIMER_WHEEL_T_C
#define ACE_TIMER_WHEEL_T_C

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Timer_Wheel_T.h"
#include "ace/Log_Msg.h"

ACE_RCSID(ace, Timer_Wheel_T, "$Id$")


// Design/implementation notes for ACE_Timer_Wheel_T.
//
// Each timer queue entry is represented by a ACE_Timer_Node.
// The timing wheel is divided into a number of "spokes"; there are
// spoke_count_ spokes in the wheel. Each timer is hashed into one of the
// spokes. Entries within each spoke are linked in a double-linked list
// in order of increasing expiration. The first ACE_Timer_Node in each
// spoke is a "dummy node" that marks the end of the list of ACE_Timer_Nodes
// in that spoke.
//
// The timer ID for a scheduled timer is formed by its spoke position in
// the wheel, and the number of timers that have been inserted in that spoke
// since the queue was initialized. N bits of the long timer_id are used
// to determine the spoke, and M bits are used as a counter.
// Each time a Node is inserted into a spoke, it's counter
// is incremented. The count is kept in the timer ID field
// of the dummy root Node. In the event of overflow of the counter, the spoke
// must be searched for each new id to make sure it's not already in use. To
// prevent having to do an exhaustive search each time, we keep extra data
// in the dummy root Node. 
/**
* Default Constructor that sets defaults for spoke_count_ and resolution_
* and doesn't do any preallocation.
*
* @param upcall_functor A pointer to a functor to use instead of the default
* @param freelist       A pointer to a freelist to use instead of the default
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::ACE_Timer_Wheel_T 
(FUNCTOR* upcall_functor
 , FreeList* freelist
 )
: Base (upcall_functor, freelist)
, spokes_(0)
, spoke_count_(0) // calculated in open_i
, spoke_bits_(0) 
, res_bits_ (0)
, earliest_spoke_ (0)
, iterator_(0)
, timer_count_(0)
{
  ACE_TRACE ("ACE_Timer_Wheel_T::ACE_Timer_Wheel_T");
  this->open_i(0, ACE_DEFAULT_TIMER_WHEEL_SIZE, ACE_DEFAULT_TIMER_WHEEL_RESOLUTION);
}

/**
* Constructor that sets up the timing wheel and also may preallocate
* some nodes on the free list
*
* @param wheelsize      The number of lists in the timer wheel
* @param resolution     The time resolution in milliseconds used by the hashing function
* @param prealloc       The number of entries to prealloc in the free_list
* @param upcall_functor A pointer to a functor to use instead of the default
* @param freelist       A pointer to a freelist to use instead of the default
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::ACE_Timer_Wheel_T 
( u_int spoke_count, 
 u_int resolution, 
 size_t prealloc, 
 FUNCTOR* upcall_functor, 
 FreeList* freelist
 )
: Base (upcall_functor, freelist)
, spokes_(0)
, spoke_count_ (0) // calculated in open_i
, spoke_bits_(0) 
, res_bits_(0)
, earliest_spoke_ (0)
, iterator_(0)
, timer_count_(0)
{
  ACE_TRACE ("ACE_Timer_Wheel_T::ACE_Timer_Wheel_T");
  this->open_i(prealloc, spoke_count, resolution);
}

namespace {
  int power2bits(int n, int min_bits, int max_bits) {
    int max = (1 << max_bits) - 1;
    if (n > max) {
      return max_bits;
    }
    // count the bits in n.
    int i = 0;
    int tmp = n;
    do {
      tmp >>= 1;
      ++i;
    } while (tmp != 0);
    
    if (i <= min_bits) {
      return min_bits;
    }
    // Which is nearest?
    int a = (1 << i) - n;
    int b = (1 << (i - 1)) - n;
    if (b < 0)
      b = -b;
    if (b < a)
      return i - 1;
    return i;
  }
}

/**
* Initialize the queue. Uses the established members for all needed
* information.
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::open_i (size_t prealloc, u_int spokes, u_int res)
{
  ACE_TRACE ("ACE_Timer_Wheel_T::open_i");
  
  this->gettimeofday (ACE_OS::gettimeofday);

  // Rather than waste bits in our timer id, we might as well round up
  // the spoke count to the next power of two - 1 . (i.e 1,3,7,15,...127,etc.)
  const int MIN_SPOKE_BITS = 3;  // Allow between 8 and 4096 spokes
  const int MAX_SPOKE_BITS = 12; 
  const int MAX_RES_BITS = 20;   // 20 is plenty, even on 64 bit platforms.
  
  this->spoke_bits_ = power2bits(spokes, MIN_SPOKE_BITS, MAX_SPOKE_BITS);
  this->res_bits_ = power2bits(res, 1, MAX_RES_BITS);

  this->spoke_count_ = 1 << this->spoke_bits_;

  this->free_list_->resize(prealloc + this->spoke_count_);

  this->wheel_time_.msec(1 << (this->res_bits_ + this->spoke_bits_));
  
  ACE_NEW (this->spokes_, ACE_Timer_Node_T<TYPE>* [this->spoke_count_]);
  
  // Create the root nodes. These will be treated specially
  for (u_int i = 0; i < this->spoke_count_; ++i)
  {
    ACE_Timer_Node_T<TYPE>* root = this->alloc_node();
    root->set (0, 0, ACE_Time_Value::zero, ACE_Time_Value::zero, root, root, 0);
    this->spokes_[i] = root;
  }
  
  ACE_NEW (iterator_, Iterator(*this));
}

/// Destructor just cleans up its memory
template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::~ACE_Timer_Wheel_T (void)
{
  ACE_TRACE ("ACE_Timer_spokes_T::~ACE_Timer_spokes_T");
  
  delete iterator_;
  
  for (u_int i = 0; i < this->spoke_count_; ++i)
  {
    // Free all the nodes starting at the root
    ACE_Timer_Node_T<TYPE>* root = this->spokes_[i];
    for (ACE_Timer_Node_T<TYPE>* a = root->get_next(); a != root;)
    {
      ACE_Timer_Node_T<TYPE>* b = a->get_next();
      this->upcall_functor().deletion(*this, a->get_type(), a->get_act());
      a->set_prev(0);
      a->set_next(0);
      this->free_node (a);
      a = b->get_next();
    }
    delete root;
  }
  delete[] this->spokes_;
}

/// Searches for a node by timer_id within one spoke.
template <class TYPE, class FUNCTOR, class ACE_LOCK> 
ACE_Timer_Node_T<TYPE>*
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::find_spoke_node(u_int spoke, long timer_id) const
{
  ACE_Timer_Node_T<TYPE>* root = this->spokes_[spoke];
  for (ACE_Timer_Node_T<TYPE>* n = root->get_next(); n != root; n = n->get_next()) {
    if (n->get_timer_id() == timer_id) {
      return n;
    }
  }
  return 0;
}

/// Searches all spokes for a node matching the specified timer_id
/// Uses the spoke encoded in the timer_id as a starting place.
template <class TYPE, class FUNCTOR, class ACE_LOCK> 
ACE_Timer_Node_T<TYPE>*
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::find_node(long timer_id) const
{
  if (timer_id == -1) 
    return 0; 
  
  // Search the spoke where timer_id was originally scheduled
  u_int spoke_mask = this->spoke_count_ - 1;
  u_int start = timer_id & spoke_mask;
  ACE_Timer_Node_T<TYPE>* n = this->find_spoke_node(start, timer_id);
  if (n != 0) {
    return n;
  }

  //ACE_ERROR((LM_ERROR, "Node not found in original spoke.\n"));

  // Search the rest of the spokes
  for (u_int i = 0; i < this->spoke_count_; ++i) {
    if (i != start) { // already searched this one
      n = this->find_spoke_node(i, timer_id);
      if (n != 0) {
        return n;
      }
    }
  }

  //ACE_ERROR((LM_ERROR, "Node not found.\n"));
  return 0;
}

/**
* Check to see if the wheel is empty
*
* @return True if empty
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::is_empty (void) const
{
  ACE_TRACE ("ACE_Timer_Wheel_T::is_empty");
  return timer_count_ == 0;
}


/**
* @return First (earliest) node in the wheel_'s earliest_spoke_ list
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> const ACE_Time_Value &
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::earliest_time (void) const
{
  ACE_TRACE ("ACE_Timer_Wheel_T::earliest_time");
  ACE_Timer_Node_T<TYPE>* n = this->get_first_i();
  if (n != 0)
    return n->get_timer_value();
  return ACE_Time_Value::zero;
}

/// Uses a simple hash to find which spoke to use based on when the
/// timer is due to expire. Hopefully the 64bit int operations avoid
/// any overflow problems. 
template <class TYPE, class FUNCTOR, class ACE_LOCK> u_int
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::calculate_spoke(const ACE_Time_Value& t) const
{
  return ACE_static_cast(u_int, (t.msec() >> this->res_bits_) & (this->spoke_count_ - 1));
}

/// Generates a unique timer_id for the given spoke. It should be pretty
/// fast until the point where the counter overflows.  At that time you
/// have to do exhaustive searches within the spoke to ensure that a particular
/// timer id is not already in use. Some optimizations are in place so 
/// that this hopefully doesn't have to happen often. 
template <class TYPE, class FUNCTOR, class ACE_LOCK> long
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::generate_timer_id(u_int spoke) {

  int cnt_bits = sizeof(long) * 8 - this->spoke_bits_;
  int max_cnt = (1 << cnt_bits) - 1;
  if (spoke == this->spoke_count_) {
    --max_cnt; // Because -1 is used as a special invalid timer_id.
  }
  ACE_Timer_Node_T<TYPE>* root = this->spokes_[spoke];

  if (root == root->get_next()) {
    root->set_act(0);
  }
  // We use this field to keep track of the next counter value that
  // may be in use. Of course it may have expired, so we just use
  // this field so that we know when we don't have to check for duplicates
  long next_cnt = ACE_reinterpret_cast(long, root->get_act());
  // This field is used as a counter instead of a timer_id.
  long cnt = root->get_timer_id();  

  if (cnt >= max_cnt && root == root->get_next()) {
    // Special case when we overflow on an empty spoke. We can just
    // wrap the count around without searching for duplicates. We only
    // want to do this when the counter overflows, so that we return
    // unique timer_id values as often as possible.
    root->set_timer_id(1);
    return spoke;
  } else if (cnt >= max_cnt) { // overflow
    cnt = 0; // try again starting at zero
  } else if (next_cnt == 0 || cnt < next_cnt) {
    root->set_timer_id(cnt + 1);
    return (cnt << this->spoke_bits_) | spoke;
  }

  //ACE_ERROR((LM_ERROR, "Timer id overflow. We have to search now.\n"));

  // We've run out of consecutive id numbers so now we have to search for a unique id.
  // We'll try increasing numbers until we find one that is not in use, and we'll
  // record the next highest number so that we can avoid this search as often
  // as possible.
  for (; cnt < max_cnt - 1; ++cnt) {
    long id = (cnt << this->spoke_bits_) | spoke;
    ACE_Timer_Node_T<TYPE>* n = this->find_spoke_node(spoke, id);
    if (n == 0) {
      root->set_timer_id(cnt + 1);
      // Now we need to find the next highest cnt in use
      next_cnt = 0;
      for (; n != root; n = n->get_next()) {
        int tmp = n->get_timer_id() >> this->spoke_bits_;
        if (tmp > cnt && (tmp < next_cnt || next_cnt == 0)) {
          next_cnt = tmp;
        }
      }
      root->set_act(ACE_reinterpret_cast(void*, next_cnt));
      return id;
    }
  }

  return -1; // We did our best, but the spoke is full. 
}

/**
* Creates a ACE_Timer_Node_T based on the input parameters.  Then inserts
* the node into the wheel using reschedule ().  Then returns a timer_id.
*
*  @param type            The data of the timer node
*  @param act             Asynchronous Completion Token (AKA magic cookie)
*  @param future_time     The time the timer is scheduled for (absolute time)
*  @param interval        If not ACE_Time_Value::zero, then this is a periodic
*                         timer and interval is the time period
*
*  @return Unique identifier (can be used to cancel the timer).
*          -1 on failure.
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> long
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::schedule (
                                                      const TYPE& type,
                                                      const void* act,
                                                      const ACE_Time_Value& future_time,
                                                      const ACE_Time_Value& interval
                                                      )
{
  ACE_TRACE ("ACE_Timer_Wheel_T::schedule");
  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));
  
  ACE_Timer_Node_T<TYPE>* n = this->alloc_node();
  
  if (n != 0)
  {
    u_int spoke = calculate_spoke(future_time);
    long id = generate_timer_id(spoke);
    
    //ACE_ERROR((LM_ERROR, "Scheduling %x spoke:%d id:%d\n", (long) n, spoke, id));

    if (id != -1) {
      n->set (type, act, future_time, interval, 0, 0, id);
      this->schedule_i (n, spoke, future_time);
    }
    return id;
  }
  
  // Failure return
  errno = ENOMEM;
  return -1;
}

/**
* Takes an ACE_Timer_Node and inserts it into the correct spokeition in
* the correct list.  Also makes sure to update the earliest time.
*
* @param expired The timer node to reschedule
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::reschedule (ACE_Timer_Node_T<TYPE>* n)
{
  ACE_TRACE ("ACE_Timer_Wheel_T::reschedule");
  const ACE_Time_Value& expire = n->get_timer_value(); 
  u_int spoke = calculate_spoke(expire);
  this->schedule_i(n, spoke, expire);
}

/// The shared scheduling functionality between schedule() and reschedule()
template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::schedule_i (ACE_Timer_Node_T<TYPE>* n, u_int spoke, 
                                                        const ACE_Time_Value& expire)
{
  // See if we need to update the earliest time
  if (this->is_empty() || expire < this->earliest_time())
    this->earliest_spoke_ = spoke;
  
  ACE_Timer_Node_T<TYPE>* root = this->spokes_[spoke];
  ACE_Timer_Node_T<TYPE>* last = root->get_prev();

  ++timer_count_;

  // If the spoke is empty
  if (last == root) {
    n->set_prev(root);
    n->set_next(root);
    root->set_prev(n);
    root->set_next(n);
    return;
  }
  // Note : It might be beneficial in the real world to check to see
  // if the new timer belongs on the end of the spoke, but in testing
  // it made no difference, so we just skip it. 

  // We use <= here so that the timers with equal values will 
  // be scheduled in the right order
  ACE_Timer_Node_T<TYPE>* next = root->get_next();
  while (next != root && next->get_timer_value() <= expire)
    next = next->get_next();
  
  // insert before
  n->set_prev(next->get_prev());
  n->set_next(next);
  next->get_prev()->set_next(n);
  next->set_prev(n);
}


/**
* Find the timer node by using the id as a pointer.  Then use set_interval()
* on the node to update the interval.
*
* @param timer_id The timer identifier
* @param interval The new interval
*
* @return 0 if successful, -1 if no.
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::reset_interval (
                                                            long timer_id,
                                                            const ACE_Time_Value &interval
                                                            )
{
  ACE_TRACE ("ACE_Timer_Wheel_T::reset_interval");
  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));
  ACE_Timer_Node_T<TYPE>* n = this->find_node(timer_id);
  if (n != 0) {
    n->set_interval(interval); // The interval will take effect the next time this node is expired.
    return 0;
  }
  return -1;
}


/**
* Goes through every list in the wheel and whenever we find one with the
* correct type value, we remove it and continue.  At the end make sure
* we reset the earliest time value in case the earliest timers were
* removed.
*
* @param type       The value to search for.
* @param skip_close If this non-zero, the cancellation method of the
*                   functor will not be called for each cancelled timer.
*
* @return Number of timers cancelled
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::cancel (const TYPE& type, int skip_close)
{
  ACE_TRACE ("ACE_Timer_Wheel_T::cancel");
  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));

  int num_canceled = 0; // Note : Technically this can overflow.

  if (! this->is_empty()) {
    
    ACE_Timer_Node_T<TYPE>* first = this->get_first();
    
    ACE_Time_Value last = first->get_timer_value();
    int recalc = 0;
    
    for (u_int i = 0; i < this->spoke_count_; ++i)
    {
      ACE_Timer_Node_T<TYPE>* root = this->spokes_[i];
      for (ACE_Timer_Node_T<TYPE>* n = root->get_next(); n != root;)
      {
        if (n->get_type() == type) // Note: Typically Type is an ACE_Event_Handler*
        {
          ++num_canceled;
          
          if (n == first) {
            recalc = 1;
          }
          
          ACE_Timer_Node_T<TYPE>* tmp = n;
          n = n->get_next();
          int always_skip_close = 1; // todo : Is this correct?
          this->cancel_i(tmp, always_skip_close);
        }
        else
        {
          n = n->get_next();
        }
      }
    }
    
    if (recalc)
      this->recalc_earliest(last);
  }

  if (! skip_close) { //  && num_canceled > 0) {
    this->upcall_functor().cancellation (*this, type);
  }
  return num_canceled;
}


/**
* Cancels the single timer that is specified by the timer_id.  In this
* case the timer_id is actually a pointer to the node, so we cast it
* to the node.  This can be dangerous if the timer_id is made up
* (or deleted twice) so we do a little sanity check.  Finally we update
* the earliest time in case the earliest timer was removed.
*
* @param timer_id   Timer Identifier
* @param act        Asychronous Completion Token (AKA magic cookie):
*                   If this is non-zero, stores the magic cookie of
*                   the cancelled timer here.
* @param skip_close If this non-zero, the cancellation method of the
*                   functor will not be called.
*
* @return 1 for sucess and 0 if the timer_id wasn't found (or was
*         found to be invalid)
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::cancel (long timer_id,
                                                    const void **act,
                                                    int skip_close)
{
  ACE_TRACE ("ACE_Timer_Wheel_T::cancel");
  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));
  ACE_Timer_Node_T<TYPE>* n = this->find_node(timer_id);
  if (n != 0) {
    ACE_Time_Value last = n->get_timer_value();
    int recalc = (this->get_first_i() == n);
    if (act != 0)
      *act = n->get_act();
    this->cancel_i(n, skip_close);
    if (recalc)
      this->recalc_earliest(last);
    return 1;
  }
  return 0;
}

/// Shared subset of the two cancel() methods. 
template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::cancel_i (ACE_Timer_Node_T<TYPE>* n, int skip_close)
{
  //ACE_ERROR((LM_ERROR, "Canceling %x\n", (long) n));
  this->unlink(n);
  this->free_node (n);
  if (! skip_close) {
    this->upcall_functor().cancellation (*this, n->get_type());
  }
}

/// There are a few places where we have to figure out which timer
/// will expire next. This method makes the assumption that spokes
/// are always sorted, and that timers are always in the correct spoke
/// determined from their expiration time. 
/// The last time is always passed in, even though you can often calculate
/// it as get_first()->get_timer_value().
template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::recalc_earliest(const ACE_Time_Value& last)
{
  if (this->is_empty()) // This is possible because we use a count for is_empty()
    return;

  ACE_Time_Value et = ACE_Time_Value::zero;
  
  u_int spoke = this->earliest_spoke_;

  // We will have to go around the wheel at most one time.
  for (u_int i = 0; i < this->spoke_count_; ++i)
  {
    ACE_Timer_Node_T<TYPE>* root = this->spokes_[spoke];
    ACE_Timer_Node_T<TYPE>* n = root->get_next();
    if (n != root)
    {
      ACE_Time_Value t = n->get_timer_value();
      if (t < last + this->wheel_time_) {
        this->earliest_spoke_ = spoke;
        return;
      } else if (et == ACE_Time_Value::zero || t < et) {
        et = t;
      }
    }
    if (++spoke >= this->spoke_count_) {
      spoke = 0;
    }
  }
  //ACE_ERROR((LM_ERROR, "We had to search the whole wheel.\n"));
}

/**
* Dumps out the size of the wheel, the resolution, and the contents
* of the wheel.
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::dump (void) const
{
  ACE_TRACE ("ACE_Timer_Wheel_T::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  
  ACE_DEBUG ((LM_DEBUG,
    ACE_LIB_TEXT ("\nspoke_count_ = %d"), this->spoke_count_));
  ACE_DEBUG ((LM_DEBUG,
    ACE_LIB_TEXT ("\nresolution_ = %d"), 1 << this->res_bits_));
  ACE_DEBUG ((LM_DEBUG,
    ACE_LIB_TEXT ("\nwheel_ = \n")));
  
  for (u_int i = 0; i < this->spoke_count_; ++i)
  {
    ACE_DEBUG ((LM_DEBUG, ACE_LIB_TEXT ("%d\n"), i));
    ACE_Timer_Node_T<TYPE>* root = this->spokes_[i];
    for (ACE_Timer_Node_T<TYPE>* n = root->get_next(); n != root; n = n->get_next())
    {
      n->dump ();
    }
  }
  
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
}


/**
* Removes the earliest node and then find the new <earliest_spoke_>
*
* @return The earliest timer node.
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_Timer_Node_T<TYPE> *
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::remove_first (void)
{
  ACE_TRACE ("ACE_Timer_Wheel_T::remove_first");
  return remove_first_expired(ACE_Time_Value::max_time);
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::unlink (ACE_Timer_Node_T<TYPE>* n)
{
  --timer_count_;
  n->get_prev()->set_next(n->get_next());
  n->get_next()->set_prev(n->get_prev());
  n->set_prev(0);
  n->set_next(0);
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_Timer_Node_T<TYPE> *
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::remove_first_expired (const ACE_Time_Value& now)
{
  ACE_Timer_Node_T<TYPE>* n = this->get_first();
  if (n != 0 && n->get_timer_value() <= now) {
    this->unlink(n);
    this->recalc_earliest(n->get_timer_value());
    return n;
  }
  return 0;
}

/**
* Returns the earliest node without removing it
*
* @return The earliest timer node.
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> 
ACE_Timer_Node_T<TYPE>*
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::get_first (void)
{
  ACE_TRACE ("ACE_Timer_Wheel_T::get_first");
  return this->get_first_i();
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> 
ACE_Timer_Node_T<TYPE>*
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::get_first_i (void) const
{
  ACE_Timer_Node_T<TYPE>* root = this->spokes_[this->earliest_spoke_];
  ACE_Timer_Node_T<TYPE>* first = root->get_next();
  if (first != root)
    return first;
  return 0;
}


/**
* @return The iterator
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> 
ACE_Timer_Queue_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>&
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::iter (void)
{
  this->iterator_->first();
  return *this->iterator_;
}

/**
* Dummy version of expire to get rid of warnings in Sun CC 4.2
* Just call the expire of the base class.
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::expire ()
{
  return ACE_Timer_Queue_T<TYPE,FUNCTOR,ACE_LOCK>::expire ();
}

/**
* This is a specialized version of expire that is more suited for the
* internal data representation. 
*
* @param cur_time The time to expire timers up to.
*
* @return Number of timers expired
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK>::expire (const ACE_Time_Value& cur_time)
{
  ACE_TRACE ("ACE_Timer_Wheel_T::expire");
  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));

  int expcount = 0;
  ACE_Timer_Node_T<TYPE>* n = this->remove_first_expired(cur_time);

  while (n != 0) {
    ++ expcount;

    //ACE_ERROR((LM_ERROR, "Expiring %x\n", (long) n));

    this->upcall (n->get_type(), n->get_act(), cur_time);

    if (n->get_interval() > ACE_Time_Value::zero) {
      n->set_timer_value(cur_time + n->get_interval());
      this->reschedule(n);
    } else {
      this->free_node(n);
    }

    n = this->remove_first_expired(cur_time);
  }

  //ACE_ERROR((LM_ERROR, "Expired %d nodes\n", expcount));

  return expcount;
}

///////////////////////////////////////////////////////////////////////////
// ACE_Timer_Wheel_Iterator_T
 
/**
* Just initializes the iterator with a ACE_Timer_Wheel_T and then calls
* first() to initialize the rest of itself.
*
* @param wheel A reference for a timer queue to iterate over
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Wheel_Iterator_T<TYPE,FUNCTOR,ACE_LOCK>::ACE_Timer_Wheel_Iterator_T 
(Wheel& wheel)
: timer_wheel_ (wheel)
{
  this->first();
}


/**
* Destructor, at this level does nothing.
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Wheel_Iterator_T<TYPE,
FUNCTOR,
ACE_LOCK>::~ACE_Timer_Wheel_Iterator_T (void)
{
}


/**
* spokeitions the iterator at the first spokeition in the timing wheel
* that contains something. spoke_ will be set to the spokeition of this entry
* and current_node_ will point to the first entry in that spokeition.  Since
* this is an iterator,
*
* If the wheel is empty, spoke_ will be equal timer_wheel_.spoke_count_ and
* current_node_ would be 0.
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_Wheel_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::first (void)
{
  this->goto_next(0);
}


/**
* spokeitions the iterator at the next node.
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_Wheel_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::next (void)
{
  if (this->isdone())
    return;

  ACE_Timer_Node_T<TYPE>* n = this->current_node_->get_next();
  ACE_Timer_Node_T<TYPE>* root = this->timer_wheel_.spokes_[this->spoke_];
  if (n == root) {
    this->goto_next(this->spoke_ + 1);
  } else {
    this->current_node_ = n;
  }
}

/// Helper class for common functionality of next() and first()
template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_Wheel_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::goto_next(u_int start_spoke)
{
  // Find the first non-empty entry.
  u_int sc = this->timer_wheel_.spoke_count_;
  for (u_int i = start_spoke; i < sc; ++i)
  {
    ACE_Timer_Node_T<TYPE>* root = this->timer_wheel_.spokes_[i];
    ACE_Timer_Node_T<TYPE>* n = root->get_next();
    if (n != root)
    {
      this->spoke_ = i;
      this->current_node_ = n;
      return;
    }
  }
  // empty
  this->spoke_ = sc;
  this->current_node_ = 0;
}


/**
* @return True when we there isn't anymore items (when current_node_ == 0)
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_Wheel_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::isdone (void) const
{
  return this->current_node_ == 0;
}


/**
* @return The node at the current spokeition in the sequence or 0 if the wheel
*         is empty
*/
template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_Timer_Node_T<TYPE> *
ACE_Timer_Wheel_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::item (void)
{
  return this->current_node_;
}


#endif /* ACE_TIMER_WHEEL_T_C */
