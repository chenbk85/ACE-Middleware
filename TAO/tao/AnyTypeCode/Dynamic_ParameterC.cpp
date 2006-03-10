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
// be\be_codegen.cpp:291


#include "tao/AnyTypeCode/Dynamic_ParameterC.h"
#include "tao/CDR.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
Dynamic::Parameter::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  Parameter *_tao_tmp_pointer =
    static_cast<Parameter *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Dynamic::Parameter &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.argument) &&
    (strm << _tao_aggregate.mode);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Dynamic::Parameter &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.argument) &&
    (strm >> _tao_aggregate.mode);
}

TAO_END_VERSIONED_NAMESPACE_DECL
