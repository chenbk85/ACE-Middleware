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
// be/be_codegen.cpp:315

#include "Default_ORTC.h"

#include "tao/Any.h"
#include "tao/ValueFactory.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "Default_ORTC.i"
#endif /* !defined INLINE */


// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_TAO_Default_ORT_ObjectReferenceTemplate[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  48,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x54414f5f),
  ACE_NTOHL (0x44656661),
  ACE_NTOHL (0x756c745f),
  ACE_NTOHL (0x4f52542f),
  ACE_NTOHL (0x4f626a65),
  ACE_NTOHL (0x63745265),
  ACE_NTOHL (0x66657265),
  ACE_NTOHL (0x6e636554),
  ACE_NTOHL (0x656d706c),
  ACE_NTOHL (0x6174653a),
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:TAO_Default_ORT/ObjectReferenceTemplate:1.0
  24,
  ACE_NTOHL (0x4f626a65),
  ACE_NTOHL (0x63745265),
  ACE_NTOHL (0x66657265),
  ACE_NTOHL (0x6e636554),
  ACE_NTOHL (0x656d706c),
  ACE_NTOHL (0x61746500),  // name = ObjectReferenceTemplate
  0, // value modifier
  CORBA::tk_null, // no stateful base valuetype

  0, // member count
};

static CORBA::TypeCode _tc_TAO_tc_TAO_Default_ORT_ObjectReferenceTemplate (
    CORBA::tk_value,
    sizeof (_oc_TAO_Default_ORT_ObjectReferenceTemplate),
    (char *) &_oc_TAO_Default_ORT_ObjectReferenceTemplate,
    0,
    sizeof (TAO_Default_ORT::ObjectReferenceTemplate)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (TAO_Default_ORT)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_ObjectReferenceTemplate,
    &_tc_TAO_tc_TAO_Default_ORT_ObjectReferenceTemplate
  )
TAO_NAMESPACE_END


// TAO_IDL - Generated from
// be/be_visitor_valuetype/valuetype_cs.cpp:95

void
tao_TAO_Default_ORT_ObjectReferenceTemplate_add_ref (
    TAO_Default_ORT::ObjectReferenceTemplate *p
  )
{
  CORBA::add_ref (p);
}

void
tao_TAO_Default_ORT_ObjectReferenceTemplate_remove_ref (
    TAO_Default_ORT::ObjectReferenceTemplate *p
  )
{
  CORBA::remove_ref (p);
}

// TAO_IDL - Generated from
// be/be_valuetype.cpp:299

// *************************************************************
// Operations for class TAO_Default_ORT::ObjectReferenceTemplate_var
// *************************************************************

TAO_Default_ORT::ObjectReferenceTemplate_var::ObjectReferenceTemplate_var (void)
  : ptr_ (0)
{}

TAO_Default_ORT::ObjectReferenceTemplate_var::ObjectReferenceTemplate_var (ObjectReferenceTemplate* p)
  : ptr_ (p)
{}

TAO_Default_ORT::ObjectReferenceTemplate_var::ObjectReferenceTemplate_var (const ObjectReferenceTemplate* p)
  : ptr_ (ACE_const_cast (ObjectReferenceTemplate *, p))
{}

TAO_Default_ORT::ObjectReferenceTemplate *
TAO_Default_ORT::ObjectReferenceTemplate_var::ptr (void) const
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate_var::ObjectReferenceTemplate_var (const ObjectReferenceTemplate_var &p)
{
  CORBA::add_ref (p.ptr ());
  this->ptr_ = p.ptr ();
}

TAO_Default_ORT::ObjectReferenceTemplate_var::~ObjectReferenceTemplate_var (void) // destructor
{
  CORBA::remove_ref (this->ptr_);
}

TAO_Default_ORT::ObjectReferenceTemplate_var &
TAO_Default_ORT::ObjectReferenceTemplate_var::operator= (ObjectReferenceTemplate *p)
{
  CORBA::remove_ref (this->ptr_);
  this->ptr_ = p;
  return *this;
}

TAO_Default_ORT::ObjectReferenceTemplate_var &
TAO_Default_ORT::ObjectReferenceTemplate_var::operator= (const ObjectReferenceTemplate_var &p)
{
  if (this != &p)
  {
    CORBA::remove_ref (this->ptr_);
    ObjectReferenceTemplate *tmp = p.ptr ();
    CORBA::add_ref (tmp);
    this->ptr_ = tmp;
  }

  return *this;
}

TAO_Default_ORT::ObjectReferenceTemplate_var::operator const TAO_Default_ORT::ObjectReferenceTemplate* () const // cast
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate_var::operator TAO_Default_ORT::ObjectReferenceTemplate* () // cast
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate *
TAO_Default_ORT::ObjectReferenceTemplate_var::operator-> (void) const
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate *
TAO_Default_ORT::ObjectReferenceTemplate_var::in (void) const
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate *&
TAO_Default_ORT::ObjectReferenceTemplate_var::inout (void)
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate *&
TAO_Default_ORT::ObjectReferenceTemplate_var::out (void)
{
  CORBA::remove_ref (this->ptr_);
  this->ptr_ = 0;
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate *
TAO_Default_ORT::ObjectReferenceTemplate_var::_retn (void)
{
  // yield ownership of managed obj reference
  ObjectReferenceTemplate* tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

void
TAO_Default_ORT::ObjectReferenceTemplate_var::tao_add_ref (
    ObjectReferenceTemplate *p
  )
{
  CORBA::add_ref (p);
}

void
TAO_Default_ORT::ObjectReferenceTemplate_var::tao_remove_ref (
    ObjectReferenceTemplate *p
  )
{
  CORBA::remove_ref (p);
}

// TAO_IDL - Generated from
// be/be_valuetype.cpp:569

// *************************************************************
// Operations for class TAO_Default_ORT::ObjectReferenceTemplate_out
// *************************************************************

TAO_Default_ORT::ObjectReferenceTemplate_out::ObjectReferenceTemplate_out (ObjectReferenceTemplate *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

TAO_Default_ORT::ObjectReferenceTemplate_out::ObjectReferenceTemplate_out (ObjectReferenceTemplate_var &p)
  : ptr_ (p.out ())
{
  CORBA::remove_ref (this->ptr_);
  this->ptr_ = 0;
}

TAO_Default_ORT::ObjectReferenceTemplate_out::ObjectReferenceTemplate_out (const ObjectReferenceTemplate_out &p)
  : ptr_ (ACE_const_cast (ObjectReferenceTemplate_out&, p).ptr_)
{}

TAO_Default_ORT::ObjectReferenceTemplate_out &
TAO_Default_ORT::ObjectReferenceTemplate_out::operator= (const ObjectReferenceTemplate_out &p)
{
  this->ptr_ = ACE_const_cast (ObjectReferenceTemplate_out&, p).ptr_;
  return *this;
}

TAO_Default_ORT::ObjectReferenceTemplate_out &
TAO_Default_ORT::ObjectReferenceTemplate_out::operator= (const ObjectReferenceTemplate_var &p)
{
  ObjectReferenceTemplate *tmp = p.ptr ();
  CORBA::add_ref (tmp);
  this->ptr_ = tmp;
  return *this;
}

TAO_Default_ORT::ObjectReferenceTemplate_out &
TAO_Default_ORT::ObjectReferenceTemplate_out::operator= (ObjectReferenceTemplate *p)
{
  this->ptr_ = p;
  return *this;
}

TAO_Default_ORT::ObjectReferenceTemplate_out::operator TAO_Default_ORT::ObjectReferenceTemplate*& () // cast
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate *&
TAO_Default_ORT::ObjectReferenceTemplate_out::ptr (void) // ptr
{
  return this->ptr_;
}

TAO_Default_ORT::ObjectReferenceTemplate *
TAO_Default_ORT::ObjectReferenceTemplate_out::operator-> (void)
{
  return this->ptr_;
}

// *************************************************************

// TAO_IDL - Generated from
// be/be_visitor_valuetype/valuetype_cs.cpp:138

TAO_Default_ORT::ObjectReferenceTemplate *
TAO_Default_ORT::ObjectReferenceTemplate::_downcast (CORBA::ValueBase *v)
{
  if (v == 0)
    {
      return 0;
    }

  return (ObjectReferenceTemplate *) v->_tao_obv_narrow ((ptr_arith_t) &_downcast);
}

const char *
TAO_Default_ORT::ObjectReferenceTemplate::_tao_obv_repository_id (void) const
{
  return this->_tao_obv_static_repository_id ();
}

void *
TAO_Default_ORT::ObjectReferenceTemplate::_tao_obv_narrow (ptr_arith_t type_id)
{
  if (type_id == (ptr_arith_t) &_downcast)
    {
      return this;
    }

  void *rval = 0;

  if (rval == 0)
    {
      rval = ACE_NESTED_CLASS (PortableInterceptor,ObjectReferenceTemplate)::_tao_obv_narrow (type_id);
    }

  return rval;
}

void
TAO_Default_ORT::ObjectReferenceTemplate::_tao_any_destructor (void *_tao_void_pointer)
{
  ObjectReferenceTemplate *tmp =
    ACE_static_cast (
        ObjectReferenceTemplate *,
        _tao_void_pointer
      );
  delete tmp;
}

CORBA::Boolean TAO_Default_ORT::ObjectReferenceTemplate::_tao_marshal_v (TAO_OutputCDR & strm)
{
  return this->_tao_marshal__TAO_Default_ORT_ObjectReferenceTemplate (strm);
}

CORBA::Boolean TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal_v (TAO_InputCDR & strm)
{
  return this->_tao_unmarshal__TAO_Default_ORT_ObjectReferenceTemplate (strm);
}

CORBA::Boolean TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal (
    TAO_InputCDR &strm,
    ObjectReferenceTemplate *&new_object
  )
{
  CORBA::ValueBase *base = 0;
  CORBA::ValueFactory_var factory;
  CORBA::Boolean retval =
    CORBA::ValueBase::_tao_unmarshal_pre (
        strm,
        factory,
        base,
        ObjectReferenceTemplate::_tao_obv_static_repository_id ()
      );

  if (retval == 0)
    {
      return 0;
    }

  if (factory.in () != 0)
    {
      base = factory->create_for_unmarshal ();

      if (base == 0)
        {
          return 0;  // %! except.?
        }

      retval = base->_tao_unmarshal_v (strm);

      if (retval == 0)
        {
          return 0;
        }
    }

  // Now base must be null or point to the unmarshaled object.
  // Align the pointer to the right subobject.
  new_object = ObjectReferenceTemplate::_downcast (base);
  return retval;
}

// TAO_IDL - Generated from
// be/be_visitor_valuetype/valuetype_obv_cs.cpp:56

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_marshal__TAO_Default_ORT_ObjectReferenceTemplate (TAO_OutputCDR &strm)
{
  return _tao_marshal_state (strm);
}

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal__TAO_Default_ORT_ObjectReferenceTemplate (TAO_InputCDR &strm)
{
  return _tao_unmarshal_state (strm);
}
// TAO_IDL - Generated from
// be/be_visitor_valuetype/any_op_cs.cpp:56

// Copying.
void
operator<<= (
    CORBA::Any &any,
    TAO_Default_ORT::ObjectReferenceTemplate *value
  )
{
  TAO_OutputCDR stream;

  if (stream << value)
    {
      any._tao_replace (
          TAO_Default_ORT::_tc_ObjectReferenceTemplate,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin ()
        );
    }
}

// Non-copying.
void
operator<<= (
    CORBA::Any &any,
    TAO_Default_ORT::ObjectReferenceTemplate **value
  )
{
  TAO_OutputCDR stream;

  if (stream << *value)
    {
      any._tao_replace (
          TAO_Default_ORT::_tc_ObjectReferenceTemplate,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin (),
          1,
          *value,
          TAO_Default_ORT::ObjectReferenceTemplate::_tao_any_destructor
        );
    }
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &any,
    TAO_Default_ORT::ObjectReferenceTemplate *&value
  )
{
  ACE_TRY_NEW_ENV
  {
    value = 0;
    CORBA::TypeCode_var type = any.type ();
    CORBA::Boolean result =
      type->equivalent (
          TAO_Default_ORT::_tc_ObjectReferenceTemplate
          ACE_ENV_ARG_PARAMETER
        );
    ACE_TRY_CHECK;

    if (!result)
      {
        return 0; // not equivalent
      }

    if (any.any_owns_data ())
      {
        const TAO_Default_ORT::ObjectReferenceTemplate *const_holder =
          ACE_static_cast (
              const TAO_Default_ORT::ObjectReferenceTemplate *,
              any.value ()
            );
        value =
          ACE_const_cast (
              TAO_Default_ORT::ObjectReferenceTemplate *,
              const_holder
            );
        return 1;
      }
    else
      {
        TAO_Default_ORT::ObjectReferenceTemplate *tmp;
        TAO_InputCDR stream (
            any._tao_get_cdr (),
            any._tao_byte_order ()
          );

        if (stream >> tmp)
          {
            ((CORBA::Any *)&any)->_tao_replace (
                TAO_Default_ORT::_tc_ObjectReferenceTemplate,
                1,
                ACE_static_cast (void *, tmp),
                TAO_Default_ORT::ObjectReferenceTemplate::_tao_any_destructor
              );
            value = tmp;
            return 1;
          }
      }
  }
  ACE_CATCHANY
  {
  }
  ACE_ENDTRY;
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
    template class TAO_Valuetype_Manager<TAO_Default_ORT::ObjectReferenceTemplate, TAO_Default_ORT::ObjectReferenceTemplate_var>;
  #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
  #  pragma instantiate TAO_Valuetype_Manager<TAO_Default_ORT::ObjectReferenceTemplate, TAO_Default_ORT::ObjectReferenceTemplate_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// be/be_valuetype.cpp:742

void
CORBA::add_ref (TAO_Default_ORT::ObjectReferenceTemplate * vt)
{
  if (vt != 0)
    {
      vt->_add_ref ();
    }
}

void
CORBA::remove_ref (TAO_Default_ORT::ObjectReferenceTemplate * vt)
{
  if (vt != 0)
    {
      vt->_remove_ref ();
    }
}

// TAO_IDL - Generated from
// be/be_visitor_valuetype/cdr_op_cs.cpp:70

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const TAO_Default_ORT::ObjectReferenceTemplate *_tao_valuetype
  )
{
  return
    CORBA_ValueBase::_tao_marshal (
        strm,
        ACE_const_cast (
            TAO_Default_ORT::ObjectReferenceTemplate *,
            _tao_valuetype
          ),
        (ptr_arith_t) &TAO_Default_ORT::ObjectReferenceTemplate::_downcast
      );
}

CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    TAO_Default_ORT::ObjectReferenceTemplate *&_tao_valuetype
  )
{
  return TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal (strm, _tao_valuetype);
}

// TAO_IDL - Generated from
// be/be_visitor_valuetype/marshal_cs.cpp:44

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_marshal_state (TAO_OutputCDR &)
{
  if (
    1
   )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal_state (TAO_InputCDR &)
{
  if (
    1
   )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}
