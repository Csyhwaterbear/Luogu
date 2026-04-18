#include <bits/stdc++.h>
using namespace std;

bool check (int x, int y, int z)
{
	bool used[10] = {false};
	int arr[3] = {x, y, z};
	for (int i = 0; i < 3; i++)
	{
		int num = arr[i];
		for (int j = 0; j < 3; j++)
		{
			int d = num % 10;
			if (d == 0 || used[d]) return false;
			used[d] = true;
			num /= 10;
		}
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int A, B, C;
	cin >> A >> B >> C;
	if (A == 0 || B == 0 || C == 0)
	{
		cout << "No!!!\n";
		return 0;
	}

	int g = gcd(A, gcd(B, C));
	A /= g;
	B /= g;
	C /= g;

	int L = (100 + A - 1) / A;
	int R = 999 / C;

	bool found = false;
	for (int k = L; k <= R; k++)
	{
		int x = A * k;
		int y = B * k;
		int z = C * k;

		if (check(x, y, z))
		{
			cout << x << " " << y << " " << z << "\n";
			found = true;
		}
	}

	if (!found) cout << "No!!!\n";
	return 0;
}
