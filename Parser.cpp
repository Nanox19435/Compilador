// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "Parser.hpp"


// Unqualified %code blocks.
#line 35 "src/parser/parser.yy"

    #include <iostream>
    #include <fstream>
    using namespace std;

    #include "Lexer.hpp"
    #include "Driver.hpp"
    #include "Quad.hpp"
    #include <vector>
    #include <iterator>
    
    #define yylex lexer.yylex

#line 60 "Parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 133 "Parser.cpp"

  /// Build a parser object.
  Parser::Parser (Lexer &lexer_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg),
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expresion: // expresion
        value.YY_MOVE_OR_COPY< expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTV: // INTV
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_literal: // literal
        value.YY_MOVE_OR_COPY< literal > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_F32V: // F32V
      case symbol_kind::S_F64V: // F64V
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo_arreglo: // tipo_arreglo
        value.YY_MOVE_OR_COPY< tipo_arreglo<std::int> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lista_id: // lista_id
        value.YY_MOVE_OR_COPY< vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expresion: // expresion
        value.move< expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTV: // INTV
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_literal: // literal
        value.move< literal > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_F32V: // F32V
      case symbol_kind::S_F64V: // F64V
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo_arreglo: // tipo_arreglo
        value.move< tipo_arreglo<std::int> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lista_id: // lista_id
        value.move< vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_expresion: // expresion
        value.copy< expresion > (that.value);
        break;

      case symbol_kind::S_INTV: // INTV
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_literal: // literal
        value.copy< literal > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_F32V: // F32V
      case symbol_kind::S_F64V: // F64V
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_tipo_arreglo: // tipo_arreglo
        value.copy< tipo_arreglo<std::int> > (that.value);
        break;

      case symbol_kind::S_lista_id: // lista_id
        value.copy< vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_expresion: // expresion
        value.move< expresion > (that.value);
        break;

      case symbol_kind::S_INTV: // INTV
        value.move< int > (that.value);
        break;

      case symbol_kind::S_literal: // literal
        value.move< literal > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_F32V: // F32V
      case symbol_kind::S_F64V: // F64V
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_tipo_arreglo: // tipo_arreglo
        value.move< tipo_arreglo<std::int> > (that.value);
        break;

      case symbol_kind::S_lista_id: // lista_id
        value.move< vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_expresion: // expresion
        yylhs.value.emplace< expresion > ();
        break;

      case symbol_kind::S_INTV: // INTV
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_literal: // literal
        yylhs.value.emplace< literal > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_F32V: // F32V
      case symbol_kind::S_F64V: // F64V
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_tipo_arreglo: // tipo_arreglo
        yylhs.value.emplace< tipo_arreglo<std::int> > ();
        break;

      case symbol_kind::S_lista_id: // lista_id
        yylhs.value.emplace< vector<std::string> > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // programa: declaraciones
#line 88 "src/parser/parser.yy"
                  {}
#line 681 "Parser.cpp"
    break;

  case 4: // declaraciones: %empty
#line 92 "src/parser/parser.yy"
                  {}
#line 687 "Parser.cpp"
    break;

  case 5: // declaracion: decl_const
#line 95 "src/parser/parser.yy"
               {}
#line 693 "Parser.cpp"
    break;

  case 6: // declaracion: decl_var
#line 96 "src/parser/parser.yy"
               {}
#line 699 "Parser.cpp"
    break;

  case 7: // declaracion: decl_proto
#line 97 "src/parser/parser.yy"
                 {}
#line 705 "Parser.cpp"
    break;

  case 8: // declaracion: decl_func
#line 98 "src/parser/parser.yy"
                {}
#line 711 "Parser.cpp"
    break;

  case 9: // decl_const: CONST tipo lista_id_const
#line 101 "src/parser/parser.yy"
                              {}
#line 717 "Parser.cpp"
    break;

  case 10: // lista_id_const: lista_id_const COMA ID ASIG literal
#line 104 "src/parser/parser.yy"
                                        {}
#line 723 "Parser.cpp"
    break;

  case 11: // lista_id_const: ID ASIG literal
#line 105 "src/parser/parser.yy"
                      {}
#line 729 "Parser.cpp"
    break;

  case 12: // decl_var: VAR tipo lista_id
#line 108 "src/parser/parser.yy"
                      {}
#line 735 "Parser.cpp"
    break;

  case 13: // lista_id: lista_id COMA ID
#line 112 "src/parser/parser.yy"
    {
        vector<std::string> id_l = yystack_[2].value.as < vector<std::string> > ();
        vector<std::string> single = driver.idVec(yystack_[0].value.as < std::string > ());
        id_l.insert(
            id_l.end(),
            std::make_move_iterator(single.begin()),
            std::make_move_iterator(single.end())
        );

        yylhs.value.as < vector<std::string> > () = id_l;
    }
#line 751 "Parser.cpp"
    break;

  case 14: // lista_id: ID
#line 124 "src/parser/parser.yy"
    {
        yylhs.value.as < vector<std::string> > () = driver.idVec(yystack_[0].value.as < std::string > ());
    }
#line 759 "Parser.cpp"
    break;

  case 15: // decl_proto: PROTO tipo ID LPAR lista_tipos RPAR
#line 129 "src/parser/parser.yy"
                                        {}
#line 765 "Parser.cpp"
    break;

  case 16: // lista_tipos: tipos
#line 132 "src/parser/parser.yy"
          {}
#line 771 "Parser.cpp"
    break;

  case 17: // lista_tipos: %empty
#line 133 "src/parser/parser.yy"
                {}
#line 777 "Parser.cpp"
    break;

  case 18: // tipos: tipos COMA tipo
#line 136 "src/parser/parser.yy"
                    {}
#line 783 "Parser.cpp"
    break;

  case 19: // tipos: tipo
#line 137 "src/parser/parser.yy"
           {}
#line 789 "Parser.cpp"
    break;

  case 20: // decl_func: FUNC tipo ID LPAR lista_param RPAR bloque
#line 140 "src/parser/parser.yy"
                                              {}
#line 795 "Parser.cpp"
    break;

  case 21: // tipo: nombre_tipo tipo_arreglo
#line 143 "src/parser/parser.yy"
                             {}
#line 801 "Parser.cpp"
    break;

  case 22: // tipo: tipo_estructura
#line 144 "src/parser/parser.yy"
                      {}
#line 807 "Parser.cpp"
    break;

  case 23: // tipo: nombre_tipo MUL
#line 145 "src/parser/parser.yy"
                      {}
#line 813 "Parser.cpp"
    break;

  case 24: // $@1: %empty
#line 148 "src/parser/parser.yy"
                {}
#line 819 "Parser.cpp"
    break;

  case 25: // nombre_tipo: nombre_tipo $@1 CHAR
#line 149 "src/parser/parser.yy"
         {}
#line 825 "Parser.cpp"
    break;

  case 26: // nombre_tipo: INT
#line 150 "src/parser/parser.yy"
          {}
#line 831 "Parser.cpp"
    break;

  case 27: // nombre_tipo: F32
#line 151 "src/parser/parser.yy"
          {}
#line 837 "Parser.cpp"
    break;

  case 28: // nombre_tipo: F64
#line 152 "src/parser/parser.yy"
          {}
#line 843 "Parser.cpp"
    break;

  case 29: // nombre_tipo: STR
#line 153 "src/parser/parser.yy"
          {}
#line 849 "Parser.cpp"
    break;

  case 30: // nombre_tipo: BOOL
#line 154 "src/parser/parser.yy"
           {}
#line 855 "Parser.cpp"
    break;

  case 31: // nombre_tipo: VOID
#line 155 "src/parser/parser.yy"
           {}
#line 861 "Parser.cpp"
    break;

  case 32: // tipo_arreglo: LBRACK expresion RBRACK tipo_arreglo
#line 158 "src/parser/parser.yy"
                                         {
        if (yylhs.value.as < tipo_arreglo<std::int> > ()2.type == 1) {
            if (yylhs.value.as < tipo_arreglo<std::int> > ()2.data > 0) {
                yylhs.value.as < tipo_arreglo<std::int> > ().type = driver.addToTypeTab("ARRAY", yystack_[2].value.as < expresion > ().type * yylhs.value.as < tipo_arreglo<std::int> > ()2.data);
            } else {
                driver.error("El indice debe de ser mayor a 0");
            }
        } else {
            driver.error("El indice debe de ser entero");
        }
    }
#line 877 "Parser.cpp"
    break;

  case 33: // tipo_arreglo: %empty
#line 169 "src/parser/parser.yy"
                {}
#line 883 "Parser.cpp"
    break;

  case 34: // tipo_estructura: STRUCT LBRACE decl_campo RBRACE
#line 172 "src/parser/parser.yy"
                                    {}
#line 889 "Parser.cpp"
    break;

  case 35: // tipo_estructura: STRUCT ID LBRACE decl_campo RBRACE
#line 173 "src/parser/parser.yy"
                                         {}
#line 895 "Parser.cpp"
    break;

  case 36: // decl_campo: tipo lista_id PYC decl_campo
#line 176 "src/parser/parser.yy"
                                 {}
#line 901 "Parser.cpp"
    break;

  case 37: // decl_campo: %empty
#line 177 "src/parser/parser.yy"
                {}
#line 907 "Parser.cpp"
    break;

  case 38: // lista_param: decl_params
#line 180 "src/parser/parser.yy"
                {}
#line 913 "Parser.cpp"
    break;

  case 39: // lista_param: %empty
#line 181 "src/parser/parser.yy"
                {}
#line 919 "Parser.cpp"
    break;

  case 40: // decl_params: decl_params COMA decl_param
#line 184 "src/parser/parser.yy"
                                {}
#line 925 "Parser.cpp"
    break;

  case 41: // decl_params: decl_param
#line 185 "src/parser/parser.yy"
                 {}
#line 931 "Parser.cpp"
    break;

  case 42: // decl_param: tipo_param ID
#line 188 "src/parser/parser.yy"
                  {}
#line 937 "Parser.cpp"
    break;

  case 43: // tipo_param: nombre_tipo tipo_param_arr
#line 191 "src/parser/parser.yy"
                               {}
#line 943 "Parser.cpp"
    break;

  case 44: // tipo_param: STRUCT ID
#line 192 "src/parser/parser.yy"
                {}
#line 949 "Parser.cpp"
    break;

  case 45: // tipo_param: nombre_tipo MUL
#line 193 "src/parser/parser.yy"
                      {}
#line 955 "Parser.cpp"
    break;

  case 46: // tipo_param_arr: LBRACK expresion RBRACK tipo_param_arr
#line 196 "src/parser/parser.yy"
                                           {}
#line 961 "Parser.cpp"
    break;

  case 47: // tipo_param_arr: %empty
#line 197 "src/parser/parser.yy"
                {}
#line 967 "Parser.cpp"
    break;

  case 48: // bloque: LBRACE lista_sentencias RBRACE
#line 200 "src/parser/parser.yy"
                                   {}
#line 973 "Parser.cpp"
    break;

  case 49: // lista_sentencias: lista_sentencias sentencia
#line 203 "src/parser/parser.yy"
                               {}
#line 979 "Parser.cpp"
    break;

  case 51: // sentencia: decl_loc
#line 207 "src/parser/parser.yy"
             {}
#line 985 "Parser.cpp"
    break;

  case 52: // sentencia: sentencia_simple PYC
#line 208 "src/parser/parser.yy"
                           {}
#line 991 "Parser.cpp"
    break;

  case 53: // sentencia: sentencia_return PYC
#line 209 "src/parser/parser.yy"
                           {}
#line 997 "Parser.cpp"
    break;

  case 54: // sentencia: BREAK PYC
#line 210 "src/parser/parser.yy"
                {}
#line 1003 "Parser.cpp"
    break;

  case 55: // sentencia: CONTINUE PYC
#line 211 "src/parser/parser.yy"
                   {}
#line 1009 "Parser.cpp"
    break;

  case 56: // sentencia: bloque
#line 212 "src/parser/parser.yy"
             {}
#line 1015 "Parser.cpp"
    break;

  case 57: // sentencia: sentencia_if
#line 213 "src/parser/parser.yy"
                   {}
#line 1021 "Parser.cpp"
    break;

  case 58: // sentencia: sentencia_switch
#line 214 "src/parser/parser.yy"
                       {}
#line 1027 "Parser.cpp"
    break;

  case 59: // sentencia: sentencia_for
#line 215 "src/parser/parser.yy"
                    {}
#line 1033 "Parser.cpp"
    break;

  case 60: // sentencia: PRINT expresion PYC
#line 216 "src/parser/parser.yy"
                          {}
#line 1039 "Parser.cpp"
    break;

  case 61: // sentencia: READ ID PYC
#line 217 "src/parser/parser.yy"
                  {}
#line 1045 "Parser.cpp"
    break;

  case 62: // decl_loc: VAR nombre_tipo MUL lista_id
#line 220 "src/parser/parser.yy"
                                 {}
#line 1051 "Parser.cpp"
    break;

  case 63: // decl_loc: VAR STRUCT ID lista_id
#line 221 "src/parser/parser.yy"
                             {}
#line 1057 "Parser.cpp"
    break;

  case 64: // decl_loc: VAR nombre_tipo tipo_arreglo lista_id
#line 222 "src/parser/parser.yy"
                                            {}
#line 1063 "Parser.cpp"
    break;

  case 65: // sentencia_simple: expresion
#line 225 "src/parser/parser.yy"
              {}
#line 1069 "Parser.cpp"
    break;

  case 66: // sentencia_simple: incdec
#line 226 "src/parser/parser.yy"
             {}
#line 1075 "Parser.cpp"
    break;

  case 67: // sentencia_simple: asig
#line 227 "src/parser/parser.yy"
           {}
#line 1081 "Parser.cpp"
    break;

  case 68: // asig: izq op_asig expresion
#line 230 "src/parser/parser.yy"
                          {}
#line 1087 "Parser.cpp"
    break;

  case 69: // incdec: expresion INCR
#line 233 "src/parser/parser.yy"
                   {}
#line 1093 "Parser.cpp"
    break;

  case 70: // incdec: expresion DECR
#line 234 "src/parser/parser.yy"
                     {}
#line 1099 "Parser.cpp"
    break;

  case 71: // op_asig: ASIG
#line 237 "src/parser/parser.yy"
         {}
#line 1105 "Parser.cpp"
    break;

  case 72: // op_asig: SASIG
#line 238 "src/parser/parser.yy"
            {}
#line 1111 "Parser.cpp"
    break;

  case 73: // op_asig: RASIG
#line 239 "src/parser/parser.yy"
            {}
#line 1117 "Parser.cpp"
    break;

  case 74: // op_asig: PASIG
#line 240 "src/parser/parser.yy"
            {}
#line 1123 "Parser.cpp"
    break;

  case 75: // op_asig: DASIG
#line 241 "src/parser/parser.yy"
            {}
#line 1129 "Parser.cpp"
    break;

  case 76: // op_asig: MASIG
#line 242 "src/parser/parser.yy"
            {}
#line 1135 "Parser.cpp"
    break;

  case 77: // sentencia_if: IF expresion bloque
#line 245 "src/parser/parser.yy"
                        {}
#line 1141 "Parser.cpp"
    break;

  case 78: // sentencia_if: IF expresion bloque ELSE bloque
#line 246 "src/parser/parser.yy"
                                      {}
#line 1147 "Parser.cpp"
    break;

  case 79: // sentencia_switch: SWITCH sentencia_simple LBRACE expr_casos RBRACE
#line 249 "src/parser/parser.yy"
                                                     {}
#line 1153 "Parser.cpp"
    break;

  case 80: // expr_casos: expr_casos expr_caso
#line 252 "src/parser/parser.yy"
                         {}
#line 1159 "Parser.cpp"
    break;

  case 81: // expr_casos: expr_caso
#line 253 "src/parser/parser.yy"
                {}
#line 1165 "Parser.cpp"
    break;

  case 82: // expr_caso: caso COL lista_sentencias
#line 256 "src/parser/parser.yy"
                              {}
#line 1171 "Parser.cpp"
    break;

  case 83: // caso: CASE expresion
#line 259 "src/parser/parser.yy"
                   {}
#line 1177 "Parser.cpp"
    break;

  case 84: // caso: DEFAULT
#line 260 "src/parser/parser.yy"
              {}
#line 1183 "Parser.cpp"
    break;

  case 85: // sentencia_for: FOR LPAR clausula_for RPAR bloque
#line 263 "src/parser/parser.yy"
                                      {}
#line 1189 "Parser.cpp"
    break;

  case 86: // clausula_for: sentencia_simple PYC expresion PYC sentencia_simple
#line 266 "src/parser/parser.yy"
                                                        {}
#line 1195 "Parser.cpp"
    break;

  case 87: // clausula_for: expresion
#line 267 "src/parser/parser.yy"
                {}
#line 1201 "Parser.cpp"
    break;

  case 88: // sentencia_return: RETURN expresion
#line 270 "src/parser/parser.yy"
                     {}
#line 1207 "Parser.cpp"
    break;

  case 89: // sentencia_return: RETURN
#line 271 "src/parser/parser.yy"
             {}
#line 1213 "Parser.cpp"
    break;

  case 90: // izq: ID dato_miembro
#line 274 "src/parser/parser.yy"
                    {}
#line 1219 "Parser.cpp"
    break;

  case 91: // izq: ID parte_arreglo
#line 275 "src/parser/parser.yy"
                       {}
#line 1225 "Parser.cpp"
    break;

  case 92: // izq: ID llamada_funcion
#line 276 "src/parser/parser.yy"
                         {}
#line 1231 "Parser.cpp"
    break;

  case 93: // dato_miembro: DOT ID dato_miembro
#line 279 "src/parser/parser.yy"
                        {}
#line 1237 "Parser.cpp"
    break;

  case 94: // dato_miembro: %empty
#line 280 "src/parser/parser.yy"
                {}
#line 1243 "Parser.cpp"
    break;

  case 95: // parte_arreglo: LBRACK expresion RBRACK parte_arreglo
#line 283 "src/parser/parser.yy"
                                          {}
#line 1249 "Parser.cpp"
    break;

  case 96: // parte_arreglo: LBRACK expresion RBRACK
#line 284 "src/parser/parser.yy"
                              {}
#line 1255 "Parser.cpp"
    break;

  case 97: // llamada_funcion: LPAR args RPAR
#line 287 "src/parser/parser.yy"
                   {}
#line 1261 "Parser.cpp"
    break;

  case 98: // args: lista_args
#line 290 "src/parser/parser.yy"
               {}
#line 1267 "Parser.cpp"
    break;

  case 99: // args: %empty
#line 291 "src/parser/parser.yy"
                {}
#line 1273 "Parser.cpp"
    break;

  case 100: // lista_args: expresion COMA lista_args
#line 294 "src/parser/parser.yy"
                              {}
#line 1279 "Parser.cpp"
    break;

  case 101: // lista_args: expresion
#line 295 "src/parser/parser.yy"
                {}
#line 1285 "Parser.cpp"
    break;

  case 102: // expresion: expresion OR expresion
#line 298 "src/parser/parser.yy"
                           { 
        if (yystack_[2].value.as < expresion > ().type == 0 && 0 == yystack_[0].value.as < expresion > ().type) {
            yylhs.value.as < expresion > ().type = 0 ;
            string a = yystack_[2].value.as < expresion > ().temp;
            string b = yystack_[0].value.as < expresion > ().temp;
            yylhs.value.as < expresion > ().temp = driver.newTmp();
            driver.pushQuad(OR, a, b, yylhs.value.as < expresion > ().temp);
        } else {
            /*error*/
            driver.error("Tipos incompatibles"); 
        }
       }
#line 1302 "Parser.cpp"
    break;

  case 103: // expresion: expresion AND expresion
#line 310 "src/parser/parser.yy"
                              {
        if (yystack_[2].value.as < expresion > ().type == 0 && 0 == yystack_[0].value.as < expresion > ().type) {
            yylhs.value.as < expresion > ().type = 0 ;
            yylhs.value.as < expresion > ().data = yystack_[2].value.as < expresion > ().data && yystack_[0].value.as < expresion > ().data;
        } else {
            /*error*/
        }
    }
#line 1315 "Parser.cpp"
    break;

  case 104: // expresion: expresion EQ expresion
#line 318 "src/parser/parser.yy"
                             {
        if (yystack_[2].value.as < expresion > ().type == yystack_[0].value.as < expresion > ().type) {
            yylhs.value.as < expresion > ().type = 0 ;
            yylhs.value.as < expresion > ().data = yystack_[2].value.as < expresion > ().data == yystack_[0].value.as < expresion > ().data;
        } else {
            yylhs.value.as < expresion > ().type = 0 ;
            yylhs.value.as < expresion > ().data = FALSE;
            /*error*/
        }
    }
#line 1330 "Parser.cpp"
    break;

  case 105: // expresion: expresion NEQ expresion
#line 328 "src/parser/parser.yy"
                              {
        if (yystack_[2].value.as < expresion > ().type == yystack_[0].value.as < expresion > ().type) {
            yylhs.value.as < expresion > ().type = 0 ;
            yylhs.value.as < expresion > ().data = yystack_[2].value.as < expresion > ().data != yystack_[0].value.as < expresion > ().data;
        } else {
            /*error*/
            yylhs.value.as < expresion > ().type = 0 ;
            yylhs.value.as < expresion > ().data = TRUE;
        }
    }
#line 1345 "Parser.cpp"
    break;

  case 106: // expresion: expresion LESS expresion
#line 338 "src/parser/parser.yy"
                               {
        if (yystack_[2].value.as < expresion > ().type == 1 == yystack_[0].value.as < expresion > ().type) {
            yylhs.value.as < expresion > ().type = 1 ;
            yylhs.value.as < expresion > ().data = yystack_[2].value.as < expresion > ().data < yystack_[0].value.as < expresion > ().data;
        } else {
            /*error*/
        }
    }
#line 1358 "Parser.cpp"
    break;

  case 107: // expresion: expresion LEQ expresion
#line 346 "src/parser/parser.yy"
                              {
        if (yystack_[2].value.as < expresion > ().type == 1 == yystack_[0].value.as < expresion > ().type) {
            yylhs.value.as < expresion > ().type = 1 ;
            yylhs.value.as < expresion > ().data = yystack_[2].value.as < expresion > ().data <= yystack_[0].value.as < expresion > ().data;
        } else {
            /*error*/
        }
    }
#line 1371 "Parser.cpp"
    break;

  case 108: // expresion: expresion GREAT expresion
#line 354 "src/parser/parser.yy"
                                {
        if (yystack_[2].value.as < expresion > ().type == 1 == yystack_[0].value.as < expresion > ().type) {
            yylhs.value.as < expresion > ().type = 1 ;
            yylhs.value.as < expresion > ().data = yystack_[2].value.as < expresion > ().data > yystack_[0].value.as < expresion > ().data;
        } else {
            /*error*/
        }
    }
#line 1384 "Parser.cpp"
    break;

  case 109: // expresion: expresion GEQ expresion
#line 362 "src/parser/parser.yy"
                              {
        if (yystack_[2].value.as < expresion > ().type == 1 == yystack_[0].value.as < expresion > ().type) {
            yylhs.value.as < expresion > ().type = 1 ;
            yylhs.value.as < expresion > ().data = yystack_[2].value.as < expresion > ().data >= yystack_[0].value.as < expresion > ().data;
        } else {
            /*error*/
        }
    }
#line 1397 "Parser.cpp"
    break;

  case 110: // expresion: expresion PLUS expresion
#line 370 "src/parser/parser.yy"
                               {
        if (yystack_[2].value.as < expresion > ().type == 1 == yystack_[0].value.as < expresion > ().type) {
            yylhs.value.as < expresion > ().type = 1 ;
            yylhs.value.as < expresion > ().data = yystack_[2].value.as < expresion > ().data + yystack_[0].value.as < expresion > ().data;
        } else {
            /*error*/
        }
    }
#line 1410 "Parser.cpp"
    break;

  case 111: // expresion: expresion SUB expresion
#line 378 "src/parser/parser.yy"
                              {
        if (yystack_[2].value.as < expresion > ().type == 1 == yystack_[0].value.as < expresion > ().type) {
            yylhs.value.as < expresion > ().type = 1 ;
            yylhs.value.as < expresion > ().data = yystack_[2].value.as < expresion > ().data - yystack_[0].value.as < expresion > ().data;
        } else {
            /*error*/
        }
    }
#line 1423 "Parser.cpp"
    break;

  case 112: // expresion: expresion MUL expresion
#line 386 "src/parser/parser.yy"
                              {
        if (yystack_[2].value.as < expresion > ().type == 1 == yystack_[0].value.as < expresion > ().type) {
            yylhs.value.as < expresion > ().type = 1 ;
            yylhs.value.as < expresion > ().data = yystack_[2].value.as < expresion > ().data * yystack_[0].value.as < expresion > ().data;
        } else {
            /*error*/
        }
    }
#line 1436 "Parser.cpp"
    break;

  case 113: // expresion: expresion DIV expresion
#line 394 "src/parser/parser.yy"
                              {
        if (yystack_[2].value.as < expresion > ().type == 1 == yystack_[0].value.as < expresion > ().type) {
            yylhs.value.as < expresion > ().type = 1 ;
            yylhs.value.as < expresion > ().data = yystack_[2].value.as < expresion > ().data / yystack_[0].value.as < expresion > ().data;
        } else {
            /*error*/
        }
    }
#line 1449 "Parser.cpp"
    break;

  case 114: // expresion: expresion MOD expresion
#line 402 "src/parser/parser.yy"
                              {
        if (yystack_[2].value.as < expresion > ().type == 1 == yystack_[0].value.as < expresion > ().type) {
            yylhs.value.as < expresion > ().type = 1 ;
            yylhs.value.as < expresion > ().data = yystack_[2].value.as < expresion > ().data / yystack_[0].value.as < expresion > ().data;
        } else {
            /*error*/
        }
    }
#line 1462 "Parser.cpp"
    break;

  case 115: // expresion: izq
#line 410 "src/parser/parser.yy"
          {}
#line 1468 "Parser.cpp"
    break;

  case 116: // expresion: literal
#line 412 "src/parser/parser.yy"
              {}
#line 1474 "Parser.cpp"
    break;

  case 117: // expresion: LPAR expresion RPAR
#line 413 "src/parser/parser.yy"
                          {
        yylhs.value.as < expresion > ().data = yystack_[1].value.as < expresion > ().data ;
    }
#line 1482 "Parser.cpp"
    break;

  case 118: // expresion: conversion
#line 416 "src/parser/parser.yy"
                 {}
#line 1488 "Parser.cpp"
    break;

  case 119: // conversion: nombre_tipo LPAR expresion RPAR
#line 419 "src/parser/parser.yy"
                                    {}
#line 1494 "Parser.cpp"
    break;

  case 120: // literal: TRUE
#line 423 "src/parser/parser.yy"
    { 
        literal l; 
        l.type = 0;
        l.data = &yystack_[0].value.as < bool > ();

        yylhs.value.as < literal > () = l;
    }
#line 1506 "Parser.cpp"
    break;

  case 121: // literal: FALSE
#line 431 "src/parser/parser.yy"
    { 
        literal l; 
        l.type = 0;
        l.data = &yystack_[0].value.as < bool > ();

        yylhs.value.as < literal > () = l;
    }
#line 1518 "Parser.cpp"
    break;

  case 122: // literal: INTV
#line 439 "src/parser/parser.yy"
    { 
        literal l; 
        l.type = 1;
        l.data = &yystack_[0].value.as < int > ();

        yylhs.value.as < literal > () = l;
    }
#line 1530 "Parser.cpp"
    break;

  case 123: // literal: F32V
#line 447 "src/parser/parser.yy"
    { 
        literal l; 
        l.type = 2;
        l.data = &yystack_[0].value.as < std::string > ();

        yylhs.value.as < literal > () = l;
    }
#line 1542 "Parser.cpp"
    break;

  case 124: // literal: F64V
#line 455 "src/parser/parser.yy"
    { 
        literal l; 
        l.type = 3;
        l.data = &yystack_[0].value.as < std::string > ();

        yylhs.value.as < literal > () = l;
    }
#line 1554 "Parser.cpp"
    break;

  case 125: // literal: CHAR
#line 463 "src/parser/parser.yy"
    { 
        literal l; 
        l.type = 4;
        l.data = &yystack_[0].value.as < std::string > ();

        yylhs.value.as < literal > () = l;
    }
#line 1566 "Parser.cpp"
    break;

  case 126: // literal: STR
#line 471 "src/parser/parser.yy"
    { 
        literal l; 
        l.type = 5;
        l.data = &yystack_[0].value.as < std::string > ();

        yylhs.value.as < literal > () = l;
    }
#line 1578 "Parser.cpp"
    break;


#line 1582 "Parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const short Parser::yypact_ninf_ = -148;

  const signed char Parser::yytable_ninf_ = -88;

  const short
  Parser::yypact_[] =
  {
    -148,    21,    10,  -148,    94,    94,    94,    94,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,    13,
      22,    18,  -148,    37,    55,    58,   -37,    94,  -148,    16,
    -148,   225,    63,  -148,    38,    68,    30,    32,    94,    22,
      33,    90,   -26,    23,  -148,  -148,  -148,  -148,  -148,  -148,
     225,    35,  -148,   301,  -148,  -148,  -148,   144,    96,    94,
      99,    39,    46,  -148,  -148,   112,   225,   225,  -148,  -148,
    -148,   409,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,    34,  -148,  -148,    67,
      56,   100,  -148,   116,    14,    61,   107,  -148,   123,  -148,
      94,    71,    79,  -148,   263,   324,  -148,   428,   287,   474,
     197,   197,    81,    81,    81,    81,    31,    31,  -148,  -148,
    -148,  -148,   144,  -148,    94,  -148,  -148,   225,  -148,    80,
      99,  -148,  -148,  -148,  -148,   225,    77,  -148,  -148,  -148,
     347,   193,  -148,  -148,  -148,  -148,    82,   314,   225,    84,
     225,   225,   128,   130,   225,   155,  -148,   159,  -148,  -148,
     145,  -148,  -148,  -148,  -148,  -148,   160,   227,   447,  -148,
     157,    15,   370,   225,   114,   463,  -148,  -148,   226,   164,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
     225,  -148,  -148,    22,    22,    22,   161,   166,   126,   390,
      44,  -148,  -148,   463,    16,    16,    16,    80,   225,    80,
     225,  -148,    -5,  -148,   170,  -148,   243,  -148,   463,  -148,
    -148,   193,   225,   193,  -148
  };

  const signed char
  Parser::yydefact_[] =
  {
       4,     0,     2,     1,     0,     0,     0,     0,     3,     5,
       6,     7,     8,    29,    31,    30,    26,    27,    28,     0,
       0,    33,    22,     0,     0,     0,     0,    37,    14,    12,
      23,     0,     0,    21,     0,     9,     0,     0,    37,     0,
       0,     0,    94,   126,   125,   122,   123,   124,   120,   121,
       0,    24,   115,     0,   118,   116,    25,     0,     0,    17,
      39,     0,     0,    34,    13,     0,    99,     0,    90,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,   126,    11,     0,
       0,    16,    19,     0,    24,     0,    38,    41,     0,    35,
      37,    94,     0,    98,   101,     0,   117,     0,   102,   103,
     104,   105,   106,   108,   107,   109,   110,   111,   112,   113,
     114,    32,     0,    15,     0,    44,    45,     0,    43,     0,
       0,    42,    36,    93,    97,     0,    96,   119,    10,    18,
       0,     0,    20,    40,   100,    95,    47,     0,     0,     0,
       0,    89,     0,     0,     0,     0,    56,     0,    50,    51,
       0,    67,    66,    57,    58,    59,     0,   115,    65,    46,
       0,    24,     0,     0,     0,    88,    54,    55,     0,     0,
      48,    49,    52,    53,    71,    72,    73,    74,    75,    76,
       0,    69,    70,     0,     0,     0,    77,     0,     0,    65,
       0,    60,    61,    68,    63,    62,    64,     0,     0,     0,
       0,    84,     0,    81,     0,    78,     0,    85,    83,    79,
      80,     0,     0,    82,    86
  };

  const short
  Parser::yypgoto_[] =
  {
    -148,  -148,  -148,  -148,  -148,  -148,  -148,   -38,  -148,  -148,
    -148,  -148,     4,     0,  -148,   -84,  -148,   -24,  -148,  -148,
      64,  -148,    42,  -117,   -12,  -144,  -148,  -147,  -148,  -148,
    -148,  -148,  -148,  -148,   -17,  -148,  -148,  -148,  -148,   -85,
     109,    75,  -148,  -148,    78,   -31,  -148,   -42
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,     8,     9,    35,    10,    29,    11,    90,
      91,    12,    39,    51,    32,    33,    22,    40,    95,    96,
      97,    98,   128,   156,   157,   158,   159,   160,   161,   162,
     190,   163,   164,   212,   213,   214,   165,   198,   166,    52,
      68,    69,    70,   102,   103,   168,    54,    55
  };

  const short
  Parser::yytable_[] =
  {
      53,    62,   121,   174,    21,    21,    21,    21,    20,    23,
      24,    25,   142,   181,    61,    88,    26,   -47,   -33,    71,
     210,     3,   211,   -24,    38,    28,   197,    21,   -29,     4,
       5,     6,    65,    66,    41,   104,   105,    67,    21,     7,
      34,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   196,   167,   219,    36,    21,
      94,    37,   100,    92,    41,   167,   126,   194,    56,   210,
      30,   211,   167,    57,    27,   224,   132,   127,    31,   181,
     138,    31,   -29,    83,    84,    85,    58,   195,   167,    59,
     215,    60,   217,    64,    72,    63,   140,    31,    13,    89,
      21,    99,   122,    13,   104,    14,    15,    16,    17,    18,
      14,    15,    16,    17,    18,   101,   123,   172,   124,   125,
     175,   129,    19,   178,    21,   130,   131,    93,   139,    65,
      94,    81,    82,    83,    84,    85,   167,   167,   167,   134,
      67,   141,   199,   173,   176,   127,   177,   171,    87,    44,
      45,    46,    47,    48,    49,   204,   205,   206,   179,   203,
     193,   182,    42,    43,    44,    45,    46,    47,    48,    49,
      14,    15,    16,    17,    18,   200,   183,   216,   147,   218,
     202,   148,   208,   149,   207,   150,   209,   221,   169,   151,
     152,   153,   154,   155,   143,   220,    42,    43,    44,    45,
      46,    47,    48,    49,    14,    15,    16,    17,    18,   223,
     133,   145,   147,   144,     0,   148,     0,   149,    50,   150,
     141,   180,     0,   151,   152,   153,   154,   155,    42,    43,
      44,    45,    46,    47,    48,    49,    14,    15,    16,    17,
      18,     0,   201,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    50,     0,   141,     0,     0,     0,     0,   222,
       0,     0,   184,   185,   186,   187,   188,   189,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   135,     0,     0,    50,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
       0,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    13,     0,
       0,     0,     0,     0,     0,    14,    15,    16,    17,    18,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,   170,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   136,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,     0,     0,     0,
       0,   141,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,   191,   192,     0,     0,
     -87,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,     0,   106,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     0,     0,     0,     0,     0,   137,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,   191,   192,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85
  };

  const short
  Parser::yycheck_[] =
  {
      31,    39,    86,   150,     4,     5,     6,     7,     4,     5,
       6,     7,   129,   157,    38,    57,     3,     3,     3,    50,
      25,     0,    27,     5,    61,     3,   173,    27,     5,    19,
      20,    21,    58,    59,    18,    66,    67,    63,    38,    29,
       3,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,   172,   141,    62,     3,    59,
      60,     3,    16,    59,    18,   150,    52,    52,     5,    25,
      52,    27,   157,    35,    61,   222,   100,    63,    63,   223,
     122,    63,    59,    52,    53,    54,    18,   171,   173,    59,
     207,    59,   209,     3,    59,    62,   127,    63,     4,     3,
     100,    62,    35,     4,   135,    11,    12,    13,    14,    15,
      11,    12,    13,    14,    15,     3,    60,   148,    18,     3,
     151,    60,    28,   154,   124,    18,     3,    28,   124,    58,
     130,    50,    51,    52,    53,    54,   221,   222,   223,    60,
      63,    61,   173,    59,    16,    63,    16,   147,     4,     5,
       6,     7,     8,     9,    10,   193,   194,   195,     3,   190,
       3,    16,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    61,    16,   208,    19,   210,
      16,    22,    16,    24,    23,    26,    60,    17,   146,    30,
      31,    32,    33,    34,   130,   212,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,   221,
     101,   136,    19,   135,    -1,    22,    -1,    24,    59,    26,
      61,    62,    -1,    30,    31,    32,    33,    34,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    16,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    59,    -1,    61,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    35,    36,    37,    38,    39,    40,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    18,    -1,    -1,    59,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    28,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    -1,    -1,
      60,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,    60,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    -1,    60,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    66,    67,     0,    19,    20,    21,    29,    68,    69,
      71,    73,    76,     4,    11,    12,    13,    14,    15,    28,
      77,    78,    81,    77,    77,    77,     3,    61,     3,    72,
      52,    63,    79,    80,     3,    70,     3,     3,    61,    77,
      82,    18,     3,     4,     5,     6,     7,     8,     9,    10,
      59,    78,   104,   110,   111,   112,     5,    35,    18,    59,
      59,    82,    72,    62,     3,    58,    59,    63,   105,   106,
     107,   110,    59,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    64,     4,   112,     3,
      74,    75,    77,    28,    78,    83,    84,    85,    86,    62,
      16,     3,   108,   109,   110,   110,    60,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,    80,    35,    60,    18,     3,    52,    63,    87,    60,
      18,     3,    82,   105,    60,    18,    64,    60,   112,    77,
     110,    61,    88,    85,   109,   106,    64,    19,    22,    24,
      26,    30,    31,    32,    33,    34,    88,    89,    90,    91,
      92,    93,    94,    96,    97,   101,   103,   104,   110,    87,
      28,    78,   110,    59,    92,   110,    16,    16,   110,     3,
      62,    90,    16,    16,    35,    36,    37,    38,    39,    40,
      95,    56,    57,     3,    52,    80,    88,    92,   102,   110,
      61,    16,    16,   110,    72,    72,    72,    23,    16,    60,
      25,    27,    98,    99,   100,    88,   110,    88,   110,    62,
      99,    17,    16,    89,    92
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    65,    66,    67,    67,    68,    68,    68,    68,    69,
      70,    70,    71,    72,    72,    73,    74,    74,    75,    75,
      76,    77,    77,    77,    79,    78,    78,    78,    78,    78,
      78,    78,    80,    80,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    86,    86,    86,    87,    87,    88,    89,
      89,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    92,    92,    92,    93,    94,
      94,    95,    95,    95,    95,    95,    95,    96,    96,    97,
      98,    98,    99,   100,   100,   101,   102,   102,   103,   103,
     104,   104,   104,   105,   105,   106,   106,   107,   108,   108,
     109,   109,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   111,
     112,   112,   112,   112,   112,   112,   112
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     1,     1,     1,     1,     3,
       5,     3,     3,     3,     1,     6,     1,     0,     3,     1,
       7,     2,     1,     2,     0,     3,     1,     1,     1,     1,
       1,     1,     4,     0,     4,     5,     4,     0,     1,     0,
       3,     1,     2,     2,     2,     2,     4,     0,     3,     2,
       1,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       3,     3,     4,     4,     4,     1,     1,     1,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     5,     5,
       2,     1,     3,     2,     1,     5,     5,     1,     2,     1,
       2,     2,     2,     3,     0,     4,     3,     3,     1,     0,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     1,     4,
       1,     1,     1,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "ID", "STR", "CHAR",
  "INTV", "F32V", "F64V", "TRUE", "FALSE", "VOID", "BOOL", "INT", "F32",
  "F64", "PYC", "COL", "COMA", "VAR", "CONST", "PROTO", "IF", "ELSE",
  "FOR", "CASE", "SWITCH", "DEFAULT", "STRUCT", "FUNC", "RETURN", "BREAK",
  "CONTINUE", "PRINT", "READ", "ASIG", "SASIG", "RASIG", "PASIG", "DASIG",
  "MASIG", "AMP", "OR", "AND", "EQ", "NEQ", "LESS", "GREAT", "LEQ", "GEQ",
  "PLUS", "SUB", "MUL", "DIV", "MOD", "NEG", "INCR", "DECR", "DOT", "LPAR",
  "RPAR", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "$accept", "programa",
  "declaraciones", "declaracion", "decl_const", "lista_id_const",
  "decl_var", "lista_id", "decl_proto", "lista_tipos", "tipos",
  "decl_func", "tipo", "nombre_tipo", "$@1", "tipo_arreglo",
  "tipo_estructura", "decl_campo", "lista_param", "decl_params",
  "decl_param", "tipo_param", "tipo_param_arr", "bloque",
  "lista_sentencias", "sentencia", "decl_loc", "sentencia_simple", "asig",
  "incdec", "op_asig", "sentencia_if", "sentencia_switch", "expr_casos",
  "expr_caso", "caso", "sentencia_for", "clausula_for", "sentencia_return",
  "izq", "dato_miembro", "parte_arreglo", "llamada_funcion", "args",
  "lista_args", "expresion", "conversion", "literal", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,    88,    88,    91,    92,    95,    96,    97,    98,   101,
     104,   105,   108,   111,   123,   129,   132,   133,   136,   137,
     140,   143,   144,   145,   148,   148,   150,   151,   152,   153,
     154,   155,   158,   169,   172,   173,   176,   177,   180,   181,
     184,   185,   188,   191,   192,   193,   196,   197,   200,   203,
     204,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   220,   221,   222,   225,   226,   227,   230,   233,
     234,   237,   238,   239,   240,   241,   242,   245,   246,   249,
     252,   253,   256,   259,   260,   263,   266,   267,   270,   271,
     274,   275,   276,   279,   280,   283,   284,   287,   290,   291,
     294,   295,   298,   310,   318,   328,   338,   346,   354,   362,
     370,   378,   386,   394,   402,   410,   412,   413,   416,   419,
     422,   430,   438,   446,   454,   462,   470
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2108 "Parser.cpp"

#line 479 "src/parser/parser.yy"


void yy::Parser::error(const std::string &err_message)
{
    cerr << "Error: " << err_message << " at " << lexer.lineno() << " with token " << lexer.YYText() << endl;
}
