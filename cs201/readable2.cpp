#include <iostream>
#include <string>
using namespace std;

int main()
{  
	string text;
	getline(cin, text);
	int n = text.length();
	  bool dipth = false;
	  bool silente = false;
	int syllables = 0; 
	int words = 0;
	int sentences = 0;
	for ( int i = 0; i <= n; i++) //loop counts syllables, words, and sentences
	{
	    int p = 1;
	    string letter = text.substr(i,1);
	    string secletter = text.substr(p,1);
	     
	   if (letter == "a" || letter == "e" || letter == "i" || letter == "o" || letter == "u")
	    {
		//if there is a vowel without one before it then a syllable is counted
		if (secletter == "a" || secletter == "e" || secletter == "i" || secletter == "o" || secletter == "u")
		{
		    syllables --;
		}
		else
		 syllables ++;
	   }
	   
	   
	   if ( letter == " " || letter == "." || letter == "!" || letter == "?")
		words ++; // counts words by finding spaces
	   
	   if ( letter == "." || letter == "!" || letter == "?")
		sentences ++;
	p ++;
	}
	cout << "# of syllables is: " << syllables << endl;
	cout << "# of words is: " << words << endl;
	cout << "# of sentences is: " << sentences << endl;
	return 0; // terminate program with zero errors.

}
