//
// $Id$
//
#include "Process.h"
#include "ace/OS_NS_unistd.h"

ACE_RCSID(Client_Leaks, Process, "$Id$")

Process::Process (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

CORBA::Long
Process::get_process_id (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return ACE_OS::getpid ();
}

void
Process::shutdown (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->orb_->shutdown (0);
}
