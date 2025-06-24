%option c++
%option noyywrap
%option yylineno

%{
    #include<iostream>
    #include<string>
    #include<fstream>
    #include<stack>

    using namespace std;

    yyFlexLexer *lexer = nullptr;


    stack<string> bracket;


%}

L_FIRST         "("
L_SECOND        "{"
L_THIRD         "["

R_FIRST         ")"
R_SECOND        "}"
R_THIRD         "]"
WHITESPACE      [ \t\r]


%%
{WHITESPACE} {
    // do nothing
}
{L_FIRST}|{L_SECOND}|{L_THIRD}  {
    string brac = yytext; 
    bracket.push(brac);
}

{R_FIRST}|{R_SECOND}|{R_THIRD} {
    string top_element = bracket.top();
    bracket.pop();
    string closing_bracket = yytext; 
    if(top_element!=closing_bracket){
        cout<<"Unmatched brackets"<<endl;
        return 0;
    }
}

<<EOF>> {
    cout<<"matched"<<endl;
}


%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <source_file>\n";
        return 1;
    }

    ifstream source(argv[1]);
    if (!source.is_open()) {
        cerr << "Failed to open source file\n";
        return 1;
    }

    // Redirect input to lexer
    cin.rdbuf(source.rdbuf());


    lexer = new yyFlexLexer(&cin);
    lexer->yylex();

    /* cout<<"matched"<<endl; */

    return 0;
}
