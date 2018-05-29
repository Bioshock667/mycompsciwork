/*This program has errors in it.
  They are all in the function called 'flip'.
   If `flip` was correct then the main program would compile
	and run as shown.
   The code for flip does not compile and also has logic errors.
   Correct all the errors in function `flip`.
   Mark your changes on the code below.
   Do NOT mark any change to anything but `flip`.
   'assert( test)' stops the program if the test is false.  It is an excellent tool
     for testing functions and arguments!
*/
#include <iostream>
#include <cassert>
using namespace std;
/***********Change nothing above this line***************/


void flip ( int  &i )

/* PURPOSE: flips 1 and 0.  
	If i is 0, i is changed to 1
	If i is 1, i is changed to 0
   GIVEN: the value of variable i must either be 1 or 0.
*/

{
	assert( (i==1) or (i==0) );

	if(i == 1)

		i=0;

	else

		i=1;

}


/***********Change nothing below this line***************/
int main()
{
	int i = 1;
	assert(i==1);
	flip(i);
	assert(i==0);
	flip(i);
	assert(i==1);
	cout << "Success!\n";
	return 0;
}
