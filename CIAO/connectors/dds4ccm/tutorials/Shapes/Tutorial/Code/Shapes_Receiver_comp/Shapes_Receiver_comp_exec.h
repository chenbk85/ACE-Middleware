// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.2.3
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
#ifndef CIAO__________TUTORIAL_CODE_SHAPES_RECEIVER_COMP_SHAPES_RECEIVER_COMP_EXEC_FFZ1QM_H_
#define CIAO__________TUTORIAL_CODE_SHAPES_RECEIVER_COMP_SHAPES_RECEIVER_COMP_EXEC_FFZ1QM_H_

#include /**/ "ace/pre.h"

#include "Shapes_Receiver_compEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Shapes_Receiver_comp_exec_export.h"
#include "tao/LocalObject.h"

/// Namespace for implementation of Shapes::Receiver_comp component
namespace CIAO_Shapes_Receiver_comp_Impl
{

  ///  Executor implementation class for info_out_data_listener facet
  class info_out_data_listener_exec_i
    : public virtual ::Shapes::ShapeType_conn::CCM_Listener,
      public virtual ::CORBA::LocalObject
  {
  public:
    /// Constructor
    /// @param[in] ctx - Container context
    info_out_data_listener_exec_i (
      ::Shapes::CCM_Receiver_comp_Context_ptr ctx);
    /// Destructor
    virtual ~info_out_data_listener_exec_i (void);

    /** @name Operations and attributes from Shapes::ShapeType_conn::Listener */
    //@{

    virtual
    void on_one_data (
      const ::ShapeType & datum,
      const ::CCM_DDS::ReadInfo & info);

    virtual
    void on_many_data (
      const ::ShapeTypeSeq & data,
      const ::CCM_DDS::ReadInfoSeq & infos);
    //@}

  private:
    /// Context for component instance. Used for all middleware communication.
    ::Shapes::CCM_Receiver_comp_Context_var ciao_context_;
  };

  ///  Executor implementation class for info_out_status facet
  class info_out_status_exec_i
    : public virtual ::CCM_DDS::CCM_PortStatusListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    /// Constructor
    /// @param[in] ctx - Container context
    info_out_status_exec_i (
      ::Shapes::CCM_Receiver_comp_Context_ptr ctx);
    /// Destructor
    virtual ~info_out_status_exec_i (void);

    /** @name Operations and attributes from CCM_DDS::PortStatusListener */
    //@{

    virtual
    void on_requested_deadline_missed (
      ::DDS::DataReader_ptr the_reader,
      const ::DDS::RequestedDeadlineMissedStatus & status);

    virtual
    void on_sample_lost (
      ::DDS::DataReader_ptr the_reader,
      const ::DDS::SampleLostStatus & status);
    //@}

  private:
    /// Context for component instance. Used for all middleware communication.
    ::Shapes::CCM_Receiver_comp_Context_var ciao_context_;
  };

  /// Component Executor Implementation Class: Receiver_comp_exec_i
  class Receiver_comp_exec_i
    : public virtual Receiver_comp_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    /// Constructor
    Receiver_comp_exec_i (void);
    /// Destructor
    virtual ~Receiver_comp_exec_i (void);

    /** @name Supported operations and attributes. */
    //@{

    //@}

    /** @name Component attributes and port operations. */
    //@{

    /// Factory method and getter for info_out_data_listener facet
    /// @return existing instance of facet if one exists, else creates one
    virtual ::Shapes::ShapeType_conn::CCM_Listener_ptr
    get_info_out_data_listener (void);

    /// Factory method and getter for info_out_status facet
    /// @return existing instance of facet if one exists, else creates one
    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_info_out_status (void);
    //@}

    /** @name Session component operations */
    //@{

    /// Setter for container context for this component
    /// @param[in] ctx - Container context
    virtual void set_session_context (::Components::SessionContext_ptr ctx);

    /// Component state change method to configuration_complete state
    virtual void configuration_complete (void);

    /// Component state change method to activated state
    virtual void ccm_activate (void);

    /// Component state change method to passivated state
    virtual void ccm_passivate (void);

    /// Component state change method to removed state
    virtual void ccm_remove (void);
    //@}

    /** @name User defined public operations. */
    //@{

    //@}

  private:
    /// Context for component instance. Used for all middleware communication
    ::Shapes::CCM_Receiver_comp_Context_var ciao_context_;

    /** @name Component attributes. */
    //@{
    //@}

    /** @name Component facets. */
    //@{

    /// Object reference to info_out_data_listener facet
    ::Shapes::ShapeType_conn::CCM_Listener_var ciao_info_out_data_listener_;

    /// Object reference to info_out_status facet
    ::CCM_DDS::CCM_PortStatusListener_var ciao_info_out_status_;
    //@}

    /** @name User defined members. */
    //@{

    //@}

    /** @name User defined private operations. */
    //@{

    //@}
  };

  /// Factory method and library entry point used by the middleware
  /// @return new component instance
  extern "C" SHAPES_RECEIVER_COMP_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Shapes_Receiver_comp_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
