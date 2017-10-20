#include "AstNode.hpp"

void Source::toStringF(std::string *str, FormatState *f) {
	for (AstNode *node : *nodes) {
		node->toStringF(str, f);
		str->append("\n\n");
	}
}
void Attribute::toStringF(std::string *str, FormatState *f) {
	str->append(AstNode::fmt("attribute %s %s;", AstNode::typeToStr(type), name));
}
void Out::toStringF(std::string *str, FormatState *f) {
	str->append(AstNode::fmt("out %s %s;", AstNode::typeToStr(type), name));
}
void In::toStringF(std::string *str, FormatState *f) {
	str->append(AstNode::fmt("in %s %s;", AstNode::typeToStr(type), name));
}
void Uniform::toStringF(std::string *str, FormatState *f) {
	str->append(AstNode::fmt("uniform %s %s;", AstNode::typeToStr(type), name));
}
void Block::toStringF(std::string *str, FormatState *f) {
	str->append("{\n");
	++f->indent_count;
	for (Statement *stm : *statements) {
		f->indent(str);
		stm->toStringF(str, f);
		if (stm->isControlStruct) str->append("\n");
		else str->append(";\n");
	}
	--f->indent_count;
	f->indent(str);
	str->append("}");
}
void ArgDecl::toStringF(std::string *str, FormatState *f) {
	str->append(AstNode::typeToStr(type));
	str->append(" ");
	str->append(name);
}
void Function::toStringF(std::string *str, FormatState *f) {
	str->append(AstNode::typeToStr(type));
	str->append(" ");
	str->append(name);
	str->append("(");
	for (std::vector<ArgDecl*>::iterator it = args->begin();
		it != args->end(); ++it) {
		if (it != args->begin()) {
			str->append(", ");
		}
		(*it)->toStringF(str, f);
	}
	str->append(") ");
	block->toStringF(str, f);
}
void Return::toStringF(std::string *str, FormatState *f) {
	str->append("return ");
	expr->toStringF(str, f);
}
void PrePostFix::toStringF(std::string *str, FormatState *f) {
	if (postfix) {
		str->append(name);
		if (incr) str->append("++");
		else str->append("--");
	}
	else {
		if (incr) str->append("++");
		else str->append("--");
		str->append(name);
	}
}
void If::toStringF(std::string *str, FormatState *f) {
	str->append("if (");
	expr->toStringF(str, f);
	str->append(") ");
	ifBlock->toStringF(str, f);
	if (elseBlock != NULL) {
		str->append(" else ");
		elseBlock->toStringF(str, f);
	}
}
void ForLoop::toStringF(std::string *str, FormatState *f) {
	str->append("for(");
	init->toStringF(str, f);
	str->append("; ");
	test->toStringF(str, f);
	str->append("; ");
	iter->toStringF(str, f);
	str->append(") ");
	block->toStringF(str, f);
}
void IntConst::toStringF(std::string *str, FormatState *f) {
	str->append(std::to_string(value));
}
void FloatConst::toStringF(std::string *str, FormatState *f) {
	std::string format("%.");
	format.append(std::to_string(decimals));
	format.append("f");
	str->append(AstNode::fmt(format.c_str(), value));
}
void Reference::toStringF(std::string *str, FormatState *f) {
	str->append(name);
}
void FieldReference::toStringF(std::string *str, FormatState *f) {
	expr->toStringF(str, f);
	str->append(".");
	str->append(field);
}
void BracedExpr::toStringF(std::string *str, FormatState *f) {
	str->append("(");
	expr->toStringF(str, f);
	str->append(")");
}
void Comparison::toStringF(std::string *str, FormatState *f) {
	expr1->toStringF(str, f);
	str->append(" ");
	str->append(AstNode::compOpToStr(compOp));
	str->append(" ");
	expr2->toStringF(str, f);
}
void MultiplyExpr::toStringF(std::string *str, FormatState *f) {
	op1->toStringF(str, f);
	str->append(" * ");
	op2->toStringF(str, f);
}
void DivideExpr::toStringF(std::string *str, FormatState *f) {
	op1->toStringF(str, f);
	str->append(" / ");
	op2->toStringF(str, f);
}
void PlusExpr::toStringF(std::string *str, FormatState *f) {
	op1->toStringF(str, f);
	str->append(" + ");
	op2->toStringF(str, f);
}
void MinusExpr::toStringF(std::string *str, FormatState *f) {
	op1->toStringF(str, f);
	str->append(" - ");
	op2->toStringF(str, f);
}
void FunctionCall::toStringF(std::string *str, FormatState *f) {
	str->append(name);
	str->append("(");
	for (std::vector<Expression*>::iterator it = args->begin();
		it != args->end(); ++it) {
		if (it != args->begin()) {
			str->append(", ");
		}
		(*it)->toStringF(str, f);
	}
	str->append(")");
}
void TypeConstructor::toStringF(std::string *str, FormatState *f) {
	str->append(AstNode::typeToStr(type));
	str->append("(");
	for (std::vector<Expression*>::iterator it = args->begin();
		it != args->end(); ++it) {
		if (it != args->begin()) {
			str->append(", ");
		}
		(*it)->toStringF(str, f);
	}
	str->append(")");
}
void Assignment::toStringF(std::string *str, FormatState *f) {
	str->append(name);
	str->append(" = ");
	expr->toStringF(str, f);
}
void OpAssignment::toStringF(std::string *str, FormatState *f) {
	str->append(name);
	str->append(" ");
	str->append(AstNode::opAssignToStr(op));
	str->append(" ");
	expr->toStringF(str, f);
}
void TypedAssignment::toStringF(std::string *str, FormatState *f) {
	str->append(AstNode::typeToStr(type));
	str->append(" ");
	str->append(name);
	str->append(" = ");
	expr->toStringF(str, f);
}
