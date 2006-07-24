//
// $Id$
//
// -*- C++ -*-

#if !defined BUG_1330_REGRESSION_TEST_I_H
 #define BUG_1330_REGRESSION_TEST_I_H

#include "TestS.h"

class Test_i: public POA_Test
{
public:
   /// Constructor
   Test_i (void);

   /// Destructor
   ~Test_i (void);

   /// A method
   void test_method(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
     ACE_THROW_SPEC ((CORBA::SystemException));
};

#endif /* ! BUG_1330_REGRESSION_TEST_I_H */
