//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    operation_ss.cpp
//
// = DESCRIPTION
//    Visitor generating code for Operation in the server skeleton
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#include        "idl.h"
#include        "idl_extern.h"
#include        "be.h"

#include "be_visitor_operation.h"
#include "be_visitor_argument.h"

ACE_RCSID(be_visitor_operation, operation_ss, "$Id$")


// ************************************************************
// Operation visitor for server skeletons
// ************************************************************

be_visitor_operation_ss::be_visitor_operation_ss (be_visitor_context *ctx)
  : be_visitor_operation (ctx),
    operation_name_ (0)
{
}

be_visitor_operation_ss::~be_visitor_operation_ss (void)
{
  delete[] this->operation_name_;
}

// processing to be done after every element in the scope is processed
int
be_visitor_operation_ss::post_process (be_decl *bd)
{
  // all we do here is to insert a comma and a newline
  TAO_OutStream *os = this->ctx_->stream ();
  if (!this->last_node (bd))
    *os << ",\n";
  return 0;
}

int
be_visitor_operation_ss::visit_operation (be_operation *node)
{
  TAO_OutStream *os; // output stream
  be_type *bt;       // type node for return type

  os = this->ctx_->stream (); // grab the o/p stream
  this->ctx_->node (node); // save the node for future use

  os->indent (); // start with the current indentation level

  // if there is an argument of type "native", return immediately
  if (node->has_native ())
    return 0;

  // retrieve the operation return type
  bt = be_type::narrow_from_decl (node->return_type ());
  if (!bt)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_ss::"
                         "visit_operation - "
                         "Bad return type\n"),
                        -1);
    }

  // We need the interface node in which this operation was defined. However,
  // if this operation node was an attribute node in disguise, we get this
  // information from the context
  be_interface *intf;
  intf = this->ctx_->attribute ()
    ? be_interface::narrow_from_scope (this->ctx_->attribute ()->defined_in ())
    : be_interface::narrow_from_scope (node->defined_in ());

  if (!intf)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_ss::"
                         "visit_operation - "
                         "bad interface scope\n"),
                        -1);
    }

  // generate the signature of the static skeleton
  os->indent ();
  *os << "void " << intf->full_skel_name () << "::";
  // check if we are an attribute node in disguise
  if (this->ctx_->attribute ())
    {
      // now check if we are a "get" or "set" operation
      if (node->nmembers () == 1) // set
        *os << "_set_";
      else
        *os << "_get_";
    }
  *os << node->local_name ()
      << "_skel (" << be_idt << be_idt_nl
      << "CORBA::ServerRequest &_tao_server_request," << be_nl
      << "void *_tao_object_reference, " << be_nl
      << "void * /* context */, " << be_nl
      << "CORBA::Environment &ACE_TRY_ENV" << be_uidt << be_uidt_nl
      << ")" << be_nl;

  // generate the actual code for the skeleton. However, if any of the argument
  // types is "native", we do not generate any skeleton
  // last argument - is always CORBA::Environment
  *os << "{\n" << be_idt;

  // generate all the tables and other pre-skel info
  if (this->gen_pre_skel_info (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_ss::"
                         "visit_operation - "
                         "gen_pre_skel_info failed\n"),
                        -1);
    }

  os->indent ();
  // get the right object implementation.
  *os << intf->full_skel_name () << " *_tao_impl = ("
      << intf->full_skel_name () << " *)_tao_object_reference;\n\n";

  // declare a return type variable
  be_visitor_context ctx = *this->ctx_;
  ctx.state (TAO_CodeGen::TAO_OPERATION_RETVAL_DECL_SS);
  be_visitor *visitor = tao_cg->make_visitor (&ctx);
  if (!visitor || (bt->accept (visitor) == -1))
    {
      delete visitor;
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_ss::"
                         "visit_operation - "
                         "codegen for return var decl failed\n"),
                        -1);
    }

  // declare variables for arguments
  ctx = *this->ctx_;
  ctx.state (TAO_CodeGen::TAO_OPERATION_ARG_DECL_SS);
  visitor = tao_cg->make_visitor (&ctx);
  if (!visitor || (node->accept (visitor) == -1))
    {
      delete visitor;
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_ss::"
                         "visit_operation - "
                         "codegen for return var decl failed\n"),
                        -1);
    }

  // Demarshal parameters
  if (this->gen_demarshal_params (node, bt) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_ss::"
                         "visit_operation - "
                         "gen_demarshal_params failed\n"),
                        -1);
    }

  // Fish out the interceptor and do preinvoke
  *os << "#if (TAO_HAS_INTERCEPTORS == 1)" << be_nl
      << "TAO_ServerRequestInterceptor_Adapter" << be_idt_nl
      << "_tao_vfr (_tao_server_request.orb ()->_get_server_interceptor (ACE_TRY_ENV));" << be_uidt_nl
      << "ACE_CHECK;" << be_nl
 << "CORBA::Object_var _tao_objref;" << be_nl;

  // Obtain the scope.

  os->indent ();
  if (node->is_nested ())
    {
      be_decl *parent =
        be_scope::narrow_from_scope (node->defined_in ())->decl ();
      // But since we are at the interface level our parents full_name
      // will include the interface name which we dont want and so we 
      // get our parent's parent's full name.
      //    be_interface *parent_interface = be_interface::narrow_from_decl (parent);
      // be_decl *parents_parent = be_interface::narrow_from_scope (parent_interface->scope ())->decl ();
      // Generate the scope::operation name.
      //  *os << parents_parent->full_name () << "::";
      *os << "POA_" <<parent->full_name () << "::";
    }

  *os << "TAO_ServerRequest_Info_"<< node->flat_name (); 
  // We need the interface node in which this operation was defined. However,
  // if this operation node was an attribute node in disguise, we get this
  // information from the context and add a "_get"/"_set" to the flat
  // name to get around the problem of overloaded methods which are
  // generated for attributes.
  if (this->ctx_->attribute ())
    {
      bt = be_type::narrow_from_decl (node->return_type ());
      if (!bt)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_interceptors_ch::"
                             "visit_operation - "
                             "Bad return type\n"),
                            -1);
        }
      
      // grab the right visitor to generate the return type if its not
      // void it means it is not the accessor.
      if (!this->void_return_type (bt))
        *os <<"_get";
      else
        *os <<"_set";
    }

  *os<< "  ri (" << this->compute_operation_name (node) << ",\n"
      << "_tao_server_request.service_info ()";
  
  // This necesary becos: (a) a comma is needed if there are arguments
  // (b) not needed if exceptions enabled since thats done already (c)
  // not needed if there are no args and exceptions is disabled.
  
  //  os->indent ();
  // if (node->argument_count () > 0)
  // *os << ",\n";

  // Generate the formal argument fields which are passed to the RequestInfo object
  ctx = *this->ctx_;
  ctx.state (TAO_CodeGen::TAO_OPERATION_INTERCEPTORS_INFO_ARGLIST_SS);
  visitor = tao_cg->make_visitor (&ctx);

  if ((!visitor) || (node->accept (visitor) == -1))
    {
      delete visitor;
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_cs::"
                         "visit_operation - "
                         "codegen for arglist failed\n"),
                        -1);
    }
  delete visitor;
  *os << ");\n";

  *os << "if (_tao_vfr.valid ())" << be_idt_nl
      << "{" << be_idt_nl
      << "_tao_objref = "
      << "_tao_server_request.objref (ACE_TRY_ENV);" << be_nl
      << "ACE_CHECK;" << be_uidt_nl << "}\n" << be_uidt_nl
      << "ACE_TRY" << be_idt_nl
      << "{" << be_idt_nl;
  // Update the request id field of the Request Info
  *os << "ri.request_id (_tao_server_request.request_id ());" << be_nl
      << "_tao_vfr.receive_request (&ri, ACE_TRY_ENV);"
      << be_uidt_nl
      << "TAO_INTERCEPTOR_CHECK;\n";
  if (node->flags () == AST_Operation::OP_oneway
      && !this->has_param_type (node, AST_Argument::dir_IN))
    {
      *os << "#else" << be_nl
          << "ACE_UNUSED_ARG (_tao_server_request);\n";
    }

  *os << "#endif /* TAO_HAS_INTERCEPTORS */\n\n";

  // make the upcall and assign to the return val
  ctx = *this->ctx_;
  ctx.state (TAO_CodeGen::TAO_OPERATION_RETVAL_ASSIGN_SS);
  visitor = tao_cg->make_visitor (&ctx);
  if (!visitor || (bt->accept (visitor) == -1))
    {
      delete visitor;
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_ss::"
                         "visit_operation - "
                         "codegen for retval assignment failed\n"),
                        -1);
    }

  // make the upcall
  *os << "_tao_impl->" << node->local_name () << " (" << be_idt << "\n";
  ctx = *this->ctx_;
  ctx.state (TAO_CodeGen::TAO_OPERATION_ARG_UPCALL_SS);
  visitor = tao_cg->make_visitor (&ctx);
  if (!visitor || (node->accept (visitor) == -1))
    {
      delete visitor;
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_ss::"
                         "visit_operation - "
                         "codegen for making upcall failed\n"),
                        -1);
    }

  // end the upcall
  *os << be_uidt_nl << ");\n" << be_nl;
  // Update the result.
  bt = be_type::narrow_from_decl (node->return_type ());
  if (!bt)
    {
          ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_interceptors_ch::"
                             "visit_operation - "
                             "Bad return type\n"),
                            -1);
    }
  // grab the right visitor to generate the return type accessor if
  // its not void since we cant have a private member to be of void
  // type.
  if (!this->void_return_type (bt))
    {
      // Heres what we are going to do to have a uniform way of getting the
      // return value updated for the Request Info:
      // declare a operation_retval type object and assign the
      // _tao_safe_retval._retn () to it.
      // We pass this to the result updation method (note: it hasnt
      // got destroyed)
      // We then put it back into the original _tao_safe_retval
      // object.
      // And finally the _retn () is returned from the operation w.o
      // causing any problems.
      // Generate the return type mapping (same as in the header file)
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_RETTYPE_OTHERS);
      visitor = tao_cg->make_visitor (&ctx);
      
      if ((!visitor) || (bt->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_operation_cs::"
                             "visit_operation - "
                             "codegen for return type failed\n"),
                            -1);
        }
      delete visitor;
      *os << "  _tao_retval_info = ";
      if (bt->size_type () == be_decl::VARIABLE
          || bt->base_node_type () == AST_Decl::NT_array)
        {
                    *os << "_tao_retval._retn ();";
                    *os << be_nl <<"#if (TAO_HAS_INTERCEPTORS == 1)" << be_nl;
                    *os << be_nl << " ri.result (_tao_retval_info);"
                        << be_nl << "_tao_retval = _tao_retval_info;" <<be_nl
                        << "#endif /* TAO_HAS_INTERCEPTORS */\n\n";
        }
      else
        {
          *os << "_tao_retval;";
          *os << be_nl <<"#if (TAO_HAS_INTERCEPTORS == 1)" << be_nl;
          *os << be_nl << " ri.result (_tao_retval_info);" << be_nl
              << "#endif /* TAO_HAS_INTERCEPTORS */\n\n";
        }
/*
      *os << "// Update the result" << be_nl
          << "ri.result (";
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_RETVAL_SS);
      // just so that primitive types are taken care of.
      ctx.sub_state (TAO_CodeGen::TAO_CDR_OUTPUT); 
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (bt->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_operation_ss::"
                             "visit_operation - "
                             "codegen for retval assignment failed\n"),
                        -1);
        }
        *os << ");"<< be_nl;*/
    }
  *os << "TAO_INTERCEPTOR_CHECK;\n\n";

  // do postinvoke, and check for exception.
  *os << be_nl <<"#if (TAO_HAS_INTERCEPTORS == 1)" << be_nl;
  *os << be_uidt_nl
      << " _tao_vfr.send_reply (&ri, ACE_TRY_ENV);"<<be_nl
      << "TAO_INTERCEPTOR_CHECK;" << be_uidt_nl
      << "}" << be_uidt_nl
      << "ACE_CATCHANY" << be_idt_nl
      << "{" << be_idt_nl;
  // Update the exception field of teh request info.
  *os << "ri.exception (&ACE_ANY_EXCEPTION);"<< be_nl;
  *os << "_tao_vfr.send_exception (&ri," << be_idt << be_idt_nl
      << "ACE_TRY_ENV" << be_uidt_nl
      << ");" << be_uidt_nl;

  if (idl_global->use_raw_throw ())
    *os << "throw;" << be_uidt_nl;
  else
    *os << "ACE_RE_THROW;" << be_uidt_nl;

  *os << "}" << be_uidt_nl
      << "ACE_ENDTRY;" << be_nl;
  *os << "ACE_CHECK;\n"
      << "#endif /* TAO_HAS_INTERCEPTORS */\n\n";

  // check if we are oneway in which case, we are done
  if (node->flags () == AST_Operation::OP_oneway)
    {
      // we are done. Nothing else to do, except closing the function body.
      os->indent ();
      *os << "if (_tao_server_request.response_expected ()" << be_idt << be_idt_nl
          << "&& !_tao_server_request.sync_with_server ())" << be_uidt_nl
          << "{" << be_idt_nl
          << "_tao_server_request.init_reply (ACE_TRY_ENV);" << be_nl
          << "ACE_CHECK;" << be_uidt_nl
          << "}" << be_uidt << be_uidt_nl
          << "}\n\n";
      return 0;
    }

  // marshal outgoing parameters
  if (this->gen_marshal_params (node, bt) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_ss::"
                         "visit_operation - "
                         "gen_marshal_params failed\n"),
                        -1);
    }

  os->decr_indent ();
  *os << "}\n\n";
  return 0;
}

int
be_visitor_operation_ss::visit_argument (be_argument *node)
{
  // this method is used to generate the ParamData table entry

  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt; // argument type

  // retrieve the type for this argument
  bt = be_type::narrow_from_decl (node->field_type ());
  if (!bt)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_ss::"
                         "visit_argument - "
                         "Bad argument type\n"),
                        -1);
    }

  os->indent ();
  *os << "{" << bt->tc_name () << ", ";
  switch (node->direction ())
    {
    case AST_Argument::dir_IN:
      *os << "CORBA::ARG_IN, ";
      break;
    case AST_Argument::dir_INOUT:
      *os << "CORBA::ARG_INOUT, ";
      break;
    case AST_Argument::dir_OUT:
      *os << "CORBA::ARG_OUT, ";
      break;
    }
  *os << "0}";

  return 0;
}

int
be_visitor_operation_ss::gen_pre_skel_info (be_operation *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // now make sure that we have some in and inout parameters. Otherwise, there
  // is nothing to be marshaled in
  if (this->has_param_type (node, AST_Argument::dir_IN) ||
      this->has_param_type (node, AST_Argument::dir_INOUT))
    {
      // instantiate a TAO_InputCDR variable
      os->indent ();
      *os << "TAO_InputCDR &_tao_in = _tao_server_request.incoming ();\n";
    }

  return 0;
}

int
be_visitor_operation_ss::gen_demarshal_params (be_operation *node,
                                               be_type *bt)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_visitor *visitor;
  be_visitor_context ctx;

  // now make sure that we have some in and inout parameters. Otherwise, there
  // is nothing to be marshaled in
  if (this->has_param_type (node, AST_Argument::dir_IN) ||
      this->has_param_type (node, AST_Argument::dir_INOUT))
    {
      os->indent ();

      // demarshal the in and inout arguments
      *os << "if (!(\n" << be_idt;

      // marshal each in and inout argument
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_ARG_DEMARSHAL_SS);
      ctx.sub_state (TAO_CodeGen::TAO_CDR_INPUT);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (node->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_compiled_visitor_operation_ss::"
                             "gen_demarshal_params - "
                             "codegen for demarshal failed\n"),
                            -1);
        }
      *os << be_uidt_nl << "))\n" << be_idt;

      // if marshaling fails, raise exception
      if (this->gen_raise_exception (bt, "CORBA::MARSHAL",
                                     "",
                                     "ACE_TRY_ENV") == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_compiled_visitor_operation_ss::"
                             "gen_marshal_and invoke - "
                             "codegen for return var failed\n"),
                            -1);
        }
      *os << be_uidt << "\n";

    };

  return 0;
}

int
be_visitor_operation_ss::gen_marshal_params (be_operation *node,
                                             be_type *bt)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_visitor *visitor;
  be_visitor_context ctx;

  // setup parameters for marshaling and marshal them into the
  // outgoing stream
  // the code below this is for 2way operations only

  // We will be here only if we are 2way
  // first initialize a reply message
  os->indent ();
  *os << "_tao_server_request.init_reply (ACE_TRY_ENV);" << be_nl
      << "ACE_CHECK;" << be_nl;

  // We still need the following check because we maybe 2way and yet have no
  // parameters and a void return type
  if (this->void_return_type (bt) &&
      !this->has_param_type (node, AST_Argument::dir_INOUT) &&
      !this->has_param_type (node, AST_Argument::dir_OUT))
    {
      return 0;
    }

  // Create temporary variables for the out and return parameters..
  if (!this->void_return_type (bt))
    {
      ctx = *this->ctx_;
      be_visitor_context *new_ctx =
        new be_visitor_context (ctx);
      be_visitor_operation_rettype_post_upcall_ss visitor (new_ctx);
      if (bt->accept (&visitor) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_compiled_visitor_operation_ss::"
                             "gen_marshal_params - "
                             "codegen for return var [post upcall] failed\n"),
                            -1);
        }
    }

  // Generate any temporary variables to demarshal the arguments
  ctx = *this->ctx_;
  be_visitor_args_post_upcall_ss vis1 (new be_visitor_context (ctx));
  if (node->accept (&vis1) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_compiled_visitor_operation_cs::"
                         "gen_pre_stub_info - "
                         "codegen for pre args failed\n"),
                        -1);
    }

  *os << "TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();" << be_nl;
  *os << "if (!(\n" << be_idt;

  if (!this->void_return_type (bt))
    {
      // demarshal the return val and each inout and out argument
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_RETVAL_MARSHAL_SS);
      ctx.sub_state (TAO_CodeGen::TAO_CDR_OUTPUT);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (node->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_compiled_visitor_operation_ss::"
                             "gen_marshal_params - "
                             "codegen for return var failed\n"),
                            -1);
        }
    }

  if (this->has_param_type (node, AST_Argument::dir_INOUT) ||
      this->has_param_type (node, AST_Argument::dir_OUT))
    {

      if (!this->void_return_type (bt))
        // we have already printed the return val. SO put a &&
        *os << " &&\n";

      // marshal each in and inout argument
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_ARG_MARSHAL_SS);
      ctx.sub_state (TAO_CodeGen::TAO_CDR_OUTPUT);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (node->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_compiled_visitor_operation_ss::"
                             "gen_marshal_params - "
                             "codegen for args failed\n"),
                            -1);
        }
    }

  *os << be_uidt_nl << "))\n" << be_idt;
  // if marshaling fails, raise exception
  if (this->gen_raise_exception (bt, "CORBA::MARSHAL",
                                 "",
                                 "ACE_TRY_ENV") == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_compiled_visitor_operation_ss::"
                         "gen_marshal_params - "
                         "codegen for raising exception failed\n"),
                        -1);
    }
  *os << be_uidt << be_uidt << "\n";

  return 0;
}

int
be_visitor_operation_ss::gen_raise_exception (be_type *,
                                              const char *excep,
                                              const char *completion_status,
                                              const char * /* env */)
{
  TAO_OutStream *os = this->ctx_->stream ();

  os->indent ();

  if (idl_global->use_raw_throw ())
    *os << "throw ";
  else
    *os << "ACE_THROW (";

  *os << excep << "(" << completion_status << ")";

  if (idl_global->use_raw_throw ())
    *os << ";\n";
  else
    *os << ");\n";

  return 0;
}

int
be_visitor_operation_ss::gen_check_exception (be_type *,
                                              const char * /* env */)
{
  TAO_OutStream *os = this->ctx_->stream ();

  os->indent ();
  // check if there is an exception
  *os << "ACE_CHECK;\n";

  return 0;
}

int
be_visitor_operation_ss::gen_check_interceptor_exception (be_type *, const char * /* env */)
{
  TAO_OutStream *os = this->ctx_->stream ();

  os->indent ();
  // check if there is an exception
  *os << "TAO_INTERCEPTOR_CHECK;\n";

  return 0;
}

const char *
be_visitor_operation_ss::compute_operation_name (be_operation *node)
{
  if (this->operation_name_ == 0)
    {
      size_t len = 3;           // the null termination char.
      if (this->ctx_->attribute ())
        len += 5;               // "Added length for "_set_" or "_get_".

      len += ACE_OS::strlen (node->local_name ()->get_string ());

      ACE_NEW_RETURN (this->operation_name_,
                      char [len],
                      0);

      ACE_OS::strcpy (this->operation_name_, "\"");
      if (this->ctx_->attribute ())
        {
          if (node->nmembers () == 1)
            ACE_OS::strcat (this->operation_name_, "_set_");
          else
            ACE_OS::strcat (this->operation_name_, "_get_");
        }
      ACE_OS::strcat (this->operation_name_,
                      node->local_name ()->get_string ());
      ACE_OS::strcat (this->operation_name_, "\"");
    }
  return this->operation_name_;
}
