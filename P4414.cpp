# include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> a(3);
	string b;
	cin >> a[0] >> a[1] >> a[2];
	sort(a.begin(),a.end());
	cin >> b;
	
	map<char, int> letter_to_value;
	letter_to_value['A'] = a[0];
	letter_to_value['B'] = a[1];
	letter_to_value['C'] = a[2];
	
	for(char c: b){cout << letter_to_value[c] << " ";}
	return 0;
}

