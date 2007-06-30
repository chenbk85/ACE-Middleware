// $Id$

#include "ace/Get_Opt.h"
#include "ace/OS_NS_stdio.h"
#include "test_i.h"
#include "Server_ORBInitializer.h"
#include "tao/ORBInitializer_Registry.h"

ACE_RCSID (Service_Context_Manipulation,
           server,
           "$Id$")

const char *ior_output_file = "test.ior";

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "o:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'o':
        ior_output_file = get_opts.opt_arg ();
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-o <iorfile>"
                           "\n",
                           argv [0]),
                          -1);
      }
  // Indicates sucessful parsing of the command line
  return 0;
}

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  try
    {
      Server_ORBInitializer * temp_initializer = 0;

      ACE_NEW_RETURN (temp_initializer,
                      Server_ORBInitializer,
                      -1);  // No exceptions yet!
      PortableInterceptor::ORBInitializer_var initializer =
        temp_initializer;

      PortableInterceptor::register_orb_initializer (initializer.in ());

      // Now we can create the ORB
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv);

      CORBA::Object_var poa_object =
        orb->resolve_initial_references ("RootPOA");

      if (CORBA::is_nil (poa_object.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Unable to initialize the POA.\n"),
                          1);

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (poa_object.in ());

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager ();

      poa_manager->activate ();

      if (parse_args (argc, argv) != 0)
        return 1;

      Visual_i server_impl (orb.in ());

      PortableServer::ObjectId_var id =
        root_poa->activate_object (&server_impl);

      // Create a second object to receive forwarded requests
      Visual_i forward_server_impl (orb.in ());

      PortableServer::ObjectId_var forward_id =
        root_poa->activate_object (&forward_server_impl);

      CORBA::Object_var forward_test_obj =
        root_poa->id_to_reference (forward_id.in ());

      Echo_Server_Request_Interceptor * server_interceptor =
        temp_initializer->server_interceptor ();

      if (server_interceptor == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "(%P|%t) Could not obtain reference to "
                           "server request interceptor.\n"),
                          -1);

      server_interceptor->forward_reference (forward_test_obj.in ());

      CORBA::Object_var test_obj =
        root_poa->id_to_reference (id.in ());

      Test_Interceptors::Visual_var server =
        Test_Interceptors::Visual::_narrow (test_obj.in ());

      CORBA::String_var ior =
        orb->object_to_string (server.in ());

      ACE_DEBUG ((LM_DEBUG,
                  "Test_Interceptors::Visual: <%s>\n",
                  ior.in ()));

      // If the ior_output_file exists, output the ior to it
      if (ior_output_file != 0)
        {
          FILE *output_file= ACE_OS::fopen (ior_output_file, "w");
          if (output_file == 0)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "Cannot open output file for writing IOR: %s",
                               ior_output_file),
                              1);
          ACE_OS::fprintf (output_file, "%s", ior.in ());
          ACE_OS::fclose (output_file);
        }

      orb->run ();

      ACE_DEBUG ((LM_DEBUG, "event loop finished\n"));

      root_poa->destroy (1, 1);
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Caught exception in server:");
      return 1;
    }

  return 0;
}
