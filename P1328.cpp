#include<bits/stdc++.h>
using namespace std;
int main()
{
	const int matrix_int[5][5] = {
		{0,-1,1,1,-1},
		{1,0,-1,1,-1},
		{-1,1,0,-1,1},
		{-1,-1,1,0,1},
		{1,1,-1,-1,0}
	};
	int N, N_A, N_B, A_c, B_c;
	cin >> N >> N_A >> N_B;
	A_c = 0;
	B_c = 0;

	int* A = (int*)malloc(N_A * sizeof(int));
	int* B = (int*)malloc(N_B * sizeof(int));

	for (int i = 0; i < N_A; cin >> A[i++]);
	for (int i = 0; i < N_B; cin >> B[i++]);

	for (int i = 0; i < N; i++)
	{
		int result = matrix_int[A[i%N_A]][B[i%N_B]];
		if (result == 1)
		{
			A_c++;
		}
		else if (result ==-1)
		{
			B_c++;
		}
	}
	cout << A_c << " " << B_c;
	free(A);
	free(B);
	return 0;
}
