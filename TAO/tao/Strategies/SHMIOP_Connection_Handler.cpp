// $Id$

#include "SHMIOP_Connection_Handler.h"

#if defined (TAO_HAS_SHMIOP) && (TAO_HAS_SHMIOP != 0)

#include "tao/Timeprobe.h"
#include "tao/debug.h"
#include "tao/ORB_Core.h"
#include "tao/ORB.h"
#include "tao/CDR.h"
#include "tao/Server_Strategy_Factory.h"
#include "tao/Base_Transport_Property.h"
#include "tao/Transport_Cache_Manager.h"
#include "tao/Thread_Lane_Resources.h"
#include "SHMIOP_Endpoint.h"
#include "tao/Resume_Handle.h"
#include "tao/Protocols_Hooks.h"

#include "ace/os_include/netinet/os_tcp.h"
#include "ace/os_include/os_netdb.h"

ACE_RCSID (Strategies,
           SHMIOP_Connection_Handler,
           "$Id$")

TAO_SHMIOP_Connection_Handler::TAO_SHMIOP_Connection_Handler (ACE_Thread_Manager *t)
  : TAO_SHMIOP_SVC_HANDLER (t, 0 , 0),
    TAO_Connection_Handler (0)
{
  // This constructor should *never* get called, it is just here to
  // make the compiler happy: the default implementation of the
  // Creation_Strategy requires a constructor with that signature, we
  // don't use that implementation, but some (most?) compilers
  // instantiate it anyway.
  ACE_ASSERT (0);
}


TAO_SHMIOP_Connection_Handler::TAO_SHMIOP_Connection_Handler (TAO_ORB_Core *orb_core,
                                                              CORBA::Boolean flag)
  : TAO_SHMIOP_SVC_HANDLER (orb_core->thr_mgr (), 0, 0),
    TAO_Connection_Handler (orb_core)
{
  TAO_SHMIOP_Transport* specific_transport = 0;
  ACE_NEW (specific_transport,
          TAO_SHMIOP_Transport(this, orb_core, flag));

  // store this pointer (indirectly increment ref count)
  this->transport (specific_transport);
}


TAO_SHMIOP_Connection_Handler::~TAO_SHMIOP_Connection_Handler (void)
{
  delete this->transport ();
}

int
TAO_SHMIOP_Connection_Handler::open_handler (void *v)
{
  return this->open (v);
}

int
TAO_SHMIOP_Connection_Handler::open (void*)
{
  TAO_SHMIOP_Protocol_Properties protocol_properties;

  // Initialize values from ORB params.
  protocol_properties.send_buffer_size_ =
    this->orb_core ()->orb_params ()->sock_sndbuf_size ();
  protocol_properties.recv_buffer_size_ =
    this->orb_core ()->orb_params ()->sock_rcvbuf_size ();
  protocol_properties.no_delay_ =
    this->orb_core ()->orb_params ()->nodelay ();

  TAO_Protocols_Hooks *tph =
    this->orb_core ()->get_protocols_hooks ();

  bool client =
    this->transport ()->opened_as () == TAO::TAO_CLIENT_ROLE;;

  ACE_DECLARE_NEW_CORBA_ENV;

  ACE_TRY
    {
      if (client)
        {
          tph->client_protocol_properties_at_orb_level (
            protocol_properties
            ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }
      else
        {
          tph->server_protocol_properties_at_orb_level (
            protocol_properties
            ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }
    }
  ACE_CATCHANY
    {
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  if (this->set_socket_option (this->peer (),
                               protocol_properties.send_buffer_size_,
                               protocol_properties.recv_buffer_size_) == -1)
    return -1;

#if !defined (ACE_LACKS_TCP_NODELAY)
  if (this->peer ().set_option (ACE_IPPROTO_TCP,
                                TCP_NODELAY,
                                (void *) &protocol_properties.no_delay_,
                                sizeof (protocol_properties.no_delay_)) == -1)
    return -1;

#endif /* ! ACE_LACKS_TCP_NODELAY */

  if (this->transport ()->wait_strategy ()->non_blocking ())
    {
      if (this->peer ().enable (ACE_NONBLOCK) == -1)
        return -1;
    }

  // Called by the <Strategy_Acceptor> when the handler is
  // completely connected.
  ACE_INET_Addr addr;

  ACE_TCHAR local_as_string[MAXHOSTNAMELEN + 16];

  // Get the peername.
  if (this->peer ().get_remote_addr (addr) == -1)
    return -1;

  // Verify that we can resolve the peer hostname.
  else if (addr.addr_to_string (local_as_string, sizeof (local_as_string)) == -1)
    return -1;

  if (TAO_debug_level > 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("TAO (%P|%t) - SHMIOP connection from client")
                  ACE_TEXT ("<%s> on %d\n"),
                  local_as_string, this->peer ().get_handle ()));
    }

  // Set that the transport is now connected, if fails we return -1
  // Use C-style cast b/c otherwise we get warnings on lots of
  // compilers
  if (!this->transport ()->post_open ((size_t) this->get_handle ()))
    return -1;

  // Not needed, anyway
  this->state_changed (TAO_LF_Event::LFS_SUCCESS);

  return 0;
}

int
TAO_SHMIOP_Connection_Handler::resume_handler (void)
{
  return ACE_Event_Handler::ACE_APPLICATION_RESUMES_HANDLER;
}

int
TAO_SHMIOP_Connection_Handler::close_connection (void)
{
  return this->close_connection_eh (this);
}

int
TAO_SHMIOP_Connection_Handler::handle_input (ACE_HANDLE h)
{
  return this->handle_input_eh (h, this);
}

int
TAO_SHMIOP_Connection_Handler::handle_output (ACE_HANDLE handle)
{
  int result =
    this->handle_output_eh (handle, this);

  if (result == -1)
    {
      this->close_connection ();
      return 0;
    }

  return result;
}

int
TAO_SHMIOP_Connection_Handler::handle_timeout (const ACE_Time_Value &,
                                               const void *)
{
  // We don't use this upcall for I/O.  This is only used by the
  // Connector to indicate that the connection timedout.  Therefore,
  // we should call close().
  return this->close ();
}

int
TAO_SHMIOP_Connection_Handler::handle_close (ACE_HANDLE,
                                             ACE_Reactor_Mask)
{
  ACE_ASSERT (0);
  return 0;
}

int
TAO_SHMIOP_Connection_Handler::close (u_long)
{
  return this->close_handler ();
}

int
TAO_SHMIOP_Connection_Handler::release_os_resources (void)
{
  return this->peer().close ();
}

int
TAO_SHMIOP_Connection_Handler::add_transport_to_cache (void)
{
  ACE_INET_Addr addr;

  // Get the peername.
  if (this->peer ().get_remote_addr (addr) == -1)
    return -1;

  // Construct an  SHMIOP_Endpoint object
  TAO_SHMIOP_Endpoint endpoint (
      addr,
      this->orb_core()->orb_params()->use_dotted_decimal_addresses ());

  // Construct a property object
  TAO_Base_Transport_Property prop (&endpoint);

  TAO::Transport_Cache_Manager &cache =
    this->orb_core ()->lane_resources ().transport_cache ();

  // Add the handler to Cache
  return cache.cache_idle_transport (&prop,
                                     this->transport ());
}

#endif /*(TAO_HAS_SHMIOP) && (TAO_HAS_SHMIOP != 0) */
