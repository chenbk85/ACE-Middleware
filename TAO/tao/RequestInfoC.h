// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
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
// .\be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_REQUESTINFOC_H_
#define _TAO_IDL_ORIG_REQUESTINFOC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Any.h"
#include "tao/Objref_VarOut_T.h"

#include "tao/PI_ForwardC.h"
#include "tao/DynamicC.h"
#include "tao/Messaging_SyncScopeC.h"
#include "tao/InvalidSlotC.h"
#include "tao/IOP_IORC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:48

namespace PortableInterceptor
{
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:598

#if !defined (_PORTABLEINTERCEPTOR_REQUESTINFO__VAR_OUT_CH_)
#define _PORTABLEINTERCEPTOR_REQUESTINFO__VAR_OUT_CH_
  
  class RequestInfo;
  typedef RequestInfo *RequestInfo_ptr;
  
  typedef
    TAO_Objref_Var_T<
        RequestInfo
      >
    RequestInfo_var;
  
  typedef
    TAO_Objref_Out_T<
        RequestInfo
      >
    RequestInfo_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLEINTERCEPTOR_REQUESTINFO_CH_)
#define _PORTABLEINTERCEPTOR_REQUESTINFO_CH_
  
  class TAO_Export RequestInfo
    : public virtual CORBA::Object
  {
  public:
    typedef RequestInfo_ptr _ptr_type;
    typedef RequestInfo_var _var_type;
    
    // The static operations.
    static RequestInfo_ptr _duplicate (RequestInfo_ptr obj);
    
    static void _tao_release (RequestInfo_ptr obj);
    
    static RequestInfo_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static RequestInfo_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static RequestInfo_ptr _nil (void)
    {
      return static_cast<RequestInfo_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual CORBA::ULong request_id (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual char * operation (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::Dynamic::ParameterList * arguments (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::Dynamic::ExceptionList * exceptions (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::Dynamic::ContextList * contexts (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::Dynamic::RequestContext * operation_context (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual CORBA::Any * result (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual CORBA::Boolean response_expected (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual Messaging::SyncScope sync_scope (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual PortableInterceptor::ReplyStatus reply_status (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual CORBA::Object_ptr forward_reference (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual CORBA::Any * get_slot (
        ::PortableInterceptor::SlotId id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableInterceptor::InvalidSlot
      )) = 0;
    
    // TAO_IDL - Generated from
    // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::IOP::ServiceContext * get_request_service_context (
        ::IOP::ServiceId id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::IOP::ServiceContext * get_reply_service_context (
        ::IOP::ServiceId id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:210
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    RequestInfo (void);
    
    virtual ~RequestInfo (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    RequestInfo (const RequestInfo &);
    
    void operator= (const RequestInfo &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_Export ::CORBA::TypeCode_ptr const _tc_RequestInfo;

// TAO_IDL - Generated from
// c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:66

} // module PortableInterceptor

// TAO_IDL - Generated from
// .\be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLEINTERCEPTOR_REQUESTINFO__TRAITS_CH_)
#define _PORTABLEINTERCEPTOR_REQUESTINFO__TRAITS_CH_
  
  template<>
  struct TAO_Export Objref_Traits< ::PortableInterceptor::RequestInfo>
  {
    static ::PortableInterceptor::RequestInfo_ptr duplicate (
        ::PortableInterceptor::RequestInfo_ptr
      );
    static void release (
        ::PortableInterceptor::RequestInfo_ptr
      );
    static ::PortableInterceptor::RequestInfo_ptr nil (void);
    static CORBA::Boolean marshal (
        ::PortableInterceptor::RequestInfo_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// c:\ace\latest\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::RequestInfo_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::RequestInfo_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::RequestInfo_ptr &);

// TAO_IDL - Generated from
// .\be\be_codegen.cpp:955

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


