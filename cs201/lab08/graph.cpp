/* CS201 Programming Experiment -- graphing math functions
   Programmer:
	RJBotting
   Description/Vision:
	To be able to display a graph of a function on a dumb terminal
   Analysis
	Input: Nothing
	Output: a graph.
   Algorithm
	For each x value for 0 to 360 degrees in steps of 10
		plot the value of sin(x) in a string
		display the x value and the string
   Versions:
	Downloaded Dr. Botting's skeleton file.
	2010 Multifile version
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#include "plot.h"

const double PI = 4.0*atan(1.0);  // with thanks to Dr. K. Schubert, CSE, CSUSB

int main()
{  
	const double LAST = 2*PI; // 360 degrees in radians
	const double INCREMENT = LAST/36; // 10 degrees in radians
	const double DEGREES = 180/PI; // conversion factor radians to degrees

	for( double x = 0; x <=LAST; x += INCREMENT)
	{
		cout << setw(8) << int(x*DEGREES +0.5);
		double y = sin(x);
		cout << plot(y) << endl;
	}

	return 0; // terminate program with zero errors.

}
