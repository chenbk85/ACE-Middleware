// $Id$

/*

COPYRIGHT

Copyright 1992, 1993, 1994 Sun Microsystems, Inc.  Printed in the United
States of America.  All Rights Reserved.

This product is protected by copyright and distributed under the following
license restricting its use.

The Interface Definition Language Compiler Front End (CFE) is made
available for your use provided that you include this license and copyright
notice on all media and documentation and the software program in which
this product is incorporated in whole or part. You may copy and extend
functionality (but may not remove functionality) of the Interface
Definition Language CFE without charge, but you are not authorized to
license or distribute it to anyone else except as part of a product or
program developed by you or with the express written consent of Sun
Microsystems, Inc. ("Sun").

The names of Sun Microsystems, Inc. and any of its subsidiaries or
affiliates may not be used in advertising or publicity pertaining to
distribution of Interface Definition Language CFE as permitted herein.

This license is effective until terminated by Sun for failure to comply
with this license.  Upon termination, you shall destroy or return all code
and documentation for the Interface Definition Language CFE.

INTERFACE DEFINITION LANGUAGE CFE IS PROVIDED AS IS WITH NO WARRANTIES OF
ANY KIND INCLUDING THE WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS
FOR A PARTICULAR PURPOSE, NONINFRINGEMENT, OR ARISING FROM A COURSE OF
DEALING, USAGE OR TRADE PRACTICE.

INTERFACE DEFINITION LANGUAGE CFE IS PROVIDED WITH NO SUPPORT AND WITHOUT
ANY OBLIGATION ON THE PART OF Sun OR ANY OF ITS SUBSIDIARIES OR AFFILIATES
TO ASSIST IN ITS USE, CORRECTION, MODIFICATION OR ENHANCEMENT.

SUN OR ANY OF ITS SUBSIDIARIES OR AFFILIATES SHALL HAVE NO LIABILITY WITH
RESPECT TO THE INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY
INTERFACE DEFINITION LANGUAGE CFE OR ANY PART THEREOF.

IN NO EVENT WILL SUN OR ANY OF ITS SUBSIDIARIES OR AFFILIATES BE LIABLE FOR
ANY LOST REVENUE OR PROFITS OR OTHER SPECIAL, INDIRECT AND CONSEQUENTIAL
DAMAGES, EVEN IF SUN HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

Use, duplication, or disclosure by the government is subject to
restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
Technical Data and Computer Software clause at DFARS 252.227-7013 and FAR
52.227-19.

Sun, Sun Microsystems and the Sun logo are trademarks or registered
trademarks of Sun Microsystems, Inc.

SunSoft, Inc.
2550 Garcia Avenue
Mountain View, California  94043

NOTE:

SunOS, SunSoft, Sun, Solaris, Sun Microsystems or the Sun logo are
trademarks or registered trademarks of Sun Microsystems, Inc.

*/

#include "idl_global.h"
#include "global_extern.h"
#include "ast_root.h"
#include "ast_generator.h"
#include "ast_structure.h"
#include "ast_sequence.h"
#include "ast_valuetype.h"
#include "utl_identifier.h"
#include "utl_indenter.h"
#include "utl_err.h"
#include "utl_string.h"
#include "nr_extern.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_unistd.h"
#include "ace/Process.h"

ACE_RCSID (util,
           utl_global,
           "$Id$")

// Define an increment for the size of the array used to store names of
// included files.
#undef INCREMENT
#define INCREMENT 64

static long seen_once[INCREMENT] = {0};

IDL_GlobalData::dsf::dsf (void)
  : interface_seen_ (0),
    valuetype_seen_ (0),
    abstract_iface_seen_ (0),
    local_iface_seen_ (0),
    non_local_iface_seen_ (0),
    fwd_iface_seen_ (0),
    fwd_valuetype_seen_ (0),
    basic_type_seen_ (0),
    ambiguous_type_seen_ (0),
    enum_seen_ (0),
    string_seen_ (0),
    array_seen_ (0),
    aggregate_seen_ (0),
    union_seen_ (0),
    exception_seen_ (0),
    operation_seen_ (0),
    non_local_op_seen_ (0),
    typecode_seen_ (0),
    any_seen_ (0),
    parametermode_seen_ (0),
    base_object_seen_ (0),
    valuefactory_seen_ (0),
    valuebase_seen_ (0),

    seq_seen_ (0),
    iface_seq_seen_ (0),
    vt_seq_seen_ (0),
    array_seq_seen_ (0),
    pseudo_seq_seen_ (0),
    string_seq_seen_ (0),
    wstring_seq_seen_ (0),
    octet_seq_seen_ (0),
    boolean_seq_seen_ (0),
    char_seq_seen_ (0),
    wchar_seq_seen_ (0),
    short_seq_seen_ (0),
    ushort_seq_seen_ (0),
    long_seq_seen_ (0),
    ulong_seq_seen_ (0),
    longlong_seq_seen_ (0),
    ulonglong_seq_seen_ (0),
    float_seq_seen_ (0),
    double_seq_seen_ (0),
    longdouble_seq_seen_ (0),
    any_seq_seen_ (0),

    basic_arg_seen_ (0),
    bd_string_arg_seen_ (0),
    fixed_array_arg_seen_ (0),
    fixed_size_arg_seen_ (0),
    object_arg_seen_ (0),
    special_basic_arg_seen_ (0),
    ub_string_arg_seen_ (0),
    var_array_arg_seen_ (0),
    var_size_arg_seen_ (0)
{}

IDL_GlobalData::IDL_GlobalData (void)
  : decls_seen_info_ (0),
    pd_root (0),
    pd_gen (0),
    pd_err (0),
    pd_err_count (0),
    pd_lineno (0),
    pd_filename (0),
    pd_main_filename (0),
    pd_real_filename (0),
    pd_stripped_filename (0),
    pd_import (I_FALSE),
    pd_in_main_file (I_FALSE),
    pd_prog_name (0),
    pd_cpp_location (0),
    pd_compile_flags (0),
    pd_local_escapes (0),
    pd_indent (0),
    pd_include_file_names (0),
    pd_n_include_file_names (0),
    pd_n_alloced_file_names (0),
    included_idl_files_ (0),
    n_included_idl_files_ (0),
    n_allocated_idl_files_ (0),
    pd_parse_state (PS_NoState),
    pd_idl_src_file (0),
    tao_root_ (0),
    gperf_path_ (0),
    temp_dir_ (0),
    ident_string_ (0),
    case_diff_error_ (I_TRUE),
    nest_orb_ (I_FALSE),
    idl_flags_ (""),
    preserve_cpp_keywords_ (I_TRUE),
    pass_orb_idl_ (I_FALSE)
{
  // Path for the perfect hash generator(gperf) program.
  // Default is $ACE_ROOT/bin/gperf unless ACE_GPERF is defined.
  // Use ACE_GPERF if $ACE_ROOT hasn't been set or won't be set
  // in the environment.
  // Form the absolute pathname.
  char* ace_root = ACE_OS::getenv ("ACE_ROOT");
  
  if (ace_root == 0)
    // This may not cause any problem if -g option is used to specify
    // the correct path for the  gperf program. Let us ignore this
    // error here. It will be caught when we check the existence of
    // the perfect hasher and at that time, we can switch over to some
    // other scheme.
    {
#if defined (ACE_GPERF)
      // The actual gperf program must be included in the definition of
      // ACE_GPERF, not just the directory in which it is located.
      const char ace_gperf[] = ACE_GPERF;
      ACE_NEW (this->gperf_path_,
               char [ACE_OS::strlen (ace_gperf) + 1]);
      ACE_OS::sprintf (this->gperf_path_,
                       "%s",
                       ace_gperf);
#else
      this->gperf_path_ = 0;
#endif
    }
  else
    {
#if defined (ACE_GPERF)
      const char ace_gperf[] = ACE_GPERF;
      ACE_NEW (this->gperf_path_,
               char [ACE_OS::strlen (ace_root)
                     + ACE_OS::strlen ("/bin/")
                     + ACE_OS::strlen (ace_gperf)
                     + 1]);
      ACE_OS::sprintf (this->gperf_path_,
                       "%s" ACE_DIRECTORY_SEPARATOR_STR "bin" ACE_DIRECTORY_SEPARATOR_STR "%s",
                       ace_root,
                       ace_gperf);
#else /* Not ACE_GPERF */
      // Set it to the default value.
      ACE_NEW (this->gperf_path_,
               char [ACE_OS::strlen (ace_root)
                     + ACE_OS::strlen ("/bin/gperf")
                     + 1]);
      ACE_OS::sprintf (this->gperf_path_,
                       "%s" ACE_DIRECTORY_SEPARATOR_STR "bin" ACE_DIRECTORY_SEPARATOR_STR "gperf",
                       ace_root);
#endif /* ACE_GPERF */
    }

  // Initialize the decls seen info masks

  const ACE_UINT64 cursor = 1U;

  ACE_SET_BITS (this->decls_seen_masks.interface_seen_,         cursor);
  ACE_SET_BITS (this->decls_seen_masks.valuetype_seen_,         cursor << 1);
  ACE_SET_BITS (this->decls_seen_masks.abstract_iface_seen_,    cursor << 2);
  ACE_SET_BITS (this->decls_seen_masks.local_iface_seen_,       cursor << 3);
  ACE_SET_BITS (this->decls_seen_masks.non_local_iface_seen_,   cursor << 4);
  ACE_SET_BITS (this->decls_seen_masks.fwd_iface_seen_,         cursor << 5);
  ACE_SET_BITS (this->decls_seen_masks.fwd_valuetype_seen_,     cursor << 6);
  ACE_SET_BITS (this->decls_seen_masks.basic_type_seen_,        cursor << 7);
  ACE_SET_BITS (this->decls_seen_masks.ambiguous_type_seen_,    cursor << 8);
  ACE_SET_BITS (this->decls_seen_masks.enum_seen_,              cursor << 9);
  ACE_SET_BITS (this->decls_seen_masks.string_seen_,            cursor << 10);
  ACE_SET_BITS (this->decls_seen_masks.array_seen_,             cursor << 11);
  ACE_SET_BITS (this->decls_seen_masks.aggregate_seen_,         cursor << 12);
  ACE_SET_BITS (this->decls_seen_masks.union_seen_,             cursor << 13);
  ACE_SET_BITS (this->decls_seen_masks.exception_seen_,         cursor << 14);
  ACE_SET_BITS (this->decls_seen_masks.operation_seen_,         cursor << 15);
  ACE_SET_BITS (this->decls_seen_masks.non_local_op_seen_,      cursor << 16);
  ACE_SET_BITS (this->decls_seen_masks.typecode_seen_,          cursor << 17);
  ACE_SET_BITS (this->decls_seen_masks.any_seen_,               cursor << 18);
  ACE_SET_BITS (this->decls_seen_masks.parametermode_seen_,     cursor << 19);
  ACE_SET_BITS (this->decls_seen_masks.base_object_seen_,       cursor << 20);
  ACE_SET_BITS (this->decls_seen_masks.valuefactory_seen_,      cursor << 21);
  ACE_SET_BITS (this->decls_seen_masks.valuebase_seen_,         cursor << 22);

  ACE_SET_BITS (this->decls_seen_masks.seq_seen_,               cursor << 27);
  ACE_SET_BITS (this->decls_seen_masks.iface_seq_seen_,         cursor << 28);
  ACE_SET_BITS (this->decls_seen_masks.vt_seq_seen_,            cursor << 29);
  ACE_SET_BITS (this->decls_seen_masks.array_seq_seen_,         cursor << 30);
  ACE_SET_BITS (this->decls_seen_masks.pseudo_seq_seen_,        cursor << 31);
  ACE_SET_BITS (this->decls_seen_masks.string_seq_seen_,        cursor << 32);
  ACE_SET_BITS (this->decls_seen_masks.wstring_seq_seen_,       cursor << 33);
  ACE_SET_BITS (this->decls_seen_masks.octet_seq_seen_,         cursor << 34);
  ACE_SET_BITS (this->decls_seen_masks.boolean_seq_seen_,       cursor << 35);
  ACE_SET_BITS (this->decls_seen_masks.char_seq_seen_,          cursor << 36);
  ACE_SET_BITS (this->decls_seen_masks.wchar_seq_seen_,         cursor << 37);
  ACE_SET_BITS (this->decls_seen_masks.short_seq_seen_,         cursor << 38);
  ACE_SET_BITS (this->decls_seen_masks.ushort_seq_seen_,        cursor << 39);
  ACE_SET_BITS (this->decls_seen_masks.octet_seq_seen_,         cursor << 40);
  ACE_SET_BITS (this->decls_seen_masks.long_seq_seen_,          cursor << 41);
  ACE_SET_BITS (this->decls_seen_masks.ulong_seq_seen_,         cursor << 42);
  ACE_SET_BITS (this->decls_seen_masks.longlong_seq_seen_,      cursor << 43);
  ACE_SET_BITS (this->decls_seen_masks.ulonglong_seq_seen_,     cursor << 44);
  ACE_SET_BITS (this->decls_seen_masks.float_seq_seen_,         cursor << 45);
  ACE_SET_BITS (this->decls_seen_masks.double_seq_seen_,        cursor << 46);
  ACE_SET_BITS (this->decls_seen_masks.longdouble_seq_seen_,    cursor << 47);
  ACE_SET_BITS (this->decls_seen_masks.any_seq_seen_,           cursor << 48);

  ACE_SET_BITS (this->decls_seen_masks.basic_arg_seen_,         cursor << 52);
  ACE_SET_BITS (this->decls_seen_masks.bd_string_arg_seen_,     cursor << 53);
  ACE_SET_BITS (this->decls_seen_masks.fixed_array_arg_seen_,   cursor << 54);
  ACE_SET_BITS (this->decls_seen_masks.fixed_size_arg_seen_,    cursor << 55);
  ACE_SET_BITS (this->decls_seen_masks.object_arg_seen_,        cursor << 56);
  ACE_SET_BITS (this->decls_seen_masks.special_basic_arg_seen_, cursor << 57);
  ACE_SET_BITS (this->decls_seen_masks.ub_string_arg_seen_,     cursor << 58);
  ACE_SET_BITS (this->decls_seen_masks.var_array_arg_seen_,     cursor << 59);
  ACE_SET_BITS (this->decls_seen_masks.var_size_arg_seen_,      cursor << 60);
}

IDL_GlobalData::~IDL_GlobalData (void)
{
}

// Get or set scopes stack
UTL_ScopeStack &
IDL_GlobalData::scopes (void)
{
  return this->pd_scopes;
}

// Get or set root of AST
AST_Root *
IDL_GlobalData::root (void)
{
  return this->pd_root;
}

void
IDL_GlobalData::set_root (AST_Root *r)
{
  this->pd_root = r;
}

// Get or set generator object
AST_Generator *
IDL_GlobalData::gen (void)
{
  return this->pd_gen;
}

void
IDL_GlobalData::set_gen (AST_Generator *g)
{
  this->pd_gen = g;
}

// Get or set error object
UTL_Error *
IDL_GlobalData::err (void)
{
  return this->pd_err;
}

void
IDL_GlobalData::set_err (UTL_Error *e)
{
  this->pd_err = e;
}

// Get or set error count
long
IDL_GlobalData::err_count (void)
{
  return this->pd_err_count;
}

void
IDL_GlobalData::set_err_count (long c)
{
  this->pd_err_count = c;
}

// Get or set line number
long
IDL_GlobalData::lineno (void)
{
  return this->pd_lineno;
}

void
IDL_GlobalData::set_lineno (long n)
{
  this->pd_lineno = n;
}

// Get or set file name being read now
UTL_String *
IDL_GlobalData::filename (void)
{
  return this->pd_filename;
}

void
IDL_GlobalData::set_filename (UTL_String *s)
{
  if (this->pd_filename != 0)
    {
      this->pd_filename->destroy ();
      delete this->pd_filename;
      this->pd_filename = 0;
    }

  this->pd_filename = s;
}

// Get or set main file name
UTL_String *
IDL_GlobalData::main_filename (void)
{
  return this->pd_main_filename;
}

void
IDL_GlobalData::set_main_filename (UTL_String *n)
{
  if (this->pd_main_filename != 0)
    {
      this->pd_main_filename->destroy ();
      delete this->pd_main_filename;
      this->pd_main_filename = 0;
    }

  this->pd_main_filename = n;
}

// Get or set real file name
UTL_String *
IDL_GlobalData::real_filename (void)
{
  return this->pd_real_filename;
}

void
IDL_GlobalData::set_real_filename (UTL_String *n)
{
  if (this->pd_real_filename != 0)
    {
      this->pd_real_filename->destroy ();
      delete this->pd_real_filename;
      this->pd_real_filename = 0;
    }

  this->pd_real_filename = n;
}

// Get or set indicator whether import is on
idl_bool
IDL_GlobalData::imported (void)
{
  return this->pd_in_main_file ? I_FALSE : pd_import;
}

idl_bool
IDL_GlobalData::import (void)
{
  return this->pd_import;
}

void
IDL_GlobalData::set_import (idl_bool is_in)
{
  this->pd_import = is_in;
}

// Get or set indicator whether we're reading the main file now
idl_bool
IDL_GlobalData::in_main_file (void)
{
  return this->pd_in_main_file;
}

void
IDL_GlobalData::set_in_main_file (idl_bool is_in)
{
  this->pd_in_main_file = is_in;
}

// Get or set stripped file name
UTL_String *
IDL_GlobalData::stripped_filename (void)
{
  return this->pd_stripped_filename;
}

void
IDL_GlobalData::set_stripped_filename (UTL_String *nm)
{
  if (this->pd_stripped_filename != 0)
    delete this->pd_stripped_filename;

  this->pd_stripped_filename = nm;
}

// Get or set cache value for argv[0]
const char *
IDL_GlobalData::prog_name (void)
{
  return this->pd_prog_name;
}

void
IDL_GlobalData::set_prog_name (const char *pn)
{
  this->pd_prog_name = pn;
}

// Get or set location to find C preprocessor
const char *
IDL_GlobalData::cpp_location (void)
{
  return this->pd_cpp_location;
}

void
IDL_GlobalData::set_cpp_location (const char *l)
{
  this->pd_cpp_location = l;
}

// Get or set IDL compiler flags
long
IDL_GlobalData::compile_flags (void)
{
  return this->pd_compile_flags;
}

void
IDL_GlobalData::set_compile_flags (long cf)
{
  this->pd_compile_flags = cf;
}

// Get or set local escapes string. This provides additional mechanism
// to pass information to a BE.
char *
IDL_GlobalData::local_escapes (void)
{
  return this->pd_local_escapes;
}

void
IDL_GlobalData::set_local_escapes (const char *e)
{
  if (this->pd_local_escapes != 0)
    {
      delete [] this->pd_local_escapes;
    }

  this->pd_local_escapes = ACE::strnew (e);
}

// Get or set indent object
UTL_Indenter *
IDL_GlobalData::indent (void)
{
  return this->pd_indent;
}

void
IDL_GlobalData::set_indent (UTL_Indenter *i)
{
  this->pd_indent = i;
}

// Have we seen this #include file name before?
long
IDL_GlobalData::seen_include_file_before (char *n)
{
  unsigned long i;
  char *incl = 0;
  char *tmp = n;

  for (i = 0; i < this->pd_n_include_file_names; ++i)
    {
      incl = this->pd_include_file_names[i]->get_string ();

      if (ACE_OS::strcmp (tmp, incl) == 0)
        {
          return seen_once[i]++;
        }
    }

  return 0;
}

// Store the name of an #include file.
void
IDL_GlobalData::store_include_file_name (UTL_String *n)
{
  UTL_String **o_include_file_names;
  unsigned long o_n_alloced_file_names;
  unsigned long i;

  // Check if we need to store it at all or whether we've seen it already.
  if (this->seen_include_file_before (n->get_string ()))
    {
      return;
    }

  // OK, need to store. Make sure there's space for one more string
  if (this->pd_n_include_file_names == this->pd_n_alloced_file_names)
    {
      // Allocating more space.
      if (this->pd_n_alloced_file_names == 0)
        {
          this->pd_n_alloced_file_names = INCREMENT;
          ACE_NEW (this->pd_include_file_names,
                   UTL_String *[this->pd_n_alloced_file_names]);
        }
      else
        {
          o_include_file_names = this->pd_include_file_names;
          o_n_alloced_file_names = this->pd_n_alloced_file_names;
          this->pd_n_alloced_file_names += INCREMENT;
          ACE_NEW (this->pd_include_file_names,
                   UTL_String *[this->pd_n_alloced_file_names]);

          for (i = 0; i < o_n_alloced_file_names; ++i)
            {
              this->pd_include_file_names[i] = o_include_file_names[i];
            }

          delete [] o_include_file_names;
        }
    }

  // Store it.
  seen_once[this->pd_n_include_file_names] = 1;
  this->pd_include_file_names[this->pd_n_include_file_names++] = n;
}

void
IDL_GlobalData::set_include_file_names (UTL_String **ns)
{
  this->pd_include_file_names = ns;
}

UTL_String **
IDL_GlobalData::include_file_names (void)
{
  return this->pd_include_file_names;
}

void
IDL_GlobalData::set_n_include_file_names (unsigned long n)
{
  pd_n_include_file_names = n;
}

unsigned long
IDL_GlobalData::n_include_file_names (void)
{
  return pd_n_include_file_names;
}

// Access methods to deal with other IDL files included in the main
// IDL file.

void
IDL_GlobalData::add_to_included_idl_files (char* file_name)
{
  // Is there enough space there to store one more file.
  if (this->n_included_idl_files_ == this->n_allocated_idl_files_)
    {
      // Allocating more space.
      if (this->n_allocated_idl_files_ == 0)
        {
          // First time creation.
          this->n_allocated_idl_files_ = INCREMENT;
          ACE_NEW (this->included_idl_files_,
                   char *[this->n_allocated_idl_files_]);
        }
      else
        {
          // Adding more storage.
          char** old_included_idl_files =
            this->included_idl_files_;
          size_t n_old_allocated_idl_files =
            this->n_allocated_idl_files_;
          this->n_allocated_idl_files_ += INCREMENT;
          ACE_NEW (this->included_idl_files_,
                   char *[this->n_allocated_idl_files_]);

          for (size_t i = 0; i < n_old_allocated_idl_files; ++i)
            {
              this->included_idl_files_ [i] = old_included_idl_files [i];
            }

          delete [] old_included_idl_files;
        }
    }

  // Store it.
  this->included_idl_files_ [this->n_included_idl_files_++] = file_name;
}

char**
IDL_GlobalData::included_idl_files (void)
{
  return this->included_idl_files_;
}

size_t
IDL_GlobalData::n_included_idl_files (void)
{
  return this->n_included_idl_files_;
}

// Set the number of included_idl_files. Use this carefully. This
// method is used when we validate all the #included idl files,
// against the ones that we get after preprocessing.
void
IDL_GlobalData::n_included_idl_files (size_t n)
{
  this->n_included_idl_files_ = n;
}

// Validate the included idl files, some files might have been
// ignored by the preprocessor.
void
IDL_GlobalData::validate_included_idl_files (void)
{
  // Flag to make sure we don't repeat things.
  static int already_done = 0;

  if (already_done == 1)
    {
      return;
    }

  already_done = 1;

  // New number of included_idl_files.
  size_t newj = 0;
  size_t n_found = 0;
  size_t n_pre_preproc_includes = idl_global->n_included_idl_files ();
  char **pre_preproc_includes = idl_global->included_idl_files ();
  size_t n_post_preproc_includes = idl_global->n_include_file_names ();
  UTL_String **post_preproc_includes = idl_global->include_file_names ();

  char pre_abspath[MAXPATHLEN];
  char post_abspath[MAXPATHLEN];
  char **path_tmp = 0;
  char *post_tmp = 0;
  char *full_path = 0;

  for (size_t j = 0; j < n_pre_preproc_includes; ++j)
    {
      // Check this name with the names list that we got from the
      // preprocessor.
      size_t valid_file = 0;
      full_path = ACE_OS::realpath (pre_preproc_includes[j],
                                    pre_abspath);

      if (full_path != 0)
        {
          for (size_t ni = 0; ni < n_post_preproc_includes; ++ni)
            {
              post_tmp = post_preproc_includes[ni]->get_string ();
              full_path = ACE_OS::realpath (post_tmp, post_abspath);

              if (full_path != 0
                  && ACE_OS::strcmp (pre_abspath, post_abspath) == 0)
                {
                        FILE *test = ACE_OS::fopen (post_abspath, "r");

                  if (test == 0)
                    {
                      continue;
                    }

                  // This file name is valid.
                  valid_file = 1;
                  ++n_found;
                  break;
                }
            }
        }

      if (valid_file == 0)
        {
          for (ACE_Unbounded_Queue_Iterator<char *>iter (
                   this->include_paths_
                 );
               !iter.done ();
               iter.advance ())
            {
              iter.next (path_tmp);
              ACE_CString pre_partial (*path_tmp);
              pre_partial += ACE_DIRECTORY_SEPARATOR_STR;
              pre_partial += pre_preproc_includes[j];
              full_path = ACE_OS::realpath (pre_partial.c_str (), pre_abspath);

              if (full_path != 0)
                {
                  for (size_t m = 0; m < n_post_preproc_includes; ++m)
                    {
                      post_tmp = post_preproc_includes[m]->get_string ();
                      full_path = ACE_OS::realpath (post_tmp, post_abspath);

                      if (full_path != 0
                          && ACE_OS::strcmp (pre_abspath, post_abspath) == 0)
                        {
                                FILE *test = ACE_OS::fopen (post_abspath, "r");

                          if (test == 0)
                            {
                              continue;
                            }

                          // This file name is valid.
                          valid_file = 1;
                          ++n_found;
                          break;
                        }
                    }
                }

              if (valid_file == 1)
                {
                  break;
                }
            }
        }

      // Remove the file, if it is not valid.
      if (valid_file == 0)
        {
          delete pre_preproc_includes[j];
          pre_preproc_includes[j] = 0;
        }
      else
        {
          // File is valid.

          // Move it to new index if necessary.
          if (j != newj)
            {
              // Move to the new index position.
              pre_preproc_includes[newj] =
                pre_preproc_includes[j];

              // Make old position 0.
              pre_preproc_includes[j] = 0;
            }

          // Increment the new index.
          newj++;
        }

      if (n_found == n_post_preproc_includes)
        {
          break;
        }
    }

  // Now adjust the count on the included_idl_files.
  idl_global->n_included_idl_files (newj);
}

void
IDL_GlobalData::set_parse_state(ParseState ps)
{
  pd_parse_state = ps;
}

IDL_GlobalData::ParseState
IDL_GlobalData::parse_state()
{
  return pd_parse_state;
}

/*
 * Convert a PredefinedType to an ExprType
 */
AST_Expression::ExprType
IDL_GlobalData::PredefinedTypeToExprType (
    AST_PredefinedType::PredefinedType pt
  )
{
  switch (pt) {
  case AST_PredefinedType::PT_long:
    return AST_Expression::EV_long;
  case AST_PredefinedType::PT_ulong:
    return AST_Expression::EV_ulong;
  case AST_PredefinedType::PT_short:
    return AST_Expression::EV_short;
  case AST_PredefinedType::PT_ushort:
    return AST_Expression::EV_ushort;
  case AST_PredefinedType::PT_longlong:
    return AST_Expression::EV_longlong;
  case AST_PredefinedType::PT_ulonglong:
    return AST_Expression::EV_ulonglong;
  case AST_PredefinedType::PT_float:
    return AST_Expression::EV_float;
  case AST_PredefinedType::PT_double:
    return AST_Expression::EV_double;
  case AST_PredefinedType::PT_longdouble:
    return AST_Expression::EV_longdouble;
  case AST_PredefinedType::PT_char:
    return AST_Expression::EV_char;
  case AST_PredefinedType::PT_wchar:
    return AST_Expression::EV_wchar;
  case AST_PredefinedType::PT_octet:
    return AST_Expression::EV_octet;
  case AST_PredefinedType::PT_boolean:
    return AST_Expression::EV_bool;
  case AST_PredefinedType::PT_void:
    return AST_Expression::EV_void;
  default:
    return AST_Expression::EV_enum;
  }
}

// returns the IDL source file being copiled
UTL_String* IDL_GlobalData::idl_src_file (void)
{
  return this->pd_idl_src_file;
}

// set the source IDL file that is being parsed
void IDL_GlobalData::idl_src_file (UTL_String *s)
{
  this->pd_idl_src_file = s;
}

void
IDL_GlobalData::temp_dir (const char *s)
{
  // Delete the old pointer.
  delete [] this->temp_dir_;

  // Allocate memory, 1 for the end of string.
  ACE_NEW (this->temp_dir_,
           char [ACE_OS::strlen (s) +
                ACE_OS::strlen (ACE_DIRECTORY_SEPARATOR_STR) +
                1]);

  // Copy the strings.
  ACE_OS::sprintf (this->temp_dir_,
                   "%s%s",
                   s,
                   ACE_DIRECTORY_SEPARATOR_STR);
}

const char *
IDL_GlobalData::temp_dir (void) const
{
  return this->temp_dir_;
}

void
IDL_GlobalData::tao_root (const char *s)
{
  delete [] this->tao_root_;
  this->tao_root_ = ACE::strnew (s);
}

const char *
IDL_GlobalData::tao_root (void) const
{
  return this->tao_root_;
}

void
IDL_GlobalData::gperf_path (const char *s)
{
  delete [] this->gperf_path_;
  this->gperf_path_ = ACE::strnew (s);
}

const char *
IDL_GlobalData::gperf_path (void) const
{
  return this->gperf_path_;
}

void
IDL_GlobalData::ident_string (const char *s)
{
  delete [] this->ident_string_;
  this->ident_string_ = ACE::strnew (s);
}

const char *
IDL_GlobalData::ident_string (void) const
{
  return this->ident_string_;
}

void
IDL_GlobalData::case_diff_error (idl_bool val)
{
  this->case_diff_error_ = val;
}

idl_bool
IDL_GlobalData::case_diff_error (void)
{
  return this->case_diff_error_;
}

void
IDL_GlobalData::nest_orb (idl_bool val)
{
  this->nest_orb_ = val;
}

idl_bool
IDL_GlobalData::nest_orb (void)
{
  return this->nest_orb_;
}

void
IDL_GlobalData::destroy (void)
{
  if (this->pd_filename != 0)
    {
      this->pd_filename->destroy ();
      delete this->pd_filename;
      this->pd_filename = 0;
    }

  if (this->pd_main_filename != 0)
    {
      this->pd_main_filename->destroy ();
      delete this->pd_main_filename;
      this->pd_main_filename = 0;
    }

  if (this->pd_real_filename != 0)
    {
      this->pd_real_filename->destroy ();
      delete this->pd_real_filename;
      this->pd_real_filename = 0;
    }

  if (this->pd_stripped_filename != 0)
    {
      this->pd_stripped_filename->destroy ();
      delete this->pd_stripped_filename;
      this->pd_stripped_filename = 0;
    }

  if (this->pd_idl_src_file != 0)
    {
      this->pd_idl_src_file->destroy ();
      delete this->pd_idl_src_file;
      this->pd_idl_src_file = 0;
    }

  size_t size = this->pragma_prefixes ().size  ();
  char *trash = 0;

  for (size_t i = 0; i < size; ++i)
    {
      this->pragma_prefixes ().pop (trash);
      delete [] trash;
      trash = 0;
    }
    
  for (unsigned long j = 0; j < this->pd_n_include_file_names; ++j)
    {
      // Delete the contained char* but not the UTL_String -
      // we can leave the slots allocated and clean up later.
      this->pd_include_file_names[j]->destroy ();
      this->pd_include_file_names[j] = 0;
    }
    
  this->pd_n_include_file_names = 0;
  
  for (size_t k = 0; k < n_included_idl_files_; ++k)
    {
      // No memory allocated for these, so just set to 0.
      this->included_idl_files_[k] = 0;
    }
    
  this->n_included_idl_files_ = 0;

  this->pd_root->destroy ();
}

void
IDL_GlobalData::append_idl_flag (const char *s)
{
  idl_flags_ += " " + ACE_CString (s);
}

const char *
IDL_GlobalData::idl_flags (void) const
{
  return idl_flags_.c_str ();
}

ACE_Hash_Map_Manager<ACE_CString, int, ACE_Null_Mutex> &
IDL_GlobalData::idl_keywords (void)
{
  return this->idl_keywords_;
}

ACE_Unbounded_Stack<char *> &
IDL_GlobalData::pragma_prefixes (void)
{
  return this->pragma_prefixes_;
}

void
IDL_GlobalData::update_prefix (char *filename)
{
  // If we are just starting up and processing the temporary filename,
  // there are no prefix issues to deal with yet.
  if (this->pd_main_filename == 0 || this->pd_filename == 0)
    {
      return;
    }

  char *fstring = this->pd_filename->get_string ();
  char *tail = fstring + ACE_OS::strlen (fstring) - 3;

  // We have to do this check because some preprocessors (gcc 3.2
  // on RedHat Linux 7.1, for one) output the same filename
  // multiple times for no apparent reason, and we don't want it
  // to clear the prefix.
  if (ACE_OS::strcmp (fstring, filename) == 0
      || ACE_OS::strcmp (tail, ".cc") == 0)
    {
      return;
    }

  ACE_CString tmp ("", 0, 0);
  char *main_filename = this->pd_main_filename->get_string ();

  ACE_CString ext_id (filename);
  char *prefix = 0;

  int status = this->file_prefixes_.find (ext_id, prefix);

  if (status == 0)
    {
      this->pd_root->prefix (prefix);
    }
  else
    {
      prefix = ACE::strnew ("");
      (void) this->file_prefixes_.bind (ext_id, prefix);
      char *tmp = const_cast<char *> ("");
      this->pd_root->prefix (tmp);
    }

  // The first branch is executed if we are finishing an
  // included IDL file (but the current filename has not yet
  // been changed). So we check for (1) the current filename is
  // not the same as the main filename (2) the prefix stack size
  // is greater than 1 (to skip the case where we are passed the
  // temporary filename) and (3) we have either seen the filename
  // passed in before as an included file or we are passed the
  // main filename. Otherwise we know we are beginning an included
  // file, so we push a blank prefix on the stack, which may
  // possibly be changed later.
  if (this->seen_include_file_before (filename) != 0
      || ACE_OS::strcmp (filename, main_filename) == 0
      || ACE_OS::strcmp (filename, this->pd_filename->get_string ()) != 0)
    {
      if (!this->pd_in_main_file)
        {
          char *trash = 0;
          this->pragma_prefixes_.pop (trash);
          delete [] trash;
        }
    }
  else
    {
      this->pragma_prefixes_.push (tmp.rep ());
    }
}

UTL_ScopedName *
IDL_GlobalData::string_to_scoped_name (char *s)
{
  char *start = s;
  int len = 0;
  UTL_ScopedName *retval = 0;

  char *end = ACE_OS::strstr (start, "::");

  while (end != 0)
    {
      len = end - start;

      if (len != 0)
        {
          char tmp[256];

          ACE_OS::strncpy (tmp,
                           start,
                           len);

          tmp[len] = '\0';

          Identifier *id = 0;
          ACE_NEW_RETURN (id,
                          Identifier (tmp),
                          0);

          if (retval == 0)
            {
              ACE_NEW_RETURN (retval,
                              UTL_ScopedName (id,
                                              0),
                              0);
            }
          else
            {
              UTL_ScopedName *conc_name = 0;
              ACE_NEW_RETURN (conc_name,
                              UTL_ScopedName (id,
                                              0),
                              0);

              retval->nconc (conc_name);
            }
        }

      start = end + 2;

      end = ACE_OS::strstr (start, "::");
    }

  end = ACE_OS::strchr (start, ' ');

  len = end - start;

  char tmp[256];

  ACE_OS::strncpy (tmp,
                   start,
                   len);

  tmp[len] = '\0';

  Identifier *id = 0;
  ACE_NEW_RETURN (id,
                  Identifier (tmp),
                  0);

  if (retval == 0)
    {
      ACE_NEW_RETURN (retval,
                      UTL_ScopedName (id,
                                      0),
                      0);
    }
  else
    {
      UTL_ScopedName *conc_name = 0;
      ACE_NEW_RETURN (conc_name,
                      UTL_ScopedName (id,
                                      0),
                      0);

      retval->nconc (conc_name);
    }

  return retval;
}

const char *
IDL_GlobalData::stripped_preproc_include (const char *name)
{
  // Some preprocessors prepend "./" to filenames in the
  // working directory, some others prepend ".\". If either
  // of these are here, we want to strip them.
  if (name[0] == '.')
    {
      if (name[1] == '\\' || name[1] == '/')
        {
          return name + 2;
        }
    }

  return name;
}

/**
 Whether we should not mung idl element names that are
 C++ keywords e.g. delete, operator etc. with _cxx_ prefix.
 Should be true when being used by the IFR Service
 */
idl_bool
IDL_GlobalData::preserve_cpp_keywords (void)
{
  return preserve_cpp_keywords_;
}

/**
 Set whether we should not mung idl element names that are C++
 keywords e.g. delete, operator etc. with _cxx_ prefix.
 Is unset by the tao_idl compiler.
 */
void
IDL_GlobalData::preserve_cpp_keywords (idl_bool val)
{
  preserve_cpp_keywords_ = val;
}

void
IDL_GlobalData::add_include_path (const char *s)
{
  this->include_paths_.enqueue_tail (ACE::strnew (s));
}

ACE_Hash_Map_Manager<ACE_CString, char *, ACE_Null_Mutex> &
IDL_GlobalData::file_prefixes (void)
{
  return this->file_prefixes_;
}

idl_bool
IDL_GlobalData::pass_orb_idl (void) const
{
  return this->pass_orb_idl_;
}

void
IDL_GlobalData::pass_orb_idl (idl_bool val)
{
  this->pass_orb_idl_ = val;
}

// Return 0 on success, -1 failure. The <errno> corresponding to the
// error that caused the GPERF execution is also set.
int
IDL_GlobalData::check_gperf (void)
{
  // If absolute path is not specified yet, let us call just
  // "gperf". Hopefully PATH is set up correctly to locate the gperf.
  if (idl_global->gperf_path () == 0)
    {
      // If ACE_GPERF is defined then use that gperf program instead of "gperf."
#if defined (ACE_GPERF)
      idl_global->gperf_path (ACE_GPERF);
#else
      idl_global->gperf_path ("gperf");
#endif /* ACE_GPERF */
    }

  // If we have absolute path for the <gperf> rather than just the
  // executable name <gperf>, make sure the file exists
  // firsts. Otherwise just call <gperf>. Probably PATH is set
  // correctly to take care of this.

  // If ACE_GPERF is defined then use that gperf program instead of "gperf."
#if defined (ACE_GPERF)
  if (ACE_OS::strcmp (idl_global->gperf_path (), ACE_GPERF) != 0)
#else
  if (ACE_OS::strcmp (idl_global->gperf_path (), "gperf") != 0)
#endif /* ACE_GPERF */
    {
      // It is absolute path. Check the existance, permissions and
      // the modes.
      if (ACE_OS::access (idl_global->gperf_path (),
                          F_OK | X_OK) == -1)
        {
          // Problem with the file. No point in having the absolute
          // path. Swith to "gperf".
          // If ACE_GPERF is defined then use that gperf program
          //instead of "gperf."
#if defined (ACE_GPERF)
          idl_global->gperf_path (ACE_GPERF);
#else
          idl_global->gperf_path ("gperf");
#endif /* ACE_GPERF */
        }
    }

  // Just call gperf in silent mode. It will come and immly exit.

  // Using ACE_Process.
  ACE_Process process;
  ACE_Process_Options process_options;

  // Set the command line for the gperf program.
  process_options.command_line ("%s"
                                " "
                                "-V",
                                idl_global->gperf_path ());

  // Spawn a process for gperf.
  if (process.spawn (process_options) == -1)
    {
      return -1;
    }

#if defined (ACE_WIN32)
  // No wait or anything in Win32.
  return 0;
#endif /* ACE_WIN32 */

  // Wait for gperf to complete.
  ACE_exitcode wait_status = 0;
  if (process.wait (&wait_status) == -1)
    {
      return -1;
    }
  else
    {
      // Wait is sucessful, we will check the exit code from the
      // spawned process.
      if (WIFEXITED (wait_status))
        {
          // Normal exit.

          // Check the exit value of the spawned process. ACE_Process
          // exits with <errno> as exit code, if it is not able to
          // exec gperf program, so get the exit code now and set that
          // to <errno> again, so that it can be used to print error
          // messages.
          errno = WEXITSTATUS (wait_status);
          if (errno)
            {
              // <exec> has failed.
              return -1;
            }
          else
            {
              // Everything was alright.
              return 0;
            }
        }
      else
        {
          // Not a normal exit. No <errno> might be set.
          return -1;
        }
    }
}

void
IDL_GlobalData::fini (void)
{
  this->pd_root->fini ();
  delete this->pd_root;
  this->pd_root = 0;

  delete this->pd_err;
  this->pd_err = 0;
  delete this->pd_gen;
  this->pd_gen = 0;
  delete this->pd_indent;
  this->pd_indent = 0;
  delete [] this->pd_local_escapes;
  this->pd_local_escapes = 0;
  delete [] this->tao_root_;
  this->tao_root_ = 0;
  delete [] this->gperf_path_;
  this->gperf_path_ = 0;
  delete [] this->temp_dir_;
  this->temp_dir_ = 0;
  delete [] this->ident_string_;
  this->ident_string_ = 0;
}
