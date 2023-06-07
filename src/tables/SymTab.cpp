#include "SymTab.hpp"

Symbol::Symbol() {}
Symbol::Symbol(int dir, int type, string cat) 
{
    this -> dir = dir;
    this -> type = type;
    this -> cat = cat;
}
Symbol::~Symbol() {}

SymTab::SymTab() {}
SymTab::~SymTab() {}
void SymTab::addSymbol(string id, int dir, int type, string cat)
{
    if (!has(id))
    {
        symbols[id] = Symbol(dir, type, cat);
    }
}
int SymTab::getDir(string id) 
{
    return symbols[id].dir;
}
int SymTab::getType(string id)
{
    return symbols[id].type;
}
bool SymTab::has(string id)
{
    return symbols.find(id) != symbols.end();
}
map<string, Symbol> SymTab::unwrap() {
    return symbols;
}