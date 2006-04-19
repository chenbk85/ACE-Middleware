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

#include "XSC_XML_Handlers_Export.h"
#ifndef CPD_HPP
#define CPD_HPP

// Forward declarations.
//
namespace CIAO
{
  namespace Config_Handlers
  {
    class PackagedComponentImplementation;
    class ComponentPackageDescription;
  }
}

#include <memory>
#include <list>
#include "XMLSchema/Types.hpp"

#include "ccd.hpp"

#include "cid.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    class XSC_XML_Handlers_Export PackagedComponentImplementation : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // name
      //
      public:
      ::XMLSchema::string< ACE_TCHAR > const& name () const;
      void name (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > name_;

      // referencedImplementation
      //
      public:
      ::CIAO::Config_Handlers::ComponentImplementationDescription const& referencedImplementation () const;
      void referencedImplementation (::CIAO::Config_Handlers::ComponentImplementationDescription const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentImplementationDescription > referencedImplementation_;

      public:
      PackagedComponentImplementation (::XMLSchema::string< ACE_TCHAR > const& name__,
                                       ::CIAO::Config_Handlers::ComponentImplementationDescription const& referencedImplementation__);

      PackagedComponentImplementation (::XSCRT::XML::Element< ACE_TCHAR > const&);
      PackagedComponentImplementation (PackagedComponentImplementation const& s);

      PackagedComponentImplementation&
      operator= (PackagedComponentImplementation const& s);

      private:
      char regulator__;
    };


    class XSC_XML_Handlers_Export ComponentPackageDescription : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // label
      //
      public:
      bool label_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& label () const;
      void label (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > label_;

      // UUID
      //
      public:
      bool UUID_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& UUID () const;
      void UUID (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > UUID_;

      // realizes
      //
      public:
      bool realizes_p () const;
      ::CIAO::Config_Handlers::ComponentInterfaceDescription const& realizes () const;
      void realizes (::CIAO::Config_Handlers::ComponentInterfaceDescription const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentInterfaceDescription > realizes_;

      // configProperty
      //
      public:
      bool configProperty_p () const;
      ::CIAO::Config_Handlers::Property const& configProperty () const;
      void configProperty (::CIAO::Config_Handlers::Property const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Property > configProperty_;

      // implementation
      //
      public:
      bool implementation_p () const;
      ::CIAO::Config_Handlers::PackagedComponentImplementation const& implementation () const;
      void implementation (::CIAO::Config_Handlers::PackagedComponentImplementation const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::PackagedComponentImplementation > implementation_;

      // infoProperty
      //
      public:
      bool infoProperty_p () const;
      ::CIAO::Config_Handlers::Property const& infoProperty () const;
      void infoProperty (::CIAO::Config_Handlers::Property const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Property > infoProperty_;

      // contentLocation
      //
      public:
      bool contentLocation_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& contentLocation () const;
      void contentLocation (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > contentLocation_;

      // href
      //
      public:
      bool href_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& href () const;
      ::XMLSchema::string< ACE_TCHAR >& href ();
      void href (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > href_;

      public:
      ComponentPackageDescription ();

      ComponentPackageDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ComponentPackageDescription (ComponentPackageDescription const& s);

      ComponentPackageDescription&
      operator= (ComponentPackageDescription const& s);

      private:
      char regulator__;
    };
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

#include "XMLSchema/Traversal.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      struct XSC_XML_Handlers_Export PackagedComponentImplementation : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::PackagedComponentImplementation >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        name (Type&);

        virtual void
        name (Type const&);

        virtual void
        referencedImplementation (Type&);

        virtual void
        referencedImplementation (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct XSC_XML_Handlers_Export ComponentPackageDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ComponentPackageDescription >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        label (Type&);

        virtual void
        label (Type const&);

        virtual void
        label_none (Type&);

        virtual void
        label_none (Type const&);

        virtual void
        UUID (Type&);

        virtual void
        UUID (Type const&);

        virtual void
        UUID_none (Type&);

        virtual void
        UUID_none (Type const&);

        virtual void
        realizes (Type&);

        virtual void
        realizes (Type const&);

        virtual void
        realizes_none (Type&);

        virtual void
        realizes_none (Type const&);

        virtual void
        configProperty (Type&);

        virtual void
        configProperty (Type const&);

        virtual void
        configProperty_none (Type&);

        virtual void
        configProperty_none (Type const&);

        virtual void
        implementation (Type&);

        virtual void
        implementation (Type const&);

        virtual void
        implementation_none (Type&);

        virtual void
        implementation_none (Type const&);

        virtual void
        infoProperty (Type&);

        virtual void
        infoProperty (Type const&);

        virtual void
        infoProperty_none (Type&);

        virtual void
        infoProperty_none (Type const&);

        virtual void
        contentLocation (Type&);

        virtual void
        contentLocation (Type const&);

        virtual void
        contentLocation_none (Type&);

        virtual void
        contentLocation_none (Type const&);

        virtual void
        href (Type&);

        virtual void
        href (Type const&);

        virtual void
        href_none (Type&);

        virtual void
        href_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };
    }
  }
}

#include "XMLSchema/Writer.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Writer
    {
      struct PackagedComponentImplementation : Traversal::PackagedComponentImplementation, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::PackagedComponentImplementation Type;
        PackagedComponentImplementation (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        name (Type &o)
        {

          this->name (const_cast <Type const &> (o));
        }


        virtual void
        name (Type const&);

        virtual void 
        referencedImplementation (Type &o)
        {

          this->referencedImplementation (const_cast <Type const &> (o));
        }


        virtual void
        referencedImplementation (Type const&);

        protected:
        PackagedComponentImplementation ();
      };

      struct ComponentPackageDescription : Traversal::ComponentPackageDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ComponentPackageDescription Type;
        ComponentPackageDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        label (Type &o)
        {

          this->label (const_cast <Type const &> (o));
        }


        virtual void
        label (Type const&);

        virtual void 
        UUID (Type &o)
        {

          this->UUID (const_cast <Type const &> (o));
        }


        virtual void
        UUID (Type const&);

        virtual void 
        realizes (Type &o)
        {

          this->realizes (const_cast <Type const &> (o));
        }


        virtual void
        realizes (Type const&);

        virtual void 
        configProperty (Type &o)
        {

          this->configProperty (const_cast <Type const &> (o));
        }


        virtual void
        configProperty (Type const&);

        virtual void 
        implementation (Type &o)
        {

          this->implementation (const_cast <Type const &> (o));
        }


        virtual void
        implementation (Type const&);

        virtual void 
        infoProperty (Type &o)
        {

          this->infoProperty (const_cast <Type const &> (o));
        }


        virtual void
        infoProperty (Type const&);

        virtual void 
        contentLocation (Type &o)
        {

          this->contentLocation (const_cast <Type const &> (o));
        }


        virtual void
        contentLocation (Type const&);

        virtual void 
        href (Type &o)
        {

          this->href (const_cast <Type const &> (o));
        }


        virtual void
        href (Type const&);

        protected:
        ComponentPackageDescription ();
      };
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

#endif // CPD_HPP
