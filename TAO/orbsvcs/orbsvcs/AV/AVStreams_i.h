/* -*- C++ -*- */

// $Id$

// ============================================================================
//
// = LIBRARY
//   ORBSVCS (AVStreams)
//
// = FILENAME
//   AVStreams_i.h
//
// = AUTHOR
//    Sumedh Mungee <sumedh@cs.wustl.edu>
//    Nagarajan Surendran <naga@cs.wustl.edu>
//
//
// ============================================================================

#ifndef AVSTREAMS_I_H
#define AVSTREAMS_I_H
#include "ace/pre.h"

#include "ace/OS.h"
#include "ace/SOCK_Dgram_Mcast.h"
#include "ace/ATM_Addr.h"
#include "ace/Containers_T.h"
#include "ace/Process.h"
#include "ace/SOCK_CODgram.h"
#include "ace/Connector.h"
#include "ace/SOCK_Connector.h"
#include "ace/Acceptor.h"
#include "ace/SOCK_Stream.h"
#include "ace/Svc_Handler.h"
#include "ace/SOCK_Acceptor.h"

#include "tao/PortableServer/ORB_Manager.h"
#include "orbsvcs/AV/AV_export.h"
#include "orbsvcs/CosPropertyServiceS.h"
#include "orbsvcs/AVStreamsS.h"
#include "orbsvcs/Property/CosPropertyService_i.h"
#include "orbsvcs/CosNamingC.h"
#include "orbsvcs/AV/AV_Core.h"
#include "orbsvcs/AV/Endpoint_Strategy.h"
#include "orbsvcs/Null_MediaCtrlS.h"

#if defined (TAO_ORBSVCS_HAS_Trader)
#include "orbsvcs/Trader/Trader.h"
#endif /* TAO_ORBSVCS_HAS_Trader */

#include "orbsvcs/AV/FlowSpec_Entry.h"

#if defined(sun) || defined(__osf__)
extern "C" int gethostname(char* name, int len);
#endif

#define FLOWSPEC_MAX 5
// for the Hash_Map helper classes.

// This is to remove "inherits via dominance" warnings from MSVC.
// MSVC is being a little too paranoid.
#if defined (_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
# pragma warning (disable : 4250)
#endif /* _MSC_VER */

#if !defined (TAO_ORBSVCS_HAS_Trader)

// =  Classes to deal with the ACE_Hash_Map_Manager.
class TAO_AV_Export TAO_String_Hash_Key : public CORBA::String_var
{
  // = TITLE
  //     Key for the Hash Table. The EXT_ID of the
  //     ACE_Hash_Map_Manager.
public:
  // = Initialization and termination methods.
  TAO_String_Hash_Key (void);
  // Default constructor.

  TAO_String_Hash_Key (char * name);
  // Constructor from a const string.

  TAO_String_Hash_Key (const char * name);
  // Constructor from a const string.

  TAO_String_Hash_Key (const CORBA::String_var &hash_key);
  // Copy constructor.

  ~TAO_String_Hash_Key (void);
  // Destructor.

  int operator == (const TAO_String_Hash_Key &hash_key) const;
  // The operator for hash binding and "find"ing.

  friend int operator < (const TAO_String_Hash_Key &left,
                         const TAO_String_Hash_Key &right);
  // The operator for hash binding and "find"ing.

  u_long hash (void) const;
  // The function that computes a hash value.
};
#endif /* !TAO_ORBSVCS_HAS_Trader */

typedef ACE_Hash_Map_Manager <TAO_String_Hash_Key,AVStreams::FlowEndPoint_ptr,ACE_Null_Mutex>  FlowEndPoint_Map;
typedef ACE_Hash_Map_Entry <TAO_String_Hash_Key,AVStreams::FlowEndPoint_ptr> FlowEndPoint_Map_Entry;
typedef ACE_Hash_Map_Iterator <TAO_String_Hash_Key,AVStreams::FlowEndPoint_ptr,ACE_Null_Mutex>  FlowEndPoint_Map_Iterator;

#include "AV_Core.h"

int deactivate_servant (PortableServer::Servant servant);
char *get_flowname (const char *flow_spec_entry_str);

class TAO_AV_Export AV_Null_MediaCtrl
  : public virtual POA_Null_MediaCtrl,
    public virtual PortableServer::RefCountServantBase
{
public:
  AV_Null_MediaCtrl (void);
};


class TAO_AV_Export TAO_Basic_StreamCtrl
  : public virtual POA_AVStreams::Basic_StreamCtrl,
    public virtual TAO_PropertySet,
    public virtual PortableServer::RefCountServantBase
{
  // = DESCRIPTION
  //    Base class for StreamCtrl, implements basic stream start
  //    and stop functionality

public:
  TAO_Basic_StreamCtrl (void);
  // Default Constructor

  virtual ~TAO_Basic_StreamCtrl (void);
  // Destructor.

  virtual void stop (const AVStreams::flowSpec &the_spec,
                     CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow));
  // Stop the transfer of data of the stream
  // Empty the_spec means apply operation to all flows

  virtual void start (const AVStreams::flowSpec &the_spec,
                      CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow));
  // Start the transfer of data in the stream.
  // Empty the_spec means apply operation to all flows

  virtual void destroy (const AVStreams::flowSpec &the_spec,
                        CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow));
  // Tears down the stream. This will close the connection, and delete
  // the streamendpoint and vdev associated with this stream
  // Empty the_spec means apply operation to all flows

  virtual CORBA::Boolean modify_QoS (AVStreams::streamQoS &new_qos,
                                     const AVStreams::flowSpec &the_spec,
                                     CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow,
                     AVStreams::QoSRequestFailed));
  // Changes the QoS associated with the stream
  // Empty the_spec means apply operation to all flows

  virtual void push_event (const struct CosPropertyService::Property & the_event,
                           CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Used by StreamEndPoint and VDev to inform StreamCtrl of events.
  // E.g., loss of flow, reestablishment of flow, etc..

  virtual void set_FPStatus (const AVStreams::flowSpec &the_spec,
                             const char *fp_name,
                             const CORBA::Any &fp_settings,
                             CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow,
                     AVStreams::FPError));
  // Used to control the flow protocol parameters.

  virtual CORBA::Object_ptr get_flow_connection (const char *flow_name,
                                                 CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow,
                     AVStreams::notSupported));
  // Not implemented in the light profile, will raise the notsupported
  // exception

  virtual void set_flow_connection (const char *flow_name,
                                    CORBA::Object_ptr flow_connection,
                                    CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow,
                     AVStreams::notSupported));
  // Not implemented in the light profile, will raise the notsupported
  // exception

protected:

  AVStreams::VDev_var vdev_a_;
  AVStreams::VDev_var vdev_b_;
  // The Virtual Devices for this stream

  AVStreams::StreamEndPoint_A_var sep_a_;
  AVStreams::StreamEndPoint_B_var sep_b_;
  // The Endpoints for this stream

  typedef ACE_Hash_Map_Manager <TAO_String_Hash_Key,AVStreams::FlowConnection_ptr,ACE_Null_Mutex> FlowConnection_Map;
  typedef ACE_Hash_Map_Iterator <TAO_String_Hash_Key,AVStreams::FlowConnection_ptr,ACE_Null_Mutex> FlowConnection_Map_Iterator;
  typedef ACE_Hash_Map_Entry <TAO_String_Hash_Key,AVStreams::FlowConnection_ptr> FlowConnection_Map_Entry;
  FlowConnection_Map flow_connection_map_;
  // Hash table for the flow names and its corresponding flowconnection object reference.
  AVStreams::FlowConnection_seq flowConnections_;

  u_int flow_count_;
  AVStreams::flowSpec flows_;
  //sequence of flow names.
};

class TAO_AV_Export TAO_Negotiator
  : public POA_AVStreams::Negotiator,
    public virtual PortableServer::RefCountServantBase
{
public:
  virtual CORBA::Boolean negotiate (AVStreams::Negotiator_ptr remote_negotiator,
                                    const AVStreams::streamQoS &qos_spec,
                                    CORBA::Environment &ACE_TRY_ENV = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
};

class TAO_MCastConfigIf;

class MMDevice_Map_Hash_Key
{
public:
  MMDevice_Map_Hash_Key (void);
  // default constructor.

  MMDevice_Map_Hash_Key (AVStreams::MMDevice_ptr mmdevice);
  // constructor.

  MMDevice_Map_Hash_Key (const MMDevice_Map_Hash_Key&);
  // copy constructor.

  ~MMDevice_Map_Hash_Key (void);
  // destructor.

  int operator == (const MMDevice_Map_Hash_Key &hash_key) const;
  // operator== needed by  ACE_Hash_Map_Manager.

  friend int operator < (const MMDevice_Map_Hash_Key &left,
                         const MMDevice_Map_Hash_Key &right);
  // operator== needed by  ACE_Hash_Map_Manager.

  u_long hash (void) const;
  // hash function for this mmdevice.

  static const int hash_maximum_;
protected:
  AVStreams::MMDevice_ptr mmdevice_;
};

class TAO_AV_Export TAO_StreamCtrl
  : public virtual POA_AVStreams::StreamCtrl,
    public virtual TAO_Basic_StreamCtrl,
    public virtual PortableServer::RefCountServantBase
{
  // = DESCRIPTION
  //    Implementation the A/V StreamCtrl class. this class
  //    is used to control the stream. It should be subclassed
  //    by applications that want to provide more control features.

public:

  TAO_StreamCtrl (void);
  // Default Constructor

  TAO_StreamCtrl (TAO_StreamCtrl const &);
  // Copy  Constructor to fool g++

  virtual ~TAO_StreamCtrl (void);
  // virtual destructor.

  void operator= (TAO_StreamCtrl const &);
  // Fooling g++

  virtual void stop (const AVStreams::flowSpec &the_spec,
                     CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow));
  // Stop the transfer of data of the stream
  // Empty the_spec means apply operation to all flows

  virtual void start (const AVStreams::flowSpec &the_spec,
                      CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow));
  // Start the transfer of data in the stream.
  // Empty the_spec means apply operation to all flows

  virtual void destroy (const AVStreams::flowSpec &the_spec,
                        CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow));
  // Tears down the stream. This will close the connection, and delete
  // the streamendpoint and vdev associated with this stream
  // Empty the_spec means apply operation to all flows

  virtual CORBA::Boolean bind_devs (AVStreams::MMDevice_ptr a_party,
                                    AVStreams::MMDevice_ptr b_party,
                                    AVStreams::streamQoS& the_qos,
                                    const AVStreams::flowSpec& the_flows,
                                    CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::streamOpFailed,
                     AVStreams::noSuchFlow,
                     AVStreams::QoSRequestFailed));
  // Establish a stream between a_party and b_party,
  // with qos the_qos, and for the flows in the_flows
  // if the_flows is empty, bind all the flows
  // Causes a connection to be established between the StreamEndpoints.
  // Returns success/failure

  virtual CORBA::Boolean bind (AVStreams::StreamEndPoint_A_ptr a_party,
                               AVStreams::StreamEndPoint_B_ptr b_party,
                               AVStreams::streamQoS &the_qos,
                               const AVStreams::flowSpec &the_flows,
                               CORBA::Environment &env = CORBA::Environment::default_environment ())
  ACE_THROW_SPEC ((CORBA::SystemException,
                   AVStreams::streamOpFailed,
                   AVStreams::noSuchFlow,
                   AVStreams::QoSRequestFailed));
  // Establish a connection between two streamendpoints. This can
  // be used if the streamendpoints have been created independent of
  // a MMDevice

  virtual void unbind_dev (AVStreams::MMDevice_ptr dev,
                           const AVStreams::flowSpec & the_spec,
                           CORBA::Environment &ACE_TRY_ENV = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::streamOpFailed,
                     AVStreams::noSuchFlow));

  virtual void unbind_party (AVStreams::StreamEndPoint_ptr the_ep,
                             const AVStreams::flowSpec &the_spec,
                             CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::streamOpFailed,
                     AVStreams::noSuchFlow));
  // Unbind the_ep from the stream. Empty the_spec means apply to all flows.

  virtual void unbind (CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::streamOpFailed));
  // unbind the stream. Same effect as Basic_StreamCtrl::destroy ()

  virtual AVStreams::VDev_ptr get_related_vdev (AVStreams::MMDevice_ptr adev,
                                                AVStreams::StreamEndPoint_out sep,
                                                CORBA::Environment &ACE_TRY_ENV = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::streamOpFailed));

  virtual CORBA::Boolean modify_QoS (AVStreams::streamQoS &new_qos,
                                     const AVStreams::flowSpec &the_spec,
                                     CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow,
                     AVStreams::QoSRequestFailed));
  // Changes the QoS associated with the stream
  // Empty the_spec means apply operation to all flows

protected:

  struct MMDevice_Map_Entry
  {
    AVStreams::StreamEndPoint_var sep_;
    AVStreams::VDev_var vdev_;
    AVStreams::flowSpec flowspec_;
    AVStreams::streamQoS qos_;
  };

  typedef ACE_Hash_Map_Manager <MMDevice_Map_Hash_Key,MMDevice_Map_Entry,ACE_Null_Mutex> MMDevice_Map;
  typedef ACE_Hash_Map_Iterator <MMDevice_Map_Hash_Key,MMDevice_Map_Entry,ACE_Null_Mutex> MMDevice_Map_Iterator;

  MMDevice_Map mmdevice_a_map_;
  MMDevice_Map mmdevice_b_map_;
  TAO_MCastConfigIf *mcastconfigif_;
  AVStreams::MCastConfigIf_var mcastconfigif_ptr_;
  AVStreams::StreamCtrl_var streamctrl_;
  CORBA::ULong source_id_;
};

class TAO_AV_Export TAO_MCastConfigIf
  : public virtual POA_AVStreams::MCastConfigIf,
    public virtual TAO_PropertySet,
    public virtual PortableServer::RefCountServantBase
{
public:

  enum Peer_Interface {VDEV = 0, FLOWENDPOINT=1};
  struct Peer_Info
  {
    AVStreams::VDev_var peer_;
    AVStreams::FlowEndPoint_var fep_;
    AVStreams::streamQoS qos_;
    AVStreams::flowSpec flow_spec_;
    Peer_Interface interface_;
  };

  TAO_MCastConfigIf (void);
  // Default constructor.

  ~TAO_MCastConfigIf (void);
  // Dtor

  virtual CORBA::Boolean set_peer (CORBA::Object_ptr peer,
                                   AVStreams::streamQoS & the_qos,
                                   const AVStreams::flowSpec & the_spec,
                                   CORBA::Environment &ACE_TRY_ENV = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::QoSRequestFailed,
                     AVStreams::streamOpFailed));

  virtual void configure (const CosPropertyService::Property & a_configuration,
                          CORBA::Environment &ACE_TRY_ENV = CORBA::Environment::default_environment ())
  ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void set_initial_configuration (const CosPropertyService::Properties & initial,
                                          CORBA::Environment &ACE_TRY_ENV = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void set_format (const char * flowName,
                           const char * format_name,
                           CORBA::Environment &ACE_TRY_ENV =
                           CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::notSupported));

  virtual void set_dev_params (const char * flowName,
                               const CosPropertyService::Properties & new_params,
                               CORBA::Environment &ACE_TRY_ENV = CORBA::Environment::default_environment ())

    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::PropertyException,
                     AVStreams::streamOpFailed));

protected:
  int in_flowSpec (const AVStreams::flowSpec& flow_spec, const char *flow_name);
  // checks whether the flowname is  in the flow_spec.

  ACE_SOCK_Dgram_Mcast sock_mcast_;
  // Multicast socket.

  CosPropertyService::Properties initial_configuration_;
  // Initial configuration to be distributed to all B parties when they join.

  ACE_DLList<Peer_Info> peer_list_;
  ACE_DLList_Iterator<Peer_Info> peer_list_iterator_;
};

// Forward declarations.
class TAO_AV_TCP_Flow_Handler;
class TAO_AV_UDP_Flow_Handler;
class TAO_AV_UDP_MCast_Flow_Handler;
class TAO_AV_Protocol_Object;
class TAO_AV_Callback;
class TAO_AV_SourceManager;
class TAO_AV_Source;
class TAO_AV_RTP_State;
class TAO_AV_Flow_Handler;

class TAO_AV_Export TAO_Base_StreamEndPoint
{
  // = DESCRIPTION
  //    Base class for the A/V StreamEndPoint class. this class
  //    is used to control the stream. It should be subclassed
  //    by applications that want to provide more control features.

  // @@Naga: Rename this class to TAO_Base_EndPoint since both stream and flowendpoints derive from it.
public:
  TAO_Base_StreamEndPoint (void);
  virtual ~TAO_Base_StreamEndPoint (void);

  virtual int handle_open (void);
  // called when streamendpoint is instantiated

  virtual int handle_close (void);
  // called when streamendpoint is being destructed

  virtual int handle_stop (const AVStreams::flowSpec &the_spec,
                            CORBA::Environment &env = CORBA::Environment::default_environment ());
  // Application needs to define this

  virtual int handle_start (const AVStreams::flowSpec &the_spec,
                             CORBA::Environment &env = CORBA::Environment::default_environment ());
  // Application needs to define this

  virtual int handle_destroy (const AVStreams::flowSpec &the_spec,
                               CORBA::Environment &env = CORBA::Environment::default_environment ());
  // Application needs to define this

  virtual CORBA::Boolean handle_preconnect (AVStreams::flowSpec &the_spec);
  // Application needs to define this

  virtual CORBA::Boolean handle_postconnect (AVStreams::flowSpec &the_spec);
  // Application needs to define this

  virtual CORBA::Boolean handle_connection_requested (AVStreams::flowSpec &the_spec,
                                                      CORBA::Environment &env = CORBA::Environment::default_environment ());
  // Application needs to define this

  virtual int get_callback (const char *flowname,
                            TAO_AV_Callback *&callback);

  virtual int get_control_callback (const char *flowname,
                                    TAO_AV_Callback *&callback);

  virtual int set_protocol_object (const char *flowname,
                                   TAO_AV_Protocol_Object *object);

  virtual void set_flow_handler (const char *flowname,
                            TAO_AV_Flow_Handler *handler);
};

// Forward declarations.
class TAO_AV_Acceptor;
class TAO_AV_Connector;
class TAO_Forward_FlowSpec_Entry;
class TAO_Reverse_FlowSpec_Entry;

class TAO_AV_Export TAO_StreamEndPoint
  : public virtual POA_AVStreams::StreamEndPoint,
    public virtual TAO_Base_StreamEndPoint,
    public virtual TAO_PropertySet,
    public virtual PortableServer::RefCountServantBase
{
  // = DESCRIPTION
  //    The Stream EndPoint. Used to implement one endpoint of a stream
  //    that implements the transport layer.
public:
  TAO_StreamEndPoint (void);
  // Constructor

  virtual void stop (const AVStreams::flowSpec &the_spec,
                     CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow));
   // Stop the stream. Empty the_spec means, for all the flows

  virtual void start (const AVStreams::flowSpec &the_spec,
                      CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow));
  // Start the stream, Empty the_spec means, for all the flows

  virtual void destroy (const AVStreams::flowSpec &the_spec,
                        CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow));
  // Destroy the stream, Empty the_spec means, for all the flows

  virtual CORBA::Boolean connect (AVStreams::StreamEndPoint_ptr responder,
                                  AVStreams::streamQoS& qos_spec,
                                  const AVStreams::flowSpec& the_spec,
                                  CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow,
                     AVStreams::QoSRequestFailed,
                     AVStreams::streamOpFailed));
  // Called by StreamCtrl. responder is the peer to connect to

  virtual CORBA::Boolean request_connection (AVStreams::StreamEndPoint_ptr initiator,
                                             CORBA::Boolean is_mcast,
                                             AVStreams::streamQoS &qos,
                                             AVStreams::flowSpec &the_spec,
                                             CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::streamOpDenied,
                     AVStreams::noSuchFlow,
                     AVStreams::QoSRequestFailed,
                     AVStreams::FPError));
  // Called by the peer StreamEndPoint. The flow_spec indicates the
  // flows (which contain transport addresses etc.)

  virtual CORBA::Boolean modify_QoS (AVStreams::streamQoS &new_qos,
                                     const AVStreams::flowSpec &the_flows,
                                     CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow,
                     AVStreams::QoSRequestFailed));
  // Change the transport qos on a stream

  virtual CORBA::Boolean set_protocol_restriction (const AVStreams::protocolSpec &the_pspec,
                                                   CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Used to restrict the set of protocols

  virtual void disconnect (const AVStreams::flowSpec &the_spec,
                           CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow,
                     AVStreams::streamOpFailed));
  // disconnect the flows

  virtual void set_FPStatus (const AVStreams::flowSpec &the_spec,
                             const char *fp_name,
                             const CORBA::Any &fp_settings,
                             CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow,
                     AVStreams::FPError));
  // Used to control the flow

  virtual CORBA::Object_ptr get_fep (const char *flow_name,
                                     CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::notSupported,
                     AVStreams::noSuchFlow));
  // Not implemented in the light profile, throws notsupported

  virtual char * add_fep (CORBA::Object_ptr the_fep,
                          CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::notSupported,
                     AVStreams::streamOpFailed));
  // Not implemented in the light profile, throws notsupported

  virtual void remove_fep (const char *fep_name,
                           CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::notSupported,
                     AVStreams::streamOpFailed));
  // Not implemented in the light profile, throws notsupported

  virtual void set_negotiator (AVStreams::Negotiator_ptr new_negotiator,
                               CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Used to "attach" a negotiator to the endpoint

  virtual void set_key (const char *flow_name,
                        const AVStreams::key & the_key,
                        CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Used for public key encryption.

  virtual void set_source_id (CORBA::Long source_id,
                              CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Used to set a unique id for packets sent by this streamendpoint

  virtual ~TAO_StreamEndPoint (void);
  // Destructor

  CORBA::Boolean multiconnect (AVStreams::streamQoS &the_qos,
                               AVStreams::flowSpec &the_spec,
                               CORBA::Environment &ACE_TRY_ENV);

protected:
  char* add_fep_i (AVStreams::FlowEndPoint_ptr fep,
                   CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::notSupported,
                     AVStreams::streamOpFailed));
  char* add_fep_i_add_property (AVStreams::FlowEndPoint_ptr fep,
                                CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::notSupported,
                     AVStreams::streamOpFailed));
  // Helper methods to implement add_fep()

  int translate_qos (const AVStreams::streamQoS& application_qos,
                     AVStreams::streamQoS& network_qos);
  // translate from application level to network level qos.

  u_int flow_count_;
  // Count of the number of flows in this streamendpoint, used to
  // generate unique names for the flows.

  u_int flow_num_;
  // current flow number used for system generation of flow names.

  FlowEndPoint_Map fep_map_;
  // hash table for the flownames and its corresponding flowEndpoint reference.

  AVStreams::flowSpec flows_;
  // sequence of supported flow names.

  CORBA::Long source_id_;
  // source id used for multicast.

  AVStreams::Negotiator_var negotiator_;
  // our local negotiator for QoS.

  AVStreams::protocolSpec protocols_;
  // Our available list of protocols.

  CORBA::String_var protocol_;
  // Chosen protocol for this streamendpoint based on availableprotocols property.

  AVStreams::key key_;
  // Key used for encryption.

  u_short mcast_port_;
  ACE_CString mcast_addr_;
  ACE_Hash_Map_Manager <TAO_String_Hash_Key, TAO_FlowSpec_Entry*,ACE_Null_Mutex> mcast_entry_map_;
  TAO_AV_FlowSpecSet forward_flow_spec_set;
  TAO_AV_FlowSpecSet reverse_flow_spec_set;
  AVStreams::StreamEndPoint_var peer_sep_;
  AVStreams::SFPStatus *sfp_status_;
  AVStreams::StreamCtrl_var streamctrl_;
//   TAO_Forward_FlowSpec_Entry forward_entries_ [FLOWSPEC_MAX];
//   TAO_Reverse_FlowSpec_Entry reverse_entries_ [FLOWSPEC_MAX];
};


class TAO_AV_Export TAO_StreamEndPoint_A :
  public virtual POA_AVStreams::StreamEndPoint_A,
  public virtual TAO_StreamEndPoint,
  public virtual PortableServer::RefCountServantBase
{
  // = DESCRIPTION
  //     The "A" side of a streamendpoint
public:
  TAO_StreamEndPoint_A (void);
  // Constructor

  virtual CORBA::Boolean multiconnect (AVStreams::streamQoS &the_qos,
                                       AVStreams::flowSpec &the_spec,
                                       CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow,
                     AVStreams::QoSRequestFailed,
                     AVStreams::streamOpFailed));
  // Used for ATM-style multicast

  virtual CORBA::Boolean connect_leaf (AVStreams::StreamEndPoint_B_ptr the_ep,
                                       AVStreams::streamQoS &the_qos,
                                       const AVStreams::flowSpec &the_flows,
                                       CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::streamOpFailed,
                     AVStreams::noSuchFlow,
                     AVStreams::QoSRequestFailed,
                     AVStreams::notSupported));
  // Used for ATM-style multicast

  virtual void disconnect_leaf (AVStreams::StreamEndPoint_B_ptr the_ep,
                                const AVStreams::flowSpec &theSpec,
                                CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::streamOpFailed,
                     AVStreams::noSuchFlow,
                     AVStreams::notSupported));
  // Used to remove a multicast leaf

  virtual ~TAO_StreamEndPoint_A (void);
  // Destructor

};

// For backward compatibility.
#define TAO_Client_StreamEndPoint TAO_StreamEndPoint_A
#define TAO_Server_StreamEndPoint TAO_StreamEndPoint_B

class TAO_AV_Export TAO_StreamEndPoint_B :
  public virtual POA_AVStreams::StreamEndPoint_B,
  public virtual TAO_StreamEndPoint,
  public virtual PortableServer::RefCountServantBase
{
  // = DESCRIPTION
  //     The "B" side of a streamendpoint
public:
  TAO_StreamEndPoint_B (void);
  // Constructor

  virtual CORBA::Boolean multiconnect (AVStreams::streamQoS &the_qos,
                                       AVStreams::flowSpec &the_spec,
                                       CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::streamOpFailed,
                     AVStreams::noSuchFlow,
                     AVStreams::QoSRequestFailed,
                     AVStreams::FPError));
  // Used for internet-style multicast

  virtual ~TAO_StreamEndPoint_B (void);
  // Destructor
};

class TAO_AV_Export TAO_VDev
  :public virtual TAO_PropertySet,
   public virtual POA_AVStreams::VDev,
   public virtual PortableServer::RefCountServantBase
{
  // = DESCRIPTION
  //    Implements the VDev interface. One of these is created per connection,
  //    and represents device-specific parameters
public:
  TAO_VDev (void);
  // Default Constructor

  virtual CORBA::Boolean set_peer (AVStreams::StreamCtrl_ptr the_ctrl,
                                   AVStreams::VDev_ptr the_peer_dev,
                                   AVStreams::streamQoS &the_qos,
                                   const AVStreams::flowSpec &the_spec,
                                   CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow,
                     AVStreams::QoSRequestFailed,
                     AVStreams::streamOpFailed));
  // Called to tell the vdev who the streamctrl, peer vdev is

  virtual CORBA::Boolean set_Mcast_peer (AVStreams::StreamCtrl_ptr the_ctrl,
                                         AVStreams::MCastConfigIf_ptr a_mcastconfigif,
                                         AVStreams::streamQoS &the_qos,
                                         const AVStreams::flowSpec &the_spec,
                                         CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow,
                     AVStreams::QoSRequestFailed,
                     AVStreams::streamOpFailed));
  // Used to set the streamctrl and multicast device

  virtual void configure (const CosPropertyService::Property &the_config_mesg,
                          CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::PropertyException,
                     AVStreams::streamOpFailed));
  // Called by the peer VDev to configure the device (catch all)

  virtual void set_format (const char *flowName,
                           const char *format_name,
                           CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::notSupported));
  // Used to set a format on a flowname

  virtual void set_dev_params (const char *flowName,
                               const CosPropertyService::Properties &new_params,
                               CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::PropertyException,
                     AVStreams::streamOpFailed));
  // Used to set device parameters

  virtual CORBA::Boolean modify_QoS (AVStreams::streamQoS &the_qos,
                                     const AVStreams::flowSpec &the_spec,
                                     CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::noSuchFlow,
                     AVStreams::QoSRequestFailed));
  // Called to change QoS of the device

  virtual ~TAO_VDev (void);
  // Destructor

protected:
  virtual CORBA::Boolean set_media_ctrl (CORBA::Object_ptr media_ctrl,
                                         CORBA::Environment &env = CORBA::Environment::default_environment ());
  // hook called after set_peer is done to set the media ctrl of the peer vdev.

  AVStreams::StreamCtrl_var streamctrl_;
  // My stream controller

  AVStreams::VDev_var peer_;
  // My peer

  AVStreams::MCastConfigIf_var mcast_peer_;
  // The multicast VDev peer.
};

class TAO_AV_Endpoint_Strategy;

class TAO_AV_Export TAO_MMDevice
  :public virtual POA_AVStreams::MMDevice,
   public TAO_PropertySet,
   public virtual PortableServer::RefCountServantBase
{
  // = DESCRIPTION
  //     Implements a factory to create Endpoints and VDevs

public:

  enum MMDevice_Type {MMDEVICE_A = 0,MMDEVICE_B = 1};
  TAO_MMDevice (TAO_AV_Endpoint_Strategy *endpoint_strategy_);
  // Constructor

  TAO_MMDevice (TAO_MMDevice const &);
  // Copy constructor to fool g++

  virtual AVStreams::StreamEndPoint_ptr create_A_B (MMDevice_Type type,
                                                    AVStreams::StreamCtrl_ptr the_requester,
                                                     AVStreams::VDev_out the_vdev,
                                                     AVStreams::streamQoS &the_qos,
                                                     CORBA::Boolean_out met_qos,
                                                     char *&named_vdev,
                                                     const AVStreams::flowSpec &the_spec,
                                                     CORBA::Environment &env = CORBA::Environment::default_environment ());

  virtual AVStreams::StreamCtrl_ptr  bind (AVStreams::MMDevice_ptr peer_device,
                                           AVStreams::streamQoS &the_qos,
                                           CORBA::Boolean_out is_met,
                                           const AVStreams::flowSpec &the_spec,
                                           CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::streamOpFailed,
                     AVStreams::noSuchFlow,
                     AVStreams::QoSRequestFailed));
  // Can be used to request the MMDevice to create a new StreamCtrl,
  // and call bind_devs on it

  virtual AVStreams::StreamCtrl_ptr  bind_mcast (AVStreams::MMDevice_ptr first_peer,
                                                 AVStreams::streamQoS &the_qos,
                                                 CORBA::Boolean_out is_met,
                                                 const AVStreams::flowSpec &the_spec,
                                                 CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::streamOpFailed,
                     AVStreams::noSuchFlow,
                     AVStreams::QoSRequestFailed));
  // Multicast bind

  virtual AVStreams::StreamEndPoint_A_ptr  create_A (AVStreams::StreamCtrl_ptr the_requester,
                                                     AVStreams::VDev_out the_vdev,
                                                     AVStreams::streamQoS &the_qos,
                                                     CORBA::Boolean_out met_qos,
                                                     char *&named_vdev,
                                                     const AVStreams::flowSpec &the_spec,
                                                     CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::streamOpFailed,
                     AVStreams::streamOpDenied,
                     AVStreams::notSupported,
                     AVStreams::QoSRequestFailed,
                     AVStreams::noSuchFlow));
  // Called by StreamCtrl to create a "A" type streamandpoint and vdev

  virtual AVStreams::StreamEndPoint_B_ptr  create_B (AVStreams::StreamCtrl_ptr the_requester,
                                                     AVStreams::VDev_out the_vdev,
                                                     AVStreams::streamQoS &the_qos,
                                                     CORBA::Boolean_out met_qos,
                                                     char *&named_vdev,
                                                     const AVStreams::flowSpec &the_spec,
                                                     CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::streamOpFailed,
                     AVStreams::streamOpDenied,
                     AVStreams::notSupported,
                     AVStreams::QoSRequestFailed,
                     AVStreams::noSuchFlow));
  // Called by StreamCtrl to create a "B" type streamandpoint and vdev

  virtual void destroy (AVStreams::StreamEndPoint_ptr the_ep,
                        const char *vdev_name,
                        CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::notSupported));
  // Remove the StreamEndPoint and the related vdev

  virtual char * add_fdev (CORBA::Object_ptr the_fdev,
                           CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::notSupported,
                     AVStreams::streamOpFailed));
  // Not supported in the light profile, raises notsupported

  virtual CORBA::Object_ptr get_fdev (const char *flow_name,
                                      CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::notSupported,
                     AVStreams::noSuchFlow));
  // Not supported in the light profile, raises notsupported

  virtual void remove_fdev (const char *flow_name,
                            CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::notSupported,
                     AVStreams::noSuchFlow,
                     AVStreams::streamOpFailed));
  // Not supported in the light profile, raises notsupported

  virtual ~TAO_MMDevice (void);
  // Destructor

protected:
  char* add_fdev_i (AVStreams::FDev_ptr fdev,
                    CORBA::Environment &ACE_TRY_ENV)
      ACE_THROW_SPEC ((CORBA::SystemException,
                   AVStreams::notSupported,
                   AVStreams::streamOpFailed));
  // Helper method to implement add_fdev()

protected:

  TAO_AV_Endpoint_Strategy *endpoint_strategy_;

  u_int flow_count_;
  // Count of the number of flows in this MMDevice , used to
  // generate unique names for the flows.

  u_int flow_num_;
  // current flow number used for system generation of flow names.

  typedef ACE_Hash_Map_Manager <TAO_String_Hash_Key,AVStreams::FDev_ptr,ACE_Null_Mutex> FDev_Map;
  typedef ACE_Hash_Map_Iterator <TAO_String_Hash_Key,AVStreams::FDev_ptr,ACE_Null_Mutex> FDev_Map_Iterator;
  typedef ACE_Hash_Map_Entry <TAO_String_Hash_Key,AVStreams::FDev_ptr> FDev_Map_Entry;

  FDev_Map fdev_map_;
  // hash table for the flownames and its corresponding flowEndpoint
  // reference.

  AVStreams::flowSpec flows_;
  // sequence of supported flow names.

  TAO_StreamCtrl *stream_ctrl_;
};

class TAO_FlowConsumer;
class TAO_FlowProducer;

class TAO_AV_Export TAO_FlowConnection
 : public virtual POA_AVStreams::FlowConnection,
   public TAO_PropertySet,
   public virtual PortableServer::RefCountServantBase
{
  //  =TITLE
  //     Class to manage a flow connection.
  //
  //  =Description
  //     This class currently supports only one producer and one
  //     consumer  per flow.
public:
  TAO_FlowConnection (void);
  // default constructor.

  virtual void stop (CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // stop this flow.

  virtual void start (CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // start this flow.

  virtual void destroy (CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // destroy this flow.

  virtual CORBA::Boolean modify_QoS (AVStreams::QoS & new_qos,
                                     CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::QoSRequestFailed));
  // modify the QoS for this flow.

  virtual CORBA::Boolean use_flow_protocol (const char * fp_name,
                                            const CORBA::Any & fp_settings,
                                            CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::FPError,
                     AVStreams::notSupported));
  // use the specified flow protocol for this flow.

  virtual void push_event (const AVStreams::streamEvent & the_event,
                           CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));

  // pushes an event , to be handled by the application.

  virtual CORBA::Boolean connect_devs (AVStreams::FDev_ptr a_party,
                                       AVStreams::FDev_ptr b_party,
                                       AVStreams::QoS & the_qos,
                                       CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::streamOpFailed,
                     AVStreams::streamOpDenied,
                     AVStreams::QoSRequestFailed));
  // connect 2 Flow Devices.

  virtual CORBA::Boolean connect (AVStreams::FlowProducer_ptr flow_producer,
                                  AVStreams::FlowConsumer_ptr flow_consumer,
                                  AVStreams::QoS & the_qos,
                                  CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::formatMismatch,
                     AVStreams::FEPMismatch,
                     AVStreams::alreadyConnected));
  // Connect a flow producer and consumer under this flow connection.

  virtual CORBA::Boolean disconnect (CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // disconnect this flow connection.

  virtual CORBA::Boolean add_producer (AVStreams::FlowProducer_ptr flow_producer,
                                       AVStreams::QoS & the_qos,
                                       CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::alreadyConnected,
                     AVStreams::notSupported));
  // adds the producer to this flow connection.

  virtual CORBA::Boolean add_consumer (AVStreams::FlowConsumer_ptr flow_consumer,
                                       AVStreams::QoS & the_qos,
                                       CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::alreadyConnected));
  // adds a consumer to this flow connection.

  virtual CORBA::Boolean drop (AVStreams::FlowEndPoint_ptr target,
                               CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::notConnected));
  // drops a flow endpoint from the flow.

  int set_mcast_addr (ACE_CString addr,u_short port);
  void set_protocol (const char *protocol);
protected:
  typedef ACE_Unbounded_Set<AVStreams::FlowProducer_ptr> FlowProducer_Set;
  typedef ACE_Unbounded_Set_Iterator<AVStreams::FlowProducer_ptr> FlowProducer_SetItor;
  typedef ACE_Unbounded_Set<AVStreams::FlowConsumer_ptr> FlowConsumer_Set;
  typedef ACE_Unbounded_Set_Iterator<AVStreams::FlowConsumer_ptr> FlowConsumer_SetItor;

  FlowProducer_Set flow_producer_set_;
  FlowConsumer_Set flow_consumer_set_;
  CORBA::String_var fp_name_;
  CORBA::Any fp_settings_;
  CORBA::String_var producer_address_;
  // The multicast address returned by the producer.

  int ip_multicast_;
  // IP Multicasting is used.
  TAO_MCastConfigIf *mcastconfigif_i_;
  AVStreams::MCastConfigIf_var mcastconfigif_;
  u_short mcast_port_;
  ACE_CString mcast_addr_;
  CORBA::String_var protocol_;
};

class TAO_AV_Export TAO_FlowEndPoint :
  public virtual POA_AVStreams::FlowEndPoint,
  public virtual TAO_PropertySet,
  public virtual PortableServer::RefCountServantBase,
  public virtual TAO_Base_StreamEndPoint
{
  // = DESCRIPTION
  //     This class is used per flow e.g video flow and an audio flow
  //     to encapuslate the transport details.

public:

  TAO_FlowEndPoint (void);
  //default constructor.

  TAO_FlowEndPoint (const char *flowname,
                    AVStreams::protocolSpec &protocols,
                    const char *format);

  int open (const char *flowname,
            AVStreams::protocolSpec &protocols,
            const char *format);

  int set_flowname (const char *flowname);

  virtual void set_flow_handler (const char *flowname,
                                 TAO_AV_Flow_Handler *handler);

  virtual int set_protocol_object (const char *flowname,
                                   TAO_AV_Protocol_Object *object);

  virtual CORBA::Boolean lock (CORBA::Environment &env =
                               CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // lock the flow endpoint for a particular flow.

  virtual void unlock (CORBA::Environment &env =
                       CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // unlock the flow endpoint for subsequent use.


  virtual void destroy (CORBA::Environment &env =
                        CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // destroy this flow.

  virtual AVStreams::StreamEndPoint_ptr related_sep(CORBA::Environment &env =
                                                    CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // get method for the related streamendpoint under which this
  // flowendpoint is.

  virtual void related_sep (AVStreams::StreamEndPoint_ptr related_sep,
                            CORBA::Environment &env =
                            CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // set method for the related streamendpoint under which this
  // flowendpoint is.

  virtual AVStreams::FlowConnection_ptr related_flow_connection(CORBA::Environment &env =
                                                                CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));

  // accessor for the related flow connection attribute.

  virtual void related_flow_connection (AVStreams::FlowConnection_ptr related_flow_connection,
                                        CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // set method for the related flow connection attribute.

  virtual AVStreams::FlowEndPoint_ptr get_connected_fep (CORBA::Environment &env =
                                                         CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::notConnected,
                     AVStreams::notSupported));
  // returns the other flowendpoint to which this is connected.

  virtual CORBA::Boolean use_flow_protocol (const char * fp_name,
                                            const CORBA::Any & fp_settings,
                                            CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::FPError,
                     AVStreams::notSupported));
  /// use the specified flow protocol.

  virtual void set_format (const char * format,
                           CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::notSupported));
  // sets the data format.

  virtual void set_dev_params (const CosPropertyService::Properties & new_settings,
                               CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::PropertyException,
                     AVStreams::streamOpFailed));
  // sets the device parameters.

  virtual void set_protocol_restriction (const AVStreams::protocolSpec & the_spec,
                                         CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::notSupported));
  // sets the list of protocols to be used.

  virtual CORBA::Boolean is_fep_compatible (AVStreams::FlowEndPoint_ptr fep,
                                            CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::formatMismatch,
                     AVStreams::deviceQosMismatch));
  // checks whether the passed flowendpoint is compatible with this.

  virtual CORBA::Boolean set_peer (AVStreams::FlowConnection_ptr the_fc,
                                   AVStreams::FlowEndPoint_ptr the_peer_fep,
                                   AVStreams::QoS & the_qos,
                                   CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::QoSRequestFailed,
                     AVStreams::streamOpFailed));
  // sets the peer flowendpoint.

  virtual CORBA::Boolean set_Mcast_peer (AVStreams::FlowConnection_ptr the_fc,
                                         AVStreams::MCastConfigIf_ptr a_mcastconfigif,
                                         AVStreams::QoS & the_qos,
                                         CORBA::Environment &env =
                                         CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::QoSRequestFailed));
  // sets the multicast peer flowendpoint, not implemented.


  virtual CORBA::Boolean connect_to_peer (AVStreams::QoS & the_qos,
                                          const char * address,
                                          const char * use_flow_protocol,
                                          CORBA::Environment &env =
                                          CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::failedToConnect,
                     AVStreams::FPError,
                     AVStreams::QoSRequestFailed)) = 0;
  // This should be implemented in both the FlowProducer and consumer and hence is
  // pure virtual since we need to know the role of the flowendpoint to create appropriate
  // protocol objects. eg. in SFP to create Producer Object/ Consumer Object.

  virtual CORBA::Boolean connect_to_peer_i (TAO_FlowSpec_Entry::Role role,
                                            AVStreams::QoS & the_qos,
                                            const char * address,
                                            const char * use_flow_protocol,
                                            CORBA::Environment &env =
                                            CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::failedToConnect,
                     AVStreams::FPError,
                     AVStreams::QoSRequestFailed));
  // connect to the peer endpoint.

  virtual char * go_to_listen (AVStreams::QoS & the_qos,
                               CORBA::Boolean is_mcast,
                               AVStreams::FlowEndPoint_ptr peer,
                               char *& flowProtocol,
                               CORBA::Environment &env =
                               CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::failedToListen,
                     AVStreams::FPError,
                     AVStreams::QoSRequestFailed)) = 0;
  // This should be implemented in both the FlowProducer and consumer and hence is
  // pure virtual since we need to know the role of the flowendpoint to create appropriate
  // protocol objects. eg. in SFP to create Producer Object/ Consumer Object.

  virtual char * go_to_listen_i (TAO_FlowSpec_Entry::Role role,
                                 AVStreams::QoS & the_qos,
                                 CORBA::Boolean is_mcast,
                                 AVStreams::FlowEndPoint_ptr peer,
                                 char *& flowProtocol,
                                 CORBA::Environment &env =
                                 CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::failedToListen,
                     AVStreams::FPError,
                     AVStreams::QoSRequestFailed));

  // listen request from the peer.

protected:
  AVStreams::StreamEndPoint_var related_sep_;
  // The related streamendpoint.

  AVStreams::FlowConnection_var related_flow_connection_;
  // The related flow connection reference

  AVStreams::FlowEndPoint_var peer_fep_;
  // The peer flowendpoint reference.

  AVStreams::protocolSpec protocols_;
  // Available protocols for this flowendpoint.

  AVStreams::protocolSpec protocol_addresses_;
  // Address information for the protocols.

  AVStreams::MCastConfigIf_var mcast_peer_;
  // The multicast peer endpoint.

  CORBA::Boolean lock_;
  // Lock.

  CORBA::String_var format_;
  CORBA::String_var flowname_;
  CosPropertyService::Properties dev_params_;
  TAO_AV_FlowSpecSet flow_spec_set_;
  CORBA::String_var reverse_channel_;
};

class TAO_AV_Export TAO_FlowProducer:
  public virtual POA_AVStreams::FlowProducer,
  public virtual TAO_FlowEndPoint,
  public virtual PortableServer::RefCountServantBase
{
public:
  TAO_FlowProducer (void);
  // default constructor

  TAO_FlowProducer (const char *flowname,
                    AVStreams::protocolSpec protocols,
                    const char *format);

  virtual char * get_rev_channel (const char * pcol_name,
                                  CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // get the reverse channel, to be used for feedback for protocols like UDP.
  // @@Naga: In the spec this is defined in the TAO_FlowProducer but it seems more reasonable for this
  // to be in a FlowEndPoint since any of the flowendpoints can be made to listen. So in the case of
  // UDP if the producer is listening and the consumer connects (logically) then the producer needs to
  // know the reverse channel on its peer fep to send data to.

  virtual void stop (CORBA::Environment &env =
                     CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // stop this flow, to be overridden by the application.

  virtual void start (CORBA::Environment &env =
                      CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // start this flow, to be overridden by the application.

  virtual char * go_to_listen (AVStreams::QoS & the_qos,
                               CORBA::Boolean is_mcast,
                               AVStreams::FlowEndPoint_ptr peer,
                               char *& flowProtocol,
                               CORBA::Environment &env =
                               CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::failedToListen,
                     AVStreams::FPError,
                     AVStreams::QoSRequestFailed));

  virtual CORBA::Boolean connect_to_peer (AVStreams::QoS & the_qos,
                                          const char * address,
                                          const char * use_flow_protocol,
                                          CORBA::Environment &env =
                                          CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::failedToConnect,
                     AVStreams::FPError,
                     AVStreams::QoSRequestFailed));

  virtual char * connect_mcast (AVStreams::QoS & the_qos,
                                CORBA::Boolean_out is_met,
                                const char * address,
                                const char * use_flow_protocol,
                                CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::failedToConnect,
                     AVStreams::notSupported,
                     AVStreams::FPError,
                     AVStreams::QoSRequestFailed));

  // connect to the multicast address, not implemented.


  virtual void set_key (const AVStreams::key & the_key,
                        CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // sets the public key  to be used for encryption of the data.

  virtual void set_source_id (CORBA::Long source_id,
                              CORBA::Environment &env =CORBA::Environment::default_environment())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // sets the source id of this flow producer so that it can be used
  // to distinguish this producer from others in the multicast case.

protected:
  CORBA::Long source_id_;
  // source id of this producer.
  CORBA::String_var peer_address_;
};

class TAO_AV_Export TAO_FlowConsumer :
  public virtual POA_AVStreams::FlowConsumer,
  public virtual TAO_FlowEndPoint,
  public virtual PortableServer::RefCountServantBase
{
public:
  TAO_FlowConsumer (void);
  // default constructor.

  TAO_FlowConsumer (const char *flowname,
                    AVStreams::protocolSpec protocols,
                    const char *format);

  virtual void stop (CORBA::Environment &env =
                     CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // stop this flow, to be overridden by the application.

  virtual void start (CORBA::Environment &env =
                      CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException));
  // start this flow, to be overridden by the application.

  virtual char * go_to_listen (AVStreams::QoS & the_qos,
                               CORBA::Boolean is_mcast,
                               AVStreams::FlowEndPoint_ptr peer,
                               char *& flowProtocol,
                               CORBA::Environment &env =
                               CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::failedToListen,
                     AVStreams::FPError,
                     AVStreams::QoSRequestFailed));

  virtual CORBA::Boolean connect_to_peer (AVStreams::QoS & the_qos,
                                          const char * address,
                                          const char * use_flow_protocol,
                                          CORBA::Environment &env =
                                          CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::failedToConnect,
                     AVStreams::FPError,
                     AVStreams::QoSRequestFailed));
};


class TAO_AV_Export TAO_MediaControl
  :public virtual POA_AVStreams::MediaControl,
   public virtual PortableServer::RefCountServantBase
{
  // = TITLE
  //     Abstract Mediacontrol class.
  //
  // = DESCRIPTION
  //     The following are to be handled by the specialized media control for the specific
  //     media like camera,speaker.
public:
  TAO_MediaControl (void);
  // default constructor

  virtual AVStreams::Position get_media_position (AVStreams::PositionOrigin an_origin,
                                                  AVStreams::PositionKey a_key,
                                                  CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::MediaControl::PostionKeyNotSupported)) =0;

  virtual void set_media_position (const AVStreams::Position & a_position,
                                   CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::MediaControl::PostionKeyNotSupported,
                     AVStreams::InvalidPosition)) =0;

  virtual void start (const AVStreams::Position & a_position,
                      CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::InvalidPosition)) =0;

  virtual void pause (const AVStreams::Position & a_position,
                      CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::InvalidPosition)) =0;

  virtual void resume (const AVStreams::Position & a_position,
                       CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::InvalidPosition)) =0;

  virtual void stop (const AVStreams::Position & a_position,
                     CORBA::Environment &env = CORBA::Environment::default_environment ())
    ACE_THROW_SPEC ((CORBA::SystemException,
                     AVStreams::InvalidPosition)) =0;

};

class TAO_AV_Export TAO_AV_QoS
{
public:
  TAO_AV_QoS (void);
  // constructor.

  TAO_AV_QoS (AVStreams::streamQoS &stream_qos);
  // constructor taking a stream qos parameter.

  int set (AVStreams::streamQoS &stream_qos);
  // sets the maps with the QoS paramter.

  int get_flow_qos (const char *flowname,AVStreams::QoS &flow_qos);
  // gets the flow_qos.

  int convert (AVStreams::streamQoS &network_qos);
  // converts the application level QoS to Network-level QoS.


protected:
  AVStreams::streamQoS stream_qos_;
  // Stream Qos.

  ACE_Hash_Map_Manager<TAO_String_Hash_Key,AVStreams::QoS,ACE_Null_Mutex> qos_map_;
};

#include "Transport.h"

#if defined (__ACE_INLINE__)
#include "AVStreams_i.i"
#endif /* __ACE_INLINE__ */

#include "Flows_T.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#include "ace/post.h"
#endif /* AVSTREAMS_I_H */
