// file      : CCF/IDL2/SemanticAction/Impl/Factory.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#ifndef CCF_IDL2_SEMANTIC_ACTION_IMPL_FACTORY_HPP
#define CCF_IDL2_SEMANTIC_ACTION_IMPL_FACTORY_HPP

#include "CCF/CompilerElements/Diagnostic.hpp"

#include "CCF/IDL2/SemanticGraph/Translation.hpp"

#include "CCF/IDL2/SemanticAction/Factory.hpp"

#include "CCF/IDL2/SemanticAction/Impl/Elements.hpp"

//@@ It would be nice to move this includes into .cpp
//
#include "CCF/IDL2/SemanticAction/Impl/Attribute.hpp"
#include "CCF/IDL2/SemanticAction/Impl/Enum.hpp"
#include "CCF/IDL2/SemanticAction/Impl/Exception.hpp"
#include "CCF/IDL2/SemanticAction/Impl/Include.hpp"
#include "CCF/IDL2/SemanticAction/Impl/Interface.hpp"
#include "CCF/IDL2/SemanticAction/Impl/Member.hpp"
#include "CCF/IDL2/SemanticAction/Impl/Module.hpp"
#include "CCF/IDL2/SemanticAction/Impl/Native.hpp"
#include "CCF/IDL2/SemanticAction/Impl/Operation.hpp"
#include "CCF/IDL2/SemanticAction/Impl/Struct.hpp"
#include "CCF/IDL2/SemanticAction/Impl/Typedef.hpp"
#include "CCF/IDL2/SemanticAction/Impl/TypeId.hpp"
#include "CCF/IDL2/SemanticAction/Impl/ValueType.hpp"

namespace CCF
{
  namespace IDL2
  {
    namespace SemanticAction
    {
      namespace Impl
      {
        struct Factory : virtual IDL2::SemanticAction::Factory
        {
          Factory (CompilerElements::Context& context,
                   Diagnostic::Stream& dout,
                   SemanticGraph::TranslationUnit& tu);

          virtual SemanticAction::Attribute&
          attribute ()
          {
            return attribute_;
          }

          virtual SemanticAction::Enum&
          enum_ ()
          {
            return enum__;
          }

          virtual SemanticAction::Exception&
          exception ()
          {
            return exception_;
          }

          virtual SemanticAction::Include&
          include ()
          {
            return include_;
          }

          virtual SemanticAction::Interface&
          interface ()
          {
            return interface_;
          }

          virtual SemanticAction::Member&
          member ()
          {
            return member_;
          }

          virtual SemanticAction::Module&
          module ()
          {
            return module_;
          }

          virtual SemanticAction::Native&
          native ()
          {
            return native_;
          }

          virtual SemanticAction::Operation&
          operation ()
          {
            return operation_;
          }

          virtual SemanticAction::Struct&
          struct_ ()
          {
            return struct__;
          }

          virtual SemanticAction::Typedef&
          typedef_ ()
          {
            return typedef__;
          }

          virtual SemanticAction::TypeId&
          type_id ()
          {
            return type_id_;
          }

          virtual SemanticAction::TypePrefix&
          type_prefix ()
          {
            return type_prefix_;
          }

          virtual SemanticAction::ValueType&
          value_type ()
          {
            return value_type_;
          }

        protected:
          Context ctx_;

        private:
          Attribute attribute_;
          Enum enum__;
          Exception exception_;
          Include include_;
          Interface interface_;
          Member member_;
          Module module_;
          Native native_;
          Operation operation_;
          Struct struct__;
          Typedef typedef__;
          TypeId type_id_;
          TypePrefix type_prefix_;
          ValueType value_type_;
        };
      }
    }
  }
}

#endif  // CCF_IDL2_SEMANTIC_ACTION_IMPL_FACTORY_HPP
