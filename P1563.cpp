#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> orient(n);
	vector<string> name(n);

	for (int i = 0; i < n; i++)
		cin >> orient[i] >> name[i];

	int pos = 0;
	for (int i =0; i < m; i++)
	{
		int a, s;
		cin >> a >> s;
		int dir = (a == orient[pos]) ? -1 : 1;

		pos = (pos + dir * s) % n;
		if (pos < 0) pos += n;
		pos %= n;
	}
	cout << name[pos] << endl;
	return 0;
}
