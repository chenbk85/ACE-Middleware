 // $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/orbsvcs/tests/Property
//
// = FILENAME
//    client.cpp
//
// = DESCRIPTION
//    Test client for the Property Service.
//
// = AUTHORS
//    Alexander Babu Arulanthu <alex@cs.wustl.edu>
//
// ============================================================================

#include "client.h"

ACE_RCSID(CosPropertyService, client, "$Id$")

  Client::Client (void)
{
}

int
Client::init (int argc,
              char *argv[],
              CORBA::Environment &ACE_TRY_ENV)
{
  // Init the ORB.
  manager_.init (argc,
                 argv,
                 ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  // Open the ORB.
  manager_.orb ()->open ();

  // Initialize the naming services
  if (my_name_client_.init (manager_.orb()) != 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       " (%P|%t) Unable to initialize "
                       "the TAO_Naming_Client. \n"),
                      -1);

  // Bind PropertySetDef Object.

  CosNaming::Name propsetdef_name (1);
  propsetdef_name.length (1);
  propsetdef_name [0].id = CORBA::string_dup ("PropertySetDef");
  CORBA::Object_var propsetdef_obj = my_name_client_->resolve (propsetdef_name,
							       ACE_TRY_ENV);
  ACE_CHECK_RETURN (1);

  ACE_DEBUG ((LM_DEBUG, "Naming resolve done\n"));

  this->propsetdef_ = CosPropertyService::PropertySetDef::_narrow (propsetdef_obj.in (),
                                                                   ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  if (CORBA::is_nil (this->propsetdef_.in ()))
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Couldnot resolve propsetdef in Naming server"),
                      -1);
  
  return 0;
}

// Testing the methods of the property service.

int
Client::property_tester (CORBA::Environment &ACE_TRY_ENV)
{
  // = Testing PropertySet & Iterators.

  // Testing define_property () of PropertySet interface.
  this->test_define_property (ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  // Test the number of properties.
  this->test_get_number_of_properties (ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  // Testing get_all_property_names.
  this->test_get_all_property_names (ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  // Test get_property_value.
  this->test_get_property_value (ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  // Testing delete property.
  this->test_delete_property ("no_property",ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  // Testing get_properties.
  this->test_get_properties (ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  // Testing delete_properties.
  this->test_delete_properties (ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  // Test the number of properties.
  this->test_get_number_of_properties (ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  // Testing define_properties.
  this->test_define_properties (ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  // Test the number of properties.
  this->test_get_number_of_properties (ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  // Testing get_all_property_names.
  this->test_get_all_property_names (ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  // Testing get_all_properties.
  this->test_get_all_properties (ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  // = Testing PropertySetDef & Iterators.

  // Testing define_property_with_mode.
  this->test_define_property_with_mode (ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);
  
  return 0;
}

// Testing define_property.

int
Client::test_define_property (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_DEBUG ((LM_DEBUG,
              "\nChecking define_property\n"));

  CORBA::Any anyval;

  // Prepare a char and "define" that in the PropertySet.
  CORBA::Char ch = '#';
  anyval <<= CORBA::Any::from_char (ch);
  ch = '*';
  anyval >>= CORBA::Any::to_char (ch);

  ACE_DEBUG ((LM_DEBUG,
              "Main : Char ch = %c\n",
              ch));
  this->propsetdef_->define_property ("char_property",
				      anyval,
				      ACE_TRY_ENV);

  // Check if that is an user exception, if so, print it out.
  if ((ACE_TRY_ENV.exception () != 0) &&
      (CORBA::UserException::_narrow (ACE_TRY_ENV.exception ()) != 0))
    {
      ACE_TRY_ENV.print_exception ("char_property");
      ACE_TRY_ENV.clear ();
    }

  // Prepare a Short and "define" that in the PropertySet.
  CORBA::Short s = 3;
  anyval <<= s;
  s = 7;
  anyval >>= s;

  ACE_DEBUG ((LM_DEBUG,
              "Main : Short s = %d\n",
              s));
  propsetdef_->define_property ("short_property",
				anyval,
				ACE_TRY_ENV);

  // Check if that is an user exception, if so, print it out.
  if ((ACE_TRY_ENV.exception () != 0) &&
      (CORBA::UserException::_narrow (ACE_TRY_ENV.exception ()) != 0))
    {
      ACE_TRY_ENV.print_exception ("char_property");
      ACE_TRY_ENV.clear ();
    }

  // Prepare a Long and "define" that in the PropertySet.
  CORBA::Long l = 931232;
  anyval <<= l;
  l = 931233;
  anyval >>= l;
  ACE_DEBUG ((LM_DEBUG,
              "Main : Long l = %d\n",
              l));
  CORBA::Any newany(anyval);
  propsetdef_->define_property ("long_property",
				anyval,
				ACE_TRY_ENV);

  // Check if that is an user exception, if so, print it out.
  if ((ACE_TRY_ENV.exception () != 0) &&
      (CORBA::UserException::_narrow (ACE_TRY_ENV.exception ()) != 0))
    {
      ACE_TRY_ENV.print_exception ("char_property");
      ACE_TRY_ENV.clear ();
    }

  // Prepare a Float and "define" that in the PropertySet.
  CORBA::Float f = 3.14F;
  anyval <<= f;
  f = 4.14F;
  anyval >>= f;
  ACE_DEBUG ((LM_DEBUG,
              "Main : Float f = %f\n",
              f));
  propsetdef_->define_property ("float_property",
				anyval,
				ACE_TRY_ENV);

  // Check if that is an user exception, if so, print it out.
  if ((ACE_TRY_ENV.exception () != 0) &&
      (CORBA::UserException::_narrow (ACE_TRY_ENV.exception ()) != 0))
    {
      ACE_TRY_ENV.print_exception ("char_property");
      ACE_TRY_ENV.clear ();
    }

  // Prepare a String and "define" that in the PropertySet.
  ACE_DEBUG ((LM_DEBUG,
              "Main: Any holding String\n"));
  CORBA::String_var strvar (CORBA::string_dup ("Test_String"));
  anyval <<= strvar.in ();
  CORBA::String newstr;
  anyval >>= newstr;
  ACE_DEBUG ((LM_DEBUG,
              "Main: String :  %s, From any :  %s\n",
              strvar.in (),
              newstr));
  propsetdef_->define_property ("string_property",
				anyval,
				ACE_TRY_ENV);

  // Check if that is an user exception, if so, print it out.
  if ((ACE_TRY_ENV.exception () != 0) &&
      (CORBA::UserException::_narrow (ACE_TRY_ENV.exception ()) != 0))
    {
      ACE_TRY_ENV.print_exception ("string_property");
      ACE_TRY_ENV.clear ();
    }

  return 0;
}

// Testing get_all_property_names of the PropertySet.

int
Client::test_get_all_property_names (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_DEBUG ((LM_DEBUG,
              "\nTesting get_all_property_names ()\n"));

  // Get the size.
  CORBA::ULong num_of_properties =
    propsetdef_->get_number_of_properties (ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  // Get half on the names and half of on the iterator.
  CORBA::ULong how_many = num_of_properties / 2;
  
  // The extra ptr's and out's required to avoind SunnCC's warning
  // when foo.out () is passed to a funtion.
  CosPropertyService::PropertyNames_var names_var;
  CosPropertyService::PropertyNames_ptr names_ptr = 0;
  CosPropertyService::PropertyNames_out names_out (names_ptr);
  
  CosPropertyService::PropertyNamesIterator_var iterator_var;
  CosPropertyService::PropertyNamesIterator_ptr iterator_ptr;
  CosPropertyService::PropertyNamesIterator_out iterator_out (iterator_ptr);
  
  propsetdef_->get_all_property_names (how_many,
                                       names_out,
                                       iterator_out,
                                       ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);
  
  // Get the values back to var.
  names_var = names_out.ptr ();
  iterator_var = iterator_out.ptr ();
  
  // Print out the names in the names-sequence.
  if (names_var.ptr () != 0)
    {
      CORBA::ULong len = names_var->length ();

      for (CORBA::ULong ni = 0; ni < len; ni++)
        ACE_DEBUG ((LM_DEBUG,
                    "%s\n",
                    (const char *) names_var [ni]));
    }

  // Iterate thru and print out the names in the iterator, if any.
  if (iterator_var.ptr () != 0)
    {
      // Helper variables to stop the SunCC warnings on on foo.out
      // (). 
      CosPropertyService::PropertyName  name_ptr = 0;
      CosPropertyService::PropertyName_out name_out (name_ptr);
      
      // Call the function.
      CORBA::Boolean next_one_result = iterator_var->next_one (name_out, ACE_TRY_ENV);
      
      // Get the values back on a _var variable.
      CosPropertyService::PropertyName_var name_var = name_out.ptr ();
      
      while (next_one_result == 1)
        {
          ACE_CHECK_RETURN (-1);
          ACE_DEBUG ((LM_DEBUG, "%s\n", name_var.in ()));
          
          // Call the function to iterate again.
          next_one_result = iterator_var->next_one (name_out, ACE_TRY_ENV);
          
          // Get the values back on a _var variable.
          name_var = name_out.ptr ();
        }

      ACE_CHECK_RETURN (-1);
    }
  
  return 0;
}

// Test get_properties. Give a sequence of names and get all their
// properties.

int
Client::test_get_properties (CORBA::Environment &ACE_TRY_ENV)
{
  // Get float_property, string_property and no_property. If return
  // value is false and type is tc_void then that name is not there in
  // the PropertySet.
  ACE_DEBUG ((LM_DEBUG, "\nTesting get_properties\n"));
  CosPropertyService::PropertyNames_var names;
  CosPropertyService::PropertyNames_ptr names_ptr;

  ACE_NEW_RETURN (names_ptr,
                  CosPropertyService::PropertyNames,
                  -1);
  names = names_ptr;

  names->length (3);
  names [0] = CORBA::string_dup ("float_property");
  //names [1] = CORBA::string_dup ("string_property");
  names [1] = CORBA::string_dup ("long_property");
  names [2] = CORBA::string_dup ("char_property");
  //names [2] = CORBA::string_dup ("no_property");


  CosPropertyService::Properties_ptr properties_ptr = 0;
  CosPropertyService::Properties_out properties_out (properties_ptr);

  // Get the properties.
  CORBA::Boolean return_val = propsetdef_->get_properties (names.in (),
                                                           properties_out,
                                                           ACE_TRY_ENV);
  ACE_UNUSED_ARG (return_val);
  ACE_CHECK_RETURN (-1);
  
  // Get the value to the _var.
  CosPropertyService::Properties_var properties = properties_out.ptr ();
  
  if (properties.ptr () != 0)
    {
      // Go thru the properties and print them out, if they are not
      // _tc_void typed values.
      CORBA::ULong len = properties->length ();

      for (CORBA::ULong pi = 0; pi < len; pi++)
        {
          // Print the name.
          ACE_DEBUG ((LM_DEBUG,
                      "%s : ",
                      (const char *) properties [pi].property_name.in ()));

          // Print the value.
          CORBA::Any::dump (properties [pi].property_value);
        }
    }
  return 0;
}

// Testing, get_number_of_properties.

int
Client::test_get_number_of_properties (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_DEBUG ((LM_DEBUG,
              "\nNumber of props : %d\n",
              this->propsetdef_->get_number_of_properties (ACE_TRY_ENV)));
  ACE_CHECK_RETURN (-1);

  return 0;
}

// Test delete_property.

int
Client::test_delete_property (CORBA::String property_name,
                              CORBA::Environment &ACE_TRY_ENV)
{
  ACE_UNUSED_ARG (ACE_TRY_ENV);

  ACE_DEBUG ((LM_DEBUG, "\nDeleting %s\n",property_name));

  ACE_TRY
    {
      this->propsetdef_->delete_property (property_name,
                                          ACE_TRY_ENV);
      ACE_TRY_CHECK;
    }
  ACE_CATCH (CORBA::UserException, ex)
    {
      ACE_PRINT_EXCEPTION (ex, "User exception");
      return -1;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ex, "Not an user exception");
      return -1;
    }
  ACE_ENDTRY;

  return 0;
}

// Test delete_properties.
// Make a sequence of property names and delete them from the
// PropertySet.  Deleting char, short, long, float and string
// properties.

int
Client::test_delete_properties (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_DEBUG ((LM_DEBUG,
              "\nChecking delete_properties\n"));
  CosPropertyService::PropertyNames prop_names;
  prop_names.length (3);
  prop_names [0] = CORBA::string_dup ("char_property");
  prop_names [1] = CORBA::string_dup ("short_property");
  prop_names [2] = CORBA::string_dup ("long_property");
  // prop_names [3] = CORBA::string_dup ("no_property");
  ACE_DEBUG ((LM_DEBUG,
              "Length of sequence %d, Maxlength : %d\n",
              prop_names.length (),
              prop_names.maximum ()));
  this->propsetdef_->delete_properties (prop_names,
					ACE_TRY_ENV);
  ACE_CHECK_RETURN ( 0);

  return 0;
}

// Defines a sequnce of properties containing, char, short, long,
// float in the property set.

int
Client::test_define_properties (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_DEBUG ((LM_DEBUG,
              "\nChecking define_properties\n"));
  CosPropertyService::Properties nproperties;
  nproperties.length (4);
  CORBA::Any anyval;
  // Prepare a char and "define" that in the PropertySet.
  CORBA::Char ch = '#';
  anyval <<= CORBA::Any::from_char (ch);
  ch = '*';
  anyval >>= CORBA::Any::to_char (ch);
  nproperties[0].property_name  = CORBA::string_copy ("char_property");
  nproperties[0].property_value <<= CORBA::Any::from_char (ch);

  // Prepare a Short and "define" that in the PropertySet.
  CORBA::Short s = 3;
  anyval <<= s;
  s = 7;
  anyval >>= s;
  nproperties[1].property_name  = CORBA::string_copy ("short_property");
  nproperties[1].property_value <<= s;

  // Prepare a Long and "define" that in the PropertySet.
  CORBA::Long l = 931232;
  anyval <<= l;
  l = 931233;
  anyval >>= l;
  nproperties[2].property_name  = CORBA::string_copy ("long_property");
  nproperties[2].property_value <<= l;

  // Prepare a Float and "define" that in the PropertySet.
  CORBA::Float f = 3.14F;
  anyval <<= f;
  f = 4.14F;
  anyval >>= f;
  nproperties[3].property_name  = CORBA::string_copy ("float_property");
  nproperties[3].property_value <<= f;

  // Define this sequence of properties now.
  this->propsetdef_->define_properties (nproperties, ACE_TRY_ENV);
  ACE_CHECK_RETURN ( -1);

  return 0;
}

// Test get_all_properties.

int
Client::test_get_all_properties (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_DEBUG ((LM_DEBUG,
              "\nTesting get_all_properties\n"));
  // Get the number of current properties.
  CORBA::ULong num_of_properties =
    this->propsetdef_->get_number_of_properties (ACE_TRY_ENV);
  ACE_UNUSED_ARG (num_of_properties);
  ACE_CHECK_RETURN ( -1);

  // Get half on the properties and half of on the iterator.
  CORBA::ULong how_many = 1;

  // Helper variables to avoid SunCC warnings.
  CosPropertyService::Properties_ptr properties_ptr = 0;
  CosPropertyService::Properties_out properties_out (properties_ptr);
  CosPropertyService::PropertiesIterator_ptr iterator_ptr = 0;
  CosPropertyService::PropertiesIterator_out iterator_out (iterator_ptr);
  
  propsetdef_->get_all_properties (how_many,
                                   properties_out,
                                   iterator_out,
                                   ACE_TRY_ENV);
  ACE_CHECK_RETURN ( -1);
  
  // Get these values to the _var's.
  CosPropertyService::Properties_var properties = properties_out.ptr ();
  CosPropertyService::PropertiesIterator_var iterator = iterator_out.ptr ();
  
  // Print out the properties now.
  if (properties.ptr () != 0)
    {
      CORBA::ULong len = properties->length ();

      for (CORBA::ULong pi = 0; pi < len; pi++)
        {
          // Print the property_name.
          ACE_DEBUG ((LM_DEBUG,
                      "%s : ",
                      properties [pi].property_name.in ()));

          // Print the value if type is not tk_void.
          if (properties [pi].property_value.type () == CORBA::_tc_void)
            ACE_DEBUG ((LM_DEBUG,"Void\n"));

          if (properties [pi].property_value.type () == CORBA::_tc_float)
            {
              CORBA::Float f;
              properties [pi].property_value >>= f;
              ACE_DEBUG ((LM_DEBUG,"%f\n", f));
            }

          if (properties [pi].property_value.type () == CORBA::_tc_string)
            {
              CORBA::String str;
              properties [pi].property_value >>= str;
              ACE_DEBUG ((LM_DEBUG,"%s\n", str));
            }

          if (properties [pi].property_value.type () == CORBA::_tc_long)
            {
              CORBA::Long l;
              properties [pi].property_value >>= l;
              ACE_DEBUG ((LM_DEBUG,"%d\n", l));
            }
        }
    }

  // Pass thru the iterator.
  if (iterator.ptr () != 0)
    {
      // Helper variables to avoid warnings with .out () in SunCC.
      CosPropertyService::Property* property_ptr = 0;
      CosPropertyService::Property_out property_out (property_ptr);
      
      // Call the funtion.
      CORBA::Boolean next_one_result = iterator->next_one (property_out,
                                                           ACE_TRY_ENV); 
      
      // Get the value to the _var variable.
      CosPropertyService::Property_var property = property_out.ptr ();

      while (next_one_result != 0)
        {
          ACE_DEBUG ((LM_DEBUG, "Iteration over PropertyIterartor"));
          ACE_CHECK_RETURN ( -1);
          ACE_DEBUG ((LM_DEBUG,
                      "%s : ",
                      property->property_name.in ()));

          // Print the property_value.
          if (property->property_value.type () == CORBA::_tc_char)
            {
              CORBA::Char c;
              property->property_value >>= CORBA::Any::to_char (c);
              ACE_DEBUG ((LM_DEBUG,"%c\n", c));
            }

          if (property->property_value.type () == CORBA::_tc_short)
            {
              CORBA::Short s;
              property->property_value >>= s;
              ACE_DEBUG ((LM_DEBUG,"%d\n", s));
            }

          if (property->property_value.type () == CORBA::_tc_float)
            {
              CORBA::Float f;
              property->property_value >>= f;
              ACE_DEBUG ((LM_DEBUG,"%f\n", f));
            }

          if (property->property_value.type () == CORBA::_tc_string)
            {
              CORBA::String str;
              property->property_value >>= str;
              ACE_DEBUG ((LM_DEBUG,"%s\n", str));
            }

          if (property->property_value.type () == CORBA::_tc_long)
            {
              CORBA::Long l;
              property->property_value >>= l;
              ACE_DEBUG ((LM_DEBUG,"%d\n", l));
            }
          
          // Call the function for the next iteraton.
          next_one_result = iterator->next_one (property_out,
                                                ACE_TRY_ENV); 
      
          // Get the value to the _var variable.
          property = property_out.ptr ();
        }
      ACE_CHECK_RETURN ( -1);
    }
  return 0;
}

// Testing define property with mode.
// Defines char, short, long and float properties with different modes.
int
Client::test_define_property_with_mode (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_DEBUG ((LM_DEBUG,
              "\nChecking define_property_with_mode\n"));

  CORBA::Any anyval;

  // Prepare a char and "define" that in the PropertySet.
  CORBA::Char ch = '#';
  anyval <<= CORBA::Any::from_char (ch);
  ch = '*';
  anyval >>= CORBA::Any::to_char (ch);

  ACE_DEBUG ((LM_DEBUG,
              "Main : Char ch = %c\n",
              ch));
  this->propsetdef_->define_property_with_mode ("char_property",
                                                anyval,
                                                CosPropertyService::normal,
                                                ACE_TRY_ENV);
  // Check if that is an user exception, if so, print it out.
  if ((ACE_TRY_ENV.exception () != 0) &&
      (CORBA::UserException::_narrow (ACE_TRY_ENV.exception ()) != 0))
    {
      ACE_TRY_ENV.print_exception ("char_property");
      ACE_TRY_ENV.clear ();
    }

  // Prepare a Short and "define" that in the PropertySet.
  CORBA::Short s = 3;
  anyval <<= s;
  s = 7;
  anyval >>= s;

  ACE_DEBUG ((LM_DEBUG,
              "Main : Short s = %d\n",
              s));
  propsetdef_->define_property_with_mode ("short_property",
                                          anyval,
                                          CosPropertyService::read_only,
                                          ACE_TRY_ENV);
  // Check if that is an user exception, if so, print it out.
  if (ACE_TRY_ENV.exception () != 0)
    {
      ACE_TRY_ENV.print_exception ("char_property");
      if (CORBA::UserException::_narrow (ACE_TRY_ENV.exception ()) != 0)
        ACE_TRY_ENV.clear ();
      else
        return -1;
    }


  // Prepare a Long and "define" that in the PropertySet.
  CORBA::Long l = 931232;
  anyval <<= l;
  l = 931233;
  anyval >>= l;
  ACE_DEBUG ((LM_DEBUG,
              "Main : Long l = %d\n",
              l));
  CORBA::Any newany(anyval);
  propsetdef_->define_property_with_mode ("long_property",
					  anyval,
					  CosPropertyService::fixed_normal,
					  ACE_TRY_ENV);
  ACE_CHECK_RETURN ( -1);


  // Prepare a Float and "define" that in the PropertySet.
  CORBA::Float f = 3.14F;
  anyval <<= f;
  f = 4.14F;
  anyval >>= f;
  ACE_DEBUG ((LM_DEBUG,
              "Main : Float f = %f\n",
              f));
  propsetdef_->define_property_with_mode ("float_property",
					  anyval,
					  CosPropertyService::fixed_readonly,
					  ACE_TRY_ENV);
  ACE_CHECK_RETURN ( -1);

  // Prepare a String and "define" that in the PropertySet.
  ACE_DEBUG ((LM_DEBUG,
              "Main: Any holding String\n"));
  CORBA::String_var strvar (CORBA::string_dup ("Test_String"));
  anyval <<= strvar.in ();
  CORBA::String newstr;
  anyval >>= newstr;

  ACE_DEBUG ((LM_DEBUG,
              "Main: String :  %s, From any :  %s\n",
              strvar.in (),
              newstr));
  propsetdef_->define_property  ("string_property",
                                 anyval,
                                 ACE_TRY_ENV);
  ACE_CHECK_RETURN ( -1);
  
  return 0;
}

int
Client::test_get_property_value (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_UNUSED_ARG (ACE_TRY_ENV);

  ACE_DEBUG ((LM_DEBUG, "Testing get_property_value\n"));

  ACE_TRY
    {
      // Get the ior property.
      CORBA::Any_ptr any_ptr = this->propsetdef_->get_property_value ("PropertySetDef_IOR",
                                                                      ACE_TRY_ENV);
      ACE_TRY_CHECK;
      
      ACE_DEBUG ((LM_DEBUG, "Property value received successfully\n"));

      // Check whether the IOR is fine.
      CORBA::Object_var propsetdef_object;
      (*any_ptr) >>= CORBA::Any::to_object (propsetdef_object.out ());
      
      CosPropertyService::PropertySetDef_var propsetdef =
        CosPropertyService::PropertySetDef::_narrow (propsetdef_object.in (),
                                                     ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (propsetdef.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           "invalid object reference\n"),
                          -1);

      ACE_DEBUG ((LM_DEBUG, "IOR retrieved\n"));
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "get_property_value");
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (1);
  return 0;
}

int
main (int argc, char **argv)
{
  ACE_DECLARE_NEW_CORBA_ENV;

  ACE_TRY
    {
      Client client;

      if (client.init (argc,
                       argv,
                       ACE_TRY_ENV) == -1)
        return 1;
      ACE_TRY_CHECK;

      //  client.run (ACE_TRY_ENV);
      if (client.property_tester (ACE_TRY_ENV) != 0)
        ACE_DEBUG ((LM_DEBUG, "Test failed\n"));
      else
        ACE_DEBUG ((LM_DEBUG, "Test succeeded\n"));
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "PropertyService Test : client");
      return -1;
    }
 ACE_ENDTRY;
 
  return 0;
}
