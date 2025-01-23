# include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[10], b;
	for( int i = 0; i < 10; i++ ){cin >> a[i];}
	sort(a, a+10);

	cin >> b;

	cout << upper_bound( a, a+10, b+30 ) - a;
	return 0;
}
