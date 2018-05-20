#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

class LRegressor {
    public:
	LRegressor() {r = 0;}
	int calculateR(string input_file);
	double getR() {return r;}
    private:
	double r;
};

int LRegressor::calculateR(string input_file) {
    ifstream input;
    input.open(input_file.c_str());
    double x, y;
    double Xp2, Yp2, XY;
    double sumX = 0, sumY = 0, n = 0;
    double sumXY = 0, sumXp2 = 0, sumYp2 = 0;
    double num, denom;
    int c = input.peek();
    if (c == EOF || input.fail()) 
    {
	cout << input_file << " is empty or doesn't exist.\n";
	return 0;
    }
    while(input.good() && c != EOF)
    {
  	input >> x;
	sumX += x;
	sumXp2 += (x*x);
	input >> y;
	sumY += y;
	sumYp2 += (y*y);
	sumXY += (x*y);
	n++;
	c = input.peek();
    }
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
    double R = LR.getR();
    cout << "Calculcation done!\n";
    cout << "R: " << R << "\n";
    cout << "R^2(Correlation): " << pow(R, 2) << "\n";
    return 1;
}
