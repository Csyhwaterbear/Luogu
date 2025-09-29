# include <bits/stdc++.h>
using namespace std;
int main()
{
	float s;
	cin >> s;
	cout << ceil( log( 1 - 0.01*s ) / log( 0.98 ) );

	return 0;
}
