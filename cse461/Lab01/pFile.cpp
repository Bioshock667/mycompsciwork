//////////////////////////////////////////////////////////////////////////////////////////////
//Programmer: Seth Lemanek
//Prof:Owen Murphy
//Class: Cse 461 Adv. Operating Systems
//Date: October 5, 2015
//////////////////////////////////////////////////////////////////////////////////////////////
#include "pFile.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

PasswordFile::PasswordFile(string filename)
{
    this->filename = filename;
    ifstream pwFile;
    pwFile.open(filename.c_str());
    string u, p;
    while(pwFile.good())
    {
	pwFile >> u >> p;
	user.push_back(u);
	password.push_back(p);
    }
    pwFile.close();
}

void PasswordFile::addpw(string newuser, string newpassword)
{	
    string nUser = encrypt(newuser);
    for(int i = 0; i < user.size(); i++)
    {
	if(nUser == user[i])
	{
	    cout << newuser << " already exists!" << endl;
	    return;
	}
    }
    string nPassword = encrypt(newpassword);
    user.push_back(nUser);
    password.push_back(nPassword);
    synch();
}

bool PasswordFile::checkpw(string oUser, string oPassword)
{
    string eUser = encrypt(oUser);
    string ePassword = encrypt(oPassword);
    for(int i = 0; i < user.size(); i++)
    {
	if(user[i] == eUser)
	{
	    if(password[i] == ePassword)
	    {
		return true;
		break;
	    }
	    else
		return false;
	}
	else
	    return false;
    }
}

void PasswordFile::synch()
{
    ofstream outfile;
    outfile.open(filename.c_str());
    for(int i = 0; i < user.size(); i++)
    {
	outfile << user[i] << ' ' << password[i] << endl;
    }
    outfile.close();
}

int PasswordFile::salt = 1;

void PasswordFile::newSalt(int ns)
{
    salt = ns;
}

string PasswordFile::encrypt(string s)
{
    for(int i = 0; i < s.size(); i++)
	s[i] += salt;
    return s;
}
