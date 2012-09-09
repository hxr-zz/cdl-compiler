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

# ifndef CONSTRAINTS_H
  #define CONSTRAINTS_H

# include <string>

using namespace std;

class Constraints
{
 public:
  enum Constraint_Type { closed_range, \
			 open_range, \
			 left_open_right_close_range, \
			 left_close_right_open_range, \
			 fixed, \
			 accuracy \
  };
  
 private:
  Constraint_Type consType;
  string leftBound;
  string rightBound;
  
  float accuracyBound;

 public:

  Constraints(Constraint_Type t) { consType = t; accuracyBound=0.00;}
  ~Constraints() {};

  void setLeftp(string *s){ leftBound = *s; }
  void setRightp(string *s){ rightBound = *s; }

  void setLeft(string s){ leftBound = s; }
  void setRight(string s){ rightBound = s; }
  
  void setAccuracy(float a){ accuracyBound = a; }
  
  float getAccuracy(){ return accuracyBound; }

  Constraint_Type getType() { return consType; }

  string getLeftBound(){return leftBound;}
  string getRightBound(){return rightBound;}
};

# endif
