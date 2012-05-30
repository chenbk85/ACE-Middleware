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

#include "Proxy_RW_Test_Receiver_exec.h"
#include "tao/ORB_Core.h"
#include "ace/Reactor.h"

#include "Connector/Proxy_RW_Test_Connector_conn.h"
#include "dds4ccm/impl/Utils.h"

namespace CIAO_Proxy_RW_Test_Receiver_Impl
{
  /**
   * Start Handler using IDL Proxy to Read
   */

  StartHandlerIdlProxyRead::StartHandlerIdlProxyRead (Receiver_exec_i &callback)
    : callback_ (callback)
  {
  }

  int
  StartHandlerIdlProxyRead::handle_exception (ACE_HANDLE)
  {
    this->callback_.start_read_using_idl_proxy ();
    return 0;
  }

  /**
   * Start Handler using CPP Proxy to Take
   */

  StartHandlerIdlProxyTake::StartHandlerIdlProxyTake (Receiver_exec_i &callback)
    : callback_ (callback)
  {
  }

  int
  StartHandlerIdlProxyTake::handle_exception (ACE_HANDLE)
  {
    this->callback_.start_take_using_idl_proxy ();
    return 0;
  }

  /**
   * Check last
   */
  LastSampleChecker::LastSampleChecker (Receiver_exec_i &callback,
                                        const ::ReaderStarter::assignment &task,
                                        const ::CORBA::UShort &iterations)
    : callback_ (callback)
      , task_ (task)
      , iterations_ (iterations)
  {
  }

  LastSampleChecker::~LastSampleChecker ()
  {
  }

  int
  LastSampleChecker::handle_timeout (const ACE_Time_Value &, const void *)
  {
    ACE_DEBUG ((LM_DEBUG, "Checking if last sample "
                          "is available in DDS...\n"));
    if (this->callback_.check_last (this->iterations_ + (this->iterations_ * this->task_)))
      {
        this->callback_.start_task (this->task_);
      }
    return 0;
  }

  /**
   * Facet Executor Implementation Class: info_out_data_listener_exec_i
   */

  info_out_data_listener_exec_i::info_out_data_listener_exec_i (
        ::Proxy_RW_Test::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::Proxy_RW_Test::CCM_Receiver_Context::_duplicate (ctx))
  {
  }

  info_out_data_listener_exec_i::~info_out_data_listener_exec_i (void)
  {
  }

  // Operations from ::Proxy_RW_Test::ProxyReadWriteTestConnector::Listener

  void
  info_out_data_listener_exec_i::on_one_data (const ::ProxyReadWriteTest & /* datum */,
  const ::CCM_DDS::ReadInfo & /* info */)
  {
    /* Your code here. */
  }

  void
  info_out_data_listener_exec_i::on_many_data (const ::ProxyReadWriteTestSeq & /* data */,
  const ::CCM_DDS::ReadInfoSeq & /* infos */)
  {
    /* Your code here. */
  }

  /**
   * Facet Executor Implementation Class: info_out_status_exec_i
   */

  info_out_status_exec_i::info_out_status_exec_i (
        ::Proxy_RW_Test::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::Proxy_RW_Test::CCM_Receiver_Context::_duplicate (ctx))
  {
  }

  info_out_status_exec_i::~info_out_status_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::PortStatusListener

  void
  info_out_status_exec_i::on_requested_deadline_missed (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::RequestedDeadlineMissedStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_out_status_exec_i::on_sample_lost (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::SampleLostStatus & /* status */)
  {
    /* Your code here. */
  }

  /**
   * Facet Executor Implementation Class: reader_start_exec_i
   */

  reader_start_exec_i::reader_start_exec_i (
        ::Proxy_RW_Test::CCM_Receiver_Context_ptr ctx,
        Receiver_exec_i &callback)
    : ciao_context_ (
        ::Proxy_RW_Test::CCM_Receiver_Context::_duplicate (ctx))
      , callback_ (callback)
  {
  }

  reader_start_exec_i::~reader_start_exec_i (void)
  {
  }

  // Operations from ::ReaderStarter

  void
  reader_start_exec_i::start_read (::ReaderStarter::assignment task)
  {
    this->callback_.start_read (task);
  }

  void
  reader_start_exec_i::set_reader_properties (::CORBA::UShort nr_keys,
  ::CORBA::UShort nr_iterations)
  {
    this->callback_.keys (nr_keys);
    this->callback_.iterations (nr_iterations);
  }

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  Receiver_exec_i::Receiver_exec_i (void)
    : iterations_ (0)
      , keys_ (0)
      , checker_ (0)
  {
    ACE_NEW_THROW_EX (this->rh_idl_read_,
                      StartHandlerIdlProxyRead (*this),
                      ::CORBA::NO_MEMORY ());
    ACE_NEW_THROW_EX (this->rh_idl_take_,
                      StartHandlerIdlProxyTake (*this),
                      ::CORBA::NO_MEMORY ());
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
    delete this->rh_idl_read_;
    delete this->rh_idl_take_;
  }

  // Supported operations and attributes.
  ACE_Reactor*
  Receiver_exec_i::reactor (void)
  {
    ACE_Reactor* reactor = 0;
    ::CORBA::Object_var ccm_object =
      this->ciao_context_->get_CCM_object();
    if (! ::CORBA::is_nil (ccm_object.in ()))
      {
        ::CORBA::ORB_var orb = ccm_object->_get_orb ();
        if (! ::CORBA::is_nil (orb.in ()))
          {
            reactor = orb->orb_core ()->reactor ();
          }
      }
    if (reactor == 0)
      {
        throw ::CORBA::INTERNAL ();
      }
    return reactor;
  }

  bool
  Receiver_exec_i::check_last (const ::CORBA::UShort &iteration_to_check)
  {
    ::Proxy_RW_Test::ProxyReadWriteTestConnector::Reader_var reader =
      this->ciao_context_->get_connection_info_out_data ();
    try
      {
        ProxyReadWriteTest datum;
        ::CCM_DDS::ReadInfo readinfo;
        char key[10];
        ACE_OS::sprintf (key, "KEY_%d", this->keys_);
        datum.key = CORBA::string_dup (key);
        reader->read_one_last (
                datum,
                readinfo,
                ::DDS::HANDLE_NIL);
        ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::check_last - "
                              "last iteration <%02d> - <%02d>\n",
                               datum.iteration,
                               iteration_to_check));
        return datum.iteration >= iteration_to_check;
      }
    catch (const ::CCM_DDS::InternalError &)
      {
      }
    catch (const ::CCM_DDS::NonExistent &)
      {
      }
    catch (...)
      {
        ACE_ERROR ((LM_ERROR, "Receiver_exec_i::check_last: "
                              "ERROR: Unexpected exception caught\n"));
      }
    return false;
  }

  void
  Receiver_exec_i::check_samples (const ProxyReadWriteTestSeq & data,
                                  ::ReaderStarter::assignment task)
  {
    for (::CORBA::ULong i = 0; i < data.length (); ++i)
      {
        ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::check_samples - "
                  "Received sample: key <%C> - iteration <%u>\n",
                  data[i].key.in (),
                  data[i].iteration));
        //TODO Check for invalid iterataions
      }
    WriterRestarter_var restarter =
      this->ciao_context_->get_connection_writer_restart ();
    if (!::CORBA::is_nil (restarter.in ()))
      {
        if (task == ::ReaderStarter::READ_USING_IDL_PROXY)
          {
            ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::check_samples - "
                      "Inform the Sender that is should write the next bunch.\n"));
            restarter->restart_write (::ReaderStarter::TAKE_USING_IDL_PROXY);
          }
      }
    else
      {
        ACE_ERROR ((LM_ERROR, "Receiver_exec_i::check_samples - "
                  "ERROR: Restarter is nil\n"));
      }
  }

  void
  Receiver_exec_i::start_read (::ReaderStarter::assignment task)
  {
    if (this->checker_)
      {
        this->reactor ()->cancel_timer (this->checker_);
        delete this->checker_;
        this->checker_ = 0;
      }
    ACE_NEW_THROW_EX (this->checker_,
                      LastSampleChecker (*this,
                                         task,
                                         this->iterations_),
                      ::CORBA::NO_MEMORY ());
    this->schedule_timer ();
  }

  void
  Receiver_exec_i::start_task (::ReaderStarter::assignment task)
  {
    if (this->checker_)
      {
        this->reactor ()->cancel_timer (this->checker_);
        delete this->checker_;
        this->checker_ = 0;
        ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::start_task - "
                  "Timer canceled and deleted.\n"));
      }
    if (task == ::ReaderStarter::READ_USING_IDL_PROXY)
      {
        this->reactor ()->notify (this->rh_idl_read_);
      }
    else if (task == ::ReaderStarter::TAKE_USING_IDL_PROXY)
      {
        this->reactor ()->notify (this->rh_idl_take_);
      }
  }

  void
  Receiver_exec_i::schedule_timer (void)
  {
    if (this->reactor ()->schedule_timer (this->checker_,
                                          0,
                                          ACE_Time_Value (1, 0),
                                          ACE_Time_Value (1, 0)) == -1)
      {
        ACE_ERROR ((LM_ERROR, "Receiver_exec_i::schedule_timer - "
                  "ERROR: Error while starting LastSampleChecker\n"));
      }
  }

  Receiver_exec_i::TypedDataReader::_ptr_type
  Receiver_exec_i::get_typed_idl_reader (void)
  {
    TypedDataReader::_var_type idl_reader;
    ::DDS::DataReader_var dds_dr =
      this->ciao_context_->get_connection_info_out_dds_entity ();

    if (::CORBA::is_nil (dds_dr.in ()))
      {
        ACE_ERROR ((LM_ERROR, "ERROR : Receiver_exec_i::get_typed_idl_reader - "
                    "DataReader connection is NIL.\n"));
        return TypedDataReader::_nil ();
      }

    ::CIAO::DDS4CCM::CCM_DataReader * ccm_dr =
      dynamic_cast < ::CIAO::DDS4CCM::CCM_DataReader * > (dds_dr.in ());

    if (ccm_dr)
      {
        ::DDS::DataReader_var tmp = ccm_dr->get_dds_entity ();
        if (! ::CORBA::is_nil (tmp.in ()))
          {
            idl_reader =
              ::CIAO_Proxy_RW_Test_ProxyReadWriteTestConnector_DDS_Event_Impl
              ::ProxyReadWriteTest_DDS_Traits::typed_reader_type::_narrow (tmp.in ());
            return idl_reader._retn ();
          }
        else
          {
            ACE_ERROR ((LM_ERROR, "Receiver_exec_i::get_typed_idl_reader - "
                      "ERROR: CCM DataReader returned NIL as DDS entity\n"));
            return TypedDataReader::_nil ();
          }
      }
    else
      {
        ACE_ERROR ((LM_ERROR, "Receiver_exec_i::get_typed_idl_reader - "
                  "ERROR: Unable to cast to CCM DataReader\n"));
        return TypedDataReader::_nil ();
      }
  }

  void
  Receiver_exec_i::start_read_using_idl_proxy (void)
  {
    TypedDataReader::_var_type idl_reader = this->get_typed_idl_reader ();

    if (!::CORBA::is_nil (idl_reader.in ()))
      {

        ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::start_read_using_idl_proxy - "
                  "Start reading."));
        // Start to read
        ProxyReadWriteTestSeq data;
        ::DDS::SampleInfoSeq  info;

        ::DDS::ReturnCode_t retcode = idl_reader->read (data,
                                                        info,
                                                        ::DDS::LENGTH_UNLIMITED,
                                                        ::DDS::NOT_READ_SAMPLE_STATE,
                                                        ::DDS::ANY_VIEW_STATE,
                                                        ::DDS::ALIVE_INSTANCE_STATE);
        if (retcode == ::DDS::RETCODE_OK)
          {
            this->check_samples (data,
                                 ::ReaderStarter::READ_USING_IDL_PROXY);
          }
        else
          {
            ACE_ERROR ((LM_ERROR, "Receiver_exec_i::start_read_using_idl_proxy - "
                      "ERROR: Error during read: <%C>\n",
                      ::CIAO::DDS4CCM::translate_retcode (retcode)));
          }
      }
  }

  void
  Receiver_exec_i::start_take_using_idl_proxy (void)
  {
    TypedDataReader::_var_type idl_reader = this->get_typed_idl_reader ();

    if (!::CORBA::is_nil (idl_reader.in ()))
      {
        // Start to read
        ProxyReadWriteTestSeq data;
        ::DDS::SampleInfoSeq  info;

        ::DDS::ReturnCode_t retcode = idl_reader->take (data,
                                                        info,
                                                        ::DDS::LENGTH_UNLIMITED,
                                                        ::DDS::NOT_READ_SAMPLE_STATE,
                                                        ::DDS::ANY_VIEW_STATE,
                                                        ::DDS::ALIVE_INSTANCE_STATE);
        if (retcode == ::DDS::RETCODE_OK)
          {
            this->check_samples (data,
                                 ::ReaderStarter::TAKE_USING_IDL_PROXY);
          }
        else
          {
            ACE_ERROR ((LM_ERROR, "Receiver_exec_i::start_read_using_idl_proxy - "
                      "ERROR: Error during read: <%C>\n",
                      ::CIAO::DDS4CCM::translate_retcode (retcode)));
          }
      }
  }

  void
  Receiver_exec_i::keys (::CORBA::UShort keys)
  {
    this->keys_ = keys;
  }

  void
  Receiver_exec_i::iterations (::CORBA::UShort iterations)
  {
    this->iterations_ = iterations;
  }
  // Component attributes and port operations.

  ::Proxy_RW_Test::ProxyReadWriteTestConnector::CCM_Listener_ptr
  Receiver_exec_i::get_info_out_data_listener (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_out_data_listener_.in ()))
      {
        info_out_data_listener_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_out_data_listener_exec_i (
            this->ciao_context_.in ()),
            ::Proxy_RW_Test::ProxyReadWriteTestConnector::CCM_Listener::_nil ());

          this->ciao_info_out_data_listener_ = tmp;
      }

    return
      ::Proxy_RW_Test::ProxyReadWriteTestConnector::CCM_Listener::_duplicate (
        this->ciao_info_out_data_listener_.in ());
  }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_out_status (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_out_status_.in ()))
      {
        info_out_status_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_out_status_exec_i (
            this->ciao_context_.in ()),
            ::CCM_DDS::CCM_PortStatusListener::_nil ());

          this->ciao_info_out_status_ = tmp;
      }

    return
      ::CCM_DDS::CCM_PortStatusListener::_duplicate (
        this->ciao_info_out_status_.in ());
  }

  ::CCM_ReaderStarter_ptr
  Receiver_exec_i::get_reader_start (void)
  {
    if ( ::CORBA::is_nil (this->ciao_reader_start_.in ()))
      {
        reader_start_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          reader_start_exec_i (
            this->ciao_context_.in (),
            *this),
            ::CCM_ReaderStarter::_nil ());

          this->ciao_reader_start_ = tmp;
      }

    return
      ::CCM_ReaderStarter::_duplicate (
        this->ciao_reader_start_.in ());
  }

  // Operations from Components::SessionComponent.

  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::Proxy_RW_Test::CCM_Receiver_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Receiver_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Proxy_RW_Test_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);

    return retval;
  }
}
