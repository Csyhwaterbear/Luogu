#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	vector<int> f(n+1,0);
	f[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		f[i] = 1;
		for (int j = 1; j <= i / 2; j++)
			f[i] += f[j];
	}
	cout << f[n] << "\n"; 
	return 0;
}

