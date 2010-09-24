// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.2
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:1344

#include "CIF_Component_exec.h"

namespace CIAO_CIF_CIF_Provider_Impl
{
  
  // TAO_IDL - Generated from
  // be/be_visitor_component/facet_exs.cpp:75
  //============================================================
  // Facet Executor Implementation Class: provide_cif_foo_exec_i
  //============================================================
  
  provide_cif_foo_exec_i::provide_cif_foo_exec_i (
        ::CIF::CCM_CIF_Provider_Context_ptr ctx)
    : ciao_context_ (
        ::CIF::CCM_CIF_Provider_Context::_duplicate (ctx))
  {
  }
  
  provide_cif_foo_exec_i::~provide_cif_foo_exec_i (void)
  {
  }
  
  // Operations from ::CIF::foo
  
  void
  provide_cif_foo_exec_i::do_foo (void)
  {
    /* Your code here. */
  }
  
  // TAO_IDL - Generated from
  // be/be_visitor_component/facet_exs.cpp:75
  //============================================================
  // Facet Executor Implementation Class: provide_cif_derived_foo_exec_i
  //============================================================
  
  provide_cif_derived_foo_exec_i::provide_cif_derived_foo_exec_i (
        ::CIF::CCM_CIF_Provider_Context_ptr ctx)
    : ciao_context_ (
        ::CIF::CCM_CIF_Provider_Context::_duplicate (ctx))
  {
  }
  
  provide_cif_derived_foo_exec_i::~provide_cif_derived_foo_exec_i (void)
  {
  }
  
  // Operations from ::CIF::derived_foo
  
  void
  provide_cif_derived_foo_exec_i::do_foo (void)
  {
    /* Your code here. */
  }
  
  void
  provide_cif_derived_foo_exec_i::do_derived_foo (void)
  {
    /* Your code here. */
  }
  
  //============================================================
  // Component Executor Implementation Class: CIF_Provider_exec_i
  //============================================================
  
  CIF_Provider_exec_i::CIF_Provider_exec_i (void)
    : provider_id_(4321)
  {
  }
  
  CIF_Provider_exec_i::~CIF_Provider_exec_i (void)
  {
  }
  
  // Supported operations and attributes.
  
  // Component attributes and port operations.
  
  ::CIF::CCM_foo_ptr
  CIF_Provider_exec_i::get_provide_cif_foo (void)
  {
    if ( ::CORBA::is_nil (this->ciao_provide_cif_foo_.in ()))
      {
        provide_cif_foo_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          provide_cif_foo_exec_i (
            this->ciao_context_.in ()),
          ::CIF::CCM_foo::_nil ());
        
        this->ciao_provide_cif_foo_ = tmp;
      }
    
    return
      ::CIF::CCM_foo::_duplicate (
        this->ciao_provide_cif_foo_.in ());
  }
  
  ::CIF::CCM_derived_foo_ptr
  CIF_Provider_exec_i::get_provide_cif_derived_foo (void)
  {
    if ( ::CORBA::is_nil (this->ciao_provide_cif_derived_foo_.in ()))
      {
        provide_cif_derived_foo_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          provide_cif_derived_foo_exec_i (
            this->ciao_context_.in ()),
          ::CIF::CCM_derived_foo::_nil ());
        
        this->ciao_provide_cif_derived_foo_ = tmp;
      }
    
    return
      ::CIF::CCM_derived_foo::_duplicate (
        this->ciao_provide_cif_derived_foo_.in ());
  }
  
  ::CORBA::Short
  CIF_Provider_exec_i::provider_id (void)
  {
    return this->provider_id_;
  }
  
  void
  CIF_Provider_exec_i::provider_id (
    ::CORBA::Short provider_id)
  {
    this->provider_id_ = provider_id;
  }
  
  // Operations from Components::SessionComponent.
  
  void
  CIF_Provider_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::CIF::CCM_CIF_Provider_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }
  
  void
  CIF_Provider_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }
  
  void
  CIF_Provider_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }
  
  void
  CIF_Provider_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }
  
  void
  CIF_Provider_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }
  
  extern "C" CIF_COMPONENT_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_CIF_CIF_Provider_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_NORETURN (
      retval,
      CIF_Provider_exec_i);
    
    return retval;
  }
}

namespace CIAO_CIF_CIF_User_Impl
{
  //============================================================
  // Component Executor Implementation Class: CIF_User_exec_i
  //============================================================
  
  CIF_User_exec_i::CIF_User_exec_i (void)
    : user_id_ (1234)
  {
  }
  
  CIF_User_exec_i::~CIF_User_exec_i (void)
  {
  }
  
  // Supported operations and attributes.
  
  // Component attributes and port operations.
  
  void
  CIF_User_exec_i::push_consume_do_something (
    ::CIF::DoSomething * /* ev */)
  {
    /* Your code here. */
  }
  
  ::CORBA::Short
  CIF_User_exec_i::user_id (void)
  {
    return this->user_id_;
  }
  
  void
  CIF_User_exec_i::user_id (
    ::CORBA::Short user_id)
  {
    this->user_id_ = user_id;
  }
  
  // Operations from Components::SessionComponent.
  
  void
  CIF_User_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::CIF::CCM_CIF_User_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }
  
  void
  CIF_User_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }
  
  void
  CIF_User_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }
  
  void
  CIF_User_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }
  
  void
  CIF_User_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }
  
  extern "C" CIF_COMPONENT_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_CIF_CIF_User_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_NORETURN (
      retval,
      CIF_User_exec_i);
    
    return retval;
  }
}

namespace CIAO_CIF_CIF_User_Impl
{
  //============================================================
  // Home Executor Implementation Class: CIF_UserHome_exec_i
  //============================================================
  
  CIF_UserHome_exec_i::CIF_UserHome_exec_i (void)
  {
  }
  
  CIF_UserHome_exec_i::~CIF_UserHome_exec_i (void)
  {
  }
  
  // Implicit operations.
  
  ::Components::EnterpriseComponent_ptr
  CIF_UserHome_exec_i::create (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_THROW_EX (
      retval,
      CIF_User_exec_i,
      ::CORBA::NO_MEMORY ());
    
    return retval;
  }
  
  extern "C" CIF_COMPONENT_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_CIF_CIF_UserHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();
    
    ACE_NEW_NORETURN (
      retval,
      CIF_UserHome_exec_i);
    
    return retval;
  }
}
