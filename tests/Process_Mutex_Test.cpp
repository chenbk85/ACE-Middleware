// $Id$

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    Process_Mutex_Test.cpp
//
// = DESCRIPTION
//    Tests a Process Mutex shared between multiple processes
//
// = AUTHOR
//    Irfan Pyarali
//
// ============================================================================

#include "test_config.h"
#include "ace/Synch.h"
#include "ace/Process.h"
#include "ace/Get_Opt.h"

#if defined(__BORLANDC__) && __BORLANDC__ >= 0x0530
USELIB("..\ace\aced.lib");
//---------------------------------------------------------------------------
#endif /* defined(__BORLANDC__) && __BORLANDC__ >= 0x0530 */

static int release_mutex = 1;
static int child_process = 0;
static char *mutex_name = ACE_DEFAULT_MUTEX_A;

// Explain usage and exit.
static void
print_usage_and_die (void)
{
  ACE_DEBUG ((LM_DEBUG,
              "usage: %n [-d (don't release mutex)] [-c (child process)] [-n mutex name] \n"));
  ACE_OS::exit (1);
}

// Parse the command-line arguments and set options.
static void
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opt (argc, argv, "dcn:");

  int c;

  while ((c = get_opt ()) != -1)
    switch (c)
    {
    case 'd':
      release_mutex = 0;
      break;
    case 'c':
      child_process = 1;
      break;
    case 'n':
      mutex_name = get_opt.optarg;
      break;
    default:
      print_usage_and_die ();
      break;
  }
}

static void
acquire_release (void)
{
  ACE_Process_Mutex mutex (ACE_WIDE_STRING (mutex_name));
  // Make sure the constructor succeeded
  ACE_ASSERT (ACE_LOG_MSG->op_status () == 0);
  // Grab the lock
  ACE_ASSERT (mutex.acquire () == 0);
  ACE_DEBUG ((LM_DEBUG, "(%P) Mutex acquired %s\n", mutex_name));
  ACE_DEBUG ((LM_DEBUG, "(%P) Working....\n"));
  // work
  ACE_OS::sleep (2);
  // Check if we need to release the mutex
  if (release_mutex == 1)
    {
      ACE_DEBUG ((LM_DEBUG, "(%P) Releasing the mutex %s\n", mutex_name));
      ACE_ASSERT (mutex.release () == 0);
    }
}

int
main (int argc, char *argv[])
{
  parse_args (argc, argv);

  // Child process code
  if (child_process)
    {
      ACE_APPEND_LOG ("Process_Mutex_Test-children");
      acquire_release ();
      ACE_END_LOG;
    }
  else
    {
      ACE_START_TEST ("Process_Mutex_Test");
      ACE_INIT_LOG ("Process_Mutex_Test-children");

      ACE_Process_Options options;
      if (release_mutex == 0)
        options.command_line (__TEXT ("Process_Mutex_Test") ACE_PLATFORM_EXE_SUFFIX
                              __TEXT (" -c -n %s -d"), ACE_WIDE_STRING (mutex_name));
      else
        options.command_line (__TEXT ("Process_Mutex_Test") ACE_PLATFORM_EXE_SUFFIX
                              __TEXT (" -c -n %s"), ACE_WIDE_STRING (mutex_name));

      // Spawn ACE_MAX_PROCESSES processes that will contend for the
      // lock.
      ACE_Process servers[ACE_MAX_PROCESSES];
      size_t i;

      for (i = 0; i < ACE_MAX_PROCESSES; i++)
        {
          ACE_ASSERT (servers[i].spawn (options) != -1);
          ACE_DEBUG ((LM_DEBUG,
                      "Server forked with pid = %d.\n",
                      servers[i].getpid ()));
        }

      for (i = 0; i < ACE_MAX_PROCESSES; i++)
        {
#if defined (sun) && (defined (i386) || defined (__i386__))
          // On g++/Solaris 2.6/i386 on a two-CPU machine, the test
          // sometimes hangs because a child process hangs in either
          // destruction of static objects (without
          // ACE_HAS_NONSTATIC_OBJECT_MANAGER) or at the spawn above
          // (with ACE_HAS_NONSTATIC_OBJECT_MANAGER).  This hack masks
          // that problem by killing each child process that is still
          // alive.
          ACE_OS::sleep (2);
          ACE_OS::kill (servers[i].getpid (), 1);
#else
          // Wait for the process we created to exit.
          ACE_ASSERT (servers[i].wait () != -1);
#endif /* sun && (i386 || __i386__) */
          ACE_DEBUG ((LM_DEBUG,
                      "Server %d finished\n",
                      servers[i].getpid ()));
        }

      ACE_END_TEST;
    }

  return 0;
}
