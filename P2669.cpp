#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,d;
	cin >> d;
	n = (sqrt(1+(d<<3))-1)/2;
	cout << n*(d*1.0-(n+1)*(n+2)/6.0)+d;
	return 0;
}
