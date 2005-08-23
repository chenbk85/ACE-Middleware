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
// be\be_codegen.cpp:788

#ifndef _TAO_IDL_ANYTYPECODE_GIOPA_H_
#define _TAO_IDL_ANYTYPECODE_GIOPA_H_

#include /**/ "ace/pre.h"

#include "tao/AnyTypeCode/TAO_AnyTypeCode_Export.h"
#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/GIOPC.h"
#include "tao/AnyTypeCode/IOP_IORA.h"
#include "tao/AnyTypeCode/OctetSeqA.h"


// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:59

namespace GIOP
{

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_AddressingDisposition;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_Version;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_IORAddressingInfo;

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_AnyTypeCode_Export ::CORBA::TypeCode_ptr const _tc_TargetAddress;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:86

} // module GIOP

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const GIOP::Version &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, GIOP::Version*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, GIOP::Version *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const GIOP::Version *&);

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const GIOP::IORAddressingInfo &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, GIOP::IORAddressingInfo*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, GIOP::IORAddressingInfo *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const GIOP::IORAddressingInfo *&);

// TAO_IDL - Generated from
// be\be_visitor_union/any_op_ch.cpp:53

TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, const GIOP::TargetAddress &); // copying version
TAO_AnyTypeCode_Export void operator<<= (CORBA::Any &, GIOP::TargetAddress*); // noncopying version
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, GIOP::TargetAddress *&); // deprecated
TAO_AnyTypeCode_Export CORBA::Boolean operator>>= (const CORBA::Any &, const GIOP::TargetAddress *&);

#include /**/ "ace/post.h"

#endif /* ifndef */
