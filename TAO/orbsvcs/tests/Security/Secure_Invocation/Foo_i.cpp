// -*- C++ -*-

#include "Foo_i.h"

#include "ace/OS_NS_string.h"


ACE_RCSID (Secure_Invocation,
           Foo_i,
           "$Id$")


Foo_i::Foo_i (CORBA::ORB_ptr orb,
              SecurityLevel3::SecurityCurrent_ptr current)
  : orb_ (CORBA::ORB::_duplicate (orb)),
    current_ (SecurityLevel3::SecurityCurrent::_duplicate (current))
{
}

void
Foo_i::baz (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Foo::Bar::NoSecurityAttributes))
{
  SecurityLevel3::ClientCredentials_var credentials =
    this->current_->client_credentials (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::String_var id =
    credentials->creds_id (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  ACE_DEBUG ((LM_DEBUG,
              "\n"
              "ClientCredentials ID\n"
              "====================\n"
              "%s\n",
              id.in ()));
}

void
Foo_i::shutdown (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->orb_->shutdown (0 ACE_ENV_ARG_PARAMETER);
}
