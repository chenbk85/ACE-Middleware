// $Id$

#include "Performance_Test.h"

Performance_Test::Performance_Test (void)
  : n_lwps_ (0),
    orig_n_lwps_ (0)
{
}

void
Benchmark_Test::run_test (void)
{
  // Tell the threads that we are not finished.
  Benchmark_Performance::done (0);

  // Allow thread(s) to make progress.
  ACE_Thread_Manager::instance ()->resume_all ();

  ACE_Time_Value timeout (options.sleep_time ());

  ACE_DEBUG ((LM_DEBUG, "starting timer\n"));
  options.start_timer ();

  // Use Reactor as a timer (which can be interrupted by a signal).
  ACE_Reactor::run_event_loop (timeout);

  options.stop_timer ();
  ACE_DEBUG ((LM_DEBUG, "\nstopping timer\n"));

  // Stop thread(s) from making any further progress.
  ACE_Thread_Manager::instance ()->suspend_all ();

  // Tell the threads that we are finished.
  Benchmark::done (1);

  ACE_DEBUG ((LM_DEBUG, "------------------------------------------------------------------------\n"));
  ACE_DEBUG ((LM_DEBUG, "targ 0x%x (%s, %s, %s)\n"
	     "n_lwps_orig = %d, n_lwps_set = %d, n_lwps_end = %d\n",
	     options.t_flags (),
	     (options.t_flags () & THR_DETACHED) ? "THR_DETACHED" : "Not Detached",
	     (options.t_flags () & THR_BOUND)	? "THR_BOUND"    : "Not Bound",
	     (options.t_flags () & THR_NEW_LWP)  ? "THR_NEW_LWP"  : "No New_LWP",
	     this->orig_n_lwps_, this->n_lwps_, ACE_Thread::getconcurrency ()));

  int count = options.count ();
  float rate  = count / (float (options.sleep_time ()));

  ACE_DEBUG ((LM_DEBUG,
              "to count = %d\nrate = %.3f ops/sec, per operation = %.2f usec\n",
              count,
              rate,
              (1.0e6 / rate) / synch_count));
  options.print_results ();

  // Allow thread(s) to finish up.
  ACE_Thread_Manager::instance ()->resume_all ();

  // Wait for all the threads to exit.
  ACE_Thread_Manager::instance ()->wait ();
  options.init ();
}

// Initialize and run the benchmarks tests.

int
Benchmark_Test::init (int argc, char **argv)
{
  options.parse_args (argc, argv);
  return 0;
}
