/**********************************************************************
Programmer: Kay Zemoudeh
Date:       9/14/97
Revised:    S I Lemanek
Date:       Apr 30 2013
Program:    smallest.cpp

This program finds and prints the mean of a set of integers.
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

   cin >> number;
   int size = 1;
   int total = number;/*the mean of all the numbers input so far.*/

   while (!cin.fail())
   { 
      size++;
      cin >> number;
      total = total + number;
   }/*end while*/
   int mean = total/size;
   
   
   cout << "The mean is " << mean << "\n";
   return 0;
}/*end main*/ 