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

#ifndef _TAO_IDL_ORIG_OBJECTREFERENCETEMPLATEC_H_
#define _TAO_IDL_ORIG_OBJECTREFERENCETEMPLATEC_H_

#include /**/ "ace/pre.h"

#ifndef TAO_OBJREF_TEMPLATE_SAFE_INCLUDE
#error "You should not include ObjectReferenceTemplateC.h directly, use ObjectReferenceTemplate.h"
#endif /* !TAO_OBJREF_TEMPLATE_SAFE_INCLUDE */

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/ObjRefTemplate/ort_export.h"
#include "tao/Valuetype/ValueBase.h"
#include "tao/Valuetype/Valuetype_Adapter_Impl.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Valuetype/Sequence_T.h"
#include "tao/Sequence_T.h"
#include "tao/Valuetype/Value_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"

#include "tao/PI_ForwardC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_ORT_Export

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

namespace PortableInterceptor
{
  
  // TAO_IDL - Generated from
  // be\be_valuetype.cpp:524
  
  

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__VAR_OUT_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__VAR_OUT_CH_
  
  class ObjectReferenceFactory;
  typedef
    TAO_Value_Var_T<
        ObjectReferenceFactory
      >
    ObjectReferenceFactory_var;
  
  typedef
    TAO_Value_Out_T<
        ObjectReferenceFactory
      >
    ObjectReferenceFactory_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_valuetype/valuetype_ch.cpp:56

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY_CH_
  
  class TAO_ORT_Export ObjectReferenceFactory
    : public virtual CORBA::ValueBase
  {
  public:
    typedef ObjectReferenceFactory_var _var_type;
    
    static ObjectReferenceFactory* _downcast (CORBA::ValueBase *);
    
    // (TAO extensions or internals)
    static CORBA::Boolean _tao_unmarshal (
        TAO_InputCDR &,
        ObjectReferenceFactory *&
      );
    
    virtual const char* _tao_obv_repository_id (void) const;
    
    static const char* _tao_obv_static_repository_id (void);
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be\be_visitor_valuetype/valuetype_ch.cpp:404
    
  public:
    virtual CORBA::Object_ptr make_object (
        const char *, const ::PortableInterceptor::ObjectId & ACE_ENV_ARG_DECL_WITH_DEFAULTS
      ) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_valuetype/valuetype_ch.cpp:246
  
  protected:
    ObjectReferenceFactory (void);
    
    virtual ~ObjectReferenceFactory (void);
    
    
  private:
    ObjectReferenceFactory (const ObjectReferenceFactory &);
    void operator= (const ObjectReferenceFactory &);
    
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_ORT_Export ::CORBA::TypeCode_ptr const _tc_ObjectReferenceFactory;
  
  // TAO_IDL - Generated from
  // be\be_valuetype.cpp:524
  
  

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__VAR_OUT_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__VAR_OUT_CH_
  
  class ObjectReferenceTemplate;
  typedef
    TAO_Value_Var_T<
        ObjectReferenceTemplate
      >
    ObjectReferenceTemplate_var;
  
  typedef
    TAO_Value_Out_T<
        ObjectReferenceTemplate
      >
    ObjectReferenceTemplate_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_valuetype/valuetype_ch.cpp:56

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE_CH_
  
  class TAO_ORT_Export ObjectReferenceTemplate
    : public virtual ObjectReferenceFactory
  {
  public:
    typedef ObjectReferenceTemplate_var _var_type;
    
    static ObjectReferenceTemplate* _downcast (CORBA::ValueBase *);
    
    // (TAO extensions or internals)
    static CORBA::Boolean _tao_unmarshal (
        TAO_InputCDR &,
        ObjectReferenceTemplate *&
      );
    
    virtual const char* _tao_obv_repository_id (void) const;
    
    static const char* _tao_obv_static_repository_id (void);
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be\be_visitor_valuetype/valuetype_ch.cpp:404
    
  public:
    virtual char * server_id (
         ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      ) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_valuetype/valuetype_ch.cpp:404
    
  public:
    virtual char * orb_id (
         ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      ) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_valuetype/valuetype_ch.cpp:404
    
  public:
    virtual ::PortableInterceptor::AdapterName * adapter_name (
         ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      ) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_valuetype/valuetype_ch.cpp:246
  
  protected:
    ObjectReferenceTemplate (void);
    
    virtual ~ObjectReferenceTemplate (void);
    
    
  private:
    ObjectReferenceTemplate (const ObjectReferenceTemplate &);
    void operator= (const ObjectReferenceTemplate &);
    
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_ORT_Export ::CORBA::TypeCode_ptr const _tc_ObjectReferenceTemplate;
  
  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ_CH_
  
  class ObjectReferenceTemplateSeq;
  
  typedef
    TAO_MngSeq_Var_T<
        ObjectReferenceTemplateSeq,
        TAO_Valuetype_Manager<
            ObjectReferenceTemplate,
            ObjectReferenceTemplate_var
          >
      >
    ObjectReferenceTemplateSeq_var;
  
  typedef
    TAO_MngSeq_Out_T<
        ObjectReferenceTemplateSeq,
        ObjectReferenceTemplateSeq_var,
        TAO_Valuetype_Manager<
            ObjectReferenceTemplate,
            ObjectReferenceTemplate_var
          >
      >
    ObjectReferenceTemplateSeq_out;
  
  class TAO_ORT_Export ObjectReferenceTemplateSeq
    : public
        TAO_Unbounded_Valuetype_Sequence<
            ObjectReferenceTemplate,
            ObjectReferenceTemplate_var
          >
  {
  public:
    ObjectReferenceTemplateSeq (void);
    ObjectReferenceTemplateSeq (CORBA::ULong max);
    ObjectReferenceTemplateSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        ObjectReferenceTemplate ** buffer, 
        CORBA::Boolean release = 0
      );
    ObjectReferenceTemplateSeq (const ObjectReferenceTemplateSeq &);
    ~ObjectReferenceTemplateSeq (void);
    
    static void _tao_any_destructor (void *);
    
    typedef ObjectReferenceTemplateSeq_var _var_type;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_ORT_Export ::CORBA::TypeCode_ptr const _tc_ObjectReferenceTemplateSeq;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module PortableInterceptor

// TAO_IDL - Generated from
// be\be_visitor_valuetype/obv_module.cpp:55

namespace OBV_PortableInterceptor
{
}

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__TRAITS_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__TRAITS_CH_
  
  template<>
  struct TAO_ORT_Export Value_Traits<PortableInterceptor::ObjectReferenceFactory>
  {
    static void add_ref (PortableInterceptor::ObjectReferenceFactory *);
    static void remove_ref (PortableInterceptor::ObjectReferenceFactory *);
    static void release (PortableInterceptor::ObjectReferenceFactory *);
  };

#endif /* end #if !defined */

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__TRAITS_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__TRAITS_CH_
  
  template<>
  struct TAO_ORT_Export Value_Traits<PortableInterceptor::ObjectReferenceTemplate>
  {
    static void add_ref (PortableInterceptor::ObjectReferenceTemplate *);
    static void remove_ref (PortableInterceptor::ObjectReferenceTemplate *);
    static void release (PortableInterceptor::ObjectReferenceTemplate *);
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_visitor_valuetype/any_op_ch.cpp:54

TAO_ORT_Export void operator<<= (CORBA::Any &, PortableInterceptor::ObjectReferenceFactory *); // copying
TAO_ORT_Export void operator<<= (CORBA::Any &, PortableInterceptor::ObjectReferenceFactory **); // non-copying
TAO_ORT_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ObjectReferenceFactory *&);

// TAO_IDL - Generated from
// be\be_visitor_valuetype/any_op_ch.cpp:54

TAO_ORT_Export void operator<<= (CORBA::Any &, PortableInterceptor::ObjectReferenceTemplate *); // copying
TAO_ORT_Export void operator<<= (CORBA::Any &, PortableInterceptor::ObjectReferenceTemplate **); // non-copying
TAO_ORT_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ObjectReferenceTemplate *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:52

TAO_ORT_Export void operator<<= (CORBA::Any &, const PortableInterceptor::ObjectReferenceTemplateSeq &); // copying version
TAO_ORT_Export void operator<<= (CORBA::Any &, PortableInterceptor::ObjectReferenceTemplateSeq*); // noncopying version
TAO_ORT_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ObjectReferenceTemplateSeq *&); // deprecated
TAO_ORT_Export CORBA::Boolean operator>>= (const CORBA::Any &, const PortableInterceptor::ObjectReferenceTemplateSeq *&);

// TAO_IDL - Generated from
// be\be_valuetype.cpp:431

namespace CORBA
{
  extern TAO_ORT_Export void add_ref (PortableInterceptor::ObjectReferenceFactory *);
  extern TAO_ORT_Export void remove_ref (PortableInterceptor::ObjectReferenceFactory *);
}

// TAO_IDL - Generated from
// be\be_visitor_valuetype/cdr_op_ch.cpp:61

TAO_ORT_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const PortableInterceptor::ObjectReferenceFactory *);
TAO_ORT_Export CORBA::Boolean operator>> (TAO_InputCDR &, PortableInterceptor::ObjectReferenceFactory *&);

// TAO_IDL - Generated from
// be\be_valuetype.cpp:431

namespace CORBA
{
  extern TAO_ORT_Export void add_ref (PortableInterceptor::ObjectReferenceTemplate *);
  extern TAO_ORT_Export void remove_ref (PortableInterceptor::ObjectReferenceTemplate *);
}

// TAO_IDL - Generated from
// be\be_visitor_valuetype/cdr_op_ch.cpp:61

TAO_ORT_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const PortableInterceptor::ObjectReferenceTemplate *);
TAO_ORT_Export CORBA::Boolean operator>> (TAO_InputCDR &, PortableInterceptor::ObjectReferenceTemplate *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_PortableInterceptor_ObjectReferenceTemplateSeq_H_
#define _TAO_CDR_OP_PortableInterceptor_ObjectReferenceTemplateSeq_H_

TAO_ORT_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const PortableInterceptor::ObjectReferenceTemplateSeq &
  );
TAO_ORT_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    PortableInterceptor::ObjectReferenceTemplateSeq &
  );

#endif /* _TAO_CDR_OP_PortableInterceptor_ObjectReferenceTemplateSeq_H_ */

// TAO_IDL - Generated from
// be\be_codegen.cpp:955

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "tao/ObjRefTemplate/ObjectReferenceTemplateC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


