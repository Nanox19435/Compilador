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

COMMENT (//[^\n]*|/\*([^\*]|\*+[^/])\*/)
ESP [áćéǵíḱĺḿńóṕŕśúẃýźÁĆÉǴÍḰĹḾŃÓṔŔŚÚẂÝŹäëḧïöẗüẅẍÿÄËḦÏÖÜẄẌŸñÑ]
ID ([_$a-zA-Z]|{ESP})([_$0-9a-zA-Z]|{ESP})*
INT (([0-9]("_")?)*[0-9])
FLOAT (({INT}?"."[0-9]*(("e"|"E")("+"|"-")?{INT})?)|({INT}("e"|"E")("+"|"-")?{INT}))
CHAR ({ESP}|[a-zA-Z.;\+\*\-/;=_]|\\[abfnrtv\\\'\"])
RUNA ('{CHAR}'|\"{CHAR}\")
WHITESPACE [ \t\n]

%%
{WHITESPACE}    {}
("//"[^\n]*)       { cout << "COMENTARIOOOOOO\n";}
{INT}           { return INTV; }
{FLOAT}         { return FLOATV; }
{RUNA}          { return RUNA; }
\+              { return MAS; }
"-"             { return MENOS; }
\*              { return MUL; }
\/              { return DIV; }
"="             { return ASIG; }
\(              { return LPAR; }
\)              { return RPAR; }
","             { return COMA; }
";"             { return PYC; }
"if"            { return IF; }
"int"           { return INT; }
"while"         { return FOR; }
"else"          { return ELSE; }
{ID}            { return ID; }
%%

int yyFlexLexer::yywrap(){
    return 1;
}