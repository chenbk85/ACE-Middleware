// -*- C++ -*-

#include "ORB_DLL.h"
#include "ace/Service_Config.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_strings.h"

#include "ace/Get_Opt.h"
#include "ace/Log_Msg.h"

ACE_RCSID (tests,
           ORB_DLL,
           "$Id$")


//
Abstract_Worker::Abstract_Worker (const char* s)
  : ior_file_ (s)
{
}

//
Abstract_Worker::~Abstract_Worker (void)
{
}


//
Service_Config_ORB_DLL::Service_Config_ORB_DLL (void)
  : is_server_ (-1)
  , worker_ (0)
  , argv_ (0)
{
}

//
Service_Config_ORB_DLL::~Service_Config_ORB_DLL (void)
{
}

//
int
Service_Config_ORB_DLL::init (int argc, ACE_TCHAR *argv[])
{
  ACE_ARGV* tmp = 0;
  ACE_NEW_RETURN (tmp, ACE_ARGV (argv), -1);
  this->argv_.reset (tmp);

  ACE_Get_Opt get_opts (argc, argv, "cs");
  for (int c=0;((c = get_opts ()) != -1); )
    switch (c)
    {
    case 'c':
      this->is_server_ = 0;
      break;

    case 's':
      this->is_server_ = 1;
      break;
    }

  if (this->is_server_ < 0)
    ACE_ERROR_RETURN ((LM_ERROR, "(%P|%t) You must specify -c(lient) or -s(erver) argument. Aborting."), -1);

  Abstract_Worker* worker = 0;
  if (this->is_server_)
  {
    ACE_NEW_RETURN (worker, Server_Worker, -1);
  }
  else
  {
    ACE_NEW_RETURN (worker, Client_Worker, -1);
  }
  this->worker_.reset (worker);

#if defined (ACE_HAS_THREADS)
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("(%P|%t) About to activate %s, argv[%d]=\'%s\' ...\n"),
              this->worker_->kind (),
              this->argv_->argc (),
              this->argv_->buf ()));

  // Become an Active Object if more than one argument passed.
  // Two arguments indicate two "test objects" to be dynamically
  // loaded.
  return this->activate ();
#else
  ACE_ERROR_RETURN (("(%P|%t) Threading support is required for this test. Aborting."), -1);
#endif  /* ACE_HAS_THREADS */
}

int
Service_Config_ORB_DLL::svc (void)
{
  ACE_ASSERT (this->worker_.get () != 0);
  ACE_ASSERT (this->argv_.get () != 0);

  ACE_DECLARE_NEW_ENV;
  ACE_TRY
  {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) %@ %s is active, argv[%d]=\'%s\'\n"),
                this,
                this->worker_->kind (),
                this->argv_->argc (),
                this->argv_->buf ()));

    int ret = this->worker_->test_main (this->argv_->argc (),
                                        this->argv_->argv ()
                                        ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;

    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) %@ %s bowes out - so long, cruel world! (%d)\n"),
                this,
                this->worker_->kind (),
                ret));
    return ret;
  }
  ACE_CATCHANY
  {
    ACE_PRINT_EXCEPTION(ACE_ANY_EXCEPTION, ACE_TEXT("Failure:"));
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("(%P|%t) Aborting.\n")),
                       -1);
  }
  ACE_ENDTRY;

}


// Define our service for using with the Service Configurator
ACE_FACTORY_DEFINE (Service_Config_ORB_DLL, Service_Config_ORB_DLL)
