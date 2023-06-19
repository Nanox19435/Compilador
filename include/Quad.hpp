#ifndef QUAD_HPP
#define QUAD_HPP

#include <string>
using namespace std;

enum OPERATOR {
    IF,
    GOTO,
    OP_OR,
    OP_AND,
    OP_EQ,
    OP_NEQ,
    OP_LESS,
    OP_LEQ,
    OP_GREAT,
    OP_GEQ,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    COPY,
    FTOI,
    ITOF,
    PRINT,
    READ,
};

class Quad
{
    private:
        OPERATOR op;
        string arg1;
        string arg2;
        string res;

        int type;

        bool mutArg1;
        bool mutArg2;
    public:
        Quad();
        Quad(OPERATOR op, string arg1, string arg2, string res);
        Quad(OPERATOR op, string arg1, bool typeArg1, string arg2, bool typeArg2, string res, int type);
        ~Quad();
        string genCode();
};
#endif