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
// be/be_codegen.cpp:338


#include "BoundsC.h"
#include "tao/Typecode.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "BoundsC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:62

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be/be_visitor_exception/exception_cs.cpp:63

CORBA::Bounds::Bounds (void)
  : CORBA::UserException (
        "IDL:omg.org/CORBA/Bounds:1.0",
        "Bounds"
      )
{
}

CORBA::Bounds::~Bounds (void)
{
}

CORBA::Bounds::Bounds (const ::CORBA::Bounds &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

CORBA::Bounds&
CORBA::Bounds::operator= (const ::CORBA::Bounds &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void CORBA::Bounds::_tao_any_destructor (void *_tao_void_pointer)
{
  Bounds *_tao_tmp_pointer =
    ACE_static_cast (Bounds*, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

CORBA::Bounds *
CORBA::Bounds::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/CORBA/Bounds:1.0", _tao_excp->_rep_id ()))
    {
      return ACE_dynamic_cast (Bounds *, _tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *CORBA::Bounds::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::CORBA::Bounds, 0);
  return retval;
}

CORBA::Exception *
CORBA::Bounds::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::CORBA::Bounds (*this),
      0
    );
  return result;
}

void CORBA::Bounds::_raise (void) const
{
  TAO_RAISE (*this);
}

void CORBA::Bounds::_tao_encode (
    TAO_OutputCDR &cdr
    ACE_ENV_ARG_DECL
  ) const
{
  if (cdr << *this)
    {
      return;
    }
  
  ACE_THROW (CORBA::MARSHAL ());
}

void CORBA::Bounds::_tao_decode (
    TAO_InputCDR &cdr
    ACE_ENV_ARG_DECL
  )
{
  if (cdr >> *this)
    {
      return;
    }
  
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr CORBA::Bounds::_type (void) const
{
  return ::CORBA::_tc_Bounds;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_Bounds[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  29,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f426f), 
  ACE_NTOHL (0x756e6473), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/Bounds:1.0
    7,
  ACE_NTOHL (0x426f756e), 
  ACE_NTOHL (0x64730000),  // name = Bounds
  0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_CORBA_Bounds (
    CORBA::tk_except,
    sizeof (_oc_CORBA_Bounds),
    (char *) &_oc_CORBA_Bounds,
    0,
    sizeof (CORBA::Bounds)
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_Bounds =
    &_tc_TAO_tc_CORBA_Bounds;
}

// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:1725

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

