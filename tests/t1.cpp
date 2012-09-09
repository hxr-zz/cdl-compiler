/** The code below is generated from CDL specified in t1.certdef.
 *  
 */
#include "sayAnything/CertStdDef.h"

typedef Int<32> mytype;
 
class CertificateHeader : public DataTypeInterface
{
protected:
	
	Array<Float32,100> size;
	bool isSetsize;	

	UInt<32> version;
	bool isSetversion;	

	mytype myfield;
	bool isSetmyfield;	
public:
	CertificateHeader () 
	{	
		initialize();
	}
	void initialize()
	{
		isSetsize = false;
		isSetversion = false;
		isSetmyfield = false;
			}
	CertificateHeader ( CertificateHeader& __data ) 
	{
		initialize();
		if(! validate (__data)) throw "Error validating class CertificateHeader";
		 
		size=__data.size;
		isSetsize = true;
 
		version=__data.version;
		isSetversion = true;
 
		myfield=__data.myfield;
		isSetmyfield = true;
	}
	/* Function to get out stream */
	void* toWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		 
		//Variable size
		vpCurr = size.toWire( vpCurr );
 
		//Variable version
		vpCurr = version.toWire( vpCurr );
 
		//Variable myfield
		vpCurr = myfield.toWire( vpCurr );
		return vpCurr;
	}
	/* Function to get out stream */
	void* fromWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		 
		//Variable size
		vpCurr = size.fromWire ( vpCurr );
 
		//Variable version
		vpCurr = version.fromWire ( vpCurr );
 
		//Variable myfield
		vpCurr = myfield.fromWire ( vpCurr );
		return vpCurr;
	}
	/* SET Functions */
	 
	void setsize ( Array<Float32,100>& __data )
	{
		if (validatesize( __data ) ){
			size = __data;
			isSetsize = true;
		}
		else throw "Error validating size";
	}
 
	void setversion ( UInt<32>& __data )
	{
		if (validateversion( __data ) ){
			version = __data;
			isSetversion = true;
		}
		else throw "Error validating version";
	}
 
	void setmyfield ( mytype& __data )
	{
		if (validatemyfield( __data ) ){
			myfield = __data;
			isSetmyfield = true;
		}
		else throw "Error validating myfield";
	}
	/* GET Functions */
	 
	Array<Float32,100>& getsize()
	{
		return size;
	}
	bool is_setsize()
	{
		return isSetsize;
	}
 
	UInt<32>& getversion()
	{
		return version;
	}
	bool is_setversion()
	{
		return isSetversion;
	}
 
	mytype& getmyfield()
	{
		return myfield;
	}
	bool is_setmyfield()
	{
		return isSetmyfield;
	}
	 
	bool validatesize( Array<Float32,100>& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validateversion( UInt<32>& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
		 
		if ( __data == 1 )
			return true;
				return false; 
	}
 
	bool validatemyfield( mytype& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
	/* Validatior for all variables at once */
	bool validate ( CertificateHeader& __data )
	{
		bool bVal = true;
		
		 
		bVal &= validatesize( __data.size );
 
		bVal &= validateversion( __data.version );
 
		bVal &= validatemyfield( __data.myfield );
		
		return bVal;
	}
	/* Get size of this class */
	int getSize ()
	{
		int iSz = 0;
		
		 
		iSz += size.getSize();
 
		iSz += version.getSize();
 
		iSz += myfield.getSize();
		
		return iSz;
	}
};//Close class declaration.
