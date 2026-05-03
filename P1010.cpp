#include <bits/stdc++.h>
using namespace std;

string format_pow(int n);

string format_pow(int n)
{
	if (n == 0) return "0";
	vector<int> pos;
	int p = 0;
	int t = n;
	while (t > 0)
	{
		if (t & 1) pos.push_back(p);
		++p;
		t >>= 1;
	}
	reverse(pos.begin(), pos.end());
	string res;
	for(size_t i = 0; i < pos.size(); i++)
	{
		int e = pos[i];
		if (e == 0)
			res += "2(0)";
		else if (e == 1)
			res += "2";
		else
			res += "2(" + format_pow(e) + ")";
		if (i + 1 < pos.size())
			res += "+";
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;	
	if (!(cin >> n)) return 0;
	cout << format_pow(n) << "\n";
	return 0;
}

