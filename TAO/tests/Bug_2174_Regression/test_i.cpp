// $Id$

#include "test_i.h"

#include "ace/OS_NS_unistd.h"

ACE_RCSID(Timeout, test_i, "$Id$")

Simple_Server_i::Simple_Server_i (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{

}

CORBA::Long
Simple_Server_i::echo (CORBA::Long x,
                       CORBA::Long msecs
                       ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_Time_Value tv (msecs / 1000, (msecs % 1000) * 1000);

  // ACE_DEBUG ((LM_DEBUG, "server (%P) Sleeping for %d msecs\n",
  //             tv.msec ()));
  ACE_OS::sleep (tv);

  return x;
}

void
Simple_Server_i::shutdown (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_DEBUG,
              "server (%P) Received shutdown request from client\n"));
  this->orb_->shutdown (0 ACE_ENV_ARG_PARAMETER);
}
