#include "UIOP_Connector.h"

#if TAO_HAS_UIOP == 1

#include "UIOP_Profile.h"
#include "tao/debug.h"
#include "tao/ORB_Core.h"
#include "tao/Environment.h"
#include "tao/Protocols_Hooks.h"
#include "tao/Base_Transport_Property.h"
#include "tao/Transport_Cache_Manager.h"
#include "tao/Invocation.h"
#include "tao/Thread_Lane_Resources.h"
#include "tao/Connect_Strategy.h"
ACE_RCSID(Strategies,
          UIOP_Connector,
          "$Id$")

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class TAO_Connect_Concurrency_Strategy<TAO_UIOP_Connection_Handler>;
template class TAO_Connect_Creation_Strategy<TAO_UIOP_Connection_Handler>;
template class ACE_Strategy_Connector<TAO_UIOP_Connection_Handler, ACE_LSOCK_CONNECTOR>;
template class ACE_Connect_Strategy<TAO_UIOP_Connection_Handler, ACE_LSOCK_CONNECTOR>;
template class ACE_Connector_Base<TAO_UIOP_Connection_Handler>;
template class ACE_Connector<TAO_UIOP_Connection_Handler, ACE_LSOCK_CONNECTOR>;
template class ACE_NonBlocking_Connect_Handler<TAO_UIOP_Connection_Handler>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Node<ACE_UNIX_Addr>
#pragma instantiate ACE_Unbounded_Stack<ACE_UNIX_Addr>

#pragma instantiate TAO_Connect_Concurrency_Strategy<TAO_UIOP_Connection_Handler>
#pragma instantiate TAO_Connect_Creation_Strategy<TAO_UIOP_Connection_Handler>
#pragma instantiate ACE_Strategy_Connector<TAO_UIOP_Connection_Handler, ACE_LSOCK_CONNECTOR>
#pragma instantiate ACE_Connect_Strategy<TAO_UIOP_Connection_Handler, ACE_LSOCK_CONNECTOR>
#pragma instantiate ACE_Connector_Base<TAO_UIOP_Connection_Handler>
#pragma instantiate ACE_Connector<TAO_UIOP_Connection_Handler, ACE_LSOCK_CONNECTOR>
#pragma instantiate ACE_NonBlocking_Connect_Handler<TAO_UIOP_Connection_Handler>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

TAO_UIOP_Connector::TAO_UIOP_Connector (CORBA::Boolean flag)
  : TAO_Connector (TAO_TAG_UIOP_PROFILE),
    connect_strategy_ (),
    base_connector_ (),
    lite_flag_ (flag)
{
}

TAO_UIOP_Connector::~TAO_UIOP_Connector (void)
{
}

int
TAO_UIOP_Connector::open (TAO_ORB_Core *orb_core)
{
  this->orb_core (orb_core);

  // Create our connect strategy
  if (this->create_connect_strategy () == -1)
    return -1;

  if (this->init_uiop_properties () != 0)
    return -1;

  // Our connect creation strategy
  TAO_UIOP_CONNECT_CREATION_STRATEGY *connect_creation_strategy = 0;

  ACE_NEW_RETURN (connect_creation_strategy,
                  TAO_UIOP_CONNECT_CREATION_STRATEGY
                      (orb_core->thr_mgr (),
                       orb_core,
                       &(this->uiop_properties_),
                       this->lite_flag_),
                  -1);

  /// Our activation strategy
  TAO_UIOP_CONNECT_CONCURRENCY_STRATEGY *concurrency_strategy = 0;

  ACE_NEW_RETURN (concurrency_strategy,
                  TAO_UIOP_CONNECT_CONCURRENCY_STRATEGY (orb_core),
                  -1);

  return this->base_connector_.open (this->orb_core ()->reactor (),
                                     connect_creation_strategy,
                                     &this->connect_strategy_,
                                     concurrency_strategy);
}

int
TAO_UIOP_Connector::close (void)
{
  // Zap the creation strategy that we created earlier.
  delete this->base_connector_.creation_strategy ();
  delete this->base_connector_.concurrency_strategy ();

  return this->base_connector_.close ();
}


int
TAO_UIOP_Connector::set_validate_endpoint (TAO_Endpoint *endpoint)
{
  TAO_UIOP_Endpoint *uiop_endpoint =
    this->remote_endpoint (endpoint);

  if (uiop_endpoint == 0)
    return -1;

   const ACE_UNIX_Addr &remote_address =
     uiop_endpoint->object_addr ();

   // @@ Note, POSIX.1g renames AF_UNIX to AF_LOCAL.
   // Verify that the remote ACE_UNIX_Addr was initialized properly.
   // Failure can occur if hostname lookup failed when initializing the
   // remote ACE_INET_Addr.
   if (remote_address.get_type () != AF_UNIX)
     {
       if (TAO_debug_level > 0)
         {
           ACE_DEBUG ((LM_DEBUG,
                       ACE_LIB_TEXT ("TAO (%P|%t) UIOP failure.\n")
                       ACE_LIB_TEXT ("TAO (%P|%t) This is most likely ")
                       ACE_LIB_TEXT ("due to a hostname lookup ")
                       ACE_LIB_TEXT ("failure.\n")));
         }

       return -1;
     }

   return 0;
}

int
TAO_UIOP_Connector::make_connection (TAO_GIOP_Invocation *invocation,
                                     TAO_Transport_Descriptor_Interface *desc,
                                     ACE_Time_Value *max_wait_time)
{
  if (TAO_debug_level > 0)
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("TAO (%P|%t) Connector::connect - ")
                  ACE_TEXT ("looking for UIOP connection.\n")));

  TAO_UIOP_Endpoint *uiop_endpoint =
    this->remote_endpoint (desc->endpoint ());

  if (uiop_endpoint == 0)
    return -1;

  const ACE_UNIX_Addr &remote_address =
    uiop_endpoint->object_addr ();

  if (TAO_debug_level > 2)
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) UIOP_Connector::connect ")
                ACE_TEXT ("making a new connection \n")));

  // Get the right synch options
  ACE_Synch_Options synch_options;

  this->active_connect_strategy_->synch_options (max_wait_time,
                                                 synch_options);

  TAO_UIOP_Connection_Handler *svc_handler = 0;

  // Connect.
  int result =
    this->base_connector_.connect (svc_handler,
                                   remote_address,
                                   synch_options);

  // This call creates the service handler and bumps the #REFCOUNT# up
  // one extra.  There are three possibilities: (a) connection
  // succeeds immediately - in this case, the #REFCOUNT# on the
  // handler is two; (b) connection completion is pending - in this
  // case, the #REFCOUNT# on the handler is also two; (c) connection
  // fails immediately - in this case, the #REFCOUNT# on the handler
  // is one since close() gets called on the handler.
  //
  // The extra reference count in
  // TAO_Connect_Creation_Strategy::make_svc_handler() is needed in
  // the case when connection completion is pending and we are going
  // to wait on a variable in the handler to changes, signifying
  // success or failure.  Note, that this increment cannot be done
  // once the connect() returns since this might be too late if
  // another thread pick up the completion and potentially deletes the
  // handler before we get a chance to increment the reference count.

  // No immediate result.  Wait for completion.
  if (result == -1 && errno == EWOULDBLOCK)
    {
      if (TAO_debug_level > 2)
        ACE_DEBUG ((LM_DEBUG,
                    "TAO (%P|%t) - UIOP_Connector::make_connection, "
                    "going to wait for connection completion on local"
                    "handle [%d]\n",
                    svc_handler->get_handle ()));

       // Wait for connection completion.  No need to specify timeout
       // to wait() since the correct timeout was passed to the
       // Connector. The Connector will close the handler in the case
       // of timeouts, so the event will complete (either success or
       // failure) within timeout.
      result =
        this->active_connect_strategy_->wait (svc_handler,
                                              0);

      if (TAO_debug_level > 2)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "TAO (%P|%t) - UIOP_Connector::make_connection"
                      "wait done for handle[%d], result = %d\n",
                      svc_handler->get_handle (), result));
        }

       // There are three possibilities when wait() returns: (a)
       // connection succeeded; (b) connection failed; (c) wait()
       // failed because of some other error.  It is easy to deal with
       // (a) and (b).  (c) is tricky since the connection is still
       // pending and may get completed by some other thread.  The
       // following code deals with (c).

       // Check if the handler has been closed.
       int closed =
         svc_handler->is_closed ();

       // In case of failures and close() has not be called.
       if (result == -1 &&
           !closed)
         {
           // First, cancel from connector.
           this->base_connector_.cancel (svc_handler);

           // Double check to make sure the handler has not been
           // closed yet.  This double check is required to ensure
           // that the connection handler was not closed yet by some
           // other thread since it was still registered with the
           // connector.  Once connector.cancel() has been processed,
           // we are assured that the connector will no longer
           // open/close this handler.
           closed =
             svc_handler->is_closed ();

           // If closed, there is nothing to do here.  If not closed,
           // it was either opened or is still pending.
           if (!closed)
             {
               // Check if the handler has been opened.
               int open =
                 svc_handler->is_open ();

               // Some other thread was able to open the handler even
               // though wait failed for this thread.
               if (open)
                 // Overwrite <result>.
                 result = 0;
               else
                 {
                   // Assert that it is still connecting.
                   ACE_ASSERT (svc_handler->is_connecting ());

                   // Force close the handler now.
                   svc_handler->close ();
                 }
             }
         }
    }

  // Irrespective of success or failure, remove the extra #REFCOUNT#.
  svc_handler->remove_reference ();

  // In case of errors.
  if (result == -1)
    {
      // Give users a clue to the problem.
      if (TAO_debug_level)
        {
          ACE_DEBUG ((LM_ERROR,
                      ACE_TEXT ("(%P|%t) %s:%u, connection to ")
                      ACE_TEXT ("%s failed (%p)\n"),
                      __FILE__,
                      __LINE__,
                      uiop_endpoint->rendezvous_point (),
                      ACE_TEXT ("errno")));
        }

      return -1;
    }

  // At this point, the connection has be successfully connected.
  // #REFCOUNT# is one.

  TAO_Transport *transport =
    svc_handler->transport ();

  // Add the handler to Cache
  int retval =
    this->orb_core ()->lane_resources ().transport_cache ().cache_transport (desc,
                                                                             transport);
  // Failure in adding to cache.
  if (retval != 0)
    {
      // Close the handler.
      svc_handler->close ();

      if (TAO_debug_level > 0)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("(%P|%t) UIOP_Connector::connect ")
                      ACE_TEXT ("could not add the new connection to Cache \n")));
        }

      return -1;
    }

  // If the wait strategy wants us to be registered with the reactor
  // then we do so. If registeration is required and it succeeds,
  // #REFCOUNT# becomes two.
  retval = transport->wait_strategy ()->register_handler ();

  // Registration failures.
  if (retval != 0)
    {
      // Purge from the connection cache.
      transport->purge_entry ();

      // Close the handler.
      svc_handler->close ();

      if (TAO_debug_level > 0)
        {
          ACE_ERROR ((LM_ERROR,
                      "TAO (%P|%t) - UIOP_Connector::make_connection, "
                      "could not register the new connection in the reactor\n"));
        }

      return -1;
    }

  // Handover the transport pointer to the Invocation class.
  TAO_Transport *&invocation_transport =
    invocation->transport ();
  invocation_transport = transport;

  return 0;
}

TAO_Profile *
TAO_UIOP_Connector::create_profile (TAO_InputCDR& cdr)
{
  TAO_Profile *pfile;
  ACE_NEW_RETURN (pfile,
                  TAO_UIOP_Profile (this->orb_core ()),
                  0);

  int r = pfile->decode (cdr);
  if (r == -1)
    {
      pfile->_decr_refcnt ();
      pfile = 0;
    }

  return pfile;
}

TAO_Profile *
TAO_UIOP_Connector::make_profile (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_Profile *profile = 0;
  ACE_NEW_THROW_EX (profile,
                    TAO_UIOP_Profile (this->orb_core ()),
                    CORBA::NO_MEMORY (
                      CORBA::SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOMEM),
                      CORBA::COMPLETED_NO));

  ACE_CHECK_RETURN (0);

  return profile;
}

int
TAO_UIOP_Connector::check_prefix (const char *endpoint)
{
  // Check for a valid string
  if (!endpoint || !*endpoint)
    return -1;  // Failure

  const char *protocol[] = { "uiop", "uioploc" };

  size_t slot = ACE_OS::strchr (endpoint, ':') - endpoint;

  size_t len0 = ACE_OS::strlen (protocol[0]);
  size_t len1 = ACE_OS::strlen (protocol[1]);

  // Check for the proper prefix in the IOR.  If the proper prefix
  // isn't in the IOR then it is not an IOR we can use.
  if (slot == len0
      && ACE_OS::strncasecmp (endpoint,
                              protocol[0],
                              len0) == 0)
    return 0;
  else if (slot == len1
           && ACE_OS::strncasecmp (endpoint,
                                   protocol[1],
                                   len1) == 0)
    return 0;

  return -1;
  // Failure: not an UIOP IOR DO NOT throw an exception here.
}

char
TAO_UIOP_Connector::object_key_delimiter (void) const
{
  return TAO_UIOP_Profile::object_key_delimiter_;
}

int
TAO_UIOP_Connector::init_uiop_properties (void)
{
  // Connector protocol properties are obtained from ORB-level
  // RTCORBA::ClientProtocolProperties policy override.
  // If the override doesn't exist or doesn't contain the
  // properties, we use ORB default.
  //
  // Currently, we do not use Object-level and Current-level policy
  // overrides for protocol configuration because connection
  // lookup and caching are not done based on protocol
  // properties.

  ACE_DECLARE_NEW_CORBA_ENV;

  int send_buffer_size = this->orb_core ()->orb_params ()->sock_sndbuf_size ();
  int recv_buffer_size = this->orb_core ()->orb_params ()->sock_rcvbuf_size ();
  int no_delay = 0;
  int enable_network_priority = 0;

  TAO_Protocols_Hooks *tph = this->orb_core ()->get_protocols_hooks (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  if (tph != 0)
    {
      const char protocol [] = "uiop";
      const char *protocol_type = protocol;
      int hook_result =
        tph->call_client_protocols_hook (send_buffer_size,
                                         recv_buffer_size,
                                         no_delay,
                                         enable_network_priority,
                                         protocol_type);

      if(hook_result == -1)
        return -1;
    }

    // Extract and locally store properties of interest.
    this->uiop_properties_.send_buffer_size =
      send_buffer_size;
    this->uiop_properties_.recv_buffer_size =
      recv_buffer_size;

  return 0;
}

TAO_UIOP_Endpoint *
TAO_UIOP_Connector::remote_endpoint (TAO_Endpoint *endpoint)
{
  if (endpoint->tag () != TAO_TAG_UIOP_PROFILE)
    return 0;

  TAO_UIOP_Endpoint *uiop_endpoint =
    ACE_dynamic_cast (TAO_UIOP_Endpoint *,
                      endpoint );
  if (uiop_endpoint == 0)
    return 0;

  return uiop_endpoint;
}

#endif /* TAO_HAS_UIOP == 1 */
