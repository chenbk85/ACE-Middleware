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
// be\be_codegen.cpp:277


#include "tao/WStringSeqC.h"
#include "tao/CDR.h"

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_WSTRINGSEQ_CS_)
#define _CORBA_WSTRINGSEQ_CS_

CORBA::WStringSeq::WStringSeq (void)
{}

CORBA::WStringSeq::WStringSeq (
    ::CORBA::ULong max
  )
  : TAO::unbounded_wstring_sequence
    (max)
{}

CORBA::WStringSeq::WStringSeq (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    ::CORBA::WChar * * buffer,
    ::CORBA::Boolean release
  )
  : TAO::unbounded_wstring_sequence
    (max, length, buffer, release)
{}

CORBA::WStringSeq::WStringSeq (
    const WStringSeq &seq
  )
  : TAO::unbounded_wstring_sequence
    (seq)
{}

CORBA::WStringSeq::~WStringSeq (void)
{}

void CORBA::WStringSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  WStringSeq * _tao_tmp_pointer =
    static_cast<WStringSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_CORBA_WStringSeq_CPP_
#define _TAO_CDR_OP_CORBA_WStringSeq_CPP_

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::WStringSeq &_tao_sequence
  )
{
  return TAO::marshal_sequence(strm, _tao_sequence);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::WStringSeq &_tao_sequence
  )
{
  return TAO::demarshal_sequence(strm, _tao_sequence);
}

#endif /* _TAO_CDR_OP_CORBA_WStringSeq_CPP_ */

TAO_END_VERSIONED_NAMESPACE_DECL
