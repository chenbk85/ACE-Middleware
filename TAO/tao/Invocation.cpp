// $Id$

#include "tao/Invocation.h"
#include "tao/Principal.h"
#include "tao/Stub.h"

#include "tao/Timeprobe.h"
#include "tao/Object_KeyC.h"
#include "tao/debug.h"
#include "tao/Pluggable.h"
#include "tao/Connector_Registry.h"
#include "tao/Wait_Strategy.h"
#include "tao/Transport_Mux_Strategy.h"
#include "tao/Bind_Dispatcher_Guard.h"
#include "tao/Endpoint.h"
#include "tao/RT_Policy_i.h"

#include "tao/Messaging_Policy_i.h"
#include "tao/GIOP_Utils.h"
#include "tao/ORB_Core.h"

#if !defined (__ACE_INLINE__)
# include "tao/Invocation.i"
#endif /* ! __ACE_INLINE__ */

ACE_RCSID(tao, Invocation, "$Id$")

#if defined (ACE_ENABLE_TIMEPROBES)

static const char *TAO_Invocation_Timeprobe_Description[] =
  {
    "GIOP_Invocation::invoke - start",
    "GIOP_Invocation::invoke - end",

    "GIOP_Invocation::start - enter",
    "GIOP_Invocation::start - leave",
    "GIOP_Invocation::start - connect",
    "GIOP_Invocation::start - start_msg"
  };

enum
  {
    TAO_GIOP_INVOCATION_INVOKE_START = 1000,
    TAO_GIOP_INVOCATION_INVOKE_END,

    TAO_GIOP_INVOCATION_START_ENTER,
    TAO_GIOP_INVOCATION_START_LEAVE,
    TAO_GIOP_INVOCATION_START_CONNECT,
    TAO_GIOP_INVOCATION_START_START_MSG
  };


// Setup Timeprobes
ACE_TIMEPROBE_EVENT_DESCRIPTIONS (TAO_Invocation_Timeprobe_Description,
                                  TAO_GIOP_INVOCATION_INVOKE_START);

#endif /* ACE_ENABLE_TIMEPROBES */

// Normal invocations don't involve any heap al; messages are
// constructed into stack-based buffers and are read into those
// buffers too.  Larger buffers are heap-allocated as needed.
//
// The constraint on request IDs is that no two requests from the same
// client with the same ID are outstanding at the same time.  In
// single threaded environments, this is met by any number whatever.
// When multiple threads are used, we eliminate the need for any
// locked state by using the thread ID as the request ID, since any
// given thread has at most one request outstanding at a time.
//
// NOTE: this means that if "deferred synchronous" calls get
// supported, it's done by creating a thread internally to make the
// call.  That is less disruptive (and error prone) in general than
// restructuring an ORB core in terms of asynchrony.
// ****************************************************************

TAO_GIOP_Invocation::TAO_GIOP_Invocation (TAO_Stub *stub,
                                          const char *operation,
                                          CORBA::ULong opname_len,
                                          TAO_ORB_Core* orb_core)
  : stub_ (stub),
    op_details_ (operation, opname_len),
    out_stream_ (buffer, sizeof buffer, /* ACE_CDR::DEFAULT_BUFSIZE */
                 TAO_ENCAP_BYTE_ORDER,
                 orb_core->output_cdr_buffer_allocator (),
                 orb_core->output_cdr_dblock_allocator (),
                 orb_core->orb_params ()->cdr_memcpy_tradeoff (),
                 orb_core->to_iso8859 (),
                 orb_core->to_unicode ()),
    orb_core_ (orb_core),
    transport_ (0),
    endpoint_selector_ (0),
    is_selector_initialized_ (0),
    profile_ (0),
    endpoint_ (0),
    max_wait_time_ (0),
    ior_info_ (),
    rt_context_initialized_ (0),
    restart_flag_ (0)
{
}

TAO_GIOP_Invocation::~TAO_GIOP_Invocation (void)
{
}

// The public API involves creating an invocation, starting it, filling
// in request parameters, actually performing the invocation, getting
// response parameters, and then cleaning up.  Sometimes they must be
// restarted (e.g. request forwarding).  This is the start/restart entry.

void
TAO_GIOP_Invocation::start (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_FUNCTION_TIMEPROBE (TAO_GIOP_INVOCATION_START_ENTER);
  TAO_MINIMAL_TIMEPROBE (TAO_GIOP_INVOCATION_START_ENTER);

  // First try to bind to the appropriate address.  We do that here
  // since we may get forwarded to a different objref in the course of
  // any given call, with new start () call each time.  It's not
  // cached in the objref data since the connections change
  // asynchronously from objref invocations and this simplifies
  // connection management.
  // We also need to bind *before* marshalling, because different
  // Profiles have different ObjectKeys, thus a change of Profile can
  // result in different alignment for the buffer.
  //
  // THREADING NOTE: this connection is reserved to this call.  Also,
  // starting at this point in the call, new forwarding information
  // will not be used until/unless the call is reissued.  Correctness
  // is not affected, the call will just be forwarded later than it
  // might be in a more complex implementation.

  // @@ assert is evil, it crashes the program, changed to an
  // exception (coryan)
  // assert (this->stub_ != 0);

  if (this->stub_ == 0)
    ACE_THROW (CORBA::INTERNAL (
                 CORBA_SystemException::_tao_minor_code (
                   TAO_DEFAULT_MINOR_CODE,
                   EINVAL),
              CORBA::COMPLETED_NO));

  // Get a pointer to the connector registry, which might be in
  // thread-specific storage, depending on the concurrency model.
  TAO_Connector_Registry *conn_reg =
    this->orb_core_->connector_registry ();

  if (conn_reg == 0)
    ACE_THROW (CORBA::INTERNAL (
                 CORBA_SystemException::_tao_minor_code (
                   TAO_DEFAULT_MINOR_CODE,
                   EINVAL),
                 CORBA::COMPLETED_NO));

  // Initialize endpoint selection strategy.
  if (!this->is_selector_initialized_)
    {
      this->orb_core_->endpoint_selector_factory ()->get_selector (this,
                                                                   ACE_TRY_ENV);
      ACE_CHECK;
      this->is_selector_initialized_ = 1;
    }

#if (TAO_HAS_RELATIVE_ROUNDTRIP_TIMEOUT_POLICY == 1)

  TAO_RelativeRoundtripTimeoutPolicy *timeout_policy =
    this->stub_->relative_roundtrip_timeout ();

  // Automatically release the policy
  CORBA::Object_var auto_release = timeout_policy;

  // If max_wait_time is not zero then this is not the first attempt
  // to send the request, the timeout value includes *all* those
  // attempts.
  if (this->max_wait_time_ == 0
      && timeout_policy != 0)
    {
      timeout_policy->set_time_value (this->max_wait_time_value_);
      this->max_wait_time_ = &this->max_wait_time_value_;
    }

#endif /* TAO_HAS_RELATIVE_ROUNDTRIP_TIMEOUT_POLICY == 1 */

  ACE_Countdown_Time countdown (this->max_wait_time_);

  // Loop until a connection is established or there aren't any more
  // profiles to try.
  for (;;)
    {
      // Allow loaded services to select the profile.
      if (this->stub_->service_profile_selection ())
        {
          this->profile_ = this->stub_->profile_in_use ();
          this->endpoint_ = this->profile_->endpoint ();
        }
      else
        {
          // If loaded services have nothing to say on
          // profile/endpoint selection, let the strategy do the work.
          this->endpoint_selector_->select_endpoint (this, ACE_TRY_ENV);
          ACE_CHECK;
        }

      // Get the transport object.
      if (this->transport_ != 0)
        this->transport_->idle ();

      // Obtain a connection.
      int result = conn_reg->connect (this->endpoint_,
                                      this->transport_,
                                      this->max_wait_time_,
                                      ACE_TRY_ENV);
      ACE_CHECK;

      if (result == 0)
        {
          // Now that we have the client connection handler object we need to
          // set the right messaging protocol for in the client side transport.
          const TAO_GIOP_Version& version = this->profile_->version ();
          result = this->transport_->messaging_init (version.major,
                                                     version.minor);
          if (result == -1)
            {
              if (TAO_debug_level > 0)
                {
                  ACE_DEBUG ((LM_DEBUG,
                              ACE_TEXT ("(%N|%l|%p|%t) ")
                              ACE_TEXT ("messaging_init() failed\n")));
                }
            }
          else
            break;
        }

      if (errno == ETIME)
        {
          ACE_THROW (CORBA::TIMEOUT (
              CORBA_SystemException::_tao_minor_code (
                  TAO_TIMEOUT_CONNECT_MINOR_CODE,
                  errno),
              CORBA::COMPLETED_NO));
        }

      // Try another profile/endpoint.
      this->endpoint_selector_->next (this, ACE_TRY_ENV);
      ACE_CHECK;

      countdown.update ();
    }

  // Obtain unique request id from the RMS.
  this->op_details_.request_id (
        this->transport_->tms ()->request_id ());
}

void
TAO_GIOP_Invocation::prepare_header (CORBA::Octet response_flags,
                                     CORBA_Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Then fill in the rest of the RequestHeader

  // Fill up the service context lists
  // First lookup at the services to see whether they have anything to
  // add to the service context lists
  this->orb_core_->service_context_list (this->stub_,
                                         this->service_info (),
                                         this->restart_flag_,
                                         ACE_TRY_ENV);
  ACE_CHECK;

  this->add_rt_service_context (ACE_TRY_ENV);
  ACE_CHECK;

  // The target specification mode
  if (this->stub_->addressing_mode () ==
      TAO_Target_Specification::Key_Addr)
    {
      this->target_spec_.target_specifier (
            this->profile_->object_key ());
    }
  else if (this->stub_->addressing_mode () ==
           TAO_Target_Specification::Profile_Addr)
    {
      this->target_spec_.target_specifier (
            this->profile_->create_tagged_profile ());
    }
  else if (this->stub_->addressing_mode () ==
           TAO_Target_Specification::Reference_Addr)
    {
      // We need to call the method seperately. If there is no
      // IOP::IOR info, the call would create the info and return the
      // index that we need.
      // @@Will not work for RT CORBA as the index we get would be
      // wrong.
      CORBA::ULong index = this->create_ior_info ();
      this->target_spec_.target_specifier (this->ior_info_,
                                           index);
    }

  // Update the response flags
  this->op_details_.response_flags (response_flags);

  // Send the request for the header
  if (this->transport_->send_request_header (this->op_details_,
                                             this->target_spec_,
                                             this->out_stream_) == 0)
    ACE_THROW (CORBA::MARSHAL ());
}


// Send request.
int
TAO_GIOP_Invocation::invoke (CORBA::Boolean is_roundtrip,
                             CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_Countdown_Time countdown (this->max_wait_time_);

  if (this->transport_ == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (),
                      TAO_INVOKE_EXCEPTION);

  // @@ Alex: the <is_roundtrip> flag will be tricky when we move to
  //    AMI: now it is used both to indicate the the CORBA request in
  //    a twoway and that the send_request() operation should block.
  //    Even for oneways: with AMI it is possible to wait for a
  //    response (empty) for oneways, just to make sure that they
  //    arrive, there are policies to control that.

  int result =
    this->transport_->send_request (this->stub_,
                                    this->orb_core_,
                                    this->out_stream_,
                                    is_roundtrip,
                                    this->max_wait_time_);

  //
  // @@ highly desirable to know whether we wrote _any_ data; if
  // we wrote none, then there's no chance the call completed and
  // applications don't have to deal with those nasty
  // indeterminate states where they can't immediatly tell if
  // what's safe to do.
  //
  // @@ also, there might have been a GIOP::CloseConnection
  // message in the input queue.  If so, this request should be
  // treated as a (full) "rebind" case.  Can't do that from this
  // point in the code however!  Some minor restructuring needs to
  // happen.
  //

  if (result == -1)
    {
      if (errno == ETIME)
        {
          ACE_THROW_RETURN (
              CORBA::TIMEOUT (
                  CORBA_SystemException::_tao_minor_code (
                      TAO_TIMEOUT_SEND_MINOR_CODE,
                      errno
                    ),
                  CORBA::COMPLETED_NO
                ),
              TAO_INVOKE_EXCEPTION
            );
        }
      this->transport_->close_connection ();
      this->transport_ = 0;

      this->endpoint_->reset_hint ();

      return TAO_INVOKE_RESTART;
    }

  // Indicate that the endpoint/profile was used successfully.
  // @@ Maybe the right place to do this is once the reply is
  //    received? But what about oneways?
  this->endpoint_selector_->success (this);

  return TAO_INVOKE_OK;
}

int
TAO_GIOP_Invocation::close_connection (void)
{
  // Special case of forwarding -- server was closing the
  // connection, which just indicates resource constraints, not an
  // error.  The client is effectively "forwarded" to the same
  // server!
  //
  // However, we must reinitialize the forwarding chain, since the
  // resource being reclaimed might also have been the process,
  // not just the connection.  Without reinitializing, we'd give
  // false error reports to applications.

  this->transport_->close_connection ();
  this->transport_->idle ();
  this->transport_ = 0;

  this->endpoint_->reset_hint ();
  this->endpoint_ = 0;
  this->profile_ = 0;

  this->endpoint_selector_->close_connection (this);

  return TAO_INVOKE_RESTART;
}

// Handle the GIOP Reply with status = LOCATION_FORWARD
// Replace the IIOP Profile.

int
TAO_GIOP_Invocation::location_forward (TAO_InputCDR &inp_stream,
                                       CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // It can be assumed that the GIOP header and the reply header
  // are already handled. Further it can be assumed that the
  // reply body contains an object reference to the new object.
  // This object pointer will be now extracted.

  CORBA::Object_var object = 0;

  if ( (inp_stream >> object.inout ()) == 0)
      ACE_THROW_RETURN (CORBA::MARSHAL (),
                        TAO_INVOKE_EXCEPTION);

  // The object pointer has to be changed to a TAO_Stub pointer
  // in order to obtain the profiles.
  TAO_Stub *stubobj = object->_stubobj ();

  if (stubobj == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (),
                      TAO_INVOKE_EXCEPTION);

  // Modify the state as appropriate to include new forwarding profiles.
  this->endpoint_selector_->forward (this,
                                     stubobj->base_profiles (),
                                     ACE_TRY_ENV);
  ACE_CHECK_RETURN (TAO_INVOKE_EXCEPTION);

  return TAO_INVOKE_RESTART;
}


CORBA::ULong
TAO_GIOP_Invocation::create_ior_info (void)
{
  // Get the list of profiles
  const TAO_MProfile &mprofile =
    this->stub_->base_profiles ();

  if (this->ior_info_.profiles.length () == 0)
    {
      // We are making a copy, it is expensive. We want a copy of the
      // profiles as we dont want to modify the profile set held by
      // the Stub classes. We may want to hold a lock for doing
      // that. To avoid unnecssary complications we make a copy and
      // get the info

      // @@ There should be a better way to do this - Bala
      TAO_MProfile *multi_prof =
        this->stub_->make_profiles ();

      // Get the number of elements
      CORBA::ULong count = multi_prof->profile_count ();

      // Set the number of elements in the sequence of tagged_profile
      this->ior_info_.profiles.length (count);

      // Call the create_tagged_profile one every member of the
      // profile and make the sequence
      for (CORBA::ULong index = 0;
           index < count;
           ++index)
        {
          TAO_Profile *prof =
            multi_prof->get_profile (index);

          this->ior_info_.profiles[index] =
            prof->create_tagged_profile ();
        }

      delete multi_prof;
    }

  return mprofile.get_current_handle ();
}

void
TAO_GIOP_Invocation::add_rt_service_context (CORBA_Environment
                                             &ACE_TRY_ENV)
{
  // RTCORBA-specific processing.
  // If invocation target supports RTCORBA::CLIENT_PROPAGATED priority
  // model, we must add IOP::RTCorbaPriority service context to the
  // list.

#if (TAO_HAS_RT_CORBA == 1)

  // This function may get called multiple times, but we only need to
  // perform the processing once.
  if (this->rt_context_initialized_)
    return;

  if (this->endpoint_selection_state_.priority_model_policy_)
    {
      if (this->endpoint_selection_state_.priority_model_policy_->
          get_priority_model () == RTCORBA::CLIENT_PROPAGATED)
        {
          // Encapsulate the priority of the current thread into
          // a service context.
          TAO_OutputCDR cdr;
          if ((cdr << ACE_OutputCDR::from_boolean (TAO_ENCAP_BYTE_ORDER)
               == 0)
              || (cdr << this->endpoint_selection_state_.client_priority_)
              == 0)
            ACE_THROW (CORBA::MARSHAL ());

          IOP::ServiceContextList &context_list =
            this->service_info ();

          CORBA::ULong l = context_list.length ();
          context_list.length (l + 1);
          context_list[l].context_id = IOP::RTCorbaPriority;

          // Make a *copy* of the CDR stream...
          CORBA::ULong length = cdr.total_length ();
          context_list[l].context_data.length (length);
          CORBA::Octet *buf = context_list[l].context_data.get_buffer ();

          for (const ACE_Message_Block *i = cdr.begin ();
               i != 0;
               i = i->cont ())
            {
              ACE_OS::memcpy (buf, i->rd_ptr (), i->length ());
              buf += i->length ();
            }
        }
    }
  else
    {
      // The Object does not contain PriorityModel policy in its IOR.
      // We must be talking to a non-RT ORB.  Do nothing.
    }

  this->rt_context_initialized_ = 1;

#else
  ACE_UNUSED_ARG (ACE_TRY_ENV);

#endif /* TAO_HAS_RT_CORBA == 1 */
}

// ****************************************************************

TAO_GIOP_Twoway_Invocation::~TAO_GIOP_Twoway_Invocation (void)
{
  if (this->transport_ != 0)
    this->transport_->idle_after_reply ();
}

void
TAO_GIOP_Twoway_Invocation::start (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->TAO_GIOP_Invocation::start (ACE_TRY_ENV);
  ACE_CHECK;

  this->target_spec_.target_specifier (this->profile_->object_key ());
  this->transport_->start_request (this->orb_core_,
                                   this->target_spec_,
                                   this->out_stream_,
                                   ACE_TRY_ENV);
  ACE_CHECK;
  this->rd_.reply_received () = 0;
}

int
TAO_GIOP_Twoway_Invocation::invoke (CORBA::ExceptionList_ptr exceptions,
                                    CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException,CORBA::UnknownUserException))
{
  TAO_FUNCTION_PP_TIMEPROBE (TAO_GIOP_INVOCATION_INVOKE_START);

  int retval = this->invoke_i (ACE_TRY_ENV);
  ACE_CHECK_RETURN (retval);

  // A TAO_INVOKE_EXCEPTION status, but no exception raised means that
  // we have a user exception.
  // @@ This is a bit brittle, think about a better implementation.
  if (retval == TAO_INVOKE_EXCEPTION)
    {
      // Match the exception interface repository id with the
      // exception in the exception list.
      // This is important to decode the exception.

      CORBA::String_var buf;

      TAO_InputCDR tmp_stream (this->inp_stream (),
                               this->inp_stream ().start ()->length (),
                               0);

      // Pull the exception ID out of the marshaling buffer.
      if (tmp_stream.read_string (buf.inout ()) == 0)
        {
          ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE,
                                            CORBA::COMPLETED_YES),
                            TAO_INVOKE_EXCEPTION);
        }

      for (CORBA::ULong i = 0;
           exceptions != 0 && i < exceptions->count ();
           i++)
        {
          CORBA::TypeCode_ptr tcp =
            exceptions->item (i, ACE_TRY_ENV);
          ACE_CHECK_RETURN (TAO_INVOKE_EXCEPTION);

          const char *xid = tcp->id (ACE_TRY_ENV);
          ACE_CHECK_RETURN (TAO_INVOKE_EXCEPTION);

          if (ACE_OS::strcmp (buf.in (), xid) != 0)
            continue;

          // @@ In the old days the exceptions where catched and the
          // connection was closed, that doesn't make any sense:
          // this is a client side problem, for one particular
          // request.
          // this->transport_->close_connection ();
          // ACE_RE_THROW;

          const ACE_Message_Block* cdr =
            this->inp_stream ().start ();
          CORBA_Any any (tcp, 0,
                         this->inp_stream ().byte_order (),
                         cdr);
          CORBA_Exception *exception;

          ACE_NEW_THROW_EX (exception,
                            CORBA_UnknownUserException (any),
                            CORBA::NO_MEMORY (TAO_DEFAULT_MINOR_CODE,
                                              CORBA::COMPLETED_YES));
          ACE_CHECK_RETURN (TAO_INVOKE_EXCEPTION);

          // @@ Think about a better way to raise the exception here,
          //    maybe we need some more macros?
          ACE_TRY_ENV.exception (exception);  // We can not use ACE_THROW here.
          return TAO_INVOKE_EXCEPTION;
        }

      // If we couldn't find the right exception, report it as
      // CORBA::UNKNOWN.

      // @@ It would seem like if the remote exception is a
      //    UserException we can assume that the request was
      //    completed.
      ACE_THROW_RETURN (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE,
                                        CORBA::COMPLETED_YES),
                        TAO_INVOKE_EXCEPTION);
    }

  return retval;
}

// Send request, block until any reply comes back, and unmarshal reply
// parameters as appropriate.
//
// This is used by the generated stubs.

int
TAO_GIOP_Twoway_Invocation::invoke (TAO_Exception_Data *excepts,
                                    CORBA::ULong except_count,
                                    CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::Exception))
{
  TAO_FUNCTION_PP_TIMEPROBE (TAO_GIOP_INVOCATION_INVOKE_START);

  int retval = this->invoke_i (ACE_TRY_ENV);
  ACE_CHECK_RETURN (retval);

  // A TAO_INVOKE_EXCEPTION status, but no exception raised means that
  // we have a user exception.
  // @@ This is a bit brittle, think about a better implementation.
  if (retval == TAO_INVOKE_EXCEPTION)
    {
      // Match the exception interface repository id with the
      // exception in the exception list.
      // This is important to decode the exception.

      CORBA::String_var buf;

      // Pull the exception ID out of the marshaling buffer.
      if (this->inp_stream ().read_string (buf.inout ()) == 0)
        {
          // @@ Why do we close the connection. Only the request
          //    failed, but the connection seems to be still
          //    valid!
          // this->transport_->close_connection ();
          ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE,
                                            CORBA::COMPLETED_YES),
                            TAO_INVOKE_EXCEPTION);
        }

      for (CORBA::ULong i = 0;
           i < except_count;
           i++)
        {
          CORBA::TypeCode_ptr tcp = excepts[i].tc;
          const char *xid = tcp->id (ACE_TRY_ENV);
          ACE_CHECK_RETURN (TAO_INVOKE_EXCEPTION);

          if (ACE_OS::strcmp (buf.in (), xid) != 0)
            continue;

          // match
          CORBA::Exception *exception = excepts[i].alloc ();

          if (exception == 0)
            ACE_THROW_RETURN (CORBA::NO_MEMORY (TAO_DEFAULT_MINOR_CODE,
                                                CORBA::COMPLETED_YES),
                              TAO_INVOKE_EXCEPTION);

          exception->_tao_decode (this->inp_stream (),
                                  ACE_TRY_ENV);
          ACE_CHECK_RETURN (TAO_INVOKE_EXCEPTION);

          if (TAO_debug_level > 5)
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("TAO: (%P|%t) Raising exception %s\n"),
                        buf.in ()));

          // @@ Think about a better way to raise the exception here,
          //    maybe we need some more macros?
          ACE_TRY_ENV.exception (exception); // We can not use ACE_THROW here.
          return TAO_INVOKE_EXCEPTION;
        }

      // If we couldn't find the right exception, report it as
      // CORBA::UNKNOWN.

      ACE_THROW_RETURN (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE,
                                        CORBA::COMPLETED_YES),
                        TAO_INVOKE_EXCEPTION);
    }

  return retval;
}

int
TAO_GIOP_Twoway_Invocation::invoke_i (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Register a reply dispatcher for this invocation. Use the
  // preallocated reply dispatcher.

  // Bind.

  TAO_Transport_Mux_Strategy *tms = this->transport_->tms ();

  TAO_Bind_Dispatcher_Guard dispatch_guard(this->op_details_.request_id(),
                                           &this->rd_,
                                           tms);
  int retval = dispatch_guard.status();

  if (retval == -1)
    {
      // @@ What is the right way to handle this error?
      this->close_connection ();

      ACE_THROW_RETURN (CORBA::INTERNAL (TAO_DEFAULT_MINOR_CODE,
                                         CORBA::COMPLETED_NO),
                        TAO_INVOKE_EXCEPTION);
    }

  // Just send the request, without trying to wait for the reply.
  retval = TAO_GIOP_Invocation::invoke (1, ACE_TRY_ENV);
  ACE_CHECK_RETURN (retval);

  if (retval != TAO_INVOKE_OK)
    return retval;

  // This blocks until the response is read.  In the current version,
  // there is only one client thread that ever uses this connection,
  // so most response messages are illegal.
  //
  // @@ In all MT environments, there's a cancellation point lurking
  // here; need to investigate.  Client threads would frequently be
  // canceled sometime during recv_request ... the correct action to
  // take on being canceled is to issue a CancelRequest message to the
  // server and then imediately let other client-side cancellation
  // handlers do their jobs.
  //
  // In C++, that basically means to unwind the stack using almost
  // normal procedures: all destructors should fire, and some "catch"
  // blocks should probably be able to handle things like releasing
  // pointers. (Without unwinding the C++ stack, resources that must
  // be freed by thread cancellation won't be freed, and the process
  // won't continue to function correctly.)  The tricky part is that
  // according to POSIX, all C stack frames must also have their
  // (explicitly coded) handlers called.  We assume a POSIX.1c/C/C++
  // environment.

  // Get the reply status.

  // Wait for the reply.

  if (TAO_debug_level > 0 && this->max_wait_time_ != 0)
    {
      CORBA::ULong msecs =
        this->max_wait_time_->msec ();

      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("TAO (%P|%t) Timeout on recv is <%u>\n"),
                  msecs));
    }

  int reply_error =
    this->transport_->wait_strategy ()->wait (this->max_wait_time_,
                                              this->rd_.reply_received ());


  if (TAO_debug_level > 0 && this->max_wait_time_ != 0)
    {
      CORBA::ULong msecs =
        this->max_wait_time_->msec ();

      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("TAO (%P|%t) Timeout after recv is <%u> status <%d>\n"),
                  msecs, reply_error));
    }

  // Check the reply error.

  if (reply_error == -1)
    {
      // The guard automatically unbinds the dispatcher
      if (errno == ETIME)
        {
          // Just a timeout, don't close the connection or
          // anything...
          ACE_THROW_RETURN (CORBA::TIMEOUT (
              CORBA_SystemException::_tao_minor_code (
                  TAO_TIMEOUT_SEND_MINOR_CODE,
                  errno),
              CORBA::COMPLETED_NO),
            TAO_INVOKE_EXCEPTION);
        }

      // Call the ORB Core which would check whether we need to really
      // raise an exception or are we going to base our decision on the
      // loaded services.
      return this->orb_core_->service_raise_comm_failure (this,
                                                          this->profile_,
                                                          ACE_TRY_ENV);
    }

  // @@ Alex: the old version of this had some error handling code,
  //    like:  this->profile_->reset_hint ()
  //    Can you make sure we don't forget to do that on exceptions
  //    and/or errors.
  //    BTW, think about native exceptions where if the exception is
  //    raised in the wait() method you won't get a chance
  //    to do that kind of error handling.  Do you really need
  //    exceptions in the transport objects?

  CORBA::ULong reply_status = this->rd_.reply_status ();

  switch (reply_status)
    {
    case TAO_PLUGGABLE_MESSAGE_NO_EXCEPTION:
      // Return so that the STUB can demarshal the reply.
      return TAO_INVOKE_OK;

    case TAO_PLUGGABLE_MESSAGE_USER_EXCEPTION:
      // Return so the exception can be handled.
      return TAO_INVOKE_EXCEPTION;

    case TAO_PLUGGABLE_MESSAGE_SYSTEM_EXCEPTION:
      {
        // @@ Add the location macros for this exceptions...

        CORBA::String_var type_id;

        if ((this->inp_stream () >> type_id.inout ()) == 0)
          {
            // Could not demarshal the exception id, raise an local
            // CORBA::MARSHAL
            ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE,
                                              CORBA::COMPLETED_MAYBE),
                              TAO_INVOKE_OK);
          }

        CORBA::ULong minor = 0;
        CORBA::ULong completion = 0;

        if ((this->inp_stream () >> minor) == 0
            || (this->inp_stream () >> completion) == 0)
          ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE,
                                            CORBA::COMPLETED_MAYBE),
                            TAO_INVOKE_OK);

        CORBA::SystemException* ex =
          TAO_Exceptions::create_system_exception (type_id.in (),
                                                   ACE_TRY_ENV);
        ACE_CHECK_RETURN (TAO_INVOKE_OK);

        if (ex == 0)
          {
            // @@ We should raise a CORBA::NO_MEMORY, but we ran out
            //    of memory already. We need a pre-allocated, TSS,
            //    CORBA::NO_MEMORY instance
            ACE_NEW_RETURN (ex,
                            CORBA::UNKNOWN,
                            TAO_INVOKE_EXCEPTION);
          }

        ex->minor (minor);
        ex->completed (CORBA::CompletionStatus (completion));


        // @@ There should be a better way to raise this exception!
        //    This code works for both native and emulated exceptions,
        //    but it is ugly.
        ACE_TRY_ENV.exception (ex); // We can not use ACE_THROW here.
        return TAO_INVOKE_OK;
      }
      // NOTREACHED.

    case TAO_PLUGGABLE_MESSAGE_LOCATION_FORWARD:
      // Handle the forwarding and return so the stub restarts the
      // request!
      return this->location_forward (this->inp_stream (), ACE_TRY_ENV);
    case TAO_PLUGGABLE_MESSAGE_NEEDS_ADDRESSING_MODE:
      {
        // We have received an exception with a request to change the
        // addressing mode. First let us read the mode that the
        // server/agent asks for.
        CORBA::Short addr_mode = 0;
        if (this->inp_stream ().read_short (addr_mode) == 0)
          {
            // Could not demarshal the addressing disposition, raise an local
            // CORBA::MARSHAL
            ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE,
                                              CORBA::COMPLETED_MAYBE),
                              TAO_INVOKE_OK);
          }

        // Now set this addressing mode in the stub object, so that
        // the next invocation need not go through this.
        this->stub_->addressing_mode (addr_mode);

        // Now restart the invocation
        return TAO_INVOKE_RESTART;
      }

    }

  return TAO_INVOKE_OK;
}

// ****************************************************************

TAO_GIOP_Oneway_Invocation::
TAO_GIOP_Oneway_Invocation (TAO_Stub *stub,
                            const char *operation,
                            CORBA::ULong opname_len,
                            TAO_ORB_Core *orb_core)
  : TAO_GIOP_Invocation (stub, operation, opname_len, orb_core),
    sync_scope_ (TAO::SYNC_WITH_TRANSPORT)
{
#if (TAO_HAS_SYNC_SCOPE_POLICY == 1)

  TAO_Sync_Scope_Policy *ssp = stub->sync_scope ();

  // Automatically release the policy
  CORBA::Object_var auto_release = ssp;

  if (ssp)
    {
      ssp->get_synchronization (this->sync_scope_);
    }

#endif /* TAO_HAS_SYNC_SCOPE_POLICY == 1 */
}

TAO_GIOP_Oneway_Invocation::~TAO_GIOP_Oneway_Invocation (void)
{
  if (this->transport_ != 0)
    this->transport_->idle_after_reply ();
}

void
TAO_GIOP_Oneway_Invocation::start (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->TAO_GIOP_Invocation::start (ACE_TRY_ENV);
  ACE_CHECK;

  // Make sure that you have the right object key
  this->target_spec_.target_specifier (this->profile_->object_key ());

  this->transport_->start_request (this->orb_core_,
                                   this->target_spec_,
                                   this->out_stream_,
                                   ACE_TRY_ENV);
}

int
TAO_GIOP_Oneway_Invocation::invoke (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (this->sync_scope_ == TAO::SYNC_WITH_TRANSPORT ||
      this->sync_scope_ == TAO::SYNC_NONE ||
      this->sync_scope_ == TAO::SYNC_EAGER_BUFFERING ||
      this->sync_scope_ == TAO::SYNC_DELAYED_BUFFERING)
    {
      return TAO_GIOP_Invocation::invoke (0,
                                          ACE_TRY_ENV);
    }

  // Create this only if a reply is required.
  TAO_Synch_Reply_Dispatcher rd (this->orb_core_,
                                 this->op_details_.service_info ());

  // The rest of this function is very similar to
  // TWO_GIOP_Twoway_Invocation::invoke_i, because we must
  // wait for a reply. See comments in that code.
  // @@ Jeff: is it possible to factor out this code into a common
  // case class or something?  In fact, what is the difference between
  // the two classes now?
  TAO_Transport_Mux_Strategy *tms = this->transport_->tms ();

  TAO_Bind_Dispatcher_Guard dispatch_guard(this->op_details_.request_id(),
                                           &rd,
                                           tms);
  int retval = dispatch_guard.status();

  if (retval == -1)
    {
      // @@ What is the right way to handle this error?
      this->close_connection ();

      ACE_THROW_RETURN (CORBA::INTERNAL (TAO_DEFAULT_MINOR_CODE,
                                         CORBA::COMPLETED_NO),
                        TAO_INVOKE_EXCEPTION);
    }

  // Send the request.
  retval = TAO_GIOP_Invocation::invoke (1,
                                        ACE_TRY_ENV);
  ACE_CHECK_RETURN (retval);

  if (retval != TAO_INVOKE_OK)
    return retval;

  // Wait for the reply.
  if (TAO_debug_level > 0 && this->max_wait_time_ != 0)
    {
      CORBA::ULong msecs =
        this->max_wait_time_->msec ();

      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("TAO (%P|%t) Timeout on recv is <%u>\n"),
                  msecs));
    }

  int reply_error =
    this->transport_->wait_strategy ()->wait (this->max_wait_time_,
                                              rd.reply_received ());


  if (TAO_debug_level > 0 && this->max_wait_time_ != 0)
    {
      CORBA::ULong msecs =
        this->max_wait_time_->msec ();

      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("TAO (%P|%t) Timeout after recv is <%u> status <%d>\n"),
                  msecs, reply_error));
    }

  // Check the reply error.
  if (reply_error == -1)
    {
      // The guard automatically unbinds the dispatcher
      if (errno == ETIME)
        {
          // Just a timeout, don't close the connection or
          // anything...
          ACE_THROW_RETURN (CORBA::TIMEOUT (
              CORBA_SystemException::_tao_minor_code (
                  TAO_TIMEOUT_SEND_MINOR_CODE,
                  errno),
              CORBA::COMPLETED_NO),
            TAO_INVOKE_EXCEPTION);
        }

      return this->orb_core_->service_raise_comm_failure (this,
                                                          this->profile_,
                                                          ACE_TRY_ENV);
    }

  CORBA::ULong reply_status = rd.reply_status ();

  switch (reply_status)
    {
    case TAO_PLUGGABLE_MESSAGE_NO_EXCEPTION:
      // Return so that the STUB can demarshal the reply.
      return TAO_INVOKE_OK;

    case TAO_PLUGGABLE_MESSAGE_USER_EXCEPTION:
      {
        // Pull the exception from the stream.
        CORBA::String_var buf;

        if ((rd.reply_cdr () >> buf.inout ()) == 0)
          {
            // Could not demarshal the exception id, raise an local
            // CORBA::MARSHAL
            ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE,
                                              CORBA::COMPLETED_MAYBE),
                              TAO_INVOKE_EXCEPTION);
          }

        // This kind of exception shouldn't happen with oneways,
        // but if it does, we turn it into a CORBA::UNKNOWN exception.
        ACE_THROW_RETURN (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE,
                                          CORBA::COMPLETED_YES),
                          TAO_INVOKE_EXCEPTION);
      }

    case TAO_PLUGGABLE_MESSAGE_SYSTEM_EXCEPTION:
      {
        // @@ Add the location macros for these exceptions...

        CORBA::String_var type_id;

        if ((rd.reply_cdr () >> type_id.inout ()) == 0)
          {
            // Could not demarshal the exception id, raise a local
            // CORBA::MARSHAL
            ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE,
                                              CORBA::COMPLETED_MAYBE),
                              TAO_INVOKE_OK);
          }

        CORBA::ULong minor = 0;
        CORBA::ULong completion = 0;

        if ((rd.reply_cdr () >> minor) == 0
            || (rd.reply_cdr () >> completion) == 0)
          ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE,
                                            CORBA::COMPLETED_MAYBE),
                            TAO_INVOKE_OK);

        CORBA::SystemException* ex =
          TAO_Exceptions::create_system_exception (type_id.in (),
                                                   ACE_TRY_ENV);
        ACE_CHECK_RETURN (TAO_INVOKE_OK);

        if (ex == 0)
          {
            // @@ We should raise a CORBA::NO_MEMORY, but we ran out
            //    of memory already. We need a pre-allocated, TSS,
            //    CORBA::NO_MEMORY instance
            ACE_NEW_RETURN (ex,
                            CORBA::UNKNOWN,
                            TAO_INVOKE_EXCEPTION);
          }

        ex->minor (minor);
        ex->completed (CORBA::CompletionStatus (completion));

        // @@ There should be a better way to raise this exception!
        //    This code works for both native and emulated exceptions,
        //    but it is ugly.
        ACE_TRY_ENV.exception (ex); // We can not use ACE_THROW here.
        return TAO_INVOKE_OK;
      }

    case TAO_PLUGGABLE_MESSAGE_LOCATION_FORWARD:
      // Handle the forwarding and return so the stub restarts the
      // request!
      return this->location_forward (rd.reply_cdr (),
                                     ACE_TRY_ENV);
    case TAO_PLUGGABLE_MESSAGE_NEEDS_ADDRESSING_MODE:
      {
        // We have received an exception with a request to change the
        // addressing mode. First let us read the mode that the
        // server/agent asks for.
        CORBA::Short addr_mode = 0;
        if (rd.reply_cdr ().read_short (addr_mode) == 0)
          {
            // Could not demarshal the addressing disposition, raise an local
            // CORBA::MARSHAL
            ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE,
                                              CORBA::COMPLETED_MAYBE),
                              TAO_INVOKE_OK);
          }

        // Now set this addressing mode in the stub object, so that
        // the next invocation need not go through this.
        this->stub_->addressing_mode (addr_mode);

        // Now restart the invocation
        return TAO_INVOKE_RESTART;
      }
    }

  return TAO_INVOKE_OK;
}

// ****************************************************************

TAO_GIOP_Locate_Request_Invocation::~TAO_GIOP_Locate_Request_Invocation (void)
{
  if (this->transport_ != 0)
    this->transport_->idle_after_reply ();
}

// Send request, block until any reply comes back.
void
TAO_GIOP_Locate_Request_Invocation::start (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->TAO_GIOP_Invocation::start (ACE_TRY_ENV);
  ACE_CHECK;

  // Just make sure that you pass in the object key
  this->target_spec_.target_specifier (this->profile_->object_key ());

  this->transport_->start_locate (this->orb_core_,
                                  this->target_spec_,
                                  this->op_details_,
                                  this->out_stream_,
                                  ACE_TRY_ENV);
  this->rd_.reply_received () = 0;
}

int
TAO_GIOP_Locate_Request_Invocation::invoke (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // @@ TODO This method is very similar to invoke_i(), we should try
  //    to refactor them.

  if (this->transport_ == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (),
                      TAO_INVOKE_EXCEPTION);

  // Register a reply dispatcher for this invocation. Use the
  // preallocated reply dispatcher.

  // Bind.
  TAO_Transport_Mux_Strategy *tms = this->transport_->tms ();

  TAO_Bind_Dispatcher_Guard dispatch_guard (this->op_details_.request_id(),
                                            &this->rd_,
                                            tms);
  int retval = dispatch_guard.status();

  if (retval == -1)
    {
      // @@ What is the right way to handle this error?
      this->close_connection ();

      ACE_THROW_RETURN (CORBA::INTERNAL (TAO_DEFAULT_MINOR_CODE,
                                         CORBA::COMPLETED_NO),
                        TAO_INVOKE_EXCEPTION);
    }

  int result =
    this->transport_->send_request (this->stub_,
                                    this->orb_core_,
                                    this->out_stream_,
                                    1,
                                    this->max_wait_time_);


  if (result == -1)
    {
      this->transport_->close_connection ();
      this->transport_ = 0;

      this->endpoint_->reset_hint ();

      // @@ This code abort if the connection for the currenct profile
      //    fails.  Should we transparently try new profiles until one
      //    works? Or is that something that a higher level component
      //    should decide?  Remember that LocateRequests are part of
      //    the strategy to establish a connection.

      return this->orb_core_->service_raise_transient_failure (this,
                                                               this->profile_,
                                                               ACE_TRY_ENV);

    }

  // @@ Maybe the right place to do this is once the reply is
  //    received? But what about oneways?
  this->endpoint_selector_->success (this);

  // Wait for the reply.
  int reply_error =
    this->transport_->wait_strategy ()->wait (this->max_wait_time_,
                                              this->rd_.reply_received ());

  // Check the reply error.
  if (reply_error == -1)
    {
      // The guard automatically unbinds the dispatcher
      if (errno == ETIME)
        {
          // Just a timeout, don't close the connection or
          // anything...
          ACE_THROW_RETURN (CORBA::TIMEOUT (
              CORBA_SystemException::_tao_minor_code (
                  TAO_TIMEOUT_SEND_MINOR_CODE,
                  errno),
              CORBA::COMPLETED_NO),
            TAO_INVOKE_EXCEPTION);
        }

      return this->orb_core_->service_raise_comm_failure (this,
                                                          this->profile_,
                                                          ACE_TRY_ENV);
    }

  CORBA::ULong locate_status = this->rd_.reply_status ();

  switch (locate_status)
    {
    case TAO_GIOP_OBJECT_HERE:
      break;

    case TAO_GIOP_UNKNOWN_OBJECT:
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (TAO_DEFAULT_MINOR_CODE,
                                                 CORBA::COMPLETED_YES),
                        TAO_INVOKE_EXCEPTION);
      // NOTREACHED

    case TAO_GIOP_OBJECT_FORWARD:
      return this->location_forward (this->inp_stream (),
                                     ACE_TRY_ENV);
    case TAO_GIOP_LOC_SYSTEM_EXCEPTION:
      {
        // What else do we do??
        // Pull the exception from the stream.
        CORBA::String_var buf;

        if ((this->rd_.reply_cdr () >> buf.inout ()) == 0)
          {
            // Could not demarshal the exception id, raise an local
            // CORBA::MARSHAL
            ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE,
                                              CORBA::COMPLETED_MAYBE),
                              TAO_INVOKE_EXCEPTION);
          }

        // This kind of exception shouldn't happen with oneways,
        // but if it does, we turn it into a CORBA::UNKNOWN exception.
        ACE_THROW_RETURN (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE,
                                          CORBA::COMPLETED_YES),
                          TAO_INVOKE_EXCEPTION);
      }
    case TAO_GIOP_LOC_NEEDS_ADDRESSING_MODE:
      {
        // We have received an exception with a request to change the
        // addressing mode. First let us read the mode that the
        // server/agent asks for.
        CORBA::Short addr_mode = 0;
        if (this->rd_.reply_cdr ().read_short (addr_mode) == 0)
          {
            // Could not demarshal the addressing disposition, raise an local
            // CORBA::MARSHAL
            ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE,
                                              CORBA::COMPLETED_MAYBE),
                              TAO_INVOKE_OK);
          }

        // Now set this addressing mode in the stub object, so that
        // the next invocation need not go through this.
        this->stub_->addressing_mode (addr_mode);

        // Now restart the invocation
        return TAO_INVOKE_RESTART;
      }
    }

  return TAO_INVOKE_OK;
}

// ****************************************************************

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
