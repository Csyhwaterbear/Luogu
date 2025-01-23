# include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, max=0, day=0;
	for( int i = 0; i < 7; i++)
	{
		cin >> a >> b;
		if(a+b > 8 && a+b > max)
        	{
			max = a + b;
			day = i + 1;
		}
	}
	cout << day;
	return 0;
}