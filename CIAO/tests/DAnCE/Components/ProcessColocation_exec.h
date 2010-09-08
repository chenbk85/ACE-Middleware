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
// be/be_codegen.cpp:1301

#ifndef CIAO_PROCESSCOLOCATION_EXEC_H_
#define CIAO_PROCESSCOLOCATION_EXEC_H_

#include /**/ "ace/pre.h"

#include "ProcessColocationEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "ProcessColocation_exec_export.h"
#include "tao/LocalObject.h"
#include "ace/String_Base.h"

namespace CIAO_Simple_ProcessColocation_Impl
{
  class PROCESSCOLOCATION_EXEC_Export ProcessColocation_exec_i
    : public virtual ProcessColocation_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    ProcessColocation_exec_i (void);
    virtual ~ProcessColocation_exec_i (void);
    
    // Supported operations and attributes.
    
    // Component attributes.
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual char *
    process_name (void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    process_name (
      const char * process_name);
    
    // Port operations.
    
    // Operations from Components::SessionComponent.
    
    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);
    
    virtual void configuration_complete (void);
    
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
  
  private:
    ACE_CString process_name_;
    ::Simple::CCM_ProcessColocation_Context_var context_;
  };
  
  extern "C" PROCESSCOLOCATION_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Simple_ProcessColocation_Impl (void);
}

namespace CIAO_Simple_ProcessColocation_Impl
{
  class PROCESSCOLOCATION_EXEC_Export ProcessColocationHome_exec_i
    : public virtual ProcessColocationHome_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    ProcessColocationHome_exec_i (void);
    
    virtual ~ProcessColocationHome_exec_i (void);
    
    // All operations and attributes.
    
    // Factory operations.
    
    // Finder operations.
    
    // Implicit operations.
    
    virtual ::Components::EnterpriseComponent_ptr
    create (void);
  };
  
  extern "C" PROCESSCOLOCATION_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Simple_ProcessColocationHome_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */

