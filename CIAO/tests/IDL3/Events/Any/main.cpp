#include "EventAnyC.h"
#include "ace/Get_Opt.h"

bool debug = false;

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "d");
  int c = 0;
  
  while ((c = get_opts ()) != -1)
    {
      switch (c)
        {
          case 'd':
            debug = true;
	          break;
          case '?':  // display help for use of the server.
          default:
            ACE_ERROR_RETURN ((LM_ERROR,
                              "Usage:  %s\n"
			                        "-d (display debug messages)",
                              argv [0]),
                              -1);
            break;
        }
    }

  return 0;
}

void
debug_msg (const char *msg)
{
  if (debug)
    {
      ACE_DEBUG ((LM_DEBUG, "Error: %s\n", msg));
    }
}

int
main (int argc, char *argv[])
{
  ACE_TRY
    {
      if (parse_args (argc, argv) != 0)
        {
          return -1;
        }
        
      CORBA::ORB_var orb = CORBA::ORB_init (argc, argv, "");     
      StringMsg_init *StringMsg_factory = new StringMsg_init;

      orb->register_value_factory (StringMsg_factory->tao_repository_id (),
                                   StringMsg_factory);
      StringMsg_factory->_remove_ref (); // release ownership
      
      const char *test_str = "a message";

      StringMsg_var ev = new OBV_StringMsg;    
      ev->str_msg (test_str);
      
      CORBA::Any in_any;
      in_any <<= ev.in ();
      
      TAO_OutputCDR out;
      CORBA::Boolean good = out << in_any;
      
      if (!good)
        {
          debug_msg ("Any marshaling failed");            
          return -1;
        }
        
      TAO_InputCDR in (out);
      CORBA::Any out_any;
      good = in >> out_any;
                                          
      if (!good)
        {
          debug_msg ("Any demarshaling failed");           
          return -1;
        }
        
      StringMsg *ev_out = 0;
      good = out_any >>= ev_out;
      
      if (!good)
        {
          debug_msg ("Any extraction failed");
          return -1;
        }
        
      const char *result_str = ev_out->str_msg ();
      
      if (result_str == 0 || ACE_OS::strcmp (result_str, test_str) != 0)
        {
          debug_msg ("Extracted member string null or incorrect");
          return -1;
        }
        
      orb->destroy ();
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "caught exception:");
      return 1;
    }
  ACE_ENDTRY;

  return 0;
}

