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

#include "InterMulti_Receiver_exec.h"

namespace CIAO_InterMulti_Receiver_Impl
{
   CORBA::UShort nr_of_received = 0;

  /**
   * Facet Executor Implementation Class: do_my_one_exec_i
   */

  do_my_one_exec_i::do_my_one_exec_i (
        ::InterMulti::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::InterMulti::CCM_Receiver_Context::_duplicate (ctx))
  {
  }

  do_my_one_exec_i::~do_my_one_exec_i (void)
  {
  }

  // Operations from ::InterMulti::One

  ::CORBA::Long
  do_my_one_exec_i::foo (const char * in_str,
  ::CORBA::Long cmd,
  ::CORBA::String_out answer)
  {
    ACE_DEBUG ((LM_DEBUG, "Receiver: one_foo, in_str = %C"
                          " cmd = <%u>\n",
                          in_str, cmd));
    if (cmd != 1)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Receiver ONE::foo,"
                              " origin not 1, but <%u>\n",
                              cmd));
      }
    else
      {
        ++nr_of_received;
      }
    answer = CORBA::string_dup ("answer foo one");
    return cmd;
  }

  /**
   * Facet Executor Implementation Class: do_my_two_exec_i
   */

  do_my_two_exec_i::do_my_two_exec_i (
        ::InterMulti::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::InterMulti::CCM_Receiver_Context::_duplicate (ctx))
  {
  }

  do_my_two_exec_i::~do_my_two_exec_i (void)
  {
  }

  // Operations from ::InterMulti::Two

  void
  do_my_two_exec_i::bar (::CORBA::Long cmd,
  ::CORBA::String_out answer)
  {
    ACE_DEBUG ((LM_DEBUG, "Receiver: two_bar,"
                          " cmd = <%u>\n",
                          cmd));
    if (cmd != 2)
      {
        ACE_ERROR ((LM_ERROR, "ERROR Receiver: TWO::bar,"
                              " origin not 2, but <%u>\n",
                              cmd));
      }
    else
      {
        ++nr_of_received;
      }
    answer = CORBA::string_dup ("answer bar two");
  }

  /**
   * Facet Executor Implementation Class: do_my_three_exec_i
   */

  do_my_three_exec_i::do_my_three_exec_i (
        ::InterMulti::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::InterMulti::CCM_Receiver_Context::_duplicate (ctx))
  {
  }

  do_my_three_exec_i::~do_my_three_exec_i (void)
  {
  }

  // Operations from ::InterMulti::Three

  void
  do_my_three_exec_i::bar (::CORBA::Long cmd,
  ::CORBA::String_out answer)
  {
    ACE_DEBUG ((LM_DEBUG, "Receiver: three_bar,"
                              " cmd = <%u>\n",
                              cmd));
        if (cmd != 3)
          {
            ACE_ERROR ((LM_ERROR, "ERROR: Receiver Three::bar,"
                                  " origin not 3, but <%u>\n",
                                  cmd));
          }
        else
          {
            ++nr_of_received;
          }
        answer = CORBA::string_dup ("answer bar three");
  }

  ::CORBA::Long
  do_my_three_exec_i::foo (const char * in_str,::CORBA::Long cmd,
                      ::CORBA::String_out answer)
  {
    ACE_DEBUG ((LM_DEBUG, "Receiver: three_foo, in_str = %C"
                               " cmd = <%u>\n",
                               in_str, cmd));
    if (cmd != 3)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Receiver THREE::foo,"
                              " origin not 3, but <%u>\n",
                              cmd));
      }
    else
      {
        ++nr_of_received;
      }
    answer = CORBA::string_dup ("answer foo three");
    return 3;
  }

  void
  do_my_three_exec_i::plus (::CORBA::Long cmd,
  ::CORBA::String_out answer)
  {
    ACE_DEBUG ((LM_DEBUG, "Receiver: three_plus,"
                           " cmd = <%u>\n",
                           cmd));
     ++nr_of_received;
     answer = CORBA::string_dup ("answer plus three");
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

  // Component attributes and port operations.

  ::InterMulti::CCM_One_ptr
  Receiver_exec_i::get_do_my_one (void)
  {
    if ( ::CORBA::is_nil (this->ciao_do_my_one_.in ()))
      {
        do_my_one_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          do_my_one_exec_i (
            this->ciao_context_.in ()),
            ::InterMulti::CCM_One::_nil ());

          this->ciao_do_my_one_ = tmp;
      }

    return
      ::InterMulti::CCM_One::_duplicate (
        this->ciao_do_my_one_.in ());
  }

  ::InterMulti::CCM_Two_ptr
  Receiver_exec_i::get_do_my_two (void)
  {
    if ( ::CORBA::is_nil (this->ciao_do_my_two_.in ()))
      {
        do_my_two_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          do_my_two_exec_i (
            this->ciao_context_.in ()),
            ::InterMulti::CCM_Two::_nil ());

          this->ciao_do_my_two_ = tmp;
      }

    return
      ::InterMulti::CCM_Two::_duplicate (
        this->ciao_do_my_two_.in ());
  }

  ::InterMulti::CCM_Three_ptr
  Receiver_exec_i::get_do_my_three (void)
  {
    if ( ::CORBA::is_nil (this->ciao_do_my_three_.in ()))
      {
        do_my_three_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          do_my_three_exec_i (
            this->ciao_context_.in ()),
            ::InterMulti::CCM_Three::_nil ());

          this->ciao_do_my_three_ = tmp;
      }

    return
      ::InterMulti::CCM_Three::_duplicate (
        this->ciao_do_my_three_.in ());
  }

  // Operations from Components::SessionComponent.

  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::InterMulti::CCM_Receiver_Context::_narrow (ctx);

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
    if (nr_of_received != 7)
       {
         ACE_ERROR ((LM_ERROR, "ERROR: not received the expected number of"
                               "correct calls"
                               "Expected: 7, Received: %u.\n",
                               nr_of_received));
       }
     else
       {
         ACE_DEBUG ((LM_DEBUG, "OK: Receiver received the expected "
                               "number of correct calls. "
                               "Expected: 7, Received: %u.\n",
                               nr_of_received));
       }  }

  extern "C" INTERMULTI_RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_InterMulti_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);

    return retval;
  }
}
