#include <iostream>
#include <vector>
#include <string>

#include "morsecode.h"

using namespace std;


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
