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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:151

#ifndef _TAO_IDL_ORIG_GIOPC_H_
#define _TAO_IDL_ORIG_GIOPC_H_

#include /**/ "ace/pre.h"

#include "tao/IOP_IORC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/VarOut_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/root_ch.cpp:63

namespace TAO
{
  class Collocation_Proxy_Broker;

  template<typename T> class Narrow_Utils;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:48

namespace GIOP
{

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typedef/typedef_ch.cpp:333

  typedef CORBA::Short AddressingDisposition;
  typedef CORBA::Short_out AddressingDisposition_out;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_AddressingDisposition;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52

  const CORBA::Short KeyAddr = 0;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52

  const CORBA::Short ProfileAddr = 1;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52

  const CORBA::Short ReferenceAddr = 2;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_type.cpp:258

  struct Version;

  typedef
    TAO_Fixed_Var_T<
        Version
      >
    Version_var;

  typedef
    Version &
    Version_out;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_ch.cpp:52

  struct TAO_Export Version
  {
    typedef Version_var _var_type;


    CORBA::Octet major;
    CORBA::Octet minor;
  };

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_Version;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_type.cpp:258

  struct IORAddressingInfo;

  typedef
    TAO_Var_Var_T<
        IORAddressingInfo
      >
    IORAddressingInfo_var;

  typedef
    TAO_Out_T<
        IORAddressingInfo,
        IORAddressingInfo_var
      >
    IORAddressingInfo_out;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_ch.cpp:52

  struct TAO_Export IORAddressingInfo
  {
    typedef IORAddressingInfo_var _var_type;


    CORBA::ULong selected_profile_index;
    IOP::IOR ior;
  };

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_IORAddressingInfo;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_type.cpp:258

  class TargetAddress;

  typedef
    TAO_Var_Var_T<
        TargetAddress
      >
    TargetAddress_var;

  typedef
    TAO_Out_T<
        TargetAddress,
        TargetAddress_var
      >
    TargetAddress_out;

#if !defined (_GIOP_TARGETADDRESS_CH_)
#define _GIOP_TARGETADDRESS_CH_

  class TAO_Export TargetAddress
  {
  public:
    TargetAddress (void);
    TargetAddress (const TargetAddress &);
    ~TargetAddress (void);
    TargetAddress &operator= (const TargetAddress &);

    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_union/discriminant_ch.cpp:114

    void _d (CORBA::Short);
    CORBA::Short _d (void) const;

    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_union/union_ch.cpp:108

    typedef TargetAddress_var _var_type;

    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_union_branch/public_ch.cpp:507

    void object_key (const CORBA::OctetSeq &);
    const CORBA::OctetSeq &object_key (void) const;
    CORBA::OctetSeq &object_key (void);

    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_union_branch/public_ch.cpp:615

    void profile (const IOP::TaggedProfile &);
    const IOP::TaggedProfile &profile (void) const;
    IOP::TaggedProfile &profile (void);

    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_union_branch/public_ch.cpp:615

    void ior (const ACE_NESTED_CLASS (GIOP, IORAddressingInfo) &);
    const ACE_NESTED_CLASS (GIOP, IORAddressingInfo) &ior (void) const;
    ACE_NESTED_CLASS (GIOP, IORAddressingInfo) &ior (void);

    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_union/union_ch.cpp:142

    void _default (void);
  private:
    CORBA::Short disc_;
    CORBA::Short holder_;

    union
    {
      // TAO_IDL - Generated from
      // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_union_branch/private_ch.cpp:407
      CORBA::OctetSeq *object_key_;
      // TAO_IDL - Generated from
      // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_union_branch/private_ch.cpp:482
      IOP::TaggedProfile *profile_;
      // TAO_IDL - Generated from
      // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_union_branch/private_ch.cpp:482
      ACE_NESTED_CLASS (GIOP, IORAddressingInfo) *ior_;
    } u_;

    // TAO extension - frees any allocated storage.
    void _reset (CORBA::Short, CORBA::Boolean /* finalize */);
  };

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_TargetAddress;

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:66

} // module GIOP

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_traits.cpp:48

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ch.cpp:53

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const GIOP::Version &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, GIOP::Version &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ch.cpp:53

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const GIOP::IORAddressingInfo &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, GIOP::IORAddressingInfo &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_union/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const GIOP::TargetAddress &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, GIOP::TargetAddress &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:969

#if defined (__ACE_INLINE__)
#include "GIOPC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */

