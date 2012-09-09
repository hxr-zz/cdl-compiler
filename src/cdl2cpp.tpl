{{! C++ Code template for cdlcc (CDL compiler) output }}
{{! author: Satya Popuri, RITES. spopuri@cs.uic.edu }}
{{! date: dec 21, 2006 }}

/** The code below is generated from CDL specified in {{SOURCE_FILE}}.
 *  {{>LICENCE_TEXT}}
 */

# include <CertStdDef.h>
{{#CERT_INCLUDES}}
# include <crypto++/cryptlib.h>
# include <crypto++/rsa.h>
# include <crypto++/pkcspad.h>
# include <crypto++/files.h>
# include <crypto++/osrng.h>
{{/CERT_INCLUDES}}

{{#TYPEDEFS}}{{! Defintions for non-class ADTs go here }}
typedef {{VAR_TYPE}} {{VAR_NAME}};
{{/TYPEDEFS}}

{{#ENUM_WRAPPER}}{{! This section describes class wrappers for enums }}

class {{VAR_TYPE}}Enum : public DataTypeInterface
{
public:
	{{VAR_TYPE}} _member;

	/* Constructors */
	{{VAR_TYPE}}Enum() { }

	{{VAR_TYPE}}Enum ( {{VAR_TYPE}}Enum& t )
	{
		_member = t._member;
	}

	{{VAR_TYPE}}Enum ( {{VAR_TYPE}} t )
	{
		_member = t;
	}

	void operator = ( {{VAR_TYPE}} t )
	{
		_member = t;
	}

	void operator = ( {{VAR_TYPE}}Enum& t )
	{
		_member = t._member;
	}

	bool operator == ( {{VAR_TYPE}} t )
	{
		return (_member == t );
	}

	bool operator == ( {{VAR_TYPE}}Enum& t )
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
		
		_member = ({{VAR_TYPE}})*ret;
	
		byte *newEnd = (byte *)vpStart + sizeof(_member);

		return (void *)newEnd;
	}
}; /* End of Enum wrapper */

{{/ENUM_WRAPPER}}

{{#CLASS_DECL}} {{! This section describes a class declaration }}

class {{CLASS_NAME}} : public {{BASE_CLASS_NAME}}
{
protected:
	{{#CLASS_CERT_HEADER}}
	CertificateHeader certHeader;
	{{/CLASS_CERT_HEADER}}

	{{#CLASS_VARS}}{{! This section declares all variables in a class }}
	{{CLASS_VAR_TYPE}} {{CLASS_VAR_NAME}};
	bool isSet{{CLASS_VAR_NAME}};	{{! Boolean variables to check if each variable is set }}
	{{/CLASS_VARS}}
	
	{{#CLASS_CERT_TRAILER}}
	CertificateTrailer certTrailer;
	{{/CLASS_CERT_TRAILER}}

public:
	{{! Constructors }}

	{{CLASS_NAME}} () 
	{	
		initialize();
	}
	void initialize()
	{
		{{#SET_INIT_SECTION}}
		isSet{{CLASS_VAR_NAME}} = false;
		{{/SET_INIT_SECTION}}

		{{#TRAILER_INIT}} {{! this section will initialize certTrailer }}
		Int<512> syntaxHash = {{SYN_HASH}};
		Int<512> semanticHash = {{SEM_HASH}};
		certTrailer.setsyntaxHash(syntaxHash);
		certTrailer.setsemanticHash(semanticHash);
		{{/TRAILER_INIT}}
	}

	{{CLASS_NAME}} ( {{CLASS_NAME}}& __data ) {{#DERIVED_CLS_CONSTR}}: {{BASE_CLASS_NAME}}(__data) {{/DERIVED_CLS_CONSTR}}
	{
		
		initialize();
		if(! validate (__data)) throw "Error validating class {{CLASS_NAME}}";
		
		{{#CLASS_COPY_CTOR}} {{! This section copies variables from __data to this class }}

		{{CLASS_VAR_NAME}}=__data.{{CLASS_VAR_NAME}};
		isSet{{CLASS_VAR_NAME}} = true;

		{{/CLASS_COPY_CTOR}}
	}

	/* Function to get out stream */
	void* toWire(void *vpStart)
	{
		void* vpCurr = vpStart;
		
		{{#HDR_TOWIRE_FN}}
		//Variable certHeader. 
		vpCurr = certHeader.toWire( vpCurr );
		{{/HDR_TOWIRE_FN}}

		{{#DERIVED_CLS_TOWIRE}}
		vpCurr = {{BASE_CLASS_NAME}}::toWire ( vpCurr );
		{{/DERIVED_CLS_TOWIRE}}

		{{#CLASS_TOWIRE_FN}} {{! This section serializes all class vars }}
		
		//Variable {{CLASS_VAR_NAME}}
		vpCurr = {{CLASS_VAR_NAME}}.toWire( vpCurr );
		
		{{/CLASS_TOWIRE_FN}}

		{{#TRL_TOWIRE_FN}}
		//Variable certTrailer.
		vpCurr = certTrailer.toWire( vpCurr );
		{{/TRL_TOWIRE_FN}}

		return vpCurr;
	}


	/* Function to get out stream */
	void* fromWire(void *vpStart)
	{
		void* vpCurr = vpStart;

		{{#HDR_FROMWIRE_FN}}
		vpCurr = certHeader.fromWire ( vpCurr );
		{{/HDR_FROMWIRE_FN}}
	
		{{#DERIVED_CLS_FROMWIRE}}
		vpCurr = {{BASE_CLASS_NAME}}::fromWire ( vpCurr );
		{{/DERIVED_CLS_FROMWIRE}}	

		{{#CLASS_FROMWIRE_FN}} {{! This section serializes all class vars }}
		
		//Variable {{CLASS_VAR_NAME}}
		vpCurr = {{CLASS_VAR_NAME}}.fromWire ( vpCurr );
		
		{{/CLASS_FROMWIRE_FN}}

		{{#TRL_FROMWIRE_FN}}
		vpCurr = certTrailer.fromWire ( vpCurr );
		{{/TRL_FROMWIRE_FN}}

		return vpCurr;
	}

	/* SET Functions */
	{{! For certificate classes }}
	{{#HDR_SET_FN}}
	void setcertHeader ( CertificateHeader& __data )
	{
		if (validatecertHeader ( __data ) ){
			certHeader = __data;
		}
		else throw "Error validating certificate Header";
	}
	{{/HDR_SET_FN}}

	{{#CLASS_SETTERS}} {{! This section expands SET functions for all variables in a class }}

	void set{{CLASS_VAR_NAME}} ( {{CLASS_VAR_TYPE}}& __data )
	{
		if (validate{{CLASS_VAR_NAME}}( __data ) ){
			{{CLASS_VAR_NAME}} = __data;
			isSet{{CLASS_VAR_NAME}} = true;
		}
		else throw "Error validating {{CLASS_VAR_NAME}}";
	}

	{{/CLASS_SETTERS}}

	{{#TRL_SET_FN}}
	void setcertTrailer ( CertificateTrailer& __data )
	{
		if ( validatecertTrailer ( __data ) ){
			certTrailer = __data;
		}
		else
			throw "Error validating certificate Trailer";
	}
	{{/TRL_SET_FN}}

	/* GET Functions */
	{{#HDR_GET_FN}}
	CertificateHeader& getcertHeader()
	{
		return certHeader;
	}
	{{/HDR_GET_FN}}

	{{#CLASS_GETTERS}} {{! This section expands GET functions for all variables in a class }}
	
	{{CLASS_VAR_TYPE}}& get{{CLASS_VAR_NAME}}()
	{
		return {{CLASS_VAR_NAME}};
	}
  
	bool is_set{{CLASS_VAR_NAME}}()
	{
		return isSet{{CLASS_VAR_NAME}};
	}

	{{/CLASS_GETTERS}}

	{{#TRL_GET_FN}}
	CertificateTrailer& getcertTrailer()
	{
		return certTrailer;
	}
	{{/TRL_GET_FN}}

	{{#HDR_VAL_FN}}
	bool validatecertHeader( CertificateHeader& __data)
	{
		CertificateHeader H;
		return H.validate(__data);
	}
	{{/HDR_VAL_FN}}

	{{#CLASS_VALIDATORS}} {{! This section expands VALIDATE functions for all variables in a class }}
	
	bool validate{{CLASS_VAR_NAME}}( {{CLASS_VAR_TYPE}}& __data)
	{

		{{#BASE_CLASS_VALIDATOR}}{{! This section calls the base class validator for derived classes}}
		if (! {{BASE_CLASS_NAME}}::validate{{CLASS_VAR_NAME}}( __data) )
			return false;
		{{/BASE_CLASS_VALIDATOR}}

		/* This code is generated according to various constraints specified in CDL */
		{{#FIXED_RANGE}} {{! validation for a fixed range }}
		if ( __data == {{VALUE}} )
			return true;
		{{/FIXED_RANGE}}

		{{#LEFT_OPEN_RIGHT_CLOSED}} {{! validation for a left_open_right_close range }}
		if ( __data >= {{LEFT_BOUND}} && __data < {{RIGHT_BOUND}} )
			return true;
		{{/LEFT_OPEN_RIGHT_CLOSED}}

		{{#LEFT_CLOSED_RIGHT_OPEN}}
		if ( __data > {{LEFT_BOUND}} && __data < {{RIGHT_BOUND}} )
			return true;
		{{/LEFT_CLOSED_RIGHT_OPEN}}

		{{#OPEN_RANGE}}
		if ( __data >= {{LEFT_BOUND}} && __data <= {{RIGHT_BOUND}} )
			return true;
		{{/OPEN_RANGE}}
		
		{{#CLOSED_RANGE}}
		if ( __data > {{LEFT_BOUND}} && __data < {{RIGHT_BOUND}} )
			return true;
		{{/CLOSED_RANGE}}

		{{#CHECK_ACCURACY}}
		/* Round off __data to required accuracy */
			return true;		
		{{/CHECK_ACCURACY}}

		return {{RET_VAL}}; 
	}
	
	{{/CLASS_VALIDATORS}}

	{{#TRL_VAL_FN}}
	bool validatecertTrailer( CertificateTrailer& __data )
	{
		CertificateTrailer T;
		return T.validate(__data);
	}
	{{/TRL_VAL_FN}}
	
	/* Validatior for all variables at once */
	bool validate ( {{CLASS_NAME}}& __data )
	{
		bool bVal = true;
		
		{{#HDR_VAL_VAR}} bVal &= validatecertHeader(__data.certHeader); {{/HDR_VAL_VAR}}

		{{#DERIVED_CLS_VALIDATE}}
		bVal &= {{BASE_CLASS_NAME}}::validate(__data);
		{{/DERIVED_CLS_VALIDATE}}

		{{#VALIDATE_VARS}} {{! This section expands validation code for all variables in the class }}

		bVal &= validate{{CLASS_VAR_NAME}}( __data.{{CLASS_VAR_NAME}} );
		
		{{/VALIDATE_VARS}}
		
		{{#TRL_VAL_VAR}} bVal &= validatecertTrailer(__data.certTrailer); {{/TRL_VAL_VAR}}
		return bVal;
	}

	/* Get size of this class */
	int getSize ()
	{
		int iSz = 0;
		
		{{#HDR_SIZEUP_VAR}} iSz += certHeader.getSize(); {{/HDR_SIZEUP_VAR}}

		{{#DERIVED_CLS_SIZE}}
		iSz += {{BASE_CLASS_NAME}}::getSize();
		{{/DERIVED_CLS_SIZE}}

		{{#SIZEUP_VARS}} {{! This section expands size code for all variable in the class }}
		
		iSz += {{CLASS_VAR_NAME}}.getSize();
		
		{{/SIZEUP_VARS}}
	
		{{#TRL_SIZEUP_VAR}} iSz += certTrailer.getSize(); {{/TRL_SIZEUP_VAR}}
		return iSz;
	}

	{{#CERT_FNS}}

	//Return serialized certificate bytes and the length.
	int getCertBytes(byte **stream)
	{
		//serialize header, class memebers and trailer
		int len = this->getSize() - certTrailer.getsignature().getSize();
	
		*stream = new byte[len];
		void *vpcurr = certHeader.toWire( (void *)(*stream) );

		{{#CLASS_MEM_TOWIRE}}
		vpcurr = {{CLASS_VAR_NAME}}.toWire(vpcurr);
		{{/CLASS_MEM_TOWIRE}}

		vpcurr = certTrailer.getsyntaxHash().toWire(vpcurr);
		vpcurr = certTrailer.getsemanticHash().toWire(vpcurr);

		return len;
	}
	
	//Generate a digitally signed sayAnything Certificate
	byte *generateCertificate( char *privfile)
	{
		CryptoPP::RSA::PrivateKey privatekey;

		// Load the private key from file.
		CryptoPP::FileSource fs ( privfile, true);
		privatekey.BERDecode ( fs );

		return this->generateCertificate( privatekey );
	}			

	byte* generateCertificate( CryptoPP::RSA::PrivateKey privatekey )
	{
		CryptoPP::AutoSeededRandomPool rng;
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

		return this->verifyCertificate ( publickey, certificate);
	}
		
	bool verifyCertificate ( CryptoPP::RSA::PublicKey publickey, byte *certificate )
	{
		this->fromWire((void*)certificate);

		byte *stream;
		int len = getCertBytes( &stream );

		size_t siglen = (size_t)certTrailer.getsignature().getSize();
		byte *signature = new byte[siglen];
		
		certTrailer.getsignature().toWire((void *)signature);

		CryptoPP::RSASS<CryptoPP::PKCS1v15,CryptoPP::SHA512>::Verifier verifier(publickey);

		return verifier.VerifyMessage((const byte *)stream,len,signature,siglen);
	}
	{{/CERT_FNS}}

};//Close class declaration.

{{/CLASS_DECL}}
