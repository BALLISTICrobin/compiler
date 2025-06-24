#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <iostream>
#include "scope_table.hpp"

using namespace std;

class SymbolTable
{
    ScopeTable *current_scope;
    int num_buckets;
    string current_scope_id;
    ostream &output_stream;
    int collision_count = 0;
    // int num_of_scopes = 0;

public:
    SymbolTable(int num_buckets, string id = "1", ostream &output_stream = cout, unsigned int (*hash_function)(string) = SDBMHash)
        : output_stream(output_stream)
    {
        this->num_buckets = num_buckets;
        this->current_scope_id = id;
        current_scope = new ScopeTable(id, num_buckets, nullptr, hash_function);

        // current_scope->setHashFunction(hash_function);
        cout << "\tScopeTable# " << current_scope->getScopeId() << " created\n";
    }

    ~SymbolTable()
    {
        ScopeTable *curr = current_scope;
        cout << "Destroying ScopeTable #" << curr->getScopeId() << endl;
        while (curr != nullptr)
        {
            ScopeTable *prev = curr;
            curr = curr->getParentScope();
            delete prev;
        }
        current_scope = nullptr;
    }

    void EnterScope()
    {
        if (current_scope != nullptr)
        {
            current_scope->increament_child();
            int current_child = current_scope->getChildCount();
            this->current_scope_id = current_scope->getScopeId() + "." + to_string(current_child);

            ScopeTable *new_scope = new ScopeTable(this->current_scope_id, num_buckets, current_scope, current_scope->getHashFunction());
            current_scope = new_scope;
            cout << "\tScopeTable# " << current_scope->getScopeId() << " created\n";
        }
    }

    void ExitScope()
    {
        if (current_scope != nullptr)
        {
            ScopeTable *temp = current_scope;
            cout << "\tScopeTable# " << current_scope->getScopeId() << " removed\n";
            current_scope = current_scope->getParentScope();

            
            if (current_scope != nullptr)
            {
                current_scope_id = current_scope->getScopeId();
            }
            else
            {
                current_scope_id = "1"; // Or keep "1" if you want to reset to root
            }
            delete temp;
        }
    }

    SymbolInfo *insert(const string &name, const string &type)

    {
        // cout<<name<<" "<<type<<endl;
        return current_scope->insert(name, type, output_stream, collision_count);
    }

    bool remove(string &name)
    {
        return current_scope->Delete(name, output_stream);
    }

    int getCollisionCount() const
    {
        return collision_count;
    }

    double getCollisionRatio()
    {
        return (double)collision_count / num_buckets;
    }

    void resetCollisionCount()
    {
        collision_count = 0;
    }

    SymbolInfo *lookup(const string &name)
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
        // cout << "\t\'" << name << "\' " << "not found in any of the ScopeTables\n";
        return nullptr;
    }

    void printCurrentScope(ostream &output_stream)
    {
        current_scope->print(output_stream);
    }
    void printAllScopes()
    {
        ScopeTable *curr = current_scope;
        while (curr != nullptr)
        {
            curr->print(output_stream);
            curr = curr->getParentScope();
        }
        output_stream << "\n";
    }
};

#endif