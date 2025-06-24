
    #pragma once
    #include <iostream>
    #include <fstream>
    #include <string>

    extern std::ofstream lexLogFile;
	    extern std::ofstream errorFile;
	      extern int syntaxErrorCount;
	        extern std::ofstream parserLogFile;


// Generated from C8086Lexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  C8086Lexer : public antlr4::Lexer {
public:
  enum {
    LINE_COMMENT = 1, BLOCK_COMMENT = 2, STRING = 3, WS = 4, IF = 5, ELSE = 6, 
    FOR = 7, WHILE = 8, PRINTLN = 9, RETURN = 10, INT = 11, FLOAT = 12, 
    VOID = 13, LPAREN = 14, RPAREN = 15, LCURL = 16, RCURL = 17, LTHIRD = 18, 
    RTHIRD = 19, SEMICOLON = 20, COMMA = 21, ADDOP = 22, SUBOP = 23, MULOP = 24, 
    INCOP = 25, DECOP = 26, NOT = 27, RELOP = 28, LOGICOP = 29, ASSIGNOP = 30, 
    ID = 31, CONST_INT = 32, CONST_FLOAT = 33, UNRECOGNIZED = 34
  };

  explicit C8086Lexer(antlr4::CharStream *input);

  ~C8086Lexer() override;


      void writeIntoLexLogFile(const std::string &message) {
          if (!lexLogFile.is_open()) {
              lexLogFile.open("lexLogFile.txt", std::ios::app);
              if (!lexLogFile) {
                  std::cerr << "Error opening lexLogFile.txt" << std::endl;
                  return;
              }
          }
          lexLogFile << message << std::endl;
          lexLogFile.flush();
      }

  	    void writeIntoErrorFile(const std::string message) {
          if (!errorFile) {
              std::cout << "Error opening errorFile.txt" << std::endl;
              return;
          }
          errorFile << message << std::endl;
          errorFile.flush();
      }
  	    void writeIntoparserLogFile(const std::string message) {
          if (!parserLogFile) {
              std::cout << "Error opening parserLogFile.txt" << std::endl;
              return;
          }

          parserLogFile << message << std::endl;
          parserLogFile.flush();
      }




  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void LINE_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex);
  void BLOCK_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRINGAction(antlr4::RuleContext *context, size_t actionIndex);
  void IFAction(antlr4::RuleContext *context, size_t actionIndex);
  void ELSEAction(antlr4::RuleContext *context, size_t actionIndex);
  void FORAction(antlr4::RuleContext *context, size_t actionIndex);
  void WHILEAction(antlr4::RuleContext *context, size_t actionIndex);
  void PRINTLNAction(antlr4::RuleContext *context, size_t actionIndex);
  void RETURNAction(antlr4::RuleContext *context, size_t actionIndex);
  void INTAction(antlr4::RuleContext *context, size_t actionIndex);
  void FLOATAction(antlr4::RuleContext *context, size_t actionIndex);
  void VOIDAction(antlr4::RuleContext *context, size_t actionIndex);
  void LPARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void RPARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void LCURLAction(antlr4::RuleContext *context, size_t actionIndex);
  void RCURLAction(antlr4::RuleContext *context, size_t actionIndex);
  void LTHIRDAction(antlr4::RuleContext *context, size_t actionIndex);
  void RTHIRDAction(antlr4::RuleContext *context, size_t actionIndex);
  void SEMICOLONAction(antlr4::RuleContext *context, size_t actionIndex);
  void COMMAAction(antlr4::RuleContext *context, size_t actionIndex);
  void ADDOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void SUBOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void MULOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void INCOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void DECOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void NOTAction(antlr4::RuleContext *context, size_t actionIndex);
  void RELOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOGICOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void ASSIGNOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void IDAction(antlr4::RuleContext *context, size_t actionIndex);
  void CONST_INTAction(antlr4::RuleContext *context, size_t actionIndex);
  void CONST_FLOATAction(antlr4::RuleContext *context, size_t actionIndex);
  void UNRECOGNIZEDAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};

