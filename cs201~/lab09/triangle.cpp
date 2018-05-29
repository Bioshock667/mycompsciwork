 /******************************************************************************

 kay zemoudeh 10/16/97 triangle.cpp

 RJBotting may 3rd 2005

 this program illustrates the most fundamental concept of OOP: classes.

 it defines the user defined class Triangle, and

 declares/constructs and uses several objects of that type.

 in doing so, It demonstrates the use of methods (member functions).

 *******************************************************************************/

 #include "ccc_win.h"

 using namespace std;

 // Triangle class Interface

 class Triangle {

 public:

         Triangle();                     // constructor

         Triangle(Point, Point, Point);  // constructor

	 Triangle(int n);

         void plot()const;               // accessor plot() displays it

	 void split()const;		 // accessor split() splits it

	 void inscr_circle()const;

         void move(int x, int y);        // mutator move() moves it

 private:

         Point vertex1, vertex2, vertex3; // private data field

 };

 Triangle::Triangle()

 {

         vertex1 = Point(0, 0);

         vertex2 = Point(2, 0);

         vertex3 = Point(0, 2);

 }

 Triangle::Triangle(Point v1, Point v2, Point v3)

 {

         vertex1 = v1;

         vertex2 = v2;

         vertex3 = v3;

 }
Triangle::Triangle(int n)

{
	
	vertex1 = Point(0,0);
	
	vertex2 = Point(0,0);

	vertex3 = Point(0,0);

	vertex2.move(n,0);
	
	vertex3.move(n,n);
	
}
 void Triangle::plot()const

 {

         cwin << Line(vertex1, vertex2);

         cwin << Line(vertex2, vertex3);

         cwin << Line(vertex3, vertex1);

 }
void Triangle::split()const

{
	double midx = (vertex2.get_x() + vertex3.get_x()) * 0.5;
	double midy = (vertex2.get_y() + vertex3.get_y()) * 0.5;
	Point midpoint(midx, midy);
	cwin << Line(vertex1, midpoint);
}
 void Triangle::move(int dx, int dy)

 {

         vertex1.move(dx, dy);

         vertex2.move(dx, dy);

         vertex3.move(dx, dy);

 }

 // to test Triangle class

 int ccc_win_main()

 {

         Triangle tri1;

         tri1.plot();

	 tri1.split();

         Triangle tri2(Point(5, 0), Point(10, 0), Point(5, 5));

         tri2.plot();

	 tri2.split();

         tri1.move(-5, -5);

         tri1.plot();
	 tri1.split();

	for(int i=1; i<=10; i++)
	{

	Triangle tri3(i);
	
	tri3.plot();

  	}

         return 0;

 }
