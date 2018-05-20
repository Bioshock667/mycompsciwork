//  GEORGE:  Helps you do simple Boolean algebra by
//			printing out a truth table of an expression
// By RJBotting 2010.
// This program is the first prototype...
// It is named for George Boole who invented this stuff.
// It demonstrates the "tab" character "\t",
// using a for loop with int's to generate the two Boolean values, 
// and the "boolalpha" input/output manipulator to print bool values.
// 2011 with 3 variables and an expression from page 147 R3.11

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "p\tq\tr\t(p && q) || !r\t!(p && (q || !r)) \n";

	for (int i=0; i<2; i++)
	{
	   bool p = (i==1);

	   for(int j=0; j<2; j++)
	   {
	      bool q = (j==1);
	      for(int k=0; k<2; k++)
	      {
	          bool r = (k==1);
	          bool s = ( (p&&q) || !r );
		  bool t = !(p && (q || !r));
	          cout << boolalpha << p << "\t"<<q 
			<< "\t" << r << "\t" << s << "\t" << "\t" << t <<"\n";
	      }//end for k
	   }//end for j

	}//end for i

	return 0;
}

