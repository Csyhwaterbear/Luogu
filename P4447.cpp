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
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
/* 注意：用了 fastio 就不要和 scanf/printf 混用了 */

/* ===== 调试（可选） ===== */
// #define debug(x) cerr << #x << " = " << (x) << '\n'

/* ===== 常用函数模板 ===== */

// 读一行（含空格）
string readline() {
    string s; getline(cin, s); return s;
}

// 数组输入
template <typename T>
void input(vector<T>& v) {
    for (auto& x : v) cin >> x;
}

/* ===== 数学工具 ===== */
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

/* ===== 质数判断 (试除) ===== */
bool is_prime(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

/* ===== 解决一个测试用例 ===== */
void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    input(a);
    sort(all(a));

    // end_len[v]：所有“以 v 结尾”的组长度（小根堆）
    unordered_map<ll, priority_queue<int, vector<int>, greater<int>>> end_len;
    end_len.reserve((size_t)n * 2);

    for (ll x : a) {
        auto it = end_len.find(x - 1);
        if (it != end_len.end() && !it->second.empty()) {
            // 优先接到最短组，能最大化最终最小组人数
            int len = it->second.top();
            it->second.pop();
            end_len[x].push(len + 1);
        } else {
            end_len[x].push(1);
        }
    }

    int ans = n;
    for (auto& kv : end_len) {
        auto& pq = kv.second;
        while (!pq.empty()) {
            ans = min(ans, pq.top());
            pq.pop();
        }
    }

    cout << ans << '\n';
}

int main() {
    fastio;

    int T = 1;
    // cin >> T;  // 多组测试时取消注释
    while (T--) solve();

    return 0;
}
