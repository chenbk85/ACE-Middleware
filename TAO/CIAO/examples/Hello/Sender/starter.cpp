//$Id$:
/**
 * @file starter.cpp
 *
 * @auther Tao Lu <lu@dre.vanderbilt.edu>
 */

#include "SenderC.h"
#include "ace/Get_Opt.h"

//IOR file of the Sender
char * ior = 0;

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "k");
  int c = 0;
  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'k':
        ior = get_opts.opt_arg ();
      break;

      case '?':  // display help for use of the server.
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s\n"
			   "-k <Sender IOR> (default is file://sender.ior)\n",
                           argv [0]),
                          -1);
      }

  if (ior  == 0)
    ior = "file://sender.ior";
  return 0;
}

int
main (int argc, char *argv[])
{
  ACE_TRY_NEW_ENV
    {
      // Initialize orb
      CORBA::ORB_var orb = CORBA::ORB_init (argc, argv ACE_ENV_ARG_PARAMETER);

      if (parse_args (argc, argv) != 0)
        return -1;

      CORBA::Object_var obj
        = orb->string_to_object (ior
                                 ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      Hello::Sender_var sender
        = Hello::Sender::_narrow (obj.in ()
				    ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (sender.in ()))
        ACE_ERROR_RETURN ((LM_ERROR, "Unable to acquire Sender's objref\n"), -1);

      sender->start (ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      orb->destroy (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
			   "Unknown exception \n");
      return -1;
    }
  ACE_ENDTRY;

  return 0;
}
