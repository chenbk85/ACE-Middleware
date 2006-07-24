// -*- C++ -*-
//
// $Id$
//

#include "Client_ORBInitializer.h"

ACE_RCSID (Bug_2088, Client_ORBInitializer, "$Id$")

Client_ORBInitializer::Client_ORBInitializer (void) :
  pre_init_called (false),
  post_init_called (false)
{
}

void
Client_ORBInitializer::pre_init (
    PortableInterceptor::ORBInitInfo_ptr
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  pre_init_called = true;

  ACE_THROW (CORBA::NO_MEMORY ());
}

void
Client_ORBInitializer::post_init (
    PortableInterceptor::ORBInitInfo_ptr
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  post_init_called = true;

  ACE_THROW (CORBA::NO_MEMORY ());
}

