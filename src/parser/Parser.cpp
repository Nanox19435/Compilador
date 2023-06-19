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
#line 33 "parser.yy"

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
#line 99 "parser.yy"
                              { for(string id : yystack_[0].value.as < std::vector<std::string> > ()) driver.addSym(id, yystack_[1].value.as < int > (), "const"); }
#line 804 "Parser.cpp"
    break;

  case 10: // lista_id_const: lista_id_const COMA ID ASIG literal
#line 103 "parser.yy"
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
#line 114 "parser.yy"
                      { yylhs.value.as < std::vector<std::string> > () = driver.idVec(yystack_[2].value.as < std::string > ()); }
#line 826 "Parser.cpp"
    break;

  case 12: // decl_var: VAR tipo lista_id
#line 117 "parser.yy"
                      { for(string id : yystack_[0].value.as < std::vector<std::string> > ()) driver.addSym(id, yystack_[1].value.as < int > (), "var"); }
#line 832 "Parser.cpp"
    break;

  case 13: // lista_id: lista_id COMA ID
#line 121 "parser.yy"
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
#line 133 "parser.yy"
    {
        yylhs.value.as < std::vector<std::string> > () = driver.idVec(yystack_[0].value.as < std::string > ());
    }
#line 856 "Parser.cpp"
    break;

  case 15: // decl_proto: PROTO tipo ID LPAR lista_tipos RPAR
#line 138 "parser.yy"
                                        {}
#line 862 "Parser.cpp"
    break;

  case 16: // lista_tipos: tipos
#line 141 "parser.yy"
          {}
#line 868 "Parser.cpp"
    break;

  case 17: // lista_tipos: %empty
#line 142 "parser.yy"
                {}
#line 874 "Parser.cpp"
    break;

  case 18: // tipos: tipos COMA tipo
#line 145 "parser.yy"
                    {}
#line 880 "Parser.cpp"
    break;

  case 19: // tipos: tipo
#line 146 "parser.yy"
           {}
#line 886 "Parser.cpp"
    break;

  case 20: // decl_func: FUNC tipo ID LPAR lista_param RPAR bloque
#line 149 "parser.yy"
                                              {}
#line 892 "Parser.cpp"
    break;

  case 21: // tipo: nombre_tipo tipo_arreglo
#line 152 "parser.yy"
                             {}
#line 898 "Parser.cpp"
    break;

  case 22: // tipo: tipo_estructura
#line 153 "parser.yy"
                      {}
#line 904 "Parser.cpp"
    break;

  case 23: // tipo: nombre_tipo MUL
#line 154 "parser.yy"
                      {}
#line 910 "Parser.cpp"
    break;

  case 24: // nombre_tipo: CHAR
#line 157 "parser.yy"
         {}
#line 916 "Parser.cpp"
    break;

  case 25: // nombre_tipo: INT
#line 158 "parser.yy"
          { yylhs.value.as < int > () = 1; }
#line 922 "Parser.cpp"
    break;

  case 26: // nombre_tipo: F32
#line 159 "parser.yy"
          {}
#line 928 "Parser.cpp"
    break;

  case 27: // nombre_tipo: F64
#line 160 "parser.yy"
          {}
#line 934 "Parser.cpp"
    break;

  case 28: // nombre_tipo: STR
#line 161 "parser.yy"
          {}
#line 940 "Parser.cpp"
    break;

  case 29: // nombre_tipo: BOOL
#line 162 "parser.yy"
           {}
#line 946 "Parser.cpp"
    break;

  case 30: // nombre_tipo: VOID
#line 163 "parser.yy"
           {}
#line 952 "Parser.cpp"
    break;

  case 31: // tipo_arreglo: LBRACK expresion RBRACK tipo_arreglo
#line 166 "parser.yy"
                                         {}
#line 958 "Parser.cpp"
    break;

  case 32: // tipo_arreglo: %empty
#line 167 "parser.yy"
                {}
#line 964 "Parser.cpp"
    break;

  case 33: // tipo_estructura: STRUCT LBRACE decl_campo RBRACE
#line 170 "parser.yy"
                                    {}
#line 970 "Parser.cpp"
    break;

  case 34: // tipo_estructura: STRUCT ID LBRACE decl_campo RBRACE
#line 171 "parser.yy"
                                         {}
#line 976 "Parser.cpp"
    break;

  case 35: // decl_campo: tipo lista_id PYC decl_campo
#line 174 "parser.yy"
                                 {}
#line 982 "Parser.cpp"
    break;

  case 36: // decl_campo: %empty
#line 175 "parser.yy"
                {}
#line 988 "Parser.cpp"
    break;

  case 37: // lista_param: decl_params
#line 178 "parser.yy"
                {}
#line 994 "Parser.cpp"
    break;

  case 38: // lista_param: %empty
#line 179 "parser.yy"
                {}
#line 1000 "Parser.cpp"
    break;

  case 39: // decl_params: decl_params COMA decl_param
#line 182 "parser.yy"
                                {}
#line 1006 "Parser.cpp"
    break;

  case 40: // decl_params: decl_param
#line 183 "parser.yy"
                 {}
#line 1012 "Parser.cpp"
    break;

  case 41: // decl_param: tipo_param ID
#line 186 "parser.yy"
                  {}
#line 1018 "Parser.cpp"
    break;

  case 42: // tipo_param: nombre_tipo tipo_param_arr
#line 189 "parser.yy"
                               {}
#line 1024 "Parser.cpp"
    break;

  case 43: // tipo_param: STRUCT ID
#line 190 "parser.yy"
                {}
#line 1030 "Parser.cpp"
    break;

  case 44: // tipo_param: nombre_tipo MUL
#line 191 "parser.yy"
                      {}
#line 1036 "Parser.cpp"
    break;

  case 45: // tipo_param_arr: LBRACK expresion RBRACK tipo_param_arr
#line 194 "parser.yy"
                                           {}
#line 1042 "Parser.cpp"
    break;

  case 46: // tipo_param_arr: %empty
#line 195 "parser.yy"
                {}
#line 1048 "Parser.cpp"
    break;

  case 47: // bloque: LBRACE lista_sentencias RBRACE
#line 198 "parser.yy"
                                   {}
#line 1054 "Parser.cpp"
    break;

  case 48: // lista_sentencias: lista_sentencias sentencia
#line 201 "parser.yy"
                               {}
#line 1060 "Parser.cpp"
    break;

  case 50: // sentencia: decl_loc
#line 205 "parser.yy"
             {}
#line 1066 "Parser.cpp"
    break;

  case 51: // sentencia: sentencia_simple PYC
#line 206 "parser.yy"
                           {}
#line 1072 "Parser.cpp"
    break;

  case 52: // sentencia: sentencia_return PYC
#line 207 "parser.yy"
                           {}
#line 1078 "Parser.cpp"
    break;

  case 53: // sentencia: BREAK PYC
#line 208 "parser.yy"
                {}
#line 1084 "Parser.cpp"
    break;

  case 54: // sentencia: CONTINUE PYC
#line 209 "parser.yy"
                   {}
#line 1090 "Parser.cpp"
    break;

  case 55: // sentencia: bloque
#line 210 "parser.yy"
             {}
#line 1096 "Parser.cpp"
    break;

  case 56: // sentencia: sentencia_if
#line 211 "parser.yy"
                   {}
#line 1102 "Parser.cpp"
    break;

  case 57: // sentencia: sentencia_switch
#line 212 "parser.yy"
                       {}
#line 1108 "Parser.cpp"
    break;

  case 58: // sentencia: sentencia_for
#line 213 "parser.yy"
                    {}
#line 1114 "Parser.cpp"
    break;

  case 59: // sentencia: PRINT expresion PYC
#line 214 "parser.yy"
                          {}
#line 1120 "Parser.cpp"
    break;

  case 60: // sentencia: READ ID PYC
#line 215 "parser.yy"
                  {}
#line 1126 "Parser.cpp"
    break;

  case 61: // decl_loc: VAR nombre_tipo MUL lista_id
#line 218 "parser.yy"
                                 {}
#line 1132 "Parser.cpp"
    break;

  case 62: // decl_loc: VAR STRUCT ID lista_id
#line 219 "parser.yy"
                             {}
#line 1138 "Parser.cpp"
    break;

  case 63: // decl_loc: VAR nombre_tipo tipo_arreglo lista_id
#line 220 "parser.yy"
                                            {}
#line 1144 "Parser.cpp"
    break;

  case 67: // asig: izq ASIG expresion
#line 228 "parser.yy"
                       {
        if (izq.type != expresion.type) {
            string a = yystack_[2].value.as < expresion > ().temp;
            string b = yystack_[0].value.as < expresion > ().temp;

            driver.pushQuad(COPY, a, "", b);
        } else {
            /*error*/
        }
    }
#line 1159 "Parser.cpp"
    break;

  case 68: // asig: izq SASIG expresion
#line 238 "parser.yy"
                          {driver.asigOp(OP_ADD, yystack_[2].value.as < expresion > (), yystack_[0].value.as < expresion > ())}
#line 1165 "Parser.cpp"
    break;

  case 69: // asig: izq RASIG expresion
#line 239 "parser.yy"
                          {driver.asigOp(OP_SUB, yystack_[2].value.as < expresion > (), yystack_[0].value.as < expresion > ())}
#line 1171 "Parser.cpp"
    break;

  case 70: // asig: izq PASIG expresion
#line 240 "parser.yy"
                          {driver.asigOp(OP_MUL, yystack_[2].value.as < expresion > (), yystack_[0].value.as < expresion > ())}
#line 1177 "Parser.cpp"
    break;

  case 71: // asig: izq DASIG expresion
#line 241 "parser.yy"
                          {driver.asigOp(OP_DIV, yystack_[2].value.as < expresion > (), yystack_[0].value.as < expresion > ())}
#line 1183 "Parser.cpp"
    break;

  case 72: // asig: izq MASIG expresion
#line 242 "parser.yy"
                          {driver.asigOp(OP_MOD, yystack_[2].value.as < expresion > (), yystack_[0].value.as < expresion > ())}
#line 1189 "Parser.cpp"
    break;

  case 73: // incdec: expresion INCR
#line 245 "parser.yy"
                   { driver.incdec(yystack_[1].value.as < expresion > (), OP_ADD); }
#line 1195 "Parser.cpp"
    break;

  case 74: // incdec: expresion DECR
#line 246 "parser.yy"
                     { driver.incdec(yystack_[1].value.as < expresion > (), OP_SUB); }
#line 1201 "Parser.cpp"
    break;

  case 75: // sentencia_if: IF expresion bloque
#line 249 "parser.yy"
                        {}
#line 1207 "Parser.cpp"
    break;

  case 76: // sentencia_if: IF expresion bloque ELSE bloque
#line 250 "parser.yy"
                                      {}
#line 1213 "Parser.cpp"
    break;

  case 77: // sentencia_switch: SWITCH sentencia_simple LBRACE expr_casos RBRACE
#line 253 "parser.yy"
                                                     {}
#line 1219 "Parser.cpp"
    break;

  case 78: // expr_casos: expr_casos expr_caso
#line 256 "parser.yy"
                         {}
#line 1225 "Parser.cpp"
    break;

  case 79: // expr_casos: expr_caso
#line 257 "parser.yy"
                {}
#line 1231 "Parser.cpp"
    break;

  case 80: // expr_caso: caso COL lista_sentencias
#line 260 "parser.yy"
                              {}
#line 1237 "Parser.cpp"
    break;

  case 81: // caso: CASE expresion
#line 263 "parser.yy"
                   {}
#line 1243 "Parser.cpp"
    break;

  case 82: // caso: DEFAULT
#line 264 "parser.yy"
              {}
#line 1249 "Parser.cpp"
    break;

  case 83: // sentencia_for: FOR LPAR clausula_for RPAR bloque
#line 267 "parser.yy"
                                      {}
#line 1255 "Parser.cpp"
    break;

  case 84: // clausula_for: sentencia_simple PYC expresion PYC sentencia_simple
#line 270 "parser.yy"
                                                        {}
#line 1261 "Parser.cpp"
    break;

  case 85: // clausula_for: expresion
#line 271 "parser.yy"
                {}
#line 1267 "Parser.cpp"
    break;

  case 86: // sentencia_return: RETURN expresion
#line 274 "parser.yy"
                     {}
#line 1273 "Parser.cpp"
    break;

  case 87: // sentencia_return: RETURN
#line 275 "parser.yy"
             {}
#line 1279 "Parser.cpp"
    break;

  case 88: // izq: ID dato_miembro
#line 278 "parser.yy"
                    {}
#line 1285 "Parser.cpp"
    break;

  case 89: // izq: ID parte_arreglo
#line 279 "parser.yy"
                       {}
#line 1291 "Parser.cpp"
    break;

  case 90: // izq: ID llamada_funcion
#line 280 "parser.yy"
                         {}
#line 1297 "Parser.cpp"
    break;

  case 91: // dato_miembro: DOT ID dato_miembro
#line 283 "parser.yy"
                        {}
#line 1303 "Parser.cpp"
    break;

  case 92: // dato_miembro: %empty
#line 284 "parser.yy"
                {}
#line 1309 "Parser.cpp"
    break;

  case 93: // parte_arreglo: LBRACK expresion RBRACK parte_arreglo
#line 287 "parser.yy"
                                          {}
#line 1315 "Parser.cpp"
    break;

  case 94: // parte_arreglo: LBRACK expresion RBRACK
#line 288 "parser.yy"
                              {}
#line 1321 "Parser.cpp"
    break;

  case 95: // llamada_funcion: LPAR args RPAR
#line 291 "parser.yy"
                   {}
#line 1327 "Parser.cpp"
    break;

  case 96: // args: lista_args
#line 294 "parser.yy"
               {}
#line 1333 "Parser.cpp"
    break;

  case 97: // args: %empty
#line 295 "parser.yy"
                {}
#line 1339 "Parser.cpp"
    break;

  case 98: // lista_args: expresion COMA lista_args
#line 298 "parser.yy"
                              {}
#line 1345 "Parser.cpp"
    break;

  case 99: // lista_args: expresion
#line 299 "parser.yy"
                {}
#line 1351 "Parser.cpp"
    break;

  case 100: // expresion: expresion OR expresion
#line 302 "parser.yy"
                           { 
        if (yystack_[2].value.as < expresion > ().type == 0 && 0 == yystack_[0].value.as < expresion > ().type) {
            yylhs.value.as < expresion > ().type = 0 ;
            string a = yystack_[2].value.as < expresion > ().temp;
            string b = yystack_[0].value.as < expresion > ().temp;
            yylhs.value.as < expresion > ().temp = driver.newTmp();
            driver.pushQuad(OP_OR, a, b, yylhs.value.as < expresion > ().temp);
        } else {
            /*error*/
        }
       }
#line 1367 "Parser.cpp"
    break;

  case 101: // expresion: expresion AND expresion
#line 313 "parser.yy"
                              {}
#line 1373 "Parser.cpp"
    break;

  case 102: // expresion: expresion EQ expresion
#line 314 "parser.yy"
                             {}
#line 1379 "Parser.cpp"
    break;

  case 103: // expresion: expresion NEQ expresion
#line 315 "parser.yy"
                              {}
#line 1385 "Parser.cpp"
    break;

  case 104: // expresion: expresion LESS expresion
#line 316 "parser.yy"
                               {}
#line 1391 "Parser.cpp"
    break;

  case 105: // expresion: expresion LEQ expresion
#line 317 "parser.yy"
                              {}
#line 1397 "Parser.cpp"
    break;

  case 106: // expresion: expresion GREAT expresion
#line 318 "parser.yy"
                                {}
#line 1403 "Parser.cpp"
    break;

  case 107: // expresion: expresion GEQ expresion
#line 319 "parser.yy"
                              {}
#line 1409 "Parser.cpp"
    break;

  case 108: // expresion: expresion PLUS expresion
#line 320 "parser.yy"
                               {}
#line 1415 "Parser.cpp"
    break;

  case 109: // expresion: expresion SUB expresion
#line 321 "parser.yy"
                              {}
#line 1421 "Parser.cpp"
    break;

  case 110: // expresion: expresion MUL expresion
#line 322 "parser.yy"
                              {}
#line 1427 "Parser.cpp"
    break;

  case 111: // expresion: expresion DIV expresion
#line 323 "parser.yy"
                              {}
#line 1433 "Parser.cpp"
    break;

  case 112: // expresion: expresion MOD expresion
#line 324 "parser.yy"
                              {}
#line 1439 "Parser.cpp"
    break;

  case 113: // expresion: izq
#line 325 "parser.yy"
          {}
#line 1445 "Parser.cpp"
    break;

  case 114: // expresion: literal
#line 327 "parser.yy"
              {}
#line 1451 "Parser.cpp"
    break;

  case 115: // expresion: LPAR expresion RPAR
#line 328 "parser.yy"
                          { yylhs.value.as < expresion > () = yystack_[1].value.as < expresion > (); }
#line 1457 "Parser.cpp"
    break;

  case 116: // expresion: conversion
#line 329 "parser.yy"
                 {}
#line 1463 "Parser.cpp"
    break;

  case 117: // conversion: nombre_tipo LPAR expresion RPAR
#line 332 "parser.yy"
                                    {}
#line 1469 "Parser.cpp"
    break;

  case 118: // literal: TRUE
#line 336 "parser.yy"
    { 
        literal l; 
        l.type = 0;
        l.data = "true";

        yylhs.value.as < literal > () = l;
    }
#line 1481 "Parser.cpp"
    break;

  case 119: // literal: FALSE
#line 344 "parser.yy"
    { 
        literal l; 
        l.type = 0;
        l.data = "false";

        yylhs.value.as < literal > () = l;
    }
#line 1493 "Parser.cpp"
    break;

  case 120: // literal: INTV
#line 352 "parser.yy"
    { 
        literal l; 
        l.type = 1;
        l.data = lexer.YYText();

        yylhs.value.as < literal > () = l;
    }
#line 1505 "Parser.cpp"
    break;

  case 121: // literal: F32V
#line 360 "parser.yy"
    { 
        literal l; 
        l.type = 2;
        l.data = lexer.YYText();

        yylhs.value.as < literal > () = l;
    }
#line 1517 "Parser.cpp"
    break;

  case 122: // literal: F64V
#line 368 "parser.yy"
    { 
        literal l; 
        l.type = 3;
        l.data = lexer.YYText();

        yylhs.value.as < literal > () = l;
    }
#line 1529 "Parser.cpp"
    break;

  case 123: // literal: CHAR
#line 376 "parser.yy"
    { 
        literal l; 
        l.type = 4;
        l.data = lexer.YYText();

        yylhs.value.as < literal > () = l;
    }
#line 1541 "Parser.cpp"
    break;

  case 124: // literal: STR
#line 384 "parser.yy"
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









  const short Parser::yypact_ninf_ = -150;

  const signed char Parser::yytable_ninf_ = -86;

  const short
  Parser::yypact_[] =
  {
    -150,    19,    63,  -150,    57,    57,    57,    57,  -150,     7,
      10,    15,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
      12,    29,   -36,  -150,    33,    51,    61,  -150,  -150,  -150,
      13,    57,  -150,    47,  -150,   225,  -150,    52,    68,    34,
      35,    57,    29,    36,    94,   -34,    43,    45,  -150,  -150,
    -150,  -150,  -150,   225,    56,  -150,   301,  -150,  -150,   104,
     114,    57,   121,    58,    59,  -150,  -150,   115,   225,   225,
    -150,  -150,  -150,   409,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,    60,  -150,
    -150,  -150,    86,    67,   110,  -150,   128,     3,    77,   120,
    -150,   136,  -150,    57,    82,    88,  -150,   263,   324,  -150,
     428,   287,   474,   197,   197,    92,    92,    92,    92,    37,
      37,  -150,  -150,  -150,  -150,   104,  -150,    57,  -150,  -150,
     225,  -150,    89,   121,  -150,  -150,  -150,  -150,   225,    98,
    -150,  -150,  -150,   347,   193,  -150,  -150,  -150,  -150,   112,
     314,   225,   117,   225,   225,   135,   161,   225,   176,  -150,
     159,  -150,  -150,   168,  -150,  -150,  -150,  -150,  -150,   170,
     227,   447,  -150,   184,     4,   370,   225,   127,   463,  -150,
    -150,   226,   178,  -150,  -150,  -150,  -150,   225,   225,   225,
     225,   225,   225,  -150,  -150,    29,    29,    29,   172,   194,
     149,   390,    53,  -150,  -150,   463,   463,   463,   463,   463,
     463,    47,    47,    47,    89,   225,    89,   225,  -150,    -5,
    -150,   196,  -150,   243,  -150,   463,  -150,  -150,   193,   225,
     193,  -150
  };

  const signed char
  Parser::yydefact_[] =
  {
       4,     0,     2,     1,     0,     0,     0,     0,     3,     0,
       0,     0,     8,    28,    24,    30,    29,    25,    26,    27,
       0,     0,    32,    22,     0,     0,     0,     5,     6,     7,
       0,    36,    14,    12,    23,     0,    21,     0,     9,     0,
       0,    36,     0,     0,     0,    92,   124,   123,   120,   121,
     122,   118,   119,     0,     0,   113,     0,   116,   114,     0,
       0,    17,    38,     0,     0,    33,    13,     0,    97,     0,
      88,    89,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,   124,
     123,    11,     0,     0,    16,    19,     0,    46,     0,    37,
      40,     0,    34,    36,    92,     0,    96,    99,     0,   115,
       0,   100,   101,   102,   103,   104,   106,   105,   107,   108,
     109,   110,   111,   112,    31,     0,    15,     0,    43,    44,
       0,    42,     0,     0,    41,    35,    91,    95,     0,    94,
     117,    10,    18,     0,     0,    20,    39,    98,    93,    46,
       0,     0,     0,     0,    87,     0,     0,     0,     0,    55,
       0,    49,    50,     0,    66,    65,    56,    57,    58,     0,
     113,    64,    45,     0,    32,     0,     0,     0,    86,    53,
      54,     0,     0,    47,    48,    51,    52,     0,     0,     0,
       0,     0,     0,    73,    74,     0,     0,     0,    75,     0,
       0,    64,     0,    59,    60,    67,    68,    69,    70,    71,
      72,    62,    61,    63,     0,     0,     0,     0,    82,     0,
      79,     0,    76,     0,    83,    81,    77,    78,     0,     0,
      80,    84
  };

  const short
  Parser::yypgoto_[] =
  {
    -150,  -150,  -150,  -150,  -150,  -150,  -150,   -37,  -150,  -150,
    -150,  -150,     2,    -3,   -78,  -150,   -27,  -150,  -150,    78,
    -150,    65,  -115,   -12,  -149,  -150,  -141,  -150,  -150,  -150,
    -150,  -150,    22,  -150,  -150,  -150,  -150,  -123,   118,   116,
    -150,  -150,   119,   -35,  -150,   -46
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,     8,     9,    38,    10,    33,    11,    93,
      94,    12,    42,    54,    36,    23,    43,    98,    99,   100,
     101,   131,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   219,   220,   221,   168,   200,   169,    55,    70,    71,
      72,   105,   106,   171,    57,    58
  };

  const short
  Parser::yytable_[] =
  {
      56,    22,    22,    22,    22,    64,    21,    24,    25,    26,
     124,   184,   177,    91,    63,    30,    34,   145,    73,     3,
     217,   170,   218,    27,    67,    68,    28,    35,    22,    69,
     170,    29,    32,   107,   108,   199,    37,   170,    22,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   170,    39,   129,   196,   226,    22,    97,
     198,    13,    14,    95,    40,    44,   130,    35,    15,    16,
      17,    18,    19,    31,    41,   103,   135,    44,   217,   141,
     218,   184,     4,     5,     6,    20,    60,    59,   231,    85,
      86,    87,     7,    61,    62,   143,   197,    66,    65,   222,
      22,   224,   -28,   107,   -24,   170,   170,   170,    89,    90,
      48,    49,    50,    51,    52,    74,   175,    92,   104,   178,
     102,   125,   181,    35,    22,    13,    14,   126,   127,   142,
      97,   128,    15,    16,    17,    18,    19,   132,   133,   134,
      67,   201,    83,    84,    85,    86,    87,   174,   137,    96,
     144,   179,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    69,    45,    46,    47,    48,    49,    50,    51,    52,
      15,    16,    17,    18,    19,   130,   176,   180,   150,   182,
     223,   151,   225,   152,   185,   153,   186,   195,   202,   154,
     155,   156,   157,   158,   204,   214,    45,    46,    47,    48,
      49,    50,    51,    52,    15,    16,    17,    18,    19,   216,
     215,   146,   150,   228,   172,   151,   230,   152,    53,   153,
     144,   183,   136,   154,   155,   156,   157,   158,    45,    46,
      47,    48,    49,    50,    51,    52,    15,    16,    17,    18,
      19,   227,   203,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    53,     0,   144,   148,     0,   147,     0,   229,
       0,     0,   187,   188,   189,   190,   191,   192,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,   138,     0,     0,    53,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
       0,     0,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    13,    14,
       0,     0,     0,     0,     0,    15,    16,    17,    18,    19,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,   173,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   149,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,   144,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,   193,   194,     0,     0,
     -85,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,     0,     0,   109,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,   140,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,   193,   194,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87
  };

  const short
  Parser::yycheck_[] =
  {
      35,     4,     5,     6,     7,    42,     4,     5,     6,     7,
      88,   160,   153,    59,    41,     3,    52,   132,    53,     0,
      25,   144,    27,    16,    58,    59,    16,    63,    31,    63,
     153,    16,     3,    68,    69,   176,     3,   160,    41,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,   176,     3,    52,    52,    62,    61,    62,
     175,     4,     5,    61,     3,    18,    63,    63,    11,    12,
      13,    14,    15,    61,    61,    16,   103,    18,    25,   125,
      27,   230,    19,    20,    21,    28,    18,    35,   229,    52,
      53,    54,    29,    59,    59,   130,   174,     3,    62,   214,
     103,   216,    59,   138,    59,   228,   229,   230,     4,     5,
       6,     7,     8,     9,    10,    59,   151,     3,     3,   154,
      62,    35,   157,    63,   127,     4,     5,    60,    18,   127,
     133,     3,    11,    12,    13,    14,    15,    60,    18,     3,
      58,   176,    50,    51,    52,    53,    54,   150,    60,    28,
      61,    16,   187,   188,   189,   190,   191,   192,   195,   196,
     197,    63,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    63,    59,    16,    19,     3,
     215,    22,   217,    24,    16,    26,    16,     3,    61,    30,
      31,    32,    33,    34,    16,    23,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    60,
      16,   133,    19,    17,   149,    22,   228,    24,    59,    26,
      61,    62,   104,    30,    31,    32,    33,    34,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,   219,    16,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    59,    -1,    61,   139,    -1,   138,    -1,    16,
      -1,    -1,    35,    36,    37,    38,    39,    40,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    18,    -1,    -1,    59,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,     4,     5,
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
      71,    73,    76,     4,     5,    11,    12,    13,    14,    15,
      28,    77,    78,    80,    77,    77,    77,    16,    16,    16,
       3,    61,     3,    72,    52,    63,    79,     3,    70,     3,
       3,    61,    77,    81,    18,     3,     4,     5,     6,     7,
       8,     9,    10,    59,    78,   102,   108,   109,   110,    35,
      18,    59,    59,    81,    72,    62,     3,    58,    59,    63,
     103,   104,   105,   108,    59,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    64,     4,
       5,   110,     3,    74,    75,    77,    28,    78,    82,    83,
      84,    85,    62,    16,     3,   106,   107,   108,   108,    60,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,    79,    35,    60,    18,     3,    52,
      63,    86,    60,    18,     3,    81,   103,    60,    18,    64,
      60,   110,    77,   108,    61,    87,    84,   107,   104,    64,
      19,    22,    24,    26,    30,    31,    32,    33,    34,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    99,   101,
     102,   108,    86,    28,    78,   108,    59,    91,   108,    16,
      16,   108,     3,    62,    89,    16,    16,    35,    36,    37,
      38,    39,    40,    56,    57,     3,    52,    79,    87,    91,
     100,   108,    61,    16,    16,   108,   108,   108,   108,   108,
     108,    72,    72,    72,    23,    16,    60,    25,    27,    96,
      97,    98,    87,   108,    87,   108,    62,    97,    17,    16,
      88,    91
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    65,    66,    67,    67,    68,    68,    68,    68,    69,
      70,    70,    71,    72,    72,    73,    74,    74,    75,    75,
      76,    77,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    85,    85,    85,    86,    86,    87,    88,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    90,    90,    90,    91,    91,    91,    92,    92,    92,
      92,    92,    92,    93,    93,    94,    94,    95,    96,    96,
      97,    98,    98,    99,   100,   100,   101,   101,   102,   102,
     102,   103,   103,   104,   104,   105,   106,   106,   107,   107,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   110,   110,
     110,   110,   110,   110,   110
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     2,     2,     2,     1,     3,
       5,     3,     3,     3,     1,     6,     1,     0,     3,     1,
       7,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     0,     4,     5,     4,     0,     1,     0,     3,
       1,     2,     2,     2,     2,     4,     0,     3,     2,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     3,
       3,     4,     4,     4,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     5,     5,     2,     1,
       3,     2,     1,     5,     5,     1,     2,     1,     2,     2,
       2,     3,     0,     4,     3,     3,     1,     0,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     3,     1,     4,     1,     1,
       1,     1,     1,     1,     1
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
  "decl_func", "tipo", "nombre_tipo", "tipo_arreglo", "tipo_estructura",
  "decl_campo", "lista_param", "decl_params", "decl_param", "tipo_param",
  "tipo_param_arr", "bloque", "lista_sentencias", "sentencia", "decl_loc",
  "sentencia_simple", "asig", "incdec", "sentencia_if", "sentencia_switch",
  "expr_casos", "expr_caso", "caso", "sentencia_for", "clausula_for",
  "sentencia_return", "izq", "dato_miembro", "parte_arreglo",
  "llamada_funcion", "args", "lista_args", "expresion", "conversion",
  "literal", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,    86,    86,    89,    90,    93,    94,    95,    96,    99,
     102,   114,   117,   120,   132,   138,   141,   142,   145,   146,
     149,   152,   153,   154,   157,   158,   159,   160,   161,   162,
     163,   166,   167,   170,   171,   174,   175,   178,   179,   182,
     183,   186,   189,   190,   191,   194,   195,   198,   201,   202,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   218,   219,   220,   223,   224,   225,   228,   238,   239,
     240,   241,   242,   245,   246,   249,   250,   253,   256,   257,
     260,   263,   264,   267,   270,   271,   274,   275,   278,   279,
     280,   283,   284,   287,   288,   291,   294,   295,   298,   299,
     302,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   327,   328,   329,   332,   335,   343,
     351,   359,   367,   375,   383
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
#line 2138 "Parser.cpp"

#line 392 "parser.yy"


void yy::Parser::error(const std::string &err_message)
{
    cerr << "Error: " << err_message << " at " << lexer.lineno() << " with token " << lexer.YYText() << endl;
}
