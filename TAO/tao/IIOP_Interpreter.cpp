// $Id$

// @(#)interp.cpp       1.4 95/11/04
// Copyright 1994-1995 by Sun Microsystems Inc.
// All Rights Reserved

#include "tao/corba.h"

TAO_IIOP_Interpreter::Table_Element
TAO_IIOP_Interpreter::table_[CORBA::TC_KIND_COUNT] =
{
  { 0, 1, 0 },                            // CORBA::tk_null
  { 0, 1, 0 },                            // CORBA::tk_void

  { 0, 1, 0, 0 },                         // CORBA::tk_short
  { 0, 1, 0, 0 },                         // CORBA::tk_long
  { 0, 1, 0, 0 },                         // CORBA::tk_ushort
  { 0, 1, 0, 0 },                         // CORBA::tk_ulong

  { 0, 1, 0, 0 },                         // CORBA::tk_float
  { 0, 1, 0, 0 },                         // CORBA::tk_double

  { 0, 1, 0, 0 },                         // CORBA::tk_boolean
  { 0, 1, 0, 0 },                         // CORBA::tk_char
  { 0, 1, 0, 0 },                         // CORBA::tk_octet
  { 0, 1, 0, 0 },                         // CORBA::tk_any

  { 0, 1, 0, 0 },                         // CORBA::tk_TypeCode
  { 0, 1, 0, 0 },                         // CORBA::tk_Principal
  { 0, 1, 0, skip_encapsulation },        // CORBA::tk_objref

  { 0, 1, calc_struct_attributes, 0 },    // CORBA::tk_struct
  { 0, 1, calc_union_attributes, 0 },     // CORBA::tk_union

  { 0, 1, 0, skip_encapsulation },        // CORBA::tk_enum
  { 0, 1, 0, skip_long },                 // CORBA::tk_string
  { 0, 1, 0, skip_encapsulation },        // CORBA::tk_sequence
  { 0, 1, calc_array_attributes, 0 },     // CORBA::tk_array

  // = Two TCKind values added in 94-11-7
  { 0, 1, calc_alias_attributes, 0 },     // CORBA::tk_alias
  { 0, 1, calc_exception_attributes, 0 }, // CORBA::tk_except

  // = Five extended IDL data types, defined in Appendix A of 94-9-32
  // but here with different numeric TCKind codes.  These types
  // represent extensions to CORBA (specifically, to IDL) which are
  // not yet standardized.

  { 0, 1, 0, 0 },                         // CORBA::tk_longlong
  { 0, 1, 0, 0 },                         // CORBA::tk_ulonglong
  { 0, 1, 0, 0 },                         // CORBA::tk_longdouble
  { 0, 1, 0, 0 },                         // CORBA::tk_wchar
  { 0, 1, 0, skip_long }                  // CORBA::tk_wstring
};

// Runtime initialization of the table above; note that this compiles
// down to a set of assignment statements, with the real work done by
// the C++ compiler when this file gets compiled.
//
// "Natural alignment" is a policy that the processor controls the
// alignment of data based on its type.  There's variation; some CPUs
// have a maximum alignment requirement of two or four bytes, others
// have some type-specific exceptions to the normal "alignment ==
// size" rule.
//
// "Fixed" alignment ignores data type when establishing alignment;
// not all processors support such policies, and those which do often
// pay a cost to do so (viz. RISC/CISC discussions).  The primary
// example of an OS family that chose "fixed" alignment is Microsoft's
// x86 systems, which normally align on one byte boundaries to promote
// data space efficiency.
//
// NOTE: typical PC compiler options let you specify other alignments,
// but none are "natural".  Also, they don't apply consistently to all
// data types.  Change the "one byte" assumption with extreme caution!
// And make sure all header files (e.g. generated by an IDL compiler)
// make sure that alignment of IDL-defined data types is consistent
// (one byte).

  enum TCKIND
  {
    tk_null               = 0,
    tk_void               = 1,
    tk_short              = 2,
    tk_long               = 3,
    tk_ushort             = 4,
    tk_ulong              = 5,
    tk_float              = 6,
    tk_double             = 7,
    tk_boolean            = 8,
    tk_char               = 9,
    tk_octet              = 10,
    tk_any                = 11,
    tk_TypeCode           = 12,
    tk_Principal          = 13,
    tk_objref             = 14,
    tk_struct             = 15,
    tk_union              = 16,
    tk_enum               = 17,
    tk_string             = 18,
    tk_sequence           = 19,
    tk_array              = 20,
    tk_alias              = 21,           // 94-11-7
    tk_except             = 22,           // 94-11-7

    // these five are OMG-IDL data type extensions
    tk_longlong           = 23,           // 94-9-32 Appendix A (+ 2)
    tk_ulonglong          = 24,           // 94-9-32 Appendix A (+ 2)
    tk_longdouble         = 25,           // 94-9-32 Appendix A (+ 2)
    tk_wchar              = 26,           // 94-9-32 Appendix A (+ 2)
    tk_wstring            = 27,           // 94-9-32 Appendix A (+ 2)

    // This symbol is not defined by CORBA 2.0.  It's used to speed up
    // dispatch based on TCKind values, and lets many important ones
    // just be table lookups.  It must always be the last enum value!!

    TC_KIND_COUNT
  };

#if defined (TAO_HAS_FIXED_BYTE_ALIGNMENT)
  // Have a bogus one
  #define declare_entry(x,t) struct align_struct_ ## t { }

  #define setup_entry(x,t) \
    { \
      TAO_IIOP_Interpreter::table_ [t].size_ = sizeof (x); \
      TAO_IIOP_Interpreter::table_ [t].alignment_ = 1; \
    }
#else  /* ! TAO_HAS_FIXED_BYTE_ALIGNMENT */
  // unix, ACE_WIN32, VXWORKS, __Lynx__, at least
  #define declare_entry(x,t) \
    struct align_struct_ ## t \
    { \
      x one; \
      char dummy [TAO_MAXIMUM_NATIVE_TYPE_SIZE + 1 - sizeof(x)]; \
      x two; \
    }

  #define setup_entry(x,t) \
    { \
      align_struct_ ## t align; \
      TAO_IIOP_Interpreter::table_ [t].size_ = sizeof (x); \
      TAO_IIOP_Interpreter::table_ [t].alignment_ = \
      (char *) &align.two - (char *) &align.one - TAO_MAXIMUM_NATIVE_TYPE_SIZE; \
    }
#endif /* ! TAO_HAS_FIXED_BYTE_ALIGNMENT */

// Fills in fixed size and alignment values.

declare_entry (CORBA::Short, tk_short);
declare_entry (CORBA::Long, tk_long);
declare_entry (CORBA::UShort, tk_ushort);
declare_entry (CORBA::ULong, tk_ulong);

declare_entry (CORBA::Float, tk_float);
declare_entry (CORBA::Double, tk_double);

declare_entry (CORBA::Boolean, tk_boolean);
declare_entry (CORBA::Char, tk_char);
declare_entry (CORBA::Octet, tk_octet);
declare_entry (CORBA::Any, tk_any);

declare_entry (CORBA::TypeCode_ptr, tk_TypeCode);
declare_entry (CORBA::Principal_ptr, tk_Principal);
declare_entry (CORBA::Object_ptr, tk_objref);

declare_entry (CORBA::String, tk_string);
declare_entry (TAO_opaque, tk_sequence);

declare_entry (CORBA::LongLong, tk_longlong);
declare_entry (CORBA::ULongLong, tk_ulonglong);
declare_entry (CORBA::LongDouble, tk_longdouble);
declare_entry (CORBA::WChar, tk_wchar);
declare_entry (CORBA::WString, tk_wstring);

void
TAO_IIOP_Interpreter::init_table (void)
{
  setup_entry (CORBA::Short, tk_short);
  setup_entry (CORBA::Long, tk_long);
  setup_entry (CORBA::UShort, tk_ushort);
  setup_entry (CORBA::ULong, tk_ulong);

  setup_entry (CORBA::Float, tk_float);
  setup_entry (CORBA::Double, tk_double);

  setup_entry (CORBA::Boolean, tk_boolean);
  setup_entry (CORBA::Char, tk_char);
  setup_entry (CORBA::Octet, tk_octet);
  setup_entry (CORBA::Any, tk_any);

  setup_entry (CORBA::TypeCode_ptr, tk_TypeCode);
  setup_entry (CORBA::Principal_ptr, tk_Principal);
  setup_entry (CORBA::Object_ptr, tk_objref);

  enum generic_enum {a, b, c, d};

  // XXX workaround for G++ 2.6.3 bug
  // setup_entry (generic_enum, CORBA::tk_enum);
  TAO_IIOP_Interpreter::table_ [CORBA::tk_enum].size_ =
    sizeof (generic_enum);
  TAO_IIOP_Interpreter::table_ [CORBA::tk_enum].alignment_ =
    sizeof (generic_enum);

  setup_entry (CORBA::String, tk_string);
  setup_entry (TAO_opaque, tk_sequence);

  setup_entry (CORBA::LongLong, tk_longlong);
  setup_entry (CORBA::ULongLong, tk_ulonglong);
  setup_entry (CORBA::LongDouble, tk_longdouble);
  setup_entry (CORBA::WChar, tk_wchar);
  setup_entry (CORBA::WString, tk_wstring);
}

#undef  setup

CORBA::Boolean
TAO_IIOP_Interpreter::skip_encapsulation (TAO_InputCDR *stream)
{
  return stream->skip_string ();
}

CORBA::Boolean
TAO_IIOP_Interpreter::skip_long (TAO_InputCDR *stream)
{
  CORBA::ULong  scratch;

  return stream->read_ulong (scratch);
}

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
// XXX explore splitting apart returning the size/alignment data and
// the TypeCode initialization; union traversal would benefit a bit,
// but it would need more than that to make it as speedy as struct
// traversal.

size_t
TAO_IIOP_Interpreter::calc_nested_size_and_alignment_i (CORBA::TypeCode_ptr tc,
				       TAO_InputCDR* stream,	
				       CORBA::TCKind kind,
				       size_t &alignment,
				       CORBA::Environment &env)
{
  CORBA::ULong temp;
  // Just a temporary to retrieve CORBA::TCKind variables as ULong's 

  // Check for illegal TCKind enum values ... out of range, or which
  // represent data values that can't be nested.  (Some can't even
  // exist freestanding!)

  if (kind >= CORBA::TC_KIND_COUNT
      || kind <= CORBA::tk_void
      || kind == CORBA::tk_except)
    {
      env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      return 0;
    }

  // Use attribute calculator routine if it exists; these are needed
  // only for variable-sized data types, with encapsulated parameter
  // lists that affect the size and alignment of "top level" memory
  // needed to hold an instance of this type.

  if (TAO_IIOP_Interpreter::table_[kind].calc_ != 0)
    {
      assert (TAO_IIOP_Interpreter::table_[kind].size_ == 0);

      // Pull encapsulation length out of the stream.
      if (stream->read_ulong (temp) == CORBA::B_FALSE)
        {
          env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
          return 0;
        }

      // Initialize the TypeCode if requested
      if (tc)
        {
          tc->kind_ = kind;
          tc->buffer_ = stream->rd_ptr ();
          tc->length_ = temp;
        }

      // Set up a separate stream for the parameters; it may easily
      // have a different byte order, and this is as simple a way as
      // any to ensure correctness.  Then use the calculator routine
      // to calculate size and alignment.

      assert (temp <= UINT_MAX);
      CORBA::ULong byte_order;
      if (stream->read_ulong (byte_order) != CORBA::B_TRUE)
	{
          env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
          return 0;
	}

      TAO_InputCDR nested (*stream, temp - 4);

      if (nested.good_bit () == 0)
        {
          env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
          return 0;
        }

      size_t size = TAO_IIOP_Interpreter::table_[kind].calc_ (&nested,
							      alignment,
							      env);
      if (env.exception () != 0)
	{
	  return 0;
	}

      // Check for garbage at end of parameter lists, or other cases
      // where parameters and the size allocated to them don't jive.

      stream->skip_bytes (temp - 4);
      if (stream->rd_ptr () != nested.rd_ptr ())
        {
          env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
          return 0;
        }
      return size;
    }
  assert (TAO_IIOP_Interpreter::table_[kind].size_ != 0);

  // Reinitialize the TypeCode if requested; this consumes any
  // TypeCode parameters in the stream.  They only exist for TCKind
  // values that have parameters, but which represent fixed-size data
  // types in the binary representation: CORBA::tk_string, CORBA::tk_wstring,
  // CORBA::tk_objref, CORBA::tk_enum, and CORBA::tk_sequence.

  if (tc)
    {
      CORBA::ULong len;

      tc->kind_ = kind;
      switch (kind)
        {
        default:
          assert (TAO_IIOP_Interpreter::table_[kind].skipper_ == 0);
          break;

        case CORBA::tk_string:
        case CORBA::tk_wstring:
          if (stream->read_ulong (len) == CORBA::B_FALSE)
            {
              env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
              return 0;
            }
          tc->length_ = len;
          break;

        case CORBA::tk_enum:
        case CORBA::tk_objref:
        case CORBA::tk_sequence:
          if (stream->read_ulong (len) == CORBA::B_FALSE)
            {
              env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
              return 0;
            }
          tc->length_ = len;

          assert (len < UINT_MAX);
          tc->buffer_ = stream->rd_ptr ();
          stream->skip_bytes (len);
          break;
        }

      // Otherwise, consume any parameters without stuffing them into
      // a temporary TypeCode.
    }
  else if (TAO_IIOP_Interpreter::table_[kind].skipper_ != 0
           && TAO_IIOP_Interpreter::table_[kind].skipper_ (stream) == CORBA::B_FALSE)
    {
      env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      return 0;
    }

  // Return statically known values.
  alignment = TAO_IIOP_Interpreter::table_[kind].alignment_;
  return TAO_IIOP_Interpreter::table_[kind].size_;
}

size_t
TAO_IIOP_Interpreter::calc_nested_size_and_alignment (CORBA::TypeCode_ptr tc,
                                            TAO_InputCDR *stream,
                                            size_t &alignment,
                                            CORBA::Environment &env)
{
  // Get the "kind" ... if this is an indirection, this is a guess
  // which will soon be updated.
  CORBA::ULong temp;
  if (stream->read_ulong (temp) == CORBA::B_FALSE)
    {
      env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      return 0;
    }

  env.clear ();

  CORBA::TCKind kind = (CORBA::TCKind) temp;

  if (kind != ~0)
    {
      return TAO_IIOP_Interpreter::calc_nested_size_and_alignment_i
	(tc,
	 stream,
	 kind,
	 alignment,
	 env);
    }

  // Get indirection, sanity check it, set up new stream pointing
  // there.
  //
  // XXX access to "real" size limit for this typecode and use it
  // to check for errors before indirect and to limit the new
  // stream's length.  ULONG_MAX is too much!

  CORBA::Long offset;
  if (!stream->read_long (offset)
      || offset >= -8
      || ((-offset) & 0x03) != 0)
    {
      env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      return 0;
    }
  
  // Notice how we change the sign of the offset to estimate the
  // maximum size.
  TAO_InputCDR indirected_stream (*stream, -offset, offset);

  // Fetch indirected-to TCKind.
  if (!indirected_stream.read_ulong (temp))
    {
      env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      return 0;
    }
  kind = (CORBA::TCKind) temp;

  return TAO_IIOP_Interpreter::calc_nested_size_and_alignment_i (tc,
						&indirected_stream,
						kind,
						alignment,
						env);
}

// Given typecode bytes for a structure (or exception), figure out its
// alignment and size; return size, alignment is an 'out' parameter.
// Only "CORBA::tk_struct" (or "CORBA::tk_except") has been taken out of the stream
// parameter holding the bytes.
//
// We use a one-pass algorithm, calculating size and inter-element
// padding while recording the strongest alignment restriction.  Then
// we correct the size to account for tail-padding.
//
// This routine recognizes that exceptions are just structs with some
// additional information.  Different environments may differ in what
// that additional information is, so this routine may need to be
// taught about compiler-specific representation of that additional
// "RTTI" data.

size_t
TAO_IIOP_Interpreter::calc_struct_and_except_attributes (TAO_InputCDR *stream,
                                               size_t &alignment,
                                               CORBA::Boolean is_exception,
                                               CORBA::Environment &env)
{
  CORBA::ULong  members;
  size_t size;

  // Exceptions are like structs, with key additions (all of which
  // might need to be be applied to structures!): vtable, typecode,
  // and refcount.  The size must include these "hidden" members.
  //
  // NOTE: in environments with "true" C++ exceptions, there may need
  // to be a slot for additional "RTTI" information; maybe it is part
  // of the vtable, or maybe not.  Or, that information (needed to
  // determine which 'catch' clauses apply) may only be provided by
  // the compiler to the runtime support for the "throw" statement.

  if (is_exception)
    {
      size = sizeof (CORBA::Exception);
      alignment = TAO_IIOP_Interpreter::table_[CORBA::tk_TypeCode].alignment_;
    }
  else
    {
      alignment = 1;
      size = 0;
    }

  // skip rest of header (type ID and name) and collect the number of
  // struct members

  if (!stream->skip_string ()
      || !stream->skip_string ()
      || !stream->read_ulong (members))
    {
      env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      return 0;
    }

  // iterate over all the members, skipping their names and looking
  // only at type data.

  for ( ; members != 0; members--) {
    size_t member_size;
    size_t member_alignment;

    // Skip name of the member.
    if (!stream->skip_string ())
      {
        env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
        return 0;
      }

    // Get size and alignment of the member, accounting for
    // indirection and the various kinds of parameter encoding.

    member_size = calc_nested_size_and_alignment (0,
                                                  stream,
                                                  member_alignment,
                                                  env);
    if (env.exception () != 0)
      return 0;

    // Round up the struct size to handle member alignment (by adding
    // internal padding), then update the current size to handle the
    // member's size.

    size = (size_t) align_binary (size, member_alignment);
    size += member_size;

    // Finally update the overall structure alignment requirement, if
    // this element must be more strongly aligned.

    if (member_alignment > alignment)
      alignment = member_alignment;
  };

  // Round up the structure size to match its overall alignment.  This
  // adds tail padding, if needed.
  return (size_t) align_binary (size, alignment);
}

// Calculate size and alignment for a structure.

size_t
TAO_IIOP_Interpreter::calc_struct_attributes (TAO_InputCDR *stream,
                                    size_t &alignment,
                                    CORBA::Environment &env)
{
  return calc_struct_and_except_attributes (stream,
                                            alignment,
                                            CORBA::B_FALSE,
                                            env);
}

// Calculate size and alignment for an exception.

size_t
TAO_IIOP_Interpreter::calc_exception_attributes (TAO_InputCDR *stream,
                                       size_t &alignment,
                                       CORBA::Environment &env)
{
  return calc_struct_and_except_attributes (stream,
                                            alignment,
                                            CORBA::B_TRUE,
                                            env);
}

// Calculate and return sizes for both parts of a union, as needed by
// other code.  Return value is the overall size.  The padded size of
// the discriminant is needed to traverse the two values separately.
// Unfortunately that is not quite practical to do with a single pass
// over the typecode: the inter-element padding changes depending on
// the strictest alignment required by _any_ arm of the union.

size_t
TAO_IIOP_Interpreter::calc_key_union_attributes (TAO_InputCDR *stream,
                                                 size_t &overall_alignment,
                                                 size_t &discrim_size_with_pad,
                                                 CORBA::Environment &env)
{
  CORBA::ULong members;
  CORBA::ULong temp;
  size_t discrim_size;
  size_t value_alignment;
  size_t value_size;

  overall_alignment = value_alignment = 1;
  value_size = discrim_size_with_pad = 0;

  // Skip initial optional members (type ID and name).

  if (!stream->skip_string ()                   // type ID
      || !stream->skip_string ())
    {   // typedef name
      env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      return 0;
    }

  // Calculate discriminant size and alignment: it's the first member
  // of the "struct" representing the union.  We detect illegal
  // discriminant kinds a bit later.

  CORBA::TypeCode discrim_tc (CORBA::tk_void);

  discrim_size = calc_nested_size_and_alignment (&discrim_tc,
                                                 stream,
                                                 overall_alignment,
                                                 env);
  if (env.exception () != 0)
    return 0;

  // skip "default used" indicator, and save "member count"

  if (!stream->read_ulong (temp)                 // default used
      || !stream->read_ulong (members))
    {   // member count
      env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      return 0;
    }

  // iterate over the tuples for all the members; all we care about is
  // their types, which can affect either alignment or padding
  // requirement for the union part of the construct.

  for ( ; members != 0; members--) {
    size_t member_size, member_alignment;

    // Skip member label; its size varies with discriminant type, but
    // here we don't care about its content.  This is where illegal
    // discriminant kinds are detected.
    //
    // NOTE:  This modifies 94-9-32 Appendix A to stipulate that
    // "long long" values are not legal as discriminants.

    switch (discrim_tc.kind_)
      {
      case CORBA::tk_short:
      case CORBA::tk_ushort:
      case CORBA::tk_wchar:
        {
          CORBA::Short s;

          if (!stream->read_short (s))
            {
              env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
              return 0;
            }
        }
      break;

      case CORBA::tk_long:
      case CORBA::tk_ulong:
      case CORBA::tk_enum:
        {
          CORBA::Long l;

          if (!stream->read_long (l))
            {
              env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
              return 0;
            }
        }
      break;

      case CORBA::tk_boolean:
      case CORBA::tk_char:
        {
          CORBA::Char c;

          if (!stream->read_char (c))
            {
              env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
              return 0;
            }
        }
      break;

      default:
        env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
        return 0;
      }

    // We also don't care about any member name.

    if (!stream->skip_string ())
      {
        env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
        return 0;
      }

    // Get the member size and alignment.

    member_size = calc_nested_size_and_alignment (0,
                                                  stream,
                                                  member_alignment,
                                                  env);
    if (env.exception () != 0)
      return 0;

    // Save the largest member and alignment.  They don't need to be
    // changed in sync -- e.g. "long double" size is larger than its
    // alignment restriction on SPARC, x86, and some m68k platforms.
    if (member_size > value_size)
      value_size = member_size;
    if (member_alignment > value_alignment)
      value_alignment = member_alignment;
  }

  // Round up the discriminator's size to include padding it needs in
  // order to be followed by the value.
  discrim_size_with_pad = (size_t) align_binary (discrim_size,
                                                 value_alignment);

  // Now calculate the overall size of the structure, which is the
  // discriminator, inter-element padding, value, and tail padding.
  // We know all of those except tail padding, which is a function of
  // the overall alignment.  (Ensures that arrays of these can be
  // safely allocated and accessed!)

  if (value_alignment > overall_alignment)
    overall_alignment = value_alignment;

  return (size_t) align_binary (discrim_size_with_pad + value_size,
                                overall_alignment);
}

// Calculate size and alignment for a CORBA discriminated union.
//
// Note that this is really a two-element structure.  The first
// element is the discriminator; the second is the value.  All normal
// structure padding/alignment rules apply.  In particular, all arms
// of the union have the same initial address (adequately aligned for
// any of the members).

size_t
TAO_IIOP_Interpreter::calc_union_attributes (TAO_InputCDR *stream,
                                   size_t &alignment,
                                   CORBA::Environment &env)
{
  size_t scratch;

  return calc_key_union_attributes (stream, alignment, scratch, env);
}

// Calculate size and alignment for a typedeffed type.

size_t
TAO_IIOP_Interpreter::calc_alias_attributes (TAO_InputCDR *stream,
                                   size_t &alignment,
                                   CORBA::Environment &env)
{
  // Skip type ID and name in the parameter stream

  if (!stream->skip_string ()                   // type ID
      || !stream->skip_string ())               // typedef name
    {
      env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      return 0;
    }

  // The typedef is identical to the type for which it stands.
  return calc_nested_size_and_alignment (0, stream, alignment, env);
}

// Calculate size and alignment of an array.  (All such arrays are
// described as single dimensional, even though the IDL definition may
// specify a multidimensional array ... such arrays are treated as
// nested single dimensional arrays.)

size_t
TAO_IIOP_Interpreter::calc_array_attributes (TAO_InputCDR *stream,
                                   size_t &alignment,
                                   CORBA::Environment &env)
{
  size_t member_size;
  CORBA::ULong member_count;

  // get size and alignment of the array member

  member_size = calc_nested_size_and_alignment (0, stream, alignment, env);
  if (env.exception () != 0)
    return 0;

  // Get and check count of members.

  if (stream->read_ulong (member_count) == CORBA::B_FALSE
      || member_count > UINT_MAX)
    {
      env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      return 0;
    }

  // Array size is a function only of member number and count
  return member_size * (size_t) member_count;
}

// Cast the discriminant values to the right type and compare them.

CORBA::Boolean
TAO_IIOP_Interpreter::match_value (CORBA::TCKind kind,
                         TAO_InputCDR *tc_stream,
                         const void *value,
                         CORBA::Environment &env)
{
  CORBA::Boolean retval = CORBA::B_FALSE;

  switch (kind)
    {
    case CORBA::tk_short:
    case CORBA::tk_ushort:
      {
        CORBA::UShort discrim;

        if (tc_stream->read_ushort (discrim) != CORBA::B_FALSE)
          retval = (discrim == *(CORBA::UShort *)value);
        else
          env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      }
    break;

    case CORBA::tk_long:
    case CORBA::tk_ulong:
      {
        CORBA::ULong discrim;

        if (tc_stream->read_ulong (discrim) != CORBA::B_FALSE)
          retval = (discrim == *(CORBA::ULong *)value);
        else
          env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      }
    break;

    case CORBA::tk_enum:
      {
        CORBA::ULong discrim;

        if (tc_stream->read_ulong (discrim) != CORBA::B_FALSE)
          retval = (discrim == *(unsigned *)value);
        else
          env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      }
    break;

    case CORBA::tk_boolean:
      {
        CORBA::Boolean discrim;

        if (tc_stream->read_boolean (discrim) != CORBA::B_FALSE)
          retval = (discrim == *(CORBA::Boolean *)value);
        else
          env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      }
    break;

    case CORBA::tk_char:
      {
        CORBA::Char discrim;

        if (tc_stream->read_char (discrim) != CORBA::B_FALSE)
          retval = (discrim == *(CORBA::Char *)value);
        else
          env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      }
    break;

    case CORBA::tk_wchar:
      {
        CORBA::WChar discrim;

        if (tc_stream->read_wchar (discrim) != CORBA::B_FALSE)
          retval = (discrim == *(CORBA::WChar *)value);
        else
          env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
      }
    break;

    default:
      env.exception (new CORBA::BAD_TYPECODE (CORBA::COMPLETED_NO));
    }

  return retval;
}
