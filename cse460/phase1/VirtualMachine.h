#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H


#include <vector>
#include <string>
#include <map>
#include <stack>
#include <fstream>

using namespace std;


class VirtualMachine {
   private:
        static const int REG_FILE_SIZE = 4;
        static const int MEM_SIZE = 256;
        vector <int> r;
        vector <int> mem;
	stack <int> s;
        int pc;
        int ir;
        int clk;
        int base;
        int limit;
        int sr;
        int sp;
        unsigned int op;
        unsigned int rd;
        unsigned int rs;
        unsigned  int i;
        unsigned int addr;
        int cnst;
	int pRD;
        ifstream in;
        ofstream out;
	bool inf;
	bool outf;
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
        void read (string filename);
	void checkMemory();
        void execute ();
};


#endif // VIRTUALMACHINE_H
