// -*- C++ -*-
// $Id$

#include "ComponentC_exec.h"
#include "ciao/Logger/Log_Macros.h"

namespace CIAO_connector_test_C_Impl
{
  //============================================================
  // Pulse generator
  //============================================================

  ComponentC_exec_i ::ComponentC_exec_i  (void)
    : topic_name_has_been_set_ (false)
  {
  }

  ComponentC_exec_i ::~ComponentC_exec_i  (void)
  {
  }

  // Port operations.
    void
    ComponentC_exec_i ::topic_name (const char * topic_name)
    {
      this->topic_name_ = topic_name;
      this->topic_name_has_been_set_ = true;
    }
    char *
    ComponentC_exec_i ::topic_name (void)
    {
      return CORBA::string_dup (this->topic_name_.in ());
    }

  // Operations from Components::SessionComponent.
  void
  ComponentC_exec_i ::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::connector_test::CCM_C_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  ComponentC_exec_i ::configuration_complete (void)
  {
  }

  void
  ComponentC_exec_i ::ccm_activate (void)
  {
  }

  void
  ComponentC_exec_i ::ccm_passivate (void)
  {
  }

  void
  ComponentC_exec_i ::ccm_remove (void)
  {
    if (!this->topic_name_has_been_set_)
      CIAO_ERROR ((LM_ERROR, ACE_TEXT ("ERROR : Topic name has not been set\n")));
  }

  extern "C" INHERITED_COMPONENTS_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Hello_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      ComponentC_exec_i );

    return retval;
  }
}

