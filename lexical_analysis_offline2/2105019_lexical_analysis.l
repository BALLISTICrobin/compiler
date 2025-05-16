%option c++
%option noyywrap
%option yylineno

%{
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>  // for std::count

// #include <FlexLexer.h>

#include "symbol_table.hpp"


using namespace std;

yyFlexLexer *lexer = nullptr;

ofstream tokenout;
ofstream logout;
SymbolTable *symbolTable = nullptr;
int error_count=0;

string escapeString(const string& input) {
    string result;
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == '\\' && i + 1 < input.length()) {
            switch (input[i + 1]) {
                case 'n': result += '\n'; i++; break;
                case 't': result += '\t'; i++; break;
                case '\\': result += '\\'; i++; break;
                case '\'': result += '\''; i++; break;
                case '"': result += '"'; i++; break;
                case 'a': result += '\a'; i++; break;
                case 'f': result += '\f'; i++; break;
                case 'r': result += '\r'; i++; break;
                case 'b': result += '\b'; i++; break;
                case 'v': result += '\v'; i++; break;
                case '0': result += '\0'; i++; break;
                default: result += input[i];
            }
        } else {
            result += input[i];
        }
    }
    return result;
}

string charToAscii(const string& input) {
    string escaped = escapeString(input.substr(1, input.length() - 2));
    return escaped;
}

int countNewlines(const char* str) {
    int count = 0;
    for (const char* p = str; *p; ++p) {
        if (*p == '\n') count++;
    }
    return count;
}

%}

DIGIT           [0-9]
LETTER          [a-zA-Z]
ALPHANUM        [a-zA-Z0-9_]
WHITESPACE      [ \t\r]
NEWLINE         \n
KEYWORD         (if|else|goto|for|while|long|do|break|short|int|char|static|float|double|unsigned|void|return|switch|case|default|continue)
EXPONENT        [eE][+-]?{DIGIT}+
FLOAT           ({DIGIT}*\.{DIGIT}+{EXPONENT}?|{DIGIT}+{EXPONENT})
INTEGER         {DIGIT}+
ESCAPE_SEQ      \\[nt\\'"afrbv0]
CHAR            \'([^\\\n']|{ESCAPE_SEQ})\'
STRING_CONTENT  ([^"\\\n]|{ESCAPE_SEQ})+
STRING          \"{STRING_CONTENT}*\"
MULTI_STRING    \"({STRING_CONTENT}|\\\n)*\"
IDENTIFIER      ({LETTER}|_){ALPHANUM}*
SINGLE_COMMENT  "//"[^\n]*(\\\n[^\n]*)*
MULTI_COMMENT   "/"\*([^*]|\*+[^*/])*\*+"/"
UNFINISHED_COMM "/"\*([^*]|\*+[^*/])*(\*+|\n)?
ADDOP           "+"|"-"
MULOP           "*"|"/"|"%"
INCOP           "++"|"--"
RELOP           "<="|">="|"=="|"!="|"<"|">"
ASSIGNOP        "="
LOGICOP         "&&"|"||"
NOT             "!"
LPAREN          "("
RPAREN          ")"
LCURL           "{"
RCURL           "}"
LTHIRD          "["
RTHIRD          "]"
COMMA           ","
SEMICOLON       ";"
INVALID_SUFFIX  {DIGIT}+{IDENTIFIER}
MULTI_CHAR      \'([^\\\n']|{ESCAPE_SEQ}){2,}\'
UNFINISHED_CHAR \'([^']|\\.)*(\n|$)
EMPTY_CHAR      \'\'
UNFINISHED_STR \"([^"\\\n]|{ESCAPE_SEQ}|\\\n)*$
TOO_MANY_DECIMALS {DIGIT}+(\.{DIGIT}+){2,}
ILL_FORMED      ({DIGIT}|{EXPONENT}|"\.")+
UNRECOGNIZED    .

%%

{NEWLINE}           { /* Ignore newlines */ }
{WHITESPACE}        { /* Ignore whitespace */ }

{KEYWORD} {
    string kw = string(yytext);
    for (auto &c : kw) c = toupper(c);
    logout << "Line no " << lexer->lineno() << ": Token <" << kw << "> Lexeme " << yytext << " found\n\n";
    tokenout << "<" << kw << "> ";
}

{INTEGER} {
    string lexeme = yytext;
    logout << "Line no " << lexer->lineno() << ": Token <CONST_INT> Lexeme " << lexeme << " found\n\n";
    tokenout << "<CONST_INT, " << lexeme << "> ";
    bool flag = symbolTable->insert(lexeme, "CONST_INT");
    if(flag==true) symbolTable->printAllScopes();
}

{FLOAT} {
    string lexeme = yytext;
    logout << "Line no " << lexer->lineno() << ": Token <CONST_FLOAT> Lexeme " << lexeme << " found\n\n";
    tokenout << "<CONST_FLOAT, " << lexeme << "> ";
    bool flag = symbolTable->insert(lexeme, "CONST_FLOAT");
    if(flag==true) symbolTable->printAllScopes();
}

{CHAR} {
    string lexeme = yytext;
    string ascii = charToAscii(lexeme);
    logout << "Line no " << lexer->lineno() << ": Token <CONST_CHAR> Lexeme " << lexeme 
         << " found --> <CONST_CHAR, " << ascii << ">\n\n";
    tokenout << "<CONST_CHAR, " << ascii << "> ";
    bool flag = symbolTable->insert(lexeme, "CONST_CHAR");
    if(flag) symbolTable->printAllScopes();
}

{TOO_MANY_DECIMALS} {
    logout << "Error at line no " << lexer->lineno() << ": Too many decimal points " << yytext << "\n\n\n";
    error_count++;
}

{ILL_FORMED} {
    logout << "Error at line no " << lexer->lineno() << ": Ill formed number " << yytext << "\n\n\n";
    error_count++;
}


{INVALID_SUFFIX} {
    logout << "Error at line no " << lexer->lineno() << ": Invalid prefix on ID or invalid suffix on Number " << yytext << "\n\n";
    error_count++;
}

{IDENTIFIER} {
    string lexeme = yytext;
    logout << "Line no " << lexer->lineno() << ": Token <ID> Lexeme " << lexeme << " found\n\n";
    tokenout << "<ID, " << lexeme << "> ";
    bool flag = symbolTable->insert(lexeme, "ID");
    if(flag==true) symbolTable->printAllScopes();
}

{UNFINISHED_COMM} {
    int lines = countNewlines(yytext);
    int starting_line = yylineno - lines;
    logout << "Error at line no " << starting_line << ": Unterminated comment " << yytext << "\n\n";
    error_count++;
    // Do NOT update yylineno manually — Flex does this.
}

{MULTI_COMMENT} {
    logout << "Line no " << lexer->lineno() << ": Token <COMMENT> Lexeme " << yytext << " found\n\n";
}

{SINGLE_COMMENT} {
    logout << "Line no " << lexer->lineno() << ": Token <COMMENT> Lexeme " << yytext << " found\n\n";
}


{UNFINISHED_STR} {
    int lines_in_token = countNewlines(yytext);
    int starting_line = yylineno - lines_in_token;
    logout << "Error at line no " << starting_line << ": Unterminated string " << yytext << "\n\n";
    error_count++;
}

{MULTI_CHAR} {
    logout << "Error at line no " << lexer->lineno() << ": Multi character constant error " << yytext << "\n\n\n";
    error_count++;
}

{UNFINISHED_CHAR} {
    int currentLine = lexer->lineno() - 1;
    logout << "Error at line no " << currentLine << ": Unterminated character " << yytext << "\n\n";
    error_count++;
}

{EMPTY_CHAR} {
    logout << "Error at line no " << lexer->lineno() << ": Empty character constant error " << yytext << "\n\n\n";
    error_count++;
}

{STRING} {
    string lexeme = yytext;
    string content = escapeString(lexeme.substr(1, lexeme.length() - 2));
    logout << "Line no " << lexer->lineno() << ": Token <STRING> Lexeme " << lexeme 
           << " found --> <STRING, " << content << ">\n\n";
    tokenout << "<STRING, " << content << "> ";
}

{MULTI_STRING} {
    string lexeme = yytext;
    string content;
    bool escape = false;
    for (size_t i = 1; i < lexeme.length() - 1; i++) {
        if (escape) {
            switch (lexeme[i]) {
                case 'n': content += '\n'; break;
                case 't': content += '\t'; break;
                default: content += lexeme[i];
            }
            escape = false;
        } else if (lexeme[i] == '\\') {
            if (i+1 < lexeme.length() && lexeme[i+1] == '\n') {
                i++;
            } else {
                escape = true;
            }
        } else {
            content += lexeme[i];
        }
    }
    logout << "Line no " << lexer->lineno() << ": Token <STRING> Lexeme " << lexeme 
           << " found --> <STRING, " << content << ">\n\n";
    tokenout << "<STRING, " << content << "> ";
}

{ADDOP}         { logout << "Line no " << lexer->lineno() << ": Token <ADDOP> Lexeme " << yytext << " found\n\n"; tokenout << "<ADDOP, " << yytext << "> "; }
{MULOP}         { logout << "Line no " << lexer->lineno() << ": Token <MULOP> Lexeme " << yytext << " found\n\n"; tokenout << "<MULOP, " << yytext << "> "; }
{INCOP}         { logout << "Line no " << lexer->lineno() << ": Token <INCOP> Lexeme " << yytext << " found\n\n"; tokenout << "<INCOP, " << yytext << "> "; }
{RELOP}         { logout << "Line no " << lexer->lineno() << ": Token <RELOP> Lexeme " << yytext << " found\n\n"; tokenout << "<RELOP, " << yytext << "> "; }
{ASSIGNOP}      { logout << "Line no " << lexer->lineno() << ": Token <ASSIGNOP> Lexeme " << yytext << " found\n\n"; tokenout << "<ASSIGNOP, " << yytext << "> "; }
{LOGICOP}       { logout << "Line no " << lexer->lineno() << ": Token <LOGICOP> Lexeme " << yytext << " found\n\n"; tokenout << "<LOGICOP, " << yytext << "> "; }
{NOT}           { logout << "Line no " << lexer->lineno() << ": Token <NOT> Lexeme " << yytext << " found\n\n"; tokenout << "<NOT, " << yytext << "> "; }
{LPAREN}        { logout << "Line no " << lexer->lineno() << ": Token <LPAREN> Lexeme " << yytext << " found\n\n"; tokenout << "<LPAREN, " << yytext << "> "; }
{RPAREN}        { logout << "Line no " << lexer->lineno() << ": Token <RPAREN> Lexeme " << yytext << " found\n\n"; tokenout << "<RPAREN, " << yytext << "> "; }
{LCURL}         { logout << "Line no " << lexer->lineno() << ": Token <LCURL> Lexeme " << yytext << " found\n\n"; tokenout << "<LCURL, " << yytext << "> "; symbolTable->EnterScope(); }
{RCURL}         { logout << "Line no " << lexer->lineno() << ": Token <RCURL> Lexeme " << yytext << " found\n\n"; tokenout << "<RCURL, " << yytext << "> "; symbolTable->ExitScope(); }
{LTHIRD}        { logout << "Line no " << lexer->lineno() << ": Token <LTHIRD> Lexeme " << yytext << " found\n\n"; tokenout << "<LTHIRD, " << yytext << "> "; }
{RTHIRD}        { logout << "Line no " << lexer->lineno() << ": Token <RTHIRD> Lexeme " << yytext << " found\n\n"; tokenout << "<RTHIRD, " << yytext << "> "; }
{COMMA}         { logout << "Line no " << lexer->lineno() << ": Token <COMMA> Lexeme " << yytext << " found\n\n"; tokenout << "<COMMA, " << yytext << "> "; }
{SEMICOLON}     { logout << "Line no " << lexer->lineno() << ": Token <SEMICOLON> Lexeme " << yytext << " found\n\n"; tokenout << "<SEMICOLON, " << yytext << "> "; }

{UNRECOGNIZED} {
    logout << "Error at line no " << lexer->lineno() << ": Unrecognized character " << yytext << "\n\n";
    error_count++;
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

    tokenout.open("tokens.txt");
    logout.open("log.txt");

    if (!tokenout.is_open() || !logout.is_open()) {
        cerr << "Failed to open output files\n";
        return 1;
    }

    symbolTable = new SymbolTable(7, "1", logout);
    error_count = 0;

    lexer = new yyFlexLexer(&cin);
    lexer->yylex();

    symbolTable->printAllScopes();

    cout << "Lexical analysis finished.\n";
    logout << "Total lines: " << lexer->lineno() << "\n";
    logout << "Total errors: " << error_count << "\n";

    tokenout.close();
    logout.close();

    delete lexer;
    /* symbolTable->printAllScopes(); */
    delete symbolTable;


    return 0;
}
