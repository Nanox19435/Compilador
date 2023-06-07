%{
#include <iostream>
#include <string>
using namespace std;

#include "tokens.hpp"
#include "Lexer.hpp"
%}

%option c++
%option outfile="Lexer.cpp"
%option yyclass="C_1::Lexer"

COMMENT ("//".*|"/*"([^\*]|"*"*[^"/"])*"*/")
ESP [áćéǵíḱĺḿńóṕŕśúẃýźÁĆÉǴÍḰĹḾŃÓṔŔŚÚẂÝŹäëḧïöẗüẅẍÿÄËḦÏÖÜẄẌŸñÑ]
ID ([_$a-zA-Z]|{ESP})([_$0-9a-zA-Z]|{ESP})*
INT (([0-9]("_")?)*[0-9])
FLOAT (({INT}?"."[0-9]*(("e"|"E")("+"|"-")?{INT})?)|({INT}("e"|"E")("+"|"-")?{INT}))
CHAR ({ESP}|[a-zA-Z.;\+\*\-/;=_]|\\[abfnrtv\\\'\"])
RUNA ('{CHAR}'|\"{CHAR}\")
STR (\"{CHAR}*\")
WHITESPACE [ \t\n]

%%
{WHITESPACE}    {}
{COMMENT}       {}
"\."            { return DOT; }
{INT}           { return INTV; }
{FLOAT}         { return FLOATV; }
{RUNA}          { return RUNA; }
{STR}           { return STR; }
\(              { return LPAR; }
\)              { return RPAR; }
\{              { return LCB; }
\}              { return RCB; }
","             { return COMA; }
";"             { return PYC; }
"si"            { return IF; }
"int"           { return INT; }
"var"           { return VAR; }
"const"         { return CONST; }
"para"          { return FOR; }
"sino"          { return ELSE; }
"proto"         { return PROTO; }
"ent"           { return INT; }
"dec32"         { return F32; }
"dec64"         { return F64; }
"logico"        { return BOOL; }
"sin"           { return VOID; }
"estructura"    { return STRUCT; }
"funcion"       { return FUNC; }
"predeterminado" { return DEFAULT; }
"imprimir"      { return PRINT; }
"leer"          { return READ;}          
"devolver"      { return RETURN;}
"detener"       { return STOP;}
"continuar"     { return CONTINUE;}
"verdadero"     { return TRUE; }
"falso"         { return FALSE; }
"++"            { return INCR; }
"--"            { return DECR; }
"+="            { return SASIG; }
"-="            { return RASIG; }
"*="            { return PASIG; }
"/="            { return DASIG; }
"%="            { return MASIG; }
\+              { return MAS;  }
"-"             { return MENOS; }
\*              { return MUL; }
\/              { return DIV; }
"%"             { return MOD; }            
"||"            { return OR; }
"&&"            { return AND; }
"=="            { return EQ; }
"!="            { return NEQ; }
"<="            { return LEQ; }
">="            { return GEQ; }
"<"             { return LESS ;}
">"             { return GREAT; }
"="             { return ASIG; }
"!"             { return NEG; }
"&"             { return AMP; }
{ID}            { return ID; }
%%

int yyFlexLexer::yywrap(){
    return 1;
}