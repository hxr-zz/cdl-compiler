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
/* Line 1489 of yacc.c.  */
#line 149 "parse-cdl.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gram_lval;

