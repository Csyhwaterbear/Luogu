# include <iostream>
using namespace std;
int main()
{
	int n, x, count = 0, base = 1;
	cin >> n >> x;
	for(; n / base > 0;)
	{
		int h = n / (base*10);
		int c = n / base % 10;
		int l = n % base;
		if( x )
		{
			if( c > x ) count += ( h+1 ) * base;
			if( c == x) count += h * base + l + 1;
			if( c < x ) count += h * base;
		}
		else
		{
			if( c ) count += h * base;
			else count += ( h-1 ) * base + l + 1;
		}
		base *= 10;
	}
	cout << count;
}
