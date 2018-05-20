#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class LinReg2 {
    public:
	LinReg2(string filename);
	void compObjLOCtoNewLOC() {compare(ObjLOC, ActLOC);}
	void compEstNewLOCtoNewLOC() {compare(EstLOC, ActLOC);}
	double getB0() {return B_0;}
	double getB1() {return B_1;}
    private:
	void compare (vector<double> X, vector<double> Y);
	double B_0;
	double B_1;
	vector<double> ObjLOC;
	vector<double> EstLOC;
	vector<double> ActLOC;
};

LinReg2::LinReg2(string filename) {
    B_0 = 0, B_1 = 0;
    ifstream in;
    in.open(filename.c_str());
    double value;
    in >> value;
    while (in.good())
    {
	ObjLOC.push_back(value);
	in >> value;
	EstLOC.push_back(value);
	in >> value;
	ActLOC.push_back(value);
	in >> value;
    }
    in.close();
}

void LinReg2::compare(vector<double> X, vector<double> Y) {
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < Y.size(); i++)
    {
	sumX += X[i];
	sumY += Y[i];
	sumXY += (X[i] * Y[i]);
	sumX2 += (X[i] * X[i]);	
    }
    double n = (double)Y.size();
    double avgX = sumX / n;
    double avgY = sumY / n;
    double num = sumXY - n * avgX * avgY;
    double denom = sumX2 - n * avgX * avgX;
    B_1 = num / denom;
    B_0 = avgY - B_1 * avgX;
}

int main( int argc, char* argv[])
{
    string filename;
    if(argc == 1)
	filename = "input.txt";
    else if (argc == 2)
	filename = argv[1];
    else
    {
	cout << "Invalid Arguement.\n";
	return 0;
    }
    LinReg2 LR(filename);
    LR.compObjLOCtoNewLOC();
    cout << "y = B0 + B1*x|| for y is actual new and changed LOC and x is estimated object LOC:\n";
    cout << "B0: " << LR.getB0() << "\n";
    cout << "B1: " << LR.getB1() << "\n";
    LR.compEstNewLOCtoNewLOC();
    cout << "y = B0 + B1*x|| for y is actual new and changed LOC and x is estimated new and changed LOC:\n";
    cout << "B0: " << LR.getB0() << "\n";
    cout << "B1: " << LR.getB1() << "\n";
    return 1;
}
