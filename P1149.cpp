#include <bits/stdc++.h>
using namespace std;

int cost[] = {6,2,5,5,4,5,6,3,7,6};

int match(int x)
{
	if (x == 0) return cost[0];
	int sum = 0;
	while(x > 0)
	{
		sum += cost[x%10];
		x /= 10;
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, ans;
	cin >> N;
	N -= 4;
	ans = 0;
	for (int a = 0; a <= 1111; a++)
	{
		for (int b = 0; b <= 1111; b++)
		{
			int c = a + b;
			if (match(a) + match(b) + match(c) == N) ans++;
		}
	}	
	cout << ans << "\n";
	return 0;
}
