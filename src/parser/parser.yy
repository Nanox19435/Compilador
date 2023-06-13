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
%token <int> ENTERO
%token <float> F32
%token <double> F64
%token LKEY RKEY PYC COMA

%token MAS

%type declaracion
%type<std::string> valor

%start declaracion

%%
declaracion:
    valor MAS valor {
        cout << $1 << $3 << endl;
    }
    ;
valor:
    CADENA { 
        $$ = $1;
        }
    ;
%%

void yy::Parser::error(const std::string &err_message)
{
    cerr << "Error: " << err_message << " at " << lexer.lineno() << " with token " << lexer.YYText() << endl;
}