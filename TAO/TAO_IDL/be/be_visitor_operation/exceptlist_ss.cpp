// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    exceptlist_ss.cpp
//
// = DESCRIPTION
//    Visitor generating code for the list of exceptions that an operation
//    raises (skeleton/server side).
//
// = AUTHOR
//    Ossama Othman
//
// ============================================================================

ACE_RCSID (be_visitor_operation,
           exceptlist_ss,
           "$Id$")

// ****************************************************************************
// visitor to generate the exception list for operations (skeleton/server_side)
// ****************************************************************************

be_visitor_operation_exceptlist_ss::be_visitor_operation_exceptlist_ss (
    be_visitor_context *ctx
  )
  : be_visitor_decl (ctx)
{
}

be_visitor_operation_exceptlist_ss::~be_visitor_operation_exceptlist_ss (void)
{
}

int
be_visitor_operation_exceptlist_ss::visit_operation (be_operation * node)
{
  TAO_OutStream * const os = this->ctx_->stream ();

  *os << be_nl
      << "\n#if TAO_HAS_INTERCEPTORS == 1" << be_nl;

  // Don't do anything if the exception list is empty.
  if (node->exceptions ())
    {
      *os << "static ::CORBA::TypeCode_ptr const exceptions[] = " << be_idt_nl;
      *os << "{" << be_idt_nl;

      // Initialize an iterator to iterate thru the exception list.
      // Continue until each element is visited.
      // Iterator must be advanced explicitly inside the loop.
      for (UTL_ExceptlistActiveIterator ei (node->exceptions ());
           !ei.is_done ();)
        {
          be_exception * ex = be_exception::narrow_from_decl (ei.item ());

          *os << ex->tc_name ();

          ei.next ();

          if (!ei.is_done ())
            {
              *os << "," << be_nl;
            }
        }

      *os << be_uidt_nl << "};" << be_uidt_nl
          << "static ::CORBA::ULong const nexceptions = "
          << node->exceptions()->length () << ";";
    }
  else
    {
      *os << "static ::CORBA::TypeCode_ptr const * const exceptions = 0;"
          << be_nl
          << "static ::CORBA::ULong const nexceptions = 0;";
    }

  *os << "\n#endif /* TAO_HAS_INTERCEPTORS */" << be_nl << be_nl;

  return 0;
}
