#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[25];
int ans = 0;

bool isPrime(int x) {
	if (x < 2) return false;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

void dfs(int pos, int cnt, int sum) {
	if (cnt == k) {
		if (isPrime(sum)) ans++;
		return;
	}
	
	if (pos == n) return;
	if (n - pos < k - cnt) return;
	
	dfs(pos + 1, cnt + 1, sum + a[pos]);
	dfs(pos + 1, cnt, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> a[i];
	
	dfs(0, 0, 0);
	 
	cout << ans << "\n";
	return 0;
}

