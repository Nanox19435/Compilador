%{
#include <iostream>
#include <string>
using namespace std;

#include "Lexer.hpp"

#undef YY_DECL
#define YY_DECL int Lexer::yylex(yy::Parser::value_type *const lval)
using tokens = yy::Parser::token;
%}

%option c++
%option outfile="Lexer.cpp"
%option yyclass="Lexer"

COMMENT ("//".*|"/*"([^\*]|"*"*[^"/"])*"*/")
ESP [áćéǵíḱĺḿńóṕŕśúẃýźÁĆÉǴÍḰĹḾŃÓṔŔŚÚẂÝŹäëḧïöẗüẅẍÿÄËḦÏÖÜẄẌŸñÑ]
ID ([_$a-zA-Z]|{ESP})([_$0-9a-zA-Z]|{ESP})*
INT (([0-9]("_")?)*[0-9])
FLOAT (({INT}?"."[0-9]*(("e"|"E")("+"|"-")?{INT})?)|({INT}("e"|"E")("+"|"-")?{INT}))
CHAR ({ESP}|[a-zA-Z.:;\+\*\-/;=_ ¡!¿?]|\\[abfnrtv\\\'\"])
RUNA ('{CHAR}'|\"{CHAR}\")
STR (\"{CHAR}*\")
WHITESPACE [ \t\n]

%%
{WHITESPACE}    {}
{COMMENT}       {}
"\."            { return tokens::DOT; }
{INT}           {   
                    string str = yytext;
                    // removemos los guiones bajos para poder usar stoi.
                    str.erase(remove(str.begin(), str.end(), '_'), str.end());
                    int literal = stoi(str);
                    lval->build<int>(literal);
                    return tokens::INTV; 
                }
{FLOAT}"f"      { 
                    string str = yytext;
                    str.erase(remove(str.begin(), str.end(), '_'), str.end());
                    lval->build<string>(str);
                    return tokens::F32V; 
                }
{FLOAT}         { 
                    string str = yytext;
                    str.erase(remove(str.begin(), str.end(), '_'), str.end());
                    lval->build<string>(str);
                    return tokens::F64V; 
                }
{RUNA}          { 
                    string str = yytext;
					str = str.substr(1, str.size()-2);
                    lval->build<string>(str);
                    return tokens::CHAR;  
                }
{STR}           {
                    string str = yytext;
					str = str.substr(1, str.size()-2);
                    lval->build<string>(str);
                    return tokens::STR; 
                }
"("             { return tokens::LPAR; }
")"             { return tokens::RPAR; }
"{"             { return tokens::LBRACE; }
"}"             { return tokens::RBRACE; }
","             { return tokens::COMA; }
";"             { return tokens::PYC; }
":"             { return tokens::COL; }
"si"            { return tokens::IF; }
"int"           { return tokens::INT; }
"var"           { return tokens::VAR; }
"const"         { return tokens::CONST; }
"para"          { return tokens::FOR; }
"sino"          { return tokens::ELSE; }
"proto"         { return tokens::PROTO; }
"ent"           { return tokens::INT; }
"dec32"         { return tokens::F32; }
"dec64"         { return tokens::F64; }
"logico"        { return tokens::BOOL; }
"sin"           { return tokens::VOID; }
"estructura"    { return tokens::STRUCT; }
"funcion"       { return tokens::FUNC; }
"predeterminado" { return tokens::DEFAULT; }
"imprimir"      { return tokens::PRINT; }
"leer"          { return tokens::READ;}          
"devolver"      { return tokens::RETURN;}
"detener"       { return tokens::BREAK;}
"continuar"     { return tokens::CONTINUE;}
"verdadero"     { 
                    lval->build<bool>(true);
                    return tokens::TRUE; }
"falso"         { 
                    lval->build<bool>(true);
                    return tokens::FALSE; 
                }
"++"            { return tokens::INCR; }
"--"            { return tokens::DECR; }
"+="            { return tokens::SASIG; }
"-="            { return tokens::RASIG; }
"*="            { return tokens::PASIG; }
"/="            { return tokens::DASIG; }
"%="            { return tokens::MASIG; }
"+"             { return tokens::PLUS; }
"-"             { return tokens::SUB; }
"*"             { return tokens::MUL; }
"/"             { return tokens::DIV; }
"%"             { return tokens::MOD; }            
"||"            { return tokens::OR; }
"&&"            { return tokens::AND; }
"=="            { return tokens::EQ; }
"!="            { return tokens::NEQ; }
"<="            { return tokens::LEQ; }
">="            { return tokens::GEQ; }
"<"             { return tokens::LESS; }
">"             { return tokens::GREAT; }
"="             { return tokens::ASIG; }
"!"             { return tokens::NEG; }
"&"             { return tokens::AMP; }
{ID}            { 
                    string str = yytext;
                    lval->build<string>(str);
                    return tokens::ID; }
.               { 
                    // TODO: implementar un sistema que aborte el análisis léxico al encontrar 10 errores.
                    cout << "Error léxico en cadena: " << yytext << " en la línea: "<< lineno();
                }
%%

int yyFlexLexer::yywrap(){
    return 1;
}