// $Id$

// ============================================================================
//
// = LIBRARY
//     TAO
//
// = FILENAME
//     Request_Mux_Strategy.h
//
// = DESCRIPTION
//     IIOP Request Mux Strategies.
//
// = AUTHOR
//     Alexander Babu Arulanthu <alex@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_REQUEST_MUX_STRATEGY_H
#define TAO_REQUEST_MUX_STRATEGY_H

#include "tao/GIOP.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class TAO_Reply_Dispatcher;
class TAO_GIOP_Version;
class TAO_InputCDR;

class TAO_Export TAO_Request_Mux_Strategy
{
  // = TITLE
  //
  //     Strategy to determine whether the connection should be
  //     multiplexed for multiple requests or it is exclusive for a
  //     single request at a time.
  //
  // = DESCRIPTION
  //

public:
  TAO_Request_Mux_Strategy (void);
  // Base class constructor.

  virtual ~TAO_Request_Mux_Strategy (void);
  // Base class destructor.

  virtual CORBA::ULong request_id (void)  = 0;
  // Generate and return an unique request id for the current
  // invocation.

  // = Bind and Find methods for the <Request ID, ReplyDispatcher>
  //   pairs. The ReplyDispatcher is not the CORBA ReplyDispatcher of
  //   the AMI's.

  virtual int bind_dispatcher (CORBA::ULong request_id,
                               TAO_Reply_Dispatcher *rh) = 0;
  // Bind the dispatcher with the request id.

  virtual int dispatch_reply (CORBA::ULong request_id,
                              CORBA::ULong reply_status,
                              const TAO_GIOP_Version& version,
                              TAO_GIOP_ServiceContextList& reply_ctx,
                              TAO_InputCDR* cdr) = 0;
  // Dispatch the reply for <request_id>, cleanup any resources
  // allocated for that request.

  // = "Factory methods" to obtain the CDR stream, in the Muxed case
  //    the factory simply allocates a new one, in the Exclusive case
  //    the factory returns a pointer to the pre-allocated CDR.

  virtual void set_cdr_stream (TAO_InputCDR *cdr) = 0;
  // Set the CDR stream.

  virtual TAO_InputCDR *get_cdr_stream (void);
  // Get the CDR stream.

  virtual void destroy_cdr_stream (TAO_InputCDR *) = 0;
  // Destroy the CDR stream.

protected:
  TAO_InputCDR *cdr_;
  // Pointer to the CDR stream used to read the incoming message. This
  // is obtained from the Invocation object. This is preallocated in
  // the SMI and dynamically allocated in AMI.
};

class TAO_Export TAO_Muxed_RMS : public  TAO_Request_Mux_Strategy
{
  // = TITLE
  //
  //    Connection is multiplexed for many requests.
  //
  // = DESCRIPTION
  //

public:
  TAO_Muxed_RMS (void);
  // Constructor.

  virtual ~TAO_Muxed_RMS (void);
  // Destructor.

  // = The TAO Request Strategy methods...
  virtual CORBA::ULong request_id (void);
  virtual int bind_dispatcher (CORBA::ULong request_id,
                               TAO_Reply_Dispatcher *rh);
  virtual int dispatch_reply (CORBA::ULong request_id,
                              CORBA::ULong reply_status,
                              const TAO_GIOP_Version& version,
                              TAO_GIOP_ServiceContextList& reply_ctx,
                              TAO_InputCDR* cdr);
  virtual void set_cdr_stream (TAO_InputCDR *cdr);
  virtual void destroy_cdr_stream (TAO_InputCDR *);

protected:
  // @@ HASH TABLE???
};

class TAO_Export TAO_Exclusive_RMS : public TAO_Request_Mux_Strategy
{
  // = TITLE
  //
  //    Connection exclusive for the request.
  //
  // = DESCRIPTION
  //

public:
  TAO_Exclusive_RMS (void);
  // Constructor.

  virtual ~TAO_Exclusive_RMS (void);
  // Destructor.

  // = The TAO Request Strategy methods...
  virtual CORBA::ULong request_id (void);
  virtual int bind_dispatcher (CORBA::ULong request_id,
                               TAO_Reply_Dispatcher *rh);
  virtual int dispatch_reply (CORBA::ULong request_id,
                              CORBA::ULong reply_status,
                              const TAO_GIOP_Version& version,
                              TAO_GIOP_ServiceContextList& reply_ctx,
                              TAO_InputCDR* cdr);
  virtual void set_cdr_stream (TAO_InputCDR *cdr);
  virtual void destroy_cdr_stream (TAO_InputCDR *);

protected:
  ACE_SYNCH_MUTEX lock_;
  // Synchronize the internal state

  CORBA::ULong request_id_generator_;
  // Used to generate a different request_id on each call to
  // request_id()

  CORBA::ULong request_id_;
  // Request id for the current request.

  TAO_Reply_Dispatcher *rd_;
  // Reply Dispatcher corresponding to the request.
};

#endif /* REQUEST_MUX_STRATEGY_H */
