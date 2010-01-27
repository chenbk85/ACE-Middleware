// -*- C++ -*-
// $Id$


// Test for ConnectorStatusListener:REJECTED_SAMPLE status through  too much instances
// in Sender <max_instances>2</max_instances>, in Receiver <max_instances>1</max_instances>

#include "CSL_SRTest_Sender_exec.h"
#include "ace/Guard_T.h"
#include "ciao/Logger/Log_Macros.h"
#include "tao/ORB_Core.h"
#include "ace/Reactor.h"
#include "dds4ccm/impl/ndds/Utils.h"

namespace CIAO_CSL_SRTest_Sender_Impl
{
  //============================================================
  // Facet Executor Implementation Class: ConnectorStatusListener_exec_i
  //============================================================
  ConnectorStatusListener_exec_i::ConnectorStatusListener_exec_i (Atomic_Boolean &rejected)
   : rejected_ (rejected)
  {
  }

  ConnectorStatusListener_exec_i::~ConnectorStatusListener_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::ConnectorStatusListener
  void ConnectorStatusListener_exec_i::on_inconsistent_topic(
    ::DDS::Topic_ptr /*the_topic*/,
     const DDS::InconsistentTopicStatus & /*status*/){
    }

  void ConnectorStatusListener_exec_i::on_requested_incompatible_qos(
    ::DDS::DataReader_ptr /*the_reader*/,
     const DDS::RequestedIncompatibleQosStatus & /*status*/)  {
    }

  void ConnectorStatusListener_exec_i::on_sample_rejected(
     ::DDS::DataReader_ptr the_reader,
     const DDS::SampleRejectedStatus & status)  {
       if((status.last_reason == DDS::REJECTED_BY_INSTANCES_LIMIT) &&
          (!CORBA::is_nil(the_reader)))
         {
           this->rejected_ = true;
         }
    }

  void ConnectorStatusListener_exec_i::on_offered_deadline_missed(
     ::DDS::DataWriter_ptr /*the_writer*/,
     const DDS::OfferedDeadlineMissedStatus & /*status*/)  {
    }

  void ConnectorStatusListener_exec_i::on_offered_incompatible_qos(
     ::DDS::DataWriter_ptr /*the_writer*/,
     const DDS::OfferedIncompatibleQosStatus & /*status*/)  {
   }

  void ConnectorStatusListener_exec_i::on_unexpected_status(
    ::DDS::Entity_ptr /*the_entity*/,
    ::DDS::StatusKind  /*status_kind*/)  {
    }

  //============================================================
  // Pulse generator
  //============================================================
  pulse_Generator::pulse_Generator (Sender_exec_i &callback)
    : pulse_callback_ (callback)
  {
  }

  int
  pulse_Generator::handle_timeout (const ACE_Time_Value &, const void *)
  {
    // Notify the subscribers
    this->pulse_callback_.tick ();
    return 0;
  }
  //============================================================
  // Component Executor Implementation Class: Sender_exec_i
  //============================================================

  Sender_exec_i::Sender_exec_i (void)
    : rejected_ (false),
      rate_ (100)
  {
    this->ticker_ = new pulse_Generator (*this);
  }

  Sender_exec_i::~Sender_exec_i (void)
  {
  }

  ::CCM_DDS::CCM_ConnectorStatusListener_ptr
  Sender_exec_i::get_test_topic_connector_status (void)
  {
    return new ConnectorStatusListener_exec_i (this->rejected_);
  }

  // Supported operations and attributes.
  void
  Sender_exec_i::tick ()
  {
    for (CSL_SRTest_Table::iterator i = this->_ktests_.begin ();
        i != this->_ktests_.end ();
        ++i)
      {
         try
         {
           if (!CORBA::is_nil (this->writer_) ) {
              this->writer_->write_one(i->second,::DDS::HANDLE_NIL);
              i->second->x++;
           }
         }
         catch (const CCM_DDS::InternalError& )
         {
           ACE_ERROR ((LM_ERROR, ACE_TEXT ("Internal Error while creating topic for <%C>.\n"),
                    i->first.c_str ()));
         }
       }
  }

  void
  Sender_exec_i::start (void)
  {
    // calculate the interval time
    long usec = 10000000 / this->rate_;

    if (this->context_->get_CCM_object()->_get_orb ()->orb_core ()->reactor ()->schedule_timer (
                this->ticker_,
                0,
                ACE_Time_Value (0, usec),
                ACE_Time_Value (0, usec)) == -1)
    {
      ACE_ERROR ((LM_ERROR, ACE_TEXT ("Sender_exec_i::start : ")
                             ACE_TEXT ("Error scheduling timer")));
    }
  }

  void
  Sender_exec_i::stop (void)
  {
    this->context_->get_CCM_object()->_get_orb ()->orb_core ()->reactor ()->cancel_timer (this->ticker_);
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Sender_exec_i::stop : Timer canceled.\n")));
    delete this->ticker_;
  }

  void
  Sender_exec_i::set_session_context (::Components::SessionContext_ptr ctx)
  {
    this->context_ = ::CSL_SRTest::CCM_Sender_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
   }

  void
  Sender_exec_i::configuration_complete (void)
  {
    this->writer_  = this->context_->get_connection_test_topic_write_data ();
  }

  void
  Sender_exec_i::add_instance_of_topic (const char * key, int x)
  {
    TestTopic *new_key = new TestTopic;
    new_key->key = CORBA::string_dup(key);
    new_key->x = x;
    this->_ktests_[key] = new_key;
  }
  void
  Sender_exec_i::ccm_activate (void)
  {
    //add 2 different instances of topic
    this->add_instance_of_topic ("ONE",1);
    this->add_instance_of_topic ("TWO",2);
    this->start ();
  }

  void
  Sender_exec_i::ccm_passivate (void)
  {
    this->stop ();
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
    if(!this->rejected_.value ())
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("ERROR: did not receive the expected ")
                               ACE_TEXT ("warning 'on_sample_rejected' in Sender\n")
                    ));
      }
    else
      {
         ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Received the expected ")
                               ACE_TEXT ("'on_sample_rejected' in Sender\n")
                    ));
      }
  }

  extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_CSL_SRTest_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
