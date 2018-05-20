/*Programmer: Seth Lemanek
  This main program tests the Person class and its derived class then returns stored name address and type.  */



#include "person.h"
#include "student.h"
#include "faculty.h"
#include "staffst.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std; 

string classify(Person* p)
{  return p->whatami();}

int main()
{ 
   vector<Person*> v;
   v.push_back(new Person("John Adams","Boston","617-555-0000","john@adams.com"));
   v.push_back(new Student("John Quincy Adams","Boston","617-555-0000","johnq@adams.com","senior"));
   v.push_back(new Faculty("Jackson", "5th Ave.", "909 666-7777", "jackson@yahoo.com", "jbh-201.1", "$20,000","Jan. 1st", "professor", "visiting"));
   v.push_back(new Staff("Samuel Adams","Boston","617-555-BEER","sam@adams.com","brewhouse 1","$1000","9-15-1764","Brewer"));
   v.push_back(new StaffST("Samuel Smith","Boston","617-555-BEER","samsmith@adams.com","junior","brewhouse 5","$100","9-15-1774","Taster", "2 cred hours"));

// Hey - no Faculty object ---> add one yourself!

   for (int i=0; i<v.size(); i++)
     {
cout << v[i]->get_name()<<" " << v[i]->get_address()  << "  " << classify(v[i]) << endl;
     }

   return 1;
}
