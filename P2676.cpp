#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, B;
	cin >> n >> B;
	vector<int> v(n);
	for (int i = 0; i < n; cin >> v[i++]);
	sort(v.begin(), v.end(), greater<int>());

	int count = 0;
	for (int x :v)
	{
		B -= x;
		count++;
		if (B <= 0)
			break;
	}
	cout << count;
	return 0;
}
