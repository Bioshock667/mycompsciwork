// program bubsort
//   timing test for C++ vector and C array comparison

#include <time.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <vector>


using namespace std;


double milisecond_timer(){
struct timespec itval;
/* returns system time in miliseconds - 
   this routine compiles with gcc or g++ */

/* for gcc, compile with "gcc -lrt" */

	clock_gettime(CLOCK_REALTIME,&itval);
	return itval.tv_sec*1000+itval.tv_nsec/1e6;
}


int bubble(vector<int>& x){
int i,swap,count=0;
bool done=false;
/* bubble sort - C++ vector version */
/* done is set to true at the start of
   the while loop - if any items in the
   array or vector are out of order, they are
   swapped and done is set to false.
   when nothing is out of order, done stays
   true in the inner loop and the while
   loop ends.

   because the array is passed by reference
   changes to the array are visible in main.

   count tracks how many loops it takes
   to order the array.*/

while( !done){
	count++;
	done=true;

	for(i=1;i<x.size();i++){
		if(x[i]<x[i-1]) {swap=x[i];
				x[i]=x[i-1];
				x[i-1]=swap;
				done=false;}
		}
	}
	return count; // return number of loops


}

int main(){
int i,c;
double t0,t1;
vector<int> tarray(30000);


srand(milisecond_timer()); // initialize random number generator

// initialize array of random integers

for(i = 0; i<tarray.size(); i++)
	tarray[i]=rand();

// print first item 
cout << endl << "data size =" << tarray.size() << " first =" << tarray[1] << endl;

t0=milisecond_timer(); // save start time
c=bubble(tarray); // call bubble sort routine
t1=milisecond_timer(); // save end time

// print number of loops, time in miliseconds, first array item to verify that it has changed
cout << "number of iterations =" << c << " miliseconds =" << t1-t0 << " first =" << tarray[1] << endl; 

}

