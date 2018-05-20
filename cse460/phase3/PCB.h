#ifndef PCB_H
#define PCB_H

#include "entry.h"
#include <string>
#include <fstream>

using namespace std;

    class PCB {
	friend class OS;
     private:
	int reg [4];
	entry pT[32];
	int pc, base, limit, sp, sr;
	int VMTime, WaitingTime, TurnaroundTime, IOTime, LSS, pF, Hit;
	string pname;
	fstream obfile;
	ifstream infile;
	ofstream outfile;
	fstream  stk;
    public:
	PCB();
};
#endif
