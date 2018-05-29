/**********************************************************************
Programmer: Kay Zemoudeh
Date:       9/14/97
Revised:    R J Botting
Date:       Apr 23 2005
Program:    largest.cpp

This program finds and prints the largest of a set of integers.
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

   int largest=number;/*the largest of all the numbers input so far.*/

   cin >> number;

   while (!cin.fail())
   {
       if (number > largest)
       {
            largest = number;
       }/*end if*/

       cin >> number;

   }/*end while*/

   cout << "The largest is " << largest << "\n";
   return 0;
}/*end main*/ 
