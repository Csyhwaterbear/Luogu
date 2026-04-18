#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const int MAXA = 5005;

long long cnt[MAXA];
int n;

long long C2(long long x) {
	if (x < 2) return 0;
	return x * (x - 1) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	
	int maxLen = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
		maxLen = max(maxLen, x);
	}
	
	long long ans = 0;

	for (int i = 1; i <= maxLen; i++) {
		if (cnt[i] < 2) continue;
		long long waysTwoI = C2(cnt[i]);
		 
		for (int j = 1; j <= i / 2; j++) {
			int k = i - j;
			if (j != k) {
				ans = (ans + waysTwoI * cnt[j] % MOD * cnt[k] % MOD) % MOD;
			} else {
				ans = (ans + waysTwoI * C2(cnt[j]) % MOD) % MOD;
			}
		}
	}
	cout << ans % MOD << "\n";
	return 0;
}

