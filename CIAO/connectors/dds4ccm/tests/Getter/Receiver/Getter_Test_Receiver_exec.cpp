// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.3
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

#include "Getter_Test_Receiver_exec.h"
#include "tao/ORB_Core.h"
#include "ace/Reactor.h"
#include "ace/OS_NS_sys_time.h"
#include "dds4ccm/impl/dds4ccm_conf.h"

namespace CIAO_Getter_Test_Receiver_Impl
{

  /**
   * Facet Executor Implementation Class: info_get_status_exec_i
   */

  info_get_status_exec_i::info_get_status_exec_i (
        ::Getter_Test::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::Getter_Test::CCM_Receiver_Context::_duplicate (ctx))
  {
  }

  info_get_status_exec_i::~info_get_status_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::PortStatusListener

  void
  info_get_status_exec_i::on_requested_deadline_missed (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::RequestedDeadlineMissedStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_get_status_exec_i::on_sample_lost (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::SampleLostStatus & /* status */)
  {
    /* Your code here. */
  }

  /**
   * Facet Executor Implementation Class: info_fixed_status_exec_i
   */

  info_fixed_status_exec_i::info_fixed_status_exec_i (
        ::Getter_Test::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::Getter_Test::CCM_Receiver_Context::_duplicate (ctx))
  {
  }

  info_fixed_status_exec_i::~info_fixed_status_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::PortStatusListener

  void
  info_fixed_status_exec_i::on_requested_deadline_missed (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::RequestedDeadlineMissedStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_fixed_status_exec_i::on_sample_lost (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::SampleLostStatus & /* status */)
  {
    /* Your code here. */
  }

  /**
   * Facet Executor Implementation Class: getter_invoke_exec_i
   */

  getter_invoke_exec_i::getter_invoke_exec_i (
        ::Getter_Test::CCM_Receiver_Context_ptr ctx,
        Receiver_exec_i & callback)
    : ciao_context_ (
        ::Getter_Test::CCM_Receiver_Context::_duplicate (ctx))
      , callback_ (callback)
  {
  }

  getter_invoke_exec_i::~getter_invoke_exec_i (void)
  {
  }

  // Operations from ::GetInvoker

  void
  getter_invoke_exec_i::start_timeout_get_one (void)
  {
    this->callback_.timeout_get_one ();
  }

  void
  getter_invoke_exec_i::start_timeout_get_many (void)
  {
    this->callback_.timeout_get_many ();
  }

  void
  getter_invoke_exec_i::start_get_one (const char * key,
  ::CORBA::Long fixed_key,
  ::CORBA::Long iteration)
  {
    this->callback_.start_get_one (key, fixed_key, iteration);
  }

  void
  getter_invoke_exec_i::start_get_many (::CORBA::Short keys,
  ::CORBA::Long iterations)
  {
    this->callback_.start_get_many (keys, iterations);
  }

  /**
   * GetOneHandler
   */
  GetOneHandler::GetOneHandler (Receiver_exec_i &callback,
                                const char * key,
                                CORBA::Long fixed_key,
                                CORBA::Long iteration)
    : callback_ (callback)
      , key_ (CORBA::string_dup (key))
      , fixed_key_ (fixed_key)
      , iteration_ (iteration)
  {
    this->reference_counting_policy ().value (
      ACE_Event_Handler::Reference_Counting_Policy::ENABLED);

  }

  GetOneHandler::~GetOneHandler (void)
  {
  }

  int
  GetOneHandler::handle_exception (ACE_HANDLE)
  {
    this->callback_.get_one (this->key_.in (), this->fixed_key_, this->iteration_);
    return 0;
  }

  /**
   * GetManyHandler
   */
  GetManyHandler::GetManyHandler (Receiver_exec_i &callback,
                                  CORBA::UShort keys,
                                  CORBA::Long iterations)
    : callback_ (callback),
      keys_ (keys),
      iterations_ (iterations)
  {
    this->reference_counting_policy ().value (
      ACE_Event_Handler::Reference_Counting_Policy::ENABLED);
  }

  GetManyHandler::~GetManyHandler (void)
  {
  }

  int
  GetManyHandler::handle_exception (ACE_HANDLE)
  {
    this->callback_.get_many (this->keys_, this->iterations_);
    return 0;
  }

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  Receiver_exec_i::Receiver_exec_i (void){
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
  }

  // Supported operations and attributes.
  ACE_Reactor*
  Receiver_exec_i::reactor (void)
  {
    ACE_Reactor* reactor = 0;
    ::CORBA::Object_var ccm_object =
      this->ciao_context_->get_CCM_object();
    if (! ::CORBA::is_nil (ccm_object.in ()))
      {
        ::CORBA::ORB_var orb = ccm_object->_get_orb ();
        if (! ::CORBA::is_nil (orb.in ()))
          {
            reactor = orb->orb_core ()->reactor ();
          }
      }
    if (reactor == 0)
      {
        throw ::CORBA::INTERNAL ();
      }
    return reactor;
  }

  void
  Receiver_exec_i::start_get_one (const char * key,
                                  CORBA::Long fixed_key,
                                  CORBA::Long iteration)
  {
    GetOneHandler* rh = new GetOneHandler (*this,
                                           key,
                                           fixed_key,
                                           iteration);
    ACE_Event_Handler_var safe_event_handler (rh);
    this->reactor ()->notify (rh);
  }

  void
  Receiver_exec_i::start_get_many (CORBA::Short keys,
                         CORBA::Long iterations)
  {
    GetManyHandler* rh = new  GetManyHandler (*this, keys, iterations);
    ACE_Event_Handler_var safe_event_handler (rh);
    this->reactor ()->notify (rh);
 }

  void
  Receiver_exec_i::get_many (CORBA::Short keys , CORBA::Long iterations)
  {
    // this is very hard to test in a controlled environment.
    // When data arrives in DDS, the waiting ends and the
    // Getter starts to read the data. In this test we expected
    // therefor more then one, and less then but not exactly max_delivered_data.
    // On the other hand, when the user want to have all the
    // samples in DDS, one shouldn't use the wait method.
    // Since the spec is not clear about this, the test will
    // pass when at least one sample is returned.
     ::Getter_Test::GetterTestConnector::Getter_var getter =
      this->ciao_context_->get_connection_info_get_fresh_data ();

    DDS::Duration_t to;
    to.sec = 20;
    to.nanosec = 0;
    getter->time_out (to);
    getter->max_delivered_data (40);
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::get_many: "
                          "Start getting data from DDS: "
                          "#keys <%d> - #iterations <%d> with timeout: "
                          "sec <%d> - nanosec <%u>\n",
                          keys, iterations,
                          getter->time_out ().sec,
                          getter->time_out ().nanosec));

    GetterTestSeq gettertest_seq;
    ::CCM_DDS::ReadInfoSeq readinfo;
    bool const result = getter->get_many (gettertest_seq, readinfo);
    if (result)
      {
        if (gettertest_seq.length () == 0)
          {
            ACE_ERROR ((LM_ERROR, "Receiver_exec_i::get_many: "
                                  "No data returned. "
                                  "number of samples: "
                                  "expected at least one - received <0>\n"));
          }
        if (gettertest_seq.length () == 1)
          {
            ACE_ERROR ((LM_ERROR, "Receiver_exec_i::get_many: "
                                  "Not enough data returned. "
                                  "number of samples: "
                                  "expected at least two - received <1>\n"));
          }
        if (gettertest_seq.length () > 40)
          {
            ACE_ERROR ((LM_ERROR, "Receiver_exec_i::get_many: "
                                  "To much data returned. "
                                  "number of samples: "
                                  "expected not more then 40 - received <1>\n"));
           }
        for (CORBA::ULong i = 0; i < gettertest_seq.length (); ++i)
          {
            ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::get_many: "
                                  "Returned data : key <%C> - iteration <%d>\n",
                                  gettertest_seq[i].key.in (),
                                  gettertest_seq[i].iteration));
          }
      }
    else
      {
        ACE_ERROR ((LM_ERROR, "ERROR: GET MANY: "
                              "Time out occurred\n"));
      }
    // Wait a while before reading.
    ACE_Time_Value tv (3, 0);
    ACE_OS::sleep (tv);
    this->read_many (keys, iterations, gettertest_seq);
  }

  void
  Receiver_exec_i::read_many (CORBA::Short keys ,
                              CORBA::Long iterations,
                              const GetterTestSeq& gettertest_seq)
  {


    ::Getter_Test::GetterTestConnector::Reader_var reader =
      this->ciao_context_->get_connection_info_get_data ();

    GetterTestSeq read_seq;
    ::CCM_DDS::ReadInfoSeq readinfos;
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::read_many - "
                "Start checking samples in DDS\n"));
    reader->read_all (read_seq, readinfos);
    // we expect all samples written during the test for get one (KEY_1)
    // AND all samples written during the test for get many (number of keys)
    ::CORBA::ULong expected =
      static_cast < ::CORBA::ULong > (iterations * (keys + 1));
    if (read_seq.length () != expected)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Receiver_exec_i::read_many - "
                              "Unexpected number of samples received: "
                              "expected <%d> - received <%u>\n",
                              expected, read_seq.length ()));
      }
    for (::CORBA::ULong i = 0; i < read_seq.length (); ++i)
      {
        ACE_DEBUG ((LM_DEBUG, "READ ALL : Receiver_exec_i::read_many - "
                              "Sample received: key <%C> - iteration <%d> - "
                              "sample_read_state <%d>\n",
                              read_seq[i].key.in (),
                              read_seq[i].iteration,
                              readinfos[i].access_status));
      }

    for (::CORBA::Short key = 0; key < keys; ++key)
      {
        ::CORBA::Long iter = 0;
        char str_key[8];
        ACE_OS::sprintf (str_key, "KEY_%d", key + 1);
        for (::CORBA::ULong i = 0; i < read_seq.length (); ++i)
          {
            if (ACE_OS::strcmp (read_seq[i].key.in (), str_key) == 0)
              ++iter;
            if (iter > iterations)
              ACE_ERROR ((LM_ERROR, "ERROR: Receiver_exec_i::read_many - "
                          "Unexpected number of iterations received "
                          "for key <%C>: <%d>\n",
                          str_key,
                          iter));
          }
      }
    // check which sample states should be ALREADY_SEEN/FRESH_INFO
    for (::CORBA::ULong readed = 0; readed < read_seq.length (); ++readed)
      {
        ::CCM_DDS::AccessStatus received_access_status =
          readinfos[readed].access_status;
        bool found = false;

        for (::CORBA::ULong got = 0;
             got < gettertest_seq.length () && !found;
             ++got)
          {
            if (ACE_OS::strcmp (read_seq[readed].key.in (),
                                gettertest_seq[got].key.in ()) == 0 &&
                read_seq[readed].iteration == gettertest_seq[got].iteration)
              {
                found = true;
                if (received_access_status != ::CCM_DDS::ALREADY_SEEN)
                  {
                    ACE_ERROR ((LM_ERROR, "ERROR: Receiver_exec_i::read_many - "
                                "Unexpected access state received: "
                                "expected <%d> - received <%d>\n",
                                ::CCM_DDS::ALREADY_SEEN,
                                received_access_status));
                  }
              }
          }
        // Samples which are not read by get_many or get_one (the samples belonging to
        // KEY_1), should have FRESH_INFO as access status.
        if (!found && ACE_OS::strcmp (read_seq[readed].key.in (), "KEY_1") != 0)
          {
            if (received_access_status != ::CCM_DDS::FRESH_INFO)
              {
                ACE_ERROR ((LM_ERROR, "ERROR: Receiver_exec_i::read_many - "
                            "Unexpected access state received for sample "
                            "<%C>:<%d> : "
                            "expected <%d> - received <%d>\n",
                            read_seq[readed].key.in (),
                            read_seq[readed].iteration,
                            ::CCM_DDS::FRESH_INFO,
                            received_access_status));
              }
          }
      }
  }


  void
  Receiver_exec_i::get_one_fixed (CORBA::Long fixed_key, CORBA::Long iteration)
  {
    ::Getter_Test::GetterFixedConnector::Getter_var fixed =
      this->ciao_context_->get_connection_info_fixed_fresh_data ();

    DDS::Duration_t to;
    to.sec = 5;
    to.nanosec = 0;
    fixed->time_out (to);
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::get_one_fixed: "
                          "Start getting data from DDS: "
                          "key <%u> - iteration <%d> "
                          " with timeout: "
                          "sec <%u> - nanosec <%u>\n",
                          fixed_key, iteration,
                          fixed->time_out ().sec,
                          fixed->time_out ().nanosec));
    GetterFixed gettertest_info;
    ::CCM_DDS::ReadInfo readinfo;
    ACE_Time_Value const tv = ACE_OS::gettimeofday ();
    CORBA::Boolean const result = fixed->get_one (gettertest_info, readinfo);
    if (result)
      {
        ACE_Time_Value dur = ACE_OS::gettimeofday () - tv;
        ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::get_one_fixed: "
                               "get_one took <%#T>\n",
                               &dur));
        if (gettertest_info.key != fixed_key)
          {
            ACE_ERROR ((LM_ERROR, "ERROR FIXED: GET ONE: "
                                  "Expected key does "
                                  "not match received key: "
                                  "expected <%u> - received <%C>\n",
                                  fixed_key,
                                  gettertest_info.key));
          }
        if (gettertest_info.iteration != iteration)
          {
            ACE_ERROR ((LM_ERROR, "ERROR FIXED: GET ONE: "
                                  "Expected iteration does "
                                  "not match received iteration: "
                                  "expected <%d> - received <%d>\n",
                                  iteration,
                                  gettertest_info.iteration));
          }
        // check readinfo struct.
        if (DDS_INSTANCE_HANDLE_VALID(readinfo.instance_handle))
          {
            ACE_ERROR ((LM_ERROR, ACE_TEXT ("ERROR FIXED: GET MANY: ")
                    ACE_TEXT ("received instance handle should be invalid ")
                    ACE_TEXT ("for unkeyed data: ")
                    ACE_TEXT ("key <%u> - iteration <%u>\n"),
                    gettertest_info.key,
                    gettertest_info.iteration));
          }
        if (readinfo.source_timestamp.sec == 0 &&
            readinfo.source_timestamp.nanosec == 0)
          {
            ACE_ERROR ((LM_ERROR, "ERROR FIXED: READ ONE LAST: "
                                "source timestamp seems to be invalid (nil) "
                                "key <%u> - iteration <%d>\n",
                                gettertest_info.key,
                                gettertest_info.iteration));
          }
        ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::get_one_fixed: "
                              "Returned data : key <%u> - iteration <%d>\n",
                              gettertest_info.key,
                              gettertest_info.iteration));
      }
    else
      {
        ACE_ERROR ((LM_ERROR, "ERROR FIXED: GET ONE: "
                              "Time out while waiting for "
                              "key <%u> - iteration <%d>\n",
                              fixed_key,
                              iteration));
      }
  }

  void
  Receiver_exec_i::get_one_variable (const char * key, CORBA::Long iteration)
  {
    ::Getter_Test::GetterTestConnector::Getter_var getter =
      this->ciao_context_->get_connection_info_get_fresh_data ();

    DDS::Duration_t to;
    to.sec = 5;
    to.nanosec = 0;
    getter->time_out (to);
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::get_one_variable: "
                          "Start getting data from DDS: "
                          "key <%C> - iteration <%d> "
                          " with timeout: "
                          "sec <%d> - nanosec <%u>\n",
                          key, iteration,
                          getter->time_out ().sec,
                          getter->time_out ().nanosec));
    GetterTest_var gettertest_info;
    ::CCM_DDS::ReadInfo readinfo;
    ACE_Time_Value tv = ACE_OS::gettimeofday ();
    CORBA::Boolean const result = getter->get_one (gettertest_info.out (), readinfo);
    if (result)
      {
        ACE_Time_Value dur = ACE_OS::gettimeofday () - tv;
        ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::get_one_variable: "
                               "get_one took <%#T>\n",
                               &dur));
        if (ACE_OS::strcmp (gettertest_info->key, key) != 0)
          {
            ACE_ERROR ((LM_ERROR, "ERROR VARIABLE: GET ONE: "
                                  "Expected key does "
                                  "not match received key: "
                                  "expected <%C> - received <%C>\n",
                                  key,
                                  gettertest_info->key.in ()));
          }
        if (gettertest_info->iteration != iteration)
          {
            ACE_ERROR ((LM_ERROR, "ERROR VARIABLE: GET ONE: "
                                  "Expected iteration does "
                                  "not match received iteration: "
                                  "expected <%d> - received <%d>\n",
                                  iteration,
                                  gettertest_info->iteration));
          }
        // check readinfo struct.
        if (DDS_INSTANCE_HANDLE_VALID(readinfo.instance_handle))
          {
            ACE_ERROR ((LM_ERROR, ACE_TEXT ("ERROR VARIABLE: GET MANY: ")
                    ACE_TEXT ("received instance handle should be invalid ")
                    ACE_TEXT ("for unkeyed data: ")
                    ACE_TEXT ("key <%C> - iteration <%u>\n"),
                    gettertest_info->key.in (),
                    gettertest_info->iteration));
          }
        if (readinfo.source_timestamp.sec == 0 &&
            readinfo.source_timestamp.nanosec == 0)
          {
            ACE_ERROR ((LM_ERROR, "ERROR VARIABLE: READ ONE LAST: "
                                "source timestamp seems to be invalid (nil) "
                                "key <%C> - iteration <%d>\n",
                                gettertest_info->key.in (),
                                gettertest_info->iteration));
          }
        ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::get_one_variable: "
                              "Returned data : key <%C> - iteration <%d>\n",
                              gettertest_info->key.in (),
                              gettertest_info->iteration));
      }
    else
      {
        ACE_ERROR ((LM_ERROR, "ERROR VARIABLE: GET ONE: "
                              "Time out while waiting for "
                              "key <%C> - iteration <%d>\n",
                              key,
                              iteration));
      }
  }

  void
  Receiver_exec_i::get_one (const char * key,
                            CORBA::Long fixed_key,
                            CORBA::Long iteration)
  {
    this->get_one_variable (key, iteration);
    this->get_one_fixed (fixed_key, iteration);
  }

  void
  Receiver_exec_i::timeout_get_one_fixed (void)
  {
    try
      {
        ::Getter_Test::GetterFixedConnector::Getter_var fixed =
          this->ciao_context_->get_connection_info_fixed_fresh_data ();

        DDS::Duration_t to;
        to.sec = 1;
        to.nanosec = 0;
        fixed->time_out (to);
        ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::timeout_get_one_fixed: "
                              "Start getting data from DDS: timeout: "
                              "sec <%d> - nanosec <%u>\n",
                              fixed->time_out ().sec,
                              fixed->time_out ().nanosec));
        GetterFixed gettertest_info;
        ::CCM_DDS::ReadInfo readinfo;
        CORBA::Boolean const result = fixed->get_one (gettertest_info, readinfo);
        if (result)
          {
            ACE_ERROR ((LM_ERROR, "ERROR FIXED: TIMEOUT GET ONE: "
                                  "Returning true when get no data.\n"));
          }
        else
          {
            ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::timeout_get_one_fixed: "
                                  "Expected to return no data.\n"));
          }
      }
    catch (const CCM_DDS::InternalError& )
      {
        ACE_ERROR ((LM_ERROR, "ERROR FIXED: TIMEOUT GET ONE: "
                               "Caught unexcepted InternalError "
                               "exception\n"));
      }
    catch (const ::CORBA::Exception& ex)
      {
        ex._tao_print_exception ("ERROR FIXED: TIMEOUT GET ONE:");
        ACE_ERROR ((LM_ERROR,
                "ERROR: Receiver_exec_i::timeout_get_one_fixed : Exception caught\n"));
      }
  }

  void
  Receiver_exec_i::timeout_get_one_variable (void)
  {
    try
      {
        ::Getter_Test::GetterTestConnector::Getter_var getter =
          this->ciao_context_->get_connection_info_get_fresh_data ();

        DDS::Duration_t to;
        to.sec = 1;
        to.nanosec = 0;
        getter->time_out (to);
        ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::timeout_get_one_variable: "
                              "Start getting data from DDS: timeout: "
                              "sec <%d> - nanosec <%u>\n",
                              getter->time_out ().sec,
                              getter->time_out ().nanosec));
        GetterTest_var gettertest_info;;
        ::CCM_DDS::ReadInfo readinfo;
        CORBA::Boolean result = getter->get_one (gettertest_info.out (), readinfo);
        if (result)
          {
            ACE_ERROR ((LM_ERROR, "ERROR VARIABLE: TIMEOUT GET ONE: "
                                  "Returning true when get no data.\n"));
          }
        else
          {
            ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::timeout_get_one_variable: "
                                  "Expected to return no data.\n"));
          }
      }
    catch (const CCM_DDS::InternalError& )
      {
        ACE_ERROR ((LM_ERROR, "ERROR VARIABLE: TIMEOUT GET ONE: "
                               "Caught unexcepted InternalError "
                               "exception\n"));
      }
    catch (const ::CORBA::Exception& ex)
      {
        ex._tao_print_exception ("ERROR VARIABLE: TIMEOUT GET ONE:");
        ACE_ERROR ((LM_ERROR,
                "ERROR: Receiver_exec_i::timeout_get_one_variable : Exception caught\n"));
      }
  }

  void
  Receiver_exec_i::timeout_get_one (void)
  {
    this->timeout_get_one_variable ();
    this->timeout_get_one_fixed ();
  }

  void
  Receiver_exec_i::timeout_get_many (void)
  {
    try
      {
        ::Getter_Test::GetterTestConnector::Getter_var getter =
          this->ciao_context_->get_connection_info_get_fresh_data ();

        DDS::Duration_t to;
        to.sec = 3;
        to.nanosec = 0;
        getter->time_out (to);
        ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::timeout_get_many: "
                              "Start getting data from DDS: timeout: "
                              "sec <%d> - nanosec <%u>\n",
                              getter->time_out ().sec,
                              getter->time_out ().nanosec));
        GetterTestSeq gettertest_seq;
        ::CCM_DDS::ReadInfoSeq readinfo;
        CORBA::Boolean const result = getter->get_many (gettertest_seq, readinfo);
        if (result)
          {
            ACE_ERROR ((LM_ERROR, "ERROR: TIMEOUT GET MANY: "
                                  "Returning true when get no data.\n"));
          }
        else
          {
            ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::timeout_get_many: "
                                  "Expected to return no data.\n"));
          }
      }
    catch (const CCM_DDS::InternalError&)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: TIMEOUT GET MANY: "
                               "Caught unexcepted InternalError "
                               "exception\n"));
      }
    catch (const ::CORBA::Exception& ex)
      {
        ex._tao_print_exception ("ERROR: TIMEOUT GET MANY:");
        ACE_ERROR ((LM_ERROR,
                      "ERROR: Receiver_exec_i::timeout_get_many : Exception caught\n"));
      }
  }

  // Component attributes and port operations.

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_get_status (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_get_status_.in ()))
      {
        info_get_status_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_get_status_exec_i (
            this->ciao_context_.in ()),
            ::CCM_DDS::CCM_PortStatusListener::_nil ());

          this->ciao_info_get_status_ = tmp;
      }

    return
      ::CCM_DDS::CCM_PortStatusListener::_duplicate (
        this->ciao_info_get_status_.in ());
  }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_fixed_status (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_fixed_status_.in ()))
      {
        info_fixed_status_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_fixed_status_exec_i (
            this->ciao_context_.in ()),
            ::CCM_DDS::CCM_PortStatusListener::_nil ());

          this->ciao_info_fixed_status_ = tmp;
      }

    return
      ::CCM_DDS::CCM_PortStatusListener::_duplicate (
        this->ciao_info_fixed_status_.in ());
  }

  ::CCM_GetInvoker_ptr
  Receiver_exec_i::get_getter_invoke (void)
  {
    if ( ::CORBA::is_nil (this->ciao_getter_invoke_.in ()))
      {
        getter_invoke_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          getter_invoke_exec_i (
            this->ciao_context_.in (),
            *this),
            ::CCM_GetInvoker::_nil ());

          this->ciao_getter_invoke_ = tmp;
      }

    return
      ::CCM_GetInvoker::_duplicate (
        this->ciao_getter_invoke_.in ());
  }

  // Operations from Components::SessionComponent.

  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::Getter_Test::CCM_Receiver_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Receiver_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Getter_Test_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);

    return retval;
  }
}
