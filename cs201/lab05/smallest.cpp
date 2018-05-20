/**********************************************************************
Programmer: Kay Zemoudeh
Date:       9/14/97
Revised:    S I Lemanek
Date:       Apr 30 2013
Program:    smallest.cpp

This program finds and prints the smallest of a set of integers.
It inputs one integer at a time until ^D is entered from standard input
or end-of-file is reached, if standard input is redirected.
**********************************************************************/

#include <iostream>
using namespace std;

int main()
{ 
   int number; /*the latest number input.*/
   cin >> number;

   if(cin.fail())
   {
      cout << "Error: missing or incorrect data\n";
      return 1;
   }

   int smallest=number;/*the smallest of all the numbers input so far.*/

   cin >> number;

   while (!cin.fail())
   {
       if (number < smallest)
       {
            smallest = number;
       }/*end if*/

       cin >> number;

   }/*end while*/

   cout << "The smallest is " << smallest << "\n";
   return 0;
}/*end main*/ 
