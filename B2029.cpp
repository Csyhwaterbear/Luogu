# include <iostream>
# include <cmath>
using namespace std;
int main(){
	int h, r;
	double volume;
	cin >> h >> r;
	volume	= 3.14*r*r*h;
	cout << ceil(20000.0/volume);
}
