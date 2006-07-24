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
// be\be_codegen.cpp:154

#ifndef _TAO_IDL_PS_FORWARDC_H_
#define _TAO_IDL_PS_FORWARDC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/portableserver_export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/Objref_VarOut_T.h"

#include "tao/OctetSeqC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PortableServer_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_ServantBase;
class TAO_Local_ServantBase;
class TAO_Root_POA;
class TAO_DynamicImplementation;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:49

namespace PortableServer
{
    typedef TAO_ServantBase ServantBase;
    struct RefCountServantBase {};
    template <class T> class Servant_var;
    typedef Servant_var<TAO_ServantBase> ServantBase_var;
    typedef ServantBase *Servant;

    typedef TAO_Local_ServantBase LocalServantBase;
    typedef TAO_DynamicImplementation DynamicImplementation;

  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:472

  typedef CORBA::OctetSeq ObjectId;
  typedef CORBA::OctetSeq_var ObjectId_var;
  typedef CORBA::OctetSeq_out ObjectId_out;

  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_PORTABLESERVER_POA__VAR_OUT_CH_)
#define _PORTABLESERVER_POA__VAR_OUT_CH_

  class POA;
  typedef POA *POA_ptr;

  typedef
    TAO_Objref_Var_T<
        POA
      >
    POA_var;

  typedef
    TAO_Objref_Out_T<
        POA
      >
    POA_out;

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:78

} // module PortableServer

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_codegen.cpp:1028

TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */


