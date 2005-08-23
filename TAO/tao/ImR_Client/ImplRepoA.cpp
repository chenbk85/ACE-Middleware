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

#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Enum_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/AnyTypeCode/Sequence_TypeCode_Static.h"
#include "tao/AnyTypeCode/String_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
#include "tao/AnyTypeCode/Recursive_Type_TypeCode.h"
#include "ImplRepoC.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"
#include "tao/AnyTypeCode/Any_Basic_Impl_T.h"

// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/struct_typecode.cpp:87

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const * const _tao_fields_ImplementationRepository_AlreadyRegistered = 0;
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_ImplementationRepository_AlreadyRegistered (
    CORBA::tk_except,
    "IDL:ImplementationRepository/AlreadyRegistered:1.0",
    "AlreadyRegistered",
    _tao_fields_ImplementationRepository_AlreadyRegistered,
    0);

namespace ImplementationRepository
{
  ::CORBA::TypeCode_ptr const _tc_AlreadyRegistered =
    &_tao_tc_ImplementationRepository_AlreadyRegistered;
}



// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/struct_typecode.cpp:87

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_ImplementationRepository_CannotActivate[] =
  {
    { "reason", &CORBA::_tc_string }

  };
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_ImplementationRepository_CannotActivate (
    CORBA::tk_except,
    "IDL:ImplementationRepository/CannotActivate:1.0",
    "CannotActivate",
    _tao_fields_ImplementationRepository_CannotActivate,
    1);

namespace ImplementationRepository
{
  ::CORBA::TypeCode_ptr const _tc_CannotActivate =
    &_tao_tc_ImplementationRepository_CannotActivate;
}



// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/struct_typecode.cpp:87

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const * const _tao_fields_ImplementationRepository_NotFound = 0;
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_ImplementationRepository_NotFound (
    CORBA::tk_except,
    "IDL:ImplementationRepository/NotFound:1.0",
    "NotFound",
    _tao_fields_ImplementationRepository_NotFound,
    0);

namespace ImplementationRepository
{
  ::CORBA::TypeCode_ptr const _tc_NotFound =
    &_tao_tc_ImplementationRepository_NotFound;
}



// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/struct_typecode.cpp:87

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_ImplementationRepository_EnvironmentVariable[] =
  {
    { "name", &CORBA::_tc_string },
    { "value", &CORBA::_tc_string }

  };
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_ImplementationRepository_EnvironmentVariable (
    CORBA::tk_struct,
    "IDL:ImplementationRepository/EnvironmentVariable:1.0",
    "EnvironmentVariable",
    _tao_fields_ImplementationRepository_EnvironmentVariable,
    2);

namespace ImplementationRepository
{
  ::CORBA::TypeCode_ptr const _tc_EnvironmentVariable =
    &_tao_tc_ImplementationRepository_EnvironmentVariable;
}



// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:31



// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_defn.cpp:937


#ifndef _TAO_TYPECODE_ImplementationRepository_EnvironmentList_GUARD
#define _TAO_TYPECODE_ImplementationRepository_EnvironmentList_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      ImplementationRepository_EnvironmentList_0 (
        CORBA::tk_sequence,
        &ImplementationRepository::_tc_EnvironmentVariable,
        0U);

    ::CORBA::TypeCode_ptr const tc_ImplementationRepository_EnvironmentList_0 =
      &ImplementationRepository_EnvironmentList_0;

  }
}


#endif /* _TAO_TYPECODE_ImplementationRepository_EnvironmentList_GUARD */

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_ImplementationRepository_EnvironmentList (
    CORBA::tk_alias,
    "IDL:ImplementationRepository/EnvironmentList:1.0",
    "EnvironmentList",
    &TAO::TypeCode::tc_ImplementationRepository_EnvironmentList_0);

namespace ImplementationRepository
{
  ::CORBA::TypeCode_ptr const _tc_EnvironmentList =
    &_tao_tc_ImplementationRepository_EnvironmentList;
}



// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/enum_typecode.cpp:34

static char const * const _tao_enumerators_ImplementationRepository_ActivationMode[] =
  {
    "NORMAL",
    "MANUAL",
    "PER_CLIENT",
    "AUTO_START"

  };

static TAO::TypeCode::Enum<char const *,
                           char const * const *,
                           TAO::Null_RefCount_Policy>
  _tao_tc_ImplementationRepository_ActivationMode (
    "IDL:ImplementationRepository/ActivationMode:1.0",
    "ActivationMode",
    _tao_enumerators_ImplementationRepository_ActivationMode,
    4);

namespace ImplementationRepository
{
  ::CORBA::TypeCode_ptr const _tc_ActivationMode =
    &_tao_tc_ImplementationRepository_ActivationMode;
}



// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/struct_typecode.cpp:87



// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_defn.cpp:937

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_ImplementationRepository_StartupOptions[] =
  {
    { "command_line", &CORBA::_tc_string },
    { "environment", &ImplementationRepository::_tc_EnvironmentList },
    { "working_directory", &CORBA::_tc_string },
    { "activation", &ImplementationRepository::_tc_ActivationMode },
    { "activator", &CORBA::_tc_string },
    { "start_limit", &CORBA::_tc_long }

  };
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_ImplementationRepository_StartupOptions (
    CORBA::tk_struct,
    "IDL:ImplementationRepository/StartupOptions:1.0",
    "StartupOptions",
    _tao_fields_ImplementationRepository_StartupOptions,
    6);

namespace ImplementationRepository
{
  ::CORBA::TypeCode_ptr const _tc_StartupOptions =
    &_tao_tc_ImplementationRepository_StartupOptions;
}



// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/struct_typecode.cpp:87

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_ImplementationRepository_ServerInformation[] =
  {
    { "server", &CORBA::_tc_string },
    { "startup", &ImplementationRepository::_tc_StartupOptions },
    { "partial_ior", &CORBA::_tc_string }

  };
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_ImplementationRepository_ServerInformation (
    CORBA::tk_struct,
    "IDL:ImplementationRepository/ServerInformation:1.0",
    "ServerInformation",
    _tao_fields_ImplementationRepository_ServerInformation,
    3);

namespace ImplementationRepository
{
  ::CORBA::TypeCode_ptr const _tc_ServerInformation =
    &_tao_tc_ImplementationRepository_ServerInformation;
}



// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:31



// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_defn.cpp:937


#ifndef _TAO_TYPECODE_ImplementationRepository_ServerInformationList_GUARD
#define _TAO_TYPECODE_ImplementationRepository_ServerInformationList_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      ImplementationRepository_ServerInformationList_0 (
        CORBA::tk_sequence,
        &ImplementationRepository::_tc_ServerInformation,
        0U);

    ::CORBA::TypeCode_ptr const tc_ImplementationRepository_ServerInformationList_0 =
      &ImplementationRepository_ServerInformationList_0;

  }
}


#endif /* _TAO_TYPECODE_ImplementationRepository_ServerInformationList_GUARD */

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_ImplementationRepository_ServerInformationList (
    CORBA::tk_alias,
    "IDL:ImplementationRepository/ServerInformationList:1.0",
    "ServerInformationList",
    &TAO::TypeCode::tc_ImplementationRepository_ServerInformationList_0);

namespace ImplementationRepository
{
  ::CORBA::TypeCode_ptr const _tc_ServerInformationList =
    &_tao_tc_ImplementationRepository_ServerInformationList;
}



// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_ImplementationRepository_ServerInformationIterator (
    CORBA::tk_objref,
    "IDL:ImplementationRepository/ServerInformationIterator:1.0",
    "ServerInformationIterator");

namespace ImplementationRepository
{
  ::CORBA::TypeCode_ptr const _tc_ServerInformationIterator =
    &_tao_tc_ImplementationRepository_ServerInformationIterator;
}



// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_ImplementationRepository_Administration (
    CORBA::tk_objref,
    "IDL:ImplementationRepository/Administration:1.0",
    "Administration");

namespace ImplementationRepository
{
  ::CORBA::TypeCode_ptr const _tc_Administration =
    &_tao_tc_ImplementationRepository_Administration;
}



// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_exception/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Dual_Impl_T<ImplementationRepository::AlreadyRegistered>::demarshal_value (
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
    const ImplementationRepository::AlreadyRegistered &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::AlreadyRegistered>::insert_copy (
      _tao_any,
      ImplementationRepository::AlreadyRegistered::_tao_any_destructor,
      ImplementationRepository::_tc_AlreadyRegistered,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    ImplementationRepository::AlreadyRegistered *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::AlreadyRegistered>::insert (
      _tao_any,
      ImplementationRepository::AlreadyRegistered::_tao_any_destructor,
      ImplementationRepository::_tc_AlreadyRegistered,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    ImplementationRepository::AlreadyRegistered *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const ImplementationRepository::AlreadyRegistered *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const ImplementationRepository::AlreadyRegistered *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<ImplementationRepository::AlreadyRegistered>::extract (
        _tao_any,
        ImplementationRepository::AlreadyRegistered::_tao_any_destructor,
        ImplementationRepository::_tc_AlreadyRegistered,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_exception/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Dual_Impl_T<ImplementationRepository::CannotActivate>::demarshal_value (
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
    const ImplementationRepository::CannotActivate &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::CannotActivate>::insert_copy (
      _tao_any,
      ImplementationRepository::CannotActivate::_tao_any_destructor,
      ImplementationRepository::_tc_CannotActivate,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    ImplementationRepository::CannotActivate *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::CannotActivate>::insert (
      _tao_any,
      ImplementationRepository::CannotActivate::_tao_any_destructor,
      ImplementationRepository::_tc_CannotActivate,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    ImplementationRepository::CannotActivate *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const ImplementationRepository::CannotActivate *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const ImplementationRepository::CannotActivate *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<ImplementationRepository::CannotActivate>::extract (
        _tao_any,
        ImplementationRepository::CannotActivate::_tao_any_destructor,
        ImplementationRepository::_tc_CannotActivate,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_exception/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Dual_Impl_T<ImplementationRepository::NotFound>::demarshal_value (
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
    const ImplementationRepository::NotFound &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::NotFound>::insert_copy (
      _tao_any,
      ImplementationRepository::NotFound::_tao_any_destructor,
      ImplementationRepository::_tc_NotFound,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    ImplementationRepository::NotFound *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::NotFound>::insert (
      _tao_any,
      ImplementationRepository::NotFound::_tao_any_destructor,
      ImplementationRepository::_tc_NotFound,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    ImplementationRepository::NotFound *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const ImplementationRepository::NotFound *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const ImplementationRepository::NotFound *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<ImplementationRepository::NotFound>::extract (
        _tao_any,
        ImplementationRepository::NotFound::_tao_any_destructor,
        ImplementationRepository::_tc_NotFound,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const ImplementationRepository::EnvironmentVariable &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::EnvironmentVariable>::insert_copy (
      _tao_any,
      ImplementationRepository::EnvironmentVariable::_tao_any_destructor,
      ImplementationRepository::_tc_EnvironmentVariable,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    ImplementationRepository::EnvironmentVariable *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::EnvironmentVariable>::insert (
      _tao_any,
      ImplementationRepository::EnvironmentVariable::_tao_any_destructor,
      ImplementationRepository::_tc_EnvironmentVariable,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    ImplementationRepository::EnvironmentVariable *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const ImplementationRepository::EnvironmentVariable *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const ImplementationRepository::EnvironmentVariable *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<ImplementationRepository::EnvironmentVariable>::extract (
        _tao_any,
        ImplementationRepository::EnvironmentVariable::_tao_any_destructor,
        ImplementationRepository::_tc_EnvironmentVariable,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/any_op_cs.cpp:54


// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const ImplementationRepository::EnvironmentList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::EnvironmentList>::insert_copy (
      _tao_any,
      ImplementationRepository::EnvironmentList::_tao_any_destructor,
      TAO::TypeCode::tc_ImplementationRepository_EnvironmentList_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    ImplementationRepository::EnvironmentList *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::EnvironmentList>::insert (
      _tao_any,
      ImplementationRepository::EnvironmentList::_tao_any_destructor,
      TAO::TypeCode::tc_ImplementationRepository_EnvironmentList_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    ImplementationRepository::EnvironmentList *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const ImplementationRepository::EnvironmentList *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const ImplementationRepository::EnvironmentList *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<ImplementationRepository::EnvironmentList>::extract (
        _tao_any,
        ImplementationRepository::EnvironmentList::_tao_any_destructor,
        TAO::TypeCode::tc_ImplementationRepository_EnvironmentList_0,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_enum/any_op_cs.cpp:52

void operator<<= (
    CORBA::Any &_tao_any,
    ImplementationRepository::ActivationMode _tao_elem
  )
{
  TAO::Any_Basic_Impl_T<ImplementationRepository::ActivationMode>::insert (
      _tao_any,
      ImplementationRepository::_tc_ActivationMode,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    ImplementationRepository::ActivationMode &_tao_elem
  )
{
  return
    TAO::Any_Basic_Impl_T<ImplementationRepository::ActivationMode>::extract (
        _tao_any,
        ImplementationRepository::_tc_ActivationMode,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const ImplementationRepository::StartupOptions &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::StartupOptions>::insert_copy (
      _tao_any,
      ImplementationRepository::StartupOptions::_tao_any_destructor,
      ImplementationRepository::_tc_StartupOptions,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    ImplementationRepository::StartupOptions *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::StartupOptions>::insert (
      _tao_any,
      ImplementationRepository::StartupOptions::_tao_any_destructor,
      ImplementationRepository::_tc_StartupOptions,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    ImplementationRepository::StartupOptions *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const ImplementationRepository::StartupOptions *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const ImplementationRepository::StartupOptions *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<ImplementationRepository::StartupOptions>::extract (
        _tao_any,
        ImplementationRepository::StartupOptions::_tao_any_destructor,
        ImplementationRepository::_tc_StartupOptions,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const ImplementationRepository::ServerInformation &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::ServerInformation>::insert_copy (
      _tao_any,
      ImplementationRepository::ServerInformation::_tao_any_destructor,
      ImplementationRepository::_tc_ServerInformation,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    ImplementationRepository::ServerInformation *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::ServerInformation>::insert (
      _tao_any,
      ImplementationRepository::ServerInformation::_tao_any_destructor,
      ImplementationRepository::_tc_ServerInformation,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    ImplementationRepository::ServerInformation *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const ImplementationRepository::ServerInformation *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const ImplementationRepository::ServerInformation *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<ImplementationRepository::ServerInformation>::extract (
        _tao_any,
        ImplementationRepository::ServerInformation::_tao_any_destructor,
        ImplementationRepository::_tc_ServerInformation,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/any_op_cs.cpp:54


// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const ImplementationRepository::ServerInformationList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::ServerInformationList>::insert_copy (
      _tao_any,
      ImplementationRepository::ServerInformationList::_tao_any_destructor,
      TAO::TypeCode::tc_ImplementationRepository_ServerInformationList_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    ImplementationRepository::ServerInformationList *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<ImplementationRepository::ServerInformationList>::insert (
      _tao_any,
      ImplementationRepository::ServerInformationList::_tao_any_destructor,
      TAO::TypeCode::tc_ImplementationRepository_ServerInformationList_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    ImplementationRepository::ServerInformationList *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const ImplementationRepository::ServerInformationList *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const ImplementationRepository::ServerInformationList *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<ImplementationRepository::ServerInformationList>::extract (
        _tao_any,
        ImplementationRepository::ServerInformationList::_tao_any_destructor,
        TAO::TypeCode::tc_ImplementationRepository_ServerInformationList_0,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<ImplementationRepository::ServerInformationIterator>::to_object (
      CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = CORBA::Object::_duplicate (this->value_);
    return true;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    ImplementationRepository::ServerInformationIterator_ptr _tao_elem
  )
{
  ImplementationRepository::ServerInformationIterator_ptr _tao_objptr =
    ImplementationRepository::ServerInformationIterator::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    ImplementationRepository::ServerInformationIterator_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<ImplementationRepository::ServerInformationIterator>::insert (
      _tao_any,
      ImplementationRepository::ServerInformationIterator::_tao_any_destructor,
      ImplementationRepository::_tc_ServerInformationIterator,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    ImplementationRepository::ServerInformationIterator_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<ImplementationRepository::ServerInformationIterator>::extract (
        _tao_any,
        ImplementationRepository::ServerInformationIterator::_tao_any_destructor,
        ImplementationRepository::_tc_ServerInformationIterator,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<ImplementationRepository::Administration>::to_object (
      CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = CORBA::Object::_duplicate (this->value_);
    return true;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    ImplementationRepository::Administration_ptr _tao_elem
  )
{
  ImplementationRepository::Administration_ptr _tao_objptr =
    ImplementationRepository::Administration::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    ImplementationRepository::Administration_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<ImplementationRepository::Administration>::insert (
      _tao_any,
      ImplementationRepository::Administration::_tao_any_destructor,
      ImplementationRepository::_tc_Administration,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    ImplementationRepository::Administration_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<ImplementationRepository::Administration>::extract (
        _tao_any,
        ImplementationRepository::Administration::_tao_any_destructor,
        ImplementationRepository::_tc_Administration,
        _tao_elem
      );
}
