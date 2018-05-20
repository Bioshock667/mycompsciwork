#include <iostream>
using namespace std;
int i=1;
main()
{
   cout << "i=" << i << endl;
   int j=2;
   cout << "i=" << i << endl;
   cout << "j=" << j << endl;

   {//inner block
	int k=3;
	cout <<"  i=" << i << endl;
	cout <<"  j=" << j << endl;
	cout <<"  k=" << k << endl;
   }//inner block

   cout << "i=" << i << endl;
   cout << "j=" << j << endl;
}//end main()

