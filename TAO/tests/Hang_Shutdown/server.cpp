// $Id$

#include "test_i.h"
#include "ace/Get_Opt.h"
#include "ace/OS_NS_stdio.h"

namespace Test
{
  const char *ior_output_file = "server.ior";

  static int
  try_main (int argc,
            char *argv[])
  {

    try
      {
        CORBA::ORB_var orb =
          CORBA::ORB_init (argc,
                           argv,
                           "");

        CORBA::Object_var poa_object =
          orb->resolve_initial_references("RootPOA");

        PortableServer::POA_var root_poa =
          PortableServer::POA::_narrow (poa_object.in ());

        if (CORBA::is_nil (root_poa.in ()))
          ACE_ERROR_RETURN ((LM_ERROR,
                             " (%P|%t) Panic: nil RootPOA\n"),
                            1);

        PortableServer::POAManager_var poa_manager =
          root_poa->the_POAManager ();

        test_i *test_impl;
        ACE_NEW_RETURN (test_impl,
                        test_i (),
                        1);
        PortableServer::ServantBase_var owner_transfer (test_impl);

        Hang_var test =
          test_impl->_this ();

        CORBA::String_var ior =
          orb->object_to_string (test.in ());

        // If the ior_output_file exists, output the ior to it
        FILE *output_file= ACE_OS::fopen (ior_output_file, "w");
        if (output_file == 0)
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Cannot open output file for writing IOR: %s",
                             ior_output_file),
                            1);
        ACE_OS::fprintf (output_file, "%s", ior.in ());
        ACE_OS::fclose (output_file);

        poa_manager->activate ();

        ACE_Time_Value tv (10);

        orb->run (&tv);

        ACE_DEBUG ((LM_DEBUG,
                    "(%P|%t) server - event loop finished\n"));

        root_poa->destroy (1,
                           1);

        orb->destroy ();
      }
    catch (const CORBA::Exception& ex)
      {
        ex._tao_print_exception ("Caught CORBA exception \n");
        return -1;
      }

    return 0;
  }
}

int
main (int argc, char *argv[])
{
  return Test::try_main (argc, argv);
}
