// -*- C++ -*-
// $Id$

#ifndef CIAO_RECEIVER_EXEC_H_
#define CIAO_RECEIVER_EXEC_H_

#include "ReadGet_Test_ReceiverEC.h"

#include /**/ "Receiver_exec_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"

namespace CIAO_ReadGet_Test_Receiver_Impl
{
  class Receiver_exec_i;

  //============================================================
  // read_action_Generator
  //============================================================
  class read_action_Generator
    : public ACE_Event_Handler
  {
  public:
    read_action_Generator (Receiver_exec_i &callback,
                           int run);

    ~read_action_Generator ();

    virtual int handle_timeout (const ACE_Time_Value &tv, const void *arg);
  private:
    Receiver_exec_i &callback_;
    int run_;

  };

  //============================================================
  // Starter_exec_i
  //============================================================
  class Starter_exec_i
    : public virtual ::CCM_ReadGetStarter,
      public virtual ::CORBA::LocalObject
  {
  public:
    Starter_exec_i (Receiver_exec_i & callback);
    virtual ~Starter_exec_i (void);

    virtual void set_reader_properties (CORBA::UShort nr_keys,
                  CORBA::UShort nr_iterations);
    virtual void start_read (CORBA::UShort run);

  private:
    Receiver_exec_i &callback_;
  };

  //============================================================
  // Receiver_exec_i
  //============================================================
  class RECEIVER_EXEC_Export Receiver_exec_i
    : public virtual Receiver_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Receiver_exec_i (void);
    virtual ~Receiver_exec_i (void);

    // Supported operations and attributes.
    ::CORBA::Boolean run_tests (void);

    void run_tests (::CORBA::Boolean run_tests);
    // Component attributes.

    // Port operations.
    virtual ::CCM_ReadGetStarter_ptr get_reader_start ();

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr get_get_port_status (void);

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr get_read_port_status(void);

    bool check_last ();
    void start_read (CORBA::UShort run);
    void run (CORBA::UShort run);

    ::CORBA::UShort iterations (void);
    void iterations (::CORBA::UShort iterations);

    ::CORBA::UShort keys (void);
    void keys (::CORBA::UShort keys);

    // Operations from Components::SessionComponent.
    virtual void
    set_session_context ( ::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);

  private:
    ::ReadGet_Test::CCM_Receiver_Context_var context_;
    ::ReadGet_Test::QueryConditionTestConnector::Reader_var read_reader_;
    ::ReadGet_Test::QueryConditionTestConnector::Reader_var get_reader_;
    ::ReadGet_Test::QueryConditionTestConnector::Getter_var get_getter_;
    ::CCM_DDS::ContentFilterSetting_var get_filter_setting_;
    ::CCM_DDS::ContentFilterSetting_var read_filter_setting_;

    ReadGetRestarter_var restarter_;
    CORBA::UShort   iterations_;
    CORBA::UShort   keys_;
    bool            has_run_;
    bool            run_tests_;

    int current_iter_value1_;
    int current_iter_value2_;

    read_action_Generator *ticker_;

    void test_all (void);
    void read_all_on_getter_port (void);
    void get_all_on_getter_port (void);
    void read_all_on_reader_port (void);
    void check_iter_on_getter_port (const QueryConditionTest & sample,
                                    const char * test);
    void check_iter_on_reader_port (const QueryConditionTest & sample);

    void check_filter (void);
    void check_filter (bool check_reader);
    void test_set_query_parameters (void);
  };

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_ReadGet_Test_Receiver_Impl (void);
}

#endif /* ifndef */

