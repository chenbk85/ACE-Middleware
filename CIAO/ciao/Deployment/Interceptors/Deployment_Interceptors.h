// $Id$
/**
 * @file Deployment_Interceptors.h
 * @author William R. Otte <wotte@dre.vanderbilt.edu>
 *
 * Initial deployment interceptors for use in DAnCE.  
 */

#ifndef DEPLOYMENT_INTERCEPTORS_H
#define DEPLOYMENT_INTERCEPTORS_H

#include "DAnCE/DAnCE_DeploymentInterceptors_Base_Impl.h"
#include "orbsvcs/CosNamingC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"
#include "CIAO_Deployment_Interceptors_export.h"

namespace CIAO
{
  class CIAO_Deployment_Interceptors_Export CIAO_StoreReferences_i
    : public virtual DAnCE::DeploymentInterceptor_Base
  {
  public:
    // Constructor 
    
    CIAO_StoreReferences_i (void);
  
    // Destructor 
    virtual ~CIAO_StoreReferences_i (void);
  
    virtual
      void instance_pre_install (::Deployment::DeploymentPlan & plan,
                                 ::CORBA::ULong instanceRef);
  
    virtual
      void instance_post_install (const ::Deployment::DeploymentPlan & plan,
                                  ::CORBA::ULong instance_index,
                                  const ::CORBA::Any & instance_reference,
                                  const ::CORBA::Any & exception_thrown);

    virtual
      void configure(const Deployment::Properties&);
    
    CORBA::ORB_var orb_;
  private:
    CosNaming::NamingContext_var ctx_;
  };

  class CIAO_ReferenceLookup_i
    : public virtual DAnCE::DeploymentInterceptor_Base
  {
  public:
    // Constructor 
    CIAO_ReferenceLookup_i (void);
  
    // Destructor 
    virtual ~CIAO_ReferenceLookup_i (void);
  
    virtual
      void instance_pre_connect (::Deployment::DeploymentPlan & plan,
                                 ::CORBA::ULong connection_index,
                                 ::CORBA::Any & provided_reference);
  
    virtual
      void instance_post_connect (const ::Deployment::DeploymentPlan & plan,
                                  ::CORBA::ULong connectionRef,
                                  const ::CORBA::Any & exceptionThrown);

    virtual
      void configure(const Deployment::Properties&);
  };
}

extern "C"
{
  ::DAnCE::DeploymentInterceptor_ptr 
  CIAO_Deployment_Interceptors_Export create_CIAO_StoreReferences (void);
}

#endif
