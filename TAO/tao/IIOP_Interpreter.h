// This may look like C, but it's really -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    IIOP_Interpreter.h
//
// = DESCRIPTION
//    Header file for TAO's IIOP interpreter.
//
// = AUTHOR
//     Douglas C. Schmidt
//
// ============================================================================

#ifndef TAO_IIOP_INTERPRETER_H
#define TAO_IIOP_INTERPRETER_H

// Useful typedefs.
typedef size_t TAO_attribute_calculator (TAO_InputCDR *stream,
                                         size_t &alignment,
                                         CORBA_Environment &_env);
typedef CORBA::Boolean TAO_param_skip_rtn (TAO_InputCDR *);

class TAO_Export TAO_IIOP_Interpreter
{
  // = TITLE
  //   TAO's CORBA TypeCode interpreter, which traverses GIOP/IIOP
  //   data structures.
  //
  // = DESCRIPTION
  //   This uses the standard C/C++ representation for data, and knows
  //   how to do things like align and pad according to standard
  //   rules.  It is driven by CDR marshaled representations of
  //   TypeCodes.
  //
  //   It does two key things: (a) calculate size and alignment
  //   restrictions for the data type described by any given typecode;
  //   and (b) "visits" each element of a data type in the order those
  //   elements are defined in the type's IDL definition.
  //
  //   A typical use is that some application-specific "visit"
  //   function will be called with a typecode and data value.  Then
  //   that "visit" function may choose to use the interpreter's
  //   knowledge of the environment's size, padding, and alignment
  //   rules to help it examine each of the constituents of complex
  //   data values.  It does so by making a call to
  //   <TypeCode::traverse>, and passing itself for future recursive
  //   calls.
  //
  //   NOTE that this module has system dependent parts, and so should
  //   be examined when porting to new CPU architectures, compilers,
  //   and so forth to make sure it correctly implements the
  //   appropriate binary interfaces.
  //
  //   Issues of concern are primarily that sizes and representations
  //   of CORBA primitive data types are correct (key issues are
  //   verified when the ORB initializes) and that the alignment rules
  //   are recognized.
  //
  //   Also, exceptions have vtables in them, which may cause trouble
  //   if they aren't located at the very beginning by the compiler in
  //   question.
  //
  //   So for example, moving to another CPU architecture which still
  //   uses standard sized two's complement integers and IEEE floating
  //   point, and expects "natural" alignment, won't be hard.  Even
  //   using PC style tightly packed data is simple; the alignment
  //   rules are just simpler.  Most volume microprocessors used in
  //   1995 are correctly supported.
  //
  //   Using data representations that are far from the standard C/C++
  //   style data layout is probably not practical with this
  //   implementation.  LISP systems, as one example, probably won't
  //   use "in-memory" representations much like C/C++, even though
  //   its "wire form" could directly match CDR.
  //
  //   ALSO, the treatment of exceptions may need to be examined in
  //   language environments which actually rely on C++ exceptions.
  //   The RTTI data that identifies exceptions can easily be ignored
  //   by this interpreter (if it's taught about that compiler's RTTI)
  //   but it may not be practical for any code not generated by that
  //   specific C++ compiler to store such data in the right place to
  //   look like a C++ exception, or to throw exceptions when that's
  //   needed.  (RTTI == "Run Time Typing Information", needed to make
  //   C++ exceptions work correctly and partially exposed to users by
  //   the ANSI standards comittee.  It provides type-safe
  //   "downcasting" and other features previously unavailable in
  //   C++.)
  //
  //   THREADING NOTE: Data structures being traversed should only be
  //   modified by the thread doing the traversal.  The interpretive
  //   code itself is reentrant (recursive!) so presents no threading
  //   issues; only the data being fed to the interpreter must be
  //   protected against concurrency.
public:
  static void init (void);
  // Initialize TAO's TypeCode table.

  static size_t calc_nested_size_and_alignment (CORBA::TypeCode_ptr tc,
                                                TAO_InputCDR *original_stream,
                                                size_t &alignment,
                                                CORBA_Environment &_env = CORBA_Environment::default_environment ());
  static size_t calc_nested_size_and_alignment_i (CORBA::TypeCode_ptr tc,
                                                  TAO_InputCDR *stream,
                                                  CORBA::TCKind kind,
                                                  size_t &alignment,
                                                  CORBA_Environment &_env = CORBA_Environment::default_environment ());
  // For a given typecode, figure out its size and alignment needs.
  // This version is used mostly when traversing other typecodes, and
  // follows these rules:
  //
  // - Some typecodes are illegal (can't be nested inside others);
  // - Indirections are allowed;
  // - The whole typecode (including TCKind enum) is in the stream
  //
  // When the routine returns, the stream has skipped this TypeCode.
  //
  // "size" is returned, "alignment" is an 'out' parameter.  If it is
  // non-null, "tc" is initialized to hold the contents of the TypeCode;
  // it depends on the contents of the original stream to be valid.
  //
  // The _i routine encapsulates some common code for the case were an
  // indirected TypeCode is in use.
  //
  // @@ explore splitting apart returning the size/alignment data and
  // the TypeCode initialization; union traversal would benefit a bit,
  // but it would need more than that to make it as speedy as struct
  // traversal.

  // = Static visitor methods.

  // These methods manipulate CDR-encapsulated TypeCode parameter
  // lists, calculating the size and alignment of the data type being
  // described.  The TCKind value has always been removed from the CDR
  // stream when these calculator routines get called.

  static size_t calc_struct_and_except_attributes (TAO_InputCDR *stream,
                                                   size_t &alignment,
                                                   CORBA::Boolean is_exception,
                                                   CORBA_Environment &_env = CORBA_Environment::default_environment ());
  // Given typecode bytes for a structure (or exception), figure out
  // its alignment and size; return size, alignment is an 'out'
  // parameter.  Only "CORBA::tk_struct" (or "CORBA::tk_except") has
  // been taken out of the stream parameter holding the bytes.
  //
  // We use a one-pass algorithm, calculating size and inter-element
  // padding while recording the strongest alignment restriction.
  // Then we correct the size to account for tail-padding.
  //
  // This routine recognizes that exceptions are just structs with
  // some additional information.  Different environments may differ
  // in what that additional information is, so this routine may need
  // to be taught about compiler-specific representation of that
  // additional "RTTI" data.

  static size_t calc_struct_attributes (TAO_InputCDR *stream,
                                        size_t &alignment,
                                        CORBA_Environment &_env = CORBA_Environment::default_environment ());
  // Calculate size and alignment for a structure.


#if defined (TAO_NO_COPY_OCTET_SEQUENCES)
  static size_t calc_seq_attributes (TAO_InputCDR *stream,
                                     size_t &alignment,
                                     CORBA_Environment &_env = CORBA_Environment::default_environment ());
  // Calculate size and alignment for a sequence, most of them have
  // the same requirements, but for the sequences of Octets that are
  // optimized to minimize copying.
#endif /* defined (TAO_NO_COPY_OCTET_SEQUENCES) */

  static size_t calc_exception_attributes (TAO_InputCDR *stream,
                                           size_t &alignment,
                                           CORBA_Environment &_env = CORBA_Environment::default_environment ());
  // Calculate size and alignment for an exception.


  static size_t calc_union_attributes (TAO_InputCDR *stream,
                                       size_t &alignment,
                                       CORBA_Environment &_env = CORBA_Environment::default_environment ());
  // Calculate size and alignment for a CORBA discriminated union.
  //
  // Note that this is really a two-element structure.  The first
  // element is the discriminator; the second is the value.  All normal
  // structure padding/alignment rules apply.  In particular, all arms
  // of the union have the same initial address (adequately aligned for
  // any of the members).


  static size_t calc_alias_attributes (TAO_InputCDR *stream,
                                       size_t &alignment,
                                       CORBA_Environment &_env = CORBA_Environment::default_environment ());
  // Calculate size and alignment for a typedeffed type.

  static size_t calc_array_attributes (TAO_InputCDR *stream,
                                       size_t &alignment,
                                       CORBA_Environment &_env = CORBA_Environment::default_environment ());
  // Calculate size and alignment of an array.  (All such arrays are
  // described as single dimensional, even though the IDL definition
  // may specify a multidimensional array ... such arrays are treated
  // as nested single dimensional arrays.)

  static CORBA::Boolean match_value (CORBA::TCKind kind,
                                     TAO_InputCDR *tc_stream,
                                     const void *value,
                                     CORBA_Environment &_env = CORBA_Environment::default_environment ());
  // Cast the discriminant values to the right type and compare them.

  static size_t
  calc_key_union_attributes (TAO_InputCDR *stream,
                             size_t &overall_alignment,
                             size_t &discrim_size_with_pad,
                             CORBA_Environment &_env = CORBA_Environment::default_environment ());


  // = Utility routine that checks if a union member is a variable sized type
  // (and hence is a pointer)
  static int calc_union_attr_is_var_sized_member (TAO_InputCDR *temp,
                                                  CORBA::Boolean &flag);

  // = Utility routines that skip unneeded parameter lists.
  static CORBA::Boolean skip_encapsulation (TAO_InputCDR *stream);
  static CORBA::Boolean skip_long (TAO_InputCDR *stream);

  struct Table_Element
  {
    size_t size_;
    size_t alignment_;
    TAO_attribute_calculator *calc_;
    TAO_param_skip_rtn *skipper_;
  };

  static Table_Element table_[CORBA::TC_KIND_COUNT];
  // Table supporting calculation of size and alignment requirements
  // for any one instance of a given data types.
  //
  // This is indexed via CDR's TCKind values, which are "frozen" as
  // part of the CDR standard.  Entries hold either the size and
  // alignment values for that data type, or a pointer to a function
  // that is used to calculate those values.  Function pointers are
  // normally needed only for constructed types.
  //
  // A "skipper" routine is provided for some data types whose size is
  // known statically (e.g. objrefs, structures, strings) but whose
  // typecodes have parameters that sometimes need to be ignored when
  // found in a CDR stream.  Any attribute calculator routine always
  // skips parameters in the CDR input stream, so no type with such a
  // routine also needs a "skipper".
  //
  // Rather than growing a set of processor-specific #ifdefs, we
  // calculate most of this table (except functions) at ORB
  // initialization time.
};

#endif /* TAO_IIOP_INTERPRETER_H */
