// $Id$

#include "Options.h"
#include "Single_Lookup.h"

Single_Lookup::Single_Lookup (char *usr_name)
{
  ACE_NEW (this->frp,
           Protocol_Record (ACE::strnew (usr_name)));
}

Single_Lookup::~Single_Lookup (void)
{
  if (Options::get_opt (Options::DEBUG))
    ACE_DEBUG ((LM_DEBUG,
                "disposing Single_Lookup\n"));
}

Protocol_Record *
Single_Lookup::get_each_entry (void)
{
  return this->frp;
}

Protocol_Record *
Single_Lookup::get_next_entry (void)
{
  return this->get_each_entry ();
}
