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

# include "CDLType.h"
# include <iostream>

CDLType::CDLType()
{
  initVars();
}

CDLType::CDLType(typeKind base)
{
  initVars();
  this->baseKind = base;
}

CDLType::CDLType(CDLType *ct)
{
  initVars();
  // make a deep copy of *ct here
  baseKind = ct->baseKind;
  ADTflag = ct->ADTflag;
  vectorFlag = ct->vectorFlag;

  dimension = ct->dimension;
  bitSize = ct->bitSize;

  enumList = ct->enumList;
  cons = ct->cons;
  table = ct->table;

  baseType = ct->baseType;
  baseName = ct->baseName;
  
}
void
CDLType::initVars()
{
  baseKind = mtDummy;
  ADTflag = false;
  vectorFlag = false;
  ADTvectorFlag = false;
  dimension = 0;
  bitSize = 0;
  enumList=NULL;
  cons = NULL;
  table = NULL;
  baseType = NULL;
  certificateFlag = false;
  baseName = "";
}
bool
CDLType::operator == (CDLType& t)
{
  return true;
}

void
CDLType::display()
{
  if (ADTflag){
    cerr<<"ADT:";
    cerr<<baseName<<" ";
  }

  if (vectorFlag)
    cerr<<"vector of ";
  
  switch(baseKind)
    {
    case stChar: cerr<<"char"; break;
    case stWchar: cerr<<"wchar"; break;
    case stIntx: cerr<<"int"<<bitSize; break;
    case stUintx: cerr<<"uint"<<bitSize; break;
    case stFloat32: cerr<<"Float32"; break;
    case stFloat64: cerr<<"Float64"; break;
    case stDecimald: cerr<<"decimal"<<bitSize; break;
    case ctClass: cerr<<"class\n"; break; //if(table) table->display(); break;
    case ctDerivedClass: cerr<<"Derived class"<<endl; break; //if(table) table->display(); break;
    case mtEnum: cerr<<"enum"; break;
    case mtDummy: cerr<<"nontype"; break;
    case Certificate: cerr<<"Certificate"; break;
    case CertificateHeader: cerr<<"Certificate Header"; break;
    default: cerr<<baseKind; break;
    }

  if (dimension != 0)
    cerr<<"["<<dimension<<"]";

}
      
CDLType::~CDLType()
{
}
