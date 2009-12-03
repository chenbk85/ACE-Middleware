// -*- C++ -*-
//
// $Id$

#include "Keyed_Test_Receiver_exec.h"
#include "ciao/Logger/Log_Macros.h"
#include "tao/ORB_Core.h"
#include "ace/OS_NS_time.h"

namespace CIAO_Keyed_Test_Receiver_Impl
{
  read_action_Generator::read_action_Generator (Receiver_exec_i &callback)
    : pulse_callback_ (callback)
  {
  }

  read_action_Generator::~read_action_Generator ()
  {
  }

  int
  read_action_Generator::handle_timeout (const ACE_Time_Value &, const void *)
  {
    this->pulse_callback_.read ();
    return 0;
  }

  //============================================================
  // Component Executor Implementation Class: Receiver_exec_iKeyedTest_Listener_exec_i ();
  //============================================================

  Receiver_exec_i::Receiver_exec_i (void)
    : rate_ (1),
      iterations_ (10),
      keys_ (5),
      expected_ (50)
  {
    this->ticker_ = new read_action_Generator (*this);
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
  }

  void
  Receiver_exec_i::check_received_samples ()
  {
    bool all_received = true;
    for (Last_Iteration_Table::iterator iter = this->last_iters_.begin ();
         iter != this->last_iters_.end () && all_received;
         ++iter)
      {
        all_received = iter->second == this->iterations_;
      }
    if (all_received)
      {
        CIAO_DEBUG ((LM_DEBUG, ACE_TEXT ("All samples received. Stop the timer\n")));
        this->context_->get_CCM_object()->_get_orb ()->orb_core ()->reactor ()->cancel_timer (this->ticker_);
      }
  }
  // Supported operations and attributes.
  void
  Receiver_exec_i::read (void)
  {
    if (CORBA::is_nil (this->reader_.in ()))
      {
        return;
      }
    try
      {
        for (CORBA::UShort i = 1; i < this->keys_ + 1; ++i)
          {
            KeyedTest keyedtest_info;
            char key[100];
            ACE_OS::sprintf (key, "KEY_%d", i);
            keyedtest_info.key = CORBA::string_dup (key);
            ::CCM_DDS::ReadInfo readinfo;
            this->reader_->read_one_last (keyedtest_info, readinfo, ::DDS::HANDLE_NIL);
            time_t tim = readinfo.source_timestamp.sec;
            tm* time = ACE_OS::localtime(&tim);
            CIAO_DEBUG ((LM_DEBUG, ACE_TEXT ("READ_ONE Read_Info ")
                      ACE_TEXT (" -> date = %02d:%02d:%02d.%d\n"),
                                time ? time->tm_hour : 0,
                                time ? time->tm_min : 0,
                                time ? time->tm_sec : 0,
                                readinfo.source_timestamp.nanosec));
            CIAO_DEBUG ((LM_DEBUG, ACE_TEXT ("READ ONE keyed test info : ")
                ACE_TEXT ("received keyedtest_info for <%C> at %u\n"),
                keyedtest_info.key.in (),
                keyedtest_info.iteration));
            this->last_iters_[key] = keyedtest_info.iteration;
            check_received_samples ();
          }
      }
    catch(CCM_DDS::InternalError& )
      {
        CIAO_ERROR ((LM_ERROR, ACE_TEXT ("ERROR: KeyedTest_Read: ")
                  ACE_TEXT ("Unexpected NonExistent exception received\n")));
      }
    catch(CCM_DDS::NonExistent& )
      {
        //due to timing issues, this exception may occur
        CIAO_DEBUG ((LM_DEBUG, ACE_TEXT ("KeyedTest_Read: ")
                  ACE_TEXT ("Expected NonExistent received\n")));
      }
  }

  // Component attributes.
  ::CORBA::ULong
  Receiver_exec_i::rate (void)
  {
    return this->rate_;
  }

  void
  Receiver_exec_i::rate (
    ::CORBA::ULong rate)
  {
    this->rate_ = rate;
  }

  ::CORBA::UShort
  Receiver_exec_i::iterations (void)
  {
    return this->iterations_;
  }

  void
  Receiver_exec_i::iterations (::CORBA::UShort iterations)
  {
    this->iterations_ = iterations;
    this->expected_ = this->iterations_ * this->keys_;
  }

  ::CORBA::UShort
  Receiver_exec_i::keys (void)
  {
    return this->keys_;
  }

  void
  Receiver_exec_i::keys (::CORBA::UShort keys)
  {
    this->keys_ = keys;
    this->expected_ = this->iterations_ * this->keys_;
  }

  // Port operations.
  ::CCM_DDS::KeyedTest::CCM_Listener_ptr
  Receiver_exec_i::get_info_out_data_listener (void)
  {
    return 0;
  }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_out_status (void)
  {
    return 0;
  }

  // Operations from Components::SessionComponent.
  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::Keyed_Test::CCM_Receiver_Context::_narrow (ctx);
    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Receiver_exec_i::configuration_complete (void)
  {
    this->reader_ = this->context_->get_connection_info_out_data();
  }

  void
  Receiver_exec_i::ccm_activate (void)
  {
    // calculate the interval time
    long usec = 1000000 / this->rate_;
    if (this->context_->get_CCM_object()->_get_orb ()->orb_core ()->reactor ()->schedule_timer (
                                          this->ticker_,
                                          0,
                                          ACE_Time_Value(0, usec),
                                          ACE_Time_Value(0, usec)) == -1)
      {
        CIAO_ERROR ((LM_ERROR, "Unable to schedule Timer\n"));
      }
  }

  void
  Receiver_exec_i::ccm_passivate (void)
  {
    this->context_->get_CCM_object()->_get_orb ()->orb_core ()->reactor ()->cancel_timer (this->ticker_);
    delete this->ticker_;
  }

  void
  Receiver_exec_i::ccm_remove (void)
  {
    CORBA::UShort received_ = 0;
    for (Last_Iteration_Table::iterator iter = this->last_iters_.begin ();
         iter != this->last_iters_.end ();
         ++iter)
      {
        CIAO_DEBUG ((LM_INFO, "Receiver_exec_i summary for <%C>: last sample <%u> - expected <%u>\n",
                      iter->first.c_str(),
                      iter->second,
                      this->iterations_));
        received_ += iter->second;
      }

    if (received_ < this->expected_)
      {
        CIAO_ERROR ((LM_ERROR, "ERROR : Expected to receive %u samples, actually got %u\n",
            this->expected_, received_));
      }
  }

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Keyed_Test_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);

    return retval;
  }
}

