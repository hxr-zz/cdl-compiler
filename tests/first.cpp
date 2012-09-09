/** The code below is generated from CDL specified in first.certdef.
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
 
class CertificateHeader : public DataTypeInterface
{
protected:
	
	Int<4> size;
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
	 
	void setsize ( Int<4>& __data )
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
	 
	Int<4>& getsize()
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
	 
	bool validatesize( Int<4>& __data)
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
 
class RentalAgreement : public DataTypeInterface
{
protected:
	CertificateHeader certHeader;
	
	Int<4> rentPerMonth;
	bool isSetrentPerMonth;	

	Int<64> index;
	bool isSetindex;	

	Char letter;
	bool isSetletter;	

	Float32 stock;
	bool isSetstock;	

	Float64 stock2;
	bool isSetstock2;	

	DateTime sdate;
	bool isSetsdate;	

	Vector<Char> name;
	bool isSetname;	

	Array<Int<32>,100> title;
	bool isSettitle;	
	CertificateTrailer certTrailer;
public:
	RentalAgreement () 
	{	
		initialize();
	}
	void initialize()
	{
		isSetrentPerMonth = false;
		isSetindex = false;
		isSetletter = false;
		isSetstock = false;
		isSetstock2 = false;
		isSetsdate = false;
		isSetname = false;
		isSettitle = false;
		 
		Int<512> syntaxHash = "0x28F71623A2251CE515FAD54AF9F5B0D31D2DC0BC069AB3687E823B3B94954ED3BE068267B519697A";
		Int<512> semanticHash = "0xA75C68EFF92E9642D0A2F23CA12A296A46F86A0F60664A3363B99671D0338619EF2246602707158D";
		certTrailer.setsyntaxHash(syntaxHash);
		certTrailer.setsemanticHash(semanticHash);
	}
	RentalAgreement ( RentalAgreement& __data ) 
	{
		initialize();
		if(! validate (__data)) throw "Error validating class RentalAgreement";
		 
		rentPerMonth=__data.rentPerMonth;
		isSetrentPerMonth = true;
 
		index=__data.index;
		isSetindex = true;
 
		letter=__data.letter;
		isSetletter = true;
 
		stock=__data.stock;
		isSetstock = true;
 
		stock2=__data.stock2;
		isSetstock2 = true;
 
		sdate=__data.sdate;
		isSetsdate = true;
 
		name=__data.name;
		isSetname = true;
 
		title=__data.title;
		isSettitle = true;
	}
	/* Function to get out stream */
	void* toWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		//Variable certHeader. 
		vpCurr = certHeader.toWire( vpCurr );
		 
		//Variable rentPerMonth
		vpCurr = rentPerMonth.toWire( vpCurr );
 
		//Variable index
		vpCurr = index.toWire( vpCurr );
 
		//Variable letter
		vpCurr = letter.toWire( vpCurr );
 
		//Variable stock
		vpCurr = stock.toWire( vpCurr );
 
		//Variable stock2
		vpCurr = stock2.toWire( vpCurr );
 
		//Variable sdate
		vpCurr = sdate.toWire( vpCurr );
 
		//Variable name
		vpCurr = name.toWire( vpCurr );
 
		//Variable title
		vpCurr = title.toWire( vpCurr );
		//Variable certTrailer.
		vpCurr = certTrailer.toWire( vpCurr );
		return vpCurr;
	}
	/* Function to get out stream */
	void* fromWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		vpCurr = certHeader.fromWire ( vpCurr );
		 
		//Variable rentPerMonth
		vpCurr = rentPerMonth.fromWire ( vpCurr );
 
		//Variable index
		vpCurr = index.fromWire ( vpCurr );
 
		//Variable letter
		vpCurr = letter.fromWire ( vpCurr );
 
		//Variable stock
		vpCurr = stock.fromWire ( vpCurr );
 
		//Variable stock2
		vpCurr = stock2.fromWire ( vpCurr );
 
		//Variable sdate
		vpCurr = sdate.fromWire ( vpCurr );
 
		//Variable name
		vpCurr = name.fromWire ( vpCurr );
 
		//Variable title
		vpCurr = title.fromWire ( vpCurr );
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
	 
	void setrentPerMonth ( Int<4>& __data )
	{
		if (validaterentPerMonth( __data ) ){
			rentPerMonth = __data;
			isSetrentPerMonth = true;
		}
		else throw "Error validating rentPerMonth";
	}
 
	void setindex ( Int<64>& __data )
	{
		if (validateindex( __data ) ){
			index = __data;
			isSetindex = true;
		}
		else throw "Error validating index";
	}
 
	void setletter ( Char& __data )
	{
		if (validateletter( __data ) ){
			letter = __data;
			isSetletter = true;
		}
		else throw "Error validating letter";
	}
 
	void setstock ( Float32& __data )
	{
		if (validatestock( __data ) ){
			stock = __data;
			isSetstock = true;
		}
		else throw "Error validating stock";
	}
 
	void setstock2 ( Float64& __data )
	{
		if (validatestock2( __data ) ){
			stock2 = __data;
			isSetstock2 = true;
		}
		else throw "Error validating stock2";
	}
 
	void setsdate ( DateTime& __data )
	{
		if (validatesdate( __data ) ){
			sdate = __data;
			isSetsdate = true;
		}
		else throw "Error validating sdate";
	}
 
	void setname ( Vector<Char>& __data )
	{
		if (validatename( __data ) ){
			name = __data;
			isSetname = true;
		}
		else throw "Error validating name";
	}
 
	void settitle ( Array<Int<32>,100>& __data )
	{
		if (validatetitle( __data ) ){
			title = __data;
			isSettitle = true;
		}
		else throw "Error validating title";
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
	 
	Int<4>& getrentPerMonth()
	{
		return rentPerMonth;
	}
	bool is_setrentPerMonth()
	{
		return isSetrentPerMonth;
	}
 
	Int<64>& getindex()
	{
		return index;
	}
	bool is_setindex()
	{
		return isSetindex;
	}
 
	Char& getletter()
	{
		return letter;
	}
	bool is_setletter()
	{
		return isSetletter;
	}
 
	Float32& getstock()
	{
		return stock;
	}
	bool is_setstock()
	{
		return isSetstock;
	}
 
	Float64& getstock2()
	{
		return stock2;
	}
	bool is_setstock2()
	{
		return isSetstock2;
	}
 
	DateTime& getsdate()
	{
		return sdate;
	}
	bool is_setsdate()
	{
		return isSetsdate;
	}
 
	Vector<Char>& getname()
	{
		return name;
	}
	bool is_setname()
	{
		return isSetname;
	}
 
	Array<Int<32>,100>& gettitle()
	{
		return title;
	}
	bool is_settitle()
	{
		return isSettitle;
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
	 
	bool validaterentPerMonth( Int<4>& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validateindex( Int<64>& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validateletter( Char& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validatestock( Float32& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validatestock2( Float64& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validatesdate( DateTime& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validatename( Vector<Char>& __data)
	{
				/* This code is generated according to various constraints specified in CDL */
						return true; 
	}
 
	bool validatetitle( Array<Int<32>,100>& __data)
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
	bool validate ( RentalAgreement& __data )
	{
		bool bVal = true;
		 bVal &= validatecertHeader(__data.certHeader); 
		 
		bVal &= validaterentPerMonth( __data.rentPerMonth );
 
		bVal &= validateindex( __data.index );
 
		bVal &= validateletter( __data.letter );
 
		bVal &= validatestock( __data.stock );
 
		bVal &= validatestock2( __data.stock2 );
 
		bVal &= validatesdate( __data.sdate );
 
		bVal &= validatename( __data.name );
 
		bVal &= validatetitle( __data.title );
		 bVal &= validatecertTrailer(__data.certTrailer); 
		return bVal;
	}
	/* Get size of this class */
	int getSize ()
	{
		int iSz = 0;
		 iSz += certHeader.getSize(); 
		 
		iSz += rentPerMonth.getSize();
 
		iSz += index.getSize();
 
		iSz += letter.getSize();
 
		iSz += stock.getSize();
 
		iSz += stock2.getSize();
 
		iSz += sdate.getSize();
 
		iSz += name.getSize();
 
		iSz += title.getSize();
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
		vpcurr = rentPerMonth.toWire(vpcurr);
		vpcurr = index.toWire(vpcurr);
		vpcurr = letter.toWire(vpcurr);
		vpcurr = stock.toWire(vpcurr);
		vpcurr = stock2.toWire(vpcurr);
		vpcurr = sdate.toWire(vpcurr);
		vpcurr = name.toWire(vpcurr);
		vpcurr = title.toWire(vpcurr);
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
