#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, cnt = 0;
	cin >> n;    
	vector<array<int, 3>> scores(n);
	for (int i = 0; i < n; i++)
	{
        	cin >> scores[i][0] >> scores[i][1] >> scores[i][2];
	}
    
	for (int i = 0; i < n; i++)
	{
        	for (int j = i + 1; j < n; j++)
		{
			if(
				abs(scores[i][0] - scores[j][0]) <= 5 &&
				abs(scores[i][1] - scores[j][1]) <= 5 &&
				abs(scores[i][2] - scores[j][2]) <= 5
				)
			{
				int total1 = scores[i][0] + scores[i][1] + scores[i][2];
				int total2 = scores[j][0] + scores[j][1] + scores[j][2];
				cnt += abs(total1 - total2) <= 10;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
