%{/* CDL Grammar parser.                    -*- C -*-
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
%}
%debug
%defines
%name-prefix="gram_"

%union
{
  CDLType *ctype;
  string  *sVal;
  int      iVal;
  float    fVal;
  list<string> *enumList;   // for enumerations
  SymbolHashtable *table;   // Symbol table for composite types
  Constraints *constr;      // for constraints
};

%expect 1
%start Certificate_Description

%token                          DATE		UTCDATE		TAIDATE
%token  	                CLASS 		ENUM 		
%token				ACCURACY 	YEAR 		MONTH 		
%token			       	VECTOR		TYPEDEF		
%token				RANGE 		CERTIFICATE
%token				CERTIFICATEHEADER
%token				OF     	WCHAR	CHAR
%token                          ARRAY   UNION   
%token                          FLOAT32         FLOAT64
%token                          ERROR
%token<ctype>			ADT

%token<sVal>			ID	INTX	UINTX	FILENAME	DECIMALD
%token<iVal>			NUMBER
%token<fVal>			FRACTION

%token                          SEMICOLON ";"
%token                          COMMA ","
%token                          LPAREN "("
%token                          RPAREN ")"
%token                          LSQ "["
%token                          RSQ "]"
%token                          DOTDOT
%token                          EQUALS "="
%token                          COLON ":"
%token                          LBRACE "{"
%token                          RBRACE "}"
%token                          GT ">"
%token                          LT "<"
%token				FWSLASH "/"

%type <ctype>			Base_Type Scalar_Type Vector_Type Array_Type Int_Type Char_Type Enum_Type
%type <ctype>			Decimal_Type Float_Type Date_Type Class_Type
%type <table>			Field_Declarations Field_Redefs
%type <constr>			Constraints Range Accuracy 

%type <enumList>		Id_List
%type <sVal>			Date_Bound

%% /* rules section */

Certificate_Description: Declarations
			 {
			 }
;

Declarations: Declarations Declaration
            | Declaration
;

Declaration: ADT_Declaration
	   | CertificateHeader_Declaration
	   | Certificate_Declaration
;

ADT_Declaration: ID ":" Base_Type ";" 
		 { /* ID will be installed as ADT in the symbol table */  
		    $3->setADT(true);
  		    symtab.install($1,$3,gram_lineno);
		 }
		 
	       | ID ":" ADT "," Constraints ";"
	         {
		    $3->setConstraints($5); 	    /* set constraints for the ADT type */
		    symtab.install($1,$3,gram_lineno); /* Install the ADT symbol */
		 }
;

CertificateHeader_Declaration: CERTIFICATEHEADER ":" CLASS "{" { symtab.enterScope(); }  Field_Declarations { symtab.leaveScope(); } "}" ";" 
			       {
				  CDLType *ht = new CDLType(CDLType::ctClass);
				  ht->setTable($6);
				  
			       	  // Install this in the symbol table
				  symtab.install(new string("CertificateHeader"),ht,gram_lineno);
			       }
;

Certificate_Declaration: ID ":" CERTIFICATE "{" { symtab.enterScope(); } Field_Declarations { symtab.leaveScope(); } "}" ";"
			 {
			   // check if a semantic definition file is supplied.
			   if (!semantic_file_set)
			     {
			       cerr<<"This CDL contains a Certificate definiton, but a semantic definition file was not supplied. Please use the -s switch  to name one."<<endl;
			       exit(1);
			     }
			   CDLType *ht = new CDLType(CDLType::ctClass);
			   ht->setTable($6);
			   ht->setCertificateFlag();

			   symtab.install($1,ht,gram_lineno);
			 }
;

Field_Declarations: Field_Declarations Field_Declaration
		    { $$ = symtab.getCurrentTable(); }
		  | Field_Declaration
		    { $$ = symtab.getCurrentTable(); }
;

Field_Declaration: ID ":" Base_Type ";" 
		   { symtab.install($1,$3,gram_lineno);}
		   
		 | ID ":" ADT ";"       
		   { symtab.install($1,$3,gram_lineno); }
		   
		 | ID ":" ADT "," Constraints ";"
		   { $3->setConstraints($5); symtab.install($1,$3,gram_lineno); }
;

Base_Type: Base_Type "," Constraints { $1->setConstraints($3); $$=$1; }
	 | Scalar_Type
	 | Vector_Type
	 | Array_Type
	 | Class_Type
	 | Enum_Type
;

Scalar_Type: Int_Type
	   | Char_Type
	   | Decimal_Type
	   | Float_Type
           | Date_Type
;

Vector_Type: VECTOR OF Scalar_Type { $$ = $3; $$->setVector(true); }
           | VECTOR OF ADT { $$=$3;  $$->setADTvector(true);}
;

Array_Type: Scalar_Type "[" NUMBER "]" { $1->setDimension($3); $$=$1; }
;

Int_Type: INTX 
	  {
	    /* Extract size from INTX */
	    $$ = new CDLType(CDLType::stIntx);
	    $1->erase(0,3); 	/* Erase the int part */
	    int sz = atoi($1->c_str());
	    $$->setBitSize(sz);
	  }
	    
	| UINTX
	  {
	    $1->erase(0,4);
	    int sz = atoi($1->c_str());
	    $$ = new CDLType(CDLType::stUintx);
	    $$->setBitSize(sz);
	  }
;

Char_Type: CHAR
	   {
	     $$ = new CDLType(CDLType::stChar);
	   }
	   
	 | WCHAR
	   {
	     $$ = new CDLType(CDLType::stWchar);
	   }
;

Enum_Type: ENUM "{" Id_List "}"
	   {
	     $$ = new CDLType(CDLType::mtEnum);
	     $$->setEnumList($3);
	   }
;

Id_List: Id_List "," ID
	 {
	   string s($3->c_str());
	   $$->push_front(s);
	 }
       | ID
         {
	   $$ = new list<string>();
	   string s($1->c_str());
	   $$->push_front(s);
	 }
;

Decimal_Type: DECIMALD 
	     {
	       $1->erase(0,12);
	       int sz = atoi($1->c_str());
	       $$ = new CDLType(CDLType::stDecimald); 
	       $$->setBitSize(sz);
	     }
;

Float_Type: FLOAT32  {$$ = new CDLType(CDLType::stFloat32); }
	  | FLOAT64  {$$ = new CDLType(CDLType::stFloat64); }
;

Date_Type: DATE { $$ = new CDLType(CDLType::stDate); }
         | UTCDATE { $$ = new CDLType(CDLType::stUtcDate);}

Class_Type: CLASS "{" { symtab.enterScope(); } Field_Declarations { symtab.leaveScope(); } "}" 
	    { $$ = new CDLType(CDLType::ctClass); 
	      $$->setTable($4);
	    }
	    
	  | ADT CLASS "{" { symtab.enterScope(); } Field_Redefs {symtab.leaveScope(); } "}"   
	    { 
	      $$ = new CDLType(CDLType::ctDerivedClass); 
	      $$->setTable($5);
	      $$->setBaseType($1);
	      $$->setBaseName($1->getBaseName());
	    }
;

Field_Redefs: Field_Redefs Field_Redef
	      { $$ = symtab.getCurrentTable(); }
	    | Field_Redef
	      { $$ = symtab.getCurrentTable(); }
;

Field_Redef: ID ":" Constraints ";"
	     {
		// Create a dummy CDL type to hold the constraints.
		CDLType *dt = new CDLType(CDLType::mtDummy);
		dt->setConstraints($3);
		
		symtab.install($1,dt,gram_lineno);
	     }
	     | Field_Declaration

Constraints: Range "," Accuracy 
	     { $1->setAccuracy($3->getAccuracy()); $$=$1;}
           | Range
	   | Accuracy
;

Range: RANGE "=" Date_Bound { $$ = new Constraints(Constraints::fixed);
                              $$->setLeftp($3);
                            }
     | RANGE "=" NUMBER { $$=new Constraints(Constraints::fixed);
     			  $$->setLeft(to_str($3));
			}
			 
     | RANGE "=" NUMBER DOTDOT NUMBER  
       { $$ = new Constraints(Constraints::open_range);
         $$->setLeft(to_str($3)); $$->setRight(to_str($5));
       }
       
     | RANGE "=" Date_Bound DOTDOT Date_Bound
       { $$ = new Constraints(Constraints::open_range);
         $$->setLeftp($3); $$->setRightp($5);
       }
       
     | RANGE "=" ">" NUMBER DOTDOT NUMBER
       { $$ = new Constraints(Constraints::left_close_right_open_range);
         $$->setLeft(to_str($4)); $$->setRight(to_str($6));
       }
       
     | RANGE "=" ">" Date_Bound DOTDOT Date_Bound 
       { $$=new Constraints(Constraints::left_close_right_open_range);
         $$->setLeftp($4); $$->setRightp($6);
       }

     | RANGE "=" ">" NUMBER DOTDOT "<" NUMBER
       { $$=new Constraints(Constraints::closed_range);
         $$->setLeft(to_str($4)); $$->setRight(to_str($7));
       }

     | RANGE "=" ">" Date_Bound DOTDOT "<" Date_Bound
       { $$=new Constraints(Constraints::closed_range);
         $$->setLeftp($4); $$->setRightp($7);
       }

     | RANGE "=" NUMBER DOTDOT "<" NUMBER
       { $$=new Constraints(Constraints::left_open_right_close_range);
         $$->setLeft(to_str($3)); $$->setRight(to_str($6));
       }

     | RANGE "=" Date_Bound DOTDOT "<" Date_Bound
       { $$=new Constraints(Constraints::left_open_right_close_range);
         $$->setLeftp($3); $$->setRightp($6);
       }

     | RANGE "=" ID
       { $$=new Constraints(Constraints::fixed); $$->setLeftp($3); }
;

Accuracy: ACCURACY "=" FRACTION { $$ = new Constraints(Constraints::accuracy); 
				  $$->setAccuracy($3); 
				}
;

Date_Bound: YEAR "(" NUMBER ")" 
	    { string t = "DateTime(1,1," + to_str($3) + ")"; $$=new string(t); }
	    
	  | MONTH "(" NUMBER ")" 
	    { string t = "DateTime(" + to_str($3) + ",1," + curYear + ")"; $$=new string(t); }
	    
	  | DATE "(" NUMBER ")" 
	    { string t = "DateTime(" + curMonth + "," + to_str($3) + "," + curYear + ")"; $$=new string(t); }
	    
	  | NUMBER "/" NUMBER "/" NUMBER
	    { 
	      string t = "DateTime(" + to_str($1) + ","+ to_str($3)+ "," + to_str($5) + ")"; $$=new string(t); 
	    }
;

%%

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
