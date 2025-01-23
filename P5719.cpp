# include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int suma=0, sumb=0, count=0;
	for(int i = 1; i <= a; i++)
	{
		i % b == 0 ? sumb += i: suma += i;
		count += i % b == 0; 
	}
	cout << fixed << setprecision(1) << sumb*1.0/count;
	cout << " ";
	cout << fixed << setprecision(1) << suma*1.0/(a-count);
	return 0;
}
