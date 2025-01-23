# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, count = 1, max = 0;
	cin >> n;
	int* nVa = (int*)malloc(n * sizeof(int));
	int* nVb = (int*)malloc((n-1) * sizeof(int));
	for( int i = 0; i < n;  cin >> nVa[i++] );
	for( int i = 0; i < n - 1; nVb[i++] = nVa[i+1] - nVa[i] );	
	for( int i = 0; i < n - 1; i++ )
	{
		count = nVb[i] == 1 ? count + 1 : 1;
		max = count > max ? count : max;
	} 
	cout << max;
	return 0;
}
