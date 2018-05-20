#include "staffst.h"
#include "student.h"
#include "staff.h"
#include <string>

using namespace std;

StaffST::StaffST(string n, string a, string t, string e,string st, string o, string sl, string h, string p, string ch) : Student(n, a, t, e, st), Staff(n, a, t, e, o, sl, h, p)
{
   credithours = ch;
}
string StaffST::get_credithours()
{
   return credithours;
}

string StaffST::whatami()
{
   return "StaffST";
}
