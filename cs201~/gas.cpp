/*  CS201 Project
   Programmer: Seth Lemanek
   Number in text: P5.8
   Description in text
	Implement a class Car with the following properties. A car has a certain fuel efficency
	(measured in miles/gallon or liters/km -pick one) and a certain amount of fuel in the
	gas tank. The efficency is specified in the constructor, and the initial fuel is zero.
	Supply a function drive that simulates driving the car for a certain distance, reducing
	the fuel level in the gas tank, and functions get_gas, to return the current fuel level,
	and add_gas, to tank up.
   Algorithm
	1.Define class Car with private data gaslevel and MilesPerGallon
	2.Constructor function sets parameter variable mpg to MilesPerGallon
	3.Mutator function add_gas adds input to gaslevel 
	4.Mutator function drive simulates driving with its consumption of gas
	5.Accessory function shows the amount of gas left
	6.Function main tests class Car
*/

#include <iostream>

using namespace std;

class Car
{
public:
    Car(int mpg);
    

    void add_gas(int gas){gaslevel = gaslevel + gas;}
    void drive(int miles);

    int get_gas() const {return gaslevel;}

private:
    int gaslevel;
    int MilesPerGallon;
};

Car::Car(int mpg)
    {
        MilesPerGallon = mpg;
        gaslevel = 0;
    }

void Car::drive(int miles)
{
    gaslevel = gaslevel - miles/MilesPerGallon;
}
int main()
{
    Car my_speeder(35); //50 miles per gallon

    my_speeder.add_gas(20);//add 20 gallons of gas
    my_speeder.drive(100);//drive 60 miles
    cout << "The amount of gas left is: " << my_speeder.get_gas() << " gallons.\n";//print gallons left

    return 0;//finish program with zero errors
}
