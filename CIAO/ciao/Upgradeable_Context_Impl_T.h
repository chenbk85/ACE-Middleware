// -*- C++ -*-

//=============================================================================
/**
 *  @file    Upgradeable_Context_Impl_T.h
 *
 *  $Id$
 *
 */
//=============================================================================


#ifndef CIAO_UPGRADEABLE_CONTEXT_IMPL_T_H
#define CIAO_UPGRADEABLE_CONTEXT_IMPL_T_H

#include /**/ "ace/pre.h"

#include "ciao/UpgradeableContextC.h"
#include "ciao/Context_Impl_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA
{
  class SystemException;
}
TAO_END_VERSIONED_NAMESPACE_DECL

namespace CIAO
{
  template <typename BASE_CTX,
            typename SVNT,
            typename COMP,
            typename COMP_VAR>
  class Upgradeable_Context_Impl : public virtual Context_Impl<
                                   BASE_CTX, SVNT, COMP, COMP_VAR>
  {
  public:
    Upgradeable_Context_Impl (Components::CCMHome_ptr home,
                              Session_Container *c,
                              SVNT *sv);

    virtual ~Upgradeable_Context_Impl (void);

    virtual void
    deactivate_facet (const PortableServer::ObjectId &oid
                      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual void
    update_port_activator (const PortableServer::ObjectId &oid
                           ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual void
    remove_facet (CORBA::Object_ptr reference
                  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Components::ConsumerDescriptions *
    get_registered_consumers (const char *publisher_name
                              ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       ::Components::InvalidName,
                       ::Components::InvalidConnection)) = 0;

  protected:
    SVNT *servant_;
    COMP_VAR component_;
    typedef Context_Impl<BASE_CTX, SVNT, COMP, COMP_VAR> session_context;
  private:
    /// Not to be used
    Upgradeable_Context_Impl (void);
  };
}

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "Upgradeable_Context_Impl_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Upgradeable_Context_Impl_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* CIAO_UPGRADEABLE_CONTEXT_IMPL_T_H */
