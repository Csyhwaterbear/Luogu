#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> base = {" /\\ ", "/__\\"};
vector<string> solve(int h)
{
	if (h == 2) return base;
	vector<string> cur = base;
	int curH = 2;
	while (curH < h)
	{
		int nextH = curH * 2, width = nextH * 2;
	 	vector<string> next(nextH, string(width, ' '));

		int offset = curH;
		for (int i = 0; i < curH; i++)
			for (int j = 0; j < (int)cur[i].size();j++)
				next[i][offset + j] = cur[i][j];

		for (int i = 0; i < curH; i++)
			for (int j = 0; j < (int)cur[i].size();j++)
				next[curH + i][j] = next[curH + i][j + curH * 2] = cur[i][j];

		cur = move(next);
		curH = nextH;
	}
	return cur;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	if(!(cin >> n)) return 0;
	vector<string> ans = solve(1<<n);
	for (string s: ans) cout << s << endl;
	return 0;
}
