// $Id$

#include "GPS_exec.h"
#include "CIAO_common.h"

#include "ace/OS_NS_time.h"

#define DISPLACEMENT 256

// Operations from HUDisplay::position
CORBA::Long
MyImpl::Position_Impl::posx (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return component_.posx();
}

CORBA::Long
MyImpl::Position_Impl::posy (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return component_.posy();
}


/// Default constructor.
MyImpl::GPS_exec_i::GPS_exec_i ()
{
  ACE_OS::srand ((u_int) ACE_OS::time ());
  this->positionx_ = ACE_OS::rand ();
  this->positiony_ = ACE_OS::rand ();
}

/// Default destructor.
MyImpl::GPS_exec_i::~GPS_exec_i ()
{
}

// Operations from HUDisplay::GPS
  HUDisplay::CCM_position_ptr
  MyImpl::GPS_exec_i::get_MyLocation (void)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
//     ACE_DEBUG ((LM_DEBUG,
//                 "GPS_exec::get_MyLocation called\n "));
    return (new Position_Impl (*this));
  }

void
MyImpl::GPS_exec_i::push_Refresh (HUDisplay::tick *
                                  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
//   ACE_DEBUG ((LM_DEBUG,
// 	      ACE_TEXT ("GPS: Received Refresh Event\n")));

  // Refresh position
  this->positionx_ += ACE_OS::rand () % DISPLACEMENT - (DISPLACEMENT/2);
  this->positiony_ += ACE_OS::rand () % DISPLACEMENT - (DISPLACEMENT/2);

  // Nitify others
  HUDisplay::tick_var event = new OBV_HUDisplay::tick;

  this->context_->push_Ready (event
                              ACE_ENV_ARG_PARAMETER);
}

CORBA::Long
MyImpl::GPS_exec_i::posx (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->positionx_;
}

CORBA::Long
MyImpl::GPS_exec_i::posy (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->positiony_;
}


// Operations from Components::SessionComponent
void
MyImpl::GPS_exec_i::set_session_context (Components::SessionContext_ptr ctx
                                         ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  if (CIAO::debug_level () > 0)
    ACE_DEBUG ((LM_DEBUG, "MyImpl::GPS_exec_i::set_session_context\n"));

  this->context_ =
    HUDisplay::CCM_GPS_Context::_narrow (ctx
                                         ACE_ENV_ARG_PARAMETER);

  if (CORBA::is_nil (this->context_.in ()))
    ACE_THROW (CORBA::INTERNAL ());
  // Urm, we actually discard exceptions thown from this operation.
}

void
MyImpl::GPS_exec_i::ciao_preactivate (void)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
}

void
MyImpl::GPS_exec_i::ccm_activate (void)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  if (CIAO::debug_level () > 0)
    ACE_DEBUG ((LM_DEBUG, "MyImpl::GPS_exec_i::ccm_activate\n"));
}

void
MyImpl::GPS_exec_i::ciao_postactivate (void)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
}

void
MyImpl::GPS_exec_i::ccm_passivate (void)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  if (CIAO::debug_level () > 0)
    ACE_DEBUG ((LM_DEBUG, "MyImpl::GPS_exec_i::ccm_passivate\n"));
}

void
MyImpl::GPS_exec_i::ccm_remove (void)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  if (CIAO::debug_level () > 0)
    ACE_DEBUG ((LM_DEBUG, "MyImpl::GPS_exec_i::ccm_remove\n"));
}

/// Default ctor.
MyImpl::GPSHome_exec_i::GPSHome_exec_i ()
{
}

/// Default dtor.
MyImpl::GPSHome_exec_i::~GPSHome_exec_i ()
{
}

// Explicit home operations.

// Implicit home operations.

::Components::EnterpriseComponent_ptr
MyImpl::GPSHome_exec_i::create (void)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Components::CCMException))
{
  return new MyImpl::GPS_exec_i;
}


extern "C" GPS_EXEC_Export ::Components::HomeExecutorBase_ptr
createGPSHome_Impl (void)
{
  return new MyImpl::GPSHome_exec_i();
}
