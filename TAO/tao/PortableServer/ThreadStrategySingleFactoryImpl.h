// -*- C++ -*-

//=============================================================================
/**
 *  @file ThreadStrategySingleFactoryImpl.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_PORTABLESERVER_THREADPOLICYSINGLESTRATEGYFACTORYIMPL_H
#define TAO_PORTABLESERVER_THREADPOLICYSINGLESTRATEGYFACTORYIMPL_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Config.h"
#include "tao/PortableServer/ThreadStrategyFactory.h"

#if (TAO_HAS_MINIMUM_POA == 0)

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export ThreadStrategySingleFactoryImpl
       : public virtual ThreadStrategyFactory
    {
    public:
      virtual ~ThreadStrategySingleFactoryImpl (void);

      /// Create a new thread strategy
      virtual ThreadStrategy* create (
        ::PortableServer::ThreadPolicyValue value);

      virtual void destroy (
        ThreadStrategy *strategy
        ACE_ENV_ARG_DECL);
    };

    ACE_STATIC_SVC_DECLARE_EXPORT (TAO_PortableServer, ThreadStrategySingleFactoryImpl)
    ACE_FACTORY_DECLARE (TAO_PortableServer, ThreadStrategySingleFactoryImpl)
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */

#include /**/ "ace/post.h"
#endif /* TAO_PORTABLESERVER_THREADPOLICYSINGLESTRATEGYFACTORYIMPL_H*/
