// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be\be_codegen.cpp:545

#ifndef _TAO_IDL____ORBSVCS_ORBSVCS_IFRSERVICE_IFR_BASES_T_H_
#define _TAO_IDL____ORBSVCS_ORBSVCS_IFRSERVICE_IFR_BASES_T_H_

#include /**/ "ace/pre.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be\be_visitor_root/root_sth.cpp:116

namespace POA_CORBA
{

  // TAO_IDL - Generated from
  // be\be_visitor_interface/tie_sh.cpp:87

  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  IRObject_tie : public IRObject
  {
  public:
    /// the T& ctor
    IRObject_tie (T &t);
    /// ctor taking a POA
    IRObject_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    IRObject_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    IRObject_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor

    ~IRObject_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership

    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::DefinitionKind def_kind (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    void destroy (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;

    // copy and assignment are not allowed
    IRObject_tie (const IRObject_tie &);
    void operator= (const IRObject_tie &);
  };

  // TAO_IDL - Generated from
  // be\be_visitor_interface/tie_sh.cpp:87

  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  Contained_tie : public Contained
  {
  public:
    /// the T& ctor
    Contained_tie (T &t);
    /// ctor taking a POA
    Contained_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    Contained_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    Contained_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor

    ~Contained_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership

    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::DefinitionKind def_kind (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    void destroy (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    char * id (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    void id (
        const char * id
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    char * name (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    void name (
        const char * name
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    char * version (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    void version (
        const char * version
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::Container_ptr defined_in (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    char * absolute_name (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::Repository_ptr containing_repository (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::Contained::Description * describe (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    void move (
        ::CORBA::Container_ptr new_container,
        const char * new_name,
        const char * new_version
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;

    // copy and assignment are not allowed
    Contained_tie (const Contained_tie &);
    void operator= (const Contained_tie &);
  };

  // TAO_IDL - Generated from
  // be\be_visitor_interface/tie_sh.cpp:87

  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  Container_tie : public Container
  {
  public:
    /// the T& ctor
    Container_tie (T &t);
    /// ctor taking a POA
    Container_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    Container_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    Container_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor

    ~Container_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership

    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::DefinitionKind def_kind (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    void destroy (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::Contained_ptr lookup (
        const char * search_name
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::ContainedSeq * contents (
        ::CORBA::DefinitionKind limit_type,
        ::CORBA::Boolean exclude_inherited
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::ContainedSeq * lookup_name (
        const char * search_name,
        ::CORBA::Long levels_to_search,
        ::CORBA::DefinitionKind limit_type,
        ::CORBA::Boolean exclude_inherited
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::Container::DescriptionSeq * describe_contents (
        ::CORBA::DefinitionKind limit_type,
        ::CORBA::Boolean exclude_inherited,
        ::CORBA::Long max_returned_objs
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::ModuleDef_ptr create_module (
        const char * id,
        const char * name,
        const char * version
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::ConstantDef_ptr create_constant (
        const char * id,
        const char * name,
        const char * version,
        ::CORBA::IDLType_ptr type,
        const ::CORBA::Any & value
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::StructDef_ptr create_struct (
        const char * id,
        const char * name,
        const char * version,
        const ::CORBA::StructMemberSeq & members
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::UnionDef_ptr create_union (
        const char * id,
        const char * name,
        const char * version,
        ::CORBA::IDLType_ptr discriminator_type,
        const ::CORBA::UnionMemberSeq & members
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::EnumDef_ptr create_enum (
        const char * id,
        const char * name,
        const char * version,
        const ::CORBA::EnumMemberSeq & members
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::AliasDef_ptr create_alias (
        const char * id,
        const char * name,
        const char * version,
        ::CORBA::IDLType_ptr original_type
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::InterfaceDef_ptr create_interface (
        const char * id,
        const char * name,
        const char * version,
        const ::CORBA::InterfaceDefSeq & base_interfaces
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::ValueDef_ptr create_value (
        const char * id,
        const char * name,
        const char * version,
        ::CORBA::Boolean is_custom,
        ::CORBA::Boolean is_abstract,
        ::CORBA::ValueDef_ptr base_value,
        ::CORBA::Boolean is_truncatable,
        const ::CORBA::ValueDefSeq & abstract_base_values,
        const ::CORBA::InterfaceDefSeq & supported_interfaces,
        const ::CORBA::InitializerSeq & initializers
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::ValueBoxDef_ptr create_value_box (
        const char * id,
        const char * name,
        const char * version,
        ::CORBA::IDLType_ptr original_type_def
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::ExceptionDef_ptr create_exception (
        const char * id,
        const char * name,
        const char * version,
        const ::CORBA::StructMemberSeq & members
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::NativeDef_ptr create_native (
        const char * id,
        const char * name,
        const char * version
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::AbstractInterfaceDef_ptr create_abstract_interface (
        const char * id,
        const char * name,
        const char * version,
        const ::CORBA::AbstractInterfaceDefSeq & base_interfaces
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::LocalInterfaceDef_ptr create_local_interface (
        const char * id,
        const char * name,
        const char * version,
        const ::CORBA::InterfaceDefSeq & base_interfaces
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::ExtValueDef_ptr create_ext_value (
        const char * id,
        const char * name,
        const char * version,
        ::CORBA::Boolean is_custom,
        ::CORBA::Boolean is_abstract,
        ::CORBA::ValueDef_ptr base_value,
        ::CORBA::Boolean is_truncatable,
        const ::CORBA::ValueDefSeq & abstract_base_values,
        const ::CORBA::InterfaceDefSeq & supported_interfaces,
        const ::CORBA::ExtInitializerSeq & initializers
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;

    // copy and assignment are not allowed
    Container_tie (const Container_tie &);
    void operator= (const Container_tie &);
  };

  // TAO_IDL - Generated from
  // be\be_visitor_interface/tie_sh.cpp:87

  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  IDLType_tie : public IDLType
  {
  public:
    /// the T& ctor
    IDLType_tie (T &t);
    /// ctor taking a POA
    IDLType_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    IDLType_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    IDLType_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor

    ~IDLType_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership

    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::DefinitionKind def_kind (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    void destroy (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::TypeCode_ptr type (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;

    // copy and assignment are not allowed
    IDLType_tie (const IDLType_tie &);
    void operator= (const IDLType_tie &);
  };

  // TAO_IDL - Generated from
  // be\be_visitor_interface/tie_sh.cpp:87

  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  TypedefDef_tie : public TypedefDef
  {
  public:
    /// the T& ctor
    TypedefDef_tie (T &t);
    /// ctor taking a POA
    TypedefDef_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    TypedefDef_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    TypedefDef_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor

    ~TypedefDef_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership

    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::DefinitionKind def_kind (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    void destroy (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    char * id (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    void id (
        const char * id
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    char * name (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    void name (
        const char * name
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    char * version (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    void version (
        const char * version
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::Container_ptr defined_in (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    char * absolute_name (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::Repository_ptr containing_repository (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::Contained::Description * describe (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    void move (
        ::CORBA::Container_ptr new_container,
        const char * new_name,
        const char * new_version
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/tie_sh.cpp:60

    ::CORBA::TypeCode_ptr type (
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      ));

  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;

    // copy and assignment are not allowed
    TypedefDef_tie (const TypedefDef_tie &);
    void operator= (const TypedefDef_tie &);
  };
} // module CORBA

// TAO_IDL - Generated from
// be\be_codegen.cpp:1322


TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "IFR_BaseS_T.inl"
#endif /* defined INLINE */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "IFR_BaseS_T.cpp"
#endif /* defined REQUIRED SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("IFR_BaseS_T.cpp")
#endif /* defined REQUIRED PRAGMA */

#include /**/ "ace/post.h"
#endif /* ifndef */

