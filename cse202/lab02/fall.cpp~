/*Lab 2: Fall.cpp
Programmed by Seth Lemanek on 1/14/2014*/

#include <sstream>
#include <string>
#include "ccc_win.h"

int ccc_win_main()
{
   int a = 500;
   int g = 32;
   int v = 0;
   int stp = 4;
   
   
   cwin.coord(-275, 550, 275, 0);
   Circle c = Circle(Point(0, a), 10);
   cwin << c;
   Message b = Message(Point(0,a),"500");
   cwin << b;

   while (a > 0)//do until reach ground
      {
	   
	    if(stp <= 0) //parachute opens
		{
		Point p = Point(-20,a+6);
		Point q = Point (20,a+6);
		Line l = Line(p,q); 

		v = v - 100;
		  if (v < 17)
		  {
		  
		   v = 17;
		  
	    	  }
		cwin << l;
		}
	   else//when parachute is not open
	   {
	   v = v + g;
	   }
	    a = a - v;
	    c.move(0,-v);
 	    cwin <<  c;
	    stp--;
	    string number;
	    ostringstream convert;
	    convert << a;
	    number = convert.str();
	    Message m = Message(Point(0,a), number);
	    cwin << m;
      }
   return 0;
}

