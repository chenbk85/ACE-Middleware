/* -*- c++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO_IFR_BE_DLL
//
// = FILENAME
//    be_global.h
//
// = DESCRIPTION
//    Header file for class containing compiler back end global data.
//
// = AUTHOR
//    Jeff Parsons <parsons@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_IFR_BE_GLOBAL_H
#define TAO_IFR_BE_GLOBAL_H

#include "TAO_IDL3_TO_IDL2_BE_Export.h"
#include "idl_defines.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "idl_bool.h"

class AST_Generator;

// Defines a class containing all back end global data.

class TAO_IDL3_TO_IDL2_BE_Export BE_GlobalData
{
public:
  // = TITLE
  //    BE_GlobalData
  //
  // = DESCRIPTION
  //    Storage of global data specific to the compiler back end
  //
  BE_GlobalData (void);
  // Constructor.

  virtual ~BE_GlobalData (void);
  // Destructor.

  // Data accessors.

  const char *filename (void) const;
  void filename (char *fname);

  const char* output_dir (void) const;
  void output_dir (const char* s);
  
  void parse_args (long &i, char **av);
  // Parse args that affect the backend.
  
  void prep_be_arg (char *s);
  // Special BE arg call factored out of DRV_args.
  
  void arg_post_proc (void);
  // Checks made after parsing args.
  
  void usage (void) const;
  // Usage message for backend options.
  
  AST_Generator *generator_init (void);
  // Create an AST node generator.
  
  void destroy (void);
  // Cleanup.
  
private:
  char *filename_;
  // Name of the IDL file we are processing.

  char *output_dir_;
  // Directory where the generated file is to be
  // kept. Default value is 0 for this string which means the current
  // directory from which the <tao_picml> is called.
};

#endif /* TAO_IFR_BE_GLOBAL_H */
