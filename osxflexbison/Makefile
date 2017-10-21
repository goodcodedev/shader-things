all: glsl.tab.c lex.yy.c
	#g++ -c glsl.tab.cpp glsl.tab.h lex.yy.cc
	#ar rcs glsl_parser.lib glsl.tab.o lex.yy.o

glsl.tab.c: ../glsl.y
	bison -o ../glsl.tab.cpp --defines=../glsl.tab.h ../glsl.y

lex.yy.c: ../glsl.l
	flex -o ../lex.yy.cpp ../glsl.l
