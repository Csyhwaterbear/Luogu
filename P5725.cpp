# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;

	for( int i = 0; i < n; i++ )
	{
		for( int j = 0; j < n; j++ )
		{
			cout << ( i*n + j + 1 < 10 ? "0" : "" ) << i*n + j + 1;
		}
		cout << endl;
	}
	cout << endl;
	int count = 1;
	for( int i = 0; i < n; i++ )
	{
		for( int j = 0; j < n; j++ )
		{
			if (n - j > i + 1)
			{
				cout << "  ";
			}
			else
			{
				cout << (count < 10 ? "0" : "") << count++;
			}
		}
		cout << endl;
	}
}
