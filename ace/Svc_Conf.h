/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Svc_Conf.h
 *
 *  $Id$
 *
 *  @author Doug Schmidt
 */
//=============================================================================


#ifndef ACE_SVC_CONF_H
#define ACE_SVC_CONF_H
#include "ace/pre.h"

// Globally visible macros, type decls, and extern var decls for
// Service Configurator utility.

#include "ace/Obstack.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Config.h"
#include "ace/Parse_Node.h"

#if defined (DEBUGGING)
#if defined (ACE_YY_DECL)
#undef ACE_YY_DECL
#endif /* ACE_YY_DECL */
#define ACE_YY_DECL extern "C" char *ace_yylex (void)
#else
#define ACE_YY_DECL extern "C" int ace_yylex (void)
#endif /* DEBUGGING */

void ace_yyrestart (FILE *);
// Restart input file parsing

void ace_yy_delete_parse_buffer (void);
// Delete the lexer's parse buffer

int ace_yyparse (void);
// Performs the parsing

ACE_YY_DECL;
// Performs the lexical analysis

extern FILE *ace_yyin;
// Name of input stream
// note: if using wide charcaters (unicode) for interactive or string
// based input it may be worth checking this all works fine getc is
// not portable in wide char versions, needs more work
#define ACE_YY_INPUT(buf,result,max_size) \
  if (ace_yydirective != 0) \
  { \
    int c = *ace_yydirective++; \
    result = c == '\0' ? 0 : 1; \
    buf[0] = (ACE_TCHAR) c; \
  } \
  else if ( ace_yy_current_buffer->ace_yy_is_interactive ) \
  { \
    int c = getc( ace_yyin ); \
    result = c == EOF ? 0 : 1; \
    buf[0] = (ACE_TCHAR) c; \
  } \
  else if ( ((result = fread( buf, sizeof (ACE_TCHAR), max_size, ace_yyin )) == 0) \
    && ferror( ace_yyin ) ) \
    ACE_YY_FATAL_ERROR( ACE_LIB_TEXT ("input in flex scanner failed") );

void ace_yyerror (const ACE_TCHAR *);
// Error handling routine required by YACC or BISON

extern int ace_yylineno;
// Keeps track of the current line number for error-handling routine

extern int ace_yyerrno;
// Keeps track of the number of errors encountered so far

extern const ACE_TCHAR *ace_yydirective;
// Used to parse service configurator directives from a string rather
// than from a svc.conf file.

extern ACE_TCHAR *ace_yytext;
// Holds the lexeme for the current token

extern int ace_yyleng;
// Holds the length of the lexeme for the current token

extern ACE_Obstack_T<ACE_TCHAR> *ace_obstack;
// Efficient memory allocation technique

extern ACE_Service_Type_Impl *
    ace_create_service_type (const ACE_TCHAR *, int,
                             void *, unsigned int,
                             ACE_Service_Object_Exterminator = 0);
// Factory that creates a new ACE_Service_Type_Impl.

typedef union
{
  int type_;
  ACE_Location_Node *location_node_;
  ACE_Parse_Node *parse_node_;
  ACE_Static_Node *static_node_;
  ACE_Service_Type *svc_record_;
  ACE_TCHAR *ident_;
} ACE_YYSTYPE;
extern ACE_YYSTYPE ace_yylval;
#include "ace/post.h"
#endif /* ACE_SVC_CONF_H */
