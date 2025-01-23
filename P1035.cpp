# include <bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	const float gamma = 0.5772156649;
	cin >> k;
	cout << floor(exp(k-gamma)+0.5);
	return 0;
}
