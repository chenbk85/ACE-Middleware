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
#ifndef CIAO_DELREPLYH_RECEIVER_EXEC_FMXHV6_H_
#define CIAO_DELREPLYH_RECEIVER_EXEC_FMXHV6_H_


#include "DelReplyH_ReceiverEC.h"
#include "DelReplyH_Receiver_exec_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"

namespace CIAO_DelReplyH_Receiver_Impl
{

  /**
   * Provider Executor Implementation Class: do_my_foo_exec_i
   */

  class do_my_foo_exec_i
    : public virtual ::DelReplyH::CCM_MyFoo,
      public virtual ::CORBA::LocalObject
  {
  public:
    do_my_foo_exec_i (
      ::DelReplyH::CCM_Receiver_Context_ptr ctx);
    virtual ~do_my_foo_exec_i (void);

    //@{
    /** Operations and attributes from DelReplyH::MyFoo. */

    virtual
    ::CORBA::Long foo (const char * in_str,
    ::CORBA::String_out answer);
    //@}

  private:
    ::DelReplyH::CCM_Receiver_Context_var ciao_context_;
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

    virtual ::DelReplyH::CCM_MyFoo_ptr
    get_do_my_foo (void);
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
    ::DelReplyH::CCM_Receiver_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    ::DelReplyH::CCM_MyFoo_var ciao_do_my_foo_;
    //@}

    //@{
    /** User defined members. */

    //@}

    //@{
    /** User defined private operations. */

    //@}
  };

  extern "C"  DELREPLYH_RECEIVER_EXEC_Export::Components::EnterpriseComponent_ptr
  create_DelReplyH_Receiver_Impl (void);
}

#endif /* ifndef */
