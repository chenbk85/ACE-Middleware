// $Id$

#ifndef DNC_DUMP_C
#define DNC_DUMP_C

#include "ace/Log_Msg.h"

#include "DnC_Dump.h"
#include <iostream>
#include <string>
#include <map>

namespace Deployment
{
  /*
   *  Generic dump functions
   */

  class Dump_Obj {
  public:
    class Node_Exist { };  // Exception thrown when there is a node with the same name in the map

    Dump_Obj(const char* caption)
      : desc_()
    {
      ACE_DEBUG ((LM_DEBUG, "%s%s:\n", indent_.c_str(), caption));
      indent_.append("   ");
    }

    template <typename DESC>
    Dump_Obj(const char* caption, DESC &desc): desc_(caption)
    {
      ACE_DEBUG ((LM_DEBUG, "%s%s:\n", indent_.c_str(), caption));
      indent_.append("   ");

      if (desc_map_.find(caption) != desc_map_.end())
        {
          ACE_DEBUG ((LM_DEBUG, "DnC_Dump.cpp:Dump_Obj - The item with name %s is already in the node map.\n", caption));
          throw Node_Exist();
        }
      else
        {
          CORBA::Any val;
          val <<= desc;
          desc_map_[caption] = val;
        }
    }

    ~Dump_Obj()
    {
      indent_.erase(indent_.size() - 3, 3);
      if (desc_.size() != 0)
        {
          desc_map_.erase(desc_map_.find(desc_.c_str()));
        }
    }

    static const char* indent()
    {
      return indent_.c_str();
    }

    template <typename DESC>
    static const DESC& desc(const char* caption)
    {
      static DESC* val;
      desc_map_[caption] >>= val;
      return *val;
    }

  private:
    static std::string indent_;
    static std::map<const char*, CORBA::Any> desc_map_;
    std::string desc_;
  };

  std::string Dump_Obj::indent_ = "-";
  std::map<const char*, CORBA::Any> Dump_Obj::desc_map_;

  // Dumps a string sequence
  void DnC_Dump::dump (const char* caption, const ::CORBA::StringSeq &str_seq)
  {
    CORBA::ULong size = str_seq.length ();

    if (size != 0)
      {
        Dump_Obj dump_obj (caption);
        
        for (CORBA::ULong i = 0; i < size; ++i)
          {
            ACE_DEBUG ((LM_DEBUG, "%s%s%s ",
                        Dump_Obj::indent(), str_seq[i].in (), (i < size) ? ", " : "\n"));
          }
      }
  }

  // Dumps a sequence
  template <typename SEQUENCE>
  void DnC_Dump::dump_sequence (const char* caption, const SEQUENCE &seq)
  {
    CORBA::ULong size = seq.length ();

    if (size != 0)
      {
        Dump_Obj dump_obj(caption);
        
        for (CORBA::ULong i = 0; i < size; ++i)
          {
            ACE_DEBUG ((LM_DEBUG, "%s%s %d: \n", Dump_Obj::indent(), caption, i));
            DnC_Dump::dump (seq[i]);
          }
      }
  }

  // Dumps a string
  void DnC_Dump::dump (const char* caption, const TAO_String_Manager& str)
  {
    ACE_DEBUG ((LM_DEBUG, "%s%s: %s\n", Dump_Obj::indent(), caption, str.in()));
  }

  // Dumps a boolean
  void DnC_Dump::dump (const char* caption, const CORBA::Boolean& val)
  {
    ACE_DEBUG ((LM_DEBUG, "%s%s: %s\n", Dump_Obj::indent(), caption, val ? "true" : "false"));
  }

  template <typename ROOT, typename REFERENCE, typename DATA_TYPE, typename CLASS>
  void DnC_Dump::dump_ref (const char* caption, REFERENCE& ref, const char* root, DATA_TYPE CLASS::*data)
  {
    ACE_DEBUG ((LM_DEBUG, "%s%s:\n", Dump_Obj::indent(), caption));
    const ROOT &root_obj = Dump_Obj::desc<ROOT>(root);

    int value = ref;
    ACE_DEBUG ((LM_DEBUG, "%s%s.name: %s\n",
                Dump_Obj::indent(), caption,
                (root_obj.*data)[value].name.in()));
  }

  template <typename ROOT, typename SEQUENCE, typename DATA_TYPE, typename CLASS>
  void DnC_Dump::dump_ref_seq (const char* caption, SEQUENCE& seq, const char* root, DATA_TYPE CLASS::*data)
  {
    ACE_DEBUG ((LM_DEBUG, "%s%s:\n", Dump_Obj::indent(), caption));
    for (size_t i = 0; i < seq.length(); ++i)
      {
        const ROOT &root_obj = Dump_Obj::desc<ROOT>(root);

        int value = seq[i];
        ACE_DEBUG ((LM_DEBUG, "%s%s[%d].name: %s\n",
                    Dump_Obj::indent(), caption, i,
                    (root_obj.*data)[value].name.in()));
      }
  }

  /*
   *  Object dump methods
   */

  // SatisfierProperty
  void DnC_Dump::dump (const Deployment::SatisfierProperty& sp)
  {
    Dump_Obj dump_obj("SatisfierProperty");
    dump ("name", sp.name);

    ACE_DEBUG ((LM_DEBUG, "%skind: ", Dump_Obj::indent()));
    switch (sp.kind) {
    case Quantity: ACE_DEBUG ((LM_DEBUG, "Quantity\n")); break;
    case Capacity: ACE_DEBUG ((LM_DEBUG, "Capacity\n")); break;
    case Minimum: ACE_DEBUG ((LM_DEBUG, "Minimum\n")); break;
    case Maximum: ACE_DEBUG ((LM_DEBUG, "Maximum\n")); break;
    case Attribute: ACE_DEBUG ((LM_DEBUG, "Attribute\n")); break;
    case Selection: ACE_DEBUG ((LM_DEBUG, "Selection\n")); break;
    }

    ACE_DEBUG ((LM_DEBUG, "%svalue:\n", Dump_Obj::indent()));
    dump (sp.value);
  }

  // SharedResource
  void DnC_Dump::dump (const Deployment::SharedResource& sr)
  {
    Dump_Obj dump_obj("SharedResource");
    dump ("name", sr.name);
    dump ("resourceType", sr.resourceType);
    dump_ref_seq<Deployment::Domain> ("nodeRef", sr.nodeRef, "Domain", &Domain::node);
    dump_sequence ("property", sr.property);
  }

  // Resource
  void DnC_Dump::dump (const Deployment::Resource& resource)
  {
    Dump_Obj dump_obj("Resource");
    dump ("name", resource.name);
    dump ("resourceType", resource.resourceType);
    dump_sequence ("property", resource.property);
  }

  // Node
  void DnC_Dump::dump (const Deployment::Node& node)
  {
    Dump_Obj dump_obj("Node");
    dump ("name", node.name);
    dump ("label", node.label);
    dump_ref_seq<Deployment::Domain> ("sharedResourceRef", node.sharedResourceRef, "Domain", &Domain::sharedResource);
    dump_ref_seq<Deployment::Domain> ("connectionRef", node.connectionRef, "Domain", &Domain::interconnect);
    dump_sequence ("resource", node.resource);
  }

  // Interconnect
  void DnC_Dump::dump (const Deployment::Interconnect& conn)
  {
    Dump_Obj dump_obj("Interconnect");
    dump ("name", conn.name);
    dump ("label", conn.label);
    dump_ref_seq<Deployment::Domain> ("connectionRef", conn.connectionRef, "Domain", &Domain::bridge);
    dump_ref_seq<Deployment::Domain> ("connectRef", conn.connectRef, "Domain", &Domain::node);
    dump_sequence ("resource", conn.resource);
  }

  // Bridge
  void DnC_Dump::dump (const Deployment::Bridge& bridge)
  {
    Dump_Obj dump_obj("Bridge");
    dump ("name", bridge.name);
    dump ("label", bridge.label);
    dump_ref_seq<Deployment::Domain> ("connectRef", bridge.connectRef, "Domain", &Domain::node);
    dump_sequence ("resource", bridge.resource);
  }

  void DnC_Dump::dump (const ::Deployment::Domain &domain)
  {
    Dump_Obj dump_obj("Domain", domain);
    dump ("UUID", domain.UUID);
    dump ("label", domain.label);

    dump_sequence ("sharedResource", domain.sharedResource);
    dump_sequence ("node", domain.node);
    dump_sequence ("interconnect", domain.interconnect);
    dump_sequence ("bridge", domain.bridge);
    dump_sequence ("infoProperty", domain.infoProperty);
  }

  // ComponentPortDescription

  void DnC_Dump::dump (const ::Deployment::ComponentPortDescription &compportdesc)
  {
    Dump_Obj dump_obj("ComponentPortDescription");

    dump ("name", compportdesc.name);
    dump ("specificType", compportdesc.specificType);
    dump ("supportedType", compportdesc.supportedType);
    dump ("provider", compportdesc.provider);
    dump ("exclusiveProvider", compportdesc.exclusiveProvider);
    dump ("exclusiveUser", compportdesc.exclusiveUser);
    dump ("optional", compportdesc.optional);

    ACE_DEBUG ((LM_DEBUG, "%skind: ", Dump_Obj::indent()));
    switch (compportdesc.kind) {
    case Facet: ACE_DEBUG ((LM_DEBUG, "Facet\n")); break;
    case SimplexReceptacle: ACE_DEBUG ((LM_DEBUG, "SimplexReceptacle\n")); break;
    case MultiplexReceptacle: ACE_DEBUG ((LM_DEBUG, "MultiplexReceptacle\n")); break;
    case EventEmitter: ACE_DEBUG ((LM_DEBUG, "EventEmitter\n")); break;
    case EventPublisher: ACE_DEBUG ((LM_DEBUG, "EventPublisher\n")); break;
    case EventConsumer: ACE_DEBUG ((LM_DEBUG, "EventConsumer\n")); break;
    }
  }

  // ComponentPropertyDescription

  void DnC_Dump::dump (const ::Deployment::ComponentPropertyDescription &comppropdesc)
  {
    Dump_Obj dump_obj("ComponentPropertyDescription");
    
    dump ("name", comppropdesc.name);

    ACE_DEBUG ((LM_DEBUG, "%stype: ", Dump_Obj::indent()));
    switch (comppropdesc.type.in()->kind()) {
    case ::CORBA::tk_null: ACE_DEBUG ((LM_DEBUG, "tk_null\n")); break;
    case ::CORBA::tk_void: ACE_DEBUG ((LM_DEBUG, "tk_void\n")); break;
    case ::CORBA::tk_short: ACE_DEBUG ((LM_DEBUG, "tk_short\n")); break;
    case ::CORBA::tk_long: ACE_DEBUG ((LM_DEBUG, "tk_long\n")); break;
    case ::CORBA::tk_ushort: ACE_DEBUG ((LM_DEBUG, "tk_ushort\n")); break;
    case ::CORBA::tk_ulong: ACE_DEBUG ((LM_DEBUG, "tk_ulong\n")); break;
    case ::CORBA::tk_float: ACE_DEBUG ((LM_DEBUG, "tk_float\n")); break;
    case ::CORBA::tk_double: ACE_DEBUG ((LM_DEBUG, "tk_double\n")); break;
    case ::CORBA::tk_boolean: ACE_DEBUG ((LM_DEBUG, "tk_boolean\n")); break;
    case ::CORBA::tk_char: ACE_DEBUG ((LM_DEBUG, "tk_char\n")); break;
    case ::CORBA::tk_octet: ACE_DEBUG ((LM_DEBUG, "tk_octet\n")); break;
    case ::CORBA::tk_any: ACE_DEBUG ((LM_DEBUG, "tk_any\n")); break;
    case ::CORBA::tk_TypeCode: ACE_DEBUG ((LM_DEBUG, "tk_TypeCode\n")); break;
    case ::CORBA::tk_Principal: ACE_DEBUG ((LM_DEBUG, "tk_Principal\n")); break;
    case ::CORBA::tk_objref: ACE_DEBUG ((LM_DEBUG, "tk_objref\n")); break;
    case ::CORBA::tk_struct: ACE_DEBUG ((LM_DEBUG, "tk_struct\n")); break;
    case ::CORBA::tk_union: ACE_DEBUG ((LM_DEBUG, "tk_union\n")); break;
    case ::CORBA::tk_enum: ACE_DEBUG ((LM_DEBUG, "tk_enum\n")); break;
    case ::CORBA::tk_string: ACE_DEBUG ((LM_DEBUG, "tk_string\n")); break;
    case ::CORBA::tk_sequence: ACE_DEBUG ((LM_DEBUG, "tk_sequence\n")); break;
    case ::CORBA::tk_array: ACE_DEBUG ((LM_DEBUG, "tk_array\n")); break;
    case ::CORBA::tk_alias: ACE_DEBUG ((LM_DEBUG, "tk_alias\n")); break;
    case ::CORBA::tk_except: ACE_DEBUG ((LM_DEBUG, "tk_except\n")); break;
    case ::CORBA::tk_longlong: ACE_DEBUG ((LM_DEBUG, "tk_longlong\n")); break;
    case ::CORBA::tk_ulonglong: ACE_DEBUG ((LM_DEBUG, "tk_ulonglong\n")); break;
    case ::CORBA::tk_longdouble: ACE_DEBUG ((LM_DEBUG, "tk_longdouble\n")); break;
    case ::CORBA::tk_wchar: ACE_DEBUG ((LM_DEBUG, "tk_wchar\n")); break;
    case ::CORBA::tk_wstring: ACE_DEBUG ((LM_DEBUG, "tk_wstring\n")); break;
    case ::CORBA::tk_fixed: ACE_DEBUG ((LM_DEBUG, "tk_fixed\n")); break;
    case ::CORBA::tk_value: ACE_DEBUG ((LM_DEBUG, "tk_value\n")); break;
    case ::CORBA::tk_value_box: ACE_DEBUG ((LM_DEBUG, "tk_value_box\n")); break;
    case ::CORBA::tk_native: ACE_DEBUG ((LM_DEBUG, "tk_native\n")); break;
    case ::CORBA::tk_abstract_interface: ACE_DEBUG ((LM_DEBUG, "tk_abstract_interface\n")); break;
    case ::CORBA::tk_local_interface: ACE_DEBUG ((LM_DEBUG, "tk_local_interface\n")); break;
    case ::CORBA::tk_component: ACE_DEBUG ((LM_DEBUG, "tk_component\n")); break;
    case ::CORBA::tk_home: ACE_DEBUG ((LM_DEBUG, "tk_home\n")); break;
    case ::CORBA::tk_event: ACE_DEBUG ((LM_DEBUG, "tk_event\n")); break;
    default:
      break;
    };
  }

  // ComponentInterfaceDescription

  void DnC_Dump::dump (const ::Deployment::ComponentInterfaceDescription &cid)
  {
    Dump_Obj dump_obj("ComponentInterfaceDescription", cid);

    dump ("label", cid.label);
    dump ("UUID", cid.UUID);
    dump ("specificType", cid.specificType);
    dump ("supportedType", cid.supportedType);
    dump ("idlFile", cid.idlFile);
    dump_sequence ("configProperty", cid.configProperty);
    dump_sequence ("port", cid.port);
    dump_sequence ("property", cid.property);
    dump_sequence ("infoProperty", cid.infoProperty);
  }

  // Requirement

  void DnC_Dump::dump (const ::Deployment::Requirement &req)
  {
    Dump_Obj dump_obj("Requirement");
    
    dump ("resourceType", req.resourceType);
    dump ("name", req.name);
    dump_sequence ("property", req.property);
  }

  // MonolithicDeploymentDescription

  void DnC_Dump::dump(const Deployment::MonolithicDeploymentDescription &mdd)
  {
    Dump_Obj dump_obj("MonolithicDeploymentDescription");

    dump ("name", mdd.name);
    dump ("source", mdd.source);
    dump_ref_seq<Deployment::DeploymentPlan> ("artifactRef", mdd.artifactRef, "Plan", &DeploymentPlan::artifact);
    dump_sequence ("execParameter", mdd.execParameter);
    dump_sequence ("deployRequirement", mdd.deployRequirement);
  }

  // ResourceUsageKind

  void DnC_Dump::dump(const Deployment::ResourceUsageKind &ruk)
  {
    ACE_DEBUG ((LM_DEBUG, "%sresourceUsage: ", Dump_Obj::indent()));
    switch (ruk) {
    case None: ACE_DEBUG ((LM_DEBUG, "None\n")); break;
    case InstanceUsesResource: ACE_DEBUG ((LM_DEBUG, "InstanceUsesResource\n")); break;
    case ResourceUsesInstance: ACE_DEBUG ((LM_DEBUG, "ResourceUsesInstance\n")); break;
    case PortUsesResource: ACE_DEBUG ((LM_DEBUG, "PortUsesResource\n")); break;
    case ResourceUsesPort: ACE_DEBUG ((LM_DEBUG, "ResourceUsesPort\n")); break;
    }
  }

  // InstanceResourceDeploymentDescription

  void DnC_Dump::dump(const Deployment::InstanceResourceDeploymentDescription &irdd)
  {
    Dump_Obj dump_obj("InstanceResourceDeploymentDescription");

    dump (irdd.resourceUsage);
    dump ("requirementName", irdd.requirementName);
    dump ("resourceName", irdd.resourceName);
    ACE_DEBUG ((LM_DEBUG, "%sresourceValue:\n", Dump_Obj::indent()));
    dump (irdd.resourceValue);
  }

  // InstanceDeploymentDescription

  void DnC_Dump::dump(const Deployment::InstanceDeploymentDescription &idd)
  {
    Dump_Obj dump_obj("InstanceDeploymentDescription");

    dump ("name", idd.name);
    dump ("node", idd.node);
    dump ("source", idd.source);
    dump_ref<Deployment::DeploymentPlan> ("implementationRef", idd.implementationRef, "Plan", &DeploymentPlan::implementation);
    dump_sequence ("configProperty", idd.configProperty);
    dump_sequence ("deployedResource", idd.deployedResource);
    dump_sequence ("deployedSharedResource", idd.deployedSharedResource);
  }

  // ComponentExternalPortEndpoint

  void DnC_Dump::dump (const ::Deployment::ComponentExternalPortEndpoint &cepe)
  {
    Dump_Obj dump_obj("ComponentExternalPortEndpoint");

    dump ("portName", cepe.portName);
  }

  // PlanSubcomponentPortEndpoint

  void DnC_Dump::dump(const Deployment::PlanSubcomponentPortEndpoint &pspe)
  {
    Dump_Obj dump_obj("PlanSubcomponentPortEndpoint");

    dump ("portName", pspe.portName);
    dump ("provider", pspe.provider);
    ACE_DEBUG ((LM_DEBUG, "%skind: ", Dump_Obj::indent()));
    switch (pspe.kind) {
    case Facet: ACE_DEBUG ((LM_DEBUG, "Facet\n")); break;
    case SimplexReceptacle: ACE_DEBUG ((LM_DEBUG, "SimplexReceptacle\n")); break;
    case MultiplexReceptacle: ACE_DEBUG ((LM_DEBUG, "MultiplexReceptacle\n")); break;
    case EventEmitter: ACE_DEBUG ((LM_DEBUG, "EventEmitter\n")); break;
    case EventPublisher: ACE_DEBUG ((LM_DEBUG, "EventPublisher\n")); break;
    case EventConsumer: ACE_DEBUG ((LM_DEBUG, "EventConsumer\n")); break;
    }
    dump_ref<Deployment::DeploymentPlan> ("instanceRef", pspe.instanceRef, "Plan", &DeploymentPlan::instance);
  }

  // ExternalReferenceEndpoint

  void DnC_Dump::dump (const ::Deployment::ExternalReferenceEndpoint &ere)
  {
    Dump_Obj dump_obj("ExternalReferenceEndpoint");

    ACE_DEBUG ((LM_DEBUG, "location: %s \n", ere.location.in ()));
  }

  // ConnectionResourceDeploymentDescription

  void DnC_Dump::dump(const Deployment::ConnectionResourceDeploymentDescription &crdd)
  {
    Dump_Obj dump_obj("ConnectionResourceDeploymentDescription");

    dump ("targetName", crdd.targetName);
    dump ("requirementName", crdd.requirementName);
    dump ("resourceName", crdd.resourceName);
    ACE_DEBUG ((LM_DEBUG, "%sresourceValue:\n", Dump_Obj::indent()));
    dump (crdd.resourceValue);
  }

  // PlanConnectionDescription

  void DnC_Dump::dump(const Deployment::PlanConnectionDescription &pcd)
  {
    Dump_Obj dump_obj("PlanConnectionDescription");

    dump ("name", pcd.name);
    dump ("source", pcd.source);
    dump_sequence ("deployRequirement", pcd.deployRequirement);
    dump_sequence ("externalEndpoint", pcd.externalEndpoint);
    dump_sequence ("internalEndpoint", pcd.internalEndpoint);
    dump_sequence ("externalReference", pcd.externalReference);
    dump_sequence ("deployedResource", pcd.deployedResource);
  }

  // PlanSubcomponentPropertyReference

  void DnC_Dump::dump(const Deployment::PlanSubcomponentPropertyReference &pspr)
  {
    Dump_Obj dump_obj("PlanSubcomponentPropertyReference");

    dump ("propertyName", pspr.propertyName);

    dump_ref<Deployment::DeploymentPlan> ("instanceRef", pspr.instanceRef, "Plan", &DeploymentPlan::instance);
  }

  // PlanPropertyMapping

  void DnC_Dump::dump(const Deployment::PlanPropertyMapping &ppm)
  {
    Dump_Obj dump_obj("PlanPropertyMapping");

    dump ("name", ppm.name);
    dump ("source", ppm.source);
    dump ("externalName", ppm.externalName);
    dump_sequence ("delegatesTo", ppm.delegatesTo);
  }

  // ImplementationDependency

  void DnC_Dump::dump(const Deployment::ImplementationDependency &id)
  {
    Dump_Obj dump_obj("ImplementationDependency");

    dump ("requiredType", id.requiredType);
  }

  // ResourceDeploymentDescription

  void DnC_Dump::dump(const Deployment::ResourceDeploymentDescription &rdd)
  {
    Dump_Obj dump_obj("ResourceDeploymentDescription");

    dump ("requirementName", rdd.requirementName);
    dump ("resourceName", rdd.resourceName);
    ACE_DEBUG ((LM_DEBUG, "%sresourceValue:\n", Dump_Obj::indent()));
    dump (rdd.resourceValue);
  }

  // ArtifactDeploymentDescription

  void DnC_Dump::dump(const Deployment::ArtifactDeploymentDescription &add)
  {
    Dump_Obj dump_obj("ArtifactDeploymentDescription");

    dump ("name", add.name);
    dump ("location", add.location);
    dump ("node", add.node);
    dump ("source", add.source); 
    dump_sequence ("execParameter", add.execParameter);
    dump_sequence ("deployRequirement", add.deployRequirement);
    dump_sequence ("deployedResource", add.deployedResource);
  }

  void DnC_Dump::dump(const Deployment::DeploymentPlan &plan)
  {
    Dump_Obj dump_obj("DeploymentPlan", plan);

    dump ("label", plan.label);
    dump ("UUID", plan.UUID);
    dump (plan.realizes);
    dump_sequence ("implementation", plan.implementation);
    dump_sequence ("instance", plan.instance);
    dump_sequence ("connection", plan.connection);
    dump_sequence ("externalProperty", plan.externalProperty);
    dump_sequence ("dependsOn", plan.dependsOn);
    dump_sequence ("artifact", plan.artifact);
    dump_sequence ("infoProperty", plan.infoProperty);

    /*
    ACE_DEBUG ((LM_DEBUG, "\nUUID: %s \n", plan.UUID.in ()));
    ACE_DEBUG ((LM_DEBUG, "Label: %s \n", plan.label.in ()));
    ACE_DEBUG ((LM_DEBUG, "%srealizes:\n", Dump_Obj::indent()));
    for (CORBA::ULong i = 0; i < plan.implementation.length (); ++i)
      {
        ACE_DEBUG ((LM_DEBUG, "\nMonolithicImplementation %d: \n", i + 1));
        ACE_DEBUG ((LM_DEBUG, "     Name: %s \n",
                    plan.implementation[i].name.in ()));
        for (CORBA::ULong j = 0; j < plan.implementation[i].source.length ();
             ++j)
          {
            ACE_DEBUG ((LM_DEBUG, "     Source: %d: \n", j + 1));
            ACE_DEBUG ((LM_DEBUG, "       Address: %s \n",
                        plan.implementation[i].source[j].in ()));
          }
        for (CORBA::ULong j = 0; 
             j < plan.implementation[i].artifactRef.length (); ++j)
          {
            ACE_DEBUG ((LM_DEBUG, "     Artifact: %d: \n", j + 1));
            int value = plan.implementation[i].artifactRef[j];
            ACE_DEBUG ((LM_DEBUG, "       Name: %s \n",
                        plan.artifact[value].name.in ()));
          }
        for (CORBA::ULong j = 0; 
             j < plan.implementation[i].execParameter.length (); ++j)
          {
            ACE_DEBUG ((LM_DEBUG, "     ExecParameter: %d: \n", j + 1));
            ACE_DEBUG ((LM_DEBUG, "       Name: %s \n",
                        plan.implementation[i].execParameter[j].name.in ()));
            ACE_DEBUG ((LM_DEBUG, "       "));
            dump (plan.implementation[i].execParameter[j].value);
          }
      }
    for (CORBA::ULong i = 0; i < plan.instance.length (); ++i)
      {
        ACE_DEBUG ((LM_DEBUG, "\nInstanceDescription %d: \n", i + 1));
        ACE_DEBUG ((LM_DEBUG, "     Name: %s \n",
                    plan.instance[i].name.in ()));
        ACE_DEBUG ((LM_DEBUG, "     Node: %s \n",
                    plan.instance[i].node.in ()));
        for (CORBA::ULong j = 0; j < plan.instance[i].source.length ();
             ++j)
          {
            ACE_DEBUG ((LM_DEBUG, "     Source: %d: \n", j + 1));
            ACE_DEBUG ((LM_DEBUG, "       Address: %s \n",
                        plan.instance[i].source[j].in ()));
          }
        int value = plan.instance[i].implementationRef;
        ACE_DEBUG ((LM_DEBUG, "     Implementation: %s \n",
                    plan.implementation[value].name.in ()));
        for (CORBA::ULong j = 0; 
             j < plan.instance[i].configProperty.length (); ++j)
          {
            ACE_DEBUG ((LM_DEBUG, "     ConfigProperty: %d: \n", j + 1));
            ACE_DEBUG ((LM_DEBUG, "       Name: %s \n",
                        plan.instance[i].configProperty[j].name.in ()));
            ACE_DEBUG ((LM_DEBUG, "       "));
            dump (plan.instance[i].configProperty[j].value);
          }
      }
    for (CORBA::ULong i = 0; i < plan.connection.length (); ++i)
      {
        ACE_DEBUG ((LM_DEBUG, "\nPlanConnection %d: \n", i + 1));
        ACE_DEBUG ((LM_DEBUG, "     Name: %s \n",
                    plan.connection[i].name.in ()));
        for (CORBA::ULong j = 0; j < plan.connection[i].source.length ();
             ++j)
          {
            ACE_DEBUG ((LM_DEBUG, "     Source: %d: \n", j + 1));
            ACE_DEBUG ((LM_DEBUG, "       Address: %s \n",
                        plan.connection[i].source[j].in ()));
          }
        for (CORBA::ULong j = 0; 
             j < plan.connection[i].internalEndpoint.length ();
             ++j)
          {
            ACE_DEBUG ((LM_DEBUG, "     Connection: %d: \n", j + 1));
            ACE_DEBUG ((LM_DEBUG, "       Portname: %s \n",
                        plan.connection[i].
                        internalEndpoint[j].portName.in ()));
            int value = plan.connection[i].internalEndpoint[j].instanceRef;
            ACE_DEBUG ((LM_DEBUG, "       Instance: %s \n",
                    plan.instance[value].name.in ()));
            ACE_DEBUG ((LM_DEBUG, "       PortKind: "));
            switch (plan.connection[i].internalEndpoint[j].kind)
              {
                case Facet: 
                  ACE_DEBUG ((LM_DEBUG, "Facet\n"));
                  break;

                case SimplexReceptacle: 
                  ACE_DEBUG ((LM_DEBUG, "SimplexReceptacle\n"));
                  break;

                case MultiplexReceptacle:
                  ACE_DEBUG ((LM_DEBUG, "MultiplexReceptacle\n"));
                  break;

                case EventEmitter:
                  ACE_DEBUG ((LM_DEBUG, "EventEmitter\n"));
                  break;

                case EventPublisher:
                  ACE_DEBUG ((LM_DEBUG, "EventPublisher\n"));
                  break;

                case EventConsumer:
                  ACE_DEBUG ((LM_DEBUG, "EventConsumer\n"));
                  break;

              }
          }
      }
    for (CORBA::ULong i = 0; i < plan.artifact.length (); ++i)
      {
        ACE_DEBUG ((LM_DEBUG, "\nArtifactDescription %d: \n", i + 1));
        ACE_DEBUG ((LM_DEBUG, "     Name: %s \n",
                    plan.artifact[i].name.in ()));
        ACE_DEBUG ((LM_DEBUG, "     Node: %s \n",
                    plan.artifact[i].node.in ()));
        for (CORBA::ULong j = 0; j < plan.artifact[i].source.length ();
             ++j)
          {
            ACE_DEBUG ((LM_DEBUG, "     Source: %d: \n", j + 1));
            ACE_DEBUG ((LM_DEBUG, "       Address: %s \n",
                        plan.artifact[i].source[j].in ()));
          }
        for (CORBA::ULong j = 0; j < plan.artifact[i].location.length ();
             ++j)
          {
            ACE_DEBUG ((LM_DEBUG, "     Location: %d: \n", j + 1));
            ACE_DEBUG ((LM_DEBUG, "       Address: %s \n",
                        plan.artifact[i].location[j].in ()));
          }
        for (CORBA::ULong j = 0; 
             j < plan.artifact[i].execParameter.length (); ++j)
          {
            ACE_DEBUG ((LM_DEBUG, "     ExecParameter: %d: \n", j + 1));
            ACE_DEBUG ((LM_DEBUG, "       Name: %s \n",
                        plan.artifact[i].execParameter[j].name.in ()));
            ACE_DEBUG ((LM_DEBUG, "       "));
            dump (plan.artifact[i].execParameter[j].value);
          }
      }
    for (CORBA::ULong i = 0; i < plan.externalProperty.length (); ++i)
      {
        ACE_DEBUG ((LM_DEBUG, "\nPlanProperty %d: \n", i + 1));
        ACE_DEBUG ((LM_DEBUG, "     Name: %s \n",
                    plan.externalProperty[i].name.in ()));
      }
    for (CORBA::ULong i = 0; i < plan.dependsOn.length (); ++i)
      {
        ACE_DEBUG ((LM_DEBUG, "\nImplementationDependency %d: \n", i + 1));
      }
    for (CORBA::ULong i = 0; i < plan.infoProperty.length (); ++i)
      {
        ACE_DEBUG ((LM_DEBUG, "\nExternalProperty %d: \n", i + 1));
        ACE_DEBUG ((LM_DEBUG, "     Name: %s \n",
                    plan.infoProperty[i].name.in ()));
      }
    */
  }

  // ComponentPackageReference

  void DnC_Dump::dump (const ::Deployment::ComponentPackageReference &cpr)
  {
    Dump_Obj dump_obj("ComponentPackageReference");

    dump ("requiredUUID", cpr.requiredUUID);
    dump ("requiredName", cpr.requiredName);
    dump ("requiredType", cpr.requiredType);
  }

  // SubcomponentInstantiationDescription

  void DnC_Dump::dump (const ::Deployment::SubcomponentInstantiationDescription &sid)
  {
    Dump_Obj dump_obj("SubcomponentInstantiationDescription");

    dump ("name", sid.name);
    dump_sequence ("package", sid.package);
    dump_sequence ("configProperty", sid.configProperty);
    dump_sequence ("selectRequirement", sid.selectRequirement);
    dump_sequence ("reference", sid.reference);
  }

  // SubcomponentPortEndpoint

  void DnC_Dump::dump (const ::Deployment::SubcomponentPortEndpoint& spe)
  {
    Dump_Obj dump_obj("SubcomponentPortEndpoint");

    dump ("portName", spe.portName);
    // TODO:
    //  CID->CAD->ACD->SPE
    //  CAD->instance is referred by ACD->internalEndpoint->instanceRef
    //    dump_ref_seq<Deployment::AssemblyConnectionDescription> ("instanceRef", bridge.connectionRef, "Domain", &Domain::bridge);
  }

  // AssemblyConnectionDescription

  void DnC_Dump::dump (const ::Deployment::AssemblyConnectionDescription &acd)
  {
    Dump_Obj dump_obj("AssemblyConnectionDescription");

    dump ("name", acd.name);
    dump_sequence ("deployRequirement", acd.deployRequirement);
    dump_sequence ("externalEndpoint", acd.externalEndpoint);
    dump_sequence ("internalEndpoint", acd.internalEndpoint);
    dump_sequence ("externalReference", acd.externalReference);
  }

  // SubcomponentPropertyReference

  void DnC_Dump::dump (const ::Deployment::SubcomponentPropertyReference &spr)
  {
    Dump_Obj dump_obj("SubcomponentPropertyReference");

    dump ("propertyName", spr.propertyName);
    // TODO:
    //  CID->CAD->APM->SPE
    //  CAD->instance is referred by APM->delegatesTo->instanceRef
    //    dump_ref_seq<Deployment::AssemblyConnectionDescription> ("instanceRef", bridge.connectionRef, "Domain", &Domain::bridge);
    // TODO: refers to?   dump_ref_seq<Deployment::Domain> ("instanceRef", bridge.connectionRef, "Domain", &Domain::bridge);
  }

  // AssemblyPropertyMapping

  void DnC_Dump::dump (const ::Deployment::AssemblyPropertyMapping &apm)
  {
    Dump_Obj dump_obj("AssemblyPropertyMapping");

    dump ("name", apm.name);
    dump ("externalName", apm.externalName);
    dump_sequence ("delegatesTo", apm.delegatesTo);
  }

  // ComponentAssemblyDescription
 
  void DnC_Dump::dump (const ::Deployment::ComponentAssemblyDescription& cad)
  {
    Dump_Obj dump_obj("ComponentAssemblyDescription");
    
    dump_sequence ("instance", cad.instance);
    dump_sequence ("connection", cad.connection);
    dump_sequence ("externalProperty", cad.externalProperty);
  }

  // ImplementationArtifactDescription

  void DnC_Dump::dump (const ::Deployment::ImplementationArtifactDescription &iad)
  {
    Dump_Obj dump_obj("ImplementationArtifactDescription");

    dump ("label", iad.label);
    dump ("UUID", iad.UUID);
    dump ("location", iad.location);
    dump_sequence ("execParameter", iad.execParameter);
    dump_sequence ("deployRequirement", iad.deployRequirement); 
    dump_sequence ("dependsOn", iad.dependsOn); 
    dump_sequence ("infoProperty", iad.infoProperty); 
  }

  // NamedImplementationArtifact

  void DnC_Dump::dump (const ::Deployment::NamedImplementationArtifact &nia)
  {
    Dump_Obj dump_obj("NamedImplementationArtifact");

    dump ("name", nia.name);
    dump (nia.referencedArtifact);
  }

  // ImplementationRequirement

  void DnC_Dump::dump (const ::Deployment::ImplementationRequirement &ir)
  {
    Dump_Obj dump_obj("ImplementationRequirement");
    
    dump_sequence ("resourceUsage", ir.resourceUsage);
    dump ("resourcePort", ir.resourcePort);
    dump ("componentPort", ir.componentPort);
    dump ("resourceType", ir.resourceType);
    dump ("name", ir.name);
    dump_sequence ("property", ir.property);
  }

  // MonolithicImplementationDescription

  void DnC_Dump::dump (const ::Deployment::MonolithicImplementationDescription &mid)
  {
    Dump_Obj dump_obj("MonolithicImplementationDescription");

    dump_sequence ("execParameter", mid.execParameter);
    dump_sequence ("primaryArtifact", mid.primaryArtifact);
    dump_sequence ("deployRequirement", mid.deployRequirement);
  }

  void DnC_Dump::dump (const ::Deployment::Capability &capability)
  {
    Dump_Obj dump_obj("Capability");
    
    dump ("name", capability.name);
    DnC_Dump::dump ("resourceType", capability.resourceType); 
    DnC_Dump::dump_sequence ("property", capability.property);
  }

  void DnC_Dump::dump (
        const ::Deployment::ComponentImplementationDescription &cid)
  {
    Dump_Obj dump_obj("ComponentImplementationDescription");

    dump ("label", cid.label);
    dump ("UUID", cid.UUID);
    ACE_DEBUG ((LM_DEBUG, "%sImplements:\n", Dump_Obj::indent()));
    dump (cid.implements);
    dump_sequence ("assemblyImpl", cid.assemblyImpl);
    dump_sequence ("monolithicImpl", cid.monolithicImpl);
    dump_sequence ("configProperty", cid.configProperty);
    dump_sequence ("capability", cid.capability);
    dump_sequence ("dependsOn", cid.dependsOn);
    dump_sequence ("infoProperty", cid.infoProperty);

    /*
    for (CORBA::ULong i = 0; i < cid.assemblyImpl.length (); ++i)
      {
        ACE_DEBUG ((LM_DEBUG, "\nAssemblyDescription %d: \n", i + 1));
        for (CORBA::ULong j = 0; j < cid.assemblyImpl[i].instance.length ();
             ++j)
          {
            ACE_DEBUG ((LM_DEBUG, "     Instance: %d: \n", j + 1));
            ACE_DEBUG ((LM_DEBUG, "       Name: %s \n",
                        cid.assemblyImpl[i].instance[j].name.in ()));
            for (CORBA::ULong k = 0; 
                 k < cid.assemblyImpl[i].instance[j].
                     package.length ();
                 ++k)
              {
                ACE_DEBUG ((LM_DEBUG, "     Package: %d: \n", k + 1));
                ACE_DEBUG ((LM_DEBUG, "       UUID: %s \n", 
                  cid.assemblyImpl[i].instance[j].package[k].UUID.in ()));
                ACE_DEBUG ((LM_DEBUG, "       Label: %s \n", 
                  cid.assemblyImpl[i].instance[j].package[k].label.in ()));
                ACE_DEBUG ((LM_DEBUG, "       Realizes:\n"));
                dump (cid.assemblyImpl[i].instance[j].package[k].realizes);
                dump (cid.assemblyImpl[i].instance[j].package[k]);
              }
          }
        for (CORBA::ULong j = 0; j < cid.assemblyImpl[i].connection.length ();
             ++j)
          {
            ACE_DEBUG ((LM_DEBUG, "     Connection: %d: \n", j + 1));
            ACE_DEBUG ((LM_DEBUG, "       Name: %s \n",
                        cid.assemblyImpl[i].connection[j].name.in ()));
            for (CORBA::ULong k = 0; 
                 k < cid.assemblyImpl[i].connection[j].
                     internalEndpoint.length ();
                 ++k)
              {
                ACE_DEBUG ((LM_DEBUG, "     Endpoint: %d: \n", k + 1));
                ACE_DEBUG ((LM_DEBUG, "       Portname: %s \n",
                            cid.assemblyImpl[i].connection[j].
                            internalEndpoint[k].portName.in ()));
                int value = cid.assemblyImpl[i].connection[j].
                            internalEndpoint[k].instanceRef;
                ACE_DEBUG ((LM_DEBUG, "       Instance: %s \n",
                        cid.assemblyImpl[i].instance[value].name.in ()));
              }
          }
        for (CORBA::ULong j = 0; 
             j < cid.assemblyImpl[i].externalProperty.length ();
             ++j)
          {
            ACE_DEBUG ((LM_DEBUG, "     ExternalProperty: %d: \n", j + 1));
          }
      }
    for (CORBA::ULong i = 0; i < cid.monolithicImpl.length (); ++i)
      {
        ACE_DEBUG ((LM_DEBUG, "\nMonolithicImplDescription %d: \n", i + 1));
        for (CORBA::ULong j = 0; 
             j < cid.monolithicImpl[i].primaryArtifact.length ();
             ++j)
          {
            ACE_DEBUG ((LM_DEBUG, "     Artifact: %d: \n", j + 1));
            ACE_DEBUG ((LM_DEBUG, "       Name: %s \n",
                        cid.monolithicImpl[i].primaryArtifact[j].name.in ()));
            dump (cid.monolithicImpl[i].primaryArtifact[j].
                  referencedArtifact);
          }
      }
    */
  }

  // PackagedComponentImplementation

  void DnC_Dump::dump (const ::Deployment::PackagedComponentImplementation &pci)
  {
    Dump_Obj dump_obj("PackagedComponentImplementation");

    dump ("Name", pci.name);
    ACE_DEBUG ((LM_DEBUG, 
                "%sreferencedImplementation: \n", Dump_Obj::indent()));
    DnC_Dump::dump (pci.referencedImplementation); // ComponentImplementationDescription
  }

  // ComponentPackageDescription

  void DnC_Dump::dump (const ::Deployment::ComponentPackageDescription &comppkgdesc)
  {
    Dump_Obj dump_obj("ComponentPackageDescription");

    dump ("label", comppkgdesc.label);
    dump ("UUID", comppkgdesc.UUID);
    ACE_DEBUG ((LM_DEBUG, "  realizes: \n"));
    DnC_Dump::dump (comppkgdesc.realizes); // ComponentInterfaceDescription
    dump_sequence ("configProperty", comppkgdesc.configProperty);
    dump_sequence ("implementation", comppkgdesc.implementation);
    dump_sequence ("infoProperty", comppkgdesc.infoProperty);
  }

  // PackageConfiguration

  void DnC_Dump::dump (const ::Deployment::PackageConfiguration &pc)
  {
    Dump_Obj dump_obj("PackageConfiguration");

    dump ("label", pc.label);
    dump ("UUID", pc.UUID);
    dump_sequence ("specializedConfig", pc.specializedConfig);
    dump_sequence ("basePackage", pc.basePackage);
    dump_sequence ("reference", pc.reference);
    dump_sequence ("selectRequirement", pc.selectRequirement);
    dump_sequence ("configProperty", pc.configProperty);
    /*
    ACE_DEBUG ((LM_DEBUG, "  label: %s\n", pc.label.in ()));
    ACE_DEBUG ((LM_DEBUG, "  UUID: %s\n", pc.UUID.in ()));

    ACE_DEBUG ((LM_DEBUG, "  specializedConfig: \n"));
    *    for (CORBA::ULong i = 0;
         i < pc.specializedConfigRef.length ();
         ++i)
      {
        ACE_DEBUG ((LM_DEBUG, "%i\n", pc.specializedConfigRef[i]));
      }
    *
    ACE_DEBUG ((LM_DEBUG, "  configProperty: \n"));
    for (CORBA::ULong i = 0;
         i < pc.configProperty.length ();
         ++i)
      {
        DnC_Dump::dump (pc.configProperty[i]); // Property
      }

    ACE_DEBUG ((LM_DEBUG, "  selectRequirement: \n"));
    for (CORBA::ULong i = 0;
         i < pc.selectRequirement.length ();
         ++i)
      {
        DnC_Dump::dump (pc.selectRequirement[i]); // Requirement
      }

    ACE_DEBUG ((LM_DEBUG, "  reference: \n"));
    for (CORBA::ULong i = 0;
         i < pc.reference.length ();
         ++i)
      {
        DnC_Dump::dump (pc.reference[i]); // ComponentPackageReference
      }

    ACE_DEBUG ((LM_DEBUG, "  basePackage: \n"));
    for (CORBA::ULong i = 0;
         i < pc.basePackage.length ();
         ++i)
      {
        DnC_Dump::dump (pc.basePackage[i]); // ComponentPackageDescription
      }
    */
  }

  // Requirement Satisfier
  void DnC_Dump::dump (const Deployment::RequirementSatisfier& rs)
  {
    Dump_Obj dump_obj("RequirementSatisfier");
    
    dump ("name", rs.name);
    dump ("resourceType", rs.resourceType);
    dump_sequence ("property", rs.property);
  }

  // Property
  void DnC_Dump::dump (const Deployment::Property& property)
  {
    Dump_Obj dump_obj("Property");
    dump ("name", property.name);
    ACE_DEBUG ((LM_DEBUG, "%svalue:\n", Dump_Obj::indent()));
    dump (property.value);
  }

  void DnC_Dump::dump (const ::CORBA::Any &any)
  {
    ::CORBA::TypeCode * type = any.type ();
    switch (type->kind ())
      {
      case CORBA::tk_short:
        {
          CORBA::Short temp;
          if (! (any >>= temp))
            {
              ACE_DEBUG ((LM_DEBUG, "DnC_Dump::dump (CORBA::Any), expected short\
                                  encoded different type"));
              ACE_THROW (CORBA::INTERNAL ());
            }
          ACE_DEBUG ((LM_DEBUG, "Any value: %d \n", temp));
        }
        break;

      case CORBA::tk_null:
        ACE_DEBUG ((LM_DEBUG, "Any value: null value encoded\n"));
        break;

      case CORBA::tk_void:
        ACE_DEBUG ((LM_DEBUG, "Any value: void type encoded \n"));
        break;
      case CORBA::tk_long:
        {
          CORBA::Long temp;
          if (! (any >>= temp))
            {
              ACE_DEBUG ((LM_DEBUG, "DnC::dump (CORBA::Any) expected long\
                                    encoded with different type"));
              ACE_THROW (CORBA::INTERNAL ());
            }
          ACE_DEBUG ((LM_DEBUG, "Any value: %d \n", temp));
        }
        break;

      case CORBA::tk_ushort:
        {
          CORBA::UShort temp;
          if (! (any >>= temp))
            {
              ACE_DEBUG ((LM_DEBUG, "DnC::dump (CORBA::Any) expected u short\
                                   encoded with different type"));
              ACE_THROW (CORBA::INTERNAL ());
            }
          ACE_DEBUG ((LM_DEBUG, "Any value: %u \n", temp));
        }
        break;

      case CORBA::tk_ulong:
        {
          CORBA::ULong temp;
          if (! (any >>= temp))
            {
              ACE_DEBUG ((LM_DEBUG, "DnC::dump (CORBA::Any) expected ulong\
                                    encoded with different type"));
              ACE_THROW (CORBA::INTERNAL ());
            }
          ACE_DEBUG ((LM_DEBUG, "Any value: %u \n", temp));
        }
        break;

      case CORBA::tk_float:
        {
          CORBA::Float temp;
          if (! (any >>= temp))
            {
              ACE_DEBUG ((LM_DEBUG, "DnC::dump (CORBA::Any) expected float\
                                    encoded with different type"));
              ACE_THROW (CORBA::INTERNAL ());
            }
          ACE_DEBUG ((LM_DEBUG, "Any value: %f \n", temp));
        }
        break;
      case CORBA::tk_double:
        {
          CORBA::Double temp;
          if (! (any >>= temp))
            {
              ACE_DEBUG ((LM_DEBUG, "DnC::dump (CORBA::Any) expected double\
                                    encoded with different type"));
              ACE_THROW (CORBA::INTERNAL ());
            }
          ACE_DEBUG ((LM_DEBUG, "Any value: %f \n", temp));
        }
        break;
      case CORBA::tk_boolean:
        {
          CORBA::Boolean temp;
          if (! (any >>= CORBA::Any::to_boolean (temp)))
            {
              ACE_DEBUG ((LM_DEBUG, "DnC::dump (CORBA::Any) expected bool\
                                    encoded with different type"));
              ACE_THROW (CORBA::INTERNAL ());
            }

          if (temp)
            ACE_DEBUG ((LM_DEBUG, "Any value: True \n"));
          else
            ACE_DEBUG ((LM_DEBUG, "Any value: False \n"));
        }
        break;

      case CORBA::tk_char:
        {
          CORBA::Char temp;
          if (! (any >>= CORBA::Any::to_char (temp)))
            {
              ACE_DEBUG ((LM_DEBUG, "DnC::dump (CORBA::Any) expected char\
                                    encoded with different type"));
              ACE_THROW (CORBA::INTERNAL ());
            }
          ACE_DEBUG ((LM_DEBUG, "Any value: %c \n", temp));
        }
        break;

      case CORBA::tk_octet:
        {
          CORBA::Octet temp;
          if (! (any >>= CORBA::Any::to_octet (temp)))
            {
              ACE_DEBUG ((LM_DEBUG, "DnC::dump (CORBA::Any) expected octet\
                                    encoded with different type"));
              ACE_THROW (CORBA::INTERNAL ());
            }
          ACE_DEBUG ((LM_DEBUG, "Any value: %d \n", temp));
        }
        break;

      case CORBA::tk_string:
        {
          const char * temp = 0;
          if (! (any >>= temp))
            {
              ACE_DEBUG ((LM_DEBUG, "DnC::dump (CORBA::Any) expected string\
                                    encoded with different type"));
              ACE_THROW (CORBA::INTERNAL ());
            }
          ACE_DEBUG ((LM_DEBUG, "Any value: %s \n", temp));
        }
        break;
      case CORBA::tk_longlong:
        {
          CORBA::LongLong temp;
          if (! (any >>= temp))
            {
              ACE_DEBUG ((LM_DEBUG, "DnC::dump (CORBA::Any) expected longlong\
                                    encoded with different type"));
              ACE_THROW (CORBA::INTERNAL ());
            }
          ACE_DEBUG ((LM_DEBUG, "Any value: %l \n", temp));
        }
        break;

      case CORBA::tk_longdouble:
        {
          CORBA::LongDouble temp;
          if (! (any >>= temp))
            {
              ACE_DEBUG ((LM_DEBUG, "DnC::dump (CORBA::Any) expected longdouble\
                                    encoded with different type"));
              ACE_THROW (CORBA::INTERNAL ());
            }
          ACE_DEBUG ((LM_DEBUG, "Any value: %d \n", temp));
        }

        break;
      case CORBA::tk_wchar:
        {
          CORBA::WChar temp;
          if (! (any >>= CORBA::Any::to_wchar (temp)))
            {
              ACE_DEBUG ((LM_DEBUG, "DnC::dump (CORBA::Any) expected wchar\
                                    encoded with different type"));
              ACE_THROW (CORBA::INTERNAL ());
            }
          ACE_DEBUG ((LM_DEBUG, "Any value: %c \n", temp));
        }
        break;

      case CORBA::tk_wstring:
        {
          const CORBA::WChar * temp;
          if (! (any >>= temp))
            {
              ACE_DEBUG ((LM_DEBUG, "DnC::dump (CORBA::Any) expected wstring\
                                    encoded with different type"));
              ACE_THROW (CORBA::INTERNAL ());
            }
          ACE_DEBUG ((LM_DEBUG, "Any value: %s \n", temp));
        }
        break;

      default:
        ACE_DEBUG ((LM_DEBUG, "Unknown type encoded in Any\n"));
        ACE_THROW (CORBA::INTERNAL ());
      }
  }
}

#endif /* DNC_DUMP_C */
