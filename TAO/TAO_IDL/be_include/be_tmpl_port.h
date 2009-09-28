//
// $Id$
//

/* -*- c++ -*- */
// ============================================================================
//
// = LIBRARY
//    TAO_IDL_BE
//
// = FILENAME
//    be_tmpl_port.h
//
// = DESCRIPTION
//    Extension of class AST_Tmpl_Port for C++ code generation.
//
// = AUTHOR
//    Jeff Parsons
//
// ============================================================================

#ifndef BE_TMPL_PORT_H
#define BE_TMPL_PORT_H

#include "ast_tmpl_port.h"

#include "be_field.h"

class be_visitor;

class be_tmpl_port : public virtual AST_Tmpl_Port,
                     public virtual be_field
{
  //
  // = TITLE
  //   be_tmpl_port
  //
  // = DESCRIPTION
  //   Extension of class AST_Tmpl_Port for C++ code generation.
  //
public:
  be_tmpl_port (
    UTL_ScopedName *n,
    AST_PortType *porttype_ref);
    
  virtual ~be_tmpl_port (void);
  
  virtual void destroy (void);
  
  virtual int accept (be_visitor *visitor);

  DEF_NARROW_FROM_DECL (be_tmpl_port);
};

#endif // BE_TMPL_PORT_H
