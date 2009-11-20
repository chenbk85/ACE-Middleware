// -*- C++ -*-
//
// $Id$

#include "Broker_exec.h"
#include "ace/Reactor.h"
#include "ace/OS_NS_time.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_Quoter_Broker_Impl
{

  read_action_Generator::read_action_Generator (Broker_exec_i &callback)
    : active_ (0),
      pulse_callback_ (callback)
  {
    // initialize the reactor
    this->reactor (ACE_Reactor::instance ());
  }

  read_action_Generator::~read_action_Generator ()
  {
  }

  int
  read_action_Generator::open_h ()
  {
    // convert the task into a active object that runs in separate thread
    return this->activate ();
  }

  int
  read_action_Generator::close_h ()
  {
    this->reactor ()->end_reactor_event_loop ();
    // wait for all threads in the task to exit before it returns
    return this->wait ();
  }

  int
  read_action_Generator::start (CORBA::ULong hertz)
  {
    // return if not valid
    if (hertz == 0 || this->active_ != 0)
      {
        return -1;
      }

    // calculate the interval time
    long usec = 1000 / hertz;

    std::cerr << "Starting read_action_generator with hertz of " << hertz << ", interval of "
              << usec << std::endl;

    if (this->reactor ()->schedule_timer (this,
                                          0,
                                          ACE_Time_Value(0),
                                          ACE_Time_Value(3)) == -1)
      {
        ACE_ERROR_RETURN ((LM_ERROR,
                          "Unable to setup Timer\n"),
                            -1);

      }

    ACE_OS::sleep (2);
    this->active_ = 1;
    return 0;
  }

  int
  read_action_Generator::stop (void)
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
  read_action_Generator::active (void)
  {
    return this->active_;
  }

  int
  read_action_Generator::handle_close (ACE_HANDLE handle,
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
  read_action_Generator::handle_timeout (const ACE_Time_Value &,
                                         const void *)
  {
    // Notify the subscribers
    //    this->pulse_callback_.read_one();
    //    this->pulse_callback_.read_one_history();
    //    this->pulse_callback_.read_all();
    //    this->pulse_callback_.read_all_history();
    return 0;
  }

  int
  read_action_Generator::svc (void)
  {
    // define the owner of the reactor thread
    this->reactor ()->owner (ACE_OS::thr_self ());

    // run event loop to wait for event, and then dispatch them to corresponding handlers
    this->reactor ()->run_reactor_event_loop ();

    return 0;
  }

  void
  Broker_exec_i::read_one (void)
  {
    std::cerr << "read_one" << std::endl;
    ::Quoter::Stock_Info  stock_info;
    stock_info.symbol= "IBM";
    ::CCM_DDS::ReadInfo readinfo;

    try
      {
        this->reader_->read_one_last (stock_info, readinfo, ::DDS::HANDLE_NIL);
        time_t tim = readinfo.source_timestamp.sec;
        printf("Read_Info. -> date = %s",ctime(&tim));
        printf ("Stock_Info_Read_One: received a stock_info for <%s> at %u:%u:%u\n",
            stock_info.symbol.in (),
            stock_info.low,
            stock_info.current,
            stock_info.high);
      }
    catch(CCM_DDS::NonExistent& )
      {
        printf("Stock_Info_Read_One: no stock_info received\n");
      }
  }

  void
  Broker_exec_i::read_all (void)
  {
    std::cerr << "read_all" << std::endl;

    ::Quoter::Stock_Info_Seq_var  stock_infos;
    ::CCM_DDS::ReadInfoSeq_var readinfoseq;
    this->reader_->read_all(stock_infos.out(), readinfoseq.out());
    if(readinfoseq->length()!= 0)
      {
        int nr_of_infos = readinfoseq->length();
        for(int i = 0; i < nr_of_infos; i ++)
          {
            time_t tim = readinfoseq[i].source_timestamp.sec;
            printf("Read_Info.source_timestamp -> date = %s",ctime(&tim));
          }
      }
    if(stock_infos->length()!= 0)
      {
        for(CORBA::ULong i = 0; i < stock_infos->length(); i ++)
          {
            printf ("Stock_Info_Read_All: Number %d : received a stock_info for <%s> at %u:%u:%u\n",
                i,
                stock_infos[i].symbol.in (),
                stock_infos[i].low,
                stock_infos[i].current,
                stock_infos[i].high);
          }
      }
  }
  void
  Broker_exec_i::read_all_history (void)
  {
    std::cerr << "read_all_history" << std::endl;

    ::Quoter::Stock_Info_Seq_var  stock_infos;
    ::CCM_DDS::ReadInfoSeq_var readinfoseq;
    this->reader_->read_all(stock_infos.out(), readinfoseq.out());
    if(readinfoseq->length()!= 0)
      {
        int nr_of_infos = readinfoseq->length();
        for(int i = 0; i < nr_of_infos; i ++)
          {
            time_t tim = readinfoseq[i].source_timestamp.sec;
            printf("Read_Info.source_timestamp -> date = %s",ctime(&tim));
          }
      }
    if(stock_infos->length()!= 0)
      {
        int nr_of_stock_infos = stock_infos->length();
        for(CORBA::ULong i = 0; i < (CORBA::ULong)nr_of_stock_infos; i ++)
          {
            printf ("Stock_Info_Read_All_History: Number %d : received a stock_info for <%s> at %u:%u:%u\n",
                i,
                stock_infos[i].symbol.in (),
                stock_infos[i].low,
                stock_infos[i].current,
                stock_infos[i].high);
          }
      }
  }
  // read all samples of an given instance
  void
  Broker_exec_i::read_one_history (void)
  {
    std::cerr << "read_one_history" << std::endl;
    ::Quoter::Stock_Info  stock_info;
    stock_info.symbol= "IBM";  //key of instance to read

    ::Quoter::Stock_Info_Seq_var  stock_infos;
    ::CCM_DDS::ReadInfoSeq_var readinfoseq;
    try
      {
        this->reader_->read_one_all(stock_info,stock_infos.out(), readinfoseq.out(), ::DDS::HANDLE_NIL);
        if(readinfoseq->length()!= 0)
          {
            int nr_of_infos = readinfoseq->length();
            for(int i = 0; i < nr_of_infos; i ++)
              {
                time_t tim = readinfoseq[i].source_timestamp.sec;
                printf("Read_Info.source_timestamp -> date = %s",ctime(&tim));
              }
          }
        if(stock_infos->length()!= 0)
          {
            int nr_of_stock_infos = stock_infos->length();
            for(CORBA::ULong i = 0; i < (CORBA::ULong)nr_of_stock_infos; i ++)
              {
                printf ("Stock_Info_Read_One_History: Number %d : received a stock_info for <%s> at %u:%u:%u\n",
                    i,
                    stock_infos[i].symbol.in (),
                    stock_infos[i].low,
                    stock_infos[i].current,
                    stock_infos[i].high);
              }
          }
      }
    catch(CCM_DDS::NonExistent& )
      {
         printf("Stock_Info_Read_One_History: no stock_info's received\n");
      }
  }
  //============================================================
  // Facet Executor Implementation Class: Stock_Info_Listener_exec_i
  //============================================================

  Stock_Info_Listener_exec_i::Stock_Info_Listener_exec_i (void)
  {
  }

  Stock_Info_Listener_exec_i::~Stock_Info_Listener_exec_i (void)
  {
  }

  void
  Stock_Info_Listener_exec_i::on_many_data (
    const ::Quoter::Stock_Info_Seq & /* an_instance */,
    const ::CCM_DDS::ReadInfoSeq & /* info */)
  {
  }

  void
  Stock_Info_Listener_exec_i::on_one_data (
    const ::Quoter::Stock_Info & an_instance,
    const ::CCM_DDS::ReadInfo & /* info */)
  {
    printf ("Stock_Info_Listener: received a stock_info for <%s> at %u:%u:%u\n",
            an_instance.symbol.in (),
            an_instance.low,
            an_instance.current,
            an_instance.high);
  }
  //============================================================
  // Facet Executor Implementation Class: PortStatusListener_exec_i
  //============================================================

  PortStatusListener_exec_i::PortStatusListener_exec_i (void)
  {
    printf("####### construct PortStatusListener ######");
  }

  PortStatusListener_exec_i::~PortStatusListener_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::PortStatusListener

  void
  PortStatusListener_exec_i::on_requested_deadline_missed (
    ::DDS::DataReader_ptr /* the_reader */,
    const ::DDS::RequestedDeadlineMissedStatus & /* status */)
  {
    printf("####### deadline missed ######");
  }

  void
  PortStatusListener_exec_i::on_sample_lost (
    ::DDS::DataReader_ptr  /*the_reader*/ ,
    const ::DDS::SampleLostStatus &  status )
  {
    printf("####### sample lost ######");
    printf(" status.total_count = %d\n", status.total_count);
    printf(" status.total_count_change = %d\n", status.total_count_change);
  }

  //============================================================
  // Component Executor Implementation Class: Broker_exec_i
  //============================================================

  Broker_exec_i::Broker_exec_i (void)
  {
    ACE_OS::srand (static_cast <u_int> (ACE_OS::time ()));
    this->ticker_ = new read_action_Generator (*this);
  }

  Broker_exec_i::~Broker_exec_i (void)
  {
    printf ("Broker_exec_i::~Broker_exec_i\n");
  }

  // Supported operations and attributes.

  // Component attributes.

  // Port operations.

  ::CCM_DDS::Quoter::CCM_Listener_ptr
  Broker_exec_i::get_info_out_data_listener (void)
  {
    printf ("*************** out listener\n");
    return new Stock_Info_Listener_exec_i ();
  }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Broker_exec_i::get_info_out_status (void)
  {
    printf ("*************** out status************************\n");
    //return ::CCM_DDS::CCM_PortStatusListener::_nil ();
    return new PortStatusListener_exec_i ();
  }

  // Operations from Components::SessionComponent.

  void
  Broker_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    ::Quoter::CCM_Broker_Context_var lctx =
      ::Quoter::CCM_Broker_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (lctx.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }

    this->context_ = lctx;
  }

  void
  Broker_exec_i::configuration_complete (void)
  {
    std::cerr << ">>> Broker_exec_i::configuration_complete" << endl;
    this->reader_ = this->context_->get_connection_info_out_data();
  }

  void
  Broker_exec_i::start (void)
  {
    std::cerr << ">>> Broker_exec_i::start" << endl;
    this->ticker_->start (500);
  }

  void
  Broker_exec_i::stop (void)
  {
    std::cerr << ">>> Broker_exec_i::stop" << endl;
    this->ticker_->stop ();
  }

  void
  Broker_exec_i::ccm_activate (void)
  {
    std::cerr << ">>> Broker_exec_i::ccm_activate" << endl;
    ::CCM_DDS::DataListenerControl_var lc =
    this->context_->get_connection_info_out_data_control ();

    if (CORBA::is_nil (lc.in ()))
      {
        printf ("Error:  Listener control receptacle is null!\n");
        throw CORBA::INTERNAL ();
      }
    //in case of testing Listener set lc-> enabled true
    lc->mode ( ::CCM_DDS::ONE_BY_ONE);
    //in case of testing Reader set lc-> enabled false, so the Listener doesn't consume all the messages
    //lc->enabled (false);
    this->start();
  }

  void
  Broker_exec_i::ccm_passivate (void)
  {
    std::cerr << ">>> Broker_exec_i::ccm_passivate" << endl;
    this->stop ();
  }

  void
  Broker_exec_i::ccm_remove (void)
  {
    std::cerr << ">>> Broker_exec_i::ccm_remove" << endl;
    this->ticker_->close_h ();
  }

  extern "C" BROKER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Quoter_Broker_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    printf("in create Broker\n");
    ACE_NEW_NORETURN (
      retval,
      Broker_exec_i);

    return retval;
  }
}

