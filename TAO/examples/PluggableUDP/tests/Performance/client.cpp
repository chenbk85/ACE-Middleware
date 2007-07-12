// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/examples/PluggableUDP/tests/Basic
//
// = FILENAME
//    client.cpp
//
// = DESCRIPTION
//    This is the client for the UDP performance test.
//
// = AUTHOR
//    Michael Kircher <Michael.Kircher@mchp.siemens.de>
//
// ============================================================================


#include "ace/Get_Opt.h"
#include "ace/Task.h"

#include "UDPC.h"

#include "UDP_i.h"
#include "UDP_PerformanceClient.h"

// The following include file forces DIOP to be linked into the
// executable and initialized for static builds.
#include "tao/Strategies/advanced_resource.h"

ACE_RCSID(Performance, client, "$Id$")

const char *ior = "file://test.ior";
ACE_UINT32 burst_messages = 1000;
ACE_UINT32 final_delta_micro_seconds = 10;


unsigned char performance_test = 0;

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "k:t:i:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'k':
        ior = get_opts.opt_arg ();
        break;
      case 't':
        burst_messages = ACE_OS::atoi (get_opts.opt_arg ());
        break;
      case 'i':
        final_delta_micro_seconds = ACE_OS::atoi (get_opts.opt_arg ());
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-d "
                           "-k <ior> "
                           "-t <burst_messages> "
                           "-i <final_delta_micro_seconds> "
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
        CORBA::ORB_init (argc, argv, "PerformanceClient");

      if (parse_args (argc, argv) != 0)
        return 1;

      CORBA::Object_var object =
        orb->string_to_object (ior);

      UDP_var udp_var =
        UDP::_narrow (object.in ());

      if (CORBA::is_nil (udp_var.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Object reference <%s> is nil\n",
                             ior),
                            1);
        }

      // Activate POA to handle the call back.

      CORBA::Object_var poa_object =
        orb->resolve_initial_references("RootPOA");

      if (CORBA::is_nil (poa_object.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Unable to initialize the POA.\n"),
                          1);

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (poa_object.in ());

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager ();

      poa_manager->activate ();

      // Instantiate reply handler
      UDP_i udp_i;

      // let it remember our ORB
      udp_i.orb (orb.in ());

      UDP_var udpHandler_var =
        udp_i._this ();

      // Instantiate client
      ACE_Task_Base* client = new UDP_PerformanceClient (orb.in (),
                                                         udp_var.in (),
                                                         &udp_i,
                                                         burst_messages,
                                                         final_delta_micro_seconds);

      // let the client run in a separate thread
      client->activate ();

      // ORB loop, will be shut down by our client thread
      orb->run ();  // Fetch responses

      ACE_DEBUG ((LM_DEBUG, "ORB finished\n"));

      client->wait ();

      root_poa->destroy (1, // ethernalize objects
                         0  // wait for completion
                         );

      orb->destroy ();

      // it is save to delete the client, because the client was actually
      // the one calling orb->shutdown () triggering the end of the ORB
      // event loop.
      delete client;

    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Caught exception:");
      return 1;
    }

  return 0;
}
