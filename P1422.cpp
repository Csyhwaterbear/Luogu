# include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a;
	cin >> a;
	if ( a <= 150.0 ) cout << fixed << setprecision(1) << a * 0.4463;
	else if ( 150 < a && a <= 400 ) cout << fixed << setprecision(1) << 150 * 0.4463 + ( a - 150 ) * 0.4663;
	else cout << fixed << setprecision(1) << 150 * 0.4463 + 250 * 0.4663 + ( a - 400 ) * 0.5663;
	return 0;
}
