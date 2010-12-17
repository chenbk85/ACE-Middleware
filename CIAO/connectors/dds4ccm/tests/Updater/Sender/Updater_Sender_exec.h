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
#ifndef CIAO_UPDATER_SENDER_EXEC_QTARYT_H_
#define CIAO_UPDATER_SENDER_EXEC_QTARYT_H_

#include /**/ "ace/pre.h"

#include "Updater_SenderEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Sender_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_Updater_Sender_Impl
{
  typedef ACE_Atomic_Op <TAO_SYNCH_MUTEX, CORBA::Boolean > Atomic_Boolean;

  class Sender_exec_i;

  enum UPDATER_TEST {
    UPDATE_CREATE,
    UPDATE_CREATE_ALREADY_EXIST,
    UPDATE_ONE,
    UPDATE_ONE_NOT_REGISTERED,
    DELETE_ONE,
    DELETE_ONE_NOT_REGISTERED,
    UPDATE_DELETE_REGISTER,
    CREATE_MANY,
    UPDATE_MANY,
    DELETE_MANY,
    END_TEST
  };

  /**
   * Pulse generator
   */

  class pulse_Generator :
    public ACE_Event_Handler
  {
  public:
    pulse_Generator (Sender_exec_i &callback);
    virtual int handle_timeout (const ACE_Time_Value &tv,
                                const void *arg);
  private:
    Sender_exec_i &pulse_callback_;
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
    void tick (void);

    //@}

  private:
    ::Updater::CCM_Sender_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    //@}

    //@{
    /** User defined members. */
    pulse_Generator * ticker_;

    UPDATER_TEST test_nr_;
    Atomic_Boolean test_ok_;
    TestTopicSeq topic_seq_one_;
    TestTopicSeq topic_seq_many_;

    //@}

    //@{
    /** User defined private operations. */
    void start (void);
    void stop (void);
    void add_instances_of_topic (void);

    CORBA::Boolean create_one (
      ::Updater::UpdaterConnector::Updater_ptr updater);
    CORBA::Boolean create_one_already_exist (
      ::Updater::UpdaterConnector::Updater_ptr updater);
    CORBA::Boolean update_one (
      ::Updater::UpdaterConnector::Updater_ptr updater);
    CORBA::Boolean update_one_not_registered (
      ::Updater::UpdaterConnector::Updater_ptr updater);
    CORBA::Boolean delete_one (
      ::Updater::UpdaterConnector::Updater_ptr updater);
    CORBA::Boolean delete_one_not_registered (
      ::Updater::UpdaterConnector::Updater_ptr updater);
    CORBA::Boolean update_and_delete_one_after_register (
      ::Updater::UpdaterConnector::Updater_ptr updater);
    CORBA::Boolean create_many (
      ::Updater::UpdaterConnector::Updater_ptr updater);
    CORBA::Boolean update_many (
      ::Updater::UpdaterConnector::Updater_ptr updater);
    CORBA::Boolean delete_many (
      ::Updater::UpdaterConnector::Updater_ptr updater);
    //@}

    /// Get the ACE_Reactor
    ACE_Reactor* reactor (void);
  };

  extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Updater_Sender_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
