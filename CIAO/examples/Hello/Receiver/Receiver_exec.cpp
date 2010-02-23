// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.6
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
 *       http://doc.ece.uci.edu/
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
// .\be\be_codegen.cpp:1278

#include "Receiver_exec.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_Hello_Receiver_Impl
{
  //============================================================
  // Component Executor Implementation Class: Receiver_exec_i
  //============================================================
  
  Receiver_exec_i::Receiver_exec_i (void)
    : iterations_ (10)
  {
  }
  
  Receiver_exec_i::~Receiver_exec_i (void)
  {
  }
  
  // Supported operations and attributes.
  
  // Component attributes and port operations.
  
  void
  Receiver_exec_i::push_click_in (
    ::Hello::TimeOut * ev)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_DEBUG,
          ACE_TEXT ("Receiver - Informed by the Sender with message [%C]\n"),
          ev->data ()));
    Hello::ReadMessage_var rev = this->context_->get_connection_read_message ();
    if (CORBA::is_nil (rev.in ()))
      throw CORBA::BAD_INV_ORDER ();
    for (CORBA::Short i = 0; i < this->iterations_; ++i)
      {
        CORBA::String_var str = rev->get_message ();
        ACE_DEBUG ((LM_DEBUG,
                  "Receiver - Got message from the sender [%C].\n",
                  str.in ()));
        ACE_Time_Value tv (1, 0);
        ACE_OS::sleep (tv);
      }
  }
  
  ::CORBA::Short
  Receiver_exec_i::iterations (void)
  {
    /* Your code here. */
    return this->iterations_;
  }
  
  void
  Receiver_exec_i::iterations (
    ::CORBA::Short iterations)
  {
    /* Your code here. */
    this->iterations_ = iterations;
  }
  
  // Operations from Components::SessionComponent.
  
  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::set_session_context\n"));

    this->context_ =
      ::Hello::CCM_Receiver_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }
  
  void
  Receiver_exec_i::configuration_complete (void)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_DEBUG,
                "Receiver_exec_i::configuration_complete\n"));
  }
  
  void
  Receiver_exec_i::ccm_activate (void)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::ccm_activate\n"));
  }
  
  void
  Receiver_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::ccm_passivate\n"));
  }
  
  void
  Receiver_exec_i::ccm_remove (void)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::ccm_remove\n"));
  }
  
  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Hello_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);
    
    return retval;
  }
}

namespace CIAO_Hello_Receiver_Impl
{
  //============================================================
  // Home Executor Implementation Class: ReceiverHome_exec_i
  //============================================================
  
  ReceiverHome_exec_i::ReceiverHome_exec_i (void)
  {
  }
  
  ReceiverHome_exec_i::~ReceiverHome_exec_i (void)
  {
  }
  
  // All operations and attributes.
  
  // Factory operations.
  
  // Finder operations.
  
  // Implicit operations.
  
  ::Components::EnterpriseComponent_ptr
  ReceiverHome_exec_i::create (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_THROW_EX (
      retval,
      Receiver_exec_i,
      ::CORBA::NO_MEMORY ());
    
    return retval;
  }
  
  extern "C" RECEIVER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Hello_ReceiverHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();
    
    ACE_NEW_NORETURN (
      retval,
      ReceiverHome_exec_i);
    
    return retval;
  }
}

