/****************************************************************************
** COPYRIGHT (C):    1996 Cay S. Horstmann. All Rights Reserved.
** PROJECT:          Computing Concepts with C++
** FILE:             circle.cpp
****************************************************************************/

#include "ccc_win.h"

using namespace std;

// Assuming you want graphics we replace int main() by
int ccc_win_main()
{ 	Point p(1, 3);
	cwin << p;
	cwin << Circle(p, 2.5);

	return 0;
}

