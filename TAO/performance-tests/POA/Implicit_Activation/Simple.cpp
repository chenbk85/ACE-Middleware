//
// $Id$
//
#include "Simple.h"

ACE_RCSID(Activation, Simple, "$Id$")

Simple::Simple (void)
{
}

void
Simple::destroy (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  PortableServer::POA_var poa = this->_default_POA (TAO_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  PortableServer::ObjectId_var oid =
    poa->servant_to_id (this TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;

  poa->deactivate_object (oid.in () TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;
}
