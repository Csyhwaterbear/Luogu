#include<bits/stdc++.h>
using namespace std;
int main()
{
	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;
	string str;
	cin >> str;
	string ans = "";
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] != '-') {
			ans += str[i];
			continue;
		}
		if (i == 0 || i == str.length() - 1) {
			ans += '-';
			continue;
		}
		char left = str[i - 1];
		char right = str[i + 1];
		bool both_digit = isdigit(left) && isdigit(right);
		bool both_lower = islower(left) && islower(right);
		if (!(both_digit || both_lower) || right <= left) {
			ans += '-';
			continue;
		}
		if (right == left + 1) {
			continue;
		}
		if (p3 == 1) {
			for (char ch = left + 1; ch < right; ch++)  {
				for (int j = 0; j < p2; j++) {
					if (p1 == 3)  {
						ans += '*';
					}
					else if (isdigit(ch)) {
						ans += ch;
					}
					else {
						if (p1 == 1) ans += ch;
						else if (p1 == 2) ans += (ch - 32);
					}
				}
			}
		}
		else {
			for (char ch = right - 1; ch > left; ch--) {
				for (int j = 0; j < p2; j++) {
					if (p1 == 3) {
						ans += '*';
					}
					else if (isdigit(ch)) {
						ans += ch;
					}
					else {
						if (p1 == 1) ans += ch;
						else if (p1 == 2) ans += (ch - 32);
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
