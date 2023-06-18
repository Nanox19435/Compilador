#include <iostream>
#include <fstream>
#include "Driver.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"

Driver::Driver(string filename) {
    filebuf fb;
    fb.open(filename, ios::in);
    istream in(&fb);
    
    lexer = new Lexer(&in);
    parser = new yy::Parser(*lexer);
};

void Driver::push_quad(Quad q) {
    icode.push_back(q);
}

void Driver::push_quad(OPERATOR op, string arg1, string arg2, string res) {
    Quad q = Quad(op, arg1, arg2, res);
    icode.push_back(q);
}