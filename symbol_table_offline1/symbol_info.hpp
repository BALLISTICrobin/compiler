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
        // Detect FUNCTION
        if (type.find("FUNCTION") == 0) {
            istringstream iss(type);
            string func, returnType, token;
            iss >> func >> returnType;

            string* params = new string[10];
            int paramCount = 0;
            while (iss >> token) {
                params[paramCount++] = token;

                if (paramCount >= 10) {
                    string* newParams = new string[paramCount * 2];
                    for (int i = 0; i < paramCount; ++i) {
                        newParams[i] = params[i];
                    }
                    delete[] params;
                    params = newParams;
                }
            }

            out << "<" << name << ",FUNCTION," << returnType << "<==(";
            for (int i = 0; i < paramCount; ++i) {
                out << params[i];
                if (i + 1 < paramCount) out << ",";
            }
            out << ")>";

            //deallocate memory
            delete[] params;
        }
        // Detect STRUCT or UNION
        else if (type.find("STRUCT") == 0 || type.find("UNION") == 0) {
            istringstream iss(type);
            string kind, fieldType, fieldName;
            iss >> kind;

            string **fields = new string*[10];
            int fieldCount = 0;
            while (iss >> fieldType >> fieldName && (!fieldType.empty() && !fieldName.empty())) {
                fields[fieldCount++] = new string[2];
                fields[fieldCount-1][0] = fieldType;
                fields[fieldCount-1][1] = fieldName;
                if (fieldCount >= 10) {
                    string** newFields = new string*[fieldCount * 2];
                    for (int i = 0; i < fieldCount; ++i) {
                        newFields[i] = fields[i];
                    }
                    delete[] fields;
                    fields = newFields;
                }
            }

            out << "<" << name << "," << kind << ",{";
            for (int i = 0; i < fieldCount; ++i) {
                out << "(" << fields[i][0] << "," << fields[i][1] << ")";
                if (i + 1 < fieldCount) out << ",";
            }
            out << "}>";
            //deallocate memory
            for (int i = 0; i < fieldCount; ++i) {
                delete[] fields[i];
            }
            delete[] fields;

        }
        // Simple type
        else {
            out << "<" << name << "," << type << ">";
        }
    }

};

#endif