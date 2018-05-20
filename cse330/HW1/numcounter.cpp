//Class: CSE330
//TErm: Spring 2014
////Instructor: George M. Georgiou
//Name: Seth Lemanek
//Homework 1
//Title: Vector Assignment
#include<iostream>
#include<fstream>
#include<math.h>
#include<assert.h>
#include"vector.h"

using namespace std;
  
template<class T>
T average (vector<T> values, T size)
{
 if (size != 0)
 {   
    T total = size;
    T sum = 0;
    for (int i = 0; i < size; i++)
      sum += values[i];//continues to add up until size is reached
    T result = sum/total;
    return result;
 }
 else//the size is zero
    return 0;
}

template<class T>
T variance(vector<T> values, T size)//finds variance
{
    T total = size;
    T sum = 0;
    T diff = 0;
    T avg = average(values, size);
    for(int i = 0; i < size; i++)
    {
        diff = (values[i] - avg)*(values[i] - avg);//sum((a(i)-avg)^2)
	sum += diff;
    }
    T result = sum/(total - 1);
    return result;
}
int main()
{
    vector<float> nums (100);
    float num;
    int i = 0;
    cout << "Do you want the program to read from a file? (y/n) \n";
    char response;
    cin >> response;
    if(response == 'y')//user must type in name of file
    {
	string name;
	cout << "Please enter the name of the file: \n";
    	cin >> name;
	ifstream infile;
	infile.open(name.c_str());
       	if(cin.fail())
	{
	    cout << "Error: failure to find file!\n";
	}
        while (infile.good())
	{
	    infile >> num;
	    nums[i] = num;
	    i++;
	}
	infile.close();
    }
    else//user types in the set of numbers then type a letter
    {
	cout << "Please type the numbers then type a character.\n";

       	while (cin.good())
    	{
	   if (i < nums.size())
	   {
	   cin >> num;
	   nums[i] = num;
	   }
	   else//if counter i indicates number goes over capacity
	   nums.resize(1);
	   i++;
    	}
    }
    float n = 0.0;
    for (int j = 0; j < nums.size(); j++)
    {
	if(nums[j] != 0)
	  n++;//count all numbers not zero
    }
    cout << nums[0] << nums[1] << nums[2] << endl;
    cout << "Average: " <<  average(nums, n) << endl;
    cout << "Variance: " << variance(nums, n) << endl;
    
}

