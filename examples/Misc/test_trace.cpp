// $Id$

// ============================================================================
//
// = LIBRARY
//    examples/Misc
//
// = FILENAME
//    test_trace.cpp
//
// = DESCRIPTION
//    This example illustrates how to use the ACE tracing feature and
//    also illustrates how to redirect the output to a file.
//
// = AUTHOR
//    Douglas C. Schmidt <schmidt@cs.wustl.edu> and 
//    Irfan Pyarali <irfan@cs.wustl.edu> 
//
// ============================================================================

// Enable tracing
#define ACE_NTRACE 0

#include "ace/Signal.h"
#include "ace/Task.h"

ACE_RCSID(Misc, test_trace, "$Id$")

class My_Task : public ACE_Task_Base
{
public:
  My_Task (size_t depth)
    : depth_ (depth)
  {
  }

  int recursive (size_t depth)
  {
    ACE_Trace _ ("int recursive (size_t depth)",
                 __LINE__,
                 __FILE__);
    
    if (depth > 0)
      return recursive (depth - 1);
    else
      return 0;
    // Destructor of <ACE_Trace> automatically called.
  }

  virtual int svc (void)
  {
    return this->recursive (this->depth_);
  }

private:
  size_t depth_;
  // Depth of the recursion.
};

extern "C"
void 
exithook (void)
{
  ACE_DEBUG ((LM_DEBUG,
              "we're outta here!\n"));
}

int 
main (int argc, char *argv[])
{
  const size_t MAX_DEPTH = argc == 1 ? 10 : atoi (argv[1]);

  ACE_OS::atexit (exithook);

  if (argc > 2)
    ACE_Trace::set_nesting_indent (ACE_OS::atoi (argv[2]));

  ACE_Trace _ ("int main (int argc, char *argv[])",
               __LINE__,
               __FILE__);

  // The following won't work on MVS OpenEdition...
  ACE_Sig_Action sig1 ((ACE_SignalHandler) ACE_Trace::start_tracing,
                       SIGUSR1);
  ACE_UNUSED_ARG (sig1);
  ACE_Sig_Action sig2 ((ACE_SignalHandler) ACE_Trace::stop_tracing,
                       SIGUSR2);
  ACE_UNUSED_ARG (sig2);

  My_Task task (MAX_DEPTH);

#if defined(ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  int n_threads = argc > 3 ? ACE_OS::atoi (argv[3]) : 4;

  if (task.activate (n_threads, THR_BOUND | THR_DETACHED) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "activate"),
                      -1);

  // Wait for all the threads to exit.
  ACE_Thread_Manager::instance ()->wait ();
#else
  const int MAX_ITERATIONS = argc > 3 ? ACE_OS::atoi (argv[3]) : 10;

  for (size_t i = 0; i < MAX_ITERATIONS; i++)
    task.svc ();
#endif /* ACE_MT_SAFE */

  // Destructor automatically called.
  return 0;
}

