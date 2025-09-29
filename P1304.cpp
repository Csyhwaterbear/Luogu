#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin >> N;

	vector<bool> is_prime(N+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i < N; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j < N; j+=i) {
				is_prime[j] = false;
			}
		}
	}

	for (int m = 4; m <= N; m += 2) {
		for (int p = 2; p <= m / 2; p++) {
			if (is_prime[p] && is_prime[m-p]) {
				cout << m << "=" << p << "+" << m-p << endl;
				break;
			}
		}
	}
	return 0;
}
