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

#include "ThreeComp_Sender_exec.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_ThreeComp_Sender_Impl
{
  CORBA::Boolean asynch = false;
  //============================================================
  // Worker thread for asynchronous invocations for MyFoo
  //============================================================
  asynch_foo_generator::asynch_foo_generator (
   ::ThreeComp::CCM_Sender_Context_ptr context,
    Atomic_UShort  &nr_of_rec,
    Atomic_UShort  &nr_of_sent)
  : context_(::ThreeComp::CCM_Sender_Context::_duplicate (context)),
   nr_of_rec_(nr_of_rec),
   nr_of_sent_(nr_of_sent)

  {
  }

  int asynch_foo_generator::svc ()
  {
    ::ThreeComp::Sender::sendc_run_my_fooConnections_var  my_foo_ami_ =
       context_->get_connections_sendc_run_my_foo();
    ::ThreeComp::AMI4CCM_MyFooReplyHandler_var cb =
       new AMI4CCM_MyFooReplyHandler_run_my_foo_i (
                                                 this->nr_of_rec_,
                                                 this->nr_of_sent_);

      // Invoke Asynchronous calls to test
     for (CORBA::ULong i = 0; i < my_foo_ami_->length (); ++i)
       {
         ++this->nr_of_sent_;
         my_foo_ami_[i].objref->sendc_foo (cb.in(),
                                           10 );
         ACE_DEBUG ((LM_DEBUG, "OK Sender send ASYNCHRONOUS call to Receiver.\n"));
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
  // Worker thread for synchronous invocations for MyFoo
  //============================================================
  synch_foo_generator::synch_foo_generator (
   ::ThreeComp::CCM_Sender_Context_ptr context,
    Atomic_UShort  &nr_of_rec)
  : context_(::ThreeComp::CCM_Sender_Context::_duplicate (context)),
    nr_of_rec_(nr_of_rec)
  {
  }

  int synch_foo_generator::svc ()
  {

    ::ThreeComp::Sender::run_my_fooConnections_var my_foo_ami_ =
          context_->get_connections_run_my_foo ();

    CORBA::Boolean wait = false;

    for(CORBA::ULong i = 0; i < my_foo_ami_->length(); ++i)
       {
         CORBA::String_var answer;
         try
           {
             if ( wait==true)
               {
                  ACE_ERROR ((LM_ERROR,
                               "ERROR: Sender didn't receive SYNCHRONOUS answer"
                               " from Receiver.\n"));
                }
             wait = true;
             ACE_DEBUG ((LM_DEBUG, "OK Sender send SYNCHRONOUS CALL to Receiver.\n"));

             CORBA::ULong result = my_foo_ami_[i].objref->foo( 20,
                                       answer.out ());
             if (result == 2)
               {
                 ACE_DEBUG ((LM_DEBUG, "OK Sender received SYNCHRONOUS answer "
                                       "from Receiver <%C>\n",
                                       answer.in ()));
                 ++this->nr_of_rec_;
                 wait = false;
               }
             }
         catch (const ThreeComp::InternalError&)
           {
             ACE_ERROR ((LM_ERROR, "ERROR: synch_foo_generator::foo: "
                                "Unexpected exception.\n"));
           }
       }
    return 0;
  }
  /**
   * Facet Executor Implementation Class: do_my_state_exec_i
   */

  do_my_state_exec_i::do_my_state_exec_i (
        ::ThreeComp::CCM_Sender_Context_ptr ctx)
    : ciao_context_ (
        ::ThreeComp::CCM_Sender_Context::_duplicate (ctx))
  {
  }

  do_my_state_exec_i::~do_my_state_exec_i (void)
  {
  }

  // Operations from ::ThreeComp::State

  ::CORBA::Long
  do_my_state_exec_i::bar (::CORBA::Long cmd,
  ::CORBA::String_out answer)
  {
    ACE_OS::sleep(2);
    answer = CORBA::string_dup ("Hi from sender.");
    return cmd;
  }

  /**
   * Facet Executor Implementation Class: do_my_bar_exec_i
   */

  do_my_bar_exec_i::do_my_bar_exec_i (
        ::ThreeComp::CCM_Sender_Context_ptr ctx)
    : ciao_context_ (
        ::ThreeComp::CCM_Sender_Context::_duplicate (ctx))
  {
  }

  do_my_bar_exec_i::~do_my_bar_exec_i (void)
  {
  }

  // Operations from ::ThreeComp::MyBar

  ::CORBA::Long
  do_my_bar_exec_i::testbar (::CORBA::Long /* cmd */,
  ::CORBA::String_out /* answer */)
  {
    /* Your code here. */
    return 0;
  }

  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  Sender_exec_i::Sender_exec_i (void)
  : nr_of_rec_(0),
    nr_of_sent_(0)
  {
  }

  Sender_exec_i::~Sender_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  ::ThreeComp::CCM_State_ptr
  Sender_exec_i::get_do_my_state (void)
  {
    if ( ::CORBA::is_nil (this->ciao_do_my_state_.in ()))
      {
        do_my_state_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          do_my_state_exec_i (
            this->ciao_context_.in ()),
            ::ThreeComp::CCM_State::_nil ());

          this->ciao_do_my_state_ = tmp;
      }

    return
      ::ThreeComp::CCM_State::_duplicate (
        this->ciao_do_my_state_.in ());
  }

  ::ThreeComp::CCM_MyBar_ptr
  Sender_exec_i::get_do_my_bar (void)
  {
    if ( ::CORBA::is_nil (this->ciao_do_my_bar_.in ()))
      {
        do_my_bar_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          do_my_bar_exec_i (
            this->ciao_context_.in ()),
            ::ThreeComp::CCM_MyBar::_nil ());

          this->ciao_do_my_bar_ = tmp;
      }

    return
      ::ThreeComp::CCM_MyBar::_duplicate (
        this->ciao_do_my_bar_.in ());
  }

  // Operations from Components::SessionComponent.

  void
  Sender_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::ThreeComp::CCM_Sender_Context::_narrow (ctx);

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
    //for connection with Receiver component
    this->asynch_foo_gen =
      new asynch_foo_generator (this->ciao_context_.in (),
                                this->nr_of_rec_,
                                this->nr_of_sent_);
    this->asynch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

    this->synch_foo_gen =
       new synch_foo_generator (this->ciao_context_.in(),
                                this->nr_of_rec_);
    this->synch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);  }

  void
  Sender_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
    // each Receiver (total 3, see deployment plan) send back 2 requests.
    if ((asynch == false) || (this->nr_of_rec_.value() != 6) ||
        (this->nr_of_sent_.value() != 0))
      {
        ACE_ERROR ((LM_ERROR,
                   "ERROR: Test not asynchronous or not received back"
                   " all requests ( %u/6)!\n",
                   this->nr_of_rec_.value() ));
      }
    else
      {
        ACE_DEBUG ((LM_DEBUG, "OK: Sender works as expected.\n"));
      }
    delete this->asynch_foo_gen;
    this->asynch_foo_gen = 0;
    delete this->synch_foo_gen;
    this->synch_foo_gen = 0;
  }

  AMI4CCM_MyFooReplyHandler_run_my_foo_i::AMI4CCM_MyFooReplyHandler_run_my_foo_i (
      Atomic_UShort  &nr_of_rec,
       Atomic_UShort  &nr_of_sent)
   : nr_of_rec_(nr_of_rec),
     nr_of_sent_(nr_of_sent)
  {
  }

  AMI4CCM_MyFooReplyHandler_run_my_foo_i::~AMI4CCM_MyFooReplyHandler_run_my_foo_i (void)
  {
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::foo (
    ::CORBA::Long  ami_ret_val,
    const char *  answer )
  {
    ++this->nr_of_rec_;
    if (ami_ret_val == 1 )
      {
        --this->nr_of_sent_;
        ACE_DEBUG ((LM_DEBUG,
            "OK: Sender get ASYNCHRONOUS callback from Receiver: <%C>.\n",
             answer));
      }
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::foo_excep (
    ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  extern "C" THREECOMP_SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_ThreeComp_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
