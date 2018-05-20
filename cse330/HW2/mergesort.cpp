//Class: CSE 330
//Term: Spring 2014
//Instructor: George M. Georgiou
//Names: Seth Lemanek
//Homework 2
//Title: Merge Sort Program
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

template<class Itr>
void m_sort(Itr start, unsigned int low, unsigned int high)
{
    if(low + 1 < high) {
	unsigned int center = (high + low) / 2;//split data in two
	m_sort (start, low, center);//continually split lower half
	m_sort (start, center, high);//continually split upper half
	inplace_merge (start + low, start + center, start + high);//place all split data in order
	}
}

template<class T>
void mergeSort(vector<T> & s)
{
    m_sort(s.begin(), 0, s.size());
}//make m_sort automatically work with vectors


int main() {
	vector<int> v(14);
	v[0] = 8; v[1] = 3; v[2] = 9; v[3] = 4; v[4] = 5; v[5] = 6;
	v[6] = 11; v[7] = 12; v[8] = 7; v[9] = 8; v[10] = 15; v[11] = 14;
	v[12] = 9; v[13] = 20; //initialize then define vector
	vector<int>::iterator itr = v.begin();
	while (itr != v.end()) {
		cout << *itr << " ";
		itr++;
		}//output vector before merge sort
	cout << "\n";
	mergeSort(v);
	itr = v.begin();
	while (itr != v.end()) {
		cout << *itr << " ";
		itr++;
		}//output vector after merge sort
	cout << "\n";
}