//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    amh_sh.cpp
//
// = DESCRIPTION
//    Visitor generating AMH skeleton code for Operation node in the
//    skeleton header.
//
// = AUTHOR
//    Mayur Deshpande <mayur@ics.uci.edu>
//
// ============================================================================

ACE_RCSID (be_visitor_operation,
           amh_sh,
           "$Id$")

// ******************************************************
// Visitor for generating AMH skeleton for "operation" in skeleton header.
// ******************************************************

be_visitor_amh_operation_sh::be_visitor_amh_operation_sh (
    be_visitor_context *ctx
  )
  : be_visitor_operation (ctx)
{
}

be_visitor_amh_operation_sh::~be_visitor_amh_operation_sh (void)
{
}

int
be_visitor_amh_operation_sh::visit_operation (be_operation *node)
{
  // If there is an argument of type "native", return immediately.
  if (node->has_native ())
    {
      return 0;
    }

  // Output stream.
  TAO_OutStream *os = this->ctx_->stream ();
  this->ctx_->node (node);

  this->generate_shared_prologue (node, os, "");

  be_visitor_context ctx (*this->ctx_);
  be_visitor_args_arglist arglist_visitor (&ctx);
  arglist_visitor.set_fixed_direction (AST_Argument::dir_IN);
  ctx.scope (node);

  for (UTL_ScopeActiveIterator i (node, UTL_Scope::IK_decls);
       !i.is_done ();
       i.next ())
    {
      be_argument *argument =
        be_argument::narrow_from_decl (i.item ());

      if (argument == 0
          || argument->direction () == AST_Argument::dir_OUT)
        {
          continue;
        }

      *os << "," << be_nl;

      if (arglist_visitor.visit_argument (argument) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_amh_operation_sh::"
                             "visit_operation - "
                             "codegen for upcall args failed\n"),
                            -1);
        }
    }

  *os << env_decl << be_uidt_nl
      << ")" << be_uidt_nl;

  if (be_global->use_raw_throw ())
    {
      *os << "throw (";
    }
  else
    {
      *os << "ACE_THROW_SPEC ((";
    }

  *os << " ::CORBA::SystemException";

  if (be_global->use_raw_throw ())
    {
      *os << ")";
    }
  else
    {
      *os << "))";
    }

  *os << " = 0;";

  return 0;
}

int
be_visitor_amh_operation_sh::visit_attribute (be_attribute *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  this->generate_shared_prologue (node, os, "_get_");

  if (!be_global->exception_support ())
    {
      *os << env_decl;
    }

  *os << be_uidt_nl
      << ")" << be_uidt_nl
      << "ACE_THROW_SPEC (( ::CORBA::SystemException)) = 0;" << be_nl;

  if (node->readonly ())
    {
      return 0;
    }

  this->generate_shared_prologue (node, os, "_set_");

  *os << "," << be_nl;

  be_argument the_argument (AST_Argument::dir_IN,
                            node->field_type (),
                            node->name ());
  be_visitor_context ctx (*this->ctx_);
  be_visitor_args_arglist visitor (&ctx);

  int status = visitor.visit_argument (&the_argument);
  
  the_argument.destroy ();
  
  if (-1 == status)
    {
      return -1;
    }

  if (!be_global->exception_support ())
    {
      *os << env_decl;
    }

  *os << be_uidt_nl << ")" << be_uidt_nl
      << "ACE_THROW_SPEC (( ::CORBA::SystemException)) = 0;" << be_nl;

  return 0;
}

void
be_visitor_amh_operation_sh::generate_shared_prologue (
    be_decl *node,
    TAO_OutStream *os,
    const char *skel_prefix
  )
{
  *os << be_nl << be_nl << "// TAO_IDL - Generated from " << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  *os << "static void " << skel_prefix
      << node->local_name ()
      << "_skel (" << be_idt << be_idt_nl
      << "TAO_ServerRequest &_tao_req," << be_nl
      << "void *_tao_obj," << be_nl
      << "void *_tao_servant_upcall" << env_decl << be_uidt_nl
      << ");" << be_uidt_nl << be_nl;

  // We need the interface node in which this operation was defined. However,
  // if this operation node was an attribute node in disguise, we get this
  // information from the context
  be_interface *intf =
    be_interface::narrow_from_scope (node->defined_in ());

  if (this->ctx_->attribute () != 0)
    {
      intf = be_interface::narrow_from_scope (
                 this->ctx_->attribute()->defined_in ()
               );
    }

  if (intf == 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "(%N:%l) be_visitor_amh_operation_sh::"
                  "visit_operation - "
                  "bad interface scope\n"));
      return;
    }

  // Step 1 : Generate return type: always void
  *os << "virtual void ";

  // Step 2: Generate the method name
  *os << node->local_name() << " (" << be_idt << be_idt_nl;

  // STEP 3: Generate the argument list with the appropriate
  //         mapping. For these we grab a visitor that generates the
  //         parameter listing. We also generate the ResponseHandler
  //         argument 'on the fly' and add it to the argument list

  char *buf;
  // @@ TODO this must be kept consistent with the code in
  //    be_visitor_interface/amh_sh.cpp
  intf->compute_full_name ("AMH_", "ResponseHandler_ptr", buf);

  *os << buf << " _tao_rh";
  // buf was allocated by ACE_OS::strdup, so we must use free instead
  // of delete.
  ACE_OS::free (buf);
  buf = 0;
}
