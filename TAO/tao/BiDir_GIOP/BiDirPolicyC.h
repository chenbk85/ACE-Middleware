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
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_BIDIRPOLICYC_H_
#define _TAO_IDL_ORIG_BIDIRPOLICYC_H_

#include /**/ "ace/pre.h"

#ifndef TAO_BIDIRGIOP_SAFE_INCLUDE
#error "You should not include BiDirPolicyC.h directly, use BiDirGIOP.h"
#endif /* !TAO_BIDIRGIOP_SAFE_INCLUDE */

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "bidirgiop_export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"

#include "tao/PolicyC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_BiDirGIOP_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace BiDirPolicy
{
  
  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef CORBA::UShort BidirectionalPolicyValue;
  typedef CORBA::UShort_out BidirectionalPolicyValue_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52
  
  const BiDirPolicy::BidirectionalPolicyValue NORMAL = 0U;
  
  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52
  
  const BiDirPolicy::BidirectionalPolicyValue BOTH = 1U;
  
  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::PolicyType BIDIRECTIONAL_POLICY_TYPE = 37U;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_BIDIRPOLICY_BIDIRECTIONALPOLICY__VAR_OUT_CH_)
#define _BIDIRPOLICY_BIDIRECTIONALPOLICY__VAR_OUT_CH_
  
  class BidirectionalPolicy;
  typedef BidirectionalPolicy *BidirectionalPolicy_ptr;
  
  typedef
    TAO_Objref_Var_T<
        BidirectionalPolicy
      >
    BidirectionalPolicy_var;
  
  typedef
    TAO_Objref_Out_T<
        BidirectionalPolicy
      >
    BidirectionalPolicy_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_BIDIRPOLICY_BIDIRECTIONALPOLICY_CH_)
#define _BIDIRPOLICY_BIDIRECTIONALPOLICY_CH_
  
  class TAO_BiDirGIOP_Export BidirectionalPolicy
    : public virtual ::CORBA::Policy
  {
  public:
    typedef BidirectionalPolicy_ptr _ptr_type;
    typedef BidirectionalPolicy_var _var_type;
    
    // The static operations.
    static BidirectionalPolicy_ptr _duplicate (BidirectionalPolicy_ptr obj);
    
    static void _tao_release (BidirectionalPolicy_ptr obj);
    
    static BidirectionalPolicy_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static BidirectionalPolicy_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static BidirectionalPolicy_ptr _nil (void)
    {
      return static_cast<BidirectionalPolicy_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual BiDirPolicy::BidirectionalPolicyValue value (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Policy_ptr copy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void destroy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    BidirectionalPolicy (void);
    
    virtual ~BidirectionalPolicy (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    BidirectionalPolicy (const BidirectionalPolicy &);
    
    void operator= (const BidirectionalPolicy &);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module BiDirPolicy

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{

#if !defined (_BIDIRPOLICY_BIDIRECTIONALPOLICY__TRAITS_CH_)
#define _BIDIRPOLICY_BIDIRECTIONALPOLICY__TRAITS_CH_
  
  template<>
  struct TAO_BiDirGIOP_Export Objref_Traits< ::BiDirPolicy::BidirectionalPolicy>
  {
    static ::BiDirPolicy::BidirectionalPolicy_ptr duplicate (
        ::BiDirPolicy::BidirectionalPolicy_ptr
      );
    static void release (
        ::BiDirPolicy::BidirectionalPolicy_ptr
      );
    static ::BiDirPolicy::BidirectionalPolicy_ptr nil (void);
    static CORBA::Boolean marshal (
        ::BiDirPolicy::BidirectionalPolicy_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_codegen.cpp:955

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


