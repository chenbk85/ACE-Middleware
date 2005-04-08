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

#include "LongLongSeqC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/Sequence_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:31



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:925


#ifndef _TAO_TYPECODE_CORBA_LongLongSeq_GUARD
#define _TAO_TYPECODE_CORBA_LongLongSeq_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence<::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      CORBA_LongLongSeq_0 (
        CORBA::tk_sequence,
        &CORBA::_tc_longlong,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_CORBA_LongLongSeq_0 =
      &CORBA_LongLongSeq_0;
    
  }
}


#endif /* _TAO_TYPECODE_CORBA_LongLongSeq_GUARD */
static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            CORBA::tk_alias,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_LongLongSeq (
    "IDL:omg.org/CORBA/LongLongSeq:1.0",
    "LongLongSeq",
    &TAO::TypeCode::tc_CORBA_LongLongSeq_0);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_LongLongSeq =
    &_tao_tc_CORBA_LongLongSeq;
}



// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::LongLongSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::LongLongSeq>::insert_copy (
      _tao_any,
      CORBA::LongLongSeq::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_LongLongSeq_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::LongLongSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::LongLongSeq>::insert (
      _tao_any,
      CORBA::LongLongSeq::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_LongLongSeq_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::LongLongSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::LongLongSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::LongLongSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::LongLongSeq>::extract (
        _tao_any,
        CORBA::LongLongSeq::_tao_any_destructor,
        TAO::TypeCode::tc_CORBA_LongLongSeq_0,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::LongLongSeq
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::LongLongSeq \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
