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


#include "htiop_endpointsC.h"
#include "tao/CDR.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/Sequence_TypeCode.h"
#include "tao/String_TypeCode.h"
#include "tao/Struct_TypeCode.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "htiop_endpointsC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:34

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_HTIOP_Endpoint_Info[] =
  {
    { "host", &CORBA::_tc_string },
    { "port", &CORBA::_tc_short },
    { "htid", &CORBA::_tc_string }
    
  };
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_HTIOP_Endpoint_Info (
    CORBA::tk_struct,
    "IDL:HTIOP_Endpoint_Info:1.0",
    "HTIOP_Endpoint_Info",
    _tao_fields_HTIOP_Endpoint_Info,
    3);
  
::CORBA::TypeCode_ptr const _tc_HTIOP_Endpoint_Info =
  &_tao_tc_HTIOP_Endpoint_Info;

// TAO_IDL - Generated from 
// be/be_visitor_structure/structure_cs.cpp:68



// TAO_IDL - Generated from 
// be/be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_HTIOPENDPOINTSEQUENCE_CS_)
#define _HTIOPENDPOINTSEQUENCE_CS_

HTIOPEndpointSequence::HTIOPEndpointSequence (void)
{}

HTIOPEndpointSequence::HTIOPEndpointSequence (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        HTIOP_Endpoint_Info
      >
    (max)
{}

HTIOPEndpointSequence::HTIOPEndpointSequence (
    CORBA::ULong max,
    CORBA::ULong length,
    HTIOP_Endpoint_Info * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        HTIOP_Endpoint_Info
      >
    (max, length, buffer, release)
{}

HTIOPEndpointSequence::HTIOPEndpointSequence (
    const HTIOPEndpointSequence &seq
  )
  : TAO_Unbounded_Sequence<
        HTIOP_Endpoint_Info
      >
    (seq)
{}

HTIOPEndpointSequence::~HTIOPEndpointSequence (void)
{}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_typecode/alias_typecode.cpp:31



// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:924


#ifndef _TAO_TYPECODE_HTIOPEndpointSequence_GUARD
#define _TAO_TYPECODE_HTIOPEndpointSequence_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence<CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      HTIOPEndpointSequence_0 (
        CORBA::tk_sequence,
        &_tc_HTIOP_Endpoint_Info,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_HTIOPEndpointSequence_0 =
      &HTIOPEndpointSequence_0;
    
  }
}


#endif /* _TAO_TYPECODE_HTIOPEndpointSequence_GUARD */
static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            CORBA::tk_alias,
                            TAO::Null_RefCount_Policy>
  _tao_tc_HTIOPEndpointSequence (
    "IDL:HTIOPEndpointSequence:1.0",
    "HTIOPEndpointSequence",
    &TAO::TypeCode::tc_HTIOPEndpointSequence_0);
  
::CORBA::TypeCode_ptr const _tc_HTIOPEndpointSequence =
  &_tao_tc_HTIOPEndpointSequence;

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const HTIOP_Endpoint_Info &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.host.in ()) &&
    (strm << _tao_aggregate.port) &&
    (strm << _tao_aggregate.htid.in ());
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    HTIOP_Endpoint_Info &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.host.out ()) &&
    (strm >> _tao_aggregate.port) &&
    (strm >> _tao_aggregate.htid.out ());
}

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_HTIOPEndpointSequence_CPP_
#define _TAO_CDR_OP_HTIOPEndpointSequence_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const HTIOPEndpointSequence &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    HTIOPEndpointSequence &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_HTIOPEndpointSequence_CPP_ */
