#include <iostream>
#include <string>
#include <vector>

#include "morsecode.h"

using namespace std;

int main()
{
   vector<char> input;
   char x;
   cin>>x;
   while (cin.good())
   {
	input.push_back(x);
	cin>>x;
   }
   Code C;
   cout<<C.encode(input)<<endl;
}
