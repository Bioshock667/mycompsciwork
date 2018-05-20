#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
Person();

Person(string n, string a, string t, string e);

string get_name() const;

string get_address() const;

string get_telephone() const;

string get_email() const;

virtual string whatami();

void reset(string n, string a, string t, string e);

private:
string name;
string address;
string telephone;
string email;
};
#endif