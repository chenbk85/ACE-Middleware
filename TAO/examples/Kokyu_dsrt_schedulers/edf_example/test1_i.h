//$Id$

// ============================================================================
//
// = LIBRARY
//   TAO/tests/MT_Server
//
// = FILENAME
//   test1_i.h
//
// = AUTHOR
//   Carlos O'Ryan
//
// ============================================================================

#ifndef TAO_MT_SERVER_TEST_I_H
#define TAO_MT_SERVER_TEST_I_H

#include "test1S.h"
#include "tao/RTScheduling/RTScheduler_Manager.h"
#include "Task_Stats.h"

class Simple_Server1_i : public POA_Simple_Server1
{
  // = TITLE
  //   Simpler Server implementation
  //
  // = DESCRIPTION
  //   Implements the Simple_Server1 interface in test1.idl
  //
public:
  Simple_Server1_i (CORBA::ORB_ptr orb,
                   RTScheduling::Current_ptr current,
                   Task_Stats&,
                   int);
  // ctor

  // = The Simple_Server1 methods.
  void test_method (CORBA::Long x, CORBA::Long y ACE_ENV_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException));

  void shutdown (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException));

private:
  CORBA::ORB_var orb_;
  RTScheduling::Current_var current_;
  Task_Stats& task_stats_;
  int enable_yield_;
  // The ORB
};


#if defined(__ACE_INLINE__)
#include "test1_i.i"
#endif /* __ACE_INLINE__ */

#endif /* TAO_MT_SERVER_TEST_I_H */
