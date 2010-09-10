// $Id$

// ============================================================================
//
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_helper.cpp
//
// = DESCRIPTION
//   Provides helper classes to print generated code to the output
//
// = AUTHOR
//    Aniruddha Gokhale
//
//    Improvements by Carlos O'Ryan
//
// ============================================================================

#include "be_helper.h"
#include "idl_defines.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"
#include "ace/os_include/os_ctype.h"

static const char copyright[] =
" <--\n"
" -*- XML -*-\n"
"\n"
" $I" "d$\n\n"
" ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****\n"
" TAO and the TAO IDL Compiler have been developed by:\n"
"       Center for Distributed Object Computing\n"
"       Washington University\n"
"       St. Louis, MO\n"
"       USA\n"
"       http:www.cs.wustl.edu/~schmidt/doc-center.html\n"
" and\n"
"       Distributed Object Computing Laboratory\n"
"       University of California at Irvine\n"
"       Irvine, CA\n"
"       USA\n"
"       http:doc.ece.uci.edu/\n"
" and\n"
"       Institute for Software Integrated Systems\n"
"       Vanderbilt University\n"
"       Nashville, TN\n"
"       USA\n"
"       http:www.isis.vanderbilt.edu/\n"
"\n"
" Information about TAO is available at:\n"
"     http:www.cs.wustl.edu/~schmidt/TAO.html\n"
"-->";

TAO_NL::TAO_NL (void)
{
}

TAO_INDENT::TAO_INDENT (int do_now)
  :  do_now_ (do_now)
{
}

TAO_UNINDENT::TAO_UNINDENT (int do_now)
  :  do_now_ (do_now)
{
}

const TAO_NL be_nl;
const TAO_INDENT be_idt;
const TAO_INDENT be_idt_nl (1);
const TAO_UNINDENT be_uidt;
const TAO_UNINDENT be_uidt_nl (1);

// Methods of the TAO_OutStream class.

TAO_OutStream::TAO_OutStream (void)
  : fp_ (0),
    indent_level_ (0)
{
}

TAO_OutStream::~TAO_OutStream (void)
{
  // Close the underlying I/O handle only if it exists.
  if (this->fp_ != 0)
    {
      ACE_OS::fclose (this->fp_);
      this->fp_ = 0;
    }

  indent_level_ = 0;
}

int
TAO_OutStream::open (const char *fname)
{
  if (fname != 0)
    {
      // File name exists, open an I/O file handle.
      this->fp_ = ACE_OS::fopen (fname, "w");

      if (this->fp_ != 0)
        {
          // Put the copyright notice.
          ACE_OS::fprintf (this->fp_,
                            "%s\n",
                            copyright);

          ACE_OS::fflush (this->fp_);

          return 0;
        }
      else
        {
          return -1;
        }
    }
  else
    {
      return -1;
    }
}

// Return the underlying lowlevel file pointer.
// indentation.
FILE *
TAO_OutStream::file (void)
{
  return this->fp_;
}

int
TAO_OutStream::incr_indent (unsigned short flag)
{
  indent_level_++;

  if (flag != 0)
    {
      return this->indent ();
    }
  else
    {
      // Do not indent output.
      return 0;
    }
}

// Indentation
int
TAO_OutStream::decr_indent (unsigned short flag)
{
  this->indent_level_--;
  // Just in case somebody gets "unindent happy".
  if (this->indent_level_ < 0)
    {
      // ACE_DEBUG ((LM_DEBUG, "negative indentation?\n"));
      this->indent_level_ = 0;
    }
  if (flag != 0)
    {
      return this->indent ();
    }
  else
    {
      // Do not indent output.
      return 0;
    }
}

int
TAO_OutStream::reset (void)
{
  this->indent_level_ = 0;
  return 0;
}

// Indented print.
int
TAO_OutStream::indent (void)
{
  // Based on the current indentation level, leave appropriate number of blank
  // spaces in the output.
  if (this->indent_level_ > 0)
    {
      for (int i = 0; i < this->indent_level_; i++)
        {
          ACE_OS::fprintf (this->fp_, "  ");
          ACE_OS::fflush (this->fp_);
        }
    }

  return 0;
}

int
TAO_OutStream::nl (void)
{
  ACE_OS::fprintf (this->fp_, "\n");
  this->indent ();
  return 0;
}

// Printf style variable argument print.
int
TAO_OutStream::print (const char *format, ...)
{
  int result = 0;
  va_list ap;
  va_start (ap, format);
  ACE_OSCALL (::vfprintf (this->fp_,
                          format,
                          ap),
              int,
              -1,
              result);

  ACE_OS::fflush (this->fp_);
  va_end (ap);

  return result;
}

void
TAO_OutStream::gen_ifndef_string (const char *fname,
                                  const char *prefix,
                                  const char *suffix)
{
  static char macro_name [NAMEBUFSIZE];

  ACE_OS::memset (macro_name,
                  '\0',
                  NAMEBUFSIZE);

  const char *extension = ACE_OS::strrchr (fname, '.');

  if (extension == 0)
    {
      // File seems to have no extension, so let us take the name
      // as it is.
      extension = fname;
    }

  ACE_OS::sprintf (macro_name, prefix);

  size_t offset = ACE_OS::strlen (prefix);

  // Convert letters in fname to upper case.
  for (int i = 0; i < (extension - fname); i++)
    {
      if (isalpha (fname [i]))
        {
          macro_name[i + offset] = (char) toupper (fname [i]);
        }
      else if (isdigit (fname [i]))
        {
          macro_name[i + offset] = fname[i];
        }
      else
        {
          macro_name[i + offset] = '_';
        }
    }

  ACE_OS::strcat (macro_name, suffix);

  // Generate the #ifndef ... #define statements.
  this->print ("#ifndef %s\n",
               macro_name);
  this->print ("#define %s",
               macro_name);
}

TAO_OutStream &
TAO_OutStream::operator<< (const char *str)
{
  ACE_OS::fprintf (this->fp_, "%s", str);
  ACE_OS::fflush (this->fp_);
  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::UShort num)
{
  ACE_OS::fprintf (this->fp_,
                   "%hu",
                   num);

  ACE_OS::fflush (this->fp_);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::Short num)
{
  ACE_OS::fprintf (this->fp_,
                   "%hd",
                   num);

  ACE_OS::fflush (this->fp_);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::ULong num)
{
  ACE_OS::fprintf (this->fp_,
                   "%lu",
                   (unsigned long) num);

  ACE_OS::fflush (this->fp_);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::Long num)
{
  ACE_OS::fprintf (this->fp_,
                   "%ld",
                   (long) num);

  ACE_OS::fflush (this->fp_);

  return *this;
}

#if defined (ACE_WIN64)
TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::ULongLong num)
{
  ACE_OS::fprintf (this->fp_,
                   ACE_UINT64_FORMAT_SPECIFIER,
                   num);

  ACE_OS::fflush (this->fp_);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::LongLong num)
{
  ACE_OS::fprintf (this->fp_,
                   ACE_INT64_FORMAT_SPECIFIER,
                   num);

  ACE_OS::fflush (this->fp_);

  return *this;
}
#endif /* ACE_WIN64 */

TAO_OutStream &
TAO_OutStream::operator<< (const unsigned long num)
{
  ACE_OS::fprintf (this->fp_,
                   "%lu",
                   num);

  ACE_OS::fflush (this->fp_);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const long num)
{
  ACE_OS::fprintf (this->fp_,
                   "%ld",
                   num);

  ACE_OS::fflush (this->fp_);

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const TAO_NL&)
{
  ACE_OS::fprintf (this->fp_ ,
                   "\n");
  this->indent ();

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const TAO_INDENT& i)
{
  this->incr_indent (0);

  if (i.do_now_)
    {
      this->nl ();
    }

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const TAO_UNINDENT& i)
{
  this->decr_indent (0);

  if (i.do_now_)
    {
      this->nl ();
    }

  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (Identifier *id)
{
  return this->print (id);
}

TAO_OutStream &
TAO_OutStream::operator<< (UTL_IdList *id)
{
  return this->print (id);
}

TAO_OutStream &
TAO_OutStream::operator<< (AST_Expression *expr)
{
  return this->print (expr);
}
