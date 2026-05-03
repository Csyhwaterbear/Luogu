#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	if (!(cin >> N)) return 0;
	vector<int> dp(N + 1);
	dp[0] = 1, dp[1] = 1, dp[2] = 2;
	for(int i = 3; i <= N; i++)
		dp[i] = (2 * dp[i - 1] + dp[i - 3]) % 10000;
	cout << dp[N] << "\n";
	return 0;
}
