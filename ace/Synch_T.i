/* -*- C++ -*- */
// $Id$

// Synch_T.i

#include "ace/Thread.h"

// Explicitly destroy the lock.
template <class ACE_LOCKING_MECHANISM> ACE_INLINE int 
ACE_Lock_Adapter<ACE_LOCKING_MECHANISM>::remove (void)
{
  return this->lock_.remove ();
}

// Block the thread until the lock is acquired.
template <class ACE_LOCKING_MECHANISM> ACE_INLINE int 
ACE_Lock_Adapter<ACE_LOCKING_MECHANISM>::acquire (void)
{
  return this->lock_.acquire ();
}

// Conditionally acquire the lock (i.e., won't block).

template <class ACE_LOCKING_MECHANISM> ACE_INLINE int
ACE_Lock_Adapter<ACE_LOCKING_MECHANISM>::tryacquire (void)
{
  return this->lock_.tryacquire ();
}

// Release the lock.

template <class ACE_LOCKING_MECHANISM> ACE_INLINE int 
ACE_Lock_Adapter<ACE_LOCKING_MECHANISM>::release (void)
{
  return this->lock_.release ();
}

// Block until the thread acquires a read lock.  If the locking
// mechanism doesn't support read locks then this just calls
// <acquire>.

template <class ACE_LOCKING_MECHANISM> ACE_INLINE int 
ACE_Lock_Adapter<ACE_LOCKING_MECHANISM>::acquire_read (void)
{
  return this->lock_.acquire_read ();
}

// Block until the thread acquires a write lock.  If the locking
// mechanism doesn't support read locks then this just calls
// <acquire>.

template <class ACE_LOCKING_MECHANISM> ACE_INLINE int 
ACE_Lock_Adapter<ACE_LOCKING_MECHANISM>::acquire_write (void)
{
  return this->lock_.acquire_write ();
}

// Conditionally acquire a read lock.  If the locking mechanism
// doesn't support read locks then this just calls <acquire>.

template <class ACE_LOCKING_MECHANISM> ACE_INLINE int
ACE_Lock_Adapter<ACE_LOCKING_MECHANISM>::tryacquire_read (void)
{
  return this->lock_.tryacquire_read ();
}

// Conditionally acquire a write lock.  If the locking mechanism
// doesn't support write locks then this just calls <acquire>.

template <class ACE_LOCKING_MECHANISM> ACE_INLINE int
ACE_Lock_Adapter<ACE_LOCKING_MECHANISM>::tryacquire_write (void)
{
  return this->lock_.tryacquire_write ();
}

#if defined (ACE_HAS_THREADS)

template<class MUTEX> ACE_INLINE int
ACE_Condition<MUTEX>::remove (void)
{
// ACE_TRACE ("ACE_Condition<MUTEX>::remove");

  // cond_destroy() is called in a loop if the condition variable is
  // BUSY.  This avoids a condition where a condition is signaled and
  // because of some timing problem, the thread that is to be signaled
  // has called the cond_wait routine after the signal call.  Since
  // the condition signal is not queued in any way, deadlock occurs.

  int result = 0;

  while ((result = ACE_OS::cond_destroy (&this->cond_)) == -1
	 && errno == EBUSY)
    {
      ACE_OS::cond_broadcast (&this->cond_);
      ACE_OS::thr_yield ();
    }

  return result;
}

template<class MUTEX> ACE_INLINE MUTEX &
ACE_Condition<MUTEX>::mutex (void)
{
// ACE_TRACE ("ACE_Condition<MUTEX>::mutex");
  return this->mutex_;
}

template <class MUTEX> ACE_INLINE int 
ACE_Condition<MUTEX>::signal (void)
{
// ACE_TRACE ("ACE_Condition<MUTEX>::signal");
  return ACE_OS::cond_signal (&this->cond_);
}

template <class MUTEX> ACE_INLINE int
ACE_Condition<MUTEX>::broadcast (void)
{
// ACE_TRACE ("ACE_Condition<MUTEX>::broadcast");
  return ACE_OS::cond_broadcast (&this->cond_);
}

#endif /* ACE_HAS_THREADS */

#if !(defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION)))
template <class TYPE> ACE_INLINE
ACE_TSS<TYPE>::ACE_TSS (TYPE *)
{
}

template <class TYPE> ACE_INLINE TYPE *
ACE_TSS<TYPE>::ts_object (void) const
{ 
  return (TYPE *) &this->type_;
}

template <class TYPE> ACE_INLINE TYPE *
ACE_TSS<TYPE>::ts_object (TYPE *) 
{ 
  return &this->type_;
}

template <class TYPE> ACE_INLINE TYPE *
ACE_TSS<TYPE>::ts_get (void) const
{ 
  return (TYPE *) &this->type_;
}

#endif /* ! (defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION))) */
