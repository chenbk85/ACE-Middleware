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
// be/be_codegen.cpp:291


#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Sequence_TypeCode_Static.h"
#include "tao/AnyTypeCode/String_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
#include "tao/Strategies/sciop_endpointsC.h"
#include "tao/CDR.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:69

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:74

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_TAO_SCIOP_Endpoint_Info[] =
  {
    { "host", &CORBA::_tc_string },
    { "port", &CORBA::_tc_short },
    { "priority", &CORBA::_tc_short }

  };
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_TAO_SCIOP_Endpoint_Info (
    CORBA::tk_struct,
    "IDL:TAO_SCIOP_Endpoint_Info:1.0",
    "TAO_SCIOP_Endpoint_Info",
    _tao_fields_TAO_SCIOP_Endpoint_Info,
    3);

::CORBA::TypeCode_ptr const _tc_TAO_SCIOP_Endpoint_Info =
  &_tao_tc_TAO_SCIOP_Endpoint_Info;

// TAO_IDL - Generated from
// be/be_visitor_structure/structure_cs.cpp:66



// TAO_IDL - Generated from
// be/be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_TAO_SCIOPENDPOINTSEQUENCE_CS_)
#define _TAO_SCIOPENDPOINTSEQUENCE_CS_

TAO_SCIOPEndpointSequence::TAO_SCIOPEndpointSequence (void)
{}

TAO_SCIOPEndpointSequence::TAO_SCIOPEndpointSequence (
    CORBA::ULong max
  )
  : TAO::unbounded_value_sequence<
        TAO_SCIOP_Endpoint_Info
      >
    (max)
{}

TAO_SCIOPEndpointSequence::TAO_SCIOPEndpointSequence (
    CORBA::ULong max,
    CORBA::ULong length,
    TAO_SCIOP_Endpoint_Info * buffer,
    CORBA::Boolean release
  )
  : TAO::unbounded_value_sequence<
        TAO_SCIOP_Endpoint_Info
      >
    (max, length, buffer, release)
{}

TAO_SCIOPEndpointSequence::TAO_SCIOPEndpointSequence (
    const TAO_SCIOPEndpointSequence &seq
  )
  : TAO::unbounded_value_sequence<
        TAO_SCIOP_Endpoint_Info
      >
    (seq)
{}

TAO_SCIOPEndpointSequence::~TAO_SCIOPEndpointSequence (void)
{}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_typecode/alias_typecode.cpp:31



// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:925


#ifndef _TAO_TYPECODE_TAO_SCIOPEndpointSequence_GUARD
#define _TAO_TYPECODE_TAO_SCIOPEndpointSequence_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      TAO_SCIOPEndpointSequence_0 (
        CORBA::tk_sequence,
        &_tc_TAO_SCIOP_Endpoint_Info,
        0U);

    ::CORBA::TypeCode_ptr const tc_TAO_SCIOPEndpointSequence_0 =
      &TAO_SCIOPEndpointSequence_0;

  }
}


#endif /* _TAO_TYPECODE_TAO_SCIOPEndpointSequence_GUARD */
static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_TAO_SCIOPEndpointSequence (
    CORBA::tk_alias,
    "IDL:TAO_SCIOPEndpointSequence:1.0",
    "TAO_SCIOPEndpointSequence",
    &TAO::TypeCode::tc_TAO_SCIOPEndpointSequence_0);

::CORBA::TypeCode_ptr const _tc_TAO_SCIOPEndpointSequence =
  &_tao_tc_TAO_SCIOPEndpointSequence;

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO_SCIOP_Endpoint_Info &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.host.in ()) &&
    (strm << _tao_aggregate.port) &&
    (strm << _tao_aggregate.priority);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TAO_SCIOP_Endpoint_Info &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.host.out ()) &&
    (strm >> _tao_aggregate.port) &&
    (strm >> _tao_aggregate.priority);
}

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_TAO_SCIOPEndpointSequence_CPP_
#define _TAO_CDR_OP_TAO_SCIOPEndpointSequence_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO_SCIOPEndpointSequence &_tao_sequence
  )
{
  return TAO::marshal_sequence(strm, _tao_sequence);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TAO_SCIOPEndpointSequence &_tao_sequence
  )
{
  return TAO::demarshal_sequence(strm, _tao_sequence);
}

#endif /* _TAO_CDR_OP_TAO_SCIOPEndpointSequence_CPP_ */

TAO_END_VERSIONED_NAMESPACE_DECL
