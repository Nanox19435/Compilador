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
#line 19 "src/parser/parser.yy"

    #include <iostream>
    #include <fstream>
    using namespace std;

    #include "Lexer.hpp"
    
    #define yylex lexer.yylex

#line 56 "Parser.cpp"


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
#line 129 "Parser.cpp"

  /// Build a parser object.
  Parser::Parser (Lexer &lexer_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg)
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
#line 66 "src/parser/parser.yy"
                  {}
#line 616 "Parser.cpp"
    break;

  case 3: // $@1: %empty
#line 69 "src/parser/parser.yy"
                  {declaracion.tipo = declaraciones.tipo}
#line 622 "Parser.cpp"
    break;

  case 5: // declaraciones: %empty
#line 70 "src/parser/parser.yy"
                  {}
#line 628 "Parser.cpp"
    break;

  case 6: // declaracion: decl_const
#line 73 "src/parser/parser.yy"
               {}
#line 634 "Parser.cpp"
    break;

  case 7: // declaracion: decl_var
#line 74 "src/parser/parser.yy"
               {}
#line 640 "Parser.cpp"
    break;

  case 8: // declaracion: decl_proto
#line 75 "src/parser/parser.yy"
                 {}
#line 646 "Parser.cpp"
    break;

  case 9: // declaracion: decl_func
#line 76 "src/parser/parser.yy"
                {}
#line 652 "Parser.cpp"
    break;

  case 10: // decl_const: CONST tipo lista_id_const
#line 79 "src/parser/parser.yy"
                              {}
#line 658 "Parser.cpp"
    break;

  case 11: // lista_id_const: lista_id_const COMA ID ASIG literal
#line 82 "src/parser/parser.yy"
                                        {}
#line 664 "Parser.cpp"
    break;

  case 12: // lista_id_const: ID ASIG literal
#line 83 "src/parser/parser.yy"
                      {}
#line 670 "Parser.cpp"
    break;

  case 13: // decl_var: VAR tipo lista_id
#line 86 "src/parser/parser.yy"
                      {}
#line 676 "Parser.cpp"
    break;

  case 14: // $@2: %empty
#line 89 "src/parser/parser.yy"
                  {id.tipo = L.tipo}
#line 682 "Parser.cpp"
    break;

  case 16: // $@3: %empty
#line 90 "src/parser/parser.yy"
         {id.tipo = lista_id.tipo}
#line 688 "Parser.cpp"
    break;

  case 18: // decl_proto: PROTO tipo ID LPAR lista_tipos RPAR
#line 93 "src/parser/parser.yy"
                                        {}
#line 694 "Parser.cpp"
    break;

  case 19: // lista_tipos: tipos
#line 96 "src/parser/parser.yy"
          {}
#line 700 "Parser.cpp"
    break;

  case 20: // lista_tipos: %empty
#line 97 "src/parser/parser.yy"
                {}
#line 706 "Parser.cpp"
    break;

  case 21: // tipos: tipos COMA tipo
#line 100 "src/parser/parser.yy"
                    {}
#line 712 "Parser.cpp"
    break;

  case 22: // tipos: tipo
#line 101 "src/parser/parser.yy"
           {}
#line 718 "Parser.cpp"
    break;

  case 23: // decl_func: FUNC tipo ID LPAR lista_param RPAR bloque
#line 104 "src/parser/parser.yy"
                                              {}
#line 724 "Parser.cpp"
    break;

  case 24: // tipo: nombre_tipo tipo_arreglo
#line 107 "src/parser/parser.yy"
                             {}
#line 730 "Parser.cpp"
    break;

  case 25: // tipo: tipo_estructura
#line 108 "src/parser/parser.yy"
                      {}
#line 736 "Parser.cpp"
    break;

  case 26: // tipo: nombre_tipo MUL
#line 109 "src/parser/parser.yy"
                      {}
#line 742 "Parser.cpp"
    break;

  case 27: // $@4: %empty
#line 112 "src/parser/parser.yy"
                {}
#line 748 "Parser.cpp"
    break;

  case 28: // nombre_tipo: nombre_tipo $@4 CHAR
#line 113 "src/parser/parser.yy"
         {}
#line 754 "Parser.cpp"
    break;

  case 29: // nombre_tipo: INT
#line 114 "src/parser/parser.yy"
          {}
#line 760 "Parser.cpp"
    break;

  case 30: // nombre_tipo: F32
#line 115 "src/parser/parser.yy"
          {}
#line 766 "Parser.cpp"
    break;

  case 31: // nombre_tipo: F64
#line 116 "src/parser/parser.yy"
          {}
#line 772 "Parser.cpp"
    break;

  case 32: // nombre_tipo: STR
#line 117 "src/parser/parser.yy"
          {}
#line 778 "Parser.cpp"
    break;

  case 33: // nombre_tipo: BOOL
#line 118 "src/parser/parser.yy"
           {}
#line 784 "Parser.cpp"
    break;

  case 34: // nombre_tipo: VOID
#line 119 "src/parser/parser.yy"
           {}
#line 790 "Parser.cpp"
    break;

  case 35: // tipo_arreglo: LBRACK expresion RBRACK tipo_arreglo
#line 122 "src/parser/parser.yy"
                                         {}
#line 796 "Parser.cpp"
    break;

  case 36: // tipo_arreglo: %empty
#line 123 "src/parser/parser.yy"
                {}
#line 802 "Parser.cpp"
    break;

  case 37: // tipo_estructura: STRUCT LBRACE decl_campo RBRACE
#line 126 "src/parser/parser.yy"
                                    {}
#line 808 "Parser.cpp"
    break;

  case 38: // tipo_estructura: STRUCT ID LBRACE decl_campo RBRACE
#line 127 "src/parser/parser.yy"
                                         {}
#line 814 "Parser.cpp"
    break;

  case 39: // decl_campo: tipo lista_id PYC decl_campo
#line 130 "src/parser/parser.yy"
                                 {}
#line 820 "Parser.cpp"
    break;

  case 40: // decl_campo: %empty
#line 131 "src/parser/parser.yy"
                {}
#line 826 "Parser.cpp"
    break;

  case 41: // lista_param: decl_params
#line 134 "src/parser/parser.yy"
                {}
#line 832 "Parser.cpp"
    break;

  case 42: // lista_param: %empty
#line 135 "src/parser/parser.yy"
                {}
#line 838 "Parser.cpp"
    break;

  case 43: // decl_params: decl_params COMA decl_param
#line 138 "src/parser/parser.yy"
                                {}
#line 844 "Parser.cpp"
    break;

  case 44: // decl_params: decl_param
#line 139 "src/parser/parser.yy"
                 {}
#line 850 "Parser.cpp"
    break;

  case 45: // decl_param: tipo_param ID
#line 142 "src/parser/parser.yy"
                  {}
#line 856 "Parser.cpp"
    break;

  case 46: // tipo_param: nombre_tipo tipo_param_arr
#line 145 "src/parser/parser.yy"
                               {}
#line 862 "Parser.cpp"
    break;

  case 47: // tipo_param: STRUCT ID
#line 146 "src/parser/parser.yy"
                {}
#line 868 "Parser.cpp"
    break;

  case 48: // tipo_param: nombre_tipo MUL
#line 147 "src/parser/parser.yy"
                      {}
#line 874 "Parser.cpp"
    break;

  case 49: // tipo_param_arr: LBRACK expresion RBRACK tipo_param_arr
#line 150 "src/parser/parser.yy"
                                           {}
#line 880 "Parser.cpp"
    break;

  case 50: // tipo_param_arr: %empty
#line 151 "src/parser/parser.yy"
                {}
#line 886 "Parser.cpp"
    break;

  case 51: // bloque: LBRACE lista_sentencias RBRACE
#line 154 "src/parser/parser.yy"
                                   {}
#line 892 "Parser.cpp"
    break;

  case 52: // lista_sentencias: lista_sentencias sentencia
#line 157 "src/parser/parser.yy"
                               {}
#line 898 "Parser.cpp"
    break;

  case 54: // sentencia: decl_loc
#line 161 "src/parser/parser.yy"
             {}
#line 904 "Parser.cpp"
    break;

  case 55: // sentencia: sentencia_simple PYC
#line 162 "src/parser/parser.yy"
                           {}
#line 910 "Parser.cpp"
    break;

  case 56: // sentencia: sentencia_return PYC
#line 163 "src/parser/parser.yy"
                           {}
#line 916 "Parser.cpp"
    break;

  case 57: // sentencia: BREAK PYC
#line 164 "src/parser/parser.yy"
                {}
#line 922 "Parser.cpp"
    break;

  case 58: // sentencia: CONTINUE PYC
#line 165 "src/parser/parser.yy"
                   {}
#line 928 "Parser.cpp"
    break;

  case 59: // sentencia: bloque
#line 166 "src/parser/parser.yy"
             {}
#line 934 "Parser.cpp"
    break;

  case 60: // sentencia: sentencia_if
#line 167 "src/parser/parser.yy"
                   {}
#line 940 "Parser.cpp"
    break;

  case 61: // sentencia: sentencia_switch
#line 168 "src/parser/parser.yy"
                       {}
#line 946 "Parser.cpp"
    break;

  case 62: // sentencia: sentencia_for
#line 169 "src/parser/parser.yy"
                    {}
#line 952 "Parser.cpp"
    break;

  case 63: // sentencia: PRINT expresion PYC
#line 170 "src/parser/parser.yy"
                          {}
#line 958 "Parser.cpp"
    break;

  case 64: // sentencia: READ ID PYC
#line 171 "src/parser/parser.yy"
                  {}
#line 964 "Parser.cpp"
    break;

  case 65: // decl_loc: VAR nombre_tipo MUL lista_id
#line 174 "src/parser/parser.yy"
                                 {}
#line 970 "Parser.cpp"
    break;

  case 66: // decl_loc: VAR STRUCT ID lista_id
#line 175 "src/parser/parser.yy"
                             {}
#line 976 "Parser.cpp"
    break;

  case 67: // decl_loc: VAR nombre_tipo tipo_arreglo lista_id
#line 176 "src/parser/parser.yy"
                                            {}
#line 982 "Parser.cpp"
    break;

  case 68: // sentencia_simple: expresion
#line 179 "src/parser/parser.yy"
              {}
#line 988 "Parser.cpp"
    break;

  case 69: // sentencia_simple: incdec
#line 180 "src/parser/parser.yy"
             {}
#line 994 "Parser.cpp"
    break;

  case 70: // sentencia_simple: asig
#line 181 "src/parser/parser.yy"
           {}
#line 1000 "Parser.cpp"
    break;

  case 71: // asig: izq op_asig expresion
#line 184 "src/parser/parser.yy"
                          {}
#line 1006 "Parser.cpp"
    break;

  case 72: // incdec: expresion INCR
#line 187 "src/parser/parser.yy"
                   {}
#line 1012 "Parser.cpp"
    break;

  case 73: // incdec: expresion DECR
#line 188 "src/parser/parser.yy"
                     {}
#line 1018 "Parser.cpp"
    break;

  case 74: // op_asig: ASIG
#line 191 "src/parser/parser.yy"
         {}
#line 1024 "Parser.cpp"
    break;

  case 75: // op_asig: SASIG
#line 192 "src/parser/parser.yy"
            {}
#line 1030 "Parser.cpp"
    break;

  case 76: // op_asig: RASIG
#line 193 "src/parser/parser.yy"
            {}
#line 1036 "Parser.cpp"
    break;

  case 77: // op_asig: PASIG
#line 194 "src/parser/parser.yy"
            {}
#line 1042 "Parser.cpp"
    break;

  case 78: // op_asig: DASIG
#line 195 "src/parser/parser.yy"
            {}
#line 1048 "Parser.cpp"
    break;

  case 79: // op_asig: MASIG
#line 196 "src/parser/parser.yy"
            {}
#line 1054 "Parser.cpp"
    break;

  case 80: // sentencia_if: IF expresion bloque
#line 199 "src/parser/parser.yy"
                        {}
#line 1060 "Parser.cpp"
    break;

  case 81: // sentencia_if: IF expresion bloque ELSE bloque
#line 200 "src/parser/parser.yy"
                                      {}
#line 1066 "Parser.cpp"
    break;

  case 82: // sentencia_switch: SWITCH sentencia_simple LBRACE expr_casos RBRACE
#line 203 "src/parser/parser.yy"
                                                     {}
#line 1072 "Parser.cpp"
    break;

  case 83: // expr_casos: expr_casos expr_caso
#line 206 "src/parser/parser.yy"
                         {}
#line 1078 "Parser.cpp"
    break;

  case 84: // expr_casos: expr_caso
#line 207 "src/parser/parser.yy"
                {}
#line 1084 "Parser.cpp"
    break;

  case 85: // expr_caso: caso COL lista_sentencias
#line 210 "src/parser/parser.yy"
                              {}
#line 1090 "Parser.cpp"
    break;

  case 86: // caso: CASE expresion
#line 213 "src/parser/parser.yy"
                   {}
#line 1096 "Parser.cpp"
    break;

  case 87: // caso: DEFAULT
#line 214 "src/parser/parser.yy"
              {}
#line 1102 "Parser.cpp"
    break;

  case 88: // sentencia_for: FOR LPAR clausula_for RPAR bloque
#line 217 "src/parser/parser.yy"
                                      {}
#line 1108 "Parser.cpp"
    break;

  case 89: // clausula_for: sentencia_simple PYC expresion PYC sentencia_simple
#line 220 "src/parser/parser.yy"
                                                        {}
#line 1114 "Parser.cpp"
    break;

  case 90: // clausula_for: expresion
#line 221 "src/parser/parser.yy"
                {}
#line 1120 "Parser.cpp"
    break;

  case 91: // sentencia_return: RETURN expresion
#line 224 "src/parser/parser.yy"
                     {}
#line 1126 "Parser.cpp"
    break;

  case 92: // sentencia_return: RETURN
#line 225 "src/parser/parser.yy"
             {}
#line 1132 "Parser.cpp"
    break;

  case 93: // izq: ID dato_miembro
#line 228 "src/parser/parser.yy"
                    {}
#line 1138 "Parser.cpp"
    break;

  case 94: // izq: ID parte_arreglo
#line 229 "src/parser/parser.yy"
                       {}
#line 1144 "Parser.cpp"
    break;

  case 95: // izq: ID llamada_funcion
#line 230 "src/parser/parser.yy"
                         {}
#line 1150 "Parser.cpp"
    break;

  case 96: // dato_miembro: DOT ID dato_miembro
#line 233 "src/parser/parser.yy"
                        {}
#line 1156 "Parser.cpp"
    break;

  case 97: // dato_miembro: %empty
#line 234 "src/parser/parser.yy"
                {}
#line 1162 "Parser.cpp"
    break;

  case 98: // parte_arreglo: LBRACK expresion RBRACK parte_arreglo
#line 237 "src/parser/parser.yy"
                                          {}
#line 1168 "Parser.cpp"
    break;

  case 99: // parte_arreglo: LBRACK expresion RBRACK
#line 238 "src/parser/parser.yy"
                              {}
#line 1174 "Parser.cpp"
    break;

  case 100: // llamada_funcion: LPAR args RPAR
#line 241 "src/parser/parser.yy"
                   {}
#line 1180 "Parser.cpp"
    break;

  case 101: // args: lista_args
#line 244 "src/parser/parser.yy"
               {}
#line 1186 "Parser.cpp"
    break;

  case 102: // args: %empty
#line 245 "src/parser/parser.yy"
                {}
#line 1192 "Parser.cpp"
    break;

  case 103: // lista_args: expresion COMA lista_args
#line 248 "src/parser/parser.yy"
                              {}
#line 1198 "Parser.cpp"
    break;

  case 104: // lista_args: expresion
#line 249 "src/parser/parser.yy"
                {}
#line 1204 "Parser.cpp"
    break;

  case 105: // expresion: expresion OR expresion
#line 252 "src/parser/parser.yy"
                           {}
#line 1210 "Parser.cpp"
    break;

  case 106: // expresion: expresion AND expresion
#line 253 "src/parser/parser.yy"
                              {}
#line 1216 "Parser.cpp"
    break;

  case 107: // expresion: expresion EQ expresion
#line 254 "src/parser/parser.yy"
                             {}
#line 1222 "Parser.cpp"
    break;

  case 108: // expresion: expresion NEQ expresion
#line 255 "src/parser/parser.yy"
                              {}
#line 1228 "Parser.cpp"
    break;

  case 109: // expresion: expresion LESS expresion
#line 256 "src/parser/parser.yy"
                               {}
#line 1234 "Parser.cpp"
    break;

  case 110: // expresion: expresion LEQ expresion
#line 257 "src/parser/parser.yy"
                              {}
#line 1240 "Parser.cpp"
    break;

  case 111: // expresion: expresion GREAT expresion
#line 258 "src/parser/parser.yy"
                                {}
#line 1246 "Parser.cpp"
    break;

  case 112: // expresion: expresion GEQ expresion
#line 259 "src/parser/parser.yy"
                              {}
#line 1252 "Parser.cpp"
    break;

  case 113: // expresion: expresion PLUS expresion
#line 260 "src/parser/parser.yy"
                               {}
#line 1258 "Parser.cpp"
    break;

  case 114: // expresion: expresion SUB expresion
#line 261 "src/parser/parser.yy"
                              {}
#line 1264 "Parser.cpp"
    break;

  case 115: // expresion: expresion MUL expresion
#line 262 "src/parser/parser.yy"
                              {}
#line 1270 "Parser.cpp"
    break;

  case 116: // expresion: expresion DIV expresion
#line 263 "src/parser/parser.yy"
                              {}
#line 1276 "Parser.cpp"
    break;

  case 117: // expresion: expresion MOD expresion
#line 264 "src/parser/parser.yy"
                              {}
#line 1282 "Parser.cpp"
    break;

  case 118: // expresion: izq
#line 265 "src/parser/parser.yy"
          {}
#line 1288 "Parser.cpp"
    break;

  case 119: // expresion: literal
#line 267 "src/parser/parser.yy"
              {}
#line 1294 "Parser.cpp"
    break;

  case 120: // expresion: LPAR expresion RPAR
#line 268 "src/parser/parser.yy"
                          {}
#line 1300 "Parser.cpp"
    break;

  case 121: // expresion: conversion
#line 269 "src/parser/parser.yy"
                 {}
#line 1306 "Parser.cpp"
    break;

  case 122: // conversion: nombre_tipo LPAR expresion RPAR
#line 272 "src/parser/parser.yy"
                                    {}
#line 1312 "Parser.cpp"
    break;

  case 123: // literal: TRUE
#line 276 "src/parser/parser.yy"
    { 
        literal l; 
        l.type = 0;
        l.data = &yystack_[0].value.as < bool > ();

        yylhs.value.as < literal > () = l;
    }
#line 1324 "Parser.cpp"
    break;

  case 124: // literal: FALSE
#line 284 "src/parser/parser.yy"
    { 
        literal l; 
        l.type = 0;
        l.data = &yystack_[0].value.as < bool > ();

        yylhs.value.as < literal > () = l;
    }
#line 1336 "Parser.cpp"
    break;

  case 125: // literal: INTV
#line 292 "src/parser/parser.yy"
    { 
        literal l; 
        l.type = 1;
        l.data = &yystack_[0].value.as < int > ();

        yylhs.value.as < literal > () = l;
    }
#line 1348 "Parser.cpp"
    break;

  case 126: // literal: F32V
#line 300 "src/parser/parser.yy"
    { 
        literal l; 
        l.type = 2;
        l.data = &yystack_[0].value.as < std::string > ();

        yylhs.value.as < literal > () = l;
    }
#line 1360 "Parser.cpp"
    break;

  case 127: // literal: F64V
#line 308 "src/parser/parser.yy"
    { 
        literal l; 
        l.type = 3;
        l.data = &yystack_[0].value.as < std::string > ();

        yylhs.value.as < literal > () = l;
    }
#line 1372 "Parser.cpp"
    break;

  case 128: // literal: CHAR
#line 316 "src/parser/parser.yy"
    { 
        literal l; 
        l.type = 4;
        l.data = &yystack_[0].value.as < std::string > ();

        yylhs.value.as < literal > () = l;
    }
#line 1384 "Parser.cpp"
    break;

  case 129: // literal: STR
#line 324 "src/parser/parser.yy"
    { 
        literal l; 
        l.type = 5;
        l.data = &yystack_[0].value.as < std::string > ();

        yylhs.value.as < literal > () = l;
    }
#line 1396 "Parser.cpp"
    break;


#line 1400 "Parser.cpp"

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

  const signed char Parser::yytable_ninf_ = -91;

  const short
  Parser::yypact_[] =
  {
    -148,    19,    32,  -148,   132,    90,    90,    90,    90,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
      21,    60,    18,  -148,    64,    66,    68,   -43,    90,  -148,
      17,  -148,   228,    56,  -148,    37,    67,    27,    28,    90,
      60,    16,    71,  -148,   -37,    25,  -148,  -148,  -148,  -148,
    -148,  -148,   228,    29,  -148,   279,  -148,  -148,  -148,   259,
      87,    90,   102,    30,    23,  -148,  -148,    88,    95,   228,
     228,  -148,  -148,  -148,   387,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,    59,
    -148,  -148,    84,    33,   103,  -148,   121,    12,    72,   109,
    -148,   125,  -148,    90,  -148,    76,    75,  -148,   266,   302,
    -148,   406,   453,   464,   200,   200,    58,    58,    58,    58,
     -25,   -25,  -148,  -148,  -148,  -148,   259,  -148,    90,  -148,
    -148,   228,  -148,    85,   102,  -148,  -148,  -148,  -148,   228,
      73,  -148,  -148,  -148,   325,   196,  -148,  -148,  -148,  -148,
      86,   129,   228,    91,   228,   228,   131,   138,   228,   152,
    -148,   162,  -148,  -148,   140,  -148,  -148,  -148,  -148,  -148,
     147,   267,   425,  -148,   161,    13,   348,   228,   117,   441,
    -148,  -148,   229,   163,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,   228,  -148,  -148,    60,    60,    60,
     160,   169,   127,   368,    15,  -148,  -148,   441,    17,    17,
      17,    85,   228,    85,   228,  -148,     6,  -148,   172,  -148,
     246,  -148,   441,  -148,  -148,   196,   228,   196,  -148
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       5,     0,     3,     1,     0,     0,     0,     0,     0,     4,
       6,     7,     8,     9,    32,    34,    33,    29,    30,    31,
       0,     0,    36,    25,     0,     0,     0,     0,    40,    16,
      13,    26,     0,     0,    24,     0,    10,     0,     0,    40,
       0,     0,     0,    14,    97,   129,   128,   125,   126,   127,
     123,   124,     0,    27,   118,     0,   121,   119,    28,     0,
       0,    20,    42,     0,     0,    37,    17,     0,     0,   102,
       0,    93,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
     129,    12,     0,     0,    19,    22,     0,    27,     0,    41,
      44,     0,    38,    40,    15,    97,     0,   101,   104,     0,
     120,     0,   105,   106,   107,   108,   109,   111,   110,   112,
     113,   114,   115,   116,   117,    35,     0,    18,     0,    47,
      48,     0,    46,     0,     0,    45,    39,    96,   100,     0,
      99,   122,    11,    21,     0,     0,    23,    43,   103,    98,
      50,     0,     0,     0,     0,    92,     0,     0,     0,     0,
      59,     0,    53,    54,     0,    70,    69,    60,    61,    62,
       0,   118,    68,    49,     0,    27,     0,     0,     0,    91,
      57,    58,     0,     0,    51,    52,    55,    56,    74,    75,
      76,    77,    78,    79,     0,    72,    73,     0,     0,     0,
      80,     0,     0,    68,     0,    63,    64,    71,    66,    65,
      67,     0,     0,     0,     0,    87,     0,    84,     0,    81,
       0,    88,    86,    82,    83,     0,     0,    85,    89
  };

  const short
  Parser::yypgoto_[] =
  {
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,   -39,  -148,
    -148,  -148,  -148,  -148,  -148,     1,    -3,  -148,   -79,  -148,
     -26,  -148,  -148,    57,  -148,    40,  -116,   -28,  -147,  -148,
    -143,  -148,  -148,  -148,  -148,  -148,  -148,   -18,  -148,  -148,
    -148,  -148,   -88,   107,    74,  -148,  -148,    77,   -32,  -148,
     -47
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,     4,     9,    10,    36,    11,    30,    67,
      42,    12,    93,    94,    13,    40,    53,    33,    34,    23,
      41,    98,    99,   100,   101,   132,   160,   161,   162,   163,
     164,   165,   166,   194,   167,   168,   216,   217,   218,   169,
     202,   170,    54,    71,    72,    73,   106,   107,   172,    56,
      57
  };

  const short
  Parser::yytable_[] =
  {
      55,    64,    22,    22,    22,    22,    21,    24,    25,    26,
     125,   178,    91,    63,   185,   -50,   -36,   146,    39,     3,
      74,    68,    69,   -27,    27,    22,    70,    86,    87,    88,
     -32,   214,    -2,   215,   201,    43,    22,   108,   109,   103,
     214,    43,   215,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   171,    22,    97,
     200,    58,    95,    29,   130,   198,   171,    35,   223,    37,
      31,    38,    59,   171,    66,   131,    32,   136,    65,   142,
     185,    32,    28,   228,   -32,    60,    61,    62,    75,   171,
      92,   104,   102,   127,    14,   219,   199,   221,   105,   144,
      22,    15,    16,    17,    18,    19,    14,   108,    84,    85,
      86,    87,    88,    15,    16,    17,    18,    19,    20,   126,
     176,   128,    32,   179,   129,    22,   182,   134,   135,   143,
      96,    97,   133,    14,    68,   138,    70,   171,   171,   171,
      15,    16,    17,    18,    19,   203,   145,   180,   175,   131,
     177,     5,     6,     7,   181,   183,   186,   174,   208,   209,
     210,     8,   207,   187,   197,    44,    45,    46,    47,    48,
      49,    50,    51,    15,    16,    17,    18,    19,   204,   206,
     220,   151,   222,   211,   152,   212,   153,   213,   154,   225,
     173,   147,   155,   156,   157,   158,   159,   227,   224,    44,
      45,    46,    47,    48,    49,    50,    51,    15,    16,    17,
      18,    19,   137,     0,   149,   151,   148,     0,   152,     0,
     153,    52,   154,   145,   184,     0,   155,   156,   157,   158,
     159,    44,    45,    46,    47,    48,    49,    50,    51,    15,
      16,    17,    18,    19,     0,   205,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    52,     0,   145,     0,     0,
       0,     0,   226,    90,    46,    47,    48,    49,    50,    51,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,   139,     0,     0,    52,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,   188,   189,   190,   191,   192,   193,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   140,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,   145,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,   195,   196,     0,     0,   -90,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,   110,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,     0,     0,   141,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,   195,   196,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88
  };

  const short
  Parser::yycheck_[] =
  {
      32,    40,     5,     6,     7,     8,     5,     6,     7,     8,
      89,   154,    59,    39,   161,     3,     3,   133,    61,     0,
      52,    58,    59,     5,     3,    28,    63,    52,    53,    54,
       5,    25,     0,    27,   177,    18,    39,    69,    70,    16,
      25,    18,    27,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,   145,    61,    62,
     176,     5,    61,     3,    52,    52,   154,     3,    62,     3,
      52,     3,    35,   161,     3,    63,    63,   103,    62,   126,
     227,    63,    61,   226,    59,    18,    59,    59,    59,   177,
       3,     3,    62,    60,     4,   211,   175,   213,     3,   131,
     103,    11,    12,    13,    14,    15,     4,   139,    50,    51,
      52,    53,    54,    11,    12,    13,    14,    15,    28,    35,
     152,    18,    63,   155,     3,   128,   158,    18,     3,   128,
      28,   134,    60,     4,    58,    60,    63,   225,   226,   227,
      11,    12,    13,    14,    15,   177,    61,    16,   151,    63,
      59,    19,    20,    21,    16,     3,    16,    28,   197,   198,
     199,    29,   194,    16,     3,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    61,    16,
     212,    19,   214,    23,    22,    16,    24,    60,    26,    17,
     150,   134,    30,    31,    32,    33,    34,   225,   216,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,   105,    -1,   140,    19,   139,    -1,    22,    -1,
      24,    59,    26,    61,    62,    -1,    30,    31,    32,    33,
      34,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    16,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    59,    -1,    61,    -1,    -1,
      -1,    -1,    16,     4,     5,     6,     7,     8,     9,    10,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    18,    -1,    -1,    59,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    35,    36,    37,    38,    39,    40,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    42,    43,    44,    45,    46,    47,    48,    49,    50,
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
      49,    50,    51,    52,    53,    54,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    66,    67,     0,    68,    19,    20,    21,    29,    69,
      70,    72,    76,    79,     4,    11,    12,    13,    14,    15,
      28,    80,    81,    84,    80,    80,    80,     3,    61,     3,
      73,    52,    63,    82,    83,     3,    71,     3,     3,    61,
      80,    85,    75,    18,     3,     4,     5,     6,     7,     8,
       9,    10,    59,    81,   107,   113,   114,   115,     5,    35,
      18,    59,    59,    85,    73,    62,     3,    74,    58,    59,
      63,   108,   109,   110,   113,    59,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    64,
       4,   115,     3,    77,    78,    80,    28,    81,    86,    87,
      88,    89,    62,    16,     3,     3,   111,   112,   113,   113,
      60,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,    83,    35,    60,    18,     3,
      52,    63,    90,    60,    18,     3,    85,   108,    60,    18,
      64,    60,   115,    80,   113,    61,    91,    88,   112,   109,
      64,    19,    22,    24,    26,    30,    31,    32,    33,    34,
      91,    92,    93,    94,    95,    96,    97,    99,   100,   104,
     106,   107,   113,    90,    28,    81,   113,    59,    95,   113,
      16,    16,   113,     3,    62,    93,    16,    16,    35,    36,
      37,    38,    39,    40,    98,    56,    57,     3,    52,    83,
      91,    95,   105,   113,    61,    16,    16,   113,    73,    73,
      73,    23,    16,    60,    25,    27,   101,   102,   103,    91,
     113,    91,   113,    62,   102,    17,    16,    92,    95
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    65,    66,    68,    67,    67,    69,    69,    69,    69,
      70,    71,    71,    72,    74,    73,    75,    73,    76,    77,
      77,    78,    78,    79,    80,    80,    80,    82,    81,    81,
      81,    81,    81,    81,    81,    83,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    88,    89,    89,    89,    90,
      90,    91,    92,    92,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    94,    94,    94,    95,    95,
      95,    96,    97,    97,    98,    98,    98,    98,    98,    98,
      99,    99,   100,   101,   101,   102,   103,   103,   104,   105,
     105,   106,   106,   107,   107,   107,   108,   108,   109,   109,
     110,   111,   111,   112,   112,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   114,   115,   115,   115,   115,   115,   115,   115
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     0,     3,     0,     1,     1,     1,     1,
       3,     5,     3,     3,     0,     4,     0,     3,     6,     1,
       0,     3,     1,     7,     2,     1,     2,     0,     3,     1,
       1,     1,     1,     1,     1,     4,     0,     4,     5,     4,
       0,     1,     0,     3,     1,     2,     2,     2,     2,     4,
       0,     3,     2,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     3,     3,     4,     4,     4,     1,     1,
       1,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       3,     5,     5,     2,     1,     3,     2,     1,     5,     5,
       1,     2,     1,     2,     2,     2,     3,     0,     4,     3,
       3,     1,     0,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     1,     4,     1,     1,     1,     1,     1,     1,     1
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
  "declaraciones", "$@1", "declaracion", "decl_const", "lista_id_const",
  "decl_var", "lista_id", "$@2", "$@3", "decl_proto", "lista_tipos",
  "tipos", "decl_func", "tipo", "nombre_tipo", "$@4", "tipo_arreglo",
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
       0,    66,    66,    69,    69,    70,    73,    74,    75,    76,
      79,    82,    83,    86,    89,    89,    90,    90,    93,    96,
      97,   100,   101,   104,   107,   108,   109,   112,   112,   114,
     115,   116,   117,   118,   119,   122,   123,   126,   127,   130,
     131,   134,   135,   138,   139,   142,   145,   146,   147,   150,
     151,   154,   157,   158,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   174,   175,   176,   179,   180,
     181,   184,   187,   188,   191,   192,   193,   194,   195,   196,
     199,   200,   203,   206,   207,   210,   213,   214,   217,   220,
     221,   224,   225,   228,   229,   230,   233,   234,   237,   238,
     241,   244,   245,   248,   249,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   267,
     268,   269,   272,   275,   283,   291,   299,   307,   315,   323
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
#line 1926 "Parser.cpp"

#line 332 "src/parser/parser.yy"


void yy::Parser::error(const std::string &err_message)
{
    cerr << "Error: " << err_message << " at " << lexer.lineno() << " with token " << lexer.YYText() << endl;
}
