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

#include "DomainC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/Objref_TypeCode.h"
#include "tao/Sequence_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_objref,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_DomainManager (
    "IDL:omg.org/CORBA/DomainManager:1.0",
    "DomainManager");
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_DomainManager =
    &_tao_tc_CORBA_DomainManager;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_objref,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ConstructionPolicy (
    "IDL:omg.org/CORBA/ConstructionPolicy:1.0",
    "ConstructionPolicy");
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ConstructionPolicy =
    &_tao_tc_CORBA_ConstructionPolicy;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:31



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:925


#ifndef _TAO_TYPECODE_CORBA_DomainManagerList_GUARD
#define _TAO_TYPECODE_CORBA_DomainManagerList_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence<::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      CORBA_DomainManagerList_0 (
        CORBA::tk_sequence,
        &CORBA::_tc_DomainManager,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_CORBA_DomainManagerList_0 =
      &CORBA_DomainManagerList_0;
    
  }
}


#endif /* _TAO_TYPECODE_CORBA_DomainManagerList_GUARD */
static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            CORBA::tk_alias,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_DomainManagerList (
    "IDL:omg.org/CORBA/DomainManagerList:1.0",
    "DomainManagerList",
    &TAO::TypeCode::tc_CORBA_DomainManagerList_0);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_DomainManagerList =
    &_tao_tc_CORBA_DomainManagerList;
}



// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<CORBA::DomainManager>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return true;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::DomainManager_ptr _tao_elem
  )
{
  CORBA::DomainManager_ptr _tao_objptr =
    CORBA::DomainManager::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::DomainManager_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::DomainManager>::insert (
      _tao_any,
      CORBA::DomainManager::_tao_any_destructor,
      CORBA::_tc_DomainManager,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::DomainManager_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::DomainManager>::extract (
        _tao_any,
        CORBA::DomainManager::_tao_any_destructor,
        CORBA::_tc_DomainManager,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<CORBA::ConstructionPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return true;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ConstructionPolicy_ptr _tao_elem
  )
{
  CORBA::ConstructionPolicy_ptr _tao_objptr =
    CORBA::ConstructionPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ConstructionPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::ConstructionPolicy>::insert (
      _tao_any,
      CORBA::ConstructionPolicy::_tao_any_destructor,
      CORBA::_tc_ConstructionPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ConstructionPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::ConstructionPolicy>::extract (
        _tao_any,
        CORBA::ConstructionPolicy::_tao_any_destructor,
        CORBA::_tc_ConstructionPolicy,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::DomainManagerList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::DomainManagerList>::insert_copy (
      _tao_any,
      CORBA::DomainManagerList::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_DomainManagerList_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::DomainManagerList *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::DomainManagerList>::insert (
      _tao_any,
      CORBA::DomainManagerList::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_DomainManagerList_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::DomainManagerList *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::DomainManagerList *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::DomainManagerList *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::DomainManagerList>::extract (
        _tao_any,
        CORBA::DomainManagerList::_tao_any_destructor,
        TAO::TypeCode::tc_CORBA_DomainManagerList_0,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Impl_T<
        CORBA::DomainManager
      >;

  template class
    TAO::Any_Impl_T<
        CORBA::ConstructionPolicy
      >;

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::DomainManagerList
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Impl_T< \
        CORBA::DomainManager \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        CORBA::ConstructionPolicy \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::DomainManagerList \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
