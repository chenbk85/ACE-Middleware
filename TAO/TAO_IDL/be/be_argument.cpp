// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_argument.cpp
//
// = DESCRIPTION
//    Extension of class AST_Argument that provides additional means for C++
//    mapping.
//
// = AUTHOR
//    Copyright 1994-1995 by Sun Microsystems, Inc.
//    and
//    Aniruddha Gokhale
//
// ============================================================================

#include "be_argument.h"
#include "be_type.h"
#include "be_visitor.h"
#include "nr_extern.h"

ACE_RCSID (be,
           be_argument,
           "$Id$")

be_argument::be_argument (void)
  : COMMON_Base (),
    AST_Decl (),
    AST_Field (),
    AST_Argument (),
    be_decl ()
{
}

be_argument::be_argument (AST_Argument::Direction d,
                          AST_Type *ft,
                          UTL_ScopedName *n)
  : COMMON_Base (),
    AST_Decl (AST_Decl::NT_argument,
              n),
    AST_Field (AST_Decl::NT_argument,
               ft,
               n),
    AST_Argument (d,
                  ft,
                  n),
    be_decl (AST_Decl::NT_argument,
             n)
{
  AST_Decl *dcl = ScopeAsDecl (this->defined_in ());

  if (!dcl->imported () && !dcl->is_local ())
    {
      be_type *bt = be_type::narrow_from_decl (ft);
      bt->seen_in_operation (I_TRUE);
      this->set_arg_seen_bit (bt);
    }
}


int
be_argument::accept (be_visitor *visitor)
{
  return visitor->visit_argument (this);
}

// Narrowing.
IMPL_NARROW_METHODS2 (be_argument, AST_Argument, be_decl)
IMPL_NARROW_FROM_DECL (be_argument)
