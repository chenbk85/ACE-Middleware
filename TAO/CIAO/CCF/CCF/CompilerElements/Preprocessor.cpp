// file      : CCF/CompilerElements/Preprocessor.cpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id$

#include <deque>
#include <locale>
#include <string>

#include "CCF/CompilerElements/Preprocessor.hpp"

#include <iostream>

using std::cerr;
using std::endl;
using std::string;

namespace CCF
{
  namespace CompilerElements
  {
    namespace CPP
    {
      /*
      namespace Phase2
      {
        class TokenPrototype
        {
        public:
          struct Type
          {
            enum Value
            {
              punctuation,
              keyword,
              identifier
              eos
            };
          };

          TokenPrototype (Type::Value type, string const& lexeme)
              : type_ (type), lexeme_ (lexeme)
          {
          }

          Type::Value
          type () const
          {
            return type_;
          }

          string
          lexeme () const
          {
            return lexeme_;
          }

        private:
          Type::Value type_;
          string lexeme_;
        };

        bool
        operator== (TokenPrototype const& a, TokenPrototype const& b)
        {
          return a.type () == b.type () && a.lexeme () == b.lexeme ();
        }

        class Token : public TokenPrototype
        {
        public:
          Token (Type::Value type,
                 string const& lexeme,
                 unsigned long line)
              : TokenPrototype (type, lexeme), line_ (line)
          {
          }

          unsigned long
          line () const
          {
            return line_;
          }

        private:
          unsigned long line_;
        };


        class Scanner : public TokenStream<Token>
        {
        public:
          Scanner (TokenStream<CPP::Token>& is)
              : is_ (is)
          {
          }

          virtual Token
          next ()
          {
            try
            {
              InToken t (get_ns ());

              switch (t)
              {
              case '#':
                {
                  return Token (Token::Type::punctuation, "#", t.line ());
                }
              case '\n':
                {
                  return Token (Token::Type::punctuation, "\n", t.line ());
                }
              }
            }
            catch (EOS const&)
            {
            }
          }

        private:
          typedef
          CPP::Token
          InToken;

          class EOS {};

          InToken
          get () throw (EOS)
          {
            if (ibuffer_.empty ())
            {
              InToken t (is_.next ());
              if (t == InToken::eos) throw EOS ();
              return t;
            }
            else
            {
              InToken t (ibuffer_.front ());
              ibuffer_.pop_front ();

              if (t == InToken::eos) throw EOS ();
              return t;
            }
          }

          // Get first non-space token
          //
          InToken
          get_ns () throw (EOS)
          {
            InToken t (get ());

            while (is_space (t)) t = get ();
          }

          bool
          is_space (InToken const& t)
          {
            return t == ' ' || t == '\t';
          }

        private:
          TokenStream<CPP::Token>& is_;
          std::deque<InTokent> ibuffer_;
        };
      }
      */

      // PreprocessorImpl
      //
      //
      class Preprocessor::PreprocessorImpl : public TokenStream<Token>
      {
      public:
        virtual
        ~PreprocessorImpl ()
        {
        }

        PreprocessorImpl (TokenStream<char>& is)
            : loc_ ("C"),
              state_ (State::preprocessing),
              ln_ (1),
              is_ (is),
              dsa_ (copy_)
        {
        }

        virtual Token
        next ()
        {
          if (line_.empty ()) scan_line ();

          Token t (line_.front ());
          line_.pop_front ();
          return t;
        }

      private:

        // Line-scanning
        //
        //

        class DequeStreamAdapter : public TokenStream<Token>
        {
        public:
          DequeStreamAdapter (std::deque<Token>& d)
              : d_ (d)
          {
          }

          virtual Token
          next ()
          {
            Token t (d_.front ());
            d_.pop_front ();
            return t;
          }

        private:
          std::deque<Token>& d_;
        };

        void
        scan_line ()
        {
          bool eos (false);

          while (line_.empty () && !eos)
          {
            for (;;)
            {
              Token t (next_token ());

              if (t == Token::eos)
              {
                eos = true;

                // Add new line if it's missing at the end of line.
                //
                if (!line_.empty () && line_.back () != '\n')
                {
                  //@@ should issue a warning here
                  //
                  line_.push_back (Token ('\n', line_.back ().line ()));
                }
              }
              else
              {
                line_.push_back (t);
              }

              if (eos || t == '\n') break;
            }

            /*
            cerr << "line: \'";

            for (std::deque<Token>::iterator
                   i (line_.begin ()), e (line_.end ()); i != e; ++i)
            {
              if (*i != Token::eos) cerr << *i;
            }

            cerr << '\'' << endl;
            */

            // Check if it is a PP directive
            //

            copy_ = line_;
            ls_buffer_.clear ();
            copy_.push_back (Token::eos); // add eos

            try
            {
              Token t (ls_get_ns ());

              // cerr << "t = \'" << t << '\'' << endl;

              if (t == '#')
              {
                scan_directive ();
              }
            }
            catch (EOS const&)
            {
              cerr << "EOS" << endl;

              // error condition?
              Token t ('\n', line_.front ().line ());
              line_.clear ();
              line_.push_back (t);
            }
          }

          if (eos) line_.push_back (Token::eos);
        }


        void
        scan_directive ()
        {
          Token t (ls_get_ns ());

          string lexeme;

          if (std::isalpha<char> (t, loc_))
          {
            for (;std::isalpha<char> (t, loc_); t = ls_get ()) lexeme += t;

            ls_ret (t);
          }

          // cerr << "lexeme " << lexeme << endl;

          if (lexeme == "include")
          {
            scan_include ();
          }
          else
          {
            // Ingnore any other directive.
            //
            Token t ('\n', line_.front ().line ());
            line_.clear ();
            line_.push_back (t);
          }
        }

        void
        scan_include ()
        {
          Token t (ls_get_ns ());

          char finilizer;

          switch (t)
          {
          case '\"':
            {
              finilizer = '\"';
              break;

            }
          case '<':
            {
              finilizer = '>';
              break;
            }
          default:
            {
              cerr << t.line () << ": invalid include directive" << endl;
              throw EOS (); //@@ tmp
            }
          }

          string path;

          for (t = ls_get (); t != finilizer && t != '\n'; t = ls_get ())
          {
            path += t;
          }

          if (t != finilizer)
          {
            cerr << t.line () << ": invalid include directive" << endl;
            throw EOS (); // @@ tmp
          }

          string repl (finilizer == '>' ? "__binclude \"" : "__qinclude \"");
          repl += path + "\";\n";

          line_.clear ();

          for (string::const_iterator i (repl.begin ()), e (repl.end ());
               i != e; ++i)
          {
            line_.push_back (Token (*i, t.line ()));
          }
        }

        // Char-scanning
        //
        //

        Token
        next_token ()
        {
          if (!obuffer_.empty ())
          {
            Token t (obuffer_.front ());
            obuffer_.pop_front ();
            return t;
          }

          try
          {
            switch (state_)
            {
            case State::preprocessing:
              {
                return preprocessing ();
              }
            case State::string_literal:
              {
                return string_literal ();
              }
            case State::char_literal:
              {
                return char_literal ();
              }
            }
          }
          catch (EOS const&)
          {
            return Token::eos;
          }
        }

        Token
        preprocessing ()
        {
          unsigned long l (ln_);
          char_type c (get ());

          switch (c)
          {
          case '\'':
            {
              state_ = State::char_literal;
              break;
            }
          case '\"':
            {
              state_ = State::string_literal;
              break;
            }
          case '\\':
            {
              return escape ();
            }
          case '\n':
            {
              ++ln_;
              break;
            }
          case '/':
            {
              return slash ();
            }
          }

          return Token (c, l);
        }


        Token
        string_literal ()
        {
          unsigned long l (ln_);
          char_type c (get ());

          switch (c)
          {
          case '\"':
            {
              state_ = State::preprocessing;
              break;
            }
          case '\\':
            {
              return escape ();
            }
          case '\n':
            {
              ++ln_;
              break;
            }
          }

          return Token (c, l);
        }


        Token
        char_literal ()
        {
          unsigned long l (ln_);
          char_type c (get ());

          switch (c)
          {
          case '\'':
            {
              state_ = State::preprocessing;
              break;
            }
          case '\\':
            {
              return escape ();
            }
          case '\n':
            {
              ++ln_;
              break;
            }
          }

          return Token (c, l);
        }


        Token
        escape ()
        {
          try
          {
            char_type c (get ());

            switch (c)
            {
            case '\n':
              {
                ++ln_;
                return next_token ();
              }
            case '\'':
              {
                if (state_ != State::char_literal &&
                    state_ != State::string_literal)
                {
                  state_ = State::char_literal;
                }

                put (Token ('\'', ln_));
                return Token ('\\', ln_);
              }
            case '\"':
              {
                if (state_ != State::char_literal &&
                    state_ != State::string_literal)
                {
                  state_ = State::string_literal;
                }

                put (Token ('\"', ln_));
                return Token ('\\', ln_);
              }
            default:
              {
                ret (c);
                return Token ('\\', ln_);
              }
            }
          }
          catch (EOS const&)
          {
            ret_eos ();
            return Token ('\\', ln_);
          }
        }


        Token
        slash ()
        {
          unsigned long l (ln_);

          try
          {
            char_type c (get ());

            switch (c)
            {
            case '*': // C comment
              {
                return c_comment ();
              }
            case '/': // C++ comment
              {
                return cxx_comment ();
              }
            default:
              {
                ret (c);
                break;
              }
            }
          }
          catch (EOS const&)
          {
            ret_eos ();
          }

          return Token ('/', l);
        }


        Token
        c_comment ()
        {
          // Replace the whole C comment with the single space.
          //
          unsigned long l (ln_);

          try
          {
            char_type c (get ());

            for (bool done (false); !done;)
            {
              switch (c)
              {
              case '\n':
                {
                  ++ln_;
                  break;
                }
              case '*':
                {
                  c = get ();
                  if (c == '/') done = true;
                  continue;
                }
              }

              c  = get ();
            }
          }
          catch (EOS const&)
          {
            put (Token::eos);
          }

          return Token (' ', l);
        }


        Token
        cxx_comment ()
        {
          // Replace the whole C++ comment with the single space.
          //
          unsigned long l (ln_);

          try
          {
            for (bool done (false); !done;)
            {
              char_type c (get ());

              switch (c)
              {
              case '\n':
                {
                  ++ln_;
                  done = true;
                  break;
                }
              }
            }
          }
          catch (EOS const&)
          {
            put (Token::eos);
          }

          return Token ('\n', l);
        }

        // Low-level utility functions.
        //
      private:
        typedef
        TokenStream<char>::int_type
        int_type;

        typedef
        TokenStream<char>::char_type
        char_type;

        char_type
        to_char_type (int_type i)
        {
          return TokenStream<char>::to_char_type (i);
        }

        bool
        eos (int_type i)
        {
          return TokenStream<char>::eos () == i;
        }

        class EOS {};

        char_type
        get () throw (EOS)
        {
          int_type i;

          if (ibuffer_.empty ())
          {
            i = is_.next ();
          }
          else
          {
            i = ibuffer_.front ();
            ibuffer_.pop_front ();
          }

          if (eos (i)) throw EOS ();

          return to_char_type (i);
        }

        void
        ret (char_type t)
        {
          ibuffer_.push_front (t);
        }

        void
        ret_eos ()
        {
          ibuffer_.push_front (TokenStream<char>::eos ());
        }

        void
        put (Token const& t)
        {
          obuffer_.push_back (t);
        }


        // line-scanner utility functions
        //
        //
        void
        ls_ret (Token const& t)
        {
          ls_buffer_.push_front (t);
        }

        Token
        ls_get () throw (EOS)
        {
          if (ls_buffer_.empty ())
          {
            Token t (dsa_.next ());
            if (t == Token::eos) throw EOS ();
            return t;
          }
          else
          {
            Token t (ls_buffer_.front ());
            ls_buffer_.pop_front ();

            if (t == Token::eos) throw EOS ();
            return t;
          }
        }

        // Get first non-space token
        //
        Token
        ls_get_ns () throw (EOS)
        {
          Token t (ls_get ());

          while (ls_is_space (t)) t = ls_get ();
          return t;
        }

        bool
        ls_is_space (Token const& t)
        {
          return t == ' ' || t == '\t';
        }

      private:
        struct State
        {
          enum Value
          {
            preprocessing,
            string_literal,
            char_literal
          };
        };

        std::locale loc_;

        State::Value state_;
        unsigned long ln_;

        TokenStream<char>& is_;

        std::deque<int_type> ibuffer_;
        std::deque<Token> obuffer_;

        std::deque<Token> line_;

        std::deque<Token> copy_;
        DequeStreamAdapter dsa_;
        std::deque<Token> ls_buffer_;
      };


      // Preprocessor
      //
      //
      Preprocessor::
      ~Preprocessor ()
      {
      }

      Preprocessor::
      Preprocessor (TokenStream<char>& is)
          : impl_ (new PreprocessorImpl (is))
      {
      }

      Token Preprocessor::
      next ()
      {
        return impl_->next ();
      }
    }
  }
}
