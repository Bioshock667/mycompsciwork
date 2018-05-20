#include "os.h"

using namespace std;

int main(int argc, char *argv[])
{
    OS os;
    if(argc > 1)
	os.run(argv[1]);
    else
    	return 1;
    return 0;
}
