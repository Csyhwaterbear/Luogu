#include <bits/stdc++.h>
int func(int n)
{
	return n > 1 ? n * func(n-1) : 1;
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << func(n);
	return 0;
}
