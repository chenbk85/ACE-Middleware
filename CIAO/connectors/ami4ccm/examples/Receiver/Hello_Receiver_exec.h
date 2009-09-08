// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.1 ****
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


#include "Hello_ReceiverEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"
#include "Hello_Receiver_exec_export.h"

namespace CIAO_Hello_AMI_Receiver_Impl
{
  class  MyFoo_exec_i
    : public virtual ::CCM_AMI::CCM_MyFoo,
      public virtual ::CORBA::LocalObject
  {
  public:
    MyFoo_exec_i (void);
    virtual ~MyFoo_exec_i (void);
    
    // Operations and attributes from ::CCM_AMI::MyFoo
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Long
    foo (
      const char * in_str,
      ::CORBA::String_out answer);

    virtual void
    hello (
      CORBA::Long_out answer);
  };
  
  class  MyInterface_exec_i
    : public virtual ::CCM_AMI::CCM_MyInterface,
      public virtual ::CORBA::LocalObject
  {
  public:
    MyInterface_exec_i (void);
    virtual ~MyInterface_exec_i (void);
    
    // Operations and attributes from ::CCM_AMI::MyFoo
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Float
    do_something_with_something (
      CORBA::Short something);
  };
  
  class  Receiver_exec_i
    : public virtual Receiver_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Receiver_exec_i (void);
    virtual ~Receiver_exec_i (void);
    
    // Supported operations and attributes.
    
    // Component attributes.
    
    // Port operations.
    
    virtual ::CCM_AMI::CCM_MyFoo_ptr
    get_do_my_foo (void);
    
    virtual ::CCM_AMI::CCM_MyInterface_ptr
    get_do_my_interface (void);
    
    // Operations from Components::SessionComponent.
    
    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);
    
    virtual void configuration_complete (void);
    
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
  
  private:
    ::Hello_AMI::CCM_Receiver_Context_var context_;
  };
  
  extern "C" HELLO_RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Hello_AMI_Receiver_Impl (void);
}

namespace CIAO_Hello_AMI_Receiver_Impl
{
  class  ReceiverHome_exec_i
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
  create_Hello_AMI_ReceiverHome_Impl (void);
}

#endif /* ifndef */

