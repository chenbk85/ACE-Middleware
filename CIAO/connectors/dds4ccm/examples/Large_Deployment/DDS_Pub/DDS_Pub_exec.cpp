// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.7
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
// be/be_codegen.cpp:1277

#include "DDS_Pub_exec.h"

namespace CIAO_DDS_Pub_Impl
{
  //============================================================
  // Component Executor Implementation Class: DDS_Pub_exec_i
  //============================================================
  
  DDS_Pub_exec_i::DDS_Pub_exec_i (void)
  {
  }
  
  DDS_Pub_exec_i::~DDS_Pub_exec_i (void)
  {
  }
  
  // Supported operations and attributes.
  
  // Component attributes and port operations.
  
  // Operations from Components::SessionComponent.
  
  void
  DDS_Pub_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::CCM_DDS_Pub_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }
  
  void
  DDS_Pub_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }
  
  void
  DDS_Pub_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }
  
  void
  DDS_Pub_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }
  
  void
  DDS_Pub_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }
  
  extern "C" DDS_PUB_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_DDS_Pub_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_NORETURN (
      retval,
      DDS_Pub_exec_i);
    
    return retval;
  }
}

