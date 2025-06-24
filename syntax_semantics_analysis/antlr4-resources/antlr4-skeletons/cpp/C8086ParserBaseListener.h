
// Generated from C8086Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "C8086ParserListener.h"


/**
 * This class provides an empty implementation of C8086ParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  C8086ParserBaseListener : public C8086ParserListener {
public:

  virtual void enterStart(C8086Parser::StartContext * /*ctx*/) override { }
  virtual void exitStart(C8086Parser::StartContext * /*ctx*/) override { }

  virtual void enterProgram(C8086Parser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(C8086Parser::ProgramContext * /*ctx*/) override { }

  virtual void enterUnit(C8086Parser::UnitContext * /*ctx*/) override { }
  virtual void exitUnit(C8086Parser::UnitContext * /*ctx*/) override { }

  virtual void enterFunc_declaration(C8086Parser::Func_declarationContext * /*ctx*/) override { }
  virtual void exitFunc_declaration(C8086Parser::Func_declarationContext * /*ctx*/) override { }

  virtual void enterFunc_definition(C8086Parser::Func_definitionContext * /*ctx*/) override { }
  virtual void exitFunc_definition(C8086Parser::Func_definitionContext * /*ctx*/) override { }

  virtual void enterParameter_list(C8086Parser::Parameter_listContext * /*ctx*/) override { }
  virtual void exitParameter_list(C8086Parser::Parameter_listContext * /*ctx*/) override { }

  virtual void enterInvalid_param(C8086Parser::Invalid_paramContext * /*ctx*/) override { }
  virtual void exitInvalid_param(C8086Parser::Invalid_paramContext * /*ctx*/) override { }

  virtual void enterCompound_statement(C8086Parser::Compound_statementContext * /*ctx*/) override { }
  virtual void exitCompound_statement(C8086Parser::Compound_statementContext * /*ctx*/) override { }

  virtual void enterVar_declaration(C8086Parser::Var_declarationContext * /*ctx*/) override { }
  virtual void exitVar_declaration(C8086Parser::Var_declarationContext * /*ctx*/) override { }

  virtual void enterDeclaration_list_err(C8086Parser::Declaration_list_errContext * /*ctx*/) override { }
  virtual void exitDeclaration_list_err(C8086Parser::Declaration_list_errContext * /*ctx*/) override { }

  virtual void enterType_specifier(C8086Parser::Type_specifierContext * /*ctx*/) override { }
  virtual void exitType_specifier(C8086Parser::Type_specifierContext * /*ctx*/) override { }

  virtual void enterDeclaration_list(C8086Parser::Declaration_listContext * /*ctx*/) override { }
  virtual void exitDeclaration_list(C8086Parser::Declaration_listContext * /*ctx*/) override { }

  virtual void enterStatements(C8086Parser::StatementsContext * /*ctx*/) override { }
  virtual void exitStatements(C8086Parser::StatementsContext * /*ctx*/) override { }

  virtual void enterStatement(C8086Parser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(C8086Parser::StatementContext * /*ctx*/) override { }

  virtual void enterExpression_statement(C8086Parser::Expression_statementContext * /*ctx*/) override { }
  virtual void exitExpression_statement(C8086Parser::Expression_statementContext * /*ctx*/) override { }

  virtual void enterVariable(C8086Parser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(C8086Parser::VariableContext * /*ctx*/) override { }

  virtual void enterExpression(C8086Parser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(C8086Parser::ExpressionContext * /*ctx*/) override { }

  virtual void enterLogic_expression(C8086Parser::Logic_expressionContext * /*ctx*/) override { }
  virtual void exitLogic_expression(C8086Parser::Logic_expressionContext * /*ctx*/) override { }

  virtual void enterRel_expression(C8086Parser::Rel_expressionContext * /*ctx*/) override { }
  virtual void exitRel_expression(C8086Parser::Rel_expressionContext * /*ctx*/) override { }

  virtual void enterSimple_expression(C8086Parser::Simple_expressionContext * /*ctx*/) override { }
  virtual void exitSimple_expression(C8086Parser::Simple_expressionContext * /*ctx*/) override { }

  virtual void enterTerm(C8086Parser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(C8086Parser::TermContext * /*ctx*/) override { }

  virtual void enterUnary_expression(C8086Parser::Unary_expressionContext * /*ctx*/) override { }
  virtual void exitUnary_expression(C8086Parser::Unary_expressionContext * /*ctx*/) override { }

  virtual void enterFactor(C8086Parser::FactorContext * /*ctx*/) override { }
  virtual void exitFactor(C8086Parser::FactorContext * /*ctx*/) override { }

  virtual void enterArgument_list(C8086Parser::Argument_listContext * /*ctx*/) override { }
  virtual void exitArgument_list(C8086Parser::Argument_listContext * /*ctx*/) override { }

  virtual void enterArguments(C8086Parser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(C8086Parser::ArgumentsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

