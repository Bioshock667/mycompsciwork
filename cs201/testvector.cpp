#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> a (5);
	a[0] = 5;
	a[1] = 4;
	a[2] = 3;
	a[3] = 2;
	a[4] = 1;
	a.push_back(0);
	
	cout << a[0] << a[1] << a[2] << a[3] << a[4] << a[5] << endl;

	return 0;
}
