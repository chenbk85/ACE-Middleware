// $Id$

#include "ace/Countdown_Time.h"

#if !defined (__ACE_INLINE__)
#include "ace/Countdown_Time.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Countdown_Time::ACE_Countdown_Time (ACE_Time_Value *max_wait_time)
  : max_wait_time_ (max_wait_time),
    stopped_ (false),
    gettimeofday_ (0)
{
  this->start ();
}

ACE_Countdown_Time::ACE_Countdown_Time (ACE_Time_Value *max_wait_time,
                                        ACE_Time_Value (*gettimeofday)(void))
: max_wait_time_ (max_wait_time),
  stopped_ (false),
  gettimeofday_ (gettimeofday)
{
  this->start ();
}

ACE_Countdown_Time::~ACE_Countdown_Time (void)
{
  this->stop ();
}

void
ACE_Countdown_Time::start (void)
{
  if (this->max_wait_time_ != 0)
    {
      this->start_time_ = this->gettimeofday ();
      this->stopped_ = false;
    }
}

void
ACE_Countdown_Time::stop (void)
{
  if (this->max_wait_time_ != 0 && !this->stopped_)
    {
      ACE_Time_Value const elapsed_time =
        this->gettimeofday () - this->start_time_;

      if (elapsed_time >= ACE_Time_Value::zero &&
          *this->max_wait_time_ > elapsed_time)
        {
          *this->max_wait_time_ -= elapsed_time;
        }
      else
        {
          // Used all of timeout.
          *this->max_wait_time_ = ACE_Time_Value::zero;
          // errno = ETIME;
        }
      this->stopped_ = true;
    }
}

ACE_END_VERSIONED_NAMESPACE_DECL
