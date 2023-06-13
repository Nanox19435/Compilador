%require "3.8"
%language "c++"
%header "Parser.hpp"
%output "Parser.cpp"

%code requires{
    
    class Lexer;
    
}

%parse-param { Lexer &lexer }

%code{
    #include <iostream>
    #include <fstream>
    using namespace std;

    #include "Lexer.hpp"
    
    int yylex(void);
    int yyerror(const char *s);
}

%define api.value.type variant
%define parse.assert

%token <std::string> ID CADENA
%token <std::string> NUMERO
%token <std::string> RUNA 
%token INT F32 F64
%token LKEY RKEY PYC COMA

%left MAS

%type declaracion
%type<std::string> valor

%start declaracion

%%
declaracion:
    valor MAS valor {
        cout << "reconocido" << endl;
    }
    ;
valor:
    CADENA { $$ = $1; }
    ;
%%

void yy::Parser::error(const std::string &err_message)
{
    cerr << "Error: " << err_message << " at " << lexer.getLine() << " whith token " << lexer.getVal() << endl;
}