// -*- C++ -*-
//
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.2
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
// be/be_codegen.cpp:1217

#ifndef CIAO_BROKER_EXEC_H_
#define CIAO_BROKER_EXEC_H_

#include /**/ "ace/pre.h"

#include "BrokerEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Broker_exec_export.h"
#include "tao/LocalObject.h"
#include "ace/Task.h"
#include "ace/Reactor.h"

namespace CIAO_Quoter_Broker_Impl
{

  class Broker_exec_i;
  /**
  * @class reader activity generator
  *
  * @brief an active object used by StockBroker to perform a periodical read action
  *
  */
  class read_action_Generator : public ACE_Task_Base
  {
  public:
    read_action_Generator (Broker_exec_i &callback);

    ~read_action_Generator ();

    /// Hook method that performs application-defined initialization activities
    int open_h (void);

    /// Hook method that performs application-defined destruction activites
    int close_h (void);

    /// appliation-defined method for starting the pulse-generation service
    int start (CORBA::ULong hertz);

    /// application-defined method for stopping the pulse-generation service
    int stop (void);

    /// Indicate whether the current object is active
    int active (void);

    /// Handle the timeout.
    virtual int handle_timeout (const ACE_Time_Value &tv,
                                const void *arg);

    /// Called when timer handler is removed.
    virtual int handle_close (ACE_HANDLE handle,
                              ACE_Reactor_Mask close_mask);

    /// Hook methods implemnting the task's service processing,
    /// invoked by all threads activated by activate () method
    virtual int svc (void);

  private:
    /// Tracking whether we are actively generating pulse or not.
    int active_;

    /// Maintains a handle that actually process the event
    Broker_exec_i &pulse_callback_;

  };



  class BROKER_EXEC_Export Stock_Info_RawListener_exec_i
    : public virtual ::CCM_DDS::CCM_Stock_Info_RawListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    Stock_Info_RawListener_exec_i (void);
    virtual ~Stock_Info_RawListener_exec_i (void);

    // Operations and attributes from ::CCM_DDS::Stock_Info_RawListener

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void
    on_data (
      const ::Quoter::Stock_Info & an_instance,
      const ::CCM_DDS::ReadInfo & info);
  };
  class BROKER_EXEC_Export PortStatusListener_exec_i
    : public virtual ::CCM_DDS::CCM_PortStatusListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    PortStatusListener_exec_i (void);
    virtual ~PortStatusListener_exec_i (void);

    // Operations and attributes from ::CCM_DDS::PortStatusListener

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void
    on_requested_deadline_missed (
      ::DDS::DataReader_ptr the_reader,
      const ::DDS::RequestedDeadlineMissedStatus & status);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void
    on_sample_lost (
      ::DDS::DataReader_ptr the_reader,
      const ::DDS::SampleLostStatus & status);
  };


class BROKER_EXEC_Export ConnectorStatusListener_exec_i
    : public virtual ::CCM_DDS::CCM_ConnectorStatusListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    ConnectorStatusListener_exec_i (void);
    virtual ~ConnectorStatusListener_exec_i (void);

    virtual
      void on_inconsistent_topic( ::DDS::Topic_ptr the_topic,
                                const DDS::InconsistentTopicStatus & status);
    virtual
    void on_requested_incompatible_qos( ::DDS::DataReader_ptr the_reader,
                                        const DDS::RequestedIncompatibleQosStatus & status);
    virtual
    void on_sample_rejected( ::DDS::DataReader_ptr the_reader,
                             const DDS::SampleRejectedStatus & status);
    virtual
      void on_offered_deadline_missed( ::DDS::DataWriter_ptr the_writer,
                                     const DDS::OfferedDeadlineMissedStatus & status);
    virtual
    void on_offered_incompatible_qos( ::DDS::DataWriter_ptr the_writer,
                                      const DDS::OfferedIncompatibleQosStatus & status);
    virtual
      void on_unexpected_status( ::DDS::Entity_ptr the_entity,
       ::DDS::StatusKind  status_kind);

  };


  class BROKER_EXEC_Export Broker_exec_i
    : public virtual Broker_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Broker_exec_i (void);
    virtual ~Broker_exec_i (void);

    // Supported operations and attributes.

    // Component attributes.

    // Port operations.
    virtual ::CCM_DDS::CCM_ConnectorStatusListener_ptr
    get_info_out_connector_status (void);



    virtual ::CCM_DDS::CCM_Stock_Info_RawListener_ptr
    get_info_out_data_listener (void);

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_info_out_status (void);
    void read_one (void);
    void read_one_history (void);
    void read_all(void);
    void read_all_history(void);
    // Operations from Components::SessionComponent.


    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    virtual void start (void);
    virtual void stop (void);



  private:
    ::Quoter::CCM_Broker_Context_var context_;
    read_action_Generator * ticker_;
    ::CCM_DDS::Stock_Info_Reader_var reader_;
    ::CCM_DDS::Stock_Info_Getter_var getter_;
  };

  extern "C" BROKER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Quoter_Broker_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */

