//$Id$

#include "tao/Exception.h"
#include "ace/Auto_Ptr.h"
#include "ace/Log_Msg.h"
#include "Property_Handler.h"
#include "Requirement_Handler.h"
#include "NIA_Handler.h"
#include "IAD_Handler.h"
#include "Utils.h"
#include "Process_Element.h"
#include <iostream>
#include <string>

BEGIN_DEPLOYMENT_NAMESPACE

/// handle the package configuration and populate it
void IAD_Handler::process_ImplementationArtifactDescription
(::Deployment::ImplementationArtifactDescription &iad)
{
  for (DOMNode* node = this->iter_->nextNode();
       node != 0;
       node = this->iter_->nextNode())
    {
      XStr node_name (node->getNodeName());

      if (node_name == XStr 
             (ACE_TEXT ("Deployment:ImplementationArtifactDescription")))
        {
        }
      else if
        (CIAO::Config_Handler::Utils::process_string 
              (this->iter_, node_name, "label", iad.label));
      else if
        (CIAO::Config_Handler::Utils::process_string 
              (this->iter_, node_name, "UUID", iad.UUID));
      else if
        (CIAO::Config_Handler::Utils::process_string_seq 
              (this->iter_, node_name, "location", 
               iad.location));
      else if
        (process_sequence_common<Deployment::Property>
           (this->doc_, this->iter_, node,
            node_name, "execParameter", iad.execParameter,
            &Property_Handler::process_Property,
            this->id_map_));
      else if
        (process_sequence_common<Deployment::Requirement>
           (node->getOwnerDocument(), this->iter_, node,
            node_name, "deployRequirement", iad.deployRequirement,
            &Requirement_Handler::process_Requirement,
            this->id_map_));
      else if (iad.dependsOn.length () == 0)
        ;
      /*
      else if
        (process_sequence_remote<Deployment::NamedImplementationArtifact, 
                                 NIA_Handler>
           (this->doc_, this->iter_, node,
            node_name, "dependsOn", iad.dependsOn,
            &NIA_Handler::process_NamedImplementationArtifact, this->id_map_));
      */
      else if
        (process_sequence_common<Deployment::Property>
           (this->doc_, this->iter_, node,
            node_name, "infoProperty", iad.infoProperty,
            &Property_Handler::process_Property,
            this->id_map_));
      else
        {
          this->iter_->previousNode ();
          return;
        }
    }
  return;
}

END_DEPLOYMENT_NAMESPACE
