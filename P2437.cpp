#include <bits/stdc++.h>
using namespace std;

string add(string a, string b)
{
	string res = "";
	int i = a.size() - 1;
	int j = b.size() - 1;
	int carry = 0;

	while (i >= 0 || j >= 0 || carry)
	{
		int sum = carry;
		if (i >= 0) sum += a[i--] - '0';
		if (j >= 0) sum += b[j--] - '0';

		res += char(sum % 10 + '0');
		carry = sum / 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> m >> n;
	int d = n - m;
	vector<string> fib(d + 2);
	fib[0] = "1";
	fib[1] = "1";
	for (int i = 2; i <= d; i++)
		fib[i] = add(fib[i - 1], fib[i - 2]);
	cout << fib[d] << "\n";
	return 0;
}

