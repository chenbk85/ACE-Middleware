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

#include "tao/AnyTypeCode/LongSeqA.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Sequence_TypeCode_Static.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937


#ifndef _TAO_TYPECODE_CORBA_LongSeq_GUARD
#define _TAO_TYPECODE_CORBA_LongSeq_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      CORBA_LongSeq_0 (
        CORBA::tk_sequence,
        &CORBA::_tc_long,
        0U);

    ::CORBA::TypeCode_ptr const tc_CORBA_LongSeq_0 =
      &CORBA_LongSeq_0;

  }
}


#endif /* _TAO_TYPECODE_CORBA_LongSeq_GUARD */

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_LongSeq (
    CORBA::tk_alias,
    "IDL:omg.org/CORBA/LongSeq:1.0",
    "LongSeq",
    &TAO::TypeCode::tc_CORBA_LongSeq_0);

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_LongSeq =
    &_tao_tc_CORBA_LongSeq;
}



// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_cs.cpp:54


// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::LongSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::LongSeq>::insert_copy (
      _tao_any,
      CORBA::LongSeq::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_LongSeq_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::LongSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::LongSeq>::insert (
      _tao_any,
      CORBA::LongSeq::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_LongSeq_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::LongSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::LongSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::LongSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::LongSeq>::extract (
        _tao_any,
        CORBA::LongSeq::_tao_any_destructor,
        TAO::TypeCode::tc_CORBA_LongSeq_0,
        _tao_elem
      );
}

TAO_END_VERSIONED_NAMESPACE_DECL
