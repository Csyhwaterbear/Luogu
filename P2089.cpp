#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> path;

int n;

void dfs(int idx, int sum)
{
	if (idx == 10)
	{
		if (sum == n)
			ans.push_back(path);
		return;
	}
	for (int x = 1; x <= 3; x++)
	{
		path.push_back(x);
		dfs(idx + 1, sum + x);
		path.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	if (n < 10 || n > 30)
	{
		cout << 0;
		return 0;
	}
	dfs(0, 0);

	cout << ans.size() << "\n";
	for (auto &v : ans)
	{
		for (int x : v)
		{
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}
