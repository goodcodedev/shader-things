#pragma once
#include <vector>
#include <string>
#include <stdarg.h>

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
	AstNode() {}
	virtual ~AstNode() {}
	virtual void toString(std::string *str) {}
	virtual void toStringF(std::string *str, FormatState *f) {}
	static char* typeToStr(Type t) {
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
	static char* compOpToStr(CompOp compOp) {
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
	static char* opAssignToStr(AssignOp op) {
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
	static char* fmt(const char *format, ...) {
		va_list args;
		va_start(args, format);
		//size_t buf_size = vsnprintf(NULL, 0, format, args) + 1;
		size_t buf_size = _vscprintf(format, args) + 1;
		char *buf = reinterpret_cast<char*>(malloc(sizeof(char) * buf_size));
		//vsprintf(buf, format, args);
		vsprintf_s(buf, buf_size, format, args);
		va_end(args);
		return buf;
	}
};

class Source : public AstNode {
public:
	std::vector<AstNode*> *nodes;
	Source(std::vector<AstNode*> *nodes) : nodes(nodes) {}
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

class Attribute : public AstNode {
public:
	Type type;
	char *name;
	Attribute(Type type, char *name) : type(type), name(name) {}
	~Attribute() {
		free(name);
	}
	void toString(std::string *str) {
		str->append(AstNode::fmt("attribute %s %s;", AstNode::typeToStr(type), name));
	}
	void toStringF(std::string *str, FormatState *f);
};

class Out : public AstNode {
public:
	Type type;
	char *name;
	Out(Type type, char *name) : type(type), name(name) {}
	~Out() {
		free(name);
	}
	void toString(std::string *str) {
		str->append(AstNode::fmt("out %s %s;", AstNode::typeToStr(type), name));
	}
	void toStringF(std::string *str, FormatState *f);
};

class In : public AstNode {
public:
	Type type;
	char *name;
	In(Type type, char *name) : type(type), name(name) {}
	~In() {
		free(name);
	}
	void toString(std::string *str) {
		str->append(AstNode::fmt("in %s %s;", AstNode::typeToStr(type), name));
	}
	void toStringF(std::string *str, FormatState *f);
};

class Uniform : public AstNode {
public:
	Type type;
	char *name;
	Uniform(Type type, char *name) : type(type), name(name) {}
	~Uniform() {
		free(name);
	}
	void toString(std::string *str) {
		str->append(AstNode::fmt("uniform %s %s;", AstNode::typeToStr(type), name));
	}
	void toStringF(std::string *str, FormatState *f);
};

class Statement : public AstNode {
public:
	bool isControlStruct;
	Statement() : isControlStruct(false) {}
	Statement(bool isControlStruct) : isControlStruct(isControlStruct) {}
};

class Block : public AstNode {
public:
	std::vector<Statement*> *statements;
	Block(std::vector<Statement*> *statements) : statements(statements) {}
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
	char *name;
	ArgDecl(Type type, char *name) : type(type), name(name) {}
	~ArgDecl() {
		free(name);
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
	char *name;
	std::vector<ArgDecl*> *args;
	Block *block;
	Function(Type type, char *name, std::vector<ArgDecl*> *args, Block *block) :
		type(type), name(name), args(args), block(block) {}
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
	Expression * operator+(Expression *expr);
	Expression * operator-(Expression *expr);
	Expression * operator*(Expression *expr);
	Expression * operator/(Expression *expr);
};

class Return : public Statement {
public:
	Expression *expr;
	Return(Expression *expr) : expr(expr) {}
	~Return() {
		delete expr;
	}
	void toString(std::string *str) {
		str->append("return ");
		expr->toString(str);
	}
	void toStringF(std::string *str, FormatState *f);
};

class PrePostFix : public Expression, public Statement {
public:
	char *name;
	bool postfix;
	// Increment or decrement
	bool incr;
	PrePostFix(char *name, bool postfix, bool incr) : name(name), postfix(postfix), incr(incr) {}
	~PrePostFix() {
		free(name);
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
	If(Expression *expr, Block *ifBlock) : expr(expr), ifBlock(ifBlock), elseBlock(NULL), Statement(true) {}
	If(Expression *expr, Block *ifBlock, Block *elseBlock)
		: expr(expr), ifBlock(ifBlock), elseBlock(elseBlock), Statement(true) {}
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
		: init(init), test(test), iter(iter), block(block), Statement(true) {}
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
	IntConst(int value) : value(value) {}
	void toString(std::string *str) {
		str->append(std::to_string(value));
	}
	void toStringF(std::string *str, FormatState *f);
};

class FloatConst : public Expression {
public:
	double value;
	int decimals;
	FloatConst(double value, int decimals) : value(value), decimals(decimals) {}
	FloatConst(double value) : value(value) {
		// Find last non-zero up to 10 positions
		char *serialized = AstNode::fmt("%.10f", value);
		int dotpos = (strrchr(serialized, '.') - serialized);
		int num = 0;
		for (int i = strlen(serialized) - 1; i > dotpos; --i) {
			if (serialized[i] != '0') {
				num = i - dotpos;
				break;
			}
		}
		decimals = num;
		free(serialized);
	}
	FloatConst(char *str) {
		int len = strlen(str);
		if (len > 0) {
			value = atof(str);
			char *lastdot = strrchr(str, '.');
			if (lastdot != NULL) {
				decimals = len - (lastdot - str) - 1;
			}
			else {
				decimals = 0;
			}
		}
	}
	void toString(std::string *str) {
		std::string format("%.");
		format.append(std::to_string(decimals));
		format.append("f");
		str->append(AstNode::fmt(format.c_str(), value));
	}
	void toStringF(std::string *str, FormatState *f);
};

class Reference : public Expression {
public:
	char *name;
	Reference(char *name) : name(name) {}
	~Reference() {
		free(name);
	}
	void toString(std::string *str) {
		str->append(name);
	}
	void toStringF(std::string *str, FormatState *f);
};

class FieldReference : public Expression {
public:
	Expression *expr;
	char *field;
	FieldReference(Expression *expr, char *field) : expr(expr), field(field) {}
	~FieldReference() {
		delete expr;
		free(field);
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
	BracedExpr(Expression *expr) : expr(expr) {}
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
		: compOp(compOp), expr1(expr1), expr2(expr2) {}
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
	MultiplyExpr(Expression *op1, Expression *op2) : op1(op1), op2(op2) {}
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
	DivideExpr(Expression *op1, Expression *op2) : op1(op1), op2(op2) {}
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
	PlusExpr(Expression *op1, Expression *op2) : op1(op1), op2(op2) {}
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
	MinusExpr(Expression *op1, Expression *op2) : op1(op1), op2(op2) {}
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

class FunctionCall : public Expression, public Statement {
public:
	char *name;
	std::vector<Expression*> *args;
	FunctionCall(char *name, std::vector<Expression*> *args)
		: name(name), args(args) {}
	~FunctionCall() {
		free(name);
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
	TypeConstructor(Type type, std::vector<Expression*> *args) : type(type), args(args) {}
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
	char *name;
	Expression *expr;
	Assignment(char *name, Expression *expr) :
		name(name), expr(expr) {}
	virtual ~Assignment() {
		free(name);
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
	char *name;
	Expression *expr;
	OpAssignment(AssignOp op, char *name, Expression *expr) :
		op(op), name(name), expr(expr) {}
	~OpAssignment() {
		free(name);
		delete expr;
	}
	void toString(std::string *str) {
		str->append(name);
		str->append(AstNode::opAssignToStr(op));
		expr->toString(str);
	}
	void toStringF(std::string *str, FormatState *f);
};

class TypedAssignment : public Assignment {
public:
	Type type;
	TypedAssignment(Type type, char *name, Expression *expr) :
		Assignment(name, expr), type(type) {}
	void toString(std::string *str) {
		str->append(AstNode::typeToStr(type));
		str->append(" ");
		str->append(name);
		str->append("=");
		expr->toString(str);
	}
	void toStringF(std::string *str, FormatState *f);
};