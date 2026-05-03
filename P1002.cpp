#include <bits/stdc++.h>
using namespace std;

long long dp[25][25];
bool blocked[25][25];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int bx, by, cx, cy;
	cin >> bx >> by >> cx >> cy;

	int dx[9] = {0, -1, -1, 1, 1, -2, -2, 2, 2};
	int dy[9] = {0, -2, 2, -2, 2, -1, 1, -1, 1};
	
	for (int k = 0; k < 9; k++) {
		int nx = cx + dx[k];
		int ny = cy + dy[k];
		if (nx >= 0 && nx <= bx && ny >= 0 && ny <= by) {
			blocked[nx][ny] = true;
		}
	}
	
	dp[0][0] = 1;
	
	for (int i = 0; i <= bx; i++) {
		for (int j = 0; j <= by; j++)  {
			if (blocked[i][j]) {
				dp[i][j] = 0;
				continue;
			}
			if (i == 0 && j == 0) continue;
			
			if (i > 0) dp[i][j] += dp[i - 1][j];
			if (j > 0) dp[i][j] += dp[i][j - 1];
		}
	}
	cout << dp[bx][by] << "\n";
	return 0;
}

