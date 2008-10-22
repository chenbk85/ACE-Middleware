/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef MESSENGER_I_H_
#define MESSENGER_I_H_

#include "MessengerS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orbsvcs/CosTypedEventChannelAdminC.h"

//Class Messenger_i
class  Messenger_i : public virtual POA_Messenger
{
public:
  //Constructor
  Messenger_i (CORBA::ORB_ptr orb,
               CosEventChannelAdmin::ProxyPushSupplier_ptr supplier,
               int event_limit);

  //Destructor
  virtual ~Messenger_i (void);

  virtual void send_message (const char * user_name,
                             const char * subject,
                             const char * message);

private:
  CORBA::ORB_var orb_;
  CosEventChannelAdmin::ProxyPushSupplier_var supplier_;
  int event_limit_;

};


#endif /* MESSENGERI_H_  */
