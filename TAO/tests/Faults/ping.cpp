// $Id$

#include "ace/Get_Opt.h"
#include "ping_i.h"
#include "ace/OS_NS_stdio.h"

ACE_RCSID(Faults, server, "$Id$")

const char *ior_output_file = "ping.ior";

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
main (int argc, char *argv[])
{
  try
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv, "");

      CORBA::Object_var poa_object =
        orb->resolve_initial_references("RootPOA");

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (poa_object.in ());

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager ();

      poa_manager->activate ();

      // create child poa with PERSISTENT policy
      CORBA::PolicyList policies;
      policies.length (2);
      policies[0] =
        root_poa->create_lifespan_policy(PortableServer::PERSISTENT);

      policies[1] =
        root_poa->create_implicit_activation_policy(PortableServer::IMPLICIT_ACTIVATION);

      PortableServer::POA_var persistent_poa =
        root_poa->create_POA("persistent",
                             poa_manager.in (),
                             policies);
      policies[0]->destroy ();
      policies[1]->destroy ();

      poa_manager->activate ();

      if (parse_args (argc, argv) != 0)
        return 1;

      PingObject_i *server_impl = 0;
      ACE_NEW_RETURN (server_impl,
		      PingObject_i (orb.in (),
                                    persistent_poa.in ()),
                      -1);

      PortableServer::ServantBase_var owner_transfer(server_impl);

      PingObject_var server =
        server_impl->_this ();

      CORBA::String_var ior =
        orb->object_to_string (server.in ());

      ACE_DEBUG ((LM_DEBUG, "Activated as <%s>\n", ior.in ()));

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

      ACE_DEBUG ((LM_DEBUG, "ping - event loop finished\n"));

      persistent_poa->destroy (1, 1);

      root_poa->destroy (1, 1);
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Exception caught in ping:");
      return 1;
    }

  return 0;
}
