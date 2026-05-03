#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> s(N), b(N);
	for (int i = 0; i < N; i++) cin >> s[i] >> b[i];
	
	int result = INT_MAX;
	for (int mask = 1; mask < (1 << N); mask++) {
		int acid = 1;
		int bitter = 0;
		for (int i = 0; i < N; i++) {
			if (mask & (1 << i)) {
				acid *= s[i];
				bitter += b[i];
			}
		}
		result = min(result, abs(acid - bitter));
	}
	cout << result << "\n";
	return 0;
}
