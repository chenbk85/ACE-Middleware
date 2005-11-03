// =================================================================
/**
 * @file CodecFactory.cpp
 *
 * $Id$
 *
 * @author Johnny Willemsen  <jwillemsen@remedy.nl>
 */
// =================================================================

#include "CodecFactory.h"
#include "CodecFactory_impl.h"

#include "tao/ORB.h"
#include "tao/debug.h"

ACE_RCSID (CodecFactory,
           CodecFactory,
           "$Id$")

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

CORBA::Object_ptr
TAO_CodecFactory_Loader::create_object (
  CORBA::ORB_ptr orb,
  int,
  ACE_TCHAR *[]
  ACE_ENV_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Object_ptr obj = CORBA::Object::_nil ();
  ACE_NEW_RETURN (obj,
                  TAO_CodecFactory (orb->orb_core ()),
                  CORBA::Object::_nil ());
  return obj;
}

int
TAO_CodecFactory_Loader::Initializer (void)
{
  return ACE_Service_Config::process_directive (ace_svc_desc_TAO_CodecFactory_Loader);
}

TAO_END_VERSIONED_NAMESPACE_DECL

ACE_STATIC_SVC_DEFINE (TAO_CodecFactory_Loader,
                       ACE_TEXT ("CodecFactory_Loader"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (TAO_CodecFactory_Loader),
                       ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
                       0)
ACE_FACTORY_DEFINE (TAO_CodecFactory, TAO_CodecFactory_Loader)
