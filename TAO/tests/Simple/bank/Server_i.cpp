// $Id$

#include "ace/Get_Opt.h"
//#include "tao/ORB.h"
#include "Server_i.h"

ACE_RCSID(Bank, Server_i, "$Id$")

// Constructor.

Server_i::Server_i (void)
  : ior_output_file_ (0)
{
  // no-op.
}

// Destructor.

Server_i::~Server_i (void)
{
  // no-op.
}

// Parse the command-line arguments and set options.

int
Server_i::parse_args (void)
{
  ACE_Get_Opt get_opts (this->argc_, this->argv_, "do:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'd':  // debug flag.
        TAO_debug_level++;
        break;
      case 'o':  // output the IOR to a file.
        this->ior_output_file_ =
	  ACE_OS::fopen (get_opts.optarg, "w");

        if (this->ior_output_file_ == 0)
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Unable to open %s for writing: %p\n",
                             get_opts.optarg), -1);
        break;
      case '?':  // display help for use of the server.
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s"
                           " [-d]"
                           " [-o] <ior_output_file>"
                           "\n",
                           argv_ [0]),
                          1);
      }

  // Indicates successful parsing of command line.
  return 0;
}

// Initialisation of Naming Service and registering the AccountManager Object

int
Server_i::init_naming_service (CORBA::Environment& env)
{

  CORBA::ORB_var orb;
  PortableServer::POA_var child_poa;

  orb = this->orb_manager_.orb ();
  child_poa = this->orb_manager_.child_poa ();

  int result = this->my_name_server_.init (orb.in (),
					   child_poa.in ());
  if (result == -1)
    return result;

  // Generate an IOR for the AccountManager Object and register it
  // with POA.

  Bank::AccountManager_var account_manager =
    this->account_manager_impl_->_this (env);

  CORBA::String_var objref =
    orb->object_to_string (account_manager.in (),
			   env);
  TAO_CHECK_ENV_RETURN (env, -1);

  // Print the Account Manager IOR on the console.
  ACE_DEBUG ((LM_DEBUG,
	      "The IOR is: <%s>\n",
	      (const char *) objref));


  // Print the Account Manager IOR to a file.
  if (this->ior_output_file_)
    {
      ACE_OS::fprintf (this->ior_output_file_,
                       "%s",
                       account_manager.in ());
      ACE_OS::fclose (this->ior_output_file_);
    }


  // Bind the Account Manager with the naming Service

  CosNaming::Name account_manager_name (1);
  account_manager_name.length (1);
  account_manager_name[0].id = CORBA::string_dup ("AccountManager");
  this->my_name_server_->bind (account_manager_name,
                              account_manager.in (),
                              env);
  TAO_CHECK_ENV_RETURN (env, -1);

  return 0;
}

// Initialize the server.

int
Server_i::init (int argc,
		char *argv[],
		CORBA::Environment &env)
{
  // Call the init of <TAO_ORB_Manager> to initialize the ORB and
  // create a child POA under the root POA.
  if (this->orb_manager_.init_child_poa (argc,
                                         argv,
                                         "child_poa",
                                         env) == -1)
  ACE_ERROR_RETURN ((LM_ERROR,
                     "%p\n",
                     "init_child_poa"),
                     -1);
  TAO_CHECK_ENV_RETURN (env, -1);

  this->argc_ = argc;
  this->argv_ = argv;

  int retval = this->parse_args ();

  if (retval != 0)
    return retval;

  CORBA::ORB_var orb = this->orb_manager_.orb ();

  // Now create the implementation for the Account Manager.
  ACE_NEW_RETURN (this->account_manager_impl_,
		  AccountManager_i,
		  -1);

  // Register the above implementation with the Naming Service.
  this->init_naming_service (env);
  return 0;
}

int
Server_i::run (CORBA::Environment &env)
{
  // Run the main event loop for the ORB.
  if (this->orb_manager_.run (env) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Server_i::run"),
                      -1);
  return 0;
}
