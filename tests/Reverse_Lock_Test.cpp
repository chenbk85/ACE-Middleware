// $Id$

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    Reverse_Lock_Test.cpp
//
// = DESCRIPTION
//    This is a simple test to illustrate the functionality of
//    ACE_Reverse_Lock. The test acquires and releases mutexes. No
//    command line arguments are needed to run the test.
//
// = AUTHOR
//    Irfan Pyarali <irfan@cs.wustl.edu>
//
// ============================================================================

#include "test_config.h"
#include "ace/Synch_Traits.h"
#include "ace/Thread_Mutex.h"
#include "ace/Guard_T.h"
#include "ace/Reverse_Lock_T.h"

ACE_RCSID(tests, Reverse_Lock_Test, "$Id$")

typedef ACE_Reverse_Lock<ACE_SYNCH_MUTEX> REVERSE_MUTEX;

int
run_main (int, ACE_TCHAR *[])
{
  ACE_START_TEST (ACE_TEXT ("Reverse_Lock_Test"));

  ACE_SYNCH_MUTEX mutex;
  REVERSE_MUTEX reverse_mutex (mutex);

  {
    ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, monitor, mutex, -1);

    ACE_GUARD_RETURN (REVERSE_MUTEX, reverse_monitor, reverse_mutex, -1);
  }

  ACE_END_TEST;
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class ACE_Reverse_Lock<ACE_SYNCH_MUTEX>;
template class ACE_Guard<REVERSE_MUTEX>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Reverse_Lock<ACE_SYNCH_MUTEX>
#pragma instantiate ACE_Guard<REVERSE_MUTEX>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
