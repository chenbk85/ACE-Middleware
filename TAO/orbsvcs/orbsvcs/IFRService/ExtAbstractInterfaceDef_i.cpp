/* -*- C++ -*- */
// $Id$

#include "ExtAbstractInterfaceDef_i.h"
#include "Repository_i.h"

ACE_RCSID (IFRService, 
           ExtAbstractInterfaceDef_i, 
           "$Id$")

TAO_ExtAbstractInterfaceDef_i::TAO_ExtAbstractInterfaceDef_i (
    TAO_Repository_i *repo
  )
  : TAO_IRObject_i (repo),
    TAO_Container_i (repo),
    TAO_Contained_i (repo),
    TAO_IDLType_i (repo),
    TAO_InterfaceDef_i (repo),
    TAO_AbstractInterfaceDef_i (repo),
    TAO_InterfaceAttrExtension_i (repo)
{
}

TAO_ExtAbstractInterfaceDef_i::~TAO_ExtAbstractInterfaceDef_i (void)
{
}

// Just call the base class version, this is here only to
// disambiguate multiple inheritance.
void
TAO_ExtAbstractInterfaceDef_i::destroy (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD;

  this->update_key (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  TAO_AbstractInterfaceDef_i::destroy_i (ACE_ENV_SINGLE_ARG_PARAMETER);
}

