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
// be/be_codegen.cpp:848

#ifndef _TAO_IDL_ORIG_PORTABLEINTERCEPTORA_ANYOP_H_
#define _TAO_IDL_ORIG_PORTABLEINTERCEPTORA_ANYOP_H_

#include /**/ "ace/pre.h"

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::Interceptor_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::Interceptor_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::Interceptor_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_exception/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const PortableInterceptor::ForwardRequest &); // copying version
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ForwardRequest*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ForwardRequest *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const PortableInterceptor::ForwardRequest *&);

// TAO_IDL - Generated from
// be/be_visitor_exception/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const PortableInterceptor::InvalidSlot &); // copying version
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::InvalidSlot*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::InvalidSlot *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const PortableInterceptor::InvalidSlot *&);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::Current_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::Current_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::Current_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::RequestInfo_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::RequestInfo_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::RequestInfo_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ClientRequestInfo_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ClientRequestInfo_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ClientRequestInfo_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ServerRequestInfo_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ServerRequestInfo_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ServerRequestInfo_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ClientRequestInterceptor_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ClientRequestInterceptor_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ClientRequestInterceptor_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ServerRequestInterceptor_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ServerRequestInterceptor_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ServerRequestInterceptor_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::PolicyFactory_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::PolicyFactory_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::PolicyFactory_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_interface_fwd/any_op_ch.cpp:65

TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::IORInterceptor_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::IORInterceptor_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::IORInterceptor *&);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ORBInitInfo_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ORBInitInfo_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ORBInitInfo_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_exception/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const PortableInterceptor::ORBInitInfo::DuplicateName &); // copying version
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ORBInitInfo::DuplicateName*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ORBInitInfo::DuplicateName *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const PortableInterceptor::ORBInitInfo::DuplicateName *&);

// TAO_IDL - Generated from
// be/be_visitor_exception/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const PortableInterceptor::ORBInitInfo::InvalidName &); // copying version
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ORBInitInfo::InvalidName*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ORBInitInfo::InvalidName *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const PortableInterceptor::ORBInitInfo::InvalidName *&);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ORBInitializer_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ORBInitializer_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ORBInitializer_ptr &);

#include /**/ "ace/post.h"

#endif /* ifndef */

