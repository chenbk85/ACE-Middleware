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

#include "RequestProcessingPolicyC.h"
#include "tao/Typecode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Basic_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_PortableServer_RequestProcessingPolicyValue[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  60,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f52), 
  ACE_NTOHL (0x65717565), 
  ACE_NTOHL (0x73745072), 
  ACE_NTOHL (0x6f636573), 
  ACE_NTOHL (0x73696e67), 
  ACE_NTOHL (0x506f6c69), 
  ACE_NTOHL (0x63795661), 
  ACE_NTOHL (0x6c75653a), 
  ACE_NTOHL (0x322e3300),  // repository ID = IDL:omg.org/PortableServer/RequestProcessingPolicyValue:2.3
  29,
  ACE_NTOHL (0x52657175), 
  ACE_NTOHL (0x65737450), 
  ACE_NTOHL (0x726f6365), 
  ACE_NTOHL (0x7373696e), 
  ACE_NTOHL (0x67506f6c), 
  ACE_NTOHL (0x69637956), 
  ACE_NTOHL (0x616c7565), 
  ACE_NTOHL (0x0),  // name = RequestProcessingPolicyValue
  3, // member count
  27,
  ACE_NTOHL (0x5553455f), 
  ACE_NTOHL (0x41435449), 
  ACE_NTOHL (0x56455f4f), 
  ACE_NTOHL (0x424a4543), 
  ACE_NTOHL (0x545f4d41), 
  ACE_NTOHL (0x505f4f4e), 
  ACE_NTOHL (0x4c590000),  // name = USE_ACTIVE_OBJECT_MAP_ONLY
  20,
  ACE_NTOHL (0x5553455f), 
  ACE_NTOHL (0x44454641), 
  ACE_NTOHL (0x554c545f), 
  ACE_NTOHL (0x53455256), 
  ACE_NTOHL (0x414e5400),  // name = USE_DEFAULT_SERVANT
  20,
  ACE_NTOHL (0x5553455f), 
  ACE_NTOHL (0x53455256), 
  ACE_NTOHL (0x414e545f), 
  ACE_NTOHL (0x4d414e41), 
  ACE_NTOHL (0x47455200),  // name = USE_SERVANT_MANAGER
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_RequestProcessingPolicyValue (
    CORBA::tk_enum,
    sizeof (_oc_PortableServer_RequestProcessingPolicyValue),
    (char *) &_oc_PortableServer_RequestProcessingPolicyValue,
    0,
    0
  );

namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_RequestProcessingPolicyValue =
    &_tc_TAO_tc_PortableServer_RequestProcessingPolicyValue;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

#if (TAO_HAS_MINIMUM_POA == 0)

static const CORBA::Long _oc_PortableServer_RequestProcessingPolicy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  55,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f52), 
  ACE_NTOHL (0x65717565), 
  ACE_NTOHL (0x73745072), 
  ACE_NTOHL (0x6f636573), 
  ACE_NTOHL (0x73696e67), 
  ACE_NTOHL (0x506f6c69), 
  ACE_NTOHL (0x63793a32), 
  ACE_NTOHL (0x2e330000),  // repository ID = IDL:omg.org/PortableServer/RequestProcessingPolicy:2.3
    24,
  ACE_NTOHL (0x52657175), 
  ACE_NTOHL (0x65737450), 
  ACE_NTOHL (0x726f6365), 
  ACE_NTOHL (0x7373696e), 
  ACE_NTOHL (0x67506f6c), 
  ACE_NTOHL (0x69637900),  // name = RequestProcessingPolicy
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_RequestProcessingPolicy (
    CORBA::tk_objref,
    sizeof (_oc_PortableServer_RequestProcessingPolicy),
    (char *) &_oc_PortableServer_RequestProcessingPolicy,
    0,
    0
  );

namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_RequestProcessingPolicy =
    &_tc_TAO_tc_PortableServer_RequestProcessingPolicy;
}

// TAO_IDL - Generated from
// be\be_visitor_enum/any_op_cs.cpp:52

void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::RequestProcessingPolicyValue _tao_elem
  )
{
  TAO::Any_Basic_Impl_T<PortableServer::RequestProcessingPolicyValue>::insert (
      _tao_any,
      PortableServer::_tc_RequestProcessingPolicyValue,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::RequestProcessingPolicyValue &_tao_elem
  )
{
  return
    TAO::Any_Basic_Impl_T<PortableServer::RequestProcessingPolicyValue>::extract (
        _tao_any,
        PortableServer::_tc_RequestProcessingPolicyValue,
        _tao_elem 
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::RequestProcessingPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::RequestProcessingPolicy>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::RequestProcessingPolicy>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::RequestProcessingPolicy_ptr _tao_elem
  )
{
  PortableServer::RequestProcessingPolicy_ptr _tao_objptr =
    PortableServer::RequestProcessingPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::RequestProcessingPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::RequestProcessingPolicy>::insert (
      _tao_any,
      PortableServer::RequestProcessingPolicy::_tao_any_destructor,
      PortableServer::_tc_RequestProcessingPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::RequestProcessingPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::RequestProcessingPolicy>::extract (
        _tao_any,
        PortableServer::RequestProcessingPolicy::_tao_any_destructor,
        PortableServer::_tc_RequestProcessingPolicy,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Basic_Impl_T<
        PortableServer::RequestProcessingPolicyValue
      >;

  template class
    TAO::Any_Impl_T<
        PortableServer::RequestProcessingPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Basic_Impl_T< \
        PortableServer::RequestProcessingPolicyValue \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableServer::RequestProcessingPolicy \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */
