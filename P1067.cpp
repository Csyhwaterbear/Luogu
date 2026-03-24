#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	n++;
	
	int* array = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		 cin >> array[i];
	}
	bool first = true;
	for (int i = 0; i < n; i++)
	{
		int coef = array[i];
		int exp = n - i - 1;
		if (coef == 0) continue;
		if (!first)
		{
			if (coef > 0) cout << "+";
		}
		if (exp == 0)
		{
			cout << coef;
		}
		else
		{
			if (coef == -1)
			{
				cout << "-";
			}
			else if (coef != 1)
			{
				cout << coef;
			}
			cout << "x";
			if (exp > 1)
			{
				cout << "^" << exp;
			}
		}
		first = false;
	}

	if (first)
	{
		cout << 0;
	}
	free(array);
	return 0;
}

