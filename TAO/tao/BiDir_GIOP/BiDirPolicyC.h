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
// be/be_codegen.cpp:151

#ifndef _TAO_IDL_ORIG_BIDIRPOLICYC_H_
#define _TAO_IDL_ORIG_BIDIRPOLICYC_H_

#include /**/ "ace/pre.h"

#include "bidirgiop_export.h"

#ifndef TAO_BIDIRGIOP_SAFE_INCLUDE
#error "You should not include BiDirPolicyC.h directly, use BiDirGIOP.h"
#endif /* !TAO_BIDIRGIOP_SAFE_INCLUDE */

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/Sequence_T.h"
#include "tao/PolicyC.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_BiDirGIOP_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_BiDirGIOP_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be/be_visitor_root/root_ch.cpp:63

namespace TAO
{
  class Collocation_Proxy_Broker;
}

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:48

namespace BiDirPolicy
{

  // TAO_IDL - Generated from
  // be/be_visitor_typedef/typedef_ch.cpp:333

  typedef CORBA::UShort BidirectionalPolicyValue;
  typedef CORBA::UShort_out BidirectionalPolicyValue_out;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const BiDirPolicy::BidirectionalPolicyValue NORMAL = 0U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const BiDirPolicy::BidirectionalPolicyValue BOTH = 1U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const CORBA::PolicyType BIDIRECTIONAL_POLICY_TYPE = 37U;

  // TAO_IDL - Generated from
  // be/be_interface.cpp:601

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
  // be/be_visitor_interface/interface_ch.cpp:53

#if !defined (_BIDIRPOLICY_BIDIRECTIONALPOLICY_CH_)
#define _BIDIRPOLICY_BIDIRECTIONALPOLICY_CH_

  class TAO_BiDirGIOP_Export BidirectionalPolicy
    : public virtual CORBA::Policy
  {
  public:
    typedef BidirectionalPolicy_ptr _ptr_type;
    typedef BidirectionalPolicy_var _var_type;

    // The static operations.
    static BidirectionalPolicy_ptr _duplicate (BidirectionalPolicy_ptr obj);

    static BidirectionalPolicy_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static BidirectionalPolicy_ptr _nil (void)
      {
        return (BidirectionalPolicy_ptr)0;
      }



    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual BiDirPolicy::BidirectionalPolicyValue value (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:185

    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);

  protected:
    BidirectionalPolicy (void);
    virtual ~BidirectionalPolicy (void);

  private:
    BidirectionalPolicy (const BidirectionalPolicy &);
    void operator= (const BidirectionalPolicy &);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:66

} // module BiDirPolicy

// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:48

// Traits specializations.
namespace TAO
{
};

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// be/be_codegen.cpp:969

#if defined (__ACE_INLINE__)
#include "BiDirPolicyC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */
