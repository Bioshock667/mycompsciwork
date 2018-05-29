/* Example of a string of ifs and ifelses by RJBotting 2010
*/
#include <iostream>
using namespace std;
int main()
{
       int i;
       cout << "Input a number: ";
       cin >> i;
       if ( cin.fail() )
       {  cout << "Not a number!"<<"\n";
          return 1;
       }

       if ( i <= 0 )
       {  cout << "I can not handle numbers less than 1 "<<"\n";
          return 2;
       }

       if ( i%2 != 0)
            if( i%3 != 0)
                 if( i%5 != 0)
                    if( i%7 != 0)
			if( i < 9*9)
                           	cout  << i << " is prime!";
			else
				cout << i << " may be prime!";
                    else
                           cout  << i << " is divisible by 7!";
                 else
                    cout << i << " is divisible by 5!";
            else
                 cout << i << " is divisible by 3!";
       else
            cout << i << " is divisible by 2!";

       cout << "\n";
       return 0;
}
