#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> path;

void dfs(int start, int cnt) {
	if (cnt == k)
	{
		for (int x:path)
			cout << setw(3) << x;
		cout << "\n";
		return;
	}

	for (int i = start; i <= n; i++)
	{
		path.push_back(i);
		dfs( i + 1, cnt + 1);
		path.pop_back();
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	dfs(1, 0);
	 
	return 0;
}

