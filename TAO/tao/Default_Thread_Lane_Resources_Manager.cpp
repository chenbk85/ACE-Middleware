// $Id$

#include "Default_Thread_Lane_Resources_Manager.h"
#include "Thread_Lane_Resources.h"
#include "Exception.h"
#include "Environment.h"
#include "ORB_Core.h"
#include "ace/Log_Msg.h"


ACE_RCSID (tao,
           Default_Thread_Lane_Resources_Manager,
           "$Id$")

TAO_Default_Thread_Lane_Resources_Manager::TAO_Default_Thread_Lane_Resources_Manager (TAO_ORB_Core &orb_core)
  : TAO_Thread_Lane_Resources_Manager (orb_core),
    lane_resources_ (0)
{
  // Create the default resources.
  ACE_NEW (this->lane_resources_,
           TAO_Thread_Lane_Resources (orb_core));
}

TAO_Default_Thread_Lane_Resources_Manager::~TAO_Default_Thread_Lane_Resources_Manager (void)
{
  // Delete the default resources.
  delete this->lane_resources_;
}

int
TAO_Default_Thread_Lane_Resources_Manager::open_default_resources (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_ORB_Parameters *params =
    this->orb_core_->orb_params ();

  TAO_EndpointSet endpoint_set;

  params->get_endpoint_set (TAO_DEFAULT_LANE,
                            endpoint_set);

  bool ignore_address = false;

  int result =
    this->lane_resources_->open_acceptor_registry (endpoint_set,
                                                   ignore_address
                                                   ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  return result;
}

void
TAO_Default_Thread_Lane_Resources_Manager::finalize (void)
{
  // Finalize default resources.
  this->lane_resources_->finalize ();
}

TAO_Thread_Lane_Resources &
TAO_Default_Thread_Lane_Resources_Manager::lane_resources (void)
{
  return *this->lane_resources_;
}

TAO_Thread_Lane_Resources &
TAO_Default_Thread_Lane_Resources_Manager::default_lane_resources (void)
{
  return this->lane_resources ();
}

void
TAO_Default_Thread_Lane_Resources_Manager::shutdown_reactor (void)
{
  this->lane_resources_->shutdown_reactor ();
}

int
TAO_Default_Thread_Lane_Resources_Manager::is_collocated (const TAO_MProfile &mprofile)
{
  return this->lane_resources_->is_collocated (mprofile);
}

TAO_Thread_Lane_Resources_Manager *
TAO_Default_Thread_Lane_Resources_Manager_Factory::create_thread_lane_resources_manager (TAO_ORB_Core &core)
{
  TAO_Thread_Lane_Resources_Manager *manager = 0;

  /// Create the Default Thread Lane Resources Manager.
  ACE_NEW_RETURN (manager,
                  TAO_Default_Thread_Lane_Resources_Manager (core),
                  0);

  return manager;
}

ACE_STATIC_SVC_DEFINE (TAO_Default_Thread_Lane_Resources_Manager_Factory,
                       ACE_TEXT ("Default_Thread_Lane_Resources_Manager_Factory"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (TAO_Default_Thread_Lane_Resources_Manager_Factory),
                       ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
                       0)
ACE_FACTORY_DEFINE (TAO, TAO_Default_Thread_Lane_Resources_Manager_Factory)
