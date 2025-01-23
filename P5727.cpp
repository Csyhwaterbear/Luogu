# include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> nV_arr;
	int n;
	cin >> n;
	while(n != 1){ nV_arr.push_back(n);n = n %2 == 0? n / 2 : 3*n + 1; }
	cout << 1 << " ";
	for (int i = nV_arr.size() - 1; i >= 0 ; cout << nV_arr[i--] << " ");
	return 0;
}

