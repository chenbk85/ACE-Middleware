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
// be/be_codegen.cpp:292


#include "tao/PI/ProcessingModePolicyC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "ace/OS_NS_string.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:70

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be/be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ProcessingMode (
    ::CORBA::tk_alias,
    "IDL:PortableInterceptor/ProcessingMode:1.0",
    "ProcessingMode",
    &CORBA::_tc_short);
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ProcessingMode =
    &_tao_tc_PortableInterceptor_ProcessingMode;
}



// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableInterceptor::ProcessingModePolicy.

PortableInterceptor::ProcessingModePolicy_ptr
TAO::Objref_Traits<PortableInterceptor::ProcessingModePolicy>::duplicate (
    PortableInterceptor::ProcessingModePolicy_ptr p
  )
{
  return PortableInterceptor::ProcessingModePolicy::_duplicate (p);
}

void
TAO::Objref_Traits<PortableInterceptor::ProcessingModePolicy>::release (
    PortableInterceptor::ProcessingModePolicy_ptr p
  )
{
  CORBA::release (p);
}

PortableInterceptor::ProcessingModePolicy_ptr
TAO::Objref_Traits<PortableInterceptor::ProcessingModePolicy>::nil (void)
{
  return PortableInterceptor::ProcessingModePolicy::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<PortableInterceptor::ProcessingModePolicy>::marshal (
    const PortableInterceptor::ProcessingModePolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

PortableInterceptor::ProcessingModePolicy::ProcessingModePolicy (void)
{}

PortableInterceptor::ProcessingModePolicy::~ProcessingModePolicy (void)
{}

PortableInterceptor::ProcessingModePolicy_ptr
PortableInterceptor::ProcessingModePolicy::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ProcessingModePolicy::_duplicate (
      dynamic_cast<ProcessingModePolicy_ptr> (_tao_objref)
    );
}

PortableInterceptor::ProcessingModePolicy_ptr
PortableInterceptor::ProcessingModePolicy::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ProcessingModePolicy::_duplicate (
      dynamic_cast<ProcessingModePolicy_ptr> (_tao_objref)
    );
}

PortableInterceptor::ProcessingModePolicy_ptr
PortableInterceptor::ProcessingModePolicy::_duplicate (ProcessingModePolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
PortableInterceptor::ProcessingModePolicy::_tao_release (ProcessingModePolicy_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
PortableInterceptor::ProcessingModePolicy::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Policy:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:PortableInterceptor/ProcessingModePolicy:1.0"
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

const char* PortableInterceptor::ProcessingModePolicy::_interface_repository_id (void) const
{
  return "IDL:PortableInterceptor/ProcessingModePolicy:1.0";
}

::CORBA::Boolean
PortableInterceptor::ProcessingModePolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ProcessingModePolicy (
    ::CORBA::tk_local_interface,
    "IDL:PortableInterceptor/ProcessingModePolicy:1.0",
    "ProcessingModePolicy");
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ProcessingModePolicy =
    &_tao_tc_PortableInterceptor_ProcessingModePolicy;
}




TAO_END_VERSIONED_NAMESPACE_DECL


