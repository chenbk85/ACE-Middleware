// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.1
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
// be/be_codegen.cpp:1333

#include "Executor_Destructor_exec.h"

#include "Exec_Dest_Status.h"

namespace CIAO_dance_test_Exec_Destructor_Impl
{
  //============================================================
  // Component Executor Implementation Class: Exec_Destructor_exec_i
  //============================================================
  
  Exec_Destructor_exec_i::Exec_Destructor_exec_i (void)
  {
  }
  
  Exec_Destructor_exec_i::~Exec_Destructor_exec_i (void)
  {
    ACE_DEBUG ((LM_DEBUG, "Exec_Destructor_exec_i::~Exec_Destructor_exec_i\n"));
    dance_test::EXEC_DEST_STATUS::instance ()->destructor_called (this->name_);
  }
  
  // Supported operations and attributes.
  
  // Component attributes and port operations.
  
  // Operations from Components::SessionComponent.
  
  void
  Exec_Destructor_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::dance_test::CCM_Exec_Destructor_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }
  
  void
  Exec_Destructor_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }
  
  void
  Exec_Destructor_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }
  
  void
  Exec_Destructor_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }
  
  void
  Exec_Destructor_exec_i::ccm_remove (void)
  {
  }
  
  void 
  Exec_Destructor_exec_i::id (const char  *name)
  {
    this->name_ = name;
  }
  
  extern "C" EXECUTOR_DESTRUCTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_dance_test_Exec_Destructor_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_NORETURN (
      retval,
      Exec_Destructor_exec_i);
    
    return retval;
  }
}

namespace CIAO_dance_test_Exec_Destructor_Impl
{
  //============================================================
  // Home Executor Implementation Class: Home_Destructor_exec_i
  //============================================================
  
  Home_Destructor_exec_i::Home_Destructor_exec_i (void)
  {
  }
  
  Home_Destructor_exec_i::~Home_Destructor_exec_i (void)
  {
    ACE_DEBUG ((LM_DEBUG, "Home_Destructor_exec_i::~Home_Destructor_exec_i\n"));
    dance_test::EXEC_DEST_STATUS::instance ()->destructor_called (this->name_);
  }
  
  // Implicit operations.
  
  ::Components::EnterpriseComponent_ptr
  Home_Destructor_exec_i::create (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_THROW_EX (
      retval,
      Exec_Destructor_exec_i,
      ::CORBA::NO_MEMORY ());
    
    return retval;
  }
  
  void 
  Home_Destructor_exec_i::id (const char  *name)
  {
    this->name_ = name;
  }

  char * 
  Home_Destructor_exec_i::id (void)
  {
    return 0;
  }
  
  extern "C" EXECUTOR_DESTRUCTOR_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_dance_test_Home_Destructor_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();
    
    ACE_NEW_NORETURN (
      retval,
      Home_Destructor_exec_i);
    
    return retval;
  }
}
