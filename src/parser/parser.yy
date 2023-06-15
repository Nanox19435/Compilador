%require "3.8"
%language "c++"
%header "Parser.hpp"
%output "Parser.cpp"
%define api.parser.class {Parser}

%code requires{
    
    class Lexer;
    
}

%parse-param { Lexer &lexer }

%code{
    #include <iostream>
    #include <fstream>
    using namespace std;

    #include "Lexer.hpp"
    
    #define yylex lexer.yylex
}

%define api.token.raw
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%token <std::string> ID CADENA RUNA
%token <int> INTV
%token <std::string> FVAL
%token <bool> TRUE FALSE
%token VOID BOOL INT F32 F64
%token PYC COL COMA
%nonassoc VAR CONST PROTO IF ELSE FOR CASE SWITCH DEFAULT STRUCT FUNC RETURN STOP CONTINUE PRINT READ 

%right ASIG SASIG RASIG PASIG DASIG MASIG
%right AMP

%left OR
%left AND
%left EQ NEQ
%left LESS GREAT LEQ GEQ
%left PLUS SUB
%left MUL DIV MOD
%left NEG

%left INCR DECR
%left DOT

%nonassoc LPAR RPAR LBRACE RBRACE LBRACK RBRACK


%type <std::string> programa

%start programa

%%
programa:
    PLUS { $$ = "+"; }
    ;
%%

void yy::Parser::error(const std::string &err_message)
{
    cerr << "Error: " << err_message << " at " << lexer.lineno() << " with token " << lexer.YYText() << endl;
}