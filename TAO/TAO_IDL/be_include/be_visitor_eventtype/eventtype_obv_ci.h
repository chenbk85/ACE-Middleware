//
// $Id$
//
/* -*- c++ -*- */
// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    eventtype_obv_ci.h
//
// = DESCRIPTION
//    Concrete visitor for the Eventtype node.
//    This one provides code generation for valuetype OBV_ class
//    in the (client) inline.
//
// = AUTHOR
//    Jeff Parsons
//
// ============================================================================

#ifndef _BE_EVENTTYPE_EVENTTYPE_OBV_CI_H_
#define _BE_EVENTTYPE_EVENTTYPE_OBV_CI_H_

class be_visitor_eventtype_obv_ci : public be_visitor_valuetype
{
  //
  // = TITLE
  //   be_visitor_eventtype_obv_ci
  //
  // = DESCRIPTION
  //   This is a concrete visitor to generate the inline for valuetype
  //   OBV_ class
  //
public:
  be_visitor_eventtype_obv_ci (be_visitor_context *ctx);
  // constructor

  ~be_visitor_eventtype_obv_ci (void);
  // destructor

  virtual int visit_eventtype (be_eventtype *node);
};

#endif /* _BE_EVENTTYPE_EVENTTYPE_OBV_CI_H_ */
