// $Id$

#include "tao/Exception.h"
#include "ace/Auto_Ptr.h"
#include "ace/Log_Msg.h"
#include "CPR_Handler.h"
#include "Utils.h"

BEGIN_DEPLOYMENT_NAMESPACE

/// handle the connection resource deployment description and populate it
void CPR_Handler::process_ComponentPackageReference
(::Deployment::ComponentPackageReference &cpr)
{
  for (DOMNode* node = this->iter_->nextNode();
       node != 0;
       node = this->iter_->nextNode())
    {
      XStr node_name (node->getNodeName());

      if (false);
      else if
        (CIAO::Config_Handler::Utils::process_string
               (this->iter_, node_name, "requiredUUID", 
                        cpr.requiredUUID));
      else if
        (CIAO::Config_Handler::Utils::process_string
               (this->iter_, node_name, "requiredName", cpr.requiredName));
      else if
        (CIAO::Config_Handler::Utils::process_string
               (this->iter_, node_name, "requiredType", cpr.requiredType));
      else
        {
          this->iter_->previousNode ();
          return;
        }
    }
}

END_DEPLOYMENT_NAMESPACE
