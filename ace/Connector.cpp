// Connector.cpp
// $Id$

#if !defined (ACE_CONNECTOR_C)
#define ACE_CONNECTOR_C

#define ACE_BUILD_DLL
#include "ace/Connector.h"

/* Shorthand names */
#define SH SVC_HANDLER 
#define PR_CO_1 ACE_PEER_CONNECTOR_1
#define PR_CO_2 ACE_PEER_CONNECTOR_2
#define PEER_ADDR ACE_PEER_CONNECTOR_ADDR

ACE_ALLOC_HOOK_DEFINE(ACE_Connector)

template <class SH, PR_CO_1> ACE_Reactor *
ACE_Connector<SH, PR_CO_2>::reactor (void) const
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::reactor");
  return this->reactor_;
}

template <class SH, PR_CO_1> void
ACE_Connector<SH, PR_CO_2>::reactor (ACE_Reactor *r)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::reactor");
  this->reactor_ = r;
}

template <class SH, PR_CO_1> void
ACE_Connector<SH, PR_CO_2>::dump (void) const
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->handler_map_.dump ();
  this->connector_.dump ();
  ACE_DEBUG ((LM_DEBUG, "reactor_ = %x", this->reactor_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
}

template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::activate_svc_handler (SVC_HANDLER *svc_handler)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::activate_svc_handler");
  // We are connected now, so try to open things up.
  if (svc_handler->open ((void *) this) == -1)
    {
      // Make sure to close down the Channel to avoid descriptor leaks.
      svc_handler->close (0);
      return -1;
    }
  else
    return 0;
}

template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::connect_svc_handler (SVC_HANDLER *svc_handler,
						 const PEER_ADDR &remote_addr,
						 const ACE_Synch_Options &synch_options,
						 const PEER_ADDR &local_addr,
						 int reuse_addr,
						 int flags,
						 int perms)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::connect_svc_handler");
  // Note that if timeout == ACE_Time_Value (x, y) where (x > 0 || y >
  // 0) then this->connector_.connect() will block synchronously.  If
  // <use_reactor> is set then we don't want this to happen (since we
  // want the ACE_Reactor to do the timeout asynchronously).
  // Therefore, we'll force this->connector_ to use ACE_Time_Value (0,
  // 0) in this case...

  ACE_Time_Value *timeout;
  int use_reactor = synch_options[ACE_Synch_Options::USE_REACTOR];

  if (use_reactor)
    timeout = (ACE_Time_Value *) &ACE_Time_Value::zero;
  else 
    timeout = (ACE_Time_Value *) synch_options.time_value ();

  if (this->connector_.connect (svc_handler->peer (),
				remote_addr,
				timeout,
				local_addr,
				reuse_addr,
				flags,
				perms) == -1)
    {
      if (use_reactor && errno == EWOULDBLOCK)
	{
	  // If the connection hasn't completed and we are using
	  // non-blocking semantics then register ourselves with the
	  // ACE_Reactor so that it will call us back when the
	  // connection is complete or we timeout, whichever comes
	  // first...  Note that we needn't check the return value
	  // here because if something goes wrong that will reset
	  // errno this will be detected by the caller (since -1 is
	  // being returned...).
	  this->create_AST (svc_handler, synch_options);
	}
      else
	// Make sure to close down the Channel to avoid descriptor leaks.
	svc_handler->close (0);
      return -1;
    }
  else 
    // Activate immediately if we are connected.
    return this->activate_svc_handler (svc_handler);
}

template <class SH, PR_CO_1> PEER_CONNECTOR &
ACE_Connector<SH, PR_CO_2>::connector (void) const
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::connector");
  return (PEER_CONNECTOR &) this->connector_;
}

template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::open (ACE_Reactor *reactor)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::open");
  this->reactor_ = reactor;
  return 0;
}

// Register the SVC_HANDLER with the map of pending connections so
// that it can be activated when the connection completes.

template <class SH, PR_CO_1> ACE_HANDLE
ACE_Connector<SH, PR_CO_2>::get_handle (void) const
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::get_handle");
  return this->connector_.get_handle ();
}

template <class SH>
ACE_Svc_Tuple<SH>::ACE_Svc_Tuple (SVC_HANDLER *sh, 
				  ACE_HANDLE handle,
				  const void *arg,
				  int id)
  : svc_handler_ (sh), 
    handle_ (handle),
    arg_ (arg),
    cancellation_id_ (id)
{
  ACE_TRACE ("ACE_Svc_Tuple<SH>::ACE_Svc_Tuple");
}

template <class SH> SVC_HANDLER *
ACE_Svc_Tuple<SH>::svc_handler (void)
{ 
  ACE_TRACE ("ACE_Svc_Tuple<SH>::svc_handler");
  return this->svc_handler_; 
}

template <class SH> const void *
ACE_Svc_Tuple<SH>::arg (void)
{ 
  ACE_TRACE ("ACE_Svc_Tuple<SH>::arg");
  return this->arg_;
}

template <class SH> void
ACE_Svc_Tuple<SH>::arg (const void *v)
{ 
  ACE_TRACE ("ACE_Svc_Tuple<SH>::arg");
  this->arg_ = v;
}

template <class SH> ACE_HANDLE
ACE_Svc_Tuple<SH>::handle (void)
{ 
  ACE_TRACE ("ACE_Svc_Tuple<SH>::handle");
  return this->handle_;
}

template <class SH> void
ACE_Svc_Tuple<SH>::handle (ACE_HANDLE h)
{ 
  ACE_TRACE ("ACE_Svc_Tuple<SH>::handle");
  this->handle_ = h;
}

template <class SH> int
ACE_Svc_Tuple<SH>::cancellation_id (void)
{ 
  ACE_TRACE ("ACE_Svc_Tuple<SH>::cancellation_id");
  return this->cancellation_id_;
}

template <class SH> void
ACE_Svc_Tuple<SH>::cancellation_id (int id)
{ 
  ACE_TRACE ("ACE_Svc_Tuple<SH>::cancellation_id");
  this->cancellation_id_ = id;
}

template <class SH> void
ACE_Svc_Tuple<SH>::dump (void) const
{
  ACE_TRACE ("ACE_Svc_Tuple<SH>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, "svc_handler_ = %x", this->svc_handler_));
  ACE_DEBUG ((LM_DEBUG, "\narg_ = %x", this->arg_));
  ACE_DEBUG ((LM_DEBUG, "\ncancellation_id_ = %d", this->cancellation_id_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
}

template <class SH, PR_CO_1> 
ACE_Connector<SH, PR_CO_2>::ACE_Connector (ACE_Reactor *reactor)
  : reactor_ (reactor)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::ACE_Connector");
}

// This method is called if a connection times out before completing.
// In this case, we call our cleanup_AST() method to cleanup the
// descriptor from the ACE_Connector's table.

template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::handle_timeout (const ACE_Time_Value &tv, 
					    const void *arg)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::handle_timeout");
  AST *ast = 0;

  if (this->cleanup_AST (((AST *) arg)->handle (),
			 ast) == -1)
    return -1;
  else 
    {
      ACE_ASSERT (((AST *) arg) == ast);

      // We may need this seemingly unnecessary assignment to work
      // around a bug with MSVC++?
      SH *sh = ast->svc_handler ();

      // Forward to the SVC_HANDLER the <arg> that was passed in as a
      // magic cookie during ACE_Connector::connect().
      sh->handle_timeout (tv, ast->arg ());

      delete ast;
      return 0;
    }
}

template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::cleanup_AST (ACE_HANDLE handle, 
					 ACE_Svc_Tuple<SH> *&ast)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::cleanup_AST");

  // Locate the ACE_Svc_Handler corresponding to the socket descriptor.
  if (this->handler_map_.find (handle, ast) == -1)
    {
      // Error, entry not found in map.
      errno = ENOENT;
      ACE_ERROR_RETURN ((LM_ERROR, "%p %d not found in map\n", 
			"find", handle), -1);
    }

  // Try to remove from ACE_Timer_Queue but if it's not there we ignore
  // the error.
  this->reactor_->cancel_timer (ast->cancellation_id ());

  // Remove ACE_HANDLE from ACE_Reactor.
  this->reactor_->remove_handler (handle, ACE_Event_Handler::ALL_EVENTS_MASK 
				  | ACE_Event_Handler::DONT_CALL);

  // Remove ACE_HANDLE from the map.
  this->handler_map_.unbind (handle);
  return 0;
}

// Called when a failure occurs during asynchronous connection
// establishment.  Simply delegate all work to this->handle_output().

template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::handle_input (ACE_HANDLE h)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::handle_input");
  AST *ast = 0;
  
  if (this->cleanup_AST (h, ast) != -1)
    {
      ast->svc_handler ()->close (0);
      delete ast;
    }
  return 0; // Already removed from the ACE_Reactor.
}

// Finalize a connection established in non-blocking mode.  When a
// non-blocking connect *succeeds* the descriptor becomes enabled for
// writing...  Likewise, it is generally the case that when a
// non-blocking connect *fails* the descriptor becomes enabled for
// reading.

template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::handle_output (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::handle_output");
  AST *ast = 0;

  if (this->cleanup_AST (handle, ast) == -1)
    return 0;

  ACE_ASSERT (ast != 0);   // This shouldn't happen!

  // Transfer ownership of the ACE_HANDLE to the SVC_HANDLER.
  ast->svc_handler ()->set_handle (handle);

  PEER_ADDR raddr;

  // Check to see if we're connected.
  if (ast->svc_handler ()->peer ().get_remote_addr (raddr) != -1)
      this->activate_svc_handler (ast->svc_handler ());
  else // Somethings gone wrong, so close down...
    ast->svc_handler ()->close (0);

  delete ast;
  return 0;
}

// Initiate connection to peer.  

template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::connect (SH *sh, 
				     const PEER_ADDR &remote_addr,
				     const ACE_Synch_Options &synch_options,
				     const PEER_ADDR &local_addr,
				     int reuse_addr,
				     int flags,
				     int perms)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::connect");
  // Delegate to connection strategy.
  return this->connect_svc_handler (sh, remote_addr, synch_options,
				    local_addr, reuse_addr,
				    flags, perms);
				    
}

// Cancel a <svc_handler> that was started asynchronously.
template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::cancel (SH *sh)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::cancel");
  MAP_ITERATOR mi (this->handler_map_);

  for (MAP_ENTRY *me = 0;
       mi.next (me) != 0; 
       mi.advance ())
    if (me->int_id_->svc_handler () == sh)
      {
	AST *ast = 0;
	this->cleanup_AST (me->ext_id_, ast);
	ACE_ASSERT (ast == me->int_id_);
	delete me->int_id_;
	return 0;
      }

  return -1;    
}

// Register the pending SVC_HANDLER with the map so that it can be
// activated later on when the connection complets.

template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::create_AST (SH *sh,
					const ACE_Synch_Options &synch_options)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::create_AST");
  AST *ast;

  ACE_NEW_RETURN (ast, AST (sh, this->get_handle (), synch_options.arg ()), -1);

  // Register this with the reactor for both reading and writing
  // events.
  if (this->reactor_->register_handler (this, 
					ACE_Event_Handler::READ_MASK 
					| ACE_Event_Handler::WRITE_MASK) == -1)
    goto fail1;

  // Bind ACE_Svc_Tuple with the ACE_HANDLE we're trying to connect.
  else if (this->handler_map_.bind (this->get_handle (), ast) == -1)
    goto fail2;
  // If we're starting connection under timer control then we need to
  // schedule a timeout with the ACE_Reactor.
  else
    {
      ACE_Time_Value *tv = (ACE_Time_Value *) synch_options.time_value ();

      if (tv != 0)
	{
	  int cancellation_id =
	    this->reactor_->schedule_timer (this, 
					    (const void *) ast, 
					    *tv);
	  if (cancellation_id == -1)
	    goto fail3;

	  ast->cancellation_id (cancellation_id);
	  return 0;
	}
      else
	{
	  // Reset this because something might have gone wrong
	  // elsewhere...
	  errno = EWOULDBLOCK;
	  return 0; // Ok, everything worked just fine...
	}
    }

  // Undo previous actions using the ol' "goto label and fallthru"
  // trick...
fail3:
  this->handler_map_.unbind (this->get_handle ());
  /* FALLTHRU */
fail2:
  this->reactor_->remove_handler (this, 
				  ACE_Event_Handler::READ_MASK 
				  | ACE_Event_Handler::WRITE_MASK 
				  | ACE_Event_Handler::DONT_CALL);
  /* FALLTHRU */
fail1:
  delete ast;
  return -1;
}

// Terminate the Client ACE_Connector by iterating over any
// unconnected ACE_Svc_Handler's and removing them from the
// ACE_Reactor.  Note that we can't call handle_close() back at this
// point since we own these things and we'll just get called
// recursively!

template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::handle_close (ACE_HANDLE, ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::handle_close");

  if (this->reactor_ != 0)
    {
      // Remove all timer objects from the Reactor's Timer_Queue.
      this->reactor_->cancel_timer (this);

      MAP_ITERATOR mi (this->handler_map_);

      // Iterate through the map and shut down all the pending handlers.

      for (MAP_ENTRY *me = 0;
	   mi.next (me) != 0; 
	   mi.advance ())
	{
	  this->reactor_->remove_handler (me->ext_id_, 
					  mask | ACE_Event_Handler::DONT_CALL);

	  AST *ast = 0;
	  this->cleanup_AST (me->ext_id_, ast);
	  ACE_ASSERT (ast == me->int_id_);
	  delete me->int_id_;
	}
    }

  return 0;
}
template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::fini (void)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::fini");
  // Make sure we call our handle_close(), not a subclass's!
  return ACE_Connector<SH, PR_CO_2>::handle_close ();
}

// Hook called by the explicit dynamic linking facility. 

template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::init (int, char *[])
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::init");
  return -1;
}

template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::suspend (void)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::suspend");
  return -1;
}

template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::resume (void)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::resume");
  return -1;
}

template <class SH, PR_CO_1> int
ACE_Connector<SH, PR_CO_2>::info (char **strp, size_t length) const
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::info");
  char buf[BUFSIZ];
  char addr_str[BUFSIZ];
  PEER_ADDR addr;

  if (this->connector ().get_local_addr (addr) == -1)
    return -1;
  else if (addr.addr_to_string (addr_str, sizeof addr) == -1)
    return -1;

  ACE_OS::sprintf (buf, "%s\t %s %s", 
	     "ACE_Connector", addr_str, "# connector factory\n");

  if (*strp == 0 && (*strp = ACE_OS::strdup (buf)) == 0)
    return -1;
  else
    ACE_OS::strncpy (*strp, buf, length);
  return ACE_OS::strlen (buf);
}

template <class SH, PR_CO_1>
ACE_Connector<SH, PR_CO_2>::~ACE_Connector (void)
{
  ACE_TRACE ("ACE_Connector<SH, PR_CO_2>::~ACE_Connector");
  // We will call our handle_close(), not a subclass's, due to the way
  // that C++ destructors work.
  this->handle_close ();
}

#undef SH
#undef PR_CO_1
#undef PR_CO_2
#endif /* ACE_CONNECTOR_C */
