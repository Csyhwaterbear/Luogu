# include <bits/stdc++.h>
using namespace std;
int main()
{
	int l, m, u, v, sum = 0;
	cin >> l >> m;
	bool* nV_arr = (bool*)malloc((l+1)*sizeof(bool));
	for( int i = 0; i <= l; nV_arr[i++] = false );
	for( int i = 0; i < m; i++ )
	{
		for( cin >> u >> v; u <= v; nV_arr[u++] = true );
	}
	for( int i = 0; i <= l; sum += nV_arr[i++] );
	cout << l + 1 - sum;
	return 0;
}
