// $Id$

#include "ace/OS.h"
#include "ace/Singleton.h"

#include "orbsvcs/Runtime_Scheduler.h"
#include "orbsvcs/Scheduler_Factory.h"

#if ! defined (__ACE_INLINE__)
#include "orbsvcs/Scheduler_Factory.i"
#endif /* __ACE_INLINE__ */

// initialize static class members
RtecScheduler::Scheduler_ptr ACE_Scheduler_Factory::server_ = 0;
ACE_Scheduler_Factory::Factory_Status ACE_Scheduler_Factory::status_ =
  ACE_Scheduler_Factory::UNINITIALIZED;
static int entry_count = -1;
static ACE_Scheduler_Factory::POD_RT_Info* rt_info = 0;

// Wrapper for builtin-type RtecScheduler::Preemption_Priority.
// For unknown reasons, Sunc C++ 4.2 refuses to compile ACE_TSS<TYPE>
// if TYPE is a built-in type:
// "ace/Synch_T.h", line 267: Error: Cannot have a return type of int* for ACE_TSS<int>::operator->() const.
//   Where: While specializing "ACE_TSS<int>".
//   Where: Specialized in non-template code.
struct ACE_Scheduler_Factory_Int {
  ACE_Scheduler_Factory_Int (const RtecScheduler::Preemption_Priority i = 0)
    : i_ (i)
  {
  }
  // Constructor.

  ACE_Scheduler_Factory_Int &
  operator= (const RtecScheduler::Preemption_Priority i)
  {
    i_ = i;
    return *this;
  }
  // Assignment operator.

  operator RtecScheduler::Preemption_Priority () { return i_; };
  // RtecScheduler::Preemption_Priority conversion.

private:
  RtecScheduler::Preemption_Priority i_;
  // The wrapped value.
};

// Helper struct, to encapsulate the singleton static server and
// ACE_TSS objects.  We can't use ACE_Singleton directly, because
// construction of ACE_Runbtime_Scheduler takes arguments.
struct ACE_Scheduler_Factory_Data
{
  ACE_Runtime_Scheduler scheduler_;
  // The static runtime scheduler.

  ACE_TSS<ACE_Scheduler_Factory_Int> preemption_priority_;
  // The dispatch queue number of the calling thread.  For access by
  // applications; must be set by either the application or Event
  // Channel.

  ACE_Scheduler_Factory_Data (void)
    : scheduler_ (entry_count, rt_info),
      preemption_priority_ ()
    {
    }
};

static ACE_Scheduler_Factory_Data *ace_scheduler_factory_data = 0;

int ACE_Scheduler_Factory::use_runtime (int ec,
                                        POD_RT_Info rti[])
{
  if (server_ != 0 || entry_count != -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "ACE_Scheduler_Factory::use_runtime - "
                         "server already configured\n"), -1);
    }

  entry_count = ec;
  rt_info = rti;
  status_ = ACE_Scheduler_Factory::RUNTIME;

  return 0;
}

static RtecScheduler::Scheduler_ptr
static_server ()
{
  RtecScheduler::Scheduler_ptr server_ = 0;

  // This isn't thread safe, but the static instance that it replaces
  // wasn't thread safe either.  Hola, Sr. Sandiego :-)  If it needs to
  // be made thread safe, it should be protected using double-checked
  // locking.
  if (! ace_scheduler_factory_data  &&
      (ace_scheduler_factory_data =
         ACE_Singleton<ACE_Scheduler_Factory_Data,
                       ACE_Null_Mutex>::instance ()) == 0)
        return 0;

  TAO_TRY
    {
      server_ = ace_scheduler_factory_data->scheduler_._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      ACE_DEBUG ((LM_DEBUG,
                  "ACE_Scheduler_Factory - configured static server\n"));
    }
  TAO_CATCHANY
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "ACE_Scheduler_Factory::config_runtime - "
                         "cannot allocate server\n"), 0);
    }
  TAO_ENDTRY;

  return server_;
}

int
ACE_Scheduler_Factory::use_config (CosNaming::NamingContext_ptr naming)
{
  return ACE_Scheduler_Factory::use_config (naming,
                                            "ScheduleService");
}

int
ACE_Scheduler_Factory::use_config (CosNaming::NamingContext_ptr naming,
                                   const char* name)
{
  if (server_ != 0 || entry_count != -1)
    {
      // No errors, runtime execution simply takes precedence over
      // config runs.
      return 0;
    }

  TAO_TRY
    {
      CosNaming::Name schedule_name (1);
      schedule_name.length (1);
      schedule_name[0].id = CORBA::string_dup (name);
      CORBA::Object_var objref =
        naming->resolve (schedule_name, TAO_TRY_ENV);
      TAO_CHECK_ENV;

      server_ =
        RtecScheduler::Scheduler::_narrow(objref.in (), TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }
  TAO_CATCHANY
    {
      server_ = 0;
      ACE_ERROR_RETURN ((LM_ERROR,
                         "ACE_Scheduler_Factory::use_config - "
                         " exception while resolving server\n"), -1);
    }
  TAO_ENDTRY;

  status_ = ACE_Scheduler_Factory::CONFIG;
  return 0;
}

RtecScheduler::Scheduler_ptr
ACE_Scheduler_Factory::server (void)
{
  if (server_ == 0 && entry_count != -1)
    {
      server_ = static_server ();
    }

  if (server_ == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "ACE_Scheduler_Factor::server - "
                         "no scheduling service configured\n"), 0);
    }
  return server_;
}

static char header[] =
"// This file was automatically generated by Scheduler_Factory\n"
"// before editing the file please consider generating it again\n"
"\n"
"#include \"orbsvcs/Scheduler_Factory.h\"\n"
"\n";

static char footer[] =
"\n"
"// This setups Scheduler_Factory to use the runtime version\n"
"static int scheduler_factory_setup = \n"
"  ACE_Scheduler_Factory::use_runtime (sizeof (infos)/sizeof (infos[0]),\n"
"                                      infos);\n"
"\n"
"// EOF\n";

static char start_infos[] =
"static ACE_Scheduler_Factory::POD_RT_Info infos[] = {\n";

static char end_infos[] =
"};\n"
"static int infos_size = sizeof(infos)/sizeof(infos[0])\n";

int ACE_Scheduler_Factory::dump_schedule
    (const RtecScheduler::RT_Info_Set& infos,
     const char* filename, const char* format_string)
{
  if (format_string == 0)
  {
    format_string = "{ \"%20s\", %10d, {%10d, %10d}, {%10d, %10d}, "
                    "{%10d, %10d}, %10d, "
                    "(RtecScheduler::Criticality) %d, "
                    "(RtecScheduler::Importance) %d, "
                    "{%10d, %10d}, %10d, %10d, %10d, %10d, "
                    "(RtecScheduler::Info_Type) %d }";
  }

  FILE* file = stdout;
  if (filename != 0)
    {
      file = ACE_OS::fopen (filename, "w");
      if (file == 0)
        {
          return -1;
        }
    }
  ACE_OS::fprintf(file, header);

  ACE_OS::fprintf(file, start_infos);
  for (u_int i = 0; i < infos.length (); ++i)
    {
      if (i != 0)
        {
          // Finish previous line
          ACE_OS::fprintf(file, ",\n");
        }
      const RtecScheduler::RT_Info& info = infos[i];
      // @@ TODO Eventually the TimeT structure will be a 64-bit
      // unsigned int, we will have to change this dump method then.
      ACE_OS::fprintf (file,
                       format_string,
                       (const char*) info.entry_point,
                       info.handle,
                       info.worst_case_execution_time.low,
                       info.worst_case_execution_time.high,
                       info.typical_execution_time.low,
                       info.typical_execution_time.high,
                       info.cached_execution_time.low,
                       info.cached_execution_time.high,
                       info.period,
                       info.criticality,
                       info.importance,
                       info.quantum.low,
                       info.quantum.high,
                       info.threads,
                       info.priority,
                       info.preemption_subpriority,
                       info.preemption_priority,
                       info.info_type);
    }
  // finish last line.
  ACE_OS::fprintf(file, "\n");
  ACE_OS::fprintf(file, end_infos);
  ACE_OS::fprintf(file, footer);
  ACE_OS::fclose (file);
  return 0;
}

RtecScheduler::Preemption_Priority
ACE_Scheduler_Factory::preemption_priority ()
{
  // Return whatever we've got.  The application or Event Channel is
  // responsible for making sure that it was set.
  return ace_scheduler_factory_data->preemption_priority_.ts_object () == 0  ?
    ACE_static_cast (RtecScheduler::Preemption_Priority, -1)  :
    ACE_static_cast (RtecScheduler::Preemption_Priority,
                     *ace_scheduler_factory_data->preemption_priority_);
}

void
ACE_Scheduler_Factory::set_preemption_priority
  (const RtecScheduler::Preemption_Priority preemption_priority)
{
  // Probably don't need this, because it should be safe to assume
  // that static_server () was called before this function.  But just
  // in case . . .
  if (! ace_scheduler_factory_data  &&
      (ace_scheduler_factory_data =
         ACE_Singleton<ACE_Scheduler_Factory_Data,
                       ACE_Null_Mutex>::instance ()) == 0)
        return;

  *ace_scheduler_factory_data->preemption_priority_ = preemption_priority;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Singleton<ACE_Scheduler_Factory_Data, ACE_Null_Mutex>;
template class ACE_TSS<ACE_Scheduler_Factory_Int>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Singleton<ACE_Scheduler_Factory_Data, ACE_Null_Mutex>
#pragma instantiate ACE_TSS<ACE_Scheduler_Factory_Int>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
