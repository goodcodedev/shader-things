#include "shader.hpp"

FloatConst* floatc(double value) {
	return new FloatConst(value);
}

FloatConst* floatc(const char *value) {
	return new FloatConst(value);
}

IntConst* intc(int value) {
	return new IntConst(value);
}

Reference* ref(std::string name) {
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

FunctionCall* fcall(std::string name, std::initializer_list<Expression*> args) {
	return new FunctionCall(name, new std::vector<Expression*>(args));
}

AstNode* parseFile(std::string fileName) {
    FILE *sourceFile;
    errno = 0;
#ifdef _WIN32
    fopen_s(&sourceFile, fileName.c_str(), "r");
#else
    sourceFile = fopen(fileName.c_str(), "r");
#endif
	if (!sourceFile) {
		printf("Can't open file %d", errno);
		exit(1);
	}
	yyin = sourceFile;
	do {    
		yyparse();
	} while (!feof(yyin));
	//std::string str; 
	//result->toStringF(&str, new FormatState());
	//fprintf(stdout, str.c_str());
	return result;
}

std::string getFileStr(std::string fileName) {
	AstNode *result = parseFile(fileName);
	std::string str; 
	result->toStringF(&str, new FormatState());
	return str;
}