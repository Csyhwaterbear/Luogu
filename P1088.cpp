#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	while (m--)
	{
		next_permutation(nums.begin(), nums.end());
	}

	for (int x: nums)
		cout << x << " ";
	return 0;
}

