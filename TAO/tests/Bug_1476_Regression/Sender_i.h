// This may look like C, but it's really -*- C++ -*-
// ===================================================================
/**
 *  @file   Sender_i.h
 *
 *  $Id$
 *
 *  @author Johnny Willemsen  <jwillemsen@remedy.nl>
 **/
// ===================================================================

#ifndef TAO_TESTS_ONEWAYS_INVOKING_TWOWAYS_SENDER_I_H
#define TAO_TESTS_ONEWAYS_INVOKING_TWOWAYS_SENDER_I_H
#include /**/ "ace/pre.h"

#include "TestS.h"

#if defined (_MSC_VER)
# if (_MSC_VER >= 1200)
#  pragma warning(push)
# endif /* _MSC_VER >= 1200 */
# pragma warning (disable:4250)
#endif /* _MSC_VER */

/// Implement the Test::Sender interface
/**
 * Implements the oneway call send_ready_message. This in turn calls
 * the receiver with two way invocations..
 */

class Sender_i
  : public virtual POA_Test::Sender
  , public virtual PortableServer::RefCountServantBase
{
public:
  /// Constructor
  Sender_i (CORBA::ORB_ptr orb);

  ///Destructor
  virtual ~Sender_i (void);

  // = The skeleton methods
  virtual void active_objects (CORBA::ULong ao
                               ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void send_ready_message (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  CORBA::ULong get_number_received (void) const;

  CORBA::ULong get_active_objects (void) const;

private:
  /// Our local ORB ptr
  CORBA::ORB_ptr orb_;

  /// Number of active objects who are trying to connect
  CORBA::ULong active_objects_;

  /// Number of invocations received
  CORBA::ULong number_received_;
};

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /*TAO_TESTS_ONEWAYS_INVOKING_TWOWAYS_SENDER_I_H*/
