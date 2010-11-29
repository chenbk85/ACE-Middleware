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

// test use multiple porttypes.
#include "UsesMulti_Sender_exec.h"
#include "UsesMultiA_conn_i.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_UsesMulti_Sender_Impl
{
  CORBA::Boolean asynch = false;

  //============================================================
  // Worker thread for asynchronous invocations for One
  //============================================================
  asynch_foo_generator::asynch_foo_generator (
     ::UsesMulti::CCM_Sender_Context_ptr context,
      Atomic_UShort  &nr_of_received,
      Atomic_UShort  &nr_of_sent)
   : context_(::UsesMulti::CCM_Sender_Context::_duplicate (context)),
     nr_of_received_(nr_of_received),
     nr_of_sent_(nr_of_sent)
  {
  }

  int asynch_foo_generator::svc ()
  {
    ::UsesMulti::Sender::sendc_run_my_um_oneConnections_var  my_one_ami_ =
      context_->get_connections_sendc_run_my_um_one();

    // Invoke Asynchronous calls to test
    for (CORBA::ULong i = 0; i < my_one_ami_->length (); ++i)
      {
        ::UsesMulti::AMI4CCM_OneReplyHandler_var cb =
          new CIAO_UsesMulti_Sender_Impl::AMI4CCM_OneReplyHandler_i (
                                                   this->nr_of_received_,
                                                   this->nr_of_sent_);

        CORBA::String_var test;
        switch (i)
          {
            case 0:
              test = CORBA::string_dup ("Asynch. call one.");
              break;
            case 1:
              test = CORBA::string_dup ("Asynch. call two");
              break;
            case 2:
              test = CORBA::string_dup ("Asynch. call three");
              break;
            default:
              break;
          }
        ++this->nr_of_sent_;
        my_one_ami_[i].objref->sendc_foo (cb.in (),
                                         test.in (),
                                         i);
        ACE_DEBUG ((LM_DEBUG, "Sender (ASYNCH) : send <%C> !\n",
                   test.in ()));
        // There is more than 1 message sent, without receiving callbacks,
        // so it is asynchronous
        if (this->nr_of_sent_.value() > 1)
          {
            asynch = true;
          }
       }
     return 0;
   }
   //============================================================
   // Worker thread for synchronous invocations for One
   //============================================================
   synch_foo_generator::synch_foo_generator (
      ::UsesMulti::CCM_Sender_Context_ptr context,
       Atomic_UShort  &nr_of_received)
   : context_(::UsesMulti::CCM_Sender_Context::_duplicate (context)),
    nr_of_received_ (nr_of_received)
   {
   }

   int synch_foo_generator::svc ()
   {
     ::UsesMulti::Sender::run_my_um_oneConnections_var my_one_ami_ =
          context_->get_connections_run_my_um_one ();

     for(CORBA::ULong i = 0; i < my_one_ami_->length(); ++i)
       {
         CORBA::String_var test;
         switch (i)
           {
             case 0:
               test = CORBA::string_dup ("Synch. call 0.");
               break;
             case 1:
               test = CORBA::string_dup ("Synch. call 1");
               break;
             case 2:
               test = CORBA::string_dup ("Synch. call 2");
               break;
             default:
               break;
           }

         ACE_DEBUG ((LM_DEBUG,"Sender (SYNCH) : send <%C> !\n",
                     test.in ()));

         CORBA::String_var answer;
         CORBA::ULong result = my_one_ami_[i].objref->foo( test,
                               i,
                               answer.out ());
         if (result != i)
           {
             ACE_ERROR ((LM_ERROR,
                         "ERROR Sender (SYNCH) : CLASS One foo !\n"));
           }
         else
           {
             ++this->nr_of_received_;
             ACE_DEBUG ((LM_DEBUG,
                         "Sender (SYNCH) : received answer = <%C> !\n",
                         answer.in ()));
           }
       }
     return 0;
   }
  /**
   * Component Executor Implementation Class: Sender_exec_i
  */

  Sender_exec_i::Sender_exec_i (void)
  : nr_of_received_(0),
    nr_of_sent_(0)
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
      ::UsesMulti::CCM_Sender_Context::_narrow (ctx);

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
      new asynch_foo_generator (this->ciao_context_.in(),
          this->nr_of_received_,
          this->nr_of_sent_);
    this->asynch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

    this->synch_foo_gen =
         new synch_foo_generator (this->ciao_context_.in(),
             this->nr_of_received_);
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
    if (asynch == false)
      {
        ACE_ERROR ((LM_ERROR,
                   "ERROR: Uses multiple test not asynchronous!\n"));
      }
    if (this->nr_of_received_.value() != 6)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Did not get all callbacks from "
                              "multiple ports."
                              " Received = %u of 6\n",
                              this->nr_of_received_.value()));
      }
    else
      {
        ACE_DEBUG ((LM_DEBUG,
                    "OK: All messages received back by Sender\n"));
      }
    delete this->asynch_foo_gen;
    this->asynch_foo_gen = 0;
    delete this->synch_foo_gen;
    this->synch_foo_gen = 0;
  }

  extern "C" USESMULTI_SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_UsesMulti_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
