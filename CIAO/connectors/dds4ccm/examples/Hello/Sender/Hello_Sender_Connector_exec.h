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

#ifndef CIAO_HELLO_SENDER_CONNECTOR_EXEC_H_
#define CIAO_HELLO_SENDER_CONNECTOR_EXEC_H_

#include /**/ "ace/pre.h"

#include "Hello_Sender_ConnectorEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Hello_Sender_Connector_exec_export.h"
#include "tao/LocalObject.h"

#include "dds4ccm/impl/ndds/DataWriter.h"
#include "dds4ccm/impl/ndds/Builtin_Writer.h"
#include "dds4ccm/impl/ndds/NDDS_Traits.h"

namespace CIAO_Hello_DDS_Hello_sender_Connector_Impl
{
  typedef CIAO::DDS4CCM::RTI::Builtin_Writer_T< CIAO::DDS4CCM::RTI::String_Traits, ::CCM_DDS::CCM_string_Writer > String_Writer;

  class HELLO_SENDER_CONNECTOR_EXEC_Export string_Writer_exec_i
    : public virtual ::CCM_DDS::CCM_string_Writer,
      public virtual ::CORBA::LocalObject
  {
  public:
    string_Writer_exec_i (String_Writer* wr);
    virtual ~string_Writer_exec_i (void);

    // Operations and attributes from ::CCM_DDS::string_Writer

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void write (const char * an_instance);

  private:
    String_Writer* writer_;
  };

  /*
  class HELLO_SENDER_CONNECTOR_EXEC_Export DDSWriter_i :
    public virtual CIAO::DDS4CCM::RTI::RTI_DataWriter_i,
    public virtual ::CORBA::LocalObject
  {
    DDSWriter_i (CIAO::DDS4CCM::RTI::RTI_DataWriter_i rti_dw)
      : CIAO::DDS4CCM::RTI::RTI_DataWriter_i (rti_dw)
      {
      }
  };
  */

  class HELLO_SENDER_CONNECTOR_EXEC_Export Hello_sender_Connector_exec_i
    : public virtual Hello_sender_Connector_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Hello_sender_Connector_exec_i (void);
    virtual ~Hello_sender_Connector_exec_i (void);

    // Supported operations and attributes.

    // Component attributes.

    // Port operations.

    virtual ::CCM_DDS::CCM_string_Writer_ptr
    get_sender_data (void);

    virtual ::DDS::CCM_DataWriter_ptr
    get_sender_dds_entity (void);

    // Operations from Components::SessionComponent.

    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);

  private:
    void configure_dds (void);

    ::Hello_DDS::CCM_Hello_sender_Connector_Context_var context_;

    bool dds_configured_;
    ::DDS::DomainParticipantFactory_var dpf_;
    ::DDS::DomainParticipant_var dp_;
    ::DDS::Topic_var t_;
    ::DDS::Publisher_var pub_;
    ::DDS::CCM_DataWriter_var dw_;
    ::CCM_DDS::CCM_string_Writer_var sw_;
  };

  extern "C" HELLO_SENDER_CONNECTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Hello_DDS_Hello_sender_Connector_Impl (void);
}

namespace CIAO_Hello_DDS_Hello_sender_Connector_Impl
{
  class HELLO_SENDER_CONNECTOR_EXEC_Export SenderConnectorHome_exec_i
    : public virtual SenderConnectorHome_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    SenderConnectorHome_exec_i (void);

    virtual ~SenderConnectorHome_exec_i (void);

    // All operations and attributes.

    // Factory operations.

    // Finder operations.

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
    create (void);
  };

  extern "C" HELLO_SENDER_CONNECTOR_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Hello_DDS_SenderConnectorHome_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */

