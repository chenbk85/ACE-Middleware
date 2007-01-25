// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.dre.vanderbilt.edu/CIAO

#include "Null_Component_exec.h"
#include "ciao/CIAO_common.h"

namespace CIDL_Null_Component_Impl
{
  //==================================================================
  // Facet Executor Implementation Class:   Null_Interface_exec_i
  //==================================================================

  Null_Interface_exec_i::Null_Interface_exec_i (void)
  {
  }

  Null_Interface_exec_i::~Null_Interface_exec_i (void)
  {
  }

  // Operations from ::Null_Interface

  void
  Null_Interface_exec_i::null_operation ()
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    // Your code here.
  }

  //==================================================================
  // Component Executor Implementation Class:   Null_Component_exec_i
  //==================================================================

  Null_Component_exec_i::Null_Component_exec_i (void)
  {
  }

  Null_Component_exec_i::~Null_Component_exec_i (void)
  {
  }

  // Supported or inherited operations.

  // Attribute operations.

  // Port operations.

  ::CCM_Null_Interface_ptr
  Null_Component_exec_i::get_null_facet ()
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    // Your code here.
    return ::CCM_Null_Interface::_nil ();
  }

  // Operations from Components::SessionComponent

  void
  Null_Component_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::CCMException))
  {
    this->context_ =
      Null_Component_Context::_narrow (
        ctx);

    if (this->context_ == 0)
    {
      throw ::CORBA::INTERNAL ();
    }
  }

  void
  Null_Component_exec_i::ciao_preactivate ()
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::CCMException))
  {
    // Your code here.
  }

  void
  Null_Component_exec_i::ciao_postactivate ()
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::CCMException))
  {
    // Your code here.
  }

  void
  Null_Component_exec_i::ccm_activate ()
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::CCMException))
  {
    // Your code here.
  }

  void
  Null_Component_exec_i::ccm_passivate ()
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::CCMException))
  {
    // Your code here.
  }

  void
  Null_Component_exec_i::ccm_remove ()
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::CCMException))
  {
    // Your code here.
  }

  //==================================================================
  // Home Executor Implementation Class:   Null_Component_Home_exec_i
  //==================================================================

  Null_Component_Home_exec_i::Null_Component_Home_exec_i (void)
  {
  }

  Null_Component_Home_exec_i::~Null_Component_Home_exec_i (void)
  {
  }

  // Supported or inherited operations.

  // Home operations.

  // Factory and finder operations.

  // Attribute operations.

  // Implicit operations.

  ::Components::EnterpriseComponent_ptr
  Null_Component_Home_exec_i::create ()
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::CCMException))
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (
      retval,
      Null_Component_exec_i,
      ::CORBA::NO_MEMORY ());

    return retval;
  }

  extern "C" NULL_COMPONENT_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Null_Component_Home_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();

    ACE_NEW_RETURN (
      retval,
      Null_Component_Home_exec_i,
      ::Components::HomeExecutorBase::_nil ());

    return retval;
  }
}

