#ifndef OS_H
#define OS_H

#include "VirtualMachine.h"
#include "Assembler.h"
#include "PCB.h"
#include <fstream>
#include <queue>
#include <string>
#include <list>

using namespace std;


class OS {
public: 
     void run(char mode[]);
private:
    Assembler as;
    VirtualMachine vm;
    ifstream progs;
    int highestFrameUsed;
    int processes, VMRStat, cSwitch, reqPage;
    static const int timeSlice = 15;
    int fifoReg [32];
    enum Mode {FIFO, LRU};
    Mode myMode; 
    double idTime, totalVMTime, tPut;
    static const int degProg = 5;
    queue <PCB*> readyQ, waitQ;
    PCB* memMap [32];
    bool terminate;
    list <PCB*> jobs;
    PCB * running;
    void loadProg(string nfile);
    void loadBlock(PCB* r, int frame);
    void removeBlock(int frame);
    void contextSwitch();
    void setRunning();
    void saveProcess();
    void setReady();
    void pageFault(PCB* r);
    void terminateRunning();
    void powerOff();
};
#endif
