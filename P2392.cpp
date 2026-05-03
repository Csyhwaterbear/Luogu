#include <bits/stdc++.h>
using namespace std;

int solve(int s)
{
	vector<int> nums(s);
	int sum = 0;
	for (int i = 0; i < s; i++)
	{
		cin >> nums[i];
		sum += nums[i];
	}
	int target = sum / 2;
	vector<int> dp(target + 1, 0);

	for (int x: nums)
	{
		for (int j = target; j >= x; j--)
		{
			dp[j] = max(dp[j], dp[j - x] + x);
		}
	}
	int best = dp[target];
	return max(best, sum - best);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	cout << solve(A) + solve(B) + solve(C) + solve(D) << "\n";
	return 0;
}

