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

#include "Single_Service_exec.h"

namespace CIAO_Single_Service_Impl
{
  //============================================================
  // Facet Executor Implementation Class: Simple_Service_exec_i
  //============================================================

  Simple_Service_exec_i::Simple_Service_exec_i (void)
  {
  }

  Simple_Service_exec_i::~Simple_Service_exec_i (void)
  {
  }

  // Operations from ::Simple_Service

  void
  Simple_Service_exec_i::ping (void)
  {
    /* Your code here. */
  }

  //============================================================
  // Component Executor Implementation Class: Single_Service_exec_i
  //============================================================

  Single_Service_exec_i::Single_Service_exec_i (void)
  {
  }

  Single_Service_exec_i::~Single_Service_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  ::CCM_Simple_Service_ptr
  Single_Service_exec_i::get_ping_port (void)
  {
    /* Your code here. */
    return ::CCM_Simple_Service::_nil ();
  }

  // Operations from Components::SessionComponent.

  void
  Single_Service_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::CCM_Single_Service_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Single_Service_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Single_Service_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }

  void
  Single_Service_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Single_Service_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C" SINGLE_SERVICE_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Single_Service_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Single_Service_exec_i);

    return retval;
  }
}

