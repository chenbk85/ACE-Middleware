//
// $Id$
//
#include "Server_Task.h"
#include "test_i.h"
#include "ace/OS_NS_time.h"
#include "ace/Manual_Event.h"

Server_Task::Server_Task (const char *output,
                          CORBA::ORB_ptr sorb,
                          ACE_Manual_Event &me,
                          ACE_Thread_Manager *thr_mgr)
  : ACE_Task_Base (thr_mgr)
    , output_ (output)
    , me_ (me)
    , sorb_ (CORBA::ORB::_duplicate (sorb))
{
}

int
Server_Task::svc (void)
{
 ACE_TRY_NEW_ENV
   {
     CORBA::Object_var poa_object =
       this->sorb_->resolve_initial_references("RootPOA"
                                               ACE_ENV_ARG_PARAMETER);

     PortableServer::POA_var root_poa =
       PortableServer::POA::_narrow (poa_object.in ()
                                     ACE_ENV_ARG_PARAMETER);

     if (CORBA::is_nil (root_poa.in ()))
       ACE_ERROR_RETURN ((LM_ERROR,
                          " (%P|%t) Panic: nil RootPOA\n"),
                         1);

     PortableServer::POAManager_var poa_manager =
       root_poa->the_POAManager ();

     poa_manager->activate ();

     Visual_i *vi = 0;
     ACE_NEW_RETURN (vi, Visual_i (sorb_.in ()), 1);
     PortableServer::ServantBase_var server_impl = vi;

     PortableServer::ObjectId_var id =
       root_poa->activate_object (server_impl.in()
                                  ACE_ENV_ARG_PARAMETER);

     CORBA::Object_var test_obj =
       root_poa->id_to_reference (id.in ()
                                  ACE_ENV_ARG_PARAMETER);

     Test_Interceptors::Visual_var server =
       Test_Interceptors::Visual::_narrow (test_obj.in ()
                                           ACE_ENV_ARG_PARAMETER);

     CORBA::String_var ior =
       sorb_->object_to_string (server.in () ACE_ENV_ARG_PARAMETER);

     // If the ior_output_file exists, output the ior to it
     if (output_ != 0)
       {
         FILE *output_file= ACE_OS::fopen (output_, "w");
         if (output_file == 0)
           ACE_ERROR_RETURN ((LM_ERROR,
                              "Cannot open output file for writing IOR: %s",
                              output_),
                              1);
         ACE_OS::fprintf (output_file, "%s", ior.in ());
         ACE_OS::fclose (output_file);
       }

     // Signal the main thread before we call orb->run ();
     this->me_.signal ();

     sorb_->run ();

     struct timespec ts = {0,250000000}; // quarter second
     ACE_OS::nanosleep (&ts);
     ACE_DEBUG ((LM_DEBUG, "(%P|%t) server task - event loop finished\n"));

     root_poa->destroy (1, 1 ACE_ENV_ARG_PARAMETER);

     this->sorb_->destroy ();
   }
 ACE_CATCHANY
   {
     ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                          "Exception caught in server task:");
     return 1;
   }
 ACE_ENDTRY;

 return 0;
}
