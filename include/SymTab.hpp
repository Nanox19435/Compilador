#include <string>
#include <vector>
#include <map>

using namespace std;

class Symbol {
    public:
        int type;
        string cat;

    public:
        Symbol();
        Symbol(int type, string cat);
        Symbol(int type, string cat, bool mutability);
        ~Symbol();
};

class SymTab
{
private:
    map<string, Symbol> symbols;
public:
    SymTab(/* args */);
    ~SymTab();
    void addSymbol(string id, int type, string cat);
    int getDir(string id);
    int getType(string id);
    bool has(string id);
    /* Regresa true si no es una constante, false si la variable no existe o es una constante.*/
    bool isMut(string id);
    map<string, Symbol> unwrap();
};

