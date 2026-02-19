#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

struct Complex {
	double x, y;
	Complex(double x = 0, double y = 0) : x(x), y(y) {}
	Complex operator+(const Complex & o) const {return Complex(x + o.x, y + o.y);}
	Complex operator-(const Complex & o) const {return Complex(x - o.x, y - o.y);}
	Complex operator*(const Complex & o) const {return Complex(x * o.x - y * o.y, x * o.y + y * o.x);}
};

void fft(vector<Complex> & a, bool invert)
{
	int n = a.size();
	for (int i = 1, j = 0; i < n; i++)
	{
		int bit = n >> 1;
		for (; j & bit; bit >>=1) j ^= bit;
		j ^= bit;
		if (i < j) swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<=1)
	{
		double ang = 2 * PI / len * (invert ? -1 : 1);
		Complex wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len)
		{
			Complex w(1);
			for (int j = 0; j < len / 2; j++)
			{
				Complex u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w = w * wlen;
			}
		}
	}
	if (invert)
		for (auto&x : a)
			x.x /= n;
}

string multiply(string a, string b)
{
	if (a == "0" || b == "0") return "0";

	while (a.size() > 1 && a[0] == '0') a.erase(a.begin());
	while (b.size() > 1 && b[0] == '0') b.erase(b.begin());

	vector<Complex> fa(a.size()), fb(b.size());
	for (int i = 0; i < a.size(); i++) fa[i] = Complex(a[a.size() - 1 - i] - '0', 0);
	for (int i = 0; i < b.size(); i++) fb[i] = Complex(b[b.size() - 1 - i] - '0', 0);

	int n = 1;
	while (n < (int)(fa.size() + fb.size())) n <<= 1;
	fa.resize(n); fb.resize(n);

	fft(fa, false);
	fft(fb, false);
	for (int i = 0; i < n; i++) fa[i] = fa[i] * fb[i];
	fft(fa, true);

	vector<int> res(n);
	for (int i = 0; i < n; i++)
		res[i] = round(fa[i].x);

	int carry = 0;
	for (int i = 0; i < n; i++)
	{
		res[i] += carry;
		carry = res[i] / 10;
		res[i] %= 10;
	}

	while (carry)
	{
		res.push_back(carry % 10);
		carry /= 10;
	}

	while (res.size() > 1 && res.back() == 0) res.pop_back();

	string ans;
	for (int i = res.size() - 1; i >= 0; i--)
		ans += char(res[i] + '0');

	return ans;
}

int main()
{
	string a, b, c;
	cin >> a >> b;
	cout << multiply(a, b) << endl;
	return 0;
}
