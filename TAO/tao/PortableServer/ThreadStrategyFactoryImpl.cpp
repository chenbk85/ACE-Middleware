// $Id$

#include "ThreadStrategyFactoryImpl.h"
#include "ThreadStrategy.h"
#include "ace/Dynamic_Service.h"

ACE_RCSID (PortableServer,
           ThreadStrategyFactoryImpl,
           "$Id$")

namespace TAO
{
  namespace Portable_Server
  {
    ThreadStrategyFactoryImpl::~ThreadStrategyFactoryImpl (void)
    {
    }

    ThreadStrategy*
    ThreadStrategyFactoryImpl::create (
      ::PortableServer::ThreadPolicyValue value)
    {
      ThreadStrategy* strategy = 0;

      switch (value)
      {
        case ::PortableServer::SINGLE_THREAD_MODEL :
        {
          ThreadStrategyFactory *strategy_factory =
            ACE_Dynamic_Service<ThreadStrategyFactory>::instance ("ThreadStrategySingleFactory");

          if (strategy_factory != 0)
            strategy = strategy_factory->create (value);
          else
            ACE_ERROR ((LM_ERROR,
                        ACE_TEXT ("(%P|%t) %p\n"),
                        ACE_TEXT ("Unable to get ")
                        ACE_TEXT ("ThreadStrategySingleFactory")));

          break;
        }
        case ::PortableServer::ORB_CTRL_MODEL :
        {
          strategy =
            ACE_Dynamic_Service<ThreadStrategy>::instance ("ThreadStrategyORBControl");

          if (strategy == 0)
            ACE_ERROR ((LM_ERROR,
                        ACE_TEXT ("(%P|%t) %p\n"),
                        ACE_TEXT ("Unable to get ")
                        ACE_TEXT ("ThreadStrategyORBControl")));

          break;
        }
      }

      return strategy;
    }

    void
    ThreadStrategyFactoryImpl::destroy (
      ThreadStrategy *strategy
      ACE_ENV_ARG_DECL)
    {
      switch (strategy->type ())
      {
        case ::PortableServer::SINGLE_THREAD_MODEL :
        {
          ThreadStrategyFactory *strategy_factory =
            ACE_Dynamic_Service<ThreadStrategyFactory>::instance ("ThreadStrategySingleFactory");

          if (strategy_factory != 0)
            {
              strategy_factory->destroy (strategy ACE_ENV_ARG_PARAMETER);
              ACE_CHECK;
            }
          break;
        }
        case ::PortableServer::ORB_CTRL_MODEL :
        {
          // Noop
          break;
        }
      }
    }

    ACE_STATIC_SVC_DEFINE (
        ThreadStrategyFactoryImpl,
        ACE_TEXT ("ThreadStrategyFactory"),
        ACE_SVC_OBJ_T,
        &ACE_SVC_NAME (ThreadStrategyFactoryImpl),
        ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
        0
      )

    ACE_FACTORY_DEFINE (TAO_PortableServer, ThreadStrategyFactoryImpl)

    #if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

    template class ACE_Dynamic_Service<ThreadStrategyFactoryImpl>;

    #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

    #pragma instantiate ACE_Dynamic_Service<ThreadStrategyFactoryImpl>

    #endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
  }
}

