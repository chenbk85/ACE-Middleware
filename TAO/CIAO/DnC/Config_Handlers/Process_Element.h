// -*-C++-*-
//==================================================================
/**
 *  @file Process_Element.h
 *
 *  $Id$
 *
 *  @author Emre Turkay  <turkaye@dre.vanderbilt.edu>
 */
//=====================================================================

#ifndef PROCESS_ELEMENT_H
#define PROCESS_ELEMENT_H

#include "DeploymentC.h"
#include "Config_Handler_export.h"
#include "ace/SString.h"
#include "ace/Hash_Map_Manager.h"
#include "ace/Null_Mutex.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Auto_Ptr.h"
#include "ace/Log_Msg.h"
#include "ace/OS_main.h"
#include "tao/Exception.h"
#include "XercesString.h"
#include <xercesc/util/XMLUniDefs.hpp>
#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLURL.hpp>
#include <xercesc/util/XMLUri.hpp>

using Config_Handler::XStr;
using xercesc::XMLUni;
using xercesc::XMLUri;
using xercesc::XMLURL;
using xercesc::XMLString;
using xercesc::XMLException;
using xercesc::DOMException;
using xercesc::DOMBuilder;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMImplementation;
using xercesc::DOMInputSource;
using xercesc::DOMText;
using xercesc::DOMNamedNodeMap;
using xercesc::DOMLocator;
using xercesc::DOMError;
using xercesc::DOMDocument;
using xercesc::DOMDocumentTraversal;
using xercesc::DOMNodeIterator;
using xercesc::DOMNode;
using xercesc::DOMNodeFilter;
using xercesc::DOMNamedNodeMap;

#include <iostream>

// ID map type definition
typedef ACE_Hash_Map_Manager<ACE_TString, int, ACE_Null_Mutex> REFMAP;


template <typename OBJ, typename DATA>
class Process_Function {
public:
  virtual void call(DOMNodeIterator*, DATA&)=0;

  void operator() (DOMNodeIterator* iter, DATA& data)
  {
    call(iter, data);
  }
};

/*
 *  Wrapper class for the process member functions.
 */

template <typename OBJ, typename DATA>
class Process_Member_Function: public Process_Function<OBJ, DATA> {
public:
  typedef void (OBJ::*func_type) (DOMDocument*, DOMNodeIterator*, DATA&);
  typedef DATA data_type;

  Process_Member_Function(OBJ& obj, func_type f, DOMDocument* doc)
    : obj_(&obj), f_(f), doc_(doc)
  {
  }

  Process_Member_Function(OBJ* obj, func_type f, DOMDocument* doc)
    : obj_(obj), f_(f), doc_(doc)
  {
  }

  virtual void call(DOMNodeIterator* iter, DATA& data)
  {
    (obj_->*f_) (doc_, iter, data);
  }

  void doc(DOMDocument* val)
  {
    doc_ = val;
  }

private:
  OBJ* obj_;
  func_type f_;
  DOMDocument* doc_;
};

/*
 *  Wrapper class for the static process member functions.
 */

template <typename OBJ, typename DATA>
class Process_Static_Function: public Process_Function<OBJ, DATA> {
public:
  typedef void (*func_type) (DOMNodeIterator*, DATA&);
  typedef DATA data_type;

  Process_Static_Function(func_type f)
    : f_(f)
  {
  }

  Process_Static_Function(func_type f)
    : f_(f)
  {
  }

  virtual void call(DOMNodeIterator* iter, DATA& data)
  {
    (*f_) (iter, data);
  }

private:
  func_type f_;
};

DOMDocument* create_document (const char *url);

template <typename DATA, typename VALUE, typename OBJECT>
void process_element (DOMNode* node,
                      DOMDocument* doc,
                      DOMNodeIterator* iter,
                      DATA& data,
                      VALUE val,
                      Process_Function <OBJECT, DATA>* func,
                      REFMAP& id_map);

template <typename SEQUENCE, typename DATA, typename OBJECT>
void process_sequential_element (DOMNode* node,
                                 DOMDocument* doc,
                                 DOMNodeIterator* iter,
                                 SEQUENCE& seq,
                                 Process_Function <OBJECT, DATA>* func,
                                 REFMAP& id_map);

/*
 *  Process function for member functions
 */

template<typename DATA, typename OBJECT, typename SEQUENCE, typename FUNCTION>
inline void process_function(OBJECT* obj, SEQUENCE& data, FUNCTION func,
                             DOMNode* node,
                             DOMDocument* doc,
                             DOMNodeIterator *iter,
                             REFMAP& id_map)
{
  Process_Member_Function<OBJECT, DATA> pf(obj, func, doc);
  process_sequential_element (node, doc, iter, data, &pf, id_map);
}

/*
 *  Process function for static functions
 */

template<typename DATA, typename SEQUENCE, typename FUNCTION>
inline void process_function(SEQUENCE& data, FUNCTION func,
                             DOMNode* node,
                             DOMDocument* doc,
                             DOMNodeIterator *iter,
                             REFMAP& id_map)
{
  Process_Static_Function<OBJECT, DATA> pf(func);
  process_sequential_element (node, doc, iter, data, &pf, id_map);
}

#include "Process_Element.i"

#endif // PROCESS_ELEMENT_H
