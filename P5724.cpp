# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, max = 0, min = 1000;
	for( cin >> n; n > 0; n-- )
	{
		cin >> m;
		max = (max < m? m : max);
		min = (min > m? m : min);
	}
	cout << max - min;
	return 0;
}
