//# include "../../libsayAnything/src/Int1.h"
# include <Int.h>

void printbits(byte);
int main()
{

  
  Int<4> i(1026561);
  Int<4> p(2);

  cout<<"i is : "<<i;
  cout<<"p is : "<<p;
  
  byte *wire = new byte[8];
  void *vpcurr = i.toWire((void *)wire);
  vpcurr = p.toWire( vpcurr );
  
  Int<4> j;
  Int<4> q;
  byte *from = new byte[8];
  void *vpfrom = j.fromWire((void *)wire);
  q.fromWire ( vpfrom );

  cout<<"from wire done!"<<endl;
  cout<<j<<endl;
  cout<<q<<endl;

  //cout<<j.getLong()<<endl;
  //cout<<q.getLong()<<endl;

  void * vpc = j.toWire( (void *)from);
  q.toWire( vpc );
  
  //COMPARE!
  for (int k=0; k<8; k++)
    if (wire[k] != from[k]){
      cout<<"Byte "<<k<<" not matched!\t";
      cout<<"wire byte is: ";printbits(wire[k]);
      cout<<"from byte is: ";printbits(from[k]);
    }

  cout<<"WIRE BITS:"<<endl;
  for( int k=0; k<8; k++)
    printbits(wire[k]);

  cout<<"FROM BITS:"<<endl;
  for(int k=0; k<8; k++)
    printbits(from[k]);
  
  cout<<endl;

  unsigned int *z = (unsigned int *)from;
  cout<<"taking int cast : " << z[0]<<endl;

  for(int i=0; i<4; i++)
    printbits(from[i]);
}

void printbits(byte b)
{
  for(int i=0; i<8; ++i)
    {
      if( b & 0x80 )
	cout<<"1";
      else
	cout<<"0";
      b<<=1;
    }
  cout<<endl;
}
