// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.2
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
#ifndef CIAO_TL_RESETTOPIC_SENDER_EXEC_YSJ9S8_H_
#define CIAO_TL_RESETTOPIC_SENDER_EXEC_YSJ9S8_H_

#include /**/ "ace/pre.h"

#include "TL_ResetTopic_SenderEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Sender_exec_export.h"
#include "tao/LocalObject.h"

#include <map>

namespace CIAO_TL_ResetTopic_Sender_Impl
{
  class Sender_exec_i;

  /**
   * Timeout_Handler
   */
  class Timeout_Handler :
    public ACE_Event_Handler
  {
  public:
    Timeout_Handler (Sender_exec_i &callback);
    /// Handle the timeout.
    virtual int handle_timeout (const ACE_Time_Value &tv,
                                const void *arg);
  private:
    /// Maintains a handle that actually process the event
    Sender_exec_i &callback_;
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
    virtual void set_new_topic (const char * topic_name);
    //@}

    //@{
    /** Component attributes and port operations. */

    virtual ::CORBA::UShort iterations (void);

    virtual void iterations (::CORBA::UShort iterations);

    virtual ::CORBA::UShort keys (void);

    virtual void keys (::CORBA::UShort keys);
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
    bool set_topic_name (const char * topic_name);
    bool set_topic_name_writer (const char * topic_name);
    bool set_topic_name_updater (const char * topic_name);
    void start_event_test (void);
    //@}

  private:
    ::TL_ResetTopic::CCM_Sender_Context_var ciao_context_;

    //@{
    /** Component attributes. */

    ::CORBA::UShort iterations_;

    ::CORBA::UShort keys_;
    //@}

    //@{
    /** User defined members. */
    Timeout_Handler *to_handler_;
    ACE_CString topic_name_, old_topic_name_;

    TAO_SYNCH_RECURSIVE_MUTEX topic_name_lock_;

    typedef std::map<ACE_CString, TL_ResetTopicTest_var> Sample_Table;

    Sample_Table tests_;
    //@}

    //@{
    /** User defined private operations. */
    void create_samples (void);
    //@}

    /// Get the ACE_Reactor
    ACE_Reactor* reactor (void);
  };

  extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_TL_ResetTopic_Sender_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
