// $Id$

#include "AddrServer.h"

ACE_RCSID(EC_Examples, AddrServer, "$Id$")

AddrServer::AddrServer (const RtecUDPAdmin::UDP_Addr& addr)
  : addr_ (addr)
{
}

void
AddrServer::get_addr (const RtecEventComm::EventHeader&,
                      RtecUDPAdmin::UDP_Addr_out addr)
{
  addr = this->addr_;
}
