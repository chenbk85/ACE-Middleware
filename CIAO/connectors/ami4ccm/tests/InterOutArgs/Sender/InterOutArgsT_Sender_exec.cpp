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

#include "InterOutArgsT_Sender_exec.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_InterOutArgsT_Sender_Impl
{
  // Worker thread for asynchronous invocations for MyFoo
  //============================================================
  asynch_foo_generator::asynch_foo_generator (
   ::InterOutArgsT::CCM_Sender_Context_ptr context,
    Atomic_UShort  &nr_of_received)
  : context_(::InterOutArgsT::CCM_Sender_Context::_duplicate (context)),
    nr_of_received_(nr_of_received)
  {
  }

  int asynch_foo_generator::svc ()
  {
    ACE_OS::sleep (3);
    if (CORBA::is_nil (context_))
      {
        ACE_ERROR ((LM_ERROR, "ERROR Sender (ASYNCH) :\tContext is NIL !\n"));
       return 1;
      }

    ::InterOutArgsT::AMI4CCM_MyFoo_var my_foo_ami_  =
       context_->get_connection_sendc_run_my_foo();

    if (CORBA::is_nil (my_foo_ami_))
      {
        ACE_ERROR ((LM_ERROR, "ERROR Sender (ASYNCH) :\tfoo_ami is NIL !\n"));
       return 1;
      }
    else
      {
        ::InterOutArgsT::CCM_AMI4CCM_MyFooReplyHandler_var cb =
          new AMI4CCM_MyFooReplyHandler_run_my_foo_i (
          this->nr_of_received_);

        //Invoke Asynchronous calls to test
        my_foo_ami_->sendc_var_outs ( cb.in (),
                                      "Send me a double and a long.");
        my_foo_ami_->sendc_var_div_outs (cb.in ());
        my_foo_ami_->sendc_var_div2_outs (cb.in ());
        my_foo_ami_->sendc_enum_out (cb.in ());
      }
    return 0;
  }

  //============================================================
  // Worker thread for synchronous invocations for MyFoo
  //============================================================
  synch_foo_generator::synch_foo_generator (
   ::InterOutArgsT::CCM_Sender_Context_ptr context,
    Atomic_UShort  &nr_of_received)
  : context_(::InterOutArgsT::CCM_Sender_Context::_duplicate (context)),
    nr_of_received_(nr_of_received)
  {
  }

  int synch_foo_generator::svc ()
  {
    ACE_OS::sleep (3);
   ::InterOutArgsT::MyFoo_var my_foo_ami_ =
         context_->get_connection_run_my_foo ();

    //run some synch calls
    InterOutArgsT::TestTopic_var test_topic = 0;
    InterOutArgsT::TopicString_var topic_str = 0;
    InterOutArgsT::TopicArray_var topic_arr = 0;
    CORBA::Double d_cmd = 0;
    CORBA::Long l_cmd = 0;
    CORBA::String_var out_str;
    try
      {
        my_foo_ami_->var_outs ("Do something synchronous",
                                                out_str,
                                                d_cmd ,
                                                l_cmd);
        if ( (d_cmd == 3.14 ) && (l_cmd == 100))
          {
            ++this->nr_of_received_;
          }
      }
    catch (const InterOutArgsT::InternalError&)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: synch_foo_generator::var_outs: "
                              "Unexpected exception.\n"));
      }
    try
      {
        my_foo_ami_->var_div_outs(test_topic,topic_str,topic_arr);
        if ((ACE_OS::strcmp (test_topic->key, "aaa") == 0) &&
            (test_topic->x == 10))
          {
            ++this->nr_of_received_;
          }
        else
         {
           ACE_ERROR ((LM_ERROR, "ERROR: synch_foo_generator::var_div_outs: "
                                "Unexpected data returned.\n"));
         }
      }
    catch (const InterOutArgsT::InternalError&)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: synch_foo_generator::var_div_outs: "
                              "Unexpected exception.\n"));
      }
    return 0;
  }
  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  Sender_exec_i::Sender_exec_i (void)
  : asynch_foo_gen (0),
    synch_foo_gen (0),
    nr_of_received_(0)
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
      ::InterOutArgsT::CCM_Sender_Context::_narrow (ctx);

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
          this->nr_of_received_);
    this->asynch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

    this->synch_foo_gen =
       new synch_foo_generator (this->ciao_context_.in(),
           this->nr_of_received_);
    this->synch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);  }

  void
  Sender_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
    if (this->nr_of_received_.value() == 6)
      {
        ACE_DEBUG ((LM_DEBUG, "OK: Sender received all expected data"
                              " for syn- and asynchronous calls\n"));
      }
    else
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Sender didn't receive all expected data"
                              " for syn- and asynchronous calls\n"));
      }
    delete this->asynch_foo_gen;
    this->asynch_foo_gen = 0;
    delete this->synch_foo_gen;
    this->synch_foo_gen = 0;
  }

  AMI4CCM_MyFooReplyHandler_run_my_foo_i::AMI4CCM_MyFooReplyHandler_run_my_foo_i (
      Atomic_UShort &nr_of_received)
  : nr_of_received_(nr_of_received)

  {
  }

  AMI4CCM_MyFooReplyHandler_run_my_foo_i::~AMI4CCM_MyFooReplyHandler_run_my_foo_i (void)
  {
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::var_outs ( const char * /*answer*/,
                                  CORBA::Double d_cmd, CORBA::Long l_cmd )
  {
    if (d_cmd != 3.14)
      {
        ACE_ERROR ((LM_ERROR, "ERROR MyFoo_callback_exec_i::var_outs: "
                              "received the wrong double, expected 3.14,"
                              " received %2.2f\n",
                              d_cmd));
      }
    else if (l_cmd != 100)
      {
        ACE_ERROR ((LM_ERROR, "ERROR MyFoo_callback_exec_i::var_outs: "
                              "received the wrong double, expected 3.14,"
                              " received %lu\n",
                              l_cmd));
      }
    else
      {
        ++this->nr_of_received_;
      }
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::var_outs_excep (
      ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::var_div_outs (
      const InterOutArgsT::TestTopic &test_topic,
      const InterOutArgsT::TopicString &topic_str,
      const InterOutArgsT::TopicArray &topic_arr)
  {
    CORBA::Boolean error = false;
    if ((ACE_OS::strcmp (test_topic.key, "aaa") != 0) || (test_topic.x != 10))
    {
      ACE_ERROR ((LM_ERROR, "ERROR MyFoo_exec_i::var_div_outs: "
                      "received the wrong struct, "
                      "expected key 'aaa', x = 10,"
                      " received key '%C' , x = %u\n",
                      test_topic.key.in(),test_topic.x));
      error = true;
    }
    if (( ACE_OS::strcmp (topic_str.key,"bbb") != 0) ||
        (ACE_OS::strcmp (topic_str.x_str, "ccc") != 0))
    {
      ACE_ERROR ((LM_ERROR, "ERROR MyFoo_exec_i::var_div_outs: "
                      "received the wrong struct, "
                      "expected key 'bbb', x = 'ccc',"
                      " received key '%C' , x = %C\n",
                      topic_str.key.in() ,topic_str.x_str.in()));
      error = true;
    }
    if (( ACE_OS::strcmp (topic_arr.key,"ddd") != 0) ||
        (topic_arr.x_array[1] != 100))
    {
      ACE_ERROR ((LM_ERROR, "ERROR MyFoo_exec_i::var_div_outs: "
                      "received the wrong struct, "
                      "expected key 'ddd', second elem 100 ,"
                      " received key '%C', second elem %u\n",
                      topic_arr.key.in(), topic_arr.x_array[1]));
      error = true;
    }
    if (error == false)
      {
        ++this->nr_of_received_;
      }
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::var_div_outs_excep (::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::var_div2_outs (
      const InterOutArgsT::X_Union &x_uni,
      const InterOutArgsT::test_seq &seq)
  {
    CORBA::Boolean error = false;

    if (x_uni.x_long() != 11)
      {
        ACE_ERROR ((LM_ERROR, "ERROR MyFoo_exec_i::var_div2_outs: "
                       "received the wrong union, "
                       "expected x_long = 11,"
                       " received x_long = %u\n",
                        x_uni.x_long()));
        error = true;
      }
    if (( ACE_OS::strcmp (seq[0].x_teststr, "fff") != 0) ||
        (seq[0].x_test != 12))
      {
        ACE_ERROR ((LM_ERROR, "ERROR MyFoo_exec_i::var_div2_outs: "
                   "received the wrong sequence, "
                   "expected key 'fff', x = 12,"
                   " received key '%C' , x = %u\n",
                   seq[0].x_teststr.in(),seq[0].x_test));
        error = true;
      }
    if (error == false)
      {
        ++this->nr_of_received_;
      }
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::var_div2_outs_excep (
      ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::enum_out (InterOutArgsT::test_enum test_enum)
  {
    if (test_enum != InterOutArgsT::ONE)

    {
      ACE_ERROR ((LM_ERROR, "ERROR MyFoo_callback_exec_i::enum_out: "
                            "received the wrong value, expected ONE,"
                            " received %u\n",
                            test_enum));
    }
  else
    {
      ++this->nr_of_received_;
    }
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::enum_out_excep (
      ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }


  extern "C" INTEROUTARGS_T_SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_InterOutArgsT_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
