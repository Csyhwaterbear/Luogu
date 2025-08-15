#include <bits/stdc++.h>
int main()
{
	int N;
	std::cin >> N;
	std::string Name, Temp;
	int I, II, III, IV, V, VI;
	int Max = -1;
	for(int i = 0; i < N; i++)
	{
		std::cin >> Temp >> IV >> V >> VI;
		if (Max < IV + V + VI)
		{
			Name = Temp;
			I = IV;
			II = V;
			III = VI;
			Max = I + II + III;
		}
	}
	std::cout << Name << " " << I << " " << II << " " << III;
	return 0;
}
