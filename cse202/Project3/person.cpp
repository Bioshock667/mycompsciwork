#include "person.h"
#include <string>
#include <iostream>

using namespace std;

Person::Person()
{
   cout << "Constructing person ...\n";
}

Person::Person(string n, string a, string t, string e)
{  
   this->name = n;
   this->address = a;
   this->telephone = t;
   this->email = e;
}
string Person::get_name() const
{
   return name;
}
string Person::get_address() const
{  
   return address;
}
string Person::get_telephone() const
{
   return telephone;
}

string Person::get_email() const
{
   return email;
}

string Person::whatami()
{
  return "Person";
}

void Person::reset(string n, string a, string t, string e)
{
   this->name = n;
   this->address = a;
   this->telephone = t;
   this->email = e;
}
