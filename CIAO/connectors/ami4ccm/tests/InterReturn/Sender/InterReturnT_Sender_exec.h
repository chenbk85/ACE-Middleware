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
#ifndef CIAO_INTERRETURNT_SENDER_EXEC_1UOEW8_H_
#define CIAO_INTERRETURNT_SENDER_EXEC_1UOEW8_H_

#include /**/ "ace/pre.h"

#include "InterReturnT_SenderEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "InterReturnT_Sender_exec_export.h"
#include "tao/LocalObject.h"
#include "ace/Task.h"

namespace CIAO_InterReturnT_Sender_Impl
{
  typedef ACE_Atomic_Op <TAO_SYNCH_MUTEX, CORBA::UShort > Atomic_UShort;

  /// Worker thread for asynchronous invocations
  class asynch_foo_generator : public virtual ACE_Task_Base
  {
  public:
    asynch_foo_generator (::InterReturnT::CCM_Sender_Context_ptr context,
        Atomic_UShort &nr_of_received);

    virtual int svc (void);

  private:
    ::InterReturnT::CCM_Sender_Context_var context_;
    Atomic_UShort &nr_of_received_;
  };

  /// Worker thread for synchronous invocations
  class synch_foo_generator : public virtual ACE_Task_Base
  {
  public:
    synch_foo_generator (::InterReturnT::CCM_Sender_Context_ptr context,
        Atomic_UShort &nr_of_received);

    virtual int svc (void);

  private:
    ::InterReturnT::CCM_Sender_Context_var context_;
    Atomic_UShort &nr_of_received_;
  };

  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  class Sender_exec_i
    : public virtual Sender_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Sender_exec_i (void);
    virtual ~Sender_exec_i (void);

    //@{
    /** Supported operations and attributes. */
    //@}

    //@{
    /** Component attributes and port operations. */
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
    ::InterReturnT::CCM_Sender_Context_var ciao_context_;
    asynch_foo_generator* asynch_foo_gen;
    synch_foo_generator* synch_foo_gen;
    //@{
    /** Component attributes. */
    //@}

    //@{
    /** User defined members. */
    Atomic_UShort nr_of_received_;
    //@}

    //@{
    /** User defined private operations. */
    //@}
  };

  extern "C" INTERRETURN_T_SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_InterReturnT_Sender_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
