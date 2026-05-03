#include <bits/stdc++.h>
using namespace std;

string s;
int pos = 0;

string solve() {
	string ans = "";
	
	while (pos < s.size() && s[pos] != ']') {
		if (isupper(s[pos])) {
			ans += s[pos];
			pos++;
		} else if (s[pos] == '[') {
			pos++;
			
			int num = 0;
			while (pos < s.size() && isdigit(s[pos])) {
				num = num * 10 + (s[pos] - '0');
				pos++;
			}
			
			string sub = solve();
			pos++;
			while (num--) ans += sub;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> s;
	cout << solve() << "\n";
	return 0;
}

