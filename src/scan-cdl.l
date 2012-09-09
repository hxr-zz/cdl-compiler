/* CDL lexical analyzer.
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
%option nodefault nounput noyywrap never-interactive
%option prefix="gram_" outfile="lex.yy.c"
%{
#undef gram_wrap
#define gram_wrap() 1

# include "CDLType.h"
# include "SymbolTable.h"
# include "Constraints.h"
# include <list>
# include <string>

using namespace std;

# include "parse-cdl.h"
extern SymbolTable symtab;
%}


%%
[ \t]+					/* Tabs and white space */
\-\-[^\n]*				/* A comment */
[\n]					{++gram_lineno;};

                                        /* punctuation used in CDL */
";"                                     return SEMICOLON;
","                                     return COMMA;
"("                                     return LPAREN;
")"                                     return RPAREN;
":"                                     return COLON;
"{"                                     return LBRACE;
"}"                                     return RBRACE;
"["                                     return LSQ;
"]"                                     return RSQ;
"="                                     return EQUALS;
">"                                     return GT;
"<"                                     return LT;

					/** Types */
int[0-9]+				{ gram_lval.sVal = new string(gram_text); return INTX;  } 
uint[0-9]+				{ gram_lval.sVal = new string(gram_text); return UINTX; }
char					return CHAR;
wchar					return WCHAR; /* Wide character */
enum					return ENUM;  
vector					return VECTOR;
array					return ARRAY;
union					return UNION;
decimalField[0-9]+			{ gram_lval.sVal = new string(gram_text); return DECIMALD; }
float32					return FLOAT32;
float64					return FLOAT64;
class	  				return CLASS;

					/* Simple Data Types */
date					return DATE;
utcdate					return UTCDATE;
taidate					return TAIDATE;

					/** Other keywords */
range					return RANGE;
accuracy				return ACCURACY;
YEAR					return YEAR;
MONTH					return MONTH;
DATE					return DATE;
of					return OF;
certificate				return CERTIFICATE;
certificateHeader			return CERTIFICATEHEADER;

\.\.                                    return DOTDOT;

[_a-zA-Z][_a-zA-Z0-9]*			{ /* check if ID is a typedef */
					  Symbol k;
					  if (symtab.lookup(new string(gram_text),k) == true)
					  {
					     if (k.type->isADT())
					     {
						gram_lval.ctype = new CDLType(k.type); // makes a new copy
						gram_lval.ctype->setBaseName(k.id);    // set the base name symbol.
					     	return ADT;
					     }
					     else
					        fprintf(stderr,"Duplicate symbol defined on line %d: %s\n",gram_lineno,gram_text);
					  }
					  else
					  {
					  	gram_lval.sVal = new string(gram_text);	
					  	return ID; 
					  }
					}

[_a-zA-Z][._a-zA-Z0-9/]*		return FILENAME;

[0-9]+					{ gram_lval.iVal = atoi(gram_text); return NUMBER;   }
[0123456789]*\.[0123456789]+		{ gram_lval.fVal = atof(gram_text); return FRACTION; }
					

.					{ fprintf(stderr,"unrecognized stray character on line %d: %s\n",gram_lineno, gram_text); 
					  return ERROR;	
					}					
%%

/* A dummy gram_wrap () */
//int gram_wrap  ()
//{
//    return 1;
//}

/* Initialize lexer */
void initLex(string& infile)
{
  gram_in = fopen( infile.c_str(), "r");
}

/** Comment this out when parser is ready to go **/
/*
int 
main(int argc, char **argv)
{
  int token;
  initLex(argc, argv);
  while( (token = gram_lex()) !=0 ){
    strncpy(tokenString, gram_text, TOKENMAX);
    fprintf(gram_out,"[%d, %s]\n", token, tokenString);
  }
}
*/
