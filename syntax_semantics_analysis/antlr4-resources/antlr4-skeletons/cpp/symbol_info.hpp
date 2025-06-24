#ifndef SYMBOL_INFO_HPP
#define SYMBOL_INFO_HPP

#include <iostream>
using namespace std;

class SymbolInfo
{
    string name, type;
    SymbolInfo *next;

    // Additional semantic attributes
    bool isArray = false;
    int arraySize = -1;

    bool isFunction = false;
    bool isDeclared = false;
    bool isDefined = false;

    string variableType; // type for variable or return type for function

    // Parameters for function (dynamic array)
    string *paramTypes = nullptr;
    int paramCount = 0;

public:
    SymbolInfo(string name, string type)
    {
        this->name = name;
        this->type = type;
        this->next = nullptr;
    }

    ~SymbolInfo()
    {
        delete[] paramTypes;
    }

    // === Basic getters/setters ===
    string getName() { return name; }
    string getType() { return type; }
    SymbolInfo *getNext() { return next; }

    void setNext(SymbolInfo *next) { this->next = next; }
    void setName(string name) { this->name = name; }
    void setType(string type) { this->type = type; }

    // === Semantic attributes ===
    void setArray(bool flag) { isArray = flag; }
    bool getArray() const { return isArray; }

    void setArraySize(int size) { arraySize = size; }
    int getArraySize() const { return arraySize; }

    void setFunction(bool flag) { isFunction = flag; }
    bool getFunction() const { return isFunction; }

    void setDeclared(bool flag) { isDeclared = flag; }
    bool getDeclared() const { return isDeclared; }

    void setDefined(bool flag) { isDefined = flag; }
    bool getDefined() const { return isDefined; }

    void setVariableType(const string &type) { variableType = type; }
    string getVariableType() const { return variableType; }

    void setParamTypes(string *types, int count)
    {
        delete[] paramTypes;
        paramCount = count;
        paramTypes = new string[paramCount];
        for (int i = 0; i < paramCount; ++i)
        {
            paramTypes[i] = types[i];
        }
    }

    string *getParamTypes() const { return paramTypes; }
    int getParamCount() const { return paramCount; }

    void print(ostream &out) const
    {
        out << "< " << name << " : " << type << " >";
    }
};

#endif
