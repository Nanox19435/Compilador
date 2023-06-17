%require "3.8"
%language "c++"
%header "Parser.hpp"
%output "Parser.cpp"
%define api.parser.class {Parser}

%code requires{
    
    class Lexer;
    
    struct literal {
        int type;
        void* data;
    };
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

%token <std::string> ID STR CHAR
%token <int> INTV
%token <std::string> F32V F64V
%token <bool> TRUE FALSE
%token VOID BOOL INT F32 F64
%token PYC COL COMA
%nonassoc VAR CONST PROTO IF ELSE FOR CASE SWITCH DEFAULT STRUCT FUNC RETURN BREAK CONTINUE PRINT READ 

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


%type programa
%type declaraciones declaracion
%type <literal> literal 
%start programa

%%
programa:
    declaraciones {}
    ;
declaraciones: 
    declaraciones {declaracion.tipo = declaraciones.tipo} declaracion 
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
     lista_id COMA {id.tipo = L.tipo} ID
    | ID {id.tipo = lista_id.tipo} ID
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
    caso COL lista_sentencias {}
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
    ID dato_miembro {}
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
    expresion OR expresion {}
    | expresion AND expresion {}
    | expresion EQ expresion {}
    | expresion NEQ expresion {}
    | expresion LESS expresion {}
    | expresion LEQ expresion {}
    | expresion GREAT expresion {}
    | expresion GEQ expresion {}
    | expresion PLUS expresion {}
    | expresion SUB expresion {}
    | expresion MUL expresion {}
    | expresion DIV expresion {}
    | expresion MOD expresion {}
    | izq {}
    //| op_unario expr_unaria {} este está raro no sé que quieren acá
    | literal {}
    | LPAR expresion RPAR {}
    | conversion {}
    ;
conversion:
    nombre_tipo LPAR expresion RPAR {}
    ;
literal:
    TRUE 
    { 
        literal l; 
        l.type = 0;
        l.data = &$1;

        $$ = l;
    }
    | FALSE 
    { 
        literal l; 
        l.type = 0;
        l.data = &$1;

        $$ = l;
    }
    | INTV 
    { 
        literal l; 
        l.type = 1;
        l.data = &$1;

        $$ = l;
    }
    | F32V 
    { 
        literal l; 
        l.type = 2;
        l.data = &$1;

        $$ = l;
    }
    | F64V 
    { 
        literal l; 
        l.type = 3;
        l.data = &$1;

        $$ = l;
    }
    | CHAR 
    { 
        literal l; 
        l.type = 4;
        l.data = &$1;

        $$ = l;
    }
    | STR 
    { 
        literal l; 
        l.type = 5;
        l.data = &$1;

        $$ = l;
    }
    ;
%%

void yy::Parser::error(const std::string &err_message)
{
    cerr << "Error: " << err_message << " at " << lexer.lineno() << " with token " << lexer.YYText() << endl;
}
