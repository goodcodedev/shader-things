/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "../glsl.y" /* yacc.c:339  */

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


#line 94 "../glsl.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "glsl.tab.h".  */
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
#line 28 "../glsl.y" /* yacc.c:355  */

	int ival;
	double fval;
	char *sval;
	void *ast;
	void *vector;
	int enm;

#line 189 "../glsl.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GLSL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 206 "../glsl.tab.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   314

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   102,   102,   105,   108,   109,   110,   111,   112,   113,
     116,   117,   118,   119,   120,   122,   127,   132,   135,   138,
     143,   146,   149,   152,   155,   156,   157,   158,   159,   164,
     167,   170,   175,   176,   177,   178,   179,   182,   185,   187,
     188,   189,   190,   191,   192,   193,   196,   199,   202,   207,
     209,   212,   215,   220,   221,   222,   223,   224,   225,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   239,   240,
     241,   242,   243,   246,   247,   248,   249,   250,   251,   252,
     253,   254
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTCONST", "FLOATCONST", "IDENTIFIER",
  "VOID", "INT", "FLOAT", "VEC2", "VEC3", "VEC4", "MAT2", "MAT3", "MAT4",
  "LEFT_BRACE", "RIGHT_BRACE", "LEFT_PAREN", "RIGHT_PAREN", "COMMA",
  "SEMICOLON", "EQUAL", "ATTRIBUTE", "UNIFORM", "IN", "OUT", "PLUS",
  "MINUS", "STAR", "SLASH", "MODULUS", "LEFT_SHIFT", "RIGHT_SHIFT",
  "AMPERSAND", "CARET", "PIPE", "DOT", "RETURN", "IF", "ELSE", "FOR", "LT",
  "GT", "LTE", "GTE", "EQ", "$accept", "source", "nodes", "attribute_decl",
  "in_decl", "out_decl", "uniform_decl", "global_decl", "function",
  "block", "statements", "statement", "control_struct", "expression",
  "arg_list", "arg_decl", "arg_decl_list", "type_constructable", "type",
  "comp_op", "assign_op", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -116,     1,     0,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,   300,   300,   300,   300,  -116,  -116,  -116,
    -116,  -116,  -116,    -2,    16,    22,    30,    32,    19,    21,
      33,    36,    41,  -116,   235,  -116,  -116,  -116,  -116,   286,
    -116,  -116,    49,  -116,  -116,  -116,  -116,  -116,  -116,   235,
      56,   115,    51,    54,   300,  -116,    66,  -116,    84,  -116,
    -116,  -116,   235,   235,   235,   235,    67,  -116,  -116,  -116,
    -116,  -116,   235,  -116,  -116,  -116,  -116,  -116,   178,  -116,
     227,   227,   227,   227,  -116,   227,   197,    38,  -116,   235,
     227,  -116,   256,  -116,    47,    50,   235,    57,    62,    61,
    -116,    77,   227,  -116,   235,    13,    -1,    64,    75,    76,
      78,    79,    80,    82,   235,    93,    99,   227,   235,    81,
    -116,    94,   216,   227,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,   227,  -116,  -116,   104,    63,
     235,  -116,    54,   235,   227,    85,   135,    54,    81,  -116,
      87,    54,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,    59,    60,    64,    61,    62,    63,
      65,    66,    67,     0,     0,     0,     0,     5,     6,     7,
       8,     9,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,    10,    13,    11,    12,     0,
      32,    33,    38,    53,    54,    55,    56,    57,    58,     0,
       0,     0,     0,     0,     0,    51,     0,    46,     0,    34,
      35,    14,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,     0,    46,    17,    15,    52,    49,     0,    44,
      42,    43,    40,    41,    39,    45,     0,     0,    37,     0,
      47,    36,     0,    16,     0,     0,     0,     0,     0,     0,
      19,     0,    48,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,     0,     0,
      18,     0,     0,    21,    73,    24,    74,    25,    75,    76,
      77,    78,    79,    80,    81,    22,    26,    27,     0,     0,
       0,    23,     0,     0,    20,    30,     0,     0,     0,    29,
       0,     0,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,   -84,
    -116,  -115,  -116,   -34,   -71,    60,  -116,  -116,     3,  -116,
    -116
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    17,    18,    19,    20,    21,    22,    75,
      87,    99,   100,    90,    78,    55,    39,    52,   101,    72,
     114
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,     3,    86,    28,   139,    23,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    58,    24,    25,    26,    27,
     126,    29,    13,    14,    15,    16,   127,    30,    80,    81,
      82,    83,   122,   150,   124,    31,    33,    32,    85,   125,
      34,    35,    56,    92,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    36,    93,   102,    37,    56,   145,    59,
      60,    38,   117,   149,    94,    95,    57,   152,    73,    74,
     123,    77,    84,   115,   118,    96,    97,   116,    98,   119,
     135,   120,   121,   143,   138,   128,    92,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   129,   130,   136,   131,
     132,   133,    79,   134,   137,   151,   144,    94,    95,   146,
      62,    63,    64,    65,    76,   140,     0,     0,    96,     0,
      66,     0,   142,     0,   147,    67,    68,    69,    70,    71,
      62,    63,    64,    65,     0,    61,     0,     0,     0,     0,
      66,    62,    63,    64,    65,    67,    68,    69,    70,    71,
       0,    66,     0,     0,     0,   148,    67,    68,    69,    70,
      71,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,    66,     0,     0,     0,     0,    67,    68,    69,    70,
      71,    40,    41,    42,     0,     0,     0,    43,    44,    45,
      46,    47,    48,     0,     0,    49,    88,    89,     0,     0,
      40,    41,    42,     0,     0,    50,    43,    44,    45,    46,
      47,    48,     0,     0,    49,    91,    89,     0,     0,    40,
      41,    42,     0,     0,    50,    43,    44,    45,    46,    47,
      48,     0,     0,    49,   141,    89,     0,     0,    40,    41,
      42,     0,     0,    50,    43,    44,    45,    46,    47,    48,
       0,     0,    49,    62,    63,    64,    65,     0,     0,     0,
       0,     0,    50,    66,     0,     0,     0,     0,    67,    68,
      69,    70,    71,   103,     0,     0,     0,   104,     0,     0,
       0,     0,   105,   106,     0,   107,   108,   109,   110,   111,
     112,   113,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,    53,    54,     4,     5,     6,     7,
       8,     9,    10,    11,    12
};

static const yytype_int16 yycheck[] =
{
      34,     0,    73,     5,   119,     2,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    49,    13,    14,    15,    16,
      21,     5,    22,    23,    24,    25,    27,     5,    62,    63,
      64,    65,   103,   148,    21,     5,    17,     5,    72,    26,
      21,    20,    39,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    20,    16,    89,    20,    54,   142,     3,
       4,    20,    96,   147,    26,    27,    17,   151,    17,    15,
     104,     5,     5,    26,    17,    37,    38,    27,    40,    17,
     114,    20,     5,    20,   118,    21,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    21,    21,     5,    21,
      21,    21,    18,    21,     5,    18,   140,    26,    27,   143,
      26,    27,    28,    29,    54,    21,    -1,    -1,    37,    -1,
      36,    -1,    18,    -1,    39,    41,    42,    43,    44,    45,
      26,    27,    28,    29,    -1,    20,    -1,    -1,    -1,    -1,
      36,    26,    27,    28,    29,    41,    42,    43,    44,    45,
      -1,    36,    -1,    -1,    -1,    20,    41,    42,    43,    44,
      45,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    14,    -1,    -1,    17,    18,    19,    -1,    -1,
       3,     4,     5,    -1,    -1,    27,     9,    10,    11,    12,
      13,    14,    -1,    -1,    17,    18,    19,    -1,    -1,     3,
       4,     5,    -1,    -1,    27,     9,    10,    11,    12,    13,
      14,    -1,    -1,    17,    18,    19,    -1,    -1,     3,     4,
       5,    -1,    -1,    27,     9,    10,    11,    12,    13,    14,
      -1,    -1,    17,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    27,    36,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    17,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    18,    19,     6,     7,     8,     9,
      10,    11,    12,    13,    14
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    48,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    22,    23,    24,    25,    49,    50,    51,
      52,    53,    54,    64,    64,    64,    64,    64,     5,     5,
       5,     5,     5,    17,    21,    20,    20,    20,    20,    62,
       3,     4,     5,     9,    10,    11,    12,    13,    14,    17,
      27,    59,    63,    18,    19,    61,    64,    17,    59,     3,
       4,    20,    26,    27,    28,    29,    36,    41,    42,    43,
      44,    45,    65,    17,    15,    55,    61,     5,    60,    18,
      59,    59,    59,    59,     5,    59,    60,    56,    18,    19,
      59,    18,     5,    16,    26,    27,    37,    38,    40,    57,
      58,    64,    59,    17,    21,    26,    27,    29,    30,    31,
      32,    33,    34,    35,    66,    26,    27,    59,    17,    17,
      20,     5,    60,    59,    21,    26,    21,    27,    21,    21,
      21,    21,    21,    21,    21,    59,     5,     5,    59,    57,
      21,    18,    18,    20,    59,    55,    59,    39,    20,    55,
      57,    18,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    48,    48,    48,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    58,
      58,    58,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    60,    61,
      62,    62,    62,    63,    63,    63,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    65,
      65,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     2,     2,     2,
       4,     4,     4,     4,     5,     6,     3,     0,     3,     2,
       4,     3,     3,     4,     3,     3,     3,     3,     2,     7,
       5,     9,     1,     1,     2,     2,     4,     4,     1,     3,
       3,     3,     3,     3,     3,     3,     0,     2,     3,     2,
       0,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 102 "../glsl.y" /* yacc.c:1646  */
    { result = new Source(reinterpret_cast<std::vector<AstNode*>*>((yyvsp[0].vector))); }
#line 1424 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 105 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.vector) = new std::vector<AstNode*>;
			}
#line 1432 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 108 "../glsl.y" /* yacc.c:1646  */
    { (yyval.vector) = push_node<AstNode>((yyvsp[-1].vector), (yyvsp[0].ast)); }
#line 1438 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 109 "../glsl.y" /* yacc.c:1646  */
    { (yyval.vector) = push_node<AstNode>((yyvsp[-1].vector), (yyvsp[0].ast)); }
#line 1444 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 110 "../glsl.y" /* yacc.c:1646  */
    { (yyval.vector) = push_node<AstNode>((yyvsp[-1].vector), (yyvsp[0].ast)); }
#line 1450 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 111 "../glsl.y" /* yacc.c:1646  */
    { (yyval.vector) = push_node<AstNode>((yyvsp[-1].vector), (yyvsp[0].ast)); }
#line 1456 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 112 "../glsl.y" /* yacc.c:1646  */
    { (yyval.vector) = push_node<AstNode>((yyvsp[-1].vector), (yyvsp[0].ast)); }
#line 1462 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 113 "../glsl.y" /* yacc.c:1646  */
    { (yyval.vector) = push_node<AstNode>((yyvsp[-1].vector), (yyvsp[0].ast)); }
#line 1468 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 116 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new Attribute(itot((yyvsp[-2].enm)), (yyvsp[-1].sval)); }
#line 1474 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 117 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new In(itot((yyvsp[-2].enm)), (yyvsp[-1].sval)); }
#line 1480 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 118 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new Out(itot((yyvsp[-2].enm)), (yyvsp[-1].sval)); }
#line 1486 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 119 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new Uniform(itot((yyvsp[-2].enm)), (yyvsp[-1].sval)); }
#line 1492 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 120 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new TypedAssignment(itot((yyvsp[-4].enm)), (yyvsp[-3].sval), re<Expression>((yyvsp[-1].ast))); }
#line 1498 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 122 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.ast) = new Function(itot((yyvsp[-5].enm)), (yyvsp[-4].sval), re<std::vector<ArgDecl*>>((yyvsp[-2].vector)), re<Block>((yyvsp[0].ast)));
			}
#line 1506 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 127 "../glsl.y" /* yacc.c:1646  */
    {
			(yyval.ast) = new Block(reinterpret_cast<std::vector<Statement*>*>((yyvsp[-1].vector)));
		}
#line 1514 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 132 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.vector) = new std::vector<Statement*>;
			}
#line 1522 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 135 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.vector) = push_node<Statement>((yyvsp[-2].vector), (yyvsp[-1].ast));
			}
#line 1530 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 138 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.vector) = push_node<Statement>((yyvsp[-1].vector), (yyvsp[0].ast));
			}
#line 1538 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 143 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.ast) = new TypedAssignment(itot((yyvsp[-3].enm)), (yyvsp[-2].sval), re<Expression>((yyvsp[0].ast)));
			}
#line 1546 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 146 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.ast) = new Assignment((yyvsp[-2].sval), re<Expression>((yyvsp[0].ast)));
			}
#line 1554 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 149 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.ast) = new OpAssignment(static_cast<AssignOp>((yyvsp[-1].enm)), (yyvsp[-2].sval), re<Expression>((yyvsp[0].ast)));
			}
#line 1562 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 152 "../glsl.y" /* yacc.c:1646  */
    { 
				(yyval.ast) = new FunctionCall((yyvsp[-3].sval), reinterpret_cast<std::vector<Expression*>*>((yyvsp[-1].vector)));
			}
#line 1570 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 155 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new PrePostFix((yyvsp[-2].sval), true, true); }
#line 1576 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 156 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new PrePostFix((yyvsp[-2].sval), true, false); }
#line 1582 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 157 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new PrePostFix((yyvsp[0].sval), false, true); }
#line 1588 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 158 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new PrePostFix((yyvsp[0].sval), false, false); }
#line 1594 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 159 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.ast) = new Return(re<Expression>((yyvsp[0].ast)));
			}
#line 1602 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 164 "../glsl.y" /* yacc.c:1646  */
    {
						(yyval.ast) = new If(re<Expression>((yyvsp[-4].ast)), re<Block>((yyvsp[-2].ast)), re<Block>((yyvsp[0].ast)));
					}
#line 1610 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 167 "../glsl.y" /* yacc.c:1646  */
    {
						(yyval.ast) = new If(re<Expression>((yyvsp[-2].ast)), re<Block>((yyvsp[0].ast)));
					}
#line 1618 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 170 "../glsl.y" /* yacc.c:1646  */
    {
						(yyval.ast) = new ForLoop(re<Statement>((yyvsp[-6].ast)), re<Expression>((yyvsp[-4].ast)), re<Statement>((yyvsp[-2].ast)), re<Block>((yyvsp[0].ast)));
					}
#line 1626 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 175 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new IntConst((yyvsp[0].ival)); }
#line 1632 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 176 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new FloatConst(atof((yyvsp[0].sval)), strlen((yyvsp[0].sval)) - (strrchr((yyvsp[0].sval), '.') - (yyvsp[0].sval)) - 1); }
#line 1638 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 177 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new IntConst((yyvsp[0].ival) * -1); }
#line 1644 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 178 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new FloatConst(atof((yyvsp[0].sval)) * -1.0, strlen((yyvsp[0].sval)) - (strrchr((yyvsp[0].sval), '.') - (yyvsp[0].sval)) - 1); }
#line 1650 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 179 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.ast) = new TypeConstructor(static_cast<Type>((yyvsp[-3].enm)), reinterpret_cast<std::vector<Expression*>*>((yyvsp[-1].vector)));
			}
#line 1658 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 182 "../glsl.y" /* yacc.c:1646  */
    { 
				(yyval.ast) = new FunctionCall((yyvsp[-3].sval), reinterpret_cast<std::vector<Expression*>*>((yyvsp[-1].vector)));
			}
#line 1666 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 185 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new Reference((yyvsp[0].sval)); }
#line 1672 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 187 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new FieldReference(re<Expression>((yyvsp[-2].ast)), (yyvsp[0].sval)); }
#line 1678 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 188 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new MultiplyExpr(re<Expression>((yyvsp[-2].ast)), re<Expression>((yyvsp[0].ast))); }
#line 1684 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 189 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new DivideExpr(re<Expression>((yyvsp[-2].ast)), re<Expression>((yyvsp[0].ast))); }
#line 1690 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 190 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new PlusExpr(re<Expression>((yyvsp[-2].ast)), re<Expression>((yyvsp[0].ast))); }
#line 1696 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 191 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new MinusExpr(re<Expression>((yyvsp[-2].ast)), re<Expression>((yyvsp[0].ast))); }
#line 1702 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 192 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new BracedExpr(re<Expression>((yyvsp[-1].ast))); }
#line 1708 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 193 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new Comparison(static_cast<CompOp>((yyvsp[-1].enm)), re<Expression>((yyvsp[-2].ast)), re<Expression>((yyvsp[0].ast))); }
#line 1714 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 196 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.vector) = new std::vector<Expression*>;
			}
#line 1722 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 199 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.vector) = push_node<Expression>((yyvsp[-1].vector), (yyvsp[0].ast));
			}
#line 1730 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 202 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.vector) = push_node<Expression>((yyvsp[-2].vector), (yyvsp[0].ast));
			}
#line 1738 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 207 "../glsl.y" /* yacc.c:1646  */
    { (yyval.ast) = new ArgDecl(itot((yyvsp[-1].enm)), (yyvsp[0].sval)); }
#line 1744 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 209 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.vector) = new std::vector<ArgDecl*>;
			}
#line 1752 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 212 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.vector) = push_node<ArgDecl>((yyvsp[-1].vector), (yyvsp[0].ast));
			}
#line 1760 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 215 "../glsl.y" /* yacc.c:1646  */
    {
				(yyval.vector) = push_node<ArgDecl>((yyvsp[-2].vector), (yyvsp[0].ast));
			}
#line 1768 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 220 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Vec2; }
#line 1774 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 221 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Vec3; }
#line 1780 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 222 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Vec4; }
#line 1786 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 223 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Mat2; }
#line 1792 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 224 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Mat3; }
#line 1798 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 225 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Mat4; }
#line 1804 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 228 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Void; }
#line 1810 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 229 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Int; }
#line 1816 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 230 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Vec2; }
#line 1822 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 231 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Vec3; }
#line 1828 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 232 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Vec4; }
#line 1834 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 233 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Float; }
#line 1840 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 234 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Mat2; }
#line 1846 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 235 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Mat3; }
#line 1852 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 236 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Mat4; }
#line 1858 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 239 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Lt; }
#line 1864 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 240 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Gt; }
#line 1870 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 241 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Lte; }
#line 1876 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 242 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Gte; }
#line 1882 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 243 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = Eq; }
#line 1888 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 246 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = PlusAssign; }
#line 1894 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 247 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = MinusAssign; }
#line 1900 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 248 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = DivideAssign; }
#line 1906 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 249 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = ModulusAssign; }
#line 1912 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 250 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = LeftShiftAssign; }
#line 1918 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 251 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = RightShiftAssign; }
#line 1924 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 252 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = BitAndAssign; }
#line 1930 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 253 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = BitOrAssign; }
#line 1936 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 254 "../glsl.y" /* yacc.c:1646  */
    { (yyval.enm) = BitIncOrAssign; }
#line 1942 "../glsl.tab.cpp" /* yacc.c:1646  */
    break;


#line 1946 "../glsl.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 255 "../glsl.y" /* yacc.c:1906  */


void yyerror(const char *s) {
	printf("Parse error on line %d: %s", yylineno, s);
}
