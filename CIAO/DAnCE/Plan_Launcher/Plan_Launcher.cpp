// $Id$

#include "ace/Dynamic_Service.h"
#include "ace/Env_Value_T.h"
#include "ace/Get_Opt.h"
#include "tao/ORB.h"
#include "tao/Object.h"
#include "DAnCE/Logger/Log_Macros.h"
#include "DAnCE/Logger/Logger_Service.h"
#include "DAnCE/tools/Convert_Plan/Convert_Plan_Impl.h"

#include "EM_Launcher.h"
#include "NM_Launcher.h"

//#include "Plan_Launcher_Impl.h"

ACE_CString
expand_env_vars (const ACE_TCHAR * s)
{
  ACE_TString src(s);
  ACE_TString res;
  size_t pos_done = 0;
  while (pos_done < (size_t) src.length())
    {
      size_t pos_start = src.find ('$', pos_done);
      if (ACE_TString::npos == pos_start)
        {
          res += src.substring (pos_done);
          pos_done = src.length();
        }
      else // take the substring before '$' and append value
        {
          if (pos_start > pos_done)
            {
              res += src.substring (pos_done, pos_start - pos_done);
              pos_done = pos_start;
            }

          size_t pos_end = src.length();

          size_t p;

          p = src.find (ACE_TEXT(' '), pos_start + 1);
          if (ACE_TString::npos != p && pos_end > p) pos_end = p;

          p = src.find (ACE_TEXT('/'), pos_start + 1);
          if (ACE_TString::npos != p && pos_end > p) pos_end = p;

          p = src.find (ACE_TEXT('\\'), pos_start + 1);
          if (ACE_TString::npos != p && pos_end > p) pos_end = p;

          p = src.find (ACE_TEXT('$'), pos_start + 1);
          if (ACE_TString::npos != p && pos_end > p) pos_end = p;

          if (pos_end - pos_start > 1)
            {
              ACE_Env_Value<const ACE_TCHAR*> val (src.substring (pos_start + 1, pos_end - pos_start - 1).c_str(), 0);
              res += val;
              pos_done = pos_end;
            }
          else
            {
              DANCE_DEBUG (6, (LM_WARNING, DLINFO
                               ACE_TEXT("Plan_Launcher::expand_env_vars - ")
                               ACE_TEXT("Envvar can not be parsed out at %i in \"<%s>\""),
                               pos_start,
                               src.c_str()));
            }
        }
    }
  return res;
}

namespace
{
  struct Options
  {
    enum MODE
      {
        LAUNCH,
        STARTLAUNCH,
        FINISHLAUNCH,
        START,
        TEARDOWN,
        INVALID
      };
        
    Options (void)
      : em_ior_ (0),
        nm_ior_ (0),
        xml_plan_ (0),
        cdr_plan_ (0),
        uuid_ (0),
        am_ior_ (0),
        app_ior_ (0),
        output_ (false),
        output_prefix_ (0),
        mode_ (LAUNCH)
    {}

    const ACE_TCHAR *em_ior_;
    const ACE_TCHAR *nm_ior_;
    const ACE_TCHAR *xml_plan_;
    const ACE_TCHAR *cdr_plan_;
    const ACE_TCHAR *uuid_;
    const ACE_TCHAR *am_ior_;
    const ACE_TCHAR *app_ior_;
    bool output_;
    const ACE_TCHAR *output_prefix_;
    MODE mode_;
  };
}


void
usage(const ACE_TCHAR*)
{
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Plan Launcher Options :\n")
              
              ACE_TEXT ("\t-k|--em-ior <EM IOR>\t\t")
              ACE_TEXT ("ExecutionManager IOR for EM based deployment.\n")
              ACE_TEXT ("\t-n|--nm-ior <NodeManager IOR>\t")
              ACE_TEXT ("NodeManager IOR for NM based deployment.\n")
              /*
              ACE_TEXT ("\nName Service Options\n")
              ACE_TEXT ("\t--domain-nc [NC]\t\tDomain Naming Context (default will rir NameService)\n")
              ACE_TEXT ("\t--instance-nc [NC]\t\tInstance Naming Context (default will rir NameService)\n")
              */
              ACE_TEXT ("\nPlan Identification Options:\n")
              ACE_TEXT ("\t-c|--cdr-plan <CDR Deployment Plan>\n")
              ACE_TEXT ("\t-x|--xml-plan <XML Deployment Plan>\n")
              ACE_TEXT ("\t-u|--plan-uuid <PLAN UUID>\tOnly supported for EM-based deployments\n")
              ACE_TEXT ("\t-a|--app-ior <APP IOR>\t\tIOR for ApplicationManager entity (Domain or Node)\n")
              ACE_TEXT ("\t-m|--am-ior <AM IOR>\t\tIOR For Application entity (Domain or Node)\n")
              
              ACE_TEXT ("\nPlan Control Options:\n")
              ACE_TEXT ("The default action is to fully launch a plan. The following options may be used\n")
              ACE_TEXT ("to arrive at a different state\n")
              ACE_TEXT ("\t-l|--launch-plan\t\tLaunch the plan (Requires CDR/XML plan)\n")
              ACE_TEXT ("\t-s|--stop-plan\t\t\tStop the plan\n (Requires Plan, UUID, or APP/AM references")
              
              ACE_TEXT ("\nOther Options\n")
              ACE_TEXT ("\t-o|--output[prefix]\t\tOutput IOR files that result from plan control action,")
              ACE_TEXT ("if any. Optional prefix to filename defaults to plan UUID if plan is provided."
                        "Default is on for NM-based deployments.\n")

              ACE_TEXT ("\t-h|--help\t\t\tShow this usage information\n")
              ));
}

bool
parse_args(int argc, ACE_TCHAR *argv[], Options &options)
{
  DANCE_DEBUG (9, (LM_TRACE, DLINFO ACE_TEXT("PL options : \"")));

  for (int i = 0; i < argc; ++i)
    {
      DANCE_DEBUG (9, (LM_TRACE, "\t%s\n", argv[i]));
    }

  ACE_Get_Opt get_opt(argc, argv,
                      ACE_TEXT ("k:n:c:x:u:m:a:lso::h"));
  get_opt.long_option(ACE_TEXT("em-ior"), 'k', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option(ACE_TEXT("nm-ior"), 'n', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option(ACE_TEXT("xml-plan"), 'x', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option(ACE_TEXT("cdr-plan"), 'c', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option(ACE_TEXT("plan-uuid"), 'u', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option(ACE_TEXT("am-ior"), 'm', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option(ACE_TEXT("app-ior"), 'a', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option(ACE_TEXT("launch-plan"), 'l', ACE_Get_Opt::NO_ARG);
  get_opt.long_option(ACE_TEXT("stop-plan"), 's', ACE_Get_Opt::NO_ARG);
  get_opt.long_option(ACE_TEXT("output"), 'o', ACE_Get_Opt::ARG_OPTIONAL);
  get_opt.long_option(ACE_TEXT("help"), 'h', ACE_Get_Opt::NO_ARG);

  int c;
  ACE_CString s;
  while ( (c = get_opt ()) != EOF)
    {
      switch (c)
        {
        case 'k':
          if (get_opt.opt_arg () == 0)
            {
              options.em_ior_ = "corbaname:rir:/NameService#ExecutionManager";
              DANCE_DEBUG (6, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::parse_args - Defaulting to ")
                               ACE_TEXT ("NameService lookup of ExecutionManager\n")));              
            }
          else
            {
              options.em_ior_ = get_opt.opt_arg ();
              DANCE_DEBUG (6, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::parse_args -")
                               ACE_TEXT ("Using ExecutionManager IOR: %s\n"),
                               options.em_ior_));              
            }
          break;

        case 'n':
          options.nm_ior_ = get_opt.opt_arg ();
          options.output_ = true;
          DANCE_DEBUG (6, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::parse_args -")
                           ACE_TEXT ("Using NodeManager IOR: %s\n"),
                           options.nm_ior_));
          break;
          
        case 'x':
          options.xml_plan_ = get_opt.opt_arg ();
          DANCE_DEBUG (6, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::parse_args -")
                           ACE_TEXT ("Using XML plan: %s\n"),
                           options.xml_plan_));
          break;
          
        case 'c':
          options.cdr_plan_ = get_opt.opt_arg ();
          DANCE_DEBUG (6, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::parse_args -")
                           ACE_TEXT ("Using CDR plan: %s\n"),
                           options.cdr_plan_));
          break;
          
        case 'u':
          options.uuid_ = get_opt.opt_arg ();
          DANCE_DEBUG (6, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::parse_args -")
                           ACE_TEXT ("Using UUID: %s\n"),
                           options.uuid_));
          break;

        case 'm':
          options.am_ior_ = get_opt.opt_arg ();
          DANCE_DEBUG (6, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::parse_args -")
                           ACE_TEXT ("Using ApplicationManager IOR %s\n"),
                           options.am_ior_));
          break;
          
        case 'a':
          options.app_ior_ = get_opt.opt_arg ();
          DANCE_DEBUG (6, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::parse_args -")
                           ACE_TEXT ("Application IOR: %s\n"),
                           options.app_ior_));
          break;

        case 'l':
          options.mode_ = Options::LAUNCH;
          DANCE_DEBUG (6, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::parse_args -")
                           ACE_TEXT ("Launching nominated plan\n")));
          break;          

        case 's':
          options.mode_ = Options::TEARDOWN;
          DANCE_DEBUG (6, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::parse_args -")
                           ACE_TEXT ("Tearing down nominated plan\n")));
          break;
          
        case 'o':
          options.output_ = true;
          DANCE_DEBUG (6, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::parse_args - ")
                           ACE_TEXT ("IOR files will be output to the current working directory\n")));
          
          if (get_opt.opt_arg () != 0)
            {
              options.output_prefix_ = get_opt.opt_arg ();
              DANCE_DEBUG (6, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::parse_args - ")
                               ACE_TEXT ("Storing user-provided output postfix <%s>\n"),
                               options.output_prefix_));
            }

          break;

        case 'h':
          usage (argv[0]);
          return false;
        default:
          usage (argv[0]);
          return false;
        }
    }
  
  /// Sanity checking on the options. 

  // In all cases, we need to have a EM/NM IOR specified, but only one.
  if ((!options.em_ior_ && !options.nm_ior_) || 
      (options.em_ior_ && options.nm_ior_))
    {
      DANCE_ERROR (1, (LM_ERROR, DLINFO ACE_TEXT ("Plan_launcher::parse_args - ")
                       ACE_TEXT ("Error: Must specify either EM IOR or NM IOR\n")));
      return false;
    }
  
  // Launching plans requires a plan (duh), and only one plan
  if ((options.mode_ == Options::LAUNCH) &&
      ((!options.xml_plan_ && !options.cdr_plan_) ||
       (options.xml_plan_ && options.cdr_plan_)))
    {
      DANCE_ERROR (1, (LM_ERROR, DLINFO ACE_TEXT ("Plan_Launcher::parse_args - ")
                       ACE_TEXT ("Error: Launching plans requires exactly one type of plan (CDR/XML) be ")
                       ACE_TEXT ("specified.\n")));
      return false;
    }
  
  // tearing down plans requires a bit more complex set of options:
  if ((options.mode_ == Options::TEARDOWN)
      // Either way (EM/NM), we ca use a combination of a AM and a APP.
      && !(
           (options.am_ior_ && options.app_ior_) ||
           // If we are tearing down from EM, we have more options, namely:
           // A plan of some kind
           (options.em_ior_ && 
            (
             ((!options.xml_plan_ && !options.cdr_plan_) ||
              (options.xml_plan_ && options.cdr_plan_)) ||
             // A UUID
             (!options.uuid_)
             )
            )
           )
      )
    {
      DANCE_ERROR (1, (LM_ERROR, DLINFO ACE_TEXT ("Plan_Launcher::parse_args - ")
                       ACE_TEXT ("Invalid set of plan identification as required for teardown\n")));
      return false;
    }
      
      
  return true;
}

bool
write_IOR (const ACE_TCHAR * ior_file_name, const char* ior)
{
  FILE* ior_output_file_ = ACE_OS::fopen (ior_file_name, ACE_TEXT("w"));
  
  if (ior_output_file_)
    {
      ACE_OS::fprintf (ior_output_file_, "%s", ior);
      ACE_OS::fclose (ior_output_file_);
      return true;
    }
  return false;
}

int launch_plan (const Options &opts,
                 DAnCE::Plan_Launcher_Base *pl_base,
                 const ::Deployment::DeploymentPlan *plan,
                 CORBA::ORB_ptr orb)
{
  DANCE_TRACE ("Plan_Launcher::launch_plan");
  
  try
    {
      CORBA::Object_var app_mgr, app;
      
      ACE_CString uuid (pl_base->launch_plan (*plan, app_mgr.out () , app.out ()));
      
      DANCE_DEBUG (2, (LM_NOTICE, DLINFO ACE_TEXT ("Plan_Launcher::launch_plan - ")
                       ACE_TEXT ("Successfully deployed plan with UUID: <%C>\n"),
                       uuid.c_str ()));
                       
      if (!opts.output_)
        return 0;

      ACE_TString am_output, app_output;
      
      if (opts.output_prefix_)
        am_output = app_output = opts.output_prefix_;
      else
        am_output = app_output = ACE_TEXT_CHAR_TO_TCHAR (uuid.c_str ());
      
      am_output += ACE_TEXT ("_AM.ior");
      app_output += ACE_TEXT ("_APP.ior");
      
      DANCE_DEBUG (6, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::launch_plan - ")
                       ACE_TEXT ("Writing Application Manager IOR to <%s>\n"),
                       am_output.c_str ()));
      write_IOR (am_output.c_str (), 
                 orb->object_to_string (app_mgr.in ()));

      DANCE_DEBUG (6, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::launch_plan - ")
                       ACE_TEXT ("Writing Application IOR to <%s>\n"),
                       am_output.c_str ()));
      write_IOR (app_output.c_str (),
                 orb->object_to_string (app.in ()));
     
    }
  catch (const DAnCE::Deployment_Failure &ex)
    {
      DANCE_ERROR (1, (LM_ERROR, DLINFO ACE_TEXT ("Plan_Launcher::launch_plan - ")
                       ACE_TEXT ("Deployment failed, exception: %C\n"),
                       ex.ex_.c_str ()));
      return -1;
    }
  catch (const CORBA::Exception &ex)
    {
      DANCE_ERROR (1, (LM_ERROR, DLINFO ACE_TEXT ("Plan_Launcher::launch_plan - ")
                       ACE_TEXT ("Deployment failed, caught CORBA exception %C\n"),
                       ex._info ().c_str ()));
      return -1;
    }
  catch (...)
    {
      DANCE_ERROR (1, (LM_ERROR, DLINFO ACE_TEXT ("Plan_Launcher::launch_plan - ")
                       ACE_TEXT ("Deployment failed, caught unknown C++ exception\n")));
      return -1;
    }
  
  return 0;
}

int teardown_plan (const Options &opts,
                   DAnCE::Plan_Launcher_Base *pl_base,
                   const ::Deployment::DeploymentPlan *plan,
                   CORBA::ORB_ptr orb)
{
  DANCE_TRACE ("Plan_Launcher::teardown_plan");
  
  try
    {
      if (opts.am_ior_ && opts.app_ior_)
        {
          DANCE_DEBUG (3, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::teardown_plan - ")
                           ACE_TEXT ("Tearing down plan with explicitly nominated App and AM IORs.\n")));
          CORBA::Object_var am (orb->string_to_object (opts.am_ior_));
          CORBA::Object_var app (orb->string_to_object (opts.app_ior_));
          
          pl_base->teardown_application (am, app);
        }
      else
        {
          ACE_CString uuid;
          if (plan)
            uuid = plan->UUID.in ();
          else
            uuid = opts.uuid_;
          
          DAnCE::EM_Launcher *em_launcher = dynamic_cast <DAnCE::EM_Launcher *> (pl_base);
          
          if (!pl_base)
            {
              DANCE_ERROR (1, (LM_ERROR, DLINFO ACE_TEXT ("Plan_Launcher::teardown_plan - ")
                               ACE_TEXT ("Error: Attempting UUID lookup on non-EM managed plan not supported\n")));
              return -1;
            }
          
          CORBA::Object_var am, app;
          if (em_launcher->lookup_by_uuid (uuid.c_str (),
                                           am.out (),
                                           app.out ()))
            {
              DANCE_DEBUG (3, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher::teardown_plan - ")
                               ACE_TEXT ("Tearing down plan with UUID %C\n"),
                               uuid.c_str ()));
              pl_base->teardown_application (am, app);
            }
          else
            {
              DANCE_ERROR (1, (LM_ERROR, DLINFO ACE_TEXT ("Plan_Launcher::teardown_plan - ")
                               ACE_TEXT ("Error: Lookup by UUID failed\n")));
              return -1;
            }
        }
    }
  catch (const DAnCE::Deployment_Failure &ex)
    {
      DANCE_ERROR (1, (LM_ERROR, DLINFO ACE_TEXT ("Plan_Launcher::teardown_plan - ")
                       ACE_TEXT ("Teardown failed, exception: %C\n"),
                       ex.ex_.c_str ()));
      return -1;
    }
  catch (const CORBA::Exception &ex)
    {
      DANCE_ERROR (1, (LM_ERROR, DLINFO ACE_TEXT ("Plan_Launcher::teardown_plan - ")
                       ACE_TEXT ("Teardown failed, caught CORBA exception %C\n"),
                       ex._info ().c_str ()));
      return -1;
    }
  catch (...)
    {
      DANCE_ERROR (1, (LM_ERROR, DLINFO ACE_TEXT ("Plan_Launcher::teardown_plan - ")
                       ACE_TEXT ("Teardown failed, caught unknown C++ exception\n")));
      return -1;
    }
  
  return 0;
}

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  DANCE_DISABLE_TRACE ();

  int retval = 0;

  try
    {
      DAnCE::Logger_Service
        * dlf = ACE_Dynamic_Service<DAnCE::Logger_Service>::instance ("DAnCE_Logger");

      if (dlf)
        {
          dlf->init (argc, argv);
        }

      DANCE_DEBUG (6, (LM_TRACE, DLINFO
                       ACE_TEXT("PlanLauncher - initializing ORB\n")));

      CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);
      
      Options options;
      if (!parse_args (argc, argv, options))
        {
          DANCE_ERROR (1, (LM_ERROR, DLINFO ACE_TEXT ("Plan_Launcher - ")
                           ACE_TEXT ("Failed to parse command line arguments, exiting.\n")));
          return -1;
        }
      
      
      auto_ptr<DAnCE::Plan_Launcher_Base> pl_base (0);
      
      if (options.em_ior_)
        {
          DAnCE::EM_Launcher *em_pl (0);
          
          CORBA::Object_var obj = orb->string_to_object (options.em_ior_);
          Deployment::ExecutionManager_var tmp_em = Deployment::ExecutionManager::_narrow (obj);
          
          if (CORBA::is_nil (tmp_em))
            {
              DANCE_ERROR (1, (LM_ERROR, DLINFO ACE_TEXT ("Plan_Launcher - ")
                               ACE_TEXT ("Unable to resolve ExecutionManager reference <%s>\n"),
                               options.em_ior_));
              return -1;
            }
          
          ACE_NEW_THROW_EX (em_pl,
                            DAnCE::EM_Launcher (orb.in (),
                                                tmp_em.in ()),
                            CORBA::NO_MEMORY ());
          
          pl_base.reset (em_pl);
          
        }
      else
        {
          DAnCE::NM_Launcher *nm_pl (0);

          CORBA::Object_var obj = orb->string_to_object (options.nm_ior_);
          Deployment::NodeManager_var tmp_em = Deployment::NodeManager::_narrow (obj);
          
          if (CORBA::is_nil (tmp_em))
            {
              DANCE_ERROR (1, (LM_ERROR, DLINFO ACE_TEXT ("Plan_Launcher - ")
                               ACE_TEXT ("Unable to resolve NodeManager reference <%s>\n"),
                               options.em_ior_));
              return -1;
            }
          
          ACE_NEW_THROW_EX (nm_pl,
                            DAnCE::NM_Launcher (orb.in (),
                                                tmp_em.in ()),
                            CORBA::NO_MEMORY ());
          
          pl_base.reset (nm_pl);
        }

      
      Deployment::DeploymentPlan_var dp;
      
      DANCE_DEBUG (6, (LM_DEBUG, DLINFO ACE_TEXT ("Plan_Launcher - ")
                       ACE_TEXT ("Parsing deployment plan\n")));
      if (options.cdr_plan_)
        {
          dp = DAnCE::Convert_Plan::read_cdr_plan (options.cdr_plan_);
          if (!dp.ptr ())
            {
              ACE_ERROR ((LM_ERROR, DLINFO ACE_TEXT ("PlanLauncher - Error: Unable to read in XML plan\n")));
              return -1;
            }
        }
      else if (options.xml_plan_)
        {
          dp = DAnCE::Convert_Plan::read_xml_plan (options.xml_plan_);
          
          if (!dp.ptr ())
            {
              ACE_ERROR ((LM_ERROR, DLINFO ACE_TEXT ("PlanLauncher - Error: Unable to read in XML plan\n")));
              return -1;
            }
        }
      
      switch (options.mode_)
        {
        case Options::LAUNCH:
          launch_plan (options, pl_base.get (), dp, orb.in ());
          
          break;
          
        case Options::TEARDOWN:
          teardown_plan (options, pl_base.get (), dp, orb.in ());
          break;

        default:
          DANCE_ERROR (1, (LM_ERROR, DLINFO ACE_TEXT ("Plan_Launcher -")
                           ACE_TEXT ("Mode not yet supported\n")));
          break;
          
        };

      orb->destroy ();
    }
  catch (const DAnCE::Deployment_Failure& e)
    {
      ACE_ERROR ((LM_ERROR, DLINFO "PlanLauncher - Error: %C.\n", e.ex_.c_str()));
      retval = -1;
    }
  catch (const CORBA::Exception& ex)
    {
      ACE_ERROR ((LM_ERROR, DLINFO "PlanLauncher - Error: %C\n", ex._info ().c_str ()));
      retval = -1;
    }
  catch (...)
    {
      DANCE_ERROR (1, (LM_ERROR, "PlanLauncher - Error: Unknown exception.\n"));
      retval = -1;
    }

  return retval;
}

