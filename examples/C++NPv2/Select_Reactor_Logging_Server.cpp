/*
** $Id$
**
** Copyright 2002 Addison Wesley. All Rights Reserved.
*/

#include "ace/streams.h"
#include "ace/Reactor.h"
#include "ace/Select_Reactor.h"
#include "ace/Thread_Manager.h"

#include <string>

#if defined (ACE_WIN32) && (!defined (ACE_HAS_STANDARD_CPP_LIBRARY) || \
                            (ACE_HAS_STANDARD_CPP_LIBRARY == 0))
#  error "Must add to config.h: #define ACE_HAS_STANDARD_CPP_LIBRARY 1"
#endif

#include "Reactor_Logging_Server.h"
#include "Logging_Acceptor_Ex.h"


template <class ACCEPTOR>
Reactor_Logging_Server<ACCEPTOR>::Reactor_Logging_Server
  (int argc, char *argv[], ACE_Reactor *reactor)
  : ACCEPTOR (reactor) {
  u_short logger_port = argc > 1 ? atoi (argv[1]) : 0;
  ACE_TYPENAME ACCEPTOR::PEER_ADDR server_addr;
  int result;

  if (logger_port != 0)
    result = server_addr.set (logger_port, INADDR_ANY);
  else
    result = server_addr.set ("ace_logger", INADDR_ANY);
  if (result != -1)
    result = ACCEPTOR::open (server_addr);
  if (result == -1) reactor->end_reactor_event_loop ();
}

typedef Reactor_Logging_Server<Logging_Acceptor_Ex>
        Server_Logging_Daemon;


class Quit_Handler : public ACE_Event_Handler {
  friend class ace_dewarn_gplusplus;
public:
  Quit_Handler (ACE_Reactor *r) { reactor (r); }

  virtual int handle_exception (ACE_HANDLE) {
    reactor ()->end_reactor_event_loop ();
    return -1; // Trigger call to handle_close() method.
  }

  virtual int handle_close (ACE_HANDLE, ACE_Reactor_Mask)
  { delete this; return 0; }

private:

  // Private destructor ensures dynamic allocation.
  virtual ~Quit_Handler () {}
};


static void *event_loop (void *arg) {
  ACE_Reactor *reactor = ACE_static_cast (ACE_Reactor *, arg);

  reactor->owner (ACE_OS::thr_self ());
  reactor->run_reactor_event_loop ();
  return 0;
}


static void *controller (void *arg) {
  ACE_Reactor *reactor = ACE_static_cast (ACE_Reactor *, arg);

  Quit_Handler *quit_handler = 0;
  ACE_NEW_RETURN (quit_handler, Quit_Handler (reactor), 0);

  for (;;) {
    std::string user_input;
    std::getline (cin, user_input, '\n');
    if (user_input == "quit") {
      reactor->notify (quit_handler);
      break;
    }
  }
  return 0;
}


int main (int argc, char *argv[])
{
  ACE_Select_Reactor select_reactor;
  ACE_Reactor reactor (&select_reactor);

  Server_Logging_Daemon *server;
  ACE_NEW_RETURN (server,
                  Server_Logging_Daemon (argc, argv, &reactor),
                  1);
  ACE_Thread_Manager::instance ()->spawn (event_loop, &reactor);
  ACE_Thread_Manager::instance ()->spawn (controller, &reactor);
  return ACE_Thread_Manager::instance ()->wait ();
}
