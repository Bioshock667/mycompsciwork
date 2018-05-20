#include <iostream>
#include <string>
#include <fstream>
#include <numeric>
#include <vector>
#include <math.h>

using namespace std;

struct KahanAccumulation {
	double sum;
    	double correction;
};
class LRegressor {
    public:
	LRegressor() {r = 0;}
	int calculateR(string input_file);
	double getR() {return r;}
    private:
	KahanAccumulation KahanSum(KahanAccumulation A, double value);
	double r;
};

KahanAccumulation LRegressor::KahanSum(KahanAccumulation A, double value) {
    KahanAccumulation res;
    double y = value - A.correction;
    double t = A.sum + y;
    res.correction = (t - A.sum) - y;
    res.sum = t;
    return res;
}

int LRegressor::calculateR(string input_file) {
    ifstream input;
    input.open(input_file.c_str());
    double x, y;
    vector <double> X, Y;
    vector <double> Xp2, Yp2, XY;
    double sumX = 0, sumY = 0, n = 0;
    double  sumXY = 0, sumXp2 = 0, sumYp2 = 0;
    double num, denom;
    KahanAccumulation init = {0};
    KahanAccumulation result;
    int c = input.peek();
    if (c == EOF || input.fail()) 
    {
	cout << input_file << " is empty or doesn't exist.\n";
	return 0;
    }
    while(input.good() && c != EOF)
    {
  	input >> x;
	X.push_back(x);
	//sumXp2 += (x*x);
	input >> y;
	Y.push_back(y);
	Xp2.push_back(x*x);
	Yp2.push_back(y*y);
	XY.push_back(x*y);
	//sumY += y;
	//sumYp2 += (y*y);
	//sumXY += (x*y);
	n++;
	c = input.peek();
    }
    result = accumulate(X.begin(), X.end(), init, KahanSum);
    sumX = result.sum;
    result = accumulate(Y.begin(), Y.end(), init, KahanSum);
    sumY = result.sum;
    result = accumulate(Xp2.begin(), Xp2.end(), init, KahanSum);
    sumXp2 = result.sum;
    result = accumulate(Yp2.begin(), Yp2.end(), init, KahanSum);
    sumYp2 = result.sum;
    result = accumulate(XY.begin(), XY.end(), init, KahanSum);
    sumXY = result.sum;
    num = n * sumXY - sumX * sumY;
    denom = sqrt((n * sumXp2 - pow(sumX, 2)) * (n * sumYp2 - pow(sumY, 2)));
    r = num / denom;
    return 1;
}

int main (int argc, char* argv[]) {
    string filename;
    if(argc == 1)
	filename = "input.txt";
    else
	filename = string(argv[2]);
    LRegressor LR;
    int code = LR.calculateR(filename);
    if(code == 0)
	return 0;
    float R = LR.getR();
    cout << "Calculcation done!\n";
    cout << "R: " << R << "\n";
    cout << "R^2(Correlation): " << pow(R, 2) << "\n";
    return 1;
}
