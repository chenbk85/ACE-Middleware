// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.3
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

#include "NoReplyH_Sender_exec.h"
#include "NoReplyHA_conn_i.h"
#include "ace/OS_NS_unistd.h"


namespace CIAO_NoReplyH_Sender_Impl
{
  //============================================================
  // Worker thread for asynchronous invocations for MyFoo
  //============================================================
  asynch_foo_generator::asynch_foo_generator (
        ::NoReplyH::CCM_Sender_Context_ptr context,
         Atomic_UShort &nr_received_back)
       : context_(::NoReplyH::CCM_Sender_Context::_duplicate (context)),
         nr_received_back_(nr_received_back)
  {
  }

  int asynch_foo_generator::svc ()
  {
    ACE_OS::sleep (3);
    ::NoReplyH::AMI4CCM_MyFoo_var my_foo_ami_  =
       this->context_->get_connection_sendc_run_my_foo();

    if (CORBA::is_nil (my_foo_ami_))
      {
        ACE_ERROR ((LM_ERROR, "ERROR Sender (ASYNCH) :\tfoo_ami is NIL !\n"));
        return 1;
      }
    else
      {
        ::NoReplyH::AMI4CCM_MyFooReplyHandler_var cb =
            new CIAO_NoReplyH_Sender_Impl::AMI4CCM_MyFooReplyHandler_i (
                                                 this->nr_received_back_);

        //Invoke Asynchronous calls
        //test with  replyhandler.
        my_foo_ami_->sendc_foo ( cb.in (),
                                 "Do something asynchronous");

        //test without replyhandlers.
        my_foo_ami_->sendc_foo ( NoReplyH::AMI4CCM_MyFooReplyHandler::_nil (),
                          "Do something asynchronous with no replyhandler");
        my_foo_ami_->sendc_hello (
                         NoReplyH::AMI4CCM_MyFooReplyHandler::_nil ());
        my_foo_ami_->sendc_get_rw_attrib (
                         NoReplyH::AMI4CCM_MyFooReplyHandler::_nil ());
        my_foo_ami_->sendc_set_rw_attrib (
                         NoReplyH::AMI4CCM_MyFooReplyHandler::_nil (), 15);
        my_foo_ami_->sendc_get_ro_attrib (
                         NoReplyH::AMI4CCM_MyFooReplyHandler::_nil ());
      }
      //Invoke Asynchronous calls to test exception handling
      //without replyhandlers.
      my_foo_ami_->sendc_foo (
                         NoReplyH::AMI4CCM_MyFooReplyHandler::_nil (), "");
      my_foo_ami_->sendc_set_rw_attrib (
                         NoReplyH::AMI4CCM_MyFooReplyHandler::_nil (), 0);

      return 0;
  }

  //============================================================
  // Worker thread for synchronous invocations for MyFoo
  //============================================================
  synch_foo_generator::synch_foo_generator (
      ::NoReplyH::CCM_Sender_Context_ptr context)
  : context_(::NoReplyH::CCM_Sender_Context::_duplicate (context))

  {
  }

  int synch_foo_generator::svc ()
  {
     ACE_OS::sleep (3);
     ::NoReplyH::MyFoo_var my_foo_ami_ =
        this->context_->get_connection_run_my_foo ();

    //run some synch calls
    try
      {
        CORBA::Short rw_attrib = my_foo_ami_->rw_attrib ();
        ACE_DEBUG ((LM_DEBUG, "OK: SYNCH rw_attrib() returns %u.\n",
                              rw_attrib));
      }
    catch (const NoReplyH::InternalError& )
      {
        ACE_ERROR ((LM_ERROR, "ERROR: SYNCH rw_attrib(): "
                              "Unexpected return.\n"));
      }
    try
      {
        CORBA::Short ro_attrib = my_foo_ami_->ro_attrib ();
        ACE_DEBUG ((LM_DEBUG, "OK: SYNCH ro_attrib() returns %u.\n",
                              ro_attrib));
      }
    catch (const NoReplyH::InternalError& )
      {
        ACE_ERROR ((LM_ERROR, "ERROR: SYNCH ro_attrib(): "
                              "Unexpected return.\n"));
      }
    catch (const CORBA::Exception& ex)
      {
        ex._tao_print_exception ("ERROR: Caught unexpected except:");
      }
    return 0;
  }
  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  Sender_exec_i::Sender_exec_i (void)
  : nr_received_back_(0)
  {
  }

  Sender_exec_i::~Sender_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  // Operations from Components::SessionComponent.

  void
  Sender_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::NoReplyH::CCM_Sender_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
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
    this->asynch_foo_gen =
       new asynch_foo_generator (this->ciao_context_.in (),
                                  this->nr_received_back_);
     this->asynch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

     this->synch_foo_gen =
       new synch_foo_generator (this->ciao_context_.in());
     this->synch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);
 }

  void
  Sender_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
    if(this->nr_received_back_.value() != 1)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Sender doesn't received the expected "
                              "number of callbacks"
                              "Expected: 1, Received: %u.\n",
                              this->nr_received_back_.value()));
      }
    else
      {
        ACE_DEBUG ((LM_DEBUG, "OK: Sender received the expected number of "
                              "callbacks: %u.\n",
                              this->nr_received_back_.value()));
      }
    if (this->asynch_foo_gen)
      {
        delete this->asynch_foo_gen;
        this->asynch_foo_gen = 0;
      }
    if (this->synch_foo_gen)
      {
        delete this->synch_foo_gen;
        this->synch_foo_gen = 0;
      }
  }

  extern "C" NOREPLYH_SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_NoReplyH_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
