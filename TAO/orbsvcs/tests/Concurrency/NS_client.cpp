// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/orbsvcs/bin/Naming_Service/TAO
//
// = FILENAME
//    clnt.cpp
//
// = DESCRIPTION
//      This class implements a simple CORBA client for the CosNaming
//      example using stubs generated by the TAO ORB IDL compiler.
//
// = AUTHORS
//      Sergio Flores-Gaitan <sergio@cs.wustl.edu>
//      Torben Worm <tworm@cs.wustl.edu>
//
// ============================================================================

#include "NS_client.h"
#include "tao/debug.h"
#include <stdio.h>

ACE_RCSID(Concurrency, NS_client, "$Id$")

// constructor

CosNaming_Client::CosNaming_Client (void)
  : list_contents_ (0),
    resolve_name_ (0),
    name_to_resolve_ (0),
    context_to_resolve_ (0),
    argc_ (0),
    argv_ (0),
    exit_later_ (0)
{
}

// Parses the command line arguments and returns an error status.

int
CosNaming_Client::parse_args (void)
{
  ACE_Get_Opt get_opts (argc_, argv_, "dxn:c:l");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'd':  // debug flag
        TAO_debug_level++;
        break;
      case 'l':
        this->list_contents_ = 1;
        break;
      case 'x':
        this->exit_later_++;
        break;
      case 'n':
        this->resolve_name_ = 1;
        this->name_to_resolve_ = get_opts.opt_arg ();
        break;
      case 'c':
        this->resolve_name_ = 1;
        this->context_to_resolve_ = get_opts.opt_arg ();
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s"
                           " [-d]"
                           " [-x]"
                           "\n",
                           this->argv_ [0]),
                          -1);
      }

  // Indicates successful parsing of command line.
  return 0;
}

// Execute client example code.

int
CosNaming_Client::run (void)
{
  // @@ TODO, add some interesting test here, maybe creating some
  // nested naming contexts and registering a number of objreferences
  // in there.  We could even use the iterators.

  if (this->resolve_name_)
    resolve_name (this->context_to_resolve_,
                  this->name_to_resolve_);

  if (this->list_contents_)
    list_contents ();

  return 0;
}

CosNaming_Client::~CosNaming_Client (void)
{
}

int
CosNaming_Client::resolve_name (char *c, char *n)
{
  TAO_TRY
    {
      CosNaming::Name name (2);
      name.length (2);
      name[0].id = CORBA::string_dup (c);
      name[1].id = CORBA::string_dup (n);
      CORBA::Object_var obj = this->my_name_client_->resolve (name,
                                                              TAO_TRY_ENV);
      TAO_CHECK_ENV;

      if (CORBA::is_nil (obj.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Could not resolve name in Naming service <%s>\n"),
                          -1);
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("init");
      return -1;
    }
  TAO_ENDTRY;
  return 0;
}

void
CosNaming_Client::list_contents (void)
{
  CosNaming::BindingIterator_var bi;
  CosNaming::BindingList_var li;
  CORBA::ULong how_many = 0;
  CosNaming::Binding_var b;
  CosNaming::Name n;
  CORBA::ULong names = 0;

  TAO_TRY
    {
      this->my_name_client_->list (how_many, li, bi, TAO_TRY_ENV);

      while (bi->next_one (b, TAO_TRY_ENV))
        {
          n = b->binding_name;
          names = n.length ();
          ACE_DEBUG ((LM_DEBUG,
                      " (%i) Name: ",
                      names));

          for (CORBA::ULong i = 0; i < names; i++)
            ACE_DEBUG ((LM_DEBUG,
                        "%s ",
                        n[i].id._retn ()));

          ACE_DEBUG ((LM_DEBUG, "type: %s\n",
                      b->binding_type == CosNaming::ncontext ? "C" : "O"));
        }
    }
  TAO_CATCHANY
    {
    }
  TAO_ENDTRY;
}

int
CosNaming_Client::init (int argc, char *argv[])
{
  this->argc_ = argc;
  this->argv_ = argv;

  TAO_TRY
    {
      // Initialize ORB.
      this->orb_ = CORBA::ORB_init (argc, argv, "internet", TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Initialize the naming services
      if (my_name_client_.init (orb_) != 0)
	ACE_ERROR_RETURN ((LM_ERROR,
			   " (%P|%t) Unable to initialize "
			   "the TAO_Naming_Client. \n"),
			  -1);

      // Parse command line and verify parameters.
      if (this->parse_args () == -1)
        return -1;
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("init");
      return -1;
    }
  TAO_ENDTRY;

  return 0;
}

// This function runs the test.

int
main (int argc, char **argv)
{
  CosNaming_Client cosnaming_client;

  if (cosnaming_client.init (argc, argv) == -1)
    return 1;

  return cosnaming_client.run ();
}
