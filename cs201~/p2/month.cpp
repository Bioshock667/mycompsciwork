/* CS201 Project
   Programmer: Seth Lemanek
   Number in text: P1.19
   Description in text
	Write a program that transforms numbers 1,2,3, ..., 12 into the corresponding month names January, Feburary, March, ..., December.
   Algorithm
	1.Program asks user to enter a number between 1-12
	2.When the user enters a number from 1-12, program will make a substring from a pre-existing substring
	3.To do this the program will translate the value to 0 and multiples of 9 (9 is the highest amount of letters in a month.
	4.The program will use that value to choose an initial letter in the string, thus choosing a month name and the 8 following letters
	5.The program will display the chosen subtring in the text
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{  
	string m = "January  February March    April    May      June     July     SeptemberAugust   October  November December "; // the declared month list variable

	cout << "Select a number between 1-12 to get the corresponding month.\n"; //ask for number

	int n;
	cin >> n; // define and assign value for n

	string month = m.substr(9 * (n-1), 9); // use value of na to choose month substrings

	cout << "The month is " << month << ".\n"; // displays month

	return 0; // terminate program with zero errors.

}
