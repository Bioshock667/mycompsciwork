/****************************************************************************
RJBotting
Demonstration of Message objects and strings
****************************************************************************/

#include "ccc_win.h"
#include <string>

using namespace std;

// Assuming you want graphics replace int main() by
int ccc_win_main()
{  string text = cwin.get_string(string("Input at least 4 characters? ")); // This is a little different to the Big C++ book

   const int H=2; // Half the side of the square

   cwin << Message(Point(-H, H), text.substr(0,1));
   cwin << Message(Point( H, H), text.substr(1,1));
   cwin << Message(Point( H,-H), text.substr(2,1));
   cwin << Message(Point(-H,-H), text.substr(3,1));

   return 0;
}

