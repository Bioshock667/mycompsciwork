#include <iostream>

using namespace std;
int i=1;
void staticScoped(int x);
#define dynamicScoped(x)	{ cout <<"dynamicScoped("<<x<<") i= "<< i<<endl; }
main()
{
   cout << "Global i =" << i << endl;
   int i=2;
   cout << "Main i =" << i << endl;

   {//inner block
	int i=3;
	cout <<"Inner i =" << i << endl;
	staticScoped(1);
	dynamicScoped(1);
   }//inner block

   cout << "Outer i=" << i << endl;
   staticScoped(2);
   dynamicScoped(2);
}//end main()
void staticScoped(int x){ cout <<"staticScoped("<<x<<") i= "<< i<<endl; }

