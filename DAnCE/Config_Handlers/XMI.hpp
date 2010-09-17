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

#ifndef XMI_HPP
#define XMI_HPP

#include "XSC_XML_Handlers_Export.h"
// Forward declarations.
//
namespace XMI
{
  class Extension;
}

#include <memory>
#include <string>
#include <list>
#include "XMLSchema/Types.hpp"
#include "XMLSchema/id_map.hpp"
#include "ace/Refcounted_Auto_Ptr.h"
#include "ace/Null_Mutex.h"
#include "ace/TSS_T.h"
#include "ace/ace_wchar.h"
#include "ace/Singleton.h"

namespace XMI
{
  class XSC_XML_Handlers_Export Extension : public ::XSCRT::Type
  {
    typedef ::XSCRT::Type Base;

    public:
    typedef ACE_Refcounted_Auto_Ptr < Extension, ACE_Null_Mutex > _ptr;

    // id
    //
    public:
    bool id_p () const;
    ::XMLSchema::ID< ACE_TCHAR > const& id () const;
    ::XMLSchema::ID< ACE_TCHAR >& id ();
    void id (::XMLSchema::ID< ACE_TCHAR > const& );

    protected:
    ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

    // label
    //
    public:
    bool label_p () const;
    ::XMLSchema::string< ACE_TCHAR > const& label () const;
    ::XMLSchema::string< ACE_TCHAR >& label ();
    void label (::XMLSchema::string< ACE_TCHAR > const& );

    protected:
    ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > label_;

    // uuid
    //
    public:
    bool uuid_p () const;
    ::XMLSchema::string< ACE_TCHAR > const& uuid () const;
    ::XMLSchema::string< ACE_TCHAR >& uuid ();
    void uuid (::XMLSchema::string< ACE_TCHAR > const& );

    protected:
    ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > uuid_;

    // href
    //
    public:
    bool href_p () const;
    ::XMLSchema::string< ACE_TCHAR > const& href () const;
    ::XMLSchema::string< ACE_TCHAR >& href ();
    void href (::XMLSchema::string< ACE_TCHAR > const& );

    protected:
    ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > href_;

    // idref
    //
    public:
    bool idref_p () const;
    ::XMLSchema::IDREF< ACE_TCHAR > const& idref () const;
    ::XMLSchema::IDREF< ACE_TCHAR >& idref ();
    void idref (::XMLSchema::IDREF< ACE_TCHAR > const& );
    ::XSCRT::Type* idref_ptr ();


    protected:
    ::std::auto_ptr< ::XMLSchema::IDREF< ACE_TCHAR > > idref_;

    // version
    //
    public:
    bool version_p () const;
    ::XMLSchema::string< ACE_TCHAR > const& version () const;
    ::XMLSchema::string< ACE_TCHAR >& version ();
    void version (::XMLSchema::string< ACE_TCHAR > const& );

    protected:
    ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > version_;

    // extender
    //
    public:
    bool extender_p () const;
    ::XMLSchema::string< ACE_TCHAR > const& extender () const;
    ::XMLSchema::string< ACE_TCHAR >& extender ();
    void extender (::XMLSchema::string< ACE_TCHAR > const& );

    protected:
    ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > extender_;

    // extenderID
    //
    public:
    bool extenderID_p () const;
    ::XMLSchema::string< ACE_TCHAR > const& extenderID () const;
    ::XMLSchema::string< ACE_TCHAR >& extenderID ();
    void extenderID (::XMLSchema::string< ACE_TCHAR > const& );

    protected:
    ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > extenderID_;

    public:
    Extension ();

    Extension (::XSCRT::XML::Element< ACE_TCHAR > const&);
    Extension (Extension const& s);

    Extension&
    operator= (Extension const& s);

    private:
    char regulator__;
  };
}

namespace XMI
{
  namespace reader
  {
    XSC_XML_Handlers_Export
    ::XMI::Extension
    extension (xercesc::DOMDocument const*);
  }
}

#include "XMLSchema/Traversal.hpp"

namespace XMI
{
  namespace Traversal
  {
    struct XSC_XML_Handlers_Export Extension : ::XMLSchema::Traversal::Traverser< ::XMI::Extension >
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
      id (Type&);

      virtual void
      id (Type const&);

      virtual void
      id_none (Type&);

      virtual void
      id_none (Type const&);

      virtual void
      label (Type&);

      virtual void
      label (Type const&);

      virtual void
      label_none (Type&);

      virtual void
      label_none (Type const&);

      virtual void
      uuid (Type&);

      virtual void
      uuid (Type const&);

      virtual void
      uuid_none (Type&);

      virtual void
      uuid_none (Type const&);

      virtual void
      href (Type&);

      virtual void
      href (Type const&);

      virtual void
      href_none (Type&);

      virtual void
      href_none (Type const&);

      virtual void
      idref (Type&);

      virtual void
      idref (Type const&);

      virtual void
      idref_none (Type&);

      virtual void
      idref_none (Type const&);

      virtual void
      version (Type&);

      virtual void
      version (Type const&);

      virtual void
      version_none (Type&);

      virtual void
      version_none (Type const&);

      virtual void
      extender (Type&);

      virtual void
      extender (Type const&);

      virtual void
      extender_none (Type&);

      virtual void
      extender_none (Type const&);

      virtual void
      extenderID (Type&);

      virtual void
      extenderID (Type const&);

      virtual void
      extenderID_none (Type&);

      virtual void
      extenderID_none (Type const&);

      virtual void
      post (Type&);

      virtual void
      post (Type const&);
    };
  }
}

#include "XMLSchema/Writer.hpp"

namespace XMI
{
  namespace Writer
  {
    struct Extension : Traversal::Extension,
    virtual ::XSCRT::Writer< ACE_TCHAR >
    {
      typedef ::XMI::Extension Type;
      Extension (::XSCRT::XML::Element< ACE_TCHAR >&);

      virtual void
      traverse (Type &o)
      {
        this->traverse (const_cast <Type const &> (o));
      }

      virtual void
      traverse (Type const&);

      virtual void
      id (Type &o)
      {
        this->id (const_cast <Type const &> (o));
      }

      virtual void
      id (Type const&);

      virtual void
      label (Type &o)
      {
        this->label (const_cast <Type const &> (o));
      }

      virtual void
      label (Type const&);

      virtual void
      uuid (Type &o)
      {
        this->uuid (const_cast <Type const &> (o));
      }

      virtual void
      uuid (Type const&);

      virtual void
      href (Type &o)
      {
        this->href (const_cast <Type const &> (o));
      }

      virtual void
      href (Type const&);

      virtual void
      idref (Type &o)
      {
        this->idref (const_cast <Type const &> (o));
      }

      virtual void
      idref (Type const&);

      virtual void
      version (Type &o)
      {
        this->version (const_cast <Type const &> (o));
      }

      virtual void
      version (Type const&);

      virtual void
      extender (Type &o)
      {
        this->extender (const_cast <Type const &> (o));
      }

      virtual void
      extender (Type const&);

      virtual void
      extenderID (Type &o)
      {
        this->extenderID (const_cast <Type const &> (o));
      }

      virtual void
      extenderID (Type const&);

      protected:
      Extension ();
    };
  }
}

namespace XMI
{
  namespace writer
  {
    XSC_XML_Handlers_Export
    void
    extension (::XMI::Extension const&, xercesc::DOMDocument*);
  }
}

#endif // XMI_HPP
