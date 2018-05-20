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
vector<int> v (n);
fill(v.begin(),v.begin()+n-1, 1);
cin >> n;
for (int i = 0; i < n-1; i++)
    for (int j = i+1; j < n; j++)
        if (v[i] > v[j])
            swap(v[i], v[j]);
return 0;
}
