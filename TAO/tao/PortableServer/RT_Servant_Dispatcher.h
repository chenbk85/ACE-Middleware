/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    RT_Servant_Dispatcher.h
 *
 *  $Id$
 *
 *  @author Frank Hunleth (fhunleth@cs.wustl.edu)
 */
//=============================================================================


#ifndef TAO_RT_SERVANT_DISPATCHER_H
#define TAO_RT_SERVANT_DISPATCHER_H
#include "ace/pre.h"

#include "portableserver_export.h"
#include "Servant_Dispatcher.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (TAO_HAS_RT_CORBA == 1)

/**
 * @class TAO_RT_Servant_Dispatcher
 *
 * @brief Concrete instantiation of the Servant_Dispatcher strategy.
 *
 *
 */
class TAO_PortableServer_Export TAO_RT_Servant_Dispatcher
  : public TAO_Servant_Dispatcher
{
public:
  virtual ~TAO_RT_Servant_Dispatcher (void);

  /// Dispatch the request to the servant.
  virtual void dispatch (TAO_Object_Adapter::Servant_Upcall &servant_upcall,
                         TAO_ServerRequest &req,
                         CORBA::Environment &ACE_TRY_ENV);
};

/**
 * @class RT_Priority_Model_Processing
 *
 * @brief
 *
 *      This class encapsulates processing necessary for
 *      RTCORBA CLIENT_PROPAGATED priority model.
 *
 *      Although the destructor of this class resets the priority of
 *      the thread to it's original value, application should use
 *      <post_invoke> method for that purpose: destructor cannot
 *      propagate possible exceptions to the callee.  Destructor's
 *      reset capability is intended as a last resort, i.e., if
 *      <post_invoke> isn't reached for some reason.
 */
class TAO_PortableServer_Export RT_Priority_Model_Processing
{
public:

  // Constructor.
  RT_Priority_Model_Processing (TAO_POA &poa);

  // Resets the priority of the current thread back to its original
  // value if necessary, i.e., if it was changed and the
  // <post_invoke> method hasn't been called.  Unlike <post_invoke>,
  // this method cannot propagate exceptions to the user.
  ~RT_Priority_Model_Processing (void);

  // Checks if target POA supports RTCORBA::CLIENT_PROPAGATED
  // PriorityModel.  If so, stores the original priority of the
  // current thread, and sets the thread to the client-propagated
  // priority.
  void pre_invoke (TAO_Service_Context &request_service_context,
                   TAO_Service_Context &reply_service_context,
                   CORBA::Environment &ACE_TRY_ENV);

  // Resets the priority of the current thread back to its original
  // value, if necessary.
  void post_invoke (CORBA::Environment &ACE_TRY_ENV);

private:

  RT_Priority_Model_Processing (const RT_Priority_Model_Processing &);
  void operator= (const RT_Priority_Model_Processing &);

  enum State
  {
    NO_ACTION_REQUIRED,
    PRIORITY_RESET_REQUIRED
  };

  // Indicates whether the priority of the thread needs to be reset
  // back to its original value.
  State state_;

  // Poa of the target servant.
  TAO_POA &poa_;

  // Original priority of the thread.
  RTCORBA::Priority original_priority_;
};

#endif /* TAO_HAS_RT_CORBA == 1 */

#include "ace/post.h"
#endif /* TAO_RT_SERVANT_DISPATCHER_H */
