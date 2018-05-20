#ifndef OS_H
#define OS_H

#include "VirtualMachine.h"
#include "Assembler.h"
#include "PCB.h"
#include <queue>
#include <list>

using namespace std;


class OS {
public: 
     void run();
private:
    Assembler as;
    VirtualMachine vm;
    int processes, VMRStat;
    int cSwitch, idTime, totalVMTime, tPut;
    static const int timeSlice = 15;
    queue <PCB*> readyQ, waitQ;
    bool terminate;
    list <PCB*> jobs;
    PCB * running;
    void contextSwitch();
    void setRunning();
    void saveProcess();
    void setReady();
    void terminateRunning();
    void powerOff();
};
#endif