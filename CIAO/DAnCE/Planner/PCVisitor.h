/* -*- C++ -*- */

//========================================================================
/**
 *  file  PCVisitor.h
 *
 * $Id$
 *
 *  This file contains a number of Visitor classes which are used to
 *  traverse the PackageConfiguration element defined in the
 *  PackagingData.idl
 *
 *  author Stoyan Paunov <spaunov@isis.vanderbilt.edu>
 */
//========================================================================

#ifndef PC_VISITOR_H
#define PC_VISITOR_H

#include /**/ "ace/pre.h"
#include "ace/SString.h"             //for the ACE_CString

#include "PCVisitorBase.h"           //for the base visitor
#include "Node_T.h"                  //Node
#include "ace/Containers_T.h"        //for ACE_Double_Linked_List



#include "ciao/DeploymentC.h"
#include "ciao/Deployment_BaseC.h"
#include "ciao/Deployment_DataC.h"
#include "ciao/Packaging_DataC.h"

namespace {
//Definition of various Node elements parametrized by
//Deployment specific types
  typedef Node<Deployment::Node> NNode;
  typedef Node<Deployment::MonolithicImplementationDescription> MNode;

//Definition of various stacks used to store information
//about the elements being parsed at various levels
  typedef ACE_Bounded_Stack<int> INDEX_STACK;

//definition of a Node which takes an ACE_CString
  typedef Node<ACE_CString> SNode;
}

//===========================================================================
/**
 *  class PCVisitor
 *
 *  This class is is the actual implementation for the PackageConfiguration
 *  Visitor. It derives from PCVisitorBase and overloads the functions which
 *  deal with single elements. Sequences are handled in the base class.
 */
//===========================================================================


class  PCVisitor : public PCVisitorBase
{
public:

  //constructor
  PCVisitor (Deployment::DeploymentPlan &plan,
             Deployment::PackageConfiguration &pc);

  ///Entry point to protected Visitor functions
  void Visit ();

protected:
  /// A whole slew of overloaded routines for different IDL
  /// data types part of the PackageConfiguration.

  virtual
  void Visit (Deployment::PackageConfiguration &pc);

  //!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!

  //ComponentPackageDescription descendents
  virtual
  void Visit (Deployment::ComponentPackageDescription &cpd);

  virtual
  void Visit (Deployment::ComponentInterfaceDescription &cid);

  virtual
  void Visit (Deployment::PackagedComponentImplementation &pci);

  virtual
  void Visit (Deployment::ComponentImplementationDescription &cid);

  virtual
  void Visit (Deployment::ComponentAssemblyDescription &cad);

  virtual
  void Visit (Deployment::SubcomponentInstantiationDescription &sid);

  virtual
  void Visit (Deployment::MonolithicImplementationDescription &mid);

  virtual
  void Visit (Deployment::NamedImplementationArtifact &nia);

  virtual
  void Visit (Deployment::ImplementationArtifactDescription &iad);

  //!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!

  //ComponentPackageReference descendents
  virtual
  void Visit (Deployment::ComponentPackageReference &cpr);

  //!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!

  //properties
  virtual
  void Visit (Deployment::AssemblyPropertyMapping &apm);

  virtual
  void Visit (Deployment::Property &property);


  //requirements & capabilities
  virtual
  void Visit (Deployment::Requirement &requirement);

  virtual
  void Visit (Deployment::Capability &capability);

  virtual
  void Visit (Deployment::ImplementationRequirement &ir);

  virtual
  void Visit (Deployment::ImplementationDependency &id);

  //ports and connections
  virtual
  void Visit (Deployment::AssemblyConnectionDescription &acd);

  virtual
  void Visit (Deployment::SubcomponentPortEndpoint &spe);

  virtual
  void Visit (Deployment::ComponentExternalPortEndpoint &cepe);

protected:
  ///several helper functions
  void update_execParameter (Deployment::ImplementationArtifactDescription& iad,
                             Deployment::ArtifactDeploymentDescription& add);

  void update_configProperty (Deployment::SubcomponentInstantiationDescription &scid,
                              Deployment::InstanceDeploymentDescription &idd);

  void update_configProperty (Deployment::PackagedComponentImplementation& pcid,
                              Deployment::MonolithicDeploymentDescription& mid,
                              Deployment::InstanceDeploymentDescription& idd);

private:

  Deployment::DeploymentPlan& plan_;
  Deployment::PackageConfiguration& pc_;
  Deployment::ComponentAssemblyDescription* last_cad_;

};

#include /**/ "ace/post.h"

#endif /* PC_VISITOR_H */
