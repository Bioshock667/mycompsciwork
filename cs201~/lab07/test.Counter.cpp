/* Testing a simple class */
#include <iostream>
#include <cassert>
using namespace std;

class Counter /* used for counting things in a program*/
{
   private:
	int value; // holds the count
   public:
	Counter(); // afterwards value is 0
	void count(int step);// Adds step to value
	void setValue(int v);//sets value to v
	int getValue()const; 
};
Counter::Counter()
{
	value=0;
}
int Counter::getValue() const
{
	return value;
}
void Counter::count(int step)
{
	value = value + step;
}
void Counter::setValue(int v)
{
	value = v;
}

int main()
{
	Counter c,d;
	assert ( c.getValue() == 0 );
	assert ( d.getValue() == 0 );
	c.count(1);
	assert ( c.getValue() == 1 );
	assert ( d.getValue() == 0 );
	d.count(2);
	assert ( c.getValue() == 1 );
	assert ( d.getValue() == 2 );
	c.setValue(5);
	assert ( c.getValue() == 5 );
	d.setValue(10);
	assert ( d.getValue() == 10);

	cout << "Success!\n";

	return 0;
}
