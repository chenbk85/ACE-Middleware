// $Id$

#include "Consumer_Input_Handler.h"
#include "Consumer_Handler.h"

ACE_RCSID(Consumer, Consumer_Input_Handler, "$Id$")

Consumer_Input_Handler::~Consumer_Input_Handler (void)
{
  ACE_DEBUG ((LM_DEBUG,
              "closing down Input_Handler::~Input_Handler\n"));
  this->handle_close ();
}

int
Consumer_Input_Handler::consumer_initiated_shutdown (void)
{
  return this->consumer_initiated_shutdown_;
}

void
Consumer_Input_Handler::consumer_initiated_shutdown (int c)
{
  this->consumer_initiated_shutdown_ = c;
}

ACE_HANDLE
Consumer_Input_Handler::get_handle (void) const
{
  return this->handle_;
}

int
Consumer_Input_Handler::handle_close (ACE_HANDLE, ACE_Reactor_Mask)
{
  ACE_DEBUG ((LM_DEBUG,
	      "closing down Consumer::Input_Handler\n"));

  Event_Comm::Consumer *receiver = this->receiver_handler_->receiver ();
  Event_Comm::Notifier *notifier = this->receiver_handler_->notifier ();

  if (this->consumer_initiated_shutdown ())
    {
      // Only try to unsubscribe if the Consumer initiated the
      // shutdown.  Otherwise, the Supplier initiated it and it has
      // probably gone away by now!
      TAO_TRY
        {
          // Gracefully shutdown the Receiver by removing it from the
          // Notifier's internal map.

          notifier->unsubscribe (receiver, "", TAO_TRY_ENV); //IT_X);
	  TAO_CHECK_ENV;
        }
      TAO_CATCHANY
        {
          TAO_TRY_ENV.print_exception ("Consumer_Input_Handler::handle_close\n");
        }
      TAO_ENDTRY;
    }

  // Don't execute a callback here otherwise we'll recurse
  // indefinitely!
  if (ACE_Reactor::instance ()->remove_handler
      (this,
       ACE_Event_Handler::READ_MASK | ACE_Event_Handler::DONT_CALL) == -1)
    ACE_ERROR ((LM_ERROR,
                "%p\n",
                "remove_handler"));

  // *Must* be allocated dyanmically!
  ::operator delete (this);
  return 0;
}

Consumer_Input_Handler::Consumer_Input_Handler (Consumer_Handler *ch,
			      ACE_HANDLE handle)
  : receiver_handler_ (ch),
    handle_ (handle),
    consumer_initiated_shutdown_ (0)
{
  if (ACE_Reactor::instance ()->register_handler
      (this,
       ACE_Event_Handler::READ_MASK) == -1)
    ACE_ERROR ((LM_ERROR,
                "Consumer_Input_Handler::Input_Handler\n"));
}

int
Consumer_Input_Handler::handle_input (ACE_HANDLE h)
{
  char buf[BUFSIZ];

  // Read up to BUFSIZ worth of data from ACE_HANDLE h.
  ssize_t n = ACE_OS::read (h, buf, sizeof buf - 1);

  if (n > 0)
    {
      // Null terminate the buffer, replacing the '\n' with '\0'.
      if (buf[n - 1] == '\n' || buf[n - 1] == EOF)
	buf[n - 1] = '\0';
      else
	buf[n] = '\0';
      ACE_DEBUG ((LM_DEBUG,
                  "notifying for event %s\n",
                  buf));

    }
  else
    {
      ACE_OS::strcpy (buf, "quit");
      ACE_DEBUG ((LM_DEBUG,
                  "shutting down Input_Handler\n"));
    }

  Event_Comm::Notifier *notifier =
    this->receiver_handler_->notifier ();

  ACE_ASSERT (notifier != 0);

  if (ACE_OS::strcmp (buf, "quit") == 0)
    {
      // Consumer wants to shutdown.
      this->consumer_initiated_shutdown (1);



      // Tell the main event loop to shutdown.
      ACE_Reactor::end_event_loop();
    }
  else
    {
      TAO_TRY
        {
          Event_Comm::Event event;

          event.tag_ = ACE_OS::strdup (buf);

          notifier->push (event, TAO_TRY_ENV); //IT_X);
	  TAO_CHECK_ENV;
	}
      TAO_CATCHANY
        {
          TAO_TRY_ENV.print_exception("Unexpected exception\n");
        }
      TAO_ENDTRY;
    }

  /* NOTREACHED */
  return 0;
}
