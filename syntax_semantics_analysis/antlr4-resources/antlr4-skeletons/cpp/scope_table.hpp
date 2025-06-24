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
    string scope_id;
    ScopeTable *parent_scope;
    unsigned int (*hash_function)(string);
    int childCount = 0;
    // int collision_count = 0;

    unsigned int getHashIndex(string name) const
    {
        unsigned int hash_value = hash_function(name);
        return hash_value % num_buckets;
    }

public:
    void increament_child(){
        childCount++;
    }

    int getChildCount(){
        return childCount;
    }
    ScopeTable(string id, int num_buckets, ScopeTable *parent_scope = nullptr, unsigned int (*hash_function)(string)=SDBMHash)
    {
        this->scope_id = id;
        this->num_buckets = num_buckets;
        this->parent_scope = parent_scope;
        this->hash_function = hash_function;
        hash_table = new SymbolInfo *[num_buckets];
        for (int i = 0; i < num_buckets; i++)
            hash_table[i] = nullptr;
        // cout << "ScopeTable with id " << scope_id << " created" << endl;
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
        // cout << "ScopeTable with id " << scope_id << " destroyed" << endl;
    }

    
    unsigned int (*getHashFunction())(string)
    {
        return hash_function;
    }

    
    string getScopeId() const
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

    SymbolInfo *insert(const string &name, const string &type, ostream &output_stream, int &collision_count)
    {
        int index = getHashIndex(name);
        SymbolInfo *entry = hash_table[index];
        SymbolInfo *cur = entry;
        SymbolInfo *prev = nullptr;

        SymbolInfo *found_entry = lookup(name, output_stream);
        if (found_entry != nullptr)
        {
            // cout << "\t\'" << name << "\' already exists in the current ScopeTable\n";
            return nullptr;
        } 
        if(entry!= nullptr)
        collision_count++;

        while(cur != nullptr)
        {
            prev = cur;
            cur = cur->getNext();
        }

        SymbolInfo *new_entry = new SymbolInfo(name, type);
        if (prev == nullptr)
        {
            hash_table[index] = new_entry;
        }
        else
        {
            prev->setNext(new_entry);
        }
         // cout << "\tInserted in ScopeTable# " << scope_id;
        return new_entry;
    }

    SymbolInfo *lookup(const string &name, ostream &output_stream)
    {
        int index = getHashIndex(name);
        SymbolInfo *entry = hash_table[index];
        int pos = 1;
        while (entry != nullptr)
        {
            if (entry->getName() == name)
            {
                //output_stream<<"< "<<name<<" : "<<entry->getType()<<" > already exists in ScopeTable# " << scope_id << " at position " << index  << ", " << pos-1 << "\n\n";
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
                // cout<< "\tDeleted" << " \'" << name << "\'" << " from ScopeTable# " << scope_id << " at position " << index + 1 << ", " << pos << "\n";
                return true;
            }
            prev = entry;
            entry = entry->getNext();
            pos++;
        }
        // cout << "\tNot found in the current ScopeTable\n";
        return false;
    }


    void print(ostream &output_stream) const
    {
        output_stream << "ScopeTable # " << scope_id << "\n";
        for (int i = 0; i < num_buckets; i++)
        {
            SymbolInfo *entry = hash_table[i];
            if (entry != nullptr)
            {
                output_stream << i << " --> ";
                while (entry != nullptr)
                {
                    cout<< entry->getName() << " ";
                    entry->print(output_stream);
                    entry = entry->getNext();
                }
                output_stream << "\n";
            }
        }
        // output_stream << "\n";
    }
};

#endif // SCOPE_TABLE_HPP