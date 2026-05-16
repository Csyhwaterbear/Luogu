#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, x;
	if (!(cin >> n >> x)) return 0;
	vector<long long> a(n + 1);
	a[0] = 0;
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] + a[i-1] > x) {
			long long yy = a[i] + a[i-1] - x;
			a[i] -= yy;
			ans += yy;
		}
	}
	cout << ans << '\n';
	return 0;
}

