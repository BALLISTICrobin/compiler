parser grammar C8086Parser;

options {
    tokenVocab = C8086Lexer;
}

@header {
import java.io.BufferedWriter;
import java.io.IOException;
}

@members {
    // helper to write into parserLogFile
    void writeIntoParserLogFile(String message) {
        try {
            Main.parserLogFile.write(message);
            Main.parserLogFile.newLine();
            Main.parserLogFile.flush();
        } catch (IOException e) {
            System.err.println("Parser log error: " + e.getMessage());
        }
    }

    // helper to write into Main.errorFile
    void writeIntoErrorFile(String message) {
        try {
            Main.errorFile.write(message);
            Main.errorFile.newLine();
            Main.errorFile.flush();
        } catch (IOException e) {
            System.err.println("Error file write error: " + e.getMessage());
        }
    }
}

start
    : program
      {
        writeIntoParserLogFile(
            "Parsing completed successfully with "
            + Main.syntaxErrorCount
            + " syntax errors."
        );
      }
    ;

program
    : program unit
    | unit
    ;

unit
    : var_declaration
    | func_declaration
    | func_definition
    ;

func_declaration
    : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
    | type_specifier ID LPAREN RPAREN SEMICOLON
    ;

func_definition
    : type_specifier ID LPAREN parameter_list RPAREN compound_statement
    | type_specifier ID LPAREN RPAREN compound_statement
    ;

parameter_list
    : parameter_list COMMA type_specifier ID
    | parameter_list COMMA type_specifier
    | type_specifier ID
    | type_specifier
    ;

compound_statement
    : LCURL statements RCURL
    | LCURL RCURL
    ;

var_declaration
    : t=type_specifier dl=declaration_list sm=SEMICOLON
      {
        writeIntoParserLogFile(
            "Variable Declaration: type_specifier declaration_list "
            + $sm.getType()
            + " at line "
            + $sm.getLine()
        );
        writeIntoParserLogFile(
            "type_specifier name_line: "
            + $t.name_line
        );
      }
    | t=type_specifier de=declaration_list_err sm=SEMICOLON
      {
        writeIntoErrorFile(
            "Line# "
            + $sm.getLine()
            + " with error name: "
            + $de.error_name
            + " - Syntax error at declaration list of variable declaration"
        );
        Main.syntaxErrorCount++;
      }
    ;

declaration_list_err
    returns [String error_name]
    : { $error_name = "Error in declaration list"; }
    ;

type_specifier
    returns [String name_line]
    : INT
      {
        $name_line = "type: INT at line" + $INT.getLine();
      }
    | FLOAT
      {
        $name_line = "type: FLOAT at line" + $FLOAT.getLine();
      }
    | VOID
      {
        $name_line = "type: VOID at line" + $VOID.getLine();
      }
    ;

declaration_list
    : declaration_list COMMA ID
    | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
    | ID
    | ID LTHIRD CONST_INT RTHIRD
    ;

statements
    : statement
    | statements statement
    ;

statement
    : var_declaration
    | expression_statement
    | compound_statement
    | FOR LPAREN expression_statement expression_statement expression RPAREN statement
    | IF LPAREN expression RPAREN statement
    | IF LPAREN expression RPAREN statement ELSE statement
    | WHILE LPAREN expression RPAREN statement
    | PRINTLN LPAREN ID RPAREN SEMICOLON
    | RETURN expression SEMICOLON
    ;

expression_statement
    : SEMICOLON
    | expression SEMICOLON
    ;

variable
    : ID
    | ID LTHIRD expression RTHIRD
    ;

expression
    : logic_expression
    | variable ASSIGNOP logic_expression
    ;

logic_expression
    : rel_expression
    | rel_expression LOGICOP rel_expression
    ;

rel_expression
    : simple_expression
    | simple_expression RELOP simple_expression
    ;

simple_expression
    : term
    | simple_expression ADDOP term
    ;

term
    : unary_expression
    | term MULOP unary_expression
    ;

unary_expression
    : ADDOP unary_expression
    | NOT unary_expression
    | factor
    ;

factor
    : variable
    | ID LPAREN argument_list RPAREN
    | LPAREN expression RPAREN
    | CONST_INT
    | CONST_FLOAT
    | variable INCOP
    | variable DECOP
    ;

argument_list
    : arguments
    | /* empty */
    ;

arguments
    : arguments COMMA logic_expression
    | logic_expression
    ;
