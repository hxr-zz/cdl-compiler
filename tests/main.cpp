# include "first3.cpp"
# include "Array.h"

//void printbits(byte b);
int main()
{

  RentalAgreement ra;
  //set the certificate header
    Int<4> size = 765;
  Int<32> version = 1;
   publicKeyType pubkey = 0;
  recentDateType validFrom = DateTime(1,1,2006);
  recentDateType validTo   = DateTime(1,1,2008);
  revocationServerType srv;
  string server ="http://certserv.rites.uic.edu";

  for (int i=0; i<server.length(); ++i)
     {
       Char x = server[i];
       srv.addElement(x);
     }

   publicKeyType srvkey = 0;

     CertificateHeader ch;
  ch.setsize ( size );
     ch.setversion ( version );
  ch.setvalidFrom ( validFrom );
  ch.setvalidTo ( validTo);
  ch.setrevocationServer ( srv );
  ch.setrevocationServerPublicKey ( srvkey );

  ra.setcertHeader (ch);
  
  cout<<"Ready to generate rent agreement certificate."<<endl<<endl;

   string oname;
   cout<<"Enter Owner's name: ";
   cin>>oname;

  unsigned int amount;
  cout<<"Enter rent amount per month: ";
  cin>>amount;

  unsigned int index;
  cout<<"Enter index: ";
  cin>>index;

  char letter;
  cout<<"Enter a letter: ";
  cin >> letter;

  float stock;
  cout<<"Enter stock: ";
  cin>>stock;

  double stock2;
  cout<<"Enter stock2: ";
  cin>>stock2;

  int month,year,day;
  cout<<"Enter a year: ";
  cin>>year;
  cout<<"Enter a month: ";
  cin>>month;
  cout<<"Enter a date: ";
  cin>>day;

  DateTime sdate(month,day,year);

  int x,y;
  cout<<"Enter a number:";
  cin>>x;
  cout<<"Enter another number:";
  cin>>y;

  Array<Int<32>,100> a;

  a[0]=(x);
  a[1]=(y);
  
  cout<<"Generating certificate..."<<endl;


  Int<4> amt ( amount );
  Int<64> idx ( index ); 
  Char let ( letter );
  Float32 stk ( stock );
  Float64 stk2 ( stock2 );

  
  
  ra.setrentPerMonth( amt );
  ra.setindex ( idx );
  ra.setletter(let);
  ra.setstock ( stk );
  ra.setstock2( stk2 );
  ra.setsdate(sdate);

//   Array<Char,100> name;

  Vector<Char> name;
  string sname = "satya";
  for (int i=0; i<oname.length(); ++i)
    {
      Char x = sname[i];
      name.addElement( x );
    }

//   byte *vecstream = new byte[name.getSize()];
//   name.toWire(vecstream);
//   for(int i=0; i<name.getSize(); ++i)
//     printbits(vecstream[i]);
//   cerr<<"\n";
//   //get it from wire again!
//   Vector<Char> name2;
//   name2.fromWire( (void *)vecstream);

//   //send it to wire again!
//   byte *vec2 = new byte [name2.getSize()];

//   name2.toWire( vec2 );
//   for(int i=0; i<name2.getSize(); ++i)
//     printbits(vec2[i]);

  ra.setname ( name );
  ra.settitle( a);
  
  byte *cert = ra.generateCertificate ("privkey");

  //dump the ceritficate!
  for (int i=0; i<ra.getSize(); ++i )
    cout<<(unsigned char)cert[i];

  cout<<endl;

  //  cout<<"Are you satisfied?";
  //cin>>amount;


  //verify it!

  //RentalAgreement ra1;
   if(ra.verifyCertificate("pubkey",cert))
    cout<<"verified successfully!"<<endl;
  else
    cout<<"Verification failed!"<<endl;

   cout<<"Rent per month is: "<<ra.getrentPerMonth()<<endl;


   Int<4> k = 1245;
   ra.setrentPerMonth(k);

   byte *cert2 = ra.generateCertificate("privkey");

   if(ra.verifyCertificate("pubkey",cert))
     cout<<"verified again"<<endl;
   else
     cout<<"verification failed!"<<endl;

   
//    Int<4> k = 1200;

//    if (k.isConvertableToLong()){
//      cout<<"Can convert to long.. doing it.."<<endl;
//      long j = k.getLong();
//      cout<<"k is: "<<j<<endl;
//    }
//    else
//     cout<<"Cannot convert k to long!"<<endl;

   //int *z = (int *)cert;
   //cout<<"Integer cast test: size = "<< z[0]<<endl;
}


void printbits(byte b)
{
  for(int i=0; i<8; ++i)
    {
      if( b & 0x80 )
	cerr<<"1";
      else
	cerr<<"0";
      b<<=1;
    }
  cerr<<endl;
}
