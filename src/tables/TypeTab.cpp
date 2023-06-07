#include "TypeTab.hpp"

Type::Type() {}

Type::~Type() {}

Type::Type(string name, int size)
{
    this -> name = name;
    this -> size = size;
}

TypeTab::TypeTab()
{
    types[0] = Type("ent", 4); 
    types[1] = Type("dec32", 4);
    types[2] = Type("dec64", 8);
}

TypeTab::~TypeTab() {}

void TypeTab::addType(int id, string name, int size)
{
    types[id] = Type(name, size);
}

int TypeTab::getSize(int id) 
{
    return types[id].size;
}

string TypeTab::getName(int id) 
{
    return types[id].name;
}