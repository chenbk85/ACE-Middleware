// $Id$
//
// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    Serveice_Detail.h
//
// = DESCRIPTION
//
//    Service_Detail stubs. This code generated by the The ACE ORB (TAO) IDL
//    Compiler and was then hand crafted
//
// ============================================================================

#ifndef SERVICE_H
#define SERVICE_H

#include "tao/corba.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export
#if defined(_MSC_VER)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

struct TAO_Export CORBA_ServiceDetail
{
  CORBA::ServiceDetailType service_detail_type;

#if !defined (_CORBA_SERVICEDETAIL__TAO_SEQ_OCTET_CH_)
#define _CORBA_SERVICEDETAIL__TAO_SEQ_OCTET_CH_
  
  // *************************************************************
  // _tao_seq_Octet
  // *************************************************************
  
  class  _tao_seq_Octet : public
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::Octet>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
    {
    public:
      _tao_seq_Octet (void); // default ctor
      _tao_seq_Octet (CORBA::ULong max); // uses max size
      _tao_seq_Octet (
                      CORBA::ULong max,
                      CORBA::ULong length,
                      CORBA::Octet *buffer,
                      CORBA::Boolean release=0
                      );
      _tao_seq_Octet (const _tao_seq_Octet &); // copy ctor
      ~_tao_seq_Octet (void); // dtor
      
#if defined(TAO_NO_COPY_OCTET_SEQUENCES)
      _tao_seq_Octet (
                      CORBA::ULong length,
                      const ACE_Message_Block* mb
                      )
        : TAO_Unbounded_Sequence<CORBA::Octet> (length, mb) {}
#endif /* TAO_NO_COPY_OCTET_SEQUENCE */
    };

  typedef _tao_seq_Octet *_tao_seq_Octet_ptr;
  static CORBA::TypeCode_ptr _tc__tao_seq_Octet;
#endif /* end #if !defined */

#if !defined (_CORBA_SERVICEDETAIL__TAO_SEQ_OCTET___VAR_CH_)
#define _CORBA_SERVICEDETAIL__TAO_SEQ_OCTET___VAR_CH_
  
  // *************************************************************
  // class CORBA::ServiceDetail::_tao_seq_Octet_var
  // *************************************************************
  
  class  _tao_seq_Octet_var
    {
    public:
      _tao_seq_Octet_var (void); // default constructor
      _tao_seq_Octet_var (_tao_seq_Octet *);
      _tao_seq_Octet_var (const _tao_seq_Octet_var &); // copy constructor
      ~_tao_seq_Octet_var (void); // destructor
      
      _tao_seq_Octet_var &operator= (_tao_seq_Octet *);
      _tao_seq_Octet_var &operator= (const _tao_seq_Octet_var &);
      _tao_seq_Octet *operator-> (void);
      const _tao_seq_Octet *operator-> (void) const;
      
      operator const _tao_seq_Octet &() const;
      operator _tao_seq_Octet &();
      operator _tao_seq_Octet &() const;
      CORBA::Octet &operator[] (CORBA::ULong index);
      // in, inout, out, _retn
      const _tao_seq_Octet &in (void) const;
      _tao_seq_Octet &inout (void);
      _tao_seq_Octet *&out (void);
      _tao_seq_Octet *_retn (void);
      _tao_seq_Octet *ptr (void) const;
      
    private:
      _tao_seq_Octet *ptr_;
    };

#endif /* end #if !defined */


#if !defined (_CORBA_SERVICEDETAIL__TAO_SEQ_OCTET___OUT_CH_)
#define _CORBA_SERVICEDETAIL__TAO_SEQ_OCTET___OUT_CH_

    class  _tao_seq_Octet_out
    {
    public:
      _tao_seq_Octet_out (_tao_seq_Octet *&);
      _tao_seq_Octet_out (_tao_seq_Octet_var &);
      _tao_seq_Octet_out (const _tao_seq_Octet_out &);
      _tao_seq_Octet_out &operator= (const _tao_seq_Octet_out &);
      _tao_seq_Octet_out &operator= (_tao_seq_Octet *);
      operator _tao_seq_Octet *&();
      _tao_seq_Octet *&ptr (void);
      _tao_seq_Octet *operator-> (void);
      CORBA::Octet &operator[] (CORBA::ULong index);

    private:
      _tao_seq_Octet *&ptr_;
      // assignment from T_var not allowed
      void operator= (const _tao_seq_Octet_var &);
    };


#endif /* end #if !defined */

    _tao_seq_Octet service_detail;
};

class  CORBA_ServiceDetail_var
{
 public:
  CORBA_ServiceDetail_var (void); // default constructor
  CORBA_ServiceDetail_var (CORBA_ServiceDetail *);
  CORBA_ServiceDetail_var (const CORBA_ServiceDetail_var &); // copy constructor
  ~CORBA_ServiceDetail_var (void); // destructor
  
  CORBA_ServiceDetail_var &operator= (CORBA_ServiceDetail *);
  CORBA_ServiceDetail_var &operator= (const CORBA_ServiceDetail_var &);
  CORBA_ServiceDetail *operator-> (void);
  const CORBA_ServiceDetail *operator-> (void) const;
  
  operator const CORBA_ServiceDetail &() const;
  operator CORBA_ServiceDetail &();
  operator CORBA_ServiceDetail &() const;
  // in, inout, out, _retn
  const CORBA_ServiceDetail &in (void) const;
  CORBA_ServiceDetail &inout (void);
  CORBA_ServiceDetail *&out (void);
  CORBA_ServiceDetail *_retn (void);
  CORBA_ServiceDetail *ptr (void) const;
  
 private:
  CORBA_ServiceDetail *ptr_;
};

class  CORBA_ServiceDetail_out
{
 public:
  CORBA_ServiceDetail_out (CORBA_ServiceDetail *&);
  CORBA_ServiceDetail_out (CORBA_ServiceDetail_var &);
  CORBA_ServiceDetail_out (const CORBA_ServiceDetail_out &);
  CORBA_ServiceDetail_out &operator= (const CORBA_ServiceDetail_out &);
  CORBA_ServiceDetail_out &operator= (CORBA_ServiceDetail *);
  operator CORBA_ServiceDetail *&();
  CORBA_ServiceDetail *&ptr (void);
  CORBA_ServiceDetail *operator-> (void);
  
 private:
  CORBA_ServiceDetail *&ptr_;
  // assignment from T_var not allowed
  void operator= (const CORBA_ServiceDetail_var &);
};

struct  CORBA_ServiceInformation
{
  
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  
#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CH_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CH_
  
  class _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption : public TAO_Unbounded_Base_Sequence
    {
    public:
      // = Initialization and termination methods.
      
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (void); // Default constructor.
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (CORBA::ULong maximum);
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (CORBA::ULong maximum,
                                                                               CORBA::ULong length,
                                                                               CORBA::ULong *data,
                                                                               CORBA::Boolean release = 0);
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (const _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption & rhs);
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption &operator= (const _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption &rhs);
      virtual ~_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (void); // Dtor.
      
      // = Accessors.
      CORBA::ULong &operator[] (CORBA::ULong i);
      const CORBA::ULong &operator[] (CORBA::ULong i) const;
      // = Static operations.
      static CORBA::ULong *allocbuf (CORBA::ULong size);
      static void freebuf (CORBA::ULong *buffer);
      virtual void _allocate_buffer (CORBA::ULong length);
      virtual void _deallocate_buffer (void);
      // Implement the TAO_Base_Sequence methods (see Sequence.h)
      
      CORBA::ULong *get_buffer (CORBA::Boolean orphan = 0);
      const CORBA::ULong *get_buffer (void) const;
      void replace (CORBA::ULong max,
                    CORBA::ULong length,
                    CORBA::ULong *data,
                    CORBA::Boolean release);
    };
  
#endif /* end #if !defined */
  
  
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
  
#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CH_
  
  // *************************************************************
  // _tao_seq_ServiceOption
  // *************************************************************
  
  class  _tao_seq_ServiceOption : public
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::ULong>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
    {
    public:
      _tao_seq_ServiceOption (void); // default ctor
      _tao_seq_ServiceOption (CORBA::ULong max); // uses max size
      _tao_seq_ServiceOption (
                              CORBA::ULong max,
                              CORBA::ULong length,
                              CORBA::ULong *buffer,
                              CORBA::Boolean release=0
                              );
      _tao_seq_ServiceOption (const _tao_seq_ServiceOption &); // copy ctor
      ~_tao_seq_ServiceOption (void); // dtor
    };
  typedef _tao_seq_ServiceOption *_tao_seq_ServiceOption_ptr;
  static CORBA::TypeCode_ptr _tc__tao_seq_ServiceOption;
  
  
#endif /* end #if !defined */
  
  
#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION___VAR_CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION___VAR_CH_

  // *************************************************************
  // class CORBA::ServiceInformation::_tao_seq_ServiceOption_var
  // *************************************************************
  
  class  _tao_seq_ServiceOption_var
    {
    public:
      _tao_seq_ServiceOption_var (void); // default constructor
      _tao_seq_ServiceOption_var (_tao_seq_ServiceOption *);
      _tao_seq_ServiceOption_var (const _tao_seq_ServiceOption_var &); // copy constructor
      ~_tao_seq_ServiceOption_var (void); // destructor
      _tao_seq_ServiceOption_var &operator= (_tao_seq_ServiceOption *);
      _tao_seq_ServiceOption_var &operator= (const _tao_seq_ServiceOption_var &);
      _tao_seq_ServiceOption *operator-> (void);
      const _tao_seq_ServiceOption *operator-> (void) const;
      
      operator const _tao_seq_ServiceOption &() const;
      operator _tao_seq_ServiceOption &();
      operator _tao_seq_ServiceOption &() const;
      CORBA::ServiceOption &operator[] (CORBA::ULong index);
      // in, inout, out, _retn
      const _tao_seq_ServiceOption &in (void) const;
      _tao_seq_ServiceOption &inout (void);
      _tao_seq_ServiceOption *&out (void);
      _tao_seq_ServiceOption *_retn (void);
      _tao_seq_ServiceOption *ptr (void) const;

    private:
      _tao_seq_ServiceOption *ptr_;
    };
  
  
#endif /* end #if !defined */
  
  
#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION___OUT_CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION___OUT_CH_
  
  class  _tao_seq_ServiceOption_out
    {
    public:
      _tao_seq_ServiceOption_out (_tao_seq_ServiceOption *&);
      _tao_seq_ServiceOption_out (_tao_seq_ServiceOption_var &);
      _tao_seq_ServiceOption_out (const _tao_seq_ServiceOption_out &);
      _tao_seq_ServiceOption_out &operator= (const _tao_seq_ServiceOption_out &);
      _tao_seq_ServiceOption_out &operator= (_tao_seq_ServiceOption *);
      operator _tao_seq_ServiceOption *&();
      _tao_seq_ServiceOption *&ptr (void);
      _tao_seq_ServiceOption *operator-> (void);
      CORBA::ServiceOption &operator[] (CORBA::ULong index);
      
    private:
      _tao_seq_ServiceOption *&ptr_;
      // assignment from T_var not allowed
      void operator= (const _tao_seq_ServiceOption_var &);
    };
  
  
#endif /* end #if !defined */
  
  _tao_seq_ServiceOption service_options;
  
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  
#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CH_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CH_
  
  class _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail : public TAO_Unbounded_Base_Sequence
    {
    public:
      // = Initialization and termination methods.
      
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (void); // Default constructor.
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (CORBA::ULong maximum);
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (CORBA::ULong maximum,
                                                                               CORBA::ULong length,
                                                                               CORBA_ServiceDetail *data,
                                                                               CORBA::Boolean release = 0);
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (const _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail & rhs);
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail &operator= (const _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail &rhs);
      virtual ~_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (void); // Dtor.
      // = Accessors.
      CORBA_ServiceDetail &operator[] (CORBA::ULong i);
      const CORBA_ServiceDetail &operator[] (CORBA::ULong i) const;
      // = Static operations.
      static CORBA_ServiceDetail *allocbuf (CORBA::ULong size);
      static void freebuf (CORBA_ServiceDetail *buffer);
      virtual void _allocate_buffer (CORBA::ULong length);
      virtual void _deallocate_buffer (void);
      // Implement the TAO_Base_Sequence methods (see Sequence.h)
      
      CORBA_ServiceDetail *get_buffer (CORBA::Boolean orphan = 0);
      const CORBA_ServiceDetail *get_buffer (void) const;
      void replace (CORBA::ULong max,
                    CORBA::ULong length,
                    CORBA_ServiceDetail *data,
                    CORBA::Boolean release);
    };
  
#endif /* end #if !defined */
  
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
  
#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CH_
  
  // *************************************************************
  // _tao_seq_ServiceDetail
  // *************************************************************
  
  class  _tao_seq_ServiceDetail : public
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA_ServiceDetail>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
    {
    public:
      _tao_seq_ServiceDetail (void); // default ctor
      _tao_seq_ServiceDetail (CORBA::ULong max); // uses max size
      _tao_seq_ServiceDetail (
                              CORBA::ULong max,
                              CORBA::ULong length,
                              CORBA_ServiceDetail *buffer,
                              CORBA::Boolean release=0
                              );
      _tao_seq_ServiceDetail (const _tao_seq_ServiceDetail &); // copy ctor
      ~_tao_seq_ServiceDetail (void); // dtor
    };
  typedef _tao_seq_ServiceDetail *_tao_seq_ServiceDetail_ptr;
  static CORBA::TypeCode_ptr _tc__tao_seq_ServiceDetail;
  
  
#endif /* end #if !defined */
  
#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL___VAR_CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL___VAR_CH_
  
  // *************************************************************
  // class CORBA::ServiceInformation::_tao_seq_ServiceDetail_var
  // *************************************************************
  
  class  _tao_seq_ServiceDetail_var
    {
    public:
      _tao_seq_ServiceDetail_var (void); // default constructor
      _tao_seq_ServiceDetail_var (_tao_seq_ServiceDetail *);
      _tao_seq_ServiceDetail_var (const _tao_seq_ServiceDetail_var &); // copy constructor
      ~_tao_seq_ServiceDetail_var (void); // destructor

      _tao_seq_ServiceDetail_var &operator= (_tao_seq_ServiceDetail *);
      _tao_seq_ServiceDetail_var &operator= (const _tao_seq_ServiceDetail_var &);
      _tao_seq_ServiceDetail *operator-> (void);
      const _tao_seq_ServiceDetail *operator-> (void) const;

      operator const _tao_seq_ServiceDetail &() const;
      operator _tao_seq_ServiceDetail &();
      operator _tao_seq_ServiceDetail &() const;
      CORBA_ServiceDetail &operator[] (CORBA::ULong index);
      // in, inout, out, _retn
      const _tao_seq_ServiceDetail &in (void) const;
      _tao_seq_ServiceDetail &inout (void);
      _tao_seq_ServiceDetail *&out (void);
      _tao_seq_ServiceDetail *_retn (void);
      _tao_seq_ServiceDetail *ptr (void) const;

    private:
      _tao_seq_ServiceDetail *ptr_;
    };


#endif /* end #if !defined */


#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL___OUT_CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL___OUT_CH_

  class  _tao_seq_ServiceDetail_out
    {
    public:
      _tao_seq_ServiceDetail_out (_tao_seq_ServiceDetail *&);
      _tao_seq_ServiceDetail_out (_tao_seq_ServiceDetail_var &);
      _tao_seq_ServiceDetail_out (const _tao_seq_ServiceDetail_out &);
      _tao_seq_ServiceDetail_out &operator= (const _tao_seq_ServiceDetail_out &);
      _tao_seq_ServiceDetail_out &operator= (_tao_seq_ServiceDetail *);
      operator _tao_seq_ServiceDetail *&();
      _tao_seq_ServiceDetail *&ptr (void);
      _tao_seq_ServiceDetail *operator-> (void);
      CORBA_ServiceDetail &operator[] (CORBA::ULong index);

    private:
      _tao_seq_ServiceDetail *&ptr_;
      // assignment from T_var not allowed
      void operator= (const _tao_seq_ServiceDetail_var &);
    };


#endif /* end #if !defined */

    _tao_seq_ServiceDetail service_details;
};


class  CORBA_ServiceInformation_var
{
 public:
  CORBA_ServiceInformation_var (void); // default constructor
  CORBA_ServiceInformation_var (CORBA_ServiceInformation *);
  CORBA_ServiceInformation_var (const CORBA_ServiceInformation_var &); // copy constructor
  ~CORBA_ServiceInformation_var (void); // destructor
  
  CORBA_ServiceInformation_var &operator= (CORBA_ServiceInformation *);
  CORBA_ServiceInformation_var &operator= (const CORBA_ServiceInformation_var &);
  CORBA_ServiceInformation *operator-> (void);
  const CORBA_ServiceInformation *operator-> (void) const;
  
  operator const CORBA_ServiceInformation &() const;
  operator CORBA_ServiceInformation &();
  operator CORBA_ServiceInformation &() const;
  // in, inout, out, _retn
  const CORBA_ServiceInformation &in (void) const;
  CORBA_ServiceInformation &inout (void);
  CORBA_ServiceInformation *&out (void);
  CORBA_ServiceInformation *_retn (void);
  CORBA_ServiceInformation *ptr (void) const;
  
 private:
  CORBA_ServiceInformation *ptr_;
};

class  CORBA_ServiceInformation_out
{
 public:
  CORBA_ServiceInformation_out (CORBA_ServiceInformation *&);
  CORBA_ServiceInformation_out (CORBA_ServiceInformation_var &);
  CORBA_ServiceInformation_out (const CORBA_ServiceInformation_out &);
  CORBA_ServiceInformation_out &operator= (const CORBA_ServiceInformation_out &);
  CORBA_ServiceInformation_out &operator= (CORBA_ServiceInformation *);
  
  operator CORBA_ServiceInformation *&();
  CORBA_ServiceInformation *&ptr (void);
  CORBA_ServiceInformation *operator-> (void);
  
 private:
  CORBA_ServiceInformation *&ptr_;
  // assignment from T_var not allowed
  void operator= (const CORBA_ServiceInformation_var &);
};


void  operator<<= (CORBA::Any &, const CORBA::ServiceDetail &); // copying version
void  operator<<= (CORBA::Any &, CORBA::ServiceDetail*); // noncopying version
CORBA::Boolean  operator>>= (const CORBA::Any &, CORBA::ServiceDetail *&);
void  operator<<= (CORBA::Any &, const CORBA_ServiceInformation &); // copying version
void  operator<<= (CORBA::Any &, CORBA_ServiceInformation*); // noncopying version
CORBA::Boolean  operator>>= (const CORBA::Any &, CORBA_ServiceInformation *&);

#ifndef __ACE_INLINE__

CORBA::Boolean  operator<< (TAO_OutputCDR &, const CORBA_ServiceDetail &); //
CORBA::Boolean  operator>> (TAO_InputCDR &, CORBA_ServiceDetail &);
CORBA::Boolean  operator<< (TAO_OutputCDR &, const CORBA_ServiceDetail::_tao_seq_Octet &); //
CORBA::Boolean  operator>> (TAO_InputCDR &, CORBA_ServiceDetail::_tao_seq_Octet &);
CORBA::Boolean  operator<< (TAO_OutputCDR &, const CORBA_ServiceInformation &);
 //
CORBA::Boolean  operator>> (TAO_InputCDR &, CORBA_ServiceInformation &);
CORBA::Boolean  operator<< (TAO_OutputCDR &, const CORBA_ServiceInformation::_tao_seq_ServiceOption &); //
CORBA::Boolean  operator>> (TAO_InputCDR &, CORBA_ServiceInformation::_tao_seq_ServiceOption &);
CORBA::Boolean  operator<< (TAO_OutputCDR &, const CORBA_ServiceInformation::_tao_seq_ServiceDetail &); //
CORBA::Boolean  operator>> (TAO_InputCDR &, CORBA_ServiceInformation::_tao_seq_ServiceDetail &);

#endif /* __ACE_INLINE__ */

#if defined (__ACE_INLINE__)
#include "Services.i"
#endif /* defined INLINE */



#if defined(_MSC_VER)
#pragma warning(default:4250)
#endif /* _MSC_VER */
#endif /* Sevices */
