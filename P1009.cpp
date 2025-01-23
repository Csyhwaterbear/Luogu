#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BigInt {
private:
	vector<int> digits;public:

	BigInt(int num = 0)
	{
        	while (num > 0)
		{
			digits.push_back(num % 10);
			num /= 10;
        	}
        	if (digits.empty()) digits.push_back(0);
	}

	BigInt& operator+=(const BigInt& other)
	{
		int carry = 0, sum = 0;
		size_t maxLength = max(digits.size(), other.digits.size());
		for (size_t i = 0; i < maxLength || carry; ++i)
		{
			if (i == digits.size()) digits.push_back(0);
			sum = digits[i] + (i < other.digits.size() ? other.digits[i] : 0) + carry;
			carry = sum / 10;
			digits[i] = sum % 10;
		}
		return *this;
	}

	BigInt& operator*=(int num)
	{
		int carry = 0, prod = 0;
		for (size_t i = 0; i < digits.size() || carry; ++i)
		{
			if (i == digits.size()) digits.push_back(0);
			prod = digits[i] * num + carry;
			carry = prod / 10;
			digits[i] = prod % 10;
		}
		while (digits.size() > 1 && digits.back() == 0) digits.pop_back();
		return *this;
	}


	friend ostream& operator<<(ostream& os, const BigInt& num)
	{
		for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it)
		{
			os << *it;
		}
		return os;
	}
};

int main() {
	int n;
	cin >> n;

	BigInt sum = 0;
	BigInt factorial = 1;
	for (int i = 1; i <= n; ++i)
	{
		factorial *= i;
		sum += factorial;
	}
	cout << sum << endl;
	return 0;
}

