//VirtualMachine.cpp
//Programmed by Seth Lemanek
//Prof. Key Zemoudeh
//Cass: CSE 460 
//Date Modified April, 28, 2015
//This program takes in an object file and executes it.  Its purpose is to
//simulate a 16-bit computer.  It comes with many features of basic computers 
// susch as stack pointer for recursion, a register for holding status flags 
// and a program counter to go through the program.  It puts its output and 
// clock cycle in a .out file.
//Phase 2 Update: now this version no longer directly reads and writes data 
//except for reading .o files.  Instead it returns status on status register 
//and stops running to allow OS to swap programs.
#include "VirtualMachine.h"
#include "entry.h"
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

VirtualMachine::VirtualMachine()
{
    /*construct a new virtual machine and  initializes its components*/
    r = vector <int> (REG_FILE_SIZE);
    mem = vector <int> (MEM_SIZE);
    lruReg = vector <int> (LREG_SIZE);
    TLB = vector <entry> (LREG_SIZE);
    interrupt = false;
    pc = 0;
    ir = 0;
    clk = 0;
    base = 0;
    limit = 0;
    sr = 0;
    hit = 0;
    op = 0;
    rd = 0;
    rs = 0;
    i = 0;
    addr = 0;
    cnst = 0;
    sp = 256;
    pRD = 0;

        instr [0] = &VirtualMachine::load;
        instr [1] = &VirtualMachine::store;
        instr[2] = &VirtualMachine::add;
        instr[3] = &VirtualMachine::addc;
        instr[4] = &VirtualMachine::sub;
        instr[5] = &VirtualMachine::subc;
        instr[6] = &VirtualMachine::And;
        instr[7] = &VirtualMachine::Xor;
        instr[8] = &VirtualMachine::Compl;
        instr[9] = &VirtualMachine::shl;
        instr[10] = &VirtualMachine::shla;
        instr[11] = &VirtualMachine::shr;
        instr[12] = &VirtualMachine::shra;
        instr[13] = &VirtualMachine::compr;
        instr[14] = &VirtualMachine::getstat;
        instr[15] =  &VirtualMachine::putstat;
        instr[16] = &VirtualMachine::jump;
        instr[17] = &VirtualMachine::jumpl;
        instr[18] = &VirtualMachine::jumpe;
        instr[19] = &VirtualMachine::jumpg;
        instr[20] = &VirtualMachine::call;
        instr[21] = &VirtualMachine::Return;
        instr[22] = &VirtualMachine::read;
        instr[23] = &VirtualMachine::write;
        instr[24] = &VirtualMachine::halt;
        instr[25] = &VirtualMachine::noop;
}

void VirtualMachine::execute()
{
    int countdown = clk + timer;
    if(pc < base)
	pc = base;
    while (!interrupt)
    {
	if(pc < (base + limit))//vm will not work will can intruction outside its designated frame
	{
   	   ir = mem[pc];
	    pc++;
   	    interpret(ir);
	    if( op < 0 || op > 25)//invalid opcode
	    {
	    	sr &= 31;
	    	sr |= 160;
	    	interrupt = true;
	    }
	    else 
   	    	(this->*instr[op])();
		if(interrupt)
		    break;//interrupts called by instruction are higher priority than others
	}
	if (clk >= countdown) {
		sr &= 31;
		interrupt = true;
		  //cout << "TS Interrupt" << clk << " >= " << countdown << endl;
	}
	ir = 0;
	if ((pc) >= MEM_SIZE)//out of bounds
	{
	   sr &= 31;
	   sr |= 64;
	   interrupt = true;
	}
	else if ( pc >= (base + limit)) //page fault
	{
	    int num = translate();
	    if(num >= 0)
	    	pc = num;
	}
    }
}

void VirtualMachine::interpret(int line)
{
        class format1 {
        public:
        unsigned UNUSED:6;
        unsigned RS:2;
        unsigned I:1;
        unsigned RD:2;
        unsigned OP:5;
    };
    class format2 {
    public:
        unsigned ADDR:8;
        unsigned I:1;
        unsigned RD:2;
        unsigned OP:5;
    };
    class format3 {
    public:
            int CONST:8;
            unsigned I:1;
            unsigned RD:2;
            unsigned OP:5;
    };

    union instruction {
            int i;
            format1  f1;
            format2  f2;
            format3  f3;
    };




    instruction ins;
    ins.i = line;
    op = ins.f1.OP;
    rd = ins.f1.RD;
   if (ins.f1.I == 1)
       i = 1;
   else
        i = 0;
    if(op == 0)
    {
        if(i == 0)
        {
        addr = ins.f2.ADDR;
        rs = 0;
        cnst = 0;
        }
        else
        {
            cnst = ins.f3.CONST;
            rs = 0;
            addr = 0;
        }
    }
    else if (op == 1) // for store function
    {
        addr = ins.f2.ADDR;
        rs = 0;
        cnst = 0;
    }
    else if((op >=2 && op <=7)|| op == 13)//for the operate instructions (add, sub, etc.)
    {
        if(i==0)
        {
            rs = ins.f1.RS;
            addr = 0;
            cnst = 0;
        }
        else if (i == 1)
        {
            cnst = ins.f3.CONST;
            addr = 0;
            rs = 0;
        }
    }
    else if(op >=16 && op <= 20) //for jump and call functions
    {
        addr = ins.f2.ADDR;
        rs = 0;
        cnst = 0;
    }
    else //for compliment, shift, return read, write, noop, halt
    {
        addr = 0;
        rs = 0;
        cnst = 0;
    }
}

int VirtualMachine::translate()//finds the actual address location 

{
    int index = 0;
    int offset = 0;
    if(ir != 0) //called by instruction
    { 
    	index = addr >> 3;
    	offset = addr & 7;
    }
    else //caused by pc out of block
    {
	for(int i = 0; i < 32; i++)//find the current page
	{
	    if(TLB[i].valid == true)
	    {
		if(TLB[i].frame == base/8)//if current base is at this frame
		{
		    index = i;
		    break;
		}
	    }
	}
	index++;//the next page will be searched or page faulted
	offset = 0;//start at beginning of page
    }
    int address = 0;
    if(TLB[index].valid == true)//reference found in TLB
    {
	hit++;
	lruReg[index] = clk; //update timestamp for this frame
        address = TLB[index].frame << 3;
	if(op > 1 || ir == 0)//if not a dm instr or pc out of frame.
	    base = address;
    	address += offset;
	clk += 4;
	return address; //pc or memory address will use this number
    }
    else//reference not found do system trap page fault
    {
	hit--;//that way when jump to newly referenced frame occurs it doesent count as a non-page fault reference
	sr &= 1023;	
	sr |= 1024;
	interrupt = true;
	if(ir == 0)
	   jumpto = true;//tells os to set pc and base onto new block
	pc--;//undo increment so pc is on right address after page fault is finished
	page = index; //virtual machine will request this page
	return -1;//return error
    }
}
void VirtualMachine::setCarry(int c)
{
    if(c == 0)
        sr = sr & 62;
    else if (c == 1)
        sr = sr | 1;
    else
        return;
}

void VirtualMachine::setOverflow(int v)
{
    if(v == 0)
        sr = sr & 15;
    else if (v == 1)
        sr = sr | 16;
    else
        return;
}

void VirtualMachine::mtSixteen(int prd, int add, int result)
 /*this function checks for overflow and carry and corrects the sign by sign-extending
    over the highest 16 bits when the number is out of bounds for the register's
    signed 16-bit format. This function will insure that carry and overflow is set when
    the data leaves the format.*/
{
    enum sign {pos, neg, diff};
    sign mySign;
    if((prd & 32768) == 32768 && (add & 32768) == 32768)
	mySign = neg;
    else if ( (prd & 32768) == 0 && (add & 32768) == 0)
	mySign = pos;
    else
	mySign = diff;

    if((result & 65536) == 65536)
    {
        setCarry(1);
    }
    else
	setCarry(0);
    if((result & 32768) == 32768 && mySign == pos)  //if bit 16 equals 1 it is negative (bits above bit 16 equal one).
    {
            setOverflow(1);
    }
    else if ((result & 32768) == 0 && mySign == neg) //bit 16 equals 0
    { 
       	     setOverflow(1);
    }
    else
	     setOverflow(0);
      r[rd] &= 65535;
}
void VirtualMachine::load()
{
    int num = 0;
    if (i == 0)
    {
	num = translate();
	if(num != -1)
	{
            r[rd] = mem[num];
            clk += 4;
	}
    }
    else // i = 1 : immediate mode
    {
       	r[rd] = cnst;
       	clk++;
   }
   r[rd] &= 65535; //all registers must hold no more than 16 bits therefore zero out the higher 16 bits;
}

void VirtualMachine::store()
{
    int index = addr >> 3;
    int num = translate();
    if(num != -1)
    {    
	mem[num] = r[rd];
	TLB[index].modify = true;
        clk += 4;
    }
}
void VirtualMachine::add()
{
    pRD = r[rd]; 
    if (i == 0) {
        r[rd] += r[rs];
	mtSixteen(pRD, r[rs], r[rd]);
	}
    else {
	cnst &= 65535;
        r[rd] += cnst;
	mtSixteen(pRD, cnst, r[rd]);
	}
    clk++;
}
void VirtualMachine::addc()
{
    add();
    r[rd] += (sr & 1);
    if(i == 0){
	mtSixteen(pRD, r[rs], r[rd]);
	}
    else {
	mtSixteen(pRD, cnst, r[rd]);
	}
    clk++;
}
void VirtualMachine::sub()
{
    pRD = r[rd];
    int opd;
    if (i == 0){
      opd = r[rs];
	}
    else{
	 opd = cnst;
	}
    opd = (~opd);
    opd++;
    opd &= 65535;
    r[rd] += opd; // subtract using 2's complement
    mtSixteen(pRD, opd, r[rd]);
    clk++;

}
void VirtualMachine::subc()
{
   sub();
   r[rd] -= sr&1;
   if (i == 0) 
     mtSixteen(pRD, r[rs], r[rd]);
   else
     mtSixteen(pRD, cnst, r[rd]);
}
void VirtualMachine::And()
{
    if (i == 0)
        r[rd] &= r[rs];
    else{
	cnst &= 65535;
        r[rd] &= cnst;
	}
}
void VirtualMachine::Xor()
{
    if (i == 0)
        r[rd] ^= r[rs];
    else{
	cnst &= 65535;
        r[rd] ^= cnst;
	}
    clk++;
}
void VirtualMachine::Compl()
{
    r[rd] = ~r[rd];
    r[rd] &= 65535;
    clk++;
}
void VirtualMachine::shl()
{
    pRD = r[rd];
    r[rd] <<= 1;
    clk++;
    mtSixteen(pRD, pRD, r[rd]);

}
void VirtualMachine::shla ()
{
    bool isPos;
    if ((r[rd] & 32768) == 0)
	isPos = true;
   else
	isPos = false;
    pRD = r[rd];
    r[rd] <<= 1;
    if (isPos) //if r[rd] is signed positive, make bit 16 and higher bits  0
	r[rd] = r[rd] & 32767;
    else // otherwise, just make bit 16 equal 1
	r[rd] = r[rd] | 32768;
    mtSixteen(pRD, pRD, r[rd]);
    clk++;
}
void VirtualMachine::shr ()
{
    pRD = r[rd];
    if (r[rd] % 2 == 1) //carry out bit 1 before shifting
	setCarry(1);
    else
	setCarry(0);
    r[rd] >>= 1;
    clk++;
}
void VirtualMachine::shra ()
{
     bool wasNeg;
     if ((r[rd] & 32768) == 32768)
         wasNeg = true;
     else
         wasNeg = false;
    if(r[rd] % 2 == 1)
        setCarry(1);
    else
	setCarry(0);
    r[rd] >>= 1;
    if (wasNeg)
      r[rd] |=  32768;
    else
      r[rd] &= 32767;
    clk++;
}
void VirtualMachine::compr()
{
    int opr = 0;
    if(i==0)
	opr = r[rs];
    else
	opr = cnst;
   opr &= 65535;
   int sign = (r[rd] & 32768) ^ (opr & 32768);//sign returns zero if both numbers are same sign
   if(r[rd] < opr) {
	if (sign == 0)//if the 2 numbers are same sign interpret less than
            sr = (sr & 17)|8;
	else//different signs then interpret greater than flag
	    sr = (sr & 17)|2;
	}
    else if (r[rd] == opr)
        sr = (sr & 17)|4;
    else{
	if (sign == 0)//if both are same sign then interpret greater than flag
            sr = (sr & 17)|2;
	else//if both are different sign then interpret less than flag
	    sr = (sr & 17)|8;
	}
    clk++;
}
void VirtualMachine::getstat()
{
    r[rd] = sr;
    clk++;
}
void VirtualMachine::putstat()
{
    sr = r[rd];
    clk++;
}
void VirtualMachine::jump ()
{
    int num = translate();
    if(num != -1){
    	pc = num;
    	clk++;
    }
}
void VirtualMachine::jumpl ()
{
    int num = 0;
    if ((sr & 8) == 8)
    {
     	num = translate();
     	if(num != -1)
     	{
             pc = num;
       	     clk++;
     	}
    }
}
void VirtualMachine::jumpe ()
{
    int num = 0;
    if ((sr & 4) == 4)
    {
         num = translate();
         if(num != -1)
         {
             pc = num;
             clk++;
         }
    }
}  
void VirtualMachine::jumpg ()
{
    int num = 0;
    if((sr & 2) == 2)
    {
	num = translate();
	if(num != -1)
	{
            pc = num;
            clk++;
	}
    }
}
void VirtualMachine::call()
{
    int num = translate();
    if(num != -1)
    {
    	if ((sp - 6) < stackLimit)//stack overflow
    	{
	    sr &= 31;
	    sr |= 96;
	    pc--;
	    interrupt = true;
    	}
    	else {//otherwise do the call function
    	    --sp;
    	    mem[sp] = pc;
    	    --sp;
    	    mem[sp] = r[0];
    	    --sp;
    	    mem[sp] = r[1];
    	    --sp;
    	    mem[sp] = r[2];
    	    --sp;
    	    mem[sp] = r[3];
    	    --sp;
    	    mem[sp] = sr;
    	    pc = num;
    	    clk += 4;
    	}
    }
}
void VirtualMachine::Return ()
{
    if (sp >= 256)//stack underflow
    {
	sr &= 31;
	sr |= 128;
	interrupt = true;
    }
    else {
    	sr = mem[sp];
    	++sp;
    	r[3] = mem[sp];
    	++sp;
    	r[2] = mem[sp];
    	++sp;
    	r[1] = mem[sp];
    	++sp;
    	r[0] = mem[sp];
    	++sp;
    	pc = mem[sp];
    	++sp;
    	clk += 4;
    }
}
void VirtualMachine::read ()
{
    sr &= 31;
    sr |= 192; //set sr[7:5] to 110 
    sr &= 255;
    pRD = rd << 8;
    sr |= pRD; //set sr[9:8]
    interrupt = true;
    clk++;
}
void VirtualMachine::write ()
{
    
    sr &= 31;
    sr |= 224; //set sr[7:5] to 111
    sr &= 255;
    pRD = rd << 8;
    sr |= pRD;
    clk++;
    interrupt = true;
}
void VirtualMachine::halt()
{
    sr &= 31;
    sr |= 32; //return halt instruction to OS
    clk++;
    interrupt = true;
}
void VirtualMachine::noop ()
{
    clk++;
}
