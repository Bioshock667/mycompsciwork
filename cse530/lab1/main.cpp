#include "multiply.h"
#include "print.h"
#include <stdlib.h>

int main(int argc, char* arg[]) {
    if (argc < 3) 
	return 0;
    else{
	double result;
	result = multiply(atof(arg[1]), atof(arg[2]));
   	print(result);
	return 1;
    }
}
