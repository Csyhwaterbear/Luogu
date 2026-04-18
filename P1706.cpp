#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> path;
bool used[10];

void dfs() {
	if (int(path.size()) == n)
	{
		for (int x: path)
		{
			cout << setw(5) << x;
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			used[i] = true;
			path.push_back(i);
			dfs();
			path.pop_back();
			used[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	dfs();
	return 0;
}

