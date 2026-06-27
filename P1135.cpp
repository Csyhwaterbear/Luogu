#include <bits/stdc++.h>
using namespace std;

/* ===== 类型别名 ===== */
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

/* ===== 常用宏 ===== */
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

/* ===== 快读快写 ===== */
#define fastio                                                                 \
	ios::sync_with_stdio(false);                                           \
	cin.tie(nullptr)
/* 注意：用了 fastio 就不要和 scanf/printf 混用了 */

/* ===== 调试（可选） ===== */
// #define debug(x) cerr << #x << " = " << (x) << '\n'

/* ===== 常用函数模板 ===== */

// 读一行（含空格）
string readline() {
	string s;
	getline(cin, s);
	return s;
}

// 数组输入
template <typename T> void input(vector<T> &v) {
	for (auto &x : v)
		cin >> x;
}

// 二分查找第一个等于 target 的位置（数组需非降序）
// 返回 1-based 下标；若不存在返回 -1
int bifunc(const vector<int> &list, int target) {
	int l = 0, r = (int)list.size();
	while (l < r) {
		int m = l + (r - l) / 2;
		if (list[m] < target)
			l = m + 1;
		else
			r = m;
	}
	if (l < (int)list.size() && list[l] == target)
		return l + 1;
	return -1;
}

/* ===== 数学工具 ===== */
// greatest common divisor
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// least common multiple
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

/* ===== 质数判断 (试除) ===== */
bool is_prime(ll n) {
	if (n < 2)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (ll i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	return true;
}

/* ===== BigInt（非负，常用竞赛版） ===== */
struct BigInt {
	static const int BASE = 1000000000;
	vector<int> d; // little-endian

	BigInt(long long x = 0) { *this = x; }

	BigInt &operator=(long long x) {
		d.clear();
		if (x == 0)
			return *this;
		while (x) {
			d.push_back((int)(x % BASE));
			x /= BASE;
		}
		return *this;
	}

	bool is_zero() const { return d.empty(); }

	void trim() {
		while (!d.empty() && d.back() == 0)
			d.pop_back();
	}

	void mul_int(int m) {
		if (is_zero() || m == 0) {
			d.clear();
			return;
		}
		long long carry = 0;
		for (size_t i = 0; i < d.size(); ++i) {
			long long cur = 1LL * d[i] * m + carry;
			d[i] = (int)(cur % BASE);
			carry = cur / BASE;
		}
		while (carry) {
			d.push_back((int)(carry % BASE));
			carry /= BASE;
		}
	}

	BigInt div_int(int v) const {
		BigInt q;
		if (is_zero())
			return q;
		q.d.assign(d.size(), 0);
		long long rem = 0;
		for (int i = (int)d.size() - 1; i >= 0; --i) {
			long long cur = d[i] + rem * BASE;
			q.d[i] = (int)(cur / v);
			rem = cur % v;
		}
		q.trim();
		return q;
	}

	friend bool operator<(const BigInt &a, const BigInt &b) {
		if (a.d.size() != b.d.size())
			return a.d.size() < b.d.size();
		for (int i = (int)a.d.size() - 1; i >= 0; --i) {
			if (a.d[i] != b.d[i])
				return a.d[i] < b.d[i];
		}
		return false;
	}

	friend bool operator>(const BigInt &a, const BigInt &b) {
		return b < a;
	}
	friend bool operator<=(const BigInt &a, const BigInt &b) {
		return !(b < a);
	}
	friend bool operator>=(const BigInt &a, const BigInt &b) {
		return !(a < b);
	}
	friend bool operator==(const BigInt &a, const BigInt &b) {
		return a.d == b.d;
	}
	friend bool operator!=(const BigInt &a, const BigInt &b) {
		return !(a == b);
	}

	string str() const {
		if (d.empty())
			return "0";
		string s = to_string(d.back());
		for (int i = (int)d.size() - 2; i >= 0; --i) {
			string t = to_string(d[i]);
			s += string(9 - (int)t.size(), '0') + t;
		}
		return s;
	}
};

/* ===== 解决一个测试用例 ===== */
void solve() {
	int N, A, B;
	cin >> N >> A >> B;
	vector<int> K(N + 1); 
	for (int i = 1; i <= N; ++i)
		cin >> K[i];

	vector<int> dist(N + 1, -1); 
	queue<int> q;

	dist[A] = 0;
	q.push(A);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == B)
			break; 

		int up = cur + K[cur];
		int down = cur - K[cur];

		if (up <= N && dist[up] == -1) {
			dist[up] = dist[cur] + 1;
			q.push(up);
		}
		if (down >= 1 && dist[down] == -1) {
			dist[down] = dist[cur] + 1;
			q.push(down);
		}
	}

	cout << dist[B] << '\n';
}

int main() {
	fastio;

	int T = 1;
	// cin >> T;  // 多组测试时取消注释
	while (T--)
		solve();

	return 0;
}
