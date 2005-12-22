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
// be/be_codegen.cpp:164

#ifndef _TAO_IDL_ORIG_PROCESSINGMODEPOLICYC_H_
#define _TAO_IDL_ORIG_PROCESSINGMODEPOLICYC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PI/pi_export.h"
#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/AnyTypeCode/PolicyA.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Versioned_Namespace.h"

#include "tao/PolicyC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PI_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:49

namespace PortableInterceptor
{
  
  // TAO_IDL - Generated from
  // be/be_visitor_typedef/typedef_ch.cpp:379
  
  typedef CORBA::Short ProcessingMode;
  typedef CORBA::Short_out ProcessingMode_out;
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_PI_Export ::CORBA::TypeCode_ptr const _tc_ProcessingMode;
  
  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52
  
  const PortableInterceptor::ProcessingMode LOCAL_AND_REMOTE = 0;
  
  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52
  
  const PortableInterceptor::ProcessingMode REMOTE_ONLY = 1;
  
  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52
  
  const PortableInterceptor::ProcessingMode LOCAL_ONLY = 2;
  
  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::PolicyType PROCESSING_MODE_POLICY_TYPE = 100U;
  
  // TAO_IDL - Generated from
  // be/be_interface.cpp:646

#if !defined (_PORTABLEINTERCEPTOR_PROCESSINGMODEPOLICY__VAR_OUT_CH_)
#define _PORTABLEINTERCEPTOR_PROCESSINGMODEPOLICY__VAR_OUT_CH_
  
  class ProcessingModePolicy;
  typedef ProcessingModePolicy *ProcessingModePolicy_ptr;
  
  typedef
    TAO_Objref_Var_T<
        ProcessingModePolicy
      >
    ProcessingModePolicy_var;
  
  typedef
    TAO_Objref_Out_T<
        ProcessingModePolicy
      >
    ProcessingModePolicy_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLEINTERCEPTOR_PROCESSINGMODEPOLICY_CH_)
#define _PORTABLEINTERCEPTOR_PROCESSINGMODEPOLICY_CH_
  
  class TAO_PI_Export ProcessingModePolicy
    : public virtual ::CORBA::Policy
  {
  public:
    typedef ProcessingModePolicy_ptr _ptr_type;
    typedef ProcessingModePolicy_var _var_type;
    
    // The static operations.
    static ProcessingModePolicy_ptr _duplicate (ProcessingModePolicy_ptr obj);
    
    static void _tao_release (ProcessingModePolicy_ptr obj);
    
    static ProcessingModePolicy_ptr _narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ProcessingModePolicy_ptr _unchecked_narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ProcessingModePolicy_ptr _nil (void)
    {
      return static_cast<ProcessingModePolicy_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::PortableInterceptor::ProcessingMode processing_mode (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Policy_ptr copy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void destroy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:210
    
    virtual ::CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    ProcessingModePolicy (void);
    
    virtual ~ProcessingModePolicy (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ProcessingModePolicy (const ProcessingModePolicy &);
    
    void operator= (const ProcessingModePolicy &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:49
  
  extern TAO_PI_Export ::CORBA::TypeCode_ptr const _tc_ProcessingModePolicy;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:78

} // module PortableInterceptor

// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:62

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLEINTERCEPTOR_PROCESSINGMODEPOLICY__TRAITS_)
#define _PORTABLEINTERCEPTOR_PROCESSINGMODEPOLICY__TRAITS_
  
  template<>
  struct TAO_PI_Export Objref_Traits< ::PortableInterceptor::ProcessingModePolicy>
  {
    static ::PortableInterceptor::ProcessingModePolicy_ptr duplicate (
        ::PortableInterceptor::ProcessingModePolicy_ptr
      );
    static void release (
        ::PortableInterceptor::ProcessingModePolicy_ptr
      );
    static ::PortableInterceptor::ProcessingModePolicy_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::PortableInterceptor::ProcessingModePolicy_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be/be_codegen.cpp:1101

TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */


