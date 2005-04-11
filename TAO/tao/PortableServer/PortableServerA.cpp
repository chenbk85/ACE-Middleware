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

#include "PortableServer.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/Objref_TypeCode.h"
#include "tao/Sequence_TypeCode.h"
#include "tao/String_TypeCode.h"
#include "tao/Struct_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:31



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:925

namespace PortableServer
{
  extern ::CORBA::TypeCode_ptr const _tc_POA;
}


#ifndef _TAO_TYPECODE_PortableServer_POAList_GUARD
#define _TAO_TYPECODE_PortableServer_POAList_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      PortableServer_POAList_0 (
        CORBA::tk_sequence,
        &PortableServer::_tc_POA,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_PortableServer_POAList_0 =
      &PortableServer_POAList_0;
    
  }
}


#endif /* _TAO_TYPECODE_PortableServer_POAList_GUARD */
static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            CORBA::tk_alias,
                            TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_POAList (
    "IDL:omg.org/PortableServer/POAList:1.0",
    "POAList",
    &TAO::TypeCode::tc_PortableServer_POAList_0);
  
namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_POAList =
    &_tao_tc_PortableServer_POAList;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:70

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const * const _tao_fields_PortableServer_POA_AdapterAlreadyExists = 0;
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_POA_AdapterAlreadyExists (
    CORBA::tk_except,
    "IDL:omg.org/PortableServer/POA/AdapterAlreadyExists:2.3",
    "AdapterAlreadyExists",
    _tao_fields_PortableServer_POA_AdapterAlreadyExists,
    0);
  
::CORBA::TypeCode_ptr const PortableServer::POA::_tc_AdapterAlreadyExists =
  &_tao_tc_PortableServer_POA_AdapterAlreadyExists;

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:70

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const * const _tao_fields_PortableServer_POA_AdapterNonExistent = 0;
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_POA_AdapterNonExistent (
    CORBA::tk_except,
    "IDL:omg.org/PortableServer/POA/AdapterNonExistent:2.3",
    "AdapterNonExistent",
    _tao_fields_PortableServer_POA_AdapterNonExistent,
    0);
  
::CORBA::TypeCode_ptr const PortableServer::POA::_tc_AdapterNonExistent =
  &_tao_tc_PortableServer_POA_AdapterNonExistent;

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:70

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_PortableServer_POA_InvalidPolicy[] =
  {
    { "index", &CORBA::_tc_ushort }
    
  };
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_POA_InvalidPolicy (
    CORBA::tk_except,
    "IDL:omg.org/PortableServer/POA/InvalidPolicy:2.3",
    "InvalidPolicy",
    _tao_fields_PortableServer_POA_InvalidPolicy,
    1);
  
::CORBA::TypeCode_ptr const PortableServer::POA::_tc_InvalidPolicy =
  &_tao_tc_PortableServer_POA_InvalidPolicy;

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:70

#if (TAO_HAS_MINIMUM_POA == 0)

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const * const _tao_fields_PortableServer_POA_NoServant = 0;
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_POA_NoServant (
    CORBA::tk_except,
    "IDL:omg.org/PortableServer/POA/NoServant:2.3",
    "NoServant",
    _tao_fields_PortableServer_POA_NoServant,
    0);
  
::CORBA::TypeCode_ptr const PortableServer::POA::_tc_NoServant =
  &_tao_tc_PortableServer_POA_NoServant;

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:70

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const * const _tao_fields_PortableServer_POA_ObjectAlreadyActive = 0;
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_POA_ObjectAlreadyActive (
    CORBA::tk_except,
    "IDL:omg.org/PortableServer/POA/ObjectAlreadyActive:2.3",
    "ObjectAlreadyActive",
    _tao_fields_PortableServer_POA_ObjectAlreadyActive,
    0);
  
::CORBA::TypeCode_ptr const PortableServer::POA::_tc_ObjectAlreadyActive =
  &_tao_tc_PortableServer_POA_ObjectAlreadyActive;

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:70

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const * const _tao_fields_PortableServer_POA_ObjectNotActive = 0;
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_POA_ObjectNotActive (
    CORBA::tk_except,
    "IDL:omg.org/PortableServer/POA/ObjectNotActive:2.3",
    "ObjectNotActive",
    _tao_fields_PortableServer_POA_ObjectNotActive,
    0);
  
::CORBA::TypeCode_ptr const PortableServer::POA::_tc_ObjectNotActive =
  &_tao_tc_PortableServer_POA_ObjectNotActive;

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:70

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const * const _tao_fields_PortableServer_POA_ServantAlreadyActive = 0;
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_POA_ServantAlreadyActive (
    CORBA::tk_except,
    "IDL:omg.org/PortableServer/POA/ServantAlreadyActive:2.3",
    "ServantAlreadyActive",
    _tao_fields_PortableServer_POA_ServantAlreadyActive,
    0);
  
::CORBA::TypeCode_ptr const PortableServer::POA::_tc_ServantAlreadyActive =
  &_tao_tc_PortableServer_POA_ServantAlreadyActive;

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:70

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const * const _tao_fields_PortableServer_POA_ServantNotActive = 0;
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_POA_ServantNotActive (
    CORBA::tk_except,
    "IDL:omg.org/PortableServer/POA/ServantNotActive:2.3",
    "ServantNotActive",
    _tao_fields_PortableServer_POA_ServantNotActive,
    0);
  
::CORBA::TypeCode_ptr const PortableServer::POA::_tc_ServantNotActive =
  &_tao_tc_PortableServer_POA_ServantNotActive;

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:70

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const * const _tao_fields_PortableServer_POA_WrongAdapter = 0;
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_POA_WrongAdapter (
    CORBA::tk_except,
    "IDL:omg.org/PortableServer/POA/WrongAdapter:2.3",
    "WrongAdapter",
    _tao_fields_PortableServer_POA_WrongAdapter,
    0);
  
::CORBA::TypeCode_ptr const PortableServer::POA::_tc_WrongAdapter =
  &_tao_tc_PortableServer_POA_WrongAdapter;

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:70

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const * const _tao_fields_PortableServer_POA_WrongPolicy = 0;
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_POA_WrongPolicy (
    CORBA::tk_except,
    "IDL:omg.org/PortableServer/POA/WrongPolicy:2.3",
    "WrongPolicy",
    _tao_fields_PortableServer_POA_WrongPolicy,
    0);
  
::CORBA::TypeCode_ptr const PortableServer::POA::_tc_WrongPolicy =
  &_tao_tc_PortableServer_POA_WrongPolicy;

// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_POA (
    "IDL:omg.org/PortableServer/POA:2.3",
    "POA");
  
namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_POA =
    &_tao_tc_PortableServer_POA;
}



// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54



template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POAList>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POAList>::demarshal_value (TAO_InputCDR &)
{
  return false;
}// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POAList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POAList>::insert_copy (
      _tao_any,
      PortableServer::POAList::_tao_any_destructor,
      TAO::TypeCode::tc_PortableServer_POAList_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POAList *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POAList>::insert (
      _tao_any,
      PortableServer::POAList::_tao_any_destructor,
      TAO::TypeCode::tc_PortableServer_POAList_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POAList *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POAList *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POAList *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POAList>::extract (
        _tao_any,
        PortableServer::POAList::_tao_any_destructor,
        TAO::TypeCode::tc_PortableServer_POAList_0,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::POA>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return true;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::POA>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::POA>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA_ptr _tao_elem
  )
{
  PortableServer::POA_ptr _tao_objptr =
    PortableServer::POA::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::POA>::insert (
      _tao_any,
      PortableServer::POA::_tao_any_destructor,
      PortableServer::_tc_POA,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::POA>::extract (
        _tao_any,
        PortableServer::POA::_tao_any_destructor,
        PortableServer::_tc_POA,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterAlreadyExists>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterAlreadyExists>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::AdapterAlreadyExists &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterAlreadyExists>::insert_copy (
      _tao_any,
      PortableServer::POA::AdapterAlreadyExists::_tao_any_destructor,
      PortableServer::POA::_tc_AdapterAlreadyExists,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::AdapterAlreadyExists *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterAlreadyExists>::insert (
      _tao_any,
      PortableServer::POA::AdapterAlreadyExists::_tao_any_destructor,
      PortableServer::POA::_tc_AdapterAlreadyExists,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::AdapterAlreadyExists *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::AdapterAlreadyExists *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::AdapterAlreadyExists *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterAlreadyExists>::extract (
        _tao_any,
        PortableServer::POA::AdapterAlreadyExists::_tao_any_destructor,
        PortableServer::POA::_tc_AdapterAlreadyExists,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterNonExistent>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterNonExistent>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::AdapterNonExistent &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterNonExistent>::insert_copy (
      _tao_any,
      PortableServer::POA::AdapterNonExistent::_tao_any_destructor,
      PortableServer::POA::_tc_AdapterNonExistent,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::AdapterNonExistent *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterNonExistent>::insert (
      _tao_any,
      PortableServer::POA::AdapterNonExistent::_tao_any_destructor,
      PortableServer::POA::_tc_AdapterNonExistent,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::AdapterNonExistent *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::AdapterNonExistent *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::AdapterNonExistent *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterNonExistent>::extract (
        _tao_any,
        PortableServer::POA::AdapterNonExistent::_tao_any_destructor,
        PortableServer::POA::_tc_AdapterNonExistent,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::InvalidPolicy>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::InvalidPolicy>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::InvalidPolicy &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::InvalidPolicy>::insert_copy (
      _tao_any,
      PortableServer::POA::InvalidPolicy::_tao_any_destructor,
      PortableServer::POA::_tc_InvalidPolicy,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::InvalidPolicy *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::InvalidPolicy>::insert (
      _tao_any,
      PortableServer::POA::InvalidPolicy::_tao_any_destructor,
      PortableServer::POA::_tc_InvalidPolicy,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::InvalidPolicy *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::InvalidPolicy *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::InvalidPolicy *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::InvalidPolicy>::extract (
        _tao_any,
        PortableServer::POA::InvalidPolicy::_tao_any_destructor,
        PortableServer::POA::_tc_InvalidPolicy,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

#if (TAO_HAS_MINIMUM_POA == 0)

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::NoServant>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::NoServant>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::NoServant &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::NoServant>::insert_copy (
      _tao_any,
      PortableServer::POA::NoServant::_tao_any_destructor,
      PortableServer::POA::_tc_NoServant,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::NoServant *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::NoServant>::insert (
      _tao_any,
      PortableServer::POA::NoServant::_tao_any_destructor,
      PortableServer::POA::_tc_NoServant,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::NoServant *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::NoServant *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::NoServant *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::NoServant>::extract (
        _tao_any,
        PortableServer::POA::NoServant::_tao_any_destructor,
        PortableServer::POA::_tc_NoServant,
        _tao_elem
      );
}

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectAlreadyActive>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectAlreadyActive>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::ObjectAlreadyActive &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectAlreadyActive>::insert_copy (
      _tao_any,
      PortableServer::POA::ObjectAlreadyActive::_tao_any_destructor,
      PortableServer::POA::_tc_ObjectAlreadyActive,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::ObjectAlreadyActive *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectAlreadyActive>::insert (
      _tao_any,
      PortableServer::POA::ObjectAlreadyActive::_tao_any_destructor,
      PortableServer::POA::_tc_ObjectAlreadyActive,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::ObjectAlreadyActive *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::ObjectAlreadyActive *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::ObjectAlreadyActive *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectAlreadyActive>::extract (
        _tao_any,
        PortableServer::POA::ObjectAlreadyActive::_tao_any_destructor,
        PortableServer::POA::_tc_ObjectAlreadyActive,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectNotActive>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectNotActive>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::ObjectNotActive &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectNotActive>::insert_copy (
      _tao_any,
      PortableServer::POA::ObjectNotActive::_tao_any_destructor,
      PortableServer::POA::_tc_ObjectNotActive,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::ObjectNotActive *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectNotActive>::insert (
      _tao_any,
      PortableServer::POA::ObjectNotActive::_tao_any_destructor,
      PortableServer::POA::_tc_ObjectNotActive,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::ObjectNotActive *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::ObjectNotActive *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::ObjectNotActive *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectNotActive>::extract (
        _tao_any,
        PortableServer::POA::ObjectNotActive::_tao_any_destructor,
        PortableServer::POA::_tc_ObjectNotActive,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ServantAlreadyActive>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ServantAlreadyActive>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::ServantAlreadyActive &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ServantAlreadyActive>::insert_copy (
      _tao_any,
      PortableServer::POA::ServantAlreadyActive::_tao_any_destructor,
      PortableServer::POA::_tc_ServantAlreadyActive,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::ServantAlreadyActive *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ServantAlreadyActive>::insert (
      _tao_any,
      PortableServer::POA::ServantAlreadyActive::_tao_any_destructor,
      PortableServer::POA::_tc_ServantAlreadyActive,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::ServantAlreadyActive *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::ServantAlreadyActive *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::ServantAlreadyActive *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::ServantAlreadyActive>::extract (
        _tao_any,
        PortableServer::POA::ServantAlreadyActive::_tao_any_destructor,
        PortableServer::POA::_tc_ServantAlreadyActive,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ServantNotActive>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ServantNotActive>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::ServantNotActive &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ServantNotActive>::insert_copy (
      _tao_any,
      PortableServer::POA::ServantNotActive::_tao_any_destructor,
      PortableServer::POA::_tc_ServantNotActive,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::ServantNotActive *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ServantNotActive>::insert (
      _tao_any,
      PortableServer::POA::ServantNotActive::_tao_any_destructor,
      PortableServer::POA::_tc_ServantNotActive,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::ServantNotActive *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::ServantNotActive *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::ServantNotActive *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::ServantNotActive>::extract (
        _tao_any,
        PortableServer::POA::ServantNotActive::_tao_any_destructor,
        PortableServer::POA::_tc_ServantNotActive,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::WrongAdapter>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::WrongAdapter>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::WrongAdapter &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::WrongAdapter>::insert_copy (
      _tao_any,
      PortableServer::POA::WrongAdapter::_tao_any_destructor,
      PortableServer::POA::_tc_WrongAdapter,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::WrongAdapter *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::WrongAdapter>::insert (
      _tao_any,
      PortableServer::POA::WrongAdapter::_tao_any_destructor,
      PortableServer::POA::_tc_WrongAdapter,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::WrongAdapter *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::WrongAdapter *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::WrongAdapter *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::WrongAdapter>::extract (
        _tao_any,
        PortableServer::POA::WrongAdapter::_tao_any_destructor,
        PortableServer::POA::_tc_WrongAdapter,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::WrongPolicy>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::WrongPolicy>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::WrongPolicy &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::WrongPolicy>::insert_copy (
      _tao_any,
      PortableServer::POA::WrongPolicy::_tao_any_destructor,
      PortableServer::POA::_tc_WrongPolicy,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::WrongPolicy *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::WrongPolicy>::insert (
      _tao_any,
      PortableServer::POA::WrongPolicy::_tao_any_destructor,
      PortableServer::POA::_tc_WrongPolicy,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::WrongPolicy *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::WrongPolicy *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::WrongPolicy *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::WrongPolicy>::extract (
        _tao_any,
        PortableServer::POA::WrongPolicy::_tao_any_destructor,
        PortableServer::POA::_tc_WrongPolicy,
        _tao_elem
      );
}
