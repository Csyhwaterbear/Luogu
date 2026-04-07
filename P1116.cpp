#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	int count = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; cin >> v[i++]);
	while (n--)
	{
		auto maxIt = max_element(v.begin(), v.end());
		int maxIndex = static_cast<int>(distance(v.begin(), maxIt));
		count += n - maxIndex;
		v.erase(v.begin() + maxIndex);
	}
	cout << count << endl;
	return 0;
}
