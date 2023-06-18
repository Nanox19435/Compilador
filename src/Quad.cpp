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
        case ADD:
            return res + " = " + arg1 + " + " + arg2;
        case SUB:
            return res + " = " + arg1 + " - " + arg2;
        case MUL:
            return res + " = " + arg1 + " * " + arg2;
        case DIV:
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