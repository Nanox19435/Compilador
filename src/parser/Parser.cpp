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
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expresion: // expresion
        value.copy< expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTV: // INTV
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
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expresion: // expresion
        value.move< expresion > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTV: // INTV
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
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expresion: // expresion
        value.YY_MOVE_OR_COPY< expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTV: // INTV
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
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expresion: // expresion
        value.move< expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTV: // INTV
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
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_expresion: // expresion
        value.copy< expresion > (that.value);
        break;

      case symbol_kind::S_INTV: // INTV
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
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_expresion: // expresion
        value.move< expresion > (that.value);
        break;

      case symbol_kind::S_INTV: // INTV
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
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_expresion: // expresion
        yylhs.value.emplace< expresion > ();
        break;

      case symbol_kind::S_INTV: // INTV
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
#line 98 "parser.yy"
                              { for(string id : yystack_[0].value.as < std::vector<std::string> > ()) driver.addSym(id, yystack_[1].value.as < int > (), "const"); }
#line 832 "Parser.cpp"
    break;

  case 10: // lista_id_const: lista_id_const COMA ID ASIG literal
#line 102 "parser.yy"
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
#line 848 "Parser.cpp"
    break;

  case 11: // lista_id_const: ID ASIG literal
#line 113 "parser.yy"
                      { yylhs.value.as < std::vector<std::string> > () = driver.idVec(yystack_[2].value.as < std::string > ()); }
#line 854 "Parser.cpp"
    break;

  case 12: // decl_var: VAR tipo lista_id
#line 116 "parser.yy"
                      { for(string id : yystack_[0].value.as < std::vector<std::string> > ()) driver.addSym(id, yystack_[1].value.as < int > (), "var"); }
#line 860 "Parser.cpp"
    break;

  case 13: // lista_id: lista_id COMA ID
#line 120 "parser.yy"
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
#line 876 "Parser.cpp"
    break;

  case 14: // lista_id: ID
#line 132 "parser.yy"
    {
        yylhs.value.as < std::vector<std::string> > () = driver.idVec(yystack_[0].value.as < std::string > ());
    }
#line 884 "Parser.cpp"
    break;

  case 15: // decl_proto: PROTO tipo ID LPAR lista_tipos RPAR
#line 137 "parser.yy"
                                        {}
#line 890 "Parser.cpp"
    break;

  case 16: // lista_tipos: tipos
#line 140 "parser.yy"
          {}
#line 896 "Parser.cpp"
    break;

  case 17: // lista_tipos: %empty
#line 141 "parser.yy"
                {}
#line 902 "Parser.cpp"
    break;

  case 18: // tipos: tipos COMA tipo
#line 144 "parser.yy"
                    {}
#line 908 "Parser.cpp"
    break;

  case 19: // tipos: tipo
#line 145 "parser.yy"
           {}
#line 914 "Parser.cpp"
    break;

  case 20: // decl_func: FUNC tipo ID LPAR lista_param RPAR bloque
#line 148 "parser.yy"
                                              {}
#line 920 "Parser.cpp"
    break;

  case 21: // tipo: nombre_tipo tipo_arreglo
#line 151 "parser.yy"
                             {}
#line 926 "Parser.cpp"
    break;

  case 22: // tipo: tipo_estructura
#line 152 "parser.yy"
                      {}
#line 932 "Parser.cpp"
    break;

  case 23: // tipo: nombre_tipo MUL
#line 153 "parser.yy"
                      {}
#line 938 "Parser.cpp"
    break;

  case 24: // nombre_tipo: CHAR
#line 156 "parser.yy"
         {}
#line 944 "Parser.cpp"
    break;

  case 25: // nombre_tipo: INT
#line 157 "parser.yy"
          { yylhs.value.as < int > () = 1; }
#line 950 "Parser.cpp"
    break;

  case 26: // nombre_tipo: F32
#line 158 "parser.yy"
          {}
#line 956 "Parser.cpp"
    break;

  case 27: // nombre_tipo: F64
#line 159 "parser.yy"
          {}
#line 962 "Parser.cpp"
    break;

  case 28: // nombre_tipo: STR
#line 160 "parser.yy"
          {}
#line 968 "Parser.cpp"
    break;

  case 29: // nombre_tipo: BOOL
#line 161 "parser.yy"
           {}
#line 974 "Parser.cpp"
    break;

  case 30: // nombre_tipo: VOID
#line 162 "parser.yy"
           {}
#line 980 "Parser.cpp"
    break;

  case 31: // tipo_arreglo: LBRACK expresion RBRACK tipo_arreglo
#line 165 "parser.yy"
                                         {}
#line 986 "Parser.cpp"
    break;

  case 32: // tipo_arreglo: %empty
#line 166 "parser.yy"
                {}
#line 992 "Parser.cpp"
    break;

  case 33: // tipo_estructura: STRUCT LBRACE decl_campo RBRACE
#line 169 "parser.yy"
                                    {}
#line 998 "Parser.cpp"
    break;

  case 34: // tipo_estructura: STRUCT ID LBRACE decl_campo RBRACE
#line 170 "parser.yy"
                                         {}
#line 1004 "Parser.cpp"
    break;

  case 35: // decl_campo: tipo lista_id PYC decl_campo
#line 173 "parser.yy"
                                 {}
#line 1010 "Parser.cpp"
    break;

  case 36: // decl_campo: %empty
#line 174 "parser.yy"
                {}
#line 1016 "Parser.cpp"
    break;

  case 37: // lista_param: decl_params
#line 177 "parser.yy"
                {}
#line 1022 "Parser.cpp"
    break;

  case 38: // lista_param: %empty
#line 178 "parser.yy"
                {}
#line 1028 "Parser.cpp"
    break;

  case 39: // decl_params: decl_params COMA decl_param
#line 181 "parser.yy"
                                {}
#line 1034 "Parser.cpp"
    break;

  case 40: // decl_params: decl_param
#line 182 "parser.yy"
                 {}
#line 1040 "Parser.cpp"
    break;

  case 41: // decl_param: tipo_param ID
#line 185 "parser.yy"
                  {}
#line 1046 "Parser.cpp"
    break;

  case 42: // tipo_param: nombre_tipo tipo_param_arr
#line 188 "parser.yy"
                               {}
#line 1052 "Parser.cpp"
    break;

  case 43: // tipo_param: STRUCT ID
#line 189 "parser.yy"
                {}
#line 1058 "Parser.cpp"
    break;

  case 44: // tipo_param: nombre_tipo MUL
#line 190 "parser.yy"
                      {}
#line 1064 "Parser.cpp"
    break;

  case 45: // tipo_param_arr: LBRACK expresion RBRACK tipo_param_arr
#line 193 "parser.yy"
                                           {}
#line 1070 "Parser.cpp"
    break;

  case 46: // tipo_param_arr: %empty
#line 194 "parser.yy"
                {}
#line 1076 "Parser.cpp"
    break;

  case 47: // bloque: LBRACE lista_sentencias RBRACE
#line 197 "parser.yy"
                                   {}
#line 1082 "Parser.cpp"
    break;

  case 48: // lista_sentencias: lista_sentencias sentencia
#line 200 "parser.yy"
                               {}
#line 1088 "Parser.cpp"
    break;

  case 50: // sentencia: decl_loc
#line 204 "parser.yy"
             {}
#line 1094 "Parser.cpp"
    break;

  case 51: // sentencia: sentencia_simple PYC
#line 205 "parser.yy"
                           {}
#line 1100 "Parser.cpp"
    break;

  case 52: // sentencia: sentencia_return PYC
#line 206 "parser.yy"
                           {}
#line 1106 "Parser.cpp"
    break;

  case 53: // sentencia: BREAK PYC
#line 207 "parser.yy"
                {}
#line 1112 "Parser.cpp"
    break;

  case 54: // sentencia: CONTINUE PYC
#line 208 "parser.yy"
                   {}
#line 1118 "Parser.cpp"
    break;

  case 55: // sentencia: bloque
#line 209 "parser.yy"
             {}
#line 1124 "Parser.cpp"
    break;

  case 56: // sentencia: sentencia_if
#line 210 "parser.yy"
                   {}
#line 1130 "Parser.cpp"
    break;

  case 57: // sentencia: sentencia_switch
#line 211 "parser.yy"
                       {}
#line 1136 "Parser.cpp"
    break;

  case 58: // sentencia: sentencia_for
#line 212 "parser.yy"
                    {}
#line 1142 "Parser.cpp"
    break;

  case 59: // sentencia: PRINT expresion PYC
#line 213 "parser.yy"
                          {}
#line 1148 "Parser.cpp"
    break;

  case 60: // sentencia: READ ID PYC
#line 214 "parser.yy"
                  {}
#line 1154 "Parser.cpp"
    break;

  case 61: // decl_loc: VAR nombre_tipo MUL lista_id
#line 217 "parser.yy"
                                 {}
#line 1160 "Parser.cpp"
    break;

  case 62: // decl_loc: VAR STRUCT ID lista_id
#line 218 "parser.yy"
                             {}
#line 1166 "Parser.cpp"
    break;

  case 63: // decl_loc: VAR nombre_tipo tipo_arreglo lista_id
#line 219 "parser.yy"
                                            {}
#line 1172 "Parser.cpp"
    break;

  case 64: // sentencia_simple: expresion
#line 222 "parser.yy"
              {}
#line 1178 "Parser.cpp"
    break;

  case 65: // sentencia_simple: incdec
#line 223 "parser.yy"
             {}
#line 1184 "Parser.cpp"
    break;

  case 66: // sentencia_simple: asig
#line 224 "parser.yy"
           {}
#line 1190 "Parser.cpp"
    break;

  case 67: // asig: izq op_asig expresion
#line 227 "parser.yy"
                          {}
#line 1196 "Parser.cpp"
    break;

  case 68: // incdec: expresion INCR
#line 230 "parser.yy"
                   {}
#line 1202 "Parser.cpp"
    break;

  case 69: // incdec: expresion DECR
#line 231 "parser.yy"
                     {}
#line 1208 "Parser.cpp"
    break;

  case 70: // op_asig: ASIG
#line 234 "parser.yy"
         {}
#line 1214 "Parser.cpp"
    break;

  case 71: // op_asig: SASIG
#line 235 "parser.yy"
            {}
#line 1220 "Parser.cpp"
    break;

  case 72: // op_asig: RASIG
#line 236 "parser.yy"
            {}
#line 1226 "Parser.cpp"
    break;

  case 73: // op_asig: PASIG
#line 237 "parser.yy"
            {}
#line 1232 "Parser.cpp"
    break;

  case 74: // op_asig: DASIG
#line 238 "parser.yy"
            {}
#line 1238 "Parser.cpp"
    break;

  case 75: // op_asig: MASIG
#line 239 "parser.yy"
            {}
#line 1244 "Parser.cpp"
    break;

  case 76: // sentencia_if: IF expresion bloque
#line 242 "parser.yy"
                        {}
#line 1250 "Parser.cpp"
    break;

  case 77: // sentencia_if: IF expresion bloque ELSE bloque
#line 243 "parser.yy"
                                      {}
#line 1256 "Parser.cpp"
    break;

  case 78: // sentencia_switch: SWITCH sentencia_simple LBRACE expr_casos RBRACE
#line 246 "parser.yy"
                                                     {}
#line 1262 "Parser.cpp"
    break;

  case 79: // expr_casos: expr_casos expr_caso
#line 249 "parser.yy"
                         {}
#line 1268 "Parser.cpp"
    break;

  case 80: // expr_casos: expr_caso
#line 250 "parser.yy"
                {}
#line 1274 "Parser.cpp"
    break;

  case 81: // expr_caso: caso COL lista_sentencias
#line 253 "parser.yy"
                              {}
#line 1280 "Parser.cpp"
    break;

  case 82: // caso: CASE expresion
#line 256 "parser.yy"
                   {}
#line 1286 "Parser.cpp"
    break;

  case 83: // caso: DEFAULT
#line 257 "parser.yy"
              {}
#line 1292 "Parser.cpp"
    break;

  case 84: // sentencia_for: FOR LPAR clausula_for RPAR bloque
#line 260 "parser.yy"
                                      {}
#line 1298 "Parser.cpp"
    break;

  case 85: // clausula_for: sentencia_simple PYC expresion PYC sentencia_simple
#line 263 "parser.yy"
                                                        {}
#line 1304 "Parser.cpp"
    break;

  case 86: // clausula_for: expresion
#line 264 "parser.yy"
                {}
#line 1310 "Parser.cpp"
    break;

  case 87: // sentencia_return: RETURN expresion
#line 267 "parser.yy"
                     {}
#line 1316 "Parser.cpp"
    break;

  case 88: // sentencia_return: RETURN
#line 268 "parser.yy"
             {}
#line 1322 "Parser.cpp"
    break;

  case 89: // izq: ID dato_miembro
#line 271 "parser.yy"
                    {}
#line 1328 "Parser.cpp"
    break;

  case 90: // izq: ID parte_arreglo
#line 272 "parser.yy"
                       {}
#line 1334 "Parser.cpp"
    break;

  case 91: // izq: ID llamada_funcion
#line 273 "parser.yy"
                         {}
#line 1340 "Parser.cpp"
    break;

  case 92: // dato_miembro: DOT ID dato_miembro
#line 276 "parser.yy"
                        {}
#line 1346 "Parser.cpp"
    break;

  case 93: // dato_miembro: %empty
#line 277 "parser.yy"
                {}
#line 1352 "Parser.cpp"
    break;

  case 94: // parte_arreglo: LBRACK expresion RBRACK parte_arreglo
#line 280 "parser.yy"
                                          {}
#line 1358 "Parser.cpp"
    break;

  case 95: // parte_arreglo: LBRACK expresion RBRACK
#line 281 "parser.yy"
                              {}
#line 1364 "Parser.cpp"
    break;

  case 96: // llamada_funcion: LPAR args RPAR
#line 284 "parser.yy"
                   {}
#line 1370 "Parser.cpp"
    break;

  case 97: // args: lista_args
#line 287 "parser.yy"
               {}
#line 1376 "Parser.cpp"
    break;

  case 98: // args: %empty
#line 288 "parser.yy"
                {}
#line 1382 "Parser.cpp"
    break;

  case 99: // lista_args: expresion COMA lista_args
#line 291 "parser.yy"
                              {}
#line 1388 "Parser.cpp"
    break;

  case 100: // lista_args: expresion
#line 292 "parser.yy"
                {}
#line 1394 "Parser.cpp"
    break;

  case 101: // expresion: expresion OR expresion
#line 295 "parser.yy"
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
#line 1410 "Parser.cpp"
    break;

  case 102: // expresion: expresion AND expresion
#line 306 "parser.yy"
                              {}
#line 1416 "Parser.cpp"
    break;

  case 103: // expresion: expresion EQ expresion
#line 307 "parser.yy"
                             {}
#line 1422 "Parser.cpp"
    break;

  case 104: // expresion: expresion NEQ expresion
#line 308 "parser.yy"
                              {}
#line 1428 "Parser.cpp"
    break;

  case 105: // expresion: expresion LESS expresion
#line 309 "parser.yy"
                               {}
#line 1434 "Parser.cpp"
    break;

  case 106: // expresion: expresion LEQ expresion
#line 310 "parser.yy"
                              {}
#line 1440 "Parser.cpp"
    break;

  case 107: // expresion: expresion GREAT expresion
#line 311 "parser.yy"
                                {}
#line 1446 "Parser.cpp"
    break;

  case 108: // expresion: expresion GEQ expresion
#line 312 "parser.yy"
                              {}
#line 1452 "Parser.cpp"
    break;

  case 109: // expresion: expresion PLUS expresion
#line 313 "parser.yy"
                               {}
#line 1458 "Parser.cpp"
    break;

  case 110: // expresion: expresion SUB expresion
#line 314 "parser.yy"
                              {}
#line 1464 "Parser.cpp"
    break;

  case 111: // expresion: expresion MUL expresion
#line 315 "parser.yy"
                              {}
#line 1470 "Parser.cpp"
    break;

  case 112: // expresion: expresion DIV expresion
#line 316 "parser.yy"
                              {}
#line 1476 "Parser.cpp"
    break;

  case 113: // expresion: expresion MOD expresion
#line 317 "parser.yy"
                              {}
#line 1482 "Parser.cpp"
    break;

  case 114: // expresion: izq
#line 318 "parser.yy"
          {}
#line 1488 "Parser.cpp"
    break;

  case 115: // expresion: literal
#line 320 "parser.yy"
              {}
#line 1494 "Parser.cpp"
    break;

  case 116: // expresion: LPAR expresion RPAR
#line 321 "parser.yy"
                          { yylhs.value.as < expresion > () = yystack_[1].value.as < expresion > (); }
#line 1500 "Parser.cpp"
    break;

  case 117: // expresion: conversion
#line 322 "parser.yy"
                 {}
#line 1506 "Parser.cpp"
    break;

  case 118: // conversion: nombre_tipo LPAR expresion RPAR
#line 325 "parser.yy"
                                    {}
#line 1512 "Parser.cpp"
    break;

  case 119: // literal: TRUE
#line 329 "parser.yy"
    { 
        literal l; 
        l.type = 0;
        l.data = &yystack_[0].value.as < bool > ();

        yylhs.value.as < literal > () = l;
    }
#line 1524 "Parser.cpp"
    break;

  case 120: // literal: FALSE
#line 337 "parser.yy"
    { 
        literal l; 
        l.type = 0;
        l.data = &yystack_[0].value.as < bool > ();

        yylhs.value.as < literal > () = l;
    }
#line 1536 "Parser.cpp"
    break;

  case 121: // literal: INTV
#line 345 "parser.yy"
    { 
        literal l; 
        l.type = 1;
        l.data = &yystack_[0].value.as < int > ();

        yylhs.value.as < literal > () = l;
    }
#line 1548 "Parser.cpp"
    break;

  case 122: // literal: F32V
#line 353 "parser.yy"
    { 
        literal l; 
        l.type = 2;
        l.data = &yystack_[0].value.as < std::string > ();

        yylhs.value.as < literal > () = l;
    }
#line 1560 "Parser.cpp"
    break;

  case 123: // literal: F64V
#line 361 "parser.yy"
    { 
        literal l; 
        l.type = 3;
        l.data = &yystack_[0].value.as < std::string > ();

        yylhs.value.as < literal > () = l;
    }
#line 1572 "Parser.cpp"
    break;

  case 124: // literal: CHAR
#line 369 "parser.yy"
    { 
        literal l; 
        l.type = 4;
        l.data = &yystack_[0].value.as < std::string > ();

        yylhs.value.as < literal > () = l;
    }
#line 1584 "Parser.cpp"
    break;

  case 125: // literal: STR
#line 377 "parser.yy"
    { 
        literal l; 
        l.type = 5;
        l.data = &yystack_[0].value.as < std::string > ();

        yylhs.value.as < literal > () = l;
    }
#line 1596 "Parser.cpp"
    break;


#line 1600 "Parser.cpp"

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









  const short Parser::yypact_ninf_ = -153;

  const signed char Parser::yytable_ninf_ = -87;

  const short
  Parser::yypact_[] =
  {
    -153,    11,     8,  -153,   116,   116,   116,   116,  -153,     0,
       6,    19,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
       9,    35,   -39,  -153,    57,    58,    77,  -153,  -153,  -153,
      21,   116,  -153,    65,  -153,   233,  -153,    49,    68,    28,
      29,   116,    35,    27,    87,   -27,    34,    37,  -153,  -153,
    -153,  -153,  -153,   233,    38,  -153,   309,  -153,  -153,   100,
      91,   116,   134,    39,     1,  -153,  -153,    96,   233,   233,
    -153,  -153,  -153,   417,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,    51,  -153,
    -153,  -153,    67,    53,    97,  -153,   114,   -38,    63,   106,
    -153,   115,  -153,   116,    74,    66,  -153,   271,   332,  -153,
     436,   295,   482,   205,   205,    14,    14,    14,    14,    24,
      24,  -153,  -153,  -153,  -153,   100,  -153,   116,  -153,  -153,
     233,  -153,    75,   134,  -153,  -153,  -153,  -153,   233,    79,
    -153,  -153,  -153,   355,   201,  -153,  -153,  -153,  -153,    80,
     322,   233,    78,   233,   233,   124,   135,   233,   147,  -153,
     160,  -153,  -153,   136,  -153,  -153,  -153,  -153,  -153,   138,
     235,   455,  -153,   156,   -37,   378,   233,    99,   471,  -153,
    -153,   234,   145,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,   233,  -153,  -153,    35,    35,    35,   157,
     165,   125,   398,    46,  -153,  -153,   471,    65,    65,    65,
      75,   233,    75,   233,  -153,    -4,  -153,   170,  -153,   251,
    -153,   471,  -153,  -153,   201,   233,   201,  -153
  };

  const signed char
  Parser::yydefact_[] =
  {
       4,     0,     2,     1,     0,     0,     0,     0,     3,     0,
       0,     0,     8,    28,    24,    30,    29,    25,    26,    27,
       0,     0,    32,    22,     0,     0,     0,     5,     6,     7,
       0,    36,    14,    12,    23,     0,    21,     0,     9,     0,
       0,    36,     0,     0,     0,    93,   125,   124,   121,   122,
     123,   119,   120,     0,     0,   114,     0,   117,   115,     0,
       0,    17,    38,     0,     0,    33,    13,     0,    98,     0,
      89,    90,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,   125,
     124,    11,     0,     0,    16,    19,     0,    46,     0,    37,
      40,     0,    34,    36,    93,     0,    97,   100,     0,   116,
       0,   101,   102,   103,   104,   105,   107,   106,   108,   109,
     110,   111,   112,   113,    31,     0,    15,     0,    43,    44,
       0,    42,     0,     0,    41,    35,    92,    96,     0,    95,
     118,    10,    18,     0,     0,    20,    39,    99,    94,    46,
       0,     0,     0,     0,    88,     0,     0,     0,     0,    55,
       0,    49,    50,     0,    66,    65,    56,    57,    58,     0,
     114,    64,    45,     0,    32,     0,     0,     0,    87,    53,
      54,     0,     0,    47,    48,    51,    52,    70,    71,    72,
      73,    74,    75,     0,    68,    69,     0,     0,     0,    76,
       0,     0,    64,     0,    59,    60,    67,    62,    61,    63,
       0,     0,     0,     0,    83,     0,    80,     0,    77,     0,
      84,    82,    78,    79,     0,     0,    81,    85
  };

  const short
  Parser::yypgoto_[] =
  {
    -153,  -153,  -153,  -153,  -153,  -153,  -153,   -41,  -153,  -153,
    -153,  -153,    -2,    50,   -82,  -153,   -31,  -153,  -153,    55,
    -153,    40,  -112,   -29,  -152,  -153,  -146,  -153,  -153,  -153,
    -153,  -153,  -153,   -19,  -153,  -153,  -153,  -153,   -91,    93,
      59,  -153,  -153,    61,   -35,  -153,   -50
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,     8,     9,    38,    10,    33,    11,    93,
      94,    12,    42,    54,    36,    23,    43,    98,    99,   100,
     101,   131,   159,   160,   161,   162,   163,   164,   165,   193,
     166,   167,   215,   216,   217,   168,   201,   169,    55,    70,
      71,    72,   105,   106,   171,    57,    58
  };

  const short
  Parser::yytable_[] =
  {
      56,    64,    21,    24,    25,    26,   124,   177,   184,    91,
      63,     3,    30,    34,   129,   197,    27,   103,    73,    44,
     145,   213,    28,   214,    35,   130,    35,     4,     5,     6,
     200,    67,    68,   107,   108,    29,    69,     7,    32,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   170,    22,    22,    22,    22,   222,    95,
      37,    39,   170,   199,    83,    84,    85,    86,    87,   170,
      31,   213,   135,   214,   184,   141,    85,    86,    87,   227,
      40,    22,    41,    44,    59,   170,    60,    61,    62,    65,
      66,    22,   198,   -28,    92,   143,   -24,    74,   218,   104,
     220,   102,   125,   107,    89,    90,    48,    49,    50,    51,
      52,    22,    97,   126,    35,   127,   175,   128,   134,   178,
      13,    14,   181,   132,   133,   142,   137,    15,    16,    17,
      18,    19,    67,   170,   170,   170,   144,   176,    13,    14,
     179,   202,    69,   130,    20,    15,    16,    17,    18,    19,
     182,   180,   185,    22,   186,   207,   208,   209,   206,   196,
     203,   205,    96,    45,    46,    47,    48,    49,    50,    51,
      52,    15,    16,    17,    18,    19,   219,    22,   221,   150,
     210,   211,   151,    97,   152,   212,   153,   224,   146,   172,
     154,   155,   156,   157,   158,   226,   223,   136,   148,   147,
     174,     0,     0,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    15,    16,    17,    18,    19,     0,     0,    53,
     150,   144,   183,   151,     0,   152,     0,   153,     0,     0,
       0,   154,   155,   156,   157,   158,    45,    46,    47,    48,
      49,    50,    51,    52,    15,    16,    17,    18,    19,     0,
     204,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      53,     0,   144,     0,     0,     0,     0,   225,     0,     0,
     187,   188,   189,   190,   191,   192,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   138,
       0,     0,    53,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    13,    14,     0,     0,
       0,     0,     0,    15,    16,    17,    18,    19,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
     173,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   139,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   149,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,     0,   144,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,   194,   195,     0,     0,   -86,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,     0,     0,     0,   109,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,     0,     0,   140,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,   194,   195,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87
  };

  const short
  Parser::yycheck_[] =
  {
      35,    42,     4,     5,     6,     7,    88,   153,   160,    59,
      41,     0,     3,    52,    52,    52,    16,    16,    53,    18,
     132,    25,    16,    27,    63,    63,    63,    19,    20,    21,
     176,    58,    59,    68,    69,    16,    63,    29,     3,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,   144,     4,     5,     6,     7,    62,    61,
       3,     3,   153,   175,    50,    51,    52,    53,    54,   160,
      61,    25,   103,    27,   226,   125,    52,    53,    54,   225,
       3,    31,    61,    18,    35,   176,    18,    59,    59,    62,
       3,    41,   174,    59,     3,   130,    59,    59,   210,     3,
     212,    62,    35,   138,     4,     5,     6,     7,     8,     9,
      10,    61,    62,    60,    63,    18,   151,     3,     3,   154,
       4,     5,   157,    60,    18,   127,    60,    11,    12,    13,
      14,    15,    58,   224,   225,   226,    61,    59,     4,     5,
      16,   176,    63,    63,    28,    11,    12,    13,    14,    15,
       3,    16,    16,   103,    16,   196,   197,   198,   193,     3,
      61,    16,    28,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,   211,   127,   213,    19,
      23,    16,    22,   133,    24,    60,    26,    17,   133,   149,
      30,    31,    32,    33,    34,   224,   215,   104,   139,   138,
     150,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    59,
      19,    61,    62,    22,    -1,    24,    -1,    26,    -1,    -1,
      -1,    30,    31,    32,    33,    34,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      16,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      59,    -1,    61,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      35,    36,    37,    38,    39,    40,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    18,
      -1,    -1,    59,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,     4,     5,    -1,    -1,
      -1,    -1,    -1,    11,    12,    13,    14,    15,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      28,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    -1,    -1,    60,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    -1,    60,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    -1,    60,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    66,    67,     0,    19,    20,    21,    29,    68,    69,
      71,    73,    76,     4,     5,    11,    12,    13,    14,    15,
      28,    77,    78,    80,    77,    77,    77,    16,    16,    16,
       3,    61,     3,    72,    52,    63,    79,     3,    70,     3,
       3,    61,    77,    81,    18,     3,     4,     5,     6,     7,
       8,     9,    10,    59,    78,   103,   109,   110,   111,    35,
      18,    59,    59,    81,    72,    62,     3,    58,    59,    63,
     104,   105,   106,   109,    59,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    64,     4,
       5,   111,     3,    74,    75,    77,    28,    78,    82,    83,
      84,    85,    62,    16,     3,   107,   108,   109,   109,    60,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,    79,    35,    60,    18,     3,    52,
      63,    86,    60,    18,     3,    81,   104,    60,    18,    64,
      60,   111,    77,   109,    61,    87,    84,   108,   105,    64,
      19,    22,    24,    26,    30,    31,    32,    33,    34,    87,
      88,    89,    90,    91,    92,    93,    95,    96,   100,   102,
     103,   109,    86,    28,    78,   109,    59,    91,   109,    16,
      16,   109,     3,    62,    89,    16,    16,    35,    36,    37,
      38,    39,    40,    94,    56,    57,     3,    52,    79,    87,
      91,   101,   109,    61,    16,    16,   109,    72,    72,    72,
      23,    16,    60,    25,    27,    97,    98,    99,    87,   109,
      87,   109,    62,    98,    17,    16,    88,    91
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
      89,    90,    90,    90,    91,    91,    91,    92,    93,    93,
      94,    94,    94,    94,    94,    94,    95,    95,    96,    97,
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
       7,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     0,     4,     5,     4,     0,     1,     0,     3,
       1,     2,     2,     2,     2,     4,     0,     3,     2,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     3,
       3,     4,     4,     4,     1,     1,     1,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     3,     5,     5,     2,
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
  "decl_func", "tipo", "nombre_tipo", "tipo_arreglo", "tipo_estructura",
  "decl_campo", "lista_param", "decl_params", "decl_param", "tipo_param",
  "tipo_param_arr", "bloque", "lista_sentencias", "sentencia", "decl_loc",
  "sentencia_simple", "asig", "incdec", "op_asig", "sentencia_if",
  "sentencia_switch", "expr_casos", "expr_caso", "caso", "sentencia_for",
  "clausula_for", "sentencia_return", "izq", "dato_miembro",
  "parte_arreglo", "llamada_funcion", "args", "lista_args", "expresion",
  "conversion", "literal", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,    85,    85,    88,    89,    92,    93,    94,    95,    98,
     101,   113,   116,   119,   131,   137,   140,   141,   144,   145,
     148,   151,   152,   153,   156,   157,   158,   159,   160,   161,
     162,   165,   166,   169,   170,   173,   174,   177,   178,   181,
     182,   185,   188,   189,   190,   193,   194,   197,   200,   201,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   217,   218,   219,   222,   223,   224,   227,   230,   231,
     234,   235,   236,   237,   238,   239,   242,   243,   246,   249,
     250,   253,   256,   257,   260,   263,   264,   267,   268,   271,
     272,   273,   276,   277,   280,   281,   284,   287,   288,   291,
     292,   295,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   320,   321,   322,   325,   328,
     336,   344,   352,   360,   368,   376
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
#line 2180 "Parser.cpp"

#line 385 "parser.yy"


void yy::Parser::error(const std::string &err_message)
{
    cerr << "Error: " << err_message << " at " << lexer.lineno() << " with token " << lexer.YYText() << endl;
}
