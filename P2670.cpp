#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	// 方向数组：8个方向
	const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '*') {
				cout << '*';
			} else {
				int count = 0;
				for (int k = 0; k < 8; k++) {
					int ni = i + dx[k];
					int nj = j + dy[k];
					if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
						if (grid[ni][nj] == '*') {
							count++;
						}
					}
				}
				cout << count;
			}
		}
		cout << '\n';
	}

	return 0;
}
