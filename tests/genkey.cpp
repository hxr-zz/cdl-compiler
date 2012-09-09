# include <crypto++/cryptlib.h>
# include <crypto++/rsa.h>
# include <crypto++/pssr.h>
# include <crypto++/files.h>
# include <crypto++/hex.h>
# include <crypto++/base64.h>
# include <crypto++/pkcspad.h>
# include <crypto++/osrng.h>

using namespace CryptoPP;

int main()
{
  AutoSeededRandomPool rng;
  
  RSA::PrivateKey privatekey;
  privatekey.Initialize ( rng, 1024);
  RSA::PublicKey publickey(privatekey);

  FileSink prsink ("privkey",true);
  privatekey.BEREncode(prsink);
  
  FileSink pusink ("pubkey", true);
  publickey.BEREncode(pusink);
}
