// -*- C++ -*-

//=============================================================================
/**
 *  @file  value_typecode.h
 *
 *  $Id$
 *
 *  Structure TypeCode generation visitor.
 *
 *  @author  Ossama Othman <ossama@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef TAO_BE_VISITOR_VALUE_TYPECODE_H
#define TAO_BE_VISITOR_VALUE_TYPECODE_H

#include "ace/pre.h"

namespace TAO
{

  /**
   * @class be_visitor_value_typecode
   *
   * @brief valuetype TypeCode generation visitor.
   *
   * Structure TypeCode generation visitor.
   */
  class be_visitor_value_typecode
    : public be_visitor_typecode_defn
  {
  public:

    /// Constructor.
    be_visitor_value_typecode (be_visitor_context * ctx);

    /// Visit a structure.
    /**
     * @todo The legacy method name "@c visit_valuetype()" is
     *       redundant since it is obvious from the argument what kind
     *       of TypeCode is being visited.  It will be changed once
     *       the rest of the legacy method names and their call sites
     *       are updated accordingly.
     */
    virtual int visit_valuetype (be_valuetype * node);

  private:

    /// Generate structure field related TypeCode code.
    int visit_members (be_valuetype * node);

  };

}

#include "ace/post.h"

#endif  /* TAO_BE_VISITOR_VALUE_TYPECODE_H */
