// $Id$

// ============================================================================
//
// = LIBRARY
//    examples/Web_Crawler
//
// = FILENAME
//    main.cpp
//
// = DESCRIPTION
//     This program implements a Web crawler that can be configured to
//     apply various strategies to URLs that it visits.
//
// = AUTHOR
//    Doug Schmidt <schmidt@cs.wustl.edu>
//
// ============================================================================

#include "ace/OS_main.h"
#include "ace/Signal.h"
#include "Web_Crawler.h"
#include "Options.h"

ACE_RCSID(Web_Crawler, main, "$Id$")

void sig_handler (int)
{
  ACE_DEBUG ((LM_DEBUG,
              "aborting!\n"));
  ACE_OS::abort ();
}

int 
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  ACE_Sig_Action sa ((ACE_SignalHandler) sig_handler, SIGFPE);

  Web_Crawler crawler;
  
  if (crawler.open (argc, argv) == -1)
    return 1;
  else if (crawler.run () == -1)
    return 1;
  else
    return 0;
}



