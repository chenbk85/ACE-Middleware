// $Id$

#include "tao/RT_Policy_i.h"

#if ! defined (__ACE_INLINE__)
#include "tao/RT_Policy_i.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(TAO, RT_Policy_i, "$Id$")

#if (TAO_HAS_RT_CORBA == 1)

TAO_PriorityModelPolicy::TAO_PriorityModelPolicy
(RTCORBA::PriorityModel priority_model,
 RTCORBA::Priority server_priority)
  : priority_model_ (priority_model),
    server_priority_ (server_priority)
{
}

TAO_PriorityModelPolicy::TAO_PriorityModelPolicy (const
                                                  TAO_PriorityModelPolicy &rhs)
  : priority_model_ (rhs.priority_model_),
    server_priority_ (rhs.server_priority_)
{
}

TAO_PriorityModelPolicy::~TAO_PriorityModelPolicy (void)
{
}

RTCORBA::PriorityModel
TAO_PriorityModelPolicy::priority_model (CORBA::Environment &)
  ACE_THROW_SPEC (())
{
  return this->priority_model_;
}

RTCORBA::Priority
TAO_PriorityModelPolicy::server_priority (CORBA::Environment &)
  ACE_THROW_SPEC (())
{
  return this->server_priority_;
}

CORBA::PolicyType
TAO_PriorityModelPolicy::policy_type (CORBA::Environment &)
{
  return RTCORBA::PRIORITY_MODEL_POLICY_TYPE;
}

CORBA::Policy_ptr
TAO_PriorityModelPolicy::copy (CORBA::Environment &ACE_TRY_ENV)
{
  TAO_PriorityModelPolicy* tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_PriorityModelPolicy (*this),
                    CORBA::NO_MEMORY (TAO_DEFAULT_MINOR_CODE,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  return tmp;
}

void TAO_PriorityModelPolicy::destroy (CORBA::Environment &)
{
}

// ****************************************************************

TAO_ThreadpoolPolicy::TAO_ThreadpoolPolicy (RTCORBA::ThreadpoolId id)
  : id_ (id)
{
}

TAO_ThreadpoolPolicy::TAO_ThreadpoolPolicy (const TAO_ThreadpoolPolicy
                                            &rhs)
  : id_ (rhs.id_)
{
}

TAO_ThreadpoolPolicy::~TAO_ThreadpoolPolicy (void)
{
}

RTCORBA::ThreadpoolId
TAO_ThreadpoolPolicy::threadpool (CORBA::Environment &)
  ACE_THROW_SPEC (())
{
  return this->id_;
}

CORBA::PolicyType
TAO_ThreadpoolPolicy::policy_type (CORBA::Environment &)
{
  return RTCORBA::THREADPOOL_POLICY_TYPE;
}

CORBA::Policy_ptr
TAO_ThreadpoolPolicy::copy (CORBA::Environment &ACE_TRY_ENV)
{
  TAO_ThreadpoolPolicy* tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_ThreadpoolPolicy (*this),
                    CORBA::NO_MEMORY (TAO_DEFAULT_MINOR_CODE,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  return tmp;
}

void TAO_ThreadpoolPolicy::destroy (CORBA::Environment &)
{
}

// ****************************************************************

TAO_PrivateConnectionPolicy::TAO_PrivateConnectionPolicy (void)
{
}

TAO_PrivateConnectionPolicy::TAO_PrivateConnectionPolicy (const
                                                           TAO_PrivateConnectionPolicy &)
{
}

TAO_PrivateConnectionPolicy::~TAO_PrivateConnectionPolicy (void)
{
}

CORBA::PolicyType
TAO_PrivateConnectionPolicy::policy_type (CORBA::Environment &)
{
  return RTCORBA::PRIVATE_CONNECTION_POLICY_TYPE;
}

CORBA::Policy_ptr
TAO_PrivateConnectionPolicy::copy (CORBA::Environment &ACE_TRY_ENV)
{
  TAO_PrivateConnectionPolicy* tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_PrivateConnectionPolicy (*this),
                    CORBA::NO_MEMORY (TAO_DEFAULT_MINOR_CODE,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  return tmp;
}

void
TAO_PrivateConnectionPolicy::destroy (CORBA::Environment &)
{
}

// ****************************************************************

TAO_PriorityBandedConnectionPolicy::TAO_PriorityBandedConnectionPolicy
(const RTCORBA::PriorityBands &bands)
  : priority_bands_ (bands)
{
}

TAO_PriorityBandedConnectionPolicy::TAO_PriorityBandedConnectionPolicy
(const TAO_PriorityBandedConnectionPolicy &rhs)
  : priority_bands_ (rhs.priority_bands_)
{
}

TAO_PriorityBandedConnectionPolicy::~TAO_PriorityBandedConnectionPolicy (void)
{
}

RTCORBA::PriorityBands *
TAO_PriorityBandedConnectionPolicy::priority_bands (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC (())
{
  RTCORBA::PriorityBands *tmp;
  ACE_NEW_THROW_EX (tmp,
                    RTCORBA::PriorityBands (this->priority_bands_),
                    CORBA::NO_MEMORY (TAO_DEFAULT_MINOR_CODE,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (0);

  return tmp;
}

CORBA::PolicyType
TAO_PriorityBandedConnectionPolicy::policy_type (CORBA::Environment &)
{
  return RTCORBA::PRIORITY_BANDED_CONNECTION_POLICY_TYPE;
}

CORBA::Policy_ptr
TAO_PriorityBandedConnectionPolicy::copy (CORBA::Environment &ACE_TRY_ENV)
{
  TAO_PriorityBandedConnectionPolicy *tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_PriorityBandedConnectionPolicy (*this),
                    CORBA::NO_MEMORY (TAO_DEFAULT_MINOR_CODE,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  return tmp;
}

void TAO_PriorityBandedConnectionPolicy::destroy (CORBA::Environment &)
{
}

// ****************************************************************

TAO_TCP_Properties::TAO_TCP_Properties (CORBA::Long send_buffer_size,
                                        CORBA::Long recv_buffer_size,
                                        CORBA::Boolean keep_alive,
                                        CORBA::Boolean dont_route,
                                        CORBA::Boolean no_delay)
  : send_buffer_size_ (send_buffer_size),
    recv_buffer_size_ (recv_buffer_size),
    keep_alive_ (keep_alive),
    dont_route_ (dont_route),
    no_delay_ (no_delay)
{
}

TAO_TCP_Properties::~TAO_TCP_Properties (void)
{
}

CORBA::Long
TAO_TCP_Properties::send_buffer_size (CORBA::Environment &)
  ACE_THROW_SPEC (())
{
  return this->send_buffer_size_;
}

void
TAO_TCP_Properties::send_buffer_size (CORBA::Long send_buffer_size,
                                      CORBA::Environment &)
  ACE_THROW_SPEC (())
{
  this->send_buffer_size_ = send_buffer_size;
}

CORBA::Long
TAO_TCP_Properties::recv_buffer_size (CORBA::Environment &)
  ACE_THROW_SPEC (())
{
  return this->recv_buffer_size_;
}

void
TAO_TCP_Properties::recv_buffer_size (CORBA::Long recv_buffer_size,
                                      CORBA::Environment &)
  ACE_THROW_SPEC (())
{
  this->recv_buffer_size_ = recv_buffer_size;
}

CORBA::Boolean
TAO_TCP_Properties::keep_alive (CORBA::Environment &)
  ACE_THROW_SPEC (())
{
  return this->keep_alive_;
}

void
TAO_TCP_Properties::keep_alive (CORBA::Boolean keep_alive,
                                CORBA::Environment &)
  ACE_THROW_SPEC (())
{
  this->keep_alive_ = keep_alive;
}

CORBA::Boolean
TAO_TCP_Properties::dont_route (CORBA::Environment &)
  ACE_THROW_SPEC (())
{
  return this->dont_route_;
}

void
TAO_TCP_Properties::dont_route (CORBA::Boolean dont_route,
                                CORBA::Environment &)
  ACE_THROW_SPEC (())
{
  this->dont_route_ = dont_route;
}

CORBA::Boolean TAO_TCP_Properties::no_delay (CORBA::Environment &)
  ACE_THROW_SPEC (())
{
  return this->no_delay_;
}

void
TAO_TCP_Properties::no_delay (CORBA::Boolean no_delay,
                              CORBA::Environment &)
  ACE_THROW_SPEC (())
{
  this->no_delay_ = no_delay;
}

// ****************************************************************

TAO_ServerProtocolPolicy::TAO_ServerProtocolPolicy (const
                                                    RTCORBA::ProtocolList &protocols)
  : protocols_ (protocols)
{
}

TAO_ServerProtocolPolicy::TAO_ServerProtocolPolicy (const
                                                    TAO_ServerProtocolPolicy &rhs)
  : protocols_ (rhs.protocols_)
{
}

TAO_ServerProtocolPolicy::~TAO_ServerProtocolPolicy (void)
{
}

RTCORBA::ProtocolList *
TAO_ServerProtocolPolicy::protocols (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC (())
{
  RTCORBA::ProtocolList *tmp;
  ACE_NEW_THROW_EX (tmp,
                    RTCORBA::ProtocolList (this->protocols_),
                    CORBA::NO_MEMORY (TAO_DEFAULT_MINOR_CODE,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (0);

  return tmp;
}

CORBA::PolicyType
TAO_ServerProtocolPolicy::policy_type (CORBA::Environment &)
{
  return RTCORBA::SERVER_PROTOCOL_POLICY_TYPE;
}

CORBA::Policy_ptr
TAO_ServerProtocolPolicy::copy (CORBA::Environment &ACE_TRY_ENV)
{
  TAO_ServerProtocolPolicy* tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_ServerProtocolPolicy (*this),
                    CORBA::NO_MEMORY (TAO_DEFAULT_MINOR_CODE,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  return tmp;
}

void
TAO_ServerProtocolPolicy::destroy (CORBA::Environment &)
{
}

// ****************************************************************

TAO_ClientProtocolPolicy::TAO_ClientProtocolPolicy (const
                                                    RTCORBA::ProtocolList &protocols)
  : protocols_ (protocols)
{
}

TAO_ClientProtocolPolicy::TAO_ClientProtocolPolicy (const
                                                    TAO_ClientProtocolPolicy &rhs)
  : protocols_ (rhs.protocols_)
{
}

TAO_ClientProtocolPolicy::~TAO_ClientProtocolPolicy ()
{
}

RTCORBA::ProtocolList *
TAO_ClientProtocolPolicy::protocols (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC (())
{
  RTCORBA::ProtocolList *tmp;
  ACE_NEW_THROW_EX (tmp,
                    RTCORBA::ProtocolList (this->protocols_),
                    CORBA::NO_MEMORY (TAO_DEFAULT_MINOR_CODE,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (0);

  return tmp;
}

CORBA::PolicyType
TAO_ClientProtocolPolicy::policy_type (CORBA::Environment &)
{
  return RTCORBA::CLIENT_PROTOCOL_POLICY_TYPE;
}

CORBA::Policy_ptr
TAO_ClientProtocolPolicy::copy (CORBA::Environment &ACE_TRY_ENV)
{
  TAO_ClientProtocolPolicy* tmp;
  ACE_NEW_THROW_EX (tmp,
                    TAO_ClientProtocolPolicy (*this),
                    CORBA::NO_MEMORY (TAO_DEFAULT_MINOR_CODE,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  return tmp;
}

void
TAO_ClientProtocolPolicy::destroy (CORBA::Environment &)
{
}


#endif /* TAO_HAS_RT_CORBA == 1 */
