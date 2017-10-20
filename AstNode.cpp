#include "AstNode.hpp"

// Operator overloading on Expression
Expression * Expression::operator+(Expression *expr) {
	return new PlusExpr(this, expr);
}
Expression * Expression::operator-(Expression *expr) {
	return new MinusExpr(this, expr);
}
Expression * Expression::operator*(Expression *expr) {
	return new MultiplyExpr(this, expr);
}
Expression * Expression::operator/(Expression *expr) {
	return new DivideExpr(this, expr);
}