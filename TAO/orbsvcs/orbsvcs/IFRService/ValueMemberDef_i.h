// -*- C++ -*-

// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/orbsvcs/orbsvcs/IFRService
//
// = FILENAME
//    ValueMemberDef_i.h
//
// = DESCRIPTION
//    ValueMemberDef servant class.
//
// = AUTHOR
//    Jeff Parsons <parsons@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_VALUEMEMBERDEF_I_H
#define TAO_VALUEMEMBERDEF_I_H

#include "orbsvcs/IFRService/Contained_i.h"
#include "orbsvcs/IFRService/ifr_service_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_IFRService_Export TAO_ValueMemberDef_i : public virtual TAO_Contained_i
{
  // = TITLE
  //    TAO_ValeMemberDef_i
  //
  // = DESCRIPTION
  //    Represents the definition of a valuemember structure.
  //
public:
  TAO_ValueMemberDef_i (TAO_Repository_i *repoy);
  // Constructor

  virtual ~TAO_ValueMemberDef_i (void);
  // Destructor

  virtual CORBA::DefinitionKind def_kind ()
;
  // Return our definition kind.

  virtual CORBA::Contained::Description *describe ()
;
  // From Contained_i's pure virtual function.

  virtual CORBA::Contained::Description *describe_i ()
;
  // From Contained_i's pure virtual function.

  virtual CORBA::TypeCode_ptr type ()
;

  CORBA::TypeCode_ptr type_i ()
;

  virtual CORBA::IDLType_ptr type_def ()
;

  CORBA::IDLType_ptr type_def_i ()
;

  virtual void type_def (
      CORBA::IDLType_ptr type_def)
;

  void type_def_i (
      CORBA::IDLType_ptr type_def)
;

  virtual CORBA::Visibility access ()
;

  CORBA::Visibility access_i ()
;

  virtual void access (
      CORBA::Visibility access)
;

  void access_i (
      CORBA::Visibility access)
;
};

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* TAO_VALUEMEMBERDEF_I_H */
