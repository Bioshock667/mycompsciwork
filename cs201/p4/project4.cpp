/* CS201 Project
   Programmer: Seth Lemanek
   Number in text: P4.19
   Description in text
	Write functions: double perimeter(Circle c); double area(Circle c); that compute the area and perimeter inside circle c.  
	Use these functions in a graphics program the user to specify a circle. Then display messages with a perimeter and area
	of a circle.
   Algorithm
	1.Draw a graphics programs with six circles drawn
	2.Prompt user to click an area within a circle
	3.range function finds whether the point clicked is within a circle and which circle it is in
	4.Call perimeter and area function to find perimeter and area of given circle
	5.Output data near chosen circle
*/
#include <cmath>
#include <iostream>
#include "ccc_win.h"

using namespace std;


/**
	Finds parameter of Circle c
	@param c the circle chosen
	@return perimeter of the circle
*/
double perimeter(Circle c)
{
	const double PI = 4.0 * atan(1.0);
	double p = 2 * PI * c.get_radius();
	return p;
}

/**
	Finds area of Circle c
	@param c a circle calculated
	@return area of the circle
*/
double area(Circle c)
{
	const double PI = 4.0 * atan(1.0);
	double a = PI * c.get_radius() * c.get_radius();
	return a;
}

/**
	Determines 
*/
bool range (Circle C, Point p)
{
	double c = p.get_x();
	double d = p.get_y();
	double a = C.get_center().get_y();
	double b = C.get_center().get_x();
	double r = C.get_radius();
//equation of cricle is a^2 + b^2 = r^2 point selected = (c, d)
	if(c <= sqrt((r * r - (d - a) * (d - a)) + b) && c >= -sqrt(r * r - (d - a) * (d - a)) + b)
	{
		if(d <= sqrt((r * r - (c - b) * (c - b)) + a) && c >= -sqrt(r * r - (c - b) * (c - b)) + a)
		return true;
		else
			return false;
	}
	else
		return false;
}
int ccc_win_main()
{
	cwin.coord(-30, 30, 60, -30);
	Circle u(Point(5, 20), 8);
	Circle v(Point(8, 1), 6);
	Circle w(Point(-6, 6), 5);
	Circle x(Point(-6, -6), 3);
	Circle y(Point(3, -16), 10);
	Circle z(Point(35, 0), 15);
	cwin << u << v << w << x << y << z << Message(Point(0, 0), "0, 0");
	Point m = cwin.get_mouse("Please click a circle.");
	cwin << m;
	string circle;
	if(range(u, m))
		circle = "u";
	if(range(v, m))
		circle = "v";
    if(range(w, m))
        circle = "w";
    if(range(x, m))
        circle = "x";
    if(range(y, m))
        circle = "y";
    if(range(z, m))
        circle = "z";

    if(circle == "u")
	{
        cwin << Message(Point(0, 20), "Perimeter: ") << Message(Point(18, 20), perimeter(u))
		<< Message(Point(0, 18), "Area:") << Message(Point(18, 18), area(u));
	}
	if(circle == "v")
	{
        cwin << Message(Point((8, 1), "Perimeter: ") << Message(Point(26, 1), perimeter(v))
		<< Message(Point(8, -1), "Area:") << Message(Point(26, -1), area(v));
	}
	if(circle == "w")
    {
        cwin << Message(Point(-6, 6), "Perimeter:") << Message(Point(12, 6), perimeter(w))
        << Message(Point(-6, 4), "Area:") << Message(Point(-6, 4), area(w));
    }
	if(circle == "x")
	{
		cwin << Message(Point(-6, -6), "Perimeter:") << Message(Point(12, -6), perimeter(w))
        << Message(Point(12, -8), "Area:") << Message(Point(12, -8), area(w));
	}
	if(circle == "y")
	{
		cwin << Message(Point(3, -16), "Perimeter:") << Message(Point(21, -16), perimeter(w))
        << Message(Point(3, -18), "Area:") << Message(Point(21, -18), area(w));
	}
	if(circle == "z")
	{
		cwin << Message(Point(35, 0), "Perimeter:") << Message(Point(53, 0), perimeter(w))
        << Message(Point(35, -2), "Area:") << Message(Point(53, 0), area(w));
	}
	return 0; // terminate program with zero errors.

}
