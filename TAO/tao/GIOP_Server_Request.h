// This may look like C, but it's really -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    GIOP_Server_Request.h
//
// = DESCRIPTION
//    Header file for CORBA's Dynamic Server Skeleton Interface's
//    "Server Request" type.  (for GIOP)
//
// = AUTHOR
//     Copyright 1994-1995 by Sun Microsystems, Inc. and Chris Cleeland.
//     Modifications by Aniruddha Gokhale based on CORBAv2.2 Feb 98
// ============================================================================

#ifndef TAO_GIOP_SERVER_REQUEST_H
#include "ace/pre.h"
#define TAO_GIOP_SERVER_REQUEST_H

#include "tao/corbafwd.h"
// @@ Bala: there is a reasons why the rest of the #includes are after
// the pragma once, think about it.

//#include "tao/GIOP_Utils.h"
#include "tao/GIOP_Message_Base.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Server_Request.h"
#include "tao/ORB.h"
#include "tao/Principal.h"

class TAO_Export TAO_GIOP_ServerRequest : public CORBA_ServerRequest
{
  // = TITLE
  //    Class representing an GIOP ServerRequest object.
public:
  // = Initialization and termination methods.
  TAO_GIOP_ServerRequest (TAO_Pluggable_Messaging_Interface *mesg_base,
                          TAO_InputCDR &input,
                          TAO_OutputCDR &output,
                          TAO_ORB_Core *orb_core,
                          const TAO_GIOP_Version &version);
                          
  // Constructor
  TAO_GIOP_ServerRequest (TAO_Pluggable_Messaging_Interface *mesg_base,
                          CORBA::ULong &request_id,
                          CORBA::Boolean &response_expected,
                          TAO_ObjectKey &object_key,
                          const ACE_CString &operation,
                          TAO_OutputCDR &output,
                          TAO_ORB_Core *orb_core,
                          const TAO_GIOP_Version &version,
                          int &parse_error);

  virtual ~TAO_GIOP_ServerRequest (void);
  // Destructor.

#if !defined (TAO_HAS_MINIMUM_CORBA)

  // = General ServerRequest operations
  void arguments (CORBA::NVList_ptr &list,
                  CORBA_Environment &ACE_TRY_ENV =
                      TAO_default_environment ());

  void set_result (const CORBA::Any &value,
                   CORBA_Environment &ACE_TRY_ENV =
                       TAO_default_environment ());

  void set_exception (const CORBA::Any &value,
                      CORBA_Environment &ACE_TRY_ENV =
                          TAO_default_environment ());

  virtual void dsi_marshal (CORBA_Environment &ACE_TRY_ENV =
                                TAO_default_environment ());
  // does the marshaling of outgoing parameters and is used by the DSI
  // based scheme

#endif /* TAO_HAS_MINIMUM_CORBA */

  // = Request attributes.

  const char *operation (void) const;
  // return the operation name

  void operation (ACE_CString &operation);
  // set the operation name

  void operation (const char * name,
                  int release);
  // set the operation name
  
  
  unsigned int operation_length (void) const;
  // return the legnth of the operation

  //  CORBA::Context_ptr ctx (void);
  // return the context pointer

  // = TAO extensions

  CORBA::ORB_ptr  orb (void);
  // return the underlying ORB

  TAO_POA *oa (void);
  // return the Object Adapter

  //
  // = TAO extensions
  // meant to be used internally.
  //

  virtual void demarshal (CORBA_Environment &ACE_TRY_ENV,
                          const TAO_Call_Data_Skel *info,
                          ...);
  // demarshal incoming parameters. Used by the SII skeleton (i.e., the IDL
  // compiler generated skeleton)

  virtual void marshal (CORBA_Environment &ACE_TRY_ENV,
                        //                        CORBA_Environment &skel_env,
                        const TAO_Call_Data_Skel *info,
                        ...);
  // marshal outgoing parameters and return value. This is used by the SSI
  // i.e., by the IDL compiler generated skeletons.

  virtual void init_reply (CORBA_Environment &ACE_TRY_ENV =
                               TAO_default_environment ());
  // start a Reply message

  virtual TAO_InputCDR &incoming (void);
  // Retrieve the incoming stream.

  virtual TAO_OutputCDR &outgoing (void);
  // Retrieve the outgoing stream.

  virtual CORBA::Boolean response_expected (void) const;
  // Is the response expected?

  virtual void response_expected (CORBA::Boolean response);
  // Set the response expected flag

  virtual CORBA::Boolean sync_with_server (void) const;
  // Should we return before dispatching the servant?

  virtual void sync_with_server (CORBA::Boolean sync_flag);
  // Set the sync_with_server flag

  virtual void _tao_lazy_evaluation (int lazy_evaluation);
  // Set the lazy evaluation flag

  virtual void send_no_exception_reply (TAO_Transport *transport);
  // Used with reliable oneway requests.

  virtual CORBA::Principal_ptr principal (void) const;

  virtual TAO_ObjectKey &object_key (void);

  virtual CORBA::Object_ptr objref (CORBA_Environment &ACE_TRY_ENV =
                                      TAO_default_environment ());
  // Return the object reference of the request.

  virtual IOP::ServiceContextList &service_info (void);
  virtual void service_info (IOP::ServiceContextList &service_info);

  // The pseudo object methods, not really needed because the class is
  // not in the spec, but we add them for the sake of completeness.
  static TAO_GIOP_ServerRequest* _duplicate (TAO_GIOP_ServerRequest*);
  static TAO_GIOP_ServerRequest* _nil (void);

  // To handle System Exceptions at the lowest level,
  // a method returning the request_id_ is needed.

  virtual CORBA::ULong request_id (void);
  virtual void request_id (CORBA::ULong req);

  CORBA::Object_ptr forward_location (void);
  // get the forward_location

  CORBA::ULong exception_type (void);
  // get the exception type

  void requesting_principal (CORBA_Principal_ptr principal);
  // set the requesting principal

  void header_length (size_t len);

  void message_size_offset (size_t len);

private:
  TAO_Pluggable_Messaging_Interface *mesg_base_;
  
  ACE_CString operation_;
  // Operation name.

  CORBA::Object_var forward_location_;

  TAO_InputCDR *incoming_;
  // Incoming stream.

  TAO_OutputCDR *outgoing_;
  // Outgoing stream.

  CORBA::Boolean response_expected_;
  // 0: oneway (SYNC_NONE or SYNC_WITH_TRANSPORT)
  // 1: twoway, or oneway (SYNC_WITH_SERVER or SYNC_WITH_TARGET)

  CORBA::Boolean sync_with_server_;
  // 1: oneway (SYNC_WITH_SERVER)
  // 0: anything else

  int lazy_evaluation_;
  // If zero then the NVList is evaluated ASAP.

#if !defined (TAO_HAS_MINIMUM_CORBA)

  CORBA::NVList_ptr params_;
  // Incoming parameters.

#endif /* TAO_HAS_MINIMUM_CORBA */

  CORBA::Any_ptr retval_;
  // Return value.

  CORBA::Any_ptr exception_;
  // Any exception which might be raised.

  //  TAO_GIOP_ReplyStatusType exception_type_;
  CORBA::ULong exception_type_;
  // exception type (will be NO_EXCEPTION in the majority of the cases)

  TAO_ORB_Core* orb_core_;
  // A pointer to the ORB Core for the context where the request was
  // created.

  TAO_GIOP_Version version_;
  // The version for the GIOP request, the reply must have the same
  // one.

  IOP::ServiceContextList service_info_;
  // The service context for the request (CORBA Reference?)

  CORBA::ULong request_id_;
  // Unique identifier for a request

  TAO_ObjectKey object_key_;
  // The object key of the destination object.

  CORBA::Principal_var requesting_principal_;
  // Identifies the requester
};

#if defined (__ACE_INLINE__)
# include "tao/GIOP_Server_Request.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /* TAO_GIOP_SERVER_REQUEST_H */
