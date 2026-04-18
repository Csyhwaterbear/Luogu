#include <bits/stdc++.h>
using namespace std;

struct person{
	int score, ID;
};

bool cmp(person& a, person& b)
{
	if (a.score != b.score) return a.score > b.score;
	return a.ID < b.ID;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	int k = m * 3 / 2;
	vector<person> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].ID >> v[i].score;
	}
	sort(v.begin(), v.end(), cmp);

	int line = v[k-1].score;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (v[i].score >= line)
			cnt++;
	cout << line << " " << cnt << endl;
	for (int i = 0; i < cnt; i++)
	       cout << v[i].ID << " " << v[i].score << endl;	

	return 0;
}
