#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include <string>

using namespace std;

class Student : public virtual Person
{
public:
Student(string n, string a, string t, string e, string st);
string get_status();
string virtual whatami();
private:
string status;
};
#endif
