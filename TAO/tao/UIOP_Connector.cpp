// This may look like C, but it's really -*- C++ -*-
// $Id$


#include "tao/UIOP_Connector.h"

#if TAO_HAS_UIOP == 1

#include "tao/UIOP_Profile.h"
#include "tao/debug.h"
#include "tao/ORB_Core.h"
#include "tao/Environment.h"
#include "ace/Auto_Ptr.h"
#include "tao/RT_Policy_i.h"

ACE_RCSID(tao, UIOP_Connector, "$Id$")

#if defined (TAO_USES_ROBUST_CONNECTION_MGMT)
int
TAO_UIOP_Connector::purge_connections (void)
{
  return this->cached_connect_strategy_->purge_connections ();
}

#define TAO_HANDLER TAO_UIOP_Client_Connection_Handler
#define TAO_SVC_TUPLE ACE_Svc_Tuple<TAO_HANDLER>
#define TAO_ADDR TAO_UIOP_Connector::TAO_IADDR
#define TAO_HASH_KEY TAO_UIOP_Connector::TAO_HASH_KEY
#define TAO_COMPARE_KEYS TAO_UIOP_Connector::TAO_COMPARE_KEYS
#define TAO_ATTRIBUTES TAO_UIOP_Connector::TAO_ATTRIBUTES
#define TAO_CACHED_HANDLER TAO_UIOP_Connector::TAO_CACHED_HANDLER
#define TAO_HASH_MAP TAO_UIOP_Connector::TAO_HASH_MAP
#define TAO_HASH_MAP_ITERATOR TAO_UIOP_Connector::TAO_HASH_MAP_ITERATOR
#define TAO_HASH_MAP_REVERSE_ITERATOR TAO_UIOP_Connector::TAO_HASH_MAP_REVERSE_ITERATOR
#define TAO_CACHING_UTILITY TAO_UIOP_Connector::TAO_CACHING_UTILITY
#define TAO_CACHING_STRATEGY TAO_UIOP_Connector::TAO_CACHING_STRATEGY
#define TAO_CACHED_CONNECT_STRATEGY TAO_UIOP_Connector::TAO_CACHED_CONNECT_STRATEGY

typedef ACE_LRU_Caching_Strategy<TAO_ATTRIBUTES, TAO_CACHING_UTILITY>
        TAO_UIOP_LRU_CACHING_STRATEGY;

#if defined (ACE_HAS_BROKEN_EXTENDED_TEMPLATES) || (TAO_HAS_MINIMUM_CONNECTION_CACHING_STRATEGY == 1)
typedef TAO_UIOP_LRU_CACHING_STRATEGY
        TAO_UIOP_CACHING_STRATEGY;
#else
#if (TAO_HAS_MINIMUM_CONNECTION_CACHING_STRATEGY == 0)
typedef ACE_Caching_Strategy<TAO_ATTRIBUTES, TAO_CACHING_UTILITY>
        TAO_UIOP_CACHING_STRATEGY;
typedef ACE_LFU_Caching_Strategy<TAO_ATTRIBUTES, TAO_CACHING_UTILITY>
        TAO_UIOP_LFU_CACHING_STRATEGY;
typedef ACE_FIFO_Caching_Strategy<TAO_ATTRIBUTES, TAO_CACHING_UTILITY>
        TAO_UIOP_FIFO_CACHING_STRATEGY;
typedef ACE_Null_Caching_Strategy<TAO_ATTRIBUTES, TAO_CACHING_UTILITY>
        TAO_UIOP_NULL_CACHING_STRATEGY;
typedef ACE_Caching_Strategy_Adapter<TAO_ATTRIBUTES, TAO_CACHING_UTILITY, TAO_UIOP_LRU_CACHING_STRATEGY>
        TAO_UIOP_LRU_CACHING_STRATEGY_ADAPTER;
typedef ACE_Caching_Strategy_Adapter<TAO_ATTRIBUTES, TAO_CACHING_UTILITY, TAO_UIOP_LFU_CACHING_STRATEGY>
        TAO_UIOP_LFU_CACHING_STRATEGY_ADAPTER;
typedef ACE_Caching_Strategy_Adapter<TAO_ATTRIBUTES, TAO_CACHING_UTILITY, TAO_UIOP_FIFO_CACHING_STRATEGY>
        TAO_UIOP_FIFO_CACHING_STRATEGY_ADAPTER;
typedef ACE_Caching_Strategy_Adapter<TAO_ATTRIBUTES, TAO_CACHING_UTILITY, TAO_UIOP_NULL_CACHING_STRATEGY>
        TAO_UIOP_NULL_CACHING_STRATEGY_ADAPTER;
#endif /* TAO_HAS_MINIMUM_CONNECTION_CACHING_STRATEGY = 0*/
#endif /* ACE_HAS_BROKEN_EXTENDED_TEMPLATES
          TAO_HAS_MINIMUM_CONNECTION_CACHING_STRATEGY == 1*/

int
TAO_UIOP_Connector::make_caching_strategy (void)
{

  TAO_Resource_Factory *resource_factory =
    this->orb_core_->resource_factory ();

#if defined (ACE_HAS_BROKEN_EXTENDED_TEMPLATES) || (TAO_HAS_MINIMUM_CONNECTION_CACHING_STRATEGY == 1)
  ACE_NEW_RETURN (this->caching_strategy_,
                  TAO_UIOP_CACHING_STRATEGY,
                  -1);
#else
#if (TAO_HAS_MINIMUM_CONNECTION_CACHING_STRATEGY == 0)
  switch (resource_factory->connection_caching_strategy_type ())
    {
    case TAO_Resource_Factory::NOOP:
      ACE_NEW_RETURN (this->caching_strategy_,
                      TAO_UIOP_NULL_CACHING_STRATEGY_ADAPTER,
                      -1);
      break;

    default:
    case TAO_Resource_Factory::LRU:
      ACE_NEW_RETURN (this->caching_strategy_,
                      TAO_UIOP_LRU_CACHING_STRATEGY_ADAPTER,
                      -1);
      break;

    case TAO_Resource_Factory::LFU:
      ACE_NEW_RETURN (this->caching_strategy_,
                      TAO_UIOP_LFU_CACHING_STRATEGY_ADAPTER,
                      -1);
      break;

    case TAO_Resource_Factory::FIFO:
      ACE_NEW_RETURN (this->caching_strategy_,
                      TAO_UIOP_FIFO_CACHING_STRATEGY_ADAPTER,
                      -1);
      break;
    }
#endif /* TAO_HAS_MINIMUM_CONNECTION_CACHING_STRATEGY == 0*/
#endif /* ACE_HAS_BROKEN_EXTENDED_TEMPLATES
          TAO_HAS_MINIMUM_CONNECTION_CACHING_STRATEGY == 1*/

  this->caching_strategy_->purge_percent (resource_factory->purge_percentage ());
  return 0;
}
#endif /* TAO_USES_ROBUST_CONNECTION_MGMT */

// The TAO_Cached_Connector_Lock template instantiations are in
// Resource_Factory.cpp.

#if !defined (TAO_USES_ROBUST_CONNECTION_MGMT)
#define TAO_SVC_TUPLE ACE_Svc_Tuple<TAO_UIOP_Client_Connection_Handler>
#define CACHED_CONNECT_STRATEGY ACE_Cached_Connect_Strategy<TAO_UIOP_Client_Connection_Handler, ACE_LSOCK_CONNECTOR, TAO_Cached_Connector_Lock>
#define TAO_ADDR ACE_Refcounted_Hash_Recyclable<ACE_UNIX_Addr>
#define TAO_HANDLER TAO_UIOP_Client_Connection_Handler
#define TAO_HASH_KEY ACE_Hash<TAO_ADDR>
#define TAO_COMPARE_KEYS ACE_Equal_To<TAO_ADDR>
#endif /* TAO_USES_ROBUST_CONNECTION_MGMT */

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION) || \
    defined (ACE_HAS_GNU_REPO)

template class ACE_Auto_Basic_Array_Ptr<ACE_UNIX_Addr>;
template class ACE_Auto_Basic_Array_Ptr<TAO_UIOP_Client_Connection_Handler*>;
template class auto_ptr<TAO_UIOP_Connect_Creation_Strategy>;
template class ACE_Auto_Basic_Ptr<TAO_UIOP_Connect_Creation_Strategy>;

template class ACE_Node<ACE_UNIX_Addr>;
template class ACE_Unbounded_Stack<ACE_UNIX_Addr>;
template class ACE_Unbounded_Stack_Iterator<ACE_UNIX_Addr>;

#if !defined (TAO_USES_ROBUST_CONNECTION_MGMT)
template class CACHED_CONNECT_STRATEGY;
template class TAO_ADDR;
#endif /* TAO_USES_ROBUST_CONNECTION_MGMT */

template class ACE_Svc_Handler<ACE_LSOCK_STREAM, ACE_NULL_SYNCH>;
template class ACE_Refcounted_Hash_Recyclable<ACE_UNIX_Addr>;
template class ACE_NOOP_Creation_Strategy<TAO_HANDLER>;
template class ACE_Concurrency_Strategy<TAO_HANDLER>;
template class ACE_Connect_Strategy<TAO_HANDLER, ACE_LSOCK_CONNECTOR>;
template class ACE_Connector<TAO_HANDLER, ACE_LSOCK_CONNECTOR>;
template class ACE_Creation_Strategy<TAO_HANDLER>;
template class ACE_Hash_Map_Entry<TAO_ADDR, TAO_HANDLER *>;
template class ACE_Hash<ACE_Refcounted_Hash_Recyclable<ACE_UNIX_Addr> >;
template class ACE_Equal_To<ACE_Refcounted_Hash_Recyclable<ACE_UNIX_Addr> >;
template class ACE_Map_Entry<ACE_HANDLE, TAO_SVC_TUPLE *>;
template class ACE_Map_Manager<ACE_HANDLE, TAO_SVC_TUPLE *, ACE_SYNCH_RW_MUTEX>;
template class ACE_Map_Iterator_Base<ACE_HANDLE, TAO_SVC_TUPLE *, ACE_SYNCH_RW_MUTEX>;
template class ACE_Map_Iterator<ACE_HANDLE, TAO_SVC_TUPLE *, ACE_SYNCH_RW_MUTEX>;
template class ACE_Map_Reverse_Iterator<ACE_HANDLE, TAO_SVC_TUPLE *, ACE_SYNCH_RW_MUTEX>;
template class ACE_NOOP_Concurrency_Strategy<TAO_HANDLER>;
template class ACE_Recycling_Strategy<TAO_HANDLER>;
template class ACE_Strategy_Connector<TAO_HANDLER, ACE_LSOCK_CONNECTOR>;
template class TAO_SVC_TUPLE;

template class ACE_Hash_Map_Manager<TAO_ADDR, TAO_HANDLER *, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator<TAO_ADDR, TAO_HANDLER *, ACE_Null_Mutex>;
template class ACE_Hash_Map_Reverse_Iterator<TAO_ADDR, TAO_HANDLER *, ACE_Null_Mutex>;
template class ACE_Hash_Map_Manager_Ex<TAO_ADDR, TAO_HANDLER *, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator_Ex<TAO_ADDR, TAO_HANDLER *, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>;
template class ACE_Hash_Map_Reverse_Iterator_Ex<TAO_ADDR, TAO_HANDLER *, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator_Base_Ex<TAO_ADDR, TAO_HANDLER *, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>;
template class ACE_Hash_Map_Bucket_Iterator<TAO_ADDR, TAO_HANDLER *, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>;

#if defined (TAO_USES_ROBUST_CONNECTION_MGMT)
template class ACE_Pair<TAO_HANDLER *, TAO_ATTRIBUTES>;
template class ACE_Reference_Pair<TAO_ADDR, TAO_HANDLER *>;
template class ACE_Hash_Map_Entry<TAO_ADDR, TAO_CACHED_HANDLER>;

template class ACE_Hash_Map_Manager<TAO_ADDR, TAO_CACHED_HANDLER, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator<TAO_ADDR, TAO_CACHED_HANDLER, ACE_Null_Mutex>;
template class ACE_Hash_Map_Reverse_Iterator<TAO_ADDR, TAO_CACHED_HANDLER, ACE_Null_Mutex>;
template class ACE_Hash_Map_Manager_Ex<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator_Ex<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>;
template class ACE_Hash_Map_Reverse_Iterator_Ex<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator_Base_Ex<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>;
template class ACE_Hash_Map_Bucket_Iterator<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>;

// = Caching_Strategy
template class ACE_Hash_Cache_Map_Manager<TAO_ADDR, TAO_HANDLER *, TAO_HASH_KEY, TAO_COMPARE_KEYS, TAO_CACHING_STRATEGY, TAO_ATTRIBUTES>;

template class ACE_LRU_Caching_Strategy<TAO_ATTRIBUTES, TAO_CACHING_UTILITY>;

#if !defined (ACE_HAS_BROKEN_EXTENDED_TEMPLATES)
#if (TAO_HAS_MINIMUM_CONNECTION_CACHING_STRATEGY == 0)

template class ACE_Caching_Strategy<TAO_ATTRIBUTES, TAO_CACHING_UTILITY>;
template class ACE_LFU_Caching_Strategy<TAO_ATTRIBUTES, TAO_CACHING_UTILITY>;
template class ACE_FIFO_Caching_Strategy<TAO_ATTRIBUTES, TAO_CACHING_UTILITY>;
template class ACE_Null_Caching_Strategy<TAO_ATTRIBUTES, TAO_CACHING_UTILITY>;

template class ACE_Caching_Strategy_Adapter<TAO_ATTRIBUTES, TAO_CACHING_UTILITY, TAO_UIOP_LRU_CACHING_STRATEGY>;
template class ACE_Caching_Strategy_Adapter<TAO_ATTRIBUTES, TAO_CACHING_UTILITY, TAO_UIOP_LFU_CACHING_STRATEGY>;
template class ACE_Caching_Strategy_Adapter<TAO_ATTRIBUTES, TAO_CACHING_UTILITY, TAO_UIOP_FIFO_CACHING_STRATEGY>;
template class ACE_Caching_Strategy_Adapter<TAO_ATTRIBUTES, TAO_CACHING_UTILITY, TAO_UIOP_NULL_CACHING_STRATEGY>;

template class ACE_Cache_Map_Manager<TAO_ADDR, TAO_HANDLER *, TAO_HASH_MAP, TAO_HASH_MAP_ITERATOR, TAO_HASH_MAP_REVERSE_ITERATOR, TAO_CACHING_STRATEGY, TAO_ATTRIBUTES>;
template class ACE_Cache_Map_Iterator<TAO_ADDR, TAO_HANDLER *, TAO_HASH_MAP_ITERATOR, TAO_CACHING_STRATEGY, TAO_ATTRIBUTES>;
template class ACE_Cache_Map_Reverse_Iterator<TAO_ADDR, TAO_HANDLER *, TAO_HASH_MAP_REVERSE_ITERATOR, TAO_CACHING_STRATEGY, TAO_ATTRIBUTES>;
#endif /*TAO_HAS_MINIMUM_CONNECTION_CACHING_STRATEGY == 0*/
#else

template class ACE_Cache_Map_Manager<TAO_ADDR, TAO_HANDLER *, TAO_HASH_MAP, TAO_CACHING_STRATEGY, TAO_ATTRIBUTES>;

#endif /* ACE_HAS_BROKEN_EXTENDED_TEMPLATES
          TAO_HAS_MINIMUM_CONNECTION_CACHING_STRATEGY == 0*/

template class ACE_Cached_Connect_Strategy_Ex<TAO_HANDLER, ACE_LSOCK_CONNECTOR, TAO_CACHING_STRATEGY, TAO_ATTRIBUTES, TAO_Cached_Connector_Lock>;
template class ACE_Cached_Connect_Strategy<TAO_HANDLER, ACE_LSOCK_CONNECTOR, TAO_Cached_Connector_Lock>;

template class ACE_Cleanup_Strategy<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_MAP>;
template class ACE_Refcounted_Recyclable_Handler_Cleanup_Strategy<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_MAP>;
template class ACE_Refcounted_Recyclable_Handler_Caching_Utility<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_MAP, TAO_HASH_MAP_ITERATOR, TAO_ATTRIBUTES>;
#endif /* TAO_USES_ROBUST_CONNECTION_MGMT */

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Auto_Basic_Array_Ptr<ACE_UNIX_Addr>
#pragma instantiate ACE_Auto_Basic_Array_Ptr<TAO_UIOP_Client_Connection_Handler*>
#pragma instantiate auto_ptr<TAO_UIOP_Connect_Creation_Strategy>
#pragma instantiate ACE_Auto_Basic_Ptr<TAO_UIOP_Connect_Creation_Strategy>

#pragma instantiate ACE_Node<ACE_UNIX_Addr>
#pragma instantiate ACE_Unbounded_Stack<ACE_UNIX_Addr>
#pragma instantiate ACE_Unbounded_Stack_Iterator<ACE_UNIX_Addr>

#if !defined (TAO_USES_ROBUST_CONNECTION_MGMT)
#pragma instantiate CACHED_CONNECT_STRATEGY
#pragma instantiate TAO_ADDR
#endif /* TAO_USES_ROBUST_CONNECTION_MGMT */

#pragma instantiate ACE_Svc_Handler<ACE_LSOCK_STREAM, ACE_NULL_SYNCH>
#pragma instantiate ACE_Refcounted_Hash_Recyclable<ACE_UNIX_Addr>
#pragma instantiate ACE_NOOP_Creation_Strategy<TAO_HANDLER>
#pragma instantiate ACE_Concurrency_Strategy<TAO_HANDLER>
#pragma instantiate ACE_Connect_Strategy<TAO_HANDLER, ACE_LSOCK_CONNECTOR>
#pragma instantiate ACE_Connector<TAO_HANDLER, ACE_LSOCK_CONNECTOR>
#pragma instantiate ACE_Creation_Strategy<TAO_HANDLER>
#pragma instantiate ACE_Hash_Map_Entry<TAO_ADDR, TAO_HANDLER *>
#pragma instantiate ACE_Hash<ACE_Refcounted_Hash_Recyclable<ACE_UNIX_Addr> >
#pragma instantiate ACE_Equal_To<ACE_Refcounted_Hash_Recyclable<ACE_UNIX_Addr> >
#pragma instantiate ACE_Map_Entry<ACE_HANDLE, TAO_SVC_TUPLE *>
#pragma instantiate ACE_Map_Manager<ACE_HANDLE, TAO_SVC_TUPLE *, ACE_SYNCH_RW_MUTEX>
#pragma instantiate ACE_Map_Iterator_Base<ACE_HANDLE, TAO_SVC_TUPLE *, ACE_SYNCH_RW_MUTEX>
#pragma instantiate ACE_Map_Iterator<ACE_HANDLE, TAO_SVC_TUPLE *, ACE_SYNCH_RW_MUTEX>
#pragma instantiate ACE_Map_Reverse_Iterator<ACE_HANDLE, TAO_SVC_TUPLE *, ACE_SYNCH_RW_MUTEX>
#pragma instantiate ACE_NOOP_Concurrency_Strategy<TAO_HANDLER>
#pragma instantiate ACE_Recycling_Strategy<TAO_HANDLER>
#pragma instantiate ACE_Strategy_Connector<TAO_HANDLER, ACE_LSOCK_CONNECTOR>
#pragma instantiate TAO_SVC_TUPLE

#pragma instantiate ACE_Hash_Map_Manager<TAO_ADDR, TAO_HANDLER *, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator<TAO_ADDR, TAO_HANDLER *, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator<TAO_ADDR, TAO_HANDLER *, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Manager_Ex<TAO_ADDR, TAO_HANDLER *, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator_Ex<TAO_ADDR, TAO_HANDLER *, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator_Ex<TAO_ADDR, TAO_HANDLER *, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator_Base_Ex<TAO_ADDR, TAO_HANDLER *, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Bucket_Iterator<TAO_ADDR, TAO_HANDLER *, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>

#if defined (TAO_USES_ROBUST_CONNECTION_MGMT)
#pragma instantiate ACE_Pair<TAO_HANDLER *, TAO_ATTRIBUTES>
#pragma instantiate ACE_Reference_Pair<TAO_ADDR, TAO_HANDLER *>
#pragma instantiate ACE_Hash_Map_Entry<TAO_ADDR, TAO_CACHED_HANDLER>

#pragma instantiate ACE_Hash_Map_Manager<TAO_ADDR, TAO_CACHED_HANDLER, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator<TAO_ADDR, TAO_CACHED_HANDLER, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator<TAO_ADDR, TAO_CACHED_HANDLER, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Manager_Ex<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator_Ex<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator_Ex<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator_Base_Ex<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Bucket_Iterator<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_KEY, TAO_COMPARE_KEYS, ACE_Null_Mutex>

// = Caching_Strategy
#pragma instantiate ACE_Hash_Cache_Map_Manager<TAO_ADDR, TAO_HANDLER *, TAO_HASH_KEY, TAO_COMPARE_KEYS, TAO_CACHING_STRATEGY, TAO_ATTRIBUTES>

#pragma instantiate ACE_LRU_Caching_Strategy<TAO_ATTRIBUTES, TAO_CACHING_UTILITY>

#if !defined (ACE_HAS_BROKEN_EXTENDED_TEMPLATES)
#if (TAO_HAS_MINIMUM_CONNECTION_CACHING_STRATEGY == 0)

#pragma instantiate ACE_Caching_Strategy<TAO_ATTRIBUTES, TAO_CACHING_UTILITY>
#pragma instantiate ACE_LFU_Caching_Strategy<TAO_ATTRIBUTES, TAO_CACHING_UTILITY>
#pragma instantiate ACE_FIFO_Caching_Strategy<TAO_ATTRIBUTES, TAO_CACHING_UTILITY>
#pragma instantiate ACE_Null_Caching_Strategy<TAO_ATTRIBUTES, TAO_CACHING_UTILITY>

#pragma instantiate ACE_Caching_Strategy_Adapter<TAO_ATTRIBUTES, TAO_CACHING_UTILITY, TAO_UIOP_LRU_CACHING_STRATEGY>
#pragma instantiate ACE_Caching_Strategy_Adapter<TAO_ATTRIBUTES, TAO_CACHING_UTILITY, TAO_UIOP_LFU_CACHING_STRATEGY>
#pragma instantiate ACE_Caching_Strategy_Adapter<TAO_ATTRIBUTES, TAO_CACHING_UTILITY, TAO_UIOP_FIFO_CACHING_STRATEGY>
#pragma instantiate ACE_Caching_Strategy_Adapter<TAO_ATTRIBUTES, TAO_CACHING_UTILITY, TAO_UIOP_NULL_CACHING_STRATEGY>

#pragma instantiate ACE_Cache_Map_Manager<TAO_ADDR, TAO_HANDLER *, TAO_HASH_MAP, TAO_HASH_MAP_ITERATOR, TAO_HASH_MAP_REVERSE_ITERATOR, TAO_CACHING_STRATEGY, TAO_ATTRIBUTES>
#pragma instantiate ACE_Cache_Map_Iterator<TAO_ADDR, TAO_HANDLER *, TAO_HASH_MAP_ITERATOR, TAO_CACHING_STRATEGY, TAO_ATTRIBUTES>
#pragma instantiate ACE_Cache_Map_Reverse_Iterator<TAO_ADDR, TAO_HANDLER *, TAO_HASH_MAP_REVERSE_ITERATOR, TAO_CACHING_STRATEGY, TAO_ATTRIBUTES>

#endif /*TAO_HAS_MINIMUM_CONNECTION_CACHING_STRATEGY == 0*/
#else

#pragma instantiate ACE_Cache_Map_Manager<TAO_ADDR, TAO_HANDLER *, TAO_HASH_MAP, TAO_CACHING_STRATEGY, TAO_ATTRIBUTES>

#endif /* ACE_HAS_BROKEN_EXTENDED_TEMPLATES
          TAO_HAS_MINIMUM_CONNECTION_CACHING_STRATEGY == 0*/

#pragma instantiate ACE_Cached_Connect_Strategy_Ex<TAO_HANDLER, ACE_LSOCK_CONNECTOR, TAO_CACHING_STRATEGY, TAO_ATTRIBUTES, TAO_Cached_Connector_Lock>
#pragma instantiate ACE_Cached_Connect_Strategy<TAO_HANDLER, ACE_LSOCK_CONNECTOR, TAO_Cached_Connector_Lock>

#pragma instantiate ACE_Cleanup_Strategy<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_MAP>
#pragma instantiate ACE_Refcounted_Recyclable_Handler_Cleanup_Strategy<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_MAP>
#pragma instantiate ACE_Refcounted_Recyclable_Handler_Caching_Utility<TAO_ADDR, TAO_CACHED_HANDLER, TAO_HASH_MAP, TAO_HASH_MAP_ITERATOR, TAO_ATTRIBUTES>
#endif /* TAO_USES_ROBUST_CONNECTION_MGMT */

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

TAO_UIOP_Connect_Creation_Strategy::
  TAO_UIOP_Connect_Creation_Strategy (ACE_Thread_Manager* t,
                                      TAO_ORB_Core* orb_core,
                                      void *arg,
                                      CORBA::Boolean flag)
    :  ACE_Creation_Strategy<TAO_UIOP_Client_Connection_Handler> (t),
       orb_core_ (orb_core),
       arg_ (arg),
       lite_flag_ (flag)
{
}

int
TAO_UIOP_Connect_Creation_Strategy::make_svc_handler
  (TAO_UIOP_Client_Connection_Handler *&sh)
{
  if (sh == 0)
    ACE_NEW_RETURN (sh,
                    TAO_UIOP_Client_Connection_Handler
                    (this->orb_core_->thr_mgr (),
                     this->orb_core_,
                     this->lite_flag_,
                     this->arg_),
                    -1);
  return 0;
}

#if !defined (TAO_USES_ROBUST_CONNECTION_MGMT)
typedef ACE_Cached_Connect_Strategy<TAO_UIOP_Client_Connection_Handler,
                                    ACE_LSOCK_CONNECTOR,
                                    TAO_Cached_Connector_Lock>
        TAO_CACHED_CONNECT_STRATEGY;
#endif /* ! TAO_USES_ROBUST_CONNECTION_MGMT */

TAO_UIOP_Connector::TAO_UIOP_Connector (CORBA::Boolean flag)
  : TAO_Connector (TAO_TAG_UIOP_PROFILE),
    base_connector_ (),
    orb_core_ (0),
    lite_flag_ (flag)
#if defined (TAO_USES_ROBUST_CONNECTION_MGMT)
    ,
    cached_connect_strategy_ (0),
    caching_strategy_ (0)
#endif /* TAO_USES_ROBUST_CONNECTION_MGMT */
{
}

int
TAO_UIOP_Connector::open (TAO_ORB_Core *orb_core)
{
  this->orb_core_ = orb_core;

#if defined (TAO_USES_ROBUST_CONNECTION_MGMT)
  if (this->make_caching_strategy () == -1)
    return -1;
#endif /* TAO_USES_ROBUST_CONNECTION_MGMT */

  if (this->init_uiop_properties () != 0)
    return -1;

  TAO_UIOP_Connect_Creation_Strategy *connect_creation_strategy = 0;
  ACE_NEW_RETURN (connect_creation_strategy,
                  TAO_UIOP_Connect_Creation_Strategy
                  (this->orb_core_->thr_mgr (),
                   this->orb_core_,
                   &(this->uiop_properties_),
                   this->lite_flag_),
                  -1);

  auto_ptr<TAO_UIOP_Connect_Creation_Strategy>
    new_connect_creation_strategy (connect_creation_strategy);

  TAO_Cached_Connector_Lock *connector_lock = 0;
  ACE_NEW_RETURN (connector_lock,
                  TAO_Cached_Connector_Lock (orb_core),
                  -1);

  auto_ptr<TAO_Cached_Connector_Lock> new_connector_lock (connector_lock);

#if defined (TAO_USES_ROBUST_CONNECTION_MGMT)
  ACE_NEW_RETURN (this->cached_connect_strategy_,
                  TAO_CACHED_CONNECT_STRATEGY (*this->caching_strategy_,
                                               new_connect_creation_strategy.get (),
                                               0,
                                               0,
                                               new_connector_lock.get (),
                                               1),
                  -1);
#else /* TAO_USES_ROBUST_CONNECTION_MGMT */
  TAO_CACHED_CONNECT_STRATEGY *cached_connect_strategy = 0;
  ACE_NEW_RETURN (cached_connect_strategy,
                  TAO_CACHED_CONNECT_STRATEGY
                  (new_connect_creation_strategy.get (),
                   0,
                   0,
                   new_connector_lock.get (),
                   1),
                  -1);
#endif /* TAO_USES_ROBUST_CONNECTION_MGMT */

  // Finally everything is fine.  Make sure to take ownership away
  // from the auto pointer.
  connect_creation_strategy =
    new_connect_creation_strategy.release ();
  connector_lock =
    new_connector_lock.release ();

#if defined (TAO_USES_ROBUST_CONNECTION_MGMT)
  return this->base_connector_.open (this->orb_core_->reactor (),
                                     &this->null_creation_strategy_,
                                     this->cached_connect_strategy_,
                                     &this->null_activation_strategy_);
#else /* TAO_USES_ROBUST_CONNECTION_MGMT */
  return this->base_connector_.open (this->orb_core_->reactor (),
                                     &this->null_creation_strategy_,
                                     cached_connect_strategy,
                                     &this->null_activation_strategy_);
#endif /* TAO_USES_ROBUST_CONNECTION_MGMT */
}

int
TAO_UIOP_Connector::close (void)
{
  this->base_connector_.close ();

  // Zap the creation strategy that we created earlier.
#if defined (TAO_USES_ROBUST_CONNECTION_MGMT)
  delete this->cached_connect_strategy_->creation_strategy ();
  delete this->cached_connect_strategy_;
  delete this->caching_strategy_;
#else /* TAO_USES_ROBUST_CONNECTION_MGMT */
  TAO_CACHED_CONNECT_STRATEGY *cached_connect_strategy =
    ACE_dynamic_cast (TAO_CACHED_CONNECT_STRATEGY *,
                      this->base_connector_.connect_strategy ());

  delete cached_connect_strategy->creation_strategy ();
  delete cached_connect_strategy;
#endif /* TAO_USES_ROBUST_CONNECTION_MGMT */

  return 0;
}

int
TAO_UIOP_Connector::connect (TAO_Endpoint *endpoint,
                             TAO_Transport *& transport,
                             ACE_Time_Value *max_wait_time,
                             CORBA::Environment &)
{
  if (TAO_debug_level > 0)
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("TAO (%P|%t) Connector::connect - ")
                  ACE_TEXT ("looking for UIOP connection.\n")));

  if (endpoint->tag () != TAO_TAG_UIOP_PROFILE)
    return -1;

  TAO_UIOP_Endpoint *uiop_endpoint =
    ACE_dynamic_cast (TAO_UIOP_Endpoint *,
                      endpoint);
  if (uiop_endpoint == 0)
    return -1;

  const ACE_UNIX_Addr &remote_address =
    uiop_endpoint->object_addr ();

  // @@ Note, POSIX.1g renames AF_UNIX to AF_LOCAL.

  // Verify that the remote ACE_UNIX_Addr was initialized properly.
  // Failure should never occur in the case of an ACE_UNIX_Addr!
  if (remote_address.get_type () != AF_UNIX)
    return -1;

  TAO_UIOP_Client_Connection_Handler *svc_handler = 0;
  int result = 0;

  if (max_wait_time != 0)
    {
      ACE_Synch_Options synch_options (ACE_Synch_Options::USE_TIMEOUT,
                                       *max_wait_time);

      // The connect call will set the hint () stored in the Endpoint
      // object; but we obtain the transport in the <svc_handler>
      // variable. Other threads may modify the hint, but we are not
      // affected.
      result = this->base_connector_.connect (uiop_endpoint->hint (),
                                              svc_handler,
                                              remote_address,
                                              synch_options);
    }
  else
    {
      // The connect call will set the hint () stored in the Endpoint
      // object; but we obtain the transport in the <svc_handler>
      // variable. Other threads may modify the hint, but we are not
      // affected.
      result = this->base_connector_.connect (uiop_endpoint->hint (),
                                              svc_handler,
                                              remote_address);
    }

  if (result == -1)
    {
      // Give users a clue to the problem.
      if (TAO_orbdebug)
        {
          ACE_DEBUG ((LM_ERROR,
                      ACE_TEXT ("(%P|%t) %s:%u, connection to ")
                      ACE_TEXT ("%s failed (%p)\n"),
                      __FILE__,
                      __LINE__,
                      uiop_endpoint->rendezvous_point (),
                      "errno"));
        }

      return -1;
    }

  transport = svc_handler->transport ();

  return 0;
}

int
TAO_UIOP_Connector::preconnect (const char *preconnects)
{
  // Check for the proper protocol prefix.
  if (this->check_prefix (preconnects) != 0)
    return 0; // Failure: zero successful preconnections

  const char *protocol_removed =
    ACE_OS::strstr (preconnects, "://") + 3;
  // "+ 3" since strlen of "://" is 3.

  char *preconnections =
    ACE_OS::strdup (protocol_removed);

  int successes = 0;
  if (preconnections)
    {
      ACE_UNIX_Addr dest;
      ACE_Unbounded_Stack<ACE_UNIX_Addr> dests;

      size_t num_connections;

      char *nextptr = 0;
      char *where = 0;

      for (where = ACE::strsplit_r (preconnections, ",", nextptr);
           where != 0;
           where = ACE::strsplit_r (0, ",", nextptr))
        {
          char *rendezvous_point = where;

          int version_offset = 0;
          // Additional offset to remove version from preconnect, if
          // it exists.

          if (isdigit (rendezvous_point[0]) &&
              rendezvous_point[1] == '.' &&
              isdigit (rendezvous_point[2]) &&
              rendezvous_point[3] == '@')
            version_offset = 4;

          // @@ For now, we just drop the version prefix.  However, at
          // some point in the future the version may become useful.

          dest.set (rendezvous_point + version_offset);

          dests.push (dest);
        }

      // Create an array of addresses from the stack, as well as an
      // array of eventual handlers.
      num_connections = dests.size ();
      ACE_UNIX_Addr *remote_addrs = 0;
      TAO_UIOP_Client_Connection_Handler **handlers = 0;
      char *failures = 0;

      ACE_NEW_RETURN (remote_addrs,
                      ACE_UNIX_Addr[num_connections],
                      -1);

      ACE_Auto_Basic_Array_Ptr<ACE_UNIX_Addr> safe_remote_addrs (remote_addrs);

      ACE_NEW_RETURN (handlers,
                      TAO_UIOP_Client_Connection_Handler *[num_connections],
                      -1);

      ACE_Auto_Basic_Array_Ptr<TAO_UIOP_Client_Connection_Handler *>
        safe_handlers (handlers);

      ACE_NEW_RETURN (failures,
                      char[num_connections],
                      -1);

      // No longer need to worry about exception safety at this point.
      remote_addrs = safe_remote_addrs.release ();
      handlers = safe_handlers.release ();

      size_t slot = 0;

      // Fill in the remote address array
      while (dests.pop (remote_addrs[slot]) == 0)
        handlers[slot++] = 0;

      // Finally, try to connect.
      this->base_connector_.connect_n (num_connections,
                                       handlers,
                                       remote_addrs,
                                       failures);

      // Loop over all the failures and set the handlers that
      // succeeded to idle state.
      for (slot = 0;
           slot < num_connections;
           ++slot)
        {
          if (!failures[slot])
            {
              handlers[slot]->idle ();
              ++successes;

              if (TAO_debug_level > 0)
                ACE_DEBUG ((LM_DEBUG,
                            "TAO (%P|%t) Preconnection <%s> succeeded.\n",
                            remote_addrs[slot].get_path_name ()));
            }
          else if (TAO_debug_level > 0)
            ACE_DEBUG ((LM_DEBUG,
                        "TAO (%P|%t) Preconnection <%s> failed.\n",
                        remote_addrs[slot].get_path_name ()));
        }

      ACE_OS::free (preconnections);

      if (TAO_debug_level > 0)
        ACE_DEBUG ((LM_DEBUG,
                    "TAO (%P|%t) UIOP preconnections: %d successes and "
                    "%d failures.\n",
                    successes,
                    num_connections - successes));
    }

  return successes;
}

TAO_Profile *
TAO_UIOP_Connector::create_profile (TAO_InputCDR& cdr)
{
  TAO_Profile *pfile;
  ACE_NEW_RETURN (pfile,
                  TAO_UIOP_Profile (this->orb_core_),
                  0);

  int r = pfile->decode (cdr);
  if (r == -1)
    {
      pfile->_decr_refcnt ();
      pfile = 0;
    }

  return pfile;
}

void
TAO_UIOP_Connector::make_profile (const char *endpoint,
                                  TAO_Profile *&profile,
                                  CORBA::Environment &ACE_TRY_ENV)
{
  // The endpoint should be of the form:
  //    N.n@rendezvous_point|object_key
  // or:
  //    rendezvous_point|object_key

  ACE_NEW_THROW_EX (profile,
                    TAO_UIOP_Profile (endpoint,
                                      this->orb_core_,
                                      ACE_TRY_ENV),
                    CORBA::NO_MEMORY ());

  ACE_CHECK;

}

int
TAO_UIOP_Connector::check_prefix (const char *endpoint)
{
  // Check for a valid string
  if (!endpoint || !*endpoint)
    return -1;  // Failure

  const char *protocol[] = { "uiop", "uioploc" };

  size_t slot = ACE_OS::strchr (endpoint, ':') - endpoint;

  size_t len0 = ACE_OS::strlen (protocol[0]);
  size_t len1 = ACE_OS::strlen (protocol[1]);

  // Check for the proper prefix in the IOR.  If the proper prefix
  // isn't in the IOR then it is not an IOR we can use.
  if (slot == len0
      && ACE_OS::strncasecmp (endpoint,
                              protocol[0],
                              len0) == 0)
    return 0;
  else if (slot == len1
           && ACE_OS::strncasecmp (endpoint,
                                   protocol[1],
                                   len1) == 0)
    return 0;

  return -1;
  // Failure: not an UIOP IOR DO NOT throw an exception here.
}

char
TAO_UIOP_Connector::object_key_delimiter (void) const
{
  return TAO_UIOP_Profile::object_key_delimiter_;
}

int
TAO_UIOP_Connector::init_uiop_properties (void)
{
#if (TAO_HAS_RT_CORBA == 1)

  // Connector protocol properties are obtained from ORB-level
  // RTCORBA::ClientProtocolProperties policy override.
  // If the override doesn't exist or doesn't contain the
  // properties, we use ORB default.
  //
  // Currently, we do not use Object-level and Current-level policy
  // overrides for protocol configuration because connection
  // lookup and caching are not done based on protocol
  // properties.

  ACE_DECLARE_NEW_CORBA_ENV;

  // Check ORB-level override for tcp properties.
  TAO_ClientProtocolPolicy *client_protocols =
    this->orb_core_->policy_manager ()->client_protocol ();
  CORBA::Object_var auto_release = client_protocols;
  RTCORBA::UnixDomainProtocolProperties_var uiop_properties =
    RTCORBA::UnixDomainProtocolProperties::_nil ();

  if (client_protocols != 0)
    {
      RTCORBA::ProtocolList & protocols = client_protocols->protocols_rep ();

      for (CORBA::ULong j = 0; j < protocols.length (); ++j)
        if (protocols[j].protocol_type == TAO_TAG_UIOP_PROFILE)
          {
            uiop_properties =
              RTCORBA::UnixDomainProtocolProperties::_narrow
            (protocols[j].transport_protocol_properties.in (),
             ACE_TRY_ENV);
            ACE_CHECK_RETURN (-1);
            break;
          }
    }

  if (CORBA::is_nil (uiop_properties.in ()))
    {
      // No tcp properties in ORB-level override.  Use ORB defaults.
      // Orb defaults should never be null - they were initialized by
      // the ORB_Core.
      client_protocols = this->orb_core_->default_client_protocol ();
      auto_release = client_protocols;
      RTCORBA::ProtocolList & protocols = client_protocols->protocols_rep ();
      for (CORBA::ULong j = 0; j < protocols.length (); ++j)
        if (protocols[j].protocol_type == TAO_TAG_UIOP_PROFILE)
          {
            uiop_properties =
              RTCORBA::UnixDomainProtocolProperties::_narrow
              (protocols[j].transport_protocol_properties.in (),
               ACE_TRY_ENV);
            ACE_CHECK_RETURN (-1);
            break;
          }
    }

  // Extract and locally store properties of interest.
  this->uiop_properties_.send_buffer_size =
    uiop_properties->send_buffer_size ();
  this->uiop_properties_.recv_buffer_size =
    uiop_properties->recv_buffer_size ();

#else /* TAO_HAS_RT_CORBA == 1 */

  // Without RTCORBA, protocol configuration properties come from ORB
  // options.
  this->uiop_properties_.send_buffer_size =
    this->orb_core_->orb_params ()->sock_sndbuf_size ();
  this->uiop_properties_.recv_buffer_size =
    this->orb_core_->orb_params ()->sock_rcvbuf_size ();

#endif /* TAO_HAS_RT_CORBA == 1 */

  return 0;
}

#endif /* TAO_HAS_UIOP == 1 */
