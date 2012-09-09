/** The code below is generated from CDL specified in t4.certdef.
 *  
 */
# include <CertStdDef.h>
# include <crypto++/cryptlib.h>
# include <crypto++/rsa.h>
# include <crypto++/pkcspad.h>
# include <crypto++/files.h>
# include <crypto++/osrng.h>

typedef Int<512> hashType;

typedef Int<129> publicKeyType;

typedef Int<128> signatureType;

typedef DateTime dateType;

typedef DateTime recentDateType;

typedef Vector<Char> revocationServerType;

typedef enum { YUAN, EURO, USD } currencyUnits;

typedef Int<32> ipV4number;

typedef Float32 height;

typedef enum { duke, lord, sir } titleType;

class currencyUnitsEnum : public DataTypeInterface
{
public:
	currencyUnits _member;
	/* Constructors */
	currencyUnitsEnum() { }
	currencyUnitsEnum ( currencyUnitsEnum& t )
	{
		_member = t._member;
	}
	currencyUnitsEnum ( currencyUnits t )
	{
		_member = t;
	}
	void operator = ( currencyUnits t )
	{
		_member = t;
	}
	void operator = ( currencyUnitsEnum& t )
	{
		_member = t._member;
	}
	bool operator == ( currencyUnits t )
	{
		return (_member == t );
	}
	bool operator == ( currencyUnitsEnum& t )
	{
		return (_member == t._member );
	}
	int getSize () { return sizeof ( _member ) ; }
	void *toWire ( void *vpStart )
	{
		unsigned char *vpCurr = (unsigned char *)vpStart;
		unsigned char *ret = toLittleEndian ( (unsigned char *)&_member, sizeof (_member) );
		for ( int i=0; i<sizeof(_member); ++i )
			vpCurr[i] = ret[i];
		byte *newStart = (byte *)vpStart + sizeof(_member);
		return (void *)newStart;
	}
	void *fromWire ( void *vpStart )
	{
		unsigned char *vpCurr = (unsigned char *)vpStart;
		unsigned char *ret = fromLittleEndian ( (unsigned char *)vpStart, sizeof(_member) );
		_member = (currencyUnits)*ret;
		byte *newEnd = (byte *)vpStart + sizeof(_member);
		return (void *)newEnd;
	}
}; /* End of Enum wrapper */

class titleTypeEnum : public DataTypeInterface
{
public:
	titleType _member;
	/* Constructors */
	titleTypeEnum() { }
	titleTypeEnum ( titleTypeEnum& t )
	{
		_member = t._member;
	}
	titleTypeEnum ( titleType t )
	{
		_member = t;
	}
	void operator = ( titleType t )
	{
		_member = t;
	}
	void operator = ( titleTypeEnum& t )
	{
		_member = t._member;
	}
	bool operator == ( titleType t )
	{
		return (_member == t );
	}
	bool operator == ( titleTypeEnum& t )
	{
		return (_member == t._member );
	}
	int getSize () { return sizeof ( _member ) ; }
	void *toWire ( void *vpStart )
	{
		unsigned char *vpCurr = (unsigned char *)vpStart;
		unsigned char *ret = toLittleEndian ( (unsigned char *)&_member, sizeof (_member) );
		for ( int i=0; i<sizeof(_member); ++i )
			vpCurr[i] = ret[i];
		byte *newStart = (byte *)vpStart + sizeof(_member);
		return (void *)newStart;
	}
	void *fromWire ( void *vpStart )
	{
		unsigned char *vpCurr = (unsigned char *)vpStart;
		unsigned char *ret = fromLittleEndian ( (unsigned char *)vpStart, sizeof(_member) );
		_member = (titleType)*ret;
		byte *newEnd = (byte *)vpStart + sizeof(_member);
		return (void *)newEnd;
	}
}; /* End of Enum wrapper */
 
class CertificateHeader : public DataTypeInterface
{
protected:
	
	Int<64> size;
	bool isSetsize;	

	Int<32> version;
	bool isSetversion;	

	publicKeyType publicKey;
	bool isSetpublicKey;	

	recentDateType validFrom;
	bool isSetvalidFrom;	

	recentDateType validTo;
	bool isSetvalidTo;	

	revocationServerType revocationServer;
	bool isSetrevocationServer;	

	publicKeyType revocationServerPublicKey;
	bool isSetrevocationServerPublicKey;	
public:
	CertificateHeader () 
	{	
		initialize();
	}
	void initialize()
	{
		isSetsize = false;
		isSetversion = false;
		isSetpublicKey = false;
		isSetvalidFrom = false;
		isSetvalidTo = false;
		isSetrevocationServer = false;
		isSetrevocationServerPublicKey = false;
			}
	CertificateHeader ( CertificateHeader& __data ) 
	{
		initialize();
		if(! validate (__data)) throw "Error validating class CertificateHeader";
		 
		size=__data.size;
		isSetsize = true;
 
		version=__data.version;
		isSetversion = true;
 
		publicKey=__data.publicKey;
		isSetpublicKey = true;
 
		validFrom=__data.validFrom;
		isSetvalidFrom = true;
 
		validTo=__data.validTo;
		isSetvalidTo = true;
 
		revocationServer=__data.revocationServer;
		isSetrevocationServer = true;
 
		revocationServerPublicKey=__data.revocationServerPublicKey;
		isSetrevocationServerPublicKey = true;
	}
	/* Function to get out stream */
	void* toWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		 
		//Variable size
		vpCurr = size.toWire( vpCurr );
 
		//Variable version
		vpCurr = version.toWire( vpCurr );
 
		//Variable publicKey
		vpCurr = publicKey.toWire( vpCurr );
 
		//Variable validFrom
		vpCurr = validFrom.toWire( vpCurr );
 
		//Variable validTo
		vpCurr = validTo.toWire( vpCurr );
 
		//Variable revocationServer
		vpCurr = revocationServer.toWire( vpCurr );
 
		//Variable revocationServerPublicKey
		vpCurr = revocationServerPublicKey.toWire( vpCurr );
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
 
		//Variable publicKey
		vpCurr = publicKey.fromWire ( vpCurr );
 
		//Variable validFrom
		vpCurr = validFrom.fromWire ( vpCurr );
 
		//Variable validTo
		vpCurr = validTo.fromWire ( vpCurr );
 
		//Variable revocationServer
		vpCurr = revocationServer.fromWire ( vpCurr );
 
		//Variable revocationServerPublicKey
		vpCurr = revocationServerPublicKey.fromWire ( vpCurr );
		return vpCurr;
	}
	/* SET Functions */
	 
	void setsize ( Int<64>& __data )
	{
		if (validatesize( __data ) ){
			size = __data;
			isSetsize = true;
		}
		else throw "Error validating size";
	}
 
	void setversion ( Int<32>& __data )
	{
		if (validateversion( __data ) ){
			version = __data;
			isSetversion = true;
		}
		else throw "Error validating version";
	}
 
	void setpublicKey ( publicKeyType& __data )
	{
		if (validatepublicKey( __data ) ){
			publicKey = __data;
			isSetpublicKey = true;
		}
		else throw "Error validating publicKey";
	}
 
	void setvalidFrom ( recentDateType& __data )
	{
		if (validatevalidFrom( __data ) ){
			validFrom = __data;
			isSetvalidFrom = true;
		}
		else throw "Error validating validFrom";
	}
 
	void setvalidTo ( recentDateType& __data )
	{
		if (validatevalidTo( __data ) ){
			validTo = __data;
			isSetvalidTo = true;
		}
		else throw "Error validating validTo";
	}
 
	void setrevocationServer ( revocationServerType& __data )
	{
		if (validaterevocationServer( __data ) ){
			revocationServer = __data;
			isSetrevocationServer = true;
		}
		else throw "Error validating revocationServer";
	}
 
	void setrevocationServerPublicKey ( publicKeyType& __data )
	{
		if (validaterevocationServerPublicKey( __data ) ){
			revocationServerPublicKey = __data;
			isSetrevocationServerPublicKey = true;
		}
		else throw "Error validating revocationServerPublicKey";
	}
	/* GET Functions */
	 
	Int<64>& getsize()
	{
		return size;
	}
	bool is_setsize()
	{
		return isSetsize;
	}
 
	Int<32>& getversion()
	{
		return version;
	}
	bool is_setversion()
	{
		return isSetversion;
	}
 
	publicKeyType& getpublicKey()
	{
		return publicKey;
	}
	bool is_setpublicKey()
	{
		return isSetpublicKey;
	}
 
	recentDateType& getvalidFrom()
	{
		return validFrom;
	}
	bool is_setvalidFrom()
	{
		return isSetvalidFrom;
	}
 
	recentDateType& getvalidTo()
	{
		return validTo;
	}
	bool is_setvalidTo()
	{
		return isSetvalidTo;
	}
 
	revocationServerType& getrevocationServer()
	{
		return revocationServer;
	}
	bool is_setrevocationServer()
	{
		return isSetrevocationServer;
	}
 
	publicKeyType& getrevocationServerPublicKey()
	{
		return revocationServerPublicKey;
	}
	bool is_setrevocationServerPublicKey()
	{
		return isSetrevocationServerPublicKey;
	}
	 
	bool validatesize( Int<64>& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validateversion( Int<32>& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
		 
		if ( __data == 1 )
			return true;
				return false; 
	}
 
	bool validatepublicKey( publicKeyType& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validatevalidFrom( recentDateType& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						if ( __data >= DateTime(1,1,1980) && __data <= DateTime(1,1,2020) )
			return true;
		return false; 
	}
 
	bool validatevalidTo( recentDateType& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						if ( __data >= DateTime(1,1,1980) && __data <= DateTime(1,1,2020) )
			return true;
		return false; 
	}
 
	bool validaterevocationServer( revocationServerType& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validaterevocationServerPublicKey( publicKeyType& __data)
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
 
		bVal &= validatepublicKey( __data.publicKey );
 
		bVal &= validatevalidFrom( __data.validFrom );
 
		bVal &= validatevalidTo( __data.validTo );
 
		bVal &= validaterevocationServer( __data.revocationServer );
 
		bVal &= validaterevocationServerPublicKey( __data.revocationServerPublicKey );
		
		return bVal;
	}
	/* Get size of this class */
	int getSize ()
	{
		int iSz = 0;
		
		 
		iSz += size.getSize();
 
		iSz += version.getSize();
 
		iSz += publicKey.getSize();
 
		iSz += validFrom.getSize();
 
		iSz += validTo.getSize();
 
		iSz += revocationServer.getSize();
 
		iSz += revocationServerPublicKey.getSize();
		
		return iSz;
	}
};//Close class declaration.
 
class CertificateTrailer : public DataTypeInterface
{
protected:
	
	hashType syntaxHash;
	bool isSetsyntaxHash;	

	hashType semanticHash;
	bool isSetsemanticHash;	

	signatureType signature;
	bool isSetsignature;	
public:
	CertificateTrailer () 
	{	
		initialize();
	}
	void initialize()
	{
		isSetsyntaxHash = false;
		isSetsemanticHash = false;
		isSetsignature = false;
			}
	CertificateTrailer ( CertificateTrailer& __data ) 
	{
		initialize();
		if(! validate (__data)) throw "Error validating class CertificateTrailer";
		 
		syntaxHash=__data.syntaxHash;
		isSetsyntaxHash = true;
 
		semanticHash=__data.semanticHash;
		isSetsemanticHash = true;
 
		signature=__data.signature;
		isSetsignature = true;
	}
	/* Function to get out stream */
	void* toWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		 
		//Variable syntaxHash
		vpCurr = syntaxHash.toWire( vpCurr );
 
		//Variable semanticHash
		vpCurr = semanticHash.toWire( vpCurr );
 
		//Variable signature
		vpCurr = signature.toWire( vpCurr );
		return vpCurr;
	}
	/* Function to get out stream */
	void* fromWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		 
		//Variable syntaxHash
		vpCurr = syntaxHash.fromWire ( vpCurr );
 
		//Variable semanticHash
		vpCurr = semanticHash.fromWire ( vpCurr );
 
		//Variable signature
		vpCurr = signature.fromWire ( vpCurr );
		return vpCurr;
	}
	/* SET Functions */
	 
	void setsyntaxHash ( hashType& __data )
	{
		if (validatesyntaxHash( __data ) ){
			syntaxHash = __data;
			isSetsyntaxHash = true;
		}
		else throw "Error validating syntaxHash";
	}
 
	void setsemanticHash ( hashType& __data )
	{
		if (validatesemanticHash( __data ) ){
			semanticHash = __data;
			isSetsemanticHash = true;
		}
		else throw "Error validating semanticHash";
	}
 
	void setsignature ( signatureType& __data )
	{
		if (validatesignature( __data ) ){
			signature = __data;
			isSetsignature = true;
		}
		else throw "Error validating signature";
	}
	/* GET Functions */
	 
	hashType& getsyntaxHash()
	{
		return syntaxHash;
	}
	bool is_setsyntaxHash()
	{
		return isSetsyntaxHash;
	}
 
	hashType& getsemanticHash()
	{
		return semanticHash;
	}
	bool is_setsemanticHash()
	{
		return isSetsemanticHash;
	}
 
	signatureType& getsignature()
	{
		return signature;
	}
	bool is_setsignature()
	{
		return isSetsignature;
	}
	 
	bool validatesyntaxHash( hashType& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validatesemanticHash( hashType& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validatesignature( signatureType& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
	/* Validatior for all variables at once */
	bool validate ( CertificateTrailer& __data )
	{
		bool bVal = true;
		
		 
		bVal &= validatesyntaxHash( __data.syntaxHash );
 
		bVal &= validatesemanticHash( __data.semanticHash );
 
		bVal &= validatesignature( __data.signature );
		
		return bVal;
	}
	/* Get size of this class */
	int getSize ()
	{
		int iSz = 0;
		
		 
		iSz += syntaxHash.getSize();
 
		iSz += semanticHash.getSize();
 
		iSz += signature.getSize();
		
		return iSz;
	}
};//Close class declaration.
 
class currency : public DataTypeInterface
{
protected:
	
	Float32 amount;
	bool isSetamount;	

	currencyUnitsEnum units;
	bool isSetunits;	
public:
	currency () 
	{	
		initialize();
	}
	void initialize()
	{
		isSetamount = false;
		isSetunits = false;
			}
	currency ( currency& __data ) 
	{
		initialize();
		if(! validate (__data)) throw "Error validating class currency";
		 
		amount=__data.amount;
		isSetamount = true;
 
		units=__data.units;
		isSetunits = true;
	}
	/* Function to get out stream */
	void* toWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		 
		//Variable amount
		vpCurr = amount.toWire( vpCurr );
 
		//Variable units
		vpCurr = units.toWire( vpCurr );
		return vpCurr;
	}
	/* Function to get out stream */
	void* fromWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		 
		//Variable amount
		vpCurr = amount.fromWire ( vpCurr );
 
		//Variable units
		vpCurr = units.fromWire ( vpCurr );
		return vpCurr;
	}
	/* SET Functions */
	 
	void setamount ( Float32& __data )
	{
		if (validateamount( __data ) ){
			amount = __data;
			isSetamount = true;
		}
		else throw "Error validating amount";
	}
 
	void setunits ( currencyUnitsEnum& __data )
	{
		if (validateunits( __data ) ){
			units = __data;
			isSetunits = true;
		}
		else throw "Error validating units";
	}
	/* GET Functions */
	 
	Float32& getamount()
	{
		return amount;
	}
	bool is_setamount()
	{
		return isSetamount;
	}
 
	currencyUnitsEnum& getunits()
	{
		return units;
	}
	bool is_setunits()
	{
		return isSetunits;
	}
	 
	bool validateamount( Float32& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						/* Round off __data to required accuracy */
			return true;		
		return false; 
	}
 
	bool validateunits( currencyUnitsEnum& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
	/* Validatior for all variables at once */
	bool validate ( currency& __data )
	{
		bool bVal = true;
		
		 
		bVal &= validateamount( __data.amount );
 
		bVal &= validateunits( __data.units );
		
		return bVal;
	}
	/* Get size of this class */
	int getSize ()
	{
		int iSz = 0;
		
		 
		iSz += amount.getSize();
 
		iSz += units.getSize();
		
		return iSz;
	}
};//Close class declaration.
 
class usDollarType : public currency
{
protected:
	
	Int<32> conversionrate;
	bool isSetconversionrate;	
public:
	usDollarType () 
	{	
		initialize();
	}
	void initialize()
	{
		isSetconversionrate = false;
			}
	usDollarType ( usDollarType& __data ) : currency(__data) 
	{
		initialize();
		if(! validate (__data)) throw "Error validating class usDollarType";
		 
		conversionrate=__data.conversionrate;
		isSetconversionrate = true;
	}
	/* Function to get out stream */
	void* toWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		vpCurr = currency::toWire ( vpCurr );
		 
		//Variable conversionrate
		vpCurr = conversionrate.toWire( vpCurr );
		return vpCurr;
	}
	/* Function to get out stream */
	void* fromWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		vpCurr = currency::fromWire ( vpCurr );
		 
		//Variable conversionrate
		vpCurr = conversionrate.fromWire ( vpCurr );
		return vpCurr;
	}
	/* SET Functions */
	 
	void setconversionrate ( Int<32>& __data )
	{
		if (validateconversionrate( __data ) ){
			conversionrate = __data;
			isSetconversionrate = true;
		}
		else throw "Error validating conversionrate";
	}
	/* GET Functions */
	 
	Int<32>& getconversionrate()
	{
		return conversionrate;
	}
	bool is_setconversionrate()
	{
		return isSetconversionrate;
	}
	 
	bool validateamount( Float32& __data)
	{
		
		if (! currency::validateamount( __data) )
			return false;
		/* This code is generated according to various constraints specified in CDL */
						/* Round off __data to required accuracy */
			return true;		
		return false; 
	}
 
	bool validateunits( currencyUnitsEnum& __data)
	{
		
		if (! currency::validateunits( __data) )
			return false;
		/* This code is generated according to various constraints specified in CDL */
		 
		if ( __data == USD )
			return true;
				return false; 
	}
 
	bool validateconversionrate( Int<32>& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						if ( __data >= 1 && __data <= 50 )
			return true;
		return false; 
	}
	/* Validatior for all variables at once */
	bool validate ( usDollarType& __data )
	{
		bool bVal = true;
		
		bVal &= currency::validate(__data);
		 
		bVal &= validateamount( __data.amount );
 
		bVal &= validateunits( __data.units );
 
		bVal &= validateconversionrate( __data.conversionrate );
		
		return bVal;
	}
	/* Get size of this class */
	int getSize ()
	{
		int iSz = 0;
		
		iSz += currency::getSize();
		 
		iSz += conversionrate.getSize();
		
		return iSz;
	}
};//Close class declaration.
 
class pettyCash : public usDollarType
{
protected:
	public:
	pettyCash () 
	{	
		initialize();
	}
	void initialize()
	{
			}
	pettyCash ( pettyCash& __data ) : usDollarType(__data) 
	{
		initialize();
		if(! validate (__data)) throw "Error validating class pettyCash";
			}
	/* Function to get out stream */
	void* toWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		vpCurr = usDollarType::toWire ( vpCurr );
				return vpCurr;
	}
	/* Function to get out stream */
	void* fromWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		vpCurr = usDollarType::fromWire ( vpCurr );
				return vpCurr;
	}
	/* SET Functions */
		/* GET Functions */
		 
	bool validateamount( Float32& __data)
	{
		
		if (! usDollarType::validateamount( __data) )
			return false;
		/* This code is generated according to various constraints specified in CDL */
						return false; 
	}
	/* Validatior for all variables at once */
	bool validate ( pettyCash& __data )
	{
		bool bVal = true;
		
		bVal &= usDollarType::validate(__data);
		 
		bVal &= validateamount( __data.amount );
		
		return bVal;
	}
	/* Get size of this class */
	int getSize ()
	{
		int iSz = 0;
		
		iSz += usDollarType::getSize();
				
		return iSz;
	}
};//Close class declaration.
 
class nameType : public DataTypeInterface
{
protected:
	
	Array<Char,100> lastName;
	bool isSetlastName;	

	Array<Char,50> firstName;
	bool isSetfirstName;	

	Char middleInitial;
	bool isSetmiddleInitial;	

	titleTypeEnum title;
	bool isSettitle;	
public:
	nameType () 
	{	
		initialize();
	}
	void initialize()
	{
		isSetlastName = false;
		isSetfirstName = false;
		isSetmiddleInitial = false;
		isSettitle = false;
			}
	nameType ( nameType& __data ) 
	{
		initialize();
		if(! validate (__data)) throw "Error validating class nameType";
		 
		lastName=__data.lastName;
		isSetlastName = true;
 
		firstName=__data.firstName;
		isSetfirstName = true;
 
		middleInitial=__data.middleInitial;
		isSetmiddleInitial = true;
 
		title=__data.title;
		isSettitle = true;
	}
	/* Function to get out stream */
	void* toWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		 
		//Variable lastName
		vpCurr = lastName.toWire( vpCurr );
 
		//Variable firstName
		vpCurr = firstName.toWire( vpCurr );
 
		//Variable middleInitial
		vpCurr = middleInitial.toWire( vpCurr );
 
		//Variable title
		vpCurr = title.toWire( vpCurr );
		return vpCurr;
	}
	/* Function to get out stream */
	void* fromWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		 
		//Variable lastName
		vpCurr = lastName.fromWire ( vpCurr );
 
		//Variable firstName
		vpCurr = firstName.fromWire ( vpCurr );
 
		//Variable middleInitial
		vpCurr = middleInitial.fromWire ( vpCurr );
 
		//Variable title
		vpCurr = title.fromWire ( vpCurr );
		return vpCurr;
	}
	/* SET Functions */
	 
	void setlastName ( Array<Char,100>& __data )
	{
		if (validatelastName( __data ) ){
			lastName = __data;
			isSetlastName = true;
		}
		else throw "Error validating lastName";
	}
 
	void setfirstName ( Array<Char,50>& __data )
	{
		if (validatefirstName( __data ) ){
			firstName = __data;
			isSetfirstName = true;
		}
		else throw "Error validating firstName";
	}
 
	void setmiddleInitial ( Char& __data )
	{
		if (validatemiddleInitial( __data ) ){
			middleInitial = __data;
			isSetmiddleInitial = true;
		}
		else throw "Error validating middleInitial";
	}
 
	void settitle ( titleTypeEnum& __data )
	{
		if (validatetitle( __data ) ){
			title = __data;
			isSettitle = true;
		}
		else throw "Error validating title";
	}
	/* GET Functions */
	 
	Array<Char,100>& getlastName()
	{
		return lastName;
	}
	bool is_setlastName()
	{
		return isSetlastName;
	}
 
	Array<Char,50>& getfirstName()
	{
		return firstName;
	}
	bool is_setfirstName()
	{
		return isSetfirstName;
	}
 
	Char& getmiddleInitial()
	{
		return middleInitial;
	}
	bool is_setmiddleInitial()
	{
		return isSetmiddleInitial;
	}
 
	titleTypeEnum& gettitle()
	{
		return title;
	}
	bool is_settitle()
	{
		return isSettitle;
	}
	 
	bool validatelastName( Array<Char,100>& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validatefirstName( Array<Char,50>& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validatemiddleInitial( Char& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validatetitle( titleTypeEnum& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
	/* Validatior for all variables at once */
	bool validate ( nameType& __data )
	{
		bool bVal = true;
		
		 
		bVal &= validatelastName( __data.lastName );
 
		bVal &= validatefirstName( __data.firstName );
 
		bVal &= validatemiddleInitial( __data.middleInitial );
 
		bVal &= validatetitle( __data.title );
		
		return bVal;
	}
	/* Get size of this class */
	int getSize ()
	{
		int iSz = 0;
		
		 
		iSz += lastName.getSize();
 
		iSz += firstName.getSize();
 
		iSz += middleInitial.getSize();
 
		iSz += title.getSize();
		
		return iSz;
	}
};//Close class declaration.
 
class certName : public DataTypeInterface
{
protected:
	CertificateHeader certHeader;
	
	nameType name;
	bool isSetname;	

	currency amount;
	bool isSetamount;	
	CertificateTrailer certTrailer;
public:
	certName () 
	{	
		initialize();
	}
	void initialize()
	{
		isSetname = false;
		isSetamount = false;
		 
		Int<512> syntaxHash = "0xB79905613A3F2CD76682F1EA1E3FC2902A4B2922819DB3215BF0A78E5F663509E23DC8A918AFD91E";
		Int<512> semanticHash = "0xB79905613A3F2CD76682F1EA1E3FC2902A4B2922819DB3215BF0A78E5F663509E23DC8A918AFD91E";
		certTrailer.setsyntaxHash(syntaxHash);
		certTrailer.setsemanticHash(semanticHash);
	}
	certName ( certName& __data ) 
	{
		initialize();
		if(! validate (__data)) throw "Error validating class certName";
		 
		name=__data.name;
		isSetname = true;
 
		amount=__data.amount;
		isSetamount = true;
	}
	/* Function to get out stream */
	void* toWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		//Variable certHeader. 
		vpCurr = certHeader.toWire( vpCurr );
		 
		//Variable name
		vpCurr = name.toWire( vpCurr );
 
		//Variable amount
		vpCurr = amount.toWire( vpCurr );
		//Variable certTrailer.
		vpCurr = certTrailer.toWire( vpCurr );
		return vpCurr;
	}
	/* Function to get out stream */
	void* fromWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		vpCurr = certHeader.fromWire ( vpCurr );
		 
		//Variable name
		vpCurr = name.fromWire ( vpCurr );
 
		//Variable amount
		vpCurr = amount.fromWire ( vpCurr );
		vpCurr = certTrailer.fromWire ( vpCurr );
		return vpCurr;
	}
	/* SET Functions */
	void setcertHeader ( CertificateHeader& __data )
	{
		if (validatecertHeader ( __data ) ){
			certHeader = __data;
		}
		else throw "Error validating certificate Header";
	}
	 
	void setname ( nameType& __data )
	{
		if (validatename( __data ) ){
			name = __data;
			isSetname = true;
		}
		else throw "Error validating name";
	}
 
	void setamount ( currency& __data )
	{
		if (validateamount( __data ) ){
			amount = __data;
			isSetamount = true;
		}
		else throw "Error validating amount";
	}
	void setcertTrailer ( CertificateTrailer& __data )
	{
		if ( validatecertTrailer ( __data ) ){
			certTrailer = __data;
		}
		else
			throw "Error validating certificate Trailer";
	}
	/* GET Functions */
	CertificateHeader& getcertHeader()
	{
		return certHeader;
	}
	 
	nameType& getname()
	{
		return name;
	}
	bool is_setname()
	{
		return isSetname;
	}
 
	currency& getamount()
	{
		return amount;
	}
	bool is_setamount()
	{
		return isSetamount;
	}
	CertificateTrailer& getcertTrailer()
	{
		return certTrailer;
	}
	bool validatecertHeader( CertificateHeader& __data)
	{
		CertificateHeader H;
		return H.validate(__data);
	}
	 
	bool validatename( nameType& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validateamount( currency& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
	bool validatecertTrailer( CertificateTrailer& __data )
	{
		CertificateTrailer T;
		return T.validate(__data);
	}
	/* Validatior for all variables at once */
	bool validate ( certName& __data )
	{
		bool bVal = true;
		 bVal &= validatecertHeader(__data.certHeader); 
		 
		bVal &= validatename( __data.name );
 
		bVal &= validateamount( __data.amount );
		 bVal &= validatecertTrailer(__data.certTrailer); 
		return bVal;
	}
	/* Get size of this class */
	int getSize ()
	{
		int iSz = 0;
		 iSz += certHeader.getSize(); 
		 
		iSz += name.getSize();
 
		iSz += amount.getSize();
		 iSz += certTrailer.getSize(); 
		return iSz;
	}
	//Return serialized certificate bytes and the length.
	int getCertBytes(byte **stream)
	{
		//serialize header, class memebers and trailer
		int len = this->getSize() - certTrailer.getsignature().getSize();
		*stream = new byte[len];
		void *vpcurr = certHeader.toWire( (void *)(*stream) );
		vpcurr = name.toWire(vpcurr);
		vpcurr = amount.toWire(vpcurr);
		vpcurr = certTrailer.getsyntaxHash().toWire(vpcurr);
		vpcurr = certTrailer.getsemanticHash().toWire(vpcurr);
		return len;
	}
	//Generate a digitally signed sayAnything Certificate
	byte* generateCertificate( char *privfile )
	{
		CryptoPP::AutoSeededRandomPool rng;
		CryptoPP::RSA::PrivateKey privatekey;
		// Load the private key from file.
		CryptoPP::FileSource fs ( privfile, true);
		privatekey.BERDecode ( fs );
		CryptoPP::RSASS<CryptoPP::PKCS1v15,CryptoPP::SHA512>::Signer signer(privatekey);
		byte *signature = new byte[signer.MaxSignatureLength()];
		byte *stream;
		int len = getCertBytes(&stream);
		size_t siglen = signer.SignMessage(rng, (const byte *)stream, len, signature );
		// set the signature via fromWire()
		certTrailer.getsignature().fromWire( (const void*) signature);
		byte *certificate = new byte[this->getSize()];
		this->toWire( (void *)certificate );
		return certificate;
	}
	bool verifyCertificate ( char *pubfile, byte *certificate )
	{
		CryptoPP::RSA::PublicKey publickey;
		//Load the public key from file
		CryptoPP::FileSource fs ( pubfile, true);
		publickey.BERDecode ( fs );
		this->fromWire((void*)certificate);
		byte *stream;
		int len = getCertBytes( &stream );
		size_t siglen = (size_t)certTrailer.getsignature().getSize();
		byte *signature = new byte[siglen];
		certTrailer.getsignature().toWire((void *)signature);
		CryptoPP::RSASS<CryptoPP::PKCS1v15,CryptoPP::SHA512>::Verifier verifier(publickey);
		return verifier.VerifyMessage((const byte *)stream,len,signature,siglen);
	}
};//Close class declaration.
