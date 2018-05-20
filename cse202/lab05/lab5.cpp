
/* Simple buffer overflow example             RJBotting 9/27/2004
    Warning this is an example with many pieces of insecure code and information.
    Inspired by
	INSIDE THE BUFFER OVERFLOW ATTACK: MECHANISM, METHOD, & PREVENTION
	Mark E. Donaldson, SANS Corporation.
	April 3, 2002
	GSEC Version 1.3
*/
#include <cassert>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <curses.h>

using namespace std;

void get(char * askfor, int numchars, char * input);
void get_password(char * name, char * pwd);

int main()
{
    //  Change these character arrays to strings.

	char name[8]; char pwd[8]; char passwd[8]; 
	cout << "Address of name =" <<  &name <<"\n";
	cout << "Address of pwd =" <<  &pwd <<"\n";
	cout << "Address of passwd =" <<  &passwd <<"\n";

	bool authenticated=false;
	while(! authenticated)
	{

                // input the name here 
		get("Name", 7, name);
                // get the password pwd for the name
		get_password(name, pwd);
               // input a password passwd
		get("Password", 7, passwd);
	 	// cout <<pwd<<" vs " <<passwd<<endl;
                // compare the two passwords
		authenticated= ! strncmp(pwd,passwd,7);

		if(!authenticated)
			cout << "Please try again\n";
	}
	cout << "Welcome "<<name<<"\n";

	//...
	return 0;
}
void get(char * askfor, int numchars, char * input)
{
   // this inputs a chracter array from input ... change it to input a string
	cout << askfor<<"("<<numchars<<" characters): ";
	cin>>input;
	return;
}
void get_password(char * name, char * pwd)
{
        // Yuch! This returns pwd depending on the variable name
        // Rewrite so it accepts a string name and returns a string

	if(!strcmp(name,"botting"))
		strcpy(pwd, "123456");
	else if(!strcmp(name,"ernesto"))
		strcpy(pwd, "765432");
	else if(!strcmp(name,"tong"))
		strcpy(pwd, "234567");
	else
		 strcpy(pwd, "qwert");
	return;
}

