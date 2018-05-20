
#include "VirtualMachine.h"
#include "Assembler.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Assembler as;
    VirtualMachine vm;
    string filename;
    string a = argv[2];
    filename = argv[1];
	for (int i = 0; i < argc; i++)
	cout << argv[i] << endl;
      if (a == "-c")
	{
    	     as.compile(filename);
	}
     else if (a == "-dr")
	{
	    vm.read(filename);
	    vm.checkMemory();
	}
     else if (a == "-e")
       {
	 vm.read(filename);
	 vm.execute();
      }
    else 
	{
	cout << "Error: Invalid Argumeent" << endl;
	}
    return 0;
}
