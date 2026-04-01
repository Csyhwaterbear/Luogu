#include <bits/stdc++.h>
using namespace std;

const int LEN = 500;

struct BigInt {
	int d[LEN];
	BigInt() {
		memset(d, 0, sizeof(d));
	}
};

BigInt multiply(const BigInt& a, const BigInt& b) {
	BigInt res;
	long long temp[LEN * 2];
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < LEN; i++) {
		if (a.d[i] == 0) continue;
		for (int j = 0; j + i < LEN; j++) {
			if (b.d[j] == 0) continue;
			temp[i + j] += 1LL * a.d[i] * b.d[j];
		}
	}
	for (int i = 0; i < LEN - 1; i++) {
		temp[i + 1] += temp[i] / 10;
		res.d[i] = temp[i] % 10;
	}
	res.d[LEN - 1] = temp[LEN - 1] % 10;
	return res;
}

int main() {
	int p;
	cin >> p;
	
	int digits = (int)(p * log10(2)) + 1;
	cout << digits << endl;
	
	BigInt ans, base;
	ans.d[0] = 1;
	base.d[0] = 2;

	while (p > 0) {
		if (p & 1) ans = multiply(ans, base);
		base = multiply(base, base);
		p >>= 1;
	}
	ans.d[0]--;
	for (int i = 0; i < LEN - 1; i++) {
		if (ans.d[i] < 0) {
			ans.d[i] += 10;
			ans.d[i + 1]--;
		}
	}
	
	for (int i = LEN - 1; i >= 0; i--) {
		cout << ans.d[i];
		if (i % 50 == 0) cout << endl;
	}
	return 0;
}

