//Class: CSE 330
// Term: Spring 2014
// Instructor: George M. Georgiou
// Name: Seth Lemanek
// Lab 8
// Title: selection sort test

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

//selection sort
int main()
{
cout << "Please print a number to test:\n";
int n;
cin >> n;
vector<int> v (n);
fill(v.begin(),v.begin()+n-1, 1);
int j;
int elem;
//insertion sort
for (int i = 1; i < n; i++)
    for (elem = v[i], j = i-1; j >=0 and elem < v[j]; j--)
        v[j+1] = v[j];
    v[j+1] = elem;
return 0;
}
