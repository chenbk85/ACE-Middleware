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


#include "PIForwardRequestC.h"
#include "tao/CDR.h"
#include "tao/SystemException.h"
#include "ace/OS_NS_string.h"

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

PortableInterceptor::ForwardRequest::ForwardRequest (void)
  : ::CORBA::UserException (
        "IDL:omg.org/PortableInterceptor/ForwardRequest:1.0",
        "ForwardRequest"
      )
{
}

PortableInterceptor::ForwardRequest::~ForwardRequest (void)
{
}

PortableInterceptor::ForwardRequest::ForwardRequest (const ::PortableInterceptor::ForwardRequest &_tao_excp)
  : ::CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
  this->forward = CORBA::Object::_duplicate (_tao_excp.forward.in ());
}

PortableInterceptor::ForwardRequest&
PortableInterceptor::ForwardRequest::operator= (const ::PortableInterceptor::ForwardRequest &_tao_excp)
{
  this->ACE_NESTED_CLASS ( ::CORBA, UserException)::operator= (_tao_excp);
  this->forward = CORBA::Object::_duplicate (_tao_excp.forward.in ());
  return *this;
}

void PortableInterceptor::ForwardRequest::_tao_any_destructor (void *_tao_void_pointer)
{
  ForwardRequest *_tao_tmp_pointer =
    static_cast<ForwardRequest *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableInterceptor::ForwardRequest *
PortableInterceptor::ForwardRequest::_downcast ( ::CORBA::Exception *_tao_excp)
{
  return dynamic_cast<ForwardRequest *> (_tao_excp);
}

const PortableInterceptor::ForwardRequest *
PortableInterceptor::ForwardRequest::_downcast ( ::CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const ForwardRequest *> (_tao_excp);
}

::CORBA::Exception *PortableInterceptor::ForwardRequest::_alloc (void)
{
  ::CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableInterceptor::ForwardRequest, 0);
  return retval;
}

::CORBA::Exception *
PortableInterceptor::ForwardRequest::_tao_duplicate (void) const
{
  ::CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::PortableInterceptor::ForwardRequest (*this),
      0
    );
  return result;
}

void PortableInterceptor::ForwardRequest::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableInterceptor::ForwardRequest::_tao_encode (
    TAO_OutputCDR &cdr
    ACE_ENV_ARG_DECL
  ) const
{
  if (cdr << *this)
    {
      return;
    }
  
  ACE_THROW ( ::CORBA::MARSHAL ());
}

void PortableInterceptor::ForwardRequest::_tao_decode (
    TAO_InputCDR &cdr
    ACE_ENV_ARG_DECL
  )
{
  if (cdr >> *this)
    {
      return;
    }
  
  ACE_THROW ( ::CORBA::MARSHAL ());
}



// TAO_IDL - Generated from
// be\be_visitor_exception/exception_ctor.cpp:66

PortableInterceptor::ForwardRequest::ForwardRequest (
    const ::CORBA::Object_ptr  _tao_forward
  )
  : ::CORBA::UserException (
        "IDL:omg.org/PortableInterceptor/ForwardRequest:1.0",
        "ForwardRequest"
      )
{
  this->forward = CORBA::Object::_duplicate (_tao_forward);
}



// TAO_IDL - Generated from
// be\be_visitor_exception/cdr_op_cs.cpp:60

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const PortableInterceptor::ForwardRequest &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
    {
      // Now marshal the members (if any).
      return (
        (strm << _tao_aggregate.forward.in ())
       );
    }
  else
    {
      return false;
    }
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    PortableInterceptor::ForwardRequest &_tao_aggregate
  )
{
  // Demarshal the members.
  return (
    (strm >> _tao_aggregate.forward.out ())
  );
}
