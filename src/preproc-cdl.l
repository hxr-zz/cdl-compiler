/* A naive preprocessor for the CDL include command
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
%option noyywrap never-interactive
%option prefix="preproc_" outfile="lex.yy.c"
%{
#undef gram_wrap
#define gram_wrap() 1

# include <iostream>
# include <stdio.h>
# include <stdlib.h>

using namespace std;
bool found_include = false;
%}

%%
include[ ]*\"[_a-zA-Z][._a-zA-Z0-9/]*\"[ ]*	{ // found an include. Expand the file in place
                                                  found_include = true;
						  char *s = strdup(preproc_text);
						  char *pch = strtok(s,"\"");
						  pch = strtok(NULL,"\"");
						  FILE *fp = fopen(pch, "r");
						  if (!fp)
						  {
						    cerr<<"Cannot open Include file:"<<pch<<endl;
						    exit(1);
						  }
						  int ch;
						  while( (ch=fgetc(fp)) != EOF)
						    fputc(ch,preproc_out);
						}
%%
int
main(int argc, char **argv)
{
  // Initialize the lexer here
  if (argc < 3)
   {
      cout<<"Usage: preproc [sourcefile] [outputfile]"<<endl;
      exit(1);
   }

   preproc_in = fopen(argv[1],"r");
   preproc_out = fopen(argv[2],"w");
   preproc_lex();

   fclose ( preproc_in );
   fclose ( preproc_out );
}
