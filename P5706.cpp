#include <iostream>
#include <iomanip>using namespace std;

int main() {
	double t;
	int n;

	cin >> t >> n;
	double per_person = t / n;
	int total_cups = n * 2;
	cout << fixed << setprecision(3) << per_person << endl;
	cout << total_cups << endl;
	return 0;
}