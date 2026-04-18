#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long n, m;
	cin >> n >> m;

	long long sq = 0;
	for (long long k = 1; k <= min(n, m); k++)
		sq += (n - k + 1) * (m - k + 1);
	long long all = (n * (n + 1) / 2) * (m * (m + 1 ) / 2);

	cout << sq << " " << all -sq;

	return 0;
}
