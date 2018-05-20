#include "stack.h"
#include <list>
#include <iostream>
using namespace std;
bool is_palindrome(string);
int main()
{
string palind;
cout << endl;
cout << "Enter string for palindrom test: ";
cin >> palind;
cout << endl;
if (is_palindrome(palind))
    cout << palind << " is a palindrome" << endl << endl;
else
    cout << palind << " is not a palindrome" << endl << endl;
return 0;
}
bool is_palindrome(string palind)
{
    Stack<char> thestack;
    int len = palind.length();
    int k = 1;
    while (k <= len/2)
    {
	thestack.push(palind[k-1]);
	k++;
    }
    if (len%2 != 0)
    k++; // for odd length strings
    char next;
    while (k <= len)
    {
    	next = thestack.top();
	thestack.pop();
	if (next != palind[k-1])
	return false;
	k++;
    }
    return true;
}
