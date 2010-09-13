// $Id$

#define ACE_BUILD_SVC_DLL

#include "ace/Get_Opt.h"

#include "jaws3/Concurrency.h"

#include "HTTP_Service_Handler.h"
#include "HTTP_States.h"
#include "HTTP_Data.h"

JAWS_HTTP_Service_Handler::JAWS_HTTP_Service_Handler (void)
  : JAWS_Protocol_Handler (JAWS_HTTP_Read_Request::instance (), & this->data_)
  , data_ (this)
{
}

int
JAWS_HTTP_Service_Handler::open (void *)
{
  int result = JAWS_Concurrency::instance ()->putq (this);
  if (result < 0)
    return -1;

  return 0;
}

int
JAWS_HTTP_Service_Handler::close (unsigned long)
{
  delete this;
  return 0;
}

int
JAWS_HTTP_Acceptor::init (int argc, ACE_TCHAR *argv[])
{
  ACE_Get_Opt opt (argc, argv, ACE_TEXT("p:"));

  unsigned short p = 0;

  int c;
  while ((c = opt ()) != -1)
    switch (c)
      {
      case 'p':
        p = (unsigned short) ACE_OS::atoi (opt.optarg);
        break;
      default:
        break;
      }

  if (p == 0)
    p = 8000;

  if (this->open (ACE_INET_Addr (p)) == -1)
    {
      ACE_DEBUG ((LM_DEBUG, "%p\n", "ACE_Acceptor::open"));
      return -1;
    }

  return 0;
}

ACE_SVC_FACTORY_DEFINE (JAWS_HTTP_Acceptor)
