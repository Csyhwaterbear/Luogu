#include <iostream>
#include <vector>

using namespace std;

void pardon(vector<vector<int>>& matrix, int x, int y, int size) {
	if (size == 1)
		return;

	int half = size / 2;
	for (int i = x; i < x + half; i++)
		for (int j = y; j < y + half; j++)
		    matrix[i][j] = 0;

	pardon(matrix, x + half, y, half);
	pardon(matrix, x, y + half, half);
	pardon(matrix, x + half, y + half, half);
}

int main()
{
	int n;
	cin >> n;
	int size = 1 << n;
	vector<vector<int>> matrix(size, vector<int>(size, 1));

	pardon(matrix, 0, 0, size);
    
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrix[i][j];
			if (j < size - 1)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
