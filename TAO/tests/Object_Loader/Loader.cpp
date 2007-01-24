// $Id$

#include "Loader.h"
#include "Test_i.h"

ACE_RCSID(Object_Loader, Loader, "$Id$")

Loader::Loader (void)
{
}

CORBA::Object_ptr
Loader::create_object (CORBA::ORB_ptr orb,
                       int,
                       char * []
                       ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_TRY
    {
      CORBA::Object_var obj =
        orb->resolve_initial_references ("RootPOA" ACE_ENV_ARG_PARAMETER);

      PortableServer::POA_var poa =
        PortableServer::POA::_narrow (obj.in () ACE_ENV_ARG_PARAMETER);

      PortableServer::POAManager_var mgr =
        poa->the_POAManager ();

      mgr->activate ();

      Test_i *test;
      ACE_NEW_RETURN (test, Test_i (poa.in ()),
                      CORBA::Object::_nil ());

      PortableServer::ServantBase_var tmp = test;
      obj = test->_this ();

      return obj._retn ();
    }
  ACE_CATCHANY
    {
    }
  ACE_ENDTRY;
  return CORBA::Object::_nil ();
}

// ****************************************************************

#if 0
ACE_STATIC_SVC_DEFINE (Loader,
                       ACE_TEXT ("TAO_Object_Loader"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (Loader),
                       ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
                       0)
#endif /* 0 */

ACE_FACTORY_DEFINE (OLT, Loader)
