// $Id$

#include "IdUniquenessStrategyFactoryImpl.h"
#include "IdUniquenessStrategy.h"
#include "ace/Dynamic_Service.h"

ACE_RCSID (PortableServer,
           IdUniquenessStrategyFactoryImpl,
           "$Id$")

namespace TAO
{
  namespace Portable_Server
  {
    IdUniquenessStrategyFactoryImpl::~IdUniquenessStrategyFactoryImpl (void)
    {
    }
    IdUniquenessStrategy*
    IdUniquenessStrategyFactoryImpl::create (
      ::PortableServer::IdUniquenessPolicyValue value)
    {
      IdUniquenessStrategy* strategy = 0;

      switch (value)
      {
        case ::PortableServer::MULTIPLE_ID :
        {
          strategy =
            ACE_Dynamic_Service<IdUniquenessStrategy>::instance ("IdUniquenessStrategyMultiple");

          if (strategy == 0)
            ACE_ERROR ((LM_ERROR,
                        ACE_TEXT ("(%P|%t) %p\n"),
                        ACE_TEXT ("Unable to get ")
                        ACE_TEXT ("IdUniquenessStrategyMultiple")));

          break;
        }
        case ::PortableServer::UNIQUE_ID :
        {
          IdUniquenessStrategyFactory *strategy_factory =
            ACE_Dynamic_Service<IdUniquenessStrategyFactory>::instance ("IdUniquenessStrategyUniqueFactory");

          if (strategy_factory != 0)
            strategy = strategy_factory->create (value);
          else
            ACE_ERROR ((LM_ERROR,
                        ACE_TEXT ("(%P|%t) %p\n"),
                        ACE_TEXT ("Unable to get ")
                        ACE_TEXT ("IdUniquenessStrategyUniqueFactory")));

          break;
        }
      }

      return strategy;
    }

    void
    IdUniquenessStrategyFactoryImpl::destroy (
      IdUniquenessStrategy *strategy
      ACE_ENV_ARG_DECL)
    {
      switch (strategy->type ())
      {
        case ::PortableServer::MULTIPLE_ID :
        {
          // Noop
          break;
        }
        case ::PortableServer::UNIQUE_ID :
        {
          IdUniquenessStrategyFactory *strategy_factory =
            ACE_Dynamic_Service<IdUniquenessStrategyFactory>::instance ("IdUniquenessStrategyUniqueFactory");

          if (strategy_factory != 0)
            {
              strategy_factory->destroy (strategy ACE_ENV_ARG_PARAMETER);
              ACE_CHECK;
            }
          break;
        }
      }
    }

    ACE_STATIC_SVC_DEFINE (
        IdUniquenessStrategyFactoryImpl,
        ACE_TEXT ("IdUniquenessStrategyFactory"),
        ACE_SVC_OBJ_T,
        &ACE_SVC_NAME (IdUniquenessStrategyFactoryImpl),
        ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
        0
      )

    ACE_FACTORY_DEFINE (TAO_PortableServer, IdUniquenessStrategyFactoryImpl)

    #if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
    template class ACE_Dynamic_Service<IdUniquenessStrategyFactoryImpl>;
    #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
    #pragma instantiate ACE_Dynamic_Service<IdUniquenessStrategyFactoryImpl>
    #endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
  }
}
