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

#ifndef _TAO_IDL_ORIG_MESSAGINGS_H_
#define _TAO_IDL_ORIG_MESSAGINGS_H_

#include "ace/pre.h"

#include "messaging_export.h"
#include "Messaging.h"
#include "tao/PortableServer/PolicyS.h"
#include "tao/TimeBaseS.h"
#include "tao/Messaging_SyncScopeC.h"

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


TAO_NAMESPACE  POA_Messaging
{
#if (TAO_HAS_AMI_CALLBACK == 1) || (TAO_HAS_AMI_POLLER == 1)
  class ReplyHandler;
  typedef ReplyHandler *ReplyHandler_ptr;
  // Forward Classes Declaration
  class _TAO_ReplyHandler_ThruPOA_Proxy_Impl;
  class _TAO_ReplyHandler_Direct_Proxy_Impl;
  class _TAO_ReplyHandler_Strategized_Proxy_Broker;
  
  class TAO_Messaging_Export ReplyHandler
    : public virtual PortableServer::ServantBase
  {
  protected:
    ReplyHandler (void);

  public:
    ReplyHandler (const ReplyHandler& rhs);
    virtual ~ReplyHandler (void);


    virtual CORBA::Boolean _is_a (
        const char* logical_type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    virtual void* _downcast (
        const char* logical_type_id
      );

    static void _is_a_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *servant_upcall
        ACE_ENV_ARG_DECL
      );

    static void _non_existent_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *servant_upcall
        ACE_ENV_ARG_DECL
      );

    static void _interface_skel (
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


    ::Messaging::ReplyHandler *_this (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;


  };
#endif /* TAO_HAS_AMI_CALLBACK == 1 || TAO_HAS_AMI_POLLER == 1 */

  
#if (TAO_HAS_AMI_CALLBACK == 1) || (TAO_HAS_AMI_POLLER == 1)
  ///////////////////////////////////////////////////////////////////////
  //               Strategized Proxy Broker Declaration 
  //
  
  class TAO_Messaging_Export _TAO_ReplyHandler_Strategized_Proxy_Broker : public virtual ::Messaging::_TAO_ReplyHandler_Proxy_Broker
  {
  public: 
    _TAO_ReplyHandler_Strategized_Proxy_Broker (void);
    
    virtual ~_TAO_ReplyHandler_Strategized_Proxy_Broker (void);
    
    virtual ::Messaging::_TAO_ReplyHandler_Proxy_Impl &select_proxy (
      ::Messaging::ReplyHandler *object
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
    ::Messaging::_TAO_ReplyHandler_Proxy_Impl
    *proxy_cache_[TAO_Collocation_Strategies::CS_LAST];
    
    TAO_SYNCH_MUTEX mutex_;
    // This funxtion is used to get an handle to the unique instance
    // of the Strategized Proxy Broker that is available for a given
    // interface.
  
  public:
    static _TAO_ReplyHandler_Strategized_Proxy_Broker *the_TAO_ReplyHandler_Strategized_Proxy_Broker (void);
  };
  
  
  //
  //            End Strategized Proxy Broker Declaration 
  ///////////////////////////////////////////////////////////////////////
  
  
  ///////////////////////////////////////////////////////////////////////
  //                    ThruPOA  Impl. Declaration
  //
  
  class TAO_Messaging_Export _TAO_ReplyHandler_ThruPOA_Proxy_Impl : 
    public virtual ::Messaging::_TAO_ReplyHandler_Proxy_Impl,
    public virtual TAO_ThruPOA_Object_Proxy_Impl
  {
  public:
    _TAO_ReplyHandler_ThruPOA_Proxy_Impl (void);
    
    virtual ~_TAO_ReplyHandler_ThruPOA_Proxy_Impl (void) { }
    
    
  };
  
  //
  //                ThruPOA  Proxy Impl. Declaration
  ///////////////////////////////////////////////////////////////////////
  
  
///////////////////////////////////////////////////////////////////////
//                    Direct  Impl. Declaration
//

class TAO_Messaging_Export _TAO_ReplyHandler_Direct_Proxy_Impl : 
  public virtual Messaging::_TAO_ReplyHandler_Proxy_Impl,
  public virtual TAO_Direct_Object_Proxy_Impl
{
public:
  _TAO_ReplyHandler_Direct_Proxy_Impl (void);
  
  virtual ~_TAO_ReplyHandler_Direct_Proxy_Impl (void) { }
  
  };


//
//                Direct  Proxy Impl. Declaration
///////////////////////////////////////////////////////////////////////

#endif /* TAO_HAS_AMI_CALLBACK == 1 || TAO_HAS_AMI_POLLER == 1 */

}
TAO_NAMESPACE_CLOSE // module Messaging

#include "MessagingS_T.h"

#if defined (__ACE_INLINE__)
#include "MessagingS.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */
