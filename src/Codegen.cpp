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

# include "Codegen.h"
# include <iostream>
# include <sstream>
# include <fstream>

CodeGenerator::CodeGenerator(string tp_file,string source_file)
{
  syntaxHash = "";
  semanticHash = "";
  outputfile = "";
  output_set = false;
  certfns_dict = NULL;
  // Instantiate the dictionary and open the template
  tpl = google::Template::GetTemplate (tp_file, google::STRIP_BLANK_LINES);

  if(!tpl){
    cerr<<"Code generator could not instantiate template from file " << tp_file<< endl;
    exit(1);
  }

  // create the top level dictionary
  tl_dict = new google::TemplateDictionary("CODE_TOP_LVL");

  if(!tl_dict){
    cerr<<"Code generator could not instantiate top level template dictionary!\n";
    exit(1);
  }

  tl_dict->SetValue("SOURCE_FILE",source_file);
}

// Walk thru symtab and fill out the top level dictionary
void
CodeGenerator::generateCode(SymbolTable *symtab)
{
  Symbol *sym=NULL;

  while ( ( sym = symtab->iterate() ) != NULL )
    {

      switch( sym->type->getKind() )
	{
	case CDLType::ctClass: // make a class section dictionary and fill it up
	  {
	    google::TemplateDictionary *class_dict = tl_dict->AddSectionDictionary("CLASS_DECL");
	    class_dict->SetValue("BASE_CLASS_NAME","DataTypeInterface");
	    // If class is a certificate declaration, add certHeader and certTrailer sections.
	    if (sym->type->isCertificate())
	      {
		class_dict->ShowSection("CLASS_CERT_HEADER");
		class_dict->ShowSection("CLASS_CERT_TRAILER");
		class_dict->ShowSection("HDR_TOWIRE_FN");
		class_dict->ShowSection("HDR_FROMWIRE_FN");
		class_dict->ShowSection("TRL_TOWIRE_FN");
		class_dict->ShowSection("TRL_FROMWIRE_FN");
		class_dict->ShowSection("HDR_SET_FN");
		class_dict->ShowSection("TRL_SET_FN");
		class_dict->ShowSection("HDR_GET_FN");
		class_dict->ShowSection("TRL_GET_FN");
		class_dict->ShowSection("HDR_VAL_FN");
		class_dict->ShowSection("TRL_VAL_FN");
		class_dict->ShowSection("HDR_VAL_VAR");
		class_dict->ShowSection("TRL_VAL_VAR");
		class_dict->ShowSection("HDR_SIZEUP_VAR");
		class_dict->ShowSection("TRL_SIZEUP_VAR");

		google::TemplateDictionary *tcons = class_dict->AddSectionDictionary("TRAILER_INIT");
		tcons->SetFormattedValue("SYN_HASH", "\"0x%s\"",syntaxHash.c_str());
		tcons->SetFormattedValue("SEM_HASH", "\"0x%s\"",semanticHash.c_str());

		tl_dict->ShowSection("CERT_INCLUDES");
		certfns_dict = class_dict->AddSectionDictionary("CERT_FNS");
	      }
		    
	    fillClassDict(sym->type->getTable(),class_dict,sym->id, NULL,"");
	    break;
	  }
	  
	 case CDLType::ctDerivedClass:
	   {
	     google::TemplateDictionary *class_dict = tl_dict->AddSectionDictionary("CLASS_DECL");
	     class_dict->SetValue("BASE_CLASS_NAME", sym->type->getBaseName());
	     class_dict->ShowSection("DERIVED_CLS_CONSTR"); // show the derived class constructor.
	     class_dict->ShowSection("DERIVED_CLS_FROMWIRE");
	     class_dict->ShowSection("DERIVED_CLS_TOWIRE");
	     class_dict->ShowSection("DERIVED_CLS_VALIDATE");
	     class_dict->ShowSection("DERIVED_CLS_SIZE");
	     fillClassDict(sym->type->getTable(), class_dict, sym->id, sym->type->getBaseType(), sym->type->getBaseName());
	     break;
	  }
	  
	default: fillTopLevelDict(sym);
	  break;
	}
    }

  string code_out;

  tpl->Expand(&code_out,tl_dict);

  if ( output_set )
    {
      ofstream outfile(outputfile.c_str());
      outfile<<code_out;
      outfile.close();
    }
  else
    cout<<code_out;
}

void
CodeGenerator::fillClassDict(SymbolHashtable *sh, google::TemplateDictionary *dict, string name, CDLType *basetype, string basename)
{
  Symbol *sym=NULL;

  dict->SetValue("CLASS_NAME",name);
  sh->initIterator();

  while( (sym = sh->iterate() ) !=NULL )
    { 
      if (sym->type->getKind() == CDLType::mtDummy)
	{
	  // Fill a validation dictionary for overridden variables
	  google::TemplateDictionary *class_validator = dict->AddSectionDictionary("CLASS_VALIDATORS");
	  class_validator->SetValue("CLASS_VAR_NAME",sym->id);

	  //get the format string for type from the base class and set CLASS_VAR_TYPE.
	  string formatString = "";
	  int param=0;

	  string symid(sym->id);
	  Symbol old_sym;
	  bool done = false;
	  while(! done)
	    {
	      if ( basetype->getTable()->lookup_sym(symid,old_sym) == true)
		{
		  //symbol is found, but may be dummy. In that case we are not done yet
		  if (old_sym.type->getKind() != CDLType::mtDummy)
		    break; //this is what we want
		}
	      //symbol is not found or a dummy symbol was found in the base class. Go one level up.
	      if ( basetype->getKind() == CDLType::ctDerivedClass )
		{
		  basetype = basetype->getBaseType();
		  done = false;
		  continue;
		}
	      //if we reached this point, it is an error!
	      cerr<<"Error: Redefined symbol "<< symid <<" is not present in any base class."<<endl;
	      exit(1);
	    }

	  //process the symbol type.
	  CDLType *symtype = old_sym.type;
	
	  if (symtype->isADT())
	    {
	      class_validator->SetValue("CLASS_VAR_TYPE",symtype->getBaseName());
	    }
	  else
	    {
	      formatTypeString(formatString,&param,symtype);
	      if(symtype->isVector())
		formatString = "Vector <" + formatString + ">";
	    
	      if(sym->type->getDimension() !=0)
		{
		  stringstream ss;
		  ss<<sym->type->getDimension();
		  formatString = "Array<" + formatString + "," + ss.str() + ">";
		}

	      class_validator->SetFormattedValue("CLASS_VAR_TYPE",formatString.c_str(),param);
	    }
	  //Now fill a validator dict based on constraints
	  fillValidatorDict(class_validator,sym->type);

	  //show the sections relevant to calling base class validators
	  class_validator->SetValue("BASE_CLASS_NAME",basename);
	  class_validator->ShowSection("BASE_CLASS_VALIDATOR");

	  //Add validator vars
	  dict->SetValueAndShowSection("CLASS_VAR_NAME",sym->id,"VALIDATE_VARS");
	  continue;
	} // Done processing Dummy symbol

      google::TemplateDictionary *class_set_init = dict->AddSectionDictionary("SET_INIT_SECTION");
      google::TemplateDictionary *class_copy_ctor = dict->AddSectionDictionary("CLASS_COPY_CTOR");
      google::TemplateDictionary *class_towire_fn = dict->AddSectionDictionary("CLASS_TOWIRE_FN");
      google::TemplateDictionary *class_fromwire_fn = dict->AddSectionDictionary("CLASS_FROMWIRE_FN");

      google::TemplateDictionary *class_validator = dict->AddSectionDictionary("CLASS_VALIDATORS");
      google::TemplateDictionary *class_vars = dict->AddSectionDictionary("CLASS_VARS");
      google::TemplateDictionary *class_setter = dict->AddSectionDictionary("CLASS_SETTERS");
      google::TemplateDictionary *class_getter = dict->AddSectionDictionary("CLASS_GETTERS");
      google::TemplateDictionary *validate_vars = dict->AddSectionDictionary("VALIDATE_VARS");
      google::TemplateDictionary *sizeup_vars = dict->AddSectionDictionary("SIZEUP_VARS");

      google::TemplateDictionary *certfns_memtowire = NULL;
      if (certfns_dict != NULL )
	certfns_memtowire = certfns_dict->AddSectionDictionary("CLASS_MEM_TOWIRE"); 

      class_set_init->SetValue("CLASS_VAR_NAME",sym->id);
      class_vars->SetValue("CLASS_VAR_NAME",sym->id);
      class_setter->SetValue("CLASS_VAR_NAME",sym->id);
      class_getter->SetValue("CLASS_VAR_NAME",sym->id);
      class_validator->SetValue("CLASS_VAR_NAME",sym->id);
      validate_vars->SetValue("CLASS_VAR_NAME",sym->id);
      class_copy_ctor->SetValue("CLASS_VAR_NAME",sym->id);
      class_towire_fn->SetValue("CLASS_VAR_NAME",sym->id);
      class_fromwire_fn->SetValue("CLASS_VAR_NAME",sym->id);
      sizeup_vars->SetValue("CLASS_VAR_NAME", sym->id);
      
      if (certfns_memtowire != NULL )
	certfns_memtowire->SetValue("CLASS_VAR_NAME",sym->id);


      // Done setting name. Set the type now.
      if(sym->type->isADT())
	{
	  if (sym->type->getKind() == CDLType::mtEnum)
	    {
	      string newBaseName = sym->type->getBaseName() + "Enum";
	      sym->type->setBaseName(newBaseName);
	    }
	  string basename = sym->type->getBaseName();
	  if (sym->type->isADTvector())
	    basename = "Vector<" + basename + ">";
	  
	  class_vars->SetValue("CLASS_VAR_TYPE",basename);
	  class_setter->SetValue("CLASS_VAR_TYPE",basename);
	  class_getter->SetValue("CLASS_VAR_TYPE",basename);
	  class_validator->SetValue("CLASS_VAR_TYPE",basename);

	  fillValidatorDict(class_validator,sym->type);
	  continue;
	}

      // Otherwise set type differently.
      string formatString="";
      int param=0;

      formatTypeString(formatString, &param, sym->type);
      
      if( sym->type->isVector() )
      {
	// this is a vector of basic type. Translates to Vector<basic_type>
	formatString = "Vector<" + formatString + ">";
      }

      if (sym->type->getDimension() !=0 )
	{
	  stringstream ss;
	  ss<<sym->type->getDimension();
	  formatString = "Array<" + formatString + "," + ss.str() + ">";
	}
      
      class_vars->SetFormattedValue("CLASS_VAR_TYPE",formatString.c_str(),param);
      
      class_setter->SetFormattedValue("CLASS_VAR_TYPE",formatString.c_str(),param);
      class_getter->SetFormattedValue("CLASS_VAR_TYPE",formatString.c_str(),param);
      class_validator->SetFormattedValue("CLASS_VAR_TYPE",formatString.c_str(),param);

      fillValidatorDict(class_validator,sym->type);

    }//close while
}//close fillDict


void
CodeGenerator::fillValidatorDict(google::TemplateDictionary* class_validator, CDLType *type)
{
      //fill in constraints for the class validator.
      Constraints *cons = type->getConstraints();
      if ( cons == NULL ){ //there are no constraints
	class_validator->SetValue("RET_VAL","true");
	return;
      }

      class_validator->SetValue("RET_VAL","false"); // The default return value
      class_validator->SetValue("LEFT_BOUND",cons->getLeftBound());
      class_validator->SetValue("RIGHT_BOUND", cons->getRightBound());
      class_validator->SetFormattedValue("ACCURACY","%.2f",cons->getAccuracy());
      
      //fill in the leftbound and right bound and show the appropriate section
      switch(cons->getType())
	{
	case Constraints::fixed:
	  class_validator->SetValueAndShowSection("VALUE",cons->getLeftBound(),"FIXED_RANGE");
	  break;

	case Constraints::left_open_right_close_range:
	  class_validator->ShowSection("LEFT_CLOSE_RIGHT_OPEN");
	  break;

	case Constraints::left_close_right_open_range:
	  class_validator->ShowSection("LEFT_OPEN_RIGHT_CLOSE");
	  break;

	case Constraints::open_range:
	  class_validator->ShowSection("OPEN_RANGE");
	  break;

	case Constraints::closed_range:
	  class_validator->ShowSection("CLOSED_RANGE");
	  break;

	case Constraints::accuracy:
	  class_validator->ShowSection("CHECK_ACCURACY");
	  break;
	}//close switch

      //sometimes range and accuracy are both present
      if ( cons->getAccuracy() != 0 )
	class_validator->ShowSection("CHECK_ACCURACY");     
}



void
CodeGenerator::fillTopLevelDict(Symbol *sym)
{
  // This function is called if top level ADT declaration is not a class
  // Fill out the typedefs section of the top level dictionary

  google::TemplateDictionary *typedefs = tl_dict->AddSectionDictionary("TYPEDEFS");

  //Fill in the name
  typedefs->SetValue("VAR_NAME",sym->id);

  //Fill in the type
  string formatString="";
  int param=0;

  formatTypeString(formatString, &param, sym->type);

  if(sym->type->getKind() == CDLType::mtEnum)
    {
      formatString = "enum " + formatString;

      // Also show the section for a class wrapper
      google::TemplateDictionary *ewr = tl_dict->AddSectionDictionary("ENUM_WRAPPER");
      ewr->SetValue("VAR_TYPE",sym->id);
    }
      

  if(sym->type->isVector() )
    formatString = "Vector<" + formatString + ">";
  
  typedefs->SetFormattedValue("VAR_TYPE",formatString.c_str(),param);
}

void
CodeGenerator::formatTypeString(string& formatString, int *param, CDLType* type)
{
  switch(type->getKind())
    {
  	case CDLType::stIntx:
	  formatString = "Int<%d>";
	  *param = type->getBitSize();
	  break;
	    
	case CDLType::stUintx:
	  formatString = "UInt<%d>";
	  *param = type->getBitSize();
	  break;

	case CDLType::stFloat32:
	  formatString="Float32";
	  *param=0;
	  break;

	case CDLType::stFloat64:
	  formatString = "Float64";
	  *param=0;
	  break;
	  
	case CDLType::stChar:
	  formatString = "Char";
	  *param=0;
	  break;

	case CDLType::stWchar:
	  formatString = "WChar";
	  *param=0;
	  break;

	case CDLType::stDecimald:
	  formatString = "DecimalField<%d>";
	  *param=type->getBitSize();
	  break;

        case CDLType::stDate:
	  formatString = "DateTime";
	  *param=0;
	  break;

        case CDLType::stUtcDate:
	  formatString = "UTCDateTime";
	  *param = 0;
	  break;
	
	case CDLType::mtEnum:
	  {
	    // set the list.
	    list<string> *elist = type->getEnumList();
	    list<string> :: iterator it = elist->begin();
	    int size = elist->size();
	    formatString+= "{ ";
	    while( size != 1 )
	      {
		formatString += *it + ", ";
		it ++;
		size--;
	      }
	    formatString += *it + " }";
	    *param=0;
	    break;
	  }//close the Enum case.
    }//close switch 
}
