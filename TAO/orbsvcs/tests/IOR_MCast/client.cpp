// $Id$

#include "ior_mcast_client_i.h"

int ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  try
    {
      ior_mcast_Client_i client;

      int init_result;
      init_result = client.init (argc, argv);

      return 0;
    }
  catch (const CORBA::SystemException&)
    {
      // Ignore
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("client");
    }

  return 0;
}
