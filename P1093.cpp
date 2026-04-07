#include <bits/stdc++.h>
using namespace std;

struct student{
	int ID, A, B, C, sum;
};

bool cmp(const student& x, const student& y)
{
	if (x.sum != y.sum) return x.sum > y.sum;
	if (x.A != y.A) return x.A > y.A;
	return x.ID < y.ID;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<student> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i].ID = i + 1;
		cin >> v[i].A >> v[i].B >> v[i].C;
		v[i].sum = v[i].A + v[i].B + v[i].C;
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < 5; i++)
		cout << v[i].ID << " " << v[i].sum << "\n";
	return 0;
}
