// $Id$

#include "tao/Asynch_Reply_Dispatcher_Base.h"
#include "tao/Pluggable_Messaging_Utils.h"
#include "tao/ORB_Core.h"
#include "tao/debug.h"
#include "tao/Transport.h"

#if !defined (__ACE_INLINE__)
#include "tao/Asynch_Reply_Dispatcher_Base.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID (tao,
           Asynch_Reply_Dispatcher_Base,
           "$Id$")

// Constructor.
TAO_Asynch_Reply_Dispatcher_Base::TAO_Asynch_Reply_Dispatcher_Base (
    TAO_ORB_Core *orb_core
  )
  : db_ (sizeof buf_,
         ACE_Message_Block::MB_DATA,
         this->buf_,
         orb_core->input_cdr_buffer_allocator (),
         orb_core->locking_strategy (),
         ACE_Message_Block::DONT_DELETE,
         orb_core->input_cdr_dblock_allocator ()),
    reply_cdr_ (&db_,
                ACE_Message_Block::MB_DATA,
                TAO_ENCAP_BYTE_ORDER,
                TAO_DEF_GIOP_MAJOR,
                TAO_DEF_GIOP_MINOR,
                orb_core)
  , transport_ (0)
  , lock_ (0)
  , refcount_ (1)
  , is_reply_dispatched_ (false)
{
  // @@ NOTE: Need a seperate option for this..
  this->lock_ =
    orb_core->resource_factory ()->create_cached_connection_lock ();
}

// Destructor.
TAO_Asynch_Reply_Dispatcher_Base::~TAO_Asynch_Reply_Dispatcher_Base (void)
{
  // Release the transport that we own
  if (this->transport_ != 0)
    this->transport_->remove_reference ();

  if (this->lock_)
    delete this->lock_;
}

void
TAO_Asynch_Reply_Dispatcher_Base::transport (TAO_Transport *t)
{
  if (this->transport_ != 0)
    this->transport_->remove_reference ();

  this->transport_ = t;

  this->transport_->add_reference ();
}

// Must override pure virtual method in TAO_Reply_Dispatcher.
int
TAO_Asynch_Reply_Dispatcher_Base::dispatch_reply (
    TAO_Pluggable_Reply_Params & /*params*/
  )
{
  return 0;
}

void
TAO_Asynch_Reply_Dispatcher_Base::connection_closed (void)
{
}

void
TAO_Asynch_Reply_Dispatcher_Base::reply_timed_out (void)
{
}

long
TAO_Asynch_Reply_Dispatcher_Base::schedule_timer (
    CORBA::ULong /*request_id */,
    const ACE_Time_Value & /*max_wait_time*/
  )
{
  return 0;
}

long
TAO_Asynch_Reply_Dispatcher_Base::incr_refcount (void)
{
  ACE_GUARD_RETURN (ACE_Lock,
                    mutex,
                    *this->lock_,
                    -1);
  return ++this->refcount_;
}

long
TAO_Asynch_Reply_Dispatcher_Base::decr_refcount (void)
{
  {
    ACE_GUARD_RETURN (ACE_Lock,
                      mutex,
                      *this->lock_,
                      -1);
    --this->refcount_;

    if (this->refcount_ > 0)
      return this->refcount_;
  }

  delete this;

  return 0;
}

bool
TAO_Asynch_Reply_Dispatcher_Base::try_dispatch_reply (void)
{
  if (this->is_reply_dispatched_)
    return false;

  if (!this->is_reply_dispatched_)
    {
      ACE_GUARD_RETURN (ACE_Lock,
                        mutex,
                        *this->lock_,
                        false);

      if (!this->is_reply_dispatched_)
        {
          this->is_reply_dispatched_ = true;
          return true;
        }
    }

  return false;
}
