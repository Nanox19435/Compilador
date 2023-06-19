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
    types[6] = Type("char", 1);
    types[7] = Type("f32", 4);
    types[8] = Type("f64", 4);
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

int TypeTab::ttsize() {
    return types.size();
}