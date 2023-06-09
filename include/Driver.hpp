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

        vector<SymTab> ts;
        TypeTab tt;

        /* Relaciona una label con un segmento de código intermedio*/
        map<string, vector<Quad>> icode;
        string current_label;
        int label_counter = 0;

        Lexer *lexer = nullptr;
        yy::Parser *parser = nullptr;
public:

    Driver(string filename);
    ~Driver();

    //Funciones para código intermedio.
    string newIdStr();
    string newLabel();
    string label(string l);
    string newTmp();
    void setCurrentLabel(string s);

    /*Realiza el análisis semántico y sintáctico*/
    int parse();
    
    /* Agrega una nueva instrucción de 3 direcciones.*/
    void pushQuad(Quad q);
    void pushQuad(Quad q, string label);
    void pushQuad(OPERATOR op, string arg1, string arg2, string res);
    void pushQuad(OPERATOR op, string arg1, string arg2, string res, string label);
    
    /* Informa de la ocurrencia de un error léxico, como una discrepancia de tipos.*/
    void error(string msg);

    /* Valida una id, es decir, regresa si está disponible o no.*/
    bool validateID(string id);
    /* Genera un vector que contiene a la id recibida.*/
    vector<string> idVec(string id);
    /* Función para agregar un símbolo a la tabla de símbolos.*/
    void addSym(string id, int type, string cat);
    /* Regresa en forma de string el código intermedio que se generó.*/
    string getICode();

    // Acciones semánticas repetitivas:
    void asigOp(OPERATOR op, expresion a, expresion b);
    void incdec(expresion e, OPERATOR op);
    expresion expr(expresion izq, OPERATOR op, expresion der);
    void function(int type, string id);
};

#endif