// CDL type system.
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

# ifndef CDLTYPE_H
  #define CDLTYPE_H

# include <iostream>
# include <list>
# include <string>
# include "SymbolTable.h"
# include "Constraints.h"

using namespace std;

class SymbolHashtable;

struct CDLType
{
 public:
  enum typeKind {
    /* Scalar types */
    stChar, stWchar, stIntx, stUintx, stFloat32, stFloat64, stDecimald, stDate, stUtcDate,
    
    /* Vector types */
    vtVector, vtArray,
    
    /* Composite types */
    ctClass, ctDerivedClass,
    
    /* Misc types */
    mtEnum, mtDummy, /* Dummy type is for holding constraints in derived classes */

    /* Certificate and Certificate Header */
    Certificate, CertificateHeader

  };

 private:
  typeKind baseKind;		/* The CDL base type */
  bool ADTflag;			/* Is this an ADT?  */
  bool vectorFlag;		/* Is this a vector?  */
  bool ADTvectorFlag;		/* Vector of ADT ? */
  int dimension;		/* For array types */
  int bitSize;			/* For INTX UINTX and DECIMALD types */
  list<string> *enumList;	/* For enum types, the list of valid enum names */
  Constraints *cons;		/* Constraints on this type */
  bool certificateFlag;		/* Is true if this a certificate specification */
  
  SymbolHashtable *table;	/* For composite types (class types) */
  CDLType *baseType;		/* For derived classes, the base ADT */

  string baseName;		/* For ADTs, the name of the base type symbol */

  void initVars();		/* Initialize all variables. */
 public:
  CDLType();
  ~CDLType();

  CDLType(typeKind base);
  CDLType(CDLType *t);  	        /* makes a deep copy of an existing type */
  bool operator == (CDLType &t); 	/* Type Check with another CDLType */

  /** Set methods */
  void setDimension(int n){ dimension = n; }
  void setBitSize(int n){ bitSize = n; }
  void setVector(bool vflag){ vectorFlag = vflag;}
  void setADT(bool aflag){ ADTflag = aflag; }
  void setADTvector(bool avflag){ ADTvectorFlag = true;}
  void setConstraints(Constraints *c) { cons = c; }
  void setKind(typeKind base) { baseKind = base; }
  void add2enum(string s){ enumList->push_back(s); }
  void setEnumList(list<string> *elist) { enumList = elist; }
  void setTable(SymbolHashtable *t){ table = t; }
  void setBaseType(CDLType *t){ baseType = t; }
  void setBaseName(string s){baseName = s; }
  void setCertificateFlag() { certificateFlag = true; }
  
  void display();		/* display the type */
  
  /** Get methods */
  int getDimension() { return dimension; }
  int getBitSize() { return bitSize; }
  bool isVector() { return vectorFlag; }
  bool isADT() { return ADTflag; }
  bool isADTvector() { return ADTvectorFlag; } 
  Constraints *getConstraints(){ return cons; }
  list<string> *getEnumList(){ return enumList; }
  typeKind getKind() { return baseKind; }
  SymbolHashtable *getTable(){ return table; }
  string getBaseName() { return baseName; }
  CDLType *getBaseType() { return baseType; }
  bool isCertificate() { return certificateFlag; }
  
};

# endif
