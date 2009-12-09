#include "Factory.h"
#include "tao/AnyTypeCode/TypeCode.h"


void
NodeFactory::register_new_factory(CORBA::ORB& orb) {
  CORBA::ValueFactoryBase_var mf = new NodeFactory;
  CORBA::String_var id = ::demo::value::idl::_tc_Node->id();
  orb.register_value_factory(id.in(), mf.in());
}

CORBA::ValueBase*
NodeFactory::create_for_unmarshal(void)
{
  ::CORBA::ValueBase *ret_val = 0;
  ACE_NEW_THROW_EX (
      ret_val,
      OBV_demo::value::idl::Node,
      ::CORBA::NO_MEMORY ()
    );
  return ret_val;
}


void
BoxedValueFactory::register_new_factory(CORBA::ORB& orb) {
  CORBA::ValueFactoryBase_var mf = new BoxedValueFactory;
  OBV_demo::value::idl::boxedValue bv;
  CORBA::String_var id = bv._tao_type()->id ();;
  orb.register_value_factory(id.in(), mf.in());
}

CORBA::ValueBase*
BoxedValueFactory::create_for_unmarshal(void)
{
  ::CORBA::ValueBase *ret_val = 0;
  ACE_NEW_THROW_EX (
      ret_val,
      OBV_demo::value::idl::boxedValue,
      ::CORBA::NO_MEMORY ()
    );
  return ret_val;
}


void
BaseValueFactory::register_new_factory(CORBA::ORB& orb) {
  CORBA::ValueFactoryBase_var mf = new BaseValueFactory;
  OBV_demo::value::idl::BaseValue bv;
  CORBA::String_var id = bv._tao_type()->id ();;
  orb.register_value_factory(id.in(), mf.in());
}

CORBA::ValueBase*
BaseValueFactory::create_for_unmarshal(void)
{
  ::CORBA::ValueBase *ret_val = 0;
  ACE_NEW_THROW_EX (
      ret_val,
      OBV_demo::value::idl::BaseValue,
      ::CORBA::NO_MEMORY ()
    );
  return ret_val;
}


void
TValueFactory::register_new_factory(CORBA::ORB& orb) {
  CORBA::ValueFactoryBase_var mf = new TValueFactory;
  OBV_demo::value::idl::TValue bv;
  CORBA::String_var id = bv._tao_type()->id ();;
  orb.register_value_factory(id.in(), mf.in());
}

CORBA::ValueBase*
TValueFactory::create_for_unmarshal(void)
{
  ::CORBA::ValueBase *ret_val = 0;
  ACE_NEW_THROW_EX (
      ret_val,
      OBV_demo::value::idl::TValue,
      ::CORBA::NO_MEMORY ()
    );
  return ret_val;
}

void
ConfigValueFactory::register_new_factory(CORBA::ORB& orb) {
  CORBA::ValueFactoryBase_var mf = new ConfigValueFactory;
  OBV_demo::value::idl::ConfigValue bv;
  CORBA::String_var id = bv._tao_type()->id ();;
  orb.register_value_factory(id.in(), mf.in());
}

CORBA::ValueBase*
ConfigValueFactory::create_for_unmarshal(void)
{
  ::CORBA::ValueBase *ret_val = 0;
  ACE_NEW_THROW_EX (
      ret_val,
      OBV_demo::value::idl::ConfigValue,
      ::CORBA::NO_MEMORY ()
    );
  return ret_val;
}


ConfigValueImpl::ConfigValueImpl (const char* name, const char* value)
{
  this->name (name);
  this->value () <<= value;
}
