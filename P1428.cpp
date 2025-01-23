# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, temp;
	cin >> n;
	int* nV_arr = (int*)malloc( n * sizeof(int) );
	int* nV_res = (int*)malloc( n * sizeof(int) );
	for( int i = 0; i < n; i++ )
	{
		cin >> nV_arr[i];
		temp = 0;
		for( int ii = 0; ii < i; ii++ )
		{
			temp += nV_arr[i] > nV_arr[ii];
		}
		nV_res[i] = temp;
	}
	for( int i = 0; i < n; cout << nV_res[i++] << " " );
	return 0;
}
