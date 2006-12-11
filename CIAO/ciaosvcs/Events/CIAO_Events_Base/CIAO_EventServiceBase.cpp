//=============================================================================
/**
 *  @file CIAO_EventServiceBase.cpp
 *
 *  $Id$
 *
 *  @author Gan Deng <dengg@dre.vanderbilt.edu>
 */
//=============================================================================

#include "CIAO_EventServiceBase.h"

namespace CIAO
{
  EventServiceBase::
  EventServiceBase (void)
  {
  }

  EventServiceBase::~EventServiceBase (void)
  {
  }

   void
     EventServiceBase::ciao_push_event (
      ::Components::EventBase * evt,
      const char * source_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::BadEventType))
   {
      ACE_UNUSED_ARG (evt);
      ACE_UNUSED_ARG (source_id);
   }
}
