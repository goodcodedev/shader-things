#pragma once
#include "AstNode.hpp"

FloatConst* floatc(double value);
FloatConst* floatc(char *value);
IntConst* intc(int value);
Reference* ref(char *name);
BracedExpr* braced(Expression* expr);

TypeConstructor* vec2(std::initializer_list<Expression*> args);
TypeConstructor* vec3(std::initializer_list<Expression*> args);
TypeConstructor* vec4(std::initializer_list<Expression*> args);

FunctionCall* fcall(char *name, std::initializer_list<Expression*> args);