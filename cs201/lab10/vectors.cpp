/*
	Suppose that we want to input an unknown number of numbers and then
	print them out forwards and then backwards, using a vector. We will
	push ints onto the back of a vector called v. We will then print 
	each item in v in turn. Finally we will print the vector backwards.
	You can download the code from [ Vector.cpp ] but here are the 
	highlights. First we must declare the facilities we want to use
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void print( const vector<int>& ) ;//utility function outputs a vector of ints
void print_backwards( const vector<int> &);
int sum( const vector <int> &);
double mean(const vector <int> &);
int max(const vector <int> &);
int min(const vector <int> &);
int range(const vector <int> &);
int sum_of_squares(const vector <int> &);
double variance(const vector <int> &);
double sd(const vector <int> &);
/*Then we describe the main program: */
int main()
{
	vector<int> v;
	int number;

	cout <<"Input some numbers and then end the input\n";
	while(cin>>number){
		v.push_back(number);
	}//while(more)

	print(v);
	print_backwards(v);
	cout << "The standard deviance is: " << sd(v) << endl;

}//main

/* Finally the two procedures that print out the data: */
void print_backwards( const vector<int> &a)
{
	for(int i=a.size()-1; i>=0; --i)
		cout << a[i] << " ";

	cout << endl;
	cout << "----------------"<<endl;

}//print_backwards
void print( const vector<int>& a)
{
	for(int i=0; i<a.size(); ++i)
		cout << a[i] << " ";

	cout << endl;
	cout << "----------------"<<endl;

}//print
int sum( const vector <int> & v )
{
	int total = 0;
	for(int i = 0; i <= v.size()-1; i++)
		total = total + v[i];
	return total;	
}
double mean(const vector <int> & v){return sum(v)/v.size();}
int max(const vector <int> & v)
{
	int maximum = v[0];
	for(int i = 1; i <= v.size()-1; i++)
	{
		if(v[i] > maximum)
			maximum = v[i];
	}
	return maximum;
}
int min(const vector <int> & v)
{
	int minimum = v[0];
	for(int i = 1; i <= v.size()-1; i++)
	{
		if(v[i] <= minimum)
			minimum = v[i];
	}
	return minimum;
}
int range(const vector <int> & v) {return max(v) - min(v);}
int sum_of_squares(const vector <int> & v)
{
	int total = 0;
	for(int i = 0; i <= v.size()-1; i++)
		total = total + v[i] * v[i];
	return total;
}
double variance(const vector <int> & v){return (sum_of_squares(v)-mean(v)*sum(v))/(v.size()-1);}
double sd(const vector <int> & v){return sqrt(variance(v));}
