//a prototype of a virtual machine using a map of strings and function pointers.

#include <map>
#include <iostream>
#include <string>

using namespace std;

class FArray {
	typedef void (FArray::*FP)(string);
	
	void load(string s) {cout << "Load: " << s << endl;}
	void add(string s) {cout << "Add: " << s << endl;}
	void store(string s) {cout << "Store: " << s << endl;}
	map<string, FP> instr;
public:
	FArray();
	int assemble();
};

FArray::FArray()
{
	instr["load"] = &FArray::load;
	instr["add"] = &FArray::add;
	instr["store"] = &FArray::store;
}

int FArray::assemble()
{
	string opcode;
	cin >> opcode;
	(this->*instr[opcode])("something");
}

main()
{
	FArray farray;
	farray.assemble();
}		
