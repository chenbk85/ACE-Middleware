//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    any_op_cs.cpp
//
// = DESCRIPTION
//    Visitor for code generation of Arrays for the Any operators in the client
//    stubs.
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

ACE_RCSID (be_visitor_array, 
           any_op_cs, 
           "$Id$")


// ***************************************************************************
// Array visitor for generating Any operator declarations in the client
// stubs file
// ***************************************************************************

be_visitor_array_any_op_cs::be_visitor_array_any_op_cs (
    be_visitor_context *ctx
  )
  : be_visitor_decl (ctx)
{
}

be_visitor_array_any_op_cs::~be_visitor_array_any_op_cs (void)
{
}

int
be_visitor_array_any_op_cs::visit_array (be_array *node)
{
  if (node->cli_stub_any_op_gen () || node->imported ())
    {
      return 0;
    }

  TAO_OutStream *os = this->ctx_->stream ();

  *os << be_nl << be_nl 
      << "// TAO_IDL - Generated from " << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  *os << "void operator<<= (" << be_idt << be_idt_nl
      << "CORBA::Any &_tao_any," << be_nl
      << "const " << node->name () << "_forany &_tao_elem" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl
      << "TAO::Any_Array_Impl_T<" << be_idt << be_idt_nl
      << node->name () << "_slice," << be_nl
      << node->name () << "_forany" << be_uidt_nl
      << ">::insert (" 
      << be_idt << be_idt_nl
      << "_tao_any," << be_nl
      << node->name () << "_forany::_tao_any_destructor," << be_nl
      << node->tc_name () << "," << be_nl
      << "ACE_const_cast (" << be_idt << be_idt_nl
      << node->name () << "_slice * const," << be_nl
      << "_tao_elem.nocopy ()" << be_idt_nl
      << "? _tao_elem.in ()" << be_nl
      << ": ACE_const_cast (" << be_idt << be_idt << be_idt_nl
      << "const " << node->name () << "_slice *," << be_nl
      << node->name () << "_dup (_tao_elem.in ())" << be_uidt_nl
      << ")" << be_uidt << be_uidt << be_uidt << be_uidt_nl
      << ")" << be_uidt << be_uidt_nl
      << ");" << be_uidt << be_uidt << be_uidt_nl
      << "}" << be_nl << be_nl;

  *os << "CORBA::Boolean operator>>= (" << be_idt << be_idt_nl
      << "const CORBA::Any &_tao_any," << be_nl
      << node->name () << "_forany &_tao_elem" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl
      << "return" << be_idt_nl
      << "TAO::Any_Array_Impl_T<" << be_idt << be_idt_nl
      << node->name () << "_slice," << be_nl
      << node->name () << "_forany" << be_uidt_nl
      << ">::extract ("
      << be_idt << be_idt_nl
      << "_tao_any," << be_nl
      << node->name () << "_forany::_tao_any_destructor," << be_nl
      << node->tc_name () << "," << be_nl
      << "ACE_const_cast (" << be_idt << be_idt_nl
      << "const " << node->name () << "_slice *&," << be_nl
      << "_tao_elem.out ()" << be_uidt_nl
      << ")" << be_uidt << be_uidt_nl
      << ");" << be_uidt << be_uidt << be_uidt << be_uidt_nl
      << "}";

  // Since we don't generate CDR stream operators for types that
  // explicitly contain a local interface (at some level), we 
  // must override these Any template class methods to avoid
  // calling the non-existent operators. The zero return value
  // will eventually cause CORBA::MARSHAL to be raised if this
  // type is inserted into an Any and then marshaled.
  if (node->is_local ())
    {
      *os << be_nl << be_nl
          << "template<>" << be_nl
          << "ACE_INLINE" << be_nl
          << "CORBA::Boolean" << be_nl
          << "TAO::Any_Array_Impl_T<" << node->name ()
          << "_slice, " << node->name () 
          << "_forany>::marshal_value (TAO_OutputCDR &)" << be_nl
          << "{" << be_idt_nl
          << "return 0;" << be_uidt_nl
          << "}";

      *os << be_nl << be_nl
          << "template<>" << be_nl
          << "ACE_INLINE" << be_nl
          << "CORBA::Boolean" << be_nl
          << "TAO::Any_Array_Impl_T<" << node->name ()
          << "_slice, " << node->name () 
          << "_forany>::demarshal_value (TAO_InputCDR &)" << be_nl
          << "{" << be_idt_nl
          << "return 0;" << be_uidt_nl
          << "}";
    }

  *os << be_nl << be_nl
      << "#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \\"
      << be_idt_nl
      << "  defined (ACE_HAS_GNU_REPO)" << be_nl
      << "template class TAO::Any_Array_Impl_T<" << be_idt << be_idt_nl
      << node->name () << "_slice," << be_nl
      << node->name () << "_forany" << be_uidt_nl
      << ">;" << be_uidt << be_uidt_nl
      << "#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)" << be_nl
      << "# pragma instantiate TAO::Any_Array_Impl_T<" << be_idt << be_idt_nl
      << node->name () << "_slice," << be_nl
      << node->name () << "_forany" << be_uidt_nl
      << ">" << be_uidt_nl
      << "#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */";

  node->cli_stub_any_op_gen (1);
  return 0;
}
