//
// $Id$
//

#ifndef COLLOCATED_TEST_CLIENT_TASK_H
#define COLLOCATED_TEST_CLIENT_TASK_H
#include /**/ "ace/pre.h"
#include "ace/Task.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/ORB.h"
#include "orbsvcs/CosNamingC.h"

/// Implement a Task to run the client as a thread
class Client_Task : public ACE_Task_Base
{
public:

  /// Constructor
  Client_Task (CosNaming::NamingContext_ptr root_context,
               CORBA::ORB_ptr corb,
               ACE_Thread_Manager *thr_mgr,
               CORBA::Boolean result);

  /// Thread entry point
  int svc (void);

private:
  CosNaming::NamingContext_var root_context_;

  CORBA::ORB_var corb_;

  // Boolean to indicate whether the invocation should work or not.
  CORBA::Boolean result_;
};

#include /**/ "ace/post.h"
#endif /* COLLOCATED_TEST_CLIENT_TASK_H */
