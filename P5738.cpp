#include <bits/stdc++.h>
int main()
{
	int n, m;
	std::cin >> n >> m;
	int matrix[n][m];
	int min = 10, max = 0;
	int H = 0, Temp;
	for(int i = 0; i < n; i++)
	{
		min = std::numeric_limits<int>::max();
		max = std::numeric_limits<int>::min();

		for(int j = 0; j < m; j++)
		{
			std::cin >> matrix[i][j];
			min = std::min(min, matrix[i][j]);
			max = std::max(max, matrix[i][j]);
		}
		Temp = - min - max;
		for(int j = 0; j < m; j++)
		{
			Temp += matrix[i][j];
		}
		H = std::max(H,Temp);
	}
	std::cout << std::fixed << std::setprecision(2) << H*1.00 / (m-2) << std::endl;
	return 0;
}
