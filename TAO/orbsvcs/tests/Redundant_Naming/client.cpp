// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/orbsvcs/Naming_Service/
//
// = FILENAME
//    client.cpp
//
// = DESCRIPTION
//      This class implements a CORBA client for a redundant CosNaming
//      Service using stubs generated by the TAO ORB IDL compiler.
//
// = AUTHORS
//      Rich Seibel <seibel_r@ociweb.com>
// ============================================================================

#include "test_objectS.h"
#include "orbsvcs/CosNamingC.h"
#include "orbsvcs/Naming/Naming_Server.h"
#include "tao/debug.h"
#include "ace/Get_Opt.h"
#include "ace/OS_NS_stdio.h"

ACE_RCSID (Simple_Naming,
           client,
           "$Id$")

#if defined (_MSC_VER)
# pragma warning (disable : 4250)
#endif /* _MSC_VER */

class My_Test_Object :
  public virtual POA_Test_Object
{
public:
  // = Initialization and termination methods.
  My_Test_Object (CORBA::Short id = 0);
  // Constructor.

  ~My_Test_Object (void);
  // Destructor.

  // = Interface implementation accessor methods.

  void id (CORBA::Short id)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Sets id.

  CORBA::Short id (void)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Gets id.

private:
  short id_;
};

My_Test_Object::My_Test_Object (CORBA::Short id)
  : id_ (id)
{
}

My_Test_Object::~My_Test_Object (void)
{
}

CORBA::Short
My_Test_Object::id (void)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  return id_;
}

void
My_Test_Object::id (CORBA::Short id)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  id_ = id;
}


// This function runs the test.

int
main (int argc, ACE_TCHAR **argv)
{
  int c_breath = 4;
  int c_depth = 4;
  int o_breath = 4;
  ACE_TCHAR *ns1ref = 0;
  ACE_TCHAR *ns2ref = 0;

  ACE_Get_Opt get_opts (argc, argv, ACE_TEXT ("b:d:o:p:q:"));
  int c;
  int i;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'b':
        i = ACE_OS::atoi(get_opts.opt_arg ());
        if (i<2)
        {
          ACE_ERROR((LM_ERROR,
                     ACE_TEXT ("Invalid breath, must be 2 or more\n")));
          exit(1);
        }
        c_breath = i;
        break;
      case 'd':
        i = ACE_OS::atoi(get_opts.opt_arg ());
        if (i<2)
        {
          ACE_ERROR((LM_ERROR,
                     ACE_TEXT ("Invalid depth, must be 2 or more\n")));
          exit(1);
        }
        c_depth = i;
        break;
      case 'o':
        i = ACE_OS::atoi(get_opts.opt_arg ());
        if (i<2)
        {
          ACE_ERROR((LM_ERROR,
                     ACE_TEXT ("Invalid breath, must be 2 or more\n")));
          exit(1);
        }
        o_breath = i;
        break;
      case 'p':
        ns1ref = get_opts.opt_arg ();
        break;
      case 'q':
        ns2ref = get_opts.opt_arg ();
        break;
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("Argument %c \n usage:  %s")
                           ACE_TEXT (" [-b <breath of context tree>]")
                           ACE_TEXT (" [-d <depth of context tree>]")
                           ACE_TEXT (" [-o <breath of object tree>]")
                           ACE_TEXT (" -p <ior of first name server>")
                           ACE_TEXT (" -q <ior of second name server>")
                           ACE_TEXT ("\n")),
                          -1);
      }

  CosNaming::NamingContext_var root_context_1;
  CosNaming::NamingContext_var root_context_2;

  try
  {
    // Initialize orb
    CORBA::ORB_var orb = CORBA::ORB_init(argc, argv, 0);

    // ior's are specified for the name servers through a commandline
    // option or a file.

    // Resolve the first name server

    CORBA::Object_var ns1obj = orb->string_to_object (
                            ACE_TEXT_ALWAYS_CHAR (ns1ref));

    if (CORBA::is_nil (ns1obj.in ()))
            ACE_ERROR_RETURN ((LM_ERROR,
                               ACE_TEXT ("invalid ior <%s>\n"),
                               ns1ref),
                              -1);
    root_context_1 = CosNaming::NamingContext::_narrow (ns1obj.in ());


    // Resolve the second name server

    CORBA::Object_var ns2obj = orb->string_to_object (
                            ACE_TEXT_ALWAYS_CHAR (ns2ref));

    if (CORBA::is_nil (ns2obj.in ()))
            ACE_ERROR_RETURN ((LM_ERROR,
                               ACE_TEXT ("invalid ior <%s>\n"),
                               ns2ref),
                              -1);
    root_context_2 = CosNaming::NamingContext::_narrow (ns2obj.in ());

  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (ACE_TEXT ("Unable to resolve name servers"));
    return -1;
  }

  // Create a bunch of objects in one context
  // Note: strings to the naming service must be char, not wchar
  try
  {
    // Bind one context level under root.
    CosNaming::Name level1;
    level1.length (1);
    level1[0].id = CORBA::string_dup ("level1_context");
    CosNaming::NamingContext_var level1_context;
    level1_context = root_context_1->bind_new_context (level1);
    for (i=0; i<o_breath; i++)
    {
      // Instantiate a dummy object and bind it under the new context.
      My_Test_Object *impl1 = new My_Test_Object (i+1);
      Test_Object_var obj1 = impl1->_this ();
      impl1->_remove_ref ();

      CosNaming::Name obj_name;
      obj_name.length (1);
      char wide_name[16];
      ACE_OS::sprintf(wide_name, "obj_%d", i);
      obj_name[0].id = CORBA::string_dup (wide_name);
      level1_context->bind (obj_name, obj1.in ());
    }

  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (ACE_TEXT ("Unable to create a lot of objects"));
    return -1;
  }

  // Create a deep context tree
  try
  {
    CosNaming::NamingContext_var next_context = root_context_1;
    for (i=0; i<c_depth; i++)
    {
      // Bind level1 context under root.
      CosNaming::Name deep;
      deep.length (1);
      char deep_name[16];
      ACE_OS::sprintf(deep_name, "deep_%d", i);
      deep[0].id = CORBA::string_dup (deep_name);
      CosNaming::NamingContext_var deep_context;
      deep_context = next_context->bind_new_context (deep);
      next_context = deep_context;
    }
  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (ACE_TEXT ("Unable to create deep context"));
    return -1;
  }

  // Create a wide context tree
  try
  {
    for (i=0; i<c_breath; i++)
    {
      // Bind all level of context under root.
      CosNaming::Name wide;
      wide.length (1);
      char wide_name[16];
      ACE_OS::sprintf(wide_name, "wide_%d", i);
      wide[0].id = CORBA::string_dup (wide_name);
      CosNaming::NamingContext_var wide_context;
      wide_context = root_context_1->bind_new_context (wide);
    }
  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (ACE_TEXT ("Unable to create wide context"));
    return -1;
  }

  // Delete three selected things, one from each tree
  try
  {
    // Remove the second to last object from the Naming Context
    CosNaming::Name wide1;
    wide1.length (2);
    wide1[0].id = CORBA::string_dup ("level1_context");
    char wide_name[16];
    ACE_OS::sprintf(wide_name, "obj_%d", o_breath-2);
    wide1[1].id = CORBA::string_dup (wide_name);
    root_context_1->unbind (wide1);

    // Remove the second to last context from the wide root Naming Context
    CosNaming::Name wide2;
    wide2.length (1);
    ACE_OS::sprintf(wide_name, "wide_%d", c_breath-2);
    wide2[0].id = CORBA::string_dup (wide_name);
    CORBA::Object_var result_obj_ref = root_context_1->resolve (wide2);
    CosNaming::NamingContext_var result_object =
      CosNaming::NamingContext::_narrow (result_obj_ref.in ());
    if (CORBA::is_nil (result_object.in ()))
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("Problems with resolving wide context ")
                         ACE_TEXT ("- nil object ref.\n")),
                         -1);
    result_object->destroy();
    root_context_1->unbind (wide2);

    // Remove the last context from the deep Naming Context
    CosNaming::Name deep;
    deep.length (c_depth);
    char deep_name[16];
    for (i=0; i<c_depth; i++)
    {
      ACE_OS::sprintf(deep_name, "deep_%d", i);
      deep[i].id = CORBA::string_dup (deep_name);
    }
    result_obj_ref = root_context_1->resolve (deep);
    result_object =
      CosNaming::NamingContext::_narrow (result_obj_ref.in ());
    if (CORBA::is_nil (result_object.in ()))
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("Problems with resolving deep context ")
                         ACE_TEXT ("- nil object ref.\n")),
                         -1);
    result_object->destroy();
    root_context_1->unbind (deep);

  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (ACE_TEXT ("Unable to delete objects"));
    return -1;
  }

  // Now use the other name server to access 3 objects next to the
  // deleted objects and the 3 deleted objects
  try
  {
    // Access the last object from the Naming Context
    CosNaming::Name wide;
    wide.length (2);
    wide[0].id = CORBA::string_dup ("level1_context");
    char wide_name[16];
    ACE_OS::sprintf(wide_name, "obj_%d", o_breath-1);
    wide[1].id = CORBA::string_dup (wide_name);
    CORBA::Object_var result_obj_ref = root_context_2->resolve (wide);
    Test_Object_var result_object = Test_Object::_narrow (result_obj_ref.in ());
    if (CORBA::is_nil (result_object.in ()))
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("Problems with resolving object from ")
                         ACE_TEXT ("redundant server - nil object ref.\n")),
                         -1);
  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (
      ACE_TEXT (
        "Unable to resolve object from redundant server"));
    return -1;
  }

  try
  {
    // Access the deleted second to last object from the Naming Context
    CosNaming::Name wide;
    wide.length (2);
    wide[0].id = CORBA::string_dup ("level1_context");
    char wide_name[16];
    ACE_OS::sprintf(wide_name, "obj_%d", o_breath-2);
    wide[1].id = CORBA::string_dup (wide_name);
    CORBA::Object_var result_obj_ref = root_context_2->resolve (wide);
    ACE_ERROR_RETURN ((LM_ERROR,
                    ACE_TEXT ("Problems with resolving object from ")
                    ACE_TEXT ("redundant server - deleted object found.\n")),
                    -1);
  }
  catch (const CORBA::Exception&)
  {
    //expect exception since the context was deleted
  }

  try
  {
    // Access the last context from the wide Naming Context
    CosNaming::Name wide;
    wide.length (1);
    char wide_name[16];
    ACE_OS::sprintf(wide_name, "wide_%d", c_breath-1);
    wide[0].id = CORBA::string_dup (wide_name);
    CORBA::Object_var result_obj_ref = root_context_2->resolve (wide);
    CosNaming::NamingContext_var result_object =
      CosNaming::NamingContext::_narrow (result_obj_ref.in ());
    if (CORBA::is_nil (result_object.in ()))
      ACE_ERROR_RETURN ((LM_ERROR,
                      ACE_TEXT ("Problems with resolving wide context from ")
                      ACE_TEXT ("redundant server - nil object ref.\n")),
                      -1);
  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (
      ACE_TEXT (
        "Unable to resolve wide context from redundant server"));
    return -1;
  }

  try
  {
    // Access the deleted second to last object from the Naming Context
    CosNaming::Name wide;
    wide.length (2);
    char wide_name[16];
    ACE_OS::sprintf(wide_name, "wide_%d", c_breath-2);
    wide[0].id = CORBA::string_dup (wide_name);
    CORBA::Object_var result_obj_ref = root_context_2->resolve (wide);
    ACE_ERROR_RETURN ((LM_ERROR,
                    ACE_TEXT ("Problems with resolving wide context from ")
                    ACE_TEXT ("redundant server - deleted object found.\n")),
                    -1);
  }
  catch (const CORBA::Exception&)
  {
    //expect exception since the context was deleted
  }

  try
  {
    // Access the deleted last context from the deep Naming Context
    CosNaming::Name deep;
    deep.length (c_depth);
    char deep_name[16];
    for (i=0; i<c_depth; i++)
    {
      ACE_OS::sprintf(deep_name, "deep_%d", i);
      deep[i].id = CORBA::string_dup (deep_name);
    }
    CORBA::Object_var result_obj_ref = root_context_1->resolve (deep);
    ACE_ERROR_RETURN ((LM_ERROR,
                    ACE_TEXT ("Problems with resolving deep context from ")
                    ACE_TEXT ("redundant server - deleted object found.\n")),
                    -1);
  }
  catch (const CORBA::Exception&)
  {
    //expect exception since the context was deleted
  }

  try
  {
    // Access the second to last object from the Naming Context
    CosNaming::Name deep;
    deep.length (c_depth-1);
    char deep_name[16];
    for (i=0; i<c_depth-1; i++)
    {
      ACE_OS::sprintf(deep_name, "deep_%d", i);
      deep[i].id = CORBA::string_dup (deep_name);
    }
    CORBA::Object_var result_obj_ref = root_context_1->resolve (deep);
    CosNaming::NamingContext_var result_object =
      CosNaming::NamingContext::_narrow (result_obj_ref.in ());
    if (CORBA::is_nil (result_object.in ()))
      ACE_ERROR_RETURN ((LM_ERROR,
                      ACE_TEXT ("Problems with resolving deep context from ")
                      ACE_TEXT ("redundant server - nil object ref.\n")),
                      -1);


  }
  catch (const CORBA::Exception& ex)
  {
    ex._tao_print_exception (
      ACE_TEXT (
        "Unable to resolve deep context from redundant server"));
    return -1;
  }

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Redundancy test OK\n")));
  return 0;

}
