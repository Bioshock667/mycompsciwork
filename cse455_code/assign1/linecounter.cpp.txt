#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class LogLineCounter {
    public:
	LogLineCounter();
	int countLines(string filename);
	int getNumberofLines() {return TotalLines;}
    private:
	int TotalLines;
};

LogLineCounter::LogLineCounter() {
    TotalLines = 0;
}

int LogLineCounter::countLines(string filename) {
    string tempLine;
    ifstream in;
    in.open(filename.c_str());
    if(in.fail())
	return 0;
    while(in.good())
    {
	getline(in, tempLine);
	TotalLines++;
	if(tempLine.substr(0,1) == "/" || tempLine.length() == 0)
	    TotalLines--; //if line is neither a comment nor empty, count as a line
    }
    in.close();
    return 1;
}

int main() {
    string fname = "linecounter.cpp.txt";
    LogLineCounter llcounter;
    int status = llcounter.countLines(fname);
    if(status == 0)
    {
	cout << "Error: " << fname << " cannot be opened.\n";
	return 0;
    }
    int total = llcounter.getNumberofLines();
    cout << "Count successful!\n" << "Total # of Lines: " << total << "\n";
    return 1;
}
