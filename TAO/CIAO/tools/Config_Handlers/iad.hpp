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
#ifndef IAD_HPP
#define IAD_HPP

// Forward declarations.
//
namespace CIAO
{
  namespace Config_Handlers
  {
    class NamedImplementationArtifact;
    class ImplementationArtifactDescription;
  }
}

#include <memory>
#include <list>
#include "XMLSchema/Types.hpp"

#include "Basic_Deployment_Data.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    class XSC_XML_Handlers_Export NamedImplementationArtifact : public ::XSCRT::Type
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

      // referencedArtifact
      //
      public:
      ::CIAO::Config_Handlers::ImplementationArtifactDescription const& referencedArtifact () const;
      void referencedArtifact (::CIAO::Config_Handlers::ImplementationArtifactDescription const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ImplementationArtifactDescription > referencedArtifact_;

      public:
      NamedImplementationArtifact (::XMLSchema::string< ACE_TCHAR > const& name__,
                                   ::CIAO::Config_Handlers::ImplementationArtifactDescription const& referencedArtifact__);

      NamedImplementationArtifact (::XSCRT::XML::Element< ACE_TCHAR > const&);
      NamedImplementationArtifact (NamedImplementationArtifact const& s);

      NamedImplementationArtifact&
      operator= (NamedImplementationArtifact const& s);

      private:
      char regulator__;
    };


    class XSC_XML_Handlers_Export ImplementationArtifactDescription : public ::XSCRT::Type
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

      // location
      //
      public:
      typedef ::std::list< ::XMLSchema::string< ACE_TCHAR > >::iterator location_iterator;
      typedef ::std::list< ::XMLSchema::string< ACE_TCHAR > >::const_iterator location_const_iterator;
      location_iterator begin_location ();
      location_iterator end_location ();
      location_const_iterator begin_location () const;
      location_const_iterator end_location () const;
      void add_location (::XMLSchema::string< ACE_TCHAR > const& );
      size_t count_location (void) const;

      protected:
      ::std::list< ::XMLSchema::string< ACE_TCHAR > > location_;

      // dependsOn
      //
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::NamedImplementationArtifact >::iterator dependsOn_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::NamedImplementationArtifact >::const_iterator dependsOn_const_iterator;
      dependsOn_iterator begin_dependsOn ();
      dependsOn_iterator end_dependsOn ();
      dependsOn_const_iterator begin_dependsOn () const;
      dependsOn_const_iterator end_dependsOn () const;
      void add_dependsOn (::CIAO::Config_Handlers::NamedImplementationArtifact const& );
      size_t count_dependsOn (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::NamedImplementationArtifact > dependsOn_;

      // execParameter
      //
      public:
      bool execParameter_p () const;
      ::CIAO::Config_Handlers::Property const& execParameter () const;
      void execParameter (::CIAO::Config_Handlers::Property const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Property > execParameter_;

      // deployRequirement
      //
      public:
      bool deployRequirement_p () const;
      ::CIAO::Config_Handlers::Requirement const& deployRequirement () const;
      void deployRequirement (::CIAO::Config_Handlers::Requirement const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Requirement > deployRequirement_;

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
      ImplementationArtifactDescription ();

      ImplementationArtifactDescription (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ImplementationArtifactDescription (ImplementationArtifactDescription const& s);

      ImplementationArtifactDescription&
      operator= (ImplementationArtifactDescription const& s);

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
      struct XSC_XML_Handlers_Export NamedImplementationArtifact : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::NamedImplementationArtifact >
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
        referencedArtifact (Type&);

        virtual void
        referencedArtifact (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct XSC_XML_Handlers_Export ImplementationArtifactDescription : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ImplementationArtifactDescription >
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
        location (Type&);

        virtual void
        location (Type const&);

        virtual void
        location_pre (Type&);

        virtual void
        location_pre (Type const&);

        virtual void
        location_next (Type&);

        virtual void
        location_next (Type const&);

        virtual void
        location_post (Type&);

        virtual void
        location_post (Type const&);

        virtual void
        location_none (Type&);

        virtual void
        location_none (Type const&);

        virtual void
        dependsOn (Type&);

        virtual void
        dependsOn (Type const&);

        virtual void
        dependsOn_pre (Type&);

        virtual void
        dependsOn_pre (Type const&);

        virtual void
        dependsOn_next (Type&);

        virtual void
        dependsOn_next (Type const&);

        virtual void
        dependsOn_post (Type&);

        virtual void
        dependsOn_post (Type const&);

        virtual void
        dependsOn_none (Type&);

        virtual void
        dependsOn_none (Type const&);

        virtual void
        execParameter (Type&);

        virtual void
        execParameter (Type const&);

        virtual void
        execParameter_none (Type&);

        virtual void
        execParameter_none (Type const&);

        virtual void
        deployRequirement (Type&);

        virtual void
        deployRequirement (Type const&);

        virtual void
        deployRequirement_none (Type&);

        virtual void
        deployRequirement_none (Type const&);

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
      struct NamedImplementationArtifact : Traversal::NamedImplementationArtifact, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::NamedImplementationArtifact Type;
        NamedImplementationArtifact (::XSCRT::XML::Element< ACE_TCHAR >&);

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
        referencedArtifact (Type &o)
        {

          this->referencedArtifact (const_cast <Type const &> (o));
        }


        virtual void
        referencedArtifact (Type const&);

        protected:
        NamedImplementationArtifact ();
      };

      struct ImplementationArtifactDescription : Traversal::ImplementationArtifactDescription, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ImplementationArtifactDescription Type;
        ImplementationArtifactDescription (::XSCRT::XML::Element< ACE_TCHAR >&);

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
        location_pre (Type &o)
        {

          this->location_pre (const_cast <Type const &> (o));
        }


        virtual void
        location_pre (Type const&);

        virtual void 
        location_next (Type &o)
        {

          this->location_next (const_cast <Type const &> (o));
        }


        virtual void
        location_next (Type const&);

        virtual void 
        location_post (Type &o)
        {

          this->location_post (const_cast <Type const &> (o));
        }


        virtual void
        location_post (Type const&);

        virtual void 
        dependsOn_pre (Type &o)
        {

          this->dependsOn_pre (const_cast <Type const &> (o));
        }


        virtual void
        dependsOn_pre (Type const&);

        virtual void 
        dependsOn_next (Type &o)
        {

          this->dependsOn_next (const_cast <Type const &> (o));
        }


        virtual void
        dependsOn_next (Type const&);

        virtual void 
        dependsOn_post (Type &o)
        {

          this->dependsOn_post (const_cast <Type const &> (o));
        }


        virtual void
        dependsOn_post (Type const&);

        virtual void 
        execParameter (Type &o)
        {

          this->execParameter (const_cast <Type const &> (o));
        }


        virtual void
        execParameter (Type const&);

        virtual void 
        deployRequirement (Type &o)
        {

          this->deployRequirement (const_cast <Type const &> (o));
        }


        virtual void
        deployRequirement (Type const&);

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
        ImplementationArtifactDescription ();
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

#endif // IAD_HPP
