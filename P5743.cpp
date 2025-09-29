#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int i = 1;
	cin >> n;
	for (; --n; i = (i + 1) * 2){}
	cout << i;
	return 0;
}
