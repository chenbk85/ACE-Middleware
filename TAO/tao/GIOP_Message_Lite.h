// -*- C++ -*-
//
// ===================================================================
/**
 *  @file GIOP_Message_Lite.h
 *
 *  $Id$
 *
 *  @author Balachandran Natarajan <bala@cs.wustl.edu>
 *  @author Carlos O'Ryan <coryan@uci.edu>
 */
// ===================================================================
#ifndef TAO_GIOP_MESSAGE_LITE_H
#define TAO_GIOP_MESSAGE_LITE_H
#include "ace/pre.h"

#include "tao/Pluggable_Messaging.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/GIOP_Utils.h"
#include "tao/GIOP_Message_State.h"
#include "tao/CDR.h"

class TAO_Operation_Details;
class TAO_Pluggable_Reply_Params;
class TAO_GIOP_Locate_Request_Header;

/**
 * @class TAO_GIOP_Message_Lite
 *
 * @brief Definitions of GIOPLite specific stuff
 *
 * This protocol is a modified version of GIOP. This is more suited
 * for homogenous platforms.
 */

class TAO_Export TAO_GIOP_Message_Lite : public TAO_Pluggable_Messaging
{
public:

  /// Constructor
  TAO_GIOP_Message_Lite (TAO_ORB_Core *orb_core,
                         size_t input_cdr_size = ACE_CDR::DEFAULT_BUFSIZE);

  /// Dtor
  virtual ~TAO_GIOP_Message_Lite (void);

  /// Initialize the object -- this is a dummy for GIOPlite
  virtual void init (CORBA::Octet, CORBA::Octet);

  /// Reset the messaging the object
  virtual void reset (int reset_flag = 1);

  /// Write the RequestHeader in to the <cdr> stream. The underlying
  /// implementation of the mesaging should do the right thing.
  virtual int generate_request_header (TAO_Operation_Details &op,
                                       TAO_Target_Specification &spec,
                                       TAO_OutputCDR &cdr);

  /// Write the RequestHeader in to the <cdr> stream.
  virtual int generate_locate_request_header (
      TAO_Operation_Details &op,
      TAO_Target_Specification &spec,
      TAO_OutputCDR &cdr);

  /// Write the reply header
  virtual int generate_reply_header (
      TAO_OutputCDR &cdr,
      TAO_Pluggable_Reply_Params_Base &params
    );

  /// This method reads the message on the connection. Returns 0 when
  /// there is short read on the connection. Returns 1 when the full
  /// message is read and handled. Returns -1 on errors. If <block> is
  /// 1, then reply is read in a blocking manner. <bytes> indicates the
  /// number of bytes that needs to be read from the connection.
  /// GIOP uses this read to unmarshall the message details that appear
  /// on the connection.
  virtual int read_message (TAO_Transport *transport,
                            int block = 0,
                            ACE_Time_Value *max_wait_time = 0);


  /// Format the message. As we have not written the message length in
  /// the header, we make use of this oppurtunity to insert and format
  /// the message.
  virtual int format_message (TAO_OutputCDR &cdr);


  /// Get the message type. The return value would be one of the
  /// following:
  /// TAO_PLUGGABLE_MESSAGE_REQUEST,
  /// TAO_PLUGGABLE_MESSAGE_REPLY,
  /// TAO_PLUGGABLE_MESSAGE_CLOSECONNECTION,
  /// TAO_PLUGGABLE_MESSAGE_MESSAGE_ERROR.
  virtual TAO_Pluggable_Message_Type message_type (void);



  /// Process the request message that we have received on the
  /// connection
  virtual int process_request_message (TAO_Transport *transport,
                                       TAO_ORB_Core *orb_core);

  /// Parse the reply message that we received and return the reply
  /// information though <reply_info>
  virtual int process_reply_message (
      TAO_Pluggable_Reply_Params &reply_info);

  /// Generate a reply message with the exception <ex>.
  virtual int generate_exception_reply (
      TAO_OutputCDR &cdr,
      TAO_Pluggable_Reply_Params_Base &params,
      CORBA::Exception &x
    );

private:

  /// Writes the GIOP header in to <msg>
  /// NOTE: If the GIOP header happens to change in the future, we can
  /// push this method in to the generator_parser classes.
  int write_protocol_header (TAO_GIOP_Message_Type t,
                             TAO_OutputCDR &msg);

  /// Processes the <GIOP_REQUEST> messages
  int process_request (TAO_Transport *transport,
                       TAO_ORB_Core *orb_core,
                       TAO_InputCDR &input);

  /// Processes the <GIOP_LOCATE_REQUEST> messages
  int process_locate_request (TAO_Transport *transport,
                              TAO_ORB_Core *orb_core,
                              TAO_InputCDR &input);

  /// Make a <GIOP_LOCATEREPLY> and hand that over to the transport so
  /// that it can be sent over the connection.
  /// NOTE:As on date 1.1 & 1.2 seem to have similar headers. Till an
  /// unmanageable difference comes let them be implemented here.
  int make_send_locate_reply (TAO_Transport *transport,
                              TAO_GIOP_Locate_Request_Header &request,
                              TAO_GIOP_Locate_Status_Msg &status);

  /// Send error messages
  int  send_error (TAO_Transport *transport);

  /// Parses the header of the GIOP messages for validity
  int parse_header (void);

  /// Validates the first 4 bytes that contain the magic word
  /// "GIOP". Also calls the validate_version () on the incoming
  /// stream.
  int parse_magic_bytes (void);

  /// This will do a validation of the stream that arrive in the
  /// transport.
  int validate_version (void);

  /// Set the state
  void set_state (CORBA::Octet major,
                  CORBA::Octet minor);

  /// Close a connection, first sending GIOP::CloseConnection.
  void send_close_connection (const TAO_GIOP_Version &version,
                              TAO_Transport *transport,
                              void *ctx);

  /// We must send a LocateReply through <transport>, this request
  /// resulted in some kind of exception.
  int send_reply_exception (TAO_Transport *transport,
                            TAO_ORB_Core* orb_core,
                            CORBA::ULong request_id,
                            IOP::ServiceContextList *svc_info,
                            CORBA::Exception *x);

  /// Print out a debug messages..
  void dump_msg (const char *label,
                 const u_char *ptr,
                 size_t len);

  /// Write the locate reply header
  virtual int generate_locate_reply_header (
      TAO_OutputCDR & /*cdr*/,
      TAO_Pluggable_Reply_Params_Base & /*params*/);

  /// Is the messaging object ready for processing BiDirectional
  /// request/response?
  virtual int is_ready_for_bidirectional (void);

private:

  /// Write the request header in to <msg>
  int write_request_header (
      const TAO_Operation_Details &opdetails,
      TAO_Target_Specification &spec,
      TAO_OutputCDR &msg);

  /// Write the LocateRequest header
  int write_locate_request_header (
      CORBA::ULong request_id,
      TAO_Target_Specification &spec,
      TAO_OutputCDR &msg);

  /// Write the reply header in to <output>
  int write_reply_header (
      TAO_OutputCDR &output,
      TAO_Pluggable_Reply_Params_Base &reply,
      CORBA::Environment &ACE_TRY_ENV =
      TAO_default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Writes the locate _reply message in to the <output>
  int write_locate_reply_mesg (
      TAO_OutputCDR &output,
      CORBA::ULong request_id,
      TAO_GIOP_Locate_Status_Msg &status);

  /// Parse the Request Header from the incoming stream. This will do a
  /// version specific parsing of the incoming Request header
  int parse_request_header (TAO_ServerRequest &);

  /// Parse the Loacte Request Header from the incoming stream. This will do a
  /// version specific parsing of the incoming Request header
  int parse_locate_header (
      TAO_GIOP_Locate_Request_Header &);

  /// Parse the reply message
  int parse_reply (TAO_InputCDR &input,
                   TAO_Pluggable_Reply_Params &params);

  /// Parse the locate reply message from the server
  int parse_locate_reply (TAO_InputCDR &input,
                          TAO_Pluggable_Reply_Params &params);

private:

  /// The message state. It represents the status of the messages that
  /// have been read from the connection.
  TAO_GIOP_Message_State message_state_;

  /// Output CDR
  TAO_OutputCDR *output_;

  /// Allocators for the output CDR that we hold. As we cannot rely on
  /// the resources from ORB Core we reserve our own resources. The
  /// reason that we cannot believe the ORB core is that, for a
  /// multi-threaded servers it dishes out resources cached in
  /// TSS. This would be dangerous as TSS gets destroyed before we
  /// would. So we have our own memory that we can rely on.
  /// Implementations of GIOP that we have
  ACE_Allocator *cdr_buffer_alloc_;
  ACE_Allocator *cdr_dblock_alloc_;

  /// A buffer that we will use to initialise the CDR stream
  char repbuf_[ACE_CDR::DEFAULT_BUFSIZE];

  /// The InputCDR stream in which the incoming messages are
  /// read. This will be used to decode the messages.
  TAO_InputCDR input_cdr_;

  /// The offset of the write pointer of the input cdr stream
  size_t current_offset_;
};




#if defined (__ACE_INLINE__)
# include "tao/GIOP_Message_Lite.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /*TAO_GIOP_MESSAGE_LITE_H*/
