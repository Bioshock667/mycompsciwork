#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "person.h"
#include <string>

using namespace std;

class Employee : public Person
{
public:
Employee(string n, string a, string t, string e, string o, string sl, string h);
string get_office() const;
string get_salary() const;
string get_hiredate() const;
private:
string office;
string salary;
string hiredate;
};
#endif
