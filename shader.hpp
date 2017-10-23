#pragma once
#include "AstNode.hpp"

extern FILE *yyin;
extern int yyparse();
extern AstNode *result; 

FloatConst* floatc(double value);
FloatConst* floatc(char *value);
IntConst* intc(int value);
Reference* ref(std::string name);
BracedExpr* braced(Expression* expr);

TypeConstructor* vec2(std::initializer_list<Expression*> args);
TypeConstructor* vec3(std::initializer_list<Expression*> args);
TypeConstructor* vec4(std::initializer_list<Expression*> args);

FunctionCall* fcall(std::string name, std::initializer_list<Expression*> args);

AstNode* parseFile(std::string fileName);

std::string getFileStr(std::string fileName);