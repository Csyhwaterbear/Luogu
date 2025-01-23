# include <bits/stdc++.h>
using namespace std;
int main(){
	int num;
	cin >> num;
	bool cond1 = num%2==0;
	bool cond2 = 4 < num && num <= 12;
	cout << (cond1 && cond2) <<  " " << (cond1 || cond2)  << " " << (!cond1 != !cond2) << " " << (!cond1 && !cond2);
	return 0;
}
