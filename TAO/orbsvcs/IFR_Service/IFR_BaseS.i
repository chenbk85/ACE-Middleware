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
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

ACE_INLINE void POA_CORBA::Contained::_get_def_kind_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::IRObject_ptr impl = (POA_CORBA::Contained_ptr) obj;
  POA_CORBA::IRObject::_get_def_kind_skel (
      req,
      (POA_CORBA::IRObject_ptr) impl,
      context,
      ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::Contained::destroy_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::IRObject_ptr impl = (POA_CORBA::Contained_ptr) obj;
  POA_CORBA::IRObject::destroy_skel (
      req,
      (POA_CORBA::IRObject_ptr) impl,
      context,
       ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::Container::_get_def_kind_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::IRObject_ptr impl = (POA_CORBA::Container_ptr) obj;
  POA_CORBA::IRObject::_get_def_kind_skel (
      req,
      (POA_CORBA::IRObject_ptr) impl,
      context,
      ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::Container::destroy_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::IRObject_ptr impl = (POA_CORBA::Container_ptr) obj;
  POA_CORBA::IRObject::destroy_skel (
      req,
      (POA_CORBA::IRObject_ptr) impl,
      context,
       ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::IDLType::_get_def_kind_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::IRObject_ptr impl = (POA_CORBA::IDLType_ptr) obj;
  POA_CORBA::IRObject::_get_def_kind_skel (
      req,
      (POA_CORBA::IRObject_ptr) impl,
      context,
      ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::IDLType::destroy_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::IRObject_ptr impl = (POA_CORBA::IDLType_ptr) obj;
  POA_CORBA::IRObject::destroy_skel (
      req,
      (POA_CORBA::IRObject_ptr) impl,
      context,
       ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::TypedefDef::_get_id_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::Contained_ptr impl = (POA_CORBA::TypedefDef_ptr) obj;
  POA_CORBA::Contained::_get_id_skel (
      req,
      (POA_CORBA::Contained_ptr) impl,
      context,
      ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::TypedefDef::_set_id_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::Contained_ptr impl = (POA_CORBA::TypedefDef_ptr) obj;
  POA_CORBA::Contained::_set_id_skel (
      req,
      (POA_CORBA::Contained_ptr) impl,
      context,
      ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::TypedefDef::_get_name_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::Contained_ptr impl = (POA_CORBA::TypedefDef_ptr) obj;
  POA_CORBA::Contained::_get_name_skel (
      req,
      (POA_CORBA::Contained_ptr) impl,
      context,
      ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::TypedefDef::_set_name_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::Contained_ptr impl = (POA_CORBA::TypedefDef_ptr) obj;
  POA_CORBA::Contained::_set_name_skel (
      req,
      (POA_CORBA::Contained_ptr) impl,
      context,
      ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::TypedefDef::_get_version_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::Contained_ptr impl = (POA_CORBA::TypedefDef_ptr) obj;
  POA_CORBA::Contained::_get_version_skel (
      req,
      (POA_CORBA::Contained_ptr) impl,
      context,
      ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::TypedefDef::_set_version_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::Contained_ptr impl = (POA_CORBA::TypedefDef_ptr) obj;
  POA_CORBA::Contained::_set_version_skel (
      req,
      (POA_CORBA::Contained_ptr) impl,
      context,
      ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::TypedefDef::_get_defined_in_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::Contained_ptr impl = (POA_CORBA::TypedefDef_ptr) obj;
  POA_CORBA::Contained::_get_defined_in_skel (
      req,
      (POA_CORBA::Contained_ptr) impl,
      context,
      ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::TypedefDef::_get_absolute_name_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::Contained_ptr impl = (POA_CORBA::TypedefDef_ptr) obj;
  POA_CORBA::Contained::_get_absolute_name_skel (
      req,
      (POA_CORBA::Contained_ptr) impl,
      context,
      ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::TypedefDef::_get_containing_repository_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::Contained_ptr impl = (POA_CORBA::TypedefDef_ptr) obj;
  POA_CORBA::Contained::_get_containing_repository_skel (
      req,
      (POA_CORBA::Contained_ptr) impl,
      context,
      ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::TypedefDef::describe_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::Contained_ptr impl = (POA_CORBA::TypedefDef_ptr) obj;
  POA_CORBA::Contained::describe_skel (
      req,
      (POA_CORBA::Contained_ptr) impl,
      context,
       ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::TypedefDef::move_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::Contained_ptr impl = (POA_CORBA::TypedefDef_ptr) obj;
  POA_CORBA::Contained::move_skel (
      req,
      (POA_CORBA::Contained_ptr) impl,
      context,
       ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::TypedefDef::_get_type_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::IDLType_ptr impl = (POA_CORBA::TypedefDef_ptr) obj;
  POA_CORBA::IDLType::_get_type_skel (
      req,
      (POA_CORBA::IDLType_ptr) impl,
      context,
      ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::TypedefDef::_get_def_kind_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::IRObject_ptr impl = (POA_CORBA::TypedefDef_ptr) obj;
  POA_CORBA::IRObject::_get_def_kind_skel (
      req,
      (POA_CORBA::IRObject_ptr) impl,
      context,
      ACE_TRY_ENV
    );
}
ACE_INLINE void POA_CORBA::TypedefDef::destroy_skel (
    TAO_ServerRequest &req,
    void *obj,
    void *context,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::IRObject_ptr impl = (POA_CORBA::TypedefDef_ptr) obj;
  POA_CORBA::IRObject::destroy_skel (
      req,
      (POA_CORBA::IRObject_ptr) impl,
      context,
       ACE_TRY_ENV
    );
}
