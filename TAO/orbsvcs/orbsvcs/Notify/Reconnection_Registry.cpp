// -*- C++ -*-

/**
 *  @file Reconnection_Registry.cpp
 *
 *  $Id$
 *
 *  @author Dale Wilson <wilson_d@ociweb.com>
 */
#include "Reconnection_Registry.h"
#include "tao/debug.h"
#include "Properties.h"
#include "Topology_Saver.h"
#include "ace/Vector_T.h"
//#define DEBUG_LEVEL 10
#ifndef DEBUG_LEVEL
# define DEBUG_LEVEL TAO_debug_level
#endif


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO_Notify
{
  Reconnection_Registry::Reconnection_Registry (Topology_Parent & parent)
    : highest_id_(0)
  {
    // not the best technique, here.  Take advantage of "protected"
    Topology_Object::topology_parent_ = &parent;
  }

  Reconnection_Registry::~Reconnection_Registry ()
  {
  }

  //////////////////////////
  // During normal operation

  NotifyExt::ReconnectionRegistry::ReconnectionID
  Reconnection_Registry::register_callback (
    NotifyExt::ReconnectionCallback_ptr callback
    ACE_ENV_ARG_DECL)
  {
    //@@todo DO WE NEED THREAD SAFENESS?
    NotifyExt::ReconnectionRegistry::ReconnectionID next_id = ++highest_id_;

    if (DEBUG_LEVEL > 0)
    {
      ACE_DEBUG ((LM_DEBUG,
        ACE_TEXT ("(%P|%t) Reconnect registry: registering %d\n"),
        static_cast<int> (next_id)
        ));
    }
    TAO_Notify_Properties* properties = TAO_Notify_PROPERTIES::instance();
    CORBA::ORB_var orb = properties->orb ();

    CORBA::String_var cior = orb->object_to_string (callback ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);
    ACE_CString ior(cior.in ());
    if ( 0 != reconnection_registry_.bind (next_id, ior))
    {
      //todo throw something;
    }
    this->self_change (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    return next_id;
  }

  void
  Reconnection_Registry::unregister_callback (NotifyExt::ReconnectionRegistry::ReconnectionID id
    ACE_ENV_ARG_DECL)
  {
    if (DEBUG_LEVEL > 0)
    {
      ACE_DEBUG ((LM_DEBUG,
        ACE_TEXT ("(%P|%t) Reconnect registry: unregistering %d\n"),
        static_cast<int> (id)
        ));
    }
    if ( 0 != reconnection_registry_.unbind (id))
    {
      //@@todo  throw something
    }
    this->self_change (ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  CORBA::Boolean
  Reconnection_Registry::is_alive (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  {
    return CORBA::Boolean(1);
  }

  //////////////////////
  // During topology save

  void
  Reconnection_Registry::save_persistent (Topology_Saver& saver ACE_ENV_ARG_DECL)
  {
    bool change = this->self_changed_;
    this->self_changed_ = false;
    this->children_changed_ = false;

    NVPList attrs;
    //@@todo: bool want_all_children =
      saver.begin_object (0, REGISTRY_TYPE, attrs, change ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    Reconnection_Registry_Type::ENTRY *entry;
    for (Reconnection_Registry_Type::ITERATOR iter (this->reconnection_registry_);
      iter.next (entry);
      iter.advance ())
    {
      NVPList cattrs;
      if (DEBUG_LEVEL > 0)
      {
        ACE_DEBUG ((LM_DEBUG,
          ACE_TEXT ("(%P|%t) Reconnect registry: saving %d\n"),
          static_cast<int> (entry->ext_id_)
          ));
      }
      cattrs.push_back(NVP(RECONNECT_ID, entry->ext_id_));
      cattrs.push_back(NVP(RECONNECT_IOR, entry->int_id_));
      saver.begin_object (entry->ext_id_, REGISTRY_CALLBACK_TYPE, cattrs, true ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
      saver.end_object (entry->ext_id_, REGISTRY_CALLBACK_TYPE ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
// todo:
//    for all deleted children
//    {
//      saver.delete_child(child_type, child_id);
//    }
    saver.end_object (0, REGISTRY_TYPE ACE_ENV_ARG_PARAMETER);
  }

  ///////////////////////////////////////
  // During reload of persistent topology

  Topology_Object*
  Reconnection_Registry::load_child (const ACE_CString & type,
        CORBA::Long,
        const NVPList& attrs
        ACE_ENV_ARG_DECL_NOT_USED)
  {
    if (type == REGISTRY_CALLBACK_TYPE)
    {
      NotifyExt::ReconnectionRegistry::ReconnectionID id;
      ACE_CString ior;
      if (attrs.load (RECONNECT_ID, id) && attrs.load (RECONNECT_IOR, ior))
      {
        if (id > highest_id_)
        {
          highest_id_ = id;

          if (DEBUG_LEVEL > 0)
          {
            ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("(%P|%t) Reconnect registry: reloading %d\n"),
              static_cast<int> (id)
              ));
          }
        }
        if ( 0 != reconnection_registry_.bind (id, ior))
        {
          //@@todo - throw something;
        }
      }
      else
      {
        ACE_ERROR ((LM_ERROR,
          ACE_TEXT ("(%P|%t) Reconnect registry: missing attribute\n")
          ));
      }
    }
    return this;
  }

  void
  Reconnection_Registry::send_reconnect (CosNotifyChannelAdmin::EventChannelFactory_ptr dest_factory
    ACE_ENV_ARG_DECL_NOT_USED)
  {
    TAO_Notify_Properties* properties = TAO_Notify_PROPERTIES::instance();
    CORBA::ORB_var orb = properties->orb ();
    ACE_Vector <NotifyExt::ReconnectionRegistry::ReconnectionID> bad_ids;

    Reconnection_Registry_Type::ENTRY *entry;
    for (Reconnection_Registry_Type::ITERATOR iter (this->reconnection_registry_);
      iter.next (entry);
      iter.advance ())
    {
      ACE_DECLARE_NEW_ENV;
      ACE_TRY
      {
        if (DEBUG_LEVEL > 0)
        {
          ACE_DEBUG ((LM_DEBUG,
            ACE_TEXT ("(%P|%t) Reconnection Registry: Sending reconnection to client %d\n"),
              static_cast<int> (entry->ext_id_)
            ));
        }
        ACE_CString & ior = entry->int_id_;
        CORBA::Object_var obj = orb->string_to_object (ior.c_str () ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;
        NotifyExt::ReconnectionCallback_var callback =
          NotifyExt::ReconnectionCallback::_narrow (obj.in ());
        if (!CORBA::is_nil (callback.in ()))
        {
          callback->reconnect (dest_factory ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }
        else
        {
          ACE_DEBUG ((LM_DEBUG,
            ACE_TEXT ("(%P|%t) Reconnection Registry: Can't resolve reconnection client's IOR %d\n"),
              static_cast<int> (entry->ext_id_)
            ));

          //throw this entry away but you've got an iterator so be careful
          bad_ids.push_back (entry->ext_id_);
        }
      }
      ACE_CATCHANY
      {
        ACE_DEBUG ((LM_DEBUG,
          ACE_TEXT ("(%P|%t) Reconnection Registry: Exception sending reconnection to client -- discarding registry entry\n")
          ));
        //throw this entry away but you've got an iterator so be careful
        bad_ids.push_back (entry->ext_id_);
        //@@todo : we might want to check for retryable exceptions, but for now...
      }
      ACE_ENDTRY;
    }
    size_t bad_count = bad_ids.size ();
    for (size_t nbad = 0; nbad < bad_count; ++nbad)
    {
      this->reconnection_registry_.unbind (bad_ids[nbad]);
    }
  }

  void
  Reconnection_Registry::release (void)
  {
    delete this;
    //@@ inform factory
  }

} // namespace TAO_Notify

TAO_END_VERSIONED_NAMESPACE_DECL
