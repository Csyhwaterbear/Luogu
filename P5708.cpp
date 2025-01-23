#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;

	double p = (a + b + c) / 2.0;

	
	if (a + b > c && a + c > b && b + c > a) {
		double area = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << fixed << setprecision(1) << area << endl;
	} else {
		cout << "Invalid triangle" << endl;
	}
	return 0;
}