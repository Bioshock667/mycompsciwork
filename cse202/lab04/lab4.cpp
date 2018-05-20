#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Code
{
public:
  
  Code();  // Default constructor - loads and uses morse code

  string decode(vector<string> message);  // decodes a message 

private:

  vector<string> codewords; // this is a codeword vector parallel to A-Z
  vector<char> alpha; // this is the vector for A-Z

  vector<char>  alphacode(); // function builds the vector alpha - A B C etc.

  vector<string>  morsecode(); // function builds the vector codewords containing morse code

  char decode(string c); //returns the character for the codeword c.

};

Code::Code()
{
  alpha=alphacode();
  codewords=morsecode();
}

string Code::decode(vector<string> message)
{
  string output;
  for (int i=0; i<message.size(); i++)
    output+=decode(message[i]);
  return output;
}

char Code::decode(string c)
{
  for (int i=0; i<codewords.size(); i++)
  {
    if(c == codewords[i])
      return alpha[i];
  }
}
	
vector<string> Code::morsecode()
{ // This function returns a vector containing the morse code
 vector<string> temp(28);
 temp[0] =".-";
 temp[1] ="-...";
 temp[2] ="-.-.";
 temp[3] ="-..";
 temp[4] =".";
 temp[5] ="..-.";
 temp[6] ="--.";
 temp[7] ="....";
 temp[8] ="..";
 temp[9] =".---";
 temp[10] ="-.-";
 temp[11] =".-..";
 temp[12] ="--";
 temp[13] ="-.";
 temp[14] ="---";
 temp[15] =".--.";
 temp[16] ="--.--";
 temp[17] =".-.";
 temp[18] ="...";
 temp[19] ="-";
 temp[20] ="..-";
 temp[21] ="...-";
 temp[22] =".--";
 temp[23] ="-..-";
 temp[24] ="-.--";
 temp[25] ="--..";
 temp[26] =".......";
 temp[27] ="x";
 return temp;
}

vector<char> Code::alphacode()
{// This returns a vector containing the alphabet a-z and " "
 vector<char> temp;
 for (char c='A'; c<='Z'; c++)
      temp.push_back(c);
 temp.push_back(' ');
 temp.push_back('.');
 return temp;
}


int main()
{
  vector<string> input;
  string x;
  cin>>x;
  while (cin.good())
  {
    input.push_back(x);
    cin>>x;
  }
  Code C;
  cout<<C.decode(input)<<endl;
}
