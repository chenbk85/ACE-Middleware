// -*- C++ -*-
//
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    upcall_command_ss.cpp
//
// = DESCRIPTION
//    Visitor that generates operation-specific TAO::Upcall_Command
//    objects in skeletons.
//
// = AUTHOR
//    Ossama Othman
//
// ============================================================================

#ifndef _BE_VISITOR_OPERATION_UPCALL_COMMAND_SS_H_
#define _BE_VISITOR_OPERATION_UPCALL_COMMAND_SS_H_

class be_visitor_operation_upcall_command_ss
  : public be_visitor_operation
{
public:

  /// constructor
  be_visitor_operation_upcall_command_ss (be_visitor_context * ctx);

  /// destructor
  ~be_visitor_operation_upcall_command_ss (void);

  /// visit the operation
  virtual int visit_operation (be_operation * node);

  /// Same as visit_operation() but override full_skel_name.
  int visit (be_operation * node, char const * full_skel_name);

private:

  /// Generate the upcall.
  int gen_upcall (be_operation * node);

};

#endif /* _BE_VISITOR_OPERATION_UPCALL_COMMAND_SS_H_ */
