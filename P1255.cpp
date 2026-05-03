#include <bits/stdc++.h>
using namespace std;

string add(string a, string b) {
	string res = "";
	int i = a.size() - 1, j = b.size() - 1, carry = 0;
	while (i >= 0 || j >= 0 || carry) {
		int sum = carry;
		if (i >= 0) sum += a[i] - '0', i--;
		if (j >= 0) sum += b[j] - '0', j--;
		res += char(sum % 10 + '0');
		carry = sum / 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	if (N == 1)
	{
		cout << 1 << "\n";
		return 0;
	}
	if (N == 2)
	{
		cout << 2 << "\n";
		return 0;
	}
	string a = "1", b = "2", c;
	for (int i = 3; i <= N; i++)
	{
		c = add(a, b); a = b; b = c;
	}

	cout << b << "\n";
	return 0;
}
