/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
//
// = FILENAME
//    SOCK_Dgram_Mcast_QoS.h
//
// = AUTHORS
//    Vishal Kachroo <vishal@cs.wustl.edu>
//
// ============================================================================

#ifndef ACE_SOCK_DGRAM_MCAST_QOS_H
#define ACE_SOCK_DGRAM_MCAST_QOS_H
#include "ace/pre.h"

#include "ace/SOCK_Dgram_Mcast.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class ACE_Export ACE_SOCK_Dgram_Mcast_QoS : public ACE_SOCK_Dgram_Mcast
{
  // = TITLE
  //     Defines the member functions for the ACE QoS enabled socket 
  //     wrapper for UDP/IP multicast.

public:
  // = Initialization routine.
  ACE_SOCK_Dgram_Mcast_QoS (void);

  // Note that there is no public <open> method.  Therefore, this
  // class cannot be used unless you <subscribe> to a multicast group.
  // If you just want to send (and not listen) to a multicast group,
  // use <ACE_SOCK_Dgram> or <ACE_SOCK_CODgram> instead.

  ~ACE_SOCK_Dgram_Mcast_QoS (void);
  // Default dtor.

  // = Multicast group management routines.
  int subscribe (const ACE_INET_Addr &mcast_addr,
                 const ACE_QoS_Params &qos_params,
                 int reuse_addr = 1,
                 const ASYS_TCHAR *net_if = 0,
                 int protocol_family = PF_INET,
                 int protocol = 0,
                 ACE_Protocol_Info *protocolinfo = 0,
                 ACE_SOCK_GROUP g = 0,
                 u_long flags = 0,
                 ACE_QoS_Manager *qos_manager = 0,
                 ACE_QoS_Session *qos_session = 0);
  // This is a QoS-enabled method for joining a multicast group, which
  // passes <qos_params> via <ACE_OS::join_leaf>.  The network
  // interface device driver is instructed to accept datagrams with
  // <mcast_addr> multicast addresses.  If the socket has already been
  // opened, <subscribe> closes the socket and opens a new socket
  // bound to the <mcast_addr>. The session object specifies the QoS 
  // session that the socket wants to subscribe to. A socket may 
  // subscribe to multiple QoS sessions by calling this method multiple
  // times with different session objects.
  //
  // The <net_if> interface is hardware specific, e.g., use "netstat
  // -i" to find whether your interface is, such as "le0" or something
  // else.  If net_if == 0, <subscribe> uses the default mcast
  // interface.  Returns: -1 if the call fails.
  // 
  // Note that some platforms, such as pSoS, support only number, not
  // names, for network interfaces.  For these platforms, just give
  // these numbers in alphanumeric form and <subscribe> will convert
  // them into numbers via <ACE_OS::atoi>.

  // = Data transfer routines.

  ssize_t send (const iovec buffers[],
                int buffer_count,
                size_t &number_of_bytes_sent,
                int flags,
                const ACE_Addr &addr,
                ACE_OVERLAPPED *overlapped,
                ACE_OVERLAPPED_COMPLETION_FUNC func) const;
  // Send <buffer_count> worth of <buffers> to <addr> using overlapped
  // I/O (uses <WSASentTo>).  Returns 0 on success.

  ssize_t send (const void *buf,
                size_t n,
                const ACE_Addr &addr,
                int flags,
                ACE_OVERLAPPED *overlapped,
                ACE_OVERLAPPED_COMPLETION_FUNC func) const;
  // Send an <n> byte <buf> to the datagram socket (uses <WSASentTo>).

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  // = Disable public <open> method to ensure class used properly.

  int open (const ACE_Addr &mcast_addr,
            const ACE_QoS_Params &qos_params,
            int protocol_family = PF_INET,
            int protocol = 0,
            ACE_Protocol_Info *protocolinfo = 0,
            ACE_SOCK_GROUP g = 0,
            u_long flags = 0,
            int reuse_addr = 0);
  // Not publically visible.

  int subscribe_ifs (const ACE_INET_Addr &mcast_addr,
                     const ACE_QoS_Params &qos_params,
                     const ASYS_TCHAR *net_if,
                     int protocol_family,
                     int protocol,
                     int reuse_addr,
                     ACE_Protocol_Info *protocolinfo);
  // Subscribe to the multicast interface using QoS-enabled semantics.

};

#if !defined (ACE_LACKS_INLINE_FUNCTIONS)
#include "ace/SOCK_Dgram_Mcast_QoS.i"
#endif /* ACE_LACKS_INLINE_FUNCTIONS */

#include "ace/post.h"
#endif /* ACE_SOCK_DGRAM_MCAST_QOS_H */


