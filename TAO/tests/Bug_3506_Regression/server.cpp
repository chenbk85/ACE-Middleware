// $Id$

#include "IF_EXE_M_R_StructsS.h"
#include "ace/Get_Opt.h"
#include "ace/OS_NS_stdio.h"

CORBA::ORB_var m_ORB_p;

const ACE_TCHAR *ior_output_file = ACE_TEXT("test.ior");

int
parse_args (int argc, ACE_TCHAR *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, ACE_TEXT("o:"));
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
        case 'o':
          ior_output_file = get_opts.opt_arg ();
          break;

        case '?':
        default:
          ACE_ERROR_RETURN((LM_ERROR,
                            "usage:  %s "
                            "-o <iorfile>"
                            "\n",
                            argv [0]),
                            -1);
      }
  // Indicates sucessful parsing of the command line
  return 0;
}


class IF_Test_impl : public POA_IF_EXE_M_R::IF_ExeCtrlData
{
public:
  virtual void
  shutdown ()
  {
    m_ORB_p->shutdown (0);
  }

  virtual void
  foo (const ::IF_EXE_M_R::Test_Struct &ts)
  {
    IF_EXE_M_R::CORBA_FOOIInPlan *anUnion_p = new IF_EXE_M_R::CORBA_FOOIInPlan;
    if (ts.whatEver >>= anUnion_p)
      {
        ACE_DEBUG((LM_DEBUG, "Any successfully marshalled\nAny is %@\nID: %C\nNAME: %C\nKIND: %d\n", &ts.whatEver,
                               ts.whatEver._tao_get_typecode()->id(),
                               ts.whatEver._tao_get_typecode()->name(),
                               ts.whatEver._tao_get_typecode()->kind()));

      }
    else
      {
        ACE_ERROR((LM_ERROR, "ERROR Any not successfully marshalled\nAny is %@\n", &ts.whatEver));
        if (ts.whatEver._tao_get_typecode ()->kind () != CORBA::tk_null)
          {
            ACE_ERROR((LM_ERROR, "ID: %C\nNAME: %C\nKIND: %d\n",
                                       ts.whatEver._tao_get_typecode()->id(),
                                       ts.whatEver._tao_get_typecode()->name(),
                                       ts.whatEver._tao_get_typecode()->kind()));
          }
        else
          {
            ACE_ERROR((LM_ERROR, "Typecode is NULL\nKIND: %d\n",
                                       ts.whatEver._tao_get_typecode()->kind()));
          }
      }
  }
};

class Main_C
{
public:
  int Create (int argc, ACE_TCHAR *argv[]);
};

int
Main_C::Create (int argc, ACE_TCHAR *argv[])
{
  try
    {
      // ENTER your code here ...
      CORBA::Object_var obj = m_ORB_p->resolve_initial_references ("RootPOA");

      if (parse_args (argc, argv) != 0)
        return 1;

      PortableServer::POA_var poa = PortableServer::POA::_narrow (obj);

      PortableServer::POAManager_var mgr = poa->the_POAManager ();
      mgr->activate ();

      CORBA::Object_var reference;
      IF_Test_impl *servant = new IF_Test_impl;

      reference = poa->servant_to_reference (servant);

      IF_EXE_M_R::IF_ExeCtrlData_var servant_var =
        IF_EXE_M_R::IF_ExeCtrlData::_narrow (reference);
      CORBA::String_var str = m_ORB_p->object_to_string (servant_var);

      // Output the IOR to the <ior_output_file>
      FILE *output_file = ACE_OS::fopen (ior_output_file, "w");
      if (output_file == 0)
        ACE_ERROR_RETURN((LM_ERROR,
                                      "Cannot open output file for writing IOR: %s\n",
                                      ior_output_file),
                                     1);
      ACE_OS::fprintf (output_file, "%s", str.in ());
      ACE_OS::fclose (output_file);

      m_ORB_p->run ();
    }
  catch (const CORBA::Exception &ex)
    {
      ex._tao_print_exception ("Exception caught:");
      return 1;
    }
  return 0;
}

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  int ret = -1;
  bool CORBA_success = true;

  m_ORB_p = CORBA::ORB_init (argc, argv);

  Main_C main_cs;
  return main_cs.Create (argc, argv);
}
