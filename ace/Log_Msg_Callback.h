// -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
//
// = FILENAME
//    Log_Msg_Callback.h
//
// = AUTHOR
//    Douglas C. Schmidt <schmidt@cs.wustl.edu>
//
// ============================================================================

#ifndef ACE_LOG_MSG_CALLBACK_H
#define ACE_LOG_MSG_CALLBACK_H
#include "ace/pre.h"

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class ACE_Log_Record;

/// An interface class used to get logging callbacks.
/**
 *
 *     Users who are interested in getting the logging messages
 *     directly, can subclass this interface and override the log()
 *     method. They must then register their subclass with the
 *     Log_Msg class and make sure that they turn on the
 *     ACE_Log_Msg::MSG_CALLBACK flag.
 *
 *     Your <log> routine is called with an instance of
 *     ACE_Log_Record.  From this class, you can get the log
 *     message, the verbose log message, message type, message
 *     priority, and so on.
 *
 *     Remember that there is one Log_Msg object per thread.
 *     Therefore, you may need to register your callback object with
 *     many <ACE_Log_Msg> objects (and have the correct
 *     synchronization in the <log> method) or have a separate
 *     callback object per Log_Msg object.  Moreover,
 *     <ACE_Log_Msg_Callbacks> are not inherited when a new thread
 *     is spawned, so you'll need to reset these in each new thread.
 */
class ACE_Export ACE_Log_Msg_Callback
{
  // = TITLE
  //     
  //
  // = DESCRIPTION
public:
  /// No-op virtual destructor.
  virtual ~ACE_Log_Msg_Callback (void);

  /// Callback routine.  This is called when we want to log a message.
  /// Since this routine is pure virtual, it must be overwritten by the
  /// subclass.
  virtual void log (ACE_Log_Record &log_record) = 0;
};

#include "ace/post.h"
#endif /* ACE_LOG_MSG_CALLBACK_H */
