// $Id$

#include "mpeg_server/Video_Server.h"

int
main (int argc, char **argv)
{
  ACE_DEBUG ((LM_DEBUG, "(%P|%t) %s:%d\n", __FILE__, __LINE__));
  Video_Server video_server; 
  
  TAO_TRY
    {
      // Parses the arguments, and initializes the server.
      if (video_server.init (argc,
                             argv,
                             TAO_TRY_ENV) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "(%P|%t) Video_Server: init failed\n"),
                          -1);

      // Release the lock on which the server is waiting
      ACE_SV_Semaphore_Simple semaphore (4242);
      semaphore.release ();
      ACE_DEBUG ((LM_DEBUG, "(%P|%t) %s:%d\n", __FILE__, __LINE__));
      // Increment ACE_SV_Semaphore by one. Dijkstra's V operation,
      // Tannenbaums UP operation.

      // %% potential race condition if the client
      // sends a request before we enter the event loop
      // Runs the reactor event loop.
      video_server.run (TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("Exception");
      return -1;
    }
  TAO_ENDTRY;
  
  return 0;
}
