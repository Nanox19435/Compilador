#include <string>
#include <vector>
#include <map>

using namespace std;

class Symbol {
    public:
        int dir;
        int type;
        string cat;

    public:
        Symbol();
        Symbol(int dir, int type, string cat);
        ~Symbol();
};

class SymTab
{
private:
    map<string, Symbol> symbols;
public:
    SymTab(/* args */);
    ~SymTab();
    void addSymbol(string id, int dir, int type, string cat);
    int getDir(string id);
    int getType(string id);
    bool has(string id);
    map<string, Symbol> unwrap();
};

