/* CS201 Project
   Programmer: Seth Lemanek
   Number in text: P2.22
   Description in text
	_
   Algorithm
	1.choose center of circle
	2._
	3._
	...
*/
#include "ccc_win.h"

using namespace std;

// Assuming you want graphics we replace int main() by
int ccc_win_main()
{ 	Point c(2.5, 0);
	cwin << Circle(c, 2.5);
	
	Point lefteye(1,0);
	cwin << lefteye;

	Point righteye(2,0);
	cwin << righteye;

	Point leftmouth(lefteye);
	leftmouth.move(0,-1);
	Point rightmouth(righteye);
	rightmouth.move(0,-1);
	Line mouth(leftmouth, rightmouth);
	cwin << mouth;


	return 0; // terminate program with zero errors.

}
