// file      : CIDLC/Literals.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#include "Literals.hpp"

namespace StringLiterals
{
  char const* const COPYRIGHT =
    "// $I" "d$\n"
    "//\n"
    "// ****              Code generated by the                 ****\n"
    "// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****\n"
    "// CIAO has been developed by:\n"
    "//       Center for Distributed Object Computing\n"
    "//       Washington University\n"
    "//       St. Louis, MO\n"
    "//       USA\n"
    "//       http://www.cs.wustl.edu/~schmidt/doc-center.html\n"
    "// CIDL Compiler has been developed by:\n"
    "//       Institute for Software Integrated Systems\n"
    "//       Vanderbilt University\n"
    "//       Nashville, TN\n"
    "//       USA\n"
    "//       http://www.isis.vanderbilt.edu/\n"
    "//\n"
    "// Information about CIAO is available at:\n"
    "//    http://www.dre.vanderbilt.edu/CIAO"
    "\n\n";

  char const* const STRS[LIT_SIZE] =
  {
    // Common CORBA and all Components exceptions.
    "ACE_THROW_SPEC (( ::CORBA::SystemException))",       // EXCP_SNGL
    "ACE_THROW_SPEC ((",                                  // EXCP_START
    "::CORBA::SystemException",                           // EXCP_SYS
    "::CORBA::BAD_PARAM ()",                              // EXCP_BP
    "::Components::IllegalState",                         // EXCP_IS
    "::Components::AlreadyConnected",                     // EXCP_AC
    "::Components::InvalidConnection",                    // EXCP_IC
    "::Components::NoConnection",                         // EXCP_NC
    "::Components::ExceededConnectionLimit",              // EXCP_ECL
    "::Components::InvalidName",                          // EXCP_IN
    "::Components::RemoveFailure",                        // EXCP_RF
    "::Components::NoKeyAvailable",                       // EXCP_NKA
    "::Components::InvalidConfiguration",                 // EXCP_ICF
    "::Components::CookieRequired",                       // EXCP_CR
    "::Components::BadEventType",                         // EXCP_BET
    "::Components::CCMException",                         // EXCP_CE

    // Commonly used Components module members.
    "::Components::Cookie",                               // COMP_CK
    "::Components::NameList & /* names */",               // COMP_NAMES
    "::Components::EventConsumerBase",                    // COMP_ECB
    "::Components::EnterpriseComponent",                  // COMP_EC
    "::Components::SessionContext",                       // COMP_SC
    "::Components::ConsumerDescriptions",                 // COMP_CD
    "::Components::ReceptacleDescriptions",               // COMP_RD
    "::Components::PublisherDescriptions",                // COMP_PD
    "::Components::EmitterDescriptions",                  // COMP_ED

    // This could change - don't want it scattered all over.
    "namespace CIDL_",                                    // CIDL_NS
    "CIAO_FACET",                                         // FACET_PREFIX

    // Labels for things stored in a SyntaxTree node's Context.
    "CIDLC::RepositoryIdGenerator::TypeId",               // TYPE_ID
    "CIDLC::RepositoryIdGenerator::TypePrefix",           // TYPE_PREFIX
    "CIDLC::RepositoryIdGenerator::RepoId",               // REPO_ID

    "// Your code here.",                                 // YCH
    "//==================================================================", // SEP

    "variable-size",                                      // VAR_SIZE
    "_ciao_extract_val",                                  // EXTRACT
    "_ciao_extract_tmp",                                  // EXTRACT_TMP
    "ACE_UNUSED_ARG",                                     // ACE_UA
    "throw",                                              // ACE_TH
    "ACE_THROW_RETURN"                                    // ACE_TR
  };
}

