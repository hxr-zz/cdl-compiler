// Copyright (C) 2007 Satya Kiran Popuri <spopur2@uic.edu>
//  
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//  
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//  
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//  

/** CDL compiler. The code generator.
 *  Works by walking through the symbol table and filling in a dictionary
 *  The dictionary is then applied to a template to get the final code
 */

# ifndef CODEGEN_H
# define CODEGEN_H

# include <string>
# include <google/template.h>
# include "SymbolTable.h"
# include "CDLType.h"
# include "Constraints.h"
using namespace std;

class CodeGenerator
{
private:
  google::TemplateDictionary *tl_dict; /* Top level dictionary */
  google::Template *tpl;	/* The template to be expanded */
  string syntaxHash;		/* Hash of input CDL */
  string semanticHash;		/* Hash of semantic file */
  string outputfile;		/* This is where code will be output */
  bool output_set;
  google::TemplateDictionary *certfns_dict;
public:
  CodeGenerator(string template_file, string source_file);
  ~CodeGenerator(){delete tpl; delete tl_dict; }

  void setSyntaxHash(string synHash) { syntaxHash = synHash; }
  void setSemanticHash(string semHash) { semanticHash = semHash; }
  void setOutputFile ( string out ) { outputfile = out; output_set = true;}
  void generateCode(SymbolTable *symtab);
  
private:
  /* fill a dictonary with this part of the table */
  void fillClassDict(SymbolHashtable *symtab, google::TemplateDictionary *dict, string name, CDLType *basetype, string basename);
  void fillTopLevelDict(Symbol *sym);
  void formatTypeString(string& fm, int *param, CDLType *type);
  void fillValidatorDict(google::TemplateDictionary *dict, CDLType *t);
};

#endif
