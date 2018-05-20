//Class: CSE 330
//Term: Spring 2014
//Instructor: George M. Georgiou
//Names: Seth Lemanek & Alden Amoranto
//Lab 3
//Title: Sieve of Eratosthenes

#include<iostream>
#include"list.h"

using namespace std;

void sieve(List<int> & values)
{
    unsigned int max = 101;
    int i;
    int array[max];
    // initalize all cells in the array
    for (i = 0; i < max; i++)
    {
	array[i] = i;
    }
     //search for non-zero cells
    for (i = 2; i*i < max; i++)
    {
	if (array[i] != 0)
	{
	  for (int j = i+i; j < max; j += i)
	     array[j] = 0; //multiples of i have been cleared
	}
    }

    for(int k = 0; k < max; k++)
    {  
      values.push_back(array[k]);//copy array onto list
    }

}
int main()
{
    List<int> nums;
    sieve(nums);//call sieve funct to make only prime numbers appear
    List<int>::iterator i = nums.begin();
    for (i = nums.begin(); i != nums.end(); i++)
    {
	
	   cout  << *i << " ";
    }
    cout << endl;
return 0;//end program with zero errors
}   
