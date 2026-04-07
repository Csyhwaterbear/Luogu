#include <bits/stdc++.h>
using namespace std;

struct person
{
	int ID;
	string vote;
};

bool cmp(const person& x, const person& y)
{
	if (x.vote.length() != y.vote.length()) return x.vote.length() > y.vote.length();
	for (size_t i = 0; i < x.vote.length(); i++)
	{
		if (x.vote[i] != y.vote[i]) return x.vote[i] > y.vote[i];
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<person> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i].ID = i + 1;
		cin >> v[i].vote;
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[0].ID << endl << v[0].vote;
	return 0;
}
