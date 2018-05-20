
#include "employee.h"
#include "faculty.h"
#include <string>

using namespace std;

Faculty::Faculty(string n, string a, string t, string e, string o, string sl, string h, string r, string st) : Employee(n, a, t, e, o, sl, h)
{
   this->rank = r;
   this->status = st;
}
string Faculty::get_rank() const
{
   return rank;
}
string Faculty::get_status() const
{
   return status;
}
