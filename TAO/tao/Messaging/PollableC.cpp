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


#include "tao/Messaging/PollableC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"
#include "ace/OS_NS_string.h"

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CORBA::Pollable.

CORBA::Pollable_ptr
TAO::Objref_Traits<CORBA::Pollable>::duplicate (
    CORBA::Pollable_ptr p
  )
{
  return CORBA::Pollable::_duplicate (p);
}

void
TAO::Objref_Traits<CORBA::Pollable>::release (
    CORBA::Pollable_ptr p
  )
{
  CORBA::release (p);
}

CORBA::Pollable_ptr
TAO::Objref_Traits<CORBA::Pollable>::nil (void)
{
  return CORBA::Pollable::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<CORBA::Pollable>::marshal (
    CORBA::Pollable_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

CORBA::Pollable::Pollable (void)
{}

CORBA::Pollable::~Pollable (void)
{}

CORBA::Pollable_ptr
CORBA::Pollable::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return Pollable::_duplicate (
      dynamic_cast<Pollable_ptr> (_tao_objref)
    );
}

CORBA::Pollable_ptr
CORBA::Pollable::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return Pollable::_duplicate (
      dynamic_cast<Pollable_ptr> (_tao_objref)
    );
}

CORBA::Pollable_ptr
CORBA::Pollable::_duplicate (Pollable_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
CORBA::Pollable::_tao_release (Pollable_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
CORBA::Pollable::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Pollable:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* CORBA::Pollable::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/Pollable:1.0";
}

::CORBA::Boolean
CORBA::Pollable::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_Pollable (
    ::CORBA::tk_local_interface,
    "IDL:omg.org/CORBA/Pollable:1.0",
    "Pollable");
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_Pollable =
    &_tao_tc_CORBA_Pollable;
}



// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CORBA::DIIPollable.

CORBA::DIIPollable_ptr
TAO::Objref_Traits<CORBA::DIIPollable>::duplicate (
    CORBA::DIIPollable_ptr p
  )
{
  return CORBA::DIIPollable::_duplicate (p);
}

void
TAO::Objref_Traits<CORBA::DIIPollable>::release (
    CORBA::DIIPollable_ptr p
  )
{
  CORBA::release (p);
}

CORBA::DIIPollable_ptr
TAO::Objref_Traits<CORBA::DIIPollable>::nil (void)
{
  return CORBA::DIIPollable::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<CORBA::DIIPollable>::marshal (
    CORBA::DIIPollable_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

CORBA::DIIPollable::DIIPollable (void)
{}

CORBA::DIIPollable::~DIIPollable (void)
{}

CORBA::DIIPollable_ptr
CORBA::DIIPollable::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return DIIPollable::_duplicate (
      dynamic_cast<DIIPollable_ptr> (_tao_objref)
    );
}

CORBA::DIIPollable_ptr
CORBA::DIIPollable::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return DIIPollable::_duplicate (
      dynamic_cast<DIIPollable_ptr> (_tao_objref)
    );
}

CORBA::DIIPollable_ptr
CORBA::DIIPollable::_duplicate (DIIPollable_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
CORBA::DIIPollable::_tao_release (DIIPollable_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
CORBA::DIIPollable::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Pollable:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/DIIPollable:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* CORBA::DIIPollable::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/DIIPollable:1.0";
}

::CORBA::Boolean
CORBA::DIIPollable::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_DIIPollable (
    ::CORBA::tk_local_interface,
    "IDL:omg.org/CORBA/DIIPollable:1.0",
    "DIIPollable");
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_DIIPollable =
    &_tao_tc_CORBA_DIIPollable;
}



// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CORBA::PollableSet.

CORBA::PollableSet_ptr
TAO::Objref_Traits<CORBA::PollableSet>::duplicate (
    CORBA::PollableSet_ptr p
  )
{
  return CORBA::PollableSet::_duplicate (p);
}

void
TAO::Objref_Traits<CORBA::PollableSet>::release (
    CORBA::PollableSet_ptr p
  )
{
  CORBA::release (p);
}

CORBA::PollableSet_ptr
TAO::Objref_Traits<CORBA::PollableSet>::nil (void)
{
  return CORBA::PollableSet::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<CORBA::PollableSet>::marshal (
    CORBA::PollableSet_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

CORBA::PollableSet::NoPossiblePollable::NoPossiblePollable (void)
  : ::CORBA::UserException (
        "IDL:omg.org/CORBA/PollableSet/NoPossiblePollable:1.0",
        "NoPossiblePollable"
      )
{
}

CORBA::PollableSet::NoPossiblePollable::~NoPossiblePollable (void)
{
}

CORBA::PollableSet::NoPossiblePollable::NoPossiblePollable (const ::CORBA::PollableSet::NoPossiblePollable &_tao_excp)
  : ::CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

CORBA::PollableSet::NoPossiblePollable&
CORBA::PollableSet::NoPossiblePollable::operator= (const ::CORBA::PollableSet::NoPossiblePollable &_tao_excp)
{
  this->ACE_NESTED_CLASS ( ::CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void CORBA::PollableSet::NoPossiblePollable::_tao_any_destructor (void *_tao_void_pointer)
{
  NoPossiblePollable *_tao_tmp_pointer =
    static_cast<NoPossiblePollable *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

CORBA::PollableSet::NoPossiblePollable *
CORBA::PollableSet::NoPossiblePollable::_downcast ( ::CORBA::Exception *_tao_excp)
{
  return dynamic_cast<NoPossiblePollable *> (_tao_excp);
}

const CORBA::PollableSet::NoPossiblePollable *
CORBA::PollableSet::NoPossiblePollable::_downcast ( ::CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const NoPossiblePollable *> (_tao_excp);
}

::CORBA::Exception *CORBA::PollableSet::NoPossiblePollable::_alloc (void)
{
  ::CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::CORBA::PollableSet::NoPossiblePollable, 0);
  return retval;
}

::CORBA::Exception *
CORBA::PollableSet::NoPossiblePollable::_tao_duplicate (void) const
{
  ::CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::CORBA::PollableSet::NoPossiblePollable (*this),
      0
    );
  return result;
}

void CORBA::PollableSet::NoPossiblePollable::_raise (void) const
{
  TAO_RAISE (*this);
}

void CORBA::PollableSet::NoPossiblePollable::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

void CORBA::PollableSet::NoPossiblePollable::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
::CORBA::TypeCode_ptr CORBA::PollableSet::NoPossiblePollable::_tao_type (void) const
{
  return ::CORBA::PollableSet::_tc_NoPossiblePollable;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:89

static TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const * const _tao_fields_CORBA_PollableSet_NoPossiblePollable = 0;
static TAO::TypeCode::Struct<char const *,
                      ::CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_PollableSet_NoPossiblePollable (
    ::CORBA::tk_except,
    "IDL:omg.org/CORBA/PollableSet/NoPossiblePollable:1.0",
    "NoPossiblePollable",
    _tao_fields_CORBA_PollableSet_NoPossiblePollable,
    0);
  
::CORBA::TypeCode_ptr const CORBA::PollableSet::_tc_NoPossiblePollable =
  &_tao_tc_CORBA_PollableSet_NoPossiblePollable;

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

CORBA::PollableSet::UnknownPollable::UnknownPollable (void)
  : ::CORBA::UserException (
        "IDL:omg.org/CORBA/PollableSet/UnknownPollable:1.0",
        "UnknownPollable"
      )
{
}

CORBA::PollableSet::UnknownPollable::~UnknownPollable (void)
{
}

CORBA::PollableSet::UnknownPollable::UnknownPollable (const ::CORBA::PollableSet::UnknownPollable &_tao_excp)
  : ::CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

CORBA::PollableSet::UnknownPollable&
CORBA::PollableSet::UnknownPollable::operator= (const ::CORBA::PollableSet::UnknownPollable &_tao_excp)
{
  this->ACE_NESTED_CLASS ( ::CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void CORBA::PollableSet::UnknownPollable::_tao_any_destructor (void *_tao_void_pointer)
{
  UnknownPollable *_tao_tmp_pointer =
    static_cast<UnknownPollable *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

CORBA::PollableSet::UnknownPollable *
CORBA::PollableSet::UnknownPollable::_downcast ( ::CORBA::Exception *_tao_excp)
{
  return dynamic_cast<UnknownPollable *> (_tao_excp);
}

const CORBA::PollableSet::UnknownPollable *
CORBA::PollableSet::UnknownPollable::_downcast ( ::CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const UnknownPollable *> (_tao_excp);
}

::CORBA::Exception *CORBA::PollableSet::UnknownPollable::_alloc (void)
{
  ::CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::CORBA::PollableSet::UnknownPollable, 0);
  return retval;
}

::CORBA::Exception *
CORBA::PollableSet::UnknownPollable::_tao_duplicate (void) const
{
  ::CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::CORBA::PollableSet::UnknownPollable (*this),
      0
    );
  return result;
}

void CORBA::PollableSet::UnknownPollable::_raise (void) const
{
  TAO_RAISE (*this);
}

void CORBA::PollableSet::UnknownPollable::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

void CORBA::PollableSet::UnknownPollable::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
::CORBA::TypeCode_ptr CORBA::PollableSet::UnknownPollable::_tao_type (void) const
{
  return ::CORBA::PollableSet::_tc_UnknownPollable;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:89

static TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const * const _tao_fields_CORBA_PollableSet_UnknownPollable = 0;
static TAO::TypeCode::Struct<char const *,
                      ::CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_PollableSet_UnknownPollable (
    ::CORBA::tk_except,
    "IDL:omg.org/CORBA/PollableSet/UnknownPollable:1.0",
    "UnknownPollable",
    _tao_fields_CORBA_PollableSet_UnknownPollable,
    0);
  
::CORBA::TypeCode_ptr const CORBA::PollableSet::_tc_UnknownPollable =
  &_tao_tc_CORBA_PollableSet_UnknownPollable;

CORBA::PollableSet::PollableSet (void)
{}

CORBA::PollableSet::~PollableSet (void)
{}

CORBA::PollableSet_ptr
CORBA::PollableSet::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return PollableSet::_duplicate (
      dynamic_cast<PollableSet_ptr> (_tao_objref)
    );
}

CORBA::PollableSet_ptr
CORBA::PollableSet::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return PollableSet::_duplicate (
      dynamic_cast<PollableSet_ptr> (_tao_objref)
    );
}

CORBA::PollableSet_ptr
CORBA::PollableSet::_duplicate (PollableSet_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
CORBA::PollableSet::_tao_release (PollableSet_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
CORBA::PollableSet::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/PollableSet:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* CORBA::PollableSet::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/PollableSet:1.0";
}

::CORBA::Boolean
CORBA::PollableSet::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_PollableSet (
    ::CORBA::tk_local_interface,
    "IDL:omg.org/CORBA/PollableSet:1.0",
    "PollableSet");
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_PollableSet =
    &_tao_tc_CORBA_PollableSet;
}


TAO_END_VERSIONED_NAMESPACE_DECL
