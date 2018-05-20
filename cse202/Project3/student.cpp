#include "person.h"
#include "student.h"
#include <string>

using namespace std;

Student::Student(string n, string a, string t, string e, string st) : Person(n, a, t, e)
{
   reset(n,a,t,e);
   this->status = st;
}

string Student::get_status()
{
   return status;
}

string Student::whatami()
{
   return "Student";
}
