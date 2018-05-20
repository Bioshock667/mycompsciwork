#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class UserPw
{
 public:
 UserPw()
   {
	user = "";
	password = "";
   }
 UserPw(string user, string password)//Constructor
   {
    this->user = user;
    this->password = password;
   }
 string GetUser(){return user;} // returns the user
 string GetPassword() {return password;}
 
 private :
 string user;
 string password;
};

class PasswordFile
{
 public:
 PasswordFile(string filename)// opens the file and reads the names/passwords in the vector entry
{
   this->filename = filename;
   ifstream input_data;
   input_data.open(this->filename.c_str());
   string u;
   string p;
   input_data >> u >> p;
   while (input_data.good())
   {
	entry.push_back(UserPw(u,p));
	input_data >> u >> p;
	
   }
   input_data.close();
}
 vector<UserPw> getFile() // returns the vector entry 
 { return entry;}
 void addpw(UserPw newentry) //this adds a new user/password to entry and writes entry to the file filename
  {  
	entry.push_back(newentry);
	ofstream output_data;
	output_data.open(filename.c_str(),ios::out|ios::app);
	output_data << newentry.GetUser() << newentry.GetPassword() << endl;
	output_data.close();
 }
 bool checkpw(string user, string passwd) // returns true is user exists and password matches
  {
	for(int i = 0; i < entry.size(); i++)
	{
	   if(user == entry[i].GetUser() && passwd == entry[i].GetPassword())
	      return true;
	}
	return false;
  }
		
 private:
 string filename; // the file that contains password information
 vector<UserPw> entry; // the list of usernames/passwords
};

int main()
{
 PasswordFile passfile("passwords.txt");
 passfile.addpw(UserPw("dbotting","123qwe"));
 passfile.addpw(UserPw("egomez","qwerty"));
 passfile.addpw(UserPw("tongyu","liberty"));
 // write some lines to see if passwords match users
}
