#include "ace/DLL_Manager.h"
#include "ace/Dynamic_Service_Dependency.h"
#include "ace/Service_Config.h"

ACE_RCSID (ace,
           Dynamic_Service_Dependency,
           "$Id$")


ACE_BEGIN_VERSIONED_NAMESPACE_DECL


ACE_Dynamic_Service_Dependency::ACE_Dynamic_Service_Dependency (const ACE_TCHAR *principal)
{
  this->init (ACE_Service_Config::current (), principal);
}

ACE_Dynamic_Service_Dependency::ACE_Dynamic_Service_Dependency (const ACE_Service_Gestalt *cfg,
                                                                const ACE_TCHAR *principal)
{
  this->init (cfg, principal);
}


ACE_Dynamic_Service_Dependency::~ACE_Dynamic_Service_Dependency (void)
{
  if (ACE::debug () > 1)
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) DSD, this=%@ - destroying dependency\n"),
                this));
}

void
ACE_Dynamic_Service_Dependency::init (const ACE_Service_Gestalt *cfg,
                                      const ACE_TCHAR *principal)
{
  const ACE_Service_Type* st = ACE_Dynamic_Service_Base::find_i (cfg, principal);
  if (ACE::debug () > 1)
  {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) DSD, this=%@ - creating dependency on "), this));
    st->dump ();
  }
  this->tracker_ = st->dll ();
}


ACE_END_VERSIONED_NAMESPACE_DECL
