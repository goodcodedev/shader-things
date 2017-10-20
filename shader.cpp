#pragma once
#include "shader.hpp"

FloatConst* floatc(double value) {
	return new FloatConst(value);
}

FloatConst* floatc(char *value) {
	return new FloatConst(value);
}

IntConst* intc(int value) {
	return new IntConst(value);
}

Reference* ref(char *name) {
	return new Reference(name);
}

BracedExpr* braced(Expression* expr) {
	return new BracedExpr(expr);
}

TypeConstructor* vec2(std::initializer_list<Expression*> args) {
	return new TypeConstructor(Vec2, new std::vector<Expression*>(args));
}

TypeConstructor* vec3(std::initializer_list<Expression*> args) {
	return new TypeConstructor(Vec3, new std::vector<Expression*>(args));
}

TypeConstructor* vec4(std::initializer_list<Expression*> args) {
	return new TypeConstructor(Vec4, new std::vector<Expression*>(args));
}

FunctionCall* fcall(char *name, std::initializer_list<Expression*> args) {
	return new FunctionCall(name, new std::vector<Expression*>(args));
}