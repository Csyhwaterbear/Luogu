# include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i*i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

bool is_palindromic(int num)
{
	int rev=0,val;
	val = num;
	while(num > 0)
	{
		rev = rev * 10 + num % 10;
		num = num / 10;
	}
	return val==rev;	
}

int main()
{
	int a, b;
	cin >> a >> b;
	for( int i = a; i <= b; i++ )
	{
		//cout << i << is_palindromic(i) << isPrime(i)  << endl;
		if( is_palindromic(i) )
		{
			if( isPrime(i) )
			{
				cout << i << endl;
			}
		}
	}
	return 0;

}
