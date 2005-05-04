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

#include "ServantActivatorC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode_Static.h"
#include "tao/Objref_TypeCode_Static.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_ServantActivator (
    CORBA::tk_local_interface,
    "IDL:omg.org/PortableServer/ServantActivator:2.3",
    "ServantActivator");
  
namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_ServantActivator =
    &_tao_tc_PortableServer_ServantActivator;
}



// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableServer::ServantActivator>::to_object (
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
  Any_Impl_T<PortableServer::ServantActivator>::marshal_value (TAO_OutputCDR &)
  {
    return false;
  }
  
  template<>
  CORBA::Boolean
  Any_Impl_T<PortableServer::ServantActivator>::demarshal_value (TAO_InputCDR &)
  {
    return false;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::ServantActivator_ptr _tao_elem
  )
{
  PortableServer::ServantActivator_ptr _tao_objptr =
    PortableServer::ServantActivator::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::ServantActivator_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::ServantActivator>::insert (
      _tao_any,
      PortableServer::ServantActivator::_tao_any_destructor,
      PortableServer::_tc_ServantActivator,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::ServantActivator_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::ServantActivator>::extract (
        _tao_any,
        PortableServer::ServantActivator::_tao_any_destructor,
        PortableServer::_tc_ServantActivator,
        _tao_elem
      );
}
