#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <iostream>
#include "scope_table.hpp"

using namespace std;

class SymbolTable
{
    ScopeTable *current_scope;
    int num_buckets;
    int current_scope_id;
    ostream &output_stream;

public:
    SymbolTable(int num_buckets, int id = 1, ostream &output_stream = cout, unsigned int (*hash_function)(string, unsigned int) = SDBMHash)
        : output_stream(output_stream)
    {
        this->num_buckets = num_buckets;
        this->current_scope_id = id;
        current_scope = new ScopeTable(id, num_buckets,nullptr, hash_function);
        // current_scope->setHashFunction(hash_function);
        output_stream << "\tScopeTable# " << current_scope->getScopeId() << " created\n";
    }

    ~SymbolTable()
    {
        while (current_scope != nullptr)
        {
            ExitScope();
        }
    }

    void EnterScope()
    {
        if (current_scope != nullptr)
        {
            current_scope_id++;
            ScopeTable *new_scope = new ScopeTable(current_scope_id, num_buckets, current_scope, current_scope->getHashFunction());
            current_scope = new_scope;
            output_stream << "\tScopeTable# " << current_scope->getScopeId() << " created\n";
        }
    }

    void ExitScope()
    {
        if (current_scope != nullptr)
        {
            ScopeTable *temp = current_scope;
            output_stream << "\tScopeTable# " << current_scope->getScopeId() << " removed\n";
            current_scope = current_scope->getParentScope();
            delete temp;
        }
    }

    bool insert(string &name, string &type)
    {
        return current_scope->insert(name, type, output_stream);
    }

    bool remove(string &name)
    {
        return current_scope->Delete(name, output_stream);
    }

    SymbolInfo *lookup(string &name)
    {
        ScopeTable *curr = current_scope;
        while (curr != nullptr)
        {
            SymbolInfo *entry = curr->lookup(name, output_stream);
            if (entry != nullptr)
            {
                return entry;
            }
            curr = curr->getParentScope();
        }
        output_stream <<"\t\'"<<name<<"\' "  << "not found in any of the ScopeTables\n";
        return nullptr;
    }

    void printCurrentScope(ostream &output_stream)
    {
        current_scope->print(output_stream);
    }
    void printAllScopes() {
        printAllScopesRecursive(current_scope, 1); // start indent level 1
    }
    void printAllScopesRecursive(ScopeTable *scope, int indent)
    {
        if (scope == nullptr)
            return;
        scope->print(output_stream, indent);
        if (scope->getParentScope())
        {
            printAllScopesRecursive(scope->getParentScope(), indent + 1);
        }
    }
};

#endif