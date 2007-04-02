// $Id$

#include "tao/ORB.h"
#include "ace/Get_Opt.h"
#include "ace/Service_Config.h"

ACE_RCSID (Bug_2735_Regression,
           server,
           "$Id$")

static const ACE_TCHAR* server_strat =
  ACE_STATIC_SERVICE_DIRECTIVE ("Server_Strategy_Factory",
                                "-ORBConcurrency thread-per-connection");
static const ACE_TCHAR* foo_strat =
  ACE_STATIC_SERVICE_DIRECTIVE ("Foo_Strategy_Factory", "");

enum Strategy { SERVER, FOO };

static Strategy strategy = SERVER;

static int
parse_args (int argc, ACE_TCHAR *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, ACE_TEXT ("fs"));
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {       
      case 'f':
        strategy = FOO;
        break;
      case 's':
        strategy = SERVER;
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage: %s "
                           "-f "
                           "-s "
                           "\n", 
                           argv [0]),
                          -1);
      }
  return 0;   
}  


int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  try
    {
      if (parse_args (argc, argv) == -1)
        return -1;

      int targc = 3;
      char* targv[] = { "server", "-ORBSvcConfDirective", 0 };
      switch (strategy)
        {
        case FOO:
          targv[2] = const_cast<char*> (ACE_TEXT_ALWAYS_CHAR (foo_strat));
          break;
        case SERVER:
          targv[2] = const_cast<char*> (ACE_TEXT_ALWAYS_CHAR (server_strat));
          break;
        }
      CORBA::ORB_var orb = CORBA::ORB_init (targc, targv);
      orb->destroy ();
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Exception caught:");
      return 1;
    }

  return 0;
}
