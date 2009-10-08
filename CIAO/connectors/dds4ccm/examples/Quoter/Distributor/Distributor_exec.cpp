// -*- C++ -*-
//
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.2
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
 *       http://doc.ece.uci.edu/
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

// TAO_IDL - Generated from
// be/be_codegen.cpp:1278

#include "Distributor_exec.h"
#include "ciao/CIAO_common.h"
#include "ace/Reactor.h"
#include "ace/Guard_T.h"
#include "ace/CORBA_macros.h"
#include "ace/OS_NS_time.h"
#include <iostream>

namespace CIAO_Quoter_Distributor_Impl
{
  //============================================================
  // Component Executor Implementation Class: Distributor_exec_i
  //============================================================

  pulse_Generator::pulse_Generator (Distributor_exec_i &callback)
    : active_ (0),
      pulse_callback_ (callback)
  {
    // initialize the reactor
    this->reactor (ACE_Reactor::instance ());
  }

  pulse_Generator::~pulse_Generator ()
  {
  }

  int
  pulse_Generator::open_h ()
  {
    // convert the task into a active object that runs in separate thread
    return this->activate ();
  }

  int
  pulse_Generator::close_h ()
  {
    this->reactor ()->end_reactor_event_loop ();

    // wait for all threads in the task to exit before it returns
    return this->wait ();
  }

  int
  pulse_Generator::start (CORBA::ULong hertz)
  {
    // return if not valid
    if (hertz == 0 || this->active_ != 0)
    {
      return -1;
    }

    // calculate the interval time
    long usec = 1000000 / hertz;

    std::cerr << "Starting pulse_generator with hertz of " << hertz << ", interval of "
              << usec << std::endl;

    if (this->reactor ()->schedule_timer (this,
                                          0,
                                          ACE_Time_Value (0, usec),
                                          ACE_Time_Value (0, usec)) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "Unable to setup Timer\n"),
                          -1);

    }

    this->active_ = 1;
    return 0;
  }

  int
  pulse_Generator::stop (void)
  {
    // return if not valid.
    if (this->active_ == 0)
    {
      return -1;
    }
    // cancle the timer
    this->reactor ()->cancel_timer (this);
    this->active_ = 0;
    return 0;
  }

  int
  pulse_Generator::active (void)
  {
    return this->active_;
  }

  int
  pulse_Generator::handle_close (ACE_HANDLE handle,
                                 ACE_Reactor_Mask close_mask)
  {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("[%x] handle = %d, close_mask = %d\n"),
                this,
                handle,
                close_mask));
    return 0;
  }

  int
  pulse_Generator::handle_timeout (const ACE_Time_Value &,
                                   const void *)
  {
    // Notify the subscribers
    this->pulse_callback_.tick ();
    return 0;
  }

  int
  pulse_Generator::svc (void)
  {
    // define the owner of the reactor thread
    this->reactor ()->owner (ACE_OS::thr_self ());

    // run event loop to wait for event, and then dispatch them to corresponding handlers
    this->reactor ()->run_reactor_event_loop ();

    return 0;
  }

  Distributor_exec_i::Distributor_exec_i (void)
    : rate_ (5)
  {
    ACE_OS::srand (static_cast <u_int> (ACE_OS::time ()));
    this->ticker_ = new pulse_Generator (*this);
  }

  Distributor_exec_i::~Distributor_exec_i (void)
  {
  }

  // Supported operations and attributes.

  void
  Distributor_exec_i::tick (void)
  {
    std::cerr << "Ticking" << std::endl;

    for (Stock_Table::iterator i = this->stocks_.begin ();
         i != this->stocks_.end ();
         ++i)
      {
        if (ACE_OS::rand () % 2)
          {
            //std::cerr << "Updating stock: " << i->first.c_str () << std::endl;

            int delta = (ACE_OS::rand () % 10) - 2;

            i->second->current += delta;

            if (i->second->current > i->second->high)
              i->second->high = i->second->current;

            if (i->second->current < i->second->low)
              i->second->low = i->second->current;

            if (!CORBA::is_nil (this->writer_))
              this->writer_->write (i->second);
            else
              std::cerr << "Writer reference is nil!" << std::endl;

          }
      }
  }

  void
  Distributor_exec_i::add_stock (
    const char * stock)
  {
    std::cerr << "Distributor_exec_i::add_stock - Adding stock: " << stock << std::endl;

    ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX, _guard,
                        this->mutex_, CORBA::INTERNAL ());

    Quoter::Stock_Info *new_stock = new Quoter::Stock_Info;

    new_stock->low = 50;
    new_stock->high = 50;
    new_stock->current = 50;
    new_stock->symbol = stock;

    this->stocks_[stock] = new_stock;
  }

  void
  Distributor_exec_i::del_stock (const char * stock)
  {
    std::cerr << "Distributor_exec_i::del_stock - Removing stock: "  << stock << std::endl;

    ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX, _guard,
                        this->mutex_, CORBA::INTERNAL ());

    Stock_Table::iterator pos = this->stocks_.find (stock);

    if (pos != this->stocks_.end ())
      {
        this->stocks_.erase (pos);
      }

    std::cerr << "Distributor_exec_i::del_stock - Stock no present: " << stock;
  }

  void
  Distributor_exec_i::start (void)
  {
    this->ticker_->start (this->rate_);
  }

  void
  Distributor_exec_i::stop (void)
  {
    this->ticker_->stop ();
  }

  // Component attributes.

  ::CORBA::ULong
  Distributor_exec_i::rate (void)
  {
    return this->rate_;
  }

  void
  Distributor_exec_i::rate (
    ::CORBA::ULong rate )
  {
    this->rate_ = rate;
  }

  // Port operations.

  // Operations from Components::SessionComponent.

  void
  Distributor_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    ::Quoter::CCM_Distributor_Context_var lctx =
      ::Quoter::CCM_Distributor_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (lctx.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }

    this->context_ = lctx;
  }

  void
  Distributor_exec_i::configuration_complete (void)
  {
    /* Your code here. */
    this->writer_ = this->context_->get_connection_info_in_data ();

    this->ticker_->activate ();
  }

  void
  Distributor_exec_i::ccm_activate (void)
  {
    this->start ();
    this->add_stock ("MSFT");
  }

  void
  Distributor_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Distributor_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C" DISTRIBUTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Quoter_Distributor_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Distributor_exec_i);

    return retval;
  }
}

