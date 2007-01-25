// $Id$

// ******************************************************************
// Include Section
// ******************************************************************

#include "ace/Get_Opt.h"
#include "ace/OS_NS_unistd.h"

#include "orbsvcs/CosNotifyCommC.h"
#include "orbsvcs/CosNamingC.h"
#include "Notify_Sequence_Push_Consumer.h"
#include "goC.h"

#include "Notify_Test_Client.h"

// ******************************************************************
// Data Section
// ******************************************************************

static const char* ior = "file://supplier.ior";
static CORBA::Short discard_policy = CosNotification::AnyOrder;
static int sent = 40;
static Notify_Sequence_Push_Consumer* consumer_1 = 0;

// ******************************************************************
// Subroutine Section
// ******************************************************************

class Consumer_Client : public Notify_Test_Client
{
public:
  virtual int parse_args (int argc, char* argv[]);
};


int
Consumer_Client::parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "k:l:h:d:");
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
        if (ACE_OS::strcmp (discard, "fifo") == 0)
        {
          discard_policy = CosNotification::FifoOrder;
        }
        else if (ACE_OS::strcmp (discard, "priority") == 0)
        {
          discard_policy = CosNotification::PriorityOrder;
        }
        else if (ACE_OS::strcmp (discard, "lifo") == 0)
        {
          discard_policy = CosNotification::LifoOrder;
        }
        else if (ACE_OS::strcmp (discard, "deadline") == 0)
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
        "-d <any|fifo|lifo|priority|deadline> "
        "\n",
        argv [0]),
        -1);
  }
  // Indicates sucessful parsing of the command line
  return 0;
}


static CosNotifyChannelAdmin::ConsumerAdmin_ptr
create_consumeradmin (CosNotifyChannelAdmin::EventChannel_ptr ec)
{
  CosNotifyChannelAdmin::AdminID adminid = 0;
  CosNotifyChannelAdmin::ConsumerAdmin_var admin =
    ec->new_for_consumers (CosNotifyChannelAdmin::OR_OP,
    adminid);


  return CosNotifyChannelAdmin::ConsumerAdmin::_duplicate (admin.in ());
}


static void
create_consumers (CosNotifyChannelAdmin::ConsumerAdmin_ptr admin,
                  Notify_Test_Client* client)
{
  // startup the consumer
  ACE_NEW_THROW_EX (consumer_1,
    Notify_Sequence_Push_Consumer ("consumer1", discard_policy, *client, sent),
    CORBA::NO_MEMORY ());

  consumer_1->init (client->root_poa ());

  consumer_1->_connect (admin);
}

// ******************************************************************
// Main Section
// ******************************************************************

int main (int argc, char* argv[])
{
  int status = 0;
  try
  {
    Consumer_Client client;

    status = client.init (argc, argv);
    ACE_UNUSED_ARG(status);
    ACE_ASSERT(status == 0);

    CosNotifyChannelAdmin::EventChannel_var ec =
      client.create_event_channel ("MyEventChannel", 1);

    CORBA::ORB_ptr orb = client.orb ();
    CORBA::Object_var object =
      orb->string_to_object (ior);

    sig_var sig = sig::_narrow (object.in ());
    ACE_ASSERT(! CORBA::is_nil (sig.in ()));

    CosNotifyChannelAdmin::ConsumerAdmin_var admin =
      create_consumeradmin (ec.in ());
    ACE_ASSERT(!CORBA::is_nil (admin.in ()));

    create_consumers (admin.in (), &client);

    // Tell the supplier to go
    sig->go ();

    ACE_DEBUG((LM_DEBUG, "Consumer waiting for events...\n"));

    client.ORB_run( );

    ACE_DEBUG((LM_DEBUG, "Consumer done.\n"));
    consumer_1->disconnect();

    sig->done ();
  }
  catch (const CORBA::Exception& e)
  {
    e._tao_print_exception ("Error: ");
    status = 1;
  }

  return status;
}
