// $Id$

#define ACE_BUILD_SVC_DLL

#include "ace/Get_Opt.h"
#include "ace/Acceptor.h"
#include "ace/SOCK_Connector.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/SPIPE_Acceptor.h"
#include "Client_Logging_Handler.h"

ACE_RCSID(lib, Client_Logging_Handler, "$Id$")

ACE_Client_Logging_Handler::ACE_Client_Logging_Handler (ACE_HANDLE output_handle)
  : logging_output_ (output_handle)
{
  // Register ourselves to receive SIGPIPE so we can attempt
  // reconnections.
#if !defined (ACE_LACKS_UNIX_SIGNALS)
  if (ACE_Reactor::instance ()->register_handler (SIGPIPE,
                                                  this) == -1)
    ACE_ERROR ((LM_ERROR,
                "%n: %p\n",
		"register_handler (SIGPIPE)"));
#endif /* !ACE_LACKS_UNIX_SIGNALS */
}

// This is called when a <send> to the logging server fails...

int
ACE_Client_Logging_Handler::handle_signal (int signum, 
                                           siginfo_t *,
                                           ucontext_t *)
{
  if (signum == SIGPIPE)
    return 0;
  else
    return -1;
}

// This function is called every time a client connects to us.

int
ACE_Client_Logging_Handler::open (void *)
{
  LOGGING_ADDR server_addr;

  // Register ourselves to receive <handle_input> callbacks when
  // clients send us logging records.  Note that since we're really a
  // Singleton, this->peer() will change after each connect, so we
  // need to grab the value now.
  if (ACE_Reactor::instance ()->register_handler
      (this->peer ().get_handle (),
       this,
       ACE_Event_Handler::READ_MASK
       | ACE_Event_Handler::EXCEPT_MASK) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%n: %p\n",
		       "register_handler)"),
                      -1);
  // Figure out what remote port we're really bound to.
  if (this->peer ().get_remote_addr (server_addr) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "get_remote_addr"),
                      -1);

  ACE_DEBUG ((LM_DEBUG,
	      "connected to client on handle %u\n",
	      this->peer ().get_handle ()));
  return 0;
}

/* VIRTUAL */ ACE_HANDLE
ACE_Client_Logging_Handler::get_handle (void) const
{
  ACE_TRACE ("ACE_Client_Logging_Handler::get_handle");

  ACE_ERROR ((LM_ERROR,
	      "get_handle() shouldn't be called\n"));

  return ACE_INVALID_HANDLE;
}

// Receive a logging record from an application.

int
ACE_Client_Logging_Handler::handle_input (ACE_HANDLE handle)
{
  ACE_DEBUG ((LM_DEBUG,
              "in handle_input, handle = %u\n",
              handle));

  if (handle == this->logging_output_)
    // We're getting a message from the logging server!
    ACE_ERROR_RETURN ((LM_ERROR,
                       "received data from server!\n"),
                      -1);
  ACE_Log_Record log_record;
#if defined (ACE_HAS_STREAM_PIPES)
  // We're getting a logging message from a local application.

  ACE_Str_Buf msg ((void *) &log_record,
		   0,
		   sizeof log_record);

  ACE_SPIPE_Stream spipe;
  spipe.set_handle (handle);
  int flags = 0;

  int result = spipe.recv ((ACE_Str_Buf *) 0,
                           &msg,
                           &flags);

  // We've got a framed IPC mechanism, so we can just to a <recv>.
  if (result < 0 || msg.len == 0)
    {
      if (ACE_Reactor::instance ()->remove_handler
	  (handle,
	   ACE_Event_Handler::READ_MASK
	   | ACE_Event_Handler::EXCEPT_MASK
	   | ACE_Event_Handler::DONT_CALL) == -1)
	ACE_ERROR_RETURN ((LM_ERROR,
                           "%n: %p\n",
			   "remove_handler"),
                          -1);
      spipe.close ();
      ACE_DEBUG ((LM_DEBUG,
                  "client closing down\n"));
      return 0;
    }
#else
  ACE_INT32 length;

  // We need to use the ol' two-read trick here since TCP sockets
  // don't support framing natively.  Note that the first call is just
  // a "peek" -- we don't actually remove the data until the second
  // call.  Note that this code is portable as long as ACE_UNIT32 is
  // always 32 bits on both the sender and receiver side.

  ssize_t count = ACE_OS::recv (handle,
                                (char *) &length,
                                sizeof length,
                                MSG_PEEK);
  switch (count)
    {
      // Handle shutdown and error cases.
    default:
    case -1:
    case 0:
      if (ACE_Reactor::instance ()->remove_handler
	  (handle,
	   ACE_Event_Handler::READ_MASK
	   | ACE_Event_Handler::EXCEPT_MASK
	   | ACE_Event_Handler::DONT_CALL) == -1)
	ACE_ERROR_RETURN ((LM_ERROR,
                           "%n: %p\n",
			   "remove_handler"), 
                          0);
      ACE_OS::closesocket (handle);
      ACE_DEBUG ((LM_DEBUG,
                  "client closing down\n"));
      return 0;
      /* NOTREACHED */

    case sizeof length:
#if defined (ACE_WIN32)
      // This is a special-case sent from near line 610 in
      // Log_Msg.cpp.  Without this code Win32 sockets are never
      // closed, so this server will quickly run out of handles.
      if (length == ~0)
        {
          if (ACE_Reactor::instance ()->remove_handler
              (handle,
               ACE_Event_Handler::READ_MASK
               | ACE_Event_Handler::EXCEPT_MASK
               | ACE_Event_Handler::DONT_CALL) == -1)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "%n: %p\n",
                               "remove_handler"), 
                              0);
 
          ACE_OS::closesocket (handle);
          ACE_DEBUG ((LM_DEBUG,
                      "client closing down\n"));
          return 0;
        }
#endif /* ACE_WIN32 */
 
      ssize_t retrieved = ACE_OS::recv (handle,
                                        (char *) &log_record,
                                        (int) length);
 
      // We go a ``short-read.''  Try once more, then abandon all hope
      // on this socket.
      if (retrieved != length)
       {
           ACE_DEBUG ((LM_DEBUG,
                       "partial message retrieved, attempting second try...\n"));
 
          int remainder = length - retrieved;
 
           int secondtry = ACE_OS::recv (handle,
                                         ((char *) &log_record) + retrieved,
                                         remainder);
           if (secondtry != remainder)
             {
               ACE_DEBUG ((LM_DEBUG,
                           "second try failed\n"));
 
               if (ACE_Reactor::instance ()->remove_handler
                   (handle,
                    ACE_Event_Handler::READ_MASK
                    | ACE_Event_Handler::EXCEPT_MASK
                    | ACE_Event_Handler::DONT_CALL) == -1)
                 {
                   ACE_ERROR_RETURN ((LM_ERROR,
                                      "%n: %p\n",
                                      "remove_handler"), 
                                     0);
                 }
 
               ACE_OS::closesocket (handle);
               
               ACE_ERROR_RETURN ((LM_ERROR,
                                  "%p\n",
                                  "recv"),
                                 0);
             }
       }
    }
#endif /* ACE_HAS_STREAM_PIPES */

  // Forward the logging record to the server.
  if (this->send (log_record) == -1)
    ACE_ERROR ((LM_ERROR,
		"%p\n",
		"send"));
  return 0;
}

// Receive a logging record from an application send via a non-0
// MSG_BAND...  This just calls handle_input().

int
ACE_Client_Logging_Handler::handle_exception (ACE_HANDLE handle)
{
  return this->handle_input (handle);
}

// Called when object is removed from the ACE_Reactor

int
ACE_Client_Logging_Handler::close (u_long)
{
  ACE_DEBUG ((LM_DEBUG,
              "shutting down!!!\n"));

  if (this->logging_output_ != ACE_STDERR)
    ACE_OS::closesocket (this->logging_output_);

  this->destroy ();
  return 0;
}

int
ACE_Client_Logging_Handler::handle_output (ACE_HANDLE)
{
  return 0;
}

// Encodes the contents of log_record object using network byte-order
// and sends it to the logging server.

int
ACE_Client_Logging_Handler::send (ACE_Log_Record &log_record)
{
  if (this->logging_output_ == ACE_STDERR)
    log_record.print ("<localhost>",
                      ACE_Log_Msg::instance ()->flags (),
                      stderr);
  else
    {
      long len = log_record.length ();
      log_record.encode ();

      if (ACE::send (this->logging_output_,
		     (char *) &log_record,
		     len) == -1)
	// Switch over to logging to stderr for now.  At some point,
	// we'll improve the implementation to queue up the message,
	// try to reestablish a connection, and then send the queued
	// data once we've reconnect to the logging server.  If you'd
	// like to implement this functionality and contribute it back
	// to ACE that would be great!
	this->logging_output_ = ACE_STDERR;
    }

  ostream *orig_ostream = ACE_Log_Msg::instance ()->msg_ostream ();

  if (orig_ostream)
    log_record.print ("<localhost>",
                      ACE_Log_Msg::instance ()->flags (),
                      *orig_ostream);
  return 0;
}

class ACE_Client_Logging_Acceptor : public ACE_Acceptor<ACE_Client_Logging_Handler, LOGGING_ACCEPTOR>
{
  // = TITLE
  //     This factory creates connections with the
  //     <Server_Logging_Acceptor>.
  //
  // = DESCRIPTION
  //     This class contains the service-specific methods that can't
  //     easily be factored into the <ACE_Acceptor>.
public:
  // = Initialization method.
  ACE_Client_Logging_Acceptor (void);
  // Default constructor.

protected:
  // = Dynamic linking hooks.
  virtual int init (int argc, char *argv[]);
  // Called when service is linked.

  virtual int fini (void);
  // Called when service is unlinked.

  virtual int info (char **strp, size_t length) const;
  // Called to determine info about the service.

  virtual int make_svc_handler (ACE_Client_Logging_Handler *&sh);
  // Factory that always returns the <handler_>.

  // = Scheduling hooks.
  virtual int suspend (void);
  virtual int resume (void);

private:
  int parse_args (int argc, char *argv[]);
  // Parse svc.conf arguments.

  const char *server_host_;
  // Host where the logging server is located.

  u_short server_port_;
  // Port number where the logging server is listening for
  // connections.

  ACE_INET_Addr server_addr_;
  // Address of the logging server.

  const char *logger_key_;
  // Communication endpoint where the client logging daemon will
  // listen for connections from clients.

  ACE_Client_Logging_Handler *handler_;
  // Pointer to the handler that does the work.
};

int
ACE_Client_Logging_Acceptor::fini (void)
{
  this->close ();

  if (this->handler_ != 0)
    this->handler_->close (0);

  // Try to unlink the logger key so weird things don't happen if
  // we're using STREAM pipes.
  ACE_OS::unlink (this->logger_key_);

  // This memory was allocated by <ACE_OS::strdup>.
  ACE_OS::free ((void *) this->logger_key_);
  ACE_OS::free ((void *) this->server_host_);

  return 0;
}

int
ACE_Client_Logging_Acceptor::make_svc_handler (ACE_Client_Logging_Handler *&sh)
{
  // Always return a pointer to the Singleton handler.
  sh = this->handler_;
  return 0;
}

int
ACE_Client_Logging_Acceptor::info (char **strp, size_t length) const
{
  char buf[BUFSIZ];

  ACE_OS::sprintf (buf, "%d/%s %s",
		   this->server_addr_.get_port_number (), "tcp",
		   "# client logging daemon\n");

  if (*strp == 0 && (*strp = ACE_OS::strdup (buf)) == 0)
    return -1;
  else
    ACE_OS::strncpy (*strp, buf, length);
  return ACE_OS::strlen (buf);
}

ACE_Client_Logging_Acceptor::ACE_Client_Logging_Acceptor (void)
  : server_host_ (ACE_OS::strdup (ACE_DEFAULT_SERVER_HOST)),
    server_port_ (ACE_DEFAULT_LOGGING_SERVER_PORT),
    logger_key_ (ACE_OS::strdup (ACE_DEFAULT_LOGGER_KEY)),
    handler_ (0)
{
}

int
ACE_Client_Logging_Acceptor::init (int argc, char *argv[])
{
  // We'll log *our* error and debug messages to stderr!
  ACE_LOG_MSG->open ("Client Logging Service");

  // Use the options hook to parse the command line arguments and set
  // options.
  this->parse_args (argc, argv);

  // Try to unlink the logger key so weird things don't happen if
  // we're using STREAM pipes.
  ACE_OS::unlink (this->logger_key_);

  // Initialize the acceptor endpoint.
  if (this->open (LOGGING_ADDR (this->logger_key_)) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       this->logger_key_),
                      -1);

  // Establish connection with the server.
  ACE_SOCK_Connector con;
  ACE_SOCK_Stream stream;

  if (con.connect (stream,
                   this->server_addr_) == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "%p, using stderr\n",
		  "can't connect to logging server"));
      // If we can't connect to the server then we'll send the logging
      // messages to stderr.
      stream.set_handle (ACE_STDERR);
    }
  else
    {
      ACE_INET_Addr server_addr;

      // Figure out what remote port we're really bound to.
      if (stream.get_remote_addr (server_addr) == -1)
	ACE_ERROR_RETURN ((LM_ERROR,
                           "%p\n",
                           "get_remote_addr"),
                          -1);
      ACE_DEBUG ((LM_DEBUG,
		  "starting up Client Logging Daemon, "
		  "connected to port %d on handle %u\n",
		  server_addr.get_port_number (),
		  stream.get_handle ()));
    }

  // Create the Singleton <Client_Logging_Handler>.
  ACE_NEW_RETURN (this->handler_,
		  ACE_Client_Logging_Handler (stream.get_handle ()),
		  -1);
  return 0;
}

int
ACE_Client_Logging_Acceptor::parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opt (argc, argv, "h:k:p:", 0);

  for (int c; (c = get_opt ()) != -1; )
    {
      switch (c)
	{
	case 'h':
          ACE_OS::free ((void *) this->server_host_);
	  this->server_host_ = ACE_OS::strdup (get_opt.optarg);
	  break;
	case 'k':
          ACE_OS::free ((void *) this->logger_key_);
	  this->logger_key_ = ACE_OS::strdup (get_opt.optarg);
	  break;
	case 'p':
	  this->server_port_ = ACE_OS::atoi (get_opt.optarg);
	  break;
	default:
	  ACE_ERROR_RETURN ((LM_ERROR,
			    "%n:\n[-p server-port]\n%a", 1),
			   -1);
	}
    }

  if (this->server_addr_.set (this->server_port_,
			      this->server_host_) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%p\n",
                       "set"),
                      -1);
  return 0;
}

int
ACE_Client_Logging_Acceptor::suspend (void)
{
  // To be done...
  return 0;
}

int
ACE_Client_Logging_Acceptor::resume (void)
{
  // To be done...
  return 0;
}

// The following is a "Factory" used by the ACE_Service_Config and
// svc.conf file to dynamically initialize the state of the
// single-threaded logging server.

ACE_SVC_FACTORY_DEFINE (ACE_Client_Logging_Acceptor)

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Acceptor<ACE_Client_Logging_Handler, LOGGING_ACCEPTOR>;
template class ACE_Svc_Handler<LOGGING_STREAM, ACE_NULL_SYNCH>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Acceptor<ACE_Client_Logging_Handler, LOGGING_ACCEPTOR>
#pragma instantiate ACE_Svc_Handler<LOGGING_STREAM, ACE_NULL_SYNCH>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
