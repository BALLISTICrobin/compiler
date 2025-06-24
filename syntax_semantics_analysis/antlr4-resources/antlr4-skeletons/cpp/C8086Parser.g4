parser grammar C8086Parser;

options {
	tokenVocab = C8086Lexer;
}

@parser::header {
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
    #include "C8086Lexer.h"
	#include "symbol_table.hpp"


	extern SymbolTable* symTable;
    extern std::ofstream parserLogFile;
    extern std::ofstream errorFile;

    extern int syntaxErrorCount;
}

@parser::members {
	std::string currentVarType; // add in your parser class

    bool insertIntoTable=true;

    void writeIntoparserLogFile(const std::string message) {
        if (!parserLogFile) {
            std::cout << "Error opening parserLogFile.txt" << std::endl;
            return;
        }

        parserLogFile << message << std::endl;
        parserLogFile.flush();
    }

    void writeIntoErrorFile(const std::string message) {
        if (!errorFile) {
            std::cout << "Error opening errorFile.txt" << std::endl;
            return;
        }
        errorFile << message << std::endl;
        errorFile.flush();
    }
}

start:
	p = program {
        writeIntoparserLogFile(
            "Line " + $p.lineNo + ": start : program\n"
        );

        symTable->printAllScopes();

        writeIntoparserLogFile(
		             "Total number of lines: " + $p.lineNo + "\n" +
            "Total number of errors: " + std::to_string(syntaxErrorCount)
        );
	};

program
	returns[std::string text, std::string lineNo]:
	p = program u = unit {
        $text = $p.text + "\n" + $u.text;
        $lineNo = $u.lineNo; 
        writeIntoparserLogFile(
            "Line " + $lineNo + ": program : program unit\n\n" +
            $text + "\n"
        );
    }
	| u = unit {
        $text = $u.text;
        $lineNo = $u.lineNo;
        writeIntoparserLogFile(
            "Line " + $lineNo + ": program : unit\n\n" +
            $text + "\n"
        );
    };

unit
	returns[std::string text, std::string lineNo]:
	v = var_declaration {
        $text = $v.text;
        $lineNo = std::to_string($v.stop->getLine());
        writeIntoparserLogFile(
            "Line " + std::to_string($v.stop->getLine()) + ": unit : var_declaration\n\n" +
            $text + "\n"
        );
    }
	| f = func_declaration {
        $text = $f.text;
        $lineNo = std::to_string($f.stop->getLine());
        writeIntoparserLogFile(
            "Line " + std::to_string($f.stop->getLine()) + ": unit : func_declaration\n\n" +
            $text + "\n"
        );
    }
	| fd = func_definition {
        $text = $fd.text;
        $lineNo = $fd.lineNo;
        writeIntoparserLogFile(
            "Line " + $fd.lineNo + ": unit : func_definition\n\n" +
            $text + "\n"
        );
    };

func_declaration
	returns[std::string text]:
	t = type_specifier id = ID lp = LPAREN {
        insertIntoTable = false;
    } pl = parameter_list rp = RPAREN sc = SEMICOLON {
        $text = $t.text + " " + $id->getText() + $lp->getText() + $pl.text + $rp->getText() + $sc->getText();
		SymbolInfo* s = symTable->insert($id->getText(), "ID");
    if (s != nullptr) {
	    s->setFunction(true);
	    s->setVariableType($t.text);
	    s->setDeclared(true);
        int n = $pl.ids.size();
        string* paramTypes = new string[n];
        for (int i = 0; i < n; ++i) paramTypes[i] = $pl.ids[i].second;
        s->setParamTypes(paramTypes, n);
    }

        writeIntoparserLogFile(
            "Line " + std::to_string($t.stop->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n" +
            $text + "\n"        
        );
    }
	| t = type_specifier id = ID lp = LPAREN rp = RPAREN sc = SEMICOLON {
        $text = $t.text + " " + $id->getText() + $lp->getText() + $rp->getText() + $sc->getText();
		SymbolInfo* s = symTable->insert($id->getText(), "ID");
        if (s != nullptr) {
            s->setFunction(true);
	        s->setVariableType($t.text);
		    s->setDeclared(true);
	        s->setParamTypes(nullptr, 0);
        }

        writeIntoparserLogFile(
            "Line " + std::to_string($t.stop->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n" +
            $text + "\n"
        );
    };

func_definition
	returns[std::string text, std::vector<std::pair<std::string, std::string>> param_ids, std::string lineNo]
		:
	t = type_specifier id = ID { 
	    insertIntoTable = true;
	    SymbolInfo* sym = symTable->lookup($id->getText());
        string errorText = "";
    
    if (!sym) {
        
        sym = symTable->insert($id->getText(), "ID");
        sym->setFunction(true);
        sym->setDefined(true);
        sym->setDeclared(false);
        sym->setVariableType($t.text);
	    
    }
    
    } lp = LPAREN {
	        symTable->EnterScope();
    } pl = parameter_list rp = RPAREN {
        $param_ids = $pl.ids;
	        sym = symTable->lookup($id->getText());
	            
            if(sym->getDeclared()==false) {
	                int n = $pl.ids.size();
                string* paramTypes = new string[n];
            for (int i = 0; i < n; ++i) paramTypes[i] = $pl.ids[i].second;
                if(sym) {
                sym->setParamTypes(paramTypes, n);
                }
            }
	         
        if (!sym->getFunction()) {
            
	            writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + "\n");
            errorText = "Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + "\n";
            syntaxErrorCount++;
	            writeIntoparserLogFile(errorText);
        } else {
            
	            if (sym->getVariableType() != $t.text) {
	                writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Return type mismatch of " + $id->getText() + "\n");
                    errorText = "Error at line " + std::to_string($id->getLine()) + ": Return type mismatch of " + $id->getText() + "\n";
                syntaxErrorCount++;
	                writeIntoparserLogFile(errorText);
            }
            
	        if (sym->getParamCount() != $param_ids.size()) {
	                writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Total number of arguments mismatch with declaration in function " + $id->getText() + "\n");
                errorText = "Error at line " + std::to_string($id->getLine()) + ": Total number of arguments mismatch with declaration in function " + $id->getText() + "\n";
                syntaxErrorCount++;
	                writeIntoparserLogFile(errorText);
            } else {
                for (int i = 0; i < sym->getParamCount(); i++) {
                    if (sym->getParamTypes()[i] != $param_ids[i].second) {
                        writeIntoErrorFile("Line " + std::to_string($id->getLine()) + ": Type mismatch in parameter " + std::to_string(i+1) + " of function '" + $id->getText() + "'");
                        syntaxErrorCount++;
	                        writeIntoparserLogFile(errorText);
                    }
                }
            }
            sym->setDefined(true);
        }
    
        // sym = symTable->lookup($id->getText());
	    
	        

      } cs = compound_statement[$param_ids] {
	        
        $text = $t.text + " " + $id->getText() + $lp->getText() + $pl.text + $rp->getText() + $cs.text;
        $lineNo = $cs.lineNo;

	    sym = symTable->lookup($id->getText());

        if (sym != nullptr) {
            string expectedVarType = sym->getVariableType();
            if(expectedVarType=="void" && $cs.returnType!=""){
		            writeIntoErrorFile("Error at line " + $cs.lineNo+ ": Cannot return value from function " + $id->getText() + " with void return type.\n");
                syntaxErrorCount++;
                errorText = "Error at line " + $cs.lineNo + ": Cannot return value from function " + $id->getText() + " with void return type.\n";
                writeIntoparserLogFile(errorText);

            }
// 	        else if(expectedVarType=="int" && $cs.returnType!="int"){
// 	                writeIntoErrorFile("Error at line " + $cs.lineNo
//  + ": Cannot return value from function " + $id->getText() + " with int return type\n");
//                 syntaxErrorCount++;

                
//             }

// 	        else if(expectedVarType=="float" && $cs.returnType!="float"){
// 	                writeIntoErrorFile("Error at line " + $cs.lineNo
//  + ": Cannot return value from function " + $id->getText() + " with float return type\n");
//                 syntaxErrorCount++;
                
//             }
        }
        
        writeIntoparserLogFile(
            "Line " + $cs.lineNo + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n" +
            $text + "\n"
        );


    }
	| t = type_specifier id = ID { 
	        SymbolInfo* sym = symTable->lookup($id->getText());
            string errorText = "";
    
    if (sym != nullptr) {
        if (!sym->getFunction()) {
		            writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of" + $id->getText() + "\n");
            errorText = "Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + "\n";
            syntaxErrorCount++;
	            writeIntoparserLogFile(errorText);
        } else if (sym->getDefined()) {
            writeIntoErrorFile("Line " + std::to_string($id->getLine()) + ": Function '" + $id->getText() + "' is already defined");
            errorText = "Line " + std::to_string($id->getLine()) + ": Function '" + $id->getText() + "' is already defined\n";
            syntaxErrorCount++;
	            writeIntoparserLogFile(errorText);
        } else {
            if (sym->getVariableType() != $t.text || sym->getParamCount() > 0) {
                writeIntoErrorFile("Line " + std::to_string($id->getLine()) + ": Function definition mismatch with declaration for '" + $id->getText() + "'");
                errorText = "Line " + std::to_string($id->getLine()) + ": Function definition mismatch with declaration for '" + $id->getText() + "'\n";
                syntaxErrorCount++;
	                writeIntoparserLogFile(errorText);
            }
            sym->setDefined(true);
        }
    } else {
        sym = symTable->insert($id->getText(), "ID");
        sym->setFunction(true);
        sym->setDefined(true);
        sym->setVariableType($t.text);
	    sym->setParamTypes(nullptr, 0);
    }
	    
    } lp = LPAREN {
            symTable->EnterScope();
    } rp = RPAREN {
        $param_ids = {};

	
	    } cs = compound_statement[$param_ids] {
        $text = $t.text + " " + $id->getText() + $lp->getText() + $rp->getText() + $cs.text;
		      $lineNo = $cs.lineNo;   

	    sym = symTable->lookup($id->getText());

        if (sym != nullptr) {
            string expectedVarType = sym->getVariableType();
		            cout<<$id->getText()<<" "<<expectedVarType<<endl;
            if(expectedVarType=="void" && $cs.returnType!=""){
		            writeIntoErrorFile("Error at line " + $cs.lineNo + ": Cannot return value from function " + $id->getText() + " with void return type.\n");
                syntaxErrorCount++;
                errorText = "Error at line " + $cs.lineNo + ": Cannot return value from function " + $id->getText() + " with void return type.\n";
                writeIntoparserLogFile(errorText);

            }
	        // else if(expectedVarType=="int" && $cs.returnType!="int"){
	        //         writeIntoErrorFile("Error at line " + $cs.lineNo + ": Cannot return value from function " + $id->getText() + " with int return type\n");
            //     syntaxErrorCount++;
                
            // }

	        // else if(expectedVarType=="float" && $cs.returnType!="float"){
	        //        writeIntoErrorFile("Error at line " + $cs.lineNo + ": Cannot return value from function " + $id->getText() + " with float return type\n");
            //     syntaxErrorCount++;
                
            // }
        }
        writeIntoparserLogFile(
	            "Line " + $cs.lineNo + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n" +
            $text + "\n"
        );
    };

parameter_list
	returns[std::string text, std::vector<std::pair<std::string, std::string>> ids]:
	pl = parameter_list cm = COMMA ts = type_specifier id = ID {
        string errorText = "";
        $ids = $pl.ids;
	    $ids.push_back({ $id->getText(), $ts.text });
        $text = $pl.text + $cm->getText() + $ts.text +" "+ $id->getText();

	    
        
        if(insertIntoTable) {
           
	        SymbolInfo* s = symTable->insert($id->getText(), "ID");
            if (s != nullptr) {
	            s->setVariableType($ts.text);
	               
            }
            else{
			        writeIntoErrorFile("Error at line " + std::to_string($ts.stop->getLine())
                     + ": Multiple declaration of " + $id->getText() + " in parameter\n");
                    errorText = "Error at line " + std::to_string($ts.stop->getLine())
                     + ": Multiple declaration of " + $id->getText() + " in parameter\n";
                syntaxErrorCount++;
                writeIntoparserLogFile(errorText);
            }
    }
	    writeIntoparserLogFile(
            "Line " + std::to_string($pl.stop->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID\n\n" +
            $text + "\n"
        );
        
    }
	| pl = parameter_list cm = COMMA ts = type_specifier {
	    $ids = $pl.ids;
        $ids.push_back({ "", $ts.text });

        $text = $pl.text + $cm->getText() + $ts.text;
        writeIntoparserLogFile(
            "Line " + std::to_string($pl.stop->getLine()) + ": parameter_list : parameter_list COMMA type_specifier\n\n" +
            $text + "\n"
        );
    }
	| ts = type_specifier id = ID {
        string errorText = "";
	    $ids = { { $id->getText(), $ts.text } };
        $text = $ts.text + " " + $id->getText();
	    
        if(insertIntoTable) {
	        SymbolInfo* s = symTable->insert($id->getText(), "ID");
            if (s != nullptr) {
	            s->setVariableType($ts.text);
	                
            }
            else{
			        writeIntoErrorFile("Error at line " + std::to_string($ts.stop->getLine()

) + ": Multiple declaration of " + $id->getText() + " in parameter\n");
                errorText = "Error at line " + std::to_string($ts.stop->getLine()

) + ": Multiple declaration of " + $id->getText() + " in parameter\n";
                syntaxErrorCount++;
                writeIntoparserLogFile(errorText);
            }
    }
	    writeIntoparserLogFile(
            "Line " + std::to_string($ts.stop->getLine()) + ": parameter_list : type_specifier ID\n\n" +
            $text + "\n"
        );
        
    }
	| ts = type_specifier {
	    $ids = { { "", $ts.text } };

        $text = $ts.text;
        writeIntoparserLogFile(
            "Line " + std::to_string($ts.stop->getLine()) + ": parameter_list : type_specifier\n\n" +
            $text + "\n"
        );
    }
|
ts = type_specifier ip = invalid_param {
    $ids = { { "", $ts.text } };
    $text = $ts.text;

    writeIntoparserLogFile(
        "Line " + std::to_string($ts.stop->getLine()) + ": parameter_list : type_specifier\n\n" +
        $text + "\n"
    );

    writeIntoparserLogFile(
        "Error at line " + std::to_string($ip.start->getLine()) +
        ": syntax error, unexpected " + $ip.name + ", expecting RPAREN or COMMA\n"
    );

    writeIntoErrorFile(
        "Error at line " + std::to_string($ip.start->getLine()) +
        ": syntax error, unexpected " + $ip.name + ", expecting RPAREN or COMMA\n"
    );

    syntaxErrorCount++;
};

invalid_param
	returns[std::string name]:
	ADDOP {
        $name = "ADDOP";
    }
	| MULOP {
        $name = "MULOP";
    }
	| RELOP {
        $name = "RELOP";
    }
	| ASSIGNOP {
        $name = "ASSIGNOP";
    }
	| LOGICOP { 
        $name = "LOGICOP";
    }
	| NOT { 
        $name = "NOT";
    };

compound_statement[std::vector<std::pair<std::string, std::string>> param_ids]
	returns[std::string text, std::string lineNo, std::string returnType]:
	lc = LCURL (st = statements)? rc = RCURL {
	$returnType = "";
$text = $lc->getText() + "\n";

if ($st.ctx != nullptr) {
    $text += $st.text;
    $returnType = $st.returnType;
}

$text += "\n" + $rc->getText();
$lineNo = std::to_string($rc->getLine());

writeIntoparserLogFile(
    "Line " + $lineNo + ": compound_statement : LCURL statements RCURL\n\n" +
    $text + "\n"
);

symTable->printAllScopes();
symTable->ExitScope();

    };

var_declaration
	returns[std::string text]:
	t = type_specifier {
	        currentVarType= $t.text;
    } dl = declaration_list sm = SEMICOLON {
        $text = $t.text + " " + $dl.text + $sm->getText();
        string errorText = "";

        if($t.text == "void") {
            writeIntoErrorFile(
	                "Error at line " + std::to_string($t.stop->getLine()) + ": Variable type cannot be void\n"
            );
            syntaxErrorCount++;
            errorText = "Error at line " + std::to_string($t.stop->getLine()) + ": Variable type cannot be void\n\n";
        }
        
        writeIntoparserLogFile(
            "Line " + std::to_string($sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON\n\n" +
            errorText +
			$text + "\n"
        );

	    //     for (auto &decl : $dl.ids) {
        //     std::string name = decl.first;

        //     SymbolInfo* sym = symTable->lookup(name);
        //     if (sym != nullptr) {
        //         sym->setVariableType($t.text);
        //     }
        // }

		
    }
	| t = type_specifier de = declaration_list_err sm = SEMICOLON {
        $text = $t.text + " " + $de.error_name + $sm->getText();
        
        writeIntoErrorFile(
            "Line " + std::to_string($sm->getLine()) + ": var_declaration : type_specifier declaration_list_err SEMICOLON\n\n" +
			$text + "\n"
        );

        syntaxErrorCount++;
    };

declaration_list_err
	returns[std::string error_name]:
	{
        $error_name = "Error in declaration list";
    };

type_specifier
	returns[std::string name_line, std::string text]:
	INT {
        $text = $INT->getText();
        $name_line = "Line " + std::to_string($INT->getLine()) + ": type_specifier : INT\n\n" + $text + "\n";
        writeIntoparserLogFile($name_line);
    }
	| FLOAT {
        $text = $FLOAT->getText();
        $name_line = "Line " + std::to_string($FLOAT->getLine()) + ": type_specifier : FLOAT\n\n" + $text + "\n";
        writeIntoparserLogFile($name_line);
    }
	| VOID {
        $text = $VOID->getText();
        $name_line = "Line " + std::to_string($VOID->getLine()) + ": type_specifier : VOID\n\n" + $text + "\n";
        writeIntoparserLogFile($name_line);
    };

declaration_list
	returns[std::vector<std::pair<std::string, int>> ids, std::string text]:
	d1 = declaration_list cm = COMMA id = ID {
        $ids = $d1.ids;
        $ids.push_back({$id->getText(), -1});
        $text = $d1.text + $cm->getText()  + $id->getText();

		        std::string name = $id->getText();
			
			std::string type = "ID";

            SymbolInfo* sym = symTable->insert(name, type);
	
			if(!sym) {
	                writeIntoparserLogFile(
		                    "Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + name + "\n"
                );
                writeIntoErrorFile(
	                     "Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + name + "\n"
                );
                syntaxErrorCount++;
            }
	    if(sym){
	            sym->setArray(false);
	                sym->setDeclared(true);
                    sym->setVariableType(currentVarType);
		                    // cout<< $id->getText()<<" isarray "<<sym->getArray()<<endl;
        }
        
		
		writeIntoparserLogFile(
			"Line " + std::to_string($id->getLine()) + ": declaration_list : declaration_list COMMA ID\n\n" +
			$text + "\n"
		);
    }
	| d2 = declaration_list cm = COMMA id = ID lt = LTHIRD size = CONST_INT rt = RTHIRD {
        $ids = $d2.ids;
        $ids.push_back({$id->getText(), std::stoi($size->getText())});
        $text = $d2.text + $cm->getText()  + $id->getText() + $lt->getText() + $size->getText() + $rt->getText();
	             std::string name = $id->getText();
				
			std::string type = "ID";
            SymbolInfo* sym = symTable->insert(name, type);
			if(!sym) {
	                writeIntoparserLogFile(
		                    "Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + name + "\n"
                );
                writeIntoErrorFile(
                         "Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + name + "\n"
                );
                syntaxErrorCount++;
            }
		        if(sym){
	            sym->setArray(true);
	                sym->setDeclared(true);
                    sym->setVariableType(currentVarType);
	                    // cout<< $id->getText()<<" isarray "<<sym->getArray()<<endl;
        }
        
		writeIntoparserLogFile(
			"Line " + std::to_string($id->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n" +
			$text + "\n"
		);
    }
	| id = ID {
        $ids = { { $id->getText(), -1 } };
        $text = $id->getText();
			        std::string name = $id->getText();
	
			std::string type = "ID";

	    SymbolInfo* sym = symTable->insert(name, type);
	
			if(!sym) {
	                writeIntoparserLogFile(
		                    "Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + name + "\n"
                );
	                writeIntoErrorFile(
	                     "Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + name + "\n"
                );
                syntaxErrorCount++;
            }
	    if(sym){
	            sym->setArray(false);
	                sym->setDeclared(true);
                    sym->setVariableType(currentVarType);
	                    // cout<< $id->getText()<<" isarray "<<sym->getArray()<<endl;
        }
        
		writeIntoparserLogFile(
			"Line " + std::to_string($id->getLine()) + ": declaration_list : ID\n\n" +
			$text + "\n"
		);
    }
	| id = ID lt = LTHIRD size = CONST_INT rt = RTHIRD {
        $ids = { { $id->getText(), std::stoi($size->getText()) } };
        $text = $id->getText() + $lt->getText() + $size->getText() + $rt->getText();

	        		        std::string name = $id->getText();
			
			std::string type = "ID";

            SymbolInfo* sym = symTable->insert(name, type);        
	
			if(!sym) {
	                writeIntoparserLogFile(
		                    "Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + name + "\n"
                );
	                writeIntoErrorFile(
	                     "Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + name + "\n"
                );
                syntaxErrorCount++;
            }
	    if(sym){
	            sym->setArray(true);
                    sym->setDeclared(true);
                    sym->setVariableType(currentVarType);
	                    // cout<< $id->getText()<<" isarray "<<sym->getArray()<<endl;
        }  
        
        
		writeIntoparserLogFile(
			"Line " + std::to_string($id->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n" +
			$text + "\n"
		);
    }
	| d4 = declaration_list ip = invalid_param id = ID cm = COMMA d5 = declaration_list {
        
        $ids = $d4.ids;
        $ids.insert($ids.end(), $d5.ids.begin(), $d5.ids.end());
        $text = $d4.text + $cm->getText() + $d5.text; // Skip the ADDOP and ID after it
        
        
        writeIntoErrorFile(
            "Error at line " + std::to_string($cm->getLine()) + 
		            ": syntax error, unexpected " + $ip.name + ", expecting COMMA or SEMICOLON\n"
        );
        writeIntoparserLogFile(
            "Error at line " + std::to_string($cm->getLine()) + 
                    ": syntax error, unexpected " + $ip.name + ", expecting COMMA or SEMICOLON\n"
        );
	        writeIntoparserLogFile(
	            "Line " + std::to_string($cm->getLine()) + ": declaration_list : declaration_list COMMA ID\n\n" +
            $text + "\n"
        );
        syntaxErrorCount++;
    }
	| error_recovery = . {
        
        writeIntoparserLogFile(
            "Error at line " + std::to_string($error_recovery->getLine()) + 
            ": syntax error in declaration_list, unexpected token '" + $error_recovery->getText() + "'\n"
        );
        writeIntoErrorFile(
            "Error at line " + std::to_string($error_recovery->getLine()) + 
            ": syntax error in declaration_list, unexpected token '" + $error_recovery->getText() + "'\n"
        );
        syntaxErrorCount++;
        
        // Initialize return values to avoid parser errors
        $ids = {};
        $text = "";
    };

statements
	returns[std::string text, std::string returnType]:
	st = statement {
        $text = $st.text;
        $returnType = $st.returnType;
        if($text!=""){
        writeIntoparserLogFile(
            "Line " + std::to_string($st.stop->getLine()) + ": statements : statement\n\n" +
            $text + "\n"
        );
        }
    }
	| sts = statements st = statement {
        $text = $sts.text +"\n"+ $st.text;
	    if (!$st.returnType.empty())
            $returnType = $st.returnType;
        else
            $returnType = $sts.returnType;
        writeIntoparserLogFile(
            "Line " + std::to_string($st.stop->getLine()) + ": statements : statements statement\n\n" +
            $text + "\n"
        );
    };

statement
	returns[std::string text, std::string returnType]:
	vd = var_declaration {
        $text = $vd.text;
	    $returnType = "";
        writeIntoparserLogFile(
            "Line " + std::to_string($vd.stop->getLine()) + ": statement : var_declaration\n\n" +
            $text + "\n"
        );
    }
	| es = expression_statement {
        $text = $es.text;
	        $returnType = "";
            if($text!=""){
        writeIntoparserLogFile(
            "Line " + std::to_string($es.stop->getLine()) + ": statement : expression_statement\n\n" +
            $text + "\n"
        );
            }
    }
	| {
	    std::vector<std::pair<std::string, std::string>> empty_ids;
        symTable->EnterScope();
	  } cs = compound_statement[empty_ids] {
        $text = $cs.text;
	        $returnType = "";
        writeIntoparserLogFile(
            "Line " + std::to_string($cs.stop->getLine()) + ": statement : compound_statement\n\n" +
            $text + "\n"
        );
    }
	| f = FOR lp = LPAREN es1 = expression_statement es2 = expression_statement e = expression rp =
		RPAREN st = statement {
        $text = $f->getText()  + $lp->getText() + $es1.text  + $es2.text  + $e.text + $rp->getText()  + $st.text;
	        $returnType = "";
        writeIntoparserLogFile(
            "Line " + std::to_string($st.stop->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" +
            $text + "\n"
        );
    }
	| i = IF lp = LPAREN e = expression rp = RPAREN st = statement {
        $text = $i->getText()  + $lp->getText() + $e.text + $rp->getText()  + $st.text;
	        $returnType = $st.returnType;
        writeIntoparserLogFile(
            "Line " + std::to_string($st.stop->getLine()) + ": statement : IF LPAREN expression RPAREN statement\n\n" +
            $text + "\n"
        );
    }
	| i = IF lp = LPAREN e = expression rp = RPAREN st1 = statement el = ELSE st2 = statement {
        $text = $i->getText() + $lp->getText() + $e.text + $rp->getText() + $st1.text + $el->getText()+" "  + $st2.text;
	    if (!$st1.returnType.empty() && $st1.returnType == $st2.returnType)
            $returnType = $st1.returnType;
        else
            $returnType = ""; // mismatch or one branch doesn't return
        writeIntoparserLogFile(
            "Line " + std::to_string($st2.stop->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" +
            $text + "\n"
        );
    }
	| w = WHILE lp = LPAREN e = expression rp = RPAREN st = statement {
        $text = $w->getText()  + $lp->getText() + $e.text + $rp->getText()  + $st.text;
	        $returnType = ""; // loop body might not return
        writeIntoparserLogFile(
            "Line " + std::to_string($st.stop->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" +
            $text + "\n"
        );
    }
	| p = PRINTLN lp = LPAREN id = ID rp = RPAREN sc = SEMICOLON {
        $text = $p->getText() + $lp->getText() + $id->getText() + $rp->getText() + $sc->getText();
	        $returnType = "";
        string errorText = "";
        SymbolInfo* sym = symTable->lookup($id->getText());
        if(!sym){
            writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Undeclared variable " + $id->getText() + "\n");
            syntaxErrorCount++;
            errorText = "Error at line " + std::to_string($id->getLine()) + ": Undeclared variable " + $id->getText() + "\n\n";
            // writeIntoparserLogFile(
            //     "Line " + std::to_string($sc->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n" +
            //     $text + "\n"
            // );
        }

	        writeIntoparserLogFile(
            "Line " + std::to_string($sc->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n" +
            errorText +
            $text + "\n"
        );
    }
	| r = RETURN e = expression sc = SEMICOLON {
        $text = $r->getText() + " " + $e.text + $sc->getText();
	    $returnType = $e.type;
        writeIntoparserLogFile(
            "Line " + std::to_string($sc->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" +
            $text + "\n"
        );
    };

expression_statement
	returns[std::string text]:
	sc = SEMICOLON {
        $text = $sc->getText();
        writeIntoparserLogFile(
            "Line " + std::to_string($sc->getLine()) + ": expression_statement : SEMICOLON\n\n" +
            $text + "\n"
        );
    }
|e = expression sc = SEMICOLON {
	    $text = "";
    
    std::string semicolonText = $sc->getText();
    bool semicolonMissing = (semicolonText.find("missing") != std::string::npos);

    if (semicolonMissing==false) {
	    $text = $e.text;
        $text += semicolonText;

        writeIntoparserLogFile(
            "Line " + std::to_string($e.stop->getLine()) + ": expression_statement : expression SEMICOLON\n\n" +
            $text + "\n"
        );
    }
} ;
variable
	returns[std::string text, std::string type, bool isArray, bool reallyArray, bool declared]:
	id = ID {
        $text = $id->getText();
        string errorText = "";

        SymbolInfo* sym = symTable->lookup($id->getText());
        
        if(sym!=nullptr){
	            $type = sym->getVariableType();
            $isArray = false;
            $reallyArray = sym->getArray();
            $declared = true;

	        if($reallyArray==true && $isArray==false) {
		        writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Type mismatch, " + $text + " is an array\n");
                errorText = "Error at line " + std::to_string($id->getLine()) + ": Type mismatch, " + $text + " is an array\n\n";
        syntaxErrorCount++;
    }
        }
        
        else{
	            $type = "void";
                $isArray = false;
                $reallyArray = false;
	            $declared = false;

	                writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Undeclared variable " + $id->getText()+"\n");
            errorText = "Error at line " + std::to_string($id->getLine()) + ": Undeclared variable " + $id->getText() + "\n\n";
	
            syntaxErrorCount++;
        }
        
        writeIntoparserLogFile(
            "Line " + std::to_string($id->getLine()) + ": variable : ID\n\n" + errorText +
            $text + "\n"
        );
    }
	| id = ID lt = LTHIRD e = expression rt = RTHIRD {
        $text = $id->getText() + $lt->getText() + $e.text + $rt->getText();
        

        SymbolInfo* sym = symTable->lookup($id->getText());
        string errorText = "";
        
	        if(sym!=nullptr){
	            $type = sym->getVariableType();
            $isArray = true;
            $reallyArray = sym->getArray();
	            $declared = true;

                if($isArray==true && $reallyArray==false) {
			                    writeIntoErrorFile("Error at line "+std::to_string($id->getLine()) +": "+ $id->getText()+ " not an array\n");
	            errorText = "Error at line " + std::to_string($id->getLine())+": " + $id->getText() + " not an array\n\n";
            syntaxErrorCount++;
                }
        }
        
        else{
	            $type = "void";
                $isArray = false;
                $reallyArray = false;
	                $declared = false;

	                    writeIntoErrorFile("Line " + std::to_string($id->getLine()) + ": Undeclared array '" + $id->getText() + "'");
            errorText = "Line " + std::to_string($id->getLine()) + ": Undeclared array '" + $id->getText() + "'\n\n";
            syntaxErrorCount++;
        }
        if ($e.type != "int") {
		            writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Expression inside third brackets not an integer\n");
            errorText = "Error at line " + std::to_string($id->getLine()) + ": Expression inside third brackets not an integer\n\n";
            syntaxErrorCount++;
        }

	       

        writeIntoparserLogFile(
            "Line " + std::to_string($id->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n\n" + errorText +
            $text + "\n"
        );
    };

expression
	returns[std::string text, std::string type, bool isArray]:
	le = logic_expression {
        $text = $le.text;
        $type = $le.type;
        $isArray = $le.isArray;
        writeIntoparserLogFile(
            "Line " + std::to_string($le.stop->getLine()) + ": expression : logic_expression\n\n" +
            $text + "\n"
        );
    }
	| v = variable ao = ASSIGNOP le = logic_expression {
        $text = $v.text  + $ao->getText()  + $le.text;
	        
	    string lhsType = $v.type;
        $isArray = $v.reallyArray;

        
        
        

    string rhsType = $le.type;

    string errortext="" ;

    if($v.declared == false){}

    else if (rhsType == "void") {
	        writeIntoErrorFile("Error at line " + std::to_string($v.start->getLine()) + ": Void function used in expression\n");
	        errortext = "Error at line " + std::to_string($v.start->getLine()) + ": Void function used in expression\n\n";
        syntaxErrorCount++;
    } else if (!(lhsType=="float" && rhsType=="int") && lhsType != rhsType && rhsType != "undefined") {
        writeIntoErrorFile("Error at line " + std::to_string($v.start->getLine()) + ": Type Mismatch\n" );
        errortext = "Error at line " + std::to_string($v.start->getLine()) + ": Type Mismatch\n\n";
        syntaxErrorCount++;
    }
        writeIntoparserLogFile(
            "Line " + std::to_string($v.stop->getLine()) + ": expression : variable ASSIGNOP logic_expression\n\n" + errortext +
            $text + "\n"
        );
		        $type = rhsType;
    };

logic_expression
	returns[std::string text, std::string type, bool isArray]:
	re = rel_expression {
        $text = $re.text;
        $type = $re.type;
        $isArray = $re.isArray; 
        writeIntoparserLogFile(
            "Line " + std::to_string($re.stop->getLine()) + ": logic_expression : rel_expression\n\n" +
            $text + "\n"
        );
    }
	| re1 = rel_expression lo = LOGICOP re2 = rel_expression {
        $text = $re1.text + $lo->getText() + $re2.text;
        $type = "int";
        $isArray = $re1.isArray; 
        writeIntoparserLogFile(
            "Line " + std::to_string($re1.stop->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression\n\n" +
            $text + "\n"
        );
    };

rel_expression
	returns[std::string text, std::string type, bool isArray]:
	se = simple_expression {
        $text = $se.text;
        $type = $se.type;
        $isArray = $se.isArray; 
        writeIntoparserLogFile(
            "Line " + std::to_string($se.stop->getLine()) + ": rel_expression : simple_expression\n\n" +
            $text + "\n"
        );
    }
	| se1 = simple_expression ro = RELOP se2 = simple_expression {
        $text = $se1.text + $ro->getText() + $se2.text;
        $type = "int"; 
        $isArray = $se1.isArray;
        writeIntoparserLogFile(
            "Line " + std::to_string($se1.stop->getLine()) + ": rel_expression : simple_expression RELOP simple_expression\n\n" +
            $text + "\n"
        );
    };

simple_expression
	returns[std::string text, std::string type, bool isArray]:
	t = term {
        $text = $t.text;
        $type = $t.type; 
        $isArray = $t.isArray;
        writeIntoparserLogFile(
            "Line " + std::to_string($t.stop->getLine()) + ": simple_expression : term\n\n" +
            $text + "\n"
        );
    }
	| se = simple_expression ao = ADDOP t = term {
        $text = $se.text  + $ao->getText()  + $t.text;
        $isArray = $se.isArray;
        
        if ($se.type == "float" || $t.type == "float")
            $type = "float";
        else
            $type = "int";
        writeIntoparserLogFile(
            "Line " + std::to_string($se.stop->getLine()) + ": simple_expression : simple_expression ADDOP term\n\n" +
            $text + "\n"
        );
    }
|
se = simple_expression ao = ADDOP invalid_op = ASSIGNOP se2 = simple_expression {
    
    $text = $se.text;
    $type = $se.type;
    $isArray = $se.isArray;
    
    // writeIntoparserLogFile(
    //     "Line " + std::to_string($se.stop->getLine()) + ": simple_expression : term\n\n" +
    //     $se.text + "\n"
    // );
    
    writeIntoparserLogFile(
        "Error at line " + std::to_string($invalid_op->getLine()) + ": syntax error, unexpected ASSIGNOP\n\n"
    );
    writeIntoErrorFile(
        "Error at line " + std::to_string($invalid_op->getLine()) + ": syntax error, unexpected ASSIGNOP\n"
    );
    syntaxErrorCount++;
};
term
	returns[std::string text, std::string type, bool isArray]:
	ue = unary_expression {
        $text = $ue.text;
        $type = $ue.type;
        $isArray = $ue.isArray;
        writeIntoparserLogFile(
            "Line " + std::to_string($ue.stop->getLine()) + ": term : unary_expression\n\n" +
            $text + "\n"
        );
    }
	| t = term mo = MULOP ue = unary_expression {
        $text = $t.text + $mo->getText()  + $ue.text;
        $isArray = $t.isArray;
        string errorText = "";
        if ($mo->getText() == "%") {
            if ($t.type != "int" || $ue.type != "int") {
                $type = "undefined";
                writeIntoErrorFile(
	                    "Error at line " + std::to_string($mo->getLine()) + ": Non-Integer operand on modulus operator\n"
                        
                );
                errorText = "Error at line " + std::to_string($mo->getLine()) + ": Non-Integer operand on modulus operator\n\n";
                syntaxErrorCount++;
            }

	            else if($ue.text == "0"){ 
                    $type = "undefined";
                writeIntoErrorFile(
	                        "Error at line " + std::to_string($mo->getLine()) + ": Modulus by Zero\n"
                );
                errorText = "Error at line " + std::to_string($mo->getLine()) + ": Modulus by Zero\n\n";
                syntaxErrorCount++;
                }

	       
            else
            $type = "int";
        } else if ($t.type == "float" || $ue.type == "float") {
            $type = "float";
        } 
	    else if ($t.type == "void" || $ue.type == "void") {
	            writeIntoErrorFile("Error at line " + std::to_string($t.stop->getLine()) + ": Void function used in expression\n");
                syntaxErrorCount++;
                $type = "undefined";
                errorText = "Error at line " + std::to_string($t.stop->getLine()) + ": Void function used in expression\n\n";
            }
        else {
            $type = "int";
        }

        writeIntoparserLogFile(
            "Line " + std::to_string($t.stop->getLine()) + ": term : term MULOP unary_expression\n\n" + errorText +
            $text + "\n"
        );
    };

unary_expression
	returns[std::string text, std::string type, bool isArray]:
	ao = ADDOP ue = unary_expression {
        $text = $ao->getText() + $ue.text;
        $type = $ue.type;
        $isArray = $ue.isArray;
        writeIntoparserLogFile(
            "Line " + std::to_string($ao->getLine()) + ": unary_expression : ADDOP unary_expression\n\n" +
            $text + "\n"
        );
    }
	| n = NOT ue = unary_expression {
        $text = $n->getText() + $ue.text;
        $type = "int"; 
	    $isArray = $ue.isArray;
        writeIntoparserLogFile(
            "Line " + std::to_string($n->getLine()) + ": unary_expression : NOT unary_expression\n\n" +
            $text + "\n"
        );
    }
	| f = factor {
        $text = $f.text;
        $type = $f.type;
        $isArray = $f.isArray;
        writeIntoparserLogFile(
            "Line " + std::to_string($f.stop->getLine()) + ": unary_expression : factor\n\n" +
            $text + "\n"
        );
    };

factor
	returns[std::string text, std::string type, bool isArray]:

	// ---- Case 1: Single variable ----
	v = variable {
        $text = $v.text;
	    
        
            
	            $isArray = $v.reallyArray;
        
            $type = $v.type;

        writeIntoparserLogFile(
            "Line " + std::to_string($v.stop->getLine()) + ": factor : variable\n\n" + $text + "\n"
        );
    }

	// ---- Case 2: Function call ----
	| id = ID lp = LPAREN al = argument_list rp = RPAREN {
        $text = $id->getText() + $lp->getText() + $al.text + $rp->getText();
        string errorText = "";
        SymbolInfo* sym = symTable->lookup($id->getText());

        

        if (sym == nullptr) {
            $type = "undefined";
            writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Undefined function " + $id->getText() + "\n");
            syntaxErrorCount++;
            errorText = "Error at line " + std::to_string($id->getLine()) + ": Undefined function " + $id->getText() + "\n\n";
        } 
        else if (!sym->getFunction()) {
            $type = "undefined";
            writeIntoErrorFile("Line " + std::to_string($id->getLine()) + ": '" + $id->getText() + "' is not a function");
            syntaxErrorCount++;
            errorText = "Line " + std::to_string($id->getLine()) + ": '" + $id->getText() + "' is not a function\n\n";
        } else {
            $type = sym->getVariableType();  
            $isArray = false;
          
            int expected = sym->getParamCount();
            if (expected != $al.types.size()) {
	                writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Total number of arguments mismatch with declaration in function " + $id->getText() + "\n");
                syntaxErrorCount++;
                errorText = "Error at line " + std::to_string($id->getLine()) + ": Total number of arguments mismatch with declaration in function " + $id->getText() + "\n\n";
            } else {
                
                string* expectedTypes = sym->getParamTypes();
                for (int i = 0; i < expected; ++i) {
	                    cout<<$id->getText() <<"Expected type: " << expectedTypes[i] << ", Actual type: " << $al.types[i] << endl;
	                    if($al.isArray[i]==true){
			                //             writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Type mismatch, " +$al.names[i] +" is an array\n");
                            // errorText = "Error at line " + std::to_string($id->getLine()) + ": Type mismatch, " +$al.names[i] +" is an array\n\n";
                            // syntaxErrorCount++;
                    }
                    else if (expectedTypes[i] != $al.types[i] ) {
	                        writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) +
                                           ": " + std::to_string(i+1) + "th argument mismatch in function " +
                                           $id->getText() + "\n");
                        syntaxErrorCount++;
                        errorText = "Error at line " + std::to_string($id->getLine()) +
                                    ": " + std::to_string(i+1) + "th argument mismatch in function " +
                                    $id->getText() + "\n\n";
                        break;
                    }
                }
            }

            
        }

        writeIntoparserLogFile(
            "Line " + std::to_string($id->getLine()) + ": factor : ID LPAREN argument_list RPAREN\n\n" +errorText +
             $text + "\n"
        );
    }

	// ---- Case 3: Parenthesized expression ----
	| lp = LPAREN e = expression rp = RPAREN {
        $text = $lp->getText() + $e.text + $rp->getText();
        $type = $e.type;
        $isArray = $e.isArray;

        writeIntoparserLogFile(
            "Line " + std::to_string($lp->getLine()) + ": factor : LPAREN expression RPAREN\n\n" + $text + "\n"
        );
    }

	// ---- Case 4: Integer constant ----
	| ci = CONST_INT {
        $text = $ci->getText();
        $type = "int";
        $isArray = false;
        writeIntoparserLogFile(
            "Line " + std::to_string($ci->getLine()) + ": factor : CONST_INT\n\n" + $text + "\n"
        );
    }

	// ---- Case 5: Float constant ----
	| cf = CONST_FLOAT {
        $text = $cf->getText();
        $type = "float";
        $isArray = false;
        writeIntoparserLogFile(
            "Line " + std::to_string($cf->getLine()) + ": factor : CONST_FLOAT\n\n" + $text + "\n"
        );
    }

	// ---- Case 6: variable++ ----
	| v = variable ic = INCOP {
        $text = $v.text + $ic->getText();
        
            $isArray = $v.reallyArray;
            $type = $v.type;

        writeIntoparserLogFile(
            "Line " + std::to_string($v.stop->getLine()) + ": factor : variable INCOP\n\n" + $text + "\n"
        );
    }

	// ---- Case 7: variable-- ----
	| v = variable dc = DECOP {
        $text = $v.text + $dc->getText();
       
            $type = $v.type;
            $isArray = $v.reallyArray;
       

       

        writeIntoparserLogFile(
            "Line " + std::to_string($v.stop->getLine()) + ": factor : variable DECOP\n\n" + $text + "\n"
        );
    };

argument_list
	returns[std::string text, std::vector<std::string> types, std::vector<bool> isArray,std::vector<std::string> names]
		:
	a = arguments {
        $text = $a.text;
        $types = $a.types;
        $isArray = $a.isArray;
        $names = $a.names;
        writeIntoparserLogFile(
            "Line " + std::to_string($a.stop->getLine()) + ": argument_list : arguments\n\n" +
            $text + "\n"
        );
    }
	| {
        $text = "";
        $types = {};
        $isArray = {};
        $names = {};
    };

arguments
	returns[std::string text,std::vector<std::string> names, std::vector<std::string> types, std::vector<bool> isArray]
		:
	a = arguments cm = COMMA le = logic_expression {
        $text = $a.text + $cm->getText()  + $le.text;
        $types = $a.types;
        $types.push_back($le.type);
        $isArray = $a.isArray;
        $isArray.push_back($le.isArray);
        $names = $a.names;
        $names.push_back($le.text);   
        writeIntoparserLogFile(
            "Line " + std::to_string($a.stop->getLine()) + ": arguments : arguments COMMA logic_expression\n\n" +
            $text + "\n"
        );
    }
	| le = logic_expression {
        $text = $le.text;
	    $types.push_back($le.type);
        $isArray.push_back($le.isArray);
        $names.push_back($le.text);  
        writeIntoparserLogFile(
            "Line " + std::to_string($le.stop->getLine()) + ": arguments : logic_expression\n\n" +
            $text + "\n"
        );
    };