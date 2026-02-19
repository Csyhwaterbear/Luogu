#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
	vector<char> matches;
	char c;
	while (cin >> c)
	{
		if (c == 'E') break;
		if (c == 'W' || c == 'L')
			matches.push_back(c);
	}

	int a = 0, b = 0;
	for (char ch : matches)
	{
		if (ch == 'W') a++;
		else if (ch == 'L') b++;
		if ((a >= 11 || b >= 11) && abs(a - b) >= 2)
		{
			cout << a << ":" << b << endl;
			a = 0;
			b = 0;
		}
	}
	cout << a << ":" << b << endl;
	cout << endl;

	a = 0, b = 0;
	for (char ch : matches)
	{
		if (ch == 'W') a++;
		else if (ch == 'L') b++;
		if ((a >= 21 || b >= 21) && abs(a - b) >= 2)
		{
			cout << a << ":" << b << endl;
			a = 0;
			b = 0;
		}
	}
	cout << a << ":" << b << endl;

	return 0;
}
