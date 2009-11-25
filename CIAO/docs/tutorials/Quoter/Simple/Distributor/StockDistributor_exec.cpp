// $Id$

#include "StockDistributor_exec.h"
#include "ace/Reactor.h"

namespace CIAO_Stock_StockDistributor_Impl
{

  // initialze the stock values
  CORBA::Long
  StockDistributor_exec_i::ibm_ = 100;

  CORBA::Long
  StockDistributor_exec_i::msft_ = 101;

  //==================================================================
  //  C L A S S: pulse_Generator
  //==================================================================

  pulse_Generator::pulse_Generator (StockDistributor_exec_i *callback)
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
  pulse_Generator::start (CORBA::Long hertz)
  {
    // return if not valid
    if (hertz == 0 || this->active_ != 0)
    {
      return -1;
    }

    // calculate the interval time
    long usec = 1000000 / hertz;

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
    this->pulse_callback_->push_notify_out ();
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



  //==================================================================
  // Facet Executor Implementation Class:   StockQuoter_exec_i
  //==================================================================

  ::Stock::StockInfo *
  StockQuoter_exec_i::get_stock_info (const char *stock_name)
  {
    if (ACE_OS::strcmp (stock_name, "MSFT") == 0)
    {
      Stock::StockInfo_var info = new Stock::StockInfo;
      info->name = CORBA::string_dup ("MSFT");
      info->high = 10000;
      info->low = 0;
      info->last = this->distributor_.msft_; // retrieve the current stock value
      return info._retn ();
    }
    else if (ACE_OS::strcmp (stock_name, "IBM") == 0)
    {
      Stock::StockInfo_var info = new Stock::StockInfo;
      info->name = CORBA::string_dup ("IBM");
      info->high = 10000;
      info->low = 0;
      info->last = this->distributor_.ibm_; // retrieve the current stock value
      return info._retn ();
    }
    else
    {
      throw Stock::Invalid_Stock ();
    }
  }

  //==================================================================
  // Component Executor Implementation Class:   StockDistributor_exec_i
  //==================================================================

  StockDistributor_exec_i::StockDistributor_exec_i (void)
    : rate_ (0), pulser_ (this)
  {
  }

  StockDistributor_exec_i::~StockDistributor_exec_i (void)
  {
  }

  // Supported or inherited operations.

  void
  StockDistributor_exec_i::start ()
  {
    if (this->rate_ == 0 || this->pulser_.active())
    {
      throw CORBA::BAD_PARAM ();
    }

    this->pulser_.start (this->rate_);
  }

  void
  StockDistributor_exec_i::stop ()
  {
    if (! this->pulser_.active ())
    {
      throw CORBA::BAD_INV_ORDER ();
    }

    this->pulser_.stop ();
  }

  // Attribute operations.

  ::CORBA::Long
  StockDistributor_exec_i::rate ()
  {
    return this->rate_;
  }

  void
  StockDistributor_exec_i::rate (
  ::CORBA::Long rate)
  {
    this->rate_ = rate;
  }

  // Port operations.

  ::Stock::CCM_StockQuoter_ptr
  StockDistributor_exec_i::get_push_quoter ()
  {
    return new StockQuoter_exec_i (*this);
  }

  void
  StockDistributor_exec_i::push_notify_out ()
  {
    ++this->msft_;
    ++this->ibm_;

    Stock::StockName_var ev_msft = new OBV_Stock::StockName;
    ev_msft->name (CORBA::string_dup ("MSFT"));
    this->context_->push_notify_out (ev_msft.in ());

    Stock::StockName_var ev_ibm = new OBV_Stock::StockName;
    ev_ibm->name (CORBA::string_dup ("IBM"));
    this->context_->push_notify_out (ev_ibm.in ());
  }

  // Operations from Components::SessionComponent

  void
  StockDistributor_exec_i::set_session_context (
  ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::Stock::CCM_StockDistributor_Context::_narrow (ctx);

    if (CORBA::is_nil (this->context_.in ()))
    {
      throw ::CORBA::INTERNAL ();
    }
  }

  void
  StockDistributor_exec_i::configuration_complete ()
  {
  }

  void
  StockDistributor_exec_i::ccm_activate ()
  {
    // Start the active object
    this->pulser_.open_h ();
  }

  void
  StockDistributor_exec_i::ccm_passivate ()
  {
    // Deactivate the active object
    this->pulser_.close_h ();
  }

  void
  StockDistributor_exec_i::ccm_remove ()
  {
  }

  //==================================================================
  // Home Executor Implementation Class:   StockDistributorHome_exec_i
  //==================================================================

  StockDistributorHome_exec_i::StockDistributorHome_exec_i (void)
  {
  }

  StockDistributorHome_exec_i::~StockDistributorHome_exec_i (void)
  {
  }

  ::Components::EnterpriseComponent_ptr
  StockDistributorHome_exec_i::create ()
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (
      retval,
      StockDistributor_exec_i,
      CORBA::NO_MEMORY ());

    return retval;
  }

  extern "C" STOCKDISTRIBUTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Stock_StockDistributorComp_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_RETURN (
      retval,
      StockDistributor_exec_i,
      ::Components::EnterpriseComponent::_nil ());

    return retval;
  }

  extern "C" STOCKDISTRIBUTOR_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Stock_StockDistributorHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();

    ACE_NEW_RETURN (
      retval,
      StockDistributorHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());

    return retval;
  }
}

