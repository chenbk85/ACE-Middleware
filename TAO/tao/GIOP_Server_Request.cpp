// $Id$

// Implementation of the Dynamic Server Skeleton Interface  (for GIOP)

#include "tao/GIOP_Server_Request.h"

#include "tao/CDR.h"
#include "tao/POAC.h"
#include "tao/Environment.h"
#include "tao/NVList.h"
#include "tao/Principal.h"
#include "tao/ORB_Core.h"
#include "tao/ORB.h"
#include "tao/Timeprobe.h"
#include "tao/Any.h"

#if !defined (__ACE_INLINE__)
# include "tao/GIOP_Server_Request.i"
#endif /* ! __ACE_INLINE__ */

ACE_RCSID(tao, GIOP_Server_Request, "$Id$")

#if defined (ACE_ENABLE_TIMEPROBES)

static const char *TAO_Server_Request_Timeprobe_Description[] =
  {
    "GIOP_Server_Request::GIOP_Server_Request - start",
    "GIOP_Server_Request::GIOP_Server_Request - end",
  };

enum
  {
    // Timeprobe description table start key
    TAO_SERVER_REQUEST_START = 400,
    TAO_SERVER_REQUEST_END
  };

// Setup Timeprobes
ACE_TIMEPROBE_EVENT_DESCRIPTIONS (TAO_Server_Request_Timeprobe_Description,
                                  TAO_SERVER_REQUEST_START);

#endif /* ACE_ENABLE_TIMEPROBES */

TAO_GIOP_ServerRequest::
    TAO_GIOP_ServerRequest (TAO_InputCDR &input,
                            TAO_OutputCDR &output,
                            TAO_ORB_Core *orb_core,
                            const TAO_GIOP_Version &version,
                            int &parse_error)
  : incoming_ (&input),
    outgoing_ (&output),
    response_expected_ (0),

#if !defined (TAO_HAS_MINIMUM_CORBA)

    params_ (0),

#endif /* TAO_HAS_MINIMUM_CORBA */

    retval_ (0),
    exception_ (0),
    exception_type_ (TAO_GIOP_NO_EXCEPTION),
    orb_core_ (orb_core),
    version_ (version),
    service_info_ (),
    request_id_ (0),
    object_key_ (),
    requesting_principal_ (0)
{
  ACE_FUNCTION_TIMEPROBE (TAO_SERVER_REQUEST_START);

  parse_error = this->parse_header ();
}

int
TAO_GIOP_ServerRequest::parse_header_std (void)
{
  // Tear out the service context ... we currently ignore it, but it
  // should probably be passed to each ORB service as appropriate
  // (e.g. transactions, security).
  //
  // NOTE: As security support kicks in, this is a good place to
  // verify a digital signature, if that is required in this security
  // environment.  It may be required even when using IPSEC security
  // infrastructure.

  TAO_InputCDR& input = *this->incoming_;

  input >> this->service_info_;
  CORBA::Boolean hdr_status = (CORBA::Boolean) input.good_bit ();

  // Get the rest of the request header ...

  hdr_status = hdr_status && input.read_ulong (this->request_id_);
  hdr_status = hdr_status && input.read_boolean (this->response_expected_);

  // We use ad-hoc demarshalling here: there is no need to increase
  // the reference count on the CDR message block, because this key
  // will not outlive the request (or the message block).

  CORBA::Long key_length = 0;
  hdr_status = hdr_status && input.read_long (key_length);
  if (hdr_status)
    {
      this->object_key_.replace (key_length, key_length,
                                 (CORBA::Octet*)input.rd_ptr (),
                                 0);
      input.skip_bytes (key_length);
    }

  if (input.char_translator () == 0)
    {
      CORBA::ULong length = 0;
      hdr_status = hdr_status && input.read_ulong (length);
      if (hdr_status)
        {
          // Do not include NULL character at the end.
          // @@ This is not getting demarshaled using the codeset
          //    translators!
          this->operation_.set (input.rd_ptr (),
                                length - 1,
                                0);
          hdr_status = input.skip_bytes (length);
        }
    }
  else
    {
      // @@ We could optimize for this case too, i.e. do in-place
      //    demarshaling of the string... But there is an issue
      //    pending on the OMG as to whether the operation should be
      //    sent in the connection negotiated codeset or always in
      //    ISO8859-1.
      CORBA::String_var tmp;
      hdr_status = hdr_status && input.read_string (tmp.inout ());
      this->operation_.set (tmp._retn (), 1);
    }

  if (hdr_status)
    {
      input >> this->requesting_principal_.out ();
      hdr_status = (CORBA::Boolean) input.good_bit ();
    }

  return hdr_status ? 0 : -1;
}

int
TAO_GIOP_ServerRequest::parse_header_lite (void)
{
  TAO_InputCDR& input = *this->incoming_;

  CORBA::Boolean hdr_status = (CORBA::Boolean) input.good_bit ();

  // Get the rest of the request header ...

  hdr_status = hdr_status && input.read_ulong (this->request_id_);
  hdr_status = hdr_status && input.read_boolean (this->response_expected_);

  // We use ad-hoc demarshalling here: there is no need to increase
  // the reference count on the CDR message block, because this key
  // will not outlive the request (or the message block).

  CORBA::Long key_length = 0;
  hdr_status = hdr_status && input.read_long (key_length);
  if (hdr_status)
    {
      this->object_key_.replace (key_length, key_length,
                                 (CORBA::Octet*)input.rd_ptr (),
                                 0);
      input.skip_bytes (key_length);
    }

  if (input.char_translator () == 0)
    {
      CORBA::ULong length = 0;
      hdr_status = hdr_status && input.read_ulong (length);
      if (hdr_status)
        {
          // Do not include NULL character at the end.
          // @@ This is not getting demarshaled using the codeset
          //    translators!
          this->operation_.set (input.rd_ptr (),
                                length - 1,
                                0);
          hdr_status = input.skip_bytes (length);
        }
    }
  else
    {
      // @@ We could optimize for this case too, i.e. do in-place
      //    demarshaling of the string... But there is an issue
      //    pending on the OMG as to whether the operation should be
      //    sent in the connection negotiated codeset or always in
      //    ISO8859-1.
      CORBA::String_var tmp;
      hdr_status = hdr_status && input.read_string (tmp.inout ());
      this->operation_.set (tmp._retn (), 1);
    }

  return hdr_status ? 0 : -1;
}

int
TAO_GIOP_ServerRequest::parse_header (void)
{
  if (this->orb_core_->orb_params ()->use_lite_protocol ())
    return this->parse_header_lite ();
  else
    return this->parse_header_std ();
}

// This constructor is used, by the locate request code

TAO_GIOP_ServerRequest::
    TAO_GIOP_ServerRequest (CORBA::ULong &request_id,
                            CORBA::Boolean &response_expected,
                            TAO_ObjectKey &object_key,
                            const ACE_CString &operation,
                            TAO_OutputCDR &output,
                            TAO_ORB_Core *orb_core,
                            const TAO_GIOP_Version &version,
                            int &parse_error)
  : operation_ (operation),
    incoming_ (0),
    outgoing_ (&output),
    response_expected_ (response_expected),

#if !defined (TAO_HAS_MINIMUM_CORBA)

    params_ (0),

#endif /* TAO_HAS_MINIMUM_CORBA */

    retval_ (0),
    exception_ (0),
    exception_type_ (TAO_GIOP_NO_EXCEPTION),
    orb_core_ (orb_core),
    version_ (version),
    service_info_ (),
    request_id_ (request_id),
    object_key_ (object_key),
    requesting_principal_ (0)
{
  parse_error = 0;
}

TAO_GIOP_ServerRequest::~TAO_GIOP_ServerRequest (void)
{

#if !defined (TAO_HAS_MINIMUM_CORBA)

  if (this->params_)
    CORBA::release (this->params_);

#endif /* TAO_HAS_MINIMUM_CORBA */

  delete this->retval_;
  delete this->exception_;
}

CORBA::ORB_ptr
TAO_GIOP_ServerRequest::orb (void)
{
  return this->orb_core_->orb ();
}

TAO_POA *
TAO_GIOP_ServerRequest::oa (void)
{
  return this->orb_core_->root_poa ();
}

#if !defined (TAO_HAS_MINIMUM_CORBA)

// Unmarshal in/inout params, and set up to marshal the appropriate
// inout/out/return values later on.

void
TAO_GIOP_ServerRequest::arguments (CORBA::NVList_ptr &list,
                                   CORBA::Environment &ACE_TRY_ENV)
{
  // Save params for later use when marshaling the reply.
  this->params_ = list;

  // Then unmarshal each "in" and "inout" parameter.
  for (u_int i = 0; i < list->count (); i++)
    {
      CORBA::NamedValue_ptr nv = list->item (i, ACE_TRY_ENV);
      ACE_CHECK;

      // check if it is an in or inout parameter
      if (ACE_BIT_DISABLED (nv->flags (), CORBA::ARG_IN | CORBA::ARG_INOUT))
        continue;

      CORBA::Any_ptr any = nv->value ();
      CORBA::TypeCode_var tc = any->type ();

      // @@ (JP) The following code depends on the fact that
      // TO_InputCDR does not contain chained message blocks.
      char *begin, *end;

      // This will be the start of a new message block.
      begin = this->incoming_->rd_ptr ();

      // Skip over the next aregument.
      CORBA::TypeCode::traverse_status status =
        this->incoming_->skip (tc.in (), ACE_TRY_ENV);
      ACE_CHECK;

      if (status != CORBA::TypeCode::TRAVERSE_CONTINUE)
        {
          const char* param_name = nv->name ();

          if (param_name == 0)
            param_name = "(no name given)";

          ACE_ERROR ((LM_ERROR,
                      "TAO_GIOP_ServerRequest::arguments - problem while"
                      " decoding parameter %d <%s>\n", i, param_name));
          return;
        }

      // This will be the end of the new message block.
      end = this->incoming_->rd_ptr ();

      // Allocate the new message block and set its endpoints.
      ACE_Message_Block *cdr;

      ACE_NEW (cdr,
               ACE_Message_Block (end - begin));

      cdr->rd_ptr (begin);

      cdr->wr_ptr (end);

      // Stick it into the Any. It gets duplicated there.
      any->_tao_replace (tc.in (),
                         cdr,
                         ACE_TRY_ENV);
      ACE_CHECK;

      // Now we can release the original.
      ACE_Message_Block::release (cdr);
    }

  // If any data is left over, it'd be context values ... else error.
  // We don't support context values, so it's always an error.

  // @@ (TAO) support for Contexts??
  if (incoming_->length () != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "TAO_GIOP_ServerRequest::arguments - "
                  "%d bytes left in buffer\n", incoming_->length ()));
      ACE_THROW (CORBA::BAD_PARAM ());
    }
}

// Store the result value.  There's either an exception, or a result,
// but not both of them.  Results (and exceptions) can be reported
// only after the parameter list has been provided (maybe empty).

void
TAO_GIOP_ServerRequest::set_result (const CORBA::Any &value,
                                CORBA::Environment &ACE_TRY_ENV)
{
  // setting a result when another result already exists or if an exception
  // exists is an error
  if (this->retval_ || this->exception_)
    ACE_THROW (CORBA::BAD_INV_ORDER ());

  this->retval_ = new CORBA::Any (value);
}

// Store the exception value.

void
TAO_GIOP_ServerRequest::set_exception (const CORBA::Any &value,
                                       CORBA::Environment &ACE_TRY_ENV)
{
  if (this->retval_ || this->exception_)
    ACE_THROW (CORBA::BAD_INV_ORDER ());
  else
  {

#if !defined (TAO_HAS_MINIMUM_CORBA)

    // Try to narrow to ForwardRequest
    PortableServer::ForwardRequest_ptr forward_request =
      PortableServer::ForwardRequest::_narrow ((CORBA::Exception *) value.value ());

    // If narrowing of exception succeeded
    if (forward_request != 0)
      {
        this->forward_location_ = forward_request->forward_reference;
        this->exception_type_ = TAO_GIOP_USER_EXCEPTION;
      }
    // Normal exception
    else

#endif /* TAO_HAS_MINIMUM_CORBA */

      {
        this->exception_ = new CORBA::Any (value);

        // @@ This cast is not safe, but we haven't implemented the >>=
        // and <<= operators for base exceptions (yet).
        CORBA_Exception* x = (CORBA_Exception*)value.value ();
        if (CORBA_UserException::_narrow (x) != 0)
          this->exception_type_ = TAO_GIOP_USER_EXCEPTION;
        else
          this->exception_type_ = TAO_GIOP_SYSTEM_EXCEPTION;
      }
   }
}

// this method will be utilized by the DSI servant to marshal outgoing
// parameters

void
TAO_GIOP_ServerRequest::dsi_marshal (CORBA::Environment &ACE_TRY_ENV)
{
  // NOTE: if "env" is set, it takes precedence over exceptions
  // reported using the mechanism of the ServerRequest.  Only system
  // exceptions are reported that way ...
  //
  // XXX Exception reporting is ambiguous; it can be cleaner than
  // this.  With both language-mapped and dynamic/explicit reporting
  // mechanisms, one of must be tested "first" ... so an exception
  // reported using the other mechanism could be "lost".  Perhaps only
  // the language mapped one should be used for system exceptions.


  // only if there wasn't any exception, we proceed
  if (this->exception_type_ == TAO_GIOP_NO_EXCEPTION &&
      CORBA::is_nil (this->forward_location_.in ()))
    {
      // ... then send any return value ...
      if (this->retval_)
        {
          CORBA::TypeCode_var tc = this->retval_->type ();
                if (this->retval_->any_owns_data ())
            {
              (void) this->outgoing_->encode (tc.in (),
                                              retval_->value (),
                                              0, ACE_TRY_ENV);
              ACE_CHECK;
            }
          else
            {
              TAO_InputCDR cdr (retval_->_tao_get_cdr ());
              (void) this->outgoing_->append (tc.in (), &cdr,
                                              ACE_TRY_ENV);
              ACE_CHECK;
            }
        }

      // ... Followed by "inout" and "out" parameters, left to right
      if (this->params_)
        {
          for (u_int i = 0;
               i < this->params_->count ();
               i++)
            {
              CORBA::NamedValue_ptr nv = this->params_->item (i, ACE_TRY_ENV);
              ACE_CHECK;

              if (!(nv->flags () & (CORBA::ARG_INOUT|CORBA::ARG_OUT)))
                continue;

              CORBA::Any_ptr any = nv->value ();
              CORBA::TypeCode_var tc = any->type ();
              if (any->any_owns_data ())
                {
                  (void) this->outgoing_->encode (tc.in (),
                                                  any->value (),
                                                  0, ACE_TRY_ENV);
                  ACE_CHECK;
                }
              else
                {
                  TAO_InputCDR cdr (any->_tao_get_cdr ());
                  (void) this->outgoing_->append (tc.in (),
                                                  &cdr, ACE_TRY_ENV);
                  ACE_CHECK;
                }
            }
        }
    }
}

#endif /* TAO_HAS_MINIMUM_CORBA */

// Extension
void
TAO_GIOP_ServerRequest::demarshal (CORBA::Environment &ACE_TRY_ENV,
                                   // ORB related exception reporting
                                   const TAO_Call_Data_Skel *info,
                                   // call description
                                   ...)
{
  CORBA::ULong i;
  const TAO_Param_Data_Skel *pdp;
  va_list param_vector;
  va_start (param_vector, info);

  for (i = 0, pdp = info->params;
       i < info->param_count;
       i++, pdp++)
    {
      void *ptr = va_arg (param_vector, void *);

      if ((pdp->mode == CORBA::ARG_IN)
          || (pdp->mode == CORBA::ARG_INOUT))
        {
          // Then just unmarshal the value.
          (void) incoming_->decode (pdp->tc, ptr, 0, ACE_TRY_ENV);
          ACE_CHECK;
        }
    }
  va_end (param_vector);
}

// Extension

void
TAO_GIOP_ServerRequest::marshal (CORBA::Environment &ACE_TRY_ENV,
                                 // ORB related exception reporting
                                 //                             CORBA::Environment &skel_env,
                                 // skeleton related exception reporting
                                 const TAO_Call_Data_Skel *info,
                                 // call description
                                 ...)
{
  // what is "ACE_TRY_ENV" and "skel_env"?
  // "skel_env" holds the exception that got raised inside the operation
  // implementation (upcall)
  //
  // "orb_env" is the exception that may have been raised due to things going
  // wrong in the entire dispatch process. These are always system exceptions.

  // check if we are inside with an exception. This may have happened
  // since the upcall could have set some exception
#if 0 /* ASG */
  if (skel_env.exception ())
    {
      // We must increase the "refcnt" on the exception, because it is
      // "owned" by both <skel_env> and (eventually) by the
      // Server_Request.
      CORBA::Exception_ptr exception = skel_env.exception ();
      exception->_incr_refcnt ();

      // The Any does not own the because ultimately it will be owned
      // by the Server_Request via the call to "set_exception"
      CORBA::Any any (skel_env.exception ()->_type (), exception);
      this->set_exception (any, ACE_TRY_ENV);
    }
#endif

  // Setup a Reply message so that we can marshal all the outgoing parameters
  // into it. If an exception was set, then that gets marshaled into the reply
  // message and we don't do anything after that
  this->init_reply (ACE_TRY_ENV);
  ACE_CHECK;

#if 0 /* ASG */
  // exception? nothing to do after this
  if (orb_env.exception () || skel_env.exception ())
    return;
  ACE_CHECK;
#endif

  CORBA::ULong i;
  const TAO_Param_Data_Skel *pdp;
  va_list param_vector;
  va_start (param_vector, info);

  ACE_TRY
    {
      for (i = 0, pdp = info->params;
           i < info->param_count;
           i++, pdp++)
        {
          void *ptr = va_arg (param_vector, void *);

          if (pdp->mode == 0)
            {
              // check if the return type is not void
              CORBA::TCKind result = pdp->tc->kind (ACE_TRY_ENV);
              ACE_TRY_CHECK;
              if (result != CORBA::tk_void)
                {
                  // Then just marshal the value.
                  (void) this->outgoing_->encode (pdp->tc, ptr, 0,
                                                  ACE_TRY_ENV);
                  ACE_TRY_CHECK;
                }
            }
          else if ((pdp->mode == CORBA::ARG_INOUT)
                   || (pdp->mode == CORBA::ARG_OUT))
            {
              // Then just marshal the value.
              (void) this->outgoing_->encode (pdp->tc, ptr, 0, ACE_TRY_ENV);
              ACE_TRY_CHECK;
            }
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "TAO_GIOP_ServerRequest::marshal - parameter encode failed");
      ACE_RETHROW;
    }
  ACE_ENDTRY;
  ACE_CHECK;

  va_end (param_vector);
}

void
TAO_GIOP_ServerRequest::init_reply (CORBA::Environment &ACE_TRY_ENV)
{
  // Construct a REPLY header.
  TAO_GIOP::start_message (this->version_,
                           TAO_GIOP::Reply,
                           *this->outgoing_,
                           this->orb_core_);

  *this->outgoing_ << this->service_info_;
  this->outgoing_->write_ulong (this->request_id_);

  // Standard exceptions are caught in Connect::handle_input

  // Forward exception only.
  if (!CORBA::is_nil (this->forward_location_.in ()))
    {
      this->outgoing_->write_ulong (TAO_GIOP_LOCATION_FORWARD);

      CORBA::Object_ptr object_ptr = this->forward_location_.in ();
      if ((*this->outgoing_ << object_ptr) == 0)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "TAO_GIOP_ServerRequest::marshal - "
                      "encoding forwarded objref failed\n"));
          return;
        }
    }

  // Any exception at all.
  else if (this->exception_ == 0)
    {
      // First finish the GIOP header ...
      this->outgoing_->write_ulong (TAO_GIOP_NO_EXCEPTION);
    }
  else
    {
      CORBA::TypeCode_ptr except_tc;

      except_tc = this->exception_->type ();

      // Finish the GIOP Reply header, then marshal the exception.
      // XXX x->type () someday ...

      this->outgoing_->write_ulong (this->exception_type_);

      // we use the any's ACE_Message_Block
      TAO_InputCDR cdr (this->exception_->_tao_get_cdr ());
      (void) this->outgoing_->append (except_tc, &cdr, ACE_TRY_ENV);
    }
}

CORBA::Object_ptr
TAO_GIOP_ServerRequest::forward_location (void)
// get the forward_location
{
  return CORBA::Object::_duplicate (this->forward_location_.in ());
}

CORBA::ULong
TAO_GIOP_ServerRequest::exception_type (void)
// get the exception type
{
  return this->exception_type_;
}
