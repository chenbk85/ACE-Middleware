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


#include "ServantManagerC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "ServantManagerC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{
}

#if (TAO_HAS_MINIMUM_POA == 0)

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableServer::ServantManager.

PortableServer::ServantManager_ptr
TAO::Objref_Traits<PortableServer::ServantManager>::duplicate (
    PortableServer::ServantManager_ptr p
  )
{
  return PortableServer::ServantManager::_duplicate (p);
}

void
TAO::Objref_Traits<PortableServer::ServantManager>::release (
    PortableServer::ServantManager_ptr p
  )
{
  CORBA::release (p);
}

PortableServer::ServantManager_ptr
TAO::Objref_Traits<PortableServer::ServantManager>::nil (void)
{
  return PortableServer::ServantManager::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<PortableServer::ServantManager>::marshal (
    PortableServer::ServantManager_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

PortableServer::ServantManager::ServantManager (void)
{}

PortableServer::ServantManager::~ServantManager (void)
{}

void 
PortableServer::ServantManager::_tao_any_destructor (void *_tao_void_pointer)
{
  ServantManager *_tao_tmp_pointer =
    static_cast<ServantManager *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

PortableServer::ServantManager_ptr
PortableServer::ServantManager::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ServantManager::_nil ();
    }
  
  ServantManager_ptr proxy =
    dynamic_cast<ServantManager_ptr> (_tao_objref);
  
  return ServantManager::_duplicate (proxy);
}

PortableServer::ServantManager_ptr
PortableServer::ServantManager::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ServantManager::_nil ();
    }
  
  ServantManager_ptr proxy =
    dynamic_cast<ServantManager_ptr> (_tao_objref);
  
  return ServantManager::_duplicate (proxy);
}

PortableServer::ServantManager_ptr
PortableServer::ServantManager::_duplicate (ServantManager_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
PortableServer::ServantManager::_tao_release (ServantManager_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
PortableServer::ServantManager::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableServer/ServantManager:2.3"
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

const char* PortableServer::ServantManager::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableServer/ServantManager:2.3";
}

CORBA::Boolean
PortableServer::ServantManager::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1619

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        PortableServer::ServantManager
      >;

  template class
    TAO_Objref_Var_T<
        PortableServer::ServantManager
      >;
  
  template class
    TAO_Objref_Out_T<
        PortableServer::ServantManager
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        PortableServer::ServantManager \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        PortableServer::ServantManager
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        PortableServer::ServantManager
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */
