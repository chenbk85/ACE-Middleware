// -*- C++ -*-

//=============================================================================
/**
 *  @file    Adapter_Activator.h
 *
 *  $Id$
 */
//=============================================================================

#ifndef TAO_ADAPTER_ACTIVATOR_H
#define TAO_ADAPTER_ACTIVATOR_H
#include /**/ "ace/pre.h"

#include "tao/PortableServer/portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/AdapterActivatorC.h"

#if (TAO_HAS_MINIMUM_POA == 0)

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace PortableServer
{
  class POAManager;

  typedef POAManager *POAManager_ptr;
  typedef TAO_Objref_Var_T<POAManager> POAManager_var;
}

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export Adapter_Activator
      : public PortableServer::AdapterActivator
    {
    public:

      Adapter_Activator (PortableServer::POAManager_ptr poa_manager);

      CORBA::Boolean unknown_adapter (PortableServer::POA_ptr parent,
                                      const char *name
                                      ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException));

    protected:

      /// POA Manager
      PortableServer::POAManager_var poa_manager_;
    };
  }
}

TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* TAO_HAS_MINIMUM_POA == 0 */

#include /**/ "ace/post.h"
#endif /* TAO_ADAPTER_ACTIVATOR_H */
