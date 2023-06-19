#include "SymTab.hpp"

Symbol::Symbol() {}
Symbol::Symbol(int type, string cat) 
{
    this -> type = type;
    this -> cat = cat;
}
Symbol::Symbol(int type, string cat, bool mutability)
{
    this -> type = type;
    this -> cat = cat;
}
Symbol::~Symbol() {}

SymTab::SymTab() {}
SymTab::~SymTab() {}
void SymTab::addSymbol(string id, int type, string cat)
{
    if (!has(id))
    {
        symbols[id] = Symbol(type, cat);
    }
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