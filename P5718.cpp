# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, b = 10001;
	cin >> n;
	for(int i = 0; i < n; i++ )
	{
		cin >> a;
		b=(a <= b?a:b);
	}
	cout << b;
	return 0;
}
