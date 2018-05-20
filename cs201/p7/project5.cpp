/* CS201 Project
   Programmer: Seth Lemanek
   Number in text: P4.19
   Description in text
	Write functions: double perimeter(Circle c); double area(Circle c); that compute the area and perimeter inside circle c.
   Algorithm
	1._
	2._
	3._
	...
*/
#include <cmath>
#include <iostream>
#include "ccc_win.h"

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

int ccc_win_main()
{  
	cwin.coord(-30, 40, 60, -30);
	Circle u(Point(5, 20), 8);
	Circle v(Point(8, 1), 6);
	Circle w(Point(-6, 6), 5);
	Circle x(Point(-6, -6), 3);
	Circle y(Point(3, -16), 10);
	Circle z(Point(35, 0), 15);
	cwin << u << v << w << x << y << z << Message(Point(0, 0), "0");
	Point m = cwin.get_mouse("Please click a circle.");
	cwin << m;
	int circle;
	if (range(u, m))
		circle = 1;
	else if (range(v, m))
		circle = 2;
	else if (range(w, m))
		circle = 3;
	else if (range(x, m))
		circle = 4;
	else if (range(y, m))
		circle = 5;
	else if (range(z, m))
		circle = 6;
	else
		circle = 0;
	
	if(circle == 1)
	{
		cwin << Message(Point(0, 20), "Perimeter: ") << Message(Point(18, 20), perimeter(u))
			<< Message(Point(0, 18), "Area:") << Message(Point(18, 18), area(u));
	}
	else if (circle == 2)
	{
		cwin << Message(Point(3, 1), "Perimeter: ") << Message(Point(21, 1), perimeter(v))
			<< Message(Point(3, -1), "Area:") << Message(Point(21, -1), area(v));
	}
	else if (circle == 3)
	{
		cwin << Message(Point(-11, 6), "Perimeter: ") << Message(Point(7, 6), perimeter(w))
			<< Message(Point(-11, 4), "Area:") << Message(Point(7, 4), area(w));
	}
	else if (circle == 4)
	{
		cwin << Message(Point(-11, -6), "Perimeter: ") << Message(Point(7, -6), perimeter(x))
			<< Message(Point(-11, -8), "Area:") << Message(Point(7, -8), area(x));
	}
	else if (circle == 5)
	{
		cwin << Message(Point(-2, -16), "Perimeter: ") << Message(Point(16, -16), perimeter(y))
			<< Message(Point(-2, -18), "Area:") << Message(Point(16, -18), area(y));
	}
	else if (circle == 6)
	{
		cwin << Message(Point(30, 0), "Perimeter: ") << Message(Point(48, 0), perimeter(z))
			<< Message(Point(30, -2), "Area:") << Message(Point(48, -2), area(z));
	}
	else if (circle == 0)
		cwin << Message(m, "No circle selected!");

	return 0; // terminate program with zero errors.

}
