#ifndef FACULTY_H
#define FACULTY_H
#include "employee.h"
#include <string>

using namespace std;

class Faculty : public Employee
{
public:
Faculty(string n, string a, string t, string e, string o, string sl, string h, string r, string st);
string get_rank() const;
string get_status() const;
private:
string rank;
string status;
};
#endif
