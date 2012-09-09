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

# include "SymbolTable.h"

/** Implementation of SymbolHashtable */
SymbolHashtable::SymbolHashtable(int id)
{
  symIndex = 0;
  this->id = id;
}

void
SymbolHashtable::install_sym(string id, CDLType *type, int line, int scope)
{
  symTab.insert(Symbol(id,type,line,scope,symIndex++));
}

bool
SymbolHashtable::lookup_sym(string id, Symbol& s)
{
  Symbol k(id, NULL, 0, 0, 0);
  hash_set<Symbol, hash<Symbol>, Symbol> :: const_iterator it = symTab.find(k);

  if( it == symTab.end() )
    return false;

  s = (Symbol)(*it);
  return true;
}

void
SymbolHashtable::display()
{
  hash_set<Symbol, hash<Symbol>, Symbol> :: iterator it = symTab.begin();

  while(it != symTab.end() )
    {
      ((Symbol)(*it)).display();
      it++;
    }
}

void
SymbolHashtable::initIterator()
{
  m_curIndex = 0;
}

// Iterate thru the current hash table and return the symbol in order of symbol indices
// This is an inefficient way. Change data structure of SymbolHashtable to be ordered instead.

Symbol*
SymbolHashtable::iterate()
{
  Symbol *sym;
  hash_set<Symbol, hash<Symbol>, Symbol> :: iterator it = symTab.begin();

  while( it != symTab.end() && m_curIndex != symTab.size() )
    {
      sym = (Symbol *)&(*it);

      if( sym->index == m_curIndex )
	{
	  m_curIndex++; // The index of symbol that will be returned next.
	  return sym;
	}
      else
	it++;
    }
  return NULL; //not found or index out of bounds;
}

SymbolHashtable::~SymbolHashtable(){ }

/** Implementation of Symboltable */
SymbolTable::SymbolTable()
{
  ht_id=1;  
  //push the global symbol table.
  SymbolHashtable *global_table = new SymbolHashtable(ht_id++);
  scopeStack.push_front(global_table);
}

void
SymbolTable::enterScope()
{
  //push a new symboltable.
  scopeStack.push_front(new SymbolHashtable(ht_id++));
}

void
SymbolTable::leaveScope()
{
  usedStack.push_front(scopeStack.front());
  scopeStack.pop_front();
}

void
SymbolTable::install(Symbol& s)
{
  this->install(&s.id,s.type,s.lineNumber);
}

void
SymbolTable::install(string *id, CDLType* type, int line)
{
  scopeStack.front()->install_sym(*id,type,line,this->getScopeDepth());
}

bool
SymbolTable::lookup(string *id, Symbol &s)
{
  //search the entire stack and return the first occurance of symbol.
  //return scopeStack.front()->lookup_sym(id,s);
  
  list<SymbolHashtable*>::iterator i = scopeStack.begin();
  while( i != scopeStack.end() )
    {
      
      if( (*i)->lookup_sym(*id,s) )
	return true;

      ++i;
    }
  
}

bool
SymbolTable::lookup(Symbol& s)
{
  return this->lookup(&s.id,s);
}

unsigned int
SymbolTable::getScopeDepth()
{
  return (unsigned int)scopeStack.size();
}

void
SymbolTable::display()
{
  // print *all* tables
  list<SymbolHashtable*>::iterator i = scopeStack.begin();
  while( i != scopeStack.end() )
    {
      (*i)->display();
      ++i;
    }
  
}

Symbol *
SymbolTable::iterate()
{
  static list<SymbolHashtable*> :: iterator i = scopeStack.begin();
  static bool iterator_init = false;
  Symbol *sym;
  
  if( i != scopeStack.end() )
    {
      if(! iterator_init){
	((SymbolHashtable *)(*i))->initIterator();
	iterator_init = true;
      }
      
      sym = ((SymbolHashtable *)(*i))->iterate();

      if (sym )  
	return sym;
      else
	return NULL;
    }
  else
    return NULL;
}

SymbolTable::~SymbolTable()
{
}
