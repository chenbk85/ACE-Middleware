// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:443

#ifndef _TAO_IDL_ORIG_IMPLREPOS_H_
#define _TAO_IDL_ORIG_IMPLREPOS_H_

#include "ace/pre.h"
#include "ImplRepoC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"
#include "tao/PortableServer/Collocated_Object.h"
#include "tao/PortableServer/ThruPOA_Object_Proxy_Impl.h"
#include "tao/PortableServer/Direct_Object_Proxy_Impl.h"

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_sh.cpp:49

TAO_NAMESPACE  POA_ImplementationRepository
{
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_sh.cpp:86
  
  class ServerObject;
  typedef ServerObject *ServerObject_ptr;
  
  class _TAO_ServerObject_ThruPOA_Proxy_Impl;
  class _TAO_ServerObject_Direct_Proxy_Impl;
  class _TAO_ServerObject_Strategized_Proxy_Broker;
  
  class TAO_PortableServer_Export ServerObject
    : public virtual PortableServer::ServantBase
  {
  protected:
    ServerObject (void);
  
  public:
    ServerObject (const ServerObject& rhs);
    virtual ~ServerObject (void);
    
    virtual CORBA::Boolean _is_a (
        const char* logical_type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual void* _downcast (
        const char* logical_type_id
      );
    
    static void _is_a_skel (
        TAO_ServerRequest &req,
        void *servant,
        void *servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    static void _non_existent_skel (
        TAO_ServerRequest &req,
        void *servant,
        void *servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    static void _interface_skel (
        TAO_ServerRequest &req,
        void *servant,
        void *servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    static void _component_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    virtual void _dispatch (
        TAO_ServerRequest &req,
        void *_servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    ::ImplementationRepository::ServerObject *_this (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void ping (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    static void ping_skel (
        TAO_ServerRequest &_tao_req,
        void *_tao_servant,
        void *_tao_servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void shutdown (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    static void shutdown_skel (
        TAO_ServerRequest &_tao_req,
        void *_tao_servant,
        void *_tao_servant_upcall
        ACE_ENV_ARG_DECL
      );
  };  
  
  ///////////////////////////////////////////////////////////////////////
  //               Strategized Proxy Broker Declaration 
  //
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/strategized_proxy_broker_sh.cpp:39
  
  class TAO_PortableServer_Export _TAO_ServerObject_Strategized_Proxy_Broker : public virtual ::ImplementationRepository::_TAO_ServerObject_Proxy_Broker
  {
  public: 
    _TAO_ServerObject_Strategized_Proxy_Broker (void);
    
    virtual ~_TAO_ServerObject_Strategized_Proxy_Broker (void);
    
    virtual ::ImplementationRepository::_TAO_ServerObject_Proxy_Impl &select_proxy (
      ::ImplementationRepository::ServerObject *object
      ACE_ENV_ARG_DECL
    );
  
  private:
    // Helper methods that takes care to create the proxy
    // as soon as their use is necessary.
    void create_proxy (
      int collocation_strategy
      ACE_ENV_ARG_DECL
    );
    
    // Caches the proxy implementations. The proxy implementation
    // are totally stateless, and those can be shared by all the
    // instances of a given IDL interface type.
    ::ImplementationRepository::_TAO_ServerObject_Proxy_Impl
    *proxy_cache_[TAO_Collocation_Strategies::CS_LAST];
    
    TAO_SYNCH_MUTEX mutex_;
    // This funxtion is used to get an handle to the unique instance
    // of the Strategized Proxy Broker that is available for a given
    // interface.
  
  public:
    static _TAO_ServerObject_Strategized_Proxy_Broker *the_TAO_ServerObject_Strategized_Proxy_Broker (void);
  };
  
  //
  //            End Strategized Proxy Broker Declaration 
  ///////////////////////////////////////////////////////////////////////
  
  
  ///////////////////////////////////////////////////////////////////////
  //                    ThruPOA  Impl. Declaration
  //
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/thru_poa_proxy_impl_sh.cpp:37
  
  class TAO_PortableServer_Export _TAO_ServerObject_ThruPOA_Proxy_Impl : 
    public virtual ::ImplementationRepository::_TAO_ServerObject_Proxy_Impl,
    public virtual TAO_ThruPOA_Object_Proxy_Impl
  {
  public:
    _TAO_ServerObject_ThruPOA_Proxy_Impl (void);
    
    virtual ~_TAO_ServerObject_ThruPOA_Proxy_Impl (void) {}
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    virtual void ping (
        CORBA::Object *_collocated_tao_target_
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    virtual void shutdown (
        CORBA::Object *_collocated_tao_target_
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
  };
  
  //
  //                ThruPOA  Proxy Impl. Declaration
  ///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//                    Direct  Impl. Declaration
//

class TAO_PortableServer_Export _TAO_ServerObject_Direct_Proxy_Impl : 
  public virtual ImplementationRepository::_TAO_ServerObject_Proxy_Impl,
  public virtual TAO_Direct_Object_Proxy_Impl
{
public:
  _TAO_ServerObject_Direct_Proxy_Impl (void);
  
  virtual ~_TAO_ServerObject_Direct_Proxy_Impl (void) {}
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void ping (
      CORBA::Object *_collocated_tao_target_
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void shutdown (
      CORBA::Object *_collocated_tao_target_
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));};


//
//                Direct  Proxy Impl. Declaration
///////////////////////////////////////////////////////////////////////

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_sh.cpp:86

class Administration;
typedef Administration *Administration_ptr;

class _TAO_Administration_ThruPOA_Proxy_Impl;
class _TAO_Administration_Direct_Proxy_Impl;
class _TAO_Administration_Strategized_Proxy_Broker;

class TAO_PortableServer_Export Administration
  : public virtual PortableServer::ServantBase
{
protected:
  Administration (void);

public:
  Administration (const Administration& rhs);
  virtual ~Administration (void);
  
  virtual CORBA::Boolean _is_a (
      const char* logical_type_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  virtual void* _downcast (
      const char* logical_type_id
    );
  
  static void _is_a_skel (
      TAO_ServerRequest &req,
      void *servant,
      void *servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  static void _non_existent_skel (
      TAO_ServerRequest &req,
      void *servant,
      void *servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  static void _interface_skel (
      TAO_ServerRequest &req,
      void *servant,
      void *servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  static void _component_skel (
      TAO_ServerRequest &req,
      void *obj,
      void *servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  virtual void _dispatch (
      TAO_ServerRequest &req,
      void *_servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  ::ImplementationRepository::Administration *_this (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    );
  
  virtual const char* _interface_repository_id (void) const;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual void activate_server (
      const char * server
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
      , ImplementationRepository::CannotActivate
    )) = 0;
  
  static void activate_server_skel (
      TAO_ServerRequest &_tao_req,
      void *_tao_servant,
      void *_tao_servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual char * activate_server_with_startup (
      const char * server,
      CORBA::Long check_startup
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
      , ImplementationRepository::CannotActivate
    )) = 0;
  
  static void activate_server_with_startup_skel (
      TAO_ServerRequest &_tao_req,
      void *_tao_servant,
      void *_tao_servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual void register_server (
      const char * server,
      const ImplementationRepository::StartupOptions & options
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::AlreadyRegistered
    )) = 0;
  
  static void register_server_skel (
      TAO_ServerRequest &_tao_req,
      void *_tao_servant,
      void *_tao_servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual void reregister_server (
      const char * server,
      const ImplementationRepository::StartupOptions & options
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;
  
  static void reregister_server_skel (
      TAO_ServerRequest &_tao_req,
      void *_tao_servant,
      void *_tao_servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual void remove_server (
      const char * server
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
    )) = 0;
  
  static void remove_server_skel (
      TAO_ServerRequest &_tao_req,
      void *_tao_servant,
      void *_tao_servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual void shutdown_server (
      const char * server
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
    )) = 0;
  
  static void shutdown_server_skel (
      TAO_ServerRequest &_tao_req,
      void *_tao_servant,
      void *_tao_servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual char * server_is_running (
      const char * server,
      const char * addr,
      ImplementationRepository::ServerObject_ptr server_object
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
    )) = 0;
  
  static void server_is_running_skel (
      TAO_ServerRequest &_tao_req,
      void *_tao_servant,
      void *_tao_servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual void server_is_shutting_down (
      const char * server
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
    )) = 0;
  
  static void server_is_shutting_down_skel (
      TAO_ServerRequest &_tao_req,
      void *_tao_servant,
      void *_tao_servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual void find (
      const char * server,
      ImplementationRepository::ServerInformation_out info
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
    )) = 0;
  
  static void find_skel (
      TAO_ServerRequest &_tao_req,
      void *_tao_servant,
      void *_tao_servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual void list (
      CORBA::ULong how_many,
      ImplementationRepository::ServerInformationList_out server_list,
      ImplementationRepository::ServerInformationIterator_out server_iterator
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;
  
  static void list_skel (
      TAO_ServerRequest &_tao_req,
      void *_tao_servant,
      void *_tao_servant_upcall
      ACE_ENV_ARG_DECL
    );
};

///////////////////////////////////////////////////////////////////////
//               Strategized Proxy Broker Declaration 
//

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/strategized_proxy_broker_sh.cpp:39

class TAO_PortableServer_Export _TAO_Administration_Strategized_Proxy_Broker : public virtual ::ImplementationRepository::_TAO_Administration_Proxy_Broker
{
public: 
  _TAO_Administration_Strategized_Proxy_Broker (void);
  
  virtual ~_TAO_Administration_Strategized_Proxy_Broker (void);
  
  virtual ::ImplementationRepository::_TAO_Administration_Proxy_Impl &select_proxy (
    ::ImplementationRepository::Administration *object
    ACE_ENV_ARG_DECL
  );

private:
  // Helper methods that takes care to create the proxy
  // as soon as their use is necessary.
  void create_proxy (
    int collocation_strategy
    ACE_ENV_ARG_DECL
  );
  
  // Caches the proxy implementations. The proxy implementation
  // are totally stateless, and those can be shared by all the
  // instances of a given IDL interface type.
  ::ImplementationRepository::_TAO_Administration_Proxy_Impl
  *proxy_cache_[TAO_Collocation_Strategies::CS_LAST];
  
  TAO_SYNCH_MUTEX mutex_;
  // This funxtion is used to get an handle to the unique instance
  // of the Strategized Proxy Broker that is available for a given
  // interface.

public:
  static _TAO_Administration_Strategized_Proxy_Broker *the_TAO_Administration_Strategized_Proxy_Broker (void);
};

//
//            End Strategized Proxy Broker Declaration 
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//                    ThruPOA  Impl. Declaration
//

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/thru_poa_proxy_impl_sh.cpp:37

class TAO_PortableServer_Export _TAO_Administration_ThruPOA_Proxy_Impl : 
  public virtual ::ImplementationRepository::_TAO_Administration_Proxy_Impl,
  public virtual TAO_ThruPOA_Object_Proxy_Impl
{
public:
  _TAO_Administration_ThruPOA_Proxy_Impl (void);
  
  virtual ~_TAO_Administration_ThruPOA_Proxy_Impl (void) {}
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void activate_server (
      CORBA::Object *_collocated_tao_target_,
      const char * server
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
      , ImplementationRepository::CannotActivate
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual char * activate_server_with_startup (
      CORBA::Object *_collocated_tao_target_,
      const char * server,
      CORBA::Long check_startup
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
      , ImplementationRepository::CannotActivate
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void register_server (
      CORBA::Object *_collocated_tao_target_,
      const char * server,
      const ImplementationRepository::StartupOptions & options
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::AlreadyRegistered
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void reregister_server (
      CORBA::Object *_collocated_tao_target_,
      const char * server,
      const ImplementationRepository::StartupOptions & options
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void remove_server (
      CORBA::Object *_collocated_tao_target_,
      const char * server
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void shutdown_server (
      CORBA::Object *_collocated_tao_target_,
      const char * server
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual char * server_is_running (
      CORBA::Object *_collocated_tao_target_,
      const char * server,
      const char * addr,
      ImplementationRepository::ServerObject_ptr server_object
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void server_is_shutting_down (
      CORBA::Object *_collocated_tao_target_,
      const char * server
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void find (
      CORBA::Object *_collocated_tao_target_,
      const char * server,
      ImplementationRepository::ServerInformation_out info
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void list (
      CORBA::Object *_collocated_tao_target_,
      CORBA::ULong how_many,
      ImplementationRepository::ServerInformationList_out server_list,
      ImplementationRepository::ServerInformationIterator_out server_iterator
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
};

//
//                ThruPOA  Proxy Impl. Declaration
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//                    Direct  Impl. Declaration
//

class TAO_PortableServer_Export _TAO_Administration_Direct_Proxy_Impl : 
  public virtual ImplementationRepository::_TAO_Administration_Proxy_Impl,
  public virtual TAO_Direct_Object_Proxy_Impl
{
public:
  _TAO_Administration_Direct_Proxy_Impl (void);
  
  virtual ~_TAO_Administration_Direct_Proxy_Impl (void) {}
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void activate_server (
      CORBA::Object *_collocated_tao_target_,
      const char * server
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
      , ImplementationRepository::CannotActivate
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual char * activate_server_with_startup (
      CORBA::Object *_collocated_tao_target_,
      const char * server,
      CORBA::Long check_startup
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
      , ImplementationRepository::CannotActivate
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void register_server (
      CORBA::Object *_collocated_tao_target_,
      const char * server,
      const ImplementationRepository::StartupOptions & options
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::AlreadyRegistered
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void reregister_server (
      CORBA::Object *_collocated_tao_target_,
      const char * server,
      const ImplementationRepository::StartupOptions & options
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void remove_server (
      CORBA::Object *_collocated_tao_target_,
      const char * server
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void shutdown_server (
      CORBA::Object *_collocated_tao_target_,
      const char * server
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual char * server_is_running (
      CORBA::Object *_collocated_tao_target_,
      const char * server,
      const char * addr,
      ImplementationRepository::ServerObject_ptr server_object
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void server_is_shutting_down (
      CORBA::Object *_collocated_tao_target_,
      const char * server
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void find (
      CORBA::Object *_collocated_tao_target_,
      const char * server,
      ImplementationRepository::ServerInformation_out info
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
      , ImplementationRepository::NotFound
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void list (
      CORBA::Object *_collocated_tao_target_,
      CORBA::ULong how_many,
      ImplementationRepository::ServerInformationList_out server_list,
      ImplementationRepository::ServerInformationIterator_out server_iterator
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));};


//
//                Direct  Proxy Impl. Declaration
///////////////////////////////////////////////////////////////////////

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_sh.cpp:86

class ServerInformationIterator;
typedef ServerInformationIterator *ServerInformationIterator_ptr;

class _TAO_ServerInformationIterator_ThruPOA_Proxy_Impl;
class _TAO_ServerInformationIterator_Direct_Proxy_Impl;
class _TAO_ServerInformationIterator_Strategized_Proxy_Broker;

class TAO_PortableServer_Export ServerInformationIterator
  : public virtual PortableServer::ServantBase
{
protected:
  ServerInformationIterator (void);

public:
  ServerInformationIterator (const ServerInformationIterator& rhs);
  virtual ~ServerInformationIterator (void);
  
  virtual CORBA::Boolean _is_a (
      const char* logical_type_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  virtual void* _downcast (
      const char* logical_type_id
    );
  
  static void _is_a_skel (
      TAO_ServerRequest &req,
      void *servant,
      void *servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  static void _non_existent_skel (
      TAO_ServerRequest &req,
      void *servant,
      void *servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  static void _interface_skel (
      TAO_ServerRequest &req,
      void *servant,
      void *servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  static void _component_skel (
      TAO_ServerRequest &req,
      void *obj,
      void *servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  virtual void _dispatch (
      TAO_ServerRequest &req,
      void *_servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  ::ImplementationRepository::ServerInformationIterator *_this (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    );
  
  virtual const char* _interface_repository_id (void) const;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual CORBA::Boolean next_n (
      CORBA::ULong how_many,
      ImplementationRepository::ServerInformationList_out server_list
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;
  
  static void next_n_skel (
      TAO_ServerRequest &_tao_req,
      void *_tao_servant,
      void *_tao_servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual void destroy (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;
  
  static void destroy_skel (
      TAO_ServerRequest &_tao_req,
      void *_tao_servant,
      void *_tao_servant_upcall
      ACE_ENV_ARG_DECL
    );
};

///////////////////////////////////////////////////////////////////////
//               Strategized Proxy Broker Declaration 
//

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/strategized_proxy_broker_sh.cpp:39

class TAO_PortableServer_Export _TAO_ServerInformationIterator_Strategized_Proxy_Broker : public virtual ::ImplementationRepository::_TAO_ServerInformationIterator_Proxy_Broker
{
public: 
  _TAO_ServerInformationIterator_Strategized_Proxy_Broker (void);
  
  virtual ~_TAO_ServerInformationIterator_Strategized_Proxy_Broker (void);
  
  virtual ::ImplementationRepository::_TAO_ServerInformationIterator_Proxy_Impl &select_proxy (
    ::ImplementationRepository::ServerInformationIterator *object
    ACE_ENV_ARG_DECL
  );

private:
  // Helper methods that takes care to create the proxy
  // as soon as their use is necessary.
  void create_proxy (
    int collocation_strategy
    ACE_ENV_ARG_DECL
  );
  
  // Caches the proxy implementations. The proxy implementation
  // are totally stateless, and those can be shared by all the
  // instances of a given IDL interface type.
  ::ImplementationRepository::_TAO_ServerInformationIterator_Proxy_Impl
  *proxy_cache_[TAO_Collocation_Strategies::CS_LAST];
  
  TAO_SYNCH_MUTEX mutex_;
  // This funxtion is used to get an handle to the unique instance
  // of the Strategized Proxy Broker that is available for a given
  // interface.

public:
  static _TAO_ServerInformationIterator_Strategized_Proxy_Broker *the_TAO_ServerInformationIterator_Strategized_Proxy_Broker (void);
};

//
//            End Strategized Proxy Broker Declaration 
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//                    ThruPOA  Impl. Declaration
//

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/thru_poa_proxy_impl_sh.cpp:37

class TAO_PortableServer_Export _TAO_ServerInformationIterator_ThruPOA_Proxy_Impl : 
  public virtual ::ImplementationRepository::_TAO_ServerInformationIterator_Proxy_Impl,
  public virtual TAO_ThruPOA_Object_Proxy_Impl
{
public:
  _TAO_ServerInformationIterator_ThruPOA_Proxy_Impl (void);
  
  virtual ~_TAO_ServerInformationIterator_ThruPOA_Proxy_Impl (void) {}
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual CORBA::Boolean next_n (
      CORBA::Object *_collocated_tao_target_,
      CORBA::ULong how_many,
      ImplementationRepository::ServerInformationList_out server_list
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void destroy (
      CORBA::Object *_collocated_tao_target_
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
};

//
//                ThruPOA  Proxy Impl. Declaration
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//                    Direct  Impl. Declaration
//

class TAO_PortableServer_Export _TAO_ServerInformationIterator_Direct_Proxy_Impl : 
  public virtual ImplementationRepository::_TAO_ServerInformationIterator_Proxy_Impl,
  public virtual TAO_Direct_Object_Proxy_Impl
{
public:
  _TAO_ServerInformationIterator_Direct_Proxy_Impl (void);
  
  virtual ~_TAO_ServerInformationIterator_Direct_Proxy_Impl (void) {}
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual CORBA::Boolean next_n (
      CORBA::Object *_collocated_tao_target_,
      CORBA::ULong how_many,
      ImplementationRepository::ServerInformationList_out server_list
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
  
  virtual void destroy (
      CORBA::Object *_collocated_tao_target_
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));};


//
//                Direct  Proxy Impl. Declaration
///////////////////////////////////////////////////////////////////////



// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_sh.cpp:80

}
TAO_NAMESPACE_CLOSE // module ImplementationRepository

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:1044

#include "ImplRepoS_T.h"

#if defined (__ACE_INLINE__)
#include "ImplRepoS.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */
