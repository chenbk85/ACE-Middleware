// -*- C++ -*-
//
// $Id$

#include "UCC_Test_Component_exec.h"
#include "tao/ORB_Core.h"
#include "ace/Reactor.h"

#define NR_OF_KEYS 10

struct UCCVariableSizedStructTest_i : UCCVariableSizedStructTest
{
  static size_t count_;

  UCCVariableSizedStructTest_i ()
    {
      ++count_;
    }

  ~UCCVariableSizedStructTest_i ()
    {
      --count_;
    }
private:
  UCCVariableSizedStructTest_i (const UCCVariableSizedStructTest_i &);
  UCCVariableSizedStructTest_i operator = (const UCCVariableSizedStructTest_i &);

};

struct UCCFixedSizedStructTest_i : UCCFixedSizedStructTest
{
  static size_t count_;

  UCCFixedSizedStructTest_i ()
    {
      ++count_;
    }

  ~UCCFixedSizedStructTest_i ()
    {
      --count_;
    }
private:
  UCCFixedSizedStructTest_i (const UCCFixedSizedStructTest_i &);
  UCCFixedSizedStructTest_i operator = (const UCCFixedSizedStructTest_i &);

};

size_t UCCVariableSizedStructTest_i::count_ = 0;
size_t UCCFixedSizedStructTest_i::count_ = 0;


namespace CIAO_UCC_Test_UCCTestComponent_Impl
{
  //============================================================
  // WriteVariableHandler
  //============================================================
  WriteVariableHandler::WriteVariableHandler (Component_exec_i &callback)
    : callback_ (callback)
  {
  }

  int
  WriteVariableHandler::handle_timeout (const ACE_Time_Value &, const void *)
  {
    this->callback_.write_variable ();
    return 0;
  }

  //============================================================
  // WriteFixedHandler
  //============================================================
  WriteFixedHandler::WriteFixedHandler (Component_exec_i &callback)
    : callback_ (callback)
  {
  }

  int
  WriteFixedHandler::handle_timeout (const ACE_Time_Value &, const void *)
  {
    this->callback_.write_fixed ();
    return 0;
  }



  //============================================================
  // Component_exec_i
  //============================================================
  Component_exec_i::Component_exec_i (void)
  {
    this->var_rh_ = new WriteVariableHandler (*this);
    this->fixed_rh_ = new WriteFixedHandler (*this);
  }

  Component_exec_i::~Component_exec_i (void)
  {
    delete this->var_rh_;
    delete this->fixed_rh_;
  }

  // Operations from Components::SessionComponent.
  void
  Component_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::UCC_Test::CCM_UCCTestComponent_Context::_narrow (ctx);
    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Component_exec_i::write_fixed (void)
  {
    ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX, _guard,
                        this->fixed_mutex_, CORBA::INTERNAL ());
    {
      for (CORBA::UShort i = 1; i < NR_OF_KEYS + 1; ++i)
        {
          ACE_DEBUG ((LM_DEBUG, "Write fixed %i\n", i));
          this->fixed_writer_->write_one (this->fixed_samples_[i], ::DDS::HANDLE_NIL);
        }
    }
  }

  void
  Component_exec_i::write_variable (void)
  {
    ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX, _guard,
                        this->var_mutex_, CORBA::INTERNAL ());
    {
      for (CORBA::UShort i = 1; i < NR_OF_KEYS + 1; ++i)
        {
          char key[7];
          ACE_OS::sprintf (key, "KEY_%d", i);
          ACE_DEBUG ((LM_DEBUG, "Write variable %C\n", key));
          this->var_writer_->write_one (this->var_samples_[key], ::DDS::HANDLE_NIL);
        }
    }
  }

  void
  Component_exec_i::create_fixed_sized_samples (void)
  {
    ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX, _guard,
                        this->fixed_mutex_, CORBA::INTERNAL ());
    ACE_DEBUG ((LM_DEBUG, "Component_exec_i::create_fixed_sized_samples - "
                          "Create fixed sized samples.\n"));
    for (::CORBA::UShort i = 1; i < NR_OF_KEYS + 1; ++i)
      {
        UCCFixedSizedStructTest_i new_key;
        new_key.x = i;
        new_key.y = new_key.x;
        new_key.z = 2*i;

        this->fixed_samples_[i] = new_key;
      }
  }

  void
  Component_exec_i::create_variable_sized_samples (void)
  {
    ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX, _guard,
                        this->var_mutex_, CORBA::INTERNAL ());
    ACE_DEBUG ((LM_DEBUG, "Component_exec_i::create_variable_sized_samples - "
                      "Create variable sized samples\n"));
    for (::CORBA::UShort i = 1; i < NR_OF_KEYS + 1; ++i)
      {
        char key[7];
        UCCVariableSizedStructTest_i new_key;
        ACE_OS::sprintf (key, "KEY_%d", i);
        new_key.symbol = CORBA::string_dup (key);
        new_key.x = i;
        new_key.y = new_key.x;
        this->var_samples_[key] = &new_key;
      }
  }

  void
  Component_exec_i::configuration_complete (void)
  {
  }

  void
  Component_exec_i::ccm_activate (void)
  {
    this->var_writer_ = this->context_->get_connection_var_size_write_data ();
    this->fixed_writer_ = this->context_->get_connection_fixed_size_write_data ();

    ACE_DEBUG ((LM_DEBUG, "Component_exec_i::ccm_activate - "
                          "Create samples.\n"));
    this->create_fixed_sized_samples ();
    this->create_variable_sized_samples ();

    if (this->context_->get_CCM_object()->_get_orb ()->orb_core ()->reactor ()->schedule_timer (
                this->var_rh_,
                0,
                ACE_Time_Value (2, 0),
                ACE_Time_Value (1, 0)) == -1)
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Component_exec_i::ccm_activate : ")
                              ACE_TEXT ("Error scheduling timer for variable sized struct.\n")));
      }

    if (this->context_->get_CCM_object()->_get_orb ()->orb_core ()->reactor ()->schedule_timer (
                this->fixed_rh_,
                0,
                ACE_Time_Value (2, 0),
                ACE_Time_Value (1, 0)) == -1)
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Component_exec_i::ccm_activate : ")
                              ACE_TEXT ("Error scheduling timer for fixed sized struct.\n")));
      }
  }

  void
  Component_exec_i::ccm_passivate (void)
  {
    this->context_->get_CCM_object()->_get_orb ()->orb_core ()->reactor ()->cancel_timer (this->var_rh_);
    this->context_->get_CCM_object()->_get_orb ()->orb_core ()->reactor ()->cancel_timer (this->fixed_rh_);
  }

  void
  Component_exec_i::ccm_remove (void)
  {
    if (UCCFixedSizedStructTest_i::count_ != 0)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Reference count for fixed sized "
                              "samples is not nil. expected <0> - found <%d>\n",
                              UCCFixedSizedStructTest_i::count_));
      }
    else
      {
        ACE_DEBUG ((LM_DEBUG, "Reference count for variable sized "
                              "samples is nil\n"));
      }
    if (UCCVariableSizedStructTest_i::count_ != 0)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Reference count for variable sized "
                              "samples is not nil. expected <0> - found <%d>\n",
                              UCCVariableSizedStructTest_i::count_));
      }
    else
      {
        ACE_DEBUG ((LM_DEBUG, "Reference count for variable sized "
                              "samples is nil\n"));
      }

  }

  extern "C" COMPONENT_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_UCCTest_Component_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Component_exec_i);

    return retval;
  }
}

