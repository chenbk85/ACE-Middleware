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
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:314


#include "BoundsC.h"
#include "tao/Stub.h"
#include "tao/Invocation.h"
#include "tao/PortableInterceptor.h"

#if TAO_HAS_INTERCEPTORS == 1
#include "tao/RequestInfo_Util.h"
#include "tao/ClientRequestInfo_i.h"
#include "tao/ClientInterceptorAdapter.h"
#endif  /* TAO_HAS_INTERCEPTORS == 1 */



#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "BoundsC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_cs.cpp:63

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
  this->UserException::operator= (_tao_excp);
  return *this;
}

void CORBA::Bounds::_tao_any_destructor (void *_tao_void_pointer)
{
  Bounds *tmp = ACE_static_cast (Bounds*, _tao_void_pointer);
  delete tmp;
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

void CORBA::Bounds::_raise (void)
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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

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

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_Bounds,
    &_tc_TAO_tc_CORBA_Bounds
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::Bounds &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::Bounds>::insert_copy (
      _tao_any,
      CORBA::Bounds::_tao_any_destructor,
      CORBA::_tc_Bounds,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::Bounds *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::Bounds>::insert (
      _tao_any,
      CORBA::Bounds::_tao_any_destructor,
      CORBA::_tc_Bounds,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::Bounds *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const CORBA::Bounds *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::Bounds *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::Bounds>::extract (
        _tao_any,
        CORBA::Bounds::_tao_any_destructor,
        CORBA::_tc_Bounds,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Dual_Impl_T<CORBA::Bounds>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Dual_Impl_T<CORBA::Bounds>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

