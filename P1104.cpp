#include <bits/stdc++.h>
using namespace std;

struct Point
{
	string name;
	int x, y, z, ID;
};

bool cmp(const Point& a, const Point& b)
{
	if (a.x != b.x) return a.x < b.x;
	if (a.y != b.y) return a.y < b.y;
	if (a.z != b.z) return a.z < b.z;
	return a.ID > b.ID;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<Point> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].name >> v[i].x >> v[i].y >> v[i].z;
		v[i].ID = i;
	}
	sort(v.begin(), v.end(), cmp);

	for (auto x: v)
		cout << x.name << endl;
	return 0;
}
