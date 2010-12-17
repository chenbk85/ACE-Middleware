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

#include "GetComp_Sender_exec.h"

namespace CIAO_GetComp_Sender_Impl
{
  CORBA::Boolean GetComponent = false;

  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  Sender_exec_i::Sender_exec_i (void){
  }

  Sender_exec_i::~Sender_exec_i (void)
  {
  }
  int
     Sender_exec_i::get_component(void)
     {
       ACE_OS::sleep (3);

       ::GetComp::AMI4CCM_MyFoo_var my_foo_ami_ =
         this->ciao_context_->get_connection_sendc_run_my_foo();

       if (CORBA::is_nil (my_foo_ami_))
         {
           ACE_ERROR ((LM_ERROR, ACE_TEXT ("ERROR Sender (ASYNCH)")
                                 ACE_TEXT (" :\tmy_foo_ami is NIL !\n")));
           return 1;
         }

       CORBA::Object_var cmp;
       try
         {
           cmp = my_foo_ami_->_get_component ();
           if (::CORBA::is_nil (cmp.in ()))
           {
             GetComp::InternalError ex (1, "Unable to get component interface");
             throw ex;
           }
         }
       catch (const GetComp::InternalError& ex)
         {
           ACE_ERROR ((LM_ERROR,
                       ACE_TEXT ("ERROR: Sender:")
                       ACE_TEXT ("caught InternalError exception: retval <%C>\n"),
                       ex.error_string.in()));
           return 1;
         }
       catch (const CORBA::Exception& ex)
         {
           ex._tao_print_exception ("ERROR: Caught unexpected except:");
           ACE_ERROR ((LM_ERROR,
                       ACE_TEXT ("ERROR: Sender :")
                       ACE_TEXT ("Unable to get component interface\n")));
           return 1;
         }

       try
         {
           ::GetComp::AMI4CCM_MyFoo_Connector::CCM_AMI4CCM_Connector_var conn =
             ::GetComp::AMI4CCM_MyFoo_Connector::CCM_AMI4CCM_Connector::_narrow (cmp.in ());

           if (::CORBA::is_nil (conn.in ()))
             {
               GetComp::InternalError ex (1, "Narrowed connector is nil.\n");
               throw ex;
             }
          }
        catch (const GetComp::InternalError& ex)
         {
           ACE_ERROR ((LM_ERROR,
                       ACE_TEXT ("ERROR: Sender:")
                       ACE_TEXT ("caught InternalError exception: retval <%C>\n"),
                       ex.error_string.in()));
           return 1;
         }
       catch (const CORBA::Exception& ex)
         {
           ex._tao_print_exception ("ERROR: Caught unexpected except:");
           ACE_ERROR ((LM_ERROR,
                       ACE_TEXT ("ERROR: Sender:")
                       ACE_TEXT ("Unable to narrow connector interface\n")));
           return 1;
         }
       return 0;
     }

  // Supported operations and attributes.

  // Component attributes and port operations.

  // Operations from Components::SessionComponent.

  void
  Sender_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::GetComp::CCM_Sender_Context::_narrow (ctx);

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
    if (get_component()== 0)
      {
        GetComponent = true;
      }
  }

  void
  Sender_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
    if (GetComponent != true)
      {
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("ERROR:")
                    ACE_TEXT (" Sender not possible to get component\n")));
      }
    else
      {
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("OK: Sender, possible to get component \n")));
      }
  }

  AMI4CCM_MyFooReplyHandler_run_my_foo_i::AMI4CCM_MyFooReplyHandler_run_my_foo_i (void)
  {
  }

  AMI4CCM_MyFooReplyHandler_run_my_foo_i::~AMI4CCM_MyFooReplyHandler_run_my_foo_i (void)
  {
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::foo (
    ::CORBA::Long /* ami_return_val */,
    const char * /* answer */)
  {
    /* Your code here. */
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::foo_excep (
    ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  extern "C" GETCOMP_T_SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_GetComp_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
