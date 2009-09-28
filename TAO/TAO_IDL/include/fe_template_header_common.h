// $Id$

#ifndef FE_TEMPLATE_HEADER_COMMON_H
#define FE_TEMPLATE_HEADER_COMMON_H

#include "fe_utils.h"

class AST_Template_Common;

class TAO_IDL_FE_Export FE_TemplateHeader_Common
{
public:
  FE_TemplateHeader_Common (FE_Utils::T_PARAMLIST_INFO *params);

  virtual ~FE_TemplateHeader_Common (void);

  // Data accessor.
  FE_Utils::T_PARAMLIST_INFO *param_info (void) const;

  // Destroy anything we own the memory for.
  virtual void destroy (void);

protected:
  bool duplicate_param_id (void);

protected:
  FE_Utils::T_PARAMLIST_INFO *param_info_;
};

#endif // FE_TEMPLATE_HEADER_COMMON_H

