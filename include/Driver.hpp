#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <vector>
#include <string>
#include <stack>
using namespace std;

#include "TypeTab.hpp"
#include "SymTab.hpp"
#include "Quad.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"

class Driver
{
    private:
        int numTemp = 0;
        int numStr = 0;
        int numConst = 0;

        int global_type;
        int global_dir;

        vector<Quad> icode;
        vector<int> labels;
        yy::Parser *parser = nullptr;
public:
    Driver(string flename);
    ~Driver();

    //Funciones para código intermedio.
    string newIdStr();
    string newLabel();
    string newTmp();

    /*Realiza el análisis semántico y sintáctico*/
    void parse();
    
    /* Agrega una nueva instrucción de 3 direcciones.*/
    void push_quad(Quad q);
    void push_quad(OPERATOR op, string arg1, string arg2, string res);
    /* Informa de la ocurrencia de un error léxico, como una discrepancia de tipos.*/
    void error(string msg);

    /* Regresa en forma de string el código intermedio que se generó.*/
    string getICode();
};

#endif