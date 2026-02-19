#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;
const ll G = 3;

ll power(ll base, ll exp, ll mod) {
	ll res = 1;
	while (exp) {
		if (exp & 1) res = res * base % mod;
		base = base * base % mod;
		exp >>= 1;
	}
	return res;
}

void ntt(vector<ll>& a, bool invert) {
	int n = a.size();
	for (int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		for (; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if (i < j) swap(a[i], a[j]);
	}

	for (int len = 2; len <= n; len <<= 1) {
		ll wlen = power(G, (MOD - 1) / len, MOD);
		if (invert) wlen = power(wlen, MOD - 2, MOD);
		for (int i = 0; i < n; i += len) {
			ll w = 1;
			for (int j = 0; j < len / 2; j++) {
				ll u = a[i + j];
				ll v = a[i + j + len / 2] * w % MOD;
				a[i + j] = (u + v) % MOD;
				a[i + j + len / 2] = (u - v + MOD) % MOD;
				w = w * wlen % MOD;
			}
		}
	}

	if (invert) {
		ll inv_n = power(n, MOD - 2, MOD);
		for (ll& x : a) x = x * inv_n % MOD;
	}
}

string multiply_ntt(string a, string b) {
	if (a == "0" || b == "0") return "0";

	vector<ll> fa, fb;
	for (int i = a.size() - 1; i >= 0; i--) fa.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i--) fb.push_back(b[i] - '0');

	int n = 1;
	while (n < (int)(fa.size() + fb.size())) n <<= 1;
	fa.resize(n, 0);
	fb.resize(n, 0);

	ntt(fa, false);
	ntt(fb, false);
	for (int i = 0; i < n; i++) fa[i] = fa[i] * fb[i] % MOD;
	ntt(fa, true);

	vector<int> res(n);
	for (int i = 0; i < n; i++) res[i] = fa[i];

	int carry = 0;
	for (int i = 0; i < n; i++) {
		res[i] += carry;
		carry = res[i] / 10;
		res[i] %= 10;
	}
	while (carry) {
		res.push_back(carry % 10);
		carry /= 10;
	}

	while (res.size() > 1 && res.back() == 0) res.pop_back();

	string ans;
	for (int i = res.size() - 1; i >= 0; i--) {
		ans += char(res[i] + '0');
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string a, b;
	cin >> a >> b;
	cout << multiply_ntt(a, b) << '\n';
	return 0;
}
