//
// $Id$
//

#include "Server_Task.h"

ACE_RCSID(MT_Timeout, Server_Task, "$Id$")

Server_Task::Server_Task (ACE_Thread_Manager *thr_mgr,
                          CORBA::ORB_ptr orb,
                          const ACE_Time_Value &running_time)
  : ACE_Task_Base (thr_mgr)
  , orb_ (CORBA::ORB::_duplicate (orb))
  , running_time_ (running_time)
{
}

int
Server_Task::svc (void)
{
  ACE_DEBUG ((LM_DEBUG, "(%P|%t) Starting server task\n"));
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      this->orb_->run (this->running_time_, ACE_TRY_ENV);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return -1;
    }
  ACE_ENDTRY;
  ACE_DEBUG ((LM_DEBUG, "(%P|%t) Server task finished\n"));
  return 0;
}
