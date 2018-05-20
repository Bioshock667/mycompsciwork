#ifndef PCB_H
#define PCB_H

#include <string>
#include <fstream>

using namespace std;

    class PCB {
	friend class OS;
     private:
	int reg [4];
	int pc, base, limit, sp, sr;
	int VMTime, WaitingTime, TurnaroundTime, IOTime, LSS;
	string pname;
	ifstream obfile;
	ifstream infile;
	ofstream outfile;
	fstream  stk;
    public:
	PCB();
};
#endif