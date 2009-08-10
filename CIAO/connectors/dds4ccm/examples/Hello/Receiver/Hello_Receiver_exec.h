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
// be/be_codegen.cpp:1217

#ifndef CIAO_HELLO_RECEIVER_EXEC_H_
#define CIAO_HELLO_RECEIVER_EXEC_H_

#include /**/ "ace/pre.h"

#include "Hello_ReceiverEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Hello_Receiver_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_Hello_DDS_Receiver_Impl
{
  typedef ACE_Atomic_Op <TAO_SYNCH_MUTEX, CORBA::ULong > Atomic_ULong;

  class HELLO_RECEIVER_EXEC_Export string_RawListener_exec_i
    : public virtual ::CCM_DDS::CCM_string_RawListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    string_RawListener_exec_i (Atomic_ULong &,
                               const ACE_CString &);
    virtual ~string_RawListener_exec_i (void);

  // Operations and attributes from ::CCM_DDS::string_RawListener

  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46

  virtual void
  on_data (const char * an_instance,
           const ::CCM_DDS::ReadInfo & info);

private:
  Atomic_ULong &received_;
  const ACE_CString &name_;
};

class HELLO_RECEIVER_EXEC_Export PortStatusListener_exec_i
  : public virtual ::CCM_DDS::CCM_PortStatusListener,
    public virtual ::CORBA::LocalObject
{
 public:
  PortStatusListener_exec_i (Atomic_ULong &);
  virtual ~PortStatusListener_exec_i (void);

  // Operations and attributes from ::CCM_DDS::PortStatusListener

  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46

  virtual void
    on_requested_deadline_missed (::DDS::DataReader_ptr the_reader,
                                  const ::DDS::RequestedDeadlineMissedStatus & status);

  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46

  virtual void
    on_sample_lost (::DDS::DataReader_ptr the_reader,
                    const ::DDS::SampleLostStatus & status);
 private:
  Atomic_ULong &lost_;
};

class HELLO_RECEIVER_EXEC_Export Receiver_exec_i
  : public virtual Receiver_Exec,
    public virtual ::CORBA::LocalObject
{
 public:
  Receiver_exec_i (void);
  virtual ~Receiver_exec_i (void);

  // Supported operations and attributes.

  // Component attributes.
  virtual ::CORBA::ULong expected_samples (void);

  virtual void expected_samples (::CORBA::ULong expected_samples);

  virtual char * name (void);

  virtual void name (const char *name);

  // Port operations.

  virtual ::CCM_DDS::CCM_string_RawListener_ptr
    get_read_message_listener (void);

  virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_read_message_status (void);

  // Operations from Components::SessionComponent.

  virtual void
    set_session_context (
                         ::Components::SessionContext_ptr ctx);

  virtual void configuration_complete (void);

  virtual void ccm_activate (void);
  virtual void ccm_passivate (void);
  virtual void ccm_remove (void);

 private:
  ::Hello_DDS::CCM_Receiver_Context_var context_;
  CORBA::ULong expected_;
  Atomic_ULong received_;
  Atomic_ULong lost_;
  ACE_CString name_;
};

extern "C" HELLO_RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
create_Hello_DDS_Receiver_Impl (void);
}

namespace CIAO_Hello_DDS_Receiver_Impl
{
  class HELLO_RECEIVER_EXEC_Export ReceiverHome_exec_i
    : public virtual ReceiverHome_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    ReceiverHome_exec_i (void);

    virtual ~ReceiverHome_exec_i (void);

    // All operations and attributes.

    // Factory operations.

    // Finder operations.

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
      create (void);
  };

  extern "C" HELLO_RECEIVER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Hello_DDS_ReceiverHome_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */

