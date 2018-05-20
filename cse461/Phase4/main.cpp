////////////////////////////////////
//Homework 4
//Seth Lemanek
//November 30, 2015
///////////////////////////////////////////

#include "dbase.h"
#include <iostream>
#include <string>

using namespace std;

int main() 
{
    Table table("database", 128, 256, "ffile", "ifile");
    table.Build_Table("data_input.txt");
    cout << "Enter a date:\n";
    string value;
    cout << "$";
    getline(cin, value);
    while(value != "quit")
    {
	int code = table.Search(value);
	cout << "$";
	getline(cin, value);
        
    }
    cout << "Program finished.\n";
    return 0;
}
