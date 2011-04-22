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

#include "SL_OneByOne_Sender_exec.h"
#include "tao/ORB_Core.h"
#include "ace/Reactor.h"

namespace CIAO_SL_OneByOne_Sender_Impl
{

  /**
   * Write action generator
   */

  pulse_Generator::pulse_Generator (Sender_exec_i &callback)
    : pulse_callback_ (callback)
  {
  }

  int
  pulse_Generator::handle_timeout (const ACE_Time_Value &, const void *)
  {
    // Notify the subscribers
    this->pulse_callback_.tick ();
    return 0;
  }

  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  Sender_exec_i::Sender_exec_i (void)
    : test_nr_(UPDATE_CREATE),
      test_ok_(true)
  {
    ACE_NEW_THROW_EX (this->ticker_,
                      pulse_Generator (*this),
                      ::CORBA::NO_MEMORY ());
  }

  Sender_exec_i::~Sender_exec_i (void)
  {
    delete this->ticker_;
  }

  // Supported operations and attributes.
  ACE_Reactor*
  Sender_exec_i::reactor (void)
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

  CORBA::Boolean
  Sender_exec_i::create_one (void)
  {
    TestTopic i = this->topic_seq_one_[0];
    try
      {
        ::SL_OneByOne::SL_OneByOneConnector::Updater_var updater =
          this->ciao_context_->get_connection_test_topic_update_data ();
        if (::CORBA::is_nil (updater.in ()))
          {
            ACE_ERROR ((LM_ERROR, "Sender_exec_i::create_one - "
                      "ERROR: Updater seems nil\n"));
            return false;
          }
        updater->create_one (i);
        ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("SL_OneByOne: create_one with instance key <%C>\n"),
                   i.key.in ()));
      }
    catch (const CCM_DDS::AlreadyCreated &)
      {
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("Unexpected exception: AlreadyCreated with test updater create_one <%C>.\n"),
                      i.key.in ()));
        return false;
      }
    catch (const CCM_DDS::InternalError& )
      {
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("Internal Error while create_one for <%C>.\n"),
                      i.key.in ()));
        return false;
      }
    return true;
  }

  CORBA::Boolean
  Sender_exec_i::update_one (void)
  {
    //update already created instance with handle nil
    TestTopic i = this->topic_seq_one_[0];
    try
      {
        ::SL_OneByOne::SL_OneByOneConnector::Updater_var updater =
          this->ciao_context_->get_connection_test_topic_update_data ();
        if (::CORBA::is_nil (updater.in ()))
          {
            ACE_ERROR ((LM_ERROR, "Sender_exec_i::update_one - "
                      "ERROR: Updater seems nil\n"));
            return false;
          }
        updater->update_one (i, DDS::HANDLE_NIL);
        ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Updater: update_one with already existing instance with DDS::HANDLE_NIL, key <%C>\n"),
                      i.key.in ()));
      }
    catch (const CCM_DDS::NonExistent &)
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Unexpected exception: NonExistent with test updater update_one <%C>.\n"),
                       i.key.in ()));
        return false;
      }
    catch (const CCM_DDS::InternalError& )
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Internal Error while update_one for <%C>.\n"),
                        i.key.in ()));
        return false;
      }
    return true;
  }

  CORBA::Boolean
  Sender_exec_i::delete_one (void)
  {
    //delete registered instance with DDS::HANDLE_NIL
    TestTopic i = this->topic_seq_one_[0];
    try
      {
        ::SL_OneByOne::SL_OneByOneConnector::Updater_var updater =
          this->ciao_context_->get_connection_test_topic_update_data ();
        if (::CORBA::is_nil (updater.in ()))
          {
            ACE_ERROR ((LM_ERROR, "Sender_exec_i::delete_one - "
                      "ERROR: Updater seems nil\n"));
            return false;
          }
        ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Updater: delete_one with registered instance with DDS::HANDLE_NIL, key <%C>\n"),
                      i.key.in ()));
        updater->delete_one (i, DDS::HANDLE_NIL);
      }
    catch (const CCM_DDS::NonExistent &)
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Unexpected exception: NonExistent with test updater delete_one <%C>.\n"),
                       i.key.in ()));
        return false;
      }
    catch (const CCM_DDS::InternalError& )
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Internal Error while delete_one for <%C>.\n"),
                        i.key.in ()));
        return false;
      }
    return true;
  }

  CORBA::Boolean
  Sender_exec_i::create_many (void)
  {
    //create many with no exception
    try
      {
        ::SL_OneByOne::SL_OneByOneConnector::Updater_var updater =
          this->ciao_context_->get_connection_test_topic_update_data ();
        if (::CORBA::is_nil (updater.in ()))
          {
            ACE_ERROR ((LM_ERROR, "Sender_exec_i::create_many - "
                      "ERROR: Updater seems nil\n"));
            return false;
          }
        ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("create_many : <%u> samples\n"),
                         this->topic_seq_many_.length ()));
        updater->create_many (this->topic_seq_many_);
      }
    catch (const CCM_DDS::NonExistent& )
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Unexpected exception: NonExistent with test updater create_many\n")));
        return false;
      }
    catch (const CCM_DDS::InternalError& ex)
      {
         ACE_ERROR ((LM_ERROR, ACE_TEXT ("ERROR: Internal Error ")
                     ACE_TEXT ("in updater: create_many: index <%d> - retval <%d>\n"),
                     ex.index, ex.error_code));
         return false;

      }
    return true;
  }

  CORBA::Boolean
  Sender_exec_i::update_many (void)
  {
    try
      {
        ::SL_OneByOne::SL_OneByOneConnector::Updater_var updater =
          this->ciao_context_->get_connection_test_topic_update_data ();
        if (::CORBA::is_nil (updater.in ()))
          {
            ACE_ERROR ((LM_ERROR, "Sender_exec_i::update_many - "
                      "ERROR: Updater seems nil\n"));
            return false;
          }
        updater->update_many (this->topic_seq_many_);
        ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("update_many : written <%u> samples\n"),
                   this->topic_seq_many_.length ()));
      }
    catch (const CCM_DDS::NonExistent& )
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Unexpected exception: NonExistent with test updater update_many.\n")));
        return false;
      }
    catch (const CCM_DDS::InternalError& ex)
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("ERROR: Internal Error ")
                     ACE_TEXT ("whit update_many: index <%d> - retval <%d>\n"),
                     ex.index, ex.error_code));
        return false;
      }
    return true;
  }

  CORBA::Boolean
  Sender_exec_i::delete_many (void)
  {
    try
      {
        ::SL_OneByOne::SL_OneByOneConnector::Updater_var updater =
          this->ciao_context_->get_connection_test_topic_update_data ();
        if (::CORBA::is_nil (updater.in ()))
          {
            ACE_ERROR ((LM_ERROR, "Sender_exec_i::delete_many - "
                      "ERROR: Updater seems nil\n"));
            return false;
          }
        ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("delete_many : deleted <%u> samples\n"),
                                          this->topic_seq_many_.length ()));
        updater->delete_many (this->topic_seq_many_);
      }
    catch (const CCM_DDS::NonExistent& )
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Unexpected exception: NonExistent with test updater delete_many\n")));
        return false;
      }
    catch (const CCM_DDS::InternalError& ex)
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("ERROR: Internal Error ")
                   ACE_TEXT ("with test updater delete_many: index <%d> - retval <%d>\n"),
                   ex.index, ex.error_code));
        return false;
      }

    return true;
  }

  void
  Sender_exec_i::add_instances_of_topic ()
  {
    CORBA::UShort total = 3;
    this->topic_seq_one_.length (total);
    //sequence for tests with .._one
    for (int i = 1; i < (total + 1); i++)
      {
        char key[7];
        TestTopic new_key;
        ACE_OS::sprintf (key, "KEY_%d", i);
        new_key.key = CORBA::string_dup(key);
        new_key.x = i;
        this->topic_seq_one_[i-1] = new_key;
      }
    //sequence for tests with .._many
    this->topic_seq_many_.length (total);
    for (int i = 1; i < (total + 1); i++)
      {
        char key[7];
        TestTopic new_key;
        ACE_OS::sprintf (key, "many_%d", i);
        new_key.key = CORBA::string_dup(key);
        new_key.x = i;
        this->topic_seq_many_[i-1] = new_key;
      }
  }

  void
  Sender_exec_i::tick ()
  {
    if(this->test_ok_.value())
     {
       switch (this->test_nr_)
         {
          case UPDATE_CREATE:
            this->test_ok_ = this->create_one();
            if(this->test_ok_.value())
              {
                this->test_nr_ = UPDATE_ONE;
              }
            else
              {
                this->test_nr_ = END_TEST;
              }
            break;
          case UPDATE_ONE:
            this->test_ok_ = this->update_one();
            this->test_nr_ = DELETE_ONE;
            break;
          case DELETE_ONE:
            this->test_ok_ = this->delete_one();
            this->test_nr_ = CREATE_MANY;
            break;
          case CREATE_MANY:
            this->test_ok_ = this->create_many();
            if(this->test_ok_.value())
              {
                this->test_nr_ = UPDATE_MANY;
              }
            else
              {
                this->test_nr_ = END_TEST;
              }
            this->test_nr_ = UPDATE_MANY;
            break;
          case UPDATE_MANY:
            this->test_ok_ = this->update_many();
            this->test_nr_ = DELETE_MANY;
            break;
          case DELETE_MANY:
            this->test_ok_ = this->delete_many();
            this->test_nr_ = END_TEST;
            break;
          default:
            break;
        }
    }
  }
  void
  Sender_exec_i::start (void)
  {
    long sec = 1L;
    long const usec = 0L;
    if (this->reactor ()->schedule_timer (
                this->ticker_,
                0,
                ACE_Time_Value (sec, usec),
                ACE_Time_Value (sec, usec)) == -1)
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Sender_exec_i::start : ")
                               ACE_TEXT ("Error scheduling timer")));
      }
  }

  void
  Sender_exec_i::stop (void)
  {
    this->reactor ()->cancel_timer (this->ticker_);
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Sender_exec_i::stop : Timer canceled.\n")));
  }


  // Component attributes and port operations.

  // Operations from Components::SessionComponent.

  void
  Sender_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::SL_OneByOne::CCM_Sender_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Sender_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Sender_exec_i::ccm_activate (void)
  {
    this->add_instances_of_topic ();
    this->start ();
  }

  void
  Sender_exec_i::ccm_passivate (void)
  {
    this->stop ();
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_SL_OneByOne_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
