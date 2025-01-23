#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	cin >> n >> m;

	if ( m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12 )
	{
		cout << 31;
	}
	else if ( m == 2 )
	{
		cout << ( ( n%4==0 && n%100!=0 ) || ( n%400==0 ) ? 29 : 28 ) ;
	}
	else
	{
		cout << 30;
 	}	

	return 0;
}

