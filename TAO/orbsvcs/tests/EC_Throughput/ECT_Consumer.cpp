// $Id$

#include "ace/Get_Opt.h"
#include "ace/Auto_Ptr.h"
#include "ace/Sched_Params.h"

#include "tao/Timeprobe.h"
#include "orbsvcs/Event_Utilities.h"
#include "orbsvcs/Event_Service_Constants.h"
#include "orbsvcs/Scheduler_Factory.h"
#include "orbsvcs/Time_Utilities.h"
#include "ECT_Consumer.h"

ACE_RCSID(EC_Throughput, ECT_Consumer, "$Id$")

Test_Consumer::Test_Consumer (ECT_Driver *driver,
                              void *cookie,
                              int n_suppliers)
  : driver_ (driver),
    cookie_ (cookie),
    n_suppliers_ (n_suppliers),
    recv_count_ (0),
    shutdown_count_ (0)
{
}

void
Test_Consumer::connect (const char* name,
                        int event_a, int event_b,
                        RtecEventChannelAdmin::EventChannel_ptr ec,
                        CORBA::Environment& _env)
{
  RtecScheduler::Scheduler_ptr server =
    ACE_Scheduler_Factory::server ();

  RtecScheduler::handle_t rt_info =
    server->create (name, _env);
  if (_env.exception () != 0) return;

  // The worst case execution time is far less than 2
  // milliseconds, but that is a safe estimate....
  ACE_Time_Value tv (0, 2000);
  TimeBase::TimeT time;
  ORBSVCS_Time::Time_Value_to_TimeT (time, tv);
  server->set (rt_info,
               RtecScheduler::VERY_HIGH_CRITICALITY,
               time, time, time,
               0,
               RtecScheduler::VERY_LOW_IMPORTANCE,
               time,
               0,
               RtecScheduler::OPERATION,
               _env);
  if (_env.exception () != 0) return;

  ACE_ConsumerQOS_Factory qos;
  qos.start_disjunction_group ();
  qos.insert_type (ACE_ES_EVENT_SHUTDOWN, rt_info);
  qos.insert_type (event_a, rt_info);
  qos.insert_type (event_b, rt_info);

  // = Connect as a consumer.
  RtecEventChannelAdmin::ConsumerAdmin_var consumer_admin =
    ec->for_consumers (_env);
  if (_env.exception () != 0) return;

  this->supplier_proxy_ =
    consumer_admin->obtain_push_supplier (_env);
  if (_env.exception () != 0) return;

  RtecEventComm::PushConsumer_var objref = this->_this (_env);
  if (_env.exception () != 0) return;

  this->supplier_proxy_->connect_push_consumer (objref.in (),
                                                qos.get_ConsumerQOS (),
                                                _env);
  if (_env.exception () != 0) return;
}

void
Test_Consumer::disconnect (CORBA::Environment &_env)
{
  if (CORBA::is_nil (this->supplier_proxy_.in ()))
    return;

  this->supplier_proxy_->disconnect_push_supplier (_env);
  if (_env.exception () != 0) return;

  this->supplier_proxy_ =
    RtecEventChannelAdmin::ProxyPushSupplier::_nil ();

  // Deactivate the servant
  PortableServer::POA_var poa = 
    this->_default_POA (_env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  PortableServer::ObjectId_var id =
    poa->servant_to_id (this, _env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
  poa->deactivate_object (id.in (), _env);
  TAO_CHECK_ENV_RETURN_VOID (_env);
}

void
Test_Consumer::dump_results (const char* name)
{
  ACE_Time_Value tv;
  this->timer_.elapsed_time (tv);
  double f = 1.0 / (tv.sec () + tv.usec () / 1000000.0);
  double eps = this->recv_count_ * f;
  
  ACE_DEBUG ((LM_DEBUG,
              "ECT_Consumer (%s):\n"
              "    Total time: %d.%08.8d (secs.usecs)\n"
              "    Total events: %d\n"
              "    Events per second: %.3f\n",
              name,
              tv.sec (), tv.usec (),
              this->recv_count_,
              eps));
}

void
Test_Consumer::push (const RtecEventComm::EventSet& events,
                     CORBA::Environment &_env)
{
  if (events.length () == 0)
    {
      // ACE_DEBUG ((LM_DEBUG, "no events\n"));
      return;
    }

  ACE_GUARD (ACE_SYNCH_MUTEX, ace_mon, this->lock_);

  // We start the timer as soon as we receive the first event...
  if (this->recv_count_ == 0)
    this->timer_.start ();

  this->recv_count_ += events.length ();

  if (TAO_debug_level > 0
      && this->recv_count_ % 1000 == 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "ECT_Consumer (%P|%t): %d events received\n",
		  this->recv_count_));
    }

  // ACE_DEBUG ((LM_DEBUG, "%d event(s)\n", events.length ()));

  for (u_int i = 0; i < events.length (); ++i)
    {
      const RtecEventComm::Event& e = events[i];

      if (e.data.payload.mb () == 0)
        {
          // ACE_DEBUG ((LM_DEBUG, "No data in event[%d]\n", i));
          // continue;
        }
      if (events[i].header.type == ACE_ES_EVENT_SHUTDOWN)
        {
          this->shutdown_count_++;
          if (this->shutdown_count_ >= this->n_suppliers_)
            {
              // We stop the timer as soon as we realize it is time to
              // do so.
              this->timer_.stop ();
              this->driver_->shutdown_consumer (this->cookie_, _env);
            }
        }
    }
}

void
Test_Consumer::disconnect_push_consumer (CORBA::Environment &)
{
}

// ****************************************************************

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
