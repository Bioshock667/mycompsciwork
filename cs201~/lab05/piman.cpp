/* Attempt evaluate pi by throwing darts at a square board and counting
   hits in a circular target area.  Actually uses one quarter of a 2*2 square
   with a quadrant of a unit circle inside it.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ccc_win.h"
using namespace std;
int ccc_win_main( )
{
	const int NUMBER_OF_POINTS=30000;
	const double RADIUS =1.0;

	const double RAND_SCALE = 1.0/RAND_MAX;
	srand(time(0));

	cwin.coord(0,RADIUS,RADIUS,0);

	double in =0.0;//counter

	for( double total=0.0; total < NUMBER_OF_POINTS ; total =total+1 )
	{
		double x=rand() * RAND_SCALE;
		double y=rand() * RAND_SCALE;


		/* (x,y) is in circle if x*x+y*y is less than 1 */
		if( x*x+y*y <= RADIUS*RADIUS )
		{
			cwin << Point(x,y);
			in=in+1;
		}

		cout << 4.0 * in/total << endl;
	}
}

