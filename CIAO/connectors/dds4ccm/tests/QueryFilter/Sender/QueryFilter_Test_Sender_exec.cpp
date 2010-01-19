// -*- C++ -*-
// $Id$

#include "QueryFilter_Test_Sender_exec.h"
#include "ciao/Logger/Log_Macros.h"

namespace CIAO_QueryFilter_Test_Sender_Impl
{
  //============================================================
  // ConnectorStatusListener_exec_i
  //============================================================
  ConnectorStatusListener_exec_i::ConnectorStatusListener_exec_i (Sender_exec_i &callback)
    : callback_ (callback)
  {
  }

  ConnectorStatusListener_exec_i::~ConnectorStatusListener_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::ConnectorStatusListener
  void ConnectorStatusListener_exec_i::on_inconsistent_topic(
     ::DDS::Topic_ptr ,
     const DDS::InconsistentTopicStatus & )
  {
  }

  void ConnectorStatusListener_exec_i::on_requested_incompatible_qos(
    ::DDS::DataReader_ptr ,
     const DDS::RequestedIncompatibleQosStatus & )
  {
  }

  void ConnectorStatusListener_exec_i::on_sample_rejected(
     ::DDS::DataReader_ptr ,
     const DDS::SampleRejectedStatus & )
  {
  }

  void ConnectorStatusListener_exec_i::on_offered_deadline_missed(
     ::DDS::DataWriter_ptr ,
     const DDS::OfferedDeadlineMissedStatus & )
  {
  }

  void ConnectorStatusListener_exec_i::on_offered_incompatible_qos(
     ::DDS::DataWriter_ptr ,
     const DDS::OfferedIncompatibleQosStatus & )
  {
  }

  void ConnectorStatusListener_exec_i::on_unexpected_status(
    ::DDS::Entity_ptr /*the_entity*/,
    ::DDS::StatusKind  status_kind)
  {
    if (status_kind == ::DDS::PUBLICATION_MATCHED_STATUS)
      this->callback_.start ();
  }


  //============================================================
  // Restarter_exec_i
  //============================================================
  Restarter_exec_i::Restarter_exec_i (Sender_exec_i & callback)
    : callback_ (callback)
  {
  }

  Restarter_exec_i::~Restarter_exec_i (void)
  {
  }

  void
  Restarter_exec_i::restart_write ()
  {
    this->callback_.start ();
  }

  //============================================================
  // Component Executor Implementation Class: Sender_exec_i
  //============================================================
  Sender_exec_i::Sender_exec_i (void)
    : iterations_ (10),
      keys_ (5),
      done_ (false),
      ccm_activated_ (false)
  {
  }

  Sender_exec_i::~Sender_exec_i (void)
  {
  }

  void
  Sender_exec_i::start (void)
  {
    //start can be called more than once...
    if (!this->done_ && this->ccm_activated_)
      {
        this->done_ = true;
        if (!CORBA::is_nil (this->starter_))
          {
            this->starter_->set_reader_properties (this->keys_, this->iterations_);
          }
        else
          {
            ACE_ERROR ((LM_ERROR, ACE_TEXT ("ERROR: Unable to start the reader\n")));
          }
        for (CORBA::UShort iter_key = 1; iter_key < this->keys_ + 1; ++iter_key)
          {
            char key[7];
            QueryFilterTest *new_key = new QueryFilterTest;
            ACE_OS::sprintf (key, "KEY_%d", iter_key);
            new_key->symbol = CORBA::string_dup(key);
            for (CORBA::UShort iter = 1; iter < this->iterations_ + 1; ++iter)
              {
                new_key->iteration = iter;
                this->writer_->write_one (*new_key, ::DDS::HANDLE_NIL);
                ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Written key <%C> with <%d>\n"),
                            key, iter));
              }
          }
      }
  }

  ::CORBA::UShort
  Sender_exec_i::iterations (void)
  {
    return this->iterations_;
  }

  void
  Sender_exec_i::iterations (::CORBA::UShort iterations)
  {
    this->iterations_ = iterations;
  }

  ::CORBA::UShort
  Sender_exec_i::keys (void)
  {
    return this->keys_;
  }

  void
  Sender_exec_i::keys (::CORBA::UShort keys)
  {
    this->keys_ = keys;
  }

  ::CCM_DDS::CCM_ConnectorStatusListener_ptr
  Sender_exec_i::get_info_out_connector_status (void)
  {
    return new ConnectorStatusListener_exec_i (*this);
  }

  ::CCM_QueryFilterRestarter_ptr
  Sender_exec_i::get_restart_writer (void)
  {
    return new Restarter_exec_i (*this);
  }

  void
  Sender_exec_i::set_session_context (::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::QueryFilter_Test::CCM_Sender_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Sender_exec_i::configuration_complete (void)
  {
  }

  void
  Sender_exec_i::ccm_activate (void)
  {
    try
      {
        this->writer_ = this->context_->get_connection_info_write_data ();
        this->starter_ = this->context_->get_connection_start_reader ();
        this->ccm_activated_ = true;
      }
    catch (const CORBA::Exception& ex)
      {
        ex._tao_print_exception ("Exception caught:");
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("ERROR: GET_CONNECTION_START_READER : Exception caught\n")));
      }
    catch (...)
      {
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("ERROR: GET_CONNECTION_START_READER : Unknown exception caught\n")));
      }
  }

  void
  Sender_exec_i::ccm_passivate (void)
  {
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
  }

  extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_QueryFilter_Test_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
