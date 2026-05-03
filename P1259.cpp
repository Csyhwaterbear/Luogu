#include <bits/stdc++.h>
using namespace std;

int n;
vector<char> ch;
void swap2(char &a, char &b) {
	char t = a; a = b; b = t;
}

void output_state() {
	for (char c : ch) cout << c;
	cout << '\n';
}

void movechess(int start, int end) {
	swap2(ch[start], ch[end]);
	swap2(ch[start + 1], ch[end + 1]);
	output_state();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	if (!(cin >> n)) return 0;
	ch.assign(2 * n + 2, '-');
	for (int i = 0; i < n; ++i) ch[i] = 'o';
	for (int i = n; i < 2 * n; ++i) ch[i] = '*';
	ch[2 * n] = ch[2 * n + 1] = '-';
	
	output_state();
	
	int len = n;
	while (true) {
		movechess(len - 1, 2 * len);
		--len;
		if (len == 3) break;
		movechess(len, 2 * len);
	}
	vector<string> tbl = {
		"ooo*o**--*",
		"o--*o**oo*",
		"o*o*o*--o*",
		"--o*o*o*o*"
	};
	
	string tail;
	for (int i = 0; i < n - 4; ++i) tail += "o*";
	for (int i = 0; i < 4; ++i) {
		cout << tbl[i] << tail << '\n';
	}
	
	return 0;
}

