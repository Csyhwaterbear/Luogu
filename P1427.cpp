# include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> nV_arr;
	int n;
	do{cin >> n; nV_arr.push_back(n);}while(n != 0);
	for (int i = nV_arr.size() - 2; i >= 0 ; cout << nV_arr[i--] << " ");
	return 0;
}
