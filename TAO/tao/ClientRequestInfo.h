// -*- C++ -*-

//=============================================================================
/**
 * @file ClientRequestInfo.h
 *
 * $Id$
 *
 * This is the implementation of the
 * PortableInterceptor::ClientRequestInfo interface.
 *
 * @author Ossama Othman <ossama@uci.edu>
 */
//=============================================================================

#ifndef TAO_CLIENT_REQUEST_INFO_H
#define TAO_CLIENT_REQUEST_INFO_H

#include /**/ "ace/pre.h"

#include "tao/LocalObject.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (TAO_HAS_INTERCEPTORS == 1)

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#include "tao/ClientRequestInfoC.h"
#include "tao/ORB_Constants.h"
#include "Invocation_Utils.h"
#include "PIForwardRequestC.h"
#include "PICurrent_Impl.h"
#include "PICurrent_Copy_Callback.h"

class TAO_Service_Context;

namespace TAO
{
  class Invocation_Base;
}

namespace Dynamic
{
  class ParameterList;
  class ExceptionList;
  typedef CORBA::StringSeq RequestContext;
  typedef CORBA::StringSeq ContextList;
}

namespace Messaging
{
  typedef CORBA::Short SyncScope;
}

/**
 * @class TAO_ClientRequestInfo
 *
 * @brief Implementation of the PortableInterceptor::ClientRequestInfo
 *        interface.
 */
class TAO_ClientRequestInfo
  : public virtual PortableInterceptor::ClientRequestInfo,
    public virtual TAO_Local_RefCounted_Object
{
public:
  TAO_ClientRequestInfo (TAO::Invocation_Base *invocation);

  /// Return an ID unique to the current request.  This request ID may
  /// or may not be the same as the GIOP request ID.
  virtual CORBA::ULong request_id (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return the operation name for the current request.
  virtual char * operation (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return the list of arguments passed to the current operation.
  virtual Dynamic::ParameterList * arguments (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return the list of exceptions the current operation is capable
  /// of throwing.
  virtual Dynamic::ExceptionList * exceptions (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual Dynamic::ContextList * contexts (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual Dynamic::RequestContext * operation_context (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return the result of the current request.  If there is no return
  /// value then an Any with tk_void TypeCode is returned.  This is
  /// method is not valid for oneway operations.
  virtual CORBA::Any * result (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Returns true for a two-way operation, and false otherwise.
  virtual CORBA::Boolean response_expected (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException)) ;

  /// Return the sync_scope policy value for the current one-way
  /// operation.  If the operation is not a one-way, a
  /// CORBA::BAD_INV_ORDER exception is thrown.
  virtual Messaging::SyncScope sync_scope (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return the reply status for the current request.
  /**
   * Statuses can be PortableInterceptor::SUCCESSFUL,
   * SYSTEM_EXCEPTION, USER_EXCEPTION, LOCATION_FORWARD,
   * TRANSPORT_RETRY, UNKNOWN.
   */
  virtual PortableInterceptor::ReplyStatus reply_status (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// If the reply status is PortableInterceptor::LOCATION_FORWARD or
  /// return the object reference to which the request was forwarded.
  virtual CORBA::Object_ptr forward_reference (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException)) ;

  virtual CORBA::Any * get_slot (
      PortableInterceptor::SlotId id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableInterceptor::InvalidSlot));

  /// Return the IOP::ServiceContext with the given IOP::ServiceId
  /// from the request service context list.
  virtual IOP::ServiceContext * get_request_service_context (
      IOP::ServiceId id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return the IOP::ServiceContext with the given IOP::ServiceId
  /// from the reply service context list.
  virtual IOP::ServiceContext * get_reply_service_context (
      IOP::ServiceId id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return the (initial, non-forwarded, or permanently forwarded)
  /// object reference of the target.
  virtual CORBA::Object_ptr target (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return the object reference for the current target.  The target
  /// may change in the even of a location forward.
  virtual CORBA::Object_ptr effective_target (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual IOP::TaggedProfile * effective_profile (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return an Any containing the received exception, if any.
  /// Otherwise, throw a CORBA::BAD_INV_ORDER exception.
  /**
   * @note There is no trivial way to extract the exception from an Any.
   */
  virtual CORBA::Any * received_exception (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return the repository ID for the received exception.
  virtual char * received_exception_id (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return the first IOP::TaggedComponent that matches the given
  /// IOP::ComponentId in the object reference for the current
  /// target.
  virtual IOP::TaggedComponent * get_effective_component (
      IOP::ComponentId id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return all IOP::TaggedComponent(s) that match the given
  /// IOP::ComponentId in the object reference for the current
  /// target.
  virtual IOP::TaggedComponentSeq * get_effective_components (
      IOP::ComponentId id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return the policy of the given type in effect for the current
  /// request.
  virtual CORBA::Policy_ptr get_request_policy (
      CORBA::PolicyType type
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Add the IOP::ServiceContext to the request (outgoing)
  /// IOP::ServiceContextList.
  virtual void add_request_service_context (
      const IOP::ServiceContext & service_context,
      CORBA::Boolean replace
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
     ACE_THROW_SPEC ((CORBA::SystemException));

  /**
   * @name Stub helper methods
   *
   * The following methods are used in the implementation of the
   * Stubs, they are not part of the ClientRequestInfo interface, but
   * an extension used internally by TAO.
   */
  //@{

  /// Change the exception status.
  void exception (CORBA::Exception *exception);

  /// Set the status of the received reply.
  void reply_status (TAO::Invocation_Status s);

  /// Extract the forward object reference from the
  /// PortableInterceptor::ForwardRequest exception, and set the reply
  /// status flag accordingly.
  void forward_reference (PortableInterceptor::ForwardRequest &exc);
  //@}


private:

  /// Check if this ClientRequestInfo object is called within the
  /// context of a request.
  void check_validity (ACE_ENV_SINGLE_ARG_DECL);

  /// Setup thread scope and request scope
  /// PortableInterceptor::Current objects.
  void setup_picurrent (void);

  /// Helper method to get the request and response service contexts.
  IOP::ServiceContext *get_service_context_i (
      TAO_Service_Context &service_context_list,
      IOP::ServiceId id
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

private:
  /// Pointer to the invocation object.
  TAO::Invocation_Base *invocation_;

  /// Pointer to the caught exception.
  CORBA::Exception *caught_exception_;

  /// Reply status for the current request.
  PortableInterceptor::ReplyStatus reply_status_;

  /// The "Request Scope Current" (RSC) object, as required by
  /// Portable Interceptors.
  TAO::PICurrent_Impl rs_pi_current_;

  /// Callback object to be executed when shallow copied slot table
  /// must be deep copied.
  /**
   * This callback object deep copies the slot table from the TSC to
   * the RSC.
   * @par
   * As an optimization, the TSC's slot table is initially only
   * shallowed copied to the RSC.  If the TSC's slot table will be
   * modified, e.g. via PICurrent::set_slot(), it's slot table must be
   * deep copied to the RSC before actually modifying that slot
   * table.  This is necessary since the RSC is read-only on the
   * client side, meaning that changes in the TSC that occur after
   * instantiation of the RSC must not be reflected in the RSC.
   */
  TAO::PICurrent_Copy_Callback copy_callback_;
};

// -------------------------------------------------------------------

# if defined (__ACE_INLINE__)
#  include "ClientRequestInfo.inl"
# endif  /* __ACE_INLINE__ */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* TAO_HAS_INTERCEPTORS == 1 */

#include /**/ "ace/post.h"

#endif /* TAO_CLIENT_REQUEST_INFO_H */
