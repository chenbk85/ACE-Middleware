// $Id$

#if !defined (ACE_TIMEPROBE_C)
#define ACE_TIMEPROBE_C

#include "ace/Timeprobe.h"

#if defined (ACE_ENABLE_TIMEPROBES)

#if !defined (__ACE_INLINE__)
#include "ace/Timeprobe.i"
#endif /* __ACE_INLINE__ */

#include "ace/High_Res_Timer.h"

template <class ACE_LOCK>
ACE_Timeprobe<ACE_LOCK>::ACE_Timeprobe (u_long size,
                                        ACE_Allocator *alloc)
  : timeprobes_ (0),
    allocator_ (alloc != 0 ? alloc : ACE_Allocator::instance ()),
    lock_ (),
    max_size_ (size),
    current_size_ (0)
{
  void *space = this->allocator_->malloc ((sizeof(timeprobe_t)) * this->max_size_);
  this->timeprobes_ = new ((timeprobe_t *) space) timeprobe_t[this->max_size_];
}

template <class ACE_LOCK>
ACE_Timeprobe<ACE_LOCK>::~ACE_Timeprobe (void)
{
  for (u_long i = 0; i < this->max_size_; i++)
    this->timeprobes_[i].timeprobe_t::~timeprobe_t ();

  this->allocator_->free (this->timeprobes_);
}

template <class ACE_LOCK> void
ACE_Timeprobe<ACE_LOCK>::timeprobe (u_long event)
{
  ACE_GUARD (ACE_LOCK, ace_mon, this->lock_);

  ACE_ASSERT (this->current_size_ < this->max_size_);

  this->timeprobes_[this->current_size_].event_.event_number_ = event;
  this->timeprobes_[this->current_size_].event_type_ = timeprobe_t::NUMBER;
  this->timeprobes_[this->current_size_].time_ = ACE_OS::gethrtime ();
  this->timeprobes_[this->current_size_].thread_ = ACE_OS::thr_self ();

  this->current_size_++;
}

template <class ACE_LOCK> void
ACE_Timeprobe<ACE_LOCK>::timeprobe (const char *event)
{
  ACE_GUARD (ACE_LOCK, ace_mon, this->lock_);

  ACE_ASSERT (this->current_size_ < this->max_size_);

  this->timeprobes_[this->current_size_].event_.event_description_ = event;
  this->timeprobes_[this->current_size_].event_type_ = timeprobe_t::STRING;
  this->timeprobes_[this->current_size_].time_ = ACE_OS::gethrtime ();
  this->timeprobes_[this->current_size_].thread_ = ACE_OS::thr_self ();

  this->current_size_++;
}

template <class ACE_LOCK> void
ACE_Timeprobe<ACE_LOCK>::reset (void)
{
  ACE_GUARD (ACE_LOCK, ace_mon, this->lock_);

  this->current_size_ = 0;
}

template <class ACE_LOCK> int
ACE_Timeprobe<ACE_LOCK>::event_descriptions (const char **descriptions,
                                             u_long minimum_id)
{
  ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  Event_Descriptions events;
  events.descriptions_ = descriptions;
  events.minimum_id_ = minimum_id;

  this->event_descriptions_.insert (events);

  return 0;
}

template <class ACE_LOCK> void
ACE_Timeprobe<ACE_LOCK>::print_times (void)
{
  ACE_DEBUG ((LM_DEBUG,
              "\nACE_Timeprobe; %d timestamps were recorded:\n",
              this->current_size_));

  if (this->current_size_ == 0)
    return;

  ACE_DEBUG ((LM_DEBUG,
              "\n%-50.50s %8.8s %13.13s\n\n",
              "Event",
              "thread",
              "usec"));

  ACE_DEBUG ((LM_DEBUG,
              "%-50.50s %8.8x %13.13s\n",
              this->find_description (0),
              this->timeprobes_[0].thread_,
              "START"));

  for (u_long i = 1; i < this->current_size_; i++)
    {
      ACE_hrtime_t time_difference = 
        this->timeprobes_[i].time_ - this->timeprobes_[i-1].time_;

      ACE_UINT32 elapsed_time_in_micro_seconds = 
        (ACE_UINT32) (time_difference / ACE_High_Res_Timer::global_scale_factor ());

      ACE_DEBUG ((LM_DEBUG,
                  "%-50.50s %8.8x %13u\n",
                  this->find_description (i),
                  this->timeprobes_[i].thread_,
                  (unsigned int) elapsed_time_in_micro_seconds));
    }
}

template <class ACE_LOCK> const char *
ACE_Timeprobe<ACE_LOCK>::find_description (u_long i)
{
  if (this->timeprobes_[i].event_type_ == timeprobe_t::STRING)
    return this->timeprobes_[i].event_.event_description_;
  else
    {
      EVENT_DESCRIPTIONS::iterator iterator = this->event_descriptions_.begin ();
      for (u_long j = 0;
           j < this->event_descriptions_.size () - 1;
           iterator++, j++)
        {
          EVENT_DESCRIPTIONS::iterator next_event_descriptions = iterator;
          next_event_descriptions++;
          
          if (this->timeprobes_[i].event_.event_number_ < (*next_event_descriptions).minimum_id_)
            break;
        }
      return (*iterator).descriptions_[this->timeprobes_[i].event_.event_number_ - (*iterator).minimum_id_];
    }
}

template <class Timeprobe>
ACE_Function_Timeprobe<Timeprobe>::ACE_Function_Timeprobe (Timeprobe &timeprobe, 
                                                           u_long event)
  : timeprobe_ (timeprobe),
    event_ (event)
{
  this->timeprobe_.timeprobe (this->event_);
}

template <class Timeprobe>
ACE_Function_Timeprobe<Timeprobe>::~ACE_Function_Timeprobe (void)
{
  this->timeprobe_.timeprobe (this->event_ + 1);
}

#endif /* ACE_ENABLE_TIMEPROBES */

#endif /* ACE_TIMEPROBE_C */
