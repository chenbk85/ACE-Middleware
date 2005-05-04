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

#include "PortableInterceptorC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode_Static.h"
#include "tao/Objref_TypeCode_Static.h"
#include "tao/String_TypeCode_Static.h"
#include "tao/Struct_TypeCode_Static.h"
#include "tao/TypeCode_Struct_Field.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_Interceptor (
    CORBA::tk_local_interface,
    "IDL:omg.org/PortableInterceptor/Interceptor:1.0",
    "Interceptor");
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_Interceptor =
    &_tao_tc_PortableInterceptor_Interceptor;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:74

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_PortableInterceptor_ForwardRequest[] =
  {
    { "forward", &CORBA::_tc_Object }
    
  };
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ForwardRequest (
    CORBA::tk_except,
    "IDL:omg.org/PortableInterceptor/ForwardRequest:1.0",
    "ForwardRequest",
    _tao_fields_PortableInterceptor_ForwardRequest,
    1);
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ForwardRequest =
    &_tao_tc_PortableInterceptor_ForwardRequest;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_Current (
    CORBA::tk_local_interface,
    "IDL:omg.org/PortableInterceptor/Current:1.0",
    "Current");
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_Current =
    &_tao_tc_PortableInterceptor_Current;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ClientRequestInterceptor (
    CORBA::tk_local_interface,
    "IDL:omg.org/PortableInterceptor/ClientRequestInterceptor:1.0",
    "ClientRequestInterceptor");
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ClientRequestInterceptor =
    &_tao_tc_PortableInterceptor_ClientRequestInterceptor;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ServerRequestInterceptor (
    CORBA::tk_local_interface,
    "IDL:omg.org/PortableInterceptor/ServerRequestInterceptor:1.0",
    "ServerRequestInterceptor");
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ServerRequestInterceptor =
    &_tao_tc_PortableInterceptor_ServerRequestInterceptor;
}



// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableInterceptor::Interceptor>::to_object (
      CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = CORBA::Object::_duplicate (this->value_);
    return true;
  }
}

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableInterceptor::Interceptor>::marshal_value (TAO_OutputCDR &)
  {
    return false;
  }
  
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableInterceptor::Interceptor>::demarshal_value (TAO_InputCDR &)
  {
    return false;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::Interceptor_ptr _tao_elem
  )
{
  PortableInterceptor::Interceptor_ptr _tao_objptr =
    PortableInterceptor::Interceptor::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::Interceptor_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::Interceptor>::insert (
      _tao_any,
      PortableInterceptor::Interceptor::_tao_any_destructor,
      PortableInterceptor::_tc_Interceptor,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::Interceptor_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::Interceptor>::extract (
        _tao_any,
        PortableInterceptor::Interceptor::_tao_any_destructor,
        PortableInterceptor::_tc_Interceptor,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be/be_visitor_exception/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Dual_Impl_T<PortableInterceptor::ForwardRequest>::demarshal_value (
      TAO_InputCDR & cdr
    )
  {
    CORBA::String_var id;
    
    if (!(cdr >> id.out ()))
      {
        return false;
      }
    
    ACE_TRY_NEW_ENV
      {
        this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;
      }
    ACE_CATCHANY
      {
        return false;
      }
    ACE_ENDTRY;
    
    return true;
  }
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableInterceptor::ForwardRequest &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableInterceptor::ForwardRequest>::insert_copy (
      _tao_any,
      PortableInterceptor::ForwardRequest::_tao_any_destructor,
      PortableInterceptor::_tc_ForwardRequest,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ForwardRequest *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableInterceptor::ForwardRequest>::insert (
      _tao_any,
      PortableInterceptor::ForwardRequest::_tao_any_destructor,
      PortableInterceptor::_tc_ForwardRequest,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ForwardRequest *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableInterceptor::ForwardRequest *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableInterceptor::ForwardRequest *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableInterceptor::ForwardRequest>::extract (
        _tao_any,
        PortableInterceptor::ForwardRequest::_tao_any_destructor,
        PortableInterceptor::_tc_ForwardRequest,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableInterceptor::Current>::to_object (
      CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = CORBA::Object::_duplicate (this->value_);
    return true;
  }
}

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableInterceptor::Current>::marshal_value (TAO_OutputCDR &)
  {
    return false;
  }
  
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableInterceptor::Current>::demarshal_value (TAO_InputCDR &)
  {
    return false;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::Current_ptr _tao_elem
  )
{
  PortableInterceptor::Current_ptr _tao_objptr =
    PortableInterceptor::Current::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::Current_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::Current>::insert (
      _tao_any,
      PortableInterceptor::Current::_tao_any_destructor,
      PortableInterceptor::_tc_Current,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::Current_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::Current>::extract (
        _tao_any,
        PortableInterceptor::Current::_tao_any_destructor,
        PortableInterceptor::_tc_Current,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableInterceptor::ClientRequestInterceptor>::to_object (
      CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = CORBA::Object::_duplicate (this->value_);
    return true;
  }
}

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableInterceptor::ClientRequestInterceptor>::marshal_value (TAO_OutputCDR &)
  {
    return false;
  }
  
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableInterceptor::ClientRequestInterceptor>::demarshal_value (TAO_InputCDR &)
  {
    return false;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ClientRequestInterceptor_ptr _tao_elem
  )
{
  PortableInterceptor::ClientRequestInterceptor_ptr _tao_objptr =
    PortableInterceptor::ClientRequestInterceptor::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ClientRequestInterceptor_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::ClientRequestInterceptor>::insert (
      _tao_any,
      PortableInterceptor::ClientRequestInterceptor::_tao_any_destructor,
      PortableInterceptor::_tc_ClientRequestInterceptor,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ClientRequestInterceptor_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::ClientRequestInterceptor>::extract (
        _tao_any,
        PortableInterceptor::ClientRequestInterceptor::_tao_any_destructor,
        PortableInterceptor::_tc_ClientRequestInterceptor,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableInterceptor::ServerRequestInterceptor>::to_object (
      CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = CORBA::Object::_duplicate (this->value_);
    return true;
  }
}

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableInterceptor::ServerRequestInterceptor>::marshal_value (TAO_OutputCDR &)
  {
    return false;
  }
  
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableInterceptor::ServerRequestInterceptor>::demarshal_value (TAO_InputCDR &)
  {
    return false;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ServerRequestInterceptor_ptr _tao_elem
  )
{
  PortableInterceptor::ServerRequestInterceptor_ptr _tao_objptr =
    PortableInterceptor::ServerRequestInterceptor::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ServerRequestInterceptor_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::ServerRequestInterceptor>::insert (
      _tao_any,
      PortableInterceptor::ServerRequestInterceptor::_tao_any_destructor,
      PortableInterceptor::_tc_ServerRequestInterceptor,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ServerRequestInterceptor_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::ServerRequestInterceptor>::extract (
        _tao_any,
        PortableInterceptor::ServerRequestInterceptor::_tao_any_destructor,
        PortableInterceptor::_tc_ServerRequestInterceptor,
        _tao_elem
      );
}
