// file      : CCF/IDL2/SemanticGraph/Union.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#ifndef CCF_IDL2_SEMANTIC_GRAPH_UNION_HPP
#define CCF_IDL2_SEMANTIC_GRAPH_UNION_HPP

#include "CCF/IDL2/SemanticGraph/Elements.hpp"
#include "CCF/IDL2/SemanticGraph/Member.hpp"

namespace CCF
{
  namespace IDL2
  {
    namespace SemanticGraph
    {
      class Selector;
      class UnionMember;

      class Selects : public virtual Edge
      {
      public:
        Selector&
        selector () const
        {
          return *selector_;
        }

        UnionMember&
        member () const
        {
          return *member_;
        }

        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Selects ()
        {
          type_info (static_type_info ());
        }

        void
        set_left_node (Selector& n)
        {
          selector_ = &n;
        }

        void
        set_right_node (UnionMember& n)
        {
          member_ = &n;
        }

      private:
        Selector* selector_;
        UnionMember* member_;
      };

      class UnionMember : public virtual Member
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        UnionMember ()
        {
          type_info (static_type_info ());
        }
      };

      class Selector : public virtual Node
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Selector ()
        {
          type_info (static_type_info ());
        }
      };

      class DefaultSelector : public virtual Selector
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        DefaultSelector ()
        {
          type_info (static_type_info ());
        }
      };

      class ValueSelector : public virtual Selector,
                            public virtual Instance
      {
      public:
        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        ValueSelector ()
        {
          type_info (static_type_info ());
        }
      };

      class Union : public virtual TypeTemplateSpecialization,
                    public virtual Scope
      {
      public:
        virtual bool
        complete () const
        {
          return defined ();
        }

        static Introspection::TypeInfo const&
        static_type_info ();

      protected:
        friend class Graph<Node, Edge>;

        Union ()
        {
          type_info (static_type_info ());
        }

        using TypeTemplateSpecialization::add_edge_left;
        using TypeTemplateSpecialization::add_edge_right;
        using Scope::add_edge_left;
      };
    }
  }
}

#endif  // CCF_IDL2_SEMANTIC_GRAPH_UNION_HPP
