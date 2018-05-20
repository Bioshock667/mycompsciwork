/*
Name: Seth Lemanek
Program: linecounter for assignment 2
Date Revised: Feb 6 2016
*/ 
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Object {
    private:
	Object (string oName);
	string name;
	int objectLines;
	int totalMethods;
	friend class ProgramLineCounter;
};

class ProgramLineCounter {
    public:
	ProgramLineCounter();
	int countLines(string filename);
	int getNumberofLines() {return TotalLines;}
	void displayObjects();
    private:
	int TotalLines;
	vector<Object*> classes;
};
Object::Object (string oName) {
    name = oName;
    objectLines = 0;
    totalMethods = 0;
}
ProgramLineCounter::ProgramLineCounter() {
    TotalLines = 0;
}
//counts logical lines and classes and its name, logical lines, and methods for program 
int ProgramLineCounter::countLines(string filename) {
    int cPointer = -1;
    string tempLine, tempWord, cName;
    ifstream in;
    string::size_type n;
    bool isMLC = false;
    bool inClass = false;
    istringstream buffer;
    in.open(filename.c_str());
    if(in.fail())
	return 0;
    while(in.good())
    {
	getline(in, tempLine);
	buffer.str(tempLine);
	buffer >> tempWord;
	if(isMLC == false && tempWord.substr(0,2) == "/*")
	    isMLC = true;
	else if(isMLC ==true && tempWord.substr(0,2) == "*/")
	    isMLC = false;
	if(inClass == false) 
	{	
	    if(tempWord == "class")
	    {
	    	inClass = true;
		buffer >> cName;
	    	classes.push_back(new Object(cName));
	    	cPointer += 1;
	    }
	}
	if(inClass == true)
	{
	    n = tempLine.find("(");
	    if(n != string::npos)
		classes[cPointer]->totalMethods += 1;
	    if(!(tempWord.substr(0,1) == "/" || tempLine.length() == 0 ||isMLC))
	    	classes[cPointer]->objectLines += 1;
	    if( tempWord.substr(0,2) == "};")
	    	inClass = false;
	}
	if(!(tempWord.substr(0,1) == "/" || tempLine.length() == 0 ||isMLC))
	{
	    TotalLines++; //if line is neither a comment nor empty, count as a line
	}
	tempWord = "";
	buffer.str("");
	buffer.clear();
    }
    in.close();
    return 1;
}

void ProgramLineCounter::displayObjects() {
    for(int i = 0; i<classes.size(); i++)
    {
	cout << "Object Name: " << classes[i]->name << "\n";
	cout << "	Methods: " << classes[i]->totalMethods << "\n";
	cout << "	LOC: " << classes[i]->objectLines << "\n";
    }
    cout << "Object count finished!\n";
}

int main() {
    string fname = "linecounter.cpp.txt";
    ProgramLineCounter llcounter;
    int status = llcounter.countLines(fname);
    if(status == 0)
    {
	cout << "Error: " << fname << " cannot be opened.\n";
	return 0;
    }
    int total = llcounter.getNumberofLines();
    cout << "Count successful!\n" << "Total # of Lines: " << total << "\n";
    llcounter.displayObjects();
    return 1;
}
