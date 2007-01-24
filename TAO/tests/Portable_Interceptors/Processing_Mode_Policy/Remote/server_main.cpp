//$Id$
#include "Server_Task.h"
#include "ace/Get_Opt.h"
#include "ace/Argv_Type_Converter.h"
#include "ace/SString.h"
#include "ace/Manual_Event.h"
#include "Echo_Server_ORBInitializer.h"
#include "tao/ORBInitializer_Registry.h"
#include "server_interceptor.h"

const char *output = "test.ior";

ACE_CString proc_mode_str;

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "p:o:");
  int c;

  proc_mode_str.set ("LOCAL_AND_REMOTE");

  while ((c = get_opts ()) != -1)
  {
    switch (c)
      {
      case 'p':
        proc_mode_str.set (get_opts.opt_arg ());
        break;
      case 'o':
        output = get_opts.opt_arg ();
        break;
      case '?':
      default:
       return 0;
      }
  }
  // Indicates sucessful parsing of the command line
  return 0;
}

int
main (int argc, char *argv[])
{
  if (parse_args (argc,
                  argv) == -1)
    return -1;

  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      PortableInterceptor::ORBInitializer_ptr temp_initializer =
        PortableInterceptor::ORBInitializer::_nil ();

      // Set up our default expectations.
      CORBA::ULong expected_interceptor_check = 12;

      PortableInterceptor::ProcessingMode proc_mode =
                                   PortableInterceptor::LOCAL_AND_REMOTE;

      if (proc_mode_str == "LOCAL_ONLY")
        {
          proc_mode = PortableInterceptor::LOCAL_ONLY;
          ACE_DEBUG((LM_DEBUG,
                     "Using LOCAL_ONLY for server-side ProcessingMode.\n"));

          // Since all of the calls are remote, setting the server-side
          // ProcessingMode to LOCAL_ONLY will cause the server request
          // interceptor to not fire.  Thus, we expect 0 calls on the
          // server interceptor.
          expected_interceptor_check = 0;
        }
      else if (proc_mode_str == "REMOTE_ONLY")
        {
          proc_mode = PortableInterceptor::REMOTE_ONLY;
          ACE_DEBUG((LM_DEBUG,
                     "Using REMOTE_ONLY for server-side ProcessingMode.\n"));
        }
      else
        {
          ACE_DEBUG((LM_DEBUG,
                     "Using LOCAL_AND_REMOTE for server-side ProcessingMode.\n"));
        }

      ACE_NEW_RETURN (temp_initializer,
                      Echo_Server_ORBInitializer (proc_mode),
                      -1);  // No exceptions yet!
      PortableInterceptor::ORBInitializer_var orb_initializer =
        temp_initializer;

      PortableInterceptor::register_orb_initializer (orb_initializer.in ()
                                                     ACE_ENV_ARG_PARAMETER);

      ACE_Argv_Type_Converter atc (argc, argv);
      CORBA::ORB_var orb =
        CORBA::ORB_init (atc.get_argc (),
                         atc.get_TCHAR_argv (),
                         ""
                         ACE_ENV_ARG_PARAMETER);

      ACE_Manual_Event me;
      Server_Task server_task (output,
                               orb.in (),
                               me,
                               ACE_Thread_Manager::instance ());

      if (server_task.activate (THR_NEW_LWP | THR_JOINABLE,
                                1,
                                1) == -1)
        {
          ACE_ERROR ((LM_ERROR, "Error activating server task\n"));
        }

      ACE_Thread_Manager::instance ()->wait ();

      CORBA::ULong number_called =
        Echo_Server_Request_Interceptor::server_interceptor_check_;

      if (number_called != expected_interceptor_check)
        {
          ACE_ERROR ((LM_ERROR,
                      "(%P|%t) ERROR: Server-Side Interceptors not "
                      "called properly, called %d times, expected %d.\n",
                      number_called, expected_interceptor_check));
          return 1;
        }
    }
  ACE_CATCHANY
    {
      ACE_ERROR ((LM_ERROR,
                  "(%P|%t) ERROR: Some exception was caught in main().\n"));
      return 1;
    }
  ACE_ENDTRY;
  return 0;
}
