
/* This program contains a function to compute square roots.
   It also shows how to generate random number in C++  */


#include <iostream>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

double squareroot(double x)

{ /* computes the square root of x */

/* make sure x is not negative .. no math crimes allowed! */
 assert( x >= 0 );
 if (x==0) return 0;

/* the sqrt must be between xhi and xlo */
 double xhi;
 double xlo;
 double guess;
if (x > 1)
{
 xhi = x;
 xlo = 0;
 guess = x/2;
}
else
{
 xhi = 1;
 xlo = x;
 guess = x/2;
}
/* We stop when guess*guess-x is very small */
if (x < 1)
{

  while (abs(guess*guess-x) > 0.0000001 )
   {
     if (guess*guess > x)  xhi = guess;
     else xlo = guess;
     guess = (xhi + xlo)/2;
   };
 }
else
{
 while (abs(guess*guess-x) > 0.0000001 )
   {
     if (guess*guess > x)  xhi = guess;
     else xlo = guess;
     guess = (xhi + xlo)/2;
   };
 }
 return guess;
 }

/* Test Stub */


int main()
 {
  double testvalue;
  cout << "\n Enter a TestValue= " ; 
  cin >> testvalue;
  cout << endl;
  double testresult = squareroot(testvalue);
  cout << "\n Square Root= " << testresult << "\n" ; 
  }

