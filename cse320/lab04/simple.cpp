#include <iostream>

using namespace std;
int i=1;
main()
{
   cout << "i=" << i << endl;
   i=2;
   cout << "i=" << i << endl;

   {//inner block
	i=3;
	cout <<"  i=" << i << endl;
	   {//inner inner block
		i=4;
		cout <<"    i=" << i << endl;
	   }//inner inner block
	cout <<"  i=" << i << endl;
   }//inner block

   cout << "i=" << i << endl;
}//end main()

