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
// be\be_codegen.cpp:291


#include "tao/ObjRefTemplate/ObjectReferenceTemplate.h"
#include "tao/CDR.h"
#include "tao/Exception_Data.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Valuetype/ValueFactory.h"
#include "tao/ORB_Core.h"
#include "tao/Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"
#include "tao/Var_Size_Argument_T.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "tao/ObjRefTemplate/ObjectReferenceTemplateC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // be\be_visitor_arg_traits.cpp:489

#if !defined (_CORBA_STRINGSEQ__ARG_TRAITS_CS_)
#define _CORBA_STRINGSEQ__ARG_TRAITS_CS_

  template<>
  class Arg_Traits<CORBA::StringSeq>
    : public
        Var_Size_Arg_Traits_T<
            CORBA::StringSeq,
            CORBA::StringSeq_var,
            CORBA::StringSeq_out,
            TAO::Any_Insert_Policy_Stream <CORBA::StringSeq>
          >
  {
  };

#endif /* end #if !defined */
}


// TAO_IDL - Generated from
// be\be_visitor_valuetype/valuetype_cs.cpp:66

void
TAO::Value_Traits<PortableInterceptor::ObjectReferenceFactory>::add_ref (
    PortableInterceptor::ObjectReferenceFactory * p
  )
{
  CORBA::add_ref (p);
}

void
TAO::Value_Traits<PortableInterceptor::ObjectReferenceFactory>::remove_ref (
    PortableInterceptor::ObjectReferenceFactory * p
  )
{
  CORBA::remove_ref (p);
}

void
TAO::Value_Traits<PortableInterceptor::ObjectReferenceFactory>::release (
    PortableInterceptor::ObjectReferenceFactory * p
  )
{
  CORBA::remove_ref (p);
}

PortableInterceptor::ObjectReferenceFactory *
PortableInterceptor::ObjectReferenceFactory::_downcast (CORBA::ValueBase *v)
{
  return dynamic_cast< ::PortableInterceptor::ObjectReferenceFactory * > (v);
}

const char *
PortableInterceptor::ObjectReferenceFactory::_tao_obv_repository_id (void) const
{
  return this->_tao_obv_static_repository_id ();
}

void
PortableInterceptor::ObjectReferenceFactory::_tao_any_destructor (void *_tao_void_pointer)
{
  ObjectReferenceFactory *_tao_tmp_pointer =
    static_cast<ObjectReferenceFactory *> (_tao_void_pointer);
  CORBA::remove_ref (_tao_tmp_pointer);
}

PortableInterceptor::ObjectReferenceFactory::~ObjectReferenceFactory (void)
{}

CORBA::Boolean PortableInterceptor::ObjectReferenceFactory::_tao_unmarshal (
    TAO_InputCDR &strm,
    ObjectReferenceFactory *&new_object
  )
{
  CORBA::ValueBase *base = 0;
  CORBA::ValueFactory_var factory;
  CORBA::Boolean retval =
    CORBA::ValueBase::_tao_unmarshal_pre (
        strm,
        factory.out (),
        base,
        ObjectReferenceFactory::_tao_obv_static_repository_id ()
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
  new_object = ObjectReferenceFactory::_downcast (base);
  return retval;
}

// TAO_IDL - Generated from
// be\be_visitor_valuetype/valuetype_cs.cpp:66

void
TAO::Value_Traits<PortableInterceptor::ObjectReferenceTemplate>::add_ref (
    PortableInterceptor::ObjectReferenceTemplate * p
  )
{
  CORBA::add_ref (p);
}

void
TAO::Value_Traits<PortableInterceptor::ObjectReferenceTemplate>::remove_ref (
    PortableInterceptor::ObjectReferenceTemplate * p
  )
{
  CORBA::remove_ref (p);
}

void
TAO::Value_Traits<PortableInterceptor::ObjectReferenceTemplate>::release (
    PortableInterceptor::ObjectReferenceTemplate * p
  )
{
  CORBA::remove_ref (p);
}

PortableInterceptor::ObjectReferenceTemplate *
PortableInterceptor::ObjectReferenceTemplate::_downcast (CORBA::ValueBase *v)
{
  return dynamic_cast< ::PortableInterceptor::ObjectReferenceTemplate * > (v);
}

const char *
PortableInterceptor::ObjectReferenceTemplate::_tao_obv_repository_id (void) const
{
  return this->_tao_obv_static_repository_id ();
}

void
PortableInterceptor::ObjectReferenceTemplate::_tao_any_destructor (void *_tao_void_pointer)
{
  ObjectReferenceTemplate *_tao_tmp_pointer =
    static_cast<ObjectReferenceTemplate *> (_tao_void_pointer);
  CORBA::remove_ref (_tao_tmp_pointer);
}

PortableInterceptor::ObjectReferenceTemplate::~ObjectReferenceTemplate (void)
{}

CORBA::Boolean PortableInterceptor::ObjectReferenceTemplate::_tao_unmarshal (
    TAO_InputCDR &strm,
    ObjectReferenceTemplate *&new_object
  )
{
  CORBA::ValueBase *base = 0;
  CORBA::ValueFactory_var factory;
  CORBA::Boolean retval =
    CORBA::ValueBase::_tao_unmarshal_pre (
        strm,
        factory.out (),
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
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ_CS_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ_CS_

PortableInterceptor::ObjectReferenceTemplateSeq::ObjectReferenceTemplateSeq (void)
{}

PortableInterceptor::ObjectReferenceTemplateSeq::ObjectReferenceTemplateSeq (
    CORBA::ULong max
  )
  : TAO::unbounded_valuetype_sequence<
        PortableInterceptor::ObjectReferenceTemplate,
        PortableInterceptor::ObjectReferenceTemplate_var
      >
    (max)
{}

PortableInterceptor::ObjectReferenceTemplateSeq::ObjectReferenceTemplateSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    PortableInterceptor::ObjectReferenceTemplate * * buffer,
    CORBA::Boolean release
  )
  : TAO::unbounded_valuetype_sequence<
        PortableInterceptor::ObjectReferenceTemplate,
        PortableInterceptor::ObjectReferenceTemplate_var
      >
    (max, length, buffer, release)
{}

PortableInterceptor::ObjectReferenceTemplateSeq::ObjectReferenceTemplateSeq (
    const ObjectReferenceTemplateSeq &seq
  )
  : TAO::unbounded_valuetype_sequence<
        PortableInterceptor::ObjectReferenceTemplate,
        PortableInterceptor::ObjectReferenceTemplate_var
      >
    (seq)
{}

PortableInterceptor::ObjectReferenceTemplateSeq::~ObjectReferenceTemplateSeq (void)
{}

void PortableInterceptor::ObjectReferenceTemplateSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  ObjectReferenceTemplateSeq * _tao_tmp_pointer =
    static_cast<ObjectReferenceTemplateSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_valuetype.cpp:487

void
CORBA::add_ref (PortableInterceptor::ObjectReferenceFactory * vt)
{
  if (vt != 0)
    {
      vt->_add_ref ();
    }
}

void
CORBA::remove_ref (PortableInterceptor::ObjectReferenceFactory * vt)
{
  if (vt != 0)
    {
      vt->_remove_ref ();
    }
}

// TAO_IDL - Generated from
// be\be_visitor_valuetype/cdr_op_cs.cpp:73

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const PortableInterceptor::ObjectReferenceFactory *_tao_valuetype
  )
{
  return
    CORBA::ValueBase::_tao_marshal (
        strm,
        _tao_valuetype,
        reinterpret_cast<ptrdiff_t> (&PortableInterceptor::ObjectReferenceFactory::_downcast)
      );
}

CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    PortableInterceptor::ObjectReferenceFactory *&_tao_valuetype
  )
{
  return PortableInterceptor::ObjectReferenceFactory::_tao_unmarshal (strm, _tao_valuetype);
}



// TAO_IDL - Generated from
// be\be_valuetype.cpp:487

void
CORBA::add_ref (PortableInterceptor::ObjectReferenceTemplate * vt)
{
  if (vt != 0)
    {
      vt->_add_ref ();
    }
}

void
CORBA::remove_ref (PortableInterceptor::ObjectReferenceTemplate * vt)
{
  if (vt != 0)
    {
      vt->_remove_ref ();
    }
}

// TAO_IDL - Generated from
// be\be_visitor_valuetype/cdr_op_cs.cpp:73

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const PortableInterceptor::ObjectReferenceTemplate *_tao_valuetype
  )
{
  return
    CORBA::ValueBase::_tao_marshal (
        strm,
        _tao_valuetype,
        reinterpret_cast<ptrdiff_t> (&PortableInterceptor::ObjectReferenceTemplate::_downcast)
      );
}

CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    PortableInterceptor::ObjectReferenceTemplate *&_tao_valuetype
  )
{
  return PortableInterceptor::ObjectReferenceTemplate::_tao_unmarshal (strm, _tao_valuetype);
}



// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_PortableInterceptor_ObjectReferenceTemplateSeq_CPP_
#define _TAO_CDR_OP_PortableInterceptor_ObjectReferenceTemplateSeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const PortableInterceptor::ObjectReferenceTemplateSeq &_tao_sequence
  )
{
  return TAO::marshal_sequence(strm, _tao_sequence);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    PortableInterceptor::ObjectReferenceTemplateSeq &_tao_sequence
  )
{
  return TAO::demarshal_sequence(strm, _tao_sequence);
}

#endif /* _TAO_CDR_OP_PortableInterceptor_ObjectReferenceTemplateSeq_CPP_ */

TAO_END_VERSIONED_NAMESPACE_DECL
