#ifndef SYMBOL_INFO_HPP
#define SYMBOL_INFO_HPP

#include<iostream>
#include<sstream>

using namespace std;

class SymbolInfo {
    string name, type;
    SymbolInfo* next;

    public:
    SymbolInfo(string name, string type) {
        this->name = name;
        this->type = type;
        this->next = nullptr;
    }

    // ~SymbolInfo() {
    //     delete next;
    // }
    string getName() {
        return name;
    }
    string getType() {
        return type;
    }
    SymbolInfo* getNext() {
        return next;
    }
    void setNext(SymbolInfo* next) {
        this->next = next;
    }

    void setName(string name) {
        this->name = name;
    }
    void setType(string type) {
        this->type = type;
    }
    void print(ostream& out) const {
        out << "< " << name << " : " << type << " >";
    }

};

#endif