//Class: CSE 330
//Term: Spring 2014
//Name: Seth Lemanek
//Lab 1
//Array of Integers

#include<stdlib.h>
#include<iostream>

using namespace std;

int main()
{
  srand(10);//create a seed value for random num. gen.
  int a[52];
  int b[52];//both arrays carry a set of random numbers
 for (int i=0; i<52; i++)
  {
   a[i] = rand()%101;
   b[i] = rand()%101;
  }
  int c[52];
  for (int i=0; i<52; i++)
   c[i] = a[i]*b[i];//this loop array c has values set to products of values from other arrays
  for (int i=0; i<52; i++)
   cout << a[i]<<" ";//print out values in array a
   cout << endl;
  for (int i=0; i<52; i++)
   cout << b[i]<<" ";//print out values in array b
   cout << endl;
  for (int i=0; i<52; i++)
  cout << c[i]<<" ";//print out values of array c
  cout << endl;
}
  
