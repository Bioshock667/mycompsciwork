#ifndef STAFF_H
#define STAFF_H
#include "employee.h"
#include <string>

using namespace std;

class Staff : public Employee
{
public:
Staff(string n, string a, string t, string e, string o, string sl, string h, string p);
string get_position() const;
string virtual whatami();
private:
string position;
};
#endif
