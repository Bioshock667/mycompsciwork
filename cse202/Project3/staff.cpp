#include "employee.h"
#include "staff.h"
#include <string>

using namespace std;

Staff::Staff(string n, string a, string t, string e, string o, string sl, string h, string p) : Employee(n, a, t, e, o, sl, h)
{
   this->position = p;
}
string Staff::get_position() const
{
   return position;
}

string Staff::whatami()
{
   return "Staff";
}
