
#include <cmath>
#include "ccc_win.h"
#include <iostream>
#include "pafinder.h"

using namespace std;


double perimeter(Circle c)
{
	const double PI = 4.0 * atan(1.0);
	double p = 2 * PI * c.get_radius();
	return p;
}

double area(Circle c)
{
	const double PI = 4.0 * atan(1.0);
	double a = PI * c.get_radius() * c.get_radius();
	return a;
}
bool range (Circle C, Point p)
{
	double x = p.get_x();
	double y = p.get_y();
	double a = C.get_center().get_y();
	double b = C.get_center().get_x();
	double r = C.get_radius();
	
	if (x <= sqrt((r * r - (y - a) * (y - a)) + b) && x >= -sqrt(r * r - (y - a) * (y - a)) + b)
		return true;
	else
		return false;
}

