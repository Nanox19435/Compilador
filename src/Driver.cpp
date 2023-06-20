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
    ts.push_back(SymTab());

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
    string label = "L" + to_string(label_counter);
    vector<Quad>i;
    icode[label] = i; 
    return label;
}

string Driver::newTmp()
{
    return "t" + numTemp++;
}

string Driver::label(string l)
{
    vector<Quad> i;
    icode[l] = i;
    return l;
}

int Driver::parse()
{
    return parser->parse();
}

void Driver::pushQuad(Quad q)
{
    icode[current_label].push_back(q);
}

void Driver::pushQuad(OPERATOR op, string arg1, string arg2, string res)
{
    Quad q = Quad(op, arg1, arg2, res);
    icode[current_label].push_back(q);
}

void Driver::pushQuad(Quad q, string label)
{
    icode[label].push_back(q);
}

void Driver::pushQuad(OPERATOR op, string arg1, string arg2, string res, string label)
{
    Quad q = Quad(op, arg1, arg2, res);
    icode[label].push_back(q);
}

bool Driver::validateID(string id)
{
    return ts[0].has(id);
}

vector<string> Driver::idVec(string id)
{
    vector<string> result;
    result.push_back(id);

    return result;
}

void Driver::addSym(string id, int type, string cat)
{
    if (ts[0].has(id))
    {
        /*error*/
    }
    else
    {
        ts[0].addSymbol(id, type, cat);
    }
}

string Driver::getICode()
{
    string code = "";
    std::map<string, vector<Quad>>::iterator it = icode.begin();

    while (it != icode.end())
    {
        string label = it->first;
        vector<Quad> icode = it->second;

        code += label + ":\n";
        for (Quad q : icode)
        {
            code += "    " + q.genCode();
        }
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

void Driver::function(int type, string id) 
{
    if (ts[0].has(id))
    {
        /*error*/
    } else {
        SymTab s = SymTab();
        ts.push_back(s);

        string l = label(id);
        current_label = l;
    }
    
}

void Driver::error(string msg)
{
    /*TODO*/
}