#include <bits/stdc++.h>

std::string func(int I, int J)
{
	return (I * 0.7 + J * 0.3 >= 80.0 && I + J > 140 ? "Excellent" : "Not excellent"); 
}

int main()
{
	int n;
	std::cin >> n;

	int **matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[3];
	}

	for (int i = 0; i < n; i++)
	{
		std::cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2];
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << func(matrix[i][1], matrix[i][2]) << std::endl;
	}
	
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	
	return 0;
}
