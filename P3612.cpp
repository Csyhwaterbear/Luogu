#include <bits/stdc++.h>
using namespace std;
long long l, n, t;
char s[73];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	scanf("%s%lld", s + 1, &n);
	l = t = strlen(s + 1);
	while (t <  n) t <<= 1;
	while (t != l) t >>= 1, n = n > t ? ((t + 1 != n) ? n - t - 1 : t) : n;
	cout << s[n] << "\n";
	return 0;
}
