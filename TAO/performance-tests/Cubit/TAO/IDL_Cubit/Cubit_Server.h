
//=============================================================================
/**
 *  @file    Cubit_Server.h
 *
 *  $Id$
 *
 *    This class implements a simple "cube" CORBA server for the Cubit
 *    example using skeletons generated by the TAO ORB IDL compiler.
 *
 *
 *  @author Nagarajan Surendran (naga@cs.wustl.edu)
 */
//=============================================================================


#ifndef _CUBIT_SERVER_H
#define _CUBIT_SERVER_H

#include "ace/Get_Opt.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Log_Msg.h"
#include "tao/Utils/ORB_Manager.h"
#include "Cubit_Client.h"
#include "Cubit_i.h"

/**
 * @class Cubit_Server
 *
 * @brief Defines a Cubit Server class that implements the functionality
 * of a server process as an object.
 *
 * The interface is quite simple. A server program has to call
 * init to initialize the cubit_server's state and then call run
 * to run the orb.
 */
class Cubit_Server
{
public:
  // = Initialization and termination methods.
  /// Default constructor
  Cubit_Server (void);

  /// Destructor
  ~Cubit_Server (void);

  /// Initialize the Cubit_Server state - parsing arguments and ...
  int init (int argc,
            ACE_TCHAR **argv);

  /// Run the orb
  int run (void);

private:
  /// Parses the commandline arguments.
  int parse_args (void);

  /// File to output the cubit factory IOR.
  FILE* ior_output_file_;

  /// The ORB manager.
  TAO_ORB_Manager orb_manager_;

  /// Implementation object of the cubit factory.
  Cubit_Factory_i *factory_impl_;

  /// Id of the factory.
  CORBA::String_var factory_id_;

  /// Number of commandline arguments.
  int argc_;

  /// commandline arguments.
  ACE_TCHAR **argv_;
};

#endif /* _CUBIT_SERVER_H */
