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

#include "IOP_CodecC.h"
#include "IOP_CodecA.h"
#include "tao/Typecode.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<IOP::Codec>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<IOP::Codec>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<IOP::Codec>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    IOP::Codec_ptr _tao_elem
  )
{
  IOP::Codec_ptr _tao_objptr =
    IOP::Codec::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    IOP::Codec_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<IOP::Codec>::insert (
      _tao_any,
      IOP::Codec::_tao_any_destructor,
      IOP::_tc_Codec,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    IOP::Codec_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<IOP::Codec>::extract (
        _tao_any,
        IOP::Codec::_tao_any_destructor,
        IOP::_tc_Codec,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be/be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<IOP::Codec::InvalidTypeForEncoding>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<IOP::Codec::InvalidTypeForEncoding>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IOP::Codec::InvalidTypeForEncoding &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::Codec::InvalidTypeForEncoding>::insert_copy (
      _tao_any,
      IOP::Codec::InvalidTypeForEncoding::_tao_any_destructor,
      IOP::Codec::_tc_InvalidTypeForEncoding,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IOP::Codec::InvalidTypeForEncoding *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::Codec::InvalidTypeForEncoding>::insert (
      _tao_any,
      IOP::Codec::InvalidTypeForEncoding::_tao_any_destructor,
      IOP::Codec::_tc_InvalidTypeForEncoding,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IOP::Codec::InvalidTypeForEncoding *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const IOP::Codec::InvalidTypeForEncoding *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IOP::Codec::InvalidTypeForEncoding *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::Codec::InvalidTypeForEncoding>::extract (
        _tao_any,
        IOP::Codec::InvalidTypeForEncoding::_tao_any_destructor,
        IOP::Codec::_tc_InvalidTypeForEncoding,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be/be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<IOP::Codec::FormatMismatch>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<IOP::Codec::FormatMismatch>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IOP::Codec::FormatMismatch &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::Codec::FormatMismatch>::insert_copy (
      _tao_any,
      IOP::Codec::FormatMismatch::_tao_any_destructor,
      IOP::Codec::_tc_FormatMismatch,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IOP::Codec::FormatMismatch *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::Codec::FormatMismatch>::insert (
      _tao_any,
      IOP::Codec::FormatMismatch::_tao_any_destructor,
      IOP::Codec::_tc_FormatMismatch,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IOP::Codec::FormatMismatch *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const IOP::Codec::FormatMismatch *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IOP::Codec::FormatMismatch *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::Codec::FormatMismatch>::extract (
        _tao_any,
        IOP::Codec::FormatMismatch::_tao_any_destructor,
        IOP::Codec::_tc_FormatMismatch,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be/be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<IOP::Codec::TypeMismatch>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<IOP::Codec::TypeMismatch>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IOP::Codec::TypeMismatch &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::Codec::TypeMismatch>::insert_copy (
      _tao_any,
      IOP::Codec::TypeMismatch::_tao_any_destructor,
      IOP::Codec::_tc_TypeMismatch,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IOP::Codec::TypeMismatch *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::Codec::TypeMismatch>::insert (
      _tao_any,
      IOP::Codec::TypeMismatch::_tao_any_destructor,
      IOP::Codec::_tc_TypeMismatch,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IOP::Codec::TypeMismatch *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const IOP::Codec::TypeMismatch *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IOP::Codec::TypeMismatch *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::Codec::TypeMismatch>::extract (
        _tao_any,
        IOP::Codec::TypeMismatch::_tao_any_destructor,
        IOP::Codec::_tc_TypeMismatch,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be/be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IOP::Encoding &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::Encoding>::insert_copy (
      _tao_any,
      IOP::Encoding::_tao_any_destructor,
      IOP::_tc_Encoding,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IOP::Encoding *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::Encoding>::insert (
      _tao_any,
      IOP::Encoding::_tao_any_destructor,
      IOP::_tc_Encoding,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IOP::Encoding *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const IOP::Encoding *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IOP::Encoding *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::Encoding>::extract (
        _tao_any,
        IOP::Encoding::_tao_any_destructor,
        IOP::_tc_Encoding,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<IOP::CodecFactory>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<IOP::CodecFactory>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<IOP::CodecFactory>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    IOP::CodecFactory_ptr _tao_elem
  )
{
  IOP::CodecFactory_ptr _tao_objptr =
    IOP::CodecFactory::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    IOP::CodecFactory_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<IOP::CodecFactory>::insert (
      _tao_any,
      IOP::CodecFactory::_tao_any_destructor,
      IOP::_tc_CodecFactory,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    IOP::CodecFactory_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<IOP::CodecFactory>::extract (
        _tao_any,
        IOP::CodecFactory::_tao_any_destructor,
        IOP::_tc_CodecFactory,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be/be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<IOP::CodecFactory::UnknownEncoding>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<IOP::CodecFactory::UnknownEncoding>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IOP::CodecFactory::UnknownEncoding &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::CodecFactory::UnknownEncoding>::insert_copy (
      _tao_any,
      IOP::CodecFactory::UnknownEncoding::_tao_any_destructor,
      IOP::CodecFactory::_tc_UnknownEncoding,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IOP::CodecFactory::UnknownEncoding *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::CodecFactory::UnknownEncoding>::insert (
      _tao_any,
      IOP::CodecFactory::UnknownEncoding::_tao_any_destructor,
      IOP::CodecFactory::_tc_UnknownEncoding,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IOP::CodecFactory::UnknownEncoding *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const IOP::CodecFactory::UnknownEncoding *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IOP::CodecFactory::UnknownEncoding *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::CodecFactory::UnknownEncoding>::extract (
        _tao_any,
        IOP::CodecFactory::UnknownEncoding::_tao_any_destructor,
        IOP::CodecFactory::_tc_UnknownEncoding,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        IOP::Codec::InvalidTypeForEncoding
      >;

  template class
    TAO::Any_Dual_Impl_T<
        IOP::Codec::FormatMismatch
      >;

  template class
    TAO::Any_Dual_Impl_T<
        IOP::Codec::TypeMismatch
      >;

  template class
    TAO::Any_Impl_T<
        IOP::Codec
      >;

  template class
    TAO::Any_Dual_Impl_T<
        IOP::Encoding
      >;

  template class
    TAO::Any_Dual_Impl_T<
        IOP::CodecFactory::UnknownEncoding
      >;

  template class
    TAO::Any_Impl_T<
        IOP::CodecFactory
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        IOP::Codec::InvalidTypeForEncoding \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        IOP::Codec::FormatMismatch \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        IOP::Codec::TypeMismatch \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        IOP::Codec \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        IOP::Encoding \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        IOP::CodecFactory::UnknownEncoding \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        IOP::CodecFactory \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 


