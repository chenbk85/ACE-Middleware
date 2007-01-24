// -*- C++ -*-

// ================================================================
/**
 *  @file Messaging.h
 *
 *  $Id$
 *
 *  Include all the required headers to use CORBA Messaging easily.
 *
 *  @author Carlos O'Ryan <coryan@uci.edu>
 */
// ================================================================

#ifndef TAO_MESSAGING_H
#define TAO_MESSAGING_H

#include /**/ "ace/pre.h"

#include "tao/Messaging/messaging_export.h"

#define TAO_MESSAGING_SAFE_INCLUDE
#include "tao/Messaging/MessagingC.h"
#undef TAO_MESSAGING_SAFE_INCLUDE

#include "tao/Messaging/MessagingA.h"
#include "tao/Messaging/TAO_ExtC.h"
#include "tao/TAOC.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_Messaging_Export TAO_Messaging_Initializer
{
public:
  /// Used to force the initialisation of the ORB code.
  static int init (void);
};

static int
TAO_Requires_Messaging_Initializer = TAO_Messaging_Initializer::init ();

// Typedef for the Reply Handler Skeleton.
// This is handcrafted not generated by the IDL compiler.

class TAO_InputCDR;

enum TAO_AMI_Reply_Status
{
  /// Reply is normal.
  TAO_AMI_REPLY_OK,

  /// Reply is not normal and no exceptions
  TAO_AMI_REPLY_NOT_OK,

  /// An user exception was raised.
  TAO_AMI_REPLY_USER_EXCEPTION,

  /// An system exception was raised.
  TAO_AMI_REPLY_SYSTEM_EXCEPTION
};


typedef void (*TAO_Reply_Handler_Skeleton)(
    TAO_InputCDR &,
    Messaging::ReplyHandler_ptr,
    CORBA::ULong reply_status

    );

namespace TAO
{
  struct Exception_Data;
}

/**
 * @namespace TAO_Messaging_Helper
 *
 * @brief Define helper functions for the CORBA Messaging
 * implementation in TAO.
 */
namespace TAO_Messaging_Helper
{
  /// Implement the code shared by all the ExceptionHolder::raise_*()
  /// operations
  void TAO_Messaging_Export exception_holder_raise (
           TAO::Exception_Data *exception_data,
           CORBA::ULong exception_count,
           CORBA::Octet *marshaled_data,
           CORBA::ULong marshaled_data_length,
           CORBA::Boolean byte_order,
           CORBA::Boolean is_system_exception
          );
}

TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* TAO_MESSAGING_H */
