// file      : CIDLC/Literals.hpp
// author    : Jeff Parsons <j.parsons@vanderbilt.edu>
// cvs-id    : $Id$

#ifndef LITERALS_HPP
#define LITERALS_HPP

namespace StringLiterals
{
  static const char COPYRIGHT[] =
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
    "//    http://www.cs.wustl.edu/~nanbor/projects/CIAO-src/docs/index.html";

  static const char *STRS[] =
  {
    // ACE Environment portability macros.
    "ACE_ENV_ARG_DECL_WITH_DEFAULTS",                     // ENV_HDR
    "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS",              // ENV_SNGL_HDR
    "ACE_ENV_ARG_DECL",                                   // ENV_SRC
    "ACE_ENV_SINGLE_ARG_DECL",                            // ENV_SNGL_SRC
    "ACE_ENV_ARG_PARAMETER",                              // ENV_ARG
    "ACE_ENV_SINGLE_ARG_PARAMETER",                       // ENV_SNGL_ARG

    // Common CORBA and all Components exceptions.
    "ACE_THROW_SPEC ((CORBA::SystemException))",          // EXCP_SNGL
    "ACE_THROW_SPEC ((",                                  // EXCP_START
    "::CORBA::SystemException",                           // EXCP_SYS
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

    // Commonly used Components module members.
    "::Components::Cookie",                               // COMP_CK
    "::Components::NameList &names",                      // COMP_NAMES
    "::Components::EventConsumerBase",                    // COMP_ECB

    // This could change - don't want it scattered all over.
    "namespace CIAO_GLUE",                                // GLUE_NS

    // Commonly used base class.
    "public virtual PortableServer::RefCountServantBase", // INH_RCSB
    
    // Labels for things stored in a SyntaxTree node's Context.
    "CIDLC::RepositoryIdGenerator::TypeId",               // TYPE_ID
    "CIDLC::RepositoryIdGenerator::TypePrefix",           // TYPE_PREFIX
    "CIDLC::RepositoryIdGenerator::RepoId",               // REPO_ID
    
    "variable-size"                                       // VAR_SIZE
  };

  // Index into the strings above.
  enum
  {
    ENV_HDR = 0,
    ENV_SNGL_HDR,
    ENV_SRC,
    ENV_SNGL_SRC,
    ENV_ARG,
    ENV_SNGL_ARG,
    EXCP_SNGL,
    EXCP_START,
    EXCP_SYS,
    EXCP_IS,
    EXCP_AC,
    EXCP_IC,
    EXCP_NC,
    EXCP_ECL,
    EXCP_IN,
    EXCP_RF,
    EXCP_NKA,
    EXCP_ICF,
    EXCP_CR,
    EXCP_BET,
    COMP_CK,
    COMP_NAMES,
    COMP_ECB,
    GLUE_NS,
    INH_RCSB,
    TYPE_ID,
    TYPE_PREFIX,
    REPO_ID,
    VAR_SIZE
  };
}

#endif  // LITERALS_HPP
