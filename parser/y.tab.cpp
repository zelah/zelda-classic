/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SCRIPT = 258,
     FLOAT = 259,
     FOR = 260,
     BOOL = 261,
     VOID = 262,
     IF = 263,
     ELSE = 264,
     RETURN = 265,
     IMPORT = 266,
     TRUE = 267,
     FALSE = 268,
     WHILE = 269,
     FFC = 270,
     ITEM = 271,
     ITEMCLASS = 272,
     GLOBAL = 273,
     BREAK = 274,
     CONTINUE = 275,
     CONST = 276,
     DO = 277,
     NPC = 278,
     ASSIGN = 279,
     SEMICOLON = 280,
     COMMA = 281,
     LBRACKET = 282,
     RBRACKET = 283,
     LPAREN = 284,
     RPAREN = 285,
     DOT = 286,
     LBRACE = 287,
     RBRACE = 288,
     ARROW = 289,
     NUMBER = 290,
     PLUSASSIGN = 291,
     MINUSASSIGN = 292,
     TIMESASSIGN = 293,
     DIVIDEASSIGN = 294,
     ANDASSIGN = 295,
     ORASSIGN = 296,
     BITANDASSIGN = 297,
     BITORASSIGN = 298,
     BITXORASSIGN = 299,
     MODULOASSIGN = 300,
     LSHIFTASSIGN = 301,
     RSHIFTASSIGN = 302,
     IDENTIFIER = 303,
     QUOTEDSTRING = 304,
     RSHIFT = 305,
     LSHIFT = 306,
     BITXOR = 307,
     BITOR = 308,
     BITAND = 309,
     OR = 310,
     AND = 311,
     BITNOT = 312,
     NOT = 313,
     DECREMENT = 314,
     INCREMENT = 315,
     NE = 316,
     EQ = 317,
     GT = 318,
     GE = 319,
     LT = 320,
     LE = 321,
     MINUS = 322,
     PLUS = 323,
     DIVIDE = 324,
     TIMES = 325,
     MODULO = 326
   };
#endif
/* Tokens.  */
#define SCRIPT 258
#define FLOAT 259
#define FOR 260
#define BOOL 261
#define VOID 262
#define IF 263
#define ELSE 264
#define RETURN 265
#define IMPORT 266
#define TRUE 267
#define FALSE 268
#define WHILE 269
#define FFC 270
#define ITEM 271
#define ITEMCLASS 272
#define GLOBAL 273
#define BREAK 274
#define CONTINUE 275
#define CONST 276
#define DO 277
#define NPC 278
#define ASSIGN 279
#define SEMICOLON 280
#define COMMA 281
#define LBRACKET 282
#define RBRACKET 283
#define LPAREN 284
#define RPAREN 285
#define DOT 286
#define LBRACE 287
#define RBRACE 288
#define ARROW 289
#define NUMBER 290
#define PLUSASSIGN 291
#define MINUSASSIGN 292
#define TIMESASSIGN 293
#define DIVIDEASSIGN 294
#define ANDASSIGN 295
#define ORASSIGN 296
#define BITANDASSIGN 297
#define BITORASSIGN 298
#define BITXORASSIGN 299
#define MODULOASSIGN 300
#define LSHIFTASSIGN 301
#define RSHIFTASSIGN 302
#define IDENTIFIER 303
#define QUOTEDSTRING 304
#define RSHIFT 305
#define LSHIFT 306
#define BITXOR 307
#define BITOR 308
#define BITAND 309
#define OR 310
#define AND 311
#define BITNOT 312
#define NOT 313
#define DECREMENT 314
#define INCREMENT 315
#define NE 316
#define EQ 317
#define GT 318
#define GE 319
#define LT 320
#define LE 321
#define MINUS 322
#define PLUS 323
#define DIVIDE 324
#define TIMES 325
#define MODULO 326




/* Copy the first part of user declarations.  */
#line 10 "ffscript.ypp"

#include <stdlib.h>
#include <stdio.h>
#include "AST.h"
#include "UtilVisitors.h"
#include "../zsyssimple.h"
#define YYINCLUDED_STDLIB_H
extern int yydebug;
extern int yylineno;
extern char* yytext;
extern int yylex(void);
extern FILE *yyin;
extern AST *resAST;
extern void resetLexer();
void yyerror(const char* s);
string curfilename;
extern YYLTYPE noloc;

#define SHORTCUT(x,d1,d3,dd,l1,l2) ASTExpr *lval = (ASTExpr *)d1; \
					Clone c; \
					lval->execute(c,NULL); \
					x *rhs = new x(l2); \
					rhs->setFirstOperand((ASTExpr *)c.getResult()); \
					rhs->setSecondOperand((ASTExpr *)d3); \
					dd = new ASTStmtAssign(lval, rhs, l1);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 277 "y.tab.cpp"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYLTYPE_IS_TRIVIAL) && YYLTYPE_IS_TRIVIAL \
             && defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
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
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   432

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  46
/* YYNRULES -- Number of rules. */
#define YYNRULES  138
/* YYNRULES -- Number of states. */
#define YYNSTATES  228

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      20,    25,    32,    37,    39,    41,    44,    48,    51,    54,
      56,    59,    64,    66,    69,    71,    73,    75,    77,    79,
      81,    83,    90,    96,   100,   102,   106,   109,   112,   114,
     117,   120,   123,   125,   127,   129,   132,   134,   136,   138,
     141,   144,   147,   149,   151,   153,   155,   157,   159,   161,
     163,   165,   166,   168,   170,   172,   176,   180,   184,   188,
     192,   196,   200,   204,   208,   212,   216,   220,   224,   226,
     228,   232,   234,   238,   245,   249,   251,   255,   257,   261,
     263,   267,   269,   273,   275,   279,   281,   285,   287,   289,
     291,   293,   295,   297,   299,   301,   303,   307,   309,   311,
     313,   317,   319,   321,   323,   325,   328,   331,   334,   336,
     340,   342,   345,   348,   350,   352,   354,   356,   358,   363,
     367,   371,   373,   383,   389,   396,   402,   410,   413
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      73,     0,    -1,    74,    -1,    74,    75,    -1,    -1,    77,
      -1,    79,    -1,    85,    -1,    76,    -1,    83,    25,    -1,
      83,    24,    95,    25,    -1,    21,     4,    48,    24,    35,
      25,    -1,    78,     3,    48,    80,    -1,    84,    -1,    18,
      -1,    11,    49,    -1,    32,    81,    33,    -1,    32,    33,
      -1,    82,    81,    -1,    82,    -1,    83,    25,    -1,    83,
      24,    95,    25,    -1,    85,    -1,    84,    48,    -1,     4,
      -1,     6,    -1,     7,    -1,    15,    -1,    16,    -1,    17,
      -1,    23,    -1,    84,    48,    29,    86,    30,    87,    -1,
      84,    48,    29,    30,    87,    -1,    83,    26,    86,    -1,
      83,    -1,    32,    88,    33,    -1,    32,    33,    -1,    88,
      89,    -1,    89,    -1,    83,    25,    -1,    92,    25,    -1,
      91,    25,    -1,   113,    -1,   116,    -1,    87,    -1,   117,
      25,    -1,   114,    -1,   115,    -1,    25,    -1,    95,    25,
      -1,    19,    25,    -1,    20,    25,    -1,    83,    -1,    92,
      -1,    91,    -1,   113,    -1,   116,    -1,    87,    -1,   117,
      -1,   114,    -1,   115,    -1,    -1,    95,    -1,    19,    -1,
      20,    -1,    94,    36,    95,    -1,    94,    37,    95,    -1,
      94,    38,    95,    -1,    94,    39,    95,    -1,    94,    40,
      95,    -1,    94,    41,    95,    -1,    94,    42,    95,    -1,
      94,    43,    95,    -1,    94,    44,    95,    -1,    94,    46,
      95,    -1,    94,    47,    95,    -1,    94,    45,    95,    -1,
      93,    24,    95,    -1,    83,    -1,    94,    -1,    48,    31,
      48,    -1,    48,    -1,    94,    34,    48,    -1,    94,    34,
      48,    27,    95,    28,    -1,    95,    55,    96,    -1,    96,
      -1,    96,    56,    97,    -1,    97,    -1,    97,    53,    98,
      -1,    98,    -1,    98,    52,    99,    -1,    99,    -1,    99,
      54,   100,    -1,   100,    -1,   100,   103,   101,    -1,   101,
      -1,   101,   102,   104,    -1,   104,    -1,    51,    -1,    50,
      -1,    63,    -1,    64,    -1,    65,    -1,    66,    -1,    62,
      -1,    61,    -1,   104,   105,   106,    -1,   106,    -1,    68,
      -1,    67,    -1,   106,   107,   108,    -1,   108,    -1,    70,
      -1,    69,    -1,    71,    -1,    58,   108,    -1,    67,   108,
      -1,    57,   108,    -1,   109,    -1,    29,    95,    30,    -1,
      94,    -1,    94,    60,    -1,    94,    59,    -1,    35,    -1,
     110,    -1,   111,    -1,    12,    -1,    13,    -1,    94,    29,
     112,    30,    -1,    94,    29,    30,    -1,    95,    26,   112,
      -1,    95,    -1,     5,    29,    90,    25,    95,    25,    90,
      30,    89,    -1,    14,    29,    95,    30,    89,    -1,    22,
      89,    14,    29,    95,    30,    -1,     8,    29,    95,    30,
      89,    -1,     8,    29,    95,    30,    89,     9,    89,    -1,
      10,    95,    -1,    10,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   103,   103,   106,   109,   112,   113,   114,   115,   116,
     117,   124,   129,   136,   137,   140,   145,   146,   149,   152,
     157,   158,   163,   166,   172,   173,   174,   175,   176,   177,
     178,   181,   190,   201,   204,   209,   210,   213,   217,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   268,   271,   272,
     275,   279,   282,   286,   294,   300,   303,   309,   312,   318,
     321,   327,   330,   336,   339,   345,   348,   354,   357,   358,
     361,   362,   363,   364,   365,   366,   369,   375,   378,   379,
     382,   388,   391,   392,   393,   396,   400,   404,   408,   411,
     412,   413,   417,   421,   423,   424,   427,   428,   431,   435,
     441,   445,   451,   458,   462,   466,   469,   475,   476
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SCRIPT", "FLOAT", "FOR", "BOOL", "VOID",
  "IF", "ELSE", "RETURN", "IMPORT", "TRUE", "FALSE", "WHILE", "FFC",
  "ITEM", "ITEMCLASS", "GLOBAL", "BREAK", "CONTINUE", "CONST", "DO", "NPC",
  "ASSIGN", "SEMICOLON", "COMMA", "LBRACKET", "RBRACKET", "LPAREN",
  "RPAREN", "DOT", "LBRACE", "RBRACE", "ARROW", "NUMBER", "PLUSASSIGN",
  "MINUSASSIGN", "TIMESASSIGN", "DIVIDEASSIGN", "ANDASSIGN", "ORASSIGN",
  "BITANDASSIGN", "BITORASSIGN", "BITXORASSIGN", "MODULOASSIGN",
  "LSHIFTASSIGN", "RSHIFTASSIGN", "IDENTIFIER", "QUOTEDSTRING", "RSHIFT",
  "LSHIFT", "BITXOR", "BITOR", "BITAND", "OR", "AND", "BITNOT", "NOT",
  "DECREMENT", "INCREMENT", "NE", "EQ", "GT", "GE", "LT", "LE", "MINUS",
  "PLUS", "DIVIDE", "TIMES", "MODULO", "$accept", "Init", "Prog",
  "GlobalStmt", "ConstDecl", "Script", "ScriptType", "Import",
  "ScriptBlock", "ScriptStmtList", "ScriptStmt", "VarDecl", "Type",
  "FuncDecl", "ParamList", "Block", "StmtList", "Stmt", "StmtNoSemi",
  "ShortcutAssignStmt", "AssignStmt", "LVal", "DotExpr", "Expr", "Expr15",
  "Expr16", "Expr17", "Expr18", "Expr2", "Expr25", "ShiftOp", "RelOp",
  "Expr3", "AddOp", "Expr4", "MultOp", "Expr5", "Factor", "BoolConstant",
  "FuncCall", "ExprList", "ForStmt", "WhileStmt", "DoStmt", "IfStmt",
  "ReturnStmt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    72,    73,    74,    74,    75,    75,    75,    75,    75,
      75,    76,    77,    78,    78,    79,    80,    80,    81,    81,
      82,    82,    82,    83,    84,    84,    84,    84,    84,    84,
      84,    85,    85,    86,    86,    87,    87,    88,    88,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    92,    93,    93,
      94,    94,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   103,   103,   103,   103,   104,   104,   105,   105,
     106,   106,   107,   107,   107,   108,   108,   108,   108,   109,
     109,   109,   109,   109,   109,   109,   110,   110,   111,   111,
     112,   112,   113,   114,   115,   116,   116,   117,   117
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     2,
       4,     6,     4,     1,     1,     2,     3,     2,     2,     1,
       2,     4,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     6,     5,     3,     1,     3,     2,     2,     1,     2,
       2,     2,     1,     1,     1,     2,     1,     1,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     1,     3,     6,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     2,     2,     2,     1,     3,
       1,     2,     2,     1,     1,     1,     1,     1,     4,     3,
       3,     1,     9,     5,     6,     5,     7,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       4,     0,     2,     1,    24,    25,    26,     0,    27,    28,
      29,    14,     0,    30,     3,     8,     5,     0,     6,     0,
      13,     7,    15,     0,     0,     0,     9,    23,     0,     0,
     126,   127,     0,   123,    81,     0,     0,     0,   120,     0,
      85,    87,    89,    91,    93,    95,    97,   107,   111,   118,
     124,   125,     0,     0,     0,    12,     0,     0,   117,   115,
     116,     0,     0,   122,   121,    10,     0,     0,     0,     0,
       0,   105,   104,   100,   101,   102,   103,     0,    99,    98,
       0,   109,   108,     0,   113,   112,   114,     0,     0,    34,
       0,     0,     0,    17,     0,    19,     0,     0,    22,   119,
      80,   129,   131,     0,    82,    84,    86,    88,    90,    92,
      94,    96,   106,   110,     0,    32,     0,    23,     0,    11,
      16,    18,     0,    20,     0,   128,     0,     0,     0,   138,
       0,     0,     0,     0,    48,    36,    78,    44,     0,    38,
       0,     0,     0,   120,     0,    42,    46,    47,    43,     0,
      33,    31,     0,   130,     0,    61,     0,   137,     0,    50,
      51,     0,    39,    35,    37,    41,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,    45,    21,    83,    63,    64,    52,    57,     0,    54,
      53,    62,    55,    59,    60,    56,    58,     0,     0,     0,
      77,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      76,    74,    75,     0,     0,     0,     0,     0,   135,   133,
       0,    61,     0,   134,     0,   136,     0,   132
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,     2,    14,    15,    16,    17,    18,    55,    94,
      95,   136,    90,    98,    91,   137,   138,   139,   188,   140,
     141,   142,    38,   144,    40,    41,    42,    43,    44,    45,
      80,    77,    46,    83,    47,    87,    48,    49,    50,    51,
     103,   145,   146,   147,   148,   149
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -152
static const short int yypact[] =
{
    -152,    20,   409,  -152,  -152,  -152,  -152,   -27,  -152,  -152,
    -152,  -152,    42,  -152,  -152,  -152,  -152,    46,  -152,     5,
      31,  -152,  -152,    34,    44,    32,  -152,    71,    83,    76,
    -152,  -152,    32,  -152,    79,    32,    32,    32,    -6,    -4,
      56,    62,    68,    69,    40,   -16,   -30,   -45,  -152,  -152,
    -152,  -152,   243,    91,   115,  -152,     9,    80,  -152,  -152,
    -152,    30,    85,  -152,  -152,  -152,    32,    32,    32,    32,
      32,  -152,  -152,  -152,  -152,  -152,  -152,    32,  -152,  -152,
      32,  -152,  -152,    32,  -152,  -152,  -152,    32,    95,   109,
      88,   107,   114,  -152,   108,   299,    61,    31,  -152,  -152,
    -152,  -152,    -8,   110,   117,    56,    62,    68,    69,    40,
     -16,   -30,   -45,  -152,   163,  -152,   299,  -152,    95,  -152,
    -152,  -152,    32,  -152,    32,  -152,    32,   118,   120,    32,
     121,   126,   127,   275,  -152,  -152,   147,  -152,   219,  -152,
     149,   156,   122,   363,     2,  -152,  -152,  -152,  -152,   159,
    -152,  -152,     7,  -152,   -15,   331,    32,   132,    32,  -152,
    -152,   175,  -152,  -152,  -152,  -152,  -152,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
    -152,  -152,  -152,  -152,  -152,  -152,   166,  -152,   168,  -152,
    -152,   132,  -152,  -152,  -152,  -152,  -152,    26,    39,   162,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,    32,   275,   275,    32,     8,   185,  -152,
      43,   331,   275,  -152,   167,  -152,   275,  -152
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,   104,
    -152,    -2,     1,   199,    86,   -87,  -152,  -131,   -17,  -151,
    -150,  -152,   -97,   -13,   139,   140,   138,   141,   142,   136,
    -152,  -152,   129,  -152,   131,  -152,   -21,  -152,  -152,  -152,
      92,  -149,  -147,  -146,  -145,  -144
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -80
static const short int yytable[] =
{
      19,   115,   161,    20,   189,   190,   192,   164,   193,   194,
     195,   196,    39,   183,    58,    59,    60,   143,   124,    56,
       3,    65,    22,    61,    84,    85,    86,   180,    62,    25,
      26,   151,   182,   221,    78,    79,   143,    81,    82,    99,
      66,   143,    30,    31,    30,    31,    23,    66,   102,    24,
      89,    66,    96,    63,    64,    97,   214,    66,   143,    32,
     101,    32,    66,    66,    66,    33,   113,    33,   187,   215,
     189,   190,   192,   223,   193,   194,   195,   196,    34,    27,
      34,    66,    28,   218,   219,   122,   123,    35,    36,    35,
      36,   225,    29,    96,    66,   227,    97,    37,    66,    37,
      52,    71,    72,    73,    74,    75,    76,    53,    54,   152,
      57,   102,    67,   154,    89,    68,   157,   143,   143,     4,
      69,     5,     6,    70,   143,   143,    92,   114,   100,   143,
       8,     9,    10,   104,   187,   116,   117,   118,    13,   119,
     125,   120,   191,   197,   126,   198,   167,   155,    93,   156,
     158,   159,   160,   186,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     4,   127,     5,
       6,   128,   162,   129,   165,    30,    31,   130,     8,     9,
      10,   166,   131,   132,   181,   133,    13,    66,   134,   199,
     -78,   216,    32,   213,   222,   114,   135,   226,    33,   121,
     217,    21,   150,   220,   224,   105,   107,   106,   191,   111,
     108,    34,   109,   110,   112,     0,   153,     0,     0,   186,
      35,    36,     0,     4,   127,     5,     6,   128,     0,   129,
      37,    30,    31,   130,     8,     9,    10,     0,   131,   132,
       0,   133,    13,     0,   134,     0,     0,     4,    32,     5,
       6,   114,   163,     0,    33,     0,     0,     0,     8,     9,
      10,     0,     0,     0,     0,     0,    13,    34,     0,     0,
       0,     0,     0,    88,     0,     0,    35,    36,     0,     4,
     127,     5,     6,   128,     0,   129,    37,    30,    31,   130,
       8,     9,    10,     0,   131,   132,     0,   133,    13,     0,
     134,     0,     0,     4,    32,     5,     6,   114,     0,     0,
      33,     0,     0,     0,     8,     9,    10,     0,     0,     0,
       0,     0,    13,    34,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    36,     0,     4,   127,     5,     6,   128,
       0,   129,    37,    30,    31,   130,     8,     9,    10,     0,
     184,   185,     0,   133,    13,     0,     0,     0,     0,     0,
      32,     0,     0,   114,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,   -79,    35,    36,
       0,     0,    61,     0,     0,     0,     0,    62,    37,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,     0,     0,     4,     0,     5,     6,     0,     0,     0,
       7,     0,    63,    64,     8,     9,    10,    11,     0,     0,
      12,     0,    13
};

static const short int yycheck[] =
{
       2,    88,   133,     2,   155,   155,   155,   138,   155,   155,
     155,   155,    25,    28,    35,    36,    37,   114,    26,    32,
       0,    25,    49,    29,    69,    70,    71,    25,    34,    24,
      25,   118,    25,    25,    50,    51,   133,    67,    68,    30,
      55,   138,    12,    13,    12,    13,     4,    55,    61,     3,
      52,    55,    54,    59,    60,    54,    30,    55,   155,    29,
      30,    29,    55,    55,    55,    35,    87,    35,   155,    30,
     221,   221,   221,    30,   221,   221,   221,   221,    48,    48,
      48,    55,    48,   214,   215,    24,    25,    57,    58,    57,
      58,   222,    48,    95,    55,   226,    95,    67,    55,    67,
      29,    61,    62,    63,    64,    65,    66,    24,    32,   122,
      31,   124,    56,   126,   116,    53,   129,   214,   215,     4,
      52,     6,     7,    54,   221,   222,    35,    32,    48,   226,
      15,    16,    17,    48,   221,    26,    48,    30,    23,    25,
      30,    33,   155,   156,    27,   158,    24,    29,    33,    29,
      29,    25,    25,   155,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,     4,     5,     6,
       7,     8,    25,    10,    25,    12,    13,    14,    15,    16,
      17,    25,    19,    20,    25,    22,    23,    55,    25,    14,
      24,    29,    29,    25,     9,    32,    33,    30,    35,    95,
     213,     2,   116,   216,   221,    66,    68,    67,   221,    80,
      69,    48,    70,    77,    83,    -1,   124,    -1,    -1,   221,
      57,    58,    -1,     4,     5,     6,     7,     8,    -1,    10,
      67,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    -1,    25,    -1,    -1,     4,    29,     6,
       7,    32,    33,    -1,    35,    -1,    -1,    -1,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    23,    48,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    57,    58,    -1,     4,
       5,     6,     7,     8,    -1,    10,    67,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    -1,
      25,    -1,    -1,     4,    29,     6,     7,    32,    -1,    -1,
      35,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    23,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    -1,     4,     5,     6,     7,     8,
      -1,    10,    67,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    32,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    57,    58,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    67,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,     4,    -1,     6,     7,    -1,    -1,    -1,
      11,    -1,    59,    60,    15,    16,    17,    18,    -1,    -1,
      21,    -1,    23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    73,    74,     0,     4,     6,     7,    11,    15,    16,
      17,    18,    21,    23,    75,    76,    77,    78,    79,    83,
      84,    85,    49,     4,     3,    24,    25,    48,    48,    48,
      12,    13,    29,    35,    48,    57,    58,    67,    94,    95,
      96,    97,    98,    99,   100,   101,   104,   106,   108,   109,
     110,   111,    29,    24,    32,    80,    95,    31,   108,   108,
     108,    29,    34,    59,    60,    25,    55,    56,    53,    52,
      54,    61,    62,    63,    64,    65,    66,   103,    50,    51,
     102,    67,    68,   105,    69,    70,    71,   107,    30,    83,
      84,    86,    35,    33,    81,    82,    83,    84,    85,    30,
      48,    30,    95,   112,    48,    96,    97,    98,    99,   100,
     101,   104,   106,   108,    32,    87,    26,    48,    30,    25,
      33,    81,    24,    25,    26,    30,    27,     5,     8,    10,
      14,    19,    20,    22,    25,    33,    83,    87,    88,    89,
      91,    92,    93,    94,    95,   113,   114,   115,   116,   117,
      86,    87,    95,   112,    95,    29,    29,    95,    29,    25,
      25,    89,    25,    33,    89,    25,    25,    24,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      25,    25,    25,    28,    19,    20,    83,    87,    90,    91,
      92,    95,   113,   114,   115,   116,   117,    95,    95,    14,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    25,    30,    30,    29,    95,    89,    89,
      95,    25,     9,    30,    90,    89,    30,    89
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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value, Location);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
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
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;
  (void) yylocationp;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");

# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;
  (void) yylocationp;

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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
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

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended. */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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
  yylsp = yyls;
#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

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

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
  *++yylsp = yylloc;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 103 "ffscript.ypp"
    {resAST = new ASTProgram((ASTDeclList *)(yyvsp[0]), (yylsp[0]));;}
    break;

  case 3:
#line 106 "ffscript.ypp"
    {ASTDeclList *list = (ASTDeclList *)(yyvsp[-1]);
				list->addDeclaration((ASTDecl *)(yyvsp[0]));
				(yyval) = list;;}
    break;

  case 4:
#line 109 "ffscript.ypp"
    {(yyval) = new ASTDeclList(noloc);;}
    break;

  case 5:
#line 112 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 6:
#line 113 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 7:
#line 114 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 8:
#line 115 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 9:
#line 116 "ffscript.ypp"
    {(yyval) = (yyvsp[-1]);;}
    break;

  case 10:
#line 117 "ffscript.ypp"
    {ASTVarDecl *vd = (ASTVarDecl *)(yyvsp[-3]);
						   Clone c;
						   vd->getType()->execute(c,NULL);
						   (yyval) = new ASTVarDeclInitializer((ASTType *)c.getResult(), vd->getName(), (ASTExpr *)(yyvsp[-1]),(yylsp[-3]));
						   delete vd;;}
    break;

  case 11:
#line 124 "ffscript.ypp"
    {ASTString *name = (ASTString *)(yyvsp[-3]);
															ASTFloat *val = (ASTFloat *)(yyvsp[-1]);
															(yyval) = new ASTConstDecl(name->getValue(), val,(yylsp[-5]));
															delete name;;}
    break;

  case 12:
#line 129 "ffscript.ypp"
    {ASTType *type = (ASTType *)(yyvsp[-3]);
								   ASTString *name = (ASTString *)(yyvsp[-1]);
								   ASTDeclList *sblock = (ASTDeclList *)(yyvsp[0]);
								   (yyval) = new ASTScript(type, name->getValue(), sblock,(yylsp[-3]));
								   delete name;;}
    break;

  case 13:
#line 136 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 14:
#line 137 "ffscript.ypp"
    {(yyval) = new ASTTypeGlobal((yylsp[0]));;}
    break;

  case 15:
#line 140 "ffscript.ypp"
    {ASTString *str = (ASTString *)(yyvsp[0]);
					 (yyval) = new ASTImportDecl(str->getValue(),(yylsp[-1]));
					 delete str;;}
    break;

  case 16:
#line 145 "ffscript.ypp"
    {(yyval) = (yyvsp[-1]);;}
    break;

  case 17:
#line 146 "ffscript.ypp"
    {(yyval) = new ASTDeclList((yylsp[-1]));;}
    break;

  case 18:
#line 149 "ffscript.ypp"
    {ASTDeclList *dl = (ASTDeclList *)(yyvsp[0]);
							  dl->addDeclaration((ASTDecl *)(yyvsp[-1]));
							  (yyval) = dl;;}
    break;

  case 19:
#line 152 "ffscript.ypp"
    {ASTDeclList *dl = new ASTDeclList((yylsp[0]));
			  dl->addDeclaration((ASTDecl *)(yyvsp[0]));
			  (yyval) = dl;;}
    break;

  case 20:
#line 157 "ffscript.ypp"
    {(yyval) = (yyvsp[-1]);;}
    break;

  case 21:
#line 158 "ffscript.ypp"
    {ASTVarDecl *vd = (ASTVarDecl *)(yyvsp[-3]);
						   Clone c;
						   vd->getType()->execute(c,NULL);
						   (yyval) = new ASTVarDeclInitializer((ASTType *)c.getResult(), vd->getName(), (ASTExpr *)(yyvsp[-1]),(yylsp[-3]));
						   delete vd;;}
    break;

  case 22:
#line 163 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 23:
#line 166 "ffscript.ypp"
    {ASTType *type = (ASTType *)(yyvsp[-1]);
				   ASTString *name = (ASTString *)(yyvsp[0]);
				   (yyval) = new ASTVarDecl(type, name->getValue(),(yylsp[-1]));
				   delete name;;}
    break;

  case 24:
#line 172 "ffscript.ypp"
    {(yyval) = new ASTTypeFloat((yylsp[0]));;}
    break;

  case 25:
#line 173 "ffscript.ypp"
    {(yyval) = new ASTTypeBool((yylsp[0]));;}
    break;

  case 26:
#line 174 "ffscript.ypp"
    {(yyval) = new ASTTypeVoid((yylsp[0]));;}
    break;

  case 27:
#line 175 "ffscript.ypp"
    {(yyval) = new ASTTypeFFC((yylsp[0]));;}
    break;

  case 28:
#line 176 "ffscript.ypp"
    {(yyval) = new ASTTypeItem((yylsp[0]));;}
    break;

  case 29:
#line 177 "ffscript.ypp"
    {(yyval) = new ASTTypeItemclass((yylsp[0]));;}
    break;

  case 30:
#line 178 "ffscript.ypp"
    {(yyval) = new ASTTypeNPC((yylsp[0]));;}
    break;

  case 31:
#line 181 "ffscript.ypp"
    {ASTFuncDecl *fd = (ASTFuncDecl *)(yyvsp[-2]);
									    ASTType *rettype = (ASTType *)(yyvsp[-5]);
									    ASTString *name = (ASTString *)(yyvsp[-4]);
									    ASTBlock *block = (ASTBlock *)(yyvsp[0]);
									    fd->setName(name->getValue());
									    delete name;
									    fd->setReturnType(rettype);
									    fd->setBlock(block);
									    (yyval)=fd;;}
    break;

  case 32:
#line 190 "ffscript.ypp"
    {ASTFuncDecl *fd = new ASTFuncDecl((yylsp[-4]));
							   ASTType *rettype = (ASTType *)(yyvsp[-4]);
							   ASTString *name = (ASTString *)(yyvsp[-3]);
							   ASTBlock *block = (ASTBlock *)(yyvsp[0]);
							   fd->setName(name->getValue());
							   delete name;
							   fd->setReturnType(rettype);
							   fd->setBlock(block);
							   (yyval)=fd;;}
    break;

  case 33:
#line 201 "ffscript.ypp"
    {ASTFuncDecl *fd = (ASTFuncDecl *)(yyvsp[0]);
						 fd->addParam((ASTVarDecl *)(yyvsp[-2]));
						 (yyval)=fd;;}
    break;

  case 34:
#line 204 "ffscript.ypp"
    {ASTFuncDecl *fd = new ASTFuncDecl((yylsp[0]));
		     fd->addParam((ASTVarDecl *)(yyvsp[0]));
		     (yyval)=fd;;}
    break;

  case 35:
#line 209 "ffscript.ypp"
    {(yyval)=(yyvsp[-1]);;}
    break;

  case 36:
#line 210 "ffscript.ypp"
    {(yyval) = new ASTBlock((yylsp[-1]));;}
    break;

  case 37:
#line 213 "ffscript.ypp"
    {ASTBlock *block = (ASTBlock *)(yyvsp[-1]);
				  ASTStmt *stmt = (ASTStmt *)(yyvsp[0]);
				  block->addStatement(stmt);
				  (yyval) = block;;}
    break;

  case 38:
#line 217 "ffscript.ypp"
    {ASTBlock *block = new ASTBlock((yylsp[0]));
		  ASTStmt *stmt = (ASTStmt *)(yyvsp[0]);
		  block->addStatement(stmt);
		  (yyval) = block;;}
    break;

  case 39:
#line 223 "ffscript.ypp"
    {(yyval) = (yyvsp[-1]);;}
    break;

  case 40:
#line 224 "ffscript.ypp"
    {(yyval) = (yyvsp[-1]);;}
    break;

  case 41:
#line 225 "ffscript.ypp"
    {(yyval)=(yyvsp[-1]);;}
    break;

  case 42:
#line 226 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 43:
#line 227 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 44:
#line 228 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 45:
#line 229 "ffscript.ypp"
    {(yyval) = (yyvsp[-1]);;}
    break;

  case 46:
#line 230 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 47:
#line 231 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 48:
#line 232 "ffscript.ypp"
    {(yyval) = new ASTStmtEmpty((yylsp[0]));;}
    break;

  case 49:
#line 233 "ffscript.ypp"
    {(yyval)=(yyvsp[-1]);;}
    break;

  case 50:
#line 234 "ffscript.ypp"
    {(yyval) = new ASTStmtBreak((yylsp[-1]));;}
    break;

  case 51:
#line 235 "ffscript.ypp"
    {(yyval) = new ASTStmtContinue((yylsp[-1]));;}
    break;

  case 52:
#line 238 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 53:
#line 239 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 54:
#line 240 "ffscript.ypp"
    {(yyval)=(yyvsp[0]);;}
    break;

  case 55:
#line 241 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 56:
#line 242 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 57:
#line 243 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 58:
#line 244 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 59:
#line 245 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 60:
#line 246 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 61:
#line 247 "ffscript.ypp"
    {(yyval) = new ASTStmtEmpty(noloc);;}
    break;

  case 62:
#line 248 "ffscript.ypp"
    {(yyval)=(yyvsp[0]);;}
    break;

  case 63:
#line 249 "ffscript.ypp"
    {(yyval) = new ASTStmtBreak((yylsp[0]));;}
    break;

  case 64:
#line 250 "ffscript.ypp"
    {(yyval) = new ASTStmtContinue((yylsp[0]));;}
    break;

  case 65:
#line 253 "ffscript.ypp"
    {SHORTCUT(ASTExprPlus,(yyvsp[-2]),(yyvsp[0]),(yyval),(yylsp[-2]),(yylsp[-1])) ;}
    break;

  case 66:
#line 254 "ffscript.ypp"
    {SHORTCUT(ASTExprMinus,(yyvsp[-2]),(yyvsp[0]),(yyval),(yylsp[-2]),(yylsp[-1])) ;}
    break;

  case 67:
#line 255 "ffscript.ypp"
    {SHORTCUT(ASTExprTimes,(yyvsp[-2]),(yyvsp[0]),(yyval),(yylsp[-2]),(yylsp[-1])) ;}
    break;

  case 68:
#line 256 "ffscript.ypp"
    {SHORTCUT(ASTExprDivide,(yyvsp[-2]),(yyvsp[0]),(yyval),(yylsp[-2]),(yylsp[-1])) ;}
    break;

  case 69:
#line 257 "ffscript.ypp"
    {SHORTCUT(ASTExprAnd,(yyvsp[-2]),(yyvsp[0]),(yyval),(yylsp[-2]),(yylsp[-1])) ;}
    break;

  case 70:
#line 258 "ffscript.ypp"
    {SHORTCUT(ASTExprOr,(yyvsp[-2]),(yyvsp[0]),(yyval),(yylsp[-2]),(yylsp[-1])) ;}
    break;

  case 71:
#line 259 "ffscript.ypp"
    {SHORTCUT(ASTExprBitAnd,(yyvsp[-2]),(yyvsp[0]),(yyval),(yylsp[-2]),(yylsp[-1])) ;}
    break;

  case 72:
#line 260 "ffscript.ypp"
    {SHORTCUT(ASTExprBitOr,(yyvsp[-2]),(yyvsp[0]),(yyval),(yylsp[-2]),(yylsp[-1])) ;}
    break;

  case 73:
#line 261 "ffscript.ypp"
    {SHORTCUT(ASTExprBitXor,(yyvsp[-2]),(yyvsp[0]),(yyval),(yylsp[-2]),(yylsp[-1])) ;}
    break;

  case 74:
#line 262 "ffscript.ypp"
    {SHORTCUT(ASTExprLShift,(yyvsp[-2]),(yyvsp[0]),(yyval),(yylsp[-2]),(yylsp[-1])) ;}
    break;

  case 75:
#line 263 "ffscript.ypp"
    {SHORTCUT(ASTExprRShift,(yyvsp[-2]),(yyvsp[0]),(yyval),(yylsp[-2]),(yylsp[-1])) ;}
    break;

  case 76:
#line 264 "ffscript.ypp"
    {SHORTCUT(ASTExprModulo,(yyvsp[-2]),(yyvsp[0]),(yyval),(yylsp[-2]),(yylsp[-1])) ;}
    break;

  case 77:
#line 268 "ffscript.ypp"
    {(yyval) = new ASTStmtAssign((ASTStmt *)(yyvsp[-2]), (ASTExpr *)(yyvsp[0]),(yylsp[-2]));;}
    break;

  case 78:
#line 271 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 79:
#line 272 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 80:
#line 275 "ffscript.ypp"
    {ASTString *lval = (ASTString *)(yyvsp[-2]);
						 ASTString *rval = (ASTString *)(yyvsp[0]);
						 (yyval) = new ASTExprDot(lval->getValue(), rval->getValue(),(yylsp[-2]));
						 delete lval; delete rval;;}
    break;

  case 81:
#line 279 "ffscript.ypp"
    {ASTString *rval = (ASTString *)(yyvsp[0]);
				  (yyval) = new ASTExprDot("", rval->getValue(),(yylsp[0]));
				  delete rval;;}
    break;

  case 82:
#line 282 "ffscript.ypp"
    {ASTExpr *id = (ASTExpr *)(yyvsp[-2]);
								ASTString *rval = (ASTString *)(yyvsp[0]);
								(yyval) = new ASTExprArrow(id, rval->getValue(), (yylsp[-2]));
								delete rval;;}
    break;

  case 83:
#line 286 "ffscript.ypp"
    {ASTExpr *id = (ASTExpr *)(yyvsp[-5]);
											       	   ASTString *rval = (ASTString *)(yyvsp[-3]);
													   ASTExpr *num = (ASTExpr *)(yyvsp[-1]);
													   ASTExprArrow *res = new ASTExprArrow(id, rval->getValue(), (yylsp[-5]));
													   res->setIndex(num);
													   (yyval) = res;;}
    break;

  case 84:
#line 294 "ffscript.ypp"
    {ASTLogExpr *e = new ASTExprOr((yylsp[-1]));
				 ASTExpr *left = (ASTExpr *)(yyvsp[-2]);
				 ASTExpr *right = (ASTExpr *)(yyvsp[0]);
				 e->setFirstOperand(left);
				 e->setSecondOperand(right);
				 (yyval)=e;;}
    break;

  case 85:
#line 300 "ffscript.ypp"
    {(yyval)=(yyvsp[0]);;}
    break;

  case 86:
#line 303 "ffscript.ypp"
    {ASTLogExpr *e = new ASTExprAnd((yylsp[-1]));
				 ASTExpr *left = (ASTExpr *)(yyvsp[-2]);
				 ASTExpr *right = (ASTExpr *)(yyvsp[0]);
				 e->setFirstOperand(left);
				 e->setSecondOperand(right);
				 (yyval)=e;;}
    break;

  case 87:
#line 309 "ffscript.ypp"
    {(yyval)=(yyvsp[0]);;}
    break;

  case 88:
#line 312 "ffscript.ypp"
    {ASTBitExpr *e = new ASTExprBitOr((yylsp[-1]));
							  ASTExpr *left = (ASTExpr *)(yyvsp[-2]);
							  ASTExpr *right = (ASTExpr *)(yyvsp[0]);
							  e->setFirstOperand(left);
							  e->setSecondOperand(right);
							  (yyval)=e;;}
    break;

  case 89:
#line 318 "ffscript.ypp"
    {(yyval)=(yyvsp[0]);;}
    break;

  case 90:
#line 321 "ffscript.ypp"
    {ASTBitExpr *e = new ASTExprBitXor((yylsp[-1]));
							   ASTExpr *left = (ASTExpr *)(yyvsp[-2]);
							   ASTExpr *right = (ASTExpr *)(yyvsp[0]);
							   e->setFirstOperand(left);
							   e->setSecondOperand(right);
							   (yyval)=e;;}
    break;

  case 91:
#line 327 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 92:
#line 330 "ffscript.ypp"
    {ASTBitExpr *e = new ASTExprBitAnd((yylsp[-1]));
							   ASTExpr *left = (ASTExpr *)(yyvsp[-2]);
							   ASTExpr *right = (ASTExpr *)(yyvsp[0]);
							   e->setFirstOperand(left);
							   e->setSecondOperand(right);
							   (yyval)=e;;}
    break;

  case 93:
#line 336 "ffscript.ypp"
    {(yyval)=(yyvsp[0]);;}
    break;

  case 94:
#line 339 "ffscript.ypp"
    {ASTRelExpr *e = (ASTRelExpr *)(yyvsp[-1]);
				   ASTExpr *left = (ASTExpr *)(yyvsp[-2]);
				   ASTExpr *right = (ASTExpr *)(yyvsp[0]);
				   e->setFirstOperand(left);
				   e->setSecondOperand(right);
				   (yyval)=e;;}
    break;

  case 95:
#line 345 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 96:
#line 348 "ffscript.ypp"
    {ASTShiftExpr *e = (ASTShiftExpr *)(yyvsp[-1]);
							   ASTExpr *left = (ASTExpr *)(yyvsp[-2]);
							   ASTExpr *right = (ASTExpr *)(yyvsp[0]);
							   e->setFirstOperand(left);
							   e->setSecondOperand(right);
							   (yyval)=e;;}
    break;

  case 97:
#line 354 "ffscript.ypp"
    {(yyval)=(yyvsp[0]);;}
    break;

  case 98:
#line 357 "ffscript.ypp"
    {(yyval) = new ASTExprLShift((yylsp[0]));;}
    break;

  case 99:
#line 358 "ffscript.ypp"
    {(yyval) = new ASTExprRShift((yylsp[0]));;}
    break;

  case 100:
#line 361 "ffscript.ypp"
    {(yyval) = new ASTExprGT((yylsp[0]));;}
    break;

  case 101:
#line 362 "ffscript.ypp"
    {(yyval) = new ASTExprGE((yylsp[0]));;}
    break;

  case 102:
#line 363 "ffscript.ypp"
    {(yyval) = new ASTExprLT((yylsp[0]));;}
    break;

  case 103:
#line 364 "ffscript.ypp"
    {(yyval) = new ASTExprLE((yylsp[0]));;}
    break;

  case 104:
#line 365 "ffscript.ypp"
    {(yyval) = new ASTExprEQ((yylsp[0]));;}
    break;

  case 105:
#line 366 "ffscript.ypp"
    {(yyval) = new ASTExprNE((yylsp[0]));;}
    break;

  case 106:
#line 369 "ffscript.ypp"
    {ASTAddExpr *e = (ASTAddExpr *)(yyvsp[-1]);
				   ASTExpr *left = (ASTExpr *)(yyvsp[-2]);
				   ASTExpr *right = (ASTExpr *)(yyvsp[0]);
				   e->setFirstOperand(left);
				   e->setSecondOperand(right);
				   (yyval)=e;;}
    break;

  case 107:
#line 375 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 108:
#line 378 "ffscript.ypp"
    {(yyval) = new ASTExprPlus((yylsp[0]));;}
    break;

  case 109:
#line 379 "ffscript.ypp"
    {(yyval) = new ASTExprMinus((yylsp[0]));;}
    break;

  case 110:
#line 382 "ffscript.ypp"
    {ASTMultExpr *e = (ASTMultExpr *)(yyvsp[-1]);
				    ASTExpr *left = (ASTExpr *)(yyvsp[-2]);
				    ASTExpr *right = (ASTExpr *)(yyvsp[0]);
				    e->setFirstOperand(left);
				    e->setSecondOperand(right);
				    (yyval)=e;;}
    break;

  case 111:
#line 388 "ffscript.ypp"
    {(yyval)=(yyvsp[0]);;}
    break;

  case 112:
#line 391 "ffscript.ypp"
    {(yyval) = new ASTExprTimes((yylsp[0]));;}
    break;

  case 113:
#line 392 "ffscript.ypp"
    {(yyval) = new ASTExprDivide((yylsp[0]));;}
    break;

  case 114:
#line 393 "ffscript.ypp"
    {(yyval) = new ASTExprModulo((yylsp[0]));;}
    break;

  case 115:
#line 396 "ffscript.ypp"
    {ASTUnaryExpr *e = new ASTExprNot((yylsp[-1]));
			 ASTExpr *op = (ASTExpr *)(yyvsp[0]);
			 e->setOperand(op);
			 (yyval)=e;;}
    break;

  case 116:
#line 400 "ffscript.ypp"
    {ASTUnaryExpr *e = new ASTExprNegate((yylsp[-1]));
			   ASTExpr *op = (ASTExpr *)(yyvsp[0]);
			   e->setOperand(op);
			   (yyval)=e;;}
    break;

  case 117:
#line 404 "ffscript.ypp"
    {ASTUnaryExpr *e = new ASTExprBitNot((yylsp[-1]));
					ASTExpr *op = (ASTExpr *)(yyvsp[0]);
					e->setOperand(op);
					(yyval)=e;;}
    break;

  case 118:
#line 408 "ffscript.ypp"
    {(yyval)=(yyvsp[0]);;}
    break;

  case 119:
#line 411 "ffscript.ypp"
    {(yyval)=(yyvsp[-1]);;}
    break;

  case 120:
#line 412 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 121:
#line 413 "ffscript.ypp"
    {ASTUnaryExpr *e = new ASTExprIncrement((yylsp[0]));
						 ASTExpr *op = (ASTExpr *)(yyvsp[-1]);
						 e->setOperand(op);
						 (yyval)=e;;}
    break;

  case 122:
#line 417 "ffscript.ypp"
    {ASTUnaryExpr *e = new ASTExprDecrement((yylsp[0]));
						 ASTExpr *op = (ASTExpr *)(yyvsp[-1]);
						 e->setOperand(op);
						 (yyval)=e;;}
    break;

  case 123:
#line 421 "ffscript.ypp"
    {ASTFloat *val = (ASTFloat *)(yyvsp[0]);
		    (yyval) = new ASTNumConstant(val,(yylsp[0]));;}
    break;

  case 124:
#line 423 "ffscript.ypp"
    {(yyval) = (yyvsp[0]);;}
    break;

  case 125:
#line 424 "ffscript.ypp"
    {(yyval)=(yyvsp[0]);;}
    break;

  case 126:
#line 427 "ffscript.ypp"
    {(yyval) = new ASTBoolConstant(true,(yylsp[0]));;}
    break;

  case 127:
#line 428 "ffscript.ypp"
    {(yyval) = new ASTBoolConstant(false,(yylsp[0]));;}
    break;

  case 128:
#line 431 "ffscript.ypp"
    {ASTFuncCall *fc = (ASTFuncCall *)(yyvsp[-1]);
							    ASTExpr *name = (ASTExpr *)(yyvsp[-3]);
							    fc->setName(name);
							    (yyval)=fc;;}
    break;

  case 129:
#line 435 "ffscript.ypp"
    {ASTFuncCall *fc = new ASTFuncCall((yylsp[-2]));
					    ASTExpr *name = (ASTExpr *)(yyvsp[-2]);
					    fc->setName(name);
					    (yyval)=fc;;}
    break;

  case 130:
#line 441 "ffscript.ypp"
    {ASTFuncCall *fc = (ASTFuncCall *)(yyvsp[0]);
					  ASTExpr *e = (ASTExpr *)(yyvsp[-2]);
					  fc->addParam(e);
					  (yyval) = fc;;}
    break;

  case 131:
#line 445 "ffscript.ypp"
    {ASTFuncCall *fc = new ASTFuncCall((yylsp[0]));
		  ASTExpr *e = (ASTExpr *)(yyvsp[0]);
		  fc->addParam(e);
		  (yyval) = fc;;}
    break;

  case 132:
#line 451 "ffscript.ypp"
    {ASTStmt *prec = (ASTStmt *)(yyvsp[-6]);
												ASTExpr *term = (ASTExpr *)(yyvsp[-4]);
												ASTStmt *incr = (ASTExpr *)(yyvsp[-2]);
												ASTStmt *stmt = (ASTStmt *)(yyvsp[0]);
												(yyval) = new ASTStmtFor(prec,term,incr,stmt,(yylsp[-8]));;}
    break;

  case 133:
#line 458 "ffscript.ypp"
    {ASTExpr *cond = (ASTExpr *)(yyvsp[-2]);
										   ASTStmt *stmt = (ASTStmt *)(yyvsp[0]);
										   (yyval) = new ASTStmtWhile(cond,stmt,(yylsp[-4]));;}
    break;

  case 134:
#line 462 "ffscript.ypp"
    {ASTExpr *cond = (ASTExpr *)(yyvsp[-1]);
										   ASTStmt *stmt = (ASTStmt *)(yyvsp[-4]);
										   (yyval) = new ASTStmtDo(cond,stmt,(yylsp[-5]));;}
    break;

  case 135:
#line 466 "ffscript.ypp"
    {ASTExpr *cond = (ASTExpr *)(yyvsp[-2]);
							  ASTStmt *stmt = (ASTStmt *)(yyvsp[0]);
							  (yyval) = new ASTStmtIf(cond,stmt,(yylsp[-4]));;}
    break;

  case 136:
#line 469 "ffscript.ypp"
    {ASTExpr *cond = (ASTExpr *)(yyvsp[-4]);
										ASTStmt *ifstmt = (ASTStmt *)(yyvsp[-2]);
										ASTStmt *elsestmt = (ASTStmt *)(yyvsp[0]);
										(yyval) = new ASTStmtIfElse(cond,ifstmt,elsestmt,(yylsp[-6]));;}
    break;

  case 137:
#line 475 "ffscript.ypp"
    {(yyval) = new ASTStmtReturnVal((ASTExpr *)(yyvsp[0]),(yylsp[-1]));;}
    break;

  case 138:
#line 476 "ffscript.ypp"
    {(yyval) = new ASTStmtReturn((yylsp[0]));;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 2392 "y.tab.cpp"

  yyvsp -= yylen;
  yyssp -= yylen;
  yylsp -= yylen;

  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
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
	  int yychecklim = YYLAST - yyn;
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
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
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
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }

  yyerror_range[0] = yylloc;

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
	  yydestruct ("Error: discarding", yytoken, &yylval, &yylloc);
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
  if (0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  yylsp -= yylen;
  yyvsp -= yylen;
  yyssp -= yylen;
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping", yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though. */
  YYLLOC_DEFAULT (yyloc, yyerror_range - 1, 2);
  *++yylsp = yyloc;

  /* Shift the error token. */
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
		 yytoken, &yylval, &yylloc);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 479 "ffscript.ypp"


/*        programs */
		
void yyerror(const char *s) {
	char temp[512];
    sprintf(temp, "line %d: %s, on token %s", yylineno, s, yytext);
    box_out(temp);
    box_eol();
}

int go(const char *f)
{
yyin = NULL;
resetLexer();
yyin = fopen(f, "r");
if(!yyin)
{
	box_out("Can't open input file");
	box_eol();
	return -1;
}
	curfilename = string(f);
	int result = yyparse();
	fclose(yyin);
	return result;
}

