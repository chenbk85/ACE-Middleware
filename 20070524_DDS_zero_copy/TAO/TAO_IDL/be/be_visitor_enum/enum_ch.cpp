//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    enum_ch.cpp
//
// = DESCRIPTION
//    Visitor generating code for Enums in the client header
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#include "be_visitor_typecode/typecode_decl.h"

ACE_RCSID (be_visitor_enum, 
           enum_ch, 
           "$Id$")


// ********************************************************************
// Visitor implementation for the Enum type
// This one for the client header file
// ********************************************************************

be_visitor_enum_ch::be_visitor_enum_ch (be_visitor_context *ctx)
  : be_visitor_scope (ctx)
{
}

be_visitor_enum_ch::~be_visitor_enum_ch (void)
{
}

// Visit the enum_ch node and its scope.
int
be_visitor_enum_ch::visit_enum (be_enum *node)
{
  if (node->cli_hdr_gen () || node->imported ())
    {
      return 0;
    }

  TAO_OutStream *os = this->ctx_->stream ();

  // Comma to be generated by the scope visitor.
  this->ctx_->comma (1);

  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  *os << "enum " << node->local_name () << be_nl;
  *os << "{" << be_idt_nl;

   if (this->visit_scope (node) == 1)
     {
       ACE_ERROR_RETURN ((LM_ERROR,
                          "(%N:%l) be_visitor_enum_ch::"
                          "visit_enum - "
                          "scope generation failed\n"
                          ),
                         -1);
     }

  *os << be_uidt_nl;
  *os << "};" << be_nl << be_nl;

  // As per the ORBOS spec, we need the following typedef
  *os << "typedef " << node->local_name () << " &" << node->local_name ()
      << "_out;";

  if (be_global->tc_support ())
    {
      be_visitor_context ctx (*this->ctx_);
      be_visitor_typecode_decl visitor (&ctx);

      if (node->accept (&visitor) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_enum_ch::"
                             "visit_enum - "
                             "TypeCode declaration failed\n"
                             ),
                            -1);
        }
    }

  node->cli_hdr_gen (true);
  return 0;
}

int
be_visitor_enum_ch::post_process (be_decl *bd)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // Am I the last one?
  if (!this->last_node (bd))
    {
      *os << "," << be_nl;
    }

  return 0;
}

int
be_visitor_enum_ch::visit_enum_val (be_enum_val *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  *os << node->local_name ();

  return 0;
}
