/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

ACE_INLINE void POA_CORBA_ConstructionPolicy::_get_policy_type_skel (
    CORBA::ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::Policy_ptr impl = (POA_CORBA_ConstructionPolicy_ptr) obj;
  POA_CORBA::Policy::_get_policy_type_skel (
      req,
      (POA_CORBA::Policy_ptr) impl,
      context,
      ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA_ConstructionPolicy::copy_skel (
    CORBA::ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::Policy_ptr impl = (POA_CORBA_ConstructionPolicy_ptr) obj;
  POA_CORBA::Policy::copy_skel (
      req,
      (POA_CORBA::Policy_ptr) impl,
      context,
       ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA_ConstructionPolicy::destroy_skel (
    CORBA::ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::Policy_ptr impl = (POA_CORBA_ConstructionPolicy_ptr) obj;
  POA_CORBA::Policy::destroy_skel (
      req,
      (POA_CORBA::Policy_ptr) impl,
      context,
       ACE_TRY_ENV
    );
}
