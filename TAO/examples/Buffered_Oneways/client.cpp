// $Id$

// ================================================================
//
// = FILENAME
//     client.cpp
//
// = DESCRIPTION
//     This is a client that uses buffered oneways.
//
// = AUTHOR
//     Irfan Pyarali
//
// ================================================================

#include "testC.h"
#include "tao/debug.h"
#include "ace/Get_Opt.h"
#include "ace/Read_Buffer.h"

ACE_RCSID(Buffered_Oneways, client, "$Id$")

// Name of file contains ior.
static const char *IOR = "file://ior";

// Default iterations.
static CORBA::ULong iterations = 20;

// Default number of bytes to buffer before flushing.
static CORBA::Long message_bytes = -1;

// Default number of invocations to buffer before flushing.
static CORBA::Long message_count = iterations / 4;

// Default number of iterations before explicit flushing.
static CORBA::Long flush_count = -1;

// Time interval for implicit flushing (in milli seconds).
static long timeout = -1;

// Time interval between invocation (in milli seconds).
static long interval = 1000;

// Flag indicates whether to shutdown remote server or not upon client
// shutdown.
static int shutdown_server = 0;

static int
parse_args (int argc, char **argv)
{
  ACE_Get_Opt get_opts (argc, argv, "k:f:c:b:i:z:t:x");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'k':
        IOR = get_opts.optarg;
        break;

      case 'f':
        flush_count = ::atoi (get_opts.optarg);
        break;

      case 'c':
        message_count = ::atoi (get_opts.optarg);
        break;

      case 'b':
        message_bytes = ::atoi (get_opts.optarg);
        break;

      case 'i':
        iterations = ::atoi (get_opts.optarg);
        break;

      case 'z':
        interval = ::atoi (get_opts.optarg);
        break;

      case 't':
        timeout = ::atoi (get_opts.optarg);
        break;

      case 'x':
        shutdown_server = 1;
        break;

      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-k IOR "
                           "-f flush count "
                           "-c message count "
                           "-b message bytes "
                           "-i iterations "
                           "-z interval between calls "
                           "-t implicit flush timeout "
                           "-x shutdown server "
                           "\n",
                           argv [0]),
                          -1);
      }

  if (IOR == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Please specify the IOR for the servant\n"), -1);

  // Indicates successful parsing of command line.
  return 0;
}

int
main (int argc, char **argv)
{
  ACE_DECLARE_NEW_CORBA_ENV;

  ACE_TRY
    {
      // Initialize the ORB.
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc,
                         argv,
                         0,
                         ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Initialize options based on command-line arguments.
      int parse_args_result = parse_args (argc, argv);
      if (parse_args_result != 0)
        return parse_args_result;

      // Get an object reference from the argument string.
      CORBA::Object_var base =
        orb->string_to_object (IOR,
                               ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Try to narrow the object reference to a <test> reference.
      test_var test_object = test::_narrow (base.in (),
                                            ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Obtain PolicyCurrent.
      base = orb->resolve_initial_references ("PolicyCurrent",
                                              ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Narrow down to correct type.
      CORBA::PolicyCurrent_var policy_current =
        CORBA::PolicyCurrent::_narrow (base.in (),
                                       ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Setup the none sync scope policy, i.e., the ORB will buffer
      // oneways.
      Messaging::SyncScope sync_none = Messaging::SYNC_NONE;

      // Setup the none sync scope any.
      CORBA::Any sync_none_any;
      sync_none_any <<= sync_none;

      // Setup the none sync scope policy list.
      CORBA::PolicyList sync_none_policy_list (1);
      sync_none_policy_list.length (1);

      // Setup the none sync scope policy.
      sync_none_policy_list[0] =
        orb->create_policy (Messaging::SYNC_SCOPE_POLICY_TYPE,
                            sync_none_any,
                            ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Setup the none sync scope.
      policy_current->set_policy_overrides (sync_none_policy_list,
                                            CORBA::ADD_OVERRIDE,
                                            ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // We are now done with this policy.
      sync_none_policy_list[0]->destroy (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Start off with no constraints.
      TAO::BufferingConstraint buffering_constraint;
      buffering_constraint.mode = TAO::BUFFER_FLUSH;
      buffering_constraint.message_count = 0;
      buffering_constraint.message_bytes = 0;
      buffering_constraint.timeout = 0;

      // If valid <message_count>, set the implicit flushing to
      // account for queued messages.
      if (message_count != -1)
        {
          buffering_constraint.mode |= TAO::BUFFER_MESSAGE_COUNT;
          buffering_constraint.message_count = message_count;
        }

      // If valid <message_bytes>, set the implicit flushing to
      // account for queued bytes.
      if (message_bytes != -1)
        {
          buffering_constraint.mode |= TAO::BUFFER_MESSAGE_BYTES;
          buffering_constraint.message_bytes = message_bytes;
        }

      // If valid <timeout>, set the implicit flushing to account for
      // timeouts.
      if (timeout != -1)
        {
          buffering_constraint.mode |= TAO::BUFFER_TIMEOUT;
          buffering_constraint.timeout = timeout * 10000;
        }

      // Setup the buffering constraint any.
      CORBA::Any buffering_constraint_any;
      buffering_constraint_any <<= buffering_constraint;

      // Setup the buffering constraint policy list.
      CORBA::PolicyList buffering_constraint_policy_list (1);
      buffering_constraint_policy_list.length (1);

      // Setup the buffering constraint policy.
      buffering_constraint_policy_list[0] =
        orb->create_policy (TAO::BUFFERING_CONSTRAINT_POLICY_TYPE,
                            buffering_constraint_any,
                            ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Setup the constraints.
      policy_current->set_policy_overrides (buffering_constraint_policy_list,
                                            CORBA::ADD_OVERRIDE,
                                            ACE_TRY_ENV);
      ACE_TRY_CHECK;

      //
      // We use this policy again later. Therefore, we don't destroy
      // it right away.
      //

      // Setup the explicit flushing policy.
      TAO::BufferingConstraint buffering_flush;
      buffering_flush.mode = TAO::BUFFER_FLUSH;
      buffering_flush.message_count = 0;
      buffering_flush.message_bytes = 0;
      buffering_flush.timeout = 0;

      // Setup the buffering flush any.
      CORBA::Any buffering_flush_any;
      buffering_flush_any <<= buffering_flush;

      // Setup the buffering flush policy list.
      CORBA::PolicyList buffering_flush_policy_list (1);
      buffering_flush_policy_list.length (1);

      // Setup the buffering flush policy.
      buffering_flush_policy_list[0] =
        orb->create_policy (TAO::BUFFERING_CONSTRAINT_POLICY_TYPE,
                            buffering_flush_any,
                            ACE_TRY_ENV);
      ACE_TRY_CHECK;

      //
      // Explicit flushing policy will be used later.
      //

      for (CORBA::ULong i = 1; i <= iterations; ++i)
        {
          // Explicit flushing (is specified).
          if (flush_count != -1 &&
              i % flush_count == 0)
            {
              // Setup explicit flushing.
              policy_current->set_policy_overrides (buffering_flush_policy_list,
                                                    CORBA::ADD_OVERRIDE,
                                                    ACE_TRY_ENV);
              ACE_TRY_CHECK;

              ACE_DEBUG ((LM_DEBUG,
                          "client: Iteration %d @ %T\n",
                          i));

              // Invoke the oneway method.
              test_object->method (i,
                                   ACE_TRY_ENV);
              ACE_TRY_CHECK;

              // Reset buffering policy.
              policy_current->set_policy_overrides (buffering_constraint_policy_list,
                                                    CORBA::ADD_OVERRIDE,
                                                    ACE_TRY_ENV);
              ACE_TRY_CHECK;
            }
          else
            {
              ACE_DEBUG ((LM_DEBUG,
                          "client: Iteration %d @ %T\n",
                          i));

              // Invoke the oneway method.
              test_object->method (i,
                                   ACE_TRY_ENV);
              ACE_TRY_CHECK;
            }

          // Interval between successive calls.
          ACE_Time_Value sleep_interval (0,
                                         interval * 1000);

          orb->run (sleep_interval, ACE_TRY_ENV);
          ACE_TRY_CHECK;
        }

      // Shutdown server.
      if (shutdown_server)
        {
          test_object->shutdown (ACE_TRY_ENV);
          ACE_TRY_CHECK;
        }

      // We are done with the policy.
      buffering_constraint_policy_list[0]->destroy (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // We are done with the policy.
      buffering_flush_policy_list[0]->destroy (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Destroy the ORB.  On some platforms, e.g., Win32, the socket
      // library is closed at the end of main().  This means that any
      // socket calls made after main() fail. Hence if we wait for
      // static destructors to flush the queues, it will be too late.
      // Therefore, we use explicit destruction here and flush the
      // queues before main() ends.
      orb->destroy (ACE_TRY_ENV);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Exception caught:");
      return -1;
    }
  ACE_ENDTRY;

  ACE_CHECK_RETURN (-1);

  return 0;
}
