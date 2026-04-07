#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int l = 0, r = n - 1;
	mt19937 rng(random_device{}());
	
	while (l <= r)
	{
		int pivot = a[uniform_int_distribution<int>(l, r)(rng)];
		int i = l, j = r;
		
		while (i <= j)
		{
			while (a[i] < pivot) i++;
			while (a[j] > pivot) j--;
			if (i <= j)
			{
				swap(a[i], a[j]);
				i++;
				j--;
			}
		}
		
		if (k <= j)
		{
			r = j;
		}
		else if (k >= i)
		{
			l = i;
		}
		else
		{
			cout << a[k];
			return 0;
		}
	}
	return 0;
}
