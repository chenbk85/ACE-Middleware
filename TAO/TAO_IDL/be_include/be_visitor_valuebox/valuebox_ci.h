/* -*- c++ -*- */
//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    valuebox_ci.h
//
// = DESCRIPTION
//    Concrete visitor for the Valuebox node.
//    This provides code generation for valueboxes in the client inline.
//
// = AUTHOR
//    Gary Maxey
//
// ============================================================================

#ifndef _BE_VISITOR_VALUEBOX_CI_H_
#define _BE_VISITOR_VALUEBOX_CI_H_

class be_visitor_valuebox_ci : public be_visitor_valuebox
{
  //
  // = TITLE
  //   be_visitor_valuebox_ci
  //
  // = DESCRIPTION
  //   This is a concrete visitor to generate the client inline for valuebox
  //
  //
public:
  be_visitor_valuebox_ci (be_visitor_context *ctx);
  // constructor

  ~be_visitor_valuebox_ci (void);
  // destructor

  virtual int visit_valuebox (be_valuebox *node);
  // visit valuebox.

  virtual int visit_array (be_array *node);
  // visit array.

  virtual int visit_enum (be_enum *node);
  // visit enum.

  virtual int visit_interface (be_interface *node);
  // visit interface.

  virtual int visit_predefined_type (be_predefined_type *node);
  // visit predefined type.

  virtual int visit_sequence (be_sequence *node);
  // visit sequence.

  virtual int visit_string (be_string *node);
  // visit string.

  virtual int visit_structure (be_structure *node);
  // visit structure.

  virtual int visit_typedef (be_typedef *node);
  // visit typedef.

  virtual int visit_union (be_union *node);
  // visit union.

private:
  int emit_for_predef_enum(be_type *node,
                           const char * type_suffix,
                           bool is_any,
                           const char * marshal_arg);

  void emit_default_constructor (void);

  void emit_default_constructor_alloc (be_decl *node);

  void emit_destructor (void);

  void emit_constructor_one_arg (be_decl *node,
                                const char * type_suffix);

  void emit_constructor_one_arg_alloc (be_decl *node);

  void emit_copy_constructor (void);

  void emit_copy_constructor_alloc (be_decl *node);

  void emit_assignment( be_decl *node,
                       const char * type_suffix);

  void emit_assignment_alloc (be_decl *node);

  void emit_accessor_modifier (be_decl *node);

  void emit_boxed_access (be_decl *node, const char *out_ref_modifier);

};

#endif /* _BE_VISITOR_VALUEBOX_CI_H_ */
