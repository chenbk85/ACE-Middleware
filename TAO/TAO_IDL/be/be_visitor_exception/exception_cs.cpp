//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    exception_cs.cpp
//
// = DESCRIPTION
//    Visitor generating code for Exception in the stubs file
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#include "be_visitor_typecode/typecode_defn.h"

ACE_RCSID (be_visitor_exception, 
           exception_cs, 
           "$Id$")

// ***************************************************************************
// For client stubs.
// ***************************************************************************

be_visitor_exception_cs::be_visitor_exception_cs (be_visitor_context *ctx)
  : be_visitor_exception (ctx)
{
}

be_visitor_exception_cs::~be_visitor_exception_cs (void)
{
}

// Visit the Exception_Cs node and its scope.
int be_visitor_exception_cs::visit_exception (be_exception *node)
{
  if (node->cli_stub_gen () || node->imported ())
    {
      return 0;
    }

  TAO_OutStream *os = this->ctx_->stream ();

  os->indent ();

  // Generate stub code  required of any anonymous types of members.
  if (this->visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_exception::"
                         "visit_exception -"
                         "code for stub failed\n"),
                        -1);
    }

  *os << be_nl << be_nl << "// TAO_IDL - Generated from " << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  // Default constructor.
  *os << node->name () << "::" << node->local_name ()
      << " (void)" << be_idt_nl;
  *os << ": CORBA_UserException (" << be_idt << be_idt << be_idt_nl
      << "\"" << node->repoID () << "\"," << be_nl
      << "\"" << node->local_name () << "\"" << be_uidt_nl
      << ")" << be_uidt << be_uidt << be_uidt_nl;
  *os << "{" << be_nl;
  *os << "}" << be_nl << be_nl;

  // Destructor.
  *os << node->name () << "::~" << node->local_name ()
      << " (void)" << be_nl;
  *os << "{" << be_nl;
  *os << "}" << be_nl << be_nl;

  // Copy constructor.
  *os << node->name () << "::" << node->local_name () << " (const ::"
      << node->name () << " &_tao_excp)" << be_idt_nl;
  *os << ": CORBA_UserException (" << be_idt << be_idt << be_idt_nl
      << "_tao_excp._rep_id ()," << be_nl
      << "_tao_excp._name ()" << be_uidt_nl
      << ")" << be_uidt << be_uidt << be_uidt_nl;
  *os << "{";

  be_visitor_context ctx (*this->ctx_);
  ctx.state (TAO_CodeGen::TAO_EXCEPTION_CTOR_ASSIGN_CS);

  if (node->nmembers () > 0)
    {
      *os << be_idt;

      // Assign each individual member.
      be_visitor_exception_ctor_assign visitor (&ctx);

      if (node->accept (&visitor) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_exception_cs::"
                             "visit_exception -"
                             "codegen for scope failed\n"),
                            -1);
        }
    }

  *os << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Assignment operator.
  *os << node->name () << "&" << be_nl;
  *os << node->name () << "::operator= (const ::"
      << node->name () << " &_tao_excp)" << be_nl
      << "{" << be_idt_nl
      << "this->CORBA_UserException::operator= "
      << "(_tao_excp);";

  // Assign each individual member.
  ctx = *this->ctx_;
  ctx.state (TAO_CodeGen::TAO_EXCEPTION_CTOR_ASSIGN_CS);
  be_visitor_exception_ctor_assign visitor (&ctx);

  if (node->accept (&visitor) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_exception_cs::"
                         "visit_exception -"
                         "codegen for scope failed\n"),
                        -1);
    }

  *os << be_nl 
      << "return *this;" << be_uidt_nl
      << "}" << be_nl << be_nl;

  if (be_global->any_support ())
    {
      *os << "void "
          << node->name ()
          << "::_tao_any_destructor (void *_tao_void_pointer)" << be_nl
          << "{" << be_idt_nl
          << node->local_name () << " *tmp = ACE_static_cast ("
          << node->local_name () << "*, _tao_void_pointer);" << be_nl
          << "delete tmp;" << be_uidt_nl
          << "}" << be_nl << be_nl;
    }

  *os << node->name () << " *" << be_nl;
  *os << node->name () << "::_downcast (CORBA::Exception *exc)" << be_nl;
  *os << "{" << be_idt_nl;
  *os << "if (!ACE_OS::strcmp (\"" << node->repoID ()
      << "\", exc->_rep_id ()))" << be_idt_nl;
  *os << "{" << be_idt_nl;
  *os << "return ACE_dynamic_cast (" << node->local_name ()
      << " *, exc);" << be_uidt_nl;
  *os << "}" << be_uidt_nl;
  *os << "else" << be_idt_nl;
  *os << "{" << be_idt_nl;
  *os << "return 0;" << be_uidt_nl;
  *os << "}" << be_uidt << be_uidt_nl;
  *os << "}" << be_nl << be_nl;

  // Generate the _alloc method.
  *os << "CORBA::Exception *" << node->name ()
      << "::_alloc (void)" << be_nl;
  *os << "{" << be_idt_nl;
  *os << "CORBA::Exception *retval = 0;" << be_nl
      << "ACE_NEW_RETURN (retval, ::" << node->name ()
      << ", 0);" << be_nl
      << "return retval;" << be_uidt_nl;
  *os << "}" << be_nl << be_nl;

  *os << "CORBA::Exception *" << be_nl
      << node->name () << "::_tao_duplicate (void) const" << be_nl
      << "{" << be_idt_nl
      << "CORBA::Exception *result;" << be_nl
      << "ACE_NEW_RETURN (" << be_idt << be_idt_nl
      << "result," << be_nl
      << "::" << node->name () << " (*this)," << be_nl
      << "0" << be_uidt_nl
      << ");" << be_uidt_nl
      << "return result;" << be_uidt_nl
      << "}" << be_nl << be_nl;
  
  *os << "void " << node->name () << "::_raise (void)" << be_nl
      << "{" << be_idt_nl
      << "TAO_RAISE (*this);" << be_uidt_nl
      << "}" << be_nl << be_nl;

  *os << "void " << node->name ()
      << "::_tao_encode (" << be_idt << be_idt_nl;

  if (!node->is_local ())
    {
      *os << "TAO_OutputCDR &cdr" << be_nl
          << "ACE_ENV_ARG_DECL" << be_uidt_nl
          << ") const" << be_uidt_nl
          << "{" << be_idt_nl
          << "if (cdr << *this)" << be_idt_nl
          << "{" << be_idt_nl
          << "return;" << be_uidt_nl
          << "}" << be_uidt_nl << be_nl;

      if (be_global->use_raw_throw ())
        {
          *os << "throw CORBA::MARSHAL ();" << be_uidt_nl;
        }
      else
        {
          *os << "ACE_THROW (CORBA::MARSHAL ());" << be_uidt_nl;
        }

      *os << "}" << be_nl << be_nl;
    }
  else
    {
      *os << "TAO_OutputCDR &" << be_nl
          << "ACE_ENV_ARG_DECL" << be_uidt_nl
          << ") const" << be_uidt_nl
          << "{" << be_idt_nl;

      if (be_global->use_raw_throw ())
        {
          *os << "throw CORBA::MARSHAL ();" << be_uidt_nl;
        }
      else
        {
          *os << "ACE_THROW (CORBA::MARSHAL ());" << be_uidt_nl;
        }

      *os << "}" << be_nl << be_nl;
    }

  *os << "void " << node->name ()
      << "::_tao_decode (" << be_idt << be_idt_nl;

  if (!node->is_local ())
    {
      *os << "TAO_InputCDR &cdr" << be_nl
          << "ACE_ENV_ARG_DECL" << be_uidt_nl
          << ")" << be_uidt_nl
          << "{" << be_idt_nl
          << "if (cdr >> *this)" << be_idt_nl
          << "{" << be_idt_nl
          << "return;" << be_uidt_nl
          << "}" << be_uidt_nl << be_nl;

      if (be_global->use_raw_throw ())
        {
          *os << "throw CORBA::MARSHAL ();" << be_uidt_nl;
        }
      else
        {
          *os << "ACE_THROW (CORBA::MARSHAL ());" << be_uidt_nl;
        }

      *os << "}" << be_nl << be_nl;
    }
  else
    {
      *os << "TAO_InputCDR &" << be_nl
          << "ACE_ENV_ARG_DECL" << be_uidt_nl
          << ")" << be_uidt_nl
          << "{" << be_idt_nl;

      if (be_global->use_raw_throw ())
        {
          *os << "throw CORBA::MARSHAL ();" << be_uidt_nl;
        }
      else
        {
          *os << "ACE_THROW (CORBA::MARSHAL ());" << be_uidt_nl;
        }

      *os << "}" << be_nl << be_nl;
    }

  // Constructor taking all members. It exists only if there are any
  // members.
  if (node->member_count () > 0)
    {
      // Generate the signature.
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_EXCEPTION_CTOR_CS);
      be_visitor_exception_ctor ec_visitor (&ctx);

      if (node->accept (&ec_visitor) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_exception::"
                             "visit_exception - "
                             "codegen for ctor failed\n"),
                            -1);
        }

      *os << "  : CORBA_UserException (" 
          << be_idt << be_idt << be_idt << be_idt_nl
          << "\"" << node->repoID () << "\"," << be_nl
          << "\"" << node->local_name () << "\"" << be_uidt_nl
          << ")" << be_uidt << be_uidt << be_uidt << be_uidt_nl;
      *os << "{" << be_idt;

      // Assign each individual member. We need yet another state.
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_EXCEPTION_CTOR_ASSIGN_CS);

      // Indicate that the special ctor is being generated.
      ctx.exception (1);

      be_visitor_exception_ctor_assign eca_visitor (&ctx);

      if (node->accept (&eca_visitor) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_exception_cs::"
                             "visit_exception -"
                             "codegen for scope failed\n"),
                            -1);
        }

      *os << be_uidt_nl << "}" << be_nl << be_nl;
    }

  if (be_global->tc_support ())
    {
      *os << "// TAO extension - the virtual _type method." << be_nl;
      *os << "CORBA::TypeCode_ptr " << node->name ()
          << "::_type (void) const" << be_nl;
      *os << "{" << be_idt_nl;
      *os << "return ::" << node->tc_name () << ";" << be_uidt_nl;
      *os << "}";
    }

  if (be_global->tc_support ())
    {
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_TYPECODE_DEFN);
      ctx.sub_state (TAO_CodeGen::TAO_TC_DEFN_TYPECODE);
      be_visitor_typecode_defn visitor (&ctx);

      if (node->accept (&visitor) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_exception_cs::"
                             "visit_exception - "
                             "TypeCode definition failed\n"),
                            -1);
        }
    }

  node->cli_stub_gen (I_TRUE);
  return 0;
}
