// $Id$

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    Signal_Test.cpp
//
// = DESCRIPTION
//      This program tests the signal handling capabilities of ACE on
//      a given OS platform.
//
// = AUTHOR
//    Douglas C. Schmidt <schmidt@cs.wustl.edu> 
//
// ============================================================================

#include "test_config.h"
#include "ace/Thread_Manager.h"
#include "ace/Process.h"
#include "ace/Signal.h"
#include "ace/Get_Opt.h"

ACE_RCSID(tests, Signal_Test, "$Id$")

#if !defined (ACE_LACKS_FORK) && !defined (ACE_LACKS_UNIX_SIGNALS)

// Global options.
static size_t n_iterations = 100000;

// Keeps track of whether we're the child or not.
static int child = 0;

// Keep track of the child pid.
static pid_t child_pid = 0;

// Coordinate the shutdown between threads.
static ACE_Atomic_Op<ACE_SYNCH_MUTEX, int> shut_down (0);

static int
handle_signal (int signum)
{
  ACE_DEBUG ((LM_DEBUG, 
              ASYS_TEXT ("(%P|%t) received signal %S\n"),
              signum));

  switch (signum)
    {
    case SIGINT:
      /* FALLTHRU */
    case SIGTERM:
      // Shut_Down our thread using <ACE_Thread_Manager::exit>.
      ACE_DEBUG ((LM_DEBUG, 
                  ASYS_TEXT ("(%P|%t) shutting down\n")));

      // Signal to the main thread to shut_down.
      shut_down = 1;

      // Bail out and close down.
      return -1;
      /* NOTREACHED */

    case SIGCHLD:
	  
      for (;;)
        {
          int child_exit_status;

          // This method simply "reaps" the exit status of the child
          // without blocking.  Note that it also decrements the count
          // of waiting children by one.
          pid_t pid = ACE_OS::wait (-1,
                                    &child_exit_status,
                                    WNOHANG);
          // Check to see if there are anymore children to reap.
          if (pid == -1) 
            break;

          ACE_DEBUG ((LM_DEBUG,
                      ASYS_TEXT ("(%P|%t) reaped child pid %d with exit status %d\n"),
                      pid,
                      child_exit_status));
        }

      // Shutdown and bail out.
      shut_down = 1;
      return -1;
      /* NOTREACHED */

    case SIGHUP:
      {
        // Shutdown the child.
          
        ACE_DEBUG ((LM_DEBUG,
                    ASYS_TEXT ("(%P|%t) killing child pid %d \n"),
                    child_pid));
        int result = ACE_OS::kill (child_pid, 
                                   SIGTERM);
        ACE_ASSERT (result != -1);

        // Continue looping on <sigwait> until the child process
        // exits.
        return 0;
      }
      /* NOTREACHED */
    case -1:
      ACE_ERROR_RETURN ((LM_ERROR,
                         ASYS_TEXT ("(%P|%t) %p\n"),
                         "sigwait"),
                        -1);
      /* NOTREACHED */
    default:
      ACE_ERROR_RETURN ((LM_ERROR, 
                         ASYS_TEXT ("(%P|%t) signal %S unexpected\n"),
                         signum),
                        -1);
      /* NOTREACHED */
    }
}

// This function handles signals synchronously.

static void *
synchronous_signal_handler (void *)
{
  ACE_Sig_Set sigset;

  // Register ourselves as a "dummy" signal handler so that this
  // processes' disposition isn't SIG_IGN (which is the default).
  ACE_Sig_Action sa ((ACE_SignalHandler) synchronous_signal_handler, SIGCHLD);
  ACE_UNUSED_ARG (sa);

  // Register signal handlers.
  if (child)
    {
      sigset.sig_add (SIGINT);
      sigset.sig_add (SIGTERM);
    }
  else
    {
      sigset.sig_add (SIGCHLD);
      sigset.sig_add (SIGHUP);
    }

  for (;;)
    // Block waiting for SIGINT, SIGCHLD, SIGTERM, or SIGHUP,
    // depending on whether we're the parent or child process.
    if (handle_signal (ACE_OS::sigwait (sigset)) == -1)
      break;

  return 0;
}

#if 1 // !defined (ACE_HAS_THREADS)
// This function arranges to handle signals asynchronously, i.e., if
// the platform lacks threads.

static void *
asynchronous_signal_handler (void *)
{
  ACE_Sig_Set sigset;

  // Register signal handlers.
  if (child)
    {
      sigset.sig_add (SIGINT);
      sigset.sig_add (SIGTERM);
    }
  else
    {
      sigset.sig_add (SIGCHLD);
      sigset.sig_add (SIGHUP);
    }

  // Register the <handle_signal> method to process all the signals in
  // <sigset>.
  ACE_Sig_Action sa (sigset,
                     (ACE_SignalHandler) handle_signal);
  ACE_UNUSED_ARG (sa);

  return 0;
}

#endif /* !ACE_HAS_THREADS */

// Function that runs in the child process in its own worker thread.

static void *
worker_child (void *)
{
  for (size_t i = 0; i < n_iterations; i++)
    {
      if (shut_down > 0)
        {
          ACE_DEBUG ((LM_DEBUG,
                      ASYS_TEXT ("(%P|%t) we've been shutdown!\n")));
          break;
        }

      // Every 100 iterations sleep for 2 seconds.
      if ((i % 100) == 0)
        {
          ACE_DEBUG ((LM_DEBUG,
                      ASYS_TEXT ("(%P|%t) sleeping for 2 seconds\n")));
          ACE_OS::sleep (2);
        }

      // After 1000 iterations sent a SIGHUP to our parent.
      if ((i % 1000) == 0)
        {
          pid_t pid = ACE_OS::getppid ();
          ACE_DEBUG ((LM_DEBUG,
                      ASYS_TEXT ("(%P|%t) sending SIGHUP to parent process %d\n"),
                      pid));
          int result = ACE_OS::kill (pid, SIGHUP);
          ACE_ASSERT (result != -1);
        }
    }

  ACE_DEBUG ((LM_DEBUG,
              ASYS_TEXT ("(%P|%t) finished running child\n")));
  return 0;
}

// This is the driver function that spawns threads to run the test for
// the parent and the child process.

static void
run_test (ACE_THR_FUNC worker)
{
#if 0 // defined (ACE_HAS_THREADS)
  // Block all signals.
  ACE_Sig_Set sigset (1);
  int result = ACE_OS::thr_sigsetmask (SIG_BLOCK,
                                       sigset,
                                       0);
  ACE_ASSERT (result != -1);

  result = ACE_Thread_Manager::instance ()->spawn 
    (worker, 0, THR_DETACHED);
  ACE_ASSERT (result != -1);
  
#if 0
  result = ACE_Thread_Manager::instance ()->spawn 
    (synchronous_signal_handler, 0, THR_DETACHED);
  ACE_ASSERT (result != -1);
#else
  synchronous_signal_handler (0);
#endif /* 0 */

  // Wait for the other thread to finish.
  result = ACE_Thread_Manager::instance ()->wait ();
  ACE_ASSERT (result != -1);
#else
  asynchronous_signal_handler (0);
  (*worker) (0);
#endif /* ACE_HAS_THREADS */
}

// This function runs the parent process in a separate worker thread
// for the <ACE_TEST_ONE_CHILDR> test.

static void *
worker_parent (void *)
{
  ACE_Process_Options options;

  // We're going to create a new process that runs this program again,
  // so we need to indicate that it's the child.
  options.command_line (ACE_TEXT (".")
                        ACE_DIRECTORY_SEPARATOR_STR
                        ACE_TEXT ("Signal_Test")
                        ACE_PLATFORM_EXE_SUFFIX
                        ACE_TEXT (" -c"));
  ACE_Process pm;
  child_pid = pm.spawn (options);

  ACE_ASSERT (child_pid != -1);

  // Perform a <wait> until our child process has exited.
  int result;
  
  while (shut_down == 0)
    {
      // Wait for a signal to arrive.
      if (ACE_OS::sigsuspend () == -1)
        ACE_ERROR ((LM_ERROR,
                    ASYS_TEXT ("(%P|%t) %p\n"),
                    ASYS_TEXT ("sigsuspend")));
      ACE_DEBUG ((LM_DEBUG,
                  ASYS_TEXT ("(%P|%t) got signal!\n")));
    }
  // Note that <result> should == -1 because our signal handler should
  // have "reaped" the SIGCHLD already.

  ACE_DEBUG ((LM_DEBUG,
              ASYS_TEXT ("(%P|%t) child done, result = %d, %p\n"),
              result,
              ASYS_TEXT ("wait")));
  return 0;
}

// Parse the command-line arguments and set options.

static void
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opt (argc, argv, "i:ch");

  int c; 

  while ((c = get_opt ()) != -1)
    switch (c)
    {
    case 'i':
      n_iterations = ACE_OS::atoi (get_opt.optarg);
      break;
    case 'c':
      {
        child = 1;
        break;
      }
    case 'h':
    default:
      ACE_DEBUG ((LM_DEBUG,
                  "(%P|%t) usage:\n"
		  ASYS_TEXT ("-i <iterations>\n")));
      break;
  }
}

int
main (int argc, ASYS_TCHAR *argv[])
{
  if (argc > 1)
    {
      ACE_APPEND_LOG (ASYS_TEXT ("Signal_Test-child"));
      parse_args (argc, argv);

      run_test (worker_child);
      ACE_END_LOG;
    }
  else
    {
      ACE_START_TEST (ASYS_TEXT ("Signal_Test"));
      ACE_INIT_LOG (ASYS_TEXT ("Signal_Test-child"));

      // Run the parent logic for the signal test.
      run_test (worker_parent);

      ACE_END_TEST;
      return 0;
    }
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Atomic_Op<ACE_SYNCH_MUTEX, int>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Atomic_Op<ACE_SYNCH_MUTEX, int>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#else
int 
main (int, ASYS_TCHAR *[])
{
  ACE_START_TEST (ASYS_TEXT ("Signal_Test"));
  ACE_ERROR ((LM_ERROR,
              ASYS_TEXT ("The ACE_Process capability is not supported on this platform\n")));
  ACE_END_TEST;
  return 0;
}
#endif /* !ACE_LACKS_FORK && !defined (ACE_LACKS_UNIX_SIGNALS) */
