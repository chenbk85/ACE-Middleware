/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Timer_Heap_T.h
 *
 *  $Id$
 *
 *  @author Doug Schmidt
 */
//=============================================================================


#ifndef ACE_TIMER_HEAP_T_H
#define ACE_TIMER_HEAP_T_H
#include "ace/pre.h"

#include "ace/Timer_Queue_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Free_List.h"
#include "ace/Unbounded_Set.h"

// Forward declaration
template <class TYPE, class FUNCTOR, class ACE_LOCK>
class ACE_Timer_Heap_T;

/**
 * @class ACE_Timer_Heap_Iterator_T
 *
 * @brief Iterates over an <ACE_Timer_Heap_T>.
 *
 * This is a generic iterator that can be used to visit every
 * node of a timer queue.  Be aware that it doesn't transverse
 * in the order of timeout values.
 */
template <class TYPE, class FUNCTOR, class ACE_LOCK>
class ACE_Timer_Heap_Iterator_T : public ACE_Timer_Queue_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>
{
public:
  /// Constructor.
  ACE_Timer_Heap_Iterator_T (ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK> &);

  /// Destructor.
  ~ACE_Timer_Heap_Iterator_T (void);

  /// Positions the iterator at the earliest node in the Timer Queue
  virtual void first (void);

  /// Positions the iterator at the next node in the Timer Queue
  virtual void next (void);

  /// Returns true when there are no more nodes in the sequence
  virtual int isdone (void) const;

  /// Returns the node at the current position in the sequence
  virtual ACE_Timer_Node_T<TYPE> *item (void);

protected:
  /// Pointer to the <ACE_Timer_Heap> that we are iterating over.
  ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK> &timer_heap_;

  /// Position in the array where the iterator is at
  size_t position_;
};

/**
 * @class ACE_Timer_Heap_T
 *
 * @brief Provides a very fast and predictable timer implementation.
 *
 * This implementation uses a heap-based callout queue of
 * absolute times.  Therefore, in the average and worst case,
 * scheduling, canceling, and expiring timers is O(log N) (where
 * N is the total number of timers).  In addition, we can also
 * preallocate as many <ACE_Timer_Nodes> as there are slots in
 * the heap.  This allows us to completely remove the need for
 * dynamic memory allocation, which is important for real-time
 * systems.
 */
template <class TYPE, class FUNCTOR, class ACE_LOCK>
class ACE_Timer_Heap_T : public ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK>
{
public:
  typedef ACE_Timer_Heap_Iterator_T<TYPE, FUNCTOR, ACE_LOCK> HEAP_ITERATOR;
  friend class ACE_Timer_Heap_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>;

  typedef ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK> INHERITED;

  // = Initialization and termination methods.
  /**
   * The Constructor creates a heap with <size> elements.  If
   * <preallocated> is non-0 then we'll pre-allocate all the memory
   * for the <ACE_Timer_Nodes>.  This saves time and is more
   * predictable (though it requires more space).  Otherwise, we'll
   * just allocate the nodes as we need them.  This can also take in a
   * upcall functor and freelist (if 0, then defaults will be created)
   */
  ACE_Timer_Heap_T (size_t size,
                    int preallocated = 0,
                    FUNCTOR *upcall_functor = 0,
                    ACE_Free_List<ACE_Timer_Node_T <TYPE> > *freelist = 0);

  /**
   * Default constructor. <upcall_functor> is the instance of the
   * FUNCTOR to be used by the queue. If <upcall_functor> is 0, Timer
   * Heap will create a default FUNCTOR.  <freelist> the freelist of
   * timer nodes.  If 0, then a default freelist will be created.  The default
   * size will be ACE_DEFAULT_TIMERS and there will be no preallocation.
   */
  ACE_Timer_Heap_T (FUNCTOR *upcall_functor = 0,
                    ACE_Free_List<ACE_Timer_Node_T <TYPE> > *freelist = 0);

  /// Destructor.
  virtual ~ACE_Timer_Heap_T (void);

  /// True if heap is empty, else false.
  virtual int is_empty (void) const;

  /// Returns the time of the earlier node in the Timer_Queue.
  virtual const ACE_Time_Value &earliest_time (void) const;

  /**
   * Schedule <type> that will expire after <delay> amount of time,
   * which is specified in absolute time.  If it expires then <act> is
   * passed in as the value to the <functor>.  If <interval> is != to
   * <ACE_Time_Value::zero> then it is used to reschedule the <type>
   * automatically, using relative time to the current <gettimeofday>.
   * This method returns a <timer_id> that uniquely identifies the the
   * <type> entry in an internal list.  This <timer_id> can be used to
   * cancel the timer before it expires.  The cancellation ensures
   * that <timer_ids> are unique up to values of greater than 2
   * billion timers.  As long as timers don't stay around longer than
   * this there should be no problems with accidentally deleting the
   * wrong timer.  Returns -1 on failure (which is guaranteed never to
   * be a valid <timer_id>).
   */
  virtual long schedule (const TYPE &type,
                         const void *act,
                         const ACE_Time_Value &delay,
                         const ACE_Time_Value &interval = ACE_Time_Value::zero);

  /**
   * Resets the interval of the timer represented by <timer_id> to
   * <interval>, which is specified in relative time to the current
   * <gettimeofday>.  If <interval> is equal to
   * <ACE_Time_Value::zero>, the timer will become a non-rescheduling
   * timer.  Returns 0 if successful, -1 if not.
   */
  virtual int reset_interval (long timer_id,
                              const ACE_Time_Value &interval);

  /**
   * Cancel all timer associated with <type>.  If <dont_call> is 0
   * then the <functor> will be invoked.  Returns number of timers
   * cancelled.
   */
  virtual int cancel (const TYPE &type,
                      int dont_call_handle_close = 1);

  /**
   * Cancel the single timer that matches the <timer_id> value (which
   * was returned from the <schedule> method).  If act is non-NULL
   * then it will be set to point to the ``magic cookie'' argument
   * passed in when the timer was registered.  This makes it possible
   * to free up the memory and avoid memory leaks.  If <dont_call> is
   * 0 then the <functor> will be invoked.  Returns 1 if cancellation
   * succeeded and 0 if the <timer_id> wasn't found.
   */
  virtual int cancel (long timer_id,
                      const void **act = 0,
                      int dont_call_handle_close = 1);

  /// Returns a pointer to this <ACE_Timer_Queue>'s iterator.
  virtual ACE_Timer_Queue_Iterator_T<TYPE, FUNCTOR, ACE_LOCK> &iter (void);

  /// Removes the earliest node from the queue and returns it
  ACE_Timer_Node_T <TYPE> *remove_first (void);

  /// Dump the state of an object.
  virtual void dump (void) const;

  /// Reads the earliest node from the queue and returns it.
  virtual ACE_Timer_Node_T<TYPE> *get_first (void);

protected:
  /// Reschedule an "interval" <ACE_Timer_Node>.
  virtual void reschedule (ACE_Timer_Node_T<TYPE> *);

  /// Factory method that allocates a new node (uses operator new if
  /// we're *not* preallocating, otherwise uses an internal freelist).
  virtual ACE_Timer_Node_T<TYPE> *alloc_node (void);

  /**
   * Factory method that frees a previously allocated node (uses
   * operatord delete if we're *not* preallocating, otherwise uses an
   * internal freelist).
   */
  virtual void free_node (ACE_Timer_Node_T<TYPE> *);

private:
  /// Remove and return the <slot>th <ACE_Timer_Node> and restore the
  /// heap property.
  ACE_Timer_Node_T<TYPE> *remove (size_t slot);

  /// Insert <new_node> into the heap and restore the heap property.
  void insert (ACE_Timer_Node_T<TYPE> *new_node);

  /**
   * Doubles the size of the heap and the corresponding timer_ids array.
   * If preallocation is used, will also double the size of the
   * preallocated array of ACE_Timer_Nodes.
   */
  void grow_heap (void);

  /// Restore the heap property, starting at <slot>.
  void reheap_up (ACE_Timer_Node_T<TYPE> *new_node,
                  size_t slot,
                  size_t parent);

  /// Restore the heap property, starting at <slot>.
  void reheap_down (ACE_Timer_Node_T<TYPE> *moved_node,
                    size_t slot,
                    size_t child);

  /// Copy <moved_node> into the <slot> slot of <heap_> and move
  /// <slot> into the corresponding slot in the <timer_id_> array.
  void copy (int slot, ACE_Timer_Node_T<TYPE> *moved_node);

  /**
   * Returns a timer id that uniquely identifies this timer.  This id
   * can be used to cancel a timer via the <cancel (int)> method.  The
   * timer id returned from this method will never == -1 to avoid
   * conflicts with other failure return values.
   */
  int timer_id (void);

  /// Pops and returns a new timer id from the freelist.
  int pop_freelist (void);

  /// Pushes <old_id> onto the freelist.
  void push_freelist (int old_id);

  /// Maximum size of the heap.
  size_t max_size_;

  /// Current size of the heap.
  size_t cur_size_;

  /// Iterator used to expire timers.
  HEAP_ITERATOR *iterator_;

  /**
   * Current contents of the Heap, which is organized as a "heap" of
   * <ACE_Timer_Node> *'s.  In this context, a heap is a "partially
   * ordered, almost complete" binary tree, which is stored in an
   * array.
   */
  ACE_Timer_Node_T<TYPE> **heap_;

  /**
   * An array of "pointers" that allows each <ACE_Timer_Node> in the
   * <heap_> to be located in O(1) time.  Basically, <timer_id_[i]>
   * contains the slot in the <heap_> array where an <ACE_Timer_Node>
   * * with timer id <i> resides.  Thus, the timer id passed back from
   * <schedule> is really an slot into the <timer_ids> array.  The
   * <timer_ids_> array serves two purposes: negative values are
   * treated as "pointers" for the <freelist_>, whereas positive
   * values are treated as "pointers" into the <heap_> array.
   */
  long *timer_ids_;

  /// "Pointer" to the first element in the freelist contained within
  /// the <timer_ids_> array, which is organized as a stack.
  long timer_ids_freelist_;

  /**
   * If this is non-0, then we preallocate <max_size_> number of
   * <ACE_Timer_Node> objects in order to reduce dynamic allocation
   * costs.  In auto-growing implementation, this points to the
   * last array of nodes allocated.
   */
  ACE_Timer_Node_T<TYPE> *preallocated_nodes_;

  /// This points to the head of the <preallocated_nodes_> freelist,
  /// which is organized as a stack.
  ACE_Timer_Node_T<TYPE> *preallocated_nodes_freelist_;

  /// Set of pointers to the arrays of preallocated timer nodes.
  /// Used to delete the allocated memory when required.
  ACE_Unbounded_Set<ACE_Timer_Node_T<TYPE> *> preallocated_node_set_;

  // = Don't allow these operations for now.
  ACE_UNIMPLEMENTED_FUNC (ACE_Timer_Heap_T (const ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK> &))
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK> &))
};

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE) && !defined(ACE_HAS_BROKEN_HPUX_TEMPLATES)
#include "ace/Timer_Heap_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE && !ACE_HAS_BROKEN_HPUX_TEMPLATES */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Timer_Heap_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include "ace/post.h"
#endif /* ACE_TIMER_HEAP_T_H */
