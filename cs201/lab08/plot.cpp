#include <string>
#include "plot.h"
using namespace std;
string plot(double x)
{
	string line="-1                           0                          +1";
	const int halfWidth = (line.size()-4)/2;
	if( -1 <= x and x <= 1 )
	{
		line[ (x+1)*halfWidth + 2.5 ] = '*';

	}
	return line;
	
}
