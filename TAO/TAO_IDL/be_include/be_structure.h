/* -*- c++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_structure.h
//
// = DESCRIPTION
//    Extension of class AST_Structure that provides additional means for C++
//    mapping.
//
// = AUTHOR
//    Copyright 1994-1995 by Sun Microsystems, Inc.
//    and
//    Aniruddha Gokhale
//
// ============================================================================

#ifndef BE_STRUCTURE_H
#define BE_STRUCTURE_H

#include "be_scope.h"
#include "be_type.h"
#include "ast_structure.h"

class be_visitor;

class be_structure : public virtual AST_Structure,
                     public virtual be_scope,
                     public virtual be_type
{
public:
  be_structure (void);
  // Default constructor.

  be_structure (UTL_ScopedName *n,
                idl_bool local,
                idl_bool abstract);
  // Constructor.

  virtual void redefine (AST_Structure *from);
  // Copy BE-specific values when redefining struct or union
  // from a forward declaration.

  virtual void destroy (void);
  // Cleanup method.

  virtual int accept (be_visitor *visitor);
  // Visiting.

  AST_Field *be_add_field (AST_Field *f);
  // To access the protected base class method fe_add_field.

 // Narrowing.
  DEF_NARROW_METHODS3 (be_structure, AST_Structure, be_scope, be_type);
  DEF_NARROW_FROM_DECL (be_structure);
  DEF_NARROW_FROM_SCOPE (be_structure);
};

#endif
