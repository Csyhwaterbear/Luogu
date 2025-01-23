# include <bits/stdc++.h>
using namespace std;
int main()
{
	int N, s = 0;
	cin >> N;
	while(N) s = s*10 + N%10, N /= 10;
	cout << s;
	return 0;
}
