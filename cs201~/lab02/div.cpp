// Author: Dick Botting
// File: div.cpp
// April 5th 2005

/* Use Case
  The user inputs two numbers and the computer outputs their ratio.
     1. Computer outputs a prompt.
     2. user inputs 2 numbers.
     3. Computer computes the result of dividing the first number by the second.
     4. Computer outputs the result.
*/

#include <iostream>
using namespace std;

main( )  
{ 
   double first, second;
  
   cout << "Enter two numbers separated by white space: ";
   cin >> first >> second;
   double result = first / second;
   cout << first << '/' << second << '=' << result << "\n";
 
   return 0;

}


