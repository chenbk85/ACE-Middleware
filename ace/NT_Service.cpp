// $Id$

// NT_Service.cpp

#include "ace/inc_user_config.h"
#if defined (ACE_HAS_WINNT4) && ACE_HAS_WINNT4 != 0

#define ACE_BUILD_DLL
#include "ace/NT_Service.h"
#include "ace/Service_Object.h"

#if !defined (__ACE_INLINE__)
#include "ace/NT_Service.i"
#endif /* __ACE_INLINE__ */

ACE_ALLOC_HOOK_DEFINE(ACE_NT_Service)


// ACE_NT_Service destructor.

ACE_NT_Service::~ACE_NT_Service (void)
{
  if (svc_sc_handle_ != 0)
  {
    CloseServiceHandle(svc_sc_handle_);
    svc_sc_handle_ = 0;
  }
  delete[] desc_;
  delete[] name_;
}


// This default implementation of ACE_NT_Service::open sets the service's
// status to START_PENDING with the estimated time until STARTED set to the
// value given when this object was constructed.  Then the svc function is
// called, which implements the guts of the service.  Note that this function
// is running in a thread created by the OS, not by ACE_Thread_Manager.
// The thread manager does not know anything about this thread.  The service
// can, however, use ACE_Thread_Manager to start more threads if desired.
// When the svc function returns, the service status is set to STOPPED, and
// exit codes set based on errno/GetLastError if the svc function returns -1.
//
// The svc function is expected to set the service status to SERVICE_RUNNING
// after it initializes.
//
// The handle_control function will be called for each time there is a request
// for the service.  It is up to that function and svc to cooperate to both
// respond appropriately to the request (by at least updating the service's
// status) and to fulfill the request.

int
ACE_NT_Service::open (void *args)
{

int svc_return;

  report_status(SERVICE_START_PENDING, 0);

  if ((svc_return = this->svc()) == 0) {
    this->svc_status_.dwWin32ExitCode = NO_ERROR;
    this->svc_status_.dwServiceSpecificExitCode = 0;
  }
  else {
    if (errno == 0) {
      this->svc_status_.dwWin32ExitCode = GetLastError();
    }
    else {
      this->svc_status_.dwWin32ExitCode = ERROR_SERVICE_SPECIFIC_ERROR;
      this->svc_status_.dwServiceSpecificExitCode = errno;
    }
  }

  report_status(SERVICE_STOPPED, 0);

  return svc_return;

}

void
ACE_NT_Service::handle_control (DWORD control_code)
{

  switch(control_code) {
  case SERVICE_CONTROL_SHUTDOWN:
  case SERVICE_CONTROL_STOP:
    report_status(SERVICE_STOP_PENDING);
    /* how to cancel? */
    break;

  case SERVICE_CONTROL_PAUSE:
    report_status(SERVICE_PAUSE_PENDING);
    this->suspend();
    report_status(SERVICE_PAUSED);
    break;

  case SERVICE_CONTROL_CONTINUE:
    report_status(SERVICE_CONTINUE_PENDING);
    this->resume();
    report_status(SERVICE_RUNNING);
    break;

  case SERVICE_CONTROL_INTERROGATE:
    report_status(0);
    break;
  }

  return;

}


void
ACE_NT_Service::name (LPCTSTR name, LPCTSTR desc)
{

  delete[] desc_;
  delete[] name_;

  if (desc == 0)
    desc = name;

  name_ = ACE::strnew(name);
  desc_ = ACE::strnew(desc);

  return;

}


int
ACE_NT_Service::insert (DWORD start_type,
                        DWORD error_control,
                        LPCTSTR exe_path,
                        LPCTSTR group_name,
                        LPDWORD tag_id,
                        LPCTSTR dependencies,
                        LPCTSTR account_name,
                        LPCTSTR password)
{

TCHAR this_exe[MAXPATHLEN];

  if (exe_path == 0)
    {
      if (GetModuleFileName(0, this_exe, sizeof(this_exe)) == 0)
        return -1;
      exe_path = this_exe;
    }	

  SC_HANDLE sc_mgr = OpenSCManager(0, 0, SC_MANAGER_ALL_ACCESS);
  if (sc_mgr == 0)
    return -1;

  SC_HANDLE sh = CreateService(sc_mgr,
                               this->name(),
                               this->desc(),
                               SERVICE_ALL_ACCESS,
                               svc_status_.dwServiceType,
                               start_type,
                               error_control,
                               exe_path,
                               group_name,
                               tag_id,
                               dependencies,
                               account_name, password);
  CloseServiceHandle(sc_mgr);
  if (sh == 0)
    return -1;

  this->svc_sc_handle_ = sh;

  return 0;

}


int
ACE_NT_Service::remove (void)
{

  if (this->svc_sc_handle() == 0)
    return -1;

  if (DeleteService(this->svc_sc_handle()) == 0 &&
      GetLastError() != ERROR_SERVICE_MARKED_FOR_DELETE)
    return -1;

  return 0;

}


// Sets the startup type for the service.  Returns -1 on error, 0 on success.
int
ACE_NT_Service::startup (DWORD startup)
{

  SC_HANDLE svc = this->svc_sc_handle();
  if (svc == 0)
    return -1;

  BOOL ok = ChangeServiceConfig (svc,
                                 SERVICE_NO_CHANGE,// No change to service type
                                 startup,          // New startup type
                                 SERVICE_NO_CHANGE,// No change to error ctrl
                                 0,                // No change to pathname
                                 0,                // No change to load group
                                 0,                // No change to tag
                                 0,                // No change to dependencies
                                 0, 0,             // No change to acct/passwd
                                 0);               // No change to name

  return ok ? 0 : -1;

}


// Returns the current startup type.
DWORD
ACE_NT_Service::startup (void)
{

// The query buffer will hold strings as well as the defined struct.  The
// string pointers in the struct point to other areas in the passed memory
// area, so it has to be large enough to hold the struct plus all the strings.
char                     cfgbuff[1024];
LPQUERY_SERVICE_CONFIG   cfg;
DWORD                    cfgsize, needed_size;

  SC_HANDLE svc = this->svc_sc_handle();
  if (svc == 0)
    return -1;

  cfgsize = sizeof(cfgbuff);
  cfg = (LPQUERY_SERVICE_CONFIG)cfgbuff;
  BOOL ok = QueryServiceConfig (svc, cfg, cfgsize, &needed_size);
  if (ok)
    return cfg->dwStartType;
  return 0;

}


int
ACE_NT_Service::start_svc (ACE_Time_Value *wait_time,
                           DWORD *svc_state,
                           DWORD argc, LPCTSTR *argv)
{

  SC_HANDLE svc = this->svc_sc_handle();
  if (svc == 0)
    return -1;

  if (!StartService(svc, argc, argv))
    return -1;

  wait_for_service_state (SERVICE_RUNNING, wait_time);
  if (svc_state != 0)
    *svc_state = this->svc_status_.dwCurrentState;

  return 0;

}


int
ACE_NT_Service::stop_svc (ACE_Time_Value *wait_time, DWORD *svc_state)
{

  SC_HANDLE svc = this->svc_sc_handle();
  if (svc == 0)
    return -1;

  if (!ControlService (svc, SERVICE_CONTROL_STOP, &this->svc_status_))
    return -1;

  wait_for_service_state (SERVICE_STOPPED, wait_time);
  if (svc_state != 0)
    *svc_state = this->svc_status_.dwCurrentState;

  return 0;

}


int
ACE_NT_Service::pause_svc (ACE_Time_Value *wait_time, DWORD *svc_state)
{

  SC_HANDLE svc = this->svc_sc_handle();
  if (svc == 0)
    return -1;

  if (!ControlService (svc, SERVICE_CONTROL_PAUSE, &this->svc_status_))
    return -1;

  wait_for_service_state (SERVICE_PAUSED, wait_time);
  if (svc_state != 0)
    *svc_state = this->svc_status_.dwCurrentState;

  return 0;

}


int
ACE_NT_Service::continue_svc (ACE_Time_Value *wait_time, DWORD *svc_state)
{

  SC_HANDLE svc = this->svc_sc_handle();
  if (svc == 0)
    return -1;

  if (!ControlService (svc, SERVICE_CONTROL_CONTINUE, &this->svc_status_))
    return -1;

  wait_for_service_state (SERVICE_RUNNING, wait_time);
  if (svc_state != 0)
    *svc_state = this->svc_status_.dwCurrentState;

  return 0;

}


DWORD
ACE_NT_Service::state (ACE_Time_Value *wait_hint)
{

  SC_HANDLE svc = this->svc_sc_handle();
  if (svc == 0)
    return 0;

  QueryServiceStatus (svc, &this->svc_status_);
  if (wait_hint != 0)
    {
      wait_hint->msec(this->svc_status_.dwWaitHint);
    }

  return this->svc_status_.dwCurrentState;

}


int
ACE_NT_Service::state (DWORD *pstate, ACE_Time_Value *wait_hint)
{

  DWORD state = state (wait_hint);
  if (state > 0)
    *pstate = state;
  return state == 0 ? -1 : 0;

}



// test_access
//
// Open a new handle, ignoring any handle open in svc_sc_handle_.  This
// function's results are returned without leaving the handle open.
int
ACE_NT_Service::test_access (DWORD desired_access)
{

  int status = -1;     // Guilty until proven innocent

  SC_HANDLE sc_mgr = OpenSCManager(0, 0, GENERIC_READ);
  if (sc_mgr != 0)
    {
      SC_HANDLE handle = OpenService(sc_mgr,
                                     this->name(),
                                     desired_access);
      CloseServiceHandle(sc_mgr);
      if (handle != 0)
        {
	  status = 0;
	  CloseServiceHandle (handle);
        }
    }

  return status;

}



// report_status
//
// Reports the current status.  If new_status is not 0, it sets the 
// status to the new value before reporting.  NOTE - this assumes that
// no actual service status values have the value 0.  This is true in
// WinNT 4.
// If the status is a 'pending' type, the supplied time hint is used
// unless it's 0, in which case the existing hint is used.  The dwWaitHint
// is not updated by this function.  The checkpoint is incremented
// by one after a pending report.
// 
int
ACE_NT_Service::report_status (DWORD new_status, DWORD time_hint)
{

int   bump_checkpoint = 0,
      retval = 0;
DWORD save_controls = 0;


  if (new_status != 0)
    this->svc_status_.dwCurrentState = new_status;
  switch(this->svc_status_.dwCurrentState) {
  case SERVICE_START_PENDING:
    save_controls = this->svc_status_.dwControlsAccepted;
    this->svc_status_.dwControlsAccepted = 0;
    /* Fall through */
  case SERVICE_STOP_PENDING:
  case SERVICE_CONTINUE_PENDING:
  case SERVICE_PAUSE_PENDING:
    this->svc_status_.dwWaitHint = time_hint ? time_hint : this->start_time_;
    bump_checkpoint = 1;
    break;

  default:
    this->svc_status_.dwCheckPoint = 0;
  }

  retval = SetServiceStatus(this->svc_handle_, &this->svc_status_) ? 0 : -1;

  if (save_controls != 0)
    this->svc_status_.dwControlsAccepted = save_controls;

  if (bump_checkpoint)
    ++this->svc_status_.dwCheckPoint;

  return retval;

}


SC_HANDLE
ACE_NT_Service::svc_sc_handle (void)
{

  if (svc_sc_handle_ == 0)
    {
      SC_HANDLE sc_mgr = OpenSCManager(0, 0, SC_MANAGER_ALL_ACCESS);
      if (sc_mgr != 0)
        {
          svc_sc_handle_ = OpenService(sc_mgr,
                                       this->name(),
                                       SERVICE_ALL_ACCESS);
          CloseServiceHandle(sc_mgr);
        }
    }

  return svc_sc_handle_;

}


void
ACE_NT_Service::wait_for_service_state (DWORD desired_state,
                                        ACE_Time_Value *wait_time)
{

// Doing the right thing with these needs to be added.
ACE_UNUSED_ARG(desired_state);
ACE_UNUSED_ARG(wait_time);

  QueryServiceStatus (this->svc_sc_handle_, &this->svc_status_);
  return;

}

#endif /* ACE_HAS_WINNT4 */
