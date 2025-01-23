# include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a[3][2], min = 100000000, price, total;
	cin >> n;
	for( int i = 0; i < 3; i++ )
	{
		cin >> a[i][0] >> a[i][1];
		total = ceil( n / static_cast<float>(a[i][0]) ) * a[i][1]; 
		if(total < min){min=total;price=total;}
	}
	cout << price;
	return 0;

}
