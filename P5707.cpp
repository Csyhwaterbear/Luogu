# include <iostream>
# include <iomanip>
using namespace std;
int main()
{
	int s, v;
	cin >> s >> v;
	int total_time = ( s + v - 1 ) / v + 10;
	int school_time = 8 * 60;
	int latest_departure_time = school_time - total_time;
	if (latest_departure_time < 0){
		latest_departure_time += 24 * 60;
	}
	int hours = latest_departure_time / 60;
	int minutes = latest_departure_time % 60;

	cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << endl;
	return 0;
}