// $Id$

#include "ace/Sched_Params.h"
#include "ace/Get_Opt.h"
#include "tao/corba.h"

#include "orbsvcs/CosNamingC.h"
#include "orbsvcs/Scheduler_Factory.h"



// This program simulates a scheduler configuration run, 
// and dumps the results of one scheduling in a C++ file.

int
main (int argc, char *argv[])
{
  const int operation_count = 8;

  // create initial data for supplier and consumer operations
  ACE_Scheduler_Factory::POD_RT_Info config_infos[operation_count] = {
		  // 20 Hz high criticality supplier
		  { "high_20_S",        // entry point
			0,                  // handle
			{0, 0},             // worst case execution time
			{0, 0},             // typical execution time (unused)
			{0, 0},             // cached execution time
			500000,             // period (100 ns)
			RtecScheduler::HIGH_CRITICALITY,   // criticality
			RtecScheduler::LOW_IMPORTANCE,     // importance
			{0, 0},             // quantum (unused)
			1,                  // threads 
			0,                  // OS priority 
			0,                  // Preemption subpriority
			0,                  // Preemption priority
			RtecScheduler::OPERATION           // info type
		  },
		  // 20 Hz low criticality supplier
		  { "low_20_S",         // entry point
			0,                  // handle
			{0, 0},             // worst case execution time
			{0, 0},             // typical execution time (unused)
			{0, 0},             // cached execution time
			500000,             // period (100 ns)
			RtecScheduler::LOW_CRITICALITY,    // criticality
			RtecScheduler::HIGH_IMPORTANCE,    // importance
			{0, 0},             // quantum (unused)
			1,                  // threads 
			0,                  // OS priority 
			0,                  // Preemption subpriority
			0,                  // Preemption priority
			RtecScheduler::OPERATION           // info type
		  },
		  // 10 Hz high criticality supplier
		  { "high_10_S",        // entry point
			0,                  // handle
			{0, 0},             // worst case execution time
			{0, 0},             // typical execution time (unused)
			{0, 0},             // cached execution time
			1000000,             // period (100 ns)
			RtecScheduler::HIGH_CRITICALITY,   // criticality
			RtecScheduler::LOW_IMPORTANCE,     // importance
			{0, 0},             // quantum (unused)
			1,                  // threads 
			0,                  // OS priority 
			0,                  // Preemption subpriority
			0,                  // Preemption priority
			RtecScheduler::OPERATION           // info type
		  },
		  // 10 Hz low criticality supplier
		  { "low_10_S",         // entry point
			0,                  // handle
			{0, 0},             // worst case execution time
			{0, 0},             // typical execution time (unused)
			{0, 0},             // cached execution time
			1000000,            // period (100 ns)
			RtecScheduler::LOW_CRITICALITY,    // criticality
			RtecScheduler::HIGH_IMPORTANCE,    // importance
			{0, 0},             // quantum (unused)
			1,                  // threads 
			0,                  // OS priority 
			0,                  // Preemption subpriority
			0,                  // Preemption priority
			RtecScheduler::OPERATION           // info type
		  },
		  // 20 Hz high criticality consumer
		  { "high_20_C",        // entry point
			0,                  // handle
			{0, 0},             // worst case execution time
			{0, 0},             // typical execution time (unused)
			{0, 0},             // cached execution time
			500000,             // period (100 ns)
			RtecScheduler::HIGH_CRITICALITY,   // criticality
			RtecScheduler::LOW_IMPORTANCE,     // importance
			{0, 0},             // quantum (unused)
			0,                  // threads 
			0,                  // OS priority 
			0,                  // Preemption subpriority
			0,                  // Preemption priority
			RtecScheduler::OPERATION           // info type
		  },
		  // 20 Hz low criticality consumer
		  { "low_20_C",         // entry point
			0,                  // handle
			{0, 0},             // worst case execution time
			{0, 0},             // typical execution time (unused)
			{0, 0},             // cached execution time
			500000,             // period (100 ns)
			RtecScheduler::LOW_CRITICALITY,    // criticality
			RtecScheduler::HIGH_IMPORTANCE,    // importance
			{0, 0},             // quantum (unused)
			0,                  // threads 
			0,                  // OS priority 
			0,                  // Preemption subpriority
			0,                  // Preemption priority
			RtecScheduler::OPERATION           // info type
		  },
		  // 10 Hz high criticality consumer
		  { "high_10_C",        // entry point
			0,                  // handle
			{0, 0},             // worst case execution time
			{0, 0},             // typical execution time (unused)
			{0, 0},             // cached execution time
			1000000,             // period (100 ns)
			RtecScheduler::HIGH_CRITICALITY,   // criticality
			RtecScheduler::LOW_IMPORTANCE,     // importance
			{0, 0},             // quantum (unused)
			0,                  // threads 
			0,                  // OS priority 
			0,                  // Preemption subpriority
			0,                  // Preemption priority
			RtecScheduler::OPERATION           // info type
		  },
		  // 10 Hz low criticality consumer
		  { "low_10_C",         // entry point
			0,                  // handle
			{0, 0},             // worst case execution time
			{0, 0},             // typical execution time (unused)
			{0, 0},             // cached execution time
			1000000,            // period (100 ns)
			RtecScheduler::LOW_CRITICALITY,    // criticality
			RtecScheduler::HIGH_IMPORTANCE,    // importance
			{0, 0},             // quantum (unused)
			0,                  // threads 
			0,                  // OS priority 
			0,                  // Preemption subpriority
			0,                  // Preemption priority
			RtecScheduler::OPERATION           // info type
		  }
  };


  TAO_TRY
    {
      // Initialize ORB.
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv, "internet", TAO_TRY_ENV);
      TAO_CHECK_ENV;

      CORBA::Object_var poa_object =
        orb->resolve_initial_references("RootPOA");
      if (CORBA::is_nil(poa_object.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Unable to initialize the POA.\n"),
                          1);

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (poa_object.in(), TAO_TRY_ENV);
      TAO_CHECK_ENV;

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      CORBA::Object_var naming_obj =
        orb->resolve_initial_references ("NameService");
      if (CORBA::is_nil(naming_obj.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Unable to initialize the POA.\n"),
                          1);

      CosNaming::NamingContext_var naming_context =
        CosNaming::NamingContext::_narrow (naming_obj.in (), TAO_TRY_ENV);
      TAO_CHECK_ENV;

      ACE_Scheduler_Factory::use_config (naming_context.in ());


	  // create and initialize RT_Infos in the scheduler,
	  // make second half of array depend on first half.
	  for (int i = 0; i < operation_count; ++i)
	  {
		// create the RT_Info
	    config_infos[i].handle = 
		  ACE_Scheduler_Factory::server ()->create (config_infos[i].entry_point,
		                                            TAO_TRY_ENV);

		// initialize the RT_Info
		ACE_Scheduler_Factory::server ()->
	      set (config_infos[i].handle, 
		       (RtecScheduler::Criticality) config_infos[i].criticality, 
               config_infos[i].worst_case_execution_time, 
               config_infos[i].typical_execution_time, 
               config_infos[i].cached_execution_time, 
               config_infos[i].period, 
               (RtecScheduler::Importance) config_infos[i].importance, 
               config_infos[i].quantum, 
               config_infos[i].threads, 
               config_infos[i].info_type, 
			   TAO_TRY_ENV);

        // make operations in second half dependant on
		// operations in the first half of the array,
		// and have each called twice as a oneway call
		if (i >= (operation_count / 2))
		{
		  ACE_Scheduler_Factory::server ()->
	        add_dependency (config_infos[i].handle, 
			                config_infos[i - (operation_count / 2)].handle, 
							2,                             // number of calls
							RtecScheduler::ONE_WAY_CALL,   // type of dependency
			                TAO_TRY_ENV);
		}
      }

      RtecScheduler::RT_Info_Set_var infos;

#if defined (__SUNPRO_CC)
      // Sun C++ 4.2 warns with the code below:
      //   Warning (Anachronism): Temporary used for non-const
      //   reference, now obsolete.
      //   Note: Type "CC -migration" for more on anachronisms.
      //   Warning (Anachronism): The copy constructor for argument
      //   infos of type RtecScheduler::RT_Info_Set_out should take
      //   const RtecScheduler::RT_Info_Set_out&.
      // But, this code is not CORBA conformant, because users should
      // not define instances of _out types.

      RtecScheduler::RT_Info_Set_out infos_out (infos);
      ACE_Scheduler_Factory::server ()->compute_scheduling
        (ACE_Sched_Params::priority_min (ACE_SCHED_FIFO,
                                         ACE_SCOPE_THREAD),
         ACE_Sched_Params::priority_max (ACE_SCHED_FIFO,
                                         ACE_SCOPE_THREAD),
         infos_out, TAO_TRY_ENV);
#else  /* ! __SUNPRO_CC */
      ACE_Scheduler_Factory::server ()->compute_scheduling
	(ACE_Sched_Params::priority_min (ACE_SCHED_FIFO,
					 ACE_SCOPE_THREAD),
	 ACE_Sched_Params::priority_max (ACE_SCHED_FIFO,
					 ACE_SCOPE_THREAD),
	 infos.out (), TAO_TRY_ENV);
#endif /* ! __SUNPRO_CC */

      TAO_CHECK_ENV;

      ACE_Scheduler_Factory::dump_schedule (infos.in (),
                                            "Sched_Conf_Runtime.h");
    }
  TAO_CATCH (CORBA::SystemException, sys_ex)
    {
      TAO_TRY_ENV.print_exception ("SYS_EX");
    }
  TAO_ENDTRY;

  return 0;
}

