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
    types[0] = Type("bool", 1);
    types[1] = Type("ent", 4); 
    types[2] = Type("dec32", 4);
    types[3] = Type("dec64", 8);
    types[4] = Type("runa", -1);
    types[5] = Type("cadena", -1);
}

TypeTab::~TypeTab() {}

void TypeTab::addType(int id, string name, int size)
{
    types[id] = Type(name, size);
}

bool TypeTab::has(int id) {
    return types.find(id) != types.end();
}

int TypeTab::getSize(int id) 
{
    return types[id].size;
}

string TypeTab::getName(int id) 
{
    return types[id].name;
}