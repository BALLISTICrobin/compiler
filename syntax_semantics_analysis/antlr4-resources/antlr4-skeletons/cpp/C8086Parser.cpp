
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


// Generated from C8086Parser.g4 by ANTLR 4.13.2


#include "C8086ParserListener.h"

#include "C8086Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct C8086ParserStaticData final {
  C8086ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C8086ParserStaticData(const C8086ParserStaticData&) = delete;
  C8086ParserStaticData(C8086ParserStaticData&&) = delete;
  C8086ParserStaticData& operator=(const C8086ParserStaticData&) = delete;
  C8086ParserStaticData& operator=(C8086ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c8086parserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C8086ParserStaticData> c8086parserParserStaticData = nullptr;

void c8086parserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c8086parserParserStaticData != nullptr) {
    return;
  }
#else
  assert(c8086parserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C8086ParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "parameter_list", "invalid_param", "compound_statement", "var_declaration", 
      "declaration_list_err", "type_specifier", "declaration_list", "statements", 
      "statement", "expression_statement", "variable", "expression", "logic_expression", 
      "rel_expression", "simple_expression", "term", "unary_expression", 
      "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'printf'", 
      "'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
      "'['", "']'", "';'", "','", "", "", "", "'++'", "'--'", "'!'", "", 
      "", "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
      "ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", 
      "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT", "UNRECOGNIZED"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,34,439,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,5,1,62,8,1,10,1,12,1,65,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,3,2,76,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,3,3,94,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,117,8,4,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,3,5,131,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,5,5,144,8,5,10,5,12,5,147,9,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,3,6,161,8,6,1,7,1,7,3,7,165,8,7,1,7,1,7,1,7,1,8,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,181,8,8,1,9,1,9,1,10,1,10,1,10,
  	1,10,1,10,1,10,3,10,191,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,3,11,203,8,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,223,8,11,10,11,12,11,
  	226,9,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,5,12,236,8,12,10,12,
  	12,12,239,9,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	3,13,294,8,13,1,14,1,14,1,14,1,14,1,14,1,14,3,14,302,8,14,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,3,15,312,8,15,1,16,1,16,1,16,1,16,1,16,1,
  	16,1,16,1,16,3,16,322,8,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,3,
  	17,332,8,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,3,18,342,8,18,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	5,19,359,8,19,10,19,12,19,362,9,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,5,20,373,8,20,10,20,12,20,376,9,20,1,21,1,21,1,21,1,21,1,21,
  	1,21,1,21,1,21,1,21,1,21,1,21,3,21,389,8,21,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,3,22,417,8,22,1,23,1,23,1,23,1,23,
  	3,23,423,8,23,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,5,24,434,8,
  	24,10,24,12,24,437,9,24,1,24,0,7,2,10,22,24,38,40,48,25,0,2,4,6,8,10,
  	12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,0,0,463,0,50,
  	1,0,0,0,2,53,1,0,0,0,4,75,1,0,0,0,6,93,1,0,0,0,8,116,1,0,0,0,10,130,1,
  	0,0,0,12,160,1,0,0,0,14,162,1,0,0,0,16,180,1,0,0,0,18,182,1,0,0,0,20,
  	190,1,0,0,0,22,202,1,0,0,0,24,227,1,0,0,0,26,293,1,0,0,0,28,301,1,0,0,
  	0,30,311,1,0,0,0,32,321,1,0,0,0,34,331,1,0,0,0,36,341,1,0,0,0,38,343,
  	1,0,0,0,40,363,1,0,0,0,42,388,1,0,0,0,44,416,1,0,0,0,46,422,1,0,0,0,48,
  	424,1,0,0,0,50,51,3,2,1,0,51,52,6,0,-1,0,52,1,1,0,0,0,53,54,6,1,-1,0,
  	54,55,3,4,2,0,55,56,6,1,-1,0,56,63,1,0,0,0,57,58,10,2,0,0,58,59,3,4,2,
  	0,59,60,6,1,-1,0,60,62,1,0,0,0,61,57,1,0,0,0,62,65,1,0,0,0,63,61,1,0,
  	0,0,63,64,1,0,0,0,64,3,1,0,0,0,65,63,1,0,0,0,66,67,3,16,8,0,67,68,6,2,
  	-1,0,68,76,1,0,0,0,69,70,3,6,3,0,70,71,6,2,-1,0,71,76,1,0,0,0,72,73,3,
  	8,4,0,73,74,6,2,-1,0,74,76,1,0,0,0,75,66,1,0,0,0,75,69,1,0,0,0,75,72,
  	1,0,0,0,76,5,1,0,0,0,77,78,3,20,10,0,78,79,5,31,0,0,79,80,5,14,0,0,80,
  	81,6,3,-1,0,81,82,3,10,5,0,82,83,5,15,0,0,83,84,5,20,0,0,84,85,6,3,-1,
  	0,85,94,1,0,0,0,86,87,3,20,10,0,87,88,5,31,0,0,88,89,5,14,0,0,89,90,5,
  	15,0,0,90,91,5,20,0,0,91,92,6,3,-1,0,92,94,1,0,0,0,93,77,1,0,0,0,93,86,
  	1,0,0,0,94,7,1,0,0,0,95,96,3,20,10,0,96,97,5,31,0,0,97,98,6,4,-1,0,98,
  	99,5,14,0,0,99,100,6,4,-1,0,100,101,3,10,5,0,101,102,5,15,0,0,102,103,
  	6,4,-1,0,103,104,3,14,7,0,104,105,6,4,-1,0,105,117,1,0,0,0,106,107,3,
  	20,10,0,107,108,5,31,0,0,108,109,6,4,-1,0,109,110,5,14,0,0,110,111,6,
  	4,-1,0,111,112,5,15,0,0,112,113,6,4,-1,0,113,114,3,14,7,0,114,115,6,4,
  	-1,0,115,117,1,0,0,0,116,95,1,0,0,0,116,106,1,0,0,0,117,9,1,0,0,0,118,
  	119,6,5,-1,0,119,120,3,20,10,0,120,121,5,31,0,0,121,122,6,5,-1,0,122,
  	131,1,0,0,0,123,124,3,20,10,0,124,125,6,5,-1,0,125,131,1,0,0,0,126,127,
  	3,20,10,0,127,128,3,12,6,0,128,129,6,5,-1,0,129,131,1,0,0,0,130,118,1,
  	0,0,0,130,123,1,0,0,0,130,126,1,0,0,0,131,145,1,0,0,0,132,133,10,5,0,
  	0,133,134,5,21,0,0,134,135,3,20,10,0,135,136,5,31,0,0,136,137,6,5,-1,
  	0,137,144,1,0,0,0,138,139,10,4,0,0,139,140,5,21,0,0,140,141,3,20,10,0,
  	141,142,6,5,-1,0,142,144,1,0,0,0,143,132,1,0,0,0,143,138,1,0,0,0,144,
  	147,1,0,0,0,145,143,1,0,0,0,145,146,1,0,0,0,146,11,1,0,0,0,147,145,1,
  	0,0,0,148,149,5,22,0,0,149,161,6,6,-1,0,150,151,5,24,0,0,151,161,6,6,
  	-1,0,152,153,5,28,0,0,153,161,6,6,-1,0,154,155,5,30,0,0,155,161,6,6,-1,
  	0,156,157,5,29,0,0,157,161,6,6,-1,0,158,159,5,27,0,0,159,161,6,6,-1,0,
  	160,148,1,0,0,0,160,150,1,0,0,0,160,152,1,0,0,0,160,154,1,0,0,0,160,156,
  	1,0,0,0,160,158,1,0,0,0,161,13,1,0,0,0,162,164,5,16,0,0,163,165,3,24,
  	12,0,164,163,1,0,0,0,164,165,1,0,0,0,165,166,1,0,0,0,166,167,5,17,0,0,
  	167,168,6,7,-1,0,168,15,1,0,0,0,169,170,3,20,10,0,170,171,6,8,-1,0,171,
  	172,3,22,11,0,172,173,5,20,0,0,173,174,6,8,-1,0,174,181,1,0,0,0,175,176,
  	3,20,10,0,176,177,3,18,9,0,177,178,5,20,0,0,178,179,6,8,-1,0,179,181,
  	1,0,0,0,180,169,1,0,0,0,180,175,1,0,0,0,181,17,1,0,0,0,182,183,6,9,-1,
  	0,183,19,1,0,0,0,184,185,5,11,0,0,185,191,6,10,-1,0,186,187,5,12,0,0,
  	187,191,6,10,-1,0,188,189,5,13,0,0,189,191,6,10,-1,0,190,184,1,0,0,0,
  	190,186,1,0,0,0,190,188,1,0,0,0,191,21,1,0,0,0,192,193,6,11,-1,0,193,
  	194,5,31,0,0,194,203,6,11,-1,0,195,196,5,31,0,0,196,197,5,18,0,0,197,
  	198,5,32,0,0,198,199,5,19,0,0,199,203,6,11,-1,0,200,201,9,0,0,0,201,203,
  	6,11,-1,0,202,192,1,0,0,0,202,195,1,0,0,0,202,200,1,0,0,0,203,224,1,0,
  	0,0,204,205,10,2,0,0,205,206,3,12,6,0,206,207,5,31,0,0,207,208,5,21,0,
  	0,208,209,3,22,11,3,209,210,6,11,-1,0,210,223,1,0,0,0,211,212,10,6,0,
  	0,212,213,5,21,0,0,213,214,5,31,0,0,214,223,6,11,-1,0,215,216,10,5,0,
  	0,216,217,5,21,0,0,217,218,5,31,0,0,218,219,5,18,0,0,219,220,5,32,0,0,
  	220,221,5,19,0,0,221,223,6,11,-1,0,222,204,1,0,0,0,222,211,1,0,0,0,222,
  	215,1,0,0,0,223,226,1,0,0,0,224,222,1,0,0,0,224,225,1,0,0,0,225,23,1,
  	0,0,0,226,224,1,0,0,0,227,228,6,12,-1,0,228,229,3,26,13,0,229,230,6,12,
  	-1,0,230,237,1,0,0,0,231,232,10,1,0,0,232,233,3,26,13,0,233,234,6,12,
  	-1,0,234,236,1,0,0,0,235,231,1,0,0,0,236,239,1,0,0,0,237,235,1,0,0,0,
  	237,238,1,0,0,0,238,25,1,0,0,0,239,237,1,0,0,0,240,241,3,16,8,0,241,242,
  	6,13,-1,0,242,294,1,0,0,0,243,244,3,28,14,0,244,245,6,13,-1,0,245,294,
  	1,0,0,0,246,247,6,13,-1,0,247,248,3,14,7,0,248,249,6,13,-1,0,249,294,
  	1,0,0,0,250,251,5,7,0,0,251,252,5,14,0,0,252,253,3,28,14,0,253,254,3,
  	28,14,0,254,255,3,32,16,0,255,256,5,15,0,0,256,257,3,26,13,0,257,258,
  	6,13,-1,0,258,294,1,0,0,0,259,260,5,5,0,0,260,261,5,14,0,0,261,262,3,
  	32,16,0,262,263,5,15,0,0,263,264,3,26,13,0,264,265,6,13,-1,0,265,294,
  	1,0,0,0,266,267,5,5,0,0,267,268,5,14,0,0,268,269,3,32,16,0,269,270,5,
  	15,0,0,270,271,3,26,13,0,271,272,5,6,0,0,272,273,3,26,13,0,273,274,6,
  	13,-1,0,274,294,1,0,0,0,275,276,5,8,0,0,276,277,5,14,0,0,277,278,3,32,
  	16,0,278,279,5,15,0,0,279,280,3,26,13,0,280,281,6,13,-1,0,281,294,1,0,
  	0,0,282,283,5,9,0,0,283,284,5,14,0,0,284,285,5,31,0,0,285,286,5,15,0,
  	0,286,287,5,20,0,0,287,294,6,13,-1,0,288,289,5,10,0,0,289,290,3,32,16,
  	0,290,291,5,20,0,0,291,292,6,13,-1,0,292,294,1,0,0,0,293,240,1,0,0,0,
  	293,243,1,0,0,0,293,246,1,0,0,0,293,250,1,0,0,0,293,259,1,0,0,0,293,266,
  	1,0,0,0,293,275,1,0,0,0,293,282,1,0,0,0,293,288,1,0,0,0,294,27,1,0,0,
  	0,295,296,5,20,0,0,296,302,6,14,-1,0,297,298,3,32,16,0,298,299,5,20,0,
  	0,299,300,6,14,-1,0,300,302,1,0,0,0,301,295,1,0,0,0,301,297,1,0,0,0,302,
  	29,1,0,0,0,303,304,5,31,0,0,304,312,6,15,-1,0,305,306,5,31,0,0,306,307,
  	5,18,0,0,307,308,3,32,16,0,308,309,5,19,0,0,309,310,6,15,-1,0,310,312,
  	1,0,0,0,311,303,1,0,0,0,311,305,1,0,0,0,312,31,1,0,0,0,313,314,3,34,17,
  	0,314,315,6,16,-1,0,315,322,1,0,0,0,316,317,3,30,15,0,317,318,5,30,0,
  	0,318,319,3,34,17,0,319,320,6,16,-1,0,320,322,1,0,0,0,321,313,1,0,0,0,
  	321,316,1,0,0,0,322,33,1,0,0,0,323,324,3,36,18,0,324,325,6,17,-1,0,325,
  	332,1,0,0,0,326,327,3,36,18,0,327,328,5,29,0,0,328,329,3,36,18,0,329,
  	330,6,17,-1,0,330,332,1,0,0,0,331,323,1,0,0,0,331,326,1,0,0,0,332,35,
  	1,0,0,0,333,334,3,38,19,0,334,335,6,18,-1,0,335,342,1,0,0,0,336,337,3,
  	38,19,0,337,338,5,28,0,0,338,339,3,38,19,0,339,340,6,18,-1,0,340,342,
  	1,0,0,0,341,333,1,0,0,0,341,336,1,0,0,0,342,37,1,0,0,0,343,344,6,19,-1,
  	0,344,345,3,40,20,0,345,346,6,19,-1,0,346,360,1,0,0,0,347,348,10,1,0,
  	0,348,349,5,22,0,0,349,350,5,30,0,0,350,351,3,38,19,2,351,352,6,19,-1,
  	0,352,359,1,0,0,0,353,354,10,2,0,0,354,355,5,22,0,0,355,356,3,40,20,0,
  	356,357,6,19,-1,0,357,359,1,0,0,0,358,347,1,0,0,0,358,353,1,0,0,0,359,
  	362,1,0,0,0,360,358,1,0,0,0,360,361,1,0,0,0,361,39,1,0,0,0,362,360,1,
  	0,0,0,363,364,6,20,-1,0,364,365,3,42,21,0,365,366,6,20,-1,0,366,374,1,
  	0,0,0,367,368,10,1,0,0,368,369,5,24,0,0,369,370,3,42,21,0,370,371,6,20,
  	-1,0,371,373,1,0,0,0,372,367,1,0,0,0,373,376,1,0,0,0,374,372,1,0,0,0,
  	374,375,1,0,0,0,375,41,1,0,0,0,376,374,1,0,0,0,377,378,5,22,0,0,378,379,
  	3,42,21,0,379,380,6,21,-1,0,380,389,1,0,0,0,381,382,5,27,0,0,382,383,
  	3,42,21,0,383,384,6,21,-1,0,384,389,1,0,0,0,385,386,3,44,22,0,386,387,
  	6,21,-1,0,387,389,1,0,0,0,388,377,1,0,0,0,388,381,1,0,0,0,388,385,1,0,
  	0,0,389,43,1,0,0,0,390,391,3,30,15,0,391,392,6,22,-1,0,392,417,1,0,0,
  	0,393,394,5,31,0,0,394,395,5,14,0,0,395,396,3,46,23,0,396,397,5,15,0,
  	0,397,398,6,22,-1,0,398,417,1,0,0,0,399,400,5,14,0,0,400,401,3,32,16,
  	0,401,402,5,15,0,0,402,403,6,22,-1,0,403,417,1,0,0,0,404,405,5,32,0,0,
  	405,417,6,22,-1,0,406,407,5,33,0,0,407,417,6,22,-1,0,408,409,3,30,15,
  	0,409,410,5,25,0,0,410,411,6,22,-1,0,411,417,1,0,0,0,412,413,3,30,15,
  	0,413,414,5,26,0,0,414,415,6,22,-1,0,415,417,1,0,0,0,416,390,1,0,0,0,
  	416,393,1,0,0,0,416,399,1,0,0,0,416,404,1,0,0,0,416,406,1,0,0,0,416,408,
  	1,0,0,0,416,412,1,0,0,0,417,45,1,0,0,0,418,419,3,48,24,0,419,420,6,23,
  	-1,0,420,423,1,0,0,0,421,423,6,23,-1,0,422,418,1,0,0,0,422,421,1,0,0,
  	0,423,47,1,0,0,0,424,425,6,24,-1,0,425,426,3,34,17,0,426,427,6,24,-1,
  	0,427,435,1,0,0,0,428,429,10,2,0,0,429,430,5,21,0,0,430,431,3,34,17,0,
  	431,432,6,24,-1,0,432,434,1,0,0,0,433,428,1,0,0,0,434,437,1,0,0,0,435,
  	433,1,0,0,0,435,436,1,0,0,0,436,49,1,0,0,0,437,435,1,0,0,0,28,63,75,93,
  	116,130,143,145,160,164,180,190,202,222,224,237,293,301,311,321,331,341,
  	358,360,374,388,416,422,435
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c8086parserParserStaticData = std::move(staticData);
}

}

C8086Parser::C8086Parser(TokenStream *input) : C8086Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

C8086Parser::C8086Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  C8086Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *c8086parserParserStaticData->atn, c8086parserParserStaticData->decisionToDFA, c8086parserParserStaticData->sharedContextCache, options);
}

C8086Parser::~C8086Parser() {
  delete _interpreter;
}

const atn::ATN& C8086Parser::getATN() const {
  return *c8086parserParserStaticData->atn;
}

std::string C8086Parser::getGrammarFileName() const {
  return "C8086Parser.g4";
}

const std::vector<std::string>& C8086Parser::getRuleNames() const {
  return c8086parserParserStaticData->ruleNames;
}

const dfa::Vocabulary& C8086Parser::getVocabulary() const {
  return c8086parserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C8086Parser::getSerializedATN() const {
  return c8086parserParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

C8086Parser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::ProgramContext* C8086Parser::StartContext::program() {
  return getRuleContext<C8086Parser::ProgramContext>(0);
}


size_t C8086Parser::StartContext::getRuleIndex() const {
  return C8086Parser::RuleStart;
}

void C8086Parser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void C8086Parser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

C8086Parser::StartContext* C8086Parser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, C8086Parser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    antlrcpp::downCast<StartContext *>(_localctx)->p = program(0);

            writeIntoparserLogFile(
                "Line " + antlrcpp::downCast<StartContext *>(_localctx)->p->lineNo + ": start : program\n"
            );

            symTable->printAllScopes();

            writeIntoparserLogFile(
    		             "Total number of lines: " + antlrcpp::downCast<StartContext *>(_localctx)->p->lineNo + "\n" +
                "Total number of errors: " + std::to_string(syntaxErrorCount)
            );
    	
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

C8086Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::UnitContext* C8086Parser::ProgramContext::unit() {
  return getRuleContext<C8086Parser::UnitContext>(0);
}

C8086Parser::ProgramContext* C8086Parser::ProgramContext::program() {
  return getRuleContext<C8086Parser::ProgramContext>(0);
}


size_t C8086Parser::ProgramContext::getRuleIndex() const {
  return C8086Parser::RuleProgram;
}

void C8086Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void C8086Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


C8086Parser::ProgramContext* C8086Parser::program() {
   return program(0);
}

C8086Parser::ProgramContext* C8086Parser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  C8086Parser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, C8086Parser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(54);
    antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

            antlrcpp::downCast<ProgramContext *>(_localctx)->text =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->text;
            antlrcpp::downCast<ProgramContext *>(_localctx)->lineNo =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->lineNo;
            writeIntoparserLogFile(
                "Line " + _localctx->lineNo + ": program : unit\n\n" +
                _localctx->text + "\n"
            );
        
    _ctx->stop = _input->LT(-1);
    setState(63);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        _localctx->p = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(57);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(58);
        antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

                          antlrcpp::downCast<ProgramContext *>(_localctx)->text =  antlrcpp::downCast<ProgramContext *>(_localctx)->p->text + "\n" + antlrcpp::downCast<ProgramContext *>(_localctx)->u->text;
                          antlrcpp::downCast<ProgramContext *>(_localctx)->lineNo =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->lineNo; 
                          writeIntoparserLogFile(
                              "Line " + _localctx->lineNo + ": program : program unit\n\n" +
                              _localctx->text + "\n"
                          );
                       
      }
      setState(65);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

C8086Parser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Var_declarationContext* C8086Parser::UnitContext::var_declaration() {
  return getRuleContext<C8086Parser::Var_declarationContext>(0);
}

C8086Parser::Func_declarationContext* C8086Parser::UnitContext::func_declaration() {
  return getRuleContext<C8086Parser::Func_declarationContext>(0);
}

C8086Parser::Func_definitionContext* C8086Parser::UnitContext::func_definition() {
  return getRuleContext<C8086Parser::Func_definitionContext>(0);
}


size_t C8086Parser::UnitContext::getRuleIndex() const {
  return C8086Parser::RuleUnit;
}

void C8086Parser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void C8086Parser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
}

C8086Parser::UnitContext* C8086Parser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, C8086Parser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(66);
      antlrcpp::downCast<UnitContext *>(_localctx)->v = var_declaration();

              antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->v->text;
              antlrcpp::downCast<UnitContext *>(_localctx)->lineNo =  std::to_string((antlrcpp::downCast<UnitContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<UnitContext *>(_localctx)->v->stop) : nullptr)->getLine());
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<UnitContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<UnitContext *>(_localctx)->v->stop) : nullptr)->getLine()) + ": unit : var_declaration\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(69);
      antlrcpp::downCast<UnitContext *>(_localctx)->f = func_declaration();

              antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->f->text;
              antlrcpp::downCast<UnitContext *>(_localctx)->lineNo =  std::to_string((antlrcpp::downCast<UnitContext *>(_localctx)->f != nullptr ? (antlrcpp::downCast<UnitContext *>(_localctx)->f->stop) : nullptr)->getLine());
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<UnitContext *>(_localctx)->f != nullptr ? (antlrcpp::downCast<UnitContext *>(_localctx)->f->stop) : nullptr)->getLine()) + ": unit : func_declaration\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(72);
      antlrcpp::downCast<UnitContext *>(_localctx)->fd = func_definition();

              antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->fd->text;
              antlrcpp::downCast<UnitContext *>(_localctx)->lineNo =  antlrcpp::downCast<UnitContext *>(_localctx)->fd->lineNo;
              writeIntoparserLogFile(
                  "Line " + antlrcpp::downCast<UnitContext *>(_localctx)->fd->lineNo + ": unit : func_definition\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

C8086Parser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Type_specifierContext* C8086Parser::Func_declarationContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

C8086Parser::Parameter_listContext* C8086Parser::Func_declarationContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}


size_t C8086Parser::Func_declarationContext::getRuleIndex() const {
  return C8086Parser::RuleFunc_declaration;
}

void C8086Parser::Func_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_declaration(this);
}

void C8086Parser::Func_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_declaration(this);
}

C8086Parser::Func_declarationContext* C8086Parser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, C8086Parser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(93);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(77);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(78);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->id = match(C8086Parser::ID);
      setState(79);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->lp = match(C8086Parser::LPAREN);

              insertIntoTable = false;
          
      setState(81);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl = parameter_list(0);
      setState(82);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->rp = match(C8086Parser::RPAREN);
      setState(83);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->sc = match(C8086Parser::SEMICOLON);

              antlrcpp::downCast<Func_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->lp->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->text + antlrcpp::downCast<Func_declarationContext *>(_localctx)->rp->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->sc->getText();
      		SymbolInfo* s = symTable->insert(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText(), "ID");
          if (s != nullptr) {
      	    s->setFunction(true);
      	    s->setVariableType(antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->text);
      	    s->setDeclared(true);
              int n = antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->ids.size();
              string* paramTypes = new string[n];
              for (int i = 0; i < n; ++i) paramTypes[i] = antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->ids[i].second;
              s->setParamTypes(paramTypes, n);
          }

              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<Func_declarationContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->stop) : nullptr)->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n" +
                  _localctx->text + "\n"        
              );
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(86);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(87);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->id = match(C8086Parser::ID);
      setState(88);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->lp = match(C8086Parser::LPAREN);
      setState(89);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->rp = match(C8086Parser::RPAREN);
      setState(90);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->sc = match(C8086Parser::SEMICOLON);

              antlrcpp::downCast<Func_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->lp->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->rp->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->sc->getText();
      		SymbolInfo* s = symTable->insert(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText(), "ID");
              if (s != nullptr) {
                  s->setFunction(true);
      	        s->setVariableType(antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->text);
      		    s->setDeclared(true);
      	        s->setParamTypes(nullptr, 0);
              }

              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<Func_declarationContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->stop) : nullptr)->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_definitionContext ------------------------------------------------------------------

C8086Parser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Type_specifierContext* C8086Parser::Func_definitionContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C8086Parser::Func_definitionContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Func_definitionContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

C8086Parser::Parameter_listContext* C8086Parser::Func_definitionContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
}

tree::TerminalNode* C8086Parser::Func_definitionContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

C8086Parser::Compound_statementContext* C8086Parser::Func_definitionContext::compound_statement() {
  return getRuleContext<C8086Parser::Compound_statementContext>(0);
}


size_t C8086Parser::Func_definitionContext::getRuleIndex() const {
  return C8086Parser::RuleFunc_definition;
}

void C8086Parser::Func_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_definition(this);
}

void C8086Parser::Func_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_definition(this);
}

C8086Parser::Func_definitionContext* C8086Parser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, C8086Parser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(116);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(95);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(96);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->id = match(C8086Parser::ID);
       
      	    insertIntoTable = true;
      	    SymbolInfo* sym = symTable->lookup(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText());
              string errorText = "";
          
          if (!sym) {
              
              sym = symTable->insert(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText(), "ID");
              sym->setFunction(true);
              sym->setDefined(true);
              sym->setDeclared(false);
              sym->setVariableType(antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text);
      	    
          }
          
          
      setState(98);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lp = match(C8086Parser::LPAREN);

      	        symTable->EnterScope();
          
      setState(100);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl = parameter_list(0);
      setState(101);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rp = match(C8086Parser::RPAREN);

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->param_ids =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->ids;
      	        sym = symTable->lookup(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText());
      	            
                  if(sym->getDeclared()==false) {
      	                int n = antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->ids.size();
                      string* paramTypes = new string[n];
                  for (int i = 0; i < n; ++i) paramTypes[i] = antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->ids[i].second;
                      if(sym) {
                      sym->setParamTypes(paramTypes, n);
                      }
                  }
      	         
              if (!sym->getFunction()) {
                  
      	            writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "\n");
                  errorText = "Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "\n";
                  syntaxErrorCount++;
      	            writeIntoparserLogFile(errorText);
              } else {
                  
      	            if (sym->getVariableType() != antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text) {
      	                writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Return type mismatch of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "\n");
                          errorText = "Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Return type mismatch of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "\n";
                      syntaxErrorCount++;
      	                writeIntoparserLogFile(errorText);
                  }
                  
      	        if (sym->getParamCount() != _localctx->param_ids.size()) {
      	                writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "\n");
                      errorText = "Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "\n";
                      syntaxErrorCount++;
      	                writeIntoparserLogFile(errorText);
                  } else {
                      for (int i = 0; i < sym->getParamCount(); i++) {
                          if (sym->getParamTypes()[i] != _localctx->param_ids[i].second) {
                              writeIntoErrorFile("Line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Type mismatch in parameter " + std::to_string(i+1) + " of function '" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "'");
                              syntaxErrorCount++;
      	                        writeIntoparserLogFile(errorText);
                          }
                      }
                  }
                  sym->setDefined(true);
              }
          
              // sym = symTable->lookup(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText());
      	    
      	        

            
      setState(103);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement(_localctx->param_ids);

      	        
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->lp->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->text + antlrcpp::downCast<Func_definitionContext *>(_localctx)->rp->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->text;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->lineNo =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->lineNo;

      	    sym = symTable->lookup(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText());

              if (sym != nullptr) {
                  string expectedVarType = sym->getVariableType();
                  if(expectedVarType=="void" && antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->returnType!=""){
      		            writeIntoErrorFile("Error at line " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->lineNo+ ": Cannot return value from function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + " with void return type.\n");
                      syntaxErrorCount++;
                      errorText = "Error at line " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->lineNo + ": Cannot return value from function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + " with void return type.\n";
                      writeIntoparserLogFile(errorText);

                  }
      // 	        else if(expectedVarType=="int" && antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->returnType!="int"){
      // 	                writeIntoErrorFile("Error at line " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->lineNo
      //  + ": Cannot return value from function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + " with int return type\n");
      //                 syntaxErrorCount++;

                      
      //             }

      // 	        else if(expectedVarType=="float" && antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->returnType!="float"){
      // 	                writeIntoErrorFile("Error at line " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->lineNo
      //  + ": Cannot return value from function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + " with float return type\n");
      //                 syntaxErrorCount++;
                      
      //             }
              }
              
              writeIntoparserLogFile(
                  "Line " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->lineNo + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n" +
                  _localctx->text + "\n"
              );


          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(106);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(107);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->id = match(C8086Parser::ID);
       
      	        SymbolInfo* sym = symTable->lookup(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText());
                  string errorText = "";
          
          if (sym != nullptr) {
              if (!sym->getFunction()) {
      		            writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Multiple declaration of" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "\n");
                  errorText = "Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "\n";
                  syntaxErrorCount++;
      	            writeIntoparserLogFile(errorText);
              } else if (sym->getDefined()) {
                  writeIntoErrorFile("Line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Function '" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "' is already defined");
                  errorText = "Line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Function '" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "' is already defined\n";
                  syntaxErrorCount++;
      	            writeIntoparserLogFile(errorText);
              } else {
                  if (sym->getVariableType() != antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text || sym->getParamCount() > 0) {
                      writeIntoErrorFile("Line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Function definition mismatch with declaration for '" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "'");
                      errorText = "Line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Function definition mismatch with declaration for '" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "'\n";
                      syntaxErrorCount++;
      	                writeIntoparserLogFile(errorText);
                  }
                  sym->setDefined(true);
              }
          } else {
              sym = symTable->insert(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText(), "ID");
              sym->setFunction(true);
              sym->setDefined(true);
              sym->setVariableType(antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text);
      	    sym->setParamTypes(nullptr, 0);
          }
      	    
          
      setState(109);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lp = match(C8086Parser::LPAREN);

                  symTable->EnterScope();
          
      setState(111);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rp = match(C8086Parser::RPAREN);

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->param_ids =  {};

      	
      	    
      setState(113);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement(_localctx->param_ids);

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->lp->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->rp->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->text;
      		      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lineNo =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->lineNo;   

      	    sym = symTable->lookup(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText());

              if (sym != nullptr) {
                  string expectedVarType = sym->getVariableType();
      		            cout<<antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()<<" "<<expectedVarType<<endl;
                  if(expectedVarType=="void" && antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->returnType!=""){
      		            writeIntoErrorFile("Error at line " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->lineNo + ": Cannot return value from function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + " with void return type.\n");
                      syntaxErrorCount++;
                      errorText = "Error at line " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->lineNo + ": Cannot return value from function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + " with void return type.\n";
                      writeIntoparserLogFile(errorText);

                  }
      	        // else if(expectedVarType=="int" && antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->returnType!="int"){
      	        //         writeIntoErrorFile("Error at line " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->lineNo + ": Cannot return value from function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + " with int return type\n");
                  //     syntaxErrorCount++;
                      
                  // }

      	        // else if(expectedVarType=="float" && antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->returnType!="float"){
      	        //        writeIntoErrorFile("Error at line " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->lineNo + ": Cannot return value from function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + " with float return type\n");
                  //     syntaxErrorCount++;
                      
                  // }
              }
              writeIntoparserLogFile(
      	            "Line " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->lineNo + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

C8086Parser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Type_specifierContext* C8086Parser::Parameter_listContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C8086Parser::Parameter_listContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

C8086Parser::Invalid_paramContext* C8086Parser::Parameter_listContext::invalid_param() {
  return getRuleContext<C8086Parser::Invalid_paramContext>(0);
}

C8086Parser::Parameter_listContext* C8086Parser::Parameter_listContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
}

tree::TerminalNode* C8086Parser::Parameter_listContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}


size_t C8086Parser::Parameter_listContext::getRuleIndex() const {
  return C8086Parser::RuleParameter_list;
}

void C8086Parser::Parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list(this);
}

void C8086Parser::Parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list(this);
}


C8086Parser::Parameter_listContext* C8086Parser::parameter_list() {
   return parameter_list(0);
}

C8086Parser::Parameter_listContext* C8086Parser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  C8086Parser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, C8086Parser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(130);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(119);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
      setState(120);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->id = match(C8086Parser::ID);

              string errorText = "";
      	    antlrcpp::downCast<Parameter_listContext *>(_localctx)->ids =  { { antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText(), antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text } };
              antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText();
      	    
              if(insertIntoTable) {
      	        SymbolInfo* s = symTable->insert(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText(), "ID");
                  if (s != nullptr) {
      	            s->setVariableType(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text);
      	                
                  }
                  else{
      			        writeIntoErrorFile("Error at line " + std::to_string((antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts != nullptr ? (antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->stop) : nullptr)->getLine()

      ) + ": Multiple declaration of " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() + " in parameter\n");
                      errorText = "Error at line " + std::to_string((antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts != nullptr ? (antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->stop) : nullptr)->getLine()

      ) + ": Multiple declaration of " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() + " in parameter\n";
                      syntaxErrorCount++;
                      writeIntoparserLogFile(errorText);
                  }
          }
      	    writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts != nullptr ? (antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->stop) : nullptr)->getLine()) + ": parameter_list : type_specifier ID\n\n" +
                  _localctx->text + "\n"
              );
              
          
      break;
    }

    case 2: {
      setState(123);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();

      	    antlrcpp::downCast<Parameter_listContext *>(_localctx)->ids =  { { "", antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text } };

              antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text;
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts != nullptr ? (antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->stop) : nullptr)->getLine()) + ": parameter_list : type_specifier\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    case 3: {
      setState(126);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
      setState(127);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->ip = invalid_param();

          antlrcpp::downCast<Parameter_listContext *>(_localctx)->ids =  { { "", antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text } };
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text;

          writeIntoparserLogFile(
              "Line " + std::to_string((antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts != nullptr ? (antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->stop) : nullptr)->getLine()) + ": parameter_list : type_specifier\n\n" +
              _localctx->text + "\n"
          );

          writeIntoparserLogFile(
              "Error at line " + std::to_string((antlrcpp::downCast<Parameter_listContext *>(_localctx)->ip != nullptr ? (antlrcpp::downCast<Parameter_listContext *>(_localctx)->ip->start) : nullptr)->getLine()) +
              ": syntax error, unexpected " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->ip->name + ", expecting RPAREN or COMMA\n"
          );

          writeIntoErrorFile(
              "Error at line " + std::to_string((antlrcpp::downCast<Parameter_listContext *>(_localctx)->ip != nullptr ? (antlrcpp::downCast<Parameter_listContext *>(_localctx)->ip->start) : nullptr)->getLine()) +
              ": syntax error, unexpected " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->ip->name + ", expecting RPAREN or COMMA\n"
          );

          syntaxErrorCount++;

      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(145);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(143);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(132);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(133);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->cm = match(C8086Parser::COMMA);
          setState(134);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();
          setState(135);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->id = match(C8086Parser::ID);

                            string errorText = "";
                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->ids =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->ids;
                    	    _localctx->ids.push_back({ antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText(), antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text });
                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->text + antlrcpp::downCast<Parameter_listContext *>(_localctx)->cm->getText() + antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text +" "+ antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText();

                    	    
                            
                            if(insertIntoTable) {
                               
                    	        SymbolInfo* s = symTable->insert(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText(), "ID");
                                if (s != nullptr) {
                    	            s->setVariableType(antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text);
                    	               
                                }
                                else{
                    			        writeIntoErrorFile("Error at line " + std::to_string((antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts != nullptr ? (antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->stop) : nullptr)->getLine())
                                         + ": Multiple declaration of " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() + " in parameter\n");
                                        errorText = "Error at line " + std::to_string((antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts != nullptr ? (antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->stop) : nullptr)->getLine())
                                         + ": Multiple declaration of " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() + " in parameter\n";
                                    syntaxErrorCount++;
                                    writeIntoparserLogFile(errorText);
                                }
                        }
                    	    writeIntoparserLogFile(
                                "Line " + std::to_string((antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl != nullptr ? (antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->stop) : nullptr)->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID\n\n" +
                                _localctx->text + "\n"
                            );
                            
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->pl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(138);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(139);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->cm = match(C8086Parser::COMMA);
          setState(140);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts = type_specifier();

                    	    antlrcpp::downCast<Parameter_listContext *>(_localctx)->ids =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->ids;
                            _localctx->ids.push_back({ "", antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text });

                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->text + antlrcpp::downCast<Parameter_listContext *>(_localctx)->cm->getText() + antlrcpp::downCast<Parameter_listContext *>(_localctx)->ts->text;
                            writeIntoparserLogFile(
                                "Line " + std::to_string((antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl != nullptr ? (antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->stop) : nullptr)->getLine()) + ": parameter_list : parameter_list COMMA type_specifier\n\n" +
                                _localctx->text + "\n"
                            );
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(147);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Invalid_paramContext ------------------------------------------------------------------

C8086Parser::Invalid_paramContext::Invalid_paramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Invalid_paramContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}

tree::TerminalNode* C8086Parser::Invalid_paramContext::MULOP() {
  return getToken(C8086Parser::MULOP, 0);
}

tree::TerminalNode* C8086Parser::Invalid_paramContext::RELOP() {
  return getToken(C8086Parser::RELOP, 0);
}

tree::TerminalNode* C8086Parser::Invalid_paramContext::ASSIGNOP() {
  return getToken(C8086Parser::ASSIGNOP, 0);
}

tree::TerminalNode* C8086Parser::Invalid_paramContext::LOGICOP() {
  return getToken(C8086Parser::LOGICOP, 0);
}

tree::TerminalNode* C8086Parser::Invalid_paramContext::NOT() {
  return getToken(C8086Parser::NOT, 0);
}


size_t C8086Parser::Invalid_paramContext::getRuleIndex() const {
  return C8086Parser::RuleInvalid_param;
}

void C8086Parser::Invalid_paramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInvalid_param(this);
}

void C8086Parser::Invalid_paramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInvalid_param(this);
}

C8086Parser::Invalid_paramContext* C8086Parser::invalid_param() {
  Invalid_paramContext *_localctx = _tracker.createInstance<Invalid_paramContext>(_ctx, getState());
  enterRule(_localctx, 12, C8086Parser::RuleInvalid_param);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(160);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(148);
        match(C8086Parser::ADDOP);

                antlrcpp::downCast<Invalid_paramContext *>(_localctx)->name =  "ADDOP";
            
        break;
      }

      case C8086Parser::MULOP: {
        enterOuterAlt(_localctx, 2);
        setState(150);
        match(C8086Parser::MULOP);

                antlrcpp::downCast<Invalid_paramContext *>(_localctx)->name =  "MULOP";
            
        break;
      }

      case C8086Parser::RELOP: {
        enterOuterAlt(_localctx, 3);
        setState(152);
        match(C8086Parser::RELOP);

                antlrcpp::downCast<Invalid_paramContext *>(_localctx)->name =  "RELOP";
            
        break;
      }

      case C8086Parser::ASSIGNOP: {
        enterOuterAlt(_localctx, 4);
        setState(154);
        match(C8086Parser::ASSIGNOP);

                antlrcpp::downCast<Invalid_paramContext *>(_localctx)->name =  "ASSIGNOP";
            
        break;
      }

      case C8086Parser::LOGICOP: {
        enterOuterAlt(_localctx, 5);
        setState(156);
        match(C8086Parser::LOGICOP);
         
                antlrcpp::downCast<Invalid_paramContext *>(_localctx)->name =  "LOGICOP";
            
        break;
      }

      case C8086Parser::NOT: {
        enterOuterAlt(_localctx, 6);
        setState(158);
        match(C8086Parser::NOT);
         
                antlrcpp::downCast<Invalid_paramContext *>(_localctx)->name =  "NOT";
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

C8086Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState, std::vector<std::pair<std::string, std::string>> param_ids)
  : ParserRuleContext(parent, invokingState) {
  this->param_ids = param_ids;
}

tree::TerminalNode* C8086Parser::Compound_statementContext::LCURL() {
  return getToken(C8086Parser::LCURL, 0);
}

tree::TerminalNode* C8086Parser::Compound_statementContext::RCURL() {
  return getToken(C8086Parser::RCURL, 0);
}

C8086Parser::StatementsContext* C8086Parser::Compound_statementContext::statements() {
  return getRuleContext<C8086Parser::StatementsContext>(0);
}


size_t C8086Parser::Compound_statementContext::getRuleIndex() const {
  return C8086Parser::RuleCompound_statement;
}

void C8086Parser::Compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement(this);
}

void C8086Parser::Compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement(this);
}

C8086Parser::Compound_statementContext* C8086Parser::compound_statement(std::vector<std::pair<std::string, std::string>> param_ids) {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState(), param_ids);
  enterRule(_localctx, 14, C8086Parser::RuleCompound_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    antlrcpp::downCast<Compound_statementContext *>(_localctx)->lc = match(C8086Parser::LCURL);
    setState(164);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 15171944352) != 0)) {
      setState(163);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->st = statements(0);
    }
    setState(166);
    antlrcpp::downCast<Compound_statementContext *>(_localctx)->rc = match(C8086Parser::RCURL);

    	antlrcpp::downCast<Compound_statementContext *>(_localctx)->returnType =  "";
    antlrcpp::downCast<Compound_statementContext *>(_localctx)->text =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->lc->getText() + "\n";

    if (antlrcpp::downCast<Compound_statementContext *>(_localctx)->st != nullptr) {
        _localctx->text += antlrcpp::downCast<Compound_statementContext *>(_localctx)->st->text;
        antlrcpp::downCast<Compound_statementContext *>(_localctx)->returnType =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->st->returnType;
    }

    _localctx->text += "\n" + antlrcpp::downCast<Compound_statementContext *>(_localctx)->rc->getText();
    antlrcpp::downCast<Compound_statementContext *>(_localctx)->lineNo =  std::to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->rc->getLine());

    writeIntoparserLogFile(
        "Line " + _localctx->lineNo + ": compound_statement : LCURL statements RCURL\n\n" +
        _localctx->text + "\n"
    );

    symTable->printAllScopes();
    symTable->ExitScope();

        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

C8086Parser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Type_specifierContext* C8086Parser::Var_declarationContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

C8086Parser::Declaration_listContext* C8086Parser::Var_declarationContext::declaration_list() {
  return getRuleContext<C8086Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C8086Parser::Var_declarationContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

C8086Parser::Declaration_list_errContext* C8086Parser::Var_declarationContext::declaration_list_err() {
  return getRuleContext<C8086Parser::Declaration_list_errContext>(0);
}


size_t C8086Parser::Var_declarationContext::getRuleIndex() const {
  return C8086Parser::RuleVar_declaration;
}

void C8086Parser::Var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration(this);
}

void C8086Parser::Var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration(this);
}

C8086Parser::Var_declarationContext* C8086Parser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 16, C8086Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(180);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(169);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();

      	        currentVarType= antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text;
          
      setState(171);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
      setState(172);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C8086Parser::SEMICOLON);

              antlrcpp::downCast<Var_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->text + antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getText();
              string errorText = "";

              if(antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text == "void") {
                  writeIntoErrorFile(
      	                "Error at line " + std::to_string((antlrcpp::downCast<Var_declarationContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->stop) : nullptr)->getLine()) + ": Variable type cannot be void\n"
                  );
                  syntaxErrorCount++;
                  errorText = "Error at line " + std::to_string((antlrcpp::downCast<Var_declarationContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->stop) : nullptr)->getLine()) + ": Variable type cannot be void\n\n";
              }
              
              writeIntoparserLogFile(
                  "Line " + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON\n\n" +
                  errorText +
      			_localctx->text + "\n"
              );

      	    //     for (auto &decl : antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->ids) {
              //     std::string name = decl.first;

              //     SymbolInfo* sym = symTable->lookup(name);
              //     if (sym != nullptr) {
              //         sym->setVariableType(antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text);
              //     }
              // }

      		
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(175);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(176);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->de = declaration_list_err();
      setState(177);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C8086Parser::SEMICOLON);

              antlrcpp::downCast<Var_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->de->error_name + antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getText();
              
              writeIntoErrorFile(
                  "Line " + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": var_declaration : type_specifier declaration_list_err SEMICOLON\n\n" +
      			_localctx->text + "\n"
              );

              syntaxErrorCount++;
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_list_errContext ------------------------------------------------------------------

C8086Parser::Declaration_list_errContext::Declaration_list_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C8086Parser::Declaration_list_errContext::getRuleIndex() const {
  return C8086Parser::RuleDeclaration_list_err;
}

void C8086Parser::Declaration_list_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list_err(this);
}

void C8086Parser::Declaration_list_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list_err(this);
}

C8086Parser::Declaration_list_errContext* C8086Parser::declaration_list_err() {
  Declaration_list_errContext *_localctx = _tracker.createInstance<Declaration_list_errContext>(_ctx, getState());
  enterRule(_localctx, 18, C8086Parser::RuleDeclaration_list_err);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

            antlrcpp::downCast<Declaration_list_errContext *>(_localctx)->error_name =  "Error in declaration list";
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

C8086Parser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Type_specifierContext::INT() {
  return getToken(C8086Parser::INT, 0);
}

tree::TerminalNode* C8086Parser::Type_specifierContext::FLOAT() {
  return getToken(C8086Parser::FLOAT, 0);
}

tree::TerminalNode* C8086Parser::Type_specifierContext::VOID() {
  return getToken(C8086Parser::VOID, 0);
}


size_t C8086Parser::Type_specifierContext::getRuleIndex() const {
  return C8086Parser::RuleType_specifier;
}

void C8086Parser::Type_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_specifier(this);
}

void C8086Parser::Type_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_specifier(this);
}

C8086Parser::Type_specifierContext* C8086Parser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 20, C8086Parser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(190);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(184);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken = match(C8086Parser::INT);

                antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getText();
                antlrcpp::downCast<Type_specifierContext *>(_localctx)->name_line =  "Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine()) + ": type_specifier : INT\n\n" + _localctx->text + "\n";
                writeIntoparserLogFile(_localctx->name_line);
            
        break;
      }

      case C8086Parser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(186);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken = match(C8086Parser::FLOAT);

                antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getText();
                antlrcpp::downCast<Type_specifierContext *>(_localctx)->name_line =  "Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine()) + ": type_specifier : FLOAT\n\n" + _localctx->text + "\n";
                writeIntoparserLogFile(_localctx->name_line);
            
        break;
      }

      case C8086Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(188);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken = match(C8086Parser::VOID);

                antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getText();
                antlrcpp::downCast<Type_specifierContext *>(_localctx)->name_line =  "Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getLine()) + ": type_specifier : VOID\n\n" + _localctx->text + "\n";
                writeIntoparserLogFile(_localctx->name_line);
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

C8086Parser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Declaration_listContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::LTHIRD() {
  return getToken(C8086Parser::LTHIRD, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::CONST_INT() {
  return getToken(C8086Parser::CONST_INT, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::RTHIRD() {
  return getToken(C8086Parser::RTHIRD, 0);
}

std::vector<C8086Parser::Declaration_listContext *> C8086Parser::Declaration_listContext::declaration_list() {
  return getRuleContexts<C8086Parser::Declaration_listContext>();
}

C8086Parser::Declaration_listContext* C8086Parser::Declaration_listContext::declaration_list(size_t i) {
  return getRuleContext<C8086Parser::Declaration_listContext>(i);
}

C8086Parser::Invalid_paramContext* C8086Parser::Declaration_listContext::invalid_param() {
  return getRuleContext<C8086Parser::Invalid_paramContext>(0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}


size_t C8086Parser::Declaration_listContext::getRuleIndex() const {
  return C8086Parser::RuleDeclaration_list;
}

void C8086Parser::Declaration_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list(this);
}

void C8086Parser::Declaration_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list(this);
}


C8086Parser::Declaration_listContext* C8086Parser::declaration_list() {
   return declaration_list(0);
}

C8086Parser::Declaration_listContext* C8086Parser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  C8086Parser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, C8086Parser::RuleDeclaration_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(202);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(193);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C8086Parser::ID);

              antlrcpp::downCast<Declaration_listContext *>(_localctx)->ids =  { { antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText(), -1 } };
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText();
      			        std::string name = antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText();
      	
      			std::string type = "ID";

      	    SymbolInfo* sym = symTable->insert(name, type);
      	
      			if(!sym) {
      	                writeIntoparserLogFile(
      		                    "Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + name + "\n"
                      );
      	                writeIntoErrorFile(
      	                     "Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + name + "\n"
                      );
                      syntaxErrorCount++;
                  }
      	    if(sym){
      	            sym->setArray(false);
      	                sym->setDeclared(true);
                          sym->setVariableType(currentVarType);
      	                    // cout<< antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText()<<" isarray "<<sym->getArray()<<endl;
              }
              
      		writeIntoparserLogFile(
      			"Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": declaration_list : ID\n\n" +
      			_localctx->text + "\n"
      		);
          
      break;
    }

    case 2: {
      setState(195);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C8086Parser::ID);
      setState(196);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->lt = match(C8086Parser::LTHIRD);
      setState(197);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->size = match(C8086Parser::CONST_INT);
      setState(198);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->rt = match(C8086Parser::RTHIRD);

              antlrcpp::downCast<Declaration_listContext *>(_localctx)->ids =  { { antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText(), std::stoi(antlrcpp::downCast<Declaration_listContext *>(_localctx)->size->getText()) } };
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->lt->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->size->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->rt->getText();

      	        		        std::string name = antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText();
      			
      			std::string type = "ID";

                  SymbolInfo* sym = symTable->insert(name, type);        
      	
      			if(!sym) {
      	                writeIntoparserLogFile(
      		                    "Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + name + "\n"
                      );
      	                writeIntoErrorFile(
      	                     "Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + name + "\n"
                      );
                      syntaxErrorCount++;
                  }
      	    if(sym){
      	            sym->setArray(true);
                          sym->setDeclared(true);
                          sym->setVariableType(currentVarType);
      	                    // cout<< antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText()<<" isarray "<<sym->getArray()<<endl;
              }  
              
              
      		writeIntoparserLogFile(
      			"Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n" +
      			_localctx->text + "\n"
      		);
          
      break;
    }

    case 3: {
      setState(200);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->error_recovery = matchWildcard();

              
              writeIntoparserLogFile(
                  "Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->error_recovery->getLine()) + 
                  ": syntax error in declaration_list, unexpected token '" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->error_recovery->getText() + "'\n"
              );
              writeIntoErrorFile(
                  "Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->error_recovery->getLine()) + 
                  ": syntax error in declaration_list, unexpected token '" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->error_recovery->getText() + "'\n"
              );
              syntaxErrorCount++;
              
              // Initialize return values to avoid parser errors
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->ids =  {};
              antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  "";
          
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(224);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(222);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->d4 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(204);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(205);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->ip = invalid_param();
          setState(206);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C8086Parser::ID);
          setState(207);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->cm = match(C8086Parser::COMMA);
          setState(208);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->d5 = declaration_list(3);

                            
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->ids =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->d4->ids;
                            _localctx->ids.insert(_localctx->ids.end(), antlrcpp::downCast<Declaration_listContext *>(_localctx)->d5->ids.begin(), antlrcpp::downCast<Declaration_listContext *>(_localctx)->d5->ids.end());
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->d4->text + antlrcpp::downCast<Declaration_listContext *>(_localctx)->cm->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->d5->text; // Skip the ADDOP and ID after it
                            
                            
                            writeIntoErrorFile(
                                "Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->cm->getLine()) + 
                    		            ": syntax error, unexpected " + antlrcpp::downCast<Declaration_listContext *>(_localctx)->ip->name + ", expecting COMMA or SEMICOLON\n"
                            );
                            writeIntoparserLogFile(
                                "Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->cm->getLine()) + 
                                        ": syntax error, unexpected " + antlrcpp::downCast<Declaration_listContext *>(_localctx)->ip->name + ", expecting COMMA or SEMICOLON\n"
                            );
                    	        writeIntoparserLogFile(
                    	            "Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->cm->getLine()) + ": declaration_list : declaration_list COMMA ID\n\n" +
                                _localctx->text + "\n"
                            );
                            syntaxErrorCount++;
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->d1 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(211);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(212);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->cm = match(C8086Parser::COMMA);
          setState(213);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C8086Parser::ID);

                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->ids =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->d1->ids;
                            _localctx->ids.push_back({antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText(), -1});
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->d1->text + antlrcpp::downCast<Declaration_listContext *>(_localctx)->cm->getText()  + antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText();

                    		        std::string name = antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText();
                    			
                    			std::string type = "ID";

                                SymbolInfo* sym = symTable->insert(name, type);
                    	
                    			if(!sym) {
                    	                writeIntoparserLogFile(
                    		                    "Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + name + "\n"
                                    );
                                    writeIntoErrorFile(
                    	                     "Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + name + "\n"
                                    );
                                    syntaxErrorCount++;
                                }
                    	    if(sym){
                    	            sym->setArray(false);
                    	                sym->setDeclared(true);
                                        sym->setVariableType(currentVarType);
                    		                    // cout<< antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText()<<" isarray "<<sym->getArray()<<endl;
                            }
                            
                    		
                    		writeIntoparserLogFile(
                    			"Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": declaration_list : declaration_list COMMA ID\n\n" +
                    			_localctx->text + "\n"
                    		);
                        
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->d2 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(215);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(216);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->cm = match(C8086Parser::COMMA);
          setState(217);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C8086Parser::ID);
          setState(218);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->lt = match(C8086Parser::LTHIRD);
          setState(219);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->size = match(C8086Parser::CONST_INT);
          setState(220);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->rt = match(C8086Parser::RTHIRD);

                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->ids =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->d2->ids;
                            _localctx->ids.push_back({antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText(), std::stoi(antlrcpp::downCast<Declaration_listContext *>(_localctx)->size->getText())});
                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->d2->text + antlrcpp::downCast<Declaration_listContext *>(_localctx)->cm->getText()  + antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->lt->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->size->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->rt->getText();
                    	             std::string name = antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText();
                    				
                    			std::string type = "ID";
                                SymbolInfo* sym = symTable->insert(name, type);
                    			if(!sym) {
                    	                writeIntoparserLogFile(
                    		                    "Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + name + "\n"
                                    );
                                    writeIntoErrorFile(
                                             "Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + name + "\n"
                                    );
                                    syntaxErrorCount++;
                                }
                    		        if(sym){
                    	            sym->setArray(true);
                    	                sym->setDeclared(true);
                                        sym->setVariableType(currentVarType);
                    	                    // cout<< antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText()<<" isarray "<<sym->getArray()<<endl;
                            }
                            
                    		writeIntoparserLogFile(
                    			"Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n" +
                    			_localctx->text + "\n"
                    		);
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(226);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

C8086Parser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::StatementContext* C8086Parser::StatementsContext::statement() {
  return getRuleContext<C8086Parser::StatementContext>(0);
}

C8086Parser::StatementsContext* C8086Parser::StatementsContext::statements() {
  return getRuleContext<C8086Parser::StatementsContext>(0);
}


size_t C8086Parser::StatementsContext::getRuleIndex() const {
  return C8086Parser::RuleStatements;
}

void C8086Parser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void C8086Parser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


C8086Parser::StatementsContext* C8086Parser::statements() {
   return statements(0);
}

C8086Parser::StatementsContext* C8086Parser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  C8086Parser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, C8086Parser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(228);
    antlrcpp::downCast<StatementsContext *>(_localctx)->st = statement();

            antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->st->text;
            antlrcpp::downCast<StatementsContext *>(_localctx)->returnType =  antlrcpp::downCast<StatementsContext *>(_localctx)->st->returnType;
            if(_localctx->text!=""){
            writeIntoparserLogFile(
                "Line " + std::to_string((antlrcpp::downCast<StatementsContext *>(_localctx)->st != nullptr ? (antlrcpp::downCast<StatementsContext *>(_localctx)->st->stop) : nullptr)->getLine()) + ": statements : statement\n\n" +
                _localctx->text + "\n"
            );
            }
        
    _ctx->stop = _input->LT(-1);
    setState(237);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
        _localctx->sts = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleStatements);
        setState(231);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(232);
        antlrcpp::downCast<StatementsContext *>(_localctx)->st = statement();

                          antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->sts->text +"\n"+ antlrcpp::downCast<StatementsContext *>(_localctx)->st->text;
                  	    if (!antlrcpp::downCast<StatementsContext *>(_localctx)->st->returnType.empty())
                              antlrcpp::downCast<StatementsContext *>(_localctx)->returnType =  antlrcpp::downCast<StatementsContext *>(_localctx)->st->returnType;
                          else
                              antlrcpp::downCast<StatementsContext *>(_localctx)->returnType =  antlrcpp::downCast<StatementsContext *>(_localctx)->sts->returnType;
                          writeIntoparserLogFile(
                              "Line " + std::to_string((antlrcpp::downCast<StatementsContext *>(_localctx)->st != nullptr ? (antlrcpp::downCast<StatementsContext *>(_localctx)->st->stop) : nullptr)->getLine()) + ": statements : statements statement\n\n" +
                              _localctx->text + "\n"
                          );
                       
      }
      setState(239);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

C8086Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Var_declarationContext* C8086Parser::StatementContext::var_declaration() {
  return getRuleContext<C8086Parser::Var_declarationContext>(0);
}

std::vector<C8086Parser::Expression_statementContext *> C8086Parser::StatementContext::expression_statement() {
  return getRuleContexts<C8086Parser::Expression_statementContext>();
}

C8086Parser::Expression_statementContext* C8086Parser::StatementContext::expression_statement(size_t i) {
  return getRuleContext<C8086Parser::Expression_statementContext>(i);
}

C8086Parser::Compound_statementContext* C8086Parser::StatementContext::compound_statement() {
  return getRuleContext<C8086Parser::Compound_statementContext>(0);
}

tree::TerminalNode* C8086Parser::StatementContext::FOR() {
  return getToken(C8086Parser::FOR, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

C8086Parser::ExpressionContext* C8086Parser::StatementContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}

tree::TerminalNode* C8086Parser::StatementContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

std::vector<C8086Parser::StatementContext *> C8086Parser::StatementContext::statement() {
  return getRuleContexts<C8086Parser::StatementContext>();
}

C8086Parser::StatementContext* C8086Parser::StatementContext::statement(size_t i) {
  return getRuleContext<C8086Parser::StatementContext>(i);
}

tree::TerminalNode* C8086Parser::StatementContext::IF() {
  return getToken(C8086Parser::IF, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::ELSE() {
  return getToken(C8086Parser::ELSE, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::WHILE() {
  return getToken(C8086Parser::WHILE, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::PRINTLN() {
  return getToken(C8086Parser::PRINTLN, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::RETURN() {
  return getToken(C8086Parser::RETURN, 0);
}


size_t C8086Parser::StatementContext::getRuleIndex() const {
  return C8086Parser::RuleStatement;
}

void C8086Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void C8086Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

C8086Parser::StatementContext* C8086Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 26, C8086Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(293);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(240);
      antlrcpp::downCast<StatementContext *>(_localctx)->vd = var_declaration();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->vd->text;
      	    antlrcpp::downCast<StatementContext *>(_localctx)->returnType =  "";
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->vd != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->vd->stop) : nullptr)->getLine()) + ": statement : var_declaration\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(243);
      antlrcpp::downCast<StatementContext *>(_localctx)->es = expression_statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->es->text;
      	        antlrcpp::downCast<StatementContext *>(_localctx)->returnType =  "";
                  if(_localctx->text!=""){
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->es != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->es->stop) : nullptr)->getLine()) + ": statement : expression_statement\n\n" +
                  _localctx->text + "\n"
              );
                  }
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);

      	    std::vector<std::pair<std::string, std::string>> empty_ids;
              symTable->EnterScope();
      	  
      setState(247);
      antlrcpp::downCast<StatementContext *>(_localctx)->cs = compound_statement(empty_ids);

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->cs->text;
      	        antlrcpp::downCast<StatementContext *>(_localctx)->returnType =  "";
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->cs != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->cs->stop) : nullptr)->getLine()) + ": statement : compound_statement\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(250);
      antlrcpp::downCast<StatementContext *>(_localctx)->f = match(C8086Parser::FOR);
      setState(251);
      antlrcpp::downCast<StatementContext *>(_localctx)->lp = match(C8086Parser::LPAREN);
      setState(252);
      antlrcpp::downCast<StatementContext *>(_localctx)->es1 = expression_statement();
      setState(253);
      antlrcpp::downCast<StatementContext *>(_localctx)->es2 = expression_statement();
      setState(254);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(255);
      antlrcpp::downCast<StatementContext *>(_localctx)->rp = match(C8086Parser::RPAREN);
      setState(256);
      antlrcpp::downCast<StatementContext *>(_localctx)->st = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->f->getText()  + antlrcpp::downCast<StatementContext *>(_localctx)->lp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->es1->text  + antlrcpp::downCast<StatementContext *>(_localctx)->es2->text  + antlrcpp::downCast<StatementContext *>(_localctx)->e->text + antlrcpp::downCast<StatementContext *>(_localctx)->rp->getText()  + antlrcpp::downCast<StatementContext *>(_localctx)->st->text;
      	        antlrcpp::downCast<StatementContext *>(_localctx)->returnType =  "";
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->st != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->st->stop) : nullptr)->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(259);
      antlrcpp::downCast<StatementContext *>(_localctx)->i = match(C8086Parser::IF);
      setState(260);
      antlrcpp::downCast<StatementContext *>(_localctx)->lp = match(C8086Parser::LPAREN);
      setState(261);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(262);
      antlrcpp::downCast<StatementContext *>(_localctx)->rp = match(C8086Parser::RPAREN);
      setState(263);
      antlrcpp::downCast<StatementContext *>(_localctx)->st = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->i->getText()  + antlrcpp::downCast<StatementContext *>(_localctx)->lp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->e->text + antlrcpp::downCast<StatementContext *>(_localctx)->rp->getText()  + antlrcpp::downCast<StatementContext *>(_localctx)->st->text;
      	        antlrcpp::downCast<StatementContext *>(_localctx)->returnType =  antlrcpp::downCast<StatementContext *>(_localctx)->st->returnType;
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->st != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->st->stop) : nullptr)->getLine()) + ": statement : IF LPAREN expression RPAREN statement\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(266);
      antlrcpp::downCast<StatementContext *>(_localctx)->i = match(C8086Parser::IF);
      setState(267);
      antlrcpp::downCast<StatementContext *>(_localctx)->lp = match(C8086Parser::LPAREN);
      setState(268);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(269);
      antlrcpp::downCast<StatementContext *>(_localctx)->rp = match(C8086Parser::RPAREN);
      setState(270);
      antlrcpp::downCast<StatementContext *>(_localctx)->st1 = statement();
      setState(271);
      antlrcpp::downCast<StatementContext *>(_localctx)->el = match(C8086Parser::ELSE);
      setState(272);
      antlrcpp::downCast<StatementContext *>(_localctx)->st2 = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->i->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->e->text + antlrcpp::downCast<StatementContext *>(_localctx)->rp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->st1->text + antlrcpp::downCast<StatementContext *>(_localctx)->el->getText()+" "  + antlrcpp::downCast<StatementContext *>(_localctx)->st2->text;
      	    if (!antlrcpp::downCast<StatementContext *>(_localctx)->st1->returnType.empty() && antlrcpp::downCast<StatementContext *>(_localctx)->st1->returnType == antlrcpp::downCast<StatementContext *>(_localctx)->st2->returnType)
                  antlrcpp::downCast<StatementContext *>(_localctx)->returnType =  antlrcpp::downCast<StatementContext *>(_localctx)->st1->returnType;
              else
                  antlrcpp::downCast<StatementContext *>(_localctx)->returnType =  ""; // mismatch or one branch doesn't return
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->st2 != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->st2->stop) : nullptr)->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(275);
      antlrcpp::downCast<StatementContext *>(_localctx)->w = match(C8086Parser::WHILE);
      setState(276);
      antlrcpp::downCast<StatementContext *>(_localctx)->lp = match(C8086Parser::LPAREN);
      setState(277);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(278);
      antlrcpp::downCast<StatementContext *>(_localctx)->rp = match(C8086Parser::RPAREN);
      setState(279);
      antlrcpp::downCast<StatementContext *>(_localctx)->st = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->w->getText()  + antlrcpp::downCast<StatementContext *>(_localctx)->lp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->e->text + antlrcpp::downCast<StatementContext *>(_localctx)->rp->getText()  + antlrcpp::downCast<StatementContext *>(_localctx)->st->text;
      	        antlrcpp::downCast<StatementContext *>(_localctx)->returnType =  ""; // loop body might not return
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->st != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->st->stop) : nullptr)->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(282);
      antlrcpp::downCast<StatementContext *>(_localctx)->p = match(C8086Parser::PRINTLN);
      setState(283);
      antlrcpp::downCast<StatementContext *>(_localctx)->lp = match(C8086Parser::LPAREN);
      setState(284);
      antlrcpp::downCast<StatementContext *>(_localctx)->id = match(C8086Parser::ID);
      setState(285);
      antlrcpp::downCast<StatementContext *>(_localctx)->rp = match(C8086Parser::RPAREN);
      setState(286);
      antlrcpp::downCast<StatementContext *>(_localctx)->sc = match(C8086Parser::SEMICOLON);

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->p->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->id->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->rp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->sc->getText();
      	        antlrcpp::downCast<StatementContext *>(_localctx)->returnType =  "";
              string errorText = "";
              SymbolInfo* sym = symTable->lookup(antlrcpp::downCast<StatementContext *>(_localctx)->id->getText());
              if(!sym){
                  writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->id->getLine()) + ": Undeclared variable " + antlrcpp::downCast<StatementContext *>(_localctx)->id->getText() + "\n");
                  syntaxErrorCount++;
                  errorText = "Error at line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->id->getLine()) + ": Undeclared variable " + antlrcpp::downCast<StatementContext *>(_localctx)->id->getText() + "\n\n";
                  // writeIntoparserLogFile(
                  //     "Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->sc->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n" +
                  //     _localctx->text + "\n"
                  // );
              }

      	        writeIntoparserLogFile(
                  "Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->sc->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n" +
                  errorText +
                  _localctx->text + "\n"
              );
          
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(288);
      antlrcpp::downCast<StatementContext *>(_localctx)->r = match(C8086Parser::RETURN);
      setState(289);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(290);
      antlrcpp::downCast<StatementContext *>(_localctx)->sc = match(C8086Parser::SEMICOLON);

              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->r->getText() + " " + antlrcpp::downCast<StatementContext *>(_localctx)->e->text + antlrcpp::downCast<StatementContext *>(_localctx)->sc->getText();
      	    antlrcpp::downCast<StatementContext *>(_localctx)->returnType =  antlrcpp::downCast<StatementContext *>(_localctx)->e->type;
              writeIntoparserLogFile(
                  "Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->sc->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

C8086Parser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Expression_statementContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

C8086Parser::ExpressionContext* C8086Parser::Expression_statementContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}


size_t C8086Parser::Expression_statementContext::getRuleIndex() const {
  return C8086Parser::RuleExpression_statement;
}

void C8086Parser::Expression_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement(this);
}

void C8086Parser::Expression_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement(this);
}

C8086Parser::Expression_statementContext* C8086Parser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 28, C8086Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(301);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(295);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->sc = match(C8086Parser::SEMICOLON);

                antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->sc->getText();
                writeIntoparserLogFile(
                    "Line " + std::to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->sc->getLine()) + ": expression_statement : SEMICOLON\n\n" +
                    _localctx->text + "\n"
                );
            
        break;
      }

      case C8086Parser::LPAREN:
      case C8086Parser::ADDOP:
      case C8086Parser::NOT:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(297);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->e = expression();
        setState(298);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->sc = match(C8086Parser::SEMICOLON);

        	    antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  "";
            
            std::string semicolonText = antlrcpp::downCast<Expression_statementContext *>(_localctx)->sc->getText();
            bool semicolonMissing = (semicolonText.find("missing") != std::string::npos);

            if (semicolonMissing==false) {
        	    antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->e->text;
                _localctx->text += semicolonText;

                writeIntoparserLogFile(
                    "Line " + std::to_string((antlrcpp::downCast<Expression_statementContext *>(_localctx)->e != nullptr ? (antlrcpp::downCast<Expression_statementContext *>(_localctx)->e->stop) : nullptr)->getLine()) + ": expression_statement : expression SEMICOLON\n\n" +
                    _localctx->text + "\n"
                );
            }

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

C8086Parser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::VariableContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::VariableContext::LTHIRD() {
  return getToken(C8086Parser::LTHIRD, 0);
}

C8086Parser::ExpressionContext* C8086Parser::VariableContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}

tree::TerminalNode* C8086Parser::VariableContext::RTHIRD() {
  return getToken(C8086Parser::RTHIRD, 0);
}


size_t C8086Parser::VariableContext::getRuleIndex() const {
  return C8086Parser::RuleVariable;
}

void C8086Parser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void C8086Parser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

C8086Parser::VariableContext* C8086Parser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 30, C8086Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(311);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(303);
      antlrcpp::downCast<VariableContext *>(_localctx)->id = match(C8086Parser::ID);

              antlrcpp::downCast<VariableContext *>(_localctx)->text =  antlrcpp::downCast<VariableContext *>(_localctx)->id->getText();
              string errorText = "";

              SymbolInfo* sym = symTable->lookup(antlrcpp::downCast<VariableContext *>(_localctx)->id->getText());
              
              if(sym!=nullptr){
      	            antlrcpp::downCast<VariableContext *>(_localctx)->type =  sym->getVariableType();
                  antlrcpp::downCast<VariableContext *>(_localctx)->isArray =  false;
                  antlrcpp::downCast<VariableContext *>(_localctx)->reallyArray =  sym->getArray();
                  antlrcpp::downCast<VariableContext *>(_localctx)->declared =  true;

      	        if(_localctx->reallyArray==true && _localctx->isArray==false) {
      		        writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": Type mismatch, " + _localctx->text + " is an array\n");
                      errorText = "Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": Type mismatch, " + _localctx->text + " is an array\n\n";
              syntaxErrorCount++;
          }
              }
              
              else{
      	            antlrcpp::downCast<VariableContext *>(_localctx)->type =  "void";
                      antlrcpp::downCast<VariableContext *>(_localctx)->isArray =  false;
                      antlrcpp::downCast<VariableContext *>(_localctx)->reallyArray =  false;
      	            antlrcpp::downCast<VariableContext *>(_localctx)->declared =  false;

      	                writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": Undeclared variable " + antlrcpp::downCast<VariableContext *>(_localctx)->id->getText()+"\n");
                  errorText = "Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": Undeclared variable " + antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() + "\n\n";
      	
                  syntaxErrorCount++;
              }
              
              writeIntoparserLogFile(
                  "Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": variable : ID\n\n" + errorText +
                  _localctx->text + "\n"
              );
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(305);
      antlrcpp::downCast<VariableContext *>(_localctx)->id = match(C8086Parser::ID);
      setState(306);
      antlrcpp::downCast<VariableContext *>(_localctx)->lt = match(C8086Parser::LTHIRD);
      setState(307);
      antlrcpp::downCast<VariableContext *>(_localctx)->e = expression();
      setState(308);
      antlrcpp::downCast<VariableContext *>(_localctx)->rt = match(C8086Parser::RTHIRD);

              antlrcpp::downCast<VariableContext *>(_localctx)->text =  antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() + antlrcpp::downCast<VariableContext *>(_localctx)->lt->getText() + antlrcpp::downCast<VariableContext *>(_localctx)->e->text + antlrcpp::downCast<VariableContext *>(_localctx)->rt->getText();
              

              SymbolInfo* sym = symTable->lookup(antlrcpp::downCast<VariableContext *>(_localctx)->id->getText());
              string errorText = "";
              
      	        if(sym!=nullptr){
      	            antlrcpp::downCast<VariableContext *>(_localctx)->type =  sym->getVariableType();
                  antlrcpp::downCast<VariableContext *>(_localctx)->isArray =  true;
                  antlrcpp::downCast<VariableContext *>(_localctx)->reallyArray =  sym->getArray();
      	            antlrcpp::downCast<VariableContext *>(_localctx)->declared =  true;

                      if(_localctx->isArray==true && _localctx->reallyArray==false) {
      			                    writeIntoErrorFile("Error at line "+std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) +": "+ antlrcpp::downCast<VariableContext *>(_localctx)->id->getText()+ " not an array\n");
      	            errorText = "Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine())+": " + antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() + " not an array\n\n";
                  syntaxErrorCount++;
                      }
              }
              
              else{
      	            antlrcpp::downCast<VariableContext *>(_localctx)->type =  "void";
                      antlrcpp::downCast<VariableContext *>(_localctx)->isArray =  false;
                      antlrcpp::downCast<VariableContext *>(_localctx)->reallyArray =  false;
      	                antlrcpp::downCast<VariableContext *>(_localctx)->declared =  false;

      	                    writeIntoErrorFile("Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": Undeclared array '" + antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() + "'");
                  errorText = "Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": Undeclared array '" + antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() + "'\n\n";
                  syntaxErrorCount++;
              }
              if (antlrcpp::downCast<VariableContext *>(_localctx)->e->type != "int") {
      		            writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": Expression inside third brackets not an integer\n");
                  errorText = "Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": Expression inside third brackets not an integer\n\n";
                  syntaxErrorCount++;
              }

      	       

              writeIntoparserLogFile(
                  "Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n\n" + errorText +
                  _localctx->text + "\n"
              );
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

C8086Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Logic_expressionContext* C8086Parser::ExpressionContext::logic_expression() {
  return getRuleContext<C8086Parser::Logic_expressionContext>(0);
}

C8086Parser::VariableContext* C8086Parser::ExpressionContext::variable() {
  return getRuleContext<C8086Parser::VariableContext>(0);
}

tree::TerminalNode* C8086Parser::ExpressionContext::ASSIGNOP() {
  return getToken(C8086Parser::ASSIGNOP, 0);
}


size_t C8086Parser::ExpressionContext::getRuleIndex() const {
  return C8086Parser::RuleExpression;
}

void C8086Parser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void C8086Parser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

C8086Parser::ExpressionContext* C8086Parser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 32, C8086Parser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(321);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(313);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->le = logic_expression();

              antlrcpp::downCast<ExpressionContext *>(_localctx)->text =  antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text;
              antlrcpp::downCast<ExpressionContext *>(_localctx)->type =  antlrcpp::downCast<ExpressionContext *>(_localctx)->le->type;
              antlrcpp::downCast<ExpressionContext *>(_localctx)->isArray =  antlrcpp::downCast<ExpressionContext *>(_localctx)->le->isArray;
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->le != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->le->stop) : nullptr)->getLine()) + ": expression : logic_expression\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(316);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->v = variable();
      setState(317);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->ao = match(C8086Parser::ASSIGNOP);
      setState(318);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->le = logic_expression();

              antlrcpp::downCast<ExpressionContext *>(_localctx)->text =  antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text  + antlrcpp::downCast<ExpressionContext *>(_localctx)->ao->getText()  + antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text;
      	        
      	    string lhsType = antlrcpp::downCast<ExpressionContext *>(_localctx)->v->type;
              antlrcpp::downCast<ExpressionContext *>(_localctx)->isArray =  antlrcpp::downCast<ExpressionContext *>(_localctx)->v->reallyArray;

              
              
              

          string rhsType = antlrcpp::downCast<ExpressionContext *>(_localctx)->le->type;

          string errortext="" ;

          if(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->declared == false){}

          else if (rhsType == "void") {
      	        writeIntoErrorFile("Error at line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->v->start) : nullptr)->getLine()) + ": Void function used in expression\n");
      	        errortext = "Error at line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->v->start) : nullptr)->getLine()) + ": Void function used in expression\n\n";
              syntaxErrorCount++;
          } else if (!(lhsType=="float" && rhsType=="int") && lhsType != rhsType && rhsType != "undefined") {
              writeIntoErrorFile("Error at line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->v->start) : nullptr)->getLine()) + ": Type Mismatch\n" );
              errortext = "Error at line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->v->start) : nullptr)->getLine()) + ": Type Mismatch\n\n";
              syntaxErrorCount++;
          }
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->v->stop) : nullptr)->getLine()) + ": expression : variable ASSIGNOP logic_expression\n\n" + errortext +
                  _localctx->text + "\n"
              );
      		        antlrcpp::downCast<ExpressionContext *>(_localctx)->type =  rhsType;
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_expressionContext ------------------------------------------------------------------

C8086Parser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C8086Parser::Rel_expressionContext *> C8086Parser::Logic_expressionContext::rel_expression() {
  return getRuleContexts<C8086Parser::Rel_expressionContext>();
}

C8086Parser::Rel_expressionContext* C8086Parser::Logic_expressionContext::rel_expression(size_t i) {
  return getRuleContext<C8086Parser::Rel_expressionContext>(i);
}

tree::TerminalNode* C8086Parser::Logic_expressionContext::LOGICOP() {
  return getToken(C8086Parser::LOGICOP, 0);
}


size_t C8086Parser::Logic_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleLogic_expression;
}

void C8086Parser::Logic_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_expression(this);
}

void C8086Parser::Logic_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_expression(this);
}

C8086Parser::Logic_expressionContext* C8086Parser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 34, C8086Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(331);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(323);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re = rel_expression();

              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->text;
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->type;
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->isArray =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->isArray; 
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re != nullptr ? (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->stop) : nullptr)->getLine()) + ": logic_expression : rel_expression\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(326);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1 = rel_expression();
      setState(327);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->lo = match(C8086Parser::LOGICOP);
      setState(328);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2 = rel_expression();

              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1->text + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->lo->getText() + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re2->text;
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->type =  "int";
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->isArray =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1->isArray; 
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1 != nullptr ? (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re1->stop) : nullptr)->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_expressionContext ------------------------------------------------------------------

C8086Parser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C8086Parser::Simple_expressionContext *> C8086Parser::Rel_expressionContext::simple_expression() {
  return getRuleContexts<C8086Parser::Simple_expressionContext>();
}

C8086Parser::Simple_expressionContext* C8086Parser::Rel_expressionContext::simple_expression(size_t i) {
  return getRuleContext<C8086Parser::Simple_expressionContext>(i);
}

tree::TerminalNode* C8086Parser::Rel_expressionContext::RELOP() {
  return getToken(C8086Parser::RELOP, 0);
}


size_t C8086Parser::Rel_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleRel_expression;
}

void C8086Parser::Rel_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_expression(this);
}

void C8086Parser::Rel_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_expression(this);
}

C8086Parser::Rel_expressionContext* C8086Parser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 36, C8086Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(341);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(333);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se = simple_expression(0);

              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->text;
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->type;
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->isArray =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->isArray; 
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se != nullptr ? (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->stop) : nullptr)->getLine()) + ": rel_expression : simple_expression\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(336);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se1 = simple_expression(0);
      setState(337);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->ro = match(C8086Parser::RELOP);
      setState(338);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se2 = simple_expression(0);

              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se1->text + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->ro->getText() + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se2->text;
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->type =  "int"; 
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->isArray =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se1->isArray;
              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se1 != nullptr ? (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se1->stop) : nullptr)->getLine()) + ": rel_expression : simple_expression RELOP simple_expression\n\n" +
                  _localctx->text + "\n"
              );
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

C8086Parser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::TermContext* C8086Parser::Simple_expressionContext::term() {
  return getRuleContext<C8086Parser::TermContext>(0);
}

std::vector<C8086Parser::Simple_expressionContext *> C8086Parser::Simple_expressionContext::simple_expression() {
  return getRuleContexts<C8086Parser::Simple_expressionContext>();
}

C8086Parser::Simple_expressionContext* C8086Parser::Simple_expressionContext::simple_expression(size_t i) {
  return getRuleContext<C8086Parser::Simple_expressionContext>(i);
}

tree::TerminalNode* C8086Parser::Simple_expressionContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}

tree::TerminalNode* C8086Parser::Simple_expressionContext::ASSIGNOP() {
  return getToken(C8086Parser::ASSIGNOP, 0);
}


size_t C8086Parser::Simple_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleSimple_expression;
}

void C8086Parser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void C8086Parser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
}


C8086Parser::Simple_expressionContext* C8086Parser::simple_expression() {
   return simple_expression(0);
}

C8086Parser::Simple_expressionContext* C8086Parser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  C8086Parser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, C8086Parser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(344);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text;
            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->type; 
            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->isArray =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->isArray;
            writeIntoparserLogFile(
                "Line " + std::to_string((antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->stop) : nullptr)->getLine()) + ": simple_expression : term\n\n" +
                _localctx->text + "\n"
            );
        
    _ctx->stop = _input->LT(-1);
    setState(360);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(358);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
          _localctx->se = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
          setState(347);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(348);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->ao = match(C8086Parser::ADDOP);
          setState(349);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->invalid_op = match(C8086Parser::ASSIGNOP);
          setState(350);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se2 = simple_expression(2);

                        
                        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->text;
                        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->type;
                        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->isArray =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->isArray;
                        
                        // writeIntoparserLogFile(
                        //     "Line " + std::to_string((antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se != nullptr ? (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->stop) : nullptr)->getLine()) + ": simple_expression : term\n\n" +
                        //     antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->text + "\n"
                        // );
                        
                        writeIntoparserLogFile(
                            "Error at line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->invalid_op->getLine()) + ": syntax error, unexpected ASSIGNOP\n\n"
                        );
                        writeIntoErrorFile(
                            "Error at line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->invalid_op->getLine()) + ": syntax error, unexpected ASSIGNOP\n"
                        );
                        syntaxErrorCount++;
                    
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
          _localctx->se = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
          setState(353);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(354);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->ao = match(C8086Parser::ADDOP);
          setState(355);
          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->text  + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->ao->getText()  + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text;
                            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->isArray =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->isArray;
                            
                            if (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->type == "float" || antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->type == "float")
                                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  "float";
                            else
                                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->type =  "int";
                            writeIntoparserLogFile(
                                "Line " + std::to_string((antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se != nullptr ? (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->stop) : nullptr)->getLine()) + ": simple_expression : simple_expression ADDOP term\n\n" +
                                _localctx->text + "\n"
                            );
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(362);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

C8086Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Unary_expressionContext* C8086Parser::TermContext::unary_expression() {
  return getRuleContext<C8086Parser::Unary_expressionContext>(0);
}

C8086Parser::TermContext* C8086Parser::TermContext::term() {
  return getRuleContext<C8086Parser::TermContext>(0);
}

tree::TerminalNode* C8086Parser::TermContext::MULOP() {
  return getToken(C8086Parser::MULOP, 0);
}


size_t C8086Parser::TermContext::getRuleIndex() const {
  return C8086Parser::RuleTerm;
}

void C8086Parser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void C8086Parser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


C8086Parser::TermContext* C8086Parser::term() {
   return term(0);
}

C8086Parser::TermContext* C8086Parser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  C8086Parser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, C8086Parser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(364);
    antlrcpp::downCast<TermContext *>(_localctx)->ue = unary_expression();

            antlrcpp::downCast<TermContext *>(_localctx)->text =  antlrcpp::downCast<TermContext *>(_localctx)->ue->text;
            antlrcpp::downCast<TermContext *>(_localctx)->type =  antlrcpp::downCast<TermContext *>(_localctx)->ue->type;
            antlrcpp::downCast<TermContext *>(_localctx)->isArray =  antlrcpp::downCast<TermContext *>(_localctx)->ue->isArray;
            writeIntoparserLogFile(
                "Line " + std::to_string((antlrcpp::downCast<TermContext *>(_localctx)->ue != nullptr ? (antlrcpp::downCast<TermContext *>(_localctx)->ue->stop) : nullptr)->getLine()) + ": term : unary_expression\n\n" +
                _localctx->text + "\n"
            );
        
    _ctx->stop = _input->LT(-1);
    setState(374);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        _localctx->t = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(367);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(368);
        antlrcpp::downCast<TermContext *>(_localctx)->mo = match(C8086Parser::MULOP);
        setState(369);
        antlrcpp::downCast<TermContext *>(_localctx)->ue = unary_expression();

                          antlrcpp::downCast<TermContext *>(_localctx)->text =  antlrcpp::downCast<TermContext *>(_localctx)->t->text + antlrcpp::downCast<TermContext *>(_localctx)->mo->getText()  + antlrcpp::downCast<TermContext *>(_localctx)->ue->text;
                          antlrcpp::downCast<TermContext *>(_localctx)->isArray =  antlrcpp::downCast<TermContext *>(_localctx)->t->isArray;
                          string errorText = "";
                          if (antlrcpp::downCast<TermContext *>(_localctx)->mo->getText() == "%") {
                              if (antlrcpp::downCast<TermContext *>(_localctx)->t->type != "int" || antlrcpp::downCast<TermContext *>(_localctx)->ue->type != "int") {
                                  antlrcpp::downCast<TermContext *>(_localctx)->type =  "undefined";
                                  writeIntoErrorFile(
                  	                    "Error at line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->mo->getLine()) + ": Non-Integer operand on modulus operator\n"
                                          
                                  );
                                  errorText = "Error at line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->mo->getLine()) + ": Non-Integer operand on modulus operator\n\n";
                                  syntaxErrorCount++;
                              }

                  	            else if(antlrcpp::downCast<TermContext *>(_localctx)->ue->text == "0"){ 
                                      antlrcpp::downCast<TermContext *>(_localctx)->type =  "undefined";
                                  writeIntoErrorFile(
                  	                        "Error at line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->mo->getLine()) + ": Modulus by Zero\n"
                                  );
                                  errorText = "Error at line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->mo->getLine()) + ": Modulus by Zero\n\n";
                                  syntaxErrorCount++;
                                  }

                  	       
                              else
                              antlrcpp::downCast<TermContext *>(_localctx)->type =  "int";
                          } else if (antlrcpp::downCast<TermContext *>(_localctx)->t->type == "float" || antlrcpp::downCast<TermContext *>(_localctx)->ue->type == "float") {
                              antlrcpp::downCast<TermContext *>(_localctx)->type =  "float";
                          } 
                  	    else if (antlrcpp::downCast<TermContext *>(_localctx)->t->type == "void" || antlrcpp::downCast<TermContext *>(_localctx)->ue->type == "void") {
                  	            writeIntoErrorFile("Error at line " + std::to_string((antlrcpp::downCast<TermContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<TermContext *>(_localctx)->t->stop) : nullptr)->getLine()) + ": Void function used in expression\n");
                                  syntaxErrorCount++;
                                  antlrcpp::downCast<TermContext *>(_localctx)->type =  "undefined";
                                  errorText = "Error at line " + std::to_string((antlrcpp::downCast<TermContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<TermContext *>(_localctx)->t->stop) : nullptr)->getLine()) + ": Void function used in expression\n\n";
                              }
                          else {
                              antlrcpp::downCast<TermContext *>(_localctx)->type =  "int";
                          }

                          writeIntoparserLogFile(
                              "Line " + std::to_string((antlrcpp::downCast<TermContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<TermContext *>(_localctx)->t->stop) : nullptr)->getLine()) + ": term : term MULOP unary_expression\n\n" + errorText +
                              _localctx->text + "\n"
                          );
                       
      }
      setState(376);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

C8086Parser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Unary_expressionContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}

C8086Parser::Unary_expressionContext* C8086Parser::Unary_expressionContext::unary_expression() {
  return getRuleContext<C8086Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::Unary_expressionContext::NOT() {
  return getToken(C8086Parser::NOT, 0);
}

C8086Parser::FactorContext* C8086Parser::Unary_expressionContext::factor() {
  return getRuleContext<C8086Parser::FactorContext>(0);
}


size_t C8086Parser::Unary_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleUnary_expression;
}

void C8086Parser::Unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression(this);
}

void C8086Parser::Unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression(this);
}

C8086Parser::Unary_expressionContext* C8086Parser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 42, C8086Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(388);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(377);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ao = match(C8086Parser::ADDOP);
        setState(378);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue = unary_expression();

                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ao->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->text;
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->type;
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->isArray =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->isArray;
                writeIntoparserLogFile(
                    "Line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ao->getLine()) + ": unary_expression : ADDOP unary_expression\n\n" +
                    _localctx->text + "\n"
                );
            
        break;
      }

      case C8086Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(381);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->n = match(C8086Parser::NOT);
        setState(382);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue = unary_expression();

                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->n->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->text;
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  "int"; 
        	    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->isArray =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->isArray;
                writeIntoparserLogFile(
                    "Line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->n->getLine()) + ": unary_expression : NOT unary_expression\n\n" +
                    _localctx->text + "\n"
                );
            
        break;
      }

      case C8086Parser::LPAREN:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(385);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f = factor();

                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->text;
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->type =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->type;
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->isArray =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->isArray;
                writeIntoparserLogFile(
                    "Line " + std::to_string((antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f != nullptr ? (antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->stop) : nullptr)->getLine()) + ": unary_expression : factor\n\n" +
                    _localctx->text + "\n"
                );
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

C8086Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::VariableContext* C8086Parser::FactorContext::variable() {
  return getRuleContext<C8086Parser::VariableContext>(0);
}

tree::TerminalNode* C8086Parser::FactorContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

C8086Parser::Argument_listContext* C8086Parser::FactorContext::argument_list() {
  return getRuleContext<C8086Parser::Argument_listContext>(0);
}

tree::TerminalNode* C8086Parser::FactorContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

C8086Parser::ExpressionContext* C8086Parser::FactorContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}

tree::TerminalNode* C8086Parser::FactorContext::CONST_INT() {
  return getToken(C8086Parser::CONST_INT, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::CONST_FLOAT() {
  return getToken(C8086Parser::CONST_FLOAT, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::INCOP() {
  return getToken(C8086Parser::INCOP, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::DECOP() {
  return getToken(C8086Parser::DECOP, 0);
}


size_t C8086Parser::FactorContext::getRuleIndex() const {
  return C8086Parser::RuleFactor;
}

void C8086Parser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void C8086Parser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

C8086Parser::FactorContext* C8086Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 44, C8086Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(416);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(390);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text;
      	    
              
                  
      	            antlrcpp::downCast<FactorContext *>(_localctx)->isArray =  antlrcpp::downCast<FactorContext *>(_localctx)->v->reallyArray;
              
                  antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type;

              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<FactorContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<FactorContext *>(_localctx)->v->stop) : nullptr)->getLine()) + ": factor : variable\n\n" + _localctx->text + "\n"
              );
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(393);
      antlrcpp::downCast<FactorContext *>(_localctx)->id = match(C8086Parser::ID);
      setState(394);
      antlrcpp::downCast<FactorContext *>(_localctx)->lp = match(C8086Parser::LPAREN);
      setState(395);
      antlrcpp::downCast<FactorContext *>(_localctx)->al = argument_list();
      setState(396);
      antlrcpp::downCast<FactorContext *>(_localctx)->rp = match(C8086Parser::RPAREN);

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->lp->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->al->text + antlrcpp::downCast<FactorContext *>(_localctx)->rp->getText();
              string errorText = "";
              SymbolInfo* sym = symTable->lookup(antlrcpp::downCast<FactorContext *>(_localctx)->id->getText());

              

              if (sym == nullptr) {
                  antlrcpp::downCast<FactorContext *>(_localctx)->type =  "undefined";
                  writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": Undefined function " + antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + "\n");
                  syntaxErrorCount++;
                  errorText = "Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": Undefined function " + antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + "\n\n";
              } 
              else if (!sym->getFunction()) {
                  antlrcpp::downCast<FactorContext *>(_localctx)->type =  "undefined";
                  writeIntoErrorFile("Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": '" + antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + "' is not a function");
                  syntaxErrorCount++;
                  errorText = "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": '" + antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + "' is not a function\n\n";
              } else {
                  antlrcpp::downCast<FactorContext *>(_localctx)->type =  sym->getVariableType();  
                  antlrcpp::downCast<FactorContext *>(_localctx)->isArray =  false;
                
                  int expected = sym->getParamCount();
                  if (expected != antlrcpp::downCast<FactorContext *>(_localctx)->al->types.size()) {
      	                writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + "\n");
                      syntaxErrorCount++;
                      errorText = "Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + "\n\n";
                  } else {
                      
                      string* expectedTypes = sym->getParamTypes();
                      for (int i = 0; i < expected; ++i) {
      	                    cout<<antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() <<"Expected type: " << expectedTypes[i] << ", Actual type: " << antlrcpp::downCast<FactorContext *>(_localctx)->al->types[i] << endl;
      	                    if(antlrcpp::downCast<FactorContext *>(_localctx)->al->isArray[i]==true){
      			                //             writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": Type mismatch, " +antlrcpp::downCast<FactorContext *>(_localctx)->al->names[i] +" is an array\n");
                                  // errorText = "Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": Type mismatch, " +antlrcpp::downCast<FactorContext *>(_localctx)->al->names[i] +" is an array\n\n";
                                  // syntaxErrorCount++;
                          }
                          else if (expectedTypes[i] != antlrcpp::downCast<FactorContext *>(_localctx)->al->types[i] ) {
      	                        writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) +
                                                 ": " + std::to_string(i+1) + "th argument mismatch in function " +
                                                 antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + "\n");
                              syntaxErrorCount++;
                              errorText = "Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) +
                                          ": " + std::to_string(i+1) + "th argument mismatch in function " +
                                          antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + "\n\n";
                              break;
                          }
                      }
                  }

                  
              }

              writeIntoparserLogFile(
                  "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": factor : ID LPAREN argument_list RPAREN\n\n" +errorText +
                   _localctx->text + "\n"
              );
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(399);
      antlrcpp::downCast<FactorContext *>(_localctx)->lp = match(C8086Parser::LPAREN);
      setState(400);
      antlrcpp::downCast<FactorContext *>(_localctx)->e = expression();
      setState(401);
      antlrcpp::downCast<FactorContext *>(_localctx)->rp = match(C8086Parser::RPAREN);

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->lp->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->e->text + antlrcpp::downCast<FactorContext *>(_localctx)->rp->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->e->type;
              antlrcpp::downCast<FactorContext *>(_localctx)->isArray =  antlrcpp::downCast<FactorContext *>(_localctx)->e->isArray;

              writeIntoparserLogFile(
                  "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->lp->getLine()) + ": factor : LPAREN expression RPAREN\n\n" + _localctx->text + "\n"
              );
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(404);
      antlrcpp::downCast<FactorContext *>(_localctx)->ci = match(C8086Parser::CONST_INT);

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->ci->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  "int";
              antlrcpp::downCast<FactorContext *>(_localctx)->isArray =  false;
              writeIntoparserLogFile(
                  "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->ci->getLine()) + ": factor : CONST_INT\n\n" + _localctx->text + "\n"
              );
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(406);
      antlrcpp::downCast<FactorContext *>(_localctx)->cf = match(C8086Parser::CONST_FLOAT);

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->cf->getText();
              antlrcpp::downCast<FactorContext *>(_localctx)->type =  "float";
              antlrcpp::downCast<FactorContext *>(_localctx)->isArray =  false;
              writeIntoparserLogFile(
                  "Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->cf->getLine()) + ": factor : CONST_FLOAT\n\n" + _localctx->text + "\n"
              );
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(408);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(409);
      antlrcpp::downCast<FactorContext *>(_localctx)->ic = match(C8086Parser::INCOP);

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text + antlrcpp::downCast<FactorContext *>(_localctx)->ic->getText();
              
                  antlrcpp::downCast<FactorContext *>(_localctx)->isArray =  antlrcpp::downCast<FactorContext *>(_localctx)->v->reallyArray;
                  antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type;

              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<FactorContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<FactorContext *>(_localctx)->v->stop) : nullptr)->getLine()) + ": factor : variable INCOP\n\n" + _localctx->text + "\n"
              );
          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(412);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(413);
      antlrcpp::downCast<FactorContext *>(_localctx)->dc = match(C8086Parser::DECOP);

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text + antlrcpp::downCast<FactorContext *>(_localctx)->dc->getText();
             
                  antlrcpp::downCast<FactorContext *>(_localctx)->type =  antlrcpp::downCast<FactorContext *>(_localctx)->v->type;
                  antlrcpp::downCast<FactorContext *>(_localctx)->isArray =  antlrcpp::downCast<FactorContext *>(_localctx)->v->reallyArray;
             

             

              writeIntoparserLogFile(
                  "Line " + std::to_string((antlrcpp::downCast<FactorContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<FactorContext *>(_localctx)->v->stop) : nullptr)->getLine()) + ": factor : variable DECOP\n\n" + _localctx->text + "\n"
              );
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

C8086Parser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::ArgumentsContext* C8086Parser::Argument_listContext::arguments() {
  return getRuleContext<C8086Parser::ArgumentsContext>(0);
}


size_t C8086Parser::Argument_listContext::getRuleIndex() const {
  return C8086Parser::RuleArgument_list;
}

void C8086Parser::Argument_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument_list(this);
}

void C8086Parser::Argument_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument_list(this);
}

C8086Parser::Argument_listContext* C8086Parser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 46, C8086Parser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(422);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::LPAREN:
      case C8086Parser::ADDOP:
      case C8086Parser::NOT:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(418);
        antlrcpp::downCast<Argument_listContext *>(_localctx)->a = arguments(0);

                antlrcpp::downCast<Argument_listContext *>(_localctx)->text =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->text;
                antlrcpp::downCast<Argument_listContext *>(_localctx)->types =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->types;
                antlrcpp::downCast<Argument_listContext *>(_localctx)->isArray =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->isArray;
                antlrcpp::downCast<Argument_listContext *>(_localctx)->names =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->names;
                writeIntoparserLogFile(
                    "Line " + std::to_string((antlrcpp::downCast<Argument_listContext *>(_localctx)->a != nullptr ? (antlrcpp::downCast<Argument_listContext *>(_localctx)->a->stop) : nullptr)->getLine()) + ": argument_list : arguments\n\n" +
                    _localctx->text + "\n"
                );
            
        break;
      }

      case C8086Parser::RPAREN: {
        enterOuterAlt(_localctx, 2);

                antlrcpp::downCast<Argument_listContext *>(_localctx)->text =  "";
                antlrcpp::downCast<Argument_listContext *>(_localctx)->types =  {};
                antlrcpp::downCast<Argument_listContext *>(_localctx)->isArray =  {};
                antlrcpp::downCast<Argument_listContext *>(_localctx)->names =  {};
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

C8086Parser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Logic_expressionContext* C8086Parser::ArgumentsContext::logic_expression() {
  return getRuleContext<C8086Parser::Logic_expressionContext>(0);
}

C8086Parser::ArgumentsContext* C8086Parser::ArgumentsContext::arguments() {
  return getRuleContext<C8086Parser::ArgumentsContext>(0);
}

tree::TerminalNode* C8086Parser::ArgumentsContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}


size_t C8086Parser::ArgumentsContext::getRuleIndex() const {
  return C8086Parser::RuleArguments;
}

void C8086Parser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void C8086Parser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


C8086Parser::ArgumentsContext* C8086Parser::arguments() {
   return arguments(0);
}

C8086Parser::ArgumentsContext* C8086Parser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  C8086Parser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, C8086Parser::RuleArguments, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(425);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->le = logic_expression();

            antlrcpp::downCast<ArgumentsContext *>(_localctx)->text =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text;
    	    _localctx->types.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->type);
            _localctx->isArray.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->isArray);
            _localctx->names.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text);  
            writeIntoparserLogFile(
                "Line " + std::to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->le != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->stop) : nullptr)->getLine()) + ": arguments : logic_expression\n\n" +
                _localctx->text + "\n"
            );
        
    _ctx->stop = _input->LT(-1);
    setState(435);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentsContext>(parentContext, parentState);
        _localctx->a = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleArguments);
        setState(428);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(429);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->cm = match(C8086Parser::COMMA);
        setState(430);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->le = logic_expression();

                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->text =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->text + antlrcpp::downCast<ArgumentsContext *>(_localctx)->cm->getText()  + antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text;
                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->types =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->types;
                          _localctx->types.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->type);
                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->isArray =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->isArray;
                          _localctx->isArray.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->isArray);
                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->names =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->names;
                          _localctx->names.push_back(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text);   
                          writeIntoparserLogFile(
                              "Line " + std::to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->a != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->stop) : nullptr)->getLine()) + ": arguments : arguments COMMA logic_expression\n\n" +
                              _localctx->text + "\n"
                          );
                       
      }
      setState(437);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool C8086Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 5: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 11: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 12: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 19: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 20: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 24: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool C8086Parser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C8086Parser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

bool C8086Parser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 2);
    case 4: return precpred(_ctx, 6);
    case 5: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool C8086Parser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);
    case 8: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C8086Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void C8086Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c8086parserParserInitialize();
#else
  ::antlr4::internal::call_once(c8086parserParserOnceFlag, c8086parserParserInitialize);
#endif
}
