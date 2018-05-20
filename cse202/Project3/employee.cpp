#include "person.h"
#include "employee.h"
#include <string>

using namespace std;

Employee::Employee(string n, string a, string t, string e, string o, string sl, string h) : Person(n, a, t, e)
{
   reset(n,a,t,e);
   this->office = o;
   this->salary = sl;
   this->hiredate = h;
}

string Employee::get_office() const
{
   return office;
}

string Employee::get_salary() const
{
   return salary;
}

string Employee::get_hiredate() const
{
   return hiredate;
}

string Employee::whatami() 
{
  return "Employee";
}
