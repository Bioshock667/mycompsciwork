#include "student.h"
#include "faculty.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
   Student Jimmy = Student("Jimmy", "Main St.", "909 444-5555","jimboy@hotmail.com","freshman");
   Faculty Professor = Faculty("Jackson", "5th Ave.", "909 666-7777", "jackson@yahoo.com", "jbh-201.1", "$20,000","Jan. 1st", "professor", "visiting");
   cout << Jimmy.get_name() << "is a " << Jimmy.get_status() << " who lives on " << Jimmy.get_address() << endl;
   cout << Professor.get_name() << "is a " << Professor.get_status() << " " << Professor.get_rank() << " who earns " << Professor.get_salary() << endl;
}
