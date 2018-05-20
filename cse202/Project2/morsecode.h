#ifndef MORSECODE_H
#define MORSECODE_H

#include <string>
#include <vector>

using namespace std;

class Code
{
public:
  
  Code();  // Default constructor - loads and uses morse code

  Code(vector<int> codewords);  // constructor loading customized code
  
  string encode(vector<char> message);  // encodes a message consisting of A-Z

  string decode(vector<string> message);  // decodes a message 

private:

  vector<string> codewords; // this is a codeword vector parallel to A-Z
  vector<char> alpha; // this is the vector A-Z

  vector<char>  alphacode(); // function builds the vector alpha - A B C etc.

  vector<string>  morsecode(); // function the vector codewords containing  morse code

  string encode(char x); //returns the codeword for the character x
  char decode(string c); //returns the character for the codeword c.

};
#endif
