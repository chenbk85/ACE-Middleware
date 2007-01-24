// $Id$

#include "Multiple_InheritanceS.h"

ACE_RCSID(Multiple_Inheritance, Multiple_Inheritance_i, "$Id$")

class Multiple_Inheritance_i : public POA_D
{
public:
  Multiple_Inheritance_i (void);

  virtual char* method1 (void)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return CORBA::string_dup ("method1");
    }
  virtual char* method2 (void)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return CORBA::string_dup ("method2");
    }
  virtual char* method3 (void)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return CORBA::string_dup ("method3");
    }
  virtual char* method4 (void)
    ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return CORBA::string_dup ("method4");
    }
};
