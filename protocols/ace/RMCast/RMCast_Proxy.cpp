//
// $Id$
//

#include "RMCast_Proxy.h"

#if !defined (__ACE_INLINE__)
# include "RMCast_Proxy.i"
#endif /* ! __ACE_INLINE__ */

ACE_RCSID(ace, RMCast_Proxy, "$Id$")

ACE_RMCast_Proxy::~ACE_RMCast_Proxy (void)
{
}

ACE_UINT32
ACE_RMCast_Proxy::next_expected (void) const
{
  return this->next_expected_;
}

ACE_UINT32
ACE_RMCast_Proxy::highest_received (void) const
{
  return this->highest_received_;
}

int
ACE_RMCast_Proxy::ack (ACE_RMCast::Ack &ack)
{
  this->next_expected_ = ack.next_expected;
  this->highest_received_ = ack.highest_received;
  return this->ACE_RMCast_Module::ack (ack);
}
