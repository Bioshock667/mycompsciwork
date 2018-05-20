/* Programmed by Seth Lemanek
   Prof: Key Zemoudeh
   Class: CSE 460 Operationg Systems
   First Build Finished: 5/20/15
   Description: This is a program to simulate the function of an operating system.  Its purpose is to organize and schedule with
   programs get processed in the Virtual Machine.  It has a queue of programs ready to go called the ready queue then is takes one 
   and runs it.  Once the process is interrupted the progress of the process is saved to its PCB.  If its timeslice was finished, it
   is sent to the back of the ready queue.  If it is using an I/O device it is sent to the Wait Queue.  Once it is ready it is sent 
   to the back of the ready queue. It will continue to run until all processes are completed.*/
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
    cSwitch = 0;
    system("ls *.s > progs");
    ifstream progs;
    string nfile;
    string name;
    progs.open("progs");
    processes = 0;
    //first the OS must take all the .s files and compile them and initialize a PCB for each program.
    while(getline(progs, nfile))
    {
	cout << "Compiling" << nfile << endl;
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
	p->sp = vm.sp;
	p->LSS = 0;
	nfile = name + ".in";
	p->infile.open(nfile.c_str(), ios::in);
	nfile = name + ".out";
	p->outfile.open(nfile.c_str(), ios::out);
	nfile = name + ".st";
	p->stk.open(nfile.c_str(), ios::out);
	p->stk.close();
	p->stk.open(nfile.c_str(), ios::in|ios::out);
	p->stk << flush << endl;
	if(!p->stk.is_open())
		cout << "Stack open failed" << endl;
	jobs.push_back(p);
	readyQ.push(p);
	processes++;
    }
    tPut = processes;
    setRunning();
    cout << "Starting OS!" << endl;
    while (!terminate) {
	
	
	vm.interrupt = false;
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
		cout << "Out of Bounds: Process " << running->pname << " terminated!" << endl;
		terminateRunning();
		    break;
 	   case 3: //stack overflow exception
		cout << "Stack Overflow: Process " << running->pname << " termintated!" << endl;
		terminateRunning();
		break;
	   case 4:  //stack underflow exception
		cout << "Stack Uderflow: Process " << running->pname << " terminated!" << endl;
		terminateRunning();
		break;
	case 5: //invalid opcode exception 
		cout << "Invalid Opcode: Process " << running->pname << " terminated!" << endl;
		terminateRunning();
		break;
		//the i/o operations have their own context switch operations
	   case 6: //read operation
	        cout << "i/o interrupt " << running->pname << " reading." << endl;
	 	saveProcess();
	    	RD = waitQ.back()->sr>>8;
	    	waitQ.back()->infile >> IOnum;
		//cout << "reading " << IOnum << " into register " << RD << endl;
	   	waitQ.back()->reg[RD] = IOnum;
		setRunning();
		setReady();
		vm.clk += 5;
		cSwitch++;
	    	break;
	  case 7: //write operation
	    cout << "i/o interrupt " << running->pname << " writing." << endl;
	    	saveProcess();
		RD = waitQ.back()->sr>>8;
	    	IOnum = waitQ.back()->reg[RD];
		if((IOnum & 32768) == 32768)
		     IOnum |= -65536; //sign extend
		//cout << "Writing " << IOnum <<" from register " << RD << endl;
	    	waitQ.back()->outfile << IOnum << endl;
		setRunning();
		setReady();
		vm.clk += 5;
		cSwitch++;
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
	    	powerOff();//stop os
        }
    }//end while terminate loop
}
//this is a context switch called when running proc. will be sent to the ready queue  
void OS::contextSwitch() {
    saveProcess(); 
    setRunning();
    setReady();
   vm.clk += 5;
   cSwitch++;
   }
//get the saved state from the PCB into the virtual machine
void OS::setRunning() {
    int idle = 0;
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
	running->stk.seekg(0);
	int SP = 256;
	while(SP > running->sp) {
	     SP--;
	     running->stk >> vm.mem[SP];
	}
	int wTime = vm.clk - running->TurnaroundTime;
	running->WaitingTime += wTime;
	running->TurnaroundTime = vm.clk;
    }
    else {
      if(!waitQ.empty()){//if there are processes but none in ready queue
	//then increment clock and redo so we have a running process pulled from wait queue
	    idle = waitQ.front()->TurnaroundTime - vm.clk;
	    vm.clk = waitQ.front()->TurnaroundTime;
	    idTime += idle;
	    setReady();
	    setRunning();
	    }
	}
}
//this process is where the state of the interrupted running process is saved into its PCB
//then it would move that PCB to the ready or wait queue
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
    lss = 0;
    data = 0;
    running->stk.seekp(0, running->stk.beg);
    running->stk.clear();
    while(SP > vm.sp)
  {
	--SP;
        running->stk << vm.mem[SP] << endl;
        lss++;
    }
    if(lss > running->LSS)
	running->LSS = lss;
    int vmiTime = vm.clk - running->TurnaroundTime;
    running->VMTime += vmiTime;
    int VMStat = running->sr;
    VMStat >>= 5;
    VMStat &= 7;
    if(VMStat){//if sp != 0 then its an i/o interrupt
    	running->IOTime += 27;
    	running->TurnaroundTime = vm.clk + 27;
    	waitQ.push(running);
    }
    else {//if sr = 0, then it's a timeslice
	running->TurnaroundTime = vm.clk;
	readyQ.push(running);
    }
}
//move a PCB from wait queue to ready queue
void OS::setReady() {
if(!waitQ.empty()){
    if( vm.clk >= waitQ.front()->TurnaroundTime){
    	readyQ.push(waitQ.front());
    	waitQ.pop();
    	readyQ.back()->TurnaroundTime = vm.clk;
   	 }
    }
}
//once all processes have finished the OS will call this function to go through each process and
//output the performance specs to all output files then terminate the OS loop
void OS::powerOff() {
   double VMclk, percentBusy,VMUtil, time;
   VMclk = (double)vm.clk;
   for(list<PCB*>::iterator it = jobs.begin(); it != jobs.end(); ++it){
	totalVMTime += (*it)->VMTime;
	(*it)->infile.close();
	(*it)->stk.close();}
   VMUtil = totalVMTime/VMclk;
   VMUtil *= 100.0;
  percentBusy = 100.0*(vm.clk - idTime)/vm.clk;
   time = vm.clk/1000.0;
	tPut = (time == 0)?9999:tPut/time;
   for(list<PCB*>::iterator it2 = jobs.begin(); it2 != jobs.end(); ++it2)
   {
	(*it2)->outfile << "***************************************" << endl;
	(*it2)->outfile << cSwitch << " context switches and " << idTime << " ticks spent idle." << endl;
	(*it2)->outfile << "System CPU Utilization: " << percentBusy << "%" << endl;
 	(*it2)->outfile << "User CPU Utilization: " << VMUtil << "%" <<endl;
	(*it2)->outfile << "Throughput: " << tPut << " processes per second." << endl;
	(*it2)->outfile.close();
   }
   terminate = true;
}
//this is a context switch where running proc. is terminated
void OS::terminateRunning() {
    int vmiTime = vm.clk - running->TurnaroundTime;
    running->VMTime += vmiTime;
    running->TurnaroundTime = vm.clk;
    running->outfile << "****************************************************" << endl;
    running->outfile << "CPU Time: " << running->VMTime << endl;
    running->outfile << "Waiting Time: " << running->WaitingTime << endl;
    running->outfile << "TurnaroundTime: " << running->TurnaroundTime << endl;
    running->outfile << "I/OTime: " << running->IOTime << endl;
    running->outfile << "Largest Stack Size: " << running->LSS << endl;
    processes--;
    setReady();
    setRunning();
    cSwitch++;
    }
