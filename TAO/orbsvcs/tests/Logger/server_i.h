// -*- c++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/orbsvcs/tests/Logger
//
// = FILENAME
//    server_i.h
//
// = DESCRIPTION
//      This class implements a simple "logger" CORBA server for the Logger
//      example using skeletons generated by the TAO ORB IDL compiler.
//
// = AUTHORS
//    Nagarajan Surendran <naga@cs.wustl.edu>
//    Matthew Braun <mjb2@cec.wustl.edu>
//
// ============================================================================

#ifndef _C_SERVER_H
#define _C_SERVER_H

#include "ace/Get_Opt.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Log_Msg.h"
#include "tao/TAO.h"
#include "orbsvcs/CosNamingC.h"
#include "orbsvcs/Naming/Naming_Utils.h"
#include "orbsvcs/Log/Logger_i.h"
#include "orbsvcs/LoggerS.h"

class Logger_Server
{
  // = TITLE
  //   Defines a Logger_Server class that implements the functionality
  //   of a server process as an object.
  //
  // = DESCRIPTION
  //   The interface is quite simple. A server program has to call
  //   init to initialize the logger_server's state and then call run
  //   to run the orb.
public:
  // = Initialization and termination methods.
  Logger_Server (void);
  // Constructor.

  ~Logger_Server (void);
  // Destructor.

  int init (int argc,
            char **argv,
            CORBA::Environment& env);
  // Initialize the Logger_Server state - parsing arguments and ...

  int run (CORBA::Environment& env);
  // Run the ORB.

private:
  int parse_args (void);
  // Parses the commandline arguments.

  int init_naming_service (CORBA::Environment &env);
  // Initialises the name server and registers logger_factory with the
  // name server.

  TAO_ORB_Manager orb_manager_;
  // The ORB manager.

  TAO_Naming_Server my_name_server_;
  // An instance of the name server used for registering the factory
  // objects.

  Logger_Factory_i factory_impl_;
  // Implementation object of the Logger_Factory.

  Logger_Factory_var factory_;
  // Factory_var to register with NamingService.

  int argc_;
  // Number of commandline arguments.

  char **argv_;
  // commandline arguments.
};

#endif /* _C_SERVER_H */
