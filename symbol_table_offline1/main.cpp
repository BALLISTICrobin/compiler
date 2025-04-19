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

bool isOnlyWhitespace(const std::string& str) {
    return std::all_of(str.begin(), str.end(), [](unsigned char ch) {
        return std::isspace(ch);
    });
}

int main(int argc, char const *argv[])
{
    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);

    string line;
    int numBuckets;

    getline(infile, line);
    numBuckets = stoi(line);

    SymbolTable st(numBuckets,1, outfile);
    int cmdCount = 1;

    while (getline(infile, line)) {
        if (line.empty()) continue;
        outfile << "Cmd " << cmdCount++ << ": " << line << "\n";

        istringstream iss(line);
        string cmd, name, type;
        iss >> cmd;

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
            st.EnterScope();
        } else if (cmd == "E") {
            st.ExitScope();
        } else if (cmd == "P") {
            string subcmd;
            iss >> subcmd;
            if (subcmd == "A") st.printAllScopes(outfile);
            else if (subcmd == "C") st.printCurrentScope(outfile);
        } else if (cmd == "Q") {
            st.~SymbolTable();
        }
    }

    infile.close();
    outfile.close();

    return 0;
}
