// $Id$

#include "Locator_XMLHandler.h"
#include "XML_Backing_Store.h"
#include "utils.h"
#include "ace/OS_NS_strings.h"
#include "ace/OS_NS_sys_time.h"

const ACE_TCHAR* Locator_XMLHandler::ROOT_TAG = ACE_TEXT("ImplementationRepository");
const ACE_TCHAR* Locator_XMLHandler::SERVER_INFO_TAG = ACE_TEXT("Servers");
const ACE_TCHAR* Locator_XMLHandler::ACTIVATOR_INFO_TAG = ACE_TEXT("Activators");
const ACE_TCHAR* Locator_XMLHandler::ENVIRONMENT_TAG = ACE_TEXT("EnvironmentVariables");

Locator_XMLHandler::Locator_XMLHandler (XML_Backing_Store& repo,
                                        CORBA::ORB_ptr orb)
: repo_(repo),
  jacorb_server_ (false),
  start_limit_(0),
  server_started_(false),
  repo_id_(0),
  repo_type_(0),
  orb_(CORBA::ORB::_duplicate(orb))
{
}

static void convertEnvList (const Locator_XMLHandler::EnvList& in,
                            ImplementationRepository::EnvironmentList& out)
{
  CORBA::ULong sz = static_cast<CORBA::ULong> (in.size ());
  out.length (sz);
  for (CORBA::ULong i = 0; i < sz; ++i)
    {
      out[i].name = in[i].name.c_str ();
      out[i].value = in[i].value.c_str ();
    }
}

void
Locator_XMLHandler::startElement (const ACEXML_Char*,
                                  const ACEXML_Char*,
                                  const ACEXML_Char* qName,
                                  ACEXML_Attributes* attrs)
{
  ACE_ASSERT (qName != 0);
  if (ACE_OS::strcasecmp (qName, SERVER_INFO_TAG) == 0)
    {
      // We'll use this as a key to determine if we've got a valid record
      this->server_name_ = ACE_TEXT("");
      this->env_vars_.clear();
      this->jacorb_server_ = false;

      // if attrs exists and if the previously required 9 fields
      const size_t previous_size = 9;
      if (attrs != 0 && attrs->getLength () >= previous_size)
        {
          size_t index = 0;
          this->server_id_ = attrs->getValue (index++);
          this->server_name_ = attrs->getValue (index++);
          this->activator_name_ = attrs->getValue (index++);
          this->command_line_ = attrs->getValue (index++);
          this->working_dir_ = attrs->getValue (index++);
          this->activation_ = attrs->getValue (index++);
          this->env_vars_.clear ();
          int limit = ACE_OS::atoi (attrs->getValue (index++));
          this->start_limit_ = limit;
          this->partial_ior_ = attrs->getValue (index++);
          this->server_object_ior_ = attrs->getValue (index++);

          if (attrs->getLength () >= index)
            {
              this->server_started_ =
                (ACE_OS::atoi (attrs->getValue (index++)) != 0);
            }
          if (attrs->getLength () >= index)
            {
              this->jacorb_server_ =
                (ACE_OS::atoi (attrs->getValue (index++)) != 0);
            }
          for ( ; index < attrs->getLength(); ++index)
            {
              ACE_CString name (attrs->getLocalName(index));
              ACE_CString value (attrs->getValue(index));
              this->extra_params_.push_back(std::make_pair(name,
                                                           value));
            }
        }
    }
  else if (ACE_OS::strcasecmp (qName, ACTIVATOR_INFO_TAG) == 0)
  {
    if (attrs != 0 && attrs->getLength () >= 3)
      {
        size_t index = 0;
        const ACE_CString aname =
          ACE_TEXT_ALWAYS_CHAR(attrs->getValue (index++));
        const ACE_TString token_str = attrs->getValue (index++);
        long token = ACE_OS::atoi (token_str.c_str ());
        const ACE_CString ior =
          ACE_TEXT_ALWAYS_CHAR(attrs->getValue (index++));
        NameValues extra_params;
        for ( ; index < attrs->getLength(); ++index)
          {
            ACE_CString name (attrs->getLocalName(index));
            ACE_CString value (attrs->getValue(index));
            extra_params.push_back(std::make_pair(name,
                                                  value));
          }
        this->repo_.load_activator (aname, token, ior, extra_params);
      }
  }
  else if (ACE_OS::strcasecmp (qName, ENVIRONMENT_TAG) == 0)
    {
      if (attrs != 0 && attrs->getLength () == 2)
        {
          EnvVar ev;
          ev.name = attrs->getValue ((size_t)0);
          ev.value = attrs->getValue ((size_t)1);
          this->env_vars_.push_back (ev);
        }
    }
}

void
Locator_XMLHandler::endElement (const ACEXML_Char*,
                                const ACEXML_Char*,
                                const ACEXML_Char* qName)
{
  ACE_ASSERT(qName != 0);
  if (ACE_OS::strcasecmp (qName, SERVER_INFO_TAG) == 0
    && this->server_name_.length () > 0)
  {
    const int limit = this->start_limit_ < 1 ? 1 : this->start_limit_;
    ImplementationRepository::ActivationMode amode =
      ImR_Utils::parseActivationMode (this->activation_);

    ImplementationRepository::EnvironmentList env_vars;
    convertEnvList (this->env_vars_, env_vars);
    this->repo_.load_server(this->server_id_,
                            this->server_name_,
                            this->jacorb_server_,
                            this->activator_name_,
                            this->command_line_,
                            env_vars,
                            this->working_dir_,
                            amode,
                            limit,
                            this->partial_ior_,
                            this->server_object_ior_,
                            this->server_started_,
                            this->extra_params_);
  }
  // activator info is handled in the startElement
}

bool
Locator_XMLHandler::EnvVar::operator== (const EnvVar& rhs) const
{
  return name == rhs.name && value == rhs.value;
}
bool
Locator_XMLHandler::EnvVar::operator!= (const EnvVar& rhs) const
{
  return ! (rhs == *this);
}

