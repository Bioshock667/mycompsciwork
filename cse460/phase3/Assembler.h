#ifndef ASSEMBLER_H
#define ASSEMBLER_H
#include <string>
using namespace std;
class Assembler
{
    friend class OS;
    private:
        int line;

        enum instr_type {dm, op, ctr, ctrn, ctra};
        instr_type iType;
        int checkOP(string opc);
        void aError(string error_type);
    public:
        Assembler();
        void compile(string fname);

};

#endif // ASSEMBLER_H
