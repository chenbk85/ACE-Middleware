// -*- C++ -*-
// $Id$

#include "UsesSM_Receiver_exec.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_UsesSM_Receiver_Impl
{
  One_exec_i::One_exec_i (Atomic_UShort &nr_of_one_received)
    : nr_of_one_received_(nr_of_one_received)
  {
  }

  One_exec_i::~One_exec_i (void)
  {
  }

  ::CORBA::Long
  One_exec_i::foo (const char * in_str, ::CORBA::Long cmd,
                   ::CORBA::String_out answer)
  {
    // sleep to make it possible to test asynchronous behavior.
    ACE_OS::sleep(2);
    ++nr_of_one_received_;
    answer = CORBA::string_dup (in_str);
    return cmd;
  }
  Two_exec_i::Two_exec_i (Atomic_UShort &nr_of_two_received)
    : nr_of_two_received_(nr_of_two_received)
  {
  }

  Two_exec_i::~Two_exec_i (void)
  {
  }

  void
  Two_exec_i::bar (::CORBA::Long /*cmd*/,
                   ::CORBA::String_out answer)
  {
    ++nr_of_two_received_;
    answer = CORBA::string_dup ("answer TWO::bar");
  }

  Receiver_exec_i::Receiver_exec_i (void)
  {
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
  }

  ::UsesSM::CCM_One_ptr
  Receiver_exec_i::get_do_my_one (void)
  {
    return new One_exec_i (nr_of_one_received_);
  }

  ::UsesSM::CCM_Two_ptr
  Receiver_exec_i::get_do_my_two (void)
  {
    return new Two_exec_i (nr_of_two_received_);
  }

  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ = ::UsesSM::CCM_Receiver_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Receiver_exec_i::configuration_complete (void)
  {
  }

  void
  Receiver_exec_i::ccm_activate (void)
  {
    nr_of_one_received_ = 0;
    nr_of_two_received_ = 0;
  }

  void
  Receiver_exec_i::ccm_passivate (void)
  {
  }

  void
  Receiver_exec_i::ccm_remove (void)
  {
    if (((nr_of_one_received_.value() == 2) &&
         (nr_of_two_received_.value() == 0)) ||
        ((nr_of_two_received_.value() == 3) &&
         (nr_of_one_received_.value() == 0)))
      {
        if (nr_of_one_received_.value() == 2)
          {
            ACE_DEBUG ((LM_DEBUG, "OK: Receiver received the expected "
                                  "number of correct calls for foo (%u/2).\n",
                                   nr_of_one_received_.value()));
          }
        else
          {
            ACE_DEBUG ((LM_DEBUG, "OK: Receiver received the expected "
                                  "number of correct calls for bar (%u/3).\n",
                                   nr_of_two_received_.value()));
          }
      }
    else
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Receiver didn't receive the expected "
                              "number of correct calls.\n"
                              "Expected 2 calls for foo but received %u or \n"
                              "Expected 3 calls for bar but received %u.\n",
                              nr_of_one_received_.value(),
                              nr_of_two_received_.value()));

      }
  }

  extern "C"  ::Components::EnterpriseComponent_ptr
  create_UsesSM_AMI_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_RETURN (
      retval,
      Receiver_exec_i,
      ::Components::EnterpriseComponent::_nil ());

    return retval;
  }
}
