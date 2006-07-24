//
// $Id$
//
#include "Callback.h"

ACE_RCSID(Callback, Callback, "$Id$")

Callback::Callback (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

CORBA::Boolean
Callback::are_you_there (CORBA::String_out answer ACE_ENV_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_DEBUG,
              "(%P|%t) Callback - we are here!\n"));

  answer = CORBA::string_dup ("Yes, I am!");

  return 1;
}

void
Callback::test_oneway (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_DEBUG,
              "(%P|%t) Callback - test_oneway!\n"));
}

void
Callback::shutdown (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_DEBUG,
              "(%P|%t) Callback - shutdown!\n"));

  this->orb_->shutdown (0 ACE_ENV_ARG_PARAMETER);
}
