// $Id$

#include "ace/SOCK_Dgram_Mcast_QoS.h"

#if defined (ACE_LACKS_INLINE_FUNCTIONS)
#include "ace/SOCK_Dgram_Mcast_QoS.i"
#endif /* ACE_LACKS_INLINE_FUNCTIONS */

// This is a workaround for platforms with non-standard
// definitions of the ip_mreq structure
#if ! defined (IMR_MULTIADDR)
#define IMR_MULTIADDR imr_multiaddr
#endif /* ! defined (IMR_MULTIADDR) */

ACE_RCSID(ace, SOCK_Dgram_Mcast_QoS, "$Id $")

ACE_ALLOC_HOOK_DEFINE(ACE_SOCK_Dgram_Mcast_QoS)

// Dummy default constructor...

ACE_SOCK_Dgram_Mcast_QoS::ACE_SOCK_Dgram_Mcast_QoS (void)
{
  ACE_TRACE ("ACE_SOCK_Dgram_Mcast_QoS::ACE_SOCK_Dgram_Mcast_QoS");
}

int
ACE_SOCK_Dgram_Mcast_QoS::open (const ACE_Addr &mcast_addr,
                                const ACE_QoS_Params &qos_params,
                                int protocol_family,
                                int protocol,
                                ACE_Protocol_Info *protocolinfo,
                                ACE_SOCK_GROUP g,
                                u_long flags,
                                int reuse_addr)
{
  ACE_TRACE ("ACE_SOCK_Dgram_Mcast_QoS::open");
  
  ACE_UNUSED_ARG (qos_params);

  // Make a copy of address to use in the <send> methods.
  // Note: Sun C++ 4.2 needs the useless const_cast.
  this->mcast_addr_.set (ACE_reinterpret_cast (const ACE_INET_Addr &,
                                               ACE_const_cast (ACE_Addr &,
                                                               mcast_addr)));
  
  // Only perform the <open> initialization if we haven't been opened
  // earlier.
  if (this->get_handle () == ACE_INVALID_HANDLE)
    {
      if (ACE_SOCK::open (SOCK_DGRAM,
                          protocol_family,
                          protocol,
                          protocolinfo,
                          g,
                          flags,
                          reuse_addr) == -1)
        return -1;

      int one = 1;
      if (reuse_addr
          && this->ACE_SOCK::set_option (SOL_SOCKET,
                                         SO_REUSEADDR,
                                         &one,
                                         sizeof one) == -1)
        return -1;
#if defined (SO_REUSEPORT)
      else if (this->ACE_SOCK::set_option (SOL_SOCKET,
                                           SO_REUSEPORT,
                                           &one,
                                           sizeof one) == -1)
        return -1;
#endif /* SO_REUSEPORT */

      // Create an address to bind the socket to.
      ACE_INET_Addr local;

      if (local.set (this->mcast_addr_.get_port_number ()) == -1)
        return -1;
      else if (ACE_SOCK_Dgram::shared_open (local,
                                            protocol_family) == -1)
        return -1;
    }

  return 0;
}


int
ACE_SOCK_Dgram_Mcast_QoS::subscribe_ifs (const ACE_INET_Addr &mcast_addr,
                                         const ACE_QoS_Params &qos_params,
                                         const ASYS_TCHAR *net_if,
                                         int protocol_family,
                                         int protocol,
                                         int reuse_addr,
                                         ACE_Protocol_Info *protocolinfo)
{
  ACE_TRACE ("ACE_SOCK_Dgram_Mcast::subscribe_ifs");
#if defined (ACE_WIN32)
  // Windows NT's winsock has trouble with multicast subscribes in the
  // presence of multiple network interfaces when the IP address is
  // given as INADDR_ANY.  It will pick the first interface and only
  // accept mcast there.  So, to work around this, cycle through all
  // of the interfaces known and subscribe to all the non-loopback
  // ones.
  //
  // Note that this only needs to be done on NT, but there's no way to
  // tell at this point if the code will be running on NT - only if it
  // is compiled for NT-only or for NT/95, and that doesn't really
  // help us.  It doesn't hurt to do this on Win95, it's just a little
  // slower than it normally would be.
  //
  // NOTE - <ACE::get_ip_interfaces> doesn't always get all of the
  // interfaces.  In particular, it may not get a PPP interface.  This
  // is a limitation of the way <ACE::get_ip_interfaces> works with
  // MSVC.  The reliable way of getting the interface list is
  // available only with MSVC 5.

  if (net_if == 0)
    {
      ACE_INET_Addr *if_addrs = 0;
      size_t if_cnt;

      if (ACE::get_ip_interfaces (if_cnt,
                                  if_addrs) != 0)
        return -1;

      size_t nr_subscribed = 0;

      if (if_cnt < 2)
        {
          if (this->subscribe (mcast_addr,
                               qos_params,
                               reuse_addr,
                               ASYS_TEXT ("0.0.0.0"),
                               protocol_family,
                               protocol,
                               protocolinfo) == 0)
            ++nr_subscribed;
        }
      else
        // Iterate through all the interfaces, figure out which ones
        // offer multicast service, and subscribe to them.
        while (if_cnt > 0)
          {
            --if_cnt;

            // Convert to 0-based for indexing, next loop check.
            if (if_addrs[if_cnt].get_ip_address() == INADDR_LOOPBACK)
              continue;
            if (this->subscribe (mcast_addr,
                                 qos_params,
                                 reuse_addr,
                                 ASYS_WIDE_STRING (if_addrs[if_cnt].get_host_addr()),
                                 protocol_family,
                                 protocol,
                                 protocolinfo) == 0)
              ++nr_subscribed;
          }

      delete [] if_addrs;

      if (nr_subscribed == 0)
        {
          errno = ENODEV;
          return -1;
        }
      else
        // 1 indicates a "short-circuit" return.  This handles the
        // rather bizarre semantics of checking all the interfaces on
        // NT.
        return 1; 
    }
#else
  ACE_UNUSED_ARG (mcast_addr);
  ACE_UNUSED_ARG (qos_params);
  ACE_UNUSED_ARG (protocol_family);
  ACE_UNUSED_ARG (protocol);
  ACE_UNUSED_ARG (reuse_addr);
  ACE_UNUSED_ARG (protocolinfo);
#endif /* ACE_WIN32 */
  // Otherwise, do it like everyone else...

  // Create multicast request.
  if (this->make_multicast_address (this->mcast_addr_,
                                    net_if) == -1)
    return -1;
  else
    return 0;
}

int
ACE_SOCK_Dgram_Mcast_QoS::subscribe (const ACE_INET_Addr &mcast_addr,
                                     const ACE_QoS_Params &qos_params,
                                     int reuse_addr,
                                     const ASYS_TCHAR *net_if,
                                     int protocol_family,
                                     int protocol,
                                     ACE_Protocol_Info *protocolinfo,
                                     ACE_SOCK_GROUP g,
                                     u_long flags,
                                     ACE_QoS_Manager *qos_manager,
                                     ACE_QoS_Session *qos_session)
{
  ACE_TRACE ("ACE_SOCK_Dgram_Mcast::subscribe");
  
  if (this->open (mcast_addr,
                  qos_params,
                  protocol_family,
                  protocol,
                  protocolinfo,
                  g,
                  flags,
                  reuse_addr) == -1)
    return -1;

  // The following method call only applies to Win32 currently.
  int result = this->subscribe_ifs (mcast_addr,
                                    qos_params,
                                    net_if,
                                    protocol_family,
                                    protocol,
                                    reuse_addr,
                                    protocolinfo);
  // Check for the "short-circuit" return value of 1 (for NT).
  if (result != 0)
    return result;

  // Tell network device driver to read datagrams with a
  // <mcast_request_if_> IP interface.
  else
    {
      // Check if the mcast_addr passed into this method is the
      // same as the QoS session address.
      if (mcast_addr == qos_session->dest_addr ()) 
      {

        // Subscribe to the QoS session.
        ACE_UNUSED_ARG (qos_manager);
#if 0
        if (qos_manager->join_qos_session (qos_session) == -1)
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Unable to join QoS Session\n"),
                            -1);
#endif

      } 
      else
      {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Dest Addr in the QoS Session does"
                             " not match the address passed into"
                             " subscribe\n"),
                            -1);
      }

      sockaddr_in mult_addr;

      if (protocol_family == ACE_FROM_PROTOCOL_INFO)
        mult_addr.sin_family = protocolinfo->iAddressFamily;
      else
        mult_addr.sin_family = protocol_family;

      mult_addr.sin_port = ACE_HTONS (mcast_addr.get_port_number ());

      mult_addr.sin_addr = this->mcast_request_if_.IMR_MULTIADDR;

      // XX This is windows stuff only. fredk
      if (ACE_OS::join_leaf (this->get_handle (),
                             ACE_reinterpret_cast (const sockaddr *,
                                                   &mult_addr),
                             sizeof mult_addr,
                             qos_params) == ACE_INVALID_HANDLE
          && errno != ENOTSUP)
        return -1;
      else
        qos_session->qos (*(qos_params.socket_qos ()));

      return 0;
    }
}
