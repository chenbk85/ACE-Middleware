/**
 * @file RIR_Narrow.cpp
 *
 * $Id$
 *
 * @author Carlos O'Ryan <coryan@atdesk.com>
 */
#ifndef RIR_Narrow__cpp_
#define RIR_Narrow__cpp_

#include "RIR_Narrow.h"
#include <stdexcept>

template<class T> TAO::Utils::RIR_Narrow<T>::_ptr_type
TAO::Utils::RIR_Narrow<T>::narrow (CORBA::ORB_ptr orb,
                                   char const * id,
                                   CORBA::Environment &ACE_TRY_ENV)
{
  CORBA::Object_var object =
    orb->resolve_initial_references (id, ACE_TRY_ENV);
  ACE_CHECK_RETURN (T::_nil ());

  return RIR_Narrow<T>::narrow_object (object.in (), ACE_TRY_ENV);
}

template<class T> TAO::Utils::RIR_Narrow<T>::_ptr_type
TAO::Utils::RIR_Narrow<T>::narrow (PortableInterceptor::ORBInitInfo_ptr info,
                                   char const * id)
{
  CORBA::Object_var object =
    info->resolve_initial_references (id);
  return RIR_Narrow<T>::narrow_object (object.in ());
}

template<class T> TAO::Utils::RIR_Narrow<T>::_ptr_type
TAO::Utils::RIR_Narrow<T>::narrow_object (CORBA::Object_ptr object,
                                          CORBA::Environment &ACE_TRY_ENV)
{
  _var_type narrowed_object = T::_narrow (object, ACE_TRY_ENV);
  ACE_CHECK_RETURN (T::_nil ());

  if (CORBA::is_nil (narrowed_object.in ()))
  {
    ACE_THROW (CORBA::INV_OBJREF ());
  }
  return narrowed_object._retn ();
}

#endif // RIR_Narrow__cpp_
