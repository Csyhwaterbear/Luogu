#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	int k;
	if (!(cin >> s)) return 0;
	cin >> k;
	int n = s.size();
	string st;
	for (char c : s) {
		while (!st.empty() && k > 0 && st.back() > c) {
			st.pop_back();
			--k;
		}
		st.push_back(c);
	}
	while (k > 0 && !st.empty()) {
		st.pop_back();
		--k;
	}
	int i = 0;
	while (i < (int)st.size() && st[i] == '0') ++i;
	string ans = (i == (int)st.size()) ? "0" : st.substr(i);
	cout << ans << '\n';
	return 0;
}

