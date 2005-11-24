// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_USHORTSEQC_H_
#define _TAO_IDL_ORIG_USHORTSEQC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/Sequence_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace CORBA
{

  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_CORBA_USHORTSEQ_CH_)
#define _CORBA_USHORTSEQ_CH_

  class UShortSeq;

  typedef
    TAO_FixedSeq_Var_T<
        UShortSeq,
        CORBA::UShort
      >
    UShortSeq_var;

  typedef
    TAO_Seq_Out_T<
        UShortSeq,
        UShortSeq_var,
        CORBA::UShort
      >
    UShortSeq_out;

  class TAO_Export UShortSeq
    : public
        TAO_Unbounded_Sequence<
            CORBA::UShort
          >
  {
  public:
    UShortSeq (void);
    UShortSeq (CORBA::ULong max);
    UShortSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        CORBA::UShort* buffer,
        CORBA::Boolean release = 0
      );
    UShortSeq (const UShortSeq &);
    ~UShortSeq (void);

    static void _tao_any_destructor (void *);

    typedef UShortSeq_var _var_type;
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module CORBA

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{
}

// Workaround for a Visual Studio .NET bug where this class is not
// properly imported by an application if typedef'd or subclassed,
// resulting in 'multiply defined' link errors. The export macro
// here forces an explicit import by the application. Please see
// http://support.microsoft.com/default.aspx?scid=kb;en-us;309801
// The problem stems from use of the type below in DsLogAdmin,
// but we put the instantiation here because the application will
// need to see it in *C.h to avoid the error.
#if defined ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT
  template class TAO_Export TAO_Unbounded_Sequence<CORBA::UShortSeq>;
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_CORBA_UShortSeq_H_
#define _TAO_CDR_OP_CORBA_UShortSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::UShortSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::UShortSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_UShortSeq_H_ */

// TAO_IDL - Generated from
// be\be_codegen.cpp:955

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


