// $Id$

// ============================================================================
//
// = FILENAME
//    Generic_Factory_Impl.h
//
// = DESCRIPTION
//    A LifeCycle Service Generic Factory for the Quoter example.
//
// = AUTHOR
//    Michael Kircher (mk1@cs.wustl.edu)
//
// ============================================================================

#include "QuoterS.h"
#include "Factory_Trader.h"
#include "Criteria_Evaluator.h"

#if !defined (QUOTER_GENERIC_FACTORY_IMPL_H)
#define QUOTER_GENERIC_FACTORY_IMPL_H

class Quoter_Generic_Factory_Impl : public POA_Stock::Quoter_Generic_Factory 
{
  // = TILE
  //   A CosLifeCycle conforming Generic Factory for the Quoter
  //   example. It uses the Naming Service to find a fitting factory.

public:
  Quoter_Generic_Factory_Impl (void);
  ~Quoter_Generic_Factory_Impl (void);

  CORBA::Boolean supports (const CosLifeCycle::Key &factory_key,
                           CORBA::Environment &_env_there);
  // Returns true if the Generic Factory is able to forward a request
  // for creating an object described by the <factory_key>.

  CORBA::Object_ptr create_object (const CosLifeCycle::Key &factory_key, 
                                   const CosLifeCycle::Criteria &the_criteria,
                                   CORBA::Environment &_env_there);
  // Returns an object reference to a newly created object, though the
  // Generic Factory itself cannot create objects, it will forward the
  // request to a more concrete Factory.

  void register_factory (const char * name,
			 const char * location,
			 const char * description,
			 CORBA::Object_ptr object,
			 CORBA::Environment &_env_there);
  // Registers a factory with specified properties

private:
  Stock::Criteria_Evaluator_var criteria_evaluator_var_;
  Factory_Trader *factory_trader_ptr_;  
};

#endif /* QUOTER_GENERIC_FACTORY_IMPL_H */
