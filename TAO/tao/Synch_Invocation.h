// -*- C++ -*-

//=============================================================================
/**
 *  @file    Synch_Invocation.h
 *
 *  $Id$
 *
 *
 *  @author Balachandran Natarajan <bala@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef TAO_SYNCH_INVOCATION_H
#define TAO_SYNCH_INVOCATION_H
#include /**/ "ace/pre.h"

#include "tao/Remote_Invocation.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Exception.h"

class TAO_Operation_Details;
class TAO_Synch_Reply_Dispatcher;
class TAO_InputCDR;
class ACE_Time_Value;
class TAO_Bind_Dispatcher_Guard;

namespace CORBA
{
  class SystemException;
}

namespace TAO
{
  class Profile_Transport_Resolver;

  class TAO_Export Synch_Twoway_Invocation : public Remote_Invocation
  {
  public:
    Synch_Twoway_Invocation (CORBA::Object_ptr otarget,
                             Profile_Transport_Resolver &resolver,
                             TAO_Operation_Details &detail,
                             bool response_expected = true);

    Invocation_Status remote_twoway (ACE_Time_Value *max_wait_time
                                     ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::Exception));

  protected:

    /**
     * This method is selectively made virtual, so that inherited
     * classes can overload the  user exception handling type. For
     * example the DII needs a totally different method of
     * user exception exception handling
     */
    virtual Invocation_Status handle_user_exception (TAO_InputCDR &cdr
                                                     ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::Exception));

    Invocation_Status location_forward (TAO_InputCDR &cdr
                                        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException));



    Invocation_Status handle_system_exception (TAO_InputCDR &cdr
                                               ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException));

    Invocation_Status wait_for_reply (ACE_Time_Value *max_wait_time,
                                      TAO_Synch_Reply_Dispatcher &rd,
                                      TAO_Bind_Dispatcher_Guard &bd
                                      ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException));


  private:

    Invocation_Status check_reply_status (TAO_Synch_Reply_Dispatcher &rd
                                          ACE_ENV_ARG_DECL);


  };

  class TAO_Export Synch_Oneway_Invocation : public Synch_Twoway_Invocation
  {
  public:
    Synch_Oneway_Invocation (CORBA::Object_ptr otarget,
                             Profile_Transport_Resolver &resolver,
                             TAO_Operation_Details &detail);

    Invocation_Status remote_oneway (ACE_Time_Value *max_wait_time
                                     ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::Exception));
  };

  class TAO_Export Reply_Guard
  {
  public:
    Reply_Guard (Invocation_Base *s,
                 Invocation_Status is);

    ~Reply_Guard (void);

    void set_status (Invocation_Status s);

  private:
    Invocation_Base *invocation_;
    Invocation_Status status_;

  };

}


#if defined (__ACE_INLINE__)
# include "tao/Synch_Invocation.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /*TAO_SYNCH_INVOCATION_H*/
