# include <iostream>
using namespace std;
int main()
{
	int n, m = 1;
	cin >> n;
	for(int i = n; i > 0; i--)
	{
		for(int ii = i; ii > 0; ii--)
		{
			cout << (m < 10?"0":"") << m++;
		}
		cout << endl;
	}
	return 0;
}
