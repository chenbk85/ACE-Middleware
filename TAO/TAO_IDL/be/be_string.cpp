// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_string.cpp
//
// = DESCRIPTION
//    Extension of class AST_String that provides additional means for C++
//    mapping.
//
// = AUTHOR
//    Copyright 1994-1995 by Sun Microsystems, Inc.
//    and
//    Aniruddha Gokhale
//
// ============================================================================

#include "be_string.h"
#include "be_visitor.h"

#include "utl_identifier.h"
#include "global_extern.h"

ACE_RCSID (be,
           be_string,
           "$Id$")

be_string::be_string (void)
  : COMMON_Base (),
    AST_Decl (),
    AST_Type (),
    AST_String (),
    be_decl (),
    be_type ()
{
  // Always the case.
  this->size_type (AST_Type::VARIABLE);
}

be_string::be_string (AST_Decl::NodeType nt,
                      UTL_ScopedName * n,
                      AST_Expression * v,
                      long width)
  : COMMON_Base (),
    AST_Decl (nt,
              n,
              true),
    AST_Type (nt,
              n),
    AST_String (nt,
                n,
                v,
                width),
    be_decl (nt,
             n),
    be_type (nt,
             n)
{
  idl_global->string_seen_ = true;
}

// Overriden method.
void
be_string::compute_tc_name (void)
{
  Identifier * id = 0;

  AST_Expression zero (static_cast<unsigned long> (0));

  if (*this->max_size () == &zero)
    {
      // If the string is unbounded, use the string TypeCode
      // constants.

      // Start with the head as the CORBA namespace.
      Identifier * corba_id = 0;
      ACE_NEW (corba_id,
               Identifier ("CORBA"));

      ACE_NEW (this->tc_name_,
               UTL_ScopedName (corba_id,
                               0));

      ACE_NEW (id,
               Identifier (this->width () == 1
                           ? "_tc_string"
                           : "_tc_wstring"));
    }
  else
    {
      // We have a bounded string.  Generate a TypeCode name that is
      // meant for internal use alone.

      Identifier * tao_id = 0;
      ACE_NEW (tao_id,
               Identifier ("TAO"));

      ACE_NEW (this->tc_name_,
               UTL_ScopedName (tao_id,
                               0));

      ACE_CString local_tc_name =
        ACE_CString ("tc_")
        + ACE_CString (this->flat_name ());

      Identifier * typecode_scope = 0;
      ACE_NEW (typecode_scope,
               Identifier ("TypeCode"));

      UTL_ScopedName * tc_scope_conc_name = 0;
      ACE_NEW (tc_scope_conc_name,
               UTL_ScopedName (typecode_scope,
                               0));

      this->tc_name_->nconc (tc_scope_conc_name);

      ACE_NEW (id,
               Identifier (local_tc_name.c_str ()));
    }
    
  zero.destroy ();

  UTL_ScopedName *conc_name = 0;
  ACE_NEW (conc_name,
           UTL_ScopedName (id,
                           0));

  this->tc_name_->nconc (conc_name);
}

int
be_string::accept (be_visitor * visitor)
{
  return visitor->visit_string (this);
}

void
be_string::destroy (void)
{
  this->be_type::destroy ();
  this->AST_String::destroy ();
}

// Narrowing.
IMPL_NARROW_METHODS2 (be_string, AST_String, be_type)
IMPL_NARROW_FROM_DECL (be_string)
