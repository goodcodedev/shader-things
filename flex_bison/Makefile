all: glsl.tab.c lex.yy.c
	#g++ -c glsl.tab.cpp glsl.tab.h lex.yy.cc
	#ar rcs glsl_parser.lib glsl.tab.o lex.yy.o

glsl.tab.c: ../glsl.y
	win_bison.exe -o ../glsl.tab.cpp --defines=../glsl.tab.h ../glsl.y

lex.yy.c: ../glsl.l
	win_flex.exe --wincompat -o ../lex.yy.cpp ../glsl.l
