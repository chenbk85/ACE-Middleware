// -*- C++ -*-
// $Id$

#include "tao/ORB.h"
#include "tao/Object.h"
#include "tao/SystemException.h"
#include "tao/RTCORBA/RTCORBA.h"
#include "tao/Utils/PolicyList_Destroyer.h"
#include "ace/Log_Msg.h"
#include "ace/Thread.h"

#include "TestS.h"
#include "Client_Task.h"

class Test_i : public virtual POA_Test::Hello
{
public:
  Test_i(CORBA::ORB_ptr orb) : orb_(CORBA::ORB::_duplicate(orb))
  {
  }

  virtual ~Test_i()
  {
  }

  char * get_string()
  {
    return CORBA::string_dup("hello");
  }

  void shutdown()
  {
    orb_->shutdown(0);
  }

private:
  CORBA::ORB_var orb_;
};

RTCORBA::ThreadpoolId
createThreadpool(CORBA::ORB_ptr orb, RTCORBA::RTORB_ptr rtorb, CORBA::ULong nthreads)
{
  CORBA::Object_var obj = orb->resolve_initial_references("RTCurrent");
  RTCORBA::Current_var rtcurrent = RTCORBA::Current::_narrow(obj.in());

  CORBA::ULong const stacksize = 0; // default
  CORBA::ULong const minThreads = 1;
  CORBA::ULong const dynamicThreads = nthreads - minThreads;
  RTCORBA::Priority dfltThreadPrio = rtcurrent->the_priority();
  CORBA::Boolean const doBuffering = false;
  CORBA::ULong maxBufRequests = 0;
  CORBA::ULong maxReqBufSize = 0;

  RTCORBA::ThreadpoolId poolId;
  try
  {
    poolId = rtorb->create_threadpool(stacksize,
                                      minThreads,
                                      dynamicThreads,
                                      dfltThreadPrio,
                                      doBuffering,
                                      maxBufRequests,
                                      maxReqBufSize);
  }
  catch (const CORBA::SystemException &x)
  {
    ACE_PRINT_EXCEPTION(x, "creating thread pool");
    throw;
  }
  return poolId;
}

void destroyThreadpool(RTCORBA::RTORB_ptr rtorb, RTCORBA::ThreadpoolId id)
{
  rtorb->destroy_threadpool(id);
}

RTCORBA::RTORB_ptr getRTORB(CORBA::ORB_ptr orb, const char *id)
{
  CORBA::Object_var obj = orb->resolve_initial_references("RTORB");
  RTCORBA::RTORB_ptr rtorb = RTCORBA::RTORB::_narrow(obj.in());
  if ( CORBA::is_nil(rtorb))
    {
      ACE_ERROR ((LM_ERROR,
                  "Failed getting RTORB for orb <%s>\n",
                  id));
    }
  return rtorb;
}

PortableServer::POA_ptr getRootPoa(CORBA::ORB_ptr orb, const char *id)
{
  CORBA::Object_var obj = orb->resolve_initial_references("RootPOA");
  PortableServer::POA_ptr poa = PortableServer::POA::_narrow(obj.in());
  if ( CORBA::is_nil(poa) )
    {
      ACE_ERROR ((LM_ERROR,
                  "Failed getting RootPOA for orb <%s>\n",
                  id));
    }
  return poa;
}

const char*
addServant(
  CORBA::ORB_ptr orb,
  RTCORBA::RTORB_ptr rtorb,
  PortableServer::POA_ptr poa,
  PortableServer::ServantBase *servant,
  RTCORBA::ThreadpoolId& id,
  short nthreads)
{
  id = createThreadpool(orb, rtorb, nthreads);
  ACE_DEBUG ((LM_DEBUG,
              "Created threadpool with id <%d>\n",
              id));

  TAO::Utils::PolicyList_Destroyer policies (8);
  policies.length(8);
  CORBA::ULong i = 0;

  policies[i++] = poa->create_id_assignment_policy(PortableServer::SYSTEM_ID);
  policies[i++] = poa->create_id_uniqueness_policy(PortableServer::UNIQUE_ID);
  policies[i++] = poa->create_implicit_activation_policy(PortableServer::IMPLICIT_ACTIVATION);
  policies[i++] = poa->create_lifespan_policy(PortableServer::TRANSIENT);
  policies[i++] = poa->create_request_processing_policy(PortableServer::USE_ACTIVE_OBJECT_MAP_ONLY);
  policies[i++] = poa->create_servant_retention_policy(PortableServer::RETAIN);
  policies[i++] = poa->create_thread_policy(PortableServer::ORB_CTRL_MODEL);
  policies[i++] = rtorb->create_threadpool_policy(id);

  PortableServer::ObjectId_var dummy = poa->activate_object(servant);
  CORBA::Object_var ref = poa->servant_to_reference(servant);
  CORBA::String_var str = orb->object_to_string(ref.in ());

  return str._retn();
}

void
removeServant(
  RTCORBA::RTORB_ptr rtorb,
  PortableServer::POA_ptr poa,
  PortableServer::ServantBase *servant,
  RTCORBA::ThreadpoolId id)
{
  PortableServer::ObjectId_var oid = poa->servant_to_id(servant);
  poa->deactivate_object(oid);
  rtorb->destroy_threadpool(id);
  ACE_DEBUG ((LM_DEBUG,
              "Destroyed threadpool with id <%d>\n",
              id));
}

void shutdownORB(CORBA::ORB_ptr orb, const char * orbid)
{
  orb->shutdown(0);
  ACE_DEBUG ((LM_DEBUG,
              "ORB <%s> is shutdown\n",
              orbid));

  orb->destroy();
  ACE_DEBUG ((LM_DEBUG,
              "ORB <%s> is destoyed\n",
              orbid));
}

int write_iorfile (const char* ior_output_file, const char* ior)
{
  FILE *output_file= ACE_OS::fopen (ior_output_file, "w");
  if (output_file == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                        "Cannot open output file for writing IOR: %s\n",
                        ior_output_file),
                        1);
  ACE_OS::fprintf (output_file, "%s", ior);
  ACE_OS::fclose (output_file);

  return 0;
}


int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  try
  {
    const char *orbidA = "orbidA";
    const char *orbidB = "orbidB";

    CORBA::ORB_var orbA = CORBA::ORB_init(argc, argv, orbidA);

    PortableServer::ServantBase *implA = 0;
    PortableServer::ServantBase *implB = 0;
    RTCORBA::ThreadpoolId tpidA = 0;
    RTCORBA::ThreadpoolId tpidB = 0;

    // server - write our iors to two files
    CORBA::ORB_var orbB = CORBA::ORB_init(argc, argv, orbidB);
    RTCORBA::RTORB_var rtorbA = getRTORB(orbA.in (), orbidA);
    RTCORBA::RTORB_var rtorbB = getRTORB(orbB.in (), orbidB);

    PortableServer::POA_var rootPoaA = getRootPoa(orbA.in (), orbidA);
    PortableServer::POA_var rootPoaB = getRootPoa(orbB.in (), orbidB);

    rootPoaA->the_POAManager()->activate();
    rootPoaB->the_POAManager()->activate();

    implA = new Test_i(orbA.in ());
    implB = new Test_i(orbB.in ());

    const char* iorA = addServant(orbA.in (), rtorbA.in (), rootPoaA.in (), implA, tpidA, 3);
    const char* iorB = addServant(orbB.in (), rtorbB.in (), rootPoaB.in (), implB, tpidB, 3);

    if (write_iorfile("iorA.ior", iorA) == 1)
      return 1;

    if (write_iorfile("iorB.ior", iorB) == 1)
      return 1;

    // colocated calls work fine
    CORBA::Object_var objA = orbA->string_to_object(iorA);
    Test::Hello_var helloA(Test::Hello::_narrow(objA));
    CORBA::String_var resA = helloA->get_string();

    // note: orbA can convert iorB into a legal colocated object,
    // even though objB was created by orbB!
    CORBA::Object_var objB = orbA->string_to_object(iorB);
    Test::Hello_var helloB(Test::Hello::_narrow(objB.in ()));
    CORBA::String_var resB = helloB->get_string();

    cout << "server got resA: " << resA << " and resB: " << resB << endl;

    Client_Task client_taskA (orbA.in ());
    if (client_taskA.activate (THR_NEW_LWP | THR_JOINABLE, 1) == -1)
      {
        ACE_ERROR ((LM_ERROR, "Error activating client task\n"));
      }
    Client_Task client_taskB (orbB.in ());
    if (client_taskB.activate (THR_NEW_LWP | THR_JOINABLE, 1) == -1)
      {
        ACE_ERROR ((LM_ERROR, "Error activating client task\n"));
      }
    client_taskA.thr_mgr ()->wait ();

    if (implB != 0)
      {
        removeServant(rtorbB.in (), rootPoaB.in (), implB, tpidB);
      }

    shutdownORB(orbB.in (), orbidB);

    if (implA != 0)
      {
        removeServant(rtorbA.in (), rootPoaA.in (), implA, tpidA);
      }

    shutdownORB(orbA.in (), orbidA);
  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception ("Caught unexpected exception:");
    ACE_ERROR ((LM_ERROR,  "Bug_2953_Regression failed.\n"));
    return 1;
  }

  ACE_DEBUG ((LM_DEBUG, "Bug_2953_Regression server ended successfully.\n"));

  return 0;
}
