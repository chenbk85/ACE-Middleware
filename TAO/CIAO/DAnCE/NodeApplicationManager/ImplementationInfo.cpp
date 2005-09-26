//$Id$
#ifndef CIAO_IMPLEMENTATION_INFO_CPP
#define CIAO_IMPLEMENTATION_INFO_CPP

#include "ImplementationInfo.h"
#include "ace/SString.h"

CIAO::NodeImplementationInfoHandler::
NodeImplementationInfoHandler (::Deployment::DeploymentPlan & plan) : 
  plan_ (plan),
  node_info_ (0),
  containers_info_map_ (plan)
{
  ACE_NEW (node_info_, ::Deployment::NodeImplementationInfo);
  this->populate_server_resource_def ();
  this->populate_container_impl_infos ();
}

Deployment::NodeImplementationInfo * 
CIAO::NodeImplementationInfoHandler::node_impl_info (void) const
{
  Deployment::NodeImplementationInfo_var retv;
  ACE_NEW_RETURN (retv, 
                  Deployment::NodeImplementationInfo (this->node_info_.in ()),
                  0);
  return retv._retn ();
}

void 
CIAO::NodeImplementationInfoHandler::populate_server_resource_def (void)
{
  const CORBA::ULong instance_len = plan_.instance.length ();
  const char * target_resource_id = 0;

  CORBA::ULong i;

  // Iterate over the instance list to find whether any server resource
  // has been specified
  for (i = 0; i < instance_len; ++i)
    {
      if (this->plan_.instance[i].deployedResource.length () != 0)
        {
          target_resource_id = 
            this->plan_.instance[i].deployedResource[0].resourceName.in ();
          break;
        }
    }

  if (i != instance_len)
    {
      // Some component instance has server resource usage defined, so we
      // set the <nodeapp_config> field of the NodeImplementationInfo struct.
      for (CORBA::ULong j = 0; j < this->plan_.infoProperty.length (); ++j)
        {
          CIAO::DAnCE::ServerResource *server_resource_def = 0;
          this->plan_.infoProperty[j].value >>= server_resource_def;

          if (ACE_OS::strcmp ((*server_resource_def).Id, 
                              target_resource_id) == 0)
            {
              // Found the target server resource def, and store it.
              this->node_info_->nodeapp_config.length (1);

              this->node_info_->nodeapp_config[0].name = 
                CORBA::string_dup ("CIAOServerResource");

              this->node_info_->nodeapp_config[0].value <<= 
                server_resource_def;
              break;
            }
        }
    }
}

void 
CIAO::NodeImplementationInfoHandler::populate_container_impl_infos (void)
{
  CORBA::ULong curr_len = 
    this->containers_info_map_.containers_info ()->length ();
  ACE_UNUSED_ARG (curr_len);
  
  // assignment operation
  this->node_info_->impl_infos = 
    *(this->containers_info_map_.containers_info ());
}

#endif /* CIAO_IMPLEMENTATION_INFO_CPP */
