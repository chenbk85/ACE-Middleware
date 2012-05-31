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

#include "pcd.hpp"

namespace DAnCE
{
  namespace Config_Handlers
  {
    // ComponentPackageImport
    //

    ComponentPackageImport::
    ComponentPackageImport ()
    :
    ::XSCRT::Type (),
    regulator__ ()
    {
    }

    ComponentPackageImport::
    ComponentPackageImport (ComponentPackageImport const& s)
    :
    ::XSCRT::Type (),
    location_ (s.location_),
    regulator__ ()
    {
    }

    ComponentPackageImport& ComponentPackageImport::
    operator= (ComponentPackageImport const& s)
    {
      location_ = s.location_;

      return *this;
    }


    // ComponentPackageImport
    //
    ComponentPackageImport::location_iterator ComponentPackageImport::
    begin_location ()
    {
      return location_.begin ();
    }

    ComponentPackageImport::location_iterator ComponentPackageImport::
    end_location ()
    {
      return location_.end ();
    }

    ComponentPackageImport::location_const_iterator ComponentPackageImport::
    begin_location () const
    {
      return location_.begin ();
    }

    ComponentPackageImport::location_const_iterator ComponentPackageImport::
    end_location () const
    {
      return location_.end ();
    }

    void ComponentPackageImport::
    add_location (ACE_Refcounted_Auto_Ptr < ::XMLSchema::string< ACE_TCHAR >, ACE_Null_Mutex >  const& e)
    {
      location_.push_back (e);
    }

    size_t ComponentPackageImport::
    count_location(void) const
    {
      return location_.size ();
    }


    // PackageConfiguration
    //

    PackageConfiguration::
    PackageConfiguration ()
    :
    regulator__ ()
    {
    }

    PackageConfiguration::
    PackageConfiguration (PackageConfiguration const& s)
    :
    ::XSCRT::Type (),
    label_ (s.label_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.label_) : 0),
    UUID_ (s.UUID_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.UUID_) : 0),
    basePackage_ (s.basePackage_.get () ? new ::DAnCE::Config_Handlers::ComponentPackageDescription (*s.basePackage_) : 0),
    specializedConfig_ (s.specializedConfig_.get () ? new ::DAnCE::Config_Handlers::PackageConfiguration (*s.specializedConfig_) : 0),
    importedPackage_ (s.importedPackage_.get () ? new ::DAnCE::Config_Handlers::ComponentPackageImport (*s.importedPackage_) : 0),
    referencedPackage_ (s.referencedPackage_.get () ? new ::DAnCE::Config_Handlers::ComponentPackageReference (*s.referencedPackage_) : 0),
    selectRequirement_ (s.selectRequirement_),
    configProperty_ (s.configProperty_),
    contentLocation_ (s.contentLocation_.get () ? new ::XMLSchema::string< ACE_TCHAR > (*s.contentLocation_) : 0),
    regulator__ ()
    {
      if (label_.get ()) label_->container (this);
      if (UUID_.get ()) UUID_->container (this);
      if (basePackage_.get ()) basePackage_->container (this);
      if (specializedConfig_.get ()) specializedConfig_->container (this);
      if (importedPackage_.get ()) importedPackage_->container (this);
      if (referencedPackage_.get ()) referencedPackage_->container (this);
      if (contentLocation_.get ()) contentLocation_->container (this);
    }

    PackageConfiguration& PackageConfiguration::
    operator= (PackageConfiguration const& s)
    {
      if (s.label_.get ())
        label (*(s.label_));
      else
        label_.reset (0);

      if (s.UUID_.get ())
        UUID (*(s.UUID_));
      else
        UUID_.reset (0);

      if (s.basePackage_.get ())
        basePackage (*(s.basePackage_));
      else
        basePackage_.reset (0);

      if (s.specializedConfig_.get ())
        specializedConfig (*(s.specializedConfig_));
      else
        specializedConfig_.reset (0);

      if (s.importedPackage_.get ())
        importedPackage (*(s.importedPackage_));
      else
        importedPackage_.reset (0);

      if (s.referencedPackage_.get ())
        referencedPackage (*(s.referencedPackage_));
      else
        referencedPackage_.reset (0);

      selectRequirement_ = s.selectRequirement_;

      configProperty_ = s.configProperty_;

      if (s.contentLocation_.get ())
        contentLocation (*(s.contentLocation_));
      else
        contentLocation_.reset (0);

      return *this;
    }


    // PackageConfiguration
    //
    bool PackageConfiguration::
    label_p () const
    {
      return label_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& PackageConfiguration::
    label () const
    {
      return *label_;
    }

    void PackageConfiguration::
    label (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (label_.get ())
      {
        *label_ = e;
      }

      else
      {
        label_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        label_->container (this);
      }
    }

    // PackageConfiguration
    //
    bool PackageConfiguration::
    UUID_p () const
    {
      return UUID_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& PackageConfiguration::
    UUID () const
    {
      return *UUID_;
    }

    void PackageConfiguration::
    UUID (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (UUID_.get ())
      {
        *UUID_ = e;
      }

      else
      {
        UUID_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        UUID_->container (this);
      }
    }

    // PackageConfiguration
    //
    bool PackageConfiguration::
    basePackage_p () const
    {
      return basePackage_.get () != 0;
    }

    ::DAnCE::Config_Handlers::ComponentPackageDescription const& PackageConfiguration::
    basePackage () const
    {
      return *basePackage_;
    }

    void PackageConfiguration::
    basePackage (::DAnCE::Config_Handlers::ComponentPackageDescription const& e)
    {
      if (basePackage_.get ())
      {
        *basePackage_ = e;
      }

      else
      {
        basePackage_ = ::std::auto_ptr< ::DAnCE::Config_Handlers::ComponentPackageDescription > (new ::DAnCE::Config_Handlers::ComponentPackageDescription (e));
        basePackage_->container (this);
      }
    }

    // PackageConfiguration
    //
    bool PackageConfiguration::
    specializedConfig_p () const
    {
      return specializedConfig_.get () != 0;
    }

    ::DAnCE::Config_Handlers::PackageConfiguration const& PackageConfiguration::
    specializedConfig () const
    {
      return *specializedConfig_;
    }

    void PackageConfiguration::
    specializedConfig (::DAnCE::Config_Handlers::PackageConfiguration const& e)
    {
      if (specializedConfig_.get ())
      {
        *specializedConfig_ = e;
      }

      else
      {
        specializedConfig_ = ::std::auto_ptr< ::DAnCE::Config_Handlers::PackageConfiguration > (new ::DAnCE::Config_Handlers::PackageConfiguration (e));
        specializedConfig_->container (this);
      }
    }

    // PackageConfiguration
    //
    bool PackageConfiguration::
    importedPackage_p () const
    {
      return importedPackage_.get () != 0;
    }

    ::DAnCE::Config_Handlers::ComponentPackageImport const& PackageConfiguration::
    importedPackage () const
    {
      return *importedPackage_;
    }

    void PackageConfiguration::
    importedPackage (::DAnCE::Config_Handlers::ComponentPackageImport const& e)
    {
      if (importedPackage_.get ())
      {
        *importedPackage_ = e;
      }

      else
      {
        importedPackage_ = ::std::auto_ptr< ::DAnCE::Config_Handlers::ComponentPackageImport > (new ::DAnCE::Config_Handlers::ComponentPackageImport (e));
        importedPackage_->container (this);
      }
    }

    // PackageConfiguration
    //
    bool PackageConfiguration::
    referencedPackage_p () const
    {
      return referencedPackage_.get () != 0;
    }

    ::DAnCE::Config_Handlers::ComponentPackageReference const& PackageConfiguration::
    referencedPackage () const
    {
      return *referencedPackage_;
    }

    void PackageConfiguration::
    referencedPackage (::DAnCE::Config_Handlers::ComponentPackageReference const& e)
    {
      if (referencedPackage_.get ())
      {
        *referencedPackage_ = e;
      }

      else
      {
        referencedPackage_ = ::std::auto_ptr< ::DAnCE::Config_Handlers::ComponentPackageReference > (new ::DAnCE::Config_Handlers::ComponentPackageReference (e));
        referencedPackage_->container (this);
      }
    }

    // PackageConfiguration
    //
    PackageConfiguration::selectRequirement_iterator PackageConfiguration::
    begin_selectRequirement ()
    {
      return selectRequirement_.begin ();
    }

    PackageConfiguration::selectRequirement_iterator PackageConfiguration::
    end_selectRequirement ()
    {
      return selectRequirement_.end ();
    }

    PackageConfiguration::selectRequirement_const_iterator PackageConfiguration::
    begin_selectRequirement () const
    {
      return selectRequirement_.begin ();
    }

    PackageConfiguration::selectRequirement_const_iterator PackageConfiguration::
    end_selectRequirement () const
    {
      return selectRequirement_.end ();
    }

    void PackageConfiguration::
    add_selectRequirement (ACE_Refcounted_Auto_Ptr < ::DAnCE::Config_Handlers::Requirement, ACE_Null_Mutex >  const& e)
    {
      selectRequirement_.push_back (e);
    }

    size_t PackageConfiguration::
    count_selectRequirement(void) const
    {
      return selectRequirement_.size ();
    }

    // PackageConfiguration
    //
    PackageConfiguration::configProperty_iterator PackageConfiguration::
    begin_configProperty ()
    {
      return configProperty_.begin ();
    }

    PackageConfiguration::configProperty_iterator PackageConfiguration::
    end_configProperty ()
    {
      return configProperty_.end ();
    }

    PackageConfiguration::configProperty_const_iterator PackageConfiguration::
    begin_configProperty () const
    {
      return configProperty_.begin ();
    }

    PackageConfiguration::configProperty_const_iterator PackageConfiguration::
    end_configProperty () const
    {
      return configProperty_.end ();
    }

    void PackageConfiguration::
    add_configProperty (ACE_Refcounted_Auto_Ptr < ::DAnCE::Config_Handlers::Property, ACE_Null_Mutex >  const& e)
    {
      configProperty_.push_back (e);
    }

    size_t PackageConfiguration::
    count_configProperty(void) const
    {
      return configProperty_.size ();
    }

    // PackageConfiguration
    //
    bool PackageConfiguration::
    contentLocation_p () const
    {
      return contentLocation_.get () != 0;
    }

    ::XMLSchema::string< ACE_TCHAR > const& PackageConfiguration::
    contentLocation () const
    {
      return *contentLocation_;
    }

    void PackageConfiguration::
    contentLocation (::XMLSchema::string< ACE_TCHAR > const& e)
    {
      if (contentLocation_.get ())
      {
        *contentLocation_ = e;
      }

      else
      {
        contentLocation_ = ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > (new ::XMLSchema::string< ACE_TCHAR > (e));
        contentLocation_->container (this);
      }
    }
  }
}

namespace DAnCE
{
  namespace Config_Handlers
  {
    // ComponentPackageImport
    //

    ComponentPackageImport::
    ComponentPackageImport (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == ACE_TEXT("location"))
        {
          ACE_Refcounted_Auto_Ptr < ::XMLSchema::string< ACE_TCHAR >, ACE_Null_Mutex >  t (new ::XMLSchema::string< ACE_TCHAR > (e));
          add_location (t);
        }

        else
        {
        }
      }
    }

    // PackageConfiguration
    //

    PackageConfiguration::
    PackageConfiguration (::XSCRT::XML::Element< ACE_TCHAR > const& e)
    :Base (e), regulator__ ()
    {

      ::XSCRT::Parser< ACE_TCHAR > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< ACE_TCHAR > e (p.next_element ());
        ::std::basic_string< ACE_TCHAR > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == ACE_TEXT("label"))
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          label (t);
        }

        else if (n == ACE_TEXT("UUID"))
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          UUID (t);
        }

        else if (n == ACE_TEXT("basePackage"))
        {
          ::DAnCE::Config_Handlers::ComponentPackageDescription t (e);
          basePackage (t);
        }

        else if (n == ACE_TEXT("specializedConfig"))
        {
          ::DAnCE::Config_Handlers::PackageConfiguration t (e);
          specializedConfig (t);
        }

        else if (n == ACE_TEXT("importedPackage"))
        {
          ::DAnCE::Config_Handlers::ComponentPackageImport t (e);
          importedPackage (t);
        }

        else if (n == ACE_TEXT("referencedPackage"))
        {
          ::DAnCE::Config_Handlers::ComponentPackageReference t (e);
          referencedPackage (t);
        }

        else if (n == ACE_TEXT("selectRequirement"))
        {
          ACE_Refcounted_Auto_Ptr < ::DAnCE::Config_Handlers::Requirement, ACE_Null_Mutex >  t (new ::DAnCE::Config_Handlers::Requirement (e));
          add_selectRequirement (t);
        }

        else if (n == ACE_TEXT("configProperty"))
        {
          ACE_Refcounted_Auto_Ptr < ::DAnCE::Config_Handlers::Property, ACE_Null_Mutex >  t (new ::DAnCE::Config_Handlers::Property (e));
          add_configProperty (t);
        }

        else if (n == ACE_TEXT("contentLocation"))
        {
          ::XMLSchema::string< ACE_TCHAR > t (e);
          contentLocation (t);
        }

        else
        {
        }
      }
    }
  }
}

namespace DAnCE
{
  namespace Config_Handlers
  {
  }
}

#include "ace/XML_Utils/XMLSchema/TypeInfo.hpp"

namespace DAnCE
{
  namespace Config_Handlers
  {
    namespace
    {
      ::XMLSchema::TypeInfoInitializer < ACE_TCHAR > XMLSchemaTypeInfoInitializer_ (::XSCRT::extended_type_info_map ());

      struct ComponentPackageImportTypeInfoInitializer
      {
        ComponentPackageImportTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (::DAnCE::Config_Handlers::ComponentPackageImport));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      ComponentPackageImportTypeInfoInitializer ComponentPackageImportTypeInfoInitializer_;

      struct PackageConfigurationTypeInfoInitializer
      {
        PackageConfigurationTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (::DAnCE::Config_Handlers::PackageConfiguration));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      PackageConfigurationTypeInfoInitializer PackageConfigurationTypeInfoInitializer_;
    }
  }
}

namespace DAnCE
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      // ComponentPackageImport
      //
      //

      void ComponentPackageImport::
      traverse (Type& o)
      {
        pre (o);
        location (o);
        post (o);
      }

      void ComponentPackageImport::
      traverse (Type const& o)
      {
        pre (o);
        location (o);
        post (o);
      }

      void ComponentPackageImport::
      pre (Type&)
      {
      }

      void ComponentPackageImport::
      pre (Type const&)
      {
      }

      void ComponentPackageImport::
      location (Type& o)
      {
        // VC6 anathema strikes again
        //
        ::DAnCE::Config_Handlers::ComponentPackageImport::location_iterator b (o.begin_location()), e (o.end_location());

        if (b != e)
        {
          location_pre (o);
          for (; b != e;)
          {
            dispatch (*(*b));
            if (++b != e) location_next (o);
          }

          location_post (o);
        }

        else location_none (o);
      }

      void ComponentPackageImport::
      location (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ::DAnCE::Config_Handlers::ComponentPackageImport::location_const_iterator b (o.begin_location()), e (o.end_location());

        if (b != e)
        {
          location_pre (o);
          for (; b != e;)
          {
            dispatch (*(*b));
            if (++b != e) location_next (o);
          }

          location_post (o);
        }

        else location_none (o);
      }

      void ComponentPackageImport::
      location_pre (Type&)
      {
      }

      void ComponentPackageImport::
      location_pre (Type const&)
      {
      }

      void ComponentPackageImport::
      location_next (Type&)
      {
      }

      void ComponentPackageImport::
      location_next (Type const&)
      {
      }

      void ComponentPackageImport::
      location_post (Type&)
      {
      }

      void ComponentPackageImport::
      location_post (Type const&)
      {
      }

      void ComponentPackageImport::
      location_none (Type&)
      {
      }

      void ComponentPackageImport::
      location_none (Type const&)
      {
      }

      void ComponentPackageImport::
      post (Type&)
      {
      }

      void ComponentPackageImport::
      post (Type const&)
      {
      }

      // PackageConfiguration
      //
      //

      void PackageConfiguration::
      traverse (Type& o)
      {
        pre (o);
        if (o.label_p ()) label (o);
        else label_none (o);
        if (o.UUID_p ()) UUID (o);
        else UUID_none (o);
        if (o.basePackage_p ()) basePackage (o);
        else basePackage_none (o);
        if (o.specializedConfig_p ()) specializedConfig (o);
        else specializedConfig_none (o);
        if (o.importedPackage_p ()) importedPackage (o);
        else importedPackage_none (o);
        if (o.referencedPackage_p ()) referencedPackage (o);
        else referencedPackage_none (o);
        selectRequirement (o);
        configProperty (o);
        if (o.contentLocation_p ()) contentLocation (o);
        else contentLocation_none (o);
        post (o);
      }

      void PackageConfiguration::
      traverse (Type const& o)
      {
        pre (o);
        if (o.label_p ()) label (o);
        else label_none (o);
        if (o.UUID_p ()) UUID (o);
        else UUID_none (o);
        if (o.basePackage_p ()) basePackage (o);
        else basePackage_none (o);
        if (o.specializedConfig_p ()) specializedConfig (o);
        else specializedConfig_none (o);
        if (o.importedPackage_p ()) importedPackage (o);
        else importedPackage_none (o);
        if (o.referencedPackage_p ()) referencedPackage (o);
        else referencedPackage_none (o);
        selectRequirement (o);
        configProperty (o);
        if (o.contentLocation_p ()) contentLocation (o);
        else contentLocation_none (o);
        post (o);
      }

      void PackageConfiguration::
      pre (Type&)
      {
      }

      void PackageConfiguration::
      pre (Type const&)
      {
      }

      void PackageConfiguration::
      label (Type& o)
      {
        dispatch (o.label ());
      }

      void PackageConfiguration::
      label (Type const& o)
      {
        dispatch (o.label ());
      }

      void PackageConfiguration::
      label_none (Type&)
      {
      }

      void PackageConfiguration::
      label_none (Type const&)
      {
      }

      void PackageConfiguration::
      UUID (Type& o)
      {
        dispatch (o.UUID ());
      }

      void PackageConfiguration::
      UUID (Type const& o)
      {
        dispatch (o.UUID ());
      }

      void PackageConfiguration::
      UUID_none (Type&)
      {
      }

      void PackageConfiguration::
      UUID_none (Type const&)
      {
      }

      void PackageConfiguration::
      basePackage (Type& o)
      {
        dispatch (o.basePackage ());
      }

      void PackageConfiguration::
      basePackage (Type const& o)
      {
        dispatch (o.basePackage ());
      }

      void PackageConfiguration::
      basePackage_none (Type&)
      {
      }

      void PackageConfiguration::
      basePackage_none (Type const&)
      {
      }

      void PackageConfiguration::
      specializedConfig (Type& o)
      {
        dispatch (o.specializedConfig ());
      }

      void PackageConfiguration::
      specializedConfig (Type const& o)
      {
        dispatch (o.specializedConfig ());
      }

      void PackageConfiguration::
      specializedConfig_none (Type&)
      {
      }

      void PackageConfiguration::
      specializedConfig_none (Type const&)
      {
      }

      void PackageConfiguration::
      importedPackage (Type& o)
      {
        dispatch (o.importedPackage ());
      }

      void PackageConfiguration::
      importedPackage (Type const& o)
      {
        dispatch (o.importedPackage ());
      }

      void PackageConfiguration::
      importedPackage_none (Type&)
      {
      }

      void PackageConfiguration::
      importedPackage_none (Type const&)
      {
      }

      void PackageConfiguration::
      referencedPackage (Type& o)
      {
        dispatch (o.referencedPackage ());
      }

      void PackageConfiguration::
      referencedPackage (Type const& o)
      {
        dispatch (o.referencedPackage ());
      }

      void PackageConfiguration::
      referencedPackage_none (Type&)
      {
      }

      void PackageConfiguration::
      referencedPackage_none (Type const&)
      {
      }

      void PackageConfiguration::
      selectRequirement (Type& o)
      {
        // VC6 anathema strikes again
        //
        ::DAnCE::Config_Handlers::PackageConfiguration::selectRequirement_iterator b (o.begin_selectRequirement()), e (o.end_selectRequirement());

        if (b != e)
        {
          selectRequirement_pre (o);
          for (; b != e;)
          {
            dispatch (*(*b));
            if (++b != e) selectRequirement_next (o);
          }

          selectRequirement_post (o);
        }

        else selectRequirement_none (o);
      }

      void PackageConfiguration::
      selectRequirement (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ::DAnCE::Config_Handlers::PackageConfiguration::selectRequirement_const_iterator b (o.begin_selectRequirement()), e (o.end_selectRequirement());

        if (b != e)
        {
          selectRequirement_pre (o);
          for (; b != e;)
          {
            dispatch (*(*b));
            if (++b != e) selectRequirement_next (o);
          }

          selectRequirement_post (o);
        }

        else selectRequirement_none (o);
      }

      void PackageConfiguration::
      selectRequirement_pre (Type&)
      {
      }

      void PackageConfiguration::
      selectRequirement_pre (Type const&)
      {
      }

      void PackageConfiguration::
      selectRequirement_next (Type&)
      {
      }

      void PackageConfiguration::
      selectRequirement_next (Type const&)
      {
      }

      void PackageConfiguration::
      selectRequirement_post (Type&)
      {
      }

      void PackageConfiguration::
      selectRequirement_post (Type const&)
      {
      }

      void PackageConfiguration::
      selectRequirement_none (Type&)
      {
      }

      void PackageConfiguration::
      selectRequirement_none (Type const&)
      {
      }

      void PackageConfiguration::
      configProperty (Type& o)
      {
        // VC6 anathema strikes again
        //
        ::DAnCE::Config_Handlers::PackageConfiguration::configProperty_iterator b (o.begin_configProperty()), e (o.end_configProperty());

        if (b != e)
        {
          configProperty_pre (o);
          for (; b != e;)
          {
            dispatch (*(*b));
            if (++b != e) configProperty_next (o);
          }

          configProperty_post (o);
        }

        else configProperty_none (o);
      }

      void PackageConfiguration::
      configProperty (Type const& o)
      {
        // VC6 anathema strikes again
        //
        ::DAnCE::Config_Handlers::PackageConfiguration::configProperty_const_iterator b (o.begin_configProperty()), e (o.end_configProperty());

        if (b != e)
        {
          configProperty_pre (o);
          for (; b != e;)
          {
            dispatch (*(*b));
            if (++b != e) configProperty_next (o);
          }

          configProperty_post (o);
        }

        else configProperty_none (o);
      }

      void PackageConfiguration::
      configProperty_pre (Type&)
      {
      }

      void PackageConfiguration::
      configProperty_pre (Type const&)
      {
      }

      void PackageConfiguration::
      configProperty_next (Type&)
      {
      }

      void PackageConfiguration::
      configProperty_next (Type const&)
      {
      }

      void PackageConfiguration::
      configProperty_post (Type&)
      {
      }

      void PackageConfiguration::
      configProperty_post (Type const&)
      {
      }

      void PackageConfiguration::
      configProperty_none (Type&)
      {
      }

      void PackageConfiguration::
      configProperty_none (Type const&)
      {
      }

      void PackageConfiguration::
      contentLocation (Type& o)
      {
        dispatch (o.contentLocation ());
      }

      void PackageConfiguration::
      contentLocation (Type const& o)
      {
        dispatch (o.contentLocation ());
      }

      void PackageConfiguration::
      contentLocation_none (Type&)
      {
      }

      void PackageConfiguration::
      contentLocation_none (Type const&)
      {
      }

      void PackageConfiguration::
      post (Type&)
      {
      }

      void PackageConfiguration::
      post (Type const&)
      {
      }
    }
  }
}

namespace DAnCE
{
  namespace Config_Handlers
  {
    namespace Writer
    {
      // ComponentPackageImport
      //
      //

      ComponentPackageImport::
      ComponentPackageImport (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      ComponentPackageImport::
      ComponentPackageImport ()
      {
      }

      void ComponentPackageImport::
      traverse (Type const& o)
      {
        Traversal::ComponentPackageImport::traverse (o);
      }

      void ComponentPackageImport::
      location_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("location"), top_ ()));
      }

      void ComponentPackageImport::
      location_next (Type const& o)
      {
        location_post (o);
        location_pre (o);
      }

      void ComponentPackageImport::
      location_post (Type const&)
      {
        pop_ ();
      }

      // PackageConfiguration
      //
      //

      PackageConfiguration::
      PackageConfiguration (::XSCRT::XML::Element< ACE_TCHAR >& e)
      : ::XSCRT::Writer< ACE_TCHAR > (e)
      {
      }

      PackageConfiguration::
      PackageConfiguration ()
      {
      }

      void PackageConfiguration::
      traverse (Type const& o)
      {
        Traversal::PackageConfiguration::traverse (o);
      }

      void PackageConfiguration::
      label (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("label"), top_ ()));
        Traversal::PackageConfiguration::label (o);
        pop_ ();
      }

      void PackageConfiguration::
      UUID (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("UUID"), top_ ()));
        Traversal::PackageConfiguration::UUID (o);
        pop_ ();
      }

      void PackageConfiguration::
      basePackage (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("basePackage"), top_ ()));
        Traversal::PackageConfiguration::basePackage (o);
        pop_ ();
      }

      void PackageConfiguration::
      specializedConfig (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("specializedConfig"), top_ ()));
        Traversal::PackageConfiguration::specializedConfig (o);
        pop_ ();
      }

      void PackageConfiguration::
      importedPackage (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("importedPackage"), top_ ()));
        Traversal::PackageConfiguration::importedPackage (o);
        pop_ ();
      }

      void PackageConfiguration::
      referencedPackage (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("referencedPackage"), top_ ()));
        Traversal::PackageConfiguration::referencedPackage (o);
        pop_ ();
      }

      void PackageConfiguration::
      selectRequirement_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("selectRequirement"), top_ ()));
      }

      void PackageConfiguration::
      selectRequirement_next (Type const& o)
      {
        selectRequirement_post (o);
        selectRequirement_pre (o);
      }

      void PackageConfiguration::
      selectRequirement_post (Type const&)
      {
        pop_ ();
      }

      void PackageConfiguration::
      configProperty_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("configProperty"), top_ ()));
      }

      void PackageConfiguration::
      configProperty_next (Type const& o)
      {
        configProperty_post (o);
        configProperty_pre (o);
      }

      void PackageConfiguration::
      configProperty_post (Type const&)
      {
        pop_ ();
      }

      void PackageConfiguration::
      contentLocation (Type const& o)
      {
        push_ (::XSCRT::XML::Element< ACE_TCHAR > (ACE_TEXT ("contentLocation"), top_ ()));
        Traversal::PackageConfiguration::contentLocation (o);
        pop_ ();
      }
    }
  }
}

namespace DAnCE
{
  namespace Config_Handlers
  {
  }
}

