
// Generated from C8086Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "C8086Parser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by C8086Parser.
 */
class  C8086ParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(C8086Parser::StartContext *ctx) = 0;
  virtual void exitStart(C8086Parser::StartContext *ctx) = 0;

  virtual void enterProgram(C8086Parser::ProgramContext *ctx) = 0;
  virtual void exitProgram(C8086Parser::ProgramContext *ctx) = 0;

  virtual void enterUnit(C8086Parser::UnitContext *ctx) = 0;
  virtual void exitUnit(C8086Parser::UnitContext *ctx) = 0;

  virtual void enterFunc_declaration(C8086Parser::Func_declarationContext *ctx) = 0;
  virtual void exitFunc_declaration(C8086Parser::Func_declarationContext *ctx) = 0;

  virtual void enterFunc_definition(C8086Parser::Func_definitionContext *ctx) = 0;
  virtual void exitFunc_definition(C8086Parser::Func_definitionContext *ctx) = 0;

  virtual void enterParameter_list(C8086Parser::Parameter_listContext *ctx) = 0;
  virtual void exitParameter_list(C8086Parser::Parameter_listContext *ctx) = 0;

  virtual void enterInvalid_param(C8086Parser::Invalid_paramContext *ctx) = 0;
  virtual void exitInvalid_param(C8086Parser::Invalid_paramContext *ctx) = 0;

  virtual void enterCompound_statement(C8086Parser::Compound_statementContext *ctx) = 0;
  virtual void exitCompound_statement(C8086Parser::Compound_statementContext *ctx) = 0;

  virtual void enterVar_declaration(C8086Parser::Var_declarationContext *ctx) = 0;
  virtual void exitVar_declaration(C8086Parser::Var_declarationContext *ctx) = 0;

  virtual void enterDeclaration_list_err(C8086Parser::Declaration_list_errContext *ctx) = 0;
  virtual void exitDeclaration_list_err(C8086Parser::Declaration_list_errContext *ctx) = 0;

  virtual void enterType_specifier(C8086Parser::Type_specifierContext *ctx) = 0;
  virtual void exitType_specifier(C8086Parser::Type_specifierContext *ctx) = 0;

  virtual void enterDeclaration_list(C8086Parser::Declaration_listContext *ctx) = 0;
  virtual void exitDeclaration_list(C8086Parser::Declaration_listContext *ctx) = 0;

  virtual void enterStatements(C8086Parser::StatementsContext *ctx) = 0;
  virtual void exitStatements(C8086Parser::StatementsContext *ctx) = 0;

  virtual void enterStatement(C8086Parser::StatementContext *ctx) = 0;
  virtual void exitStatement(C8086Parser::StatementContext *ctx) = 0;

  virtual void enterExpression_statement(C8086Parser::Expression_statementContext *ctx) = 0;
  virtual void exitExpression_statement(C8086Parser::Expression_statementContext *ctx) = 0;

  virtual void enterVariable(C8086Parser::VariableContext *ctx) = 0;
  virtual void exitVariable(C8086Parser::VariableContext *ctx) = 0;

  virtual void enterExpression(C8086Parser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(C8086Parser::ExpressionContext *ctx) = 0;

  virtual void enterLogic_expression(C8086Parser::Logic_expressionContext *ctx) = 0;
  virtual void exitLogic_expression(C8086Parser::Logic_expressionContext *ctx) = 0;

  virtual void enterRel_expression(C8086Parser::Rel_expressionContext *ctx) = 0;
  virtual void exitRel_expression(C8086Parser::Rel_expressionContext *ctx) = 0;

  virtual void enterSimple_expression(C8086Parser::Simple_expressionContext *ctx) = 0;
  virtual void exitSimple_expression(C8086Parser::Simple_expressionContext *ctx) = 0;

  virtual void enterTerm(C8086Parser::TermContext *ctx) = 0;
  virtual void exitTerm(C8086Parser::TermContext *ctx) = 0;

  virtual void enterUnary_expression(C8086Parser::Unary_expressionContext *ctx) = 0;
  virtual void exitUnary_expression(C8086Parser::Unary_expressionContext *ctx) = 0;

  virtual void enterFactor(C8086Parser::FactorContext *ctx) = 0;
  virtual void exitFactor(C8086Parser::FactorContext *ctx) = 0;

  virtual void enterArgument_list(C8086Parser::Argument_listContext *ctx) = 0;
  virtual void exitArgument_list(C8086Parser::Argument_listContext *ctx) = 0;

  virtual void enterArguments(C8086Parser::ArgumentsContext *ctx) = 0;
  virtual void exitArguments(C8086Parser::ArgumentsContext *ctx) = 0;


};

