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


# ifndef SYMBOLTABLE_H
  #define SYMBOLTABLE_H

# include <string>
# include <list>
# include <ext/hash_set>
# include <iostream>
# include <algorithm>

class CDLType;
class SymbolHashtable;

# include "CDLType.h"

using namespace std;
using namespace __gnu_cxx;


struct Symbol
{
  CDLType *type; 		/* encapsulates all CDL types (including ADTs) */
  string  id;			/* The actual lexeme */
  int lineNumber;		/* Line number on which this symbol first appears */
  int scopeDepth;		/* scope of this symbol */

  int index;			/* This field is needed to order certificate fields. */
  
  bool operator () (const Symbol s1, const Symbol s2) const
  {
    return s1.id.compare(s2.id)==0;
  }

  Symbol():type(NULL),lineNumber(0),scopeDepth(0),index(0){}
  Symbol(string s, CDLType *t, int line, int scd, int idx)
  :
  type(t),
  id(s),
  lineNumber(line),
  scopeDepth(scd),
  index(idx){ }

  void display(){ cerr <<id <<" "; cerr<< " "<<lineNumber<< " "<< scopeDepth << " " <<index << endl; }
};

struct SymbolComparator
{
  bool operator() (const Symbol s1, const Symbol s2) const
  {
    return s1.index < s2.index;
  }
};

namespace __gnu_cxx
{
  template <>
  struct hash<Symbol>
  {
    size_t
    operator ()(Symbol s) const
    {
      return __stl_hash_string( s.id.c_str() );
    }
  };
}

class SymbolHashtable
{
 private:
  hash_set<Symbol, hash<Symbol>, Symbol> symTab;
  int symIndex;			/* This indexes symbols in each symbol table instance */
  int id;			/* ID the hashtable for debugging */
  int m_curIndex;		/* enables iteration in order of symbol indices */

  void sortSelf();			/* sort the hashtable */
 public:
  SymbolHashtable(int id);
  ~SymbolHashtable();
  void install_sym(string id, CDLType *t, int line, int scope);
  bool lookup_sym(string id, Symbol& s);
  void display();		/* display the table */

  void initIterator();		/* inititalize iterator */
  Symbol* iterate();		/* return the next symbol */
};

class SymbolTable
{
 private:
  /* A hash table to hold symbols */

  /*These stacks are implemented as lists (as front insertion sequences) because
   * stacks do not allow iteration thorough elements. Such iteration will be
   * required in symbol table lookups.
   */
  list<SymbolHashtable*> scopeStack; /* This is where scoped tables go */
  list<SymbolHashtable*> usedStack; /* This is where popped tables will go */
  int ht_id;
 public:
  SymbolTable();
  ~SymbolTable();

  void install(Symbol& s);
  void install(string *s, CDLType *t, int lineNumber);
  bool lookup(string *id, Symbol& s);
  bool lookup(Symbol& s);

  void enterScope();
  void leaveScope();
  
  unsigned int getScopeDepth();		/* return the current scope depth */
  SymbolHashtable *getCurrentTable(){ return scopeStack.front(); }
  
  void display();		/* display symboltable */

  Symbol* iterate();		/* return the next symbol in the table */
};

# endif
