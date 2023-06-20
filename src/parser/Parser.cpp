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
#line 38 "parser.yy"

    #include <iostream>
    #include <fstream>
    using namespace std;

    #include "Lexer.hpp"
    #include "Driver.hpp"
    #include "Quad.hpp"
    #include <iterator>
    
    #define yylex lexer.yylex

#line 59 "Parser.cpp"


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
#line 132 "Parser.cpp"

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

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_izq: // izq
      case symbol_kind::S_expresion: // expresion
        value.copy< expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
      case symbol_kind::S_nombre_tipo: // nombre_tipo
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_literal: // literal
        value.copy< literal > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_INTV: // INTV
      case symbol_kind::S_F32V: // F32V
      case symbol_kind::S_F64V: // F64V
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lista_id_const: // lista_id_const
      case symbol_kind::S_lista_id: // lista_id
        value.copy< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_izq: // izq
      case symbol_kind::S_expresion: // expresion
        value.move< expresion > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tipo: // tipo
      case symbol_kind::S_nombre_tipo: // nombre_tipo
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_literal: // literal
        value.move< literal > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_INTV: // INTV
      case symbol_kind::S_F32V: // F32V
      case symbol_kind::S_F64V: // F64V
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_lista_id_const: // lista_id_const
      case symbol_kind::S_lista_id: // lista_id
        value.move< std::vector<std::string> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



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
      case symbol_kind::S_izq: // izq
      case symbol_kind::S_expresion: // expresion
        value.YY_MOVE_OR_COPY< expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
      case symbol_kind::S_nombre_tipo: // nombre_tipo
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_literal: // literal
        value.YY_MOVE_OR_COPY< literal > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_INTV: // INTV
      case symbol_kind::S_F32V: // F32V
      case symbol_kind::S_F64V: // F64V
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lista_id_const: // lista_id_const
      case symbol_kind::S_lista_id: // lista_id
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
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
      case symbol_kind::S_izq: // izq
      case symbol_kind::S_expresion: // expresion
        value.move< expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
      case symbol_kind::S_nombre_tipo: // nombre_tipo
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_literal: // literal
        value.move< literal > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_INTV: // INTV
      case symbol_kind::S_F32V: // F32V
      case symbol_kind::S_F64V: // F64V
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lista_id_const: // lista_id_const
      case symbol_kind::S_lista_id: // lista_id
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
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
      case symbol_kind::S_izq: // izq
      case symbol_kind::S_expresion: // expresion
        value.copy< expresion > (that.value);
        break;

      case symbol_kind::S_tipo: // tipo
      case symbol_kind::S_nombre_tipo: // nombre_tipo
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_literal: // literal
        value.copy< literal > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_INTV: // INTV
      case symbol_kind::S_F32V: // F32V
      case symbol_kind::S_F64V: // F64V
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_lista_id_const: // lista_id_const
      case symbol_kind::S_lista_id: // lista_id
        value.copy< std::vector<std::string> > (that.value);
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
      case symbol_kind::S_izq: // izq
      case symbol_kind::S_expresion: // expresion
        value.move< expresion > (that.value);
        break;

      case symbol_kind::S_tipo: // tipo
      case symbol_kind::S_nombre_tipo: // nombre_tipo
        value.move< int > (that.value);
        break;

      case symbol_kind::S_literal: // literal
        value.move< literal > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_INTV: // INTV
      case symbol_kind::S_F32V: // F32V
      case symbol_kind::S_F64V: // F64V
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_lista_id_const: // lista_id_const
      case symbol_kind::S_lista_id: // lista_id
        value.move< std::vector<std::string> > (that.value);
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
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
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
      case symbol_kind::S_izq: // izq
      case symbol_kind::S_expresion: // expresion
        yylhs.value.emplace< expresion > ();
        break;

      case symbol_kind::S_tipo: // tipo
      case symbol_kind::S_nombre_tipo: // nombre_tipo
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_literal: // literal
        yylhs.value.emplace< literal > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_CHAR: // CHAR
      case symbol_kind::S_INTV: // INTV
      case symbol_kind::S_F32V: // F32V
      case symbol_kind::S_F64V: // F64V
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_lista_id_const: // lista_id_const
      case symbol_kind::S_lista_id: // lista_id
        yylhs.value.emplace< std::vector<std::string> > ();
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
  case 9: // decl_const: CONST tipo lista_id_const
#line 104 "parser.yy"
                              { for(string id : yystack_[0].value.as < std::vector<std::string> > ()) driver.addSym(id, yystack_[1].value.as < int > (), "const"); }
#line 804 "Parser.cpp"
    break;

  case 10: // lista_id_const: lista_id_const COMA ID ASIG literal
#line 108 "parser.yy"
    {
        std::vector<std::string> id_l = yystack_[4].value.as < std::vector<std::string> > ();
        std::vector<std::string> single = driver.idVec(yystack_[2].value.as < std::string > ());
        id_l.insert(
            id_l.end(),
            std::make_move_iterator(single.begin()),
            std::make_move_iterator(single.end())
        );

        yylhs.value.as < std::vector<std::string> > () = id_l;
    }
#line 820 "Parser.cpp"
    break;

  case 11: // lista_id_const: ID ASIG literal
#line 119 "parser.yy"
                      { yylhs.value.as < std::vector<std::string> > () = driver.idVec(yystack_[2].value.as < std::string > ()); }
#line 826 "Parser.cpp"
    break;

  case 12: // decl_var: VAR tipo lista_id
#line 122 "parser.yy"
                      { for(string id : yystack_[0].value.as < std::vector<std::string> > ()) driver.addSym(id, yystack_[1].value.as < int > (), "var"); }
#line 832 "Parser.cpp"
    break;

  case 13: // lista_id: lista_id COMA ID
#line 126 "parser.yy"
    {
        std::vector<std::string> id_l = yystack_[2].value.as < std::vector<std::string> > ();
        std::vector<std::string> single = driver.idVec(yystack_[0].value.as < std::string > ());
        id_l.insert(
            id_l.end(),
            std::make_move_iterator(single.begin()),
            std::make_move_iterator(single.end())
        );

        yylhs.value.as < std::vector<std::string> > () = id_l;
    }
#line 848 "Parser.cpp"
    break;

  case 14: // lista_id: ID
#line 138 "parser.yy"
    {
        yylhs.value.as < std::vector<std::string> > () = driver.idVec(yystack_[0].value.as < std::string > ());
    }
#line 856 "Parser.cpp"
    break;

  case 15: // decl_proto: PROTO tipo ID LPAR lista_tipos RPAR
#line 143 "parser.yy"
                                        {}
#line 862 "Parser.cpp"
    break;

  case 16: // lista_tipos: tipos
#line 146 "parser.yy"
          {}
#line 868 "Parser.cpp"
    break;

  case 17: // lista_tipos: %empty
#line 147 "parser.yy"
                {}
#line 874 "Parser.cpp"
    break;

  case 18: // tipos: tipos COMA tipo
#line 150 "parser.yy"
                    {}
#line 880 "Parser.cpp"
    break;

  case 19: // tipos: tipo
#line 151 "parser.yy"
           {}
#line 886 "Parser.cpp"
    break;

  case 20: // $@1: %empty
#line 154 "parser.yy"
                                       {
        
    }
#line 894 "Parser.cpp"
    break;

  case 22: // tipo: nombre_tipo tipo_arreglo
#line 159 "parser.yy"
                             {}
#line 900 "Parser.cpp"
    break;

  case 23: // tipo: tipo_estructura
#line 160 "parser.yy"
                      {}
#line 906 "Parser.cpp"
    break;

  case 24: // tipo: nombre_tipo MUL
#line 161 "parser.yy"
                      {}
#line 912 "Parser.cpp"
    break;

  case 25: // nombre_tipo: CHAR
#line 164 "parser.yy"
         {}
#line 918 "Parser.cpp"
    break;

  case 26: // nombre_tipo: INT
#line 165 "parser.yy"
          { yylhs.value.as < int > () = 1; }
#line 924 "Parser.cpp"
    break;

  case 27: // nombre_tipo: F32
#line 166 "parser.yy"
          {}
#line 930 "Parser.cpp"
    break;

  case 28: // nombre_tipo: F64
#line 167 "parser.yy"
          {}
#line 936 "Parser.cpp"
    break;

  case 29: // nombre_tipo: STR
#line 168 "parser.yy"
          {}
#line 942 "Parser.cpp"
    break;

  case 30: // nombre_tipo: BOOL
#line 169 "parser.yy"
           {}
#line 948 "Parser.cpp"
    break;

  case 31: // nombre_tipo: VOID
#line 170 "parser.yy"
           {}
#line 954 "Parser.cpp"
    break;

  case 32: // tipo_arreglo: LBRACK expresion RBRACK tipo_arreglo
#line 173 "parser.yy"
                                         {}
#line 960 "Parser.cpp"
    break;

  case 33: // tipo_arreglo: %empty
#line 174 "parser.yy"
                {}
#line 966 "Parser.cpp"
    break;

  case 34: // tipo_estructura: STRUCT LBRACE decl_campo RBRACE
#line 177 "parser.yy"
                                    {}
#line 972 "Parser.cpp"
    break;

  case 35: // tipo_estructura: STRUCT ID LBRACE decl_campo RBRACE
#line 178 "parser.yy"
                                         {}
#line 978 "Parser.cpp"
    break;

  case 36: // decl_campo: tipo lista_id PYC decl_campo
#line 181 "parser.yy"
                                 {}
#line 984 "Parser.cpp"
    break;

  case 37: // decl_campo: %empty
#line 182 "parser.yy"
                {}
#line 990 "Parser.cpp"
    break;

  case 38: // lista_param: decl_params
#line 185 "parser.yy"
                {}
#line 996 "Parser.cpp"
    break;

  case 39: // lista_param: %empty
#line 186 "parser.yy"
                {}
#line 1002 "Parser.cpp"
    break;

  case 40: // decl_params: decl_params COMA decl_param
#line 189 "parser.yy"
                                {}
#line 1008 "Parser.cpp"
    break;

  case 41: // decl_params: decl_param
#line 190 "parser.yy"
                 {}
#line 1014 "Parser.cpp"
    break;

  case 42: // decl_param: tipo_param ID
#line 193 "parser.yy"
                  {}
#line 1020 "Parser.cpp"
    break;

  case 43: // tipo_param: nombre_tipo tipo_param_arr
#line 196 "parser.yy"
                               {}
#line 1026 "Parser.cpp"
    break;

  case 44: // tipo_param: STRUCT ID
#line 197 "parser.yy"
                {}
#line 1032 "Parser.cpp"
    break;

  case 45: // tipo_param: nombre_tipo MUL
#line 198 "parser.yy"
                      {}
#line 1038 "Parser.cpp"
    break;

  case 46: // tipo_param_arr: LBRACK expresion RBRACK tipo_param_arr
#line 201 "parser.yy"
                                           {}
#line 1044 "Parser.cpp"
    break;

  case 47: // tipo_param_arr: %empty
#line 202 "parser.yy"
                {}
#line 1050 "Parser.cpp"
    break;

  case 48: // bloque: LBRACE lista_sentencias RBRACE
#line 205 "parser.yy"
                                   {}
#line 1056 "Parser.cpp"
    break;

  case 49: // lista_sentencias: lista_sentencias sentencia
#line 208 "parser.yy"
                               {}
#line 1062 "Parser.cpp"
    break;

  case 51: // sentencia: decl_loc
#line 212 "parser.yy"
             {}
#line 1068 "Parser.cpp"
    break;

  case 52: // sentencia: sentencia_simple PYC
#line 213 "parser.yy"
                           {}
#line 1074 "Parser.cpp"
    break;

  case 53: // sentencia: sentencia_return PYC
#line 214 "parser.yy"
                           {}
#line 1080 "Parser.cpp"
    break;

  case 54: // sentencia: BREAK PYC
#line 215 "parser.yy"
                {}
#line 1086 "Parser.cpp"
    break;

  case 55: // sentencia: CONTINUE PYC
#line 216 "parser.yy"
                   {}
#line 1092 "Parser.cpp"
    break;

  case 56: // sentencia: bloque
#line 217 "parser.yy"
             {}
#line 1098 "Parser.cpp"
    break;

  case 57: // sentencia: sentencia_if
#line 218 "parser.yy"
                   {}
#line 1104 "Parser.cpp"
    break;

  case 58: // sentencia: sentencia_switch
#line 219 "parser.yy"
                       {}
#line 1110 "Parser.cpp"
    break;

  case 59: // sentencia: sentencia_for
#line 220 "parser.yy"
                    {}
#line 1116 "Parser.cpp"
    break;

  case 60: // sentencia: PRINT expresion PYC
#line 221 "parser.yy"
                          {}
#line 1122 "Parser.cpp"
    break;

  case 61: // sentencia: READ ID PYC
#line 222 "parser.yy"
                  {}
#line 1128 "Parser.cpp"
    break;

  case 62: // decl_loc: VAR nombre_tipo MUL lista_id
#line 225 "parser.yy"
                                 {}
#line 1134 "Parser.cpp"
    break;

  case 63: // decl_loc: VAR STRUCT ID lista_id
#line 226 "parser.yy"
                             {}
#line 1140 "Parser.cpp"
    break;

  case 64: // decl_loc: VAR nombre_tipo tipo_arreglo lista_id
#line 227 "parser.yy"
                                            {}
#line 1146 "Parser.cpp"
    break;

  case 68: // asig: izq ASIG expresion
#line 235 "parser.yy"
                       {
        if (yystack_[2].value.as < expresion > ().type != yystack_[0].value.as < expresion > ().type) {
            string a = yystack_[2].value.as < expresion > ().temp;
            string b = yystack_[0].value.as < expresion > ().temp;

            driver.pushQuad(COPY, a, "", b);
        } else {
            /*error*/
        }
    }
#line 1161 "Parser.cpp"
    break;

  case 69: // asig: izq SASIG expresion
#line 245 "parser.yy"
                          {driver.asigOp(OP_ADD, yystack_[2].value.as < expresion > (), yystack_[0].value.as < expresion > ());}
#line 1167 "Parser.cpp"
    break;

  case 70: // asig: izq RASIG expresion
#line 246 "parser.yy"
                          {driver.asigOp(OP_SUB, yystack_[2].value.as < expresion > (), yystack_[0].value.as < expresion > ());}
#line 1173 "Parser.cpp"
    break;

  case 71: // asig: izq PASIG expresion
#line 247 "parser.yy"
                          {driver.asigOp(OP_MUL, yystack_[2].value.as < expresion > (), yystack_[0].value.as < expresion > ());}
#line 1179 "Parser.cpp"
    break;

  case 72: // asig: izq DASIG expresion
#line 248 "parser.yy"
                          {driver.asigOp(OP_DIV, yystack_[2].value.as < expresion > (), yystack_[0].value.as < expresion > ());}
#line 1185 "Parser.cpp"
    break;

  case 73: // asig: izq MASIG expresion
#line 249 "parser.yy"
                          {driver.asigOp(OP_MOD, yystack_[2].value.as < expresion > (), yystack_[0].value.as < expresion > ());}
#line 1191 "Parser.cpp"
    break;

  case 74: // incdec: expresion INCR
#line 252 "parser.yy"
                   { driver.incdec(yystack_[1].value.as < expresion > (), OP_ADD); }
#line 1197 "Parser.cpp"
    break;

  case 75: // incdec: expresion DECR
#line 253 "parser.yy"
                     { driver.incdec(yystack_[1].value.as < expresion > (), OP_SUB); }
#line 1203 "Parser.cpp"
    break;

  case 76: // sentencia_if: IF expresion bloque
#line 256 "parser.yy"
                        {}
#line 1209 "Parser.cpp"
    break;

  case 77: // sentencia_if: IF expresion bloque ELSE bloque
#line 257 "parser.yy"
                                      {}
#line 1215 "Parser.cpp"
    break;

  case 78: // sentencia_switch: SWITCH sentencia_simple LBRACE expr_casos RBRACE
#line 260 "parser.yy"
                                                     {}
#line 1221 "Parser.cpp"
    break;

  case 79: // expr_casos: expr_casos expr_caso
#line 263 "parser.yy"
                         {}
#line 1227 "Parser.cpp"
    break;

  case 80: // expr_casos: expr_caso
#line 264 "parser.yy"
                {}
#line 1233 "Parser.cpp"
    break;

  case 81: // expr_caso: caso COL lista_sentencias
#line 267 "parser.yy"
                              {}
#line 1239 "Parser.cpp"
    break;

  case 82: // caso: CASE expresion
#line 270 "parser.yy"
                   {}
#line 1245 "Parser.cpp"
    break;

  case 83: // caso: DEFAULT
#line 271 "parser.yy"
              {}
#line 1251 "Parser.cpp"
    break;

  case 84: // sentencia_for: FOR LPAR clausula_for RPAR bloque
#line 274 "parser.yy"
                                      {}
#line 1257 "Parser.cpp"
    break;

  case 85: // clausula_for: sentencia_simple PYC expresion PYC sentencia_simple
#line 277 "parser.yy"
                                                        {}
#line 1263 "Parser.cpp"
    break;

  case 86: // clausula_for: expresion
#line 278 "parser.yy"
                {}
#line 1269 "Parser.cpp"
    break;

  case 87: // sentencia_return: RETURN expresion
#line 281 "parser.yy"
                     {}
#line 1275 "Parser.cpp"
    break;

  case 88: // sentencia_return: RETURN
#line 282 "parser.yy"
             {}
#line 1281 "Parser.cpp"
    break;

  case 89: // izq: ID dato_miembro
#line 285 "parser.yy"
                    {}
#line 1287 "Parser.cpp"
    break;

  case 90: // izq: ID parte_arreglo
#line 286 "parser.yy"
                       {}
#line 1293 "Parser.cpp"
    break;

  case 91: // izq: ID llamada_funcion
#line 287 "parser.yy"
                         {}
#line 1299 "Parser.cpp"
    break;

  case 92: // dato_miembro: DOT ID dato_miembro
#line 290 "parser.yy"
                        {}
#line 1305 "Parser.cpp"
    break;

  case 93: // dato_miembro: %empty
#line 291 "parser.yy"
                {}
#line 1311 "Parser.cpp"
    break;

  case 94: // parte_arreglo: LBRACK expresion RBRACK parte_arreglo
#line 294 "parser.yy"
                                          {}
#line 1317 "Parser.cpp"
    break;

  case 95: // parte_arreglo: LBRACK expresion RBRACK
#line 295 "parser.yy"
                              {}
#line 1323 "Parser.cpp"
    break;

  case 96: // llamada_funcion: LPAR args RPAR
#line 298 "parser.yy"
                   {}
#line 1329 "Parser.cpp"
    break;

  case 97: // args: lista_args
#line 301 "parser.yy"
               {}
#line 1335 "Parser.cpp"
    break;

  case 98: // args: %empty
#line 302 "parser.yy"
                {}
#line 1341 "Parser.cpp"
    break;

  case 99: // lista_args: expresion COMA lista_args
#line 305 "parser.yy"
                              {}
#line 1347 "Parser.cpp"
    break;

  case 100: // lista_args: expresion
#line 306 "parser.yy"
                {}
#line 1353 "Parser.cpp"
    break;

  case 101: // expresion: expresion OR expresion
#line 309 "parser.yy"
                           { driver.expr(yystack_[2].value.as < expresion > (), OP_OR, yystack_[0].value.as < expresion > ()); }
#line 1359 "Parser.cpp"
    break;

  case 102: // expresion: expresion AND expresion
#line 310 "parser.yy"
                              { driver.expr(yystack_[2].value.as < expresion > (), OP_AND, yystack_[0].value.as < expresion > ()); }
#line 1365 "Parser.cpp"
    break;

  case 103: // expresion: expresion EQ expresion
#line 311 "parser.yy"
                             { driver.expr(yystack_[2].value.as < expresion > (), OP_EQ, yystack_[0].value.as < expresion > ()); }
#line 1371 "Parser.cpp"
    break;

  case 104: // expresion: expresion NEQ expresion
#line 312 "parser.yy"
                              { driver.expr(yystack_[2].value.as < expresion > (), OP_NEQ, yystack_[0].value.as < expresion > ()); }
#line 1377 "Parser.cpp"
    break;

  case 105: // expresion: expresion LESS expresion
#line 313 "parser.yy"
                               { driver.expr(yystack_[2].value.as < expresion > (), OP_LESS, yystack_[0].value.as < expresion > ()); }
#line 1383 "Parser.cpp"
    break;

  case 106: // expresion: expresion LEQ expresion
#line 314 "parser.yy"
                              { driver.expr(yystack_[2].value.as < expresion > (), OP_LEQ, yystack_[0].value.as < expresion > ()); }
#line 1389 "Parser.cpp"
    break;

  case 107: // expresion: expresion GREAT expresion
#line 315 "parser.yy"
                                { driver.expr(yystack_[2].value.as < expresion > (), OP_GREAT, yystack_[0].value.as < expresion > ()); }
#line 1395 "Parser.cpp"
    break;

  case 108: // expresion: expresion GEQ expresion
#line 316 "parser.yy"
                              { driver.expr(yystack_[2].value.as < expresion > (), OP_GEQ, yystack_[0].value.as < expresion > ()); }
#line 1401 "Parser.cpp"
    break;

  case 109: // expresion: expresion PLUS expresion
#line 317 "parser.yy"
                               { driver.expr(yystack_[2].value.as < expresion > (), OP_ADD, yystack_[0].value.as < expresion > ()); }
#line 1407 "Parser.cpp"
    break;

  case 110: // expresion: expresion SUB expresion
#line 318 "parser.yy"
                              { driver.expr(yystack_[2].value.as < expresion > (), OP_SUB, yystack_[0].value.as < expresion > ()); }
#line 1413 "Parser.cpp"
    break;

  case 111: // expresion: expresion MUL expresion
#line 319 "parser.yy"
                              { driver.expr(yystack_[2].value.as < expresion > (), OP_MUL, yystack_[0].value.as < expresion > ()); }
#line 1419 "Parser.cpp"
    break;

  case 112: // expresion: expresion DIV expresion
#line 320 "parser.yy"
                              { driver.expr(yystack_[2].value.as < expresion > (), OP_DIV, yystack_[0].value.as < expresion > ()); }
#line 1425 "Parser.cpp"
    break;

  case 113: // expresion: expresion MOD expresion
#line 321 "parser.yy"
                              { driver.expr(yystack_[2].value.as < expresion > (), OP_MOD, yystack_[0].value.as < expresion > ()); }
#line 1431 "Parser.cpp"
    break;

  case 114: // expresion: izq
#line 322 "parser.yy"
          { yylhs.value.as < expresion > () = yystack_[0].value.as < expresion > (); }
#line 1437 "Parser.cpp"
    break;

  case 115: // expresion: literal
#line 324 "parser.yy"
    {  
        expresion e;
        std::string empty = "";
        e.type = yystack_[0].value.as < literal > ().type;
        e.temp = driver.newTmp();
        driver.pushQuad(COPY, yystack_[0].value.as < literal > ().data, empty, e.temp);

        yylhs.value.as < expresion > () = e;
    }
#line 1451 "Parser.cpp"
    break;

  case 116: // expresion: LPAR expresion RPAR
#line 333 "parser.yy"
                          { yylhs.value.as < expresion > () = yystack_[1].value.as < expresion > (); }
#line 1457 "Parser.cpp"
    break;

  case 117: // expresion: conversion
#line 334 "parser.yy"
                 {}
#line 1463 "Parser.cpp"
    break;

  case 118: // conversion: nombre_tipo LPAR expresion RPAR
#line 337 "parser.yy"
                                    {}
#line 1469 "Parser.cpp"
    break;

  case 119: // literal: TRUE
#line 341 "parser.yy"
    { 
        literal l; 
        l.type = 0;
        l.data = "true";

        yylhs.value.as < literal > () = l;
    }
#line 1481 "Parser.cpp"
    break;

  case 120: // literal: FALSE
#line 349 "parser.yy"
    { 
        literal l; 
        l.type = 0;
        l.data = "false";

        yylhs.value.as < literal > () = l;
    }
#line 1493 "Parser.cpp"
    break;

  case 121: // literal: INTV
#line 357 "parser.yy"
    { 
        literal l; 
        l.type = 1;
        l.data = lexer.YYText();

        yylhs.value.as < literal > () = l;
    }
#line 1505 "Parser.cpp"
    break;

  case 122: // literal: F32V
#line 365 "parser.yy"
    { 
        literal l; 
        l.type = 2;
        l.data = lexer.YYText();

        yylhs.value.as < literal > () = l;
    }
#line 1517 "Parser.cpp"
    break;

  case 123: // literal: F64V
#line 373 "parser.yy"
    { 
        literal l; 
        l.type = 3;
        l.data = lexer.YYText();

        yylhs.value.as < literal > () = l;
    }
#line 1529 "Parser.cpp"
    break;

  case 124: // literal: CHAR
#line 381 "parser.yy"
    { 
        literal l; 
        l.type = 4;
        l.data = lexer.YYText();

        yylhs.value.as < literal > () = l;
    }
#line 1541 "Parser.cpp"
    break;

  case 125: // literal: STR
#line 389 "parser.yy"
    { 
        literal l; 
        l.type = 5;
        l.data = lexer.YYText();

        yylhs.value.as < literal > () = l;
    }
#line 1553 "Parser.cpp"
    break;


#line 1557 "Parser.cpp"

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









  const short Parser::yypact_ninf_ = -154;

  const signed char Parser::yytable_ninf_ = -87;

  const short
  Parser::yypact_[] =
  {
    -154,    15,    41,  -154,    54,    54,    54,    54,  -154,    13,
      21,    22,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,
      11,    28,   -36,  -154,    61,    68,    72,  -154,  -154,  -154,
      17,    54,  -154,    65,  -154,   247,  -154,    52,    71,    34,
      35,    54,    28,    55,    93,    64,    38,    57,  -154,  -154,
    -154,  -154,  -154,   247,    66,  -154,   303,  -154,  -154,   261,
     116,    54,    87,    58,     5,  -154,  -154,   123,   247,   247,
    -154,  -154,  -154,   411,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,    74,  -154,
    -154,  -154,   100,    78,   110,  -154,   136,   -33,    81,   122,
    -154,   172,  -154,    54,   119,   118,  -154,   265,   326,  -154,
     430,   289,   476,    97,    97,    80,    80,    80,    80,    60,
      60,  -154,  -154,  -154,  -154,   261,  -154,    54,  -154,  -154,
     247,  -154,  -154,    87,  -154,  -154,  -154,  -154,   247,   117,
    -154,  -154,  -154,   349,   137,  -154,  -154,  -154,   134,   215,
    -154,  -154,   316,   247,   140,   247,   247,   163,   186,   247,
     201,  -154,   181,  -154,  -154,   190,  -154,  -154,  -154,  -154,
    -154,   192,    69,   449,   206,   -27,   372,   247,   149,   465,
    -154,  -154,   120,   200,  -154,  -154,  -154,  -154,   247,   247,
     247,   247,   247,   247,  -154,  -154,    28,    28,    28,   194,
     216,   171,   392,     1,  -154,  -154,   465,   465,   465,   465,
     465,   465,    65,    65,    65,   137,   247,   137,   247,  -154,
      -5,  -154,   218,  -154,   248,  -154,   465,  -154,  -154,   215,
     247,   215,  -154
  };

  const signed char
  Parser::yydefact_[] =
  {
       4,     0,     2,     1,     0,     0,     0,     0,     3,     0,
       0,     0,     8,    29,    25,    31,    30,    26,    27,    28,
       0,     0,    33,    23,     0,     0,     0,     5,     6,     7,
       0,    37,    14,    12,    24,     0,    22,     0,     9,     0,
       0,    37,     0,     0,     0,    93,   125,   124,   121,   122,
     123,   119,   120,     0,     0,   114,     0,   117,   115,     0,
       0,    17,    39,     0,     0,    34,    13,     0,    98,     0,
      89,    90,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,   125,
     124,    11,     0,     0,    16,    19,     0,    47,     0,    38,
      41,     0,    35,    37,    93,     0,    97,   100,     0,   116,
       0,   101,   102,   103,   104,   105,   107,   106,   108,   109,
     110,   111,   112,   113,    32,     0,    15,     0,    44,    45,
       0,    43,    20,     0,    42,    36,    92,    96,     0,    95,
     118,    10,    18,     0,     0,    40,    99,    94,    47,     0,
      21,    46,     0,     0,     0,     0,    88,     0,     0,     0,
       0,    56,     0,    50,    51,     0,    67,    66,    57,    58,
      59,     0,   114,    65,     0,    33,     0,     0,     0,    87,
      54,    55,     0,     0,    48,    49,    52,    53,     0,     0,
       0,     0,     0,     0,    74,    75,     0,     0,     0,    76,
       0,     0,    65,     0,    60,    61,    68,    69,    70,    71,
      72,    73,    63,    62,    64,     0,     0,     0,     0,    83,
       0,    80,     0,    77,     0,    84,    82,    78,    79,     0,
       0,    81,    85
  };

  const short
  Parser::yypgoto_[] =
  {
    -154,  -154,  -154,  -154,  -154,  -154,  -154,   -37,  -154,  -154,
    -154,  -154,  -154,     2,    49,   -87,  -154,   -30,  -154,  -154,
     103,  -154,    85,  -141,     9,  -150,  -154,  -153,  -154,  -154,
    -154,  -154,  -154,    24,  -154,  -154,  -154,  -154,  -145,   159,
     133,  -154,  -154,   135,   -35,  -154,   -46
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,     8,     9,    38,    10,    33,    11,    93,
      94,    12,   144,    42,    54,    36,    23,    43,    98,    99,
     100,   101,   131,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   220,   221,   222,   170,   201,   171,    55,    70,
      71,    72,   105,   106,   173,    57,    58
  };

  const short
  Parser::yytable_[] =
  {
      56,   124,   178,   150,   172,    64,    21,    24,    25,    26,
     172,    63,   185,    91,    30,     3,    34,   172,    73,   129,
     218,   103,   219,    44,   200,   197,   218,    35,   219,    27,
     130,    32,   172,   107,   108,   199,    35,    28,    29,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    22,    22,    22,    22,   227,    13,    14,
       4,     5,     6,    95,    37,    15,    16,    17,    18,    19,
       7,    39,    31,   135,   223,    40,   225,   232,    41,   141,
      22,   185,    20,    44,   172,   172,   172,    59,   198,    60,
      22,    13,    14,    61,    62,   143,    66,   -29,    15,    16,
      17,    18,    19,   107,   188,   189,   190,   191,   192,   193,
      22,    97,    85,    86,    87,    96,   -25,    65,   176,    92,
     102,   179,    67,    68,   182,    74,   104,    69,   127,   142,
      83,    84,    85,    86,    87,   125,   204,    35,   126,   128,
     133,   132,   202,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    22,   206,   207,   208,   209,   210,   211,   212,
     213,   214,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,   134,    22,    67,   137,   180,
      69,   224,    97,   226,    45,    46,    47,    48,    49,    50,
      51,    52,    15,    16,    17,    18,    19,   130,   149,   177,
     152,   175,   181,   153,   183,   154,   186,   155,   187,   196,
     203,   156,   157,   158,   159,   160,   205,   215,    45,    46,
      47,    48,    49,    50,    51,    52,    15,    16,    17,    18,
      19,   217,   216,   151,   152,   229,   145,   153,   231,   154,
      53,   155,   149,   184,   228,   156,   157,   158,   159,   160,
      45,    46,    47,    48,    49,    50,    51,    52,    15,    16,
      17,    18,    19,   136,   230,    89,    90,    48,    49,    50,
      51,    52,   147,   146,    53,     0,   149,     0,     0,     0,
       0,     0,     0,   138,     0,     0,     0,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,    53,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      13,    14,     0,     0,     0,     0,     0,    15,    16,    17,
      18,    19,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,   174,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     139,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,     0,
       0,     0,     0,   149,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,   194,   195,
       0,     0,   -86,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
       0,   109,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
     140,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,   194,   195,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87
  };

  const short
  Parser::yycheck_[] =
  {
      35,    88,   155,   144,   149,    42,     4,     5,     6,     7,
     155,    41,   162,    59,     3,     0,    52,   162,    53,    52,
      25,    16,    27,    18,   177,    52,    25,    63,    27,    16,
      63,     3,   177,    68,    69,   176,    63,    16,    16,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     4,     5,     6,     7,    62,     4,     5,
      19,    20,    21,    61,     3,    11,    12,    13,    14,    15,
      29,     3,    61,   103,   215,     3,   217,   230,    61,   125,
      31,   231,    28,    18,   229,   230,   231,    35,   175,    18,
      41,     4,     5,    59,    59,   130,     3,    59,    11,    12,
      13,    14,    15,   138,    35,    36,    37,    38,    39,    40,
      61,    62,    52,    53,    54,    28,    59,    62,   153,     3,
      62,   156,    58,    59,   159,    59,     3,    63,    18,   127,
      50,    51,    52,    53,    54,    35,    16,    63,    60,     3,
      18,    60,   177,    46,    47,    48,    49,    50,    51,    52,
      53,    54,   103,   188,   189,   190,   191,   192,   193,   196,
     197,   198,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     3,   127,    58,    60,    16,
      63,   216,   133,   218,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    63,    61,    59,
      19,   152,    16,    22,     3,    24,    16,    26,    16,     3,
      61,    30,    31,    32,    33,    34,    16,    23,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    60,    16,   148,    19,    17,   133,    22,   229,    24,
      59,    26,    61,    62,   220,    30,    31,    32,    33,    34,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,   104,    16,     4,     5,     6,     7,     8,
       9,    10,   139,   138,    59,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    59,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
       4,     5,    -1,    -1,    -1,    -1,    -1,    11,    12,    13,
      14,    15,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    28,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      -1,    -1,    60,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      -1,    60,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,
      60,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    66,    67,     0,    19,    20,    21,    29,    68,    69,
      71,    73,    76,     4,     5,    11,    12,    13,    14,    15,
      28,    78,    79,    81,    78,    78,    78,    16,    16,    16,
       3,    61,     3,    72,    52,    63,    80,     3,    70,     3,
       3,    61,    78,    82,    18,     3,     4,     5,     6,     7,
       8,     9,    10,    59,    79,   103,   109,   110,   111,    35,
      18,    59,    59,    82,    72,    62,     3,    58,    59,    63,
     104,   105,   106,   109,    59,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    64,     4,
       5,   111,     3,    74,    75,    78,    28,    79,    83,    84,
      85,    86,    62,    16,     3,   107,   108,   109,   109,    60,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,    80,    35,    60,    18,     3,    52,
      63,    87,    60,    18,     3,    82,   104,    60,    18,    64,
      60,   111,    78,   109,    77,    85,   108,   105,    64,    61,
      88,    87,    19,    22,    24,    26,    30,    31,    32,    33,
      34,    88,    89,    90,    91,    92,    93,    94,    95,    96,
     100,   102,   103,   109,    28,    79,   109,    59,    92,   109,
      16,    16,   109,     3,    62,    90,    16,    16,    35,    36,
      37,    38,    39,    40,    56,    57,     3,    52,    80,    88,
      92,   101,   109,    61,    16,    16,   109,   109,   109,   109,
     109,   109,    72,    72,    72,    23,    16,    60,    25,    27,
      97,    98,    99,    88,   109,    88,   109,    62,    98,    17,
      16,    89,    92
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    65,    66,    67,    67,    68,    68,    68,    68,    69,
      70,    70,    71,    72,    72,    73,    74,    74,    75,    75,
      77,    76,    78,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    80,    80,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    86,    86,    86,    87,    87,    88,    89,
      89,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    92,    92,    92,    93,    93,
      93,    93,    93,    93,    94,    94,    95,    95,    96,    97,
      97,    98,    99,    99,   100,   101,   101,   102,   102,   103,
     103,   103,   104,   104,   105,   105,   106,   107,   107,   108,
     108,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   110,   111,
     111,   111,   111,   111,   111,   111
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     2,     2,     2,     1,     3,
       5,     3,     3,     3,     1,     6,     1,     0,     3,     1,
       0,     8,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     4,     0,     4,     5,     4,     0,     1,     0,
       3,     1,     2,     2,     2,     2,     4,     0,     3,     2,
       1,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       3,     3,     4,     4,     4,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     5,     5,     2,
       1,     3,     2,     1,     5,     5,     1,     2,     1,     2,
       2,     2,     3,     0,     4,     3,     3,     1,     0,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     3,     1,     4,     1,
       1,     1,     1,     1,     1,     1
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
  "decl_func", "$@1", "tipo", "nombre_tipo", "tipo_arreglo",
  "tipo_estructura", "decl_campo", "lista_param", "decl_params",
  "decl_param", "tipo_param", "tipo_param_arr", "bloque",
  "lista_sentencias", "sentencia", "decl_loc", "sentencia_simple", "asig",
  "incdec", "sentencia_if", "sentencia_switch", "expr_casos", "expr_caso",
  "caso", "sentencia_for", "clausula_for", "sentencia_return", "izq",
  "dato_miembro", "parte_arreglo", "llamada_funcion", "args", "lista_args",
  "expresion", "conversion", "literal", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,    91,    91,    94,    95,    98,    99,   100,   101,   104,
     107,   119,   122,   125,   137,   143,   146,   147,   150,   151,
     154,   154,   159,   160,   161,   164,   165,   166,   167,   168,
     169,   170,   173,   174,   177,   178,   181,   182,   185,   186,
     189,   190,   193,   196,   197,   198,   201,   202,   205,   208,
     209,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   225,   226,   227,   230,   231,   232,   235,   245,
     246,   247,   248,   249,   252,   253,   256,   257,   260,   263,
     264,   267,   270,   271,   274,   277,   278,   281,   282,   285,
     286,   287,   290,   291,   294,   295,   298,   301,   302,   305,
     306,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   333,   334,   337,   340,
     348,   356,   364,   372,   380,   388
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

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
    };
    // Last valid token kind.
    const int code_max = 319;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 2140 "Parser.cpp"

#line 397 "parser.yy"


void yy::Parser::error(const std::string &err_message)
{
    cerr << "Error: " << err_message << " at " << lexer.lineno() << " with token " << lexer.YYText() << endl;
}
