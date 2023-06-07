#ifndef TYPETAB
#define TYPETAB

#include <map>
#include <string>
using namespace std;

class Type 
{
    public:
        string name;
        int size;
    public:
        Type();
        Type(string name, int size);
        ~Type();
};

class TypeTab
{
    private:
        map<int, Type> types;
    public:
        TypeTab();
        ~TypeTab();
        void addType(int id, string name, int size);
        void addType(int id, string name, int size, int base);
        int getSize(int id);
        string getName(int id);
};

#endif