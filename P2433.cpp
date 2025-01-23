# include <iostream>
# include <iomanip>
# include <cmath>
using namespace std;
int main(){
	int C;
	cin >>  C;
	switch (C){
		case 1:
			cout << "I love Luogu!";
			break;
		case 2:
			cout << 6 << " " << 4;
			break;
		case 3:
			cout << 3 << endl;
			cout << 12 << endl;
			cout << 2;
			break;
		case 4:
			cout << fixed << setprecision(3) << 500.0/3.0;
			break;
		case 5:
			cout << floor( (260+220)/(12 + 20) );
			break;
		case 6:
			cout << sqrt(6*6+9*9);
			break;
		case 7:
			cout << 110 << "\n" << 90 << "\n" << 0;
			break;
		case 8:
			cout << 10*3.141593 << endl;
			cout << 5.0*5.0*3.141593 << endl;
			cout << 4.0/3.0*3.141593*125.0 << endl;
			break;
		case 9:
			cout << 22;
			break;
		case 10:
			cout << 9;
			break;
		case 11:
			cout << 100.0/3.0;
			break;
		case 12:
			cout << 13 << endl << "R";
			break;
		case 13:
			cout << floor( pow( 4.0/3.0*3.141593*1064, 1.0/3.0 ) );
			break;
		case 14:
			cout << 50;
			break;
		default:
			break;
	}
	return 0;
}
