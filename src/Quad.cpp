#include "Quad.hpp"

Quad::Quad(OPERATOR op, string arg1, string arg2, string res) {
    this->op = op;
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->res = res;
}

Quad::Quad(OPERATOR op, string arg1, bool mutArg1, string arg2, bool mutArg2, string res, int type) {
    this->op = op;
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->res = res;
    this->type = type;
    this->mutArg1 = mutArg1;
    this->mutArg2 = mutArg2;
}

Quad::~Quad()
{
}

string Quad::genCode() {
    switch (op)
        {
        case IF:
            return "if " + arg1 + " goto " + arg2;
        case GOTO:
            return "goto " + arg1;
        case OP_OR:
            return res + " = " + arg1 + " OR " + arg2;
        case OP_AND:
            return res + " = " + arg1 + " AND " + arg2;
        case OP_EQ:
            return res + " = " + arg1 + " == " + arg2;
        case OP_NEQ:
            return res + " = " + arg1 + " ≠ " + arg2;
        case OP_LESS:
            return res + " = " + arg1 + " < " + arg2;
        case OP_LEQ:
            return res + " = " + arg1 + " ≤ " + arg2;
        case OP_GREAT:
            return res + " = " + arg1 + " > " + arg2;
        case OP_GEQ:
            return res + " = " + arg1 + " ≥ " + arg2;
        case OP_ADD:
            return res + " = " + arg1 + " + " + arg2;
        case OP_SUB:
            return res + " = " + arg1 + " - " + arg2;
        case OP_MUL:
            return res + " = " + arg1 + " * " + arg2;
        case OP_DIV:
            return res + " = " + arg1 + " / " + arg2;
        case COPY:
            return res + " = " + arg1;
        case FTOI:
            return res + " = floatToInt("+ arg1 +")";
        case ITOF:
            return res + " = intToFloat("+ arg1 +")";
        case PRINT:
            return "print " + arg1;
        case READ:
            return res + " = read";
        default:
            /*Operación inválida, manda un error que hable sobre los rayos cósmicos y un flip de bit.*/
            break;
        }
}