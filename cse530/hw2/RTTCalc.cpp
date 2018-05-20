#include <iostream>
#include <cmath>

using namespace std;
int main() {
    cout << "Welcome to RTT calculator!" << endl;

    cout << "Enter your alpha value: ";
    double a, b, ertt, srtt, drtt, toint;
    cin >> a;
    cout << "Enter your beta value: ";
    cin >> b;
    cout << "Set your first estimated RTT in milliseconds: ";
    cin >> ertt;
    cout << "Set your first devRTT in milliseconds: ";
    cin >> drtt;
    cout << "Enter '-1' to quit" << endl;
    cout << "Sample RTT in milliseconds: ";
    cin >> srtt;
    while(srtt >= 0) {
	ertt = (1 - a) * ertt + a * srtt;
	drtt = (1 - b) * drtt + b * abs(srtt - ertt);
	toint = ertt + 4 * drtt;
	cout << "************************************************" << endl
		<< "Estimated RTT:\t\t" << ertt << endl << "DevRTT:\t\t\t" << drtt
		<< endl << "Timeout Interval:\t" << toint << endl <<
		"***********************************************" << endl;
	cout << " Enter next Sample RTT value in milliseconds: ";
	cin >> srtt;
    }
    return 0;
}
