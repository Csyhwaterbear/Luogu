# include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, i=1;
	cin >> a;
	for(;a>1;i++){a = floor(a/2.0);}
	cout << i;
	return 0;
}
