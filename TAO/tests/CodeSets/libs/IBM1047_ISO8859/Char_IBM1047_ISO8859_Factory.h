// -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests/CodeSets/libs/IBM1047_ISO8859
//
// = FILENAME
//    Char_IBM1047_ISO8859_Factory.h
//
// = DESCRIPTION
//    A tempate instantiation of the codeset translator factory from TAO. This
//    one loads a modified version of ACE's IBM1047 (EBCDIC) to ISO8859 (ASCII)
//    translator.
//
// = AUTHORS
//      Phil Mesnier <mesnier_p@ociweb.com>
//
// ============================================================================

#ifndef CHAR_IBM1047_ISO8859_FACTORY_H
#define CHAR_IBM1047_ISO8859_FACTORY_H

#include /**/ "ace/pre.h"
#include "ace/Service_Config.h"
#include "tao/Codeset_Translator_Factory.h"

#include "IBM1047_ISO8859_export.h"
#include "Char_IBM1047_ISO8859_Translator.h"

typedef IBM1047_ISO8859_Export TAO_Codeset_Translator_Factory_T<IBM1047_ISO8859> Char_IBM1047_ISO8859_Factory;

ACE_STATIC_SVC_DECLARE_EXPORT (IBM1047_ISO8859, Char_IBM1047_ISO8859_Factory)
ACE_FACTORY_DECLARE (IBM1047_ISO8859, Char_IBM1047_ISO8859_Factory)

#include /**/ "ace/post.h"
#endif /* TAO_CHAR_IBM1047_ISO8859_FACTORY_H */

