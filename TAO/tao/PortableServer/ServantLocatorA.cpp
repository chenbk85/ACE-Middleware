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

#include "ServantLocatorC.h"
#include "tao/Typecode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

#if (TAO_HAS_MINIMUM_POA == 0)

static const CORBA::Long _oc_PortableServer_ServantLocator[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  46,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f53), 
  ACE_NTOHL (0x65727661), 
  ACE_NTOHL (0x6e744c6f), 
  ACE_NTOHL (0x6361746f), 
  ACE_NTOHL (0x723a322e), 
  ACE_NTOHL (0x33000000),  // repository ID = IDL:omg.org/PortableServer/ServantLocator:2.3
    15,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x616e744c), 
  ACE_NTOHL (0x6f636174), 
  ACE_NTOHL (0x6f720000),  // name = ServantLocator
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_ServantLocator (
    CORBA::tk_objref,
    sizeof (_oc_PortableServer_ServantLocator),
    (char *) &_oc_PortableServer_ServantLocator,
    0,
    0
  );

namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_ServantLocator =
    &_tc_TAO_tc_PortableServer_ServantLocator;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::ServantLocator>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::ServantLocator>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::ServantLocator>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::ServantLocator_ptr _tao_elem
  )
{
  PortableServer::ServantLocator_ptr _tao_objptr =
    PortableServer::ServantLocator::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::ServantLocator_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::ServantLocator>::insert (
      _tao_any,
      PortableServer::ServantLocator::_tao_any_destructor,
      PortableServer::_tc_ServantLocator,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::ServantLocator_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::ServantLocator>::extract (
        _tao_any,
        PortableServer::ServantLocator::_tao_any_destructor,
        PortableServer::_tc_ServantLocator,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Impl_T<
        PortableServer::ServantLocator
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableServer::ServantLocator \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */
