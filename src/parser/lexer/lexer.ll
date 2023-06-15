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
{FLOAT}         { 
                    string str = yytext;
                    str.erase(remove(str.begin(), str.end(), '_'), str.end());
                    lval->build<string>(str);
                    return tokens::FVAL; 
                }
{RUNA}          { 
                    string str = yytext;
					str = str.substr(1, str.size()-2);
                    lval->build<string>(str);
                    return tokens::RUNA;  
                }
{STR}           {
                    string str = yytext;
					str = str.substr(1, str.size()-2);
                    lval->build<string>(str);
                    return tokens::CADENA; 
                }
"("             { return tokens::LPAR; }
")"             { return tokens::RPAR; }
"{"             { return tokens::LBRACE; }
"}"             { return tokens::RBRACE; }
","             { return tokens::COMA; }
";"             { return tokens::PYC; }
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
"detener"       { return tokens::STOP;}
"continuar"     { return tokens::CONTINUE;}
"verdadero"     { return tokens::TRUE; }
"falso"         { return tokens::FALSE; }
"++"            { return tokens::INCR; }
"--"            { return tokens::DECR; }
"+="            { return tokens::SASIG; }
"-="            { return tokens::RASIG; }
"*="            { return tokens::PASIG; }
"/="            { return tokens::DASIG; }
"%="            { return tokens::MASIG; }
"+"             { return tokens::MAS; }
"-"             { return TOKENS::MENOS; }
"*"             { return TOKENS::MUL; }
"/"             { return TOKENS::DIV; }
"%"             { return TOKENS::MOD; }            
"||"            { return TOKENS::OR; }
"&&"            { return TOKENS::AND; }
"=="            { return TOKENS::EQ; }
"!="            { return TOKENS::NEQ; }
"<="            { return TOKENS::LEQ; }
">="            { return TOKENS::GEQ; }
"<"             { return TOKENS::LESS ;}
">"             { return TOKENS::GREAT; }
"="             { return TOKENS::ASIG; }
"!"             { return TOKENS::NEG; }
"&"             { return TOKENS::AMP; }
{ID}            { 
                    string str = yytext;
                    lval->build<string>(str);
                    return TOKENS::ID; }
.               { 
                    // TODO: implementar un sistema que aborte el análisis léxico al encontrar 10 errores.
                    cout << "Error léxico en cadena: " << yytext << " en la línea: "<< lineno();
                }
%%

int yyFlexLexer::yywrap(){
    return 1;
}