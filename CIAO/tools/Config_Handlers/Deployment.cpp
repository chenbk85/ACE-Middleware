/* $Id$
 * This code was generated by the XML Schema Compiler.
 *
 * Changes made to this code will most likely be overwritten
 * when the handlers are recompiled.
 *
 * If you find errors or feel that there are bugfixes to be made,
 * please contact the current XSC maintainer:
 *             Will Otte <wotte@dre.vanderbilt.edu>
 */

// Fix for Borland compilers, which seem to have a broken
// <string> include.
#ifdef __BORLANDC__
# include <string.h>
#endif

#include "Deployment.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace reader
    {
      ::CIAO::Config_Handlers::Domain
      domain (xercesc::DOMDocument const* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () == "domain")
        {
          ::CIAO::Config_Handlers::Domain r (e);
          return r;
        }

        else
        {
          throw 1;
        }
      }
    }

    namespace reader
    {
      ::CIAO::Config_Handlers::deploymentPlan
      DeploymentPlan (xercesc::DOMDocument const* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () == "DeploymentPlan")
        {
          ::CIAO::Config_Handlers::deploymentPlan r (e);
          return r;
        }

        else
        {
          throw 1;
        }
      }
    }

    namespace reader
    {
      ::CIAO::Config_Handlers::ImplementationArtifactDescription
      implementationArtifactDescription (xercesc::DOMDocument const* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () == "implementationArtifactDescription")
        {
          ::CIAO::Config_Handlers::ImplementationArtifactDescription r (e);
          return r;
        }

        else
        {
          throw 1;
        }
      }
    }

    namespace reader
    {
      ::CIAO::Config_Handlers::ComponentInterfaceDescription
      componentInterfaceDescription (xercesc::DOMDocument const* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () == "componentInterfaceDescription")
        {
          ::CIAO::Config_Handlers::ComponentInterfaceDescription r (e);
          return r;
        }

        else
        {
          throw 1;
        }
      }
    }

    namespace reader
    {
      ::CIAO::Config_Handlers::ComponentImplementationDescription
      componentImplementationDescription (xercesc::DOMDocument const* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () == "componentImplementationDescription")
        {
          ::CIAO::Config_Handlers::ComponentImplementationDescription r (e);
          return r;
        }

        else
        {
          throw 1;
        }
      }
    }

    namespace reader
    {
      ::CIAO::Config_Handlers::ComponentPackageDescription
      componentPackageDescription (xercesc::DOMDocument const* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () == "componentPackageDescription")
        {
          ::CIAO::Config_Handlers::ComponentPackageDescription r (e);
          return r;
        }

        else
        {
          throw 1;
        }
      }
    }

    namespace reader
    {
      ::CIAO::Config_Handlers::PackageConfiguration
      packageConfiguration (xercesc::DOMDocument const* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () == "packageConfiguration")
        {
          ::CIAO::Config_Handlers::PackageConfiguration r (e);
          return r;
        }

        else
        {
          throw 1;
        }
      }
    }

    namespace reader
    {
      ::CIAO::Config_Handlers::TopLevelPackageDescription
      topLevelPackageDescription (xercesc::DOMDocument const* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () == "topLevelPackageDescription")
        {
          ::CIAO::Config_Handlers::TopLevelPackageDescription r (e);
          return r;
        }

        else
        {
          throw 1;
        }
      }
    }
  }
}

#include "XMLSchema/TypeInfo.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace
    {
      ::XMLSchema::TypeInfoInitializer < ACE_TCHAR > XMLSchemaTypeInfoInitializer_ (::XSCRT::extended_type_info_map ());
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Writer
    {
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace writer
    {
      void
      domain (::CIAO::Config_Handlers::Domain const& s, xercesc::DOMDocument* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () != "domain")
        {
          throw 1;
        }

        struct W : virtual ::CIAO::Config_Handlers::Writer::Domain,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::string< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::Node,
        virtual ::CIAO::Config_Handlers::Writer::Interconnect,
        virtual ::CIAO::Config_Handlers::Writer::Bridge,
        virtual ::CIAO::Config_Handlers::Writer::Resource,
        virtual ::CIAO::Config_Handlers::Writer::SatisfierProperty,
        virtual ::CIAO::Config_Handlers::Writer::SatisfierPropertyKind,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::boolean, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::Any,
        virtual ::CIAO::Config_Handlers::Writer::DataType,
        virtual ::CIAO::Config_Handlers::Writer::TCKind,
        virtual ::CIAO::Config_Handlers::Writer::EnumType,
        virtual ::CIAO::Config_Handlers::Writer::StructType,
        virtual ::CIAO::Config_Handlers::Writer::StructMemberType,
        virtual ::CIAO::Config_Handlers::Writer::ValueType,
        virtual ::CIAO::Config_Handlers::Writer::ValueMemberType,
        virtual ::CIAO::Config_Handlers::Writer::SequenceType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedInt, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::AliasType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::ID< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::DataValue,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::short_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::int_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedShort, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::float_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::double_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedByte, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::long_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedLong, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::NamedValue,
        virtual ::CIAO::Config_Handlers::Writer::SharedResource,
        virtual ::CIAO::Config_Handlers::Writer::Property,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          W (::XSCRT::XML::Element< ACE_TCHAR >& e)
          : ::XSCRT::Writer< ACE_TCHAR > (e)
          {
          }
        };

        W w (e);
        w.dispatch (s);
      }
    }

    namespace writer
    {
      void
      DeploymentPlan (::CIAO::Config_Handlers::deploymentPlan const& s, xercesc::DOMDocument* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () != "DeploymentPlan")
        {
          throw 1;
        }

        struct W : virtual ::CIAO::Config_Handlers::Writer::deploymentPlan,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::string< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::ComponentInterfaceDescription,
        virtual ::CIAO::Config_Handlers::Writer::Property,
        virtual ::CIAO::Config_Handlers::Writer::Any,
        virtual ::CIAO::Config_Handlers::Writer::DataType,
        virtual ::CIAO::Config_Handlers::Writer::TCKind,
        virtual ::CIAO::Config_Handlers::Writer::EnumType,
        virtual ::CIAO::Config_Handlers::Writer::StructType,
        virtual ::CIAO::Config_Handlers::Writer::StructMemberType,
        virtual ::CIAO::Config_Handlers::Writer::ValueType,
        virtual ::CIAO::Config_Handlers::Writer::ValueMemberType,
        virtual ::CIAO::Config_Handlers::Writer::SequenceType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedInt, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::AliasType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::ID< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::DataValue,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::short_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::int_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedShort, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::float_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::double_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::boolean, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedByte, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::long_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedLong, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::NamedValue,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPortDescription,
        virtual ::CIAO::Config_Handlers::Writer::CCMComponentPortKind,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPropertyDescription,
        virtual ::CIAO::Config_Handlers::Writer::MonolithicDeploymentDescription,
        virtual ::CIAO::Config_Handlers::Writer::IdRef,
        virtual ::XMLSchema::Writer::IDREF< ACE_TCHAR >, 
        virtual ::CIAO::Config_Handlers::Writer::Requirement,
        virtual ::CIAO::Config_Handlers::Writer::InstanceDeploymentDescription,
        virtual ::CIAO::Config_Handlers::Writer::InstanceResourceDeploymentDescription,
        virtual ::CIAO::Config_Handlers::Writer::ResourceUsageKind,
        virtual ::CIAO::Config_Handlers::Writer::PlanConnectionDescription,
        virtual ::CIAO::Config_Handlers::Writer::ComponentExternalPortEndpoint,
        virtual ::CIAO::Config_Handlers::Writer::PlanSubcomponentPortEndpoint,
        virtual ::CIAO::Config_Handlers::Writer::ExternalReferenceEndpoint,
        virtual ::CIAO::Config_Handlers::Writer::ConnectionResourceDeploymentDescription,
        virtual ::CIAO::Config_Handlers::Writer::ImplementationDependency,
        virtual ::CIAO::Config_Handlers::Writer::ArtifactDeploymentDescription,
        virtual ::CIAO::Config_Handlers::Writer::ResourceDeploymentDescription,
        virtual ::CIAO::Config_Handlers::Writer::PlanLocality,
        virtual ::CIAO::Config_Handlers::Writer::PlanLocalityKind,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          W (::XSCRT::XML::Element< ACE_TCHAR >& e)
          : ::XSCRT::Writer< ACE_TCHAR > (e)
          {
          }
        };

        W w (e);
        w.dispatch (s);
      }
    }

    namespace writer
    {
      void
      implementationArtifactDescription (::CIAO::Config_Handlers::ImplementationArtifactDescription const& s, xercesc::DOMDocument* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () != "implementationArtifactDescription")
        {
          throw 1;
        }

        struct W : virtual ::CIAO::Config_Handlers::Writer::ImplementationArtifactDescription,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::string< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::NamedImplementationArtifact,
        virtual ::CIAO::Config_Handlers::Writer::Property,
        virtual ::CIAO::Config_Handlers::Writer::Any,
        virtual ::CIAO::Config_Handlers::Writer::DataType,
        virtual ::CIAO::Config_Handlers::Writer::TCKind,
        virtual ::CIAO::Config_Handlers::Writer::EnumType,
        virtual ::CIAO::Config_Handlers::Writer::StructType,
        virtual ::CIAO::Config_Handlers::Writer::StructMemberType,
        virtual ::CIAO::Config_Handlers::Writer::ValueType,
        virtual ::CIAO::Config_Handlers::Writer::ValueMemberType,
        virtual ::CIAO::Config_Handlers::Writer::SequenceType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedInt, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::AliasType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::ID< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::DataValue,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::short_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::int_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedShort, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::float_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::double_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::boolean, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedByte, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::long_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedLong, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::NamedValue,
        virtual ::CIAO::Config_Handlers::Writer::Requirement,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          W (::XSCRT::XML::Element< ACE_TCHAR >& e)
          : ::XSCRT::Writer< ACE_TCHAR > (e)
          {
          }
        };

        W w (e);
        w.dispatch (s);
      }
    }

    namespace writer
    {
      void
      componentInterfaceDescription (::CIAO::Config_Handlers::ComponentInterfaceDescription const& s, xercesc::DOMDocument* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () != "componentInterfaceDescription")
        {
          throw 1;
        }

        struct W : virtual ::CIAO::Config_Handlers::Writer::ComponentInterfaceDescription,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::string< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::Property,
        virtual ::CIAO::Config_Handlers::Writer::Any,
        virtual ::CIAO::Config_Handlers::Writer::DataType,
        virtual ::CIAO::Config_Handlers::Writer::TCKind,
        virtual ::CIAO::Config_Handlers::Writer::EnumType,
        virtual ::CIAO::Config_Handlers::Writer::StructType,
        virtual ::CIAO::Config_Handlers::Writer::StructMemberType,
        virtual ::CIAO::Config_Handlers::Writer::ValueType,
        virtual ::CIAO::Config_Handlers::Writer::ValueMemberType,
        virtual ::CIAO::Config_Handlers::Writer::SequenceType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedInt, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::AliasType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::ID< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::DataValue,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::short_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::int_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedShort, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::float_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::double_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::boolean, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedByte, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::long_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedLong, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::NamedValue,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPortDescription,
        virtual ::CIAO::Config_Handlers::Writer::CCMComponentPortKind,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPropertyDescription,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          W (::XSCRT::XML::Element< ACE_TCHAR >& e)
          : ::XSCRT::Writer< ACE_TCHAR > (e)
          {
          }
        };

        W w (e);
        w.dispatch (s);
      }
    }

    namespace writer
    {
      void
      componentImplementationDescription (::CIAO::Config_Handlers::ComponentImplementationDescription const& s, xercesc::DOMDocument* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () != "componentImplementationDescription")
        {
          throw 1;
        }

        struct W : virtual ::CIAO::Config_Handlers::Writer::ComponentImplementationDescription,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::string< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::ComponentInterfaceDescription,
        virtual ::CIAO::Config_Handlers::Writer::Property,
        virtual ::CIAO::Config_Handlers::Writer::Any,
        virtual ::CIAO::Config_Handlers::Writer::DataType,
        virtual ::CIAO::Config_Handlers::Writer::TCKind,
        virtual ::CIAO::Config_Handlers::Writer::EnumType,
        virtual ::CIAO::Config_Handlers::Writer::StructType,
        virtual ::CIAO::Config_Handlers::Writer::StructMemberType,
        virtual ::CIAO::Config_Handlers::Writer::ValueType,
        virtual ::CIAO::Config_Handlers::Writer::ValueMemberType,
        virtual ::CIAO::Config_Handlers::Writer::SequenceType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedInt, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::AliasType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::ID< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::DataValue,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::short_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::int_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedShort, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::float_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::double_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::boolean, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedByte, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::long_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedLong, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::NamedValue,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPortDescription,
        virtual ::CIAO::Config_Handlers::Writer::CCMComponentPortKind,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPropertyDescription,
        virtual ::CIAO::Config_Handlers::Writer::ComponentAssemblyDescription,
        virtual ::CIAO::Config_Handlers::Writer::SubcomponentInstantiationDescription,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPackageDescription,
        virtual ::CIAO::Config_Handlers::Writer::PackagedComponentImplementation,
        virtual ::CIAO::Config_Handlers::Writer::PackageConfiguration,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPackageImport,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPackageReference,
        virtual ::CIAO::Config_Handlers::Writer::Requirement,
        virtual ::CIAO::Config_Handlers::Writer::AssemblyConnectionDescription,
        virtual ::CIAO::Config_Handlers::Writer::SubcomponentPortEndpoint,
        virtual ::CIAO::Config_Handlers::Writer::IdRef,
        virtual ::XMLSchema::Writer::IDREF< ACE_TCHAR >, 
        virtual ::CIAO::Config_Handlers::Writer::ComponentExternalPortEndpoint,
        virtual ::CIAO::Config_Handlers::Writer::ExternalReferenceEndpoint,
        virtual ::CIAO::Config_Handlers::Writer::AssemblyPropertyMapping,
        virtual ::CIAO::Config_Handlers::Writer::SubcomponentPropertyReference,
        virtual ::CIAO::Config_Handlers::Writer::MonolithicImplementationDescription,
        virtual ::CIAO::Config_Handlers::Writer::ImplementationRequirement,
        virtual ::CIAO::Config_Handlers::Writer::ResourceUsageKind,
        virtual ::CIAO::Config_Handlers::Writer::NamedImplementationArtifact,
        virtual ::CIAO::Config_Handlers::Writer::ImplementationArtifactDescription,
        virtual ::CIAO::Config_Handlers::Writer::Capability,
        virtual ::CIAO::Config_Handlers::Writer::SatisfierProperty,
        virtual ::CIAO::Config_Handlers::Writer::SatisfierPropertyKind,
        virtual ::CIAO::Config_Handlers::Writer::ImplementationDependency,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          W (::XSCRT::XML::Element< ACE_TCHAR >& e)
          : ::XSCRT::Writer< ACE_TCHAR > (e)
          {
          }
        };

        W w (e);
        w.dispatch (s);
      }
    }

    namespace writer
    {
      void
      componentPackageDescription (::CIAO::Config_Handlers::ComponentPackageDescription const& s, xercesc::DOMDocument* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () != "componentPackageDescription")
        {
          throw 1;
        }

        struct W : virtual ::CIAO::Config_Handlers::Writer::ComponentPackageDescription,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::string< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::ComponentInterfaceDescription,
        virtual ::CIAO::Config_Handlers::Writer::Property,
        virtual ::CIAO::Config_Handlers::Writer::Any,
        virtual ::CIAO::Config_Handlers::Writer::DataType,
        virtual ::CIAO::Config_Handlers::Writer::TCKind,
        virtual ::CIAO::Config_Handlers::Writer::EnumType,
        virtual ::CIAO::Config_Handlers::Writer::StructType,
        virtual ::CIAO::Config_Handlers::Writer::StructMemberType,
        virtual ::CIAO::Config_Handlers::Writer::ValueType,
        virtual ::CIAO::Config_Handlers::Writer::ValueMemberType,
        virtual ::CIAO::Config_Handlers::Writer::SequenceType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedInt, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::AliasType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::ID< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::DataValue,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::short_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::int_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedShort, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::float_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::double_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::boolean, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedByte, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::long_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedLong, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::NamedValue,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPortDescription,
        virtual ::CIAO::Config_Handlers::Writer::CCMComponentPortKind,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPropertyDescription,
        virtual ::CIAO::Config_Handlers::Writer::PackagedComponentImplementation,
        virtual ::CIAO::Config_Handlers::Writer::ComponentImplementationDescription,
        virtual ::CIAO::Config_Handlers::Writer::ComponentAssemblyDescription,
        virtual ::CIAO::Config_Handlers::Writer::SubcomponentInstantiationDescription,
        virtual ::CIAO::Config_Handlers::Writer::PackageConfiguration,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPackageImport,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPackageReference,
        virtual ::CIAO::Config_Handlers::Writer::Requirement,
        virtual ::CIAO::Config_Handlers::Writer::AssemblyConnectionDescription,
        virtual ::CIAO::Config_Handlers::Writer::SubcomponentPortEndpoint,
        virtual ::CIAO::Config_Handlers::Writer::IdRef,
        virtual ::XMLSchema::Writer::IDREF< ACE_TCHAR >, 
        virtual ::CIAO::Config_Handlers::Writer::ComponentExternalPortEndpoint,
        virtual ::CIAO::Config_Handlers::Writer::ExternalReferenceEndpoint,
        virtual ::CIAO::Config_Handlers::Writer::AssemblyPropertyMapping,
        virtual ::CIAO::Config_Handlers::Writer::SubcomponentPropertyReference,
        virtual ::CIAO::Config_Handlers::Writer::MonolithicImplementationDescription,
        virtual ::CIAO::Config_Handlers::Writer::ImplementationRequirement,
        virtual ::CIAO::Config_Handlers::Writer::ResourceUsageKind,
        virtual ::CIAO::Config_Handlers::Writer::NamedImplementationArtifact,
        virtual ::CIAO::Config_Handlers::Writer::ImplementationArtifactDescription,
        virtual ::CIAO::Config_Handlers::Writer::Capability,
        virtual ::CIAO::Config_Handlers::Writer::SatisfierProperty,
        virtual ::CIAO::Config_Handlers::Writer::SatisfierPropertyKind,
        virtual ::CIAO::Config_Handlers::Writer::ImplementationDependency,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          W (::XSCRT::XML::Element< ACE_TCHAR >& e)
          : ::XSCRT::Writer< ACE_TCHAR > (e)
          {
          }
        };

        W w (e);
        w.dispatch (s);
      }
    }

    namespace writer
    {
      void
      packageConfiguration (::CIAO::Config_Handlers::PackageConfiguration const& s, xercesc::DOMDocument* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () != "packageConfiguration")
        {
          throw 1;
        }

        struct W : virtual ::CIAO::Config_Handlers::Writer::PackageConfiguration,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::string< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPackageDescription,
        virtual ::CIAO::Config_Handlers::Writer::ComponentInterfaceDescription,
        virtual ::CIAO::Config_Handlers::Writer::Property,
        virtual ::CIAO::Config_Handlers::Writer::Any,
        virtual ::CIAO::Config_Handlers::Writer::DataType,
        virtual ::CIAO::Config_Handlers::Writer::TCKind,
        virtual ::CIAO::Config_Handlers::Writer::EnumType,
        virtual ::CIAO::Config_Handlers::Writer::StructType,
        virtual ::CIAO::Config_Handlers::Writer::StructMemberType,
        virtual ::CIAO::Config_Handlers::Writer::ValueType,
        virtual ::CIAO::Config_Handlers::Writer::ValueMemberType,
        virtual ::CIAO::Config_Handlers::Writer::SequenceType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedInt, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::AliasType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::ID< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::DataValue,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::short_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::int_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedShort, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::float_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::double_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::boolean, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedByte, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::long_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedLong, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::NamedValue,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPortDescription,
        virtual ::CIAO::Config_Handlers::Writer::CCMComponentPortKind,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPropertyDescription,
        virtual ::CIAO::Config_Handlers::Writer::PackagedComponentImplementation,
        virtual ::CIAO::Config_Handlers::Writer::ComponentImplementationDescription,
        virtual ::CIAO::Config_Handlers::Writer::ComponentAssemblyDescription,
        virtual ::CIAO::Config_Handlers::Writer::SubcomponentInstantiationDescription,
        virtual ::CIAO::Config_Handlers::Writer::Requirement,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPackageReference,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPackageImport,
        virtual ::CIAO::Config_Handlers::Writer::AssemblyConnectionDescription,
        virtual ::CIAO::Config_Handlers::Writer::SubcomponentPortEndpoint,
        virtual ::CIAO::Config_Handlers::Writer::IdRef,
        virtual ::XMLSchema::Writer::IDREF< ACE_TCHAR >, 
        virtual ::CIAO::Config_Handlers::Writer::ComponentExternalPortEndpoint,
        virtual ::CIAO::Config_Handlers::Writer::ExternalReferenceEndpoint,
        virtual ::CIAO::Config_Handlers::Writer::AssemblyPropertyMapping,
        virtual ::CIAO::Config_Handlers::Writer::SubcomponentPropertyReference,
        virtual ::CIAO::Config_Handlers::Writer::MonolithicImplementationDescription,
        virtual ::CIAO::Config_Handlers::Writer::ImplementationRequirement,
        virtual ::CIAO::Config_Handlers::Writer::ResourceUsageKind,
        virtual ::CIAO::Config_Handlers::Writer::NamedImplementationArtifact,
        virtual ::CIAO::Config_Handlers::Writer::ImplementationArtifactDescription,
        virtual ::CIAO::Config_Handlers::Writer::Capability,
        virtual ::CIAO::Config_Handlers::Writer::SatisfierProperty,
        virtual ::CIAO::Config_Handlers::Writer::SatisfierPropertyKind,
        virtual ::CIAO::Config_Handlers::Writer::ImplementationDependency,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          W (::XSCRT::XML::Element< ACE_TCHAR >& e)
          : ::XSCRT::Writer< ACE_TCHAR > (e)
          {
          }
        };

        W w (e);
        w.dispatch (s);
      }
    }

    namespace writer
    {
      void
      topLevelPackageDescription (::CIAO::Config_Handlers::TopLevelPackageDescription const& s, xercesc::DOMDocument* d)
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (d->getDocumentElement ());
        if (e.name () != "topLevelPackageDescription")
        {
          throw 1;
        }

        struct W : virtual ::CIAO::Config_Handlers::Writer::TopLevelPackageDescription,
        virtual ::CIAO::Config_Handlers::Writer::PackageConfiguration,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::string< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPackageDescription,
        virtual ::CIAO::Config_Handlers::Writer::ComponentInterfaceDescription,
        virtual ::CIAO::Config_Handlers::Writer::Property,
        virtual ::CIAO::Config_Handlers::Writer::Any,
        virtual ::CIAO::Config_Handlers::Writer::DataType,
        virtual ::CIAO::Config_Handlers::Writer::TCKind,
        virtual ::CIAO::Config_Handlers::Writer::EnumType,
        virtual ::CIAO::Config_Handlers::Writer::StructType,
        virtual ::CIAO::Config_Handlers::Writer::StructMemberType,
        virtual ::CIAO::Config_Handlers::Writer::ValueType,
        virtual ::CIAO::Config_Handlers::Writer::ValueMemberType,
        virtual ::CIAO::Config_Handlers::Writer::SequenceType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedInt, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::AliasType,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::ID< ACE_TCHAR >, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::DataValue,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::short_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::int_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedShort, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::float_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::double_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::boolean, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedByte, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::long_, ACE_TCHAR >,
        virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::unsignedLong, ACE_TCHAR >,
        virtual ::CIAO::Config_Handlers::Writer::NamedValue,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPortDescription,
        virtual ::CIAO::Config_Handlers::Writer::CCMComponentPortKind,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPropertyDescription,
        virtual ::CIAO::Config_Handlers::Writer::PackagedComponentImplementation,
        virtual ::CIAO::Config_Handlers::Writer::ComponentImplementationDescription,
        virtual ::CIAO::Config_Handlers::Writer::ComponentAssemblyDescription,
        virtual ::CIAO::Config_Handlers::Writer::SubcomponentInstantiationDescription,
        virtual ::CIAO::Config_Handlers::Writer::Requirement,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPackageReference,
        virtual ::CIAO::Config_Handlers::Writer::ComponentPackageImport,
        virtual ::CIAO::Config_Handlers::Writer::AssemblyConnectionDescription,
        virtual ::CIAO::Config_Handlers::Writer::SubcomponentPortEndpoint,
        virtual ::CIAO::Config_Handlers::Writer::IdRef,
        virtual ::XMLSchema::Writer::IDREF< ACE_TCHAR >, 
        virtual ::CIAO::Config_Handlers::Writer::ComponentExternalPortEndpoint,
        virtual ::CIAO::Config_Handlers::Writer::ExternalReferenceEndpoint,
        virtual ::CIAO::Config_Handlers::Writer::AssemblyPropertyMapping,
        virtual ::CIAO::Config_Handlers::Writer::SubcomponentPropertyReference,
        virtual ::CIAO::Config_Handlers::Writer::MonolithicImplementationDescription,
        virtual ::CIAO::Config_Handlers::Writer::ImplementationRequirement,
        virtual ::CIAO::Config_Handlers::Writer::ResourceUsageKind,
        virtual ::CIAO::Config_Handlers::Writer::NamedImplementationArtifact,
        virtual ::CIAO::Config_Handlers::Writer::ImplementationArtifactDescription,
        virtual ::CIAO::Config_Handlers::Writer::Capability,
        virtual ::CIAO::Config_Handlers::Writer::SatisfierProperty,
        virtual ::CIAO::Config_Handlers::Writer::SatisfierPropertyKind,
        virtual ::CIAO::Config_Handlers::Writer::ImplementationDependency,
        virtual ::XSCRT::Writer< ACE_TCHAR >
        {
          W (::XSCRT::XML::Element< ACE_TCHAR >& e)
          : ::XSCRT::Writer< ACE_TCHAR > (e)
          {
          }
        };

        W w (e);
        w.dispatch (s);
      }
    }
  }
}

