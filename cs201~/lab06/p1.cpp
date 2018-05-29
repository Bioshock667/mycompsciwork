/* CS201 Programming Exercise : A string function
   Programmer:
	Who are you?
*/
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

/** string email (string first, string second)
   Makes a standard email address with a max of 8 characters
   @param string first holds the first name of a person
   @param string second holds the second name of a person
   @return The first character of first name plus the first 7 characters of the second name
*/
string  email( string first, string second)
{
	return first.substr(0,1) + second.substr(0,7) /* fill in this blank */;
}/*end email*/


int main()  // test the functions above using assert
{  
	assert( email ("richard", "botting") == "rbotting" );
	assert( email ("ernsto", "gomez") == "egomez" );
	assert( email ("george", "georgeiou") == "ggeorgei" );

	cout << "Success\n";

	return 0; // terminate program with zero errors.

}

