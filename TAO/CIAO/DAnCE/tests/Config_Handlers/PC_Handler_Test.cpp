// $Id$

#include "Handler_Test.h"

#ifndef ACE_HAS_BROKEN_NESTED_TEMPLATES

#include "Config_Handlers/PC_Handler.h"

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  return run_test <CIAO::Config_Handler::PC_Handler, Deployment::PackageConfiguration>
    (argc, argv, &CIAO::Config_Handler::PC_Handler::process_PackageConfiguration);
}

#endif // ACE_HAS_BROKEN_NESTED_TEMPLATES
