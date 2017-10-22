#pragma once
#include <vector>
#include <string>
#include <stdarg.h>
#include <iostream>

enum Type {
	Void, Int, Float,
	Vec2, Vec3, Vec4,
	Mat2, Mat3, Mat4
};

enum CompOp {
	Lt, Gt, Lte, Gte, Eq
};

enum AssignOp {
	PlusAssign,
	MinusAssign,
	MultiplyAssign,
	DivideAssign,
	ModulusAssign,
	LeftShiftAssign,
	RightShiftAssign,
	BitAndAssign,
	BitOrAssign,
	BitIncOrAssign
};

enum NodeType {
	SourceNode,
	AttributeNode,
	OutNode,
	InNode,
	UniformNode,
	BlockNode,
	ArgDeclNode,
	FunctionNode,
	ReturnNode,
	PrePostFixNode,
	PrePostFixStmNode,
	IfNode,
	ForLoopNode,
	IntConstNode,
	FloatConstNode,
	ReferenceNode,
	FieldReferenceNode,
	BracedExprNode,
	ComparisonNode,
	MultiplyExprNode,
	DivideExprNode,
	PlusExprNode,
	MinusExprNode,
	FunctionCallNode,
	FunctionCallStmNode,
	TypeConstructorNode,
	AssignmentNode,
	OpAssignmentNode,
	TypedAssignmentNode,
	StructMemberNode,
	StructDeclNode,
	VersionNode
};

class FormatState {
public:
	int indent_count = 0;
	inline FormatState* incr() {
		++indent_count;
		return this;
	}
	inline FormatState* decr() {
		--indent_count;
		return this;
	}
	void indent(std::string *str) {
		for (int i = 0; i < indent_count; i++) {
			str->append("  ");
		}
	}
};

class AstNode {
public:
	NodeType nodeType;
	AstNode(NodeType nodeType): nodeType(nodeType) {}
	virtual ~AstNode() {}
	virtual void toString(std::string *str) {}
	virtual void toStringF(std::string *str, FormatState *f) {}
	static std::string typeToStr(Type t) {
		switch (t) {
		case Void: return "void";
		case Int: return "int";
		case Float: return "float";
		case Vec2: return "vec2";
		case Vec3: return "vec3";
		case Vec4: return "vec4";
		case Mat2: return "mat2";
		case Mat3: return "mat3";
		case Mat4: return "mat4";
		default: {
			return "<UNRECOGNIZED TYPE>";
		}
		}
	}
	static std::string compOpToStr(CompOp compOp) {
		switch (compOp) {
		case Lt: return "<";
		case Gt: return ">";
		case Lte: return "<=";
		case Gte: return ">=";
		case Eq: return "==";
		default: {
			return "<UNRECOGNIZED OP>";
		}
		}
	}
	static std::string opAssignToStr(AssignOp op) {
		switch (op) {
		case PlusAssign: return "+=";
		case MinusAssign: return "-=";
		case MultiplyAssign: return "*=";
		case DivideAssign: return "/=";
		case ModulusAssign: return "%=";
		case LeftShiftAssign: return "<<=";
		case RightShiftAssign: return ">>=";
		case BitAndAssign: return "&=";
		case BitOrAssign: return "^=";
		case BitIncOrAssign: return "|=";
		default: {
			return "<UNRECOGNIZED ASSIGN OP>";
		}
		}
	}
};

class Source : public AstNode {
public:
	std::vector<AstNode*> *nodes;
	Source(std::vector<AstNode*> *nodes) : AstNode(SourceNode), nodes(nodes) {}
	~Source() {
		for (AstNode* node : *nodes) delete node;
		nodes->clear();
		delete nodes;
	}
	void toString(std::string *str) {
		for (AstNode *node : *nodes) {
			node->toString(str);
		}
	}
	void toStringF(std::string *str, FormatState *f);
};

class StructMember : public AstNode {
public:
	Type type;
	std::string name;
	StructMember(Type type, std::string name) : AstNode(StructMemberNode), type(type), name(name) {}
	~StructMember() {}
	void toString(std::string *str) {
		*str += AstNode::typeToStr(type);
		*str += " ";
		*str += name;
		*str += ";";
	}
	void toStringF(std::string *str, FormatState *f);
};

class StructDecl : public AstNode {
public:
	std::vector<StructMember*> *members;
	std::string name;
	std::string varName;
	StructDecl(std::vector<StructMember*>* members, std::string name) : AstNode(StructDeclNode), members(members), name(name), varName("") {}
	StructDecl(std::vector<StructMember*>* members, std::string name, std::string varName) 
		: AstNode(StructDeclNode), members(members), name(name), varName(varName) {}
	~StructDecl() {
		for (StructMember* member : *members) delete member;
		members->clear();
		delete members;
	}
	void toString(std::string *str) {
		*str += "struct{";
		for (StructMember* member : *members) member->toString(str);
		*str += "}";
		if (varName.compare("") != 0) {
			*str += " ";
			*str += varName;
		}
		*str += ";";
	}
	void toStringF(std::string *str, FormatState *f);
};

class Attribute : public AstNode {
public:
	Type type;
	std::string name;
	Attribute(Type type, std::string name) : AstNode(AttributeNode), type(type), name(name) {}
	~Attribute() {
	}
	void toString(std::string *str) {
		*str += "attribute ";
		*str += AstNode::typeToStr(type);
		*str += " ";
		*str += name;
		*str += ";";
	}
	void toStringF(std::string *str, FormatState *f);
};

class Out : public AstNode {
public:
	Type type;
	std::string name;
	Out(Type type, std::string name) : AstNode(OutNode), type(type), name(name) {}
	~Out() {
	}
	void toString(std::string *str) {
		*str += "out ";
		*str += AstNode::typeToStr(type);
		*str += " ";
		*str += name;
		*str += ";";
	}
	void toStringF(std::string *str, FormatState *f);
};

class In : public AstNode {
public:
	Type type;
	std::string name;
	int location;
	In(Type type, std::string name) : AstNode(InNode), type(type), name(name), location(-1) {}
	In(Type type, std::string name, int location) : AstNode(InNode), type(type), name(name), location(location) {}
	~In() {
	}
	void toString(std::string *str) {
		if (location != -1) {
			*str += "layout(location=";
			*str += std::to_string(location);
			*str += ") ";
		}
		*str += "in ";
		*str += AstNode::typeToStr(type);
		*str += " ";
		*str += name;
		*str += ";";
	}
	void toStringF(std::string *str, FormatState *f);
};

class Uniform : public AstNode {
public:
	Type type;
	std::string name;
	Uniform(Type type, std::string name) : AstNode(UniformNode), type(type), name(name) {}
	~Uniform() {
	}
	void toString(std::string *str) {
		*str += "uniform ";
		*str += AstNode::typeToStr(type);
		*str += " ";
		*str += name;
		*str += ";";
	}
	void toStringF(std::string *str, FormatState *f);
};

class Statement : public AstNode {
public:
	bool isControlStruct;
	Statement(NodeType nodeType) : AstNode(nodeType), isControlStruct(false) {}
	Statement(NodeType nodeType, bool isControlStruct) : AstNode(nodeType), isControlStruct(isControlStruct) {}
};

class Block : public AstNode {
public:
	std::vector<Statement*> *statements;
	Block(std::vector<Statement*> *statements) : AstNode(BlockNode), statements(statements) {}
	~Block() {
		for (Statement* stm : *statements) delete stm;
		statements->clear();
		delete statements;
	}
	void toString(std::string *str) {
		str->append("{");
		for (Statement *stm : *statements) {
			stm->toString(str);
			if (!stm->isControlStruct) {
				str->append(";");
			}
		}
		str->append("}");
	}
	void toStringF(std::string *str, FormatState *f);
};

class ArgDecl : public AstNode {
public:
	Type type;
	std::string name;
	ArgDecl(Type type, std::string name) : AstNode(ArgDeclNode), type(type), name(name) {}
	~ArgDecl() {
	}
	void toString(std::string *str) {
		str->append(AstNode::typeToStr(type));
		str->append(" ");
		str->append(name);
	}
	void toStringF(std::string *str, FormatState *f);
};

class Function : public AstNode {
public:
	Type type;
	std::string name;
	std::vector<ArgDecl*> *args;
	Block *block;
	Function(Type type, std::string name, std::vector<ArgDecl*> *args, Block *block) :
		AstNode(FunctionNode), type(type), name(name), args(args), block(block) {}
	~Function() {
		for (ArgDecl* arg : *args) delete arg;
		args->clear();
		delete args;
	}
	void toString(std::string *str) {
		str->append(AstNode::typeToStr(type));
		str->append(" ");
		str->append(name);
		str->append("(");
		for (std::vector<ArgDecl*>::iterator it = args->begin();
			it != args->end(); ++it) {
			if (it != args->begin()) {
				str->append(",");
			}
			(*it)->toString(str);
		}
		str->append(")");
		block->toString(str);
	}
	void toStringF(std::string *str, FormatState *f);
};

class Expression : public AstNode {
public:
	Expression(NodeType nodeType) : AstNode(nodeType) {}
	Expression * operator+(Expression *expr);
	Expression * operator-(Expression *expr);
	Expression * operator*(Expression *expr);
	Expression * operator/(Expression *expr);
};

class Return : public Statement {
public:
	Expression *expr;
	Return(Expression *expr) : Statement(ReturnNode), expr(expr) {}
	~Return() {
		delete expr;
	}
	void toString(std::string *str) {
		str->append("return ");
		expr->toString(str);
	}
	void toStringF(std::string *str, FormatState *f);
};

class PrePostFix : public Expression {
public:
	std::string name;
	bool postfix;
	// Increment or decrement
	bool incr;
	PrePostFix(std::string name, bool postfix, bool incr) 
		: Expression(PrePostFixNode), name(name), postfix(postfix), incr(incr) {}
	~PrePostFix() {
	}
	void toString(std::string *str) {
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
	void toStringF(std::string *str, FormatState *f);
};

class PrePostFixStm : public Statement {
public:
	std::string name;
	bool postfix;
	// Increment or decrement
	bool incr;
	PrePostFixStm(std::string name, bool postfix, bool incr) 
		: Statement(PrePostFixStmNode), name(name), postfix(postfix), incr(incr) {}
	~PrePostFixStm() {
	}
	void toString(std::string *str) {
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
	void toStringF(std::string *str, FormatState *f);
};

class If : public Statement {
public:
	Expression *expr;
	Block *ifBlock;
	Block *elseBlock;
	If(Expression *expr, Block *ifBlock) : Statement(IfNode, true), expr(expr), ifBlock(ifBlock), elseBlock(NULL) {}
	If(Expression *expr, Block *ifBlock, Block *elseBlock)
		: Statement(IfNode, true), expr(expr), ifBlock(ifBlock), elseBlock(elseBlock) {}
	~If() {
		delete expr;
		delete ifBlock;
		delete elseBlock;
	}
	void toString(std::string *str) {
		str->append("if(");
		expr->toString(str);
		str->append(")");
		ifBlock->toString(str);
		if (elseBlock != NULL) {
			str->append("else");
			elseBlock->toString(str);
		}
	}
	void toStringF(std::string *str, FormatState *f);
};

class ForLoop : public Statement {
public:
	Statement *init;
	Expression *test;
	Statement *iter;
	Block *block;
	ForLoop(Statement *init, Expression *test, Statement *iter, Block *block)
		: Statement(ForLoopNode, true), init(init), test(test), iter(iter), block(block) {}
	~ForLoop() {
		delete init;
		delete test;
		delete iter;
		delete block;
	}
	void toString(std::string *str) {
		str->append("for(");
		init->toString(str);
		str->append(";");
		test->toString(str);
		str->append(";");
		iter->toString(str);
		str->append(")");
		block->toString(str);
	}
	void toStringF(std::string *str, FormatState *f);
};

class IntConst : public Expression {
public:
	int value;
	IntConst(int value) : Expression(IntConstNode), value(value) {}
	void toString(std::string *str) {
		str->append(std::to_string(value));
	}
	void toStringF(std::string *str, FormatState *f);
};

class FloatConst : public Expression {
public:
	double value;
	int decimals;
	FloatConst(double value, int decimals) : Expression(FloatConstNode), value(value), decimals(decimals) {}
	FloatConst(double value) : Expression(FloatConstNode), value(value) {
		// Find last non-zero up to 10 positions
		std::string serialized = std::to_string(value);
		//int dotpos = (strrchr(serialized.c_str(), '.') - serialized);
		int dotpos = serialized.find_last_of('.');
		int num = 0;
		for (int i = serialized.length() - 1; i > dotpos; --i) {
			if (serialized[i] != '0') {
				num = i - dotpos;
				break;
			}
		}
		if (num > 0) decimals = num;
		else decimals = 1;
	}
	FloatConst(std::string str) : Expression(FloatConstNode) {
		int len = str.length();
		if (len > 0) {
			value = std::stod(str);
			size_t dotpos = str.find_last_of('.');
			if (dotpos  != std::string::npos) {
				decimals = len - dotpos - 1;
				if (decimals < 1) {
					decimals = 1;
				}
			}
			else {
				decimals = 1;
			}
		}
	}
	void toString(std::string *str) {
		std::string serialized = std::to_string(value);
		std::string formatted = serialized.substr(0, serialized.find_last_of('.') + decimals + 1);
		str->append(formatted);
	}
	void toStringF(std::string *str, FormatState *f);
};

class Reference : public Expression {
public:
	std::string name;
	Reference(std::string name) : Expression(ReferenceNode), name(name) {}
	~Reference() {
	}
	void toString(std::string *str) {
		str->append(name);
	}
	void toStringF(std::string *str, FormatState *f);
};

class FieldReference : public Expression {
public:
	Expression *expr;
	std::string field;
	FieldReference(Expression *expr, std::string field) 
		: Expression(FieldReferenceNode), expr(expr), field(field) {}
	~FieldReference() {
		delete expr;
	}
	void toString(std::string *str) {
		expr->toString(str);
		str->append(".");
		str->append(field);
	}
	void toStringF(std::string *str, FormatState *f);
};

class BracedExpr : public Expression {
public:
	Expression *expr;
	BracedExpr(Expression *expr) : Expression(BracedExprNode), expr(expr) {}
	~BracedExpr() {
		delete expr;
	}
	void toString(std::string *str) {
		str->append("(");
		expr->toString(str);
		str->append(")");
	}
	void toStringF(std::string *str, FormatState *f);
};

class Comparison : public Expression {
public:
	CompOp compOp;
	Expression *expr1;
	Expression *expr2;
	Comparison(CompOp compOp, Expression *expr1, Expression *expr2)
		: Expression(ComparisonNode), compOp(compOp), expr1(expr1), expr2(expr2) {}
	~Comparison() {
		delete expr1;
		delete expr2;
	}
	void toString(std::string *str) {
		expr1->toString(str);
		str->append(AstNode::compOpToStr(compOp));
		expr2->toString(str);
	}
	void toStringF(std::string *str, FormatState *f);
};

class MultiplyExpr : public Expression {
public:
	Expression *op1;
	Expression *op2;
	MultiplyExpr(Expression *op1, Expression *op2) : Expression(MultiplyExprNode), op1(op1), op2(op2) {}
	~MultiplyExpr() {
		delete op1;
		delete op2;
	}
	void toString(std::string *str) {
		op1->toString(str);
		str->append("*");
		op2->toString(str);
	}
	void toStringF(std::string *str, FormatState *f);
};

class DivideExpr : public Expression {
public:
	Expression *op1;
	Expression *op2;
	DivideExpr(Expression *op1, Expression *op2) : Expression(DivideExprNode), op1(op1), op2(op2) {}
	~DivideExpr() {
		delete op1;
		delete op2;
	}
	void toString(std::string *str) {
		op1->toString(str);
		str->append("/");
		op2->toString(str);
	}
	void toStringF(std::string *str, FormatState *f);
};

class PlusExpr : public Expression {
public:
	Expression *op1;
	Expression *op2;
	PlusExpr(Expression *op1, Expression *op2) : Expression(PlusExprNode), op1(op1), op2(op2) {}
	~PlusExpr() {
		delete op1;
		delete op2;
	}
	void toString(std::string *str) {
		op1->toString(str);
		str->append("+");
		op2->toString(str);
	}
	void toStringF(std::string *str, FormatState *f);
};

class MinusExpr : public Expression {
public:
	Expression *op1;
	Expression *op2;
	MinusExpr(Expression *op1, Expression *op2) : Expression(MinusExprNode), op1(op1), op2(op2) {}
	~MinusExpr() {
		delete op1;
		delete op2;
	}
	void toString(std::string *str) {
		op1->toString(str);
		str->append("-");
		op2->toString(str);
	}
	void toStringF(std::string *str, FormatState *f);
};

class FunctionCall : public Expression {
public:
	std::string name;
	std::vector<Expression*> *args;
	FunctionCall(std::string name, std::vector<Expression*> *args)
		: Expression(FunctionCallNode), name(name), args(args) {}
	~FunctionCall() {
	}
	void toString(std::string *str) {
		str->append(name);
		str->append("(");
		for (std::vector<Expression*>::iterator it = args->begin();
			it != args->end(); ++it) {
			if (it != args->begin()) {
				str->append(",");
			}
			(*it)->toString(str);
		}
		str->append(")");
	}
	void toStringF(std::string *str, FormatState *f);
};

class FunctionCallStm : public Statement {
public:
	std::string name;
	std::vector<Expression*> *args;
	FunctionCallStm(std::string name, std::vector<Expression*> *args)
		: Statement(FunctionCallStmNode), name(name), args(args) {}
	~FunctionCallStm() {
	}
	void toString(std::string *str) {
		str->append(name);
		str->append("(");
		for (std::vector<Expression*>::iterator it = args->begin();
			it != args->end(); ++it) {
			if (it != args->begin()) {
				str->append(",");
			}
			(*it)->toString(str);
		}
		str->append(")");
	}
	void toStringF(std::string *str, FormatState *f);
};

class TypeConstructor : public Expression {
public:
	Type type;
	std::vector<Expression*> *args;
	TypeConstructor(Type type, std::vector<Expression*> *args) 
		: Expression(TypeConstructorNode), type(type), args(args) {}
	~TypeConstructor() {
		for (Expression *arg : *args) delete arg;
		args->clear();
		delete args;
	}
	void toString(std::string *str) {
		str->append(AstNode::typeToStr(type));
		str->append("(");
		for (std::vector<Expression*>::iterator it = args->begin();
			it != args->end(); ++it) {
			if (it != args->begin()) {
				str->append(",");
			}
			(*it)->toString(str);
		}
		str->append(")");
	}
	void toStringF(std::string *str, FormatState *f);
};

class Assignment : public Statement {
public:
	std::string name;
	Expression *expr;
	Assignment(std::string name, Expression *expr)
		: Statement(AssignmentNode), name(name), expr(expr) {}
	virtual ~Assignment() {
		delete expr;
	}
	void toString(std::string *str) {
		str->append(name);
		str->append("=");
		expr->toString(str);
	}
	void toStringF(std::string *str, FormatState *f);
};

class OpAssignment : public Statement {
public:
	AssignOp op;
	std::string name;
	Expression *expr;
	OpAssignment(AssignOp op, std::string name, Expression *expr)
		: Statement(OpAssignmentNode), op(op), name(name), expr(expr) {}
	~OpAssignment() {
		delete expr;
	}
	void toString(std::string *str) {
		str->append(name);
		str->append(AstNode::opAssignToStr(op));
		expr->toString(str);
	}
	void toStringF(std::string *str, FormatState *f);
};

class TypedAssignment : public Statement {
public:
	Type type;
	std::string name;
	Expression *expr;
	TypedAssignment(Type type, std::string name, Expression *expr)
		: Statement(TypedAssignmentNode), type(type), name(name), expr(expr) {}
	virtual ~TypedAssignment() {
		delete expr;
	}
	void toString(std::string *str) {
		str->append(AstNode::typeToStr(type));
		str->append(" ");
		str->append(name);
		str->append("=");
		expr->toString(str);
	}
	void toStringF(std::string *str, FormatState *f);
};

class Version : public AstNode {
public:
	int version;
	Version(int version) : AstNode(VersionNode), version(version) {}
	void toString(std::string *str) {
		*str += "#version ";
		*str += std::to_string(version);
		*str += "\n";
	}
	void toStringF(std::string *str, FormatState *f);
};