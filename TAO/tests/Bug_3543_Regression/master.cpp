// $Id$

#include "ace/Synch.h"
#include "ace/Task.h"
#include "masterS.h"
#include "tao/ORB.h"
#include "ace/Get_Opt.h"
#include "ace/OS_NS_unistd.h"
#include <list>
#include <sstream>
#include <iostream>

const ACE_TCHAR *ior_output_file = ACE_TEXT ("test.ior");
size_t number_of_servers = 300;
size_t steps = 10;

int
parse_args (int argc, ACE_TCHAR *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, ACE_TEXT("o:c:s:"));
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'o':
        ior_output_file = get_opts.opt_arg ();
        break;
      case 'c':
        number_of_servers = ACE_OS::atoi(get_opts.opt_arg ());
        break;
      case 's':
        steps = ACE_OS::atoi(get_opts.opt_arg ());
        break;

      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-o <ior> "
                           "-c <number of servers> "
                           "-s <steps> "
                           "\n",
                           argv [0]),
                          -1);
      }
  // Indicates sucessful parsing of the command line
  return 0;
}

static ACE_Thread_Mutex mutex;
std::list<MasterClient::Server_var> servers;
bool started = false;

class MasterImpl : public POA_MasterClient::Master
{
public:
  MasterImpl()
  {
  }

  virtual void registerServer(MasterClient::Server_ptr c)
  {
    ACE_GUARD(ACE_Thread_Mutex, mon, mutex);
    servers.push_back(MasterClient::Server::_duplicate(c));
    if (servers.size () == number_of_servers)
    {
      started = true;
    }
  }
};

void Dispatcher_shutdown(void)
{
    std::list<MasterClient::Server_var> copiedlist;
    {
      ACE_GUARD(ACE_Thread_Mutex, mon, mutex);
      copiedlist = servers;
    }
    std::list<MasterClient::Server_var>::iterator it;
    for(it = copiedlist.begin(); it != copiedlist.end(); ++it)
    {
      try
      {
        (*it)->shutdown();
      }
      catch(...)
      {
      }
    }
}

void Dispatcher_step(int id)
{
    std::list<MasterClient::Server_var> copiedlist;
    {
      ACE_GUARD(ACE_Thread_Mutex, mon, mutex);
      copiedlist = servers;
    }

    ACE_DEBUG ((LM_DEBUG, "Id %d Sending %d pings\n", id, copiedlist.size()));
    int ok = 0;
    int timeout = 0;
    int transient = 0;
    int corba = 0;
    int unknown = 0;

    std::list<MasterClient::Server_var>::iterator it;
    for(it = copiedlist.begin(); it != copiedlist.end(); ++it)
    {
      try
      {
        (*it)->ping();
        ++ok;
      }
      catch(CORBA::TIMEOUT &)
      {
          ++timeout;
      }
      catch(CORBA::TRANSIENT &)
      {
          ++transient;
      }
      catch(CORBA::Exception &e)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Caught CORBA exception %C", e._info ().c_str()));
          ++corba;
      }
      catch(...)
      {
          ++unknown;
      }
    }
    if(ok)
      {
        ACE_ERROR ((LM_ERROR, "Ok: %d\n", ok));
      }
    if(timeout)
      {
        ACE_ERROR ((LM_ERROR, "TIMEOUT: %d\n", timeout));
      }
    if(transient)
      {
        ACE_ERROR ((LM_ERROR, "TRANSIENT: %d\n", transient));
      }
    if(corba)
      {
        ACE_ERROR ((LM_ERROR, "CORBA: %d\n", corba));
      }
    if(unknown)
      {
        ACE_ERROR ((LM_ERROR, "UNKNOWN: %d\n", unknown));
      }
}

void Dispatcher_run(int id)
{
  size_t i = 0;
  while(1)
    {
      if(started)
        {
          Dispatcher_step(id);
          ++i;
        }
      if (i >= steps)
      {
        break;
      }
      ACE_OS::sleep(1);
    }
}

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  try
    {
      CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);

      if (parse_args (argc, argv) != 0)
        return 1;

      CORBA::Object_var poa_object =
        orb->resolve_initial_references("RootPOA");

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (poa_object.in ());

      if (CORBA::is_nil (root_poa.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Panic: nil RootPOA\n"),
                          1);

      PortableServer::POAManager_var poa_manager = root_poa->the_POAManager ();

      MasterImpl *hello_impl = 0;
      ACE_NEW_RETURN (hello_impl,
                      MasterImpl,
                      1);
      PortableServer::ServantBase_var owner_transfer(hello_impl);

      PortableServer::ObjectId_var id =
        root_poa->activate_object (hello_impl);

      CORBA::Object_var object = root_poa->id_to_reference (id.in ());

      MasterClient::Master_var hello = MasterClient::Master::_narrow (object.in ());

      poa_manager->activate ();

      CORBA::String_var ior = orb->object_to_string (hello.in ());

      // Output the IOR to the <ior_output_file>
      FILE *output_file= ACE_OS::fopen (ior_output_file, "w");
      if (output_file == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Cannot open output file for writing IOR: %s\n",
                           ior_output_file),
                           1);
      ACE_OS::fprintf (output_file, "%s", ior.in ());
      ACE_OS::fclose (output_file);

      ACE_Thread_Manager *thr_mgr = ACE_Thread_Manager::instance ();

      int N = 10;
      for(int i = 0; i < N; ++i)
        {
          thr_mgr->spawn_n (1, ACE_THR_FUNC (Dispatcher_run), reinterpret_cast<void *> (i), THR_NEW_LWP | THR_DETACHED);
        }

      orb->run();

      thr_mgr->wait ();

      Dispatcher_shutdown ();

      orb->destroy ();
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Exception caught:");
      return 1;
    }

  return 0;
}

