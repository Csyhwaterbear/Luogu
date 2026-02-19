#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a, b, c;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	string result = "";
	int carry = 0;
	int n = max(a.size(), b.size());

	for (int i = 0; i < n; i++)
	{
		int digitA = (i < a.size()) ? (a[i] - '0') : 0;
		int digitB = (i < b.size()) ? (b[i] - '0') : 0;
		int total = digitA + digitB + carry;
		result.push_back('0' + (total % 10));
		carry = total / 10;
	}
	
	if (carry)
		result.push_back('1');

	reverse(result.begin(), result.end());
	cout << result << endl;
	return 0;
}
