#include<bits/stdc++.h>
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
	int m, a, count;
	for (int i = 0; i < n; i++) {
		cin >> m >> a;
		vector<int> result(1,1);
		for (int j = 2; j <= m; j++)
		{
			multiply(result, j);

		}
		count = 0;
		for (auto const& c: result)
		{
			count += c == a;
		}
		cout << count << endl;
	}
	return 0;
}
