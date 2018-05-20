/* CS201 Project
   Programmer: Seth Lemanek
   Number in text: P6.5
   Description in text
	Write a function that merges two arrays, alternating elements from both arrays. If one array is shorter than
	the other, then alternate as long as you can then append the remaining elements from the longer array.
   Algorithm
	1._
	2._
	3._
	...
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> merge( vector<int>& a,  vector<int>& b)
{
	
	int min_size;
	int asize = a.size()-1;
	if(a.size() <= b.size())
		min_size = a.size();
	else if(a.size() > b.size())
		min_size = b.size();
	int pos = 1;
	vector <int> c;
	for(int k = 0; k < a.size(); k++)
		c.push_back(a[k]);
	for (int j = 0; j <= min_size; j++)
	{
		int last = c.size() - 1;
		c.push_back(c[last]);
		for (int i = last; i > pos; i--)
			c[i] = c[i-1];
		c[pos] = b[j];
		pos = pos + 2;
	}

	if(a.size() < b.size())
		c[c.size()-1] = b[b.size()-1];
	
	return c;
}		
int main()
{  
	vector<int> x (4);
	x[0] = 1;
	x[1] = 4;
	x[2] = 9;
	x[3] = 16;

	vector<int> y (5);
	y[0] = 9;
	y[1] = 7;
	y[2] = 4;
	y[3] = 9;
	y[4] = 11;

	int min_size;
	if(x.size() <= y.size())
		min_size = x.size();
	else if(x.size() > y.size())
		min_size = y.size();
	
	vector<int> z = merge(x,y);
	
	for(int i = 0; i < z.size(); i++)
		cout << z[i] << " ";
	cout << endl;
	
	return 0; // terminate program with zero errors.

}

