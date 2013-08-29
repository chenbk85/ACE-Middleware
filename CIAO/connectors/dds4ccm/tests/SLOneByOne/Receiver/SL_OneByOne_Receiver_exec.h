// -*- C++ -*-
// $Id$

#ifndef CIAO_SL_ONEBYONE_RECEIVER_EXEC_TKIVXN_H_
#define CIAO_SL_ONEBYONE_RECEIVER_EXEC_TKIVXN_H_

#include /**/ "ace/pre.h"

#include "SL_OneByOne_ReceiverEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Receiver_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_SL_OneByOne_Receiver_Impl
{
  typedef ACE_Atomic_Op <TAO_SYNCH_MUTEX, CORBA::ULong> Atomic_Long;

  class Receiver_exec_i;

  /**
   * Provider Executor Implementation Class: info_out_data_listener_exec_i
   */

  class info_out_data_listener_exec_i
    : public virtual ::SL_OneByOne::SL_OneByOneConnector::CCM_StateListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    info_out_data_listener_exec_i (
      ::SL_OneByOne::CCM_Receiver_Context_ptr ctx,
      Atomic_Long &,
      Atomic_Long &,
      Atomic_Long &,
      Atomic_Long &,
      Atomic_Long &,
      ACE_Thread_ID &);
    virtual ~info_out_data_listener_exec_i (void);

    //@{
    /** Operations and attributes from SL_OneByOne::SL_OneByOneConnector::StateListener. */

    virtual
    void on_creation (const ::TestTopic & datum,
    const ::CCM_DDS::ReadInfo & info);

    virtual
    void on_one_update (const ::TestTopic & datum,
    const ::CCM_DDS::ReadInfo & info);

    virtual
    void on_many_updates (const ::TestTopicSeq & data,
    const ::CCM_DDS::ReadInfoSeq & infos);

    virtual
    void on_deletion (const ::TestTopic & datum,
    const ::CCM_DDS::ReadInfo & info);
    //@}

  private:
    ::SL_OneByOne::CCM_Receiver_Context_var ciao_context_;
     Atomic_Long &on_many_updates_;
     Atomic_Long &on_creation_;
     Atomic_Long &on_one_update_;
     Atomic_Long &on_deletion_;
     Atomic_Long &samples_read_;
     ACE_Thread_ID &thread_id_;
  };

  /**
   * Provider Executor Implementation Class: info_out_status_exec_i
   */

  class info_out_status_exec_i
    : public virtual ::CCM_DDS::CCM_PortStatusListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    info_out_status_exec_i (
      ::SL_OneByOne::CCM_Receiver_Context_ptr ctx);
    virtual ~info_out_status_exec_i (void);

    //@{
    /** Operations and attributes from CCM_DDS::PortStatusListener. */

    virtual
    void on_requested_deadline_missed (::DDS::DataReader_ptr the_reader,
    const ::DDS::RequestedDeadlineMissedStatus & status);

    virtual
    void on_sample_lost (::DDS::DataReader_ptr the_reader,
    const ::DDS::SampleLostStatus & status);
    //@}

  private:
    ::SL_OneByOne::CCM_Receiver_Context_var ciao_context_;
    Atomic_Long on_many_updates_;
    Atomic_Long updater_data_;
    Atomic_Long on_creation_;
    Atomic_Long on_one_update_;
    Atomic_Long on_deletion_;
    ACE_Thread_ID thread_id_listener_;
  };

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  class Receiver_exec_i
    : public virtual Receiver_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Receiver_exec_i (void);
    virtual ~Receiver_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */

    virtual ::SL_OneByOne::SL_OneByOneConnector::CCM_StateListener_ptr
    get_info_out_data_listener (void);

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_info_out_status (void);
    //@}

    //@{
    /** Operations from Components::SessionComponent. */
    virtual void set_session_context (::Components::SessionContext_ptr ctx);
    virtual void configuration_complete (void);
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    //@{
    /** User defined public operations. */

    //@}

  private:
    ::SL_OneByOne::CCM_Receiver_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    ::SL_OneByOne::SL_OneByOneConnector::CCM_StateListener_var ciao_info_out_data_listener_;
    ::CCM_DDS::CCM_PortStatusListener_var ciao_info_out_status_;
    //@}

    //@{
    /** User defined members. */
    Atomic_Long on_many_updates_;
    Atomic_Long updater_data_;
    Atomic_Long on_creation_;
    Atomic_Long on_one_update_;
    Atomic_Long on_deletion_;
    Atomic_Long samples_read_;
    ACE_Thread_ID thread_id_listener_;
    //@}

    //@{
    /** User defined private operations. */

    //@}
  };

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_SL_OneByOne_Receiver_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
