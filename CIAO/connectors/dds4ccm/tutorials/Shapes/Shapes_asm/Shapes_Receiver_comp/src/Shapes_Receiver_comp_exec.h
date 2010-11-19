// -*- C++ -*-
// $Id$

#ifndef CIAO__________TUTORIAL_CODE_SHAPES_RECEIVER_COMP_SHAPES_RECEIVER_COMP_EXEC_GD0QCU_H_
#define CIAO__________TUTORIAL_CODE_SHAPES_RECEIVER_COMP_SHAPES_RECEIVER_COMP_EXEC_GD0QCU_H_

#include /**/ "ace/pre.h"

#include "Shapes_Receiver_compEC.h"

#include /**/ "Shapes_Receiver_comp_exec_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"

namespace CIAO_Shapes_Receiver_comp_Impl
{

  /**
   * Provider Executor Implementation Class: info_out_data_listener_exec_i
   */
  //============================================================
  //
  //============================================================

  class SHAPES_RECEIVER_COMP_EXEC_Export info_out_data_listener_exec_i
    : public virtual ::Shapes::ShapeType_conn::CCM_Listener,
      public virtual ::CORBA::LocalObject
  {
  public:
    info_out_data_listener_exec_i (
      ::Shapes::CCM_Receiver_comp_Context_ptr ctx);
    virtual ~info_out_data_listener_exec_i (void);

    // Operations and attributes from ::Shapes::ShapeType_conn::Listener

    virtual
    void on_one_data (const ::ShapeType & datum,
    const ::CCM_DDS::ReadInfo & info);

    virtual
    void on_many_data (const ::ShapeTypeSeq & data,
    const ::CCM_DDS::ReadInfoSeq & infos);

  private:
    ::Shapes::CCM_Receiver_comp_Context_var ciao_context_;
  };

  //============================================================
  // Provider Executor Implementation Class: info_out_status_exec_i
  //============================================================

  class SHAPES_RECEIVER_COMP_EXEC_Export info_out_status_exec_i
    : public virtual ::CCM_DDS::CCM_PortStatusListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    info_out_status_exec_i (
      ::Shapes::CCM_Receiver_comp_Context_ptr ctx);
    virtual ~info_out_status_exec_i (void);

    // Operations and attributes from ::CCM_DDS::PortStatusListener

    virtual
    void on_requested_deadline_missed (::DDS::DataReader_ptr the_reader,
    const ::DDS::RequestedDeadlineMissedStatus & status);

    virtual
    void on_sample_lost (::DDS::DataReader_ptr the_reader,
    const ::DDS::SampleLostStatus & status);

  private:
    ::Shapes::CCM_Receiver_comp_Context_var ciao_context_;
  };

  //============================================================
  // Component Executor Implementation Class: Receiver_comp_exec_i
  //============================================================

  class SHAPES_RECEIVER_COMP_EXEC_Export Receiver_comp_exec_i
    : public virtual Receiver_comp_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Receiver_comp_exec_i (void);
    virtual ~Receiver_comp_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */

    virtual ::Shapes::ShapeType_conn::CCM_Listener_ptr
    get_info_out_data_listener (void);

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_info_out_status (void);//@}

    //@{
    /** Operations from Components::SessionComponent. */

    virtual void set_session_context (::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    //@{
    /** User defined operations */

    //@}

  private:
    ::Shapes::CCM_Receiver_comp_Context_var ciao_context_;
    ::Shapes::ShapeType_conn::CCM_Listener_var ciao_info_out_data_listener_;
    ::CCM_DDS::CCM_PortStatusListener_var ciao_info_out_status_;
  };

  extern "C" SHAPES_RECEIVER_COMP_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Shapes_Receiver_comp_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
