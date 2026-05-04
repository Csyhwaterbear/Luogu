#include<bits/stdc++.h>
using namespace std;
int x, y, len, k;

void solve(int x, int y, int a, int b, int l)
{
	if(l == 1) return;
	if(x - a <= l / 2 - 1 && y - b <= l / 2 - 1)
	{
		cout << a+l/2 << " " << b+l/2 << " 1" << endl;
		solve(x,y,a,b,l/2);
		solve(a+l/2-1,b+l/2,a,b+l/2,l/2);
		solve(a+l/2,b+l/2-1,a+l/2,b,l/2);
		solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
	}
	else if(x - a <= l / 2 - 1 && y - b > l / 2 - 1)
	{
		cout << a+l/2 << " " << b+l/2-1 << " 2" << endl;
		solve(a+l/2-1,b+l/2-1,a,b,l/2);
		solve(x,y,a,b+l/2,l/2);
		solve(a+l/2,b+l/2-1,a+l/2,b,l/2);
		solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
	}
	else if(x - a > l / 2 - 1 && y - b <= l / 2 - 1)
	{
		cout << a+l/2-1 << " " << b+l/2 << " 3" << endl;
		solve(a+l/2-1,b+l/2-1,a,b,l/2);
		solve(a+l/2-1,b+l/2,a,b+l/2,l/2);
		solve(x,y,a+l/2,b,l/2);
		solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
	}
	else
	{
		cout << a+l/2-1 << " " << b+l/2-1 << " 4" << endl;
		solve(a+l/2-1,b+l/2-1,a,b,l/2);
		solve(a+l/2-1,b+l/2,a,b+l/2,l/2);
		solve(a+l/2,b+l/2-1,a+l/2,b,l/2);
		solve(x,y,a+l/2,b+l/2,l/2);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	if(!(cin >> k >> x >> y)) return 0;
	len = (1 << k);
	solve(x,y,1,1,len);
	return 0;
}
