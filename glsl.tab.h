/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_GLSL_TAB_H_INCLUDED
# define YY_YY_GLSL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTCONST = 258,
    FLOATCONST = 259,
    IDENTIFIER = 260,
    VOID = 261,
    INT = 262,
    FLOAT = 263,
    VEC2 = 264,
    VEC3 = 265,
    VEC4 = 266,
    MAT2 = 267,
    MAT3 = 268,
    MAT4 = 269,
    LEFT_BRACE = 270,
    RIGHT_BRACE = 271,
    LEFT_PAREN = 272,
    RIGHT_PAREN = 273,
    COMMA = 274,
    SEMICOLON = 275,
    EQUAL = 276,
    ATTRIBUTE = 277,
    UNIFORM = 278,
    IN = 279,
    OUT = 280,
    PLUS = 281,
    MINUS = 282,
    STAR = 283,
    SLASH = 284,
    MODULUS = 285,
    LEFT_SHIFT = 286,
    RIGHT_SHIFT = 287,
    AMPERSAND = 288,
    CARET = 289,
    PIPE = 290,
    DOT = 291,
    RETURN = 292,
    IF = 293,
    ELSE = 294,
    FOR = 295,
    LT = 296,
    GT = 297,
    LTE = 298,
    GTE = 299,
    EQ = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "../glsl.y" /* yacc.c:1909  */

	int ival;
	double fval;
	char *sval;
	void *ast;
	void *vector;
	int enm;

#line 109 "../glsl.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GLSL_TAB_H_INCLUDED  */
