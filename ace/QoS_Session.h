/* -*- C++ -*- */
// $Id$

// ===========================================================================
//
// = LIBRARY
//    ace
//
// = FILENAME
//    QoS_Session.h
//
// = AUTHOR
//    Vishal Kachroo <vishal@cs.wustl.edu>
//
// ===========================================================================

#ifndef ACE_QOS_SESSION_H
#define ACE_QOS_SESSION_H

#include "ace/INET_Addr.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class ACE_SOCK;
#include "ace/Containers_T.h"

typedef int ACE_Protocol_ID;
// IPPROTO_UDP or IPPROTO_TCP.

class ACE_Export ACE_QoS_Session
{
  // = TITLE
  //    A QoS Session object.
  // 
  // = DESCRIPTION
  //    This class defines the interface for a QoS Session. It abstracts the 
  //    notion of QoS on different platforms and presents a simple, easy-to-use
  //    API. Current [RAPI,GQoS] and future implementations will conform to this
  //    interface.

public:

  enum ACE_End_Point_Type
  {
    ACE_QOS_SENDER,
    ACE_QOS_RECEIVER,
    ACE_QOS_BOTH
  };
  // A flag to indicate if this endpoint is a sender or a receiver or both.

  virtual ~ACE_QoS_Session (void);
  // to shutup g++.

  virtual int open (ACE_INET_Addr dest_addr,
                    ACE_Protocol_ID protocol_id) = 0;
  // Open a QoS session [dest IP, dest port, Protocol ID].

  virtual int close (void) = 0;
  // Close the QoS Session.
  
  virtual ACE_QoS qos (void) const = 0;
  // Returns the QoS in the current session.
   
  virtual int qos (ACE_SOCK *socket,
                   const ACE_QoS &ace_qos) = 0;
  // Set QoS for the current session. The socket parameter is used to confirm if
  // this QoS session was subscribed to by the socket.

  virtual void qos (const ACE_QoS &ace_qos) = 0;
  // Sets the QoS for this session object to ace_qos. Does not interfere with the 
  // QoS in the underlying socket. This call is useful to update the QoS object 
  // when the underlying socket QoS is being set through a mechanism other than
  // the previous qos () method e.g. inside the dgram_mcast.subscribe () where the 
  // QoS for the socket is set through ACE_OS::join_leaf ().

  virtual int update_qos (void) = 0;
  // This is called from handle_qos () method of the the QoS Event Handler.
  // Invoking this method is an indication of a QoS event occurring, that may have 
  // resulted in a change of QoS for the underlying session. This method updates 
  // the QoS object associated with this session.
 
  virtual int session_id (void) const = 0;
  // Get the session id.
  
  virtual void session_id (const int session_id) = 0;
  // Set the session id.

  virtual ACE_INET_Addr dest_addr (void) const = 0;
  // Get the destination address for this session.

  virtual void dest_addr (const ACE_INET_Addr &dest_addr) = 0;
  // Set the destination address for this session.

  virtual int version (void) = 0;
  // Returns the version of the underlying RSVP implementation. Is
  // meaningful only when the underlying implementation has versioning.

protected:
  
  int session_id_;
  // session id for the session.
  
  ACE_INET_Addr dest_addr_;
  // Destination address for this session.
  
  ACE_Protocol_ID protocol_id_;
  // Is this a TCP or a UDP session.

  ACE_QoS qos_;
  // QoS for this session.
  
  ACE_End_Point_Type flags_;
  // Specifies if this is a sending/receiving/both session.

};

#endif /* ACE_QOS_SESSION_H */









