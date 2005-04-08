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


#include "ImplicitActivationPolicyC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

#if (TAO_HAS_MINIMUM_POA == 0)

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableServer::ImplicitActivationPolicy.

PortableServer::ImplicitActivationPolicy_ptr
TAO::Objref_Traits<PortableServer::ImplicitActivationPolicy>::duplicate (
    PortableServer::ImplicitActivationPolicy_ptr p
  )
{
  return PortableServer::ImplicitActivationPolicy::_duplicate (p);
}

void
TAO::Objref_Traits<PortableServer::ImplicitActivationPolicy>::release (
    PortableServer::ImplicitActivationPolicy_ptr p
  )
{
  CORBA::release (p);
}

PortableServer::ImplicitActivationPolicy_ptr
TAO::Objref_Traits<PortableServer::ImplicitActivationPolicy>::nil (void)
{
  return PortableServer::ImplicitActivationPolicy::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<PortableServer::ImplicitActivationPolicy>::marshal (
    PortableServer::ImplicitActivationPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

PortableServer::ImplicitActivationPolicy::ImplicitActivationPolicy (void)
{}

PortableServer::ImplicitActivationPolicy::~ImplicitActivationPolicy (void)
{}

void 
PortableServer::ImplicitActivationPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  ImplicitActivationPolicy *_tao_tmp_pointer =
    static_cast<ImplicitActivationPolicy *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

PortableServer::ImplicitActivationPolicy_ptr
PortableServer::ImplicitActivationPolicy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ImplicitActivationPolicy::_nil ();
    }
  
  ImplicitActivationPolicy_ptr proxy =
    dynamic_cast<ImplicitActivationPolicy_ptr> (_tao_objref);
  
  return ImplicitActivationPolicy::_duplicate (proxy);
}

PortableServer::ImplicitActivationPolicy_ptr
PortableServer::ImplicitActivationPolicy::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ImplicitActivationPolicy::_nil ();
    }
  
  ImplicitActivationPolicy_ptr proxy =
    dynamic_cast<ImplicitActivationPolicy_ptr> (_tao_objref);
  
  return ImplicitActivationPolicy::_duplicate (proxy);
}

PortableServer::ImplicitActivationPolicy_ptr
PortableServer::ImplicitActivationPolicy::_duplicate (ImplicitActivationPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
PortableServer::ImplicitActivationPolicy::_tao_release (ImplicitActivationPolicy_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
PortableServer::ImplicitActivationPolicy::_is_a (
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
          "IDL:omg.org/PortableServer/ImplicitActivationPolicy:2.3"
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

const char* PortableServer::ImplicitActivationPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableServer/ImplicitActivationPolicy:2.3";
}

CORBA::Boolean
PortableServer::ImplicitActivationPolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_enum/cdr_op_cs.cpp:51

CORBA::Boolean operator<< (TAO_OutputCDR & strm, PortableServer::ImplicitActivationPolicyValue _tao_enumerator)
{
  return strm << static_cast<CORBA::ULong> (_tao_enumerator);
}

CORBA::Boolean operator>> (TAO_InputCDR & strm, PortableServer::ImplicitActivationPolicyValue & _tao_enumerator)
{
  CORBA::ULong _tao_temp = 0;
  CORBA::Boolean const _tao_success = strm >> _tao_temp;
  
  if (_tao_success)
    {
      _tao_enumerator = static_cast<PortableServer::ImplicitActivationPolicyValue> (_tao_temp);
    }
  
  return _tao_success;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1528

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        PortableServer::ImplicitActivationPolicy
      >;

  template class
    TAO_Objref_Var_T<
        PortableServer::ImplicitActivationPolicy
      >;
  
  template class
    TAO_Objref_Out_T<
        PortableServer::ImplicitActivationPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        PortableServer::ImplicitActivationPolicy \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        PortableServer::ImplicitActivationPolicy
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        PortableServer::ImplicitActivationPolicy
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */
