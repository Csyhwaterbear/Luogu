#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	// Allocate matrix (0-indexed internally)
	int** matrix = (int**)malloc(n * sizeof(int*));
	matrix[0] = (int*)malloc(n * n * sizeof(int));
	for(int i = 1; i < n; i++)
		matrix[i] = matrix[0] + i * n;
	
	// Initialize with 1 to n² (0-indexed access)
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			matrix[i][j] = i * n + j + 1;  // Fixed formula
	
	while(m--) {
		int x, y, r, z;
		cin >> x >> y >> r >> z;
		
		// Convert to 0-indexed
		x--; y--;
		
		int size = 2 * r + 1;
		int** temp = (int**)malloc(size * sizeof(int*));
		temp[0] = (int*)malloc(size * size * sizeof(int));
		for(int i = 1; i < size; i++)
			temp[i] = temp[0] + i * size;
		
		// Copy submatrix
		for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++)
				temp[i][j] = matrix[x - r + i][y - r + j];
		
		// Rotate
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				int dx = i - r, dy = j - r;
				int new_i, new_j;
				
				if(z == 0) {  // Clockwise
					new_i = r + dy;
					new_j = r - dx;
				} else {  // Counter-clockwise
					new_i = r - dy;
					new_j = r + dx;
				}
				matrix[x - r + new_i][y - r + new_j] = temp[i][j];
			}
		}
		
		// ⭐ Free temp memory (was missing!)
		free(temp[0]);
		free(temp);
	}
	
	// Output (fixed: use n, not m; correct bounds)
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << matrix[i][j] << (j == n - 1 ? "" : " ");
		cout << "\n";
	}
	
	// Free matrix
	free(matrix[0]);
	free(matrix);
	
	return 0;
}
