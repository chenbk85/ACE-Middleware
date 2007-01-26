//
// $Id$
//
#include "Process_Factory.h"
#include "Startup_Callback.h"
#include "ace/Process.h"

ACE_RCSID(Client_Leaks, Process_Factory, "$Id$")

Process_Factory::Process_Factory (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
  , shutdown_received_ (0)
{
}

int
Process_Factory::shutdown_received (void)
{
  return this->shutdown_received_;
}

Test::Process_ptr
Process_Factory::create_new_process (void)
  ACE_THROW_SPEC ((CORBA::SystemException,Test::Spawn_Failed))
{
  Startup_Callback *startup_callback_impl;
  ACE_NEW_THROW_EX (startup_callback_impl,
                    Startup_Callback,
                    CORBA::NO_MEMORY ());

  PortableServer::ServantBase_var owner_transfer(startup_callback_impl);

  Test::Startup_Callback_var startup_callback =
    startup_callback_impl->_this ();

  CORBA::String_var ior =
    this->orb_->object_to_string (startup_callback.in ());

  const char* argv[3] = {
    "child",
    ior.in (),
    0};

  ACE_Process_Options options;
#if !defined(ACE_WIN32)
  options.avoid_zombies (1);
#endif /* ACE_WIN32 */
  options.command_line (argv);

  ACE_Process child_process;
  pid_t pid =
    child_process.spawn (options);

  if (pid == -1)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "(%P|%t) Process_Factory::create_new_process, "
                  " spawn call failed (%d)\n",
                  errno));
      ACE_THROW_RETURN (Test::Spawn_Failed (), Test::Process::_nil ());
    }

  int process_has_started = 0;
  Test::Process_var the_process;
  for (int i = 0; i != 500 && !process_has_started; ++i)
    {
      ACE_Time_Value interval (0, 10000);
      this->orb_->perform_work (interval);

      process_has_started =
        startup_callback_impl->process_has_started (the_process.out ());
    }

  try
    {
      PortableServer::POA_var poa =
        startup_callback_impl->_default_POA ();
      PortableServer::ObjectId_var id =
        poa->servant_to_id (startup_callback_impl);
      poa->deactivate_object (id.in ());
    }
  catch (const CORBA::Exception&)
    {
    }

  if (process_has_started == 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "(%P|%t) Process_Factory::create_new_process, "
                  " timeout while waiting for child\n"));
      (void) child_process.terminate ();
      ACE_THROW_RETURN (Test::Spawn_Failed (), Test::Process::_nil ());
    }

  return the_process._retn ();
}

void
Process_Factory::noop (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

void
Process_Factory::shutdown (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->shutdown_received_ = 1;
  this->orb_->shutdown (0);
}
