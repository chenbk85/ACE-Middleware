// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.1.1
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
#ifndef CIAO_SHAPES_CONTROL_COMP_EXEC_WWONQX_H_
#define CIAO_SHAPES_CONTROL_COMP_EXEC_WWONQX_H_


#include "Shapes_Control_compEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"

/// Namespace for implementation of Shapes::Control_comp component
namespace CIAO_Shapes_Control_comp_Impl
{

  /// Component Executor Implementation Class: Control_comp_exec_i
  class Control_comp_exec_i
    : public virtual Control_comp_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    /// Constructor
    Control_comp_exec_i (void);
    /// Destructor
    virtual ~Control_comp_exec_i (void);

    /** @name Supported operations and attributes. */
    //@{

    //@}

    /** @name Component attributes and port operations. */
    //@{

    /// Getter for rate attribute
    /// @return value of rate attribute
    virtual ::CORBA::ULong rate (
      void);

    /// Setter for rate attribute
    /// @param[in] rate - New value for rate attribute
    virtual void rate (
      ::CORBA::ULong rate);

    /// Getter for max_x attribute
    /// @return value of max_x attribute
    virtual ::CORBA::UShort max_x (
      void);

    /// Setter for max_x attribute
    /// @param[in] max_x - New value for max_x attribute
    virtual void max_x (
      ::CORBA::UShort max_x);

    /// Getter for max_y attribute
    /// @return value of max_y attribute
    virtual ::CORBA::UShort max_y (
      void);

    /// Setter for max_y attribute
    /// @param[in] max_y - New value for max_y attribute
    virtual void max_y (
      ::CORBA::UShort max_y);

    /// Getter for max_size attribute
    /// @return value of max_size attribute
    virtual ::CORBA::UShort max_size (
      void);

    /// Setter for max_size attribute
    /// @param[in] max_size - New value for max_size attribute
    virtual void max_size (
      ::CORBA::UShort max_size);

    /// Getter for resize_shape attribute
    /// @return value of resize_shape attribute
    virtual ::CORBA::Boolean resize_shape (
      void);

    /// Setter for resize_shape attribute
    /// @param[in] resize_shape - New value for resize_shape attribute
    virtual void resize_shape (
      ::CORBA::Boolean resize_shape);
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
    ::Shapes::CCM_Control_comp_Context_var ciao_context_;

    /** @name Component attributes. */
    //@{

    /// Class member storing value of rate attribute
    ::CORBA::ULong rate_;

    /// Class member storing value of max_x attribute
    ::CORBA::UShort max_x_;

    /// Class member storing value of max_y attribute
    ::CORBA::UShort max_y_;

    /// Class member storing value of max_size attribute
    ::CORBA::UShort max_size_;

    /// Class member storing value of resize_shape attribute
    ::CORBA::Boolean resize_shape_;
    //@}

    /** @name Component facets. */
    //@{
    //@}

    /** @name User defined members. */
    //@{

    //@}

    /** @name User defined private operations. */
    //@{

    //@}

    /// Get the ACE_Reactor
    /// @return non-owning pointer to reactor
    ACE_Reactor* reactor (void);
  };

  /// Factory method and library entry point used by the middleware
  /// @return new component instance
  extern "C"  ::Components::EnterpriseComponent_ptr
  create_Shapes_Control_comp_Impl (void);
}

#endif /* ifndef */
