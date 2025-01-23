# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, sum = 0, min = 1001, max = 0;
	cin >> n;
	for(int i = 0; i < n; i++ )
	{
		cin >> a;
		min=(a <= min?a:min);
		max=(a >= max?a:max);
		sum += a;
	}
	cout << fixed << setprecision(2) << (sum-min-max)*1.0/(n-2);
	return 0;
}
