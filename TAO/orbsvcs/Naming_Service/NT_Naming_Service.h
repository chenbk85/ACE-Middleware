// -*- C++ -*-

// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
//
// = FILENAME
//    NT_Naming_Service.h
//
//
// = DESCRIPTION
//    Run the TAO Naming Service as a Windows NT Service.
//
// = AUTHORS
//    John Tucker <jtucker@infoglide.com> and
//    Mike Vitalo <mvitalo@infoglide.com>
//
// ============================================================================

#ifndef TAO_NT_NAMING_SERVICE_H
#define TAO_NT_NAMING_SERVICE_H

#include /**/ "ace/OS.h"

#if defined (ACE_WIN32)

#include /**/ "ace/NT_Service.h"
#include /**/ "ace/Singleton.h"
#include /**/ "ace/Synch.h"
#include /**/ "tao/orbconf.h"

class TAO_NT_Naming_Service : public ACE_NT_Service
{
  // = TITLE
  //    Run the TAO Naming Service as a Windows NT Service.
public:
  typedef TAO_SYNCH_RECURSIVE_MUTEX MUTEX;

  // = Initialization and termination hooks.
  TAO_NT_Naming_Service (void);
  virtual ~TAO_NT_Naming_Service (void);

  virtual void handle_control (DWORD control_code);
  // We override <handle_control> because it handles stop requests
  // privately.

  virtual int handle_exception (ACE_HANDLE h);
  // We override <handle_exception> so a 'stop' control code can pop
  // the reactor off of its wait.

  virtual int svc (void);
  // This is a virtual method inherited from ACE_NT_Service.

  virtual int init (int argc,
                    ACE_TCHAR *argv[]);
  // Initialize the objects argc_ and argv_ attributes values.

private:
  // = Keep track of the "command-line" arguments.
  int argc_;
  int argc_save_;
  // Argument count.

  char **argv_;
  char **argv_save_;
  // Argument list.

  friend class ACE_Singleton<TAO_NT_Naming_Service, MUTEX>;

protected:
  /**
  * A class with a "magic" constructor/desructor to call
  * ACE_NT_Service::report_status() when an instance of it goes out of scope, as
  * it might should an exception occurs.
  */
  class AutoFinalizer
  {
    
  public:
    AutoFinalizer (TAO_NT_Naming_Service &service);
    ~AutoFinalizer ();
    
  private:
    TAO_NT_Naming_Service &service_;
  };
};



typedef ACE_Singleton<TAO_NT_Naming_Service, TAO_NT_Naming_Service::MUTEX> SERVICE;

#endif /* ACE_WIN32 */
#endif /* TAO_NT_NAMING_SERVER_H */
