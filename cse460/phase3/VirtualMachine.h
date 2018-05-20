#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H


#include <vector>
#include <map>
#include "entry.h"

using namespace std;


class VirtualMachine {
   friend class OS;
   private:
        static const int REG_FILE_SIZE = 4;
        static const int MEM_SIZE = 256;
	static const int LREG_SIZE = 32;
        vector <int> r;
	vector <int> lruReg;
        vector <int> mem;
	vector <entry> TLB;
	bool interrupt, jumpto;
	int timer;
	int stackLimit;
        int pc;
        int ir;
        int clk;
        int base;
        int limit;
        int sr;
        int sp;
	int page, hit;
        unsigned int op;
        unsigned int rd;
        unsigned int rs;
        unsigned  int i;
        unsigned int addr;
        int cnst;
	int pRD;
	bool inf;
	bool outf;
	int translate();
        void interpret(int line);
        void setCarry(int c);
        void setOverflow(int v);
        void mtSixteen(int prd, int add, int result);

        typedef void (VirtualMachine::*FP)();

        map<int, FP> instr;

        void load();
        void store();
        void add();
        void addc();
        void sub();
        void subc();
        void And();
        void Xor();
        void Compl();
        void shl();
        void shla ();
        void shr ();
        void shra ();
        void compr();
        void getstat();
        void putstat();
        void jump ();
        void  jumpl ();
        void jumpe ();
        void jumpg ();
        void call();
        void Return ();
        void read ();
        void write ();
        void halt ();
        void noop ();

    public:
        VirtualMachine();
        void execute();
};


#endif // VIRTUALMACHINE_H
