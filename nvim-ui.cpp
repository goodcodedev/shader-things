#include <stdio.h>
#include <stdlib.h>
#include <string>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#define SOKOL_IMPL
#define SOKOL_GLCORE33
#include "AstNode.hpp"
#include "shader.hpp"

extern FILE *yyin;
extern int yyparse();
extern AstNode *result;

void glfw_error(int error, const char* description) {
	fprintf(stderr, "Glfw error: %s", description);
}

int glsl_parser() {
	auto expr = floatc(123.0);
	auto my_ref = ref("uTime");
	auto pl = *expr + my_ref;
	auto plussed = expr->operator+(my_ref);
	auto another = *floatc(123.0) + ref("uTime");
	auto fc = fcall("mix", { floatc(12.0), vec3({floatc(1.0)}) });
	FILE *sourceFile;
	errno = 0;
	fopen_s(&sourceFile, "C:/nvim-ui/sdf-fragment.glsl", "r");
	if (!sourceFile) {
		printf("Can't open file %d", errno);
		return -1;
	}
	yyin = sourceFile;
	do {    
		yyparse();
	} while (!feof(yyin));
	std::string str; 
	result->toStringF(&str, new FormatState());
	fprintf(stdout, str.c_str());
	return 0;
}
/*
AstNode* box3d(double width, double height, double depth, double rounding) {

}*/

int main() {
	glsl_parser();
	if (!glfwInit()) {
		exit(1);
	}
	glfwSetErrorCallback(glfw_error);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(640, 480, "Neovim", NULL, NULL);
	if (!window) {
		exit(1);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	while (!glfwWindowShouldClose(window)) {
		int currWidth, currHeight;
		glfwGetFramebufferSize(window, &currWidth, &currHeight);
		
		glfwSwapBuffers(window);
		glfwWaitEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}