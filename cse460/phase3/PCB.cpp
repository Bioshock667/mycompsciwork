#include "PCB.h"
PCB::PCB()
{
    reg[0] = 0;
    reg[1] = 0;
    reg[2] = 0;
    reg[3] = 0;
    pF = 0;
    Hit = 0;
    pc = 0;
    base = 0;
    limit = 0;
    sp = 0;
    sr = 0;
    VMTime = 0;
    WaitingTime = 0;
    TurnaroundTime = 0;
    IOTime = 0;
    LSS = 0;
}
