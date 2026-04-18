#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int x, y, z;
};

bool cmp(const Point& a, const Point& b)
{
	return a.z < b.z;
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
		cin >> v[i].x >> v[i].y >> v[i].z;
	}
	sort(v.begin(), v.end(), cmp);
	double ans = 0;
	for (int i = 1; i < n; i++)
	{
		double dx = v[i].x - v[i - 1].x;
		double dy = v[i].y - v[i - 1].y;
		double dz = v[i].z - v[i - 1].z;
		ans += sqrt(dx * dx + dy * dy + dz * dz);
	}
	cout << fixed << setprecision(3) << ans;
	return 0;
}
