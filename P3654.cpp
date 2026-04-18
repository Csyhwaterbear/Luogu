#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M, K;
	cin >> N >> M >> K;

	vector<string> g(N);
	for (int i = 0; i < N; i++) cin >> g[i];

	int ans = 0;
	if (K == 1)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (g[i][j] == '.')
					ans++;		
		cout << ans << "\n";
		return 0;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M - K; j++) {
			bool ok = true;
			for (int k = 0; k < K; k++) {
				if (g[i][j + k] != '.') {
					ok = false;
					break;
				 }
			}
			if (ok) ans++;
		}
	}
	 
	for (int i = 0; i <= N - K; i++) {
		for (int j = 0; j < M; j++) {
			bool ok = true;
			for (int k = 0; k < K; k++) {
				if (g[i + k][j] != '.') {
					ok = false;
					break;
				}
			}
			if (ok) ans++;
		}
	}
	
	cout << ans << "\n";
	return 0;
}
