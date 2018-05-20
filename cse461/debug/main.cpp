
#include <iostream>
#include <string>
#include "fsystem.h"
#include <vector>
using namespace std;

vector<string> block(string buffer, int b)
{
// blocks the buffer into a list of blocks of size b

vector<string> blocks;
int numberofblocks=0;

if (buffer.length() % b == 0) 
   { numberofblocks= buffer.length()/b;
   }
else 
   { numberofblocks= buffer.length()/b +1;
   }

string tempblock;
for (int i=0; i<numberofblocks; i++)
    { tempblock=buffer.substr(b*i,b);
      blocks.push_back(tempblock);
    }

int lastblock=blocks.size()-1;

for (int i=blocks[lastblock].length(); i<b; i++)
    { blocks[lastblock]+="#";
    }

return blocks;

}

int main()
{
    Filesys fdebug("debug", 128, 64);
    string buffer = "Hello World";
    vector <string> bblock = block(buffer, 64);
    fdebug.newfile("file1");
    int block = fdebug.addblock("file1", bblock[0]);
    string message;
    fdebug.readblock("file1", block, message);
    cout << "There is a message ... " << message << endl;
}
