//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_visitor_enum.cpp
//
// = DESCRIPTION
//    Visitors for generation of code for Enum
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#include	"idl.h"
#include	"idl_extern.h"
#include	"be.h"

#include "be_visitor_enum.h"

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

// visit the Enum_Ch node and its scope
int
be_visitor_enum_ch::visit_enum (be_enum *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  this->ctx_->comma (1); // comma to be generated by the scope visitor

  if (!node->cli_hdr_gen () && !node->imported ())
    {
      os->indent (); // start from whatever indentation level we were at
      *os << "enum " << node->local_name () << be_nl;
      *os << "{\n";
      os->incr_indent ();
      if (this->visit_scope (node) == 1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_enum_ch::"
                             "visit_enum - "
                             "scope generation failed\n"
                             ), -1);
        }

      os->decr_indent ();
      *os << "};" << be_nl;
      // As per the ORBOS spec, we need the following typedef
      *os << "typedef " << node->local_name () << " &" << node->local_name ()
          << "_out;\n";

      // by using a visitor to declare and define the TypeCode, we have the
      // added advantage to conditionally not generate any code. This will be
      // based on the command line options. This is still TO-DO
      be_visitor *visitor;
      be_visitor_context ctx (*this->ctx_);
      ctx.state (TAO_CodeGen::TAO_TYPECODE_DECL);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (node->accept (visitor) == -1))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_enum_ch::"
                             "visit_enum - "
                             "TypeCode declaration failed\n"
                             ), -1);
        }

      node->cli_hdr_gen (I_TRUE);
    }
  return 0;
}

int
be_visitor_enum_ch::post_process (void)
{
  TAO_OutStream *os = this->ctx_->stream ();

  *os << "," << be_nl;
  return 0;
}

int
be_visitor_enum_ch::visit_enum_val (be_enum_val *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  os->indent ();
  *os << node->local_name ();

  return 0;
}


// ********************************************************************
// Visitor implementation for the Enum type
// This one for the client stubs file
// ********************************************************************

be_visitor_enum_cs::be_visitor_enum_cs (be_visitor_context *ctx)
  : be_visitor_scope (ctx)
{
}

be_visitor_enum_cs::~be_visitor_enum_cs (void)
{
}

// visit the Enum_cs node and its scope
int
be_visitor_enum_cs::visit_enum (be_enum *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  if (!node->cli_stub_gen () && !node->imported ())
    {
      // generate the typecode information here
      os->indent (); // start from current indentation level
      *os << be_nl
          << "static const CORBA::Long _oc_" << node->flatname () << "[] ="
          << be_nl
          << "{" << be_idt_nl;
      if (node->gen_encapsulation () == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_enum_cs::"
                             "visit_enum - "
                             "scope generation failed\n"
                             ), -1);
        }
      os->decr_indent ();
      *os << "};\n";

      // by using a visitor to declare and define the TypeCode, we have the
      // added advantage to conditionally not generate any code. This will be
      // based on the command line options. This is still TO-DO
      be_visitor *visitor;
      be_visitor_context ctx (*this->ctx_);
      ctx.state (TAO_CodeGen::TAO_TYPECODE_DEFN);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (node->accept (visitor) == -1))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_enum_cs::"
                             "visit_enum - "
                             "TypeCode definition failed\n"
                             ), -1);
        }

      node->cli_stub_gen (I_TRUE);
    }
  return 0;
}

// ***************************************************************************
// Enum visitor for generating Any operator declarations in the client header
// ***************************************************************************

be_visitor_enum_any_op_ch::be_visitor_enum_any_op_ch
(be_visitor_context *ctx)
  : be_visitor_scope (ctx)
{
}

be_visitor_enum_any_op_ch::~be_visitor_enum_any_op_ch (void)
{
}

int
be_visitor_enum_any_op_ch::visit_enum (be_enum *node)
{
  if (node->cli_hdr_any_op_gen () || node->imported ())
    return 0;

  TAO_OutStream *os = tao_cg->client_header ();

  // generate the Any <<= and >>= operators
  os->indent ();
  *os << "void operator<<= (CORBA::Any &, " << node->name ()
      << ");" << be_nl;
  *os << "CORBA::Boolean operator>>= (const CORBA::Any &, "
      << node->name () << " &);\n";

  node->cli_hdr_any_op_gen (1);
  return 0;
}

// ***************************************************************************
// Enum visitor for generating Any operator declarations in the client
// stubs file
// ***************************************************************************

be_visitor_enum_any_op_cs::be_visitor_enum_any_op_cs
(be_visitor_context *ctx)
  : be_visitor_scope (ctx)
{
}

be_visitor_enum_any_op_cs::~be_visitor_enum_any_op_cs (void)
{
}

int
be_visitor_enum_any_op_cs::visit_enum (be_enum *node)
{
  if (node->cli_stub_any_op_gen () || node->imported ())
    return 0;

  TAO_OutStream *os = tao_cg->client_stubs ();

  // generate the Any <<= and >>= operator declarations
  // Any <<= and >>= operators
  os->indent ();
  *os << "void operator<<= (CORBA::Any &_tao_any, "
      << node->name () << " _tao_elem)" << be_nl
      << "{" << be_idt_nl
      << "CORBA::Environment _tao_env;" << be_nl
      << "_tao_any.replace (" << node->tc_name () << ", &"
      << "_tao_elem, 1, _tao_env);" << be_uidt_nl
      << "}" << be_nl;

  *os << "CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, "
      << node->name () << " &_tao_elem)" << be_nl
      << "{" << be_idt_nl
      << "CORBA::Environment _tao_env;" << be_nl
      << "if (!_tao_any.type ()->equal (" << node->tc_name ()
      << ", _tao_env)) return 0; // not equal" << be_nl
      << "TAO_InputCDR stream ((ACE_Message_Block *)_tao_any.value ());"
      << be_nl
      << "if (stream.decode (" << node->tc_name ()
      << ", &_tao_elem, 0, _tao_env)" << be_nl
      << "  == CORBA::TypeCode::TRAVERSE_CONTINUE)" << be_nl
      << "  return 1;" << be_nl
      << "else" << be_nl
      << "  return 0;" << be_uidt_nl
      << "}\n\n";

  node->cli_stub_any_op_gen (1);
  return 0;
}
