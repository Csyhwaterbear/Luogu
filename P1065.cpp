#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	
	vector<int> order(m * n, 0);
	for (int i = 0; i < n * m; cin >> order[i++]);
	
	vector<vector<int>> machine(n, vector<int>(m));
	vector<vector<int>> cost(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> machine[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> cost[i][j];
	
	vector<int> step(n, 0);
	vector<int> finish(n, 0);
	
	vector<vector<int>> used(m, vector<int>(10000, 0));

	int ans = 0;
	for (int idx = 0; idx < m * n; idx++)
	{
		int job = order[idx] - 1;
		int op = step[job];

		int mac = machine[job][op] - 1;
		int len = cost[job][op];

		int t = finish[job] + 1;

		while (true)
		{
			bool ok = true;
			for (int k = t; k < t + len; k++)
			{
				if (used[mac][k])
				{
					ok = false;
					break;
				}
			}

			if (ok)
			{
				for (int k = t; k < t + len; k++)
				{
					used[mac][k] = 1;
				}
				finish[job] = t + len - 1;
				ans = max(ans, finish[job]);
				step[job]++;
				break;
			}
			t++;
		}
	}
	cout << ans << endl;
	return 0;
}

