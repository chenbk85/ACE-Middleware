// -*- C++ -*-

//=============================================================================
/**
 *  @file   Invocation_Endpoint_Selectors.h
 *
 *  $Id$
 *
 * Strategies for selecting profile/endpoint from an IOR for making an
 * invocation.
 *
 *  @author Marina Spivak <marina@cs.wustl.edu>
 */
//=============================================================================

#ifndef TAO_INVOCATION_ENDPOINT_SELECTOR_H
#define TAO_INVOCATION_ENDPOINT_SELECTOR_H

#include /**/ "ace/pre.h"
#include "ace/CORBA_macros.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"

class TAO_MProfile;
class ACE_Time_Value;

namespace TAO
{
  class Profile_Transport_Resolver;
}

namespace CORBA
{
  class Exception;
  class Environment;
}
/**
 * @class TAO_Invocation_Endpoint_Selector
 *
 * @brief Defines the interface for policy-based endpoint selection
 * strategies.
 *
 * Selects/reselects server endpoint for an Invocation.  Different
 * concrete strategies perform selection based on different
 * policies.
 * @par
 * All endpoint selection strategies are stateless objects - any
 * necessary state is stored in Invocation's
 * @c endpoint_selection_state_.
 */
class TAO_Export TAO_Invocation_Endpoint_Selector
{
public:
  /// Constructor.
  TAO_Invocation_Endpoint_Selector (void);

  /// Destructor.
  virtual ~TAO_Invocation_Endpoint_Selector (void);

  /// Select the endpoint and set @a r's @c profile_
  virtual void select_endpoint (TAO::Profile_Transport_Resolver *r,
                                ACE_Time_Value *val
                                ACE_ENV_ARG_DECL) = 0;

};

// ****************************************************************

/**
 * @class TAO_Default_Endpoint_Selector
 *
 * @brief Default strategy for endpoint selection.
 *
 * This strategy is used when there are no policies set or when
 * the only policy set is RTCORBA::PriorityModelPolicy and its
 * value is RTCORBA::SERVER_DECLARED.
 * The strategy is to try the first endpoint from the first
 * profile in the IOR.  If that doesn't work, try the next
 * profile, and so on.
 */
class TAO_Export TAO_Default_Endpoint_Selector :
  public TAO_Invocation_Endpoint_Selector
{
public:
  /// Constructor.
  TAO_Default_Endpoint_Selector (void);

  /// Destructor.
  virtual ~TAO_Default_Endpoint_Selector (void);

  virtual void select_endpoint (TAO::Profile_Transport_Resolver *r,
                                ACE_Time_Value *val
                                ACE_ENV_ARG_DECL);
};

#if defined (__ACE_INLINE__)
# include "tao/Invocation_Endpoint_Selectors.i"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif  /* TAO_INVOCATION_ENDPOINT_SELECTOR_H */
