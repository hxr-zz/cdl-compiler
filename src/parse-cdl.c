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

/* Substitute the variable and function names.  */
#define yyparse gram_parse
#define yylex   gram_lex
#define yyerror gram_error
#define yylval  gram_lval
#define yychar  gram_char
#define yydebug gram_debug
#define yynerrs gram_nerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DATE = 258,
     UTCDATE = 259,
     TAIDATE = 260,
     CLASS = 261,
     ENUM = 262,
     ACCURACY = 263,
     YEAR = 264,
     MONTH = 265,
     VECTOR = 266,
     TYPEDEF = 267,
     RANGE = 268,
     CERTIFICATE = 269,
     CERTIFICATEHEADER = 270,
     OF = 271,
     WCHAR = 272,
     CHAR = 273,
     ARRAY = 274,
     UNION = 275,
     FLOAT32 = 276,
     FLOAT64 = 277,
     ERROR = 278,
     ADT = 279,
     ID = 280,
     INTX = 281,
     UINTX = 282,
     FILENAME = 283,
     DECIMALD = 284,
     NUMBER = 285,
     FRACTION = 286,
     SEMICOLON = 287,
     COMMA = 288,
     LPAREN = 289,
     RPAREN = 290,
     LSQ = 291,
     RSQ = 292,
     DOTDOT = 293,
     EQUALS = 294,
     COLON = 295,
     LBRACE = 296,
     RBRACE = 297,
     GT = 298,
     LT = 299,
     FWSLASH = 300
   };
#endif
/* Tokens.  */
#define DATE 258
#define UTCDATE 259
#define TAIDATE 260
#define CLASS 261
#define ENUM 262
#define ACCURACY 263
#define YEAR 264
#define MONTH 265
#define VECTOR 266
#define TYPEDEF 267
#define RANGE 268
#define CERTIFICATE 269
#define CERTIFICATEHEADER 270
#define OF 271
#define WCHAR 272
#define CHAR 273
#define ARRAY 274
#define UNION 275
#define FLOAT32 276
#define FLOAT64 277
#define ERROR 278
#define ADT 279
#define ID 280
#define INTX 281
#define UINTX 282
#define FILENAME 283
#define DECIMALD 284
#define NUMBER 285
#define FRACTION 286
#define SEMICOLON 287
#define COMMA 288
#define LPAREN 289
#define RPAREN 290
#define LSQ 291
#define RSQ 292
#define DOTDOT 293
#define EQUALS 294
#define COLON 295
#define LBRACE 296
#define RBRACE 297
#define GT 298
#define LT 299
#define FWSLASH 300




/* Copy the first part of user declarations.  */
#line 1 "parse-cdl.y"
/* CDL Grammar parser.                    -*- C -*-
** Copyright (C) 2007 Satya Kiran Popuri <spopur2@uic.edu>
**  
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**  
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**  
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
**  
*/

# include <stdio.h>
# include <libgen.h>
# include <string>
# include <list>
# include "CDLType.h"
# include "SymbolTable.h"
# include "Constraints.h"
# include "Codegen.h"
# include <integer.h>
# include <sha.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sstream>
# include <unistd.h>
# include <time.h>
# include <stdlib.h>
# include <sstream>
# include <ctime>

using namespace std;

extern "C"
{
    int gram_parse ( void );
    void gram_error ( char* );
}

 extern int gram_lex();
 extern void initLex(string& );
 
 extern int gram_lineno;
 
 SymbolTable symtab;

 string to_str( int );
 std::string computeHash(string file);
 void parse_args ( int argc, char **argv);
 void preprocess ();
 void getTime ();
 
 static const char *arg_string = "s:o:t:";
 
 // This global switch is checked by the parser.
 static bool semantic_file_set = false;
 static bool output_file_set = false;
 static bool template_file_set = false;

 static string output_file("");
 static string semantic_file("");
 static string template_file("");
 static string input_file("");
 static string preproc_file("");

 string curYear  = "";
 string curMonth = "";


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
#line 81 "parse-cdl.y"
{
  CDLType *ctype;
  string  *sVal;
  int      iVal;
  float    fVal;
  list<string> *enumList;   // for enumerations
  SymbolHashtable *table;   // Symbol table for composite types
  Constraints *constr;      // for constraints
}
/* Line 187 of yacc.c.  */
#line 280 "parse-cdl.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 293 "parse-cdl.c"

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    21,
      28,    29,    30,    40,    41,    42,    52,    55,    57,    62,
      67,    74,    78,    80,    82,    84,    86,    88,    90,    92,
      94,    96,    98,   102,   106,   111,   113,   115,   117,   119,
     124,   128,   130,   132,   134,   136,   138,   140,   141,   142,
     149,   150,   151,   159,   162,   164,   169,   171,   175,   177,
     179,   183,   187,   193,   199,   206,   213,   221,   229,   236,
     243,   247,   251,   256,   261,   266
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    48,    49,    -1,    49,    -1,
      50,    -1,    51,    -1,    54,    -1,    25,    40,    59,    32,
      -1,    25,    40,    24,    33,    77,    32,    -1,    -1,    -1,
      15,    40,     6,    41,    52,    57,    53,    42,    32,    -1,
      -1,    -1,    25,    40,    14,    41,    55,    57,    56,    42,
      32,    -1,    57,    58,    -1,    58,    -1,    25,    40,    59,
      32,    -1,    25,    40,    24,    32,    -1,    25,    40,    24,
      33,    77,    32,    -1,    59,    33,    77,    -1,    60,    -1,
      61,    -1,    62,    -1,    70,    -1,    65,    -1,    63,    -1,
      64,    -1,    67,    -1,    68,    -1,    69,    -1,    11,    16,
      60,    -1,    11,    16,    24,    -1,    60,    36,    30,    37,
      -1,    26,    -1,    27,    -1,    18,    -1,    17,    -1,     7,
      41,    66,    42,    -1,    66,    33,    25,    -1,    25,    -1,
      29,    -1,    21,    -1,    22,    -1,     3,    -1,     4,    -1,
      -1,    -1,     6,    41,    71,    57,    72,    42,    -1,    -1,
      -1,    24,     6,    41,    73,    75,    74,    42,    -1,    75,
      76,    -1,    76,    -1,    25,    40,    77,    32,    -1,    58,
      -1,    78,    33,    79,    -1,    78,    -1,    79,    -1,    13,
      39,    80,    -1,    13,    39,    30,    -1,    13,    39,    30,
      38,    30,    -1,    13,    39,    80,    38,    80,    -1,    13,
      39,    43,    30,    38,    30,    -1,    13,    39,    43,    80,
      38,    80,    -1,    13,    39,    43,    30,    38,    44,    30,
      -1,    13,    39,    43,    80,    38,    44,    80,    -1,    13,
      39,    30,    38,    44,    30,    -1,    13,    39,    80,    38,
      44,    80,    -1,    13,    39,    25,    -1,     8,    39,    31,
      -1,     9,    34,    30,    35,    -1,    10,    34,    30,    35,
      -1,     3,    34,    30,    35,    -1,    30,    45,    30,    45,
      30,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   135,   135,   140,   141,   144,   145,   146,   149,   155,
     162,   162,   162,   172,   172,   172,   188,   190,   194,   197,
     200,   204,   205,   206,   207,   208,   209,   212,   213,   214,
     215,   216,   219,   220,   223,   226,   235,   244,   249,   255,
     262,   267,   275,   284,   285,   288,   289,   291,   291,   291,
     296,   296,   296,   305,   307,   311,   319,   321,   323,   324,
     327,   330,   334,   339,   344,   349,   354,   359,   364,   369,
     374,   378,   383,   386,   389,   392
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DATE", "UTCDATE", "TAIDATE", "CLASS",
  "ENUM", "ACCURACY", "YEAR", "MONTH", "VECTOR", "TYPEDEF", "RANGE",
  "CERTIFICATE", "CERTIFICATEHEADER", "OF", "WCHAR", "CHAR", "ARRAY",
  "UNION", "FLOAT32", "FLOAT64", "ERROR", "ADT", "ID", "INTX", "UINTX",
  "FILENAME", "DECIMALD", "NUMBER", "FRACTION", "\";\"", "\",\"", "\"(\"",
  "\")\"", "\"[\"", "\"]\"", "DOTDOT", "\"=\"", "\":\"", "\"{\"", "\"}\"",
  "\">\"", "\"<\"", "\"/\"", "$accept", "Certificate_Description",
  "Declarations", "Declaration", "ADT_Declaration",
  "CertificateHeader_Declaration", "@1", "@2", "Certificate_Declaration",
  "@3", "@4", "Field_Declarations", "Field_Declaration", "Base_Type",
  "Scalar_Type", "Vector_Type", "Array_Type", "Int_Type", "Char_Type",
  "Enum_Type", "Id_List", "Decimal_Type", "Float_Type", "Date_Type",
  "Class_Type", "@5", "@6", "@7", "@8", "Field_Redefs", "Field_Redef",
  "Constraints", "Range", "Accuracy", "Date_Bound", 0
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
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    50,    50,
      52,    53,    51,    55,    56,    54,    57,    57,    58,    58,
      58,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    61,    61,    62,    63,    63,    64,    64,    65,
      66,    66,    67,    68,    68,    69,    69,    71,    72,    70,
      73,    74,    70,    75,    75,    76,    76,    77,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    80,    80,    80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     4,     6,
       0,     0,     9,     0,     0,     9,     2,     1,     4,     4,
       6,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     1,     1,     1,     1,     4,
       3,     1,     1,     1,     1,     1,     1,     0,     0,     6,
       0,     0,     7,     2,     1,     4,     1,     3,     1,     1,
       3,     3,     5,     5,     6,     6,     7,     7,     6,     6,
       3,     3,     4,     4,     4,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,     5,     6,     7,     0,
       0,     1,     3,     0,    45,    46,     0,     0,     0,     0,
      38,    37,    43,    44,     0,    35,    36,    42,     0,    22,
      23,    24,    27,    28,    26,    29,    30,    31,    25,    10,
      47,     0,     0,    13,     0,     0,     8,     0,     0,     0,
       0,    41,     0,    33,    32,     0,    50,     0,     0,     0,
      58,    59,    21,     0,     0,    11,    17,    48,     0,    39,
      14,     0,     0,     0,     9,     0,    34,     0,     0,    16,
       0,    40,     0,     0,    56,    51,    54,    71,     0,     0,
       0,    70,    61,     0,    60,    57,     0,     0,     0,    49,
       0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,    18,    12,    15,     0,    52,     0,
       0,     0,    62,     0,     0,     0,     0,     0,     0,    63,
       0,    55,    74,    72,    73,    68,     0,    64,     0,     0,
      65,    69,    20,    75,    66,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,    49,    78,     8,    55,
      82,    65,    66,    97,    29,    30,    31,    32,    33,    34,
      52,    35,    36,    37,    38,    50,    80,    71,   102,    85,
      86,    59,    60,    61,    94
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -93
static const yytype_int16 yypact[] =
{
     -10,    -2,    13,    62,   -10,   -93,   -93,   -93,   -93,    58,
      79,   -93,   -93,    26,   -93,   -93,    30,    31,    59,    36,
     -93,   -93,   -93,   -93,    -3,   -93,   -93,   -93,    -6,    44,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,    63,   122,   -93,    43,    27,   -93,    27,    57,    64,
      64,   -93,   -26,   -93,   -93,    64,   -93,    53,    55,    66,
      69,   -93,   -93,    54,    67,    64,   -93,    64,    70,   -93,
      64,    74,    73,     3,   -93,   103,   -93,   106,    76,   -93,
      80,   -93,    87,    75,   -93,    74,   -93,   -93,    97,   102,
     104,   -93,    12,    11,    83,   -93,    16,    19,   105,   -93,
     109,    52,   100,   -93,   115,   117,   120,   -12,   123,    23,
     114,    -1,   -93,    27,   -93,   -93,   -93,   124,   -93,   119,
     125,   126,   -93,   127,   110,    -5,     1,   113,    14,   -93,
     130,   -93,   -93,   -93,   -93,   -93,   129,   -93,   133,    14,
     -93,   -93,   -93,   -93,   -93,   -93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -93,   160,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -13,    49,   155,   128,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
      81,   -47,   -93,    92,   -92
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      62,   110,    88,    44,    88,     1,    88,    68,    89,    90,
      89,    90,    89,    90,    88,     2,    69,    88,   122,   129,
      89,    90,    44,    89,    90,   137,    46,    47,    91,   127,
      45,   127,   123,    92,   140,    57,   141,    67,     9,   138,
      58,   109,    70,   128,   127,   139,    93,   145,   112,   113,
     107,   114,    47,    10,   117,    14,    15,   108,    16,    17,
      57,   125,    11,    18,    13,    58,   130,    39,   108,    20,
      21,    40,    41,    22,    23,    42,    96,    43,    25,    26,
      48,    27,    14,    15,    56,    16,    17,    63,    51,    64,
      18,    76,    72,    19,    73,    81,    20,    21,    74,    83,
      22,    23,    75,    24,    87,    25,    26,    77,    27,    14,
      15,    57,    16,    17,    79,   101,    79,    18,    98,    79,
      84,   111,    99,    20,    21,    14,    15,    22,    23,   100,
      96,   104,    25,    26,    84,    27,   105,   115,   106,    20,
      21,   116,   118,    22,    23,   119,    53,   120,    25,    26,
     121,    27,   126,   124,   132,   136,   131,   135,   108,   143,
     133,   134,   142,   144,    12,    28,   103,    95,     0,     0,
      54
};

static const yytype_int16 yycheck[] =
{
      47,    93,     3,     6,     3,    15,     3,    33,     9,    10,
       9,    10,     9,    10,     3,    25,    42,     3,    30,   111,
       9,    10,     6,     9,    10,    30,    32,    33,    25,    30,
      33,    30,    44,    30,   126,     8,   128,    50,    40,    44,
      13,    30,    55,    44,    30,    44,    43,   139,    32,    33,
      38,    32,    33,    40,   101,     3,     4,    45,     6,     7,
       8,    38,     0,    11,     6,    13,   113,    41,    45,    17,
      18,    41,    41,    21,    22,    16,    24,    41,    26,    27,
      36,    29,     3,     4,    41,     6,     7,    30,    25,    25,
      11,    37,    39,    14,    39,    25,    17,    18,    32,    25,
      21,    22,    33,    24,    31,    26,    27,    40,    29,     3,
       4,     8,     6,     7,    65,    40,    67,    11,    42,    70,
      71,    38,    42,    17,    18,     3,     4,    21,    22,    42,
      24,    34,    26,    27,    85,    29,    34,    32,    34,    17,
      18,    32,    42,    21,    22,    30,    24,    30,    26,    27,
      30,    29,    38,    30,    35,    45,    32,    30,    45,    30,
      35,    35,    32,    30,     4,    10,    85,    75,    -1,    -1,
      42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    25,    47,    48,    49,    50,    51,    54,    40,
      40,     0,    49,     6,     3,     4,     6,     7,    11,    14,
      17,    18,    21,    22,    24,    26,    27,    29,    59,    60,
      61,    62,    63,    64,    65,    67,    68,    69,    70,    41,
      41,    41,    16,    41,     6,    33,    32,    33,    36,    52,
      71,    25,    66,    24,    60,    55,    41,     8,    13,    77,
      78,    79,    77,    30,    25,    57,    58,    57,    33,    42,
      57,    73,    39,    39,    32,    33,    37,    40,    53,    58,
      72,    25,    56,    25,    58,    75,    76,    31,     3,     9,
      10,    25,    30,    43,    80,    79,    24,    59,    42,    42,
      42,    40,    74,    76,    34,    34,    34,    38,    45,    30,
      80,    38,    32,    33,    32,    32,    32,    77,    42,    30,
      30,    30,    30,    44,    30,    38,    38,    30,    44,    80,
      77,    32,    35,    35,    35,    30,    45,    30,    44,    44,
      80,    80,    32,    30,    30,    80
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
#line 136 "parse-cdl.y"
    {
			 }
    break;

  case 8:
#line 150 "parse-cdl.y"
    { /* ID will be installed as ADT in the symbol table */  
		    (yyvsp[(3) - (4)].ctype)->setADT(true);
  		    symtab.install((yyvsp[(1) - (4)].sVal),(yyvsp[(3) - (4)].ctype),gram_lineno);
		 }
    break;

  case 9:
#line 156 "parse-cdl.y"
    {
		    (yyvsp[(3) - (6)].ctype)->setConstraints((yyvsp[(5) - (6)].constr)); 	    /* set constraints for the ADT type */
		    symtab.install((yyvsp[(1) - (6)].sVal),(yyvsp[(3) - (6)].ctype),gram_lineno); /* Install the ADT symbol */
		 }
    break;

  case 10:
#line 162 "parse-cdl.y"
    { symtab.enterScope(); }
    break;

  case 11:
#line 162 "parse-cdl.y"
    { symtab.leaveScope(); }
    break;

  case 12:
#line 163 "parse-cdl.y"
    {
				  CDLType *ht = new CDLType(CDLType::ctClass);
				  ht->setTable((yyvsp[(6) - (9)].table));
				  
			       	  // Install this in the symbol table
				  symtab.install(new string("CertificateHeader"),ht,gram_lineno);
			       }
    break;

  case 13:
#line 172 "parse-cdl.y"
    { symtab.enterScope(); }
    break;

  case 14:
#line 172 "parse-cdl.y"
    { symtab.leaveScope(); }
    break;

  case 15:
#line 173 "parse-cdl.y"
    {
			   // check if a semantic definition file is supplied.
			   if (!semantic_file_set)
			     {
			       cerr<<"This CDL contains a Certificate definiton, but a semantic definition file was not supplied. Please use the -s switch  to name one."<<endl;
			       exit(1);
			     }
			   CDLType *ht = new CDLType(CDLType::ctClass);
			   ht->setTable((yyvsp[(6) - (9)].table));
			   ht->setCertificateFlag();

			   symtab.install((yyvsp[(1) - (9)].sVal),ht,gram_lineno);
			 }
    break;

  case 16:
#line 189 "parse-cdl.y"
    { (yyval.table) = symtab.getCurrentTable(); }
    break;

  case 17:
#line 191 "parse-cdl.y"
    { (yyval.table) = symtab.getCurrentTable(); }
    break;

  case 18:
#line 195 "parse-cdl.y"
    { symtab.install((yyvsp[(1) - (4)].sVal),(yyvsp[(3) - (4)].ctype),gram_lineno);}
    break;

  case 19:
#line 198 "parse-cdl.y"
    { symtab.install((yyvsp[(1) - (4)].sVal),(yyvsp[(3) - (4)].ctype),gram_lineno); }
    break;

  case 20:
#line 201 "parse-cdl.y"
    { (yyvsp[(3) - (6)].ctype)->setConstraints((yyvsp[(5) - (6)].constr)); symtab.install((yyvsp[(1) - (6)].sVal),(yyvsp[(3) - (6)].ctype),gram_lineno); }
    break;

  case 21:
#line 204 "parse-cdl.y"
    { (yyvsp[(1) - (3)].ctype)->setConstraints((yyvsp[(3) - (3)].constr)); (yyval.ctype)=(yyvsp[(1) - (3)].ctype); }
    break;

  case 32:
#line 219 "parse-cdl.y"
    { (yyval.ctype) = (yyvsp[(3) - (3)].ctype); (yyval.ctype)->setVector(true); }
    break;

  case 33:
#line 220 "parse-cdl.y"
    { (yyval.ctype)=(yyvsp[(3) - (3)].ctype);  (yyval.ctype)->setADTvector(true);}
    break;

  case 34:
#line 223 "parse-cdl.y"
    { (yyvsp[(1) - (4)].ctype)->setDimension((yyvsp[(3) - (4)].iVal)); (yyval.ctype)=(yyvsp[(1) - (4)].ctype); }
    break;

  case 35:
#line 227 "parse-cdl.y"
    {
	    /* Extract size from INTX */
	    (yyval.ctype) = new CDLType(CDLType::stIntx);
	    (yyvsp[(1) - (1)].sVal)->erase(0,3); 	/* Erase the int part */
	    int sz = atoi((yyvsp[(1) - (1)].sVal)->c_str());
	    (yyval.ctype)->setBitSize(sz);
	  }
    break;

  case 36:
#line 236 "parse-cdl.y"
    {
	    (yyvsp[(1) - (1)].sVal)->erase(0,4);
	    int sz = atoi((yyvsp[(1) - (1)].sVal)->c_str());
	    (yyval.ctype) = new CDLType(CDLType::stUintx);
	    (yyval.ctype)->setBitSize(sz);
	  }
    break;

  case 37:
#line 245 "parse-cdl.y"
    {
	     (yyval.ctype) = new CDLType(CDLType::stChar);
	   }
    break;

  case 38:
#line 250 "parse-cdl.y"
    {
	     (yyval.ctype) = new CDLType(CDLType::stWchar);
	   }
    break;

  case 39:
#line 256 "parse-cdl.y"
    {
	     (yyval.ctype) = new CDLType(CDLType::mtEnum);
	     (yyval.ctype)->setEnumList((yyvsp[(3) - (4)].enumList));
	   }
    break;

  case 40:
#line 263 "parse-cdl.y"
    {
	   string s((yyvsp[(3) - (3)].sVal)->c_str());
	   (yyval.enumList)->push_front(s);
	 }
    break;

  case 41:
#line 268 "parse-cdl.y"
    {
	   (yyval.enumList) = new list<string>();
	   string s((yyvsp[(1) - (1)].sVal)->c_str());
	   (yyval.enumList)->push_front(s);
	 }
    break;

  case 42:
#line 276 "parse-cdl.y"
    {
	       (yyvsp[(1) - (1)].sVal)->erase(0,12);
	       int sz = atoi((yyvsp[(1) - (1)].sVal)->c_str());
	       (yyval.ctype) = new CDLType(CDLType::stDecimald); 
	       (yyval.ctype)->setBitSize(sz);
	     }
    break;

  case 43:
#line 284 "parse-cdl.y"
    {(yyval.ctype) = new CDLType(CDLType::stFloat32); }
    break;

  case 44:
#line 285 "parse-cdl.y"
    {(yyval.ctype) = new CDLType(CDLType::stFloat64); }
    break;

  case 45:
#line 288 "parse-cdl.y"
    { (yyval.ctype) = new CDLType(CDLType::stDate); }
    break;

  case 46:
#line 289 "parse-cdl.y"
    { (yyval.ctype) = new CDLType(CDLType::stUtcDate);}
    break;

  case 47:
#line 291 "parse-cdl.y"
    { symtab.enterScope(); }
    break;

  case 48:
#line 291 "parse-cdl.y"
    { symtab.leaveScope(); }
    break;

  case 49:
#line 292 "parse-cdl.y"
    { (yyval.ctype) = new CDLType(CDLType::ctClass); 
	      (yyval.ctype)->setTable((yyvsp[(4) - (6)].table));
	    }
    break;

  case 50:
#line 296 "parse-cdl.y"
    { symtab.enterScope(); }
    break;

  case 51:
#line 296 "parse-cdl.y"
    {symtab.leaveScope(); }
    break;

  case 52:
#line 297 "parse-cdl.y"
    { 
	      (yyval.ctype) = new CDLType(CDLType::ctDerivedClass); 
	      (yyval.ctype)->setTable((yyvsp[(5) - (7)].table));
	      (yyval.ctype)->setBaseType((yyvsp[(1) - (7)].ctype));
	      (yyval.ctype)->setBaseName((yyvsp[(1) - (7)].ctype)->getBaseName());
	    }
    break;

  case 53:
#line 306 "parse-cdl.y"
    { (yyval.table) = symtab.getCurrentTable(); }
    break;

  case 54:
#line 308 "parse-cdl.y"
    { (yyval.table) = symtab.getCurrentTable(); }
    break;

  case 55:
#line 312 "parse-cdl.y"
    {
		// Create a dummy CDL type to hold the constraints.
		CDLType *dt = new CDLType(CDLType::mtDummy);
		dt->setConstraints((yyvsp[(3) - (4)].constr));
		
		symtab.install((yyvsp[(1) - (4)].sVal),dt,gram_lineno);
	     }
    break;

  case 57:
#line 322 "parse-cdl.y"
    { (yyvsp[(1) - (3)].constr)->setAccuracy((yyvsp[(3) - (3)].constr)->getAccuracy()); (yyval.constr)=(yyvsp[(1) - (3)].constr);}
    break;

  case 60:
#line 327 "parse-cdl.y"
    { (yyval.constr) = new Constraints(Constraints::fixed);
                              (yyval.constr)->setLeftp((yyvsp[(3) - (3)].sVal));
                            }
    break;

  case 61:
#line 330 "parse-cdl.y"
    { (yyval.constr)=new Constraints(Constraints::fixed);
     			  (yyval.constr)->setLeft(to_str((yyvsp[(3) - (3)].iVal)));
			}
    break;

  case 62:
#line 335 "parse-cdl.y"
    { (yyval.constr) = new Constraints(Constraints::open_range);
         (yyval.constr)->setLeft(to_str((yyvsp[(3) - (5)].iVal))); (yyval.constr)->setRight(to_str((yyvsp[(5) - (5)].iVal)));
       }
    break;

  case 63:
#line 340 "parse-cdl.y"
    { (yyval.constr) = new Constraints(Constraints::open_range);
         (yyval.constr)->setLeftp((yyvsp[(3) - (5)].sVal)); (yyval.constr)->setRightp((yyvsp[(5) - (5)].sVal));
       }
    break;

  case 64:
#line 345 "parse-cdl.y"
    { (yyval.constr) = new Constraints(Constraints::left_close_right_open_range);
         (yyval.constr)->setLeft(to_str((yyvsp[(4) - (6)].iVal))); (yyval.constr)->setRight(to_str((yyvsp[(6) - (6)].iVal)));
       }
    break;

  case 65:
#line 350 "parse-cdl.y"
    { (yyval.constr)=new Constraints(Constraints::left_close_right_open_range);
         (yyval.constr)->setLeftp((yyvsp[(4) - (6)].sVal)); (yyval.constr)->setRightp((yyvsp[(6) - (6)].sVal));
       }
    break;

  case 66:
#line 355 "parse-cdl.y"
    { (yyval.constr)=new Constraints(Constraints::closed_range);
         (yyval.constr)->setLeft(to_str((yyvsp[(4) - (7)].iVal))); (yyval.constr)->setRight(to_str((yyvsp[(7) - (7)].iVal)));
       }
    break;

  case 67:
#line 360 "parse-cdl.y"
    { (yyval.constr)=new Constraints(Constraints::closed_range);
         (yyval.constr)->setLeftp((yyvsp[(4) - (7)].sVal)); (yyval.constr)->setRightp((yyvsp[(7) - (7)].sVal));
       }
    break;

  case 68:
#line 365 "parse-cdl.y"
    { (yyval.constr)=new Constraints(Constraints::left_open_right_close_range);
         (yyval.constr)->setLeft(to_str((yyvsp[(3) - (6)].iVal))); (yyval.constr)->setRight(to_str((yyvsp[(6) - (6)].iVal)));
       }
    break;

  case 69:
#line 370 "parse-cdl.y"
    { (yyval.constr)=new Constraints(Constraints::left_open_right_close_range);
         (yyval.constr)->setLeftp((yyvsp[(3) - (6)].sVal)); (yyval.constr)->setRightp((yyvsp[(6) - (6)].sVal));
       }
    break;

  case 70:
#line 375 "parse-cdl.y"
    { (yyval.constr)=new Constraints(Constraints::fixed); (yyval.constr)->setLeftp((yyvsp[(3) - (3)].sVal)); }
    break;

  case 71:
#line 378 "parse-cdl.y"
    { (yyval.constr) = new Constraints(Constraints::accuracy); 
				  (yyval.constr)->setAccuracy((yyvsp[(3) - (3)].fVal)); 
				}
    break;

  case 72:
#line 384 "parse-cdl.y"
    { string t = "DateTime(1,1," + to_str((yyvsp[(3) - (4)].iVal)) + ")"; (yyval.sVal)=new string(t); }
    break;

  case 73:
#line 387 "parse-cdl.y"
    { string t = "DateTime(" + to_str((yyvsp[(3) - (4)].iVal)) + ",1," + curYear + ")"; (yyval.sVal)=new string(t); }
    break;

  case 74:
#line 390 "parse-cdl.y"
    { string t = "DateTime(" + curMonth + "," + to_str((yyvsp[(3) - (4)].iVal)) + "," + curYear + ")"; (yyval.sVal)=new string(t); }
    break;

  case 75:
#line 393 "parse-cdl.y"
    { 
	      string t = "DateTime(" + to_str((yyvsp[(1) - (5)].iVal)) + ","+ to_str((yyvsp[(3) - (5)].iVal))+ "," + to_str((yyvsp[(5) - (5)].iVal)) + ")"; (yyval.sVal)=new string(t); 
	    }
    break;


/* Line 1267 of yacc.c.  */
#line 2002 "parse-cdl.c"
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


#line 398 "parse-cdl.y"


//_____________________________________________________________________________
//  
// There was a syntax error! 
//_____________________________________________________________________________
void gram_error ( char* pCh )
{
  fprintf(stderr,"Parse error on line %d. Check syntax of your Certificate definition.\n", gram_lineno);
}

string
to_str(int i)
{
  char buf[1000];
  sprintf(buf,"%d",i);
  string s(buf);
  return s;
}

int 
main(int argc, char **argv)
{
  int token;
  parse_args(argc,argv);

  getTime (); 			// Find where we are in time.

  //preprocess the input file.
  preprocess();

  initLex(preproc_file); // initialize the lexer with the preprocessed input.

  if ( gram_parse() !=0 )
    exit(1);

  if (!template_file_set)
    {
      template_file += PKGDATADIR;
      template_file += "/cdl2cpp.tpl";
    }
  
  CodeGenerator cg ( template_file, input_file);

  cg.setSyntaxHash(computeHash(input_file));
  
  if ( semantic_file_set)
    cg.setSemanticHash(computeHash(semantic_file));

  if ( output_file_set)
    cg.setOutputFile ( output_file );
  
  cg.generateCode(&symtab);

  //clean up temp_file
  remove(preproc_file.c_str());
}

/* Computes the SHA512 hash of any given file */
string computeHash(string filename)
{
  typedef CryptoPP::SHA512 Sha512;
  byte *out;

  int fd = open ( filename.c_str(), O_RDONLY, 0);

  if ( fd < 0 )
    {
      cerr<<"computeHash: Error opening file - "<<filename;
      exit(1);
    }

  struct stat stats;

  if ( fstat ( fd, &stats ) < 0 )
    {
      cerr<<"computeHash: Cannot stat file - "<<filename;
      exit(1);
    }

  out = new byte [ stats.st_size ];
  int ret = read ( fd, out, stats.st_size );
  
  if ( ret < 0 )
    {
      cerr<<"computeHash: Error reading file - "<<filename;
      exit(1);
    }

  close ( fd );

  byte digest[ Sha512::DIGESTSIZE ];
  Sha512().CalculateDigest( digest, out, stats.st_size );

  CryptoPP::Integer iDigest;
  iDigest.Decode ( digest, Sha512::DIGESTSIZE, CryptoPP::Integer::UNSIGNED );

  stringstream s;
  s.flags(ios::hex);

  s<<iDigest;

  return s.str().substr(0,80);
}

/* Parse command line args;
 * set flags and filenames
 **/
void parse_args(int argc, char **argv)
{
  int c, index;

  while ( (c = getopt (argc, argv, arg_string)) != -1 )
    switch(c)
      {
      case 's':
	semantic_file = strdup(optarg);
	semantic_file_set = true;
	break;

      case 'o':
	output_file = strdup(optarg);
	output_file_set = true;
	break;

      case 't':
	template_file = strdup(optarg);
	template_file_set = true;
	break;
	
      case '?':
	  cerr<<"Unknown option -"<<optopt<<endl;
	  break;

      default:
	exit(1);
	break;
      }

  //input file is at whatever is left out
  if (optind >= argc)
    {
      cerr<<"Usage: cdlcc input-file [-t template] [-s semantic-def] [-o output-file]"<<endl;
      exit(1);
    }
  
  input_file = strdup(argv[optind]);
}

/**
 * preprocess input_file until all include"" directives are resolved.
 **/
void preprocess ()
{
  srand((unsigned int)time(NULL));
  stringstream ss;
  ss<<rand();
  preproc_file += "/tmp/";
  preproc_file += strdup( basename ( strdup( input_file.c_str() ) ) );
  preproc_file += ss.str();

  string cmd = "";
  cmd = cmd + "cdlpp " + input_file + " " + preproc_file;
  
  FILE *pd = popen(cmd.c_str(),"r");
  if ( pd == NULL )
    {
      cerr<<"Error opening a pipe to preprocessor!"<<endl;
      exit(1);
    }
  fflush(pd); // FIXME: Read the output and dump it on the screen
  int status = pclose(pd);
}

// populates the curYear and curMonth variables.
void getTime ()
{
  time_t curr;
  tm local;
  time(&curr);
  local=*(localtime(&curr)); 
  stringstream ssYear, ssMonth;
  ssYear<<local.tm_year;
  ssMonth<<local.tm_mon;

  curYear = ssYear.str();
  curMonth = ssMonth.str();
}

