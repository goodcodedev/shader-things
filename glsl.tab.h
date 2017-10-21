/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
     LAYOUT = 279,
     LOCATION = 280,
     IN = 281,
     OUT = 282,
     PLUS = 283,
     MINUS = 284,
     STAR = 285,
     SLASH = 286,
     MODULUS = 287,
     LEFT_SHIFT = 288,
     RIGHT_SHIFT = 289,
     AMPERSAND = 290,
     CARET = 291,
     PIPE = 292,
     DOT = 293,
     RETURN = 294,
     IF = 295,
     ELSE = 296,
     FOR = 297,
     LT = 298,
     GT = 299,
     LTE = 300,
     GTE = 301,
     EQ = 302,
     STRUCT = 303,
     HASH = 304,
     VERSION = 305
   };
#endif
/* Tokens.  */
#define INTCONST 258
#define FLOATCONST 259
#define IDENTIFIER 260
#define VOID 261
#define INT 262
#define FLOAT 263
#define VEC2 264
#define VEC3 265
#define VEC4 266
#define MAT2 267
#define MAT3 268
#define MAT4 269
#define LEFT_BRACE 270
#define RIGHT_BRACE 271
#define LEFT_PAREN 272
#define RIGHT_PAREN 273
#define COMMA 274
#define SEMICOLON 275
#define EQUAL 276
#define ATTRIBUTE 277
#define UNIFORM 278
#define LAYOUT 279
#define LOCATION 280
#define IN 281
#define OUT 282
#define PLUS 283
#define MINUS 284
#define STAR 285
#define SLASH 286
#define MODULUS 287
#define LEFT_SHIFT 288
#define RIGHT_SHIFT 289
#define AMPERSAND 290
#define CARET 291
#define PIPE 292
#define DOT 293
#define RETURN 294
#define IF 295
#define ELSE 296
#define FOR 297
#define LT 298
#define GT 299
#define LTE 300
#define GTE 301
#define EQ 302
#define STRUCT 303
#define HASH 304
#define VERSION 305




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "../glsl.y"
{
	int ival;
	double fval;
	char *sval;
	void *ast;
	void *vector;
	int enm;
}
/* Line 1529 of yacc.c.  */
#line 158 "../glsl.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

