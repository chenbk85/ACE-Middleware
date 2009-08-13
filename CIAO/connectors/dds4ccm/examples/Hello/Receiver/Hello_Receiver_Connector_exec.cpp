// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.6.9 ****
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

#define MAX_STRING_SIZE         1024

#include "Hello_Receiver_Connector_exec.h"
#include "ciao/CIAO_common.h"

#include "dds4ccm/impl/ndds/DomainParticipantFactory.h"
#include "dds4ccm/impl/ndds/DataReader.h"

/* The listener of events and data from the middleware */
class HelloListener : public ::DDS::DataReaderListener
{
  public:
    HelloListener ( ::CCM_DDS::string_RawListener_ptr listener,
                    ::CCM_DDS::PortStatusListener_ptr statuslistener);
    virtual void on_data_available( ::DDS::DataReader *reader);
    virtual void
    on_requested_deadline_missed (
      ::DDS::DataReader_ptr the_reader,
      const ::DDS::RequestedDeadlineMissedStatus & status);
    virtual void
    on_sample_lost (
      ::DDS::DataReader_ptr the_reader,
      const ::DDS::SampleLostStatus & status);
    bool enabled () const;
    void enabled (bool enable);
  private:
    ACE_Atomic_Op <TAO_SYNCH_MUTEX, bool> enabled_;
    ::CCM_DDS::string_RawListener_var listener_;
    ::CCM_DDS::PortStatusListener_var statuslistener_;
};

/* This method gets called back by DDS when one or more data samples have been
 * received.
 */

HelloListener::HelloListener ( ::CCM_DDS::string_RawListener_ptr listener, ::CCM_DDS::PortStatusListener_ptr statuslistener) :
  enabled_ (true), // @todo should be false later on
  listener_ ( ::CCM_DDS::string_RawListener::_duplicate (listener)),
  statuslistener_ (::CCM_DDS::PortStatusListener::_duplicate (statuslistener))
{
}

bool
HelloListener::enabled () const
{
  return this->enabled_.value ();
}

void
HelloListener::enabled (bool enable)
{
  this->enabled_ = enable;
}

void
HelloListener::on_requested_deadline_missed (
      ::DDS::DataReader_ptr the_reader,
      const ::DDS::RequestedDeadlineMissedStatus & status)
{
  this->statuslistener_->on_requested_deadline_missed (the_reader, status);
}

void
HelloListener::on_sample_lost (
      ::DDS::DataReader_ptr the_reader,
      const ::DDS::SampleLostStatus & status)
{
  this->statuslistener_->on_sample_lost (the_reader, status);
}

void
HelloListener::on_data_available( ::DDS::DataReader *reader)
{
  if (this->enabled_.value ())
    {
    /* Perform a safe type-cast from a generic data reader into a
     * specific data reader for the type "DDS::String"
     */
    ::CIAO::DDS4CCM::RTI::RTI_DataReader_i* rd = dynamic_cast < ::CIAO::DDS4CCM::RTI::RTI_DataReader_i*>(reader);
    DDSStringDataReader * string_reader = DDSStringDataReader::narrow(rd->get_datareader ());
    if (!string_reader) {
        /* In this specific case, this will never fail */
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("DDSStringDataReader::narrow failed.\n")));
        return;
    }

    /* Loop until there are messages available in the queue */
    for(;;) {
        char sample[MAX_STRING_SIZE];
        char *ptr_sample  = &sample[0];
        DDS_SampleInfo        info;
        DDS_ReturnCode_t retcode = string_reader->take_next_sample(
                            ptr_sample,
                            info);
        if (retcode == DDS_RETCODE_NO_DATA) {
            /* No more samples */
            break;
        } else if (retcode != DDS_RETCODE_OK) {
            ACE_ERROR ((LM_ERROR, ACE_TEXT ("Unable to take data from data reader, error %d.\n"), retcode));
            return;
        }
        if (info.valid_data) {
            ::CCM_DDS::ReadInfo empty;
            listener_->on_data (sample, empty);
    }
  }
  }
}

namespace CIAO_Hello_DDS_Hello_receiver_Connector_Impl
{
  //============================================================
  // Facet Executor Implementation Class: string_Reader_exec_i
  //============================================================

  string_Reader_exec_i::string_Reader_exec_i (DDSStringDataReader *reader)
    : reader_ (reader),
      condition_ (0)
  {
  }

  string_Reader_exec_i::~string_Reader_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::string_Reader

  void
  string_Reader_exec_i::read_all (
    ::CCM_DDS::string_Reader::stringSeq_out /* instances */,
    ::CCM_DDS::ReadInfoSeq_out /* infos */)
  {
    //this->reader_->read
    /* Your code here. */
  }

  void
  string_Reader_exec_i::read_all_history (
    ::CCM_DDS::string_Reader::stringSeq_out /* instances */,
    ::CCM_DDS::ReadInfoSeq_out /* infos */)
  {
    /* Your code here. */
  }

  void
  string_Reader_exec_i::read_one (
    char *& an_instance,
    ::CCM_DDS::ReadInfo_out info)
  {
    DDS_StringSeq data;
    DDS_SampleInfoSeq sample_info;
    DDS_ReturnCode_t retval;
    if (this->condition_)
      {
        retval = this->reader_->read_w_condition (data, sample_info, 1, this->condition_);
      }
    else
      {
        retval = this->reader_->read (data,
                           sample_info,
                           1,
                           DDS_READ_SAMPLE_STATE | DDS_NOT_READ_SAMPLE_STATE ,
                           DDS_NEW_VIEW_STATE | DDS_NOT_NEW_VIEW_STATE,
                           DDS_ALIVE_INSTANCE_STATE);
       }
    if (retval == DDS_RETCODE_OK)
      {
        an_instance = data[0];
        info.timestamp.sec = sample_info[0].reception_timestamp.sec;
        info.timestamp.nanosec = sample_info[0].reception_timestamp.nanosec;
      }
    else
      {
        //printf ("failed %d", retval);
        throw ::CCM_DDS::InternalError (retval, 0);
      }
  }

  void
  string_Reader_exec_i::read_one_history (
    const char * /* an_instance */,
    ::CCM_DDS::string_Reader::stringSeq_out /* instances */,
    ::CCM_DDS::ReadInfoSeq_out /* infos */)
  {
    /* Your code here. */
  }

  ::CCM_DDS::QueryFilter *
  string_Reader_exec_i::filter (void)
  {
    ::CCM_DDS::QueryFilter *qf = new ::CCM_DDS::QueryFilter;
    qf->query = CORBA::string_dup (this->condition_->get_query_expression());
    ::DDS_StringSeq seq;
    ::DDS_ReturnCode_t const retval = this->condition_->get_query_parameters (seq);
    if (retval == DDS_RETCODE_OK)
      {
        qf->query_parameters.length (seq.length ());
        for (::DDS_Long index = 0; index < seq.length (); index++)
          {
            qf->query_parameters[index] = CORBA::string_dup (seq[index]);
          }
      }

    return qf;
  }

  void
  string_Reader_exec_i::filter (
    const ::CCM_DDS::QueryFilter &filter)
  {
    if (this->condition_)
      {
        DDS_ReturnCode_t const retval = this->reader_->delete_readcondition (this->condition_);
        ACE_UNUSED_ARG (retval);
      }
    DDS_StringSeq params;
    for (::DDS::StringSeq::size_type index = 0; index < filter.query_parameters.length (); index++)
      {
        //params[index] = filter.query_parameters[index].in ();
      }
    this->condition_ = this->reader_->create_querycondition (
      DDS_READ_SAMPLE_STATE | DDS_NOT_READ_SAMPLE_STATE ,
      DDS_NEW_VIEW_STATE | DDS_NOT_NEW_VIEW_STATE,
      DDS_ALIVE_INSTANCE_STATE,
      filter.query,
      params);
    if (!this->condition_)
      {
        throw ::CCM_DDS::BadParameter ();
      }
  }
  //============================================================
  // Facet Executor Implementation Class: ListenerControl_exec_i
  //============================================================

  ListenerControl_exec_i::ListenerControl_exec_i (void)
  {
  }

  ListenerControl_exec_i::~ListenerControl_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::ListenerControl

  ::CORBA::Boolean
  ListenerControl_exec_i::enabled (void)
  {
    // Need to control the data listener
    /* Your code here. */
    return false;
  }

  void
  ListenerControl_exec_i::enabled (
    ::CORBA::Boolean enabled)
  {
    if (enabled)
      {
        // @todo
      }
  }
  //============================================================
  // Facet Executor Implementation Class: DataReader_exec_i
  //============================================================

  //============================================================
  // Component Executor Implementation Class: Hello_receiver_Connector_exec_i
  //============================================================

  Hello_receiver_Connector_exec_i::Hello_receiver_Connector_exec_i (void)
    : dds_configured_ (false)
  {
  }

  Hello_receiver_Connector_exec_i::~Hello_receiver_Connector_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes.

  // Port operations.

  ::CCM_DDS::CCM_string_Reader_ptr
  Hello_receiver_Connector_exec_i::get_receiver_data (void)
  {
    this->configure_dds ();
    ::CIAO::DDS4CCM::RTI::RTI_DataReader_i* rd = dynamic_cast < ::CIAO::DDS4CCM::RTI::RTI_DataReader_i*>(this->dr_.in ());
    DDSStringDataReader * string_reader = DDSStringDataReader::narrow(rd->get_datareader ());
    if (string_reader)
      return new string_Reader_exec_i (string_reader);
      
    throw ::CORBA::INTERNAL ();
  }

  ::CCM_DDS::CCM_ListenerControl_ptr
  Hello_receiver_Connector_exec_i::get_receiver_control (void)
  {
    this->configure_dds ();
//    return ::DDS::CCM_DataWriter::_duplicate (this->dw_.in ());

    /* Your code here. */
    // @todo
    return new ListenerControl_exec_i ();
  }

  ::DDS::CCM_DataReader_ptr
  Hello_receiver_Connector_exec_i::get_receiver_dds_entity (void)
  {
    this->configure_dds ();
    /* Your code here. */
    // @todo
    return ::DDS::CCM_DataReader::_duplicate (this->dr_.in ());
  }

  // Operations from Components::SessionComponent.

  void
  Hello_receiver_Connector_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    ::Hello_DDS::CCM_Hello_receiver_Connector_Context_var lctx =
      ::Hello_DDS::CCM_Hello_receiver_Connector_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (lctx.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
      
    this->context_ = lctx;
  }

  void
  Hello_receiver_Connector_exec_i::configuration_complete (void)
  {
    this->configure_dds ();
    /* Your code here. */
  }

  void
  Hello_receiver_Connector_exec_i::ccm_activate (void)
  {
    /* Your code here. */
    /* Test code to test the reader interface
    ::CCM_DDS::CCM_string_Reader_var reader = this->get_receiver_data ();
    CORBA::String_var string;
    CCM_DDS::ReadInfo_var ri;
    reader->read_one (string.out (),  ri.out ());
    printf ("read <%s>\n", string.in ());
    */
  }

  void
  Hello_receiver_Connector_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Hello_receiver_Connector_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  void
  Hello_receiver_Connector_exec_i::configure_dds (void)
  {
    if (this->dds_configured_)
      return;

    try
      {
        //NDDSConfigLogger::get_instance()->set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API,
          //                                                        NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL );

        dpf_ = new CIAO::DDS4CCM::RTI::RTI_DomainParticipantFactory_i ();
        ::DDS::DomainParticipantQos qos;
        dp_ = dpf_->create_participant (0, qos, 0, 0);

        ::DDS::TopicQos tqos;
        t_ = dp_->create_topic ("Hello, World",
                                CIAO::DDS4CCM::RTI::String_Traits::type_support::get_type_name (),
                                tqos,
                                0,
                                DDS_STATUS_MASK_NONE);

        ::DDS::SubscriberQos sqos;
        sub_ = dp_->create_subscriber (sqos,
                                      0,
                                      0);

        ::DDS::DataReaderQos drqos;
        ::CCM_DDS::string_RawListener_var rawlistener =
          this->context_->get_connection_receiver_listener ();

        ::CCM_DDS::PortStatusListener_var portstatuslistener =
          this->context_->get_connection_receiver_status ();

        ::DDS::DataReaderListener_ptr temp = new HelloListener (rawlistener.in (), portstatuslistener.in ());
        this->listener_ = temp;
        DDS::DataReader_var drv_tmp = sub_->create_datareader (t_.in (),
                                                               drqos,
                                                               listener_.in (),
                                                               DDS_DATA_AVAILABLE_STATUS);

        dr_ = DDS::CCM_DataReader::_narrow (drv_tmp);
        printf ("setup done\n");
      }
    catch (const CORBA::Exception &ex)
      {
        CIAO_ERROR ((LM_ERROR, CLINFO "Hello_receiver_Connector_exec_i::configure_dds - "
                     "Caught CORBA exception %C\n",
                     ex._info ().c_str ()));
      }
    catch (...)
      {
        CIAO_ERROR ((LM_ERROR, CLINFO "Hello_receiver_Connector_exec_i::configure_dds - "
                     "Error: caught unknown C++ exception while configuring DDS\n"));
      }

    this->dds_configured_ = true;
  }

  extern "C" HELLO_RECEIVER_CONNECTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Hello_DDS_Hello_receiver_Connector_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_RETURN (
      retval,
      Hello_receiver_Connector_exec_i,
      ::Components::EnterpriseComponent::_nil ());

    return retval;
  }
}

namespace CIAO_Hello_DDS_Hello_receiver_Connector_Impl
{
  //============================================================
  // Home Executor Implementation Class: ReceiverConnectorHome_exec_i
  //============================================================

  ReceiverConnectorHome_exec_i::ReceiverConnectorHome_exec_i (void)
  {
  }

  ReceiverConnectorHome_exec_i::~ReceiverConnectorHome_exec_i (void)
  {
  }

  // All operations and attributes.

  // Factory operations.

  // Finder operations.

  // Implicit operations.

  ::Components::EnterpriseComponent_ptr
  ReceiverConnectorHome_exec_i::create (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (
      retval,
      Hello_receiver_Connector_exec_i,
      ::CORBA::NO_MEMORY ());

    return retval;
  }

  extern "C" HELLO_RECEIVER_CONNECTOR_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Hello_DDS_ReceiverConnectorHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();

    ACE_NEW_RETURN (
      retval,
      ReceiverConnectorHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());

    return retval;
  }
}

