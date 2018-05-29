/* CS201 Programming Example -- Class modelling circles
*/
#include <iostream>
#include <cmath>
using namespace std;
const double PI = 4*atan(1);

class Circle
{
  private:
	double radius;
  public:
	       Circle (double r);
	double circumference( )const;
	double area()const;
	double getRadius()const;
	void   setRadius(double radius);
	void setCircumference(double circumference);

};


Circle::Circle(double r )
{
	radius=r; 
}/*end Circle*/
double  Circle::getRadius( )const
{
	return radius; 
}/*end getRadius*/
void Circle::setRadius(double r )
{
	radius=r; 
}/*end setRadius*/

double  Circle::circumference( )const
{
	return 2*PI*radius; 
}/*end circumference*/

double Circle::area()const
{
	return PI * radius * radius ;
}//end area

void Circle::setCircumference(double circumference)
{
	radius=circumference / (2*PI);
}


int main()
{  
	Circle c(1);
	cout << "Radius=" << c.getRadius() << "\n";
	cout << "Circumference=" << c.circumference() << "\n";
	cout << "Area =  "<<c.area() << "\n";
	cout <<"\n";
	c.setRadius(10);
	cout << "Radius=" << c.getRadius() << "\n";
	cout << "Circumference=" << c.circumference() << "\n";
	cout << "Area =  "<<c.area() << "\n";

	cout <<"\n";
	c.setCircumference(27);
	cout << "Radius=" << c.getRadius() << "\n";
	cout << "Circumference=" << c.circumference() << "\n";
	cout << "Area =  "<<c.area() << "\n";

	return 0; // terminate program with zero errors.

}
