// $Id$

#include "Notify_Structured_Push_Consumer.h"
#include "goC.h"
#include "Notify_Test_Client.h"

#include "orbsvcs/CosNotifyCommC.h"
#include "orbsvcs/CosNamingC.h"

#include "ace/Get_Opt.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_strings.h"

static const char* ior = "file://supplier.ior";
static CORBA::Short discard_policy = CosNotification::FifoOrder;
CORBA::Long max_events_per_consumer = 4;
static Notify_Structured_Push_Consumer* consumer_1;

class Consumer_Client : public Notify_Test_Client
{
public:
  virtual int parse_args (int argc, char* argv[]);
};


int
Consumer_Client::parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "k:e:d:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'k':
        ior = get_opts.optarg;
        break;

      case 'd':
      {
        const char* discard = get_opts.optarg;
        if (ACE_OS::strcasecmp (discard, "fifo") == 0)
          {
            discard_policy = CosNotification::FifoOrder;
          }
        else if (ACE_OS::strcasecmp (discard, "priority") == 0)
          {
            discard_policy = CosNotification::PriorityOrder;
          }
        else if (ACE_OS::strcasecmp (discard, "lifo") == 0)
          {
            discard_policy = CosNotification::LifoOrder;
          }
        else if (ACE_OS::strcasecmp (discard, "deadline") == 0)
          {
            discard_policy = CosNotification::DeadlineOrder;
#if !defined (ACE_HAS_TIMED_MESSAGE_BLOCKS)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "This order policy requires timed message "
                               "blocks.\nPlease #define "
                               "ACE_HAS_TIMED_MESSAGE_BLOCKS in your "
                               "config.h\n"), -1);
#endif
          }
        else
          {
            ACE_ERROR_RETURN ((LM_ERROR,
                               "Unknown discard policy: %s\n",
                               discard_policy),
                              -1);
          }
        break;
      }
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-k <ior> "
                           "-d <fifo|priority|lifo|deadline> "
                           "\n",
                           argv [0]),
                          -1);
      }
  // Indicates sucessful parsing of the command line
  return 0;
}


static CosNotifyChannelAdmin::ConsumerAdmin_ptr
create_consumeradmin (CosNotifyChannelAdmin::EventChannel_ptr ec
                      ACE_ENV_ARG_DECL)
{
  CosNotifyChannelAdmin::AdminID adminid = 0;
  CosNotifyChannelAdmin::ConsumerAdmin_var admin =
    ec->new_for_consumers (CosNotifyChannelAdmin::OR_OP,
                           adminid
                           ACE_ENV_ARG_PARAMETER);


  return CosNotifyChannelAdmin::ConsumerAdmin::_duplicate (admin.in ());
}


static void
create_consumers (CosNotifyChannelAdmin::ConsumerAdmin_ptr admin,
                  Notify_Test_Client* client
                  ACE_ENV_ARG_DECL)
{
  ACE_DEBUG ((LM_DEBUG, "Max Events per Consumer = %d...\n", max_events_per_consumer));

  // startup the consumer
  ACE_NEW_THROW_EX (consumer_1,
                    Notify_Structured_Push_Consumer (
                                          "consumer1",
                                          discard_policy,
                                          max_events_per_consumer,
                                          *client),
                    CORBA::NO_MEMORY ());
  consumer_1->init (client->root_poa () ACE_ENV_ARG_PARAMETER);

  consumer_1->_connect (admin ACE_ENV_ARG_PARAMETER);
}

// ******************************************************************
// Main Section
// ******************************************************************

int main (int argc, char* argv[])
{
  int status = 0;
  ACE_TRY_NEW_ENV
    {
      Consumer_Client client;

      status = client.init (argc, argv ACE_ENV_ARG_PARAMETER);

      if (status == 0)
        {
          CosNotifyChannelAdmin::EventChannel_var ec =
            client.create_event_channel ("MyEventChannel", 1 ACE_ENV_ARG_PARAMETER);

          CORBA::ORB_ptr orb = client.orb ();
          CORBA::Object_var object =
                              orb->string_to_object (ior ACE_ENV_ARG_PARAMETER);

          sig_var sig = sig::_narrow (object.in () ACE_ENV_ARG_PARAMETER);

          if (CORBA::is_nil (sig.in ()))
            {
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "Object reference <%s> is nil\n",
                                 ior),
                                1);
            }

          CosNotifyChannelAdmin::ConsumerAdmin_var admin =
            create_consumeradmin (ec.in () ACE_ENV_ARG_PARAMETER);

          if (!CORBA::is_nil (admin.in ()))
            {
              create_consumers (admin.in (), &client ACE_ENV_ARG_PARAMETER);
              // Tell the supplier to go
              sig->go ();

              ACE_DEBUG((LM_DEBUG, "Consumer waiting for events...\n"));

              client.ORB_run( ACE_ENV_SINGLE_ARG_PARAMETER );

              ACE_DEBUG((LM_DEBUG, "Consumer done.\n"));
              consumer_1->disconnect();

              sig->done ();
            }
        }
    }
  ACE_CATCH (CORBA::Exception, e)
    {
      ACE_PRINT_EXCEPTION (e, "Error: ");
      status = 1;
    }
  ACE_ENDTRY;

  return status;
}
