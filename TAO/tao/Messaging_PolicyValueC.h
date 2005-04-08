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

#ifndef _TAO_IDL_ORIG_MESSAGING_POLICYVALUEC_H_
#define _TAO_IDL_ORIG_MESSAGING_POLICYVALUEC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/Sequence_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"

#include "tao/IOP_IORC.h"
#include "tao/Policy_ForwardC.h"

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
// be\be_visitor_module/module_ch.cpp:48

namespace Messaging
{
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:258
  
  struct PolicyValue;
  
  typedef
    TAO_Var_Var_T<
        PolicyValue
      >
    PolicyValue_var;
  
  typedef
    TAO_Out_T<
        PolicyValue,
        PolicyValue_var
      >
    PolicyValue_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:52
  
  struct TAO_Export PolicyValue
  {
    typedef PolicyValue_var _var_type;
    
    static void _tao_any_destructor (void *);
    CORBA::PolicyType ptype;
    CORBA::OctetSeq pvalue;
  };
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_Export ::CORBA::TypeCode_ptr const _tc_PolicyValue;
  
  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_MESSAGING_POLICYVALUESEQ_CH_)
#define _MESSAGING_POLICYVALUESEQ_CH_
  
  class PolicyValueSeq;
  
  typedef
    TAO_VarSeq_Var_T<
        PolicyValueSeq,
        PolicyValue
      >
    PolicyValueSeq_var;
  
  typedef
    TAO_Seq_Out_T<
        PolicyValueSeq,
        PolicyValueSeq_var,
        PolicyValue
      >
    PolicyValueSeq_out;
  
  class TAO_Export PolicyValueSeq
    : public
        TAO_Unbounded_Sequence<
            PolicyValue
          >
  {
  public:
    PolicyValueSeq (void);
    PolicyValueSeq (CORBA::ULong max);
    PolicyValueSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        PolicyValue* buffer, 
        CORBA::Boolean release = 0
      );
    PolicyValueSeq (const PolicyValueSeq &);
    ~PolicyValueSeq (void);
    
    static void _tao_any_destructor (void *);
    
    typedef PolicyValueSeq_var _var_type;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_Export ::CORBA::TypeCode_ptr const _tc_PolicyValueSeq;
  
  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52
  
  const IOP::ComponentId TAG_POLICIES = 2U;
  
  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52
  
  const IOP::ServiceId INVOCATION_POLICIES = 2U;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module Messaging

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const Messaging::PolicyValue &); // copying version
TAO_Export void operator<<= (CORBA::Any &, Messaging::PolicyValue*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, Messaging::PolicyValue *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const Messaging::PolicyValue *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const Messaging::PolicyValueSeq &); // copying version
TAO_Export void operator<<= (CORBA::Any &, Messaging::PolicyValueSeq*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, Messaging::PolicyValueSeq *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const Messaging::PolicyValueSeq *&);

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const Messaging::PolicyValue &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, Messaging::PolicyValue &);

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_Messaging_PolicyValueSeq_H_
#define _TAO_CDR_OP_Messaging_PolicyValueSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const Messaging::PolicyValueSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    Messaging::PolicyValueSeq &
  );

#endif /* _TAO_CDR_OP_Messaging_PolicyValueSeq_H_ */

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


