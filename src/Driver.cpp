#include <iostream>
#include <fstream>
#include "Driver.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include "Quad.hpp"

Driver::Driver(string filename) {
    filebuf fb;
    fb.open(filename, ios::in);
    istream in(&fb);
    
    Lexer lexer(&in);
    parser = new yy::Parser(lexer, *this);
};


Driver::~Driver() {
    delete (parser);
    parser = nullptr;
}

string Driver::newLabel() {
    labels.push_back(icode.size());
    return "L" + to_string(labels.size());
}

string Driver::newTmp() {
    return "t" + numTemp++;
}

void Driver::parse() {
    parser->parse();
}

void Driver::pushQuad(Quad q) {
    icode.push_back(q);
}

void Driver::pushQuad(OPERATOR op, string arg1, string arg2, string res) {
    Quad q = Quad(op, arg1, arg2, res);
    icode.push_back(q);
}

bool Driver::validateID(string id) {
    return ts.has(id);
}

vector<string> Driver::idVec(string id) {
    vector<string> result;
    if (ts.has(id)) {
        
    } else {
        /*error*/
    }

    return result;
}

string Driver::getICode() {
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