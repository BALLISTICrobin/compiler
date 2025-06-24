lexer grammar C8086Lexer;

@header {
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
}

@members {
    void writeIntoLexLogFile(String message) {
        try {
            if (Main.lexLogFile != null) {
                Main.lexLogFile.write(message + "\n");
                Main.lexLogFile.flush();
            }
        } catch (IOException e) {
            System.err.println("Lexer log error: " + e.getMessage());
        }
    }
}

// Comments
LINE_COMMENT
    : '//' ~[\r\n]* {
        writeIntoLexLogFile("Line# " + getLine() + ": Token <SINGLE LINE COMMENT> Lexeme " + getText());
    } -> skip
    ;

BLOCK_COMMENT
    : '/*' .*? '*/' {
        writeIntoLexLogFile("Line# " + getLine() + ": Token <MULTI LINE COMMENT> Lexeme " + getText());
    } -> skip
    ;

// String
STRING
    : '"' ( '\\' . | ~["\\\r\n] )* '"' {
        writeIntoLexLogFile("Line# " + getLine() + ": Token <STRING> Lexeme " + getText());
    } -> skip
    ;

WS : [ \t\r\n\f]+ -> skip ;

// Keywords
IF : 'if' { writeIntoLexLogFile("Line# " + getLine() + ": Token <IF> Lexeme " + getText()); };
ELSE : 'else' { writeIntoLexLogFile("Line# " + getLine() + ": Token <ELSE> Lexeme " + getText()); };
FOR : 'for' { writeIntoLexLogFile("Line# " + getLine() + ": Token <FOR> Lexeme " + getText()); };
WHILE : 'while' { writeIntoLexLogFile("Line# " + getLine() + ": Token <WHILE> Lexeme " + getText()); };
PRINTLN : 'println' { writeIntoLexLogFile("Line# " + getLine() + ": Token <PRINTLN> Lexeme " + getText()); };
RETURN : 'return' { writeIntoLexLogFile("Line# " + getLine() + ": Token <RETURN> Lexeme " + getText()); };
INT : 'int' { writeIntoLexLogFile("Line# " + getLine() + ": Token <INT> Lexeme " + getText()); };
FLOAT : 'float' { writeIntoLexLogFile("Line# " + getLine() + ": Token <FLOAT> Lexeme " + getText()); };
VOID : 'void' { writeIntoLexLogFile("Line# " + getLine() + ": Token <VOID> Lexeme " + getText()); };

// Symbols
LPAREN : '(' { writeIntoLexLogFile("Line# " + getLine() + ": Token <LPAREN> Lexeme " + getText()); };
RPAREN : ')' { writeIntoLexLogFile("Line# " + getLine() + ": Token <RPAREN> Lexeme " + getText()); };
LCURL : '{' { writeIntoLexLogFile("Line# " + getLine() + ": Token <LCURL> Lexeme " + getText()); };
RCURL : '}' { writeIntoLexLogFile("Line# " + getLine() + ": Token <RCURL> Lexeme " + getText()); };
LTHIRD : '[' { writeIntoLexLogFile("Line# " + getLine() + ": Token <LTHIRD> Lexeme " + getText()); };
RTHIRD : ']' { writeIntoLexLogFile("Line# " + getLine() + ": Token <RTHIRD> Lexeme " + getText()); };
SEMICOLON : ';' { writeIntoLexLogFile("Line# " + getLine() + ": Token <SEMICOLON> Lexeme " + getText()); };
COMMA : ',' { writeIntoLexLogFile("Line# " + getLine() + ": Token <COMMA> Lexeme " + getText()); };

ADDOP : [+\-] { writeIntoLexLogFile("Line# " + getLine() + ": Token <ADDOP> Lexeme " + getText()); };
SUBOP : [+\-] { writeIntoLexLogFile("Line# " + getLine() + ": Token <SUBOP> Lexeme " + getText()); };
MULOP : [*/%] { writeIntoLexLogFile("Line# " + getLine() + ": Token <MULOP> Lexeme " + getText()); };
INCOP : '++' { writeIntoLexLogFile("Line# " + getLine() + ": Token <INCOP> Lexeme " + getText()); };
DECOP : '--' { writeIntoLexLogFile("Line# " + getLine() + ": Token <DECOP> Lexeme " + getText()); };
NOT : '!' { writeIntoLexLogFile("Line# " + getLine() + ": Token <NOT> Lexeme " + getText()); };
RELOP : '<=' | '==' | '>=' | '>' | '<' | '!=' { writeIntoLexLogFile("Line# " + getLine() + ": Token <RELOP> Lexeme " + getText());};
LOGICOP : '&&' | '||' { writeIntoLexLogFile("Line# " + getLine() + ": Token <LOGICOP> Lexeme " + getText());};
ASSIGNOP : '=' { writeIntoLexLogFile("Line# " + getLine() + ": Token <ASSIGNOP> Lexeme " + getText()); };

// Identifiers and constants
ID : [A-Za-z_][A-Za-z0-9_]* {
    writeIntoLexLogFile("Line# " + getLine() + ": Token <ID> Lexeme " + getText());
};

CONST_INT : [0-9]+ {
    writeIntoLexLogFile("Line# " + getLine() + ": Token <CONST_INT> Lexeme " + getText());
};

CONST_FLOAT
    : [0-9]+ ('.' [0-9]*)? ([Ee][+\-]? [0-9]+)? {
        writeIntoLexLogFile("Line# " + getLine() + ": Token <CONST_FLOAT> Lexeme " + getText());
    }
    | '.' [0-9]+ {
        writeIntoLexLogFile("Line# " + getLine() + ": Token <CONST_FLOAT> Lexeme " + getText());
    }
    | [0-9]+ '.' {
        writeIntoLexLogFile("Line# " + getLine() + ": Token <CONST_FLOAT> Lexeme " + getText());
    }
    ;
