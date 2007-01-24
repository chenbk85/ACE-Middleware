// $Id$

#include "test_i.h"

ACE_RCSID(Buffered_Oneways, test_i, "$Id$")

test_i::test_i (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

void
test_i::method (CORBA::ULong request_number
                ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_DEBUG,
              "server: Iteration %d @ %T\n",
              request_number));
}

void
test_i::shutdown (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->orb_->shutdown (0
                        ACE_ENV_ARG_PARAMETER);
}
