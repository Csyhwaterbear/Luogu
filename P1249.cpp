#include<bits/stdc++.h>
#include<ranges>
using namespace std;

void multiply(vector<int>& num, int x)
{
	int carry = 0;
	for (size_t i = 0; i < num.size(); i++)
	{
		int temp = num[i] * x + carry;
		num[i] = temp % 10;
		carry = temp / 10;
	}
	while (carry > 0)
	{
		num.push_back(carry % 10);
		carry /= 10;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums;
	vector<int> result(1, 1);
	
	int sum = 0;
	int i = 1;
	while (sum < n)
	{
		i++;
		sum += i;
		nums.push_back(i);
	}
	
	int rubbish = sum - n;
	if (rubbish == 1)
	{
		auto it1 = find(nums.begin(), nums.end(), 2);
		if (it1 != nums.end()) nums.erase(it1);
		auto it2 = find(nums.begin(), nums.end(), i);
		if (it2 != nums.end()) nums.erase(it2);
		nums.push_back(i + 1);
	}
	else
	{
		auto it = find(nums.begin(), nums.end(), rubbish);
		if (it != nums.end()) nums.erase(it);
	}
	
	sort(nums.begin(), nums.end());
	for (auto x : nums)
	{
		cout << x << " ";
		multiply(result, x);
	}
	cout << endl;
	
	for (auto r : std::views::reverse(result))
	{
		cout << r;
	}
	cout << endl;
	return 0;
}

