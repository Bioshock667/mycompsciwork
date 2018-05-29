/* CS201 Project
   Programmer: Seth Lemanek
   Number in text: P3.19
   Description in text
	Flesch Readability Index. The following index was invented by Flesch as a simple tool to gauge the legibility of a document without linguistic analysis.
   Algorithm
	1.Asks for text and counts the number of characters
	2.A loop checks every character for vowels, spaces, periods, etc. until the last character
	3.Each vowel found adds a syllable except for dipthongs and silent e's.
	4.Each space or ending punctuation marks signal a new word except when double spacing between sentences.
	5.Each ending puntuation mark also signals a new sentences.
	6.Displays number of syllables, words, and sentences after loop is finished.
	7.Calculates then displays the readablity index using said syllables, words, and sentences.
	8.Use if statements to determine the grade level capable of reading the text based on index.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Enter text to determine its Flesch readability index." << endl;
	string text;
	getline(cin, text);
	int n = text.length();
	bool dipth = false;
	bool silente = false;
	bool dousp = false;
	int syllables = 0;
	int words = 0;
	int sentences = 0;

	for ( int i = 0; i <= n; i++) //loop counts syllables, words, and sentences
	{
	    string letter = text.substr(i,1); //"letter" represent each character

	    if ( letter == "a" || letter == "i" || letter == "o" || letter == "u")
	    {
	        if (!dipth)
            {
	        dipth = true;
            syllables ++; //if there is a vowel without one before it then a syllable is counted
            }
                else
                    dipth = false;//else do not add
	    }
        if (letter == "e")//checked e independently for silent e's
            {
                silente = true;

                if (dipth)
                {
                    dipth = false;
                }
                else
                    syllables ++;
            }

	   if (!(letter == "a" || letter == "e" || letter == "i" || letter == "o" || letter == "u"))
		dipth = false; //no vowels implies no possibility of a dipthong

	   if (letter == " ")
	   {
	       if (silente)
           {
                if (dipth)
                {
                    silente = false; //if vowel before e do nothing
                    dipth = false;
                }
                else
                {
                    syllables --; //if no vowel before e then take away syllable for silent e
                    silente = false;
                }
           }
	   }
        if (dousp) //checks for double spaces
       {
           if (letter == " " || letter == "." || letter == "!" || letter == "?"|| letter == ";" || letter == ":")
            words --;// if there is double space or space after ending punct. mark take away word
           else
            dousp = false;// else there is no double space
       }
	   if ( letter == " " || letter == "." || letter == "!" || letter == "?"|| letter == ";" || letter == ":")
       {
		words ++; // counts words by finding spaces and ending punct. marks
		dousp = true;
       }
	   if ( letter == "." || letter == "!" || letter == "?" || letter == ";" || letter == ":")
		sentences ++;//add sentence for every ending punct. mark
	}
	cout << "# of syllables is: " << syllables << endl;
	cout << "# of words is: " << words << endl;
	cout << "# of sentences is: " << sentences << endl;
	float index = 201.835 - 84.6 * (syllables/words) - 1.015 * (words/sentences);
	cout << "The Flesch readability index is: " << int(index) << endl;
	cout << "Only a ";

	if ( index > 100)
	cout << "4th grader through kindergardener";
	else if (91 <= index && index <= 100)
		cout << "5th grader";
	else if (81 <= index && index <= 90)
		cout << "6th grader";
	else if (71 <= index && index <= 80)
		cout << "7th grader";
	else if (66 <= index && index <= 70)
		cout << "8th grader";
	else if (61 <= index && index <= 65)
		cout << "9th grader";
	else if (51 <= index && index <= 60)
		cout << "high school student";
	else if (31<= index && index <= 50)
		cout << "college student";
	else if (0 <= index && index <= 30)
		cout << "college graduate";
	else if ( index < 0)
		cout << "law school graduate";
	cout << " or higher grade can read this text." << endl;
	return 0; // terminate program with zero errors.
}
