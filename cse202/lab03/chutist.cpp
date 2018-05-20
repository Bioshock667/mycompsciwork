// Project: lab3

#include "ccc_win.h"
#include <sstream>
#include <string>
class Chutist
{
public:
  
  Chutist();  // Default constructor

  Chutist(Point loc);       // constructor where chutist always points up
  
  void display(bool i) const;  // accessor function, displays chutist

  void move(int dx, int dy);  // mutator function, moves chutist

private:

  Point location; // location of chutist 

};

// default; 

Chutist::Chutist()
{
  location = Point(0,0);
}

// constructor of Chutist object at Point loc;

Chutist::Chutist(Point loc)
{
  location = loc;
 
}

// accessor function: displays the chutist at location to the cwin

void Chutist::display(bool i) const
{
 Circle c = Circle(location,10);
 Point le = location;
 le.move(-2,0);
 Point re = location;
 re.move(2,0);
 Point lm = location;
 lm.move(-2,-7);
 Point rm = location;
 rm.move(2,-7);
 Point lside = location;
 lside.move(-10,0);
 Point rside = location;
 rside.move(10,0);
 Line mouth(lm,rm);
 Point chest = location;
 chest.move(0,-10);
 Point bottom = location;
 bottom.move(0,-20);
 Point lhand = location;
 lhand.move(-10,-9);
 Point rhand = location;
 rhand.move(10,-9);
 Point lfoot = location;
 lfoot.move(-5,-25);
 Point rfoot = location;
 rfoot.move(5,-25);
 Line larm(lhand,chest);
 Line rarm(chest, rhand);
 Line lleg(lfoot,bottom);
 Line rleg(bottom,rfoot);
 Line body(chest,bottom);
   Point lop = location;
   lop.move(-12,12);
   Point rop = location;
   rop.move(12,12);
   Point top = location;
   top.move(0,20);
   Line blp(lop,rop);
   Line llp(lop,top);
   Line rlp(top,rop);
   Line ls(lop,lside);
   Line rs(rside,rop);
  cwin << c << le << re << mouth << larm << rarm << lleg << rleg << body;
 if (i == true)
 {
   cwin << blp << llp << rlp << ls << rs;
 }
}//displays the chutist at the Point location.If i is negative the chute is closed. If i is positive, it is open.

void Chutist::move(int dx, int dy)
{
 location.move(dx,dy);
}

int ccc_win_main()
{
   int a = 500;
   int g = 32;
   int v = 0;
   int stp = 4;
   
   Chutist chut(Point(0,a));
   chut.display(false);
   
   cwin.coord(-260, 520, 260, 0);

   while (a > 0)//do until reach ground
      {
	   
	    if(stp <= 0) //parachute opens
		{
		Point p = Point(-20,a+6);
		Point q = Point(20,a+6);
		Line l = Line(p,q); 

		v = v - 100;
		  if (v < 17)
		  {
		  
		   v = 17;
		  chut.display(true);
	    	  }
		}
	   else//when parachute is not open
	   {
	   v = v + g;
	   }
	    a = a - v;
	    chut.move(0,-v);
 	    chut.display(false);
	    stp--;
	    string number;
	    ostringstream convert;
	    convert << a;
	    number = convert.str();
            string alt = number + " ft";
	    Message m = Message(Point(20,a), alt);
	    cwin << m;
      }

return 0;
}
