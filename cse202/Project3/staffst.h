#ifndef STAFFST_H
#define STAFFST_H
#include <string>
#include "student.h"
#include "staff.h"

using namespace std;

class StaffST : public Staff, public Student
{
   public:
     StaffST(string n, string a, string t, string e, string st, string o,
     string sl, string h, string p, string ch);
     string get_credithours();
     string virtual whatami();
   private:
     string credithours;
};
#endif
