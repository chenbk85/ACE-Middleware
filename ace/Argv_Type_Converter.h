// -*- C++ -*-
//=============================================================================
/**
 *  @file    Argv_Type_Converter.h
 *
 *  $Id$
 *
 *  @author Si Mong Park <spark@ociweb.com>
 */
//=============================================================================

#ifndef ACE_Argv_Type_Converter_h
#define ACE_Argv_Type_Converter_h

#include "ace/pre.h"
#include "ace/OS.h"


/**
 * @class ACE_Argv_Type_Converter
 *
 * @brief To convert 'char' input/command line parameter to 'wchar_t'.
 *
 * This class is to convert 'char' type command line paramter to
 * wide-character (wchar_t) format and stores the copy of it.
 * This is useful for all classes that use 'char**' argv but cannot
 * be converted into 'ACE_TCHAR**' version.
 * Note that the converted data will be lost upon destruction, so
 * classes should use this class as their data member.
 */
class ACE_Export ACE_Argv_Type_Converter
{
public:
    /**
     * Ctor accepts integer argc and 'char' type argv.
     */
    ACE_Argv_Type_Converter(int& argc, char** argv);

#if defined (ACE_USES_WCHAR)
    /**
     * Ctor accepts integer argc and 'wchar_t' type argv.
     */
    ACE_Argv_Type_Converter(int& argc, wchar_t** argv);
#endif  // ACE_USES_WCHAR

    /**
     * Dtor will delete all stored data.
     */
    ~ACE_Argv_Type_Converter(void);

    /**
     * Returns the pointer of converted command line.
     */
    ACE_TCHAR** get_TCHAR_argv(void);

    /**
     * Returns the pointer of ASCII (char) command line.
     */
    char** get_ASCII_argv(void);

    /**
     * Returns the number of sub paramters (argc).
     */
    int& get_argc(void);

private:
    /**
     * Copy Ctor should not be used.
     */
    ACE_Argv_Type_Converter(ACE_Argv_Type_Converter&);

    /**
     * '=' operator should not be used.
     */
    ACE_Argv_Type_Converter operator = (ACE_Argv_Type_Converter&);

#if defined (ACE_USES_WCHAR)
    /**
     * Perform common initialization for two Ctor's.
     */
    void initialize();

    /**
     * Align all entries in the char type argv list with wchar_t type argv list.
     */
    void align_char_with_wchar();

    /**
     * Align all entries in the wchar_t type argv list with char type argv list.
     */
    void align_wchar_with_char();

    /**
     * Clean up removed (comsumed) argv entries and reset the pass flags.
     */
    void cleanup();
#endif  // ACE_USES_WCHAR

    /**
     * Original number of input paramter, same as 'argc'.
     */
    int& saved_argc_;

    /**
     * Data member pointer that contains converted argv in ACE_ANTI_TCHAR.
     */
    char** char_argv_;

#if defined (ACE_USES_WCHAR)
    /**
     * Data member pointer that contains converted argv in ACE_TCHAR.
     */
    wchar_t** wchar_argv_;

    /**
     * argc value before any argv has been passed.
     */
    int before_pass_argc_;

    /**
     * FALSE represents original argv passed in is char, and TRUE represents wchar_t.
     * Boolean type could be used for this, but used integer for old compiler issue.
     */
    const bool original_type_;

    /**
     * TRUE indicates wchar_t type argv has been passed.
     */
    bool wchar_passed_;

    /**
     * TRUE indicates char type argv has been passed.
     */
    bool char_passed_;
#endif  // ACE_USES_WCHAR
};

#if defined (__ACE_INLINE__)
#include "ace/Argv_Type_Converter.inl"
#endif  // __ACE_INLINE__

#include "ace/post.h"

#endif  // ACE_Argv_Type_Converter_h
