/* CS201 Project
   Programmer: Seth Lemanek
   Number in text: P3.6
   Description in text
	Roman numbers. Write a program that converts a positive integer into the Roman number system. The Roman number system has digits I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000. 
   Algorithm
	1.Ask user to enter a positive integer between 1-9999
	2.The user puts in a number.
	3.The program breaks the number into individual strings containing one number.
	4.The each number will be converted into its respective roman numeral.
*/
#include <string>
#include <iostream>

using namespace std;

int main()
{ 
	cout << "Please enter a positive integer between 1 - 3999.\n";
	string number;
	cin >> number;
	int sl = number.length();
	string first;
	string second;
	string third;
	string fourth;
	if (sl == 4)
	{
	first = number.substr(0,1);
	second = number.substr(1,1);
	third = number.substr(2,1);
	fourth = number.substr(3,1);
	}
	if (sl == 3)
	{
	  first = "";
	  second = number.substr(0,1);
	  third = number.substr(1,1);
	  fourth = number.substr(2,1);
	}
	if (sl == 2)
	{
	  first = "";
	  second = "";
	  third = number.substr(0,1);
	  fourth = number.substr(1,1);
	}
	if (sl == 1)
	{
	  first = "";
	  second = "";
	  third = "";
	  fourth = number.substr(0,1);
	}
	string firstr;
	string secondr;
	string thirdr;
	string fourthr;
	if (first == "") firstr = "";
	if (first == "1") firstr = "M";
	if (first == "2") firstr = "MM";
	if (first == "3") firstr = "MMM";
	if (second == "") firstr = "";
	if (second == "1") secondr = "C";
	if (second == "2") secondr = "CC";
	if (second == "3") secondr = "CCC";
	if (second == "4") secondr = "CD";
	if (second == "5") secondr = "D";
	if (second == "6") secondr = "DC";
	if (second == "7") secondr = "DCC";
	if (second == "8") secondr = "DCCC";
	if (second == "9") secondr = "CM";
	if (third == "") thirdr = "";
	if (third == "1") thirdr = "X";
	if (third == "2") thirdr = "XX";
	if (third == "3") thirdr = "XXX";
	if (third == "4") thirdr = "XL";
	if (third == "5") thirdr = "L";
	if (third == "6") thirdr = "LX";
	if (third == "7") thirdr = "LXX";
	if (third == "8") thirdr = "LXXX";
	if (third == "9") thirdr = "XC";
	if (fourth == "") fourthr = "";
	if (fourth == "1") fourthr = "I";
	if (fourth == "2") fourthr = "II";
	if (fourth == "3") fourthr = "III";
	if (fourth == "4") fourthr = "IV";
	if (fourth == "5") fourthr = "V";
	if (fourth == "6") fourthr = "VI";
	if (fourth == "7") fourthr = "VII";
	if (fourth == "8") fourthr = "VIII";
	if (fourth == "9") fourthr = "IX";
	cout << "The Roman numeral is: " << firstr << secondr << thirdr << fourthr << ".\n";
	return 0; // terminate program with zero errors.
}
