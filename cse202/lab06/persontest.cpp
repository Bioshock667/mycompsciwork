#include "person.h"
#include "location.h"
#include <iostream>
#include <string>
using namespace std;
    
int main()
{
    Person t("Bill", "Gates", "Microsoft");
    Location l("15010 NE 36th St.", "92","55");
    
    cout << t.getName() << endl;
    cout << t.getCompany() << endl;

    cout << l.getLocationBuilding() << endl;
    cout << l.getLocationRoom() << endl;
}
