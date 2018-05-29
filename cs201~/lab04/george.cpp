//  GEORGE:  Helps you do simple Boolean algebra by
//			printing out a truth table of an expression
// By RJBotting 2010.
// This program is the first prototype...
// It is named for George Boole who invented this stuff.
// It demonstrates the "tab" character "\t",
// using a for loop with int's to generate the two Boolean values, 
// and the "boolalpha" input/output manipulator to print bool values.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "p\tq\tr\n";

	for (int i=0; i<2; i++)
	{
	   bool p = (i==1);

	   for(int j=0; j<2; j++)
	   {
	      bool q = (j==1);
	      bool r = ( !(p && q) == (!p || !q ));
	      cout << boolalpha << p << "\t"<<q << "\t" << r <<"\n";
	   }//end for j

	}//end for i

	return 0;
}

