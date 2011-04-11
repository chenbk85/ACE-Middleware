// -*- C++ -*-
// $Id$

/**
 * @file Handler_A.h
 * @author William R. Otte <wotte@dre.vanderbilt.edu>
 *
 * Installation handler implementation for spawning LocalityManagers.
 */

#ifndef DANCE_INTERCEPTOR_HANDLER_H
#define DANCE_INTERCEPTOR_HANDLER_H

#include "dance/DAnCE_LocalityManagerS.h"
#include "dance/DAnCE_Utility.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "CircularDependency_export.h"
#include "tao/LocalObject.h"

namespace DAnCE
{
  class CircularDependency_Export Handler_A_Impl
    : public virtual DAnCE::InstanceDeploymentHandler,
      public virtual ::CORBA::LocalObject
  {
  public:
    // Constructor
    Handler_A_Impl (void);

    // Destructor
    virtual ~Handler_A_Impl (void);

    virtual
      char * instance_type (void);

    ::CORBA::StringSeq *
        dependencies (void);

    virtual
      void install_instance (const ::Deployment::DeploymentPlan & plan,
                             ::CORBA::ULong instanceRef,
                             ::CORBA::Any_out instance_reference);

    virtual
      void activate_instance (const ::Deployment::DeploymentPlan & ,
                              ::CORBA::ULong ,
                              const ::CORBA::Any &) {};
    virtual
      void passivate_instance (const ::Deployment::DeploymentPlan & ,
                               ::CORBA::ULong ,
                               const ::CORBA::Any &) {};

    virtual
      void remove_instance (const ::Deployment::DeploymentPlan & plan,
                            ::CORBA::ULong instanceRef,
                            const ::CORBA::Any & instance_reference);

    virtual
      void provide_endpoint_reference (const ::Deployment::DeploymentPlan &,
                                       ::CORBA::ULong,
                                       ::CORBA::Any_out) {};

    virtual
      void connect_instance (const ::Deployment::DeploymentPlan & plan,
                             ::CORBA::ULong connectionRef,
                             const ::CORBA::Any & provided_reference);

    virtual
      void disconnect_instance (const ::Deployment::DeploymentPlan & plan,
                                ::CORBA::ULong connectionRef);

    virtual
      void instance_configured (const ::Deployment::DeploymentPlan &,
                                ::CORBA::ULong) {};

    virtual
      void configure(const Deployment::Properties&);

    virtual void close (void);

  private:
    static const char *instance_type_;
  };
}

extern "C"
{
  ::DAnCE::InstanceDeploymentHandler_ptr
  CircularDependency_Export create_Handler_A (void);
}

#endif
