// $Id$
#include "TT_Info.h"
#include "orbsvcs/Trader/Property_Evaluator.h"

const char* TT_Info::INTERFACE_NAMES[] = 
{
  "Remote_IO",
  "Plotter",
  "Printer",
  "File_System",
  "PostScript_Printer"
};

const char* TT_Info::REMOTE_IO_NAME = "Remote_IO";

const char* TT_Info::REMOTE_IO_PROPERTY_NAMES[] = 
{
  "Name",
  "Location",
  "Description"
};

CORBA::TypeCode_ptr TT_Info::REMOTE_IO_PROPERTY_TYPES[] =
{
  CORBA::_tc_string,
  CORBA::_tc_string,
  CORBA::_tc_string
};

CosTradingRepos::ServiceTypeRepository::PropertyMode
TT_Info::REMOTE_IO_PROPERTY_MODES[] =
{
  CosTradingRepos::ServiceTypeRepository::PROP_MANDATORY_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL,
  CosTradingRepos::ServiceTypeRepository::PROP_MANDATORY
};

const char* TT_Info::PLOTTER_NAME = "Plotter";

const char* TT_Info::PLOTTER_PROPERTY_NAMES[] = 
{
  "Num_Colors",
  "Auto_Loading",
  "Cost_Per_Page",
  "Model_Number",
  "User_Queue",
  "File_Sizes_Pending"
};

CORBA::TypeCode_ptr TT_Info::PLOTTER_PROPERTY_TYPES[] =
{
  CORBA::_tc_long,
  CORBA::_tc_boolean,
  CORBA::_tc_float,
  CORBA::_tc_string,
  TAO_Sequences::_tc_StringSeq,
  TAO_Sequences::_tc_ULongSeq
};

CosTradingRepos::ServiceTypeRepository::PropertyMode
TT_Info::PLOTTER_PROPERTY_MODES[] =
{
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL,
  CosTradingRepos::ServiceTypeRepository::PROP_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL,
  CosTradingRepos::ServiceTypeRepository::PROP_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL
};

const char* TT_Info::PRINTER_NAME = "Printer";

const char* TT_Info::PRINTER_PROPERTY_NAMES[] = 
{
  "Color",
  "Double_Sided",
  "Cost_Per_Page",
  "Model_Number",
  "Pages_Per_Sec",
  "User_Queue",
  "File_Sizes_Pending"
};

CORBA::TypeCode_ptr TT_Info::PRINTER_PROPERTY_TYPES[] =
{
  CORBA::_tc_boolean,
  CORBA::_tc_boolean,
  CORBA::_tc_float,
  CORBA::_tc_string,
  CORBA::_tc_ushort,
  TAO_Sequences::_tc_StringSeq,
  TAO_Sequences::_tc_ULongSeq
};

CosTradingRepos::ServiceTypeRepository::PropertyMode
TT_Info::PRINTER_PROPERTY_MODES[] =
{
  CosTradingRepos::ServiceTypeRepository::PROP_MANDATORY_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL,
  CosTradingRepos::ServiceTypeRepository::PROP_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL
};

const char* TT_Info::FILESYSTEM_NAME = "File_System";

const char* TT_Info::FILESYSTEM_PROPERTY_NAMES[] =
{
  "Disk_Space",
  "Space_Remaining",
  "Permission_Level"
};

CORBA::TypeCode_ptr TT_Info::FILESYSTEM_PROPERTY_TYPES[] =
{
  CORBA::_tc_ulong,
  CORBA::_tc_ulong,
  CORBA::_tc_ushort
};

CosTradingRepos::ServiceTypeRepository::PropertyMode
TT_Info::FILESYSTEM_PROPERTY_MODES[] =
{
  CosTradingRepos::ServiceTypeRepository::PROP_MANDATORY_READONLY,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL,
  CosTradingRepos::ServiceTypeRepository::PROP_NORMAL
};

const char* TT_Info::PS_PRINTER_PROPERTY_NAMES[] = 
{
  "Version"
};


const char* TT_Info::PS_PRINTER_NAME = "PostScript_Printer";

CORBA::TypeCode_ptr TT_Info::PS_PRINTER_PROPERTY_TYPES[] =
{
  CORBA::_tc_ushort
};

CosTradingRepos::ServiceTypeRepository::PropertyMode
TT_Info::PS_PRINTER_PROPERTY_MODES[] =
{
  CosTradingRepos::ServiceTypeRepository::PROP_MANDATORY_READONLY
};

const char* TT_Info::LOCATIONS[] =
{
  "Bryan 509",
  "Bryan 503",
  "Dunker 102",
  "Jolley 408",
  "Lopata 401",
  "January 110",
  "Cupples I 30",
  "Cupples II 201",
  "Urbauer 321",
  "Umrath 302",
  "Wilson 110",
  "Olin 239",
  "Simon 238",
  "Rebstock 232",
  "McMillan 123"
};

const char* TT_Info::USERS[] = 
{
  "sbw1",
  "schmidt",
  "naga",
  "alex",
  "mk1",
  "marina",
  "sumedh",
  "sergio",
  "coryan",
  "cdgill",
  "levine",
  "jxh",
  "irfan",
  "nanbor",
  "eea1",
  "brunsch"
};

const char* TT_Info::MODEL_NUMBERS[] =
{
  "HP238293892bn2398",
  "PK92839nkse092309",
  "8328323n293kljs98",
  "29309sjdkq34jksd2",
  "09q834efjhqw834q3",
  "q9834fdkjwq0934kf",
  "q834jfda09q834djk",
  "kajsd09q384kjda90",
  "9p83q4jklsdj098q3",
  "09a834ojfda09wu3r",
  "09234kejdfq934jed",
  "0q83kjefd09384jda",
  "asdfj0283jkdf0923",
  "kladfp72wu34j230f",
  "9q834jidlj234ujof"
};

const int TT_Info::NUM_QUERIES = 1;
const char* TT_Info::QUERIES[][3] =
{
  {INTERFACE_NAMES[REMOTE_IO], "", ""}
};


#if defined TAO_HAS_DYNAMIC_PROPERTY_BUG
void
TT_Info::dump_properties (const CosTrading::PropertySeq& prop_seq,
			  CORBA::ORB_ptr orb)
#else
void
TT_Info::dump_properties (const CosTrading::PropertySeq& prop_seq)
#endif /* TAO_HAS_DYNAMIC_PROPERTY_BUG */
{
  CORBA::Environment env;
  TAO_Property_Evaluator prop_eval (prop_seq);
  
  for (int length = prop_seq.length (), k = 0; k < length; k++)
    {
      CORBA::Any* value = 0;
      CORBA::TypeCode_ptr tc = 0;
      ACE_DEBUG ((LM_DEBUG, "%-15s: ", prop_seq[k].name.in ()));
      TAO_TRY
	{
#if defined TAO_HAS_DYNAMIC_PROPERTY_BUG
	  value = prop_eval.property_value(k, orb, env);
#else
	  value = prop_eval.property_value(k, env);
#endif /* TAO_HAS_DYNAMIC_PROPERTY_BUG */
	  TAO_CHECK_ENV;

	  tc = value->type ();
	}
      TAO_CATCHANY
	{
	  ACE_DEBUG ((LM_DEBUG, "Error retrieving property value.\n"));	  
	}
      TAO_ENDTRY;

      if (tc == 0)
	continue;
      else if (tc->equal (TAO_Sequences::_tc_StringSeq, env))
	{
	  TAO_Sequences::StringSeq* str_seq_ptr;
	  (*value) >>= str_seq_ptr;

	  TAO_Sequences::StringSeq_var str_seq (str_seq_ptr);
	  for (int length = str_seq->length (), i = 0; i < length; i++)
	    ACE_DEBUG ((LM_DEBUG, "%s ", (const char *) str_seq[i]));

	  ACE_DEBUG ((LM_DEBUG, "\n"));
	}
      else if (tc->equal (TAO_Sequences::_tc_ULongSeq, env))
	{
	  TAO_Sequences::ULongSeq* ulong_seq_ptr;
	  (*value) >>= ulong_seq_ptr;

	  TAO_Sequences::ULongSeq_var ulong_seq (ulong_seq_ptr);
	  for (int length = ulong_seq->length (), i = 0; i < length; i++)
	    ACE_DEBUG ((LM_DEBUG, "%d ", ulong_seq[i]));

	  ACE_DEBUG ((LM_DEBUG, "\n"));
	}
      else
	CORBA::Any::dump (*value);
    }
}

