#ifndef SCOPE_TABLE_HPP
#define SCOPE_TABLE_HPP

#include <iostream>
#include "symbol_info.hpp"
#include "hash.hpp"

using namespace std;

class ScopeTable
{
    SymbolInfo **hash_table;
    int num_buckets;
    int scope_id;
    ScopeTable *parent_scope;
    unsigned int (*hash_function)(string, unsigned int);
    // int collision_count = 0;

    unsigned int getHashIndex(string name) const
    {
        unsigned int hash_value = hash_function(name,num_buckets);
        return hash_value % num_buckets;
    }

public:
    ScopeTable(int id, int num_buckets, ScopeTable *parent_scope = nullptr, unsigned int (*hash_function)(string, unsigned int)=SDBMHash)
    {
        this->scope_id = id;
        this->num_buckets = num_buckets;
        this->parent_scope = parent_scope;
        this->hash_function = hash_function;
        hash_table = new SymbolInfo *[num_buckets];
        for (int i = 0; i < num_buckets; i++)
            hash_table[i] = nullptr;
        cout << "ScopeTable with id " << scope_id << " created" << endl;
    }

    ~ScopeTable()
    {
        for (int i = 0; i < num_buckets; i++)
        {
            SymbolInfo *entry = hash_table[i];
            while (entry != nullptr)
            {
                SymbolInfo *temp = entry;
                entry = entry->getNext();
                delete temp;
            }
        }
        delete[] hash_table;
        cout << "ScopeTable with id " << scope_id << " destroyed" << endl;
    }

    // void setHashFunction(unsigned int (*hash_function)(string, unsigned int))
    // {
    //     this->hash_function = hash_function;
    // }

    //get hash function
    unsigned int (*getHashFunction())(string, unsigned int)
    {
        return hash_function;
    }

    // create getters and setters for scope_id and parent_scope, num_buckets, hash_table
    int getScopeId() const
    {
        return scope_id;
    }
    ScopeTable *getParentScope() const
    {
        return parent_scope;
    }
    int getNumBuckets() const
    {
        return num_buckets;
    }
    SymbolInfo **getHashTable() const
    {
        return hash_table;
    }
    void setScopeId(int id)
    {
        scope_id = id;
    }
    void setParentScope(ScopeTable *parent)
    {
        parent_scope = parent;
    }
    void setNumBuckets(int num)
    {
        num_buckets = num;
    }
    void setHashTable(SymbolInfo **table)
    {
        hash_table = table;
    }

    // int getCollisionCount() const
    // {
    //     return collision_count;
    // }

    bool insert(string &name, string &type, ostream &output_stream, int &collision_count)
    {
        int index = getHashIndex(name);
        SymbolInfo *entry = hash_table[index];
        SymbolInfo *cur = entry;
        SymbolInfo *prev = nullptr;

        int pos = 1;

        

        while (cur != nullptr)
        {
            if (cur->getName() == name)
            {
                output_stream << "\t\'" << name << "\' already exists in the current ScopeTable" << endl;
                return false;
            }
            prev = cur;
            cur = cur->getNext();
            pos++;
        }
        if(entry!= nullptr)
        collision_count++;

        SymbolInfo *new_entry = new SymbolInfo(name, type);
        if (prev == nullptr)
        {
            hash_table[index] = new_entry;
        }
        else
        {
            prev->setNext(new_entry);
        }
        output_stream << "\tInserted in ScopeTable# " << scope_id << " at position " << index + 1 << ", " << pos << "\n";
        return true;
    }

    SymbolInfo *lookup(string &name, ostream &output_stream)
    {
        int index = getHashIndex(name);
        SymbolInfo *entry = hash_table[index];
        int pos = 1;
        while (entry != nullptr)
        {
            if (entry->getName() == name)
            {
                output_stream <<"\t\'"<<name<<"\' " <<"found in ScopeTable# " << scope_id << " at position " << index + 1 << ", " << pos << "\n";
                return entry;
            }
            entry = entry->getNext();
            pos++;
        }
        return nullptr;
    }

    bool Delete(string &name, ostream &output_stream)
    {
        int index = getHashIndex(name);
        SymbolInfo *entry = hash_table[index];
        SymbolInfo *prev = nullptr;
        int pos = 1;
        while (entry != nullptr)
        {
            if (entry->getName() == name)
            {
                if (prev == nullptr)
                {
                    hash_table[index] = entry->getNext();
                }
                else
                {
                    prev->setNext(entry->getNext());
                }
                delete entry;
                output_stream << "\tDeleted" << " \'" << name << "\'" << " from ScopeTable# " << scope_id << " at position " << index + 1 << ", " << pos << "\n";
                return true;
            }
            prev = entry;
            entry = entry->getNext();
            pos++;
        }
        output_stream << "\tNot found in the current ScopeTable\n";
        return false;
    }

    // input: I foo FUNCTION INT INT FLOAT INT
    // output: <foo,FUNCTION,INT<==(INT,FLOAT,INT)>

    // input: I car STRUCT INT n_doors BOOL is_electric STRING brand
    // output: <23,NUMBER> <car,STRUCT,{(INT,n_doors),(BOOL,is_electric),(STRING,brand)}>

    void print(ostream &output_stream, int indent = 1) const
    {
        string tab(indent, '\t');
        output_stream << tab << "ScopeTable# " << scope_id << "\n";
        for (int i = 0; i < num_buckets; i++)
        {
            SymbolInfo *entry = hash_table[i];
            output_stream << tab << i + 1 << "-->";
            while (entry != nullptr)
            {
                output_stream << " ";
                entry->print(output_stream);
                entry = entry->getNext();
            }
            output_stream << " \n";
        }
    }
};

#endif // SCOPE_TABLE_HPP