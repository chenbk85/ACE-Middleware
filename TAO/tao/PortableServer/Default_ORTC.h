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
// be/be_codegen.cpp:150

#ifndef _TAO_IDL_ORIG_DEFAULT_ORTC_H_
#define _TAO_IDL_ORIG_DEFAULT_ORTC_H_

#include /**/ "ace/pre.h"

#include "tao/ObjRefTemplate/ObjectReferenceTemplateC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "portableserver_export.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PortableServer_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_PortableServer_Export
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
// be/be_visitor_module/module_ch.cpp:48

namespace TAO_Default_ORT
{
  
  // TAO_IDL - Generated from
  // be/be_valuetype.cpp:527
  
  

#if !defined (_TAO_DEFAULT_ORT_OBJECTREFERENCETEMPLATE__VAR_OUT_CH_)
#define _TAO_DEFAULT_ORT_OBJECTREFERENCETEMPLATE__VAR_OUT_CH_
  
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
  // be/be_visitor_valuetype/valuetype_ch.cpp:56

#if !defined (_TAO_DEFAULT_ORT_OBJECTREFERENCETEMPLATE_CH_)
#define _TAO_DEFAULT_ORT_OBJECTREFERENCETEMPLATE_CH_
  
  class TAO_PortableServer_Export ObjectReferenceTemplate
    : public virtual PortableInterceptor::ObjectReferenceTemplate
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
    // be/be_visitor_valuetype/valuetype_ch.cpp:250
  
  protected:
    ObjectReferenceTemplate (void);
    
    virtual ~ObjectReferenceTemplate (void);
    
    virtual CORBA::Boolean _tao_marshal_v (TAO_OutputCDR &);
    virtual CORBA::Boolean _tao_unmarshal_v (TAO_InputCDR &);
    
  private:
    ObjectReferenceTemplate (const ObjectReferenceTemplate &);
    void operator= (const ObjectReferenceTemplate &);
    
  protected:
    virtual CORBA::Boolean
    _tao_marshal__TAO_Default_ORT_ObjectReferenceTemplate (TAO_OutputCDR &) = 0;
    
    virtual CORBA::Boolean
    _tao_unmarshal__TAO_Default_ORT_ObjectReferenceTemplate (TAO_InputCDR &) = 0;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ObjectReferenceTemplate;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:66

} // module TAO_Default_ORT

// TAO_IDL - Generated from
// be/be_visitor_valuetype/obv_module.cpp:55

namespace OBV_TAO_Default_ORT
{
  
  // TAO_IDL - Generated from
  // be/be_visitor_valuetype/valuetype_obv_ch.cpp:58

#if !defined (_TAO_DEFAULT_ORT_OBJECTREFERENCETEMPLATE___OBV_CH_)
#define _TAO_DEFAULT_ORT_OBJECTREFERENCETEMPLATE___OBV_CH_
  
  // OBV_ class
  class TAO_PortableServer_Export ObjectReferenceTemplate
    : public virtual TAO_Default_ORT::ObjectReferenceTemplate
  {
  public:
    
  protected:
    ObjectReferenceTemplate (void);
    virtual ~ObjectReferenceTemplate (void);
    
  protected:
    virtual CORBA::Boolean
    _tao_marshal__TAO_Default_ORT_ObjectReferenceTemplate (TAO_OutputCDR &);
    
    virtual CORBA::Boolean
    _tao_unmarshal__TAO_Default_ORT_ObjectReferenceTemplate (TAO_InputCDR &);
    
    CORBA::Boolean _tao_marshal_state (TAO_OutputCDR &);
    CORBA::Boolean _tao_unmarshal_state (TAO_InputCDR &);
  
  private:
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:48

// Traits specializations.
namespace TAO
{

#if !defined (_TAO_DEFAULT_ORT_OBJECTREFERENCETEMPLATE__TRAITS_CH_)
#define _TAO_DEFAULT_ORT_OBJECTREFERENCETEMPLATE__TRAITS_CH_
  
  ACE_TEMPLATE_SPECIALIZATION
  struct TAO_PortableServer_Export Value_Traits<TAO_Default_ORT::ObjectReferenceTemplate>
  {
    static void tao_add_ref (TAO_Default_ORT::ObjectReferenceTemplate *);
    static void tao_remove_ref (TAO_Default_ORT::ObjectReferenceTemplate *);
    static void tao_release (TAO_Default_ORT::ObjectReferenceTemplate *);
  };

#endif /* end #if !defined */
};

// TAO_IDL - Generated from
// be/be_visitor_valuetype/any_op_ch.cpp:54

TAO_PortableServer_Export void operator<<= (CORBA::Any &, TAO_Default_ORT::ObjectReferenceTemplate *); // copying
TAO_PortableServer_Export void operator<<= (CORBA::Any &, TAO_Default_ORT::ObjectReferenceTemplate **); // non-copying
TAO_PortableServer_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO_Default_ORT::ObjectReferenceTemplate *&);

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// be/be_valuetype.cpp:434

namespace CORBA
{
  TAO_NAMESPACE_STORAGE_CLASS void add_ref (TAO_Default_ORT::ObjectReferenceTemplate *);
  TAO_NAMESPACE_STORAGE_CLASS void remove_ref (TAO_Default_ORT::ObjectReferenceTemplate *);
}

// TAO_IDL - Generated from
// be/be_visitor_valuetype/cdr_op_ch.cpp:61

TAO_PortableServer_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_Default_ORT::ObjectReferenceTemplate *);
TAO_PortableServer_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO_Default_ORT::ObjectReferenceTemplate *&);

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// be/be_codegen.cpp:911

#if defined (__ACE_INLINE__)
#include "Default_ORTC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */

