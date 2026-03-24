#include<bits/stdc++.h>
using namespace std;

int matrix[12][12];
int dir_F = 0, dir_C = 0;
int F_X, F_Y, C_X, C_Y;
bool vis[160005];

void move_person(int &x, int &y, int &dir)
{
	if (dir == 0) // 北
	{
		if (matrix[x - 1][y] == 0) dir = 1;
		else x--;
	}
	else if (dir == 1) // 东
	{
		if (matrix[x][y + 1] == 0) dir = 2;
		else y++;
	}
	else if (dir == 2) // 南
	{
		if (matrix[x + 1][y] == 0) dir = 3;
		else x++;
	}
	else // 西
	{
		if (matrix[x][y - 1] == 0) dir = 0;
		else y--;
	}
}

int main()
{
	// 先全部设为障碍
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			matrix[i][j] = 0;
		}
	}

	string s;
	for (int i = 1; i <= 10; i++)
	{
		cin >> s;
		for (int j = 1; j <= 10; j++)
		{
			switch (s[j - 1])
			{
				case '*':
					matrix[i][j] = 0;
					break;
				case '.':
					matrix[i][j] = 1;
					break;
				case 'F':
					matrix[i][j] = 1;
					F_X = i;
					F_Y = j;
					break;
				case 'C':
					matrix[i][j] = 1;
					C_X = i;
					C_Y = j;
					break;
			}
		}
	}

	int ans = 0;

	while (true)
	{
		if (F_X == C_X && F_Y == C_Y)
		{
			cout << ans << endl;
			return 0;
		}
		int state = F_X + F_Y * 10 + C_X * 100 + C_Y * 1000 + dir_F * 10000 + dir_C * 40000;
		if (vis[state])
		{
			cout << 0 << endl;
			return 0;
		}
		vis[state] = true;
		move_person(F_X, F_Y, dir_F);
		move_person(C_X, C_Y, dir_C);
		ans++;
	}
	return 0;
}

