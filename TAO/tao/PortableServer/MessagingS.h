/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_ORIG_MESSAGINGS_H_
#define _TAO_IDL_ORIG_MESSAGINGS_H_

#include "ace/pre.h"

#include "tao/orbconf.h"

#if (TAO_HAS_CORBA_MESSAGING == 1)

#include "PortableServerC.h"
#include "Servant_Base.h"
#include "Collocated_Object.h"
#include "tao/TimeBaseS.h"
#include "tao/MessagingC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

TAO_NAMESPACE  POA_Messaging
{

#if (TAO_HAS_AMI_CALLBACK == 1)

  class ReplyHandler;
  typedef ReplyHandler *ReplyHandler_ptr;
  class TAO_PortableServer_Export ReplyHandler :  public virtual PortableServer::ServantBase
  {
  protected:
    ReplyHandler (void);

  public:
    ReplyHandler (const ReplyHandler& rhs);
    virtual ~ReplyHandler (void);


    virtual CORBA::Boolean _is_a (
        const char* logical_type_id,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual void* _downcast (
        const char* logical_type_id
      );

    static void _is_a_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    static void _non_existent_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *context,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual void _dispatch (
        TAO_ServerRequest &_tao_req,
        void *_tao_context,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    ::Messaging::ReplyHandler *_this (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual const char* _interface_repository_id (void) const;


  };


#if !defined (_MESSAGING_REPLYHANDLER___THRU_POA_COLLOCATED_SH_)
#define _MESSAGING_REPLYHANDLER___THRU_POA_COLLOCATED_SH_

  class TAO_PortableServer_Export _tao_thru_poa_collocated_ReplyHandler     : public virtual ::Messaging::ReplyHandler
  {
  public:
    _tao_thru_poa_collocated_ReplyHandler (
        TAO_Stub *stub
      );
    virtual CORBA::Boolean _is_a(
        const CORBA::Char *logical_type_id,
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );

    virtual CORBA::Boolean _non_existent(
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );

      };


#endif /* end #if !defined */


#if !defined (_MESSAGING_REPLYHANDLER___DIRECT_COLLOCATED_SH_)
#define _MESSAGING_REPLYHANDLER___DIRECT_COLLOCATED_SH_

  class TAO_PortableServer_Export _tao_direct_collocated_ReplyHandler     : public virtual Messaging::ReplyHandler, public virtual TAO_Collocated_Object
  {
  public:
    _tao_direct_collocated_ReplyHandler (
        ReplyHandler_ptr  servant,
        TAO_Stub *stub
      );
    virtual CORBA::Boolean _is_a(
        const CORBA::Char *logical_type_id,
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );
    virtual void *_tao_QueryInterface (ptr_arith_t type);

    ReplyHandler_ptr _get_servant (void) const;

    virtual CORBA::Boolean _non_existent(
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );


  private:
    ReplyHandler_ptr servant_;
  };


#endif /* end #if !defined */


#if defined (ACE_HAS_USING_KEYWORD)
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class TAO_PortableServer_Export ReplyHandler_tie : public ReplyHandler
  {
  public:
    ReplyHandler_tie (T &t);
    // the T& ctor
    ReplyHandler_tie (T &t, PortableServer::POA_ptr poa);
    // ctor taking a POA
    ReplyHandler_tie (T *tp, CORBA::Boolean release=1);
    // ctor taking pointer and an ownership flag
    ReplyHandler_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release=1);
    // ctor with T*, ownership flag and a POA
    ~ReplyHandler_tie (void);
    // dtor

    // TIE specific functions
    T *_tied_object (void);
    // return the underlying object
    void _tied_object (T &obj);
    // set the underlying object
    void _tied_object (T *obj, CORBA::Boolean release=1);
    // set the underlying object and the ownership flag
    CORBA::Boolean _is_owner (void);
    // do we own it
    void _is_owner (CORBA::Boolean b);
    // set the ownership

    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );
private:
    T *ptr_;
    PortableServer::POA_var poa_;
    CORBA::Boolean rel_;

    // copy and assignment are not allowed
    ReplyHandler_tie (const ReplyHandler_tie &);
    void operator= (const ReplyHandler_tie &);
  };

#endif /* ACE_HAS_USING_KEYWORD */

#endif /* TAO_HAS_AMI_CALLBACK == 1 */

}
TAO_NAMESPACE_CLOSE

#include "MessagingS_T.h"

#if defined (__ACE_INLINE__)
#include "MessagingS.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* TAO_HAS_CORBA_MESSAGING == 1 */

#include "ace/post.h"
#endif /* ifndef */
