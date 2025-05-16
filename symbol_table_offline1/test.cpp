#include <iostream>
#include <sstream>
#include <string>
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

int main() {
    
    string name = "     ";
    istringstream iss(name);
    string token;
    iss>>token;

    cout<<token.empty() << endl;
    
    cout<<'\t'<<"hello"<<'\n';
    cout<<"world"<<'\n';
    cout<<'\t'<<"guys";
    cout<<endl;
    cout<<'\t'<<"hello"<<endl;
    return 0;
}

