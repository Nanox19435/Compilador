#include <iostream>
#include <fstream>
#include "Driver.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include "Quad.hpp"

Driver::Driver(string filename)
{
    filebuf fb;
    fb.open(filename, ios::in);
    istream in(&fb);

    lexer = new Lexer(&in);
    parser = new yy::Parser(*lexer, *this);
};

Driver::~Driver()
{
    delete (parser);
    parser = nullptr;
    delete (lexer);
    lexer = nullptr;
}

string Driver::newLabel()
{
    labels.push_back(icode.size());
    return "L" + to_string(labels.size());
}

string Driver::newTmp()
{
    return "t" + numTemp++;
}

int Driver::parse()
{
    return parser->parse();
}

void Driver::pushQuad(Quad q)
{
    icode.push_back(q);
}

void Driver::pushQuad(OPERATOR op, string arg1, string arg2, string res)
{
    Quad q = Quad(op, arg1, arg2, res);
    icode.push_back(q);
}

bool Driver::validateID(string id)
{
    return ts.has(id);
}

vector<string> Driver::idVec(string id)
{
    vector<string> result;
    result.push_back(id);

    return result;
}

void Driver::addSym(string id, int type, string cat)
{
    if (ts.has(id))
    {
        /*error*/
    }
    else
    {
        ts.addSymbol(id, type, cat);
    }
}

string Driver::getICode()
{
    string code = "";
    int lab = 0;
    bool b = false;
    int size = icode.size();
    for (int i = 0; i < size; i++)
    {
        Quad instruction = icode[i];

        if (i < labels[lab])
        {
            ++lab;
        }
        else if (i == labels[lab])
        {
            code += "L" + to_string(lab) + ": ";
            b = true;
            lab++;
        }
        else if (b)
        {
            code += "    ";
        }

        code += instruction.genCode() + "\n";
    }

    return code;
}

void Driver::asigOp(OPERATOR op, expresion a, expresion b)
{
    if (a.type == b.type)
    {
        string at = a.temp;
        string bt = b.temp;
        string empty = "";

        string tmp = newTmp();
        pushQuad(op, at, bt, tmp);
        pushQuad(COPY, tmp, empty, at);
    }
    else
    {
        /*error*/
    }
}

void Driver::incdec(expresion e, OPERATOR op)
{
    if (e.type == 1)
    {
        string a = e.temp;
        string one = newTmp();
        pushQuad(COPY, "1", "", one);
        string temp = newTmp();
        pushQuad(op, one, a, temp);
    }
    else
    {
        /*error*/
        error("Tipos incompatibles");
    }
}

expresion Driver::expr(expresion izq, OPERATOR op, expresion der)
{
    expresion e;
    if (izq.type == 0 && 0 == der.type)
    {
        e.type = 0;
        string a = izq.temp;
        string b = der.temp;
        e.temp = newTmp();
        pushQuad(OP_AND, a, b, e.temp);
    }
    else
    {
        /*error*/
        error("Tipos incompatibles");
    }

    return e;
}

void Driver::error(string msg)
{
    /*TODO*/
}