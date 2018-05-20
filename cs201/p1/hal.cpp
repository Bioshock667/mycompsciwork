/*	CS201 Project
	Programmer: Seth Lemanek
	Exercise: P1.2
	Description: Greets the User
	Algorithm
		1. Says hello to user
		2. Asks for the name of user
		3. The user types in his or her name
		4. Program says the user name and greets


*/
#include <iostream>
#include <string>

using namespace std;

int main() 

{	
	cout << "Hello, my name is Hal!\n"; //Greet the user

	cout << "What is your name?\n"; //Ask the user's name

	string user_name; //Define string variable

	getline(cin, user_name); //Gets name from cin


	cout << "Hello, " << user_name << ". I am glad to meet you!\n"; //Greet user with own name

	return 0; // Terminate program with zero errors.
}
