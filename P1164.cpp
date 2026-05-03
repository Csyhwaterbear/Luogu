#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	cin >> N >> M;
	vector<int> dp(M + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < N; i++)
	{
		int price;
		cin >> price;

		for (int j = M; j >= price; j--)
			dp[j] += dp[j - price];
	}

	cout << dp[M] << "\n";
	return 0;
}

