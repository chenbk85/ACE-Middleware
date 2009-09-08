// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.1 ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:1278

#include "Hello_Sender_exec.h"
#include "ciao/CIAO_common.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_Hello_AMI_Sender_Impl
{
  //============================================================
  // Facet Executor Implementation Class: MyFoo_callback_exec_i
  //============================================================
  
  MyFoo_callback_exec_i::MyFoo_callback_exec_i (void)
  {
  }
  
  MyFoo_callback_exec_i::~MyFoo_callback_exec_i (void)
  {
  }
  
  //============================================================
  // Operations from ::CCM_AMI::MyFoo_callback
  //============================================================
  
  // FOO methods
  void
  MyFoo_callback_exec_i::foo_callback_handler (
    ::CORBA::Long result,
    const char * answer)
  {
    printf ("Sender (FOO) :\tCallback from AMI : result <%d> answer <%s>\n", result, answer);
  }
  
  void
  MyFoo_callback_exec_i::foo_callback_excep (
      const ::CCM_AMI::InternalException & exception_holder)
  {
    printf ("Sender (FOO) :\tCallback EXCEPTION from AMI : exception id : <%d> exception error : <%s>\n",
      exception_holder.id, exception_holder.error_string.in ());
  }
  
  // HELLO methods
  void
  MyFoo_callback_exec_i::hello_callback_handler (
    ::CORBA::Long answer)
  {
    printf ("Sender (FOO) :\tCallback from AMI (HELLO) : answer <%d>\n", answer);
  }
  
  void
  MyFoo_callback_exec_i::hello_callback_excep (
      const ::CCM_AMI::InternalException & exception_holder)
  {
    printf ("Sender (FOO) :\tCallback EXCEPTION from AMI (HELLO) : exception id : <%d> exception error : <%s>\n",
      exception_holder.id, exception_holder.error_string.in ());
  }

  //============================================================
  // Operations from ::CCM_AMI::MyInterface_callback
  //============================================================
  MyInterface_callback_exec_i::MyInterface_callback_exec_i ()
  {
  }

  MyInterface_callback_exec_i::~MyInterface_callback_exec_i ()
  {
  }

  void
  MyInterface_callback_exec_i::do_something_with_something_callback_handler (
    ::CORBA::Float result)
  {
    printf ("Sender (INTERFACE) :\tCallback from AMI : result <%f>\n", result);
  }
  
  void
  MyInterface_callback_exec_i::do_something_with_something_callback_excep (
    const ::CCM_AMI::InternalException & exception_holder)
  {
    printf ("Sender (INTERFACE) :\tCallback EXCEPTION from AMI : exception id : <%d> exception error : <%s>\n",
            exception_holder.id, exception_holder.error_string.in ());
  }

  //============================================================
  // Worker thread for asynchronous invocations for MyFoo
  //============================================================
  asynch_foo_generator::asynch_foo_generator (::CCM_AMI::AMI_MyFoo_ptr my_foo_ami)
  : my_foo_ami_ (::CCM_AMI::AMI_MyFoo::_duplicate (my_foo_ami))
  {
  }

  int asynch_foo_generator::svc ()
  {
    ACE_OS::sleep (3);
    for (int i = 0; i < 5; ++i)
      {
        if (CORBA::is_nil (my_foo_ami_))
          {
            printf ("Sender (ASYNCH) :\tfoo_ami is NIL !!!\n");
            return 1;
          }
        else
          {
            printf ("Sender (ASYNCH) :\tInvoke Asynchronous call\n");
            my_foo_ami_->sendc_foo ("Do something asynchronous");
            my_foo_ami_->sendc_hello ();
            printf ("Sender (ASYNCH) :\tInvoked Asynchronous call\n");
          }
      }
    printf ("Sender (ASYNCH) :\tInvoke Asynchronous call to test EXCEPTION HANDLING\n");
    my_foo_ami_->sendc_foo ("");
    printf ("Sender (ASYNCH) :\tInvoked Asynchronous call.\n");
    return 0;
  }
  
  //============================================================
  // Worker thread for synchronous invocations for MyFoo
  //============================================================
  synch_foo_generator::synch_foo_generator (::CCM_AMI::MyFoo_ptr my_foo_ami)
  : my_foo_ami_ (::CCM_AMI::MyFoo::_duplicate (my_foo_ami))
  {
  }

  int synch_foo_generator::svc ()
  {
    ACE_OS::sleep (3);
    //run synch calls
    char * out_str;
    for (int i = 0; i < 5; ++i)
      {
        CORBA::Long result = my_foo_ami_->foo ("Do something synchronous", out_str);
        printf ("Sender (SYNCH):\tInvoked synchronous call (FOO) result <%d> answer <%s>\n", result, out_str);
        CORBA::Long answer;
        my_foo_ami_->hello (answer);
        printf ("Sender (SYNCH):\tInvoked synchronous call (HELLO) answer <%d>\n", answer);
      }
    try
      {
        CORBA::Long result = my_foo_ami_->foo ("", out_str);
        printf ("Sender (SYNCH) :\tInvoked synchronous call result <%d> answer <%s>\n", result, out_str);
      }
    catch (CCM_AMI::InternalError& ex)
      {
        printf ("Sender (SYNCH) :\tExpected Exception caught : <%d> <%s>\n", ex.ex.id, ex.ex.error_string.in ());
      }
    return 0;
  }

  //============================================================
  // Worker thread for asynchronous invocations for MyInterface
  //============================================================
  asynch_interface_generator::asynch_interface_generator (::CCM_AMI::AMI_MyInterface_ptr my_interface_ami)
  : my_interface_ami_ (::CCM_AMI::AMI_MyInterface::_duplicate (my_interface_ami))
  {
  }

  int asynch_interface_generator::svc ()
  {
    ACE_OS::sleep (3);
    for (int i = 1; i < 15; ++i)
    {
      if (CORBA::is_nil (my_interface_ami_))
      {
        printf ("Sender (INTERFACE) :\tinterface_ami is NIL !!!\n");
        return 1;
      }
      else
      {
        printf ("Sender (INTERFACE) :\tInvoke Asynchronous call\n");
        //MyInterface_callback_exec_i* cb = new MyInterface_callback_exec_i ();
        my_interface_ami_->sendc_do_something_with_something (0, i);
        printf ("Sender (INTERFACE) :\tInvoked Asynchronous call\n");
      }
    }
    printf ("Sender (INTERFACE) :\tInvoke Asynchronous call to test EXCEPTION HANDLING\n");
    my_interface_ami_->sendc_do_something_with_something (0, 0);
    printf ("Sender (INTERFACE) :\tInvoked Asynchronous call.\n");
    return 0;
  }
  
  //============================================================
  // Component Executor Implementation Class: Sender_exec_i
  //============================================================
  Sender_exec_i::Sender_exec_i (void)
  : global_foo_callback_ (0),
    global_interface_callback_ (0)
  {
  }
  
  Sender_exec_i::~Sender_exec_i (void)
  {
  }
  
  // Supported operations and attributes.
  
  // Component attributes.
  
  // Port operations.
  
  ::CCM_AMI::CCM_AMI_MyFoo_callback_ptr
  Sender_exec_i::get_the_my_foo_callback ()
  {
    if (CORBA::is_nil (global_foo_callback_))
    {
      global_foo_callback_ = new MyFoo_callback_exec_i ();
    }

    return  global_foo_callback_;
  }
  
  ::CCM_AMI::CCM_AMI_MyInterface_callback_ptr
  Sender_exec_i::get_the_my_interface_callback ()
  {
    if (CORBA::is_nil (global_interface_callback_))
    {
      global_interface_callback_ = new MyInterface_callback_exec_i ();
    }

    return  global_interface_callback_;
  }

  // Operations from Components::SessionComponent.
  
  void
  Sender_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::Hello_AMI::CCM_Sender_Context::_narrow (ctx);
    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }
  
  void
  Sender_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }
  
  void
  Sender_exec_i::ccm_activate (void)
  {

    ::CCM_AMI::AMI_MyFoo_var asynch_foo =
      this->context_->get_connection_run_asynch_my_foo();
    asynch_foo_generator* asynch_foo_gen =
        new asynch_foo_generator (asynch_foo);
    asynch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

    ::CCM_AMI::MyFoo_var synch_foo =
        this->context_->get_connection_run_my_foo ();
    synch_foo_generator* synch_foo_gen =
      new synch_foo_generator (synch_foo);
    synch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

  ::CCM_AMI::AMI_MyInterface_var asynch_interface =
      this->context_->get_connection_run_asynch_my_interface();
  asynch_interface_generator* asynch_interface_gen =
    new asynch_interface_generator (asynch_interface);
  asynch_interface_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

  }
  
  void
  Sender_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }
  
  void
  Sender_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }
  
  extern "C"  ::Components::EnterpriseComponent_ptr
  create_Hello_AMI_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_RETURN (
      retval,
      Sender_exec_i,
      ::Components::EnterpriseComponent::_nil ());
    
    return retval;
  }
}

namespace CIAO_Hello_AMI_Sender_Impl
{
  //============================================================
  // Home Executor Implementation Class: SenderHome_exec_i
  //============================================================
  
  SenderHome_exec_i::SenderHome_exec_i (void)
  {
  }
  
  SenderHome_exec_i::~SenderHome_exec_i (void)
  {
  }
  
  // All operations and attributes.
  
  // Factory operations.
  
  // Finder operations.
  
  // Implicit operations.
  
  ::Components::EnterpriseComponent_ptr
  SenderHome_exec_i::create (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_THROW_EX (
      retval,
      Sender_exec_i,
      ::CORBA::NO_MEMORY ());
    
    return retval;
  }
  
  extern "C"  ::Components::HomeExecutorBase_ptr
  create_Hello_AMI_SenderHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();
    
    ACE_NEW_RETURN (
      retval,
      SenderHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());
    
    return retval;
  }
}

