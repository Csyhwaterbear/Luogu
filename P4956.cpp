# include <bits/stdc++.h>
using namespace std;
int main()
{
	int x, k, n;
	cin >> n;
	n /= 364;
	if(n<=103)
	{
		cout << n-3 << endl << 1;
	}
	else{
		if(n%3==0) printf("%d\n%d\n",99,(n-99)/3);
		if(n%3==1) printf("%d\n%d\n",100,(n-100)/3);
		if(n%3==2) printf("%d\n%d\n",98,(n-98)/3);
	}
	return 0;
}
