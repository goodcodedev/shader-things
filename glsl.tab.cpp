/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     VERSION = 305,
     PRECISION = 306,
     LOWP = 307,
     MEDIUMP = 308,
     HIGHP = 309
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
#define PRECISION 306
#define LOWP 307
#define MEDIUMP 308
#define HIGHP 309




/* Copy the first part of user declarations.  */
#line 1 "../glsl.y"

#include <stdio.h>
#include "AstNode.hpp"

extern FILE *yyin;
void yyerror(const char *s);
extern int yylex(void);
inline Type itot(int i) {
	return static_cast<Type>(i);
}
AstNode *result;

template<typename T>
inline std::vector<T*>* push_node(void *vec, void *node) {
	std::vector<T*>* vec2 = reinterpret_cast<std::vector<T*>*>(vec);
	vec2->push_back(reinterpret_cast<T*>(node));
	return vec2;
}

template<typename T>
inline T* re(void *node) {
	return reinterpret_cast<T*>(node);
}

extern int yylineno;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 241 "../glsl.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 254 "../glsl.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   383

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNRULES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    12,    15,    18,    21,
      24,    27,    30,    33,    37,    41,    43,    45,    47,    51,
      56,    61,    72,    77,    82,    88,    95,   103,   104,   109,
     116,   120,   121,   125,   128,   133,   137,   141,   146,   150,
     154,   158,   162,   165,   173,   179,   189,   191,   193,   196,
     199,   204,   209,   211,   215,   219,   223,   227,   231,   235,
     239,   242,   243,   246,   250,   253,   254,   257,   261,   263,
     265,   267,   269,   271,   273,   275,   277,   279,   281,   283,
     285,   287,   289,   291,   293,   295,   297,   299,   301,   304,
     307,   310,   313,   316,   319,   322,   325
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    57,    -1,    -1,    57,    68,    -1,    57,
      61,    -1,    57,    62,    -1,    57,    63,    -1,    57,    64,
      -1,    57,    65,    -1,    57,    66,    -1,    57,    60,    -1,
      57,    58,    -1,    51,    59,     8,    -1,    51,    59,     7,
      -1,    52,    -1,    53,    -1,    54,    -1,    49,    50,     3,
      -1,    22,    78,     5,    20,    -1,    26,    78,     5,    20,
      -1,    24,    17,    25,    21,     3,    18,    26,    78,     5,
      20,    -1,    27,    78,     5,    20,    -1,    23,    78,     5,
      20,    -1,    78,     5,    21,    73,    20,    -1,    48,     5,
      15,    67,    16,    20,    -1,    48,     5,    15,    67,    16,
       5,    20,    -1,    -1,    67,    78,     5,    20,    -1,    78,
       5,    17,    76,    18,    69,    -1,    15,    70,    16,    -1,
      -1,    70,    71,    20,    -1,    70,    72,    -1,    78,     5,
      21,    73,    -1,     5,    21,    73,    -1,     5,    80,    73,
      -1,     5,    17,    74,    18,    -1,     5,    28,    28,    -1,
       5,    29,    29,    -1,    28,    28,     5,    -1,    29,    29,
       5,    -1,    39,    73,    -1,    40,    17,    73,    18,    69,
      41,    69,    -1,    40,    17,    73,    18,    69,    -1,    42,
      17,    71,    20,    73,    20,    71,    18,    69,    -1,     3,
      -1,     4,    -1,    29,     3,    -1,    29,     4,    -1,    77,
      17,    74,    18,    -1,     5,    17,    74,    18,    -1,     5,
      -1,    73,    38,     5,    -1,    73,    30,    73,    -1,    73,
      31,    73,    -1,    73,    28,    73,    -1,    73,    29,    73,
      -1,    17,    73,    18,    -1,    73,    79,    73,    -1,    29,
      73,    -1,    -1,    74,    73,    -1,    74,    19,    73,    -1,
      78,     5,    -1,    -1,    76,    75,    -1,    76,    19,    75,
      -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,    13,
      -1,    14,    -1,     6,    -1,     7,    -1,     9,    -1,    10,
      -1,    11,    -1,     8,    -1,    12,    -1,    13,    -1,    14,
      -1,    43,    -1,    44,    -1,    45,    -1,    46,    -1,    47,
      -1,    28,    21,    -1,    29,    21,    -1,    31,    21,    -1,
      32,    21,    -1,    33,    21,    -1,    34,    21,    -1,    35,
      21,    -1,    36,    21,    -1,    37,    21,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   116,   116,   119,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   133,   134,   137,   138,   139,   142,   143,
     144,   145,   149,   150,   151,   153,   156,   161,   164,   169,
     174,   179,   182,   185,   190,   193,   196,   199,   202,   203,
     204,   205,   206,   211,   214,   217,   222,   223,   224,   225,
     226,   229,   232,   234,   235,   236,   237,   238,   239,   240,
     241,   244,   247,   250,   255,   257,   260,   263,   268,   269,
     270,   271,   272,   273,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   287,   288,   289,   290,   291,   294,   295,
     296,   297,   298,   299,   300,   301,   302
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTCONST", "FLOATCONST", "IDENTIFIER",
  "VOID", "INT", "FLOAT", "VEC2", "VEC3", "VEC4", "MAT2", "MAT3", "MAT4",
  "LEFT_BRACE", "RIGHT_BRACE", "LEFT_PAREN", "RIGHT_PAREN", "COMMA",
  "SEMICOLON", "EQUAL", "ATTRIBUTE", "UNIFORM", "LAYOUT", "LOCATION", "IN",
  "OUT", "PLUS", "MINUS", "STAR", "SLASH", "MODULUS", "LEFT_SHIFT",
  "RIGHT_SHIFT", "AMPERSAND", "CARET", "PIPE", "DOT", "RETURN", "IF",
  "ELSE", "FOR", "LT", "GT", "LTE", "GTE", "EQ", "STRUCT", "HASH",
  "VERSION", "PRECISION", "LOWP", "MEDIUMP", "HIGHP", "$accept", "source",
  "nodes", "precision_decl", "precision_qualifier", "version_decl",
  "attribute_decl", "in_decl", "out_decl", "uniform_decl", "global_decl",
  "struct_decl", "struct_members", "function", "block", "statements",
  "statement", "control_struct", "expression", "arg_list", "arg_decl",
  "arg_decl_list", "type_constructable", "type", "comp_op", "assign_op", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    59,    59,    59,    60,    61,
      62,    62,    63,    64,    65,    66,    66,    67,    67,    68,
      69,    70,    70,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    72,    72,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    74,    75,    76,    76,    76,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    79,    79,    79,    79,    80,    80,
      80,    80,    80,    80,    80,    80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     1,     1,     1,     3,     4,
       4,    10,     4,     4,     5,     6,     7,     0,     4,     6,
       3,     0,     3,     2,     4,     3,     3,     4,     3,     3,
       3,     3,     2,     7,     5,     9,     1,     1,     2,     2,
       4,     4,     1,     3,     3,     3,     3,     3,     3,     3,
       2,     0,     2,     3,     2,     0,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,    74,    75,    79,    76,    77,    78,
      80,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    11,     5,     6,     7,     8,     9,    10,     4,
       0,     0,     0,     0,     0,     0,     0,     0,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,    27,    18,
      14,    13,    65,     0,    19,    23,     0,    20,    22,     0,
       0,    46,    47,    52,    68,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
       0,    61,     0,    46,    47,    60,    24,     0,     0,     0,
       0,     0,    83,    84,    85,    86,    87,     0,    61,     0,
       0,    25,     0,    31,    29,    67,    64,     0,    58,    56,
      57,    54,    55,    53,    59,     0,     0,    26,    28,     0,
      51,     0,    62,    50,     0,     0,    30,     0,     0,     0,
       0,     0,     0,    33,     0,    63,     0,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,     0,    32,     0,    21,     0,    35,    88,
      38,    89,    39,    90,    91,    92,    93,    94,    95,    96,
      36,    40,    41,     0,     0,     0,    37,     0,     0,    34,
      44,     0,     0,     0,    43,     0,     0,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    21,    41,    22,    23,    24,    25,    26,
      27,    28,    59,    29,   104,   119,   132,   133,   122,   107,
      79,    60,    73,   134,    97,   148
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -145
static const yytype_int16 yypact[] =
{
    -145,    30,    -3,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,   369,   369,    23,   369,   369,    46,     5,
     -26,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
      49,    51,    52,    36,    55,    57,    54,    64,  -145,  -145,
    -145,    42,    26,    50,    63,    53,    77,    78,  -145,  -145,
    -145,  -145,  -145,   283,  -145,  -145,    68,  -145,  -145,    80,
     355,  -145,  -145,    58,  -145,  -145,  -145,  -145,  -145,  -145,
     283,   304,   155,    67,    92,     9,   107,    98,   369,  -145,
     109,  -145,    35,  -145,  -145,   313,  -145,   283,   283,   283,
     283,   111,  -145,  -145,  -145,  -145,  -145,   283,  -145,    91,
      99,  -145,   100,  -145,  -145,  -145,  -145,   220,  -145,   313,
     313,   313,   313,  -145,   313,   241,   369,  -145,  -145,    95,
    -145,   283,   313,  -145,   113,   303,  -145,    44,    97,   283,
     104,   110,   108,  -145,   124,   313,   112,  -145,   283,     4,
      10,   115,   127,   128,   129,   130,   131,   134,   283,   125,
     126,   313,   283,   133,  -145,   136,  -145,   262,   313,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
     313,  -145,  -145,   135,   138,   283,  -145,    98,   283,   313,
     118,   175,    98,   133,  -145,   142,    98,  -145
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -144,  -145,  -131,  -145,   -53,   -96,
      76,  -145,  -145,    -1,  -145,  -145
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      72,    30,   115,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    31,    32,   100,    34,    35,    82,    85,    13,
      14,    15,   174,    16,    17,   159,    38,    39,    40,   101,
       3,   161,   160,   180,   109,   110,   111,   112,   184,   162,
      33,   157,   187,    52,   114,    18,    19,    53,    20,    50,
      51,    36,   185,   108,    42,    37,    43,    44,    76,    80,
      46,    45,    47,    87,    88,    89,    90,    49,   135,    48,
      54,    74,   149,    91,    56,    81,   151,    80,    92,    93,
      94,    95,    96,    55,    98,   158,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   170,    75,    57,    58,   173,
     125,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      99,   126,   102,   103,   106,   124,   113,   116,   136,   117,
     118,   152,   179,   127,   128,   181,   150,   153,   154,   155,
     171,   172,   156,     0,   129,   130,   163,   131,   125,     4,
       5,     6,     7,     8,     9,    10,    11,    12,   164,   165,
     166,   167,   168,   177,   105,   169,     0,   175,   178,   182,
     186,   127,   128,    87,    88,    89,    90,     0,     0,     0,
       0,     0,   129,    91,     0,    86,     0,     0,    92,    93,
      94,    95,    96,    87,    88,    89,    90,     0,     0,     0,
       0,     0,     0,    91,     0,   183,     0,     0,    92,    93,
      94,    95,    96,    87,    88,    89,    90,     0,     0,     0,
       0,     0,     0,    91,     0,     0,     0,     0,    92,    93,
      94,    95,    96,    61,    62,    63,     0,     0,     0,    64,
      65,    66,    67,    68,    69,     0,     0,    70,   120,   121,
       0,     0,     0,     0,    61,    62,    63,     0,     0,    71,
      64,    65,    66,    67,    68,    69,     0,     0,    70,   123,
     121,     0,     0,     0,     0,    61,    62,    63,     0,     0,
      71,    64,    65,    66,    67,    68,    69,     0,     0,    70,
     176,   121,     0,     0,     0,     0,    61,    62,    63,     0,
       0,    71,    64,    65,    66,    67,    68,    69,     0,     0,
      70,     0,     0,     0,     0,     0,     0,    83,    84,    63,
       0,     0,    71,    64,    65,    66,    67,    68,    69,     0,
     137,    70,     0,     0,   138,     0,     0,     0,     0,     0,
       0,   139,   140,    71,   141,   142,   143,   144,   145,   146,
     147,    87,    88,    89,    90,     0,     0,     0,     0,     0,
       0,    91,     0,     0,     0,     0,    92,    93,    94,    95,
      96,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,    77,    78,     4,     5,     6,     7,     8,
       9,    10,    11,    12
};

static const yytype_int16 yycheck[] =
{
      53,     2,    98,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    13,    14,     5,    16,    17,    70,    71,    22,
      23,    24,   153,    26,    27,    21,    52,    53,    54,    20,
       0,    21,    28,   177,    87,    88,    89,    90,   182,    29,
      17,   137,   186,    17,    97,    48,    49,    21,    51,     7,
       8,     5,   183,    18,     5,    50,     5,     5,    59,    60,
       5,    25,     5,    28,    29,    30,    31,     3,   121,    15,
      20,     3,    28,    38,    21,    17,   129,    78,    43,    44,
      45,    46,    47,    20,    17,   138,     6,     7,     8,     9,
      10,    11,    12,    13,    14,   148,    16,    20,    20,   152,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      18,    16,     5,    15,     5,   116,     5,    26,     5,    20,
      20,    17,   175,    28,    29,   178,    29,    17,    20,     5,
       5,     5,    20,    -1,    39,    40,    21,    42,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    21,    21,
      21,    21,    21,    18,    78,    21,    -1,    21,    20,    41,
      18,    28,    29,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    39,    38,    -1,    20,    -1,    -1,    43,    44,
      45,    46,    47,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    20,    -1,    -1,    43,    44,
      45,    46,    47,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    12,    13,    14,    -1,    -1,    17,    18,    19,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    29,
       9,    10,    11,    12,    13,    14,    -1,    -1,    17,    18,
      19,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      29,     9,    10,    11,    12,    13,    14,    -1,    -1,    17,
      18,    19,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    29,     9,    10,    11,    12,    13,    14,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    29,     9,    10,    11,    12,    13,    14,    -1,
      17,    17,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    29,    31,    32,    33,    34,    35,    36,
      37,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    18,    19,     6,     7,     8,     9,    10,
      11,    12,    13,    14
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,    57,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    22,    23,    24,    26,    27,    48,    49,
      51,    58,    60,    61,    62,    63,    64,    65,    66,    68,
      78,    78,    78,    17,    78,    78,     5,    50,    52,    53,
      54,    59,     5,     5,     5,    25,     5,     5,    15,     3,
       7,     8,    17,    21,    20,    20,    21,    20,    20,    67,
      76,     3,     4,     5,     9,    10,    11,    12,    13,    14,
      17,    29,    73,    77,     3,    16,    78,    18,    19,    75,
      78,    17,    73,     3,     4,    73,    20,    28,    29,    30,
      31,    38,    43,    44,    45,    46,    47,    79,    17,    18,
       5,    20,     5,    15,    69,    75,     5,    74,    18,    73,
      73,    73,    73,     5,    73,    74,    26,    20,    20,    70,
      18,    19,    73,    18,    78,     5,    16,    28,    29,    39,
      40,    42,    71,    72,    78,    73,     5,    17,    21,    28,
      29,    31,    32,    33,    34,    35,    36,    37,    80,    28,
      29,    73,    17,    17,    20,     5,    20,    74,    73,    21,
      28,    21,    29,    21,    21,    21,    21,    21,    21,    21,
      73,     5,     5,    73,    71,    21,    18,    18,    20,    73,
      69,    73,    41,    20,    69,    71,    18,    69
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 116 "../glsl.y"
    { result = new Source(reinterpret_cast<std::vector<AstNode*>*>((yyvsp[(1) - (1)].vector))); ;}
    break;

  case 3:
#line 119 "../glsl.y"
    {
				(yyval.vector) = new std::vector<AstNode*>;
			;}
    break;

  case 4:
#line 122 "../glsl.y"
    { (yyval.vector) = push_node<AstNode>((yyvsp[(1) - (2)].vector), (yyvsp[(2) - (2)].ast)); ;}
    break;

  case 5:
#line 123 "../glsl.y"
    { (yyval.vector) = push_node<AstNode>((yyvsp[(1) - (2)].vector), (yyvsp[(2) - (2)].ast)); ;}
    break;

  case 6:
#line 124 "../glsl.y"
    { (yyval.vector) = push_node<AstNode>((yyvsp[(1) - (2)].vector), (yyvsp[(2) - (2)].ast)); ;}
    break;

  case 7:
#line 125 "../glsl.y"
    { (yyval.vector) = push_node<AstNode>((yyvsp[(1) - (2)].vector), (yyvsp[(2) - (2)].ast)); ;}
    break;

  case 8:
#line 126 "../glsl.y"
    { (yyval.vector) = push_node<AstNode>((yyvsp[(1) - (2)].vector), (yyvsp[(2) - (2)].ast)); ;}
    break;

  case 9:
#line 127 "../glsl.y"
    { (yyval.vector) = push_node<AstNode>((yyvsp[(1) - (2)].vector), (yyvsp[(2) - (2)].ast)); ;}
    break;

  case 10:
#line 128 "../glsl.y"
    { (yyval.vector) = push_node<AstNode>((yyvsp[(1) - (2)].vector), (yyvsp[(2) - (2)].ast)); ;}
    break;

  case 11:
#line 129 "../glsl.y"
    { (yyval.vector) = push_node<AstNode>((yyvsp[(1) - (2)].vector), (yyvsp[(2) - (2)].ast)); ;}
    break;

  case 12:
#line 130 "../glsl.y"
    { (yyval.vector) = push_node<AstNode>((yyvsp[(1) - (2)].vector), (yyvsp[(2) - (2)].ast)); ;}
    break;

  case 13:
#line 133 "../glsl.y"
    { (yyval.ast) = new Precision(static_cast<PrecisionQualifier>((yyvsp[(2) - (3)].enm)), Float); ;}
    break;

  case 14:
#line 134 "../glsl.y"
    { (yyval.ast) = new Precision(static_cast<PrecisionQualifier>((yyvsp[(2) - (3)].enm)), Int); ;}
    break;

  case 15:
#line 137 "../glsl.y"
    { (yyval.enm) = Lowp; ;}
    break;

  case 16:
#line 138 "../glsl.y"
    { (yyval.enm) = Mediump; ;}
    break;

  case 17:
#line 139 "../glsl.y"
    { (yyval.enm) = Highp; ;}
    break;

  case 18:
#line 142 "../glsl.y"
    { (yyval.ast) = new Version((yyvsp[(3) - (3)].ival)); ;}
    break;

  case 19:
#line 143 "../glsl.y"
    { (yyval.ast) = new Attribute(itot((yyvsp[(2) - (4)].enm)), (yyvsp[(3) - (4)].sval)); ;}
    break;

  case 20:
#line 144 "../glsl.y"
    { (yyval.ast) = new In(itot((yyvsp[(2) - (4)].enm)), (yyvsp[(3) - (4)].sval)); ;}
    break;

  case 21:
#line 145 "../glsl.y"
    {
			(yyval.ast) = new In(itot((yyvsp[(8) - (10)].enm)), (yyvsp[(9) - (10)].sval), (yyvsp[(5) - (10)].ival));
		;}
    break;

  case 22:
#line 149 "../glsl.y"
    { (yyval.ast) = new Out(itot((yyvsp[(2) - (4)].enm)), (yyvsp[(3) - (4)].sval)); ;}
    break;

  case 23:
#line 150 "../glsl.y"
    { (yyval.ast) = new Uniform(itot((yyvsp[(2) - (4)].enm)), (yyvsp[(3) - (4)].sval)); ;}
    break;

  case 24:
#line 151 "../glsl.y"
    { (yyval.ast) = new TypedAssignment(itot((yyvsp[(1) - (5)].enm)), (yyvsp[(2) - (5)].sval), re<Expression>((yyvsp[(4) - (5)].ast))); ;}
    break;

  case 25:
#line 153 "../glsl.y"
    {
				(yyval.ast) = new StructDecl(reinterpret_cast<std::vector<StructMember*>*>((yyvsp[(4) - (6)].vector)), (yyvsp[(2) - (6)].sval));
			;}
    break;

  case 26:
#line 156 "../glsl.y"
    {
				(yyval.ast) = new StructDecl(reinterpret_cast<std::vector<StructMember*>*>((yyvsp[(4) - (7)].vector)), (yyvsp[(2) - (7)].sval), (yyvsp[(6) - (7)].sval));
			;}
    break;

  case 27:
#line 161 "../glsl.y"
    {
				(yyval.vector) = new std::vector<StructMember*>;
			;}
    break;

  case 28:
#line 164 "../glsl.y"
    {
				(yyval.vector) = push_node<StructMember>((yyvsp[(1) - (4)].vector), new StructMember(itot((yyvsp[(2) - (4)].enm)), (yyvsp[(3) - (4)].sval)));
			;}
    break;

  case 29:
#line 169 "../glsl.y"
    {
				(yyval.ast) = new Function(itot((yyvsp[(1) - (6)].enm)), (yyvsp[(2) - (6)].sval), re<std::vector<ArgDecl*>>((yyvsp[(4) - (6)].vector)), re<Block>((yyvsp[(6) - (6)].ast)));
			;}
    break;

  case 30:
#line 174 "../glsl.y"
    {
			(yyval.ast) = new Block(reinterpret_cast<std::vector<Statement*>*>((yyvsp[(2) - (3)].vector)));
		;}
    break;

  case 31:
#line 179 "../glsl.y"
    {
				(yyval.vector) = new std::vector<Statement*>;
			;}
    break;

  case 32:
#line 182 "../glsl.y"
    {
				(yyval.vector) = push_node<Statement>((yyvsp[(1) - (3)].vector), (yyvsp[(2) - (3)].ast));
			;}
    break;

  case 33:
#line 185 "../glsl.y"
    {
				(yyval.vector) = push_node<Statement>((yyvsp[(1) - (2)].vector), (yyvsp[(2) - (2)].ast));
			;}
    break;

  case 34:
#line 190 "../glsl.y"
    {
				(yyval.ast) = new TypedAssignment(itot((yyvsp[(1) - (4)].enm)), (yyvsp[(2) - (4)].sval), re<Expression>((yyvsp[(4) - (4)].ast)));
			;}
    break;

  case 35:
#line 193 "../glsl.y"
    {
				(yyval.ast) = new Assignment((yyvsp[(1) - (3)].sval), re<Expression>((yyvsp[(3) - (3)].ast)));
			;}
    break;

  case 36:
#line 196 "../glsl.y"
    {
				(yyval.ast) = new OpAssignment(static_cast<AssignOp>((yyvsp[(2) - (3)].enm)), (yyvsp[(1) - (3)].sval), re<Expression>((yyvsp[(3) - (3)].ast)));
			;}
    break;

  case 37:
#line 199 "../glsl.y"
    { 
				(yyval.ast) = new FunctionCallStm((yyvsp[(1) - (4)].sval), reinterpret_cast<std::vector<Expression*>*>((yyvsp[(3) - (4)].vector)));
			;}
    break;

  case 38:
#line 202 "../glsl.y"
    { (yyval.ast) = new PrePostFixStm((yyvsp[(1) - (3)].sval), true, true); ;}
    break;

  case 39:
#line 203 "../glsl.y"
    { (yyval.ast) = new PrePostFixStm((yyvsp[(1) - (3)].sval), true, false); ;}
    break;

  case 40:
#line 204 "../glsl.y"
    { (yyval.ast) = new PrePostFixStm((yyvsp[(3) - (3)].sval), false, true); ;}
    break;

  case 41:
#line 205 "../glsl.y"
    { (yyval.ast) = new PrePostFixStm((yyvsp[(3) - (3)].sval), false, false); ;}
    break;

  case 42:
#line 206 "../glsl.y"
    {
				(yyval.ast) = new Return(re<Expression>((yyvsp[(2) - (2)].ast)));
			;}
    break;

  case 43:
#line 211 "../glsl.y"
    {
						(yyval.ast) = new If(re<Expression>((yyvsp[(3) - (7)].ast)), re<Block>((yyvsp[(5) - (7)].ast)), re<Block>((yyvsp[(7) - (7)].ast)));
					;}
    break;

  case 44:
#line 214 "../glsl.y"
    {
						(yyval.ast) = new If(re<Expression>((yyvsp[(3) - (5)].ast)), re<Block>((yyvsp[(5) - (5)].ast)));
					;}
    break;

  case 45:
#line 217 "../glsl.y"
    {
						(yyval.ast) = new ForLoop(re<Statement>((yyvsp[(3) - (9)].ast)), re<Expression>((yyvsp[(5) - (9)].ast)), re<Statement>((yyvsp[(7) - (9)].ast)), re<Block>((yyvsp[(9) - (9)].ast)));
					;}
    break;

  case 46:
#line 222 "../glsl.y"
    { (yyval.ast) = new IntConst((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 47:
#line 223 "../glsl.y"
    { (yyval.ast) = new FloatConst(atof((yyvsp[(1) - (1)].sval)), strlen((yyvsp[(1) - (1)].sval)) - (strrchr((yyvsp[(1) - (1)].sval), '.') - (yyvsp[(1) - (1)].sval)) - 1); ;}
    break;

  case 48:
#line 224 "../glsl.y"
    { (yyval.ast) = new IntConst((yyvsp[(2) - (2)].ival) * -1); ;}
    break;

  case 49:
#line 225 "../glsl.y"
    { (yyval.ast) = new FloatConst(atof((yyvsp[(2) - (2)].sval)) * -1.0, strlen((yyvsp[(2) - (2)].sval)) - (strrchr((yyvsp[(2) - (2)].sval), '.') - (yyvsp[(2) - (2)].sval)) - 1); ;}
    break;

  case 50:
#line 226 "../glsl.y"
    {
				(yyval.ast) = new TypeConstructor(static_cast<Type>((yyvsp[(1) - (4)].enm)), reinterpret_cast<std::vector<Expression*>*>((yyvsp[(3) - (4)].vector)));
			;}
    break;

  case 51:
#line 229 "../glsl.y"
    { 
				(yyval.ast) = new FunctionCall((yyvsp[(1) - (4)].sval), reinterpret_cast<std::vector<Expression*>*>((yyvsp[(3) - (4)].vector)));
			;}
    break;

  case 52:
#line 232 "../glsl.y"
    { (yyval.ast) = new Reference((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 53:
#line 234 "../glsl.y"
    { (yyval.ast) = new FieldReference(re<Expression>((yyvsp[(1) - (3)].ast)), (yyvsp[(3) - (3)].sval)); ;}
    break;

  case 54:
#line 235 "../glsl.y"
    { (yyval.ast) = new MultiplyExpr(re<Expression>((yyvsp[(1) - (3)].ast)), re<Expression>((yyvsp[(3) - (3)].ast))); ;}
    break;

  case 55:
#line 236 "../glsl.y"
    { (yyval.ast) = new DivideExpr(re<Expression>((yyvsp[(1) - (3)].ast)), re<Expression>((yyvsp[(3) - (3)].ast))); ;}
    break;

  case 56:
#line 237 "../glsl.y"
    { (yyval.ast) = new PlusExpr(re<Expression>((yyvsp[(1) - (3)].ast)), re<Expression>((yyvsp[(3) - (3)].ast))); ;}
    break;

  case 57:
#line 238 "../glsl.y"
    { (yyval.ast) = new MinusExpr(re<Expression>((yyvsp[(1) - (3)].ast)), re<Expression>((yyvsp[(3) - (3)].ast))); ;}
    break;

  case 58:
#line 239 "../glsl.y"
    { (yyval.ast) = new BracedExpr(re<Expression>((yyvsp[(2) - (3)].ast))); ;}
    break;

  case 59:
#line 240 "../glsl.y"
    { (yyval.ast) = new Comparison(static_cast<CompOp>((yyvsp[(2) - (3)].enm)), re<Expression>((yyvsp[(1) - (3)].ast)), re<Expression>((yyvsp[(3) - (3)].ast))); ;}
    break;

  case 60:
#line 241 "../glsl.y"
    { (yyval.ast) = new UnaryMinus(re<Expression>((yyvsp[(2) - (2)].ast))); ;}
    break;

  case 61:
#line 244 "../glsl.y"
    {
				(yyval.vector) = new std::vector<Expression*>;
			;}
    break;

  case 62:
#line 247 "../glsl.y"
    {
				(yyval.vector) = push_node<Expression>((yyvsp[(1) - (2)].vector), (yyvsp[(2) - (2)].ast));
			;}
    break;

  case 63:
#line 250 "../glsl.y"
    {
				(yyval.vector) = push_node<Expression>((yyvsp[(1) - (3)].vector), (yyvsp[(3) - (3)].ast));
			;}
    break;

  case 64:
#line 255 "../glsl.y"
    { (yyval.ast) = new ArgDecl(itot((yyvsp[(1) - (2)].enm)), (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 65:
#line 257 "../glsl.y"
    {
				(yyval.vector) = new std::vector<ArgDecl*>;
			;}
    break;

  case 66:
#line 260 "../glsl.y"
    {
				(yyval.vector) = push_node<ArgDecl>((yyvsp[(1) - (2)].vector), (yyvsp[(2) - (2)].ast));
			;}
    break;

  case 67:
#line 263 "../glsl.y"
    {
				(yyval.vector) = push_node<ArgDecl>((yyvsp[(1) - (3)].vector), (yyvsp[(3) - (3)].ast));
			;}
    break;

  case 68:
#line 268 "../glsl.y"
    { (yyval.enm) = Vec2; ;}
    break;

  case 69:
#line 269 "../glsl.y"
    { (yyval.enm) = Vec3; ;}
    break;

  case 70:
#line 270 "../glsl.y"
    { (yyval.enm) = Vec4; ;}
    break;

  case 71:
#line 271 "../glsl.y"
    { (yyval.enm) = Mat2; ;}
    break;

  case 72:
#line 272 "../glsl.y"
    { (yyval.enm) = Mat3; ;}
    break;

  case 73:
#line 273 "../glsl.y"
    { (yyval.enm) = Mat4; ;}
    break;

  case 74:
#line 276 "../glsl.y"
    { (yyval.enm) = Void; ;}
    break;

  case 75:
#line 277 "../glsl.y"
    { (yyval.enm) = Int; ;}
    break;

  case 76:
#line 278 "../glsl.y"
    { (yyval.enm) = Vec2; ;}
    break;

  case 77:
#line 279 "../glsl.y"
    { (yyval.enm) = Vec3; ;}
    break;

  case 78:
#line 280 "../glsl.y"
    { (yyval.enm) = Vec4; ;}
    break;

  case 79:
#line 281 "../glsl.y"
    { (yyval.enm) = Float; ;}
    break;

  case 80:
#line 282 "../glsl.y"
    { (yyval.enm) = Mat2; ;}
    break;

  case 81:
#line 283 "../glsl.y"
    { (yyval.enm) = Mat3; ;}
    break;

  case 82:
#line 284 "../glsl.y"
    { (yyval.enm) = Mat4; ;}
    break;

  case 83:
#line 287 "../glsl.y"
    { (yyval.enm) = Lt; ;}
    break;

  case 84:
#line 288 "../glsl.y"
    { (yyval.enm) = Gt; ;}
    break;

  case 85:
#line 289 "../glsl.y"
    { (yyval.enm) = Lte; ;}
    break;

  case 86:
#line 290 "../glsl.y"
    { (yyval.enm) = Gte; ;}
    break;

  case 87:
#line 291 "../glsl.y"
    { (yyval.enm) = Eq; ;}
    break;

  case 88:
#line 294 "../glsl.y"
    { (yyval.enm) = PlusAssign; ;}
    break;

  case 89:
#line 295 "../glsl.y"
    { (yyval.enm) = MinusAssign; ;}
    break;

  case 90:
#line 296 "../glsl.y"
    { (yyval.enm) = DivideAssign; ;}
    break;

  case 91:
#line 297 "../glsl.y"
    { (yyval.enm) = ModulusAssign; ;}
    break;

  case 92:
#line 298 "../glsl.y"
    { (yyval.enm) = LeftShiftAssign; ;}
    break;

  case 93:
#line 299 "../glsl.y"
    { (yyval.enm) = RightShiftAssign; ;}
    break;

  case 94:
#line 300 "../glsl.y"
    { (yyval.enm) = BitAndAssign; ;}
    break;

  case 95:
#line 301 "../glsl.y"
    { (yyval.enm) = BitOrAssign; ;}
    break;

  case 96:
#line 302 "../glsl.y"
    { (yyval.enm) = BitIncOrAssign; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2185 "../glsl.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 303 "../glsl.y"


void yyerror(const char *s) {
	printf("Parse error on line %d: %s", yylineno, s);
}
