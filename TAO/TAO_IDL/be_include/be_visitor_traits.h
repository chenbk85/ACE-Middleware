//=============================================================================
/**
*  @file   be_visitor_traits.h
*
*  $Id$
*
*  This visitor generates template specializations for traits of various
*  kinds for IDL declarations. These specialized template classes are then
*  used in other template classes in the ORB.
*
*  @author Jeff Parsons <j.parsons@vanderbilt.edu>
*/
//=============================================================================
#ifndef TAO_BE_VISITOR_TRAITS_H
#define TAO_BE_VISITOR_TRAITS_H

#include "be_visitor_scope.h"

/**
 * @class be_visitor_traits
 *
 * @brief Generates specialized template traits declarations.
 */
class be_visitor_traits : public be_visitor_scope
{
public:
  be_visitor_traits (be_visitor_context *ctx);

  virtual ~be_visitor_traits (void);

  virtual int visit_root (be_root *node);

  virtual int visit_module (be_module *node);

  virtual int visit_interface (be_interface *node);

  virtual int visit_interface_fwd (be_interface_fwd *node);

  virtual int visit_valuetype (be_valuetype *node);

  virtual int visit_valuetype_fwd (be_valuetype_fwd *node);

  virtual int visit_eventtype (be_eventtype *node);

  virtual int visit_eventtype_fwd (be_eventtype_fwd *node);

  virtual int visit_typedef (be_typedef *node);
};


#endif // TAO_BE_VISITOR_TRAITS_H
