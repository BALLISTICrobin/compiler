// Generated from /Users/niloydas/Desktop/compiler/syntax_semantics_analysis/antlr4-resources/antlr4-skeletons/cpp/C8086Parser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link C8086Parser}.
 */
public interface C8086ParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link C8086Parser#start}.
	 * @param ctx the parse tree
	 */
	void enterStart(C8086Parser.StartContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#start}.
	 * @param ctx the parse tree
	 */
	void exitStart(C8086Parser.StartContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(C8086Parser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(C8086Parser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#unit}.
	 * @param ctx the parse tree
	 */
	void enterUnit(C8086Parser.UnitContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#unit}.
	 * @param ctx the parse tree
	 */
	void exitUnit(C8086Parser.UnitContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#func_declaration}.
	 * @param ctx the parse tree
	 */
	void enterFunc_declaration(C8086Parser.Func_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#func_declaration}.
	 * @param ctx the parse tree
	 */
	void exitFunc_declaration(C8086Parser.Func_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#func_definition}.
	 * @param ctx the parse tree
	 */
	void enterFunc_definition(C8086Parser.Func_definitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#func_definition}.
	 * @param ctx the parse tree
	 */
	void exitFunc_definition(C8086Parser.Func_definitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void enterParameter_list(C8086Parser.Parameter_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void exitParameter_list(C8086Parser.Parameter_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#compound_statement}.
	 * @param ctx the parse tree
	 */
	void enterCompound_statement(C8086Parser.Compound_statementContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#compound_statement}.
	 * @param ctx the parse tree
	 */
	void exitCompound_statement(C8086Parser.Compound_statementContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#var_declaration}.
	 * @param ctx the parse tree
	 */
	void enterVar_declaration(C8086Parser.Var_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#var_declaration}.
	 * @param ctx the parse tree
	 */
	void exitVar_declaration(C8086Parser.Var_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#declaration_list_err}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration_list_err(C8086Parser.Declaration_list_errContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#declaration_list_err}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration_list_err(C8086Parser.Declaration_list_errContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void enterType_specifier(C8086Parser.Type_specifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void exitType_specifier(C8086Parser.Type_specifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration_list(C8086Parser.Declaration_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration_list(C8086Parser.Declaration_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#statements}.
	 * @param ctx the parse tree
	 */
	void enterStatements(C8086Parser.StatementsContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#statements}.
	 * @param ctx the parse tree
	 */
	void exitStatements(C8086Parser.StatementsContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(C8086Parser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(C8086Parser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void enterExpression_statement(C8086Parser.Expression_statementContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void exitExpression_statement(C8086Parser.Expression_statementContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(C8086Parser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(C8086Parser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(C8086Parser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(C8086Parser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#logic_expression}.
	 * @param ctx the parse tree
	 */
	void enterLogic_expression(C8086Parser.Logic_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#logic_expression}.
	 * @param ctx the parse tree
	 */
	void exitLogic_expression(C8086Parser.Logic_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#rel_expression}.
	 * @param ctx the parse tree
	 */
	void enterRel_expression(C8086Parser.Rel_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#rel_expression}.
	 * @param ctx the parse tree
	 */
	void exitRel_expression(C8086Parser.Rel_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void enterSimple_expression(C8086Parser.Simple_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void exitSimple_expression(C8086Parser.Simple_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#term}.
	 * @param ctx the parse tree
	 */
	void enterTerm(C8086Parser.TermContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#term}.
	 * @param ctx the parse tree
	 */
	void exitTerm(C8086Parser.TermContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void enterUnary_expression(C8086Parser.Unary_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void exitUnary_expression(C8086Parser.Unary_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactor(C8086Parser.FactorContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactor(C8086Parser.FactorContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#argument_list}.
	 * @param ctx the parse tree
	 */
	void enterArgument_list(C8086Parser.Argument_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#argument_list}.
	 * @param ctx the parse tree
	 */
	void exitArgument_list(C8086Parser.Argument_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link C8086Parser#arguments}.
	 * @param ctx the parse tree
	 */
	void enterArguments(C8086Parser.ArgumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link C8086Parser#arguments}.
	 * @param ctx the parse tree
	 */
	void exitArguments(C8086Parser.ArgumentsContext ctx);
}