// $Id$

#ifndef MID_HANDLER_H
#define MID_HANDLER_H
#include /**/ "ace/pre.h"

#include "DeploymentC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SString.h"
#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/dom/DOM.hpp>
#include "XercesString.h"

using Config_Handler::XStr;
using xercesc::XMLUni;
using xercesc::XMLString;
using xercesc::XMLException;
using xercesc::DOMException;
using xercesc::DOMBuilder;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMImplementation;
using xercesc::DOMText;
using xercesc::DOMNamedNodeMap;
using xercesc::DOMLocator;
using xercesc::DOMError;
using xercesc::DOMDocument;
using xercesc::DOMDocumentTraversal;
using xercesc::DOMNodeIterator;
using xercesc::DOMNode;
using xercesc::DOMNodeFilter;

namespace Config_Handler
{
  class MID_Handler
  {
  public:

    MID_Handler (DOMDocument* doc, unsigned long filter_);

    MID_Handler (DOMNodeIterator* iter, bool release = false);

    ~MID_Handler();

    void process_MonolithicImplementationDescription ();

  public:

    ::Deployment::MonolithicImplementationDescription const&
    mid ()
    {
      return *mid_;
    }

  private:

    DOMDocumentTraversal* traverse_;

    DOMNode* root_;

    unsigned long filter_;

    DOMNodeIterator* iter_;

    bool release_;

    ::Deployment::MonolithicImplementationDescription_var mid_;
  };
}

#include /**/ "ace/post.h"

#endif /* MID_HANDLER_H */
