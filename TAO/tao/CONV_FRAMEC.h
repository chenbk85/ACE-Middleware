// $Id$
//
// ================================================================
//
// = LIBRARY
//   TAO
//
// = FILENAME
//   CONV_FRAMEC.h
//
// = DESCRIPTION
//   Generated from CONV_FRAME.pidl, that contains the OMG standarized
//   CONV_FRAME module.
//   The code was generated by the IDL compiler and then hand-crafted
//   to reduce the includes interdependencies.
//
// ================================================================

#ifndef TAO_CONV_FRAMEC_H
#define TAO_CONV_FRAMEC_H

#include "tao/CDR.h"
#include "tao/Sequence.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

TAO_NAMESPACE  CONV_FRAME
{
  typedef CORBA::ULong CodeSetId;
  typedef CORBA::ULong_out CodeSetId_out;
    TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_CodeSetId;

  struct TAO_Export CodeSetComponent
  {
    CodeSetId native_code_set;

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_CONV_FRAME_CODESETCOMPONENT__TAO_SEQ_CODESETID_CH_)
#define __TAO_UNBOUNDED_SEQUENCE_CONV_FRAME_CODESETCOMPONENT__TAO_SEQ_CODESETID_CH_

      class _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId : public TAO_Unbounded_Base_Sequence
      {
      public:
        // = Initialization and termination methods.

        _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId (void); // Default constructor.
        _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId (CORBA::ULong maximum);
        _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId (CORBA::ULong maximum,
          CORBA::ULong length,
          CORBA::ULong *data,
          CORBA::Boolean release = 0);
        _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId (const _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId &rhs);
        _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId &operator= (const _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId &rhs);
        virtual ~_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId (void); // Dtor.
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

#if !defined (_CONV_FRAME_CODESETCOMPONENT__TAO_SEQ_CODESETID_CH_)
#define _CONV_FRAME_CODESETCOMPONENT__TAO_SEQ_CODESETID_CH_

    // *************************************************************
    // _tao_seq_CodeSetId
    // *************************************************************

    class TAO_Export _tao_seq_CodeSetId : public
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
      _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId
#else /* TAO_USE_SEQUENCE_TEMPLATES */
      TAO_Unbounded_Sequence<CORBA::ULong>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
    {
    public:
      _tao_seq_CodeSetId (void); // default ctor
      _tao_seq_CodeSetId (CORBA::ULong max); // uses max size
      _tao_seq_CodeSetId (
        CORBA::ULong max,
        CORBA::ULong length,
        CORBA::ULong *buffer,
        CORBA::Boolean release=0
      );
      _tao_seq_CodeSetId (const _tao_seq_CodeSetId &); // copy ctor
      ~_tao_seq_CodeSetId (void); // dtor
    };
    typedef _tao_seq_CodeSetId *_tao_seq_CodeSetId_ptr;

#endif /* end #if !defined */


#if !defined (_CONV_FRAME_CODESETCOMPONENT__TAO_SEQ_CODESETID___VAR_CH_)
#define _CONV_FRAME_CODESETCOMPONENT__TAO_SEQ_CODESETID___VAR_CH_

// *************************************************************
    // class CONV_FRAME::CodeSetComponent::_tao_seq_CodeSetId_var
    // *************************************************************

    class TAO_Export _tao_seq_CodeSetId_var
    {
    public:
      _tao_seq_CodeSetId_var (void); // default constructor
      _tao_seq_CodeSetId_var (_tao_seq_CodeSetId *);
      _tao_seq_CodeSetId_var (const _tao_seq_CodeSetId_var &); // copy constructor
      ~_tao_seq_CodeSetId_var (void); // destructor

      _tao_seq_CodeSetId_var &operator= (_tao_seq_CodeSetId *);
      _tao_seq_CodeSetId_var &operator= (const _tao_seq_CodeSetId_var &);
      _tao_seq_CodeSetId *operator-> (void);
      const _tao_seq_CodeSetId *operator-> (void) const;

      operator const _tao_seq_CodeSetId &() const;
      operator _tao_seq_CodeSetId &();
      operator _tao_seq_CodeSetId &() const;
      CodeSetId &operator[] (CORBA::ULong index);
      // in, inout, out, _retn
      const _tao_seq_CodeSetId &in (void) const;
      _tao_seq_CodeSetId &inout (void);
      _tao_seq_CodeSetId *&out (void);
      _tao_seq_CodeSetId *_retn (void);
      _tao_seq_CodeSetId *ptr (void) const;

    private:
      _tao_seq_CodeSetId *ptr_;
    };


#endif /* end #if !defined */


#if !defined (_CONV_FRAME_CODESETCOMPONENT__TAO_SEQ_CODESETID___OUT_CH_)
#define _CONV_FRAME_CODESETCOMPONENT__TAO_SEQ_CODESETID___OUT_CH_

    class TAO_Export _tao_seq_CodeSetId_out
    {
    public:
      _tao_seq_CodeSetId_out (_tao_seq_CodeSetId *&);
      _tao_seq_CodeSetId_out (_tao_seq_CodeSetId_var &);
      _tao_seq_CodeSetId_out (const _tao_seq_CodeSetId_out &);
      _tao_seq_CodeSetId_out &operator= (const _tao_seq_CodeSetId_out &);
      _tao_seq_CodeSetId_out &operator= (_tao_seq_CodeSetId *);
      operator _tao_seq_CodeSetId *&();
      _tao_seq_CodeSetId *&ptr (void);
      _tao_seq_CodeSetId *operator-> (void);
      CodeSetId &operator[] (CORBA::ULong index);

    private:
      _tao_seq_CodeSetId *&ptr_;
      // assignment from T_var not allowed
      void operator= (const _tao_seq_CodeSetId_var &);
    };


#endif /* end #if !defined */

    _tao_seq_CodeSetId conversion_code_sets;
  };

  class TAO_Export CodeSetComponent_var
  {
  public:
    CodeSetComponent_var (void); // default constructor
    CodeSetComponent_var (CodeSetComponent *);
    CodeSetComponent_var (const CodeSetComponent_var &); // copy constructor
    ~CodeSetComponent_var (void); // destructor

    CodeSetComponent_var &operator= (CodeSetComponent *);
    CodeSetComponent_var &operator= (const CodeSetComponent_var &);
    CodeSetComponent *operator-> (void);
    const CodeSetComponent *operator-> (void) const;

    operator const CodeSetComponent &() const;
    operator CodeSetComponent &();
    operator CodeSetComponent &() const;
    // in, inout, out, _retn
    const CodeSetComponent &in (void) const;
    CodeSetComponent &inout (void);
    CodeSetComponent *&out (void);
    CodeSetComponent *_retn (void);
    CodeSetComponent *ptr (void) const;

  private:
    CodeSetComponent *ptr_;
  };

  class TAO_Export CodeSetComponent_out
  {
  public:
    CodeSetComponent_out (CodeSetComponent *&);
    CodeSetComponent_out (CodeSetComponent_var &);
    CodeSetComponent_out (const CodeSetComponent_out &);
    CodeSetComponent_out &operator= (const CodeSetComponent_out &);
    CodeSetComponent_out &operator= (CodeSetComponent *);
    operator CodeSetComponent *&();
    CodeSetComponent *&ptr (void);
    CodeSetComponent *operator-> (void);

  private:
    CodeSetComponent *&ptr_;
    // assignment from T_var not allowed
    void operator= (const CodeSetComponent_var &);
  };

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_CodeSetComponent;

  struct TAO_Export CodeSetComponentInfo
  {
    CodeSetComponent ForCharData;
    CodeSetComponent ForWcharData;
  };

  class TAO_Export CodeSetComponentInfo_var
  {
  public:
    CodeSetComponentInfo_var (void); // default constructor
    CodeSetComponentInfo_var (CodeSetComponentInfo *);
    CodeSetComponentInfo_var (const CodeSetComponentInfo_var &); // copy constructor
    ~CodeSetComponentInfo_var (void); // destructor

    CodeSetComponentInfo_var &operator= (CodeSetComponentInfo *);
    CodeSetComponentInfo_var &operator= (const CodeSetComponentInfo_var &);
    CodeSetComponentInfo *operator-> (void);
    const CodeSetComponentInfo *operator-> (void) const;

    operator const CodeSetComponentInfo &() const;
    operator CodeSetComponentInfo &();
    operator CodeSetComponentInfo &() const;
    // in, inout, out, _retn
    const CodeSetComponentInfo &in (void) const;
    CodeSetComponentInfo &inout (void);
    CodeSetComponentInfo *&out (void);
    CodeSetComponentInfo *_retn (void);
    CodeSetComponentInfo *ptr (void) const;

  private:
    CodeSetComponentInfo *ptr_;
  };

  class TAO_Export CodeSetComponentInfo_out
  {
  public:
    CodeSetComponentInfo_out (CodeSetComponentInfo *&);
    CodeSetComponentInfo_out (CodeSetComponentInfo_var &);
    CodeSetComponentInfo_out (const CodeSetComponentInfo_out &);
    CodeSetComponentInfo_out &operator= (const CodeSetComponentInfo_out &);
    CodeSetComponentInfo_out &operator= (CodeSetComponentInfo *);
    operator CodeSetComponentInfo *&();
    CodeSetComponentInfo *&ptr (void);
    CodeSetComponentInfo *operator-> (void);

  private:
    CodeSetComponentInfo *&ptr_;
    // assignment from T_var not allowed
    void operator= (const CodeSetComponentInfo_var &);
  };

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_CodeSetComponentInfo;

  struct TAO_Export CodeSetContext
  {
    CodeSetId char_data;
    CodeSetId wchar_data;
  };

  class TAO_Export CodeSetContext_var
  {
  public:
    CodeSetContext_var (void); // default constructor
    CodeSetContext_var (CodeSetContext *);
    CodeSetContext_var (const CodeSetContext_var &); // copy constructor
    ~CodeSetContext_var (void); // destructor

    CodeSetContext_var &operator= (CodeSetContext *);
    CodeSetContext_var &operator= (const CodeSetContext_var &);
    CodeSetContext *operator-> (void);
    const CodeSetContext *operator-> (void) const;

    operator const CodeSetContext &() const;
    operator CodeSetContext &();
    operator CodeSetContext &() const;
    // in, inout, out, _retn
    const CodeSetContext &in (void) const;
    CodeSetContext &inout (void);
    CodeSetContext &out (void);
    CodeSetContext _retn (void);
    CodeSetContext *ptr (void) const;

  private:
    CodeSetContext *ptr_;
  };

  typedef CodeSetContext &CodeSetContext_out;

  TAO_NAMESPACE_STORAGE_CLASS CORBA::TypeCode_ptr _tc_CodeSetContext;


}
TAO_NAMESPACE_CLOSE // module CONV_FRAME

void TAO_Export operator<<= (CORBA::Any &, const CONV_FRAME::CodeSetComponent &); // copying version
void TAO_Export operator<<= (CORBA::Any &, CONV_FRAME::CodeSetComponent*); // noncopying version
CORBA::Boolean TAO_Export operator>>= (const CORBA::Any &, CONV_FRAME::CodeSetComponent *&);
void TAO_Export operator<<= (CORBA::Any &, const CONV_FRAME::CodeSetComponentInfo &); // copying version
void TAO_Export operator<<= (CORBA::Any &, CONV_FRAME::CodeSetComponentInfo*); // noncopying version
CORBA::Boolean TAO_Export operator>>= (const CORBA::Any &, CONV_FRAME::CodeSetComponentInfo *&);
void TAO_Export operator<<= (CORBA::Any &, const CONV_FRAME::CodeSetContext &); // copying version
void TAO_Export operator<<= (CORBA::Any &, CONV_FRAME::CodeSetContext*); // noncopying version
CORBA::Boolean TAO_Export operator>>= (const CORBA::Any &, CONV_FRAME::CodeSetContext *&);

#ifndef __ACE_INLINE__

CORBA::Boolean TAO_Export operator<< (TAO_OutputCDR &, const CONV_FRAME::CodeSetComponent &);
CORBA::Boolean TAO_Export operator>> (TAO_InputCDR &, CONV_FRAME::CodeSetComponent &);
CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const CONV_FRAME::CodeSetComponent::_tao_seq_CodeSetId &
  );
CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    CONV_FRAME::CodeSetComponent::_tao_seq_CodeSetId &
  );

CORBA::Boolean TAO_Export operator<< (TAO_OutputCDR &, const CONV_FRAME::CodeSetComponentInfo &);
CORBA::Boolean TAO_Export operator>> (TAO_InputCDR &, CONV_FRAME::CodeSetComponentInfo &);
CORBA::Boolean TAO_Export operator<< (TAO_OutputCDR &, const CONV_FRAME::CodeSetContext &);
CORBA::Boolean TAO_Export operator>> (TAO_InputCDR &, CONV_FRAME::CodeSetContext &);

#endif /* __ACE_INLINE__ */


#if defined (__ACE_INLINE__)
#include "tao/CONV_FRAMEC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* TAO_CONV_FRAMEC_H */
