
//#include "VirtualMachine.h"
//#include "Assembler.h"
#include "PCB.h"
#include "os.h"
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <list>
#include <fstream>
#include <stdlib.h>
using namespace std;


void OS::run()
{

    int RD;
    int IOnum;
    terminate = false;

    system("ls *.s > progs");
    ifstream progs;
    string nfile;
    string name;
    ifstream infile;
    ofstream outfile;
    fstream stfile;
    progs.open("progs");
    processes = 0;
    while(getline(progs, nfile))
    {
	as.compile(nfile);
	PCB * p = (new PCB);
	p->pname = nfile;
	nfile.erase(nfile.end()-2, nfile.end());
	name = nfile;
	nfile = name + ".o";
	vm.read(nfile);
	//p->obfile.open(nfile.c_str());
	p->base = vm.base;
	p->limit = vm.limit;
	p->pc = vm.base;
	nfile = name + ".in";
	p->infile.open(nfile.c_str());
	nfile = name + ".out";
	p->outfile.open(nfile.c_str());
	nfile = name + ".st";
	p->stk.open(nfile.c_str());
	jobs.push_back(p);
	readyQ.push(p);
	processes++;
    }
    cout << "Program input completed!" << endl;
    tPut = processes;
    setRunning();
    cout << "Starting OS!" << endl;
    while (!terminate) {
	
	//readyQ.front()->TurnaroundTime =  running->TurnaroundTime;
	vm.interrupt = false;
	vm.checkMemory();
    	vm.execute();
	VMRStat = vm.sr >> 5;
   	VMRStat &= 7;
	switch (VMRStat) {
	    case 0:	//time slice over
		cout << "Time out for " << running->pname << endl;
		contextSwitch();
		break;
	    case 1:	 //halt operation
		cout << "Program " << running->pname << " halted!" << endl;
		terminateRunning();
		break;
	   case 2: //out of bounds exception
		cout << "Out of Bounds: Process " << running->pname << "terminated!" << endl;
		terminateRunning();
		    break;
 	   case 3: //stack overflow exception
		cout << "Stack Overflow: Process " << running->pname << "termintated!" << endl;
		terminateRunning();
		break;
	   case 4:
		cout << "Stack Overflow: Process " << running->pname << "terminated!" << endl;
		terminateRunning();
		break;
	   case 5:
		cout << "Invalid Opcode: Process " << running->pname << "terminated!" << endl;
		terminateRunning();
		break;
	   case 6: //read operation
	    	contextSwitch();
	    	RD = vm.sr>>8;
	    	waitQ.front()->infile >> IOnum;
	   	waitQ.front()->reg[RD] = IOnum;
	    	break;
	  case 7: //write operation
	    	contextSwitch();
	    	RD = vm.sr>>8;
	    	IOnum = waitQ.back()->reg[RD];
	    	waitQ.back()->outfile << IOnum << endl;
	    	break;
	default:
		cout << "Error invalid VM condition!" << endl;
		break;
    	    }//end switch
    	if(readyQ.empty() && !waitQ.empty())
    	{
	    vm.clk += 5;
	    idTime += 5;
 	}
	if(processes <= 0) {
		cout << "OS terminated!" << endl;
	    	exit(0);//stop os
	}
    cout << "An OS Loop finished!" << processes << endl;
    }//end while terminate loop
}
//this is a context switch called when running proc. will be sent to waiting queue
void OS::contextSwitch() {
    saveProcess(); 
    setRunning();
    setReady();
   vm.clk += 5;
   cSwitch++;
   }
void OS::setRunning() {
    if(!readyQ.empty()) {
    running = readyQ.front();
    readyQ.pop();
    vm.base = running->base;
    vm.limit = running->limit;
    vm.pc = running->pc;
    vm.sr = running->sr;
    vm.sp = running->sp;
    for(int i = 0; i < 4; ++i)
	vm.r[i] = running->reg[i];
    for(int SP = 256; SP <= running->sp; SP--)
	running->stk >> vm.mem[SP];
    running->WaitingTime = vm.clk - running->TurnaroundTime;
    running->TurnaroundTime = vm.clk;
    }
    else {
	if(!waitQ.empty()){
	    cout << "ReadyQ is empty" << endl;
	    vm.clk = waitQ.front()->TurnaroundTime;
	    setReady();
	    setRunning();
	    }
	}
}
void OS::saveProcess() {
    running->base = vm.base;
    running->limit = vm.limit;
    running->pc = vm.pc;
    running->sr = vm.sr;
    running->sp = vm.sp;
    for(int i = 0; i < 4; ++i)
	running->reg[i] = vm.r[i];
    int SP = 256;
    int data, lss;
    while(SP >= vm.sp)
  {
        running->stk << vm.mem[SP];
        SP--;
        lss++;
    }
    if(lss > running->LSS)
	running->LSS = lss;
    int vmiTime = vm.clk - running->TurnaroundTime;
    running->VMTime += vmiTime;
    running->IOTime += 27;
    running->TurnaroundTime = vm.clk + 27;
    waitQ.push(running);
}
void OS::setReady() {
if(!waitQ.empty()){
    if( vm.clk >= waitQ.front()->TurnaroundTime){
    	readyQ.push(waitQ.front());
    	waitQ.pop();
    	readyQ.back()->TurnaroundTime = vm.clk;
   	 }
    }
    else
	cout << "WaitQ is Empty" << endl;
}
void OS::powerOff() {
   ofstream out;
   int percentBusy,VMUtil, time;
   for(list<PCB*>::iterator it = jobs.begin(); it != jobs.end(); ++it)
	totalVMTime += (*it)->VMTime;
   VMUtil = totalVMTime/vm.clk;
   for(list<PCB*>::iterator it2 = jobs.begin(); it2 != jobs.end(); ++it2)
   {
	(*it2)->outfile << "***************************************" << endl;
	(*it2)->outfile << cSwitch << " context switches and " << idTime << " ticks spent idle." << endl;
	percentBusy = 100*(vm.clk - idTime)/vm.clk;
	(*it2)->outfile << "System CPU Utilization: " << percentBusy << "%" << endl;
	VMUtil *= 100;
 	(*it2)->outfile << "User CPU Utilization: " << VMUtil << "%" <<endl;
	time = vm.clk/1000;
	tPut = tPut/time;
	(*it2)->outfile << "Throughput: " << tPut << " processes per second." << endl;
   }
   terminate = true;
}
//this is a context switch where running proc. is terminated
void OS::terminateRunning() {
    cout << "Breakpoint" << endl;
    int vmiTime = vm.clk - running->TurnaroundTime;
    running->VMTime += vmiTime;
    running->TurnaroundTime = vm.clk;
    running->outfile << "****************************************************" << endl;
    running->outfile << "CPU Time: " << running->VMTime << endl;
    running->outfile << "Waiting Time: " << running->WaitingTime << endl;
    running->outfile << "TurnaroundTime: " << running->TurnaroundTime << endl;
    running->outfile << "I/OTime: " << running->IOTime << endl;
    processes--;
    setReady();
    setRunning();
    cSwitch++;
    }
