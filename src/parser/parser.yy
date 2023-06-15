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

%define api.value.type variant
%define parse.assert

%token <std::string> ID CADENA RUNA
%token <int> INTV
%token <string> FLOAT
%token <bool> TRUE FALSE
%token LBRACE RBRACE PYC COMA

%left MAS

%type programa
%type declaraciones declaracion

%start programa

%%
programa:
    MAS {}
    ;
%%

void yy::Parser::error(const std::string &err_message)
{
    cerr << "Error: " << err_message << " at " << lexer.lineno() << " with token " << lexer.YYText() << endl;
}