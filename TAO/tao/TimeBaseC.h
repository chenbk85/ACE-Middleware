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

#ifndef _TAO_IDL_ORIG_TIMEBASEC_H_
#define _TAO_IDL_ORIG_TIMEBASEC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/VarOut_T.h"

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

namespace TimeBase
{
  
  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef CORBA::ULongLong TimeT;
  typedef CORBA::ULongLong_out TimeT_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_Export ::CORBA::TypeCode_ptr const _tc_TimeT;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef TimeT InaccuracyT;
  typedef TimeT_out InaccuracyT_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_Export ::CORBA::TypeCode_ptr const _tc_InaccuracyT;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379
  
  typedef CORBA::Short TdfT;
  typedef CORBA::Short_out TdfT_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_Export ::CORBA::TypeCode_ptr const _tc_TdfT;
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:258
  
  struct UtcT;
  
  typedef
    TAO_Fixed_Var_T<
        UtcT
      >
    UtcT_var;
  
  typedef
    UtcT &
    UtcT_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:52
  
  struct TAO_Export UtcT
  {
    typedef UtcT_var _var_type;
    
    static void _tao_any_destructor (void *);
    TimeBase::TimeT time;
    CORBA::ULong inacclo;
    CORBA::UShort inacchi;
    TimeBase::TdfT tdf;
  };
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_Export ::CORBA::TypeCode_ptr const _tc_UtcT;
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:258
  
  struct IntervalT;
  
  typedef
    TAO_Fixed_Var_T<
        IntervalT
      >
    IntervalT_var;
  
  typedef
    IntervalT &
    IntervalT_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:52
  
  struct TAO_Export IntervalT
  {
    typedef IntervalT_var _var_type;
    
    static void _tao_any_destructor (void *);
    TimeBase::TimeT lower_bound;
    TimeBase::TimeT upper_bound;
  };
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_Export ::CORBA::TypeCode_ptr const _tc_IntervalT;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module TimeBase

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const TimeBase::UtcT &); // copying version
TAO_Export void operator<<= (CORBA::Any &, TimeBase::UtcT*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, TimeBase::UtcT *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const TimeBase::UtcT *&);

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const TimeBase::IntervalT &); // copying version
TAO_Export void operator<<= (CORBA::Any &, TimeBase::IntervalT*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, TimeBase::IntervalT *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const TimeBase::IntervalT *&);

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TimeBase::UtcT &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, TimeBase::UtcT &);

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TimeBase::IntervalT &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, TimeBase::IntervalT &);

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


