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
// be/be_codegen.cpp:302


#include "Messaging_SyncScope_PolicyC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "Messaging_SyncScope_PolicyC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for Messaging::SyncScopePolicy.

Messaging::SyncScopePolicy_ptr
TAO::Objref_Traits<Messaging::SyncScopePolicy>::duplicate (
    Messaging::SyncScopePolicy_ptr p
  )
{
  return Messaging::SyncScopePolicy::_duplicate (p);
}

void
TAO::Objref_Traits<Messaging::SyncScopePolicy>::release (
    Messaging::SyncScopePolicy_ptr p
  )
{
  CORBA::release (p);
}

Messaging::SyncScopePolicy_ptr
TAO::Objref_Traits<Messaging::SyncScopePolicy>::nil (void)
{
  return Messaging::SyncScopePolicy::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<Messaging::SyncScopePolicy>::marshal (
    Messaging::SyncScopePolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

Messaging::SyncScopePolicy::SyncScopePolicy (void)
{}

Messaging::SyncScopePolicy::~SyncScopePolicy (void)
{}

void 
Messaging::SyncScopePolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  SyncScopePolicy *_tao_tmp_pointer =
    static_cast<SyncScopePolicy *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

Messaging::SyncScopePolicy_ptr
Messaging::SyncScopePolicy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return SyncScopePolicy::_nil ();
    }
  
  SyncScopePolicy_ptr proxy =
    dynamic_cast<SyncScopePolicy_ptr> (_tao_objref);
  
  return SyncScopePolicy::_duplicate (proxy);
}

Messaging::SyncScopePolicy_ptr
Messaging::SyncScopePolicy::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return SyncScopePolicy::_nil ();
    }
  
  SyncScopePolicy_ptr proxy =
    dynamic_cast<SyncScopePolicy_ptr> (_tao_objref);
  
  return SyncScopePolicy::_duplicate (proxy);
}

Messaging::SyncScopePolicy_ptr
Messaging::SyncScopePolicy::_duplicate (SyncScopePolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
Messaging::SyncScopePolicy::_tao_release (SyncScopePolicy_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
Messaging::SyncScopePolicy::_is_a (
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
          "IDL:omg.org/Messaging/SyncScopePolicy:1.0"
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

const char* Messaging::SyncScopePolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/SyncScopePolicy:1.0";
}

CORBA::Boolean
Messaging::SyncScopePolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:1528

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        Messaging::SyncScopePolicy
      >;

  template class
    TAO_Objref_Var_T<
        Messaging::SyncScopePolicy
      >;
  
  template class
    TAO_Objref_Out_T<
        Messaging::SyncScopePolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        Messaging::SyncScopePolicy \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        Messaging::SyncScopePolicy
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        Messaging::SyncScopePolicy
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
