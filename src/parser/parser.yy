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
%token LKEY RKEY PYC COMA

%left MAS

%type programa
%type declaraciones declaracion

%start programa

%%
programa:
    declaraciones {}
    ;
declaraciones: 
    declaraciones declaracion {}
    | /* empty */ {}
    ;
declaracion:
    decl_const {}
    | decl_var {}
    | decl_proto {}
    | decl_func {}
    ;
decl_const:
    CONST tipo lista_id_const {}
    ;
lista_id_const:
    lista_id_const COMA ID ASIG literal {}
    | ID ASIG literal {}
    ;
decl_var:
    VAR tipo lista_id {}
    ;
lista_id:
    lista_id COMA ID {}
    | ID {}
    ;
decl_proto:
    PROTO tipo ID LPAR lista_tipos RPAR {}
    ;
lista_tipos:
    tipos {}
    | /*empty*/ {}
    ;
tipos:
    tipos COMA tipo {}
    | tipo {}
    ;
decl_func:
    FUNC tipo ID LPAR lista_param RPAR bloque {} 
    ;
tipo:
    nombre_tipo tipo_arreglo {}
    | tipo_estructura {}
    | nombre_tipo MUL {}
    ;
nombre_tipo: //falta una producción para buscar una estructura definida por el usuario.
    nombre_tipo {}
    CHAR {}
    | INT {}
    | F32 {}
    | F64 {}
    | STR {}
    | BOOL {}
    | VOID {}
    ;
tipo_arreglo:
    LBRACK expresion RBRACK tipo_arreglo {}
    | /*empty*/ {}
    ;
tipo_estructura:
    STRUCT LBRACE decl_campo RBRACE {}
    | STRUCT ID LBRACE decl_campo RBRACE {}
    ;
decl_campo:
    tipo lista_id PYC decl_campo {}
    | /*empty*/ {}
    ;
lista_param:
    decl_params {}
    | /*empty*/ {}
    ;
decl_params:
    decl_params COMA decl_param {}
    | decl_param {}
    ;
decl_param:
    tipo_param ID {}
    ;
tipo_param:
    nombre_tipo tipo_param_arr {}
    | STRUCT ID {}
    | nombre_tipo MUL {}
    ;
tipo_param_arr:
    LBRACK expresion RBRACK tipo_param_arr {}
    | /*empty*/ {}
    ;
bloque:
    LBRACE lista_sentencias RBRACE {}
    ;
lista_sentencias:
    lista_sentencias sentencia {}
    | sentencia
    ;
sentencia:
    decl_loc {}
    | sentencia_simple PYC {}
    | sentencia_return PYC {}
    | BREAK PYC {}
    | CONTINUE PYC {}
    | bloque {}
    | sentencia_if {}
    | sentencia_switch {}
    | sentencia_for {}
    | PRINT expresion PYC {}
    | READ ID PYC {}
    ;
decl_loc:
    VAR nombre_tipo MUL lista_id {}
    | VAR STRUCT ID lista_id {}
    | VAR nombre_tipo tipo_arreglo lista_id {}
    ;
sentencia_simple:
    expresion {}
    | incdec {}
    | asig {}
    ;
asig:
    izq op_asig expresion {}
    ;
incdec:
    expresion INCR {}
    | expresion DECR {}
    ;
op_asig:
    ASIG {}
    | SASIG {}
    | RASIG {}
    | PASIG {}
    | DASIG {}
    | MASIG {}
    ;
sentencia_if:
    IF expresion bloque {}
    | IF expresion bloque ELSE bloque {}
    ;
sentencia_switch:
    SWITCH sentencia_simple LBRACE expr_casos RBRACE {}
    ;
expr_casos:
    expr_casos expr_caso {}
    | expr_caso {}
    ;
expr_caso:
    caso COLON lista_sentencias {}
    ;
caso:
    CASE expresion {}
    | DEFAULT {}
    ;
sentencia_for:
    FOR LPAR clausula_for RPAR bloque {}
    ;
clausula_for:
    sentencia_simple PYC expresion PYC sentencia_simple {}
    | expresion {}
    ;
sentencia_return: 
    RETURN expresion {}
    | RETURN {}
    ;
izq:
    ID
    | ID dato_miembro {}
    | ID parte_arreglo {}
    | ID llamada_funcion {}
    ;
dato_miembro:
    DOT ID dato_miembro {}
    | /*empty*/ {}
    ;
parte_arreglo:
    LBRACK expresion RBRACK parte_arreglo {}
    | LBRACK expresion RBRACK {}
    ;
llamada_funcion:
    LPAR args RPAR {}
    | /*empty*/
    ;
args:
    lista_args {}
    | /*empty*/ {}
    ;
lista_args:
    expresion COMA lista_args {}
    | expresion {}
    ;
expresion:
    expresion op_binario expresion {}
    | izq {}
    //| op_unario expr_unaria {} este está raro
    | literal {}
    | LPAR expresion RPAR {}
    | conversion {}
    ;
op_binario:
    OR
    | AND {}
    | EQ {}
    | NEQ {}
    | LESS {}
    | LEQ {}
    | GREAT {}
    | GEQ {}
    | SUM {}
    | SUB {}
    | MUL {}
    | DIV {}
    | MOD {}
;
conversion:
    nombre_tipo LPAR expresion RPAR {}
    ;
literal:
    INTV { $$ = $1;}
    | F32V {}
    | F64V {}
    | CADENA { $$ = $1; }
    | RUNA { $$ = $1; }
    | VERDADERO { $$ = true; }
    | FALSO { $$ = false; }
    ;
%%

void yy::Parser::error(const std::string &err_message)
{
    cerr << "Error: " << err_message << " at " << lexer.lineno() << " with token " << lexer.YYText() << endl;
}