// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0.2
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

#include "Receiver_exec.h"
#include "tao/ORB_Core.h"
#include "ace/Reactor.h"

namespace CIAO_Receiver_Impl
{

  /**
     * HelloGenerator
     */

  HelloGenerator::HelloGenerator (Receiver_exec_i &generator)
    : generator_ (generator)
  {
  }

  int
  HelloGenerator::handle_timeout (const ACE_Time_Value &, const void *)
  {
    // Notify the subscribers
    this->generator_.tick ();
    return 0;
  }

  /**
  * Component Executor Implementation Class: Receiver_exec_i
  */

  Receiver_exec_i::Receiver_exec_i (void)
  : interval_ (2, 1),
    strategy_("thru_poa")
  {
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::Receiver_exec_i \n "));
    this->hello_generator_ = new HelloGenerator (*this);
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
   Receiver_exec_i::tick (void)
   {
     try
       {
         /// Retrieve the connection to the sender.
         Hello_var hello_to_rec =
           this->ciao_context_->get_connection_hello_to_rec ();
         if (! ::CORBA::is_nil (hello_to_rec.in ()))
           {
             pointer_id::_var_type p = new pointer_id;
             p->point = (long)p.ptr ();
             hello_to_rec->set_point(p.in(), this->strategy_.in());

              ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::tick - "
                                            "set_hello-point with pointer %@\n",
                                            (void *)p.ptr ()));

           }
         else
           {
             ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::tick - "
                                            "no connection hello_to_rec with sender.\n"));
           }
        }
     catch (const CORBA::INTERNAL& /*ex*/)
       {
         if (ACE_OS::strcmp ("no_thru_poa", this->strategy_.in())== 0)
           {
             ACE_DEBUG ((LM_DEBUG, "OK: Receiver received expected exception\n"));
           }
         else
           {
             ACE_ERROR ((LM_ERROR, "Receiver_exec_i::tick - "
                             "Error: Unexpected exception caught\n"));
           }
       }
     catch (const CORBA::Exception &e)
       {
         /// Always catch CORBA exceptions. There might be somthing wrong with
         /// the CIAO framework (i.e. connection lost).
         e._tao_print_exception("Receiverr_exec_i::tick - "
                                "Error: Unexpected exception");
       }
     catch (...)
       {
         /// Just for all security
         ACE_ERROR ((LM_ERROR, "Receiver_exec_i::tick - "
                     "Error: Unexpected and unknown exception caught\n"));
       }
   }
  // Component attributes and port operations.

   char*
   Receiver_exec_i::strategy (void)
    {
      return ::CORBA::string_dup (this->strategy_);
    }

    void
    Receiver_exec_i::strategy (const char* strategy)
    {
      this->strategy_ = ::CORBA::string_dup (strategy);
    }

   // Operations from Components::SessionComponent.

  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::CCM_Receiver_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Receiver_exec_i::configuration_complete (void)
  {
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::configuration_complete \n "));
    /// No need to implement anything
  }

  void
  Receiver_exec_i::ccm_activate (void)
  {
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::ccm_activate \n "));
    /// No need to implement anything
    /// Start the timer .
     if (this->reactor ()->schedule_timer(
                 this->hello_generator_,  // The callback object
                 0,                       // No arguments for this callback
                 ACE_Time_Value (1, 0),   // Initial delay
                 this->interval_) == -1)  // Time interval
       {
         ACE_ERROR ((LM_ERROR, "Receiver_exec_i::ccm_activate - "
                               "Error scheduling timer\n"));
       }
     else
       {
         ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::ccm_activate - "
                               "Hello generator is running\n"));
       }
   }

  void
  Receiver_exec_i::ccm_passivate (void)
  {
    /// No need to implement anything
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::ccm_passivate \n "));
  }

  void
  Receiver_exec_i::ccm_remove (void)
  {
    /// No need to implement anything
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::ccm_remove \n "));
  }

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);

    return retval;
  }
}
