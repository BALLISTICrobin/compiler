// Generated from /Users/niloydas/Desktop/compiler/syntax_semantics_analysis/antlr4-resources/antlr4-skeletons/cpp/C8086Parser.g4 by ANTLR 4.13.1

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

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class C8086Parser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		LINE_COMMENT=1, BLOCK_COMMENT=2, STRING=3, WS=4, IF=5, ELSE=6, FOR=7, 
		WHILE=8, PRINTLN=9, RETURN=10, INT=11, FLOAT=12, VOID=13, LPAREN=14, RPAREN=15, 
		LCURL=16, RCURL=17, LTHIRD=18, RTHIRD=19, SEMICOLON=20, COMMA=21, ADDOP=22, 
		SUBOP=23, MULOP=24, INCOP=25, DECOP=26, NOT=27, RELOP=28, LOGICOP=29, 
		ASSIGNOP=30, ID=31, CONST_INT=32, CONST_FLOAT=33, UNRECOGNIZED=34;
	public static final int
		RULE_start = 0, RULE_program = 1, RULE_unit = 2, RULE_func_declaration = 3, 
		RULE_func_definition = 4, RULE_parameter_list = 5, RULE_invalid_param = 6, 
		RULE_compound_statement = 7, RULE_var_declaration = 8, RULE_declaration_list_err = 9, 
		RULE_type_specifier = 10, RULE_declaration_list = 11, RULE_statements = 12, 
		RULE_statement = 13, RULE_expression_statement = 14, RULE_variable = 15, 
		RULE_expression = 16, RULE_logic_expression = 17, RULE_rel_expression = 18, 
		RULE_simple_expression = 19, RULE_term = 20, RULE_unary_expression = 21, 
		RULE_factor = 22, RULE_argument_list = 23, RULE_arguments = 24;
	private static String[] makeRuleNames() {
		return new String[] {
			"start", "program", "unit", "func_declaration", "func_definition", "parameter_list", 
			"invalid_param", "compound_statement", "var_declaration", "declaration_list_err", 
			"type_specifier", "declaration_list", "statements", "statement", "expression_statement", 
			"variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
			"term", "unary_expression", "factor", "argument_list", "arguments"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, "'if'", "'else'", "'for'", "'while'", "'printf'", 
			"'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
			"'['", "']'", "';'", "','", null, null, null, "'++'", "'--'", "'!'", 
			null, null, "'='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
			"FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
			"RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
			"ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", 
			"ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT", "UNRECOGNIZED"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "C8086Parser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }


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

	public C8086Parser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StartContext extends ParserRuleContext {
		public ProgramContext p;
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public StartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_start; }
	}

	public final StartContext start() throws RecognitionException {
		StartContext _localctx = new StartContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_start);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(50);
			((StartContext)_localctx).p = program(0);

			        writeIntoparserLogFile(
			            "Line " + ((StartContext)_localctx).p.lineNo + ": start : program\n"
			        );

			        symTable->printAllScopes();

			        writeIntoparserLogFile(
					             "Total number of lines: " + ((StartContext)_localctx).p.lineNo + "\n" +
			            "Total number of errors: " + std::to_string(syntaxErrorCount)
			        );
				
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public std::string text;
		public std::string lineNo;
		public ProgramContext p;
		public UnitContext u;
		public UnitContext unit() {
			return getRuleContext(UnitContext.class,0);
		}
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		return program(0);
	}

	private ProgramContext program(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ProgramContext _localctx = new ProgramContext(_ctx, _parentState);
		ProgramContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_program, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(54);
			((ProgramContext)_localctx).u = unit();

			        ((ProgramContext)_localctx).text =  ((ProgramContext)_localctx).u.text;
			        ((ProgramContext)_localctx).lineNo =  ((ProgramContext)_localctx).u.lineNo;
			        writeIntoparserLogFile(
			            "Line " + _localctx.lineNo + ": program : unit\n\n" +
			            _localctx.text + "\n"
			        );
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(63);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ProgramContext(_parentctx, _parentState);
					_localctx.p = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_program);
					setState(57);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(58);
					((ProgramContext)_localctx).u = unit();

					                  ((ProgramContext)_localctx).text =  ((ProgramContext)_localctx).p.text + "\n" + ((ProgramContext)_localctx).u.text;
					                  ((ProgramContext)_localctx).lineNo =  ((ProgramContext)_localctx).u.lineNo; 
					                  writeIntoparserLogFile(
					                      "Line " + _localctx.lineNo + ": program : program unit\n\n" +
					                      _localctx.text + "\n"
					                  );
					              
					}
					} 
				}
				setState(65);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UnitContext extends ParserRuleContext {
		public std::string text;
		public std::string lineNo;
		public Var_declarationContext v;
		public Func_declarationContext f;
		public Func_definitionContext fd;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public Func_declarationContext func_declaration() {
			return getRuleContext(Func_declarationContext.class,0);
		}
		public Func_definitionContext func_definition() {
			return getRuleContext(Func_definitionContext.class,0);
		}
		public UnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unit; }
	}

	public final UnitContext unit() throws RecognitionException {
		UnitContext _localctx = new UnitContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_unit);
		try {
			setState(75);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(66);
				((UnitContext)_localctx).v = var_declaration();

				        ((UnitContext)_localctx).text =  ((UnitContext)_localctx).v.text;
				        ((UnitContext)_localctx).lineNo =  std::to_string((((UnitContext)_localctx).v!=null?(((UnitContext)_localctx).v.stop):null)->getLine());
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((UnitContext)_localctx).v!=null?(((UnitContext)_localctx).v.stop):null)->getLine()) + ": unit : var_declaration\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(69);
				((UnitContext)_localctx).f = func_declaration();

				        ((UnitContext)_localctx).text =  ((UnitContext)_localctx).f.text;
				        ((UnitContext)_localctx).lineNo =  std::to_string((((UnitContext)_localctx).f!=null?(((UnitContext)_localctx).f.stop):null)->getLine());
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((UnitContext)_localctx).f!=null?(((UnitContext)_localctx).f.stop):null)->getLine()) + ": unit : func_declaration\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(72);
				((UnitContext)_localctx).fd = func_definition();

				        ((UnitContext)_localctx).text =  ((UnitContext)_localctx).fd.text;
				        ((UnitContext)_localctx).lineNo =  ((UnitContext)_localctx).fd.lineNo;
				        writeIntoparserLogFile(
				            "Line " + ((UnitContext)_localctx).fd.lineNo + ": unit : func_definition\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_declarationContext extends ParserRuleContext {
		public std::string text;
		public Type_specifierContext t;
		public Token id;
		public Token lp;
		public Parameter_listContext pl;
		public Token rp;
		public Token sc;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
		public Func_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_declaration; }
	}

	public final Func_declarationContext func_declaration() throws RecognitionException {
		Func_declarationContext _localctx = new Func_declarationContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_func_declaration);
		try {
			setState(93);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(77);
				((Func_declarationContext)_localctx).t = type_specifier();
				setState(78);
				((Func_declarationContext)_localctx).id = match(ID);
				setState(79);
				((Func_declarationContext)_localctx).lp = match(LPAREN);

				        insertIntoTable = false;
				    
				setState(81);
				((Func_declarationContext)_localctx).pl = parameter_list(0);
				setState(82);
				((Func_declarationContext)_localctx).rp = match(RPAREN);
				setState(83);
				((Func_declarationContext)_localctx).sc = match(SEMICOLON);

				        ((Func_declarationContext)_localctx).text =  ((Func_declarationContext)_localctx).t.text + " " + ((Func_declarationContext)_localctx).id->getText() + ((Func_declarationContext)_localctx).lp->getText() + ((Func_declarationContext)_localctx).pl.text + ((Func_declarationContext)_localctx).rp->getText() + ((Func_declarationContext)_localctx).sc->getText();
						SymbolInfo* s = symTable->insert(((Func_declarationContext)_localctx).id->getText(), "ID");
				    if (s != nullptr) {
					    s->setFunction(true);
					    s->setVariableType(((Func_declarationContext)_localctx).t.text);
					    s->setDeclared(true);
				        int n = ((Func_declarationContext)_localctx).pl.ids.size();
				        string* paramTypes = new string[n];
				        for (int i = 0; i < n; ++i) paramTypes[i] = ((Func_declarationContext)_localctx).pl.ids[i].second;
				        s->setParamTypes(paramTypes, n);
				    }

				        writeIntoparserLogFile(
				            "Line " + std::to_string((((Func_declarationContext)_localctx).t!=null?(((Func_declarationContext)_localctx).t.stop):null)->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n" +
				            _localctx.text + "\n"        
				        );
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(86);
				((Func_declarationContext)_localctx).t = type_specifier();
				setState(87);
				((Func_declarationContext)_localctx).id = match(ID);
				setState(88);
				((Func_declarationContext)_localctx).lp = match(LPAREN);
				setState(89);
				((Func_declarationContext)_localctx).rp = match(RPAREN);
				setState(90);
				((Func_declarationContext)_localctx).sc = match(SEMICOLON);

				        ((Func_declarationContext)_localctx).text =  ((Func_declarationContext)_localctx).t.text + " " + ((Func_declarationContext)_localctx).id->getText() + ((Func_declarationContext)_localctx).lp->getText() + ((Func_declarationContext)_localctx).rp->getText() + ((Func_declarationContext)_localctx).sc->getText();
						SymbolInfo* s = symTable->insert(((Func_declarationContext)_localctx).id->getText(), "ID");
				        if (s != nullptr) {
				            s->setFunction(true);
					        s->setVariableType(((Func_declarationContext)_localctx).t.text);
						    s->setDeclared(true);
					        s->setParamTypes(nullptr, 0);
				        }

				        writeIntoparserLogFile(
				            "Line " + std::to_string((((Func_declarationContext)_localctx).t!=null?(((Func_declarationContext)_localctx).t.stop):null)->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_definitionContext extends ParserRuleContext {
		public std::string text;
		public std::vector<std::pair<std::string, std::string>> param_ids;
		public std::string lineNo;
		public Type_specifierContext t;
		public Token id;
		public Token lp;
		public Parameter_listContext pl;
		public Token rp;
		public Compound_statementContext cs;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public Func_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_definition; }
	}

	public final Func_definitionContext func_definition() throws RecognitionException {
		Func_definitionContext _localctx = new Func_definitionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_func_definition);
		try {
			setState(116);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(95);
				((Func_definitionContext)_localctx).t = type_specifier();
				setState(96);
				((Func_definitionContext)_localctx).id = match(ID);
				 
					    insertIntoTable = true;
					    SymbolInfo* sym = symTable->lookup(((Func_definitionContext)_localctx).id->getText());
				        string errorText = "";
				    
				    if (!sym) {
				        
				        sym = symTable->insert(((Func_definitionContext)_localctx).id->getText(), "ID");
				        sym->setFunction(true);
				        sym->setDefined(true);
				        sym->setDeclared(false);
				        sym->setVariableType(((Func_definitionContext)_localctx).t.text);
					    
				    }
				    
				    
				setState(98);
				((Func_definitionContext)_localctx).lp = match(LPAREN);

					        symTable->EnterScope();
				    
				setState(100);
				((Func_definitionContext)_localctx).pl = parameter_list(0);
				setState(101);
				((Func_definitionContext)_localctx).rp = match(RPAREN);

				        ((Func_definitionContext)_localctx).param_ids =  ((Func_definitionContext)_localctx).pl.ids;
					        sym = symTable->lookup(((Func_definitionContext)_localctx).id->getText());
					            
				            if(sym->getDeclared()==false) {
					                int n = ((Func_definitionContext)_localctx).pl.ids.size();
				                string* paramTypes = new string[n];
				            for (int i = 0; i < n; ++i) paramTypes[i] = ((Func_definitionContext)_localctx).pl.ids[i].second;
				                if(sym) {
				                sym->setParamTypes(paramTypes, n);
				                }
				            }
					         
				        if (!sym->getFunction()) {
				            
					            writeIntoErrorFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Multiple declaration of " + ((Func_definitionContext)_localctx).id->getText() + "\n");
				            errorText = "Error at line " + std::to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Multiple declaration of " + ((Func_definitionContext)_localctx).id->getText() + "\n";
				            syntaxErrorCount++;
					            writeIntoparserLogFile(errorText);
				        } else {
				            
					            if (sym->getVariableType() != ((Func_definitionContext)_localctx).t.text) {
					                writeIntoErrorFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Return type mismatch of " + ((Func_definitionContext)_localctx).id->getText() + "\n");
				                    errorText = "Error at line " + std::to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Return type mismatch of " + ((Func_definitionContext)_localctx).id->getText() + "\n";
				                syntaxErrorCount++;
					                writeIntoparserLogFile(errorText);
				            }
				            
					        if (sym->getParamCount() != _localctx.param_ids.size()) {
					                writeIntoErrorFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Total number of arguments mismatch with declaration in function " + ((Func_definitionContext)_localctx).id->getText() + "\n");
				                errorText = "Error at line " + std::to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Total number of arguments mismatch with declaration in function " + ((Func_definitionContext)_localctx).id->getText() + "\n";
				                syntaxErrorCount++;
					                writeIntoparserLogFile(errorText);
				            } else {
				                for (int i = 0; i < sym->getParamCount(); i++) {
				                    if (sym->getParamTypes()[i] != _localctx.param_ids[i].second) {
				                        writeIntoErrorFile("Line " + std::to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Type mismatch in parameter " + std::to_string(i+1) + " of function '" + ((Func_definitionContext)_localctx).id->getText() + "'");
				                        syntaxErrorCount++;
					                        writeIntoparserLogFile(errorText);
				                    }
				                }
				            }
				            sym->setDefined(true);
				        }
				    
				        // sym = symTable->lookup(((Func_definitionContext)_localctx).id->getText());
					    
					        

				      
				setState(103);
				((Func_definitionContext)_localctx).cs = compound_statement(_localctx.param_ids);

					        
				        ((Func_definitionContext)_localctx).text =  ((Func_definitionContext)_localctx).t.text + " " + ((Func_definitionContext)_localctx).id->getText() + ((Func_definitionContext)_localctx).lp->getText() + ((Func_definitionContext)_localctx).pl.text + ((Func_definitionContext)_localctx).rp->getText() + ((Func_definitionContext)_localctx).cs.text;
				        ((Func_definitionContext)_localctx).lineNo =  ((Func_definitionContext)_localctx).cs.lineNo;

					    sym = symTable->lookup(((Func_definitionContext)_localctx).id->getText());

				        if (sym != nullptr) {
				            string expectedVarType = sym->getVariableType();
				            if(expectedVarType=="void" && ((Func_definitionContext)_localctx).cs.returnType!=""){
						            writeIntoErrorFile("Error at line " + ((Func_definitionContext)_localctx).cs.lineNo+ ": Cannot return value from function " + ((Func_definitionContext)_localctx).id->getText() + " with void return type.\n");
				                syntaxErrorCount++;
				                errorText = "Error at line " + ((Func_definitionContext)_localctx).cs.lineNo + ": Cannot return value from function " + ((Func_definitionContext)_localctx).id->getText() + " with void return type.\n";
				                writeIntoparserLogFile(errorText);

				            }
				// 	        else if(expectedVarType=="int" && ((Func_definitionContext)_localctx).cs.returnType!="int"){
				// 	                writeIntoErrorFile("Error at line " + ((Func_definitionContext)_localctx).cs.lineNo
				//  + ": Cannot return value from function " + ((Func_definitionContext)_localctx).id->getText() + " with int return type\n");
				//                 syntaxErrorCount++;

				                
				//             }

				// 	        else if(expectedVarType=="float" && ((Func_definitionContext)_localctx).cs.returnType!="float"){
				// 	                writeIntoErrorFile("Error at line " + ((Func_definitionContext)_localctx).cs.lineNo
				//  + ": Cannot return value from function " + ((Func_definitionContext)_localctx).id->getText() + " with float return type\n");
				//                 syntaxErrorCount++;
				                
				//             }
				        }
				        
				        writeIntoparserLogFile(
				            "Line " + ((Func_definitionContext)_localctx).cs.lineNo + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n" +
				            _localctx.text + "\n"
				        );


				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(106);
				((Func_definitionContext)_localctx).t = type_specifier();
				setState(107);
				((Func_definitionContext)_localctx).id = match(ID);
				 
					        SymbolInfo* sym = symTable->lookup(((Func_definitionContext)_localctx).id->getText());
				            string errorText = "";
				    
				    if (sym != nullptr) {
				        if (!sym->getFunction()) {
						            writeIntoErrorFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Multiple declaration of" + ((Func_definitionContext)_localctx).id->getText() + "\n");
				            errorText = "Error at line " + std::to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Multiple declaration of " + ((Func_definitionContext)_localctx).id->getText() + "\n";
				            syntaxErrorCount++;
					            writeIntoparserLogFile(errorText);
				        } else if (sym->getDefined()) {
				            writeIntoErrorFile("Line " + std::to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Function '" + ((Func_definitionContext)_localctx).id->getText() + "' is already defined");
				            errorText = "Line " + std::to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Function '" + ((Func_definitionContext)_localctx).id->getText() + "' is already defined\n";
				            syntaxErrorCount++;
					            writeIntoparserLogFile(errorText);
				        } else {
				            if (sym->getVariableType() != ((Func_definitionContext)_localctx).t.text || sym->getParamCount() > 0) {
				                writeIntoErrorFile("Line " + std::to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Function definition mismatch with declaration for '" + ((Func_definitionContext)_localctx).id->getText() + "'");
				                errorText = "Line " + std::to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Function definition mismatch with declaration for '" + ((Func_definitionContext)_localctx).id->getText() + "'\n";
				                syntaxErrorCount++;
					                writeIntoparserLogFile(errorText);
				            }
				            sym->setDefined(true);
				        }
				    } else {
				        sym = symTable->insert(((Func_definitionContext)_localctx).id->getText(), "ID");
				        sym->setFunction(true);
				        sym->setDefined(true);
				        sym->setVariableType(((Func_definitionContext)_localctx).t.text);
					    sym->setParamTypes(nullptr, 0);
				    }
					    
				    
				setState(109);
				((Func_definitionContext)_localctx).lp = match(LPAREN);

				            symTable->EnterScope();
				    
				setState(111);
				((Func_definitionContext)_localctx).rp = match(RPAREN);

				        ((Func_definitionContext)_localctx).param_ids =  {};

					
					    
				setState(113);
				((Func_definitionContext)_localctx).cs = compound_statement(_localctx.param_ids);

				        ((Func_definitionContext)_localctx).text =  ((Func_definitionContext)_localctx).t.text + " " + ((Func_definitionContext)_localctx).id->getText() + ((Func_definitionContext)_localctx).lp->getText() + ((Func_definitionContext)_localctx).rp->getText() + ((Func_definitionContext)_localctx).cs.text;
						      ((Func_definitionContext)_localctx).lineNo =  ((Func_definitionContext)_localctx).cs.lineNo;   

					    sym = symTable->lookup(((Func_definitionContext)_localctx).id->getText());

				        if (sym != nullptr) {
				            string expectedVarType = sym->getVariableType();
						            cout<<((Func_definitionContext)_localctx).id->getText()<<" "<<expectedVarType<<endl;
				            if(expectedVarType=="void" && ((Func_definitionContext)_localctx).cs.returnType!=""){
						            writeIntoErrorFile("Error at line " + ((Func_definitionContext)_localctx).cs.lineNo + ": Cannot return value from function " + ((Func_definitionContext)_localctx).id->getText() + " with void return type.\n");
				                syntaxErrorCount++;
				                errorText = "Error at line " + ((Func_definitionContext)_localctx).cs.lineNo + ": Cannot return value from function " + ((Func_definitionContext)_localctx).id->getText() + " with void return type.\n";
				                writeIntoparserLogFile(errorText);

				            }
					        // else if(expectedVarType=="int" && ((Func_definitionContext)_localctx).cs.returnType!="int"){
					        //         writeIntoErrorFile("Error at line " + ((Func_definitionContext)_localctx).cs.lineNo + ": Cannot return value from function " + ((Func_definitionContext)_localctx).id->getText() + " with int return type\n");
				            //     syntaxErrorCount++;
				                
				            // }

					        // else if(expectedVarType=="float" && ((Func_definitionContext)_localctx).cs.returnType!="float"){
					        //        writeIntoErrorFile("Error at line " + ((Func_definitionContext)_localctx).cs.lineNo + ": Cannot return value from function " + ((Func_definitionContext)_localctx).id->getText() + " with float return type\n");
				            //     syntaxErrorCount++;
				                
				            // }
				        }
				        writeIntoparserLogFile(
					            "Line " + ((Func_definitionContext)_localctx).cs.lineNo + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Parameter_listContext extends ParserRuleContext {
		public std::string text;
		public std::vector<std::pair<std::string, std::string>> ids;
		public Parameter_listContext pl;
		public Type_specifierContext ts;
		public Token id;
		public Invalid_paramContext ip;
		public Token cm;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public Invalid_paramContext invalid_param() {
			return getRuleContext(Invalid_paramContext.class,0);
		}
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(C8086Parser.COMMA, 0); }
		public Parameter_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_list; }
	}

	public final Parameter_listContext parameter_list() throws RecognitionException {
		return parameter_list(0);
	}

	private Parameter_listContext parameter_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Parameter_listContext _localctx = new Parameter_listContext(_ctx, _parentState);
		Parameter_listContext _prevctx = _localctx;
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_parameter_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(130);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				{
				setState(119);
				((Parameter_listContext)_localctx).ts = type_specifier();
				setState(120);
				((Parameter_listContext)_localctx).id = match(ID);

				        string errorText = "";
					    ((Parameter_listContext)_localctx).ids =  { { ((Parameter_listContext)_localctx).id->getText(), ((Parameter_listContext)_localctx).ts.text } };
				        ((Parameter_listContext)_localctx).text =  ((Parameter_listContext)_localctx).ts.text + " " + ((Parameter_listContext)_localctx).id->getText();
					    
				        if(insertIntoTable) {
					        SymbolInfo* s = symTable->insert(((Parameter_listContext)_localctx).id->getText(), "ID");
				            if (s != nullptr) {
					            s->setVariableType(((Parameter_listContext)_localctx).ts.text);
					                
				            }
				            else{
							        writeIntoErrorFile("Error at line " + std::to_string((((Parameter_listContext)_localctx).ts!=null?(((Parameter_listContext)_localctx).ts.stop):null)->getLine()

				) + ": Multiple declaration of " + ((Parameter_listContext)_localctx).id->getText() + " in parameter\n");
				                errorText = "Error at line " + std::to_string((((Parameter_listContext)_localctx).ts!=null?(((Parameter_listContext)_localctx).ts.stop):null)->getLine()

				) + ": Multiple declaration of " + ((Parameter_listContext)_localctx).id->getText() + " in parameter\n";
				                syntaxErrorCount++;
				                writeIntoparserLogFile(errorText);
				            }
				    }
					    writeIntoparserLogFile(
				            "Line " + std::to_string((((Parameter_listContext)_localctx).ts!=null?(((Parameter_listContext)_localctx).ts.stop):null)->getLine()) + ": parameter_list : type_specifier ID\n\n" +
				            _localctx.text + "\n"
				        );
				        
				    
				}
				break;
			case 2:
				{
				setState(123);
				((Parameter_listContext)_localctx).ts = type_specifier();

					    ((Parameter_listContext)_localctx).ids =  { { "", ((Parameter_listContext)_localctx).ts.text } };

				        ((Parameter_listContext)_localctx).text =  ((Parameter_listContext)_localctx).ts.text;
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((Parameter_listContext)_localctx).ts!=null?(((Parameter_listContext)_localctx).ts.stop):null)->getLine()) + ": parameter_list : type_specifier\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case 3:
				{
				setState(126);
				((Parameter_listContext)_localctx).ts = type_specifier();
				setState(127);
				((Parameter_listContext)_localctx).ip = invalid_param();

				    ((Parameter_listContext)_localctx).ids =  { { "", ((Parameter_listContext)_localctx).ts.text } };
				    ((Parameter_listContext)_localctx).text =  ((Parameter_listContext)_localctx).ts.text;

				    writeIntoparserLogFile(
				        "Line " + std::to_string((((Parameter_listContext)_localctx).ts!=null?(((Parameter_listContext)_localctx).ts.stop):null)->getLine()) + ": parameter_list : type_specifier\n\n" +
				        _localctx.text + "\n"
				    );

				    writeIntoparserLogFile(
				        "Error at line " + std::to_string((((Parameter_listContext)_localctx).ip!=null?(((Parameter_listContext)_localctx).ip.start):null)->getLine()) +
				        ": syntax error, unexpected " + ((Parameter_listContext)_localctx).ip.name + ", expecting RPAREN or COMMA\n"
				    );

				    writeIntoErrorFile(
				        "Error at line " + std::to_string((((Parameter_listContext)_localctx).ip!=null?(((Parameter_listContext)_localctx).ip.start):null)->getLine()) +
				        ": syntax error, unexpected " + ((Parameter_listContext)_localctx).ip.name + ", expecting RPAREN or COMMA\n"
				    );

				    syntaxErrorCount++;

				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(145);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(143);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
					case 1:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.pl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(132);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(133);
						((Parameter_listContext)_localctx).cm = match(COMMA);
						setState(134);
						((Parameter_listContext)_localctx).ts = type_specifier();
						setState(135);
						((Parameter_listContext)_localctx).id = match(ID);

						                  string errorText = "";
						                  ((Parameter_listContext)_localctx).ids =  ((Parameter_listContext)_localctx).pl.ids;
						          	    _localctx.ids.push_back({ ((Parameter_listContext)_localctx).id->getText(), ((Parameter_listContext)_localctx).ts.text });
						                  ((Parameter_listContext)_localctx).text =  ((Parameter_listContext)_localctx).pl.text + ((Parameter_listContext)_localctx).cm->getText() + ((Parameter_listContext)_localctx).ts.text +" "+ ((Parameter_listContext)_localctx).id->getText();

						          	    
						                  
						                  if(insertIntoTable) {
						                     
						          	        SymbolInfo* s = symTable->insert(((Parameter_listContext)_localctx).id->getText(), "ID");
						                      if (s != nullptr) {
						          	            s->setVariableType(((Parameter_listContext)_localctx).ts.text);
						          	               
						                      }
						                      else{
						          			        writeIntoErrorFile("Error at line " + std::to_string((((Parameter_listContext)_localctx).ts!=null?(((Parameter_listContext)_localctx).ts.stop):null)->getLine())
						                               + ": Multiple declaration of " + ((Parameter_listContext)_localctx).id->getText() + " in parameter\n");
						                              errorText = "Error at line " + std::to_string((((Parameter_listContext)_localctx).ts!=null?(((Parameter_listContext)_localctx).ts.stop):null)->getLine())
						                               + ": Multiple declaration of " + ((Parameter_listContext)_localctx).id->getText() + " in parameter\n";
						                          syntaxErrorCount++;
						                          writeIntoparserLogFile(errorText);
						                      }
						              }
						          	    writeIntoparserLogFile(
						                      "Line " + std::to_string((((Parameter_listContext)_localctx).pl!=null?(((Parameter_listContext)_localctx).pl.stop):null)->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID\n\n" +
						                      _localctx.text + "\n"
						                  );
						                  
						              
						}
						break;
					case 2:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.pl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(138);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(139);
						((Parameter_listContext)_localctx).cm = match(COMMA);
						setState(140);
						((Parameter_listContext)_localctx).ts = type_specifier();

						          	    ((Parameter_listContext)_localctx).ids =  ((Parameter_listContext)_localctx).pl.ids;
						                  _localctx.ids.push_back({ "", ((Parameter_listContext)_localctx).ts.text });

						                  ((Parameter_listContext)_localctx).text =  ((Parameter_listContext)_localctx).pl.text + ((Parameter_listContext)_localctx).cm->getText() + ((Parameter_listContext)_localctx).ts.text;
						                  writeIntoparserLogFile(
						                      "Line " + std::to_string((((Parameter_listContext)_localctx).pl!=null?(((Parameter_listContext)_localctx).pl.stop):null)->getLine()) + ": parameter_list : parameter_list COMMA type_specifier\n\n" +
						                      _localctx.text + "\n"
						                  );
						              
						}
						break;
					}
					} 
				}
				setState(147);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Invalid_paramContext extends ParserRuleContext {
		public std::string name;
		public TerminalNode ADDOP() { return getToken(C8086Parser.ADDOP, 0); }
		public TerminalNode MULOP() { return getToken(C8086Parser.MULOP, 0); }
		public TerminalNode RELOP() { return getToken(C8086Parser.RELOP, 0); }
		public TerminalNode ASSIGNOP() { return getToken(C8086Parser.ASSIGNOP, 0); }
		public TerminalNode LOGICOP() { return getToken(C8086Parser.LOGICOP, 0); }
		public TerminalNode NOT() { return getToken(C8086Parser.NOT, 0); }
		public Invalid_paramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_invalid_param; }
	}

	public final Invalid_paramContext invalid_param() throws RecognitionException {
		Invalid_paramContext _localctx = new Invalid_paramContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_invalid_param);
		try {
			setState(160);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADDOP:
				enterOuterAlt(_localctx, 1);
				{
				setState(148);
				match(ADDOP);

				        ((Invalid_paramContext)_localctx).name =  "ADDOP";
				    
				}
				break;
			case MULOP:
				enterOuterAlt(_localctx, 2);
				{
				setState(150);
				match(MULOP);

				        ((Invalid_paramContext)_localctx).name =  "MULOP";
				    
				}
				break;
			case RELOP:
				enterOuterAlt(_localctx, 3);
				{
				setState(152);
				match(RELOP);

				        ((Invalid_paramContext)_localctx).name =  "RELOP";
				    
				}
				break;
			case ASSIGNOP:
				enterOuterAlt(_localctx, 4);
				{
				setState(154);
				match(ASSIGNOP);

				        ((Invalid_paramContext)_localctx).name =  "ASSIGNOP";
				    
				}
				break;
			case LOGICOP:
				enterOuterAlt(_localctx, 5);
				{
				setState(156);
				match(LOGICOP);
				 
				        ((Invalid_paramContext)_localctx).name =  "LOGICOP";
				    
				}
				break;
			case NOT:
				enterOuterAlt(_localctx, 6);
				{
				setState(158);
				match(NOT);
				 
				        ((Invalid_paramContext)_localctx).name =  "NOT";
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Compound_statementContext extends ParserRuleContext {
		public std::vector<std::pair<std::string, std::string>> param_ids;
		public std::string text;
		public std::string lineNo;
		public std::string returnType;
		public Token lc;
		public StatementsContext st;
		public Token rc;
		public TerminalNode LCURL() { return getToken(C8086Parser.LCURL, 0); }
		public TerminalNode RCURL() { return getToken(C8086Parser.RCURL, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public Compound_statementContext(ParserRuleContext parent, int invokingState) { super(parent, invokingState); }
		public Compound_statementContext(ParserRuleContext parent, int invokingState, std::vector<std::pair<std::string, std::string>> param_ids) {
			super(parent, invokingState);
			this.param_ids = param_ids;
		}
		@Override public int getRuleIndex() { return RULE_compound_statement; }
	}

	public final Compound_statementContext compound_statement(std::vector<std::pair<std::string, std::string>> param_ids) throws RecognitionException {
		Compound_statementContext _localctx = new Compound_statementContext(_ctx, getState(), param_ids);
		enterRule(_localctx, 14, RULE_compound_statement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(162);
			((Compound_statementContext)_localctx).lc = match(LCURL);
			setState(164);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 15171944352L) != 0)) {
				{
				setState(163);
				((Compound_statementContext)_localctx).st = statements(0);
				}
			}

			setState(166);
			((Compound_statementContext)_localctx).rc = match(RCURL);

				((Compound_statementContext)_localctx).returnType =  "";
			((Compound_statementContext)_localctx).text =  ((Compound_statementContext)_localctx).lc->getText() + "\n";

			if (((Compound_statementContext)_localctx).st != nullptr) {
			    _localctx.text += ((Compound_statementContext)_localctx).st.text;
			    ((Compound_statementContext)_localctx).returnType =  ((Compound_statementContext)_localctx).st.returnType;
			}

			_localctx.text += "\n" + ((Compound_statementContext)_localctx).rc->getText();
			((Compound_statementContext)_localctx).lineNo =  std::to_string(((Compound_statementContext)_localctx).rc->getLine());

			writeIntoparserLogFile(
			    "Line " + _localctx.lineNo + ": compound_statement : LCURL statements RCURL\n\n" +
			    _localctx.text + "\n"
			);

			symTable->printAllScopes();
			symTable->ExitScope();

			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Var_declarationContext extends ParserRuleContext {
		public std::string text;
		public Type_specifierContext t;
		public Declaration_listContext dl;
		public Token sm;
		public Declaration_list_errContext de;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
		public Declaration_list_errContext declaration_list_err() {
			return getRuleContext(Declaration_list_errContext.class,0);
		}
		public Var_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var_declaration; }
	}

	public final Var_declarationContext var_declaration() throws RecognitionException {
		Var_declarationContext _localctx = new Var_declarationContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_var_declaration);
		try {
			setState(180);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(169);
				((Var_declarationContext)_localctx).t = type_specifier();

					        currentVarType= ((Var_declarationContext)_localctx).t.text;
				    
				setState(171);
				((Var_declarationContext)_localctx).dl = declaration_list(0);
				setState(172);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

				        ((Var_declarationContext)_localctx).text =  ((Var_declarationContext)_localctx).t.text + " " + ((Var_declarationContext)_localctx).dl.text + ((Var_declarationContext)_localctx).sm->getText();
				        string errorText = "";

				        if(((Var_declarationContext)_localctx).t.text == "void") {
				            writeIntoErrorFile(
					                "Error at line " + std::to_string((((Var_declarationContext)_localctx).t!=null?(((Var_declarationContext)_localctx).t.stop):null)->getLine()) + ": Variable type cannot be void\n"
				            );
				            syntaxErrorCount++;
				            errorText = "Error at line " + std::to_string((((Var_declarationContext)_localctx).t!=null?(((Var_declarationContext)_localctx).t.stop):null)->getLine()) + ": Variable type cannot be void\n\n";
				        }
				        
				        writeIntoparserLogFile(
				            "Line " + std::to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON\n\n" +
				            errorText +
							_localctx.text + "\n"
				        );

					    //     for (auto &decl : ((Var_declarationContext)_localctx).dl.ids) {
				        //     std::string name = decl.first;

				        //     SymbolInfo* sym = symTable->lookup(name);
				        //     if (sym != nullptr) {
				        //         sym->setVariableType(((Var_declarationContext)_localctx).t.text);
				        //     }
				        // }

						
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(175);
				((Var_declarationContext)_localctx).t = type_specifier();
				setState(176);
				((Var_declarationContext)_localctx).de = declaration_list_err();
				setState(177);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

				        ((Var_declarationContext)_localctx).text =  ((Var_declarationContext)_localctx).t.text + " " + ((Var_declarationContext)_localctx).de.error_name + ((Var_declarationContext)_localctx).sm->getText();
				        
				        writeIntoErrorFile(
				            "Line " + std::to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": var_declaration : type_specifier declaration_list_err SEMICOLON\n\n" +
							_localctx.text + "\n"
				        );

				        syntaxErrorCount++;
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_list_errContext extends ParserRuleContext {
		public std::string error_name;
		public Declaration_list_errContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration_list_err; }
	}

	public final Declaration_list_errContext declaration_list_err() throws RecognitionException {
		Declaration_list_errContext _localctx = new Declaration_list_errContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_declaration_list_err);
		try {
			enterOuterAlt(_localctx, 1);
			{

			        ((Declaration_list_errContext)_localctx).error_name =  "Error in declaration list";
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Type_specifierContext extends ParserRuleContext {
		public std::string name_line;
		public std::string text;
		public Token INT;
		public Token FLOAT;
		public Token VOID;
		public TerminalNode INT() { return getToken(C8086Parser.INT, 0); }
		public TerminalNode FLOAT() { return getToken(C8086Parser.FLOAT, 0); }
		public TerminalNode VOID() { return getToken(C8086Parser.VOID, 0); }
		public Type_specifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_specifier; }
	}

	public final Type_specifierContext type_specifier() throws RecognitionException {
		Type_specifierContext _localctx = new Type_specifierContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_type_specifier);
		try {
			setState(190);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(184);
				((Type_specifierContext)_localctx).INT = match(INT);

				        ((Type_specifierContext)_localctx).text =  ((Type_specifierContext)_localctx).INT->getText();
				        ((Type_specifierContext)_localctx).name_line =  "Line " + std::to_string(((Type_specifierContext)_localctx).INT->getLine()) + ": type_specifier : INT\n\n" + _localctx.text + "\n";
				        writeIntoparserLogFile(_localctx.name_line);
				    
				}
				break;
			case FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(186);
				((Type_specifierContext)_localctx).FLOAT = match(FLOAT);

				        ((Type_specifierContext)_localctx).text =  ((Type_specifierContext)_localctx).FLOAT->getText();
				        ((Type_specifierContext)_localctx).name_line =  "Line " + std::to_string(((Type_specifierContext)_localctx).FLOAT->getLine()) + ": type_specifier : FLOAT\n\n" + _localctx.text + "\n";
				        writeIntoparserLogFile(_localctx.name_line);
				    
				}
				break;
			case VOID:
				enterOuterAlt(_localctx, 3);
				{
				setState(188);
				((Type_specifierContext)_localctx).VOID = match(VOID);

				        ((Type_specifierContext)_localctx).text =  ((Type_specifierContext)_localctx).VOID->getText();
				        ((Type_specifierContext)_localctx).name_line =  "Line " + std::to_string(((Type_specifierContext)_localctx).VOID->getLine()) + ": type_specifier : VOID\n\n" + _localctx.text + "\n";
				        writeIntoparserLogFile(_localctx.name_line);
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_listContext extends ParserRuleContext {
		public std::vector<std::pair<std::string, int>> ids;
		public std::string text;
		public Declaration_listContext d1;
		public Declaration_listContext d2;
		public Declaration_listContext d4;
		public Token id;
		public Token lt;
		public Token size;
		public Token rt;
		public Token error_recovery;
		public Invalid_paramContext ip;
		public Token cm;
		public Declaration_listContext d5;
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C8086Parser.LTHIRD, 0); }
		public TerminalNode CONST_INT() { return getToken(C8086Parser.CONST_INT, 0); }
		public TerminalNode RTHIRD() { return getToken(C8086Parser.RTHIRD, 0); }
		public List<Declaration_listContext> declaration_list() {
			return getRuleContexts(Declaration_listContext.class);
		}
		public Declaration_listContext declaration_list(int i) {
			return getRuleContext(Declaration_listContext.class,i);
		}
		public Invalid_paramContext invalid_param() {
			return getRuleContext(Invalid_paramContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(C8086Parser.COMMA, 0); }
		public Declaration_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration_list; }
	}

	public final Declaration_listContext declaration_list() throws RecognitionException {
		return declaration_list(0);
	}

	private Declaration_listContext declaration_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Declaration_listContext _localctx = new Declaration_listContext(_ctx, _parentState);
		Declaration_listContext _prevctx = _localctx;
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_declaration_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(202);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				{
				setState(193);
				((Declaration_listContext)_localctx).id = match(ID);

				        ((Declaration_listContext)_localctx).ids =  { { ((Declaration_listContext)_localctx).id->getText(), -1 } };
				        ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).id->getText();
							        std::string name = ((Declaration_listContext)_localctx).id->getText();
					
							std::string type = "ID";

					    SymbolInfo* sym = symTable->insert(name, type);
					
							if(!sym) {
					                writeIntoparserLogFile(
						                    "Error at line " + std::to_string(((Declaration_listContext)_localctx).id->getLine()) + ": Multiple declaration of " + name + "\n"
				                );
					                writeIntoErrorFile(
					                     "Error at line " + std::to_string(((Declaration_listContext)_localctx).id->getLine()) + ": Multiple declaration of " + name + "\n"
				                );
				                syntaxErrorCount++;
				            }
					    if(sym){
					            sym->setArray(false);
					                sym->setDeclared(true);
				                    sym->setVariableType(currentVarType);
					                    // cout<< ((Declaration_listContext)_localctx).id->getText()<<" isarray "<<sym->getArray()<<endl;
				        }
				        
						writeIntoparserLogFile(
							"Line " + std::to_string(((Declaration_listContext)_localctx).id->getLine()) + ": declaration_list : ID\n\n" +
							_localctx.text + "\n"
						);
				    
				}
				break;
			case 2:
				{
				setState(195);
				((Declaration_listContext)_localctx).id = match(ID);
				setState(196);
				((Declaration_listContext)_localctx).lt = match(LTHIRD);
				setState(197);
				((Declaration_listContext)_localctx).size = match(CONST_INT);
				setState(198);
				((Declaration_listContext)_localctx).rt = match(RTHIRD);

				        ((Declaration_listContext)_localctx).ids =  { { ((Declaration_listContext)_localctx).id->getText(), std::stoi(((Declaration_listContext)_localctx).size->getText()) } };
				        ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).id->getText() + ((Declaration_listContext)_localctx).lt->getText() + ((Declaration_listContext)_localctx).size->getText() + ((Declaration_listContext)_localctx).rt->getText();

					        		        std::string name = ((Declaration_listContext)_localctx).id->getText();
							
							std::string type = "ID";

				            SymbolInfo* sym = symTable->insert(name, type);        
					
							if(!sym) {
					                writeIntoparserLogFile(
						                    "Error at line " + std::to_string(((Declaration_listContext)_localctx).id->getLine()) + ": Multiple declaration of " + name + "\n"
				                );
					                writeIntoErrorFile(
					                     "Error at line " + std::to_string(((Declaration_listContext)_localctx).id->getLine()) + ": Multiple declaration of " + name + "\n"
				                );
				                syntaxErrorCount++;
				            }
					    if(sym){
					            sym->setArray(true);
				                    sym->setDeclared(true);
				                    sym->setVariableType(currentVarType);
					                    // cout<< ((Declaration_listContext)_localctx).id->getText()<<" isarray "<<sym->getArray()<<endl;
				        }  
				        
				        
						writeIntoparserLogFile(
							"Line " + std::to_string(((Declaration_listContext)_localctx).id->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n" +
							_localctx.text + "\n"
						);
				    
				}
				break;
			case 3:
				{
				setState(200);
				((Declaration_listContext)_localctx).error_recovery = matchWildcard();

				        
				        writeIntoparserLogFile(
				            "Error at line " + std::to_string(((Declaration_listContext)_localctx).error_recovery->getLine()) + 
				            ": syntax error in declaration_list, unexpected token '" + ((Declaration_listContext)_localctx).error_recovery->getText() + "'\n"
				        );
				        writeIntoErrorFile(
				            "Error at line " + std::to_string(((Declaration_listContext)_localctx).error_recovery->getLine()) + 
				            ": syntax error in declaration_list, unexpected token '" + ((Declaration_listContext)_localctx).error_recovery->getText() + "'\n"
				        );
				        syntaxErrorCount++;
				        
				        // Initialize return values to avoid parser errors
				        ((Declaration_listContext)_localctx).ids =  {};
				        ((Declaration_listContext)_localctx).text =  "";
				    
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(224);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(222);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
					case 1:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.d4 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(204);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(205);
						((Declaration_listContext)_localctx).ip = invalid_param();
						setState(206);
						((Declaration_listContext)_localctx).id = match(ID);
						setState(207);
						((Declaration_listContext)_localctx).cm = match(COMMA);
						setState(208);
						((Declaration_listContext)_localctx).d5 = declaration_list(3);

						                  
						                  ((Declaration_listContext)_localctx).ids =  ((Declaration_listContext)_localctx).d4.ids;
						                  _localctx.ids.insert(_localctx.ids.end(), ((Declaration_listContext)_localctx).d5.ids.begin(), ((Declaration_listContext)_localctx).d5.ids.end());
						                  ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).d4.text + ((Declaration_listContext)_localctx).cm->getText() + ((Declaration_listContext)_localctx).d5.text; // Skip the ADDOP and ID after it
						                  
						                  
						                  writeIntoErrorFile(
						                      "Error at line " + std::to_string(((Declaration_listContext)_localctx).cm->getLine()) + 
						          		            ": syntax error, unexpected " + ((Declaration_listContext)_localctx).ip.name + ", expecting COMMA or SEMICOLON\n"
						                  );
						                  writeIntoparserLogFile(
						                      "Error at line " + std::to_string(((Declaration_listContext)_localctx).cm->getLine()) + 
						                              ": syntax error, unexpected " + ((Declaration_listContext)_localctx).ip.name + ", expecting COMMA or SEMICOLON\n"
						                  );
						          	        writeIntoparserLogFile(
						          	            "Line " + std::to_string(((Declaration_listContext)_localctx).cm->getLine()) + ": declaration_list : declaration_list COMMA ID\n\n" +
						                      _localctx.text + "\n"
						                  );
						                  syntaxErrorCount++;
						              
						}
						break;
					case 2:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.d1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(211);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(212);
						((Declaration_listContext)_localctx).cm = match(COMMA);
						setState(213);
						((Declaration_listContext)_localctx).id = match(ID);

						                  ((Declaration_listContext)_localctx).ids =  ((Declaration_listContext)_localctx).d1.ids;
						                  _localctx.ids.push_back({((Declaration_listContext)_localctx).id->getText(), -1});
						                  ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).d1.text + ((Declaration_listContext)_localctx).cm->getText()  + ((Declaration_listContext)_localctx).id->getText();

						          		        std::string name = ((Declaration_listContext)_localctx).id->getText();
						          			
						          			std::string type = "ID";

						                      SymbolInfo* sym = symTable->insert(name, type);
						          	
						          			if(!sym) {
						          	                writeIntoparserLogFile(
						          		                    "Error at line " + std::to_string(((Declaration_listContext)_localctx).id->getLine()) + ": Multiple declaration of " + name + "\n"
						                          );
						                          writeIntoErrorFile(
						          	                     "Error at line " + std::to_string(((Declaration_listContext)_localctx).id->getLine()) + ": Multiple declaration of " + name + "\n"
						                          );
						                          syntaxErrorCount++;
						                      }
						          	    if(sym){
						          	            sym->setArray(false);
						          	                sym->setDeclared(true);
						                              sym->setVariableType(currentVarType);
						          		                    // cout<< ((Declaration_listContext)_localctx).id->getText()<<" isarray "<<sym->getArray()<<endl;
						                  }
						                  
						          		
						          		writeIntoparserLogFile(
						          			"Line " + std::to_string(((Declaration_listContext)_localctx).id->getLine()) + ": declaration_list : declaration_list COMMA ID\n\n" +
						          			_localctx.text + "\n"
						          		);
						              
						}
						break;
					case 3:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.d2 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(215);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(216);
						((Declaration_listContext)_localctx).cm = match(COMMA);
						setState(217);
						((Declaration_listContext)_localctx).id = match(ID);
						setState(218);
						((Declaration_listContext)_localctx).lt = match(LTHIRD);
						setState(219);
						((Declaration_listContext)_localctx).size = match(CONST_INT);
						setState(220);
						((Declaration_listContext)_localctx).rt = match(RTHIRD);

						                  ((Declaration_listContext)_localctx).ids =  ((Declaration_listContext)_localctx).d2.ids;
						                  _localctx.ids.push_back({((Declaration_listContext)_localctx).id->getText(), std::stoi(((Declaration_listContext)_localctx).size->getText())});
						                  ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).d2.text + ((Declaration_listContext)_localctx).cm->getText()  + ((Declaration_listContext)_localctx).id->getText() + ((Declaration_listContext)_localctx).lt->getText() + ((Declaration_listContext)_localctx).size->getText() + ((Declaration_listContext)_localctx).rt->getText();
						          	             std::string name = ((Declaration_listContext)_localctx).id->getText();
						          				
						          			std::string type = "ID";
						                      SymbolInfo* sym = symTable->insert(name, type);
						          			if(!sym) {
						          	                writeIntoparserLogFile(
						          		                    "Error at line " + std::to_string(((Declaration_listContext)_localctx).id->getLine()) + ": Multiple declaration of " + name + "\n"
						                          );
						                          writeIntoErrorFile(
						                                   "Error at line " + std::to_string(((Declaration_listContext)_localctx).id->getLine()) + ": Multiple declaration of " + name + "\n"
						                          );
						                          syntaxErrorCount++;
						                      }
						          		        if(sym){
						          	            sym->setArray(true);
						          	                sym->setDeclared(true);
						                              sym->setVariableType(currentVarType);
						          	                    // cout<< ((Declaration_listContext)_localctx).id->getText()<<" isarray "<<sym->getArray()<<endl;
						                  }
						                  
						          		writeIntoparserLogFile(
						          			"Line " + std::to_string(((Declaration_listContext)_localctx).id->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n" +
						          			_localctx.text + "\n"
						          		);
						              
						}
						break;
					}
					} 
				}
				setState(226);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementsContext extends ParserRuleContext {
		public std::string text;
		public std::string returnType;
		public StatementsContext sts;
		public StatementContext st;
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
	}

	public final StatementsContext statements() throws RecognitionException {
		return statements(0);
	}

	private StatementsContext statements(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		StatementsContext _localctx = new StatementsContext(_ctx, _parentState);
		StatementsContext _prevctx = _localctx;
		int _startState = 24;
		enterRecursionRule(_localctx, 24, RULE_statements, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(228);
			((StatementsContext)_localctx).st = statement();

			        ((StatementsContext)_localctx).text =  ((StatementsContext)_localctx).st.text;
			        ((StatementsContext)_localctx).returnType =  ((StatementsContext)_localctx).st.returnType;
			        if(_localctx.text!=""){
			        writeIntoparserLogFile(
			            "Line " + std::to_string((((StatementsContext)_localctx).st!=null?(((StatementsContext)_localctx).st.stop):null)->getLine()) + ": statements : statement\n\n" +
			            _localctx.text + "\n"
			        );
			        }
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(237);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new StatementsContext(_parentctx, _parentState);
					_localctx.sts = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_statements);
					setState(231);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(232);
					((StatementsContext)_localctx).st = statement();

					                  ((StatementsContext)_localctx).text =  ((StatementsContext)_localctx).sts.text +"\n"+ ((StatementsContext)_localctx).st.text;
					          	    if (!((StatementsContext)_localctx).st.returnType.empty())
					                      ((StatementsContext)_localctx).returnType =  ((StatementsContext)_localctx).st.returnType;
					                  else
					                      ((StatementsContext)_localctx).returnType =  ((StatementsContext)_localctx).sts.returnType;
					                  writeIntoparserLogFile(
					                      "Line " + std::to_string((((StatementsContext)_localctx).st!=null?(((StatementsContext)_localctx).st.stop):null)->getLine()) + ": statements : statements statement\n\n" +
					                      _localctx.text + "\n"
					                  );
					              
					}
					} 
				}
				setState(239);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementContext extends ParserRuleContext {
		public std::string text;
		public std::string returnType;
		public Var_declarationContext vd;
		public Expression_statementContext es;
		public Compound_statementContext cs;
		public Token f;
		public Token lp;
		public Expression_statementContext es1;
		public Expression_statementContext es2;
		public ExpressionContext e;
		public Token rp;
		public StatementContext st;
		public Token i;
		public StatementContext st1;
		public Token el;
		public StatementContext st2;
		public Token w;
		public Token p;
		public Token id;
		public Token sc;
		public Token r;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public List<Expression_statementContext> expression_statement() {
			return getRuleContexts(Expression_statementContext.class);
		}
		public Expression_statementContext expression_statement(int i) {
			return getRuleContext(Expression_statementContext.class,i);
		}
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public TerminalNode FOR() { return getToken(C8086Parser.FOR, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode IF() { return getToken(C8086Parser.IF, 0); }
		public TerminalNode ELSE() { return getToken(C8086Parser.ELSE, 0); }
		public TerminalNode WHILE() { return getToken(C8086Parser.WHILE, 0); }
		public TerminalNode PRINTLN() { return getToken(C8086Parser.PRINTLN, 0); }
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
		public TerminalNode RETURN() { return getToken(C8086Parser.RETURN, 0); }
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_statement);
		try {
			setState(293);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(240);
				((StatementContext)_localctx).vd = var_declaration();

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).vd.text;
					    ((StatementContext)_localctx).returnType =  "";
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((StatementContext)_localctx).vd!=null?(((StatementContext)_localctx).vd.stop):null)->getLine()) + ": statement : var_declaration\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(243);
				((StatementContext)_localctx).es = expression_statement();

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).es.text;
					        ((StatementContext)_localctx).returnType =  "";
				            if(_localctx.text!=""){
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((StatementContext)_localctx).es!=null?(((StatementContext)_localctx).es.stop):null)->getLine()) + ": statement : expression_statement\n\n" +
				            _localctx.text + "\n"
				        );
				            }
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{

					    std::vector<std::pair<std::string, std::string>> empty_ids;
				        symTable->EnterScope();
					  
				setState(247);
				((StatementContext)_localctx).cs = compound_statement(empty_ids);

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).cs.text;
					        ((StatementContext)_localctx).returnType =  "";
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((StatementContext)_localctx).cs!=null?(((StatementContext)_localctx).cs.stop):null)->getLine()) + ": statement : compound_statement\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(250);
				((StatementContext)_localctx).f = match(FOR);
				setState(251);
				((StatementContext)_localctx).lp = match(LPAREN);
				setState(252);
				((StatementContext)_localctx).es1 = expression_statement();
				setState(253);
				((StatementContext)_localctx).es2 = expression_statement();
				setState(254);
				((StatementContext)_localctx).e = expression();
				setState(255);
				((StatementContext)_localctx).rp = match(RPAREN);
				setState(256);
				((StatementContext)_localctx).st = statement();

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).f->getText()  + ((StatementContext)_localctx).lp->getText() + ((StatementContext)_localctx).es1.text  + ((StatementContext)_localctx).es2.text  + ((StatementContext)_localctx).e.text + ((StatementContext)_localctx).rp->getText()  + ((StatementContext)_localctx).st.text;
					        ((StatementContext)_localctx).returnType =  "";
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((StatementContext)_localctx).st!=null?(((StatementContext)_localctx).st.stop):null)->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(259);
				((StatementContext)_localctx).i = match(IF);
				setState(260);
				((StatementContext)_localctx).lp = match(LPAREN);
				setState(261);
				((StatementContext)_localctx).e = expression();
				setState(262);
				((StatementContext)_localctx).rp = match(RPAREN);
				setState(263);
				((StatementContext)_localctx).st = statement();

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).i->getText()  + ((StatementContext)_localctx).lp->getText() + ((StatementContext)_localctx).e.text + ((StatementContext)_localctx).rp->getText()  + ((StatementContext)_localctx).st.text;
					        ((StatementContext)_localctx).returnType =  ((StatementContext)_localctx).st.returnType;
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((StatementContext)_localctx).st!=null?(((StatementContext)_localctx).st.stop):null)->getLine()) + ": statement : IF LPAREN expression RPAREN statement\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(266);
				((StatementContext)_localctx).i = match(IF);
				setState(267);
				((StatementContext)_localctx).lp = match(LPAREN);
				setState(268);
				((StatementContext)_localctx).e = expression();
				setState(269);
				((StatementContext)_localctx).rp = match(RPAREN);
				setState(270);
				((StatementContext)_localctx).st1 = statement();
				setState(271);
				((StatementContext)_localctx).el = match(ELSE);
				setState(272);
				((StatementContext)_localctx).st2 = statement();

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).i->getText() + ((StatementContext)_localctx).lp->getText() + ((StatementContext)_localctx).e.text + ((StatementContext)_localctx).rp->getText() + ((StatementContext)_localctx).st1.text + ((StatementContext)_localctx).el->getText()+" "  + ((StatementContext)_localctx).st2.text;
					    if (!((StatementContext)_localctx).st1.returnType.empty() && ((StatementContext)_localctx).st1.returnType == ((StatementContext)_localctx).st2.returnType)
				            ((StatementContext)_localctx).returnType =  ((StatementContext)_localctx).st1.returnType;
				        else
				            ((StatementContext)_localctx).returnType =  ""; // mismatch or one branch doesn't return
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((StatementContext)_localctx).st2!=null?(((StatementContext)_localctx).st2.stop):null)->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(275);
				((StatementContext)_localctx).w = match(WHILE);
				setState(276);
				((StatementContext)_localctx).lp = match(LPAREN);
				setState(277);
				((StatementContext)_localctx).e = expression();
				setState(278);
				((StatementContext)_localctx).rp = match(RPAREN);
				setState(279);
				((StatementContext)_localctx).st = statement();

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).w->getText()  + ((StatementContext)_localctx).lp->getText() + ((StatementContext)_localctx).e.text + ((StatementContext)_localctx).rp->getText()  + ((StatementContext)_localctx).st.text;
					        ((StatementContext)_localctx).returnType =  ""; // loop body might not return
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((StatementContext)_localctx).st!=null?(((StatementContext)_localctx).st.stop):null)->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(282);
				((StatementContext)_localctx).p = match(PRINTLN);
				setState(283);
				((StatementContext)_localctx).lp = match(LPAREN);
				setState(284);
				((StatementContext)_localctx).id = match(ID);
				setState(285);
				((StatementContext)_localctx).rp = match(RPAREN);
				setState(286);
				((StatementContext)_localctx).sc = match(SEMICOLON);

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).p->getText() + ((StatementContext)_localctx).lp->getText() + ((StatementContext)_localctx).id->getText() + ((StatementContext)_localctx).rp->getText() + ((StatementContext)_localctx).sc->getText();
					        ((StatementContext)_localctx).returnType =  "";
				        string errorText = "";
				        SymbolInfo* sym = symTable->lookup(((StatementContext)_localctx).id->getText());
				        if(!sym){
				            writeIntoErrorFile("Error at line " + std::to_string(((StatementContext)_localctx).id->getLine()) + ": Undeclared variable " + ((StatementContext)_localctx).id->getText() + "\n");
				            syntaxErrorCount++;
				            errorText = "Error at line " + std::to_string(((StatementContext)_localctx).id->getLine()) + ": Undeclared variable " + ((StatementContext)_localctx).id->getText() + "\n\n";
				            // writeIntoparserLogFile(
				            //     "Line " + std::to_string(((StatementContext)_localctx).sc->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n" +
				            //     _localctx.text + "\n"
				            // );
				        }

					        writeIntoparserLogFile(
				            "Line " + std::to_string(((StatementContext)_localctx).sc->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n" +
				            errorText +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(288);
				((StatementContext)_localctx).r = match(RETURN);
				setState(289);
				((StatementContext)_localctx).e = expression();
				setState(290);
				((StatementContext)_localctx).sc = match(SEMICOLON);

				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).r->getText() + " " + ((StatementContext)_localctx).e.text + ((StatementContext)_localctx).sc->getText();
					    ((StatementContext)_localctx).returnType =  ((StatementContext)_localctx).e.type;
				        writeIntoparserLogFile(
				            "Line " + std::to_string(((StatementContext)_localctx).sc->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Expression_statementContext extends ParserRuleContext {
		public std::string text;
		public Token sc;
		public ExpressionContext e;
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Expression_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression_statement; }
	}

	public final Expression_statementContext expression_statement() throws RecognitionException {
		Expression_statementContext _localctx = new Expression_statementContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_expression_statement);
		try {
			setState(301);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SEMICOLON:
				enterOuterAlt(_localctx, 1);
				{
				setState(295);
				((Expression_statementContext)_localctx).sc = match(SEMICOLON);

				        ((Expression_statementContext)_localctx).text =  ((Expression_statementContext)_localctx).sc->getText();
				        writeIntoparserLogFile(
				            "Line " + std::to_string(((Expression_statementContext)_localctx).sc->getLine()) + ": expression_statement : SEMICOLON\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case LPAREN:
			case ADDOP:
			case NOT:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(297);
				((Expression_statementContext)_localctx).e = expression();
				setState(298);
				((Expression_statementContext)_localctx).sc = match(SEMICOLON);

					    ((Expression_statementContext)_localctx).text =  "";
				    
				    std::string semicolonText = ((Expression_statementContext)_localctx).sc->getText();
				    bool semicolonMissing = (semicolonText.find("missing") != std::string::npos);

				    if (semicolonMissing==false) {
					    ((Expression_statementContext)_localctx).text =  ((Expression_statementContext)_localctx).e.text;
				        _localctx.text += semicolonText;

				        writeIntoparserLogFile(
				            "Line " + std::to_string((((Expression_statementContext)_localctx).e!=null?(((Expression_statementContext)_localctx).e.stop):null)->getLine()) + ": expression_statement : expression SEMICOLON\n\n" +
				            _localctx.text + "\n"
				        );
				    }

				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VariableContext extends ParserRuleContext {
		public std::string text;
		public std::string type;
		public bool isArray;
		public bool reallyArray;
		public bool declared;
		public Token id;
		public Token lt;
		public ExpressionContext e;
		public Token rt;
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C8086Parser.LTHIRD, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RTHIRD() { return getToken(C8086Parser.RTHIRD, 0); }
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_variable);
		try {
			setState(311);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(303);
				((VariableContext)_localctx).id = match(ID);

				        ((VariableContext)_localctx).text =  ((VariableContext)_localctx).id->getText();
				        string errorText = "";

				        SymbolInfo* sym = symTable->lookup(((VariableContext)_localctx).id->getText());
				        
				        if(sym!=nullptr){
					            ((VariableContext)_localctx).type =  sym->getVariableType();
				            ((VariableContext)_localctx).isArray =  false;
				            ((VariableContext)_localctx).reallyArray =  sym->getArray();
				            ((VariableContext)_localctx).declared =  true;

					        if(_localctx.reallyArray==true && _localctx.isArray==false) {
						        writeIntoErrorFile("Error at line " + std::to_string(((VariableContext)_localctx).id->getLine()) + ": Type mismatch, " + _localctx.text + " is an array\n");
				                errorText = "Error at line " + std::to_string(((VariableContext)_localctx).id->getLine()) + ": Type mismatch, " + _localctx.text + " is an array\n\n";
				        syntaxErrorCount++;
				    }
				        }
				        
				        else{
					            ((VariableContext)_localctx).type =  "void";
				                ((VariableContext)_localctx).isArray =  false;
				                ((VariableContext)_localctx).reallyArray =  false;
					            ((VariableContext)_localctx).declared =  false;

					                writeIntoErrorFile("Error at line " + std::to_string(((VariableContext)_localctx).id->getLine()) + ": Undeclared variable " + ((VariableContext)_localctx).id->getText()+"\n");
				            errorText = "Error at line " + std::to_string(((VariableContext)_localctx).id->getLine()) + ": Undeclared variable " + ((VariableContext)_localctx).id->getText() + "\n\n";
					
				            syntaxErrorCount++;
				        }
				        
				        writeIntoparserLogFile(
				            "Line " + std::to_string(((VariableContext)_localctx).id->getLine()) + ": variable : ID\n\n" + errorText +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(305);
				((VariableContext)_localctx).id = match(ID);
				setState(306);
				((VariableContext)_localctx).lt = match(LTHIRD);
				setState(307);
				((VariableContext)_localctx).e = expression();
				setState(308);
				((VariableContext)_localctx).rt = match(RTHIRD);

				        ((VariableContext)_localctx).text =  ((VariableContext)_localctx).id->getText() + ((VariableContext)_localctx).lt->getText() + ((VariableContext)_localctx).e.text + ((VariableContext)_localctx).rt->getText();
				        

				        SymbolInfo* sym = symTable->lookup(((VariableContext)_localctx).id->getText());
				        string errorText = "";
				        
					        if(sym!=nullptr){
					            ((VariableContext)_localctx).type =  sym->getVariableType();
				            ((VariableContext)_localctx).isArray =  true;
				            ((VariableContext)_localctx).reallyArray =  sym->getArray();
					            ((VariableContext)_localctx).declared =  true;

				                if(_localctx.isArray==true && _localctx.reallyArray==false) {
							                    writeIntoErrorFile("Error at line "+std::to_string(((VariableContext)_localctx).id->getLine()) +": "+ ((VariableContext)_localctx).id->getText()+ " not an array\n");
					            errorText = "Error at line " + std::to_string(((VariableContext)_localctx).id->getLine())+": " + ((VariableContext)_localctx).id->getText() + " not an array\n\n";
				            syntaxErrorCount++;
				                }
				        }
				        
				        else{
					            ((VariableContext)_localctx).type =  "void";
				                ((VariableContext)_localctx).isArray =  false;
				                ((VariableContext)_localctx).reallyArray =  false;
					                ((VariableContext)_localctx).declared =  false;

					                    writeIntoErrorFile("Line " + std::to_string(((VariableContext)_localctx).id->getLine()) + ": Undeclared array '" + ((VariableContext)_localctx).id->getText() + "'");
				            errorText = "Line " + std::to_string(((VariableContext)_localctx).id->getLine()) + ": Undeclared array '" + ((VariableContext)_localctx).id->getText() + "'\n\n";
				            syntaxErrorCount++;
				        }
				        if (((VariableContext)_localctx).e.type != "int") {
						            writeIntoErrorFile("Error at line " + std::to_string(((VariableContext)_localctx).id->getLine()) + ": Expression inside third brackets not an integer\n");
				            errorText = "Error at line " + std::to_string(((VariableContext)_localctx).id->getLine()) + ": Expression inside third brackets not an integer\n\n";
				            syntaxErrorCount++;
				        }

					       

				        writeIntoparserLogFile(
				            "Line " + std::to_string(((VariableContext)_localctx).id->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n\n" + errorText +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public std::string text;
		public std::string type;
		public bool isArray;
		public Logic_expressionContext le;
		public VariableContext v;
		public Token ao;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ASSIGNOP() { return getToken(C8086Parser.ASSIGNOP, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_expression);
		try {
			setState(321);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(313);
				((ExpressionContext)_localctx).le = logic_expression();

				        ((ExpressionContext)_localctx).text =  ((ExpressionContext)_localctx).le.text;
				        ((ExpressionContext)_localctx).type =  ((ExpressionContext)_localctx).le.type;
				        ((ExpressionContext)_localctx).isArray =  ((ExpressionContext)_localctx).le.isArray;
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((ExpressionContext)_localctx).le!=null?(((ExpressionContext)_localctx).le.stop):null)->getLine()) + ": expression : logic_expression\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(316);
				((ExpressionContext)_localctx).v = variable();
				setState(317);
				((ExpressionContext)_localctx).ao = match(ASSIGNOP);
				setState(318);
				((ExpressionContext)_localctx).le = logic_expression();

				        ((ExpressionContext)_localctx).text =  ((ExpressionContext)_localctx).v.text  + ((ExpressionContext)_localctx).ao->getText()  + ((ExpressionContext)_localctx).le.text;
					        
					    string lhsType = ((ExpressionContext)_localctx).v.type;
				        ((ExpressionContext)_localctx).isArray =  ((ExpressionContext)_localctx).v.reallyArray;

				        
				        
				        

				    string rhsType = ((ExpressionContext)_localctx).le.type;

				    string errortext="" ;

				    if(((ExpressionContext)_localctx).v.declared == false){}

				    else if (rhsType == "void") {
					        writeIntoErrorFile("Error at line " + std::to_string((((ExpressionContext)_localctx).v!=null?(((ExpressionContext)_localctx).v.start):null)->getLine()) + ": Void function used in expression\n");
					        errortext = "Error at line " + std::to_string((((ExpressionContext)_localctx).v!=null?(((ExpressionContext)_localctx).v.start):null)->getLine()) + ": Void function used in expression\n\n";
				        syntaxErrorCount++;
				    } else if (!(lhsType=="float" && rhsType=="int") && lhsType != rhsType && rhsType != "undefined") {
				        writeIntoErrorFile("Error at line " + std::to_string((((ExpressionContext)_localctx).v!=null?(((ExpressionContext)_localctx).v.start):null)->getLine()) + ": Type Mismatch\n" );
				        errortext = "Error at line " + std::to_string((((ExpressionContext)_localctx).v!=null?(((ExpressionContext)_localctx).v.start):null)->getLine()) + ": Type Mismatch\n\n";
				        syntaxErrorCount++;
				    }
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((ExpressionContext)_localctx).v!=null?(((ExpressionContext)_localctx).v.stop):null)->getLine()) + ": expression : variable ASSIGNOP logic_expression\n\n" + errortext +
				            _localctx.text + "\n"
				        );
						        ((ExpressionContext)_localctx).type =  rhsType;
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Logic_expressionContext extends ParserRuleContext {
		public std::string text;
		public std::string type;
		public bool isArray;
		public Rel_expressionContext re;
		public Rel_expressionContext re1;
		public Token lo;
		public Rel_expressionContext re2;
		public List<Rel_expressionContext> rel_expression() {
			return getRuleContexts(Rel_expressionContext.class);
		}
		public Rel_expressionContext rel_expression(int i) {
			return getRuleContext(Rel_expressionContext.class,i);
		}
		public TerminalNode LOGICOP() { return getToken(C8086Parser.LOGICOP, 0); }
		public Logic_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logic_expression; }
	}

	public final Logic_expressionContext logic_expression() throws RecognitionException {
		Logic_expressionContext _localctx = new Logic_expressionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_logic_expression);
		try {
			setState(331);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(323);
				((Logic_expressionContext)_localctx).re = rel_expression();

				        ((Logic_expressionContext)_localctx).text =  ((Logic_expressionContext)_localctx).re.text;
				        ((Logic_expressionContext)_localctx).type =  ((Logic_expressionContext)_localctx).re.type;
				        ((Logic_expressionContext)_localctx).isArray =  ((Logic_expressionContext)_localctx).re.isArray; 
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((Logic_expressionContext)_localctx).re!=null?(((Logic_expressionContext)_localctx).re.stop):null)->getLine()) + ": logic_expression : rel_expression\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(326);
				((Logic_expressionContext)_localctx).re1 = rel_expression();
				setState(327);
				((Logic_expressionContext)_localctx).lo = match(LOGICOP);
				setState(328);
				((Logic_expressionContext)_localctx).re2 = rel_expression();

				        ((Logic_expressionContext)_localctx).text =  ((Logic_expressionContext)_localctx).re1.text + ((Logic_expressionContext)_localctx).lo->getText() + ((Logic_expressionContext)_localctx).re2.text;
				        ((Logic_expressionContext)_localctx).type =  "int";
				        ((Logic_expressionContext)_localctx).isArray =  ((Logic_expressionContext)_localctx).re1.isArray; 
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((Logic_expressionContext)_localctx).re1!=null?(((Logic_expressionContext)_localctx).re1.stop):null)->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Rel_expressionContext extends ParserRuleContext {
		public std::string text;
		public std::string type;
		public bool isArray;
		public Simple_expressionContext se;
		public Simple_expressionContext se1;
		public Token ro;
		public Simple_expressionContext se2;
		public List<Simple_expressionContext> simple_expression() {
			return getRuleContexts(Simple_expressionContext.class);
		}
		public Simple_expressionContext simple_expression(int i) {
			return getRuleContext(Simple_expressionContext.class,i);
		}
		public TerminalNode RELOP() { return getToken(C8086Parser.RELOP, 0); }
		public Rel_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rel_expression; }
	}

	public final Rel_expressionContext rel_expression() throws RecognitionException {
		Rel_expressionContext _localctx = new Rel_expressionContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_rel_expression);
		try {
			setState(341);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(333);
				((Rel_expressionContext)_localctx).se = simple_expression(0);

				        ((Rel_expressionContext)_localctx).text =  ((Rel_expressionContext)_localctx).se.text;
				        ((Rel_expressionContext)_localctx).type =  ((Rel_expressionContext)_localctx).se.type;
				        ((Rel_expressionContext)_localctx).isArray =  ((Rel_expressionContext)_localctx).se.isArray; 
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((Rel_expressionContext)_localctx).se!=null?(((Rel_expressionContext)_localctx).se.stop):null)->getLine()) + ": rel_expression : simple_expression\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(336);
				((Rel_expressionContext)_localctx).se1 = simple_expression(0);
				setState(337);
				((Rel_expressionContext)_localctx).ro = match(RELOP);
				setState(338);
				((Rel_expressionContext)_localctx).se2 = simple_expression(0);

				        ((Rel_expressionContext)_localctx).text =  ((Rel_expressionContext)_localctx).se1.text + ((Rel_expressionContext)_localctx).ro->getText() + ((Rel_expressionContext)_localctx).se2.text;
				        ((Rel_expressionContext)_localctx).type =  "int"; 
				        ((Rel_expressionContext)_localctx).isArray =  ((Rel_expressionContext)_localctx).se1.isArray;
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((Rel_expressionContext)_localctx).se1!=null?(((Rel_expressionContext)_localctx).se1.stop):null)->getLine()) + ": rel_expression : simple_expression RELOP simple_expression\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Simple_expressionContext extends ParserRuleContext {
		public std::string text;
		public std::string type;
		public bool isArray;
		public Simple_expressionContext se;
		public TermContext t;
		public Token ao;
		public Token invalid_op;
		public Simple_expressionContext se2;
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public List<Simple_expressionContext> simple_expression() {
			return getRuleContexts(Simple_expressionContext.class);
		}
		public Simple_expressionContext simple_expression(int i) {
			return getRuleContext(Simple_expressionContext.class,i);
		}
		public TerminalNode ADDOP() { return getToken(C8086Parser.ADDOP, 0); }
		public TerminalNode ASSIGNOP() { return getToken(C8086Parser.ASSIGNOP, 0); }
		public Simple_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_expression; }
	}

	public final Simple_expressionContext simple_expression() throws RecognitionException {
		return simple_expression(0);
	}

	private Simple_expressionContext simple_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Simple_expressionContext _localctx = new Simple_expressionContext(_ctx, _parentState);
		Simple_expressionContext _prevctx = _localctx;
		int _startState = 38;
		enterRecursionRule(_localctx, 38, RULE_simple_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(344);
			((Simple_expressionContext)_localctx).t = term(0);

			        ((Simple_expressionContext)_localctx).text =  ((Simple_expressionContext)_localctx).t.text;
			        ((Simple_expressionContext)_localctx).type =  ((Simple_expressionContext)_localctx).t.type; 
			        ((Simple_expressionContext)_localctx).isArray =  ((Simple_expressionContext)_localctx).t.isArray;
			        writeIntoparserLogFile(
			            "Line " + std::to_string((((Simple_expressionContext)_localctx).t!=null?(((Simple_expressionContext)_localctx).t.stop):null)->getLine()) + ": simple_expression : term\n\n" +
			            _localctx.text + "\n"
			        );
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(360);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(358);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,21,_ctx) ) {
					case 1:
						{
						_localctx = new Simple_expressionContext(_parentctx, _parentState);
						_localctx.se = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_simple_expression);
						setState(347);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(348);
						((Simple_expressionContext)_localctx).ao = match(ADDOP);
						setState(349);
						((Simple_expressionContext)_localctx).invalid_op = match(ASSIGNOP);
						setState(350);
						((Simple_expressionContext)_localctx).se2 = simple_expression(2);

						              
						              ((Simple_expressionContext)_localctx).text =  ((Simple_expressionContext)_localctx).se.text;
						              ((Simple_expressionContext)_localctx).type =  ((Simple_expressionContext)_localctx).se.type;
						              ((Simple_expressionContext)_localctx).isArray =  ((Simple_expressionContext)_localctx).se.isArray;
						              
						              // writeIntoparserLogFile(
						              //     "Line " + std::to_string((((Simple_expressionContext)_localctx).se!=null?(((Simple_expressionContext)_localctx).se.stop):null)->getLine()) + ": simple_expression : term\n\n" +
						              //     ((Simple_expressionContext)_localctx).se.text + "\n"
						              // );
						              
						              writeIntoparserLogFile(
						                  "Error at line " + std::to_string(((Simple_expressionContext)_localctx).invalid_op->getLine()) + ": syntax error, unexpected ASSIGNOP\n\n"
						              );
						              writeIntoErrorFile(
						                  "Error at line " + std::to_string(((Simple_expressionContext)_localctx).invalid_op->getLine()) + ": syntax error, unexpected ASSIGNOP\n"
						              );
						              syntaxErrorCount++;
						          
						}
						break;
					case 2:
						{
						_localctx = new Simple_expressionContext(_parentctx, _parentState);
						_localctx.se = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_simple_expression);
						setState(353);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(354);
						((Simple_expressionContext)_localctx).ao = match(ADDOP);
						setState(355);
						((Simple_expressionContext)_localctx).t = term(0);

						                  ((Simple_expressionContext)_localctx).text =  ((Simple_expressionContext)_localctx).se.text  + ((Simple_expressionContext)_localctx).ao->getText()  + ((Simple_expressionContext)_localctx).t.text;
						                  ((Simple_expressionContext)_localctx).isArray =  ((Simple_expressionContext)_localctx).se.isArray;
						                  
						                  if (((Simple_expressionContext)_localctx).se.type == "float" || ((Simple_expressionContext)_localctx).t.type == "float")
						                      ((Simple_expressionContext)_localctx).type =  "float";
						                  else
						                      ((Simple_expressionContext)_localctx).type =  "int";
						                  writeIntoparserLogFile(
						                      "Line " + std::to_string((((Simple_expressionContext)_localctx).se!=null?(((Simple_expressionContext)_localctx).se.stop):null)->getLine()) + ": simple_expression : simple_expression ADDOP term\n\n" +
						                      _localctx.text + "\n"
						                  );
						              
						}
						break;
					}
					} 
				}
				setState(362);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TermContext extends ParserRuleContext {
		public std::string text;
		public std::string type;
		public bool isArray;
		public TermContext t;
		public Unary_expressionContext ue;
		public Token mo;
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TerminalNode MULOP() { return getToken(C8086Parser.MULOP, 0); }
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
	}

	public final TermContext term() throws RecognitionException {
		return term(0);
	}

	private TermContext term(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		TermContext _localctx = new TermContext(_ctx, _parentState);
		TermContext _prevctx = _localctx;
		int _startState = 40;
		enterRecursionRule(_localctx, 40, RULE_term, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(364);
			((TermContext)_localctx).ue = unary_expression();

			        ((TermContext)_localctx).text =  ((TermContext)_localctx).ue.text;
			        ((TermContext)_localctx).type =  ((TermContext)_localctx).ue.type;
			        ((TermContext)_localctx).isArray =  ((TermContext)_localctx).ue.isArray;
			        writeIntoparserLogFile(
			            "Line " + std::to_string((((TermContext)_localctx).ue!=null?(((TermContext)_localctx).ue.stop):null)->getLine()) + ": term : unary_expression\n\n" +
			            _localctx.text + "\n"
			        );
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(374);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new TermContext(_parentctx, _parentState);
					_localctx.t = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_term);
					setState(367);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(368);
					((TermContext)_localctx).mo = match(MULOP);
					setState(369);
					((TermContext)_localctx).ue = unary_expression();

					                  ((TermContext)_localctx).text =  ((TermContext)_localctx).t.text + ((TermContext)_localctx).mo->getText()  + ((TermContext)_localctx).ue.text;
					                  ((TermContext)_localctx).isArray =  ((TermContext)_localctx).t.isArray;
					                  string errorText = "";
					                  if (((TermContext)_localctx).mo->getText() == "%") {
					                      if (((TermContext)_localctx).t.type != "int" || ((TermContext)_localctx).ue.type != "int") {
					                          ((TermContext)_localctx).type =  "undefined";
					                          writeIntoErrorFile(
					          	                    "Error at line " + std::to_string(((TermContext)_localctx).mo->getLine()) + ": Non-Integer operand on modulus operator\n"
					                                  
					                          );
					                          errorText = "Error at line " + std::to_string(((TermContext)_localctx).mo->getLine()) + ": Non-Integer operand on modulus operator\n\n";
					                          syntaxErrorCount++;
					                      }

					          	            else if(((TermContext)_localctx).ue.text == "0"){ 
					                              ((TermContext)_localctx).type =  "undefined";
					                          writeIntoErrorFile(
					          	                        "Error at line " + std::to_string(((TermContext)_localctx).mo->getLine()) + ": Modulus by Zero\n"
					                          );
					                          errorText = "Error at line " + std::to_string(((TermContext)_localctx).mo->getLine()) + ": Modulus by Zero\n\n";
					                          syntaxErrorCount++;
					                          }

					          	       
					                      else
					                      ((TermContext)_localctx).type =  "int";
					                  } else if (((TermContext)_localctx).t.type == "float" || ((TermContext)_localctx).ue.type == "float") {
					                      ((TermContext)_localctx).type =  "float";
					                  } 
					          	    else if (((TermContext)_localctx).t.type == "void" || ((TermContext)_localctx).ue.type == "void") {
					          	            writeIntoErrorFile("Error at line " + std::to_string((((TermContext)_localctx).t!=null?(((TermContext)_localctx).t.stop):null)->getLine()) + ": Void function used in expression\n");
					                          syntaxErrorCount++;
					                          ((TermContext)_localctx).type =  "undefined";
					                          errorText = "Error at line " + std::to_string((((TermContext)_localctx).t!=null?(((TermContext)_localctx).t.stop):null)->getLine()) + ": Void function used in expression\n\n";
					                      }
					                  else {
					                      ((TermContext)_localctx).type =  "int";
					                  }

					                  writeIntoparserLogFile(
					                      "Line " + std::to_string((((TermContext)_localctx).t!=null?(((TermContext)_localctx).t.stop):null)->getLine()) + ": term : term MULOP unary_expression\n\n" + errorText +
					                      _localctx.text + "\n"
					                  );
					              
					}
					} 
				}
				setState(376);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Unary_expressionContext extends ParserRuleContext {
		public std::string text;
		public std::string type;
		public bool isArray;
		public Token ao;
		public Unary_expressionContext ue;
		public Token n;
		public FactorContext f;
		public TerminalNode ADDOP() { return getToken(C8086Parser.ADDOP, 0); }
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode NOT() { return getToken(C8086Parser.NOT, 0); }
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public Unary_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_expression; }
	}

	public final Unary_expressionContext unary_expression() throws RecognitionException {
		Unary_expressionContext _localctx = new Unary_expressionContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_unary_expression);
		try {
			setState(388);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADDOP:
				enterOuterAlt(_localctx, 1);
				{
				setState(377);
				((Unary_expressionContext)_localctx).ao = match(ADDOP);
				setState(378);
				((Unary_expressionContext)_localctx).ue = unary_expression();

				        ((Unary_expressionContext)_localctx).text =  ((Unary_expressionContext)_localctx).ao->getText() + ((Unary_expressionContext)_localctx).ue.text;
				        ((Unary_expressionContext)_localctx).type =  ((Unary_expressionContext)_localctx).ue.type;
				        ((Unary_expressionContext)_localctx).isArray =  ((Unary_expressionContext)_localctx).ue.isArray;
				        writeIntoparserLogFile(
				            "Line " + std::to_string(((Unary_expressionContext)_localctx).ao->getLine()) + ": unary_expression : ADDOP unary_expression\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case NOT:
				enterOuterAlt(_localctx, 2);
				{
				setState(381);
				((Unary_expressionContext)_localctx).n = match(NOT);
				setState(382);
				((Unary_expressionContext)_localctx).ue = unary_expression();

				        ((Unary_expressionContext)_localctx).text =  ((Unary_expressionContext)_localctx).n->getText() + ((Unary_expressionContext)_localctx).ue.text;
				        ((Unary_expressionContext)_localctx).type =  "int"; 
					    ((Unary_expressionContext)_localctx).isArray =  ((Unary_expressionContext)_localctx).ue.isArray;
				        writeIntoparserLogFile(
				            "Line " + std::to_string(((Unary_expressionContext)_localctx).n->getLine()) + ": unary_expression : NOT unary_expression\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case LPAREN:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 3);
				{
				setState(385);
				((Unary_expressionContext)_localctx).f = factor();

				        ((Unary_expressionContext)_localctx).text =  ((Unary_expressionContext)_localctx).f.text;
				        ((Unary_expressionContext)_localctx).type =  ((Unary_expressionContext)_localctx).f.type;
				        ((Unary_expressionContext)_localctx).isArray =  ((Unary_expressionContext)_localctx).f.isArray;
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((Unary_expressionContext)_localctx).f!=null?(((Unary_expressionContext)_localctx).f.stop):null)->getLine()) + ": unary_expression : factor\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FactorContext extends ParserRuleContext {
		public std::string text;
		public std::string type;
		public bool isArray;
		public VariableContext v;
		public Token id;
		public Token lp;
		public Argument_listContext al;
		public Token rp;
		public ExpressionContext e;
		public Token ci;
		public Token cf;
		public Token ic;
		public Token dc;
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public Argument_listContext argument_list() {
			return getRuleContext(Argument_listContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CONST_INT() { return getToken(C8086Parser.CONST_INT, 0); }
		public TerminalNode CONST_FLOAT() { return getToken(C8086Parser.CONST_FLOAT, 0); }
		public TerminalNode INCOP() { return getToken(C8086Parser.INCOP, 0); }
		public TerminalNode DECOP() { return getToken(C8086Parser.DECOP, 0); }
		public FactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factor; }
	}

	public final FactorContext factor() throws RecognitionException {
		FactorContext _localctx = new FactorContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_factor);
		try {
			setState(416);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(390);
				((FactorContext)_localctx).v = variable();

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).v.text;
					    
				        
				            
					            ((FactorContext)_localctx).isArray =  ((FactorContext)_localctx).v.reallyArray;
				        
				            ((FactorContext)_localctx).type =  ((FactorContext)_localctx).v.type;

				        writeIntoparserLogFile(
				            "Line " + std::to_string((((FactorContext)_localctx).v!=null?(((FactorContext)_localctx).v.stop):null)->getLine()) + ": factor : variable\n\n" + _localctx.text + "\n"
				        );
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(393);
				((FactorContext)_localctx).id = match(ID);
				setState(394);
				((FactorContext)_localctx).lp = match(LPAREN);
				setState(395);
				((FactorContext)_localctx).al = argument_list();
				setState(396);
				((FactorContext)_localctx).rp = match(RPAREN);

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).id->getText() + ((FactorContext)_localctx).lp->getText() + ((FactorContext)_localctx).al.text + ((FactorContext)_localctx).rp->getText();
				        string errorText = "";
				        SymbolInfo* sym = symTable->lookup(((FactorContext)_localctx).id->getText());

				        

				        if (sym == nullptr) {
				            ((FactorContext)_localctx).type =  "undefined";
				            writeIntoErrorFile("Error at line " + std::to_string(((FactorContext)_localctx).id->getLine()) + ": Undefined function " + ((FactorContext)_localctx).id->getText() + "\n");
				            syntaxErrorCount++;
				            errorText = "Error at line " + std::to_string(((FactorContext)_localctx).id->getLine()) + ": Undefined function " + ((FactorContext)_localctx).id->getText() + "\n\n";
				        } 
				        else if (!sym->getFunction()) {
				            ((FactorContext)_localctx).type =  "undefined";
				            writeIntoErrorFile("Line " + std::to_string(((FactorContext)_localctx).id->getLine()) + ": '" + ((FactorContext)_localctx).id->getText() + "' is not a function");
				            syntaxErrorCount++;
				            errorText = "Line " + std::to_string(((FactorContext)_localctx).id->getLine()) + ": '" + ((FactorContext)_localctx).id->getText() + "' is not a function\n\n";
				        } else {
				            ((FactorContext)_localctx).type =  sym->getVariableType();  
				            ((FactorContext)_localctx).isArray =  false;
				          
				            int expected = sym->getParamCount();
				            if (expected != ((FactorContext)_localctx).al.types.size()) {
					                writeIntoErrorFile("Error at line " + std::to_string(((FactorContext)_localctx).id->getLine()) + ": Total number of arguments mismatch with declaration in function " + ((FactorContext)_localctx).id->getText() + "\n");
				                syntaxErrorCount++;
				                errorText = "Error at line " + std::to_string(((FactorContext)_localctx).id->getLine()) + ": Total number of arguments mismatch with declaration in function " + ((FactorContext)_localctx).id->getText() + "\n\n";
				            } else {
				                
				                string* expectedTypes = sym->getParamTypes();
				                for (int i = 0; i < expected; ++i) {
					                    cout<<((FactorContext)_localctx).id->getText() <<"Expected type: " << expectedTypes[i] << ", Actual type: " << ((FactorContext)_localctx).al.types[i] << endl;
					                    if(((FactorContext)_localctx).al.isArray[i]==true){
							                //             writeIntoErrorFile("Error at line " + std::to_string(((FactorContext)_localctx).id->getLine()) + ": Type mismatch, " +((FactorContext)_localctx).al.names[i] +" is an array\n");
				                            // errorText = "Error at line " + std::to_string(((FactorContext)_localctx).id->getLine()) + ": Type mismatch, " +((FactorContext)_localctx).al.names[i] +" is an array\n\n";
				                            // syntaxErrorCount++;
				                    }
				                    else if (expectedTypes[i] != ((FactorContext)_localctx).al.types[i] ) {
					                        writeIntoErrorFile("Error at line " + std::to_string(((FactorContext)_localctx).id->getLine()) +
				                                           ": " + std::to_string(i+1) + "th argument mismatch in function " +
				                                           ((FactorContext)_localctx).id->getText() + "\n");
				                        syntaxErrorCount++;
				                        errorText = "Error at line " + std::to_string(((FactorContext)_localctx).id->getLine()) +
				                                    ": " + std::to_string(i+1) + "th argument mismatch in function " +
				                                    ((FactorContext)_localctx).id->getText() + "\n\n";
				                        break;
				                    }
				                }
				            }

				            
				        }

				        writeIntoparserLogFile(
				            "Line " + std::to_string(((FactorContext)_localctx).id->getLine()) + ": factor : ID LPAREN argument_list RPAREN\n\n" +errorText +
				             _localctx.text + "\n"
				        );
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(399);
				((FactorContext)_localctx).lp = match(LPAREN);
				setState(400);
				((FactorContext)_localctx).e = expression();
				setState(401);
				((FactorContext)_localctx).rp = match(RPAREN);

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).lp->getText() + ((FactorContext)_localctx).e.text + ((FactorContext)_localctx).rp->getText();
				        ((FactorContext)_localctx).type =  ((FactorContext)_localctx).e.type;
				        ((FactorContext)_localctx).isArray =  ((FactorContext)_localctx).e.isArray;

				        writeIntoparserLogFile(
				            "Line " + std::to_string(((FactorContext)_localctx).lp->getLine()) + ": factor : LPAREN expression RPAREN\n\n" + _localctx.text + "\n"
				        );
				    
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(404);
				((FactorContext)_localctx).ci = match(CONST_INT);

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).ci->getText();
				        ((FactorContext)_localctx).type =  "int";
				        ((FactorContext)_localctx).isArray =  false;
				        writeIntoparserLogFile(
				            "Line " + std::to_string(((FactorContext)_localctx).ci->getLine()) + ": factor : CONST_INT\n\n" + _localctx.text + "\n"
				        );
				    
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(406);
				((FactorContext)_localctx).cf = match(CONST_FLOAT);

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).cf->getText();
				        ((FactorContext)_localctx).type =  "float";
				        ((FactorContext)_localctx).isArray =  false;
				        writeIntoparserLogFile(
				            "Line " + std::to_string(((FactorContext)_localctx).cf->getLine()) + ": factor : CONST_FLOAT\n\n" + _localctx.text + "\n"
				        );
				    
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(408);
				((FactorContext)_localctx).v = variable();
				setState(409);
				((FactorContext)_localctx).ic = match(INCOP);

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).v.text + ((FactorContext)_localctx).ic->getText();
				        
				            ((FactorContext)_localctx).isArray =  ((FactorContext)_localctx).v.reallyArray;
				            ((FactorContext)_localctx).type =  ((FactorContext)_localctx).v.type;

				        writeIntoparserLogFile(
				            "Line " + std::to_string((((FactorContext)_localctx).v!=null?(((FactorContext)_localctx).v.stop):null)->getLine()) + ": factor : variable INCOP\n\n" + _localctx.text + "\n"
				        );
				    
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(412);
				((FactorContext)_localctx).v = variable();
				setState(413);
				((FactorContext)_localctx).dc = match(DECOP);

				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).v.text + ((FactorContext)_localctx).dc->getText();
				       
				            ((FactorContext)_localctx).type =  ((FactorContext)_localctx).v.type;
				            ((FactorContext)_localctx).isArray =  ((FactorContext)_localctx).v.reallyArray;
				       

				       

				        writeIntoparserLogFile(
				            "Line " + std::to_string((((FactorContext)_localctx).v!=null?(((FactorContext)_localctx).v.stop):null)->getLine()) + ": factor : variable DECOP\n\n" + _localctx.text + "\n"
				        );
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Argument_listContext extends ParserRuleContext {
		public std::string text;
		public std::vector<std::string> types;
		public std::vector<bool> isArray;
		public std::vector<std::string> names;
		public ArgumentsContext a;
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public Argument_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argument_list; }
	}

	public final Argument_listContext argument_list() throws RecognitionException {
		Argument_listContext _localctx = new Argument_listContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_argument_list);
		try {
			setState(422);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAREN:
			case ADDOP:
			case NOT:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 1);
				{
				setState(418);
				((Argument_listContext)_localctx).a = arguments(0);

				        ((Argument_listContext)_localctx).text =  ((Argument_listContext)_localctx).a.text;
				        ((Argument_listContext)_localctx).types =  ((Argument_listContext)_localctx).a.types;
				        ((Argument_listContext)_localctx).isArray =  ((Argument_listContext)_localctx).a.isArray;
				        ((Argument_listContext)_localctx).names =  ((Argument_listContext)_localctx).a.names;
				        writeIntoparserLogFile(
				            "Line " + std::to_string((((Argument_listContext)_localctx).a!=null?(((Argument_listContext)_localctx).a.stop):null)->getLine()) + ": argument_list : arguments\n\n" +
				            _localctx.text + "\n"
				        );
				    
				}
				break;
			case RPAREN:
				enterOuterAlt(_localctx, 2);
				{

				        ((Argument_listContext)_localctx).text =  "";
				        ((Argument_listContext)_localctx).types =  {};
				        ((Argument_listContext)_localctx).isArray =  {};
				        ((Argument_listContext)_localctx).names =  {};
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentsContext extends ParserRuleContext {
		public std::string text;
		public std::vector<std::string> names;
		public std::vector<std::string> types;
		public std::vector<bool> isArray;
		public ArgumentsContext a;
		public Logic_expressionContext le;
		public Token cm;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(C8086Parser.COMMA, 0); }
		public ArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arguments; }
	}

	public final ArgumentsContext arguments() throws RecognitionException {
		return arguments(0);
	}

	private ArgumentsContext arguments(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ArgumentsContext _localctx = new ArgumentsContext(_ctx, _parentState);
		ArgumentsContext _prevctx = _localctx;
		int _startState = 48;
		enterRecursionRule(_localctx, 48, RULE_arguments, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(425);
			((ArgumentsContext)_localctx).le = logic_expression();

			        ((ArgumentsContext)_localctx).text =  ((ArgumentsContext)_localctx).le.text;
				    _localctx.types.push_back(((ArgumentsContext)_localctx).le.type);
			        _localctx.isArray.push_back(((ArgumentsContext)_localctx).le.isArray);
			        _localctx.names.push_back(((ArgumentsContext)_localctx).le.text);  
			        writeIntoparserLogFile(
			            "Line " + std::to_string((((ArgumentsContext)_localctx).le!=null?(((ArgumentsContext)_localctx).le.stop):null)->getLine()) + ": arguments : logic_expression\n\n" +
			            _localctx.text + "\n"
			        );
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(435);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ArgumentsContext(_parentctx, _parentState);
					_localctx.a = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_arguments);
					setState(428);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(429);
					((ArgumentsContext)_localctx).cm = match(COMMA);
					setState(430);
					((ArgumentsContext)_localctx).le = logic_expression();

					                  ((ArgumentsContext)_localctx).text =  ((ArgumentsContext)_localctx).a.text + ((ArgumentsContext)_localctx).cm->getText()  + ((ArgumentsContext)_localctx).le.text;
					                  ((ArgumentsContext)_localctx).types =  ((ArgumentsContext)_localctx).a.types;
					                  _localctx.types.push_back(((ArgumentsContext)_localctx).le.type);
					                  ((ArgumentsContext)_localctx).isArray =  ((ArgumentsContext)_localctx).a.isArray;
					                  _localctx.isArray.push_back(((ArgumentsContext)_localctx).le.isArray);
					                  ((ArgumentsContext)_localctx).names =  ((ArgumentsContext)_localctx).a.names;
					                  _localctx.names.push_back(((ArgumentsContext)_localctx).le.text);   
					                  writeIntoparserLogFile(
					                      "Line " + std::to_string((((ArgumentsContext)_localctx).a!=null?(((ArgumentsContext)_localctx).a.stop):null)->getLine()) + ": arguments : arguments COMMA logic_expression\n\n" +
					                      _localctx.text + "\n"
					                  );
					              
					}
					} 
				}
				setState(437);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 1:
			return program_sempred((ProgramContext)_localctx, predIndex);
		case 5:
			return parameter_list_sempred((Parameter_listContext)_localctx, predIndex);
		case 11:
			return declaration_list_sempred((Declaration_listContext)_localctx, predIndex);
		case 12:
			return statements_sempred((StatementsContext)_localctx, predIndex);
		case 19:
			return simple_expression_sempred((Simple_expressionContext)_localctx, predIndex);
		case 20:
			return term_sempred((TermContext)_localctx, predIndex);
		case 24:
			return arguments_sempred((ArgumentsContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean program_sempred(ProgramContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean parameter_list_sempred(Parameter_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 5);
		case 2:
			return precpred(_ctx, 4);
		}
		return true;
	}
	private boolean declaration_list_sempred(Declaration_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 3:
			return precpred(_ctx, 2);
		case 4:
			return precpred(_ctx, 6);
		case 5:
			return precpred(_ctx, 5);
		}
		return true;
	}
	private boolean statements_sempred(StatementsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 6:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean simple_expression_sempred(Simple_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 7:
			return precpred(_ctx, 1);
		case 8:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean term_sempred(TermContext _localctx, int predIndex) {
		switch (predIndex) {
		case 9:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean arguments_sempred(ArgumentsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 10:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001\"\u01b7\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0005\u0001"+
		">\b\u0001\n\u0001\f\u0001A\t\u0001\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0003\u0002L\b\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0003\u0003^\b\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u0004"+
		"u\b\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0003\u0005\u0083\b\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0005\u0005\u0090\b\u0005\n\u0005\f\u0005\u0093"+
		"\t\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0003\u0006\u00a1\b\u0006\u0001\u0007\u0001\u0007\u0003\u0007\u00a5"+
		"\b\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0003\b\u00b5"+
		"\b\b\u0001\t\u0001\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0003"+
		"\n\u00bf\b\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b"+
		"\u00cb\b\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0005\u000b\u00df\b\u000b\n\u000b\f\u000b\u00e2\t\u000b\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0005\f\u00ec"+
		"\b\f\n\f\f\f\u00ef\t\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r"+
		"\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0003\r\u0126\b\r\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u012e\b\u000e\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0003\u000f\u0138\b\u000f\u0001\u0010\u0001\u0010\u0001\u0010"+
		"\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0003\u0010"+
		"\u0142\b\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011"+
		"\u0001\u0011\u0001\u0011\u0001\u0011\u0003\u0011\u014c\b\u0011\u0001\u0012"+
		"\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012"+
		"\u0001\u0012\u0003\u0012\u0156\b\u0012\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0005\u0013\u0167\b\u0013\n\u0013\f\u0013\u016a\t\u0013\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0005\u0014\u0175\b\u0014\n\u0014\f\u0014\u0178\t\u0014"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0003\u0015"+
		"\u0185\b\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0003\u0016\u01a1\b\u0016\u0001\u0017"+
		"\u0001\u0017\u0001\u0017\u0001\u0017\u0003\u0017\u01a7\b\u0017\u0001\u0018"+
		"\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0001\u0018\u0005\u0018\u01b2\b\u0018\n\u0018\f\u0018\u01b5"+
		"\t\u0018\u0001\u0018\u0000\u0007\u0002\n\u0016\u0018&(0\u0019\u0000\u0002"+
		"\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e"+
		" \"$&(*,.0\u0000\u0000\u01cf\u00002\u0001\u0000\u0000\u0000\u00025\u0001"+
		"\u0000\u0000\u0000\u0004K\u0001\u0000\u0000\u0000\u0006]\u0001\u0000\u0000"+
		"\u0000\bt\u0001\u0000\u0000\u0000\n\u0082\u0001\u0000\u0000\u0000\f\u00a0"+
		"\u0001\u0000\u0000\u0000\u000e\u00a2\u0001\u0000\u0000\u0000\u0010\u00b4"+
		"\u0001\u0000\u0000\u0000\u0012\u00b6\u0001\u0000\u0000\u0000\u0014\u00be"+
		"\u0001\u0000\u0000\u0000\u0016\u00ca\u0001\u0000\u0000\u0000\u0018\u00e3"+
		"\u0001\u0000\u0000\u0000\u001a\u0125\u0001\u0000\u0000\u0000\u001c\u012d"+
		"\u0001\u0000\u0000\u0000\u001e\u0137\u0001\u0000\u0000\u0000 \u0141\u0001"+
		"\u0000\u0000\u0000\"\u014b\u0001\u0000\u0000\u0000$\u0155\u0001\u0000"+
		"\u0000\u0000&\u0157\u0001\u0000\u0000\u0000(\u016b\u0001\u0000\u0000\u0000"+
		"*\u0184\u0001\u0000\u0000\u0000,\u01a0\u0001\u0000\u0000\u0000.\u01a6"+
		"\u0001\u0000\u0000\u00000\u01a8\u0001\u0000\u0000\u000023\u0003\u0002"+
		"\u0001\u000034\u0006\u0000\uffff\uffff\u00004\u0001\u0001\u0000\u0000"+
		"\u000056\u0006\u0001\uffff\uffff\u000067\u0003\u0004\u0002\u000078\u0006"+
		"\u0001\uffff\uffff\u00008?\u0001\u0000\u0000\u00009:\n\u0002\u0000\u0000"+
		":;\u0003\u0004\u0002\u0000;<\u0006\u0001\uffff\uffff\u0000<>\u0001\u0000"+
		"\u0000\u0000=9\u0001\u0000\u0000\u0000>A\u0001\u0000\u0000\u0000?=\u0001"+
		"\u0000\u0000\u0000?@\u0001\u0000\u0000\u0000@\u0003\u0001\u0000\u0000"+
		"\u0000A?\u0001\u0000\u0000\u0000BC\u0003\u0010\b\u0000CD\u0006\u0002\uffff"+
		"\uffff\u0000DL\u0001\u0000\u0000\u0000EF\u0003\u0006\u0003\u0000FG\u0006"+
		"\u0002\uffff\uffff\u0000GL\u0001\u0000\u0000\u0000HI\u0003\b\u0004\u0000"+
		"IJ\u0006\u0002\uffff\uffff\u0000JL\u0001\u0000\u0000\u0000KB\u0001\u0000"+
		"\u0000\u0000KE\u0001\u0000\u0000\u0000KH\u0001\u0000\u0000\u0000L\u0005"+
		"\u0001\u0000\u0000\u0000MN\u0003\u0014\n\u0000NO\u0005\u001f\u0000\u0000"+
		"OP\u0005\u000e\u0000\u0000PQ\u0006\u0003\uffff\uffff\u0000QR\u0003\n\u0005"+
		"\u0000RS\u0005\u000f\u0000\u0000ST\u0005\u0014\u0000\u0000TU\u0006\u0003"+
		"\uffff\uffff\u0000U^\u0001\u0000\u0000\u0000VW\u0003\u0014\n\u0000WX\u0005"+
		"\u001f\u0000\u0000XY\u0005\u000e\u0000\u0000YZ\u0005\u000f\u0000\u0000"+
		"Z[\u0005\u0014\u0000\u0000[\\\u0006\u0003\uffff\uffff\u0000\\^\u0001\u0000"+
		"\u0000\u0000]M\u0001\u0000\u0000\u0000]V\u0001\u0000\u0000\u0000^\u0007"+
		"\u0001\u0000\u0000\u0000_`\u0003\u0014\n\u0000`a\u0005\u001f\u0000\u0000"+
		"ab\u0006\u0004\uffff\uffff\u0000bc\u0005\u000e\u0000\u0000cd\u0006\u0004"+
		"\uffff\uffff\u0000de\u0003\n\u0005\u0000ef\u0005\u000f\u0000\u0000fg\u0006"+
		"\u0004\uffff\uffff\u0000gh\u0003\u000e\u0007\u0000hi\u0006\u0004\uffff"+
		"\uffff\u0000iu\u0001\u0000\u0000\u0000jk\u0003\u0014\n\u0000kl\u0005\u001f"+
		"\u0000\u0000lm\u0006\u0004\uffff\uffff\u0000mn\u0005\u000e\u0000\u0000"+
		"no\u0006\u0004\uffff\uffff\u0000op\u0005\u000f\u0000\u0000pq\u0006\u0004"+
		"\uffff\uffff\u0000qr\u0003\u000e\u0007\u0000rs\u0006\u0004\uffff\uffff"+
		"\u0000su\u0001\u0000\u0000\u0000t_\u0001\u0000\u0000\u0000tj\u0001\u0000"+
		"\u0000\u0000u\t\u0001\u0000\u0000\u0000vw\u0006\u0005\uffff\uffff\u0000"+
		"wx\u0003\u0014\n\u0000xy\u0005\u001f\u0000\u0000yz\u0006\u0005\uffff\uffff"+
		"\u0000z\u0083\u0001\u0000\u0000\u0000{|\u0003\u0014\n\u0000|}\u0006\u0005"+
		"\uffff\uffff\u0000}\u0083\u0001\u0000\u0000\u0000~\u007f\u0003\u0014\n"+
		"\u0000\u007f\u0080\u0003\f\u0006\u0000\u0080\u0081\u0006\u0005\uffff\uffff"+
		"\u0000\u0081\u0083\u0001\u0000\u0000\u0000\u0082v\u0001\u0000\u0000\u0000"+
		"\u0082{\u0001\u0000\u0000\u0000\u0082~\u0001\u0000\u0000\u0000\u0083\u0091"+
		"\u0001\u0000\u0000\u0000\u0084\u0085\n\u0005\u0000\u0000\u0085\u0086\u0005"+
		"\u0015\u0000\u0000\u0086\u0087\u0003\u0014\n\u0000\u0087\u0088\u0005\u001f"+
		"\u0000\u0000\u0088\u0089\u0006\u0005\uffff\uffff\u0000\u0089\u0090\u0001"+
		"\u0000\u0000\u0000\u008a\u008b\n\u0004\u0000\u0000\u008b\u008c\u0005\u0015"+
		"\u0000\u0000\u008c\u008d\u0003\u0014\n\u0000\u008d\u008e\u0006\u0005\uffff"+
		"\uffff\u0000\u008e\u0090\u0001\u0000\u0000\u0000\u008f\u0084\u0001\u0000"+
		"\u0000\u0000\u008f\u008a\u0001\u0000\u0000\u0000\u0090\u0093\u0001\u0000"+
		"\u0000\u0000\u0091\u008f\u0001\u0000\u0000\u0000\u0091\u0092\u0001\u0000"+
		"\u0000\u0000\u0092\u000b\u0001\u0000\u0000\u0000\u0093\u0091\u0001\u0000"+
		"\u0000\u0000\u0094\u0095\u0005\u0016\u0000\u0000\u0095\u00a1\u0006\u0006"+
		"\uffff\uffff\u0000\u0096\u0097\u0005\u0018\u0000\u0000\u0097\u00a1\u0006"+
		"\u0006\uffff\uffff\u0000\u0098\u0099\u0005\u001c\u0000\u0000\u0099\u00a1"+
		"\u0006\u0006\uffff\uffff\u0000\u009a\u009b\u0005\u001e\u0000\u0000\u009b"+
		"\u00a1\u0006\u0006\uffff\uffff\u0000\u009c\u009d\u0005\u001d\u0000\u0000"+
		"\u009d\u00a1\u0006\u0006\uffff\uffff\u0000\u009e\u009f\u0005\u001b\u0000"+
		"\u0000\u009f\u00a1\u0006\u0006\uffff\uffff\u0000\u00a0\u0094\u0001\u0000"+
		"\u0000\u0000\u00a0\u0096\u0001\u0000\u0000\u0000\u00a0\u0098\u0001\u0000"+
		"\u0000\u0000\u00a0\u009a\u0001\u0000\u0000\u0000\u00a0\u009c\u0001\u0000"+
		"\u0000\u0000\u00a0\u009e\u0001\u0000\u0000\u0000\u00a1\r\u0001\u0000\u0000"+
		"\u0000\u00a2\u00a4\u0005\u0010\u0000\u0000\u00a3\u00a5\u0003\u0018\f\u0000"+
		"\u00a4\u00a3\u0001\u0000\u0000\u0000\u00a4\u00a5\u0001\u0000\u0000\u0000"+
		"\u00a5\u00a6\u0001\u0000\u0000\u0000\u00a6\u00a7\u0005\u0011\u0000\u0000"+
		"\u00a7\u00a8\u0006\u0007\uffff\uffff\u0000\u00a8\u000f\u0001\u0000\u0000"+
		"\u0000\u00a9\u00aa\u0003\u0014\n\u0000\u00aa\u00ab\u0006\b\uffff\uffff"+
		"\u0000\u00ab\u00ac\u0003\u0016\u000b\u0000\u00ac\u00ad\u0005\u0014\u0000"+
		"\u0000\u00ad\u00ae\u0006\b\uffff\uffff\u0000\u00ae\u00b5\u0001\u0000\u0000"+
		"\u0000\u00af\u00b0\u0003\u0014\n\u0000\u00b0\u00b1\u0003\u0012\t\u0000"+
		"\u00b1\u00b2\u0005\u0014\u0000\u0000\u00b2\u00b3\u0006\b\uffff\uffff\u0000"+
		"\u00b3\u00b5\u0001\u0000\u0000\u0000\u00b4\u00a9\u0001\u0000\u0000\u0000"+
		"\u00b4\u00af\u0001\u0000\u0000\u0000\u00b5\u0011\u0001\u0000\u0000\u0000"+
		"\u00b6\u00b7\u0006\t\uffff\uffff\u0000\u00b7\u0013\u0001\u0000\u0000\u0000"+
		"\u00b8\u00b9\u0005\u000b\u0000\u0000\u00b9\u00bf\u0006\n\uffff\uffff\u0000"+
		"\u00ba\u00bb\u0005\f\u0000\u0000\u00bb\u00bf\u0006\n\uffff\uffff\u0000"+
		"\u00bc\u00bd\u0005\r\u0000\u0000\u00bd\u00bf\u0006\n\uffff\uffff\u0000"+
		"\u00be\u00b8\u0001\u0000\u0000\u0000\u00be\u00ba\u0001\u0000\u0000\u0000"+
		"\u00be\u00bc\u0001\u0000\u0000\u0000\u00bf\u0015\u0001\u0000\u0000\u0000"+
		"\u00c0\u00c1\u0006\u000b\uffff\uffff\u0000\u00c1\u00c2\u0005\u001f\u0000"+
		"\u0000\u00c2\u00cb\u0006\u000b\uffff\uffff\u0000\u00c3\u00c4\u0005\u001f"+
		"\u0000\u0000\u00c4\u00c5\u0005\u0012\u0000\u0000\u00c5\u00c6\u0005 \u0000"+
		"\u0000\u00c6\u00c7\u0005\u0013\u0000\u0000\u00c7\u00cb\u0006\u000b\uffff"+
		"\uffff\u0000\u00c8\u00c9\t\u0000\u0000\u0000\u00c9\u00cb\u0006\u000b\uffff"+
		"\uffff\u0000\u00ca\u00c0\u0001\u0000\u0000\u0000\u00ca\u00c3\u0001\u0000"+
		"\u0000\u0000\u00ca\u00c8\u0001\u0000\u0000\u0000\u00cb\u00e0\u0001\u0000"+
		"\u0000\u0000\u00cc\u00cd\n\u0002\u0000\u0000\u00cd\u00ce\u0003\f\u0006"+
		"\u0000\u00ce\u00cf\u0005\u001f\u0000\u0000\u00cf\u00d0\u0005\u0015\u0000"+
		"\u0000\u00d0\u00d1\u0003\u0016\u000b\u0003\u00d1\u00d2\u0006\u000b\uffff"+
		"\uffff\u0000\u00d2\u00df\u0001\u0000\u0000\u0000\u00d3\u00d4\n\u0006\u0000"+
		"\u0000\u00d4\u00d5\u0005\u0015\u0000\u0000\u00d5\u00d6\u0005\u001f\u0000"+
		"\u0000\u00d6\u00df\u0006\u000b\uffff\uffff\u0000\u00d7\u00d8\n\u0005\u0000"+
		"\u0000\u00d8\u00d9\u0005\u0015\u0000\u0000\u00d9\u00da\u0005\u001f\u0000"+
		"\u0000\u00da\u00db\u0005\u0012\u0000\u0000\u00db\u00dc\u0005 \u0000\u0000"+
		"\u00dc\u00dd\u0005\u0013\u0000\u0000\u00dd\u00df\u0006\u000b\uffff\uffff"+
		"\u0000\u00de\u00cc\u0001\u0000\u0000\u0000\u00de\u00d3\u0001\u0000\u0000"+
		"\u0000\u00de\u00d7\u0001\u0000\u0000\u0000\u00df\u00e2\u0001\u0000\u0000"+
		"\u0000\u00e0\u00de\u0001\u0000\u0000\u0000\u00e0\u00e1\u0001\u0000\u0000"+
		"\u0000\u00e1\u0017\u0001\u0000\u0000\u0000\u00e2\u00e0\u0001\u0000\u0000"+
		"\u0000\u00e3\u00e4\u0006\f\uffff\uffff\u0000\u00e4\u00e5\u0003\u001a\r"+
		"\u0000\u00e5\u00e6\u0006\f\uffff\uffff\u0000\u00e6\u00ed\u0001\u0000\u0000"+
		"\u0000\u00e7\u00e8\n\u0001\u0000\u0000\u00e8\u00e9\u0003\u001a\r\u0000"+
		"\u00e9\u00ea\u0006\f\uffff\uffff\u0000\u00ea\u00ec\u0001\u0000\u0000\u0000"+
		"\u00eb\u00e7\u0001\u0000\u0000\u0000\u00ec\u00ef\u0001\u0000\u0000\u0000"+
		"\u00ed\u00eb\u0001\u0000\u0000\u0000\u00ed\u00ee\u0001\u0000\u0000\u0000"+
		"\u00ee\u0019\u0001\u0000\u0000\u0000\u00ef\u00ed\u0001\u0000\u0000\u0000"+
		"\u00f0\u00f1\u0003\u0010\b\u0000\u00f1\u00f2\u0006\r\uffff\uffff\u0000"+
		"\u00f2\u0126\u0001\u0000\u0000\u0000\u00f3\u00f4\u0003\u001c\u000e\u0000"+
		"\u00f4\u00f5\u0006\r\uffff\uffff\u0000\u00f5\u0126\u0001\u0000\u0000\u0000"+
		"\u00f6\u00f7\u0006\r\uffff\uffff\u0000\u00f7\u00f8\u0003\u000e\u0007\u0000"+
		"\u00f8\u00f9\u0006\r\uffff\uffff\u0000\u00f9\u0126\u0001\u0000\u0000\u0000"+
		"\u00fa\u00fb\u0005\u0007\u0000\u0000\u00fb\u00fc\u0005\u000e\u0000\u0000"+
		"\u00fc\u00fd\u0003\u001c\u000e\u0000\u00fd\u00fe\u0003\u001c\u000e\u0000"+
		"\u00fe\u00ff\u0003 \u0010\u0000\u00ff\u0100\u0005\u000f\u0000\u0000\u0100"+
		"\u0101\u0003\u001a\r\u0000\u0101\u0102\u0006\r\uffff\uffff\u0000\u0102"+
		"\u0126\u0001\u0000\u0000\u0000\u0103\u0104\u0005\u0005\u0000\u0000\u0104"+
		"\u0105\u0005\u000e\u0000\u0000\u0105\u0106\u0003 \u0010\u0000\u0106\u0107"+
		"\u0005\u000f\u0000\u0000\u0107\u0108\u0003\u001a\r\u0000\u0108\u0109\u0006"+
		"\r\uffff\uffff\u0000\u0109\u0126\u0001\u0000\u0000\u0000\u010a\u010b\u0005"+
		"\u0005\u0000\u0000\u010b\u010c\u0005\u000e\u0000\u0000\u010c\u010d\u0003"+
		" \u0010\u0000\u010d\u010e\u0005\u000f\u0000\u0000\u010e\u010f\u0003\u001a"+
		"\r\u0000\u010f\u0110\u0005\u0006\u0000\u0000\u0110\u0111\u0003\u001a\r"+
		"\u0000\u0111\u0112\u0006\r\uffff\uffff\u0000\u0112\u0126\u0001\u0000\u0000"+
		"\u0000\u0113\u0114\u0005\b\u0000\u0000\u0114\u0115\u0005\u000e\u0000\u0000"+
		"\u0115\u0116\u0003 \u0010\u0000\u0116\u0117\u0005\u000f\u0000\u0000\u0117"+
		"\u0118\u0003\u001a\r\u0000\u0118\u0119\u0006\r\uffff\uffff\u0000\u0119"+
		"\u0126\u0001\u0000\u0000\u0000\u011a\u011b\u0005\t\u0000\u0000\u011b\u011c"+
		"\u0005\u000e\u0000\u0000\u011c\u011d\u0005\u001f\u0000\u0000\u011d\u011e"+
		"\u0005\u000f\u0000\u0000\u011e\u011f\u0005\u0014\u0000\u0000\u011f\u0126"+
		"\u0006\r\uffff\uffff\u0000\u0120\u0121\u0005\n\u0000\u0000\u0121\u0122"+
		"\u0003 \u0010\u0000\u0122\u0123\u0005\u0014\u0000\u0000\u0123\u0124\u0006"+
		"\r\uffff\uffff\u0000\u0124\u0126\u0001\u0000\u0000\u0000\u0125\u00f0\u0001"+
		"\u0000\u0000\u0000\u0125\u00f3\u0001\u0000\u0000\u0000\u0125\u00f6\u0001"+
		"\u0000\u0000\u0000\u0125\u00fa\u0001\u0000\u0000\u0000\u0125\u0103\u0001"+
		"\u0000\u0000\u0000\u0125\u010a\u0001\u0000\u0000\u0000\u0125\u0113\u0001"+
		"\u0000\u0000\u0000\u0125\u011a\u0001\u0000\u0000\u0000\u0125\u0120\u0001"+
		"\u0000\u0000\u0000\u0126\u001b\u0001\u0000\u0000\u0000\u0127\u0128\u0005"+
		"\u0014\u0000\u0000\u0128\u012e\u0006\u000e\uffff\uffff\u0000\u0129\u012a"+
		"\u0003 \u0010\u0000\u012a\u012b\u0005\u0014\u0000\u0000\u012b\u012c\u0006"+
		"\u000e\uffff\uffff\u0000\u012c\u012e\u0001\u0000\u0000\u0000\u012d\u0127"+
		"\u0001\u0000\u0000\u0000\u012d\u0129\u0001\u0000\u0000\u0000\u012e\u001d"+
		"\u0001\u0000\u0000\u0000\u012f\u0130\u0005\u001f\u0000\u0000\u0130\u0138"+
		"\u0006\u000f\uffff\uffff\u0000\u0131\u0132\u0005\u001f\u0000\u0000\u0132"+
		"\u0133\u0005\u0012\u0000\u0000\u0133\u0134\u0003 \u0010\u0000\u0134\u0135"+
		"\u0005\u0013\u0000\u0000\u0135\u0136\u0006\u000f\uffff\uffff\u0000\u0136"+
		"\u0138\u0001\u0000\u0000\u0000\u0137\u012f\u0001\u0000\u0000\u0000\u0137"+
		"\u0131\u0001\u0000\u0000\u0000\u0138\u001f\u0001\u0000\u0000\u0000\u0139"+
		"\u013a\u0003\"\u0011\u0000\u013a\u013b\u0006\u0010\uffff\uffff\u0000\u013b"+
		"\u0142\u0001\u0000\u0000\u0000\u013c\u013d\u0003\u001e\u000f\u0000\u013d"+
		"\u013e\u0005\u001e\u0000\u0000\u013e\u013f\u0003\"\u0011\u0000\u013f\u0140"+
		"\u0006\u0010\uffff\uffff\u0000\u0140\u0142\u0001\u0000\u0000\u0000\u0141"+
		"\u0139\u0001\u0000\u0000\u0000\u0141\u013c\u0001\u0000\u0000\u0000\u0142"+
		"!\u0001\u0000\u0000\u0000\u0143\u0144\u0003$\u0012\u0000\u0144\u0145\u0006"+
		"\u0011\uffff\uffff\u0000\u0145\u014c\u0001\u0000\u0000\u0000\u0146\u0147"+
		"\u0003$\u0012\u0000\u0147\u0148\u0005\u001d\u0000\u0000\u0148\u0149\u0003"+
		"$\u0012\u0000\u0149\u014a\u0006\u0011\uffff\uffff\u0000\u014a\u014c\u0001"+
		"\u0000\u0000\u0000\u014b\u0143\u0001\u0000\u0000\u0000\u014b\u0146\u0001"+
		"\u0000\u0000\u0000\u014c#\u0001\u0000\u0000\u0000\u014d\u014e\u0003&\u0013"+
		"\u0000\u014e\u014f\u0006\u0012\uffff\uffff\u0000\u014f\u0156\u0001\u0000"+
		"\u0000\u0000\u0150\u0151\u0003&\u0013\u0000\u0151\u0152\u0005\u001c\u0000"+
		"\u0000\u0152\u0153\u0003&\u0013\u0000\u0153\u0154\u0006\u0012\uffff\uffff"+
		"\u0000\u0154\u0156\u0001\u0000\u0000\u0000\u0155\u014d\u0001\u0000\u0000"+
		"\u0000\u0155\u0150\u0001\u0000\u0000\u0000\u0156%\u0001\u0000\u0000\u0000"+
		"\u0157\u0158\u0006\u0013\uffff\uffff\u0000\u0158\u0159\u0003(\u0014\u0000"+
		"\u0159\u015a\u0006\u0013\uffff\uffff\u0000\u015a\u0168\u0001\u0000\u0000"+
		"\u0000\u015b\u015c\n\u0001\u0000\u0000\u015c\u015d\u0005\u0016\u0000\u0000"+
		"\u015d\u015e\u0005\u001e\u0000\u0000\u015e\u015f\u0003&\u0013\u0002\u015f"+
		"\u0160\u0006\u0013\uffff\uffff\u0000\u0160\u0167\u0001\u0000\u0000\u0000"+
		"\u0161\u0162\n\u0002\u0000\u0000\u0162\u0163\u0005\u0016\u0000\u0000\u0163"+
		"\u0164\u0003(\u0014\u0000\u0164\u0165\u0006\u0013\uffff\uffff\u0000\u0165"+
		"\u0167\u0001\u0000\u0000\u0000\u0166\u015b\u0001\u0000\u0000\u0000\u0166"+
		"\u0161\u0001\u0000\u0000\u0000\u0167\u016a\u0001\u0000\u0000\u0000\u0168"+
		"\u0166\u0001\u0000\u0000\u0000\u0168\u0169\u0001\u0000\u0000\u0000\u0169"+
		"\'\u0001\u0000\u0000\u0000\u016a\u0168\u0001\u0000\u0000\u0000\u016b\u016c"+
		"\u0006\u0014\uffff\uffff\u0000\u016c\u016d\u0003*\u0015\u0000\u016d\u016e"+
		"\u0006\u0014\uffff\uffff\u0000\u016e\u0176\u0001\u0000\u0000\u0000\u016f"+
		"\u0170\n\u0001\u0000\u0000\u0170\u0171\u0005\u0018\u0000\u0000\u0171\u0172"+
		"\u0003*\u0015\u0000\u0172\u0173\u0006\u0014\uffff\uffff\u0000\u0173\u0175"+
		"\u0001\u0000\u0000\u0000\u0174\u016f\u0001\u0000\u0000\u0000\u0175\u0178"+
		"\u0001\u0000\u0000\u0000\u0176\u0174\u0001\u0000\u0000\u0000\u0176\u0177"+
		"\u0001\u0000\u0000\u0000\u0177)\u0001\u0000\u0000\u0000\u0178\u0176\u0001"+
		"\u0000\u0000\u0000\u0179\u017a\u0005\u0016\u0000\u0000\u017a\u017b\u0003"+
		"*\u0015\u0000\u017b\u017c\u0006\u0015\uffff\uffff\u0000\u017c\u0185\u0001"+
		"\u0000\u0000\u0000\u017d\u017e\u0005\u001b\u0000\u0000\u017e\u017f\u0003"+
		"*\u0015\u0000\u017f\u0180\u0006\u0015\uffff\uffff\u0000\u0180\u0185\u0001"+
		"\u0000\u0000\u0000\u0181\u0182\u0003,\u0016\u0000\u0182\u0183\u0006\u0015"+
		"\uffff\uffff\u0000\u0183\u0185\u0001\u0000\u0000\u0000\u0184\u0179\u0001"+
		"\u0000\u0000\u0000\u0184\u017d\u0001\u0000\u0000\u0000\u0184\u0181\u0001"+
		"\u0000\u0000\u0000\u0185+\u0001\u0000\u0000\u0000\u0186\u0187\u0003\u001e"+
		"\u000f\u0000\u0187\u0188\u0006\u0016\uffff\uffff\u0000\u0188\u01a1\u0001"+
		"\u0000\u0000\u0000\u0189\u018a\u0005\u001f\u0000\u0000\u018a\u018b\u0005"+
		"\u000e\u0000\u0000\u018b\u018c\u0003.\u0017\u0000\u018c\u018d\u0005\u000f"+
		"\u0000\u0000\u018d\u018e\u0006\u0016\uffff\uffff\u0000\u018e\u01a1\u0001"+
		"\u0000\u0000\u0000\u018f\u0190\u0005\u000e\u0000\u0000\u0190\u0191\u0003"+
		" \u0010\u0000\u0191\u0192\u0005\u000f\u0000\u0000\u0192\u0193\u0006\u0016"+
		"\uffff\uffff\u0000\u0193\u01a1\u0001\u0000\u0000\u0000\u0194\u0195\u0005"+
		" \u0000\u0000\u0195\u01a1\u0006\u0016\uffff\uffff\u0000\u0196\u0197\u0005"+
		"!\u0000\u0000\u0197\u01a1\u0006\u0016\uffff\uffff\u0000\u0198\u0199\u0003"+
		"\u001e\u000f\u0000\u0199\u019a\u0005\u0019\u0000\u0000\u019a\u019b\u0006"+
		"\u0016\uffff\uffff\u0000\u019b\u01a1\u0001\u0000\u0000\u0000\u019c\u019d"+
		"\u0003\u001e\u000f\u0000\u019d\u019e\u0005\u001a\u0000\u0000\u019e\u019f"+
		"\u0006\u0016\uffff\uffff\u0000\u019f\u01a1\u0001\u0000\u0000\u0000\u01a0"+
		"\u0186\u0001\u0000\u0000\u0000\u01a0\u0189\u0001\u0000\u0000\u0000\u01a0"+
		"\u018f\u0001\u0000\u0000\u0000\u01a0\u0194\u0001\u0000\u0000\u0000\u01a0"+
		"\u0196\u0001\u0000\u0000\u0000\u01a0\u0198\u0001\u0000\u0000\u0000\u01a0"+
		"\u019c\u0001\u0000\u0000\u0000\u01a1-\u0001\u0000\u0000\u0000\u01a2\u01a3"+
		"\u00030\u0018\u0000\u01a3\u01a4\u0006\u0017\uffff\uffff\u0000\u01a4\u01a7"+
		"\u0001\u0000\u0000\u0000\u01a5\u01a7\u0006\u0017\uffff\uffff\u0000\u01a6"+
		"\u01a2\u0001\u0000\u0000\u0000\u01a6\u01a5\u0001\u0000\u0000\u0000\u01a7"+
		"/\u0001\u0000\u0000\u0000\u01a8\u01a9\u0006\u0018\uffff\uffff\u0000\u01a9"+
		"\u01aa\u0003\"\u0011\u0000\u01aa\u01ab\u0006\u0018\uffff\uffff\u0000\u01ab"+
		"\u01b3\u0001\u0000\u0000\u0000\u01ac\u01ad\n\u0002\u0000\u0000\u01ad\u01ae"+
		"\u0005\u0015\u0000\u0000\u01ae\u01af\u0003\"\u0011\u0000\u01af\u01b0\u0006"+
		"\u0018\uffff\uffff\u0000\u01b0\u01b2\u0001\u0000\u0000\u0000\u01b1\u01ac"+
		"\u0001\u0000\u0000\u0000\u01b2\u01b5\u0001\u0000\u0000\u0000\u01b3\u01b1"+
		"\u0001\u0000\u0000\u0000\u01b3\u01b4\u0001\u0000\u0000\u0000\u01b41\u0001"+
		"\u0000\u0000\u0000\u01b5\u01b3\u0001\u0000\u0000\u0000\u001c?K]t\u0082"+
		"\u008f\u0091\u00a0\u00a4\u00b4\u00be\u00ca\u00de\u00e0\u00ed\u0125\u012d"+
		"\u0137\u0141\u014b\u0155\u0166\u0168\u0176\u0184\u01a0\u01a6\u01b3";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}