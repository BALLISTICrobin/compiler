#include "symbol_table.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include<algorithm>

using namespace std;

string trim(const string& str) {
    int start = 0;
    while (start < str.length() && isspace(str[start])) start++;

    int end = str.length();
    while (end > start && isspace(str[end - 1])) end--;

    return str.substr(start, end - start);
}

bool isOnlyWhitespace(const string& str) {
    return all_of(str.begin(), str.end(), [](unsigned char ch) {
        return isspace(ch);
    });
}

int main(int argc, char const *argv[])
{
    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);

    unsigned int (*hash_function)(string, unsigned int);
    if(argc==3){
        hash_function = SDBMHash;
    }
    else if(argc==4){
        string hashFunction = argv[3];
        if(hashFunction == "sdbm"){
            hash_function = SDBMHash;
        }else if(hashFunction == "djb2"){
            hash_function = DJB2Hash;
        }
        else if(hashFunction == "fnv"){
            hash_function = FNVHash;
        }
        
        else{
            cout << "Invalid hash function" << endl;
            return 1;
        }
    }

    string line;
    int numBuckets;

    getline(infile, line);
    numBuckets = stoi(line);

    SymbolTable st(numBuckets,1, outfile, hash_function);
    int cmdCount = 1;

    while (getline(infile, line)) {
        if (line.empty()) continue;
        outfile << "Cmd " << cmdCount++ << ": " << line << "\n";

        istringstream iss(line);
        string cmd, name, type;
        iss >> cmd;

        string extra;

        if (cmd == "I") {
            iss >> name;
            getline(iss, type);
            type = trim(type);
            if(isOnlyWhitespace(type)) {
                outfile << "\tNumber of parameters mismatch for the command I\n";
                continue;
            }
            st.insert(name, type);
        } else if (cmd == "L") {

            iss>> name;
            getline(iss, type);
            if(!isOnlyWhitespace(type)||name.empty()){
                outfile << "\tNumber of parameters mismatch for the command L\n";
                continue;
            }
            st.lookup(name);
            
        } else if (cmd == "D") {
            iss>> name;
            getline(iss, type);
            if(!isOnlyWhitespace(type)||name.empty()){
                outfile << "\tNumber of parameters mismatch for the command D\n";
                continue;
            }
            st.remove(name);
        } else if (cmd == "S") {
            getline(iss, extra);
            if(!isOnlyWhitespace(extra)||!extra.empty()){
                outfile << "\tNumber of parameters mismatch for the command S\n";
                continue;
            }
            st.EnterScope();
        } else if (cmd == "E") {
            getline(iss, extra);
            if(!isOnlyWhitespace(extra)||!extra.empty()){
                outfile << "\tNumber of parameters mismatch for the command S\n";
                continue;
            }
            st.ExitScope();
        } else if (cmd == "P") {
            string subcmd;
            iss >> subcmd;
            if (subcmd == "A") st.printAllScopes();
            else if (subcmd == "C") st.printCurrentScope(outfile);
        } else if (cmd == "Q") {
            getline(iss, extra);
            if(!isOnlyWhitespace(extra)||!extra.empty()){
                outfile << "\tNumber of parameters mismatch for the command S\n";
                continue;
            }
            st.~SymbolTable();
        }
    }

    infile.close();
    outfile.close();

    // Print the final collision count and ratio in temp.txt and first create temp.txt
    ofstream tempFile("./textFolder/temp.txt");
    if (tempFile.is_open()) {
        tempFile << "Total collisions: " << st.getCollisionCount() << "\n";
        tempFile << "Collision ratio: " << st.getCollisionRatio() << "\n";
        tempFile.close();
    } else {
        cout << "Unable to open temp.txt" << endl;
    }


    return 0;
}
