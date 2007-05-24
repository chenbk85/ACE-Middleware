// -*- C++ -*-

//=============================================================================
/**
 * @file Server_Request_Interceptor.h
 *
 * $Id$
 *
 * Implementation header for the server request interceptor for the
 * PortableInterceptor ORB::shutdown() test.
 *
 * @author Ossama Othman <ossama@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef SERVER_REQUEST_INTERCEPTOR_H
#define SERVER_REQUEST_INTERCEPTOR_H

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PI_Server/PI_Server.h"
#include "tao/PortableInterceptorC.h"
#include "tao/LocalObject.h"

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

/**
 * @class Server_Request_Interceptor
 *
 * @brief Simple concrete server request interceptor.
 *
 * This server request interceptor simply determines if its @c
 * destroy() method is invoked out of order.
 *
 * See the README file for test details.
 */
class Server_Request_Interceptor
  : public virtual PortableInterceptor::ServerRequestInterceptor,
    public virtual TAO_Local_RefCounted_Object
{
public:

  /// Constructor.
  Server_Request_Interceptor (bool & destroy_called);

  /**
   * @name Methods Required by the Server Request Interceptor
   * Interface
   *
   * These are methods that must be implemented since they are pure
   * virtual in the abstract base class.  They are the canonical
   * methods required for all server request interceptors.
   */
  //@{
  /// Return the name of this ServerRequestinterceptor.
  virtual char * name (void);

  virtual void destroy (void);

  virtual void receive_request_service_contexts (
      PortableInterceptor::ServerRequestInfo_ptr ri);

  virtual void receive_request (
      PortableInterceptor::ServerRequestInfo_ptr ri);

  virtual void send_reply (
      PortableInterceptor::ServerRequestInfo_ptr ri);

  virtual void send_exception (
      PortableInterceptor::ServerRequestInfo_ptr ri);

  virtual void send_other (
      PortableInterceptor::ServerRequestInfo_ptr ri);
  //@}

protected:

  /// Destructor.
  ~Server_Request_Interceptor (void);

private:

  /// Flag that states whether this interceptor's @c destroy() method
  /// was called.
  bool & destroy_called_;

};

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif  /* SERVER_REQUEST_INTERCEPTOR_H */
