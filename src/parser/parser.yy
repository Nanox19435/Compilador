%require "3.8"
%language "c++"
%header "Parser.hpp"
%output "Parser.cpp"
%define api.parser.class {Parser}

%code requires{
    #include <string>
    #include <vector>
    
    class Lexer;
    class Driver;
    
    struct literal {
        int type;
        std::string data;
    };

    struct expresion {
        int type;
        std::string temp;
    };

    struct lista_id {
        int type;
        int index;
    };
}

%parse-param { Lexer &lexer }
%parse-param { Driver &driver}

%code{
    #include <iostream>
    #include <fstream>
    using namespace std;

    #include "Lexer.hpp"
    #include "Driver.hpp"
    #include "Quad.hpp"
    #include <iterator>
    
    #define yylex lexer.yylex
}

%define api.value.type variant
%define parse.assert

%token <std::string> ID STR CHAR
%token <std::string> INTV
%token <std::string> F32V F64V
%token TRUE FALSE
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
%type <int> tipo
%type <int> nombre_tipo
%type <literal> literal 
%type <expresion> expresion 
%type <std::vector<std::string>> lista_id 
%type <std::vector<std::string>> lista_id_const
%start programa

%%
programa:
    declaraciones
    ;
declaraciones: 
    declaraciones declaracion 
    | /* empty */ 
    ;
declaracion:
    decl_const PYC
    | decl_var PYC
    | decl_proto PYC
    | decl_func 
    ;
decl_const:
    CONST tipo lista_id_const { for(string id : $3) driver.addSym(id, $2, "const"); }
    ;
lista_id_const:
    lista_id_const COMA ID ASIG literal 
    {
        std::vector<std::string> id_l = $1;
        std::vector<std::string> single = driver.idVec($3);
        id_l.insert(
            id_l.end(),
            std::make_move_iterator(single.begin()),
            std::make_move_iterator(single.end())
        );

        $$ = id_l;
    }
    | ID ASIG literal { $$ = driver.idVec($1); }
    ;
decl_var:
    VAR tipo lista_id { for(string id : $3) driver.addSym(id, $2, "var"); }
    ;
lista_id:
    lista_id COMA ID 
    {
        std::vector<std::string> id_l = $1;
        std::vector<std::string> single = driver.idVec($3);
        id_l.insert(
            id_l.end(),
            std::make_move_iterator(single.begin()),
            std::make_move_iterator(single.end())
        );

        $$ = id_l;
    }
    | ID 
    {
        $$ = driver.idVec($1);
    }
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
nombre_tipo:
    CHAR {}
    | INT { $$ = 1; }
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
    | incdec {
    	if ($1.type == 1 ) {
     	$$.type = 1 ;
        string a = $1.temp;
        string b = $2.temp;
        $$.temp = driver.newTmp();
     	if($$.){
            driver.pushQuad(INCR, a, b, $$.temp);
        }else{
        	driver.pushQuad(DECR, a, b, $$.temp);
        }
     } else {
            /*error*/
            driver.error("Tipos incompatibles"); 
        }
    }
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
    expresion OR expresion { 
        if ($1.type == 0 && 0 == $3.type) {
            $$.type = 0 ;
            string a = $1.temp;
            string b = $3.temp;
            $$.temp = driver.newTmp();
            driver.pushQuad(OP_OR, a, b, $$.temp);
        } else {
            /*error*/
        }
       }
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
    | LPAR expresion RPAR { $$ = $2; }
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
        l.data = "true";

        $$ = l;
    }
    | FALSE 
    { 
        literal l; 
        l.type = 0;
        l.data = "false";

        $$ = l;
    }
    | INTV 
    { 
        literal l; 
        l.type = 1;
        l.data = lexer.YYText();

        $$ = l;
    }
    | F32V 
    { 
        literal l; 
        l.type = 2;
        l.data = lexer.YYText();

        $$ = l;
    }
    | F64V 
    { 
        literal l; 
        l.type = 3;
        l.data = lexer.YYText();

        $$ = l;
    }
    | CHAR 
    { 
        literal l; 
        l.type = 4;
        l.data = lexer.YYText();

        $$ = l;
    }
    | STR 
    { 
        literal l; 
        l.type = 5;
        l.data = lexer.YYText();

        $$ = l;
    }
    ;
%%

void yy::Parser::error(const std::string &err_message)
{
    cerr << "Error: " << err_message << " at " << lexer.lineno() << " with token " << lexer.YYText() << endl;
}
