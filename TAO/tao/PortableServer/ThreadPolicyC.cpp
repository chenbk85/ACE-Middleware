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
// be\be_codegen.cpp:302


#include "ThreadPolicyC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "ThreadPolicyC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:66

#if (TAO_HAS_MINIMUM_POA == 0)

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableServer::ThreadPolicy.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableServer::ThreadPolicy_ptr
TAO::Objref_Traits<PortableServer::ThreadPolicy>::duplicate (
    PortableServer::ThreadPolicy_ptr p
  )
{
  return PortableServer::ThreadPolicy::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<PortableServer::ThreadPolicy>::release (
    PortableServer::ThreadPolicy_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
PortableServer::ThreadPolicy_ptr
TAO::Objref_Traits<PortableServer::ThreadPolicy>::nil (void)
{
  return PortableServer::ThreadPolicy::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<PortableServer::ThreadPolicy>::marshal (
    PortableServer::ThreadPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

PortableServer::ThreadPolicy::ThreadPolicy (void)
{}

PortableServer::ThreadPolicy::~ThreadPolicy (void)
{}

void 
PortableServer::ThreadPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  ThreadPolicy *_tao_tmp_pointer =
    static_cast<ThreadPolicy *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

PortableServer::ThreadPolicy_ptr
PortableServer::ThreadPolicy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ThreadPolicy::_nil ();
    }
  
  ThreadPolicy_ptr proxy =
    dynamic_cast<ThreadPolicy_ptr> (_tao_objref);
  
  return ThreadPolicy::_duplicate (proxy);
}

PortableServer::ThreadPolicy_ptr
PortableServer::ThreadPolicy::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ThreadPolicy::_nil ();
    }
  
  ThreadPolicy_ptr proxy =
    dynamic_cast<ThreadPolicy_ptr> (_tao_objref);
  
  return ThreadPolicy::_duplicate (proxy);
}

PortableServer::ThreadPolicy_ptr
PortableServer::ThreadPolicy::_duplicate (ThreadPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
PortableServer::ThreadPolicy::_is_a (
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
          "IDL:omg.org/PortableServer/ThreadPolicy:2.3"
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

const char* PortableServer::ThreadPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableServer/ThreadPolicy:2.3";
}

CORBA::Boolean
PortableServer::ThreadPolicy::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_enum/cdr_op_cs.cpp:51

CORBA::Boolean operator<< (TAO_OutputCDR &strm, const PortableServer::ThreadPolicyValue &_tao_enumval)
{
  CORBA::ULong _tao_temp = _tao_enumval;
  return strm << _tao_temp;
}

CORBA::Boolean operator>> (TAO_InputCDR &strm, PortableServer::ThreadPolicyValue &_tao_enumval)
{
  CORBA::ULong _tao_temp = 0;
  CORBA::Boolean _tao_result = strm >> _tao_temp;
  
  if (_tao_result == 1)
    {
      _tao_enumval = static_cast<PortableServer::ThreadPolicyValue> (_tao_temp);
    }
  
  return _tao_result;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1509

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        PortableServer::ThreadPolicy
      >;

  template class
    TAO_Objref_Var_T<
        PortableServer::ThreadPolicy
      >;
  
  template class
    TAO_Objref_Out_T<
        PortableServer::ThreadPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        PortableServer::ThreadPolicy \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        PortableServer::ThreadPolicy
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        PortableServer::ThreadPolicy
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */
