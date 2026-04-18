#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	bool cond = true;
	int n;
	cin >> n;
	vector<int> v(n);
	vector<bool> seen(n, false);
	cin >> v[0];
	for (int i = 1; i < n; i++)
	{
		cin >> v[i];
		int d = abs(v[i] - v[i-1]);
		if (d < 1 || d >= n || seen[d])
		{
			cond = false;
			break;
		}
		seen[d] = true;
	}
	cout << (cond?"Jolly":"Not jolly");
	return 0;
}
