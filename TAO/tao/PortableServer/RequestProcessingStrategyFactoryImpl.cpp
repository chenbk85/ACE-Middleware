// $Id$

#include "RequestProcessingStrategyFactoryImpl.h"
#include "RequestProcessingStrategyAOMOnly.h"
#include "RequestProcessingStrategyDefaultServant.h"
#include "RequestProcessingStrategyServantLocator.h"
#include "RequestProcessingStrategyServantActivator.h"
#include "ace/Dynamic_Service.h"

ACE_RCSID (PortableServer,
           RequestProcessingStrategyFactoryImpl,
           "$Id$")

namespace TAO
{
  namespace Portable_Server
  {
    RequestProcessingStrategyFactoryImpl::~RequestProcessingStrategyFactoryImpl (void)
    {
    }

    RequestProcessingStrategy*
    RequestProcessingStrategyFactoryImpl::create (
        ::PortableServer::RequestProcessingPolicyValue value,
        ::PortableServer::ServantRetentionPolicyValue srvalue)
    {
      RequestProcessingStrategy* strategy = 0;
      RequestProcessingStrategyFactory *strategy_factory = 0;

      switch (value)
      {
        case ::PortableServer::USE_ACTIVE_OBJECT_MAP_ONLY :
        {
          strategy_factory =
            ACE_Dynamic_Service<RequestProcessingStrategyFactory>::instance ("RequestProcessingStrategyAOMOnlyFactory");

          break;
        }
        case ::PortableServer::USE_DEFAULT_SERVANT :
        {
          strategy_factory =
            ACE_Dynamic_Service<RequestProcessingStrategyFactory>::instance ("RequestProcessingStrategyDefaultServantFactory");

          break;
        }
        case ::PortableServer::USE_SERVANT_MANAGER :
        {
#if (TAO_HAS_MINIMUM_POA == 0)
          switch (srvalue)
          {
            case ::PortableServer::RETAIN :
            {
              strategy_factory =
                ACE_Dynamic_Service<RequestProcessingStrategyFactory>::instance ("RequestProcessingStrategyServantActivatorFactory");

              break;
            }
            case ::PortableServer::NON_RETAIN :
            {
              strategy_factory =
                ACE_Dynamic_Service<RequestProcessingStrategyFactory>::instance ("RequestProcessingStrategyServantLocatorFactory");

              break;
            }
          }
#endif /* TAO_HAS_MINIMUM_POA == 0 */
          break;
        }
      }

      if (strategy_factory != 0)
        strategy = strategy_factory->create (value, srvalue);
      else
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("(%P|%t) %p\n"),
                    ACE_TEXT ("Unable to get ")
                    ACE_TEXT ("RequestProcessingStrategyFactory")));

      return strategy;
    }

    void
    RequestProcessingStrategyFactoryImpl::destroy (
      RequestProcessingStrategy *strategy
      ACE_ENV_ARG_DECL)
    {
      RequestProcessingStrategyFactory *strategy_factory = 0;

      switch (strategy->type ())
      {
        case ::PortableServer::USE_ACTIVE_OBJECT_MAP_ONLY :
        {
          strategy_factory =
            ACE_Dynamic_Service<RequestProcessingStrategyFactory>::instance ("RequestProcessingStrategyAOMOnlyFactory");

          break;
        }
        case ::PortableServer::USE_DEFAULT_SERVANT :
        {
          strategy_factory =
            ACE_Dynamic_Service<RequestProcessingStrategyFactory>::instance ("RequestProcessingStrategyDefaultServantFactory");

          break;
        }
        case ::PortableServer::USE_SERVANT_MANAGER :
        {
#if (TAO_HAS_MINIMUM_POA == 0)
          switch (strategy->sr_type ())
          {
            case ::PortableServer::RETAIN :
            {
              strategy_factory =
                ACE_Dynamic_Service<RequestProcessingStrategyFactory>::instance ("RequestProcessingStrategyServantActivatorFactory");

              break;
            }
            case ::PortableServer::NON_RETAIN :
            {
              strategy_factory =
                ACE_Dynamic_Service<RequestProcessingStrategyFactory>::instance ("RequestProcessingStrategyServantLocatorFactory");
              break;
            }
          }
#endif /* TAO_HAS_MINIMUM_POA == 0 */
          break;
        }
      }

      if (strategy_factory != 0)
        {
          strategy_factory->destroy (strategy ACE_ENV_ARG_PARAMETER);
          ACE_CHECK;
        }
    }

    ACE_STATIC_SVC_DEFINE (
        RequestProcessingStrategyFactoryImpl,
        ACE_TEXT ("RequestProcessingStrategyFactory"),
        ACE_SVC_OBJ_T,
        &ACE_SVC_NAME (RequestProcessingStrategyFactoryImpl),
        ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
        0
      )

    ACE_FACTORY_DEFINE (TAO_PortableServer, RequestProcessingStrategyFactoryImpl)

    #if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
    template class ACE_Dynamic_Service<RequestProcessingStrategyFactoryImpl>;
    #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
    #pragma instantiate ACE_Dynamic_Service<RequestProcessingStrategyFactoryImpl>
    #endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
  }
}

