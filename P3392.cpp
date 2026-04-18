#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M;
	cin >> N >> M;

	vector<string> g(N);
	for (int i = 0; i < N; i++) cin >> g[i];

	vector<int> costW(N, 0), costB(N, 0), costR(N, 0);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (g[i][j] != 'W') costW[i]++;
			if (g[i][j] != 'B') costB[i]++;
			if (g[i][j] != 'R') costR[i]++;
		}
	}

	int ans = INT_MAX;
	
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; i + j <= N - 1; j++) {
			int sum = 0;
			for (int r = 0; r < i; r++) sum += costW[r];
			for (int r = i; r < i + j; r++) sum += costB[r];
			for (int r = i + j; r < N; r++) sum += costR[r];
			ans = min(ans, sum);
		}
	}
	
	cout << ans << "\n";
	return 0;
}

