#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include <string>

using namespace std;

class Student : public Person
{
public:
Student(string n, string a, string t, string e, string st);
string get_status();
private:
string status;
};
#endif
