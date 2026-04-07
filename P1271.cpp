#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(m, 0);
	for (int i = 0; i < m; cin >> v[i++]);
	sort(v.begin(), v.end());
	for (int i : v) {
		cout << i << " ";
	}
	return 0;
}
