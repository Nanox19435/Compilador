#ifndef __SCANNER_HPP__
#define __SCANNER_HPP__ 1
#include "Parser.hpp"
#include <algorithm>

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

class Lexer : public yyFlexLexer
{
public:
    Lexer(std::istream *in) : yyFlexLexer(in){};

    using FlexLexer::yylex;
    virtual int yylex(yy::Parser::value_type *const lval);
    //virtual int lexwrap(yy::Parser::value_type *t);

private:
    const int ERROR = -1;
};

#endif /* END __SCANNER_H__ */