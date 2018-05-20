// program bubsort
//   timing test for C++ vector and C array comparison

#include <time.h>
#include <stdio.h>

double milisecond_timer(){
struct timespec itval;
/* returns system time in miliseconds - 
   this routine compiles with gcc or g++ */

/* for gcc, compile with "gcc -lrt" */

	clock_gettime(CLOCK_REALTIME,&itval);
	return itval.tv_sec*1000+itval.tv_nsec/1e6;
}


int bubble(int x[], int size){
int i,swap,count,done = 0;
/* bubble sort - C vector version */
/* done is set to 1 at the start of
   the while loop - if any items in the
   array or vector are out of order, they are
   swapped and done is set to 0.
   when nothing is out of order, done stays
   1 in the inner loop and the while
   loop ends.

   because the array is passed by reference
   changes to the array are visible in main.

   count tracks how many loops it takes
   to order the array.*/

while( !done){
	count++;
	done=1;

	for(i=1;i<size;i++){
		if(x[i]<x[i-1]) {swap=x[i];
				x[i]=x[i-1];
				x[i-1]=swap;
				done=0;}
		}
	}
	return count; // return number of loops

}

int main(){
int i,c;
double t0,t1;
int aSize = 30000;
int tarray[aSize];


srand(milisecond_timer()); // initialize random number generator

// initialize array of random integers

for(i = 0; i<aSize; i++)
	tarray[i]=rand();

// print first item 
printf("data size = %d \nfirst = %d \n", aSize, tarray[1]);
t0=milisecond_timer(); // save start time
c=bubble(tarray, aSize); // call bubble sort routine
t1=milisecond_timer(); // save end time

// print number of loops, time in miliseconds, first array item to verify that it has changed 
printf("number of iterations = %d \nmilliseconds = %d \nfirst = %d \n", c, (t1-t0), tarray[1]);
}

